using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

[Serializable]
public sealed class CalibrationBaseline
{
    public int schemaVersion = 1;
    public string studyId, deviceId, connectionId, family, side, quantity, unit, provenance;
    public string createdUtc, qualification = "UNQUALIFIED", algorithm = "median_of_5_v1";
    public string sdkVersion = "0.25.6", sdkBuildMode;
    public int sampleCount;
    public double firstSourceTimestamp, lastSourceTimestamp, baseline;
    public string[] eventIds;
    public double[] values;
}

/// <summary>Per-device, per-side reference collection. Does not normalize gameplay or claim physical calibration.</summary>
public sealed class MeasuredCalibration
{
    public const int RequiredSamples = 5;
    public static MeasuredCalibration Current { get; } = new MeasuredCalibration();
    public string State { get; private set; } = "Not started";
    public int SampleCount => values.Count;
    public bool Collecting { get; private set; }
    public CalibrationBaseline Result { get; private set; }
    private readonly List<double> values = new List<double>();
    private readonly List<string> eventIds = new List<string>();
    private string study, device, connection, family, side, quantity, mode;
    private double armedAt, firstTimestamp, lastTimestamp;

    public void Begin(string studyId, string deviceId, string connectionId, string sensorFamily, string bodySide, string sdkMode, double now)
    {
        Cancel("Invalid readiness or device assignment");
        if (string.IsNullOrWhiteSpace(studyId) || string.IsNullOrWhiteSpace(deviceId) || string.IsNullOrWhiteSpace(connectionId)
            || (sensorFamily != "Alpha" && sensorFamily != "Delta") || (bodySide != "Left" && bodySide != "Right")
            || (sdkMode != "COMPATIBILITY" && sdkMode != "VENDOR-UNCHANGED") || !SensorEventProcessor.Finite(now)) return;
        study = studyId; device = deviceId; connection = connectionId; family = sensorFamily; side = bodySide; mode = sdkMode;
        quantity = family == "Alpha" ? "alpha.impact" : "delta.power_index";
        armedAt = now; Collecting = true; State = "Collecting measured repetitions";
    }
    public bool Add(SensorReading reading, double now)
    {
        if (!Collecting || !SensorEventProcessor.Finite(now) || now < armedAt || reading.ReceivedTimestamp < armedAt) return false;
        if (now - armedAt > 120) { Cancel("Collection timed out; repeat readiness check"); return false; }
        // The ingress processor additionally checks connection heartbeat, ordering, age and all numerical fields.
        if (reading.DeviceId != device || reading.ConnectionId != connection || reading.SensorType.ToString() != family
            || reading.BodySide.ToString() != side || reading.Quantity != quantity || reading.Unit != "unknown"
            || reading.Provenance != "dynamics_sdk" || !reading.IsComputedPunch || !reading.IsValid || !reading.HasTiming
            || reading.SourceClock != "unix_seconds" || !SensorEventProcessor.Finite(reading.Timestamp) || reading.Timestamp <= 0
            || !SensorEventProcessor.Finite(reading.RawValue) || reading.RawValue <= 0
            || !SensorEventProcessor.Finite(reading.SourceAgeSeconds) || reading.SourceAgeSeconds < 0
            || !SensorEventProcessor.Finite(reading.ReceivedTimestamp) || now < reading.ReceivedTimestamp
            || now - reading.ReceivedTimestamp + reading.SourceAgeSeconds > .5
            || string.IsNullOrWhiteSpace(reading.EventId) || eventIds.Contains(reading.EventId)
            || (values.Count > 0 && reading.Timestamp <= lastTimestamp)) return false;
        if (values.Count == 0) firstTimestamp = reading.Timestamp;
        lastTimestamp = reading.Timestamp; values.Add(reading.RawValue); eventIds.Add(reading.EventId);
        if (values.Count == RequiredSamples)
        {
            double[] sorted = values.ToArray(); Array.Sort(sorted);
            Result = new CalibrationBaseline { studyId = study, deviceId = device, connectionId = connection, family = family,
                side = side, quantity = quantity, unit = "unknown", provenance = "dynamics_sdk", sdkBuildMode = mode,
                createdUtc = DateTime.UtcNow.ToString("O"), sampleCount = values.Count, firstSourceTimestamp = firstTimestamp,
                lastSourceTimestamp = lastTimestamp, baseline = sorted[RequiredSamples / 2], eventIds = eventIds.ToArray(), values = values.ToArray() };
            Collecting = false; State = "Measured reference ready; hardware qualification pending";
        }
        return true;
    }
    public void Cancel(string reason) { Collecting = false; Result = null; values.Clear(); eventIds.Clear(); firstTimestamp = lastTimestamp = 0; State = reason; }
    public string Save(string directory, string currentStudy)
    {
        if (Result == null || Result.studyId != currentStudy || Result.sampleCount != RequiredSamples) throw new InvalidOperationException("No complete reference for this participant");
        Directory.CreateDirectory(directory);
        // No user-controlled identifier is used in a filename; each explicit save creates a new audit record.
        string path = Path.Combine(directory, "reference-" + Guid.NewGuid().ToString("N") + ".json");
        using (var stream = new FileStream(path, FileMode.CreateNew, FileAccess.Write))
        using (var writer = new StreamWriter(stream)) writer.Write(JsonUtility.ToJson(Result, true));
        State = "Reference saved locally — UNQUALIFIED; gameplay normalization remains disabled";
        return path;
    }
}
