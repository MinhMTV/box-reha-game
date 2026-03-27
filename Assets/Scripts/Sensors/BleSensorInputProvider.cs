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
                ? "Sensor simulation active (J/K/L, 1/2/3, 7/8/9)"
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

    void Start()
    {
        sensorBuffer = new SensorDataBuffer(128);
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
        UpdateLaneSelection();
        UpdateVerticalSelection();

        if (Input.GetKeyDown(KeyCode.J))
        {
            EmitAction(ActionType.Punch, 1f);
        }
        else if (Input.GetKeyDown(KeyCode.K))
        {
            EmitAction(ActionType.Block, 0.8f);
        }
        else if (Input.GetKeyDown(KeyCode.L))
        {
            EmitAction(ActionType.Dodge, 0.9f);
        }
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
        float blockThreshold = gameConfig != null ? gameConfig.SensorBlockAccelerationThreshold : 9f;
        float dodgeThreshold = gameConfig != null ? gameConfig.SensorDodgeGyroThreshold : 6f;

        float peakAcceleration = sensorBuffer.GetPeakAccelerationMagnitude(6);
        float averageAcceleration = sensorBuffer.GetAverageAccelerationMagnitude(10);
        SensorReading latest = sensorBuffer.GetLatest();
        float gyroMagnitude = latest.Gyroscope.magnitude;
        float measuredForce = latest.ImpactForce > 0f
            ? latest.ImpactForce
            : EstimateForceFromAcceleration(peakAcceleration);

        if (peakAcceleration >= punchThreshold)
        {
            EmitAction(ActionType.Punch, GetNormalizedPower(measuredForce), measuredForce);
        }
        else if (gyroMagnitude >= dodgeThreshold)
        {
            EmitAction(ActionType.Dodge, Mathf.Clamp01(gyroMagnitude / (dodgeThreshold * 1.5f)), measuredForce);
        }
        else if (averageAcceleration >= blockThreshold)
        {
            EmitAction(ActionType.Block, Mathf.Clamp01(averageAcceleration / (blockThreshold * 1.5f)), measuredForce);
        }
    }

    private void EmitAction(ActionType actionType, float power, float rawForce = 0f)
    {
        lastEmitTime = Time.time;
        OnActionDetected?.Invoke(PlayerActionEvent.Create(
            actionType,
            simulatedLane,
            power,
            Vector2.zero,
            Vector2.zero,
            0f,
            InputSourceType.Sensor,
            simulatedVerticalPosition,
            rawForce));
    }

    private float EstimateForceFromAcceleration(float peakAcceleration)
    {
        PlayerProfile profile = GameManager.Instance != null ? GameManager.Instance.PlayerProfile : PlayerProfileStore.Load();
        float weightKg = profile != null ? profile.WeightKg : 70f;

        // Lightweight approximation for prototyping until the glove exposes a true impact metric.
        return Mathf.Max(0f, peakAcceleration * weightKg * 0.55f);
    }

    private float GetNormalizedPower(float measuredForce)
    {
        PlayerProfile profile = GameManager.Instance != null ? GameManager.Instance.PlayerProfile : PlayerProfileStore.Load();
        float normalizedForce = profile != null ? profile.NormalizePunchForce(measuredForce) : 1f;
        return Mathf.Clamp(normalizedForce, 0.35f, 1.75f);
    }
}
