using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>Validated Unity endpoint. Native SDK initialization/collection remains a separate integration gate.</summary>
public class DynamicsSdkBridge : MonoBehaviour
{
    public const string GameObjectName = "DynamicsSdkBridge";
    [SerializeField] private BleSensorInputProvider sensorInputProvider;
    [SerializeField] private bool logIncomingPayloads;
    public static DynamicsSdkBridge Instance { get; private set; }
    public int RejectedPayloadCount { get; private set; }
    public static event Action<string> NativeStatusReceived;
    private readonly Dictionary<string, DynamicsDeviceStatePayload> deviceStates = new Dictionary<string, DynamicsDeviceStatePayload>();
    public static Func<bool> CalibrationRunning;
    private readonly SensorEventProcessor calibrationIngress = new SensorEventProcessor();

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        gameObject.name = GameObjectName;
        DontDestroyOnLoad(gameObject);
        ResolveInputProvider();
    }
    void OnDestroy() { if (Instance == this) Instance = null; }
    public static DynamicsSdkBridge EnsureInstance()
    {
        if (Instance != null) return Instance;
        return new GameObject(GameObjectName).AddComponent<DynamicsSdkBridge>();
    }
    public void SetInputProvider(BleSensorInputProvider provider)
    {
        sensorInputProvider = provider;
        if (provider == null) return;
        foreach (DynamicsDeviceStatePayload state in deviceStates.Values) ApplyDeviceState(state);
    }
    public void ReceiveNativeStatusJson(string json) { NativeStatusReceived?.Invoke(json); }
    public void ReceiveSensorDataJson(string json) { ReceiveReading(json, false); }
    public void ReceivePunchJson(string json) { ReceiveReading(json, true); }

    public void ReceiveDeviceStateJson(string json)
    {
        if (string.IsNullOrWhiteSpace(json)) return;
        try
        {
            DynamicsDeviceStatePayload payload = JsonUtility.FromJson<DynamicsDeviceStatePayload>(json);
            if (payload == null || payload.schemaVersion != 2 || string.IsNullOrWhiteSpace(payload.deviceId)
                || (payload.status != "online" && payload.status != "offline" && payload.status != "error" && payload.status != "removed"))
            { Reject("invalid_device_state"); return; }
            if (!DeviceStateIsFresh(payload)) return;
            if(payload.status == "removed")
            {
                if(deviceStates.TryGetValue(payload.deviceId,out var cached) && cached.connectionId != payload.connectionId)return;
                deviceStates.Remove(payload.deviceId);calibrationIngress.ForgetDevice(payload.deviceId,payload.connectionId);
                if(ResolveInputProvider())sensorInputProvider.ForgetDevice(payload.deviceId,payload.connectionId);
                return;
            }
            if (payload.status == "online") deviceStates[payload.deviceId] = payload;
            else deviceStates.Remove(payload.deviceId);
            calibrationIngress.SetConnection(payload.deviceId, payload.connectionId, DynamicsSensorPayload.ParseSensorType(payload.sensorType),
                DynamicsSensorPayload.ParseBodySide(payload.bodySide), payload.provenance, payload.status == "online", Time.realtimeSinceStartupAsDouble);
            if (ResolveInputProvider()) ApplyDeviceState(payload);
        }
        catch (Exception) { Reject("malformed_device_state_json"); }
    }
    private void ApplyDeviceState(DynamicsDeviceStatePayload payload)
    {
        if (!DeviceStateIsFresh(payload)) return;
        if (!sensorInputProvider.SetDeviceConnection(payload.deviceId, payload.connectionId,
                DynamicsSensorPayload.ParseSensorType(payload.sensorType),
                DynamicsSensorPayload.ParseBodySide(payload.bodySide), payload.provenance, payload.status == "online"))
                Reject("device_state_rejected");
    }
    private bool DeviceStateIsFresh(DynamicsDeviceStatePayload payload)
    {
        if (!AndroidNativeClock.IsDeviceRuntime) return true;
        if (AndroidNativeClock.TryTransportAge(payload.emittedAndroidMonotonicSeconds, out double age)
            && age <= AndroidSessionPolicy.StatusTimeoutSeconds) return true;
        Reject("missing_or_stale_android_device_state");
        return false;
    }

    private void ReceiveReading(string json, bool computedPunch)
    {
        if (string.IsNullOrWhiteSpace(json)) return;
        try
        {
            DynamicsSensorPayload payload = JsonUtility.FromJson<DynamicsSensorPayload>(json);
            if (payload == null) { Reject("null_payload"); return; }
            double transportAge = 0;
            bool measuredTransport = AndroidNativeClock.IsDeviceRuntime;
            if (measuredTransport && !AndroidNativeClock.TryTransportAge(payload.emittedAndroidMonotonicSeconds, out transportAge))
            { Reject("missing_or_invalid_android_emission_clock"); return; }
            SensorReading reading = payload.ToSensorReading(Time.realtimeSinceStartupAsDouble, computedPunch, transportAge, measuredTransport);
            double now = Time.realtimeSinceStartupAsDouble;
            calibrationIngress.ExpireConnections(now);
            if (calibrationIngress.Enqueue(reading, now))
                foreach (SensorReading accepted in calibrationIngress.ConsumeActions(now))
                    if (CalibrationRunning != null && CalibrationRunning())
                        MeasuredCalibration.Current.Add(accepted, now);
            if (!ResolveInputProvider()) return;
            if (!sensorInputProvider.PushSensorReading(reading)) Reject("reading_rejected");
            else if (logIncomingPayloads) Debug.Log("[DynamicsSdkBridge] Validated " + reading.Provenance + " " + reading.Quantity);
        }
        catch (Exception) { Reject("malformed_reading_json"); }
    }
    private void Reject(string reason)
    {
        RejectedPayloadCount++;
        // Do not include raw payloads or device identifiers in ordinary diagnostic logs.
        if (RejectedPayloadCount <= 5 || RejectedPayloadCount % 100 == 0)
            Debug.LogWarning("[DynamicsSdkBridge] Rejected payload: " + reason);
    }
    private bool ResolveInputProvider()
    {
        if (sensorInputProvider == null) sensorInputProvider = FindObjectOfType<BleSensorInputProvider>();
        return sensorInputProvider != null;
    }
}

[Serializable]
public class DynamicsDeviceStatePayload
{
    public int schemaVersion;
    public double emittedAndroidMonotonicSeconds;
    public string deviceId;
    public string connectionId;
    public string sensorType;
    public string bodySide;
    public string provenance;
    public string status;
}

[Serializable]
public class DynamicsSensorPayload
{
    public int schemaVersion;
    public string sensorType;
    public string bodySide;
    public string deviceId;
    public string connectionId;
    public string eventId;
    public long sequence;
    public string provenance;
    public bool isValid;
    public bool areComputedValuesValid;
    public string validityReason;
    public double timestamp;
    public string timestampClock;
    public bool hasTiming;
    public double sourceAgeSeconds;
    public double emittedAndroidMonotonicSeconds;
    public float ax, ay, az;
    public float gx, gy, gz;
    public bool hasMagnetometer;
    public float mx, my, mz;
    public bool hasBarometer;
    public float barometerPa;
    public int imuSamplingRateHz, barometerSamplingRateHz, magnetometerSamplingRateHz;
    public int bleCounter, sampleIndex;
    public double relativeTimeCounterSeconds;
    public string quantity;
    public string unit;
    public float impact;
    public float peakForceBasedOnBaro;
    public float powerIndex;
    public float peakAcceleration;
    public float peakVelocity;
    public float displacement;
    public double punchDurationSeconds;
    public double contactDurationSeconds;

    public SensorReading ToSensorReading(double receivedAt, bool computedPunch, double transportAgeSeconds = 0, bool measuredTransport = false)
    {
        float value = new Vector3(ax, ay, az).magnitude;
        if (computedPunch)
        {
            switch (quantity)
            {
                case "alpha.impact": value = impact; break;
                case "alpha.peak_force_baro": value = peakForceBasedOnBaro; break;
                case "delta.power_index": value = powerIndex; break;
                default: value = float.NaN; break;
            }
        }
        return new SensorReading
        {
            SchemaVersion = schemaVersion, DeviceId = deviceId, ConnectionId = connectionId,
            SensorType = ParseSensorType(sensorType), BodySide = ParseBodySide(bodySide),
            EventId = eventId, Sequence = sequence, Provenance = provenance,
            IsValid = isValid && (!computedPunch || areComputedValuesValid), ValidityReason = validityReason,
            IsComputedPunch = computedPunch, Timestamp = timestamp, SourceClock = timestampClock,
            ReceivedTimestamp = receivedAt, HasTiming = hasTiming, SourceAgeSeconds = sourceAgeSeconds + transportAgeSeconds,
            NativeSourceAgeSeconds = sourceAgeSeconds, NativeTransportAgeSeconds = transportAgeSeconds,
            HasNativeTransportTiming = measuredTransport, EmittedAndroidMonotonicSeconds = emittedAndroidMonotonicSeconds,
            Acceleration = new Vector3(ax, ay, az), Gyroscope = new Vector3(gx, gy, gz),
            HasMagnetometer = hasMagnetometer, Magnetometer = new Vector3(mx, my, mz),
            HasBarometer = hasBarometer, Barometer = barometerPa,
            ImuSamplingRateHz = imuSamplingRateHz, BarometerSamplingRateHz = barometerSamplingRateHz,
            MagnetometerSamplingRateHz = magnetometerSamplingRateHz, BleCounter = bleCounter, SampleIndex = sampleIndex,
            RelativeTimeCounterSeconds = relativeTimeCounterSeconds,
            Quantity = quantity, Unit = unit, RawValue = value,
            AlphaImpact = impact, AlphaPeakForceBasedOnBaro = peakForceBasedOnBaro, DeltaPowerIndex = powerIndex,
            PeakAcceleration = peakAcceleration, PeakVelocity = peakVelocity, Displacement = displacement,
            PunchDurationSeconds = punchDurationSeconds, ContactDurationSeconds = contactDurationSeconds,
            Detector = computedPunch ? "sdk_computed_punch" : "raw_telemetry"
        };
    }
    public static SensorDeviceType ParseSensorType(string value)
    {
        switch (value == null ? string.Empty : value.Trim().ToLowerInvariant())
        {
            case "alpha": return SensorDeviceType.Alpha;
            case "delta": return SensorDeviceType.Delta;
            default: return SensorDeviceType.Unknown;
        }
    }
    public static BodySide ParseBodySide(string value)
    {
        switch (value == null ? string.Empty : value.Trim().ToLowerInvariant())
        {
            case "left": return BodySide.Left;
            case "right": return BodySide.Right;
            default: return BodySide.Unknown;
        }
    }
}
