using System;
using UnityEngine;

/// <summary>
/// Sensor-glove input provider.
/// Supports a real sensor data feed and a keyboard simulation path for development/testing.
/// </summary>
public class BleSensorInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event Action<PlayerActionEvent> OnActionDetected;

    public bool IsEnabled { get; set; }
    public InputSourceType SourceType => InputSourceType.Sensor;
    public bool IsReady => isConnected || enableKeyboardSimulation;
    public string Status
    {
        get
        {
            if (isConnected)
            {
                return $"Sensor connected ({deviceId})";
            }

            return enableKeyboardSimulation
                ? "Sensor simulation: hold arrows for punches, hold A/D for kicks"
                : $"Waiting for sensor ({deviceId})";
        }
    }

    [SerializeField] private string deviceId = "default_sensor";
    [SerializeField] private GameConfig gameConfig;
    [SerializeField] private bool enableKeyboardSimulation = true;
    [SerializeField] private LaneType simulatedLane = LaneType.Center;
    [SerializeField] private VerticalPosition simulatedVerticalPosition = VerticalPosition.Mid;

    private bool isConnected;
    private float lastEmitTime;
    private SensorDataBuffer sensorBuffer;
    private float leftPunchDownTime = -1f;
    private float rightPunchDownTime = -1f;
    private float leftKickDownTime = -1f;
    private float rightKickDownTime = -1f;

    private const float KeyboardTapPower = 0.9f;
    private const float KeyboardMinPower = 0.75f;
    private const float KeyboardMaxPower = 1.65f;
    private const float KeyboardChargedReleaseThreshold = 0.18f;
    private const float KeyboardFullPowerHoldSeconds = 0.75f;

    void Start()
    {
        sensorBuffer = new SensorDataBuffer(128);
        DynamicsSdkBridge.EnsureInstance().SetInputProvider(this);
        Debug.Log("[BleSensorInputProvider] Sensor provider ready.");
    }

    void Update()
    {
        if (!IsEnabled) return;
        UpdateInput();
    }

    public void UpdateInput()
    {
        if (enableKeyboardSimulation)
        {
            UpdateKeyboardSimulation();
        }

        if (!isConnected)
        {
            if (Time.frameCount % 60 == 0)
            {
                Debug.Log($"[BleSensorInputProvider] {Status}");
            }
            return;
        }

        TryEmitBufferedAction();
    }

    public void OnSensorConnected()
    {
        isConnected = true;
        Debug.Log($"[BleSensorInputProvider] Sensor connected: {deviceId}");
    }

    public void OnSensorDisconnected()
    {
        isConnected = false;
        Debug.Log($"[BleSensorInputProvider] Sensor disconnected: {deviceId}");
    }

    public void PushSensorReading(SensorReading reading)
    {
        if (sensorBuffer == null)
        {
            sensorBuffer = new SensorDataBuffer(128);
        }

        sensorBuffer.Push(reading);
    }

    void OnDestroy()
    {
        if (isConnected)
        {
            OnSensorDisconnected();
        }
    }

    private void UpdateKeyboardSimulation()
    {
        UpdateVerticalSelection();

        TrackKeyboardHold(KeyCode.LeftArrow, ActionType.Punch, SensorDeviceType.Alpha, BodySide.Left, VerticalPosition.High, LaneType.Left, ref leftPunchDownTime);
        TrackKeyboardHold(KeyCode.RightArrow, ActionType.Punch, SensorDeviceType.Alpha, BodySide.Right, VerticalPosition.High, LaneType.Right, ref rightPunchDownTime);
        TrackKeyboardHold(KeyCode.A, ActionType.Kick, SensorDeviceType.Delta, BodySide.Left, VerticalPosition.Low, LaneType.Left, ref leftKickDownTime);
        TrackKeyboardHold(KeyCode.D, ActionType.Kick, SensorDeviceType.Delta, BodySide.Right, VerticalPosition.Low, LaneType.Right, ref rightKickDownTime);
    }

    private void TrackKeyboardHold(KeyCode key, ActionType actionType, SensorDeviceType sensorDevice, BodySide bodySide, VerticalPosition verticalPosition, LaneType lane, ref float downTime)
    {
        if (Input.GetKeyDown(key))
        {
            downTime = Time.time;
            EmitAction(actionType, KeyboardTapPower, 0f, sensorDevice, bodySide, verticalPosition, lane);
        }

        if (!Input.GetKeyUp(key))
        {
            return;
        }

        float holdDuration = downTime >= 0f ? Time.time - downTime : 0f;
        downTime = -1f;
        if (holdDuration < KeyboardChargedReleaseThreshold)
        {
            return;
        }

        EmitAction(actionType, GetKeyboardPower(holdDuration), 0f, sensorDevice, bodySide, verticalPosition, lane);
    }

    private float GetKeyboardPower(float holdDuration)
    {
        float t = Mathf.Clamp01(holdDuration / KeyboardFullPowerHoldSeconds);
        return Mathf.Lerp(KeyboardMinPower, KeyboardMaxPower, t);
    }

    private void UpdateLaneSelection()
    {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            simulatedLane = LaneType.Left;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            simulatedLane = LaneType.Center;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha3))
        {
            simulatedLane = LaneType.Right;
        }
    }

    private void UpdateVerticalSelection()
    {
        if (Input.GetKeyDown(KeyCode.Alpha7))
        {
            simulatedVerticalPosition = VerticalPosition.High;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha8))
        {
            simulatedVerticalPosition = VerticalPosition.Mid;
        }
        else if (Input.GetKeyDown(KeyCode.Alpha9))
        {
            simulatedVerticalPosition = VerticalPosition.Low;
        }
    }

    private void TryEmitBufferedAction()
    {
        if (sensorBuffer == null || sensorBuffer.Count == 0)
        {
            return;
        }

        float cooldown = gameConfig != null ? gameConfig.SensorActionCooldown : 0.35f;
        if (Time.time - lastEmitTime < cooldown)
        {
            return;
        }

        float punchThreshold = gameConfig != null ? gameConfig.SensorPunchAccelerationThreshold : 18f;
        float kickThreshold = gameConfig != null ? gameConfig.SensorKickAccelerationThreshold : 16f;
        float blockThreshold = gameConfig != null ? gameConfig.SensorBlockAccelerationThreshold : 9f;
        float dodgeThreshold = gameConfig != null ? gameConfig.SensorDodgeGyroThreshold : 6f;

        float peakAcceleration = sensorBuffer.GetPeakAccelerationMagnitude(6);
        float averageAcceleration = sensorBuffer.GetAverageAccelerationMagnitude(10);
        SensorReading latest = sensorBuffer.GetLatest();
        SensorDeviceType sensorType = ResolveSensorType(latest);
        BodySide bodySide = ResolveBodySide(latest);
        float gyroMagnitude = latest.Gyroscope.magnitude;
        float measuredForce = GetMeasuredForce(latest, peakAcceleration, sensorType);

        if (sensorType == SensorDeviceType.Delta)
        {
            if (peakAcceleration >= kickThreshold || latest.PowerIndex > 0f)
            {
                EmitAction(ActionType.Kick, GetNormalizedPower(measuredForce, ActionType.Kick), measuredForce,
                    SensorDeviceType.Delta, bodySide, VerticalPosition.Low);
            }
            else if (gyroMagnitude >= dodgeThreshold)
            {
                EmitAction(ActionType.Dodge, Mathf.Clamp01(gyroMagnitude / (dodgeThreshold * 1.5f)), measuredForce,
                    SensorDeviceType.Delta, bodySide, VerticalPosition.Mid);
            }
            return;
        }

        if (peakAcceleration >= punchThreshold || latest.ImpactForce > 0f)
        {
            EmitAction(ActionType.Punch, GetNormalizedPower(measuredForce, ActionType.Punch), measuredForce,
                SensorDeviceType.Alpha, bodySide, VerticalPosition.High);
        }
        else if (gyroMagnitude >= dodgeThreshold)
        {
            EmitAction(ActionType.Dodge, Mathf.Clamp01(gyroMagnitude / (dodgeThreshold * 1.5f)), measuredForce,
                SensorDeviceType.Alpha, bodySide, VerticalPosition.Mid);
        }
        else if (averageAcceleration >= blockThreshold)
        {
            EmitAction(ActionType.Block, Mathf.Clamp01(averageAcceleration / (blockThreshold * 1.5f)), measuredForce,
                SensorDeviceType.Alpha, bodySide, VerticalPosition.Mid);
        }
    }

    private void EmitAction(ActionType actionType, float power, float rawForce = 0f,
        SensorDeviceType sensorDevice = SensorDeviceType.Unknown, BodySide bodySide = BodySide.Unknown,
        VerticalPosition? verticalOverride = null, LaneType? laneOverride = null)
    {
        lastEmitTime = Time.time;
        VerticalPosition verticalPosition = verticalOverride ?? simulatedVerticalPosition;
        LaneType lane = laneOverride ?? ResolveLaneFromBodySide(bodySide);
        OnActionDetected?.Invoke(PlayerActionEvent.Create(
            actionType,
            lane,
            power,
            Vector2.zero,
            Vector2.zero,
            0f,
            InputSourceType.Sensor,
            verticalPosition,
            rawForce,
            sensorDevice,
            bodySide));
    }

    private LaneType ResolveLaneFromBodySide(BodySide bodySide)
    {
        switch (bodySide)
        {
            case BodySide.Left: return LaneType.Left;
            case BodySide.Right: return LaneType.Right;
            default: return simulatedLane;
        }
    }

    private float GetMeasuredForce(SensorReading latest, float peakAcceleration, SensorDeviceType sensorType)
    {
        if (latest.ImpactForce > 0f)
        {
            return latest.ImpactForce;
        }

        if (latest.PowerIndex > 0f)
        {
            return latest.PowerIndex;
        }

        return EstimateForceFromAcceleration(peakAcceleration, sensorType);
    }

    private float EstimateForceFromAcceleration(float peakAcceleration, SensorDeviceType sensorType)
    {
        PlayerProfile profile = GameManager.Instance != null ? GameManager.Instance.PlayerProfile : PlayerProfileStore.Load();
        float weightKg = profile != null ? profile.WeightKg : 70f;
        float factor = sensorType == SensorDeviceType.Delta ? 0.72f : 0.55f;

        // Lightweight approximation until the SDK exposes calibrated impact/power values.
        return Mathf.Max(0f, peakAcceleration * weightKg * factor);
    }

    private float GetNormalizedPower(float measuredForce, ActionType actionType)
    {
        PlayerProfile profile = GameManager.Instance != null ? GameManager.Instance.PlayerProfile : PlayerProfileStore.Load();
        float normalizedForce = 1f;
        if (profile != null)
        {
            normalizedForce = actionType == ActionType.Kick
                ? profile.NormalizeKickForce(measuredForce)
                : profile.NormalizePunchForce(measuredForce);
        }
        return Mathf.Clamp(normalizedForce, 0.35f, 1.75f);
    }

    private SensorDeviceType ResolveSensorType(SensorReading reading)
    {
        if (reading.SensorType != SensorDeviceType.Unknown)
        {
            return reading.SensorType;
        }

        string id = reading.DeviceId != null ? reading.DeviceId.ToLowerInvariant() : string.Empty;
        if (id.Contains("delta") || id.Contains("foot") || id.Contains("leg") || id.Contains("kick"))
        {
            return SensorDeviceType.Delta;
        }

        return SensorDeviceType.Alpha;
    }

    private BodySide ResolveBodySide(SensorReading reading)
    {
        if (reading.BodySide != BodySide.Unknown)
        {
            return reading.BodySide;
        }

        string id = reading.DeviceId != null ? reading.DeviceId.ToLowerInvariant() : string.Empty;
        if (id.Contains("left") || id.Contains("_l") || id.EndsWith("l"))
        {
            return BodySide.Left;
        }
        if (id.Contains("right") || id.Contains("_r") || id.EndsWith("r"))
        {
            return BodySide.Right;
        }

        return BodySide.Unknown;
    }
}
