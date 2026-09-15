using UnityEngine;

/// <summary>Common validated-reading boundary for current computed and future qualified raw acquisitions.</summary>
public static class UnifiedGameplayActionMapper
{
    public static PlayerActionEvent Map(SensorReading reading)
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
        // Personal calibration is applied later by the round controller; no inferred physical force.
        action.NormalizationValid = false;
        action.Detector = reading.Detector;
        action.SensorEvidence = reading;
        return action;
    }
}
