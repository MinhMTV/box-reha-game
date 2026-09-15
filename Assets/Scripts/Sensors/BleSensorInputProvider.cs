using System;
using UnityEngine;

/// <summary>Validated native sensor input; keyboard development input uses the common action pipeline.</summary>
public class BleSensorInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event Action<PlayerActionEvent> OnActionDetected;
    [SerializeField] private GameConfig gameConfig;
    [SerializeField] private bool enableKeyboardSimulation;
    [SerializeField] private bool enableAccelerationHeuristic;
    private readonly SensorEventProcessor processor = new SensorEventProcessor();
    private bool isEnabled;
    private int lastInputFrame = -1;

    public bool IsEnabled
    {
        get => isEnabled;
        set
        {
            if (isEnabled != value) processor.ClearPending();
            isEnabled = value;
        }
    }
    public InputSourceType SourceType => InputSourceType.Sensor;
    public bool IsReady => processor.ConnectedCount > 0 || enableKeyboardSimulation;
    public string Status => processor.ConnectedCount > 0
        ? "Sensor channels: " + processor.ConnectedCount + " | mock: " + processor.MockConnectedCount
            + (enableKeyboardSimulation ? " | keyboard development enabled" : "")
        : enableKeyboardSimulation ? "Keyboard development input | no sensor connected" : "No sensor connected | native collector required";
    public int RejectedReadingCount => processor.RejectedCount;
    public string LastRejection => processor.LastRejection;

    void Start() { DynamicsSdkBridge.EnsureInstance().SetInputProvider(this); }
    void Update() { UpdateInput(); }
    void OnDestroy()
    {
        processor.ClearPending();
        if (DynamicsSdkBridge.Instance != null) DynamicsSdkBridge.Instance.SetInputProvider(null);
    }
    public void ForgetDevice(string id,string epoch) { processor.ForgetDevice(id,epoch); }
    public bool SetDeviceConnection(string deviceId, string connectionId, SensorDeviceType type,
        BodySide side, string provenance, bool connected)
    {
        return processor.SetConnection(deviceId, connectionId, type, side, provenance, connected, Time.realtimeSinceStartupAsDouble);
    }
    public bool PushSensorReading(SensorReading reading)
    {
        bool accepted = processor.Enqueue(reading, Time.realtimeSinceStartupAsDouble);
        // Consume identity even while paused/disabled, but never replay the queued action on resume.
        if (!isEnabled) processor.ClearPending();
        return accepted;
    }
    public void UpdateInput()
    {
        processor.ExpireConnections(Time.realtimeSinceStartupAsDouble);
        if (!isEnabled || lastInputFrame == Time.frameCount) return;
        lastInputFrame = Time.frameCount;
        if (enableKeyboardSimulation)
        {
            EmitKeyboard(KeyCode.LeftArrow, ActionType.Punch, BodySide.Left);
            EmitKeyboard(KeyCode.RightArrow, ActionType.Punch, BodySide.Right);
            EmitKeyboard(KeyCode.A, ActionType.Kick, BodySide.Left);
            EmitKeyboard(KeyCode.D, ActionType.Kick, BodySide.Right);
        }
        processor.EnableAccelerationHeuristic = enableAccelerationHeuristic;
        processor.PunchThreshold = gameConfig != null ? gameConfig.SensorPunchAccelerationThreshold : 18f;
        processor.KickThreshold = gameConfig != null ? gameConfig.SensorKickAccelerationThreshold : 16f;
        processor.CooldownSeconds = gameConfig != null ? Math.Max(0, gameConfig.SensorActionCooldown) : 0.12;
        foreach (SensorReading reading in processor.ConsumeActions(Time.realtimeSinceStartupAsDouble))
            OnActionDetected?.Invoke(CreateSensorAction(reading));
    }
    private void EmitKeyboard(KeyCode key, ActionType type, BodySide side)
    {
        if (!Input.GetKeyDown(key)) return;
        OnActionDetected?.Invoke(KeyboardActionFactory.Create(type, side));
    }
    public static PlayerActionEvent CreateSensorAction(SensorReading reading)
    {
        ActionType type = reading.SensorType == SensorDeviceType.Delta ? ActionType.Kick : ActionType.Punch;
        PlayerActionEvent action = PlayerActionEvent.Create(type,
            reading.BodySide == BodySide.Left ? LaneType.Left : LaneType.Right, 1f,
            Vector2.zero, Vector2.zero, 0f, InputSourceType.Sensor,
            type == ActionType.Kick ? VerticalPosition.Low : VerticalPosition.High,
            0f, reading.SensorType, reading.BodySide);
        action.DeviceId = reading.DeviceId;
        action.ConnectionId = reading.ConnectionId;
        action.Provenance = reading.Provenance;
        action.SourceEventId = reading.EventId;
        action.SourceTimestamp = reading.Timestamp;
        action.SourceClock = reading.SourceClock;
        action.ReceivedTimestamp = reading.ReceivedTimestamp;
        action.IsValid = reading.IsValid;
        action.ValidityReason = reading.ValidityReason;
        action.RawValue = reading.RawValue;
        action.Quantity = reading.Quantity;
        action.Unit = reading.Unit;
        // No calibrated metric baseline exists yet. Neutral damage is not a force estimate.
        action.NormalizationValid = false;
        action.Detector = reading.Detector;
        action.SensorEvidence = reading;
        return action;
    }
}
