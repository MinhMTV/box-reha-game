using System;
using UnityEngine;

/// <summary>
/// Unity-facing bridge endpoint for the RISE Dynamics SDK.
/// Native Android/iOS SDK code can call these methods via UnitySendMessage.
/// </summary>
public class DynamicsSdkBridge : MonoBehaviour
{
    public const string GameObjectName = "DynamicsSdkBridge";

    [SerializeField] private BleSensorInputProvider sensorInputProvider;
    [SerializeField] private bool logIncomingPayloads;

    public static DynamicsSdkBridge Instance { get; private set; }

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        gameObject.name = GameObjectName;
        DontDestroyOnLoad(gameObject);
        ResolveInputProvider();
    }

    void Start()
    {
        ResolveInputProvider();
    }

    public static DynamicsSdkBridge EnsureInstance()
    {
        if (Instance != null)
        {
            return Instance;
        }

        GameObject bridgeObject = new GameObject(GameObjectName);
        return bridgeObject.AddComponent<DynamicsSdkBridge>();
    }

    public void SetInputProvider(BleSensorInputProvider provider)
    {
        sensorInputProvider = provider;
    }

    /// <summary>
    /// Expected JSON shape:
    /// {"sensorType":"Alpha","bodySide":"Left","deviceId":"alpha_left","ax":0,"ay":0,"az":0,"gx":0,"gy":0,"gz":0,"impactForce":0,"powerIndex":0,"timestamp":0}
    /// </summary>
    public void ReceiveSensorDataJson(string json)
    {
        if (string.IsNullOrWhiteSpace(json))
        {
            return;
        }

        ResolveInputProvider();
        if (sensorInputProvider == null)
        {
            Debug.LogWarning("[DynamicsSdkBridge] No BleSensorInputProvider found for sensor payload.");
            return;
        }

        try
        {
            DynamicsSensorPayload payload = JsonUtility.FromJson<DynamicsSensorPayload>(json);
            SensorReading reading = payload.ToSensorReading();
            sensorInputProvider.PushSensorReading(reading);

            if (logIncomingPayloads)
            {
                Debug.Log($"[DynamicsSdkBridge] Sensor payload mapped: {reading.SensorType}/{reading.BodySide} {reading.DeviceId}");
            }
        }
        catch (Exception ex)
        {
            Debug.LogWarning($"[DynamicsSdkBridge] Failed to parse sensor payload: {ex.Message}\n{json}");
        }
    }

    /// <summary>
    /// Expected JSON shape:
    /// {"sensorType":"Alpha","bodySide":"Right","deviceId":"alpha_right","impact":42,"peakForce":380,"powerIndex":0,"peakAcceleration":22,"timestamp":0}
    /// </summary>
    public void ReceivePunchJson(string json)
    {
        if (string.IsNullOrWhiteSpace(json))
        {
            return;
        }

        ResolveInputProvider();
        if (sensorInputProvider == null)
        {
            Debug.LogWarning("[DynamicsSdkBridge] No BleSensorInputProvider found for punch payload.");
            return;
        }

        try
        {
            DynamicsPunchPayload payload = JsonUtility.FromJson<DynamicsPunchPayload>(json);
            SensorReading reading = payload.ToSensorReading();
            sensorInputProvider.PushSensorReading(reading);

            if (logIncomingPayloads)
            {
                Debug.Log($"[DynamicsSdkBridge] Punch payload mapped: {reading.SensorType}/{reading.BodySide} {reading.DeviceId}");
            }
        }
        catch (Exception ex)
        {
            Debug.LogWarning($"[DynamicsSdkBridge] Failed to parse punch payload: {ex.Message}\n{json}");
        }
    }

    private void ResolveInputProvider()
    {
        if (sensorInputProvider != null)
        {
            return;
        }

        sensorInputProvider = FindObjectOfType<BleSensorInputProvider>();
    }
}

[Serializable]
public struct DynamicsSensorPayload
{
    public string sensorType;
    public string bodySide;
    public string deviceId;
    public double timestamp;
    public float ax;
    public float ay;
    public float az;
    public float gx;
    public float gy;
    public float gz;
    public float impactForce;
    public float powerIndex;

    public SensorReading ToSensorReading()
    {
        return new SensorReading
        {
            Acceleration = new Vector3(ax, ay, az),
            Gyroscope = new Vector3(gx, gy, gz),
            Timestamp = timestamp > 0d ? timestamp : Time.realtimeSinceStartupAsDouble,
            ImpactForce = impactForce,
            PowerIndex = powerIndex,
            SensorType = ParseSensorType(sensorType, deviceId, powerIndex),
            BodySide = ParseBodySide(bodySide, deviceId),
            DeviceId = deviceId
        };
    }

    internal static SensorDeviceType ParseSensorType(string value, string fallbackId, float powerIndex)
    {
        string normalized = !string.IsNullOrWhiteSpace(value) ? value.Trim().ToLowerInvariant() : string.Empty;
        string id = !string.IsNullOrWhiteSpace(fallbackId) ? fallbackId.Trim().ToLowerInvariant() : string.Empty;

        if (normalized.Contains("delta") || id.Contains("delta") || id.Contains("foot") || id.Contains("leg") || powerIndex > 0f)
        {
            return SensorDeviceType.Delta;
        }

        if (normalized.Contains("alpha") || id.Contains("alpha") || id.Contains("glove") || id.Contains("hand"))
        {
            return SensorDeviceType.Alpha;
        }

        return SensorDeviceType.Unknown;
    }

    internal static BodySide ParseBodySide(string value, string fallbackId)
    {
        string normalized = !string.IsNullOrWhiteSpace(value) ? value.Trim().ToLowerInvariant() : string.Empty;
        string id = !string.IsNullOrWhiteSpace(fallbackId) ? fallbackId.Trim().ToLowerInvariant() : string.Empty;

        if (normalized.StartsWith("l") || id.Contains("left") || id.EndsWith("_l") || id.EndsWith("-l"))
        {
            return BodySide.Left;
        }

        if (normalized.StartsWith("r") || id.Contains("right") || id.EndsWith("_r") || id.EndsWith("-r"))
        {
            return BodySide.Right;
        }

        return BodySide.Unknown;
    }
}

[Serializable]
public struct DynamicsPunchPayload
{
    public string sensorType;
    public string bodySide;
    public string deviceId;
    public double timestamp;
    public float impact;
    public float peakForce;
    public float powerIndex;
    public float peakAcceleration;

    public SensorReading ToSensorReading()
    {
        SensorDeviceType parsedSensorType = DynamicsSensorPayload.ParseSensorType(sensorType, deviceId, powerIndex);
        float force = peakForce > 0f ? peakForce : impact;

        return new SensorReading
        {
            Acceleration = new Vector3(Mathf.Max(0f, peakAcceleration), 0f, 0f),
            Gyroscope = Vector3.zero,
            Timestamp = timestamp > 0d ? timestamp : Time.realtimeSinceStartupAsDouble,
            ImpactForce = parsedSensorType == SensorDeviceType.Alpha ? force : 0f,
            PowerIndex = parsedSensorType == SensorDeviceType.Delta ? Mathf.Max(powerIndex, force) : powerIndex,
            SensorType = parsedSensorType,
            BodySide = DynamicsSensorPayload.ParseBodySide(bodySide, deviceId),
            DeviceId = deviceId
        };
    }
}
