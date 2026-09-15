using System;
using UnityEngine;

/// <summary>Validated native sensor input; keyboard development input uses the common action pipeline.</summary>
public class BleSensorInputProvider : MonoBehaviour, IPlayerActionInputProvider, ISensorReadingSink
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
    public static PlayerActionEvent CreateSensorAction(SensorReading reading) => UnifiedGameplayActionMapper.Map(reading);
}
