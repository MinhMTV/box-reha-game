using System;
using UnityEngine;

/// <summary>Contract v2. Missing identity, validity or clock is not a measurement.</summary>
[Serializable]
public struct SensorReading
{
    public Vector3 Acceleration; // SDK accData: m/s^2.
    public Vector3 Gyroscope; // SDK gyroData: degrees/s, NOT radians/s.
    public Vector3 Magnetometer; // SDK magnetoData: microtesla.
    public float Barometer; // SDK baroData: pascal.
    public bool HasMagnetometer;
    public bool HasBarometer;
    public double Timestamp; // Original timestamp; interpreted only with SourceClock.
    public string SourceClock;
    public double ReceivedTimestamp; // Unity monotonic seconds, assigned at ingress.
    public double SourceAgeSeconds; // Age at Unity receipt: native source age plus measured Android transport age when available.
    public double NativeSourceAgeSeconds;
    public double NativeTransportAgeSeconds;
    public bool HasNativeTransportTiming;
    public double EmittedAndroidMonotonicSeconds; // Android elapsedRealtime seconds; never an absolute Unity timestamp.
    public bool HasTiming;
    public int SchemaVersion;
    public long Sequence; // Strictly increasing per connection, not coarse device clock.
    public string EventId;
    public string ConnectionId;
    public string DeviceId;
    public SensorDeviceType SensorType;
    public BodySide BodySide;
    public string Provenance; // dynamics_sdk or sdk_mock; never inferred from device name.
    public bool IsValid;
    public string ValidityReason;
    public bool IsComputedPunch;
    public float RawValue;
    public string Quantity;
    public string Unit;
    public string Detector;
    public int ImuSamplingRateHz;
    public int BarometerSamplingRateHz;
    public int MagnetometerSamplingRateHz;
    public int BleCounter;
    public int SampleIndex;
    public double RelativeTimeCounterSeconds;
    public float AlphaImpact;
    public float AlphaPeakForceBasedOnBaro;
    public float DeltaPowerIndex;
    public float PeakAcceleration;
    public float PeakVelocity;
    public float Displacement;
    public double PunchDurationSeconds;
    public double ContactDurationSeconds;
}
