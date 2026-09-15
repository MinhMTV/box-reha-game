using UnityEngine;

[System.Serializable]
public struct PlayerActionEvent
{
    public ActionType ActionType;
    public LaneType Lane;
    public float Power;
    public double Timestamp;
    public Vector2 StartScreenPosition;
    public Vector2 EndScreenPosition;
    public float HoldDuration;
    public InputSourceType SourceType;
    public float RawForce;
    // Phase 3: Vertical position for future high/low punches
    public VerticalPosition VerticalPos;
    public SensorDeviceType SensorDevice;
    public BodySide BodySide;
    public string EventId;
    public string DeviceId;
    public string ConnectionId;
    public string Provenance;
    public string SourceEventId;
    public double SourceTimestamp;
    public string SourceClock;
    public double ReceivedTimestamp;
    public bool IsValid;
    public string ValidityReason;
    public float RawValue;
    public string Quantity;
    public string Unit;
    public bool NormalizationValid;
    public string Detector;
    public string CalibrationId;
    public SensorReading SensorEvidence;

    public static PlayerActionEvent Create(ActionType action, LaneType lane, float power,
        Vector2 startPos, Vector2 endPos, float holdDuration, InputSourceType source,
        VerticalPosition verticalPos = VerticalPosition.Mid, float rawForce = 0f,
        SensorDeviceType sensorDevice = SensorDeviceType.Unknown, BodySide bodySide = BodySide.Unknown)
    {
        return new PlayerActionEvent
        {
            EventId = System.Guid.NewGuid().ToString("N"),
            Provenance = source.ToString().ToLowerInvariant(),
            SourceClock = "unity_monotonic_seconds",
            SourceTimestamp = Time.realtimeSinceStartupAsDouble,
            ReceivedTimestamp = Time.realtimeSinceStartupAsDouble,
            IsValid = source != InputSourceType.Sensor,
            ValidityReason = source == InputSourceType.Sensor ? "requires_validated_sensor_evidence" : "input_event",
            Quantity = "gameplay.relative_power",
            Unit = "dimensionless",
            RawValue = power,
            NormalizationValid = source != InputSourceType.Sensor,
            ActionType = action,
            Lane = lane,
            Power = power,
            Timestamp = Time.realtimeSinceStartupAsDouble,
            StartScreenPosition = startPos,
            EndScreenPosition = endPos,
            HoldDuration = holdDuration,
            SourceType = source,
            RawForce = rawForce,
            VerticalPos = verticalPos,
            SensorDevice = sensorDevice,
            BodySide = bodySide
        };
    }
}
