using System;
using UnityEngine;

/// <summary>Android JNI commands and acknowledged session lifecycle on Unity's main thread.</summary>
public class AndroidDynamicsController : MonoBehaviour
{
    public static AndroidDynamicsController Instance { get; private set; }
    public AndroidNativeStatus Status { get; private set; }
    public string Notice { get; private set; } = "Android SDK not initialized.";
    public bool Pending => pendingStart || pendingResume || pendingCalibration;
    private bool pendingCalibration, calibrationActive;
    public bool CalibrationRunning => calibrationActive && Running;
    public static bool Supported
    {
        get {
#if UNITY_ANDROID && !UNITY_EDITOR
            return true;
#else
            return false;
#endif
        }
    }
    private bool pendingStart, pendingResume, applicationPaused;
    private float commandStarted;
    private string participantId;
    private string sessionTopology, requestedFamily;
    private string pendingRequestId;
    private long lastStatusSequence;
    private double lastStatusReceivedAt = double.NegativeInfinity;
    private string lastLoggedAcquisition;
    public static AndroidDynamicsController EnsureInstance()
    {
        if (Instance == null) new GameObject("AndroidDynamicsController").AddComponent<AndroidDynamicsController>();
        return Instance;
    }
    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        DynamicsSdkBridge.EnsureInstance();
        DynamicsSdkBridge.CalibrationRunning = () => CalibrationRunning;
        DynamicsSdkBridge.NativeStatusReceived += ReceiveStatus;
        if (Supported) Screen.orientation = ScreenOrientation.LandscapeLeft;
    }
    void OnDestroy()
    {
        DynamicsSdkBridge.NativeStatusReceived -= ReceiveStatus;
        if (Instance == this) { Instance = null; DynamicsSdkBridge.CalibrationRunning = null; }
    }
    void Update()
    {
        if (calibrationActive && !Running)
        {
            calibrationActive = false;
            MeasuredCalibration.Current.Cancel("Sensor session interrupted; repeat readiness check");
        }
        if (SessionInputSelection.Physical && GameManager.Instance != null &&
            GameManager.Instance.CurrentState == GameState.Playing && !Running)
        {
            if (!AndroidSessionPolicy.StatusIsFresh(lastStatusReceivedAt, Time.realtimeSinceStartupAsDouble))
                Notice = "No fresh SDK status for more than 3 seconds. Session paused; check the collector.";
            GameManager.Instance.PauseGame();
        }
        if (Pending && Time.unscaledTime - commandStarted > 20f)
        {
            FinishSession();
            Notice = "SDK did not acknowledge the start within 20 seconds. Check connection and retry.";
        }
    }
    public void SelectParticipant(string studyId)
    {
        bool changed = participantId != studyId;
        if (changed)
        {
            if (participantId != null) FinishSession();
            participantId = studyId;
            if (Status != null) Status.profileReady = false;
            pendingStart = pendingResume = false;
        }
        // A prior native rejection (e.g. unfinished SDK session) must remain retryable after recovery.
        if (Supported && (changed || Status == null || Status.profileStudyId != studyId)) Call("selectParticipant", studyId);
    }
    public void Initialize() { SelectParticipant(GameManager.EnsureInstance().PlayerProfile.StudyId); Call("initialize"); }
    public void RequestPermissions() { Call("requestPermissions"); }
    public void OpenAppSettings() { Call("openAppSettings"); }
    public void OpenBluetoothSettings() { Call("openBluetoothSettings"); }
    public void StartScan() { Call("startScan"); }
    public void StopScan() { Call("stopScan"); }
    public void Pair(string id, string side) { Call("pair", id, side); }
    public void ChangeSide(string id) { Call("changeSide", id); }
    public void Remove(string id) { Call("unpair", id); }
    public void SetBodyProfile(double weight, double height, string gender)
    {
        SelectParticipant(GameManager.EnsureInstance().PlayerProfile.StudyId);
        if (!AndroidSessionPolicy.ValidBodyProfile(weight, height, gender))
        {
            if (Status != null) Status.profileReady = false;
            Notice = "SDK requires weight 20–250 kg, height 50–250 cm and an explicit MALE/FEMALE value.";
        }
        // Native also invalidates any previous profile acknowledgement on an invalid attempt.
        Call("setBodyProfile", participantId, weight, height, gender ?? "");
    }
    public bool Ready(out string reason)
    {
        if (!Supported) { reason = "Physical sensors require the Android build. Windows is development only."; return false; }
        if (!AndroidSessionPolicy.StatusIsFresh(lastStatusReceivedAt, Time.realtimeSinceStartupAsDouble))
        { reason = "No current SDK heartbeat. Initialize or restore the Android collector connection."; return false; }
        if (!AndroidSessionPolicy.CanPrepare(Status, SessionInputSelection.Family, out reason)) return false;
        if (Status.profileStudyId != participantId || string.IsNullOrWhiteSpace(Status.profileReference))
        { reason = "The SDK profile must be acknowledged for the current study ID."; return false; }
        if (!string.IsNullOrEmpty(sessionTopology) &&
            (sessionTopology != AndroidSessionPolicy.Topology(Status) || requestedFamily != SessionInputSelection.Family))
        { reason = "Device selection changed. Finish this round and start a new session for the new configuration."; return false; }
        return true;
    }
    public bool Running => !applicationPaused && Ready(out _) && Status.sessionState == "running"
        && Status.sessionFamily == SessionInputSelection.Family;
    public void RequestGameStart()
    {
        if (Pending) return;
        if (GameManager.Instance != null && (GameManager.Instance.CurrentState == GameState.Playing || GameManager.Instance.CurrentState == GameState.Paused))
        { Notice = "Finish the current round before starting another SDK session."; return; }
        if (!Ready(out string reason)) { Notice = reason; return; }
        pendingStart = true; commandStarted = Time.unscaledTime;
        pendingRequestId = Guid.NewGuid().ToString("N");
        sessionTopology = AndroidSessionPolicy.Topology(Status);
        requestedFamily = SessionInputSelection.Family;
        Notice = "Waiting for SDK session start…";
        if (!Call("startSession", SessionInputSelection.Family, pendingRequestId)) pendingStart = false;
    }
    public void RequestCalibrationSession()
    {
        if (!SessionInputSelection.Physical) { Notice = "Select Android sensors in Sensor setup first."; return; }
        if (Pending) return;
        if (GameManager.Instance != null && (GameManager.Instance.CurrentState == GameState.Playing || GameManager.Instance.CurrentState == GameState.Paused))
        { Notice = "Finish gameplay before collecting a reference."; return; }
        if (!Ready(out string reason)) { Notice = reason; return; }
        pendingCalibration = true; commandStarted = Time.unscaledTime;
        pendingRequestId = Guid.NewGuid().ToString("N");
        sessionTopology = AndroidSessionPolicy.Topology(Status); requestedFamily = SessionInputSelection.Family;
        if (!Call("startSession", requestedFamily, pendingRequestId)) pendingCalibration = false;
    }
    public void PauseSession() { pendingResume = false; if (Supported && SessionInputSelection.Physical) Call("pauseSession"); }
    public void RequestResume()
    {
        if (Pending) return;
        if (!Ready(out string reason)) { Notice = reason; return; }
        pendingResume = true; commandStarted = Time.unscaledTime;
        pendingRequestId = Guid.NewGuid().ToString("N");
        if (!Call("resumeSession", pendingRequestId)) pendingResume = false;
    }
    public void FinishSession()
    {
        pendingCalibration = calibrationActive = false;
        if (MeasuredCalibration.Current.Collecting) MeasuredCalibration.Current.Cancel("Session finished before reference completed");
        pendingStart = pendingResume = false;
        sessionTopology = requestedFamily = null;
        pendingRequestId = null;
        if (Supported && SessionInputSelection.Physical) Call("finishSession");
    }
    public string AcquisitionJson()
    {
        AndroidNativeStatus state = Status;
        AndroidNativeDevice[] devices = state?.devices ?? Array.Empty<AndroidNativeDevice>();
        AndroidAcquisitionSnapshot snapshot = new AndroidAcquisitionSnapshot
        {
            requestedFamily = SessionInputSelection.Family, effectiveFamily = state?.sessionFamily,
            sdkVersion = state?.sdkVersion, sdkSessionState = state?.sessionState,
            profileReference = state?.profileReference, profileStudyId = state?.profileStudyId,
            initialized = state != null && state.initialized, permissionsGranted = state != null && state.permissionsGranted,
            profileReady = state != null && state.profileReady, devices = new AndroidAcquisitionDevice[devices.Length]
        };
        for (int i = 0; i < devices.Length; i++)
        {
            AndroidNativeDevice device = devices[i];
            if (device == null) continue;
            snapshot.devices[i] = new AndroidAcquisitionDevice { deviceId = device.id, connectionId = device.connectionId,
                family = device.family, side = device.side, firmwareVersion = device.firmwareVersion, online = device.online, isMock = device.isMock };
        }
        return JsonUtility.ToJson(snapshot);
    }
    private void ReceiveStatus(string json)
    {
        try
        {
            AndroidNativeStatus incoming = JsonUtility.FromJson<AndroidNativeStatus>(json);
            if (incoming == null || incoming.schemaVersion != 1 || incoming.statusSequence < 1) throw new FormatException();
            if (incoming.statusSequence <= lastStatusSequence) return;
            double transportAge = 0;
            if (AndroidNativeClock.IsDeviceRuntime &&
                (!AndroidNativeClock.TryTransportAge(incoming.emittedAndroidMonotonicSeconds, out transportAge)
                || transportAge > AndroidSessionPolicy.StatusTimeoutSeconds))
                throw new FormatException("Missing or stale Android emission clock.");
            lastStatusSequence = incoming.statusSequence;
            lastStatusReceivedAt = Time.realtimeSinceStartupAsDouble - transportAge;
            Status = incoming;
            var profile=GameManager.Instance?.PlayerProfile;
            if(profile != null && incoming.profileReady && incoming.profileStudyId==profile.StudyId && incoming.profileReference!=profile.SdkProfileReference)
            { profile.SdkProfileReference=incoming.profileReference;PlayerProfileStore.Save(profile); }
            Notice = incoming.code + ": " + incoming.message;
        }
        catch (Exception) { Status = null; Notice = "Malformed or delayed SDK status; physical session blocked."; }
        if (SessionInputSelection.Physical && ResearchSessionLog.IsOpen)
        {
            string snapshot = AcquisitionJson();
            if (snapshot != lastLoggedAcquisition)
            {
                ResearchSessionLog.Acquisition(snapshot);
                lastLoggedAcquisition = snapshot;
            }
        }
        if (Status == null || Status.state == "error" || Status.sessionState == "error") pendingStart = pendingResume = pendingCalibration = false;
        if (pendingCalibration && Running && AndroidSessionPolicy.AcceptsRunningAck(Status, pendingRequestId, participantId, requestedFamily))
        { pendingCalibration = false; calibrationActive = true; pendingRequestId = null; }
        GameManager manager = GameManager.Instance;
        if (Running && manager != null)
        {
            bool ack = AndroidSessionPolicy.AcceptsRunningAck(Status, pendingRequestId, participantId, requestedFamily);
            if (pendingStart && ack) { pendingStart = false; pendingRequestId = null; manager.StartAcknowledgedSensorGame(); }
            else if (pendingResume && ack) { pendingResume = false; pendingRequestId = null; manager.ResumeAcknowledgedSensorGame(); }
        }
        else if (SessionInputSelection.Physical && manager != null && manager.CurrentState == GameState.Playing)
            manager.PauseGame();
    }
    private bool Call(string method, params object[] args)
    {
        if (!Supported) { Notice = "Unavailable here: install the Android build for physical sensors."; return false; }
#if UNITY_ANDROID && !UNITY_EDITOR
        try
        {
            using (AndroidJavaClass bridge = new AndroidJavaClass("com.boxreha.dynamics.DynamicsUnityBridge"))
                bridge.CallStatic(method, args);
            return true;
        }
        catch (Exception ex)
        {
            Notice = "Android bridge " + method + " failed: " + ex.GetType().Name;
            Status = null;
            return false;
        }
#else
        return false;
#endif
    }
    void OnApplicationPause(bool paused)
    {
        if (paused && (pendingCalibration || calibrationActive)) { FinishSession(); MeasuredCalibration.Current.Cancel("App paused; repeat reference collection"); }
        applicationPaused = paused;
        if (paused && pendingStart) FinishSession();
        if (Supported) Call("setApplicationPaused", paused);
        if (paused && SessionInputSelection.Physical) GameManager.Instance?.PauseGame();
    }
    void OnApplicationQuit() { if (Supported) Call("shutdown"); }
}
