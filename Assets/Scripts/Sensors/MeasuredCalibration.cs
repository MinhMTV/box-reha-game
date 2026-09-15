using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

[Serializable]
public sealed class CalibrationBaseline
{
    public int schemaVersion = 2;
    public string calibrationId, referenceKind = "strength", appVersion, buildRevision;
    public int rejectedSamples;
    public double[] sourceTimestamps;
    public double medianIntervalSeconds, actionsPerSecond;
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
    public int RejectedSamples { get; private set; }
    public int FamiliarizationRemaining { get; private set; }
    private string referenceKind = "strength", auditPath;
    private readonly List<double> timestamps = new List<double>();
    public void ConfigureAudit(string directory) { Directory.CreateDirectory(directory); auditPath=Path.Combine(directory,"calibration-"+Guid.NewGuid().ToString("N")+".jsonl"); }
    [Serializable] private class AuditRecord { public string kind, studyId, deviceId, connectionId, family, side, quantity, eventId, reason, utc; public double sourceTimestamp, rawValue; }
    private void Audit(string kind, SensorReading r=default, string reason=null)
    {
        if(auditPath==null)return;
        File.AppendAllText(auditPath,JsonUtility.ToJson(new AuditRecord {kind=kind,studyId=study,deviceId=device,connectionId=connection,family=family,side=side,quantity=quantity,eventId=r.EventId,sourceTimestamp=r.Timestamp,rawValue=r.RawValue,reason=reason,utc=DateTime.UtcNow.ToString("O")})+"\n");
    }
    private bool Reject(SensorReading r, string reason) { RejectedSamples++;Audit("calibration_rejected",r,reason);return false; }
    private readonly List<double> values = new List<double>();
    private readonly List<string> eventIds = new List<string>();
    private string study, device, connection, family, side, quantity, mode;
    private double armedAt, firstTimestamp, lastTimestamp;

    public void Begin(string studyId, string deviceId, string connectionId, string sensorFamily, string bodySide, string sdkMode, double now, string kind = "strength", int familiarization = 0)
    {
        Cancel("Invalid readiness or device assignment");
        if (string.IsNullOrWhiteSpace(studyId) || string.IsNullOrWhiteSpace(deviceId) || string.IsNullOrWhiteSpace(connectionId)
            || (sensorFamily != "Alpha" && sensorFamily != "Delta") || (bodySide != "Left" && bodySide != "Right")
            || (sdkMode != "COMPATIBILITY" && sdkMode != "VENDOR-UNCHANGED") || !SensorEventProcessor.Finite(now)) return;
        study = studyId; device = deviceId; connection = connectionId; family = sensorFamily; side = bodySide; mode = sdkMode;
        quantity = family == "Alpha" ? "alpha.impact" : "delta.power_index";
        referenceKind = kind == "speed" ? "speed" : "strength"; FamiliarizationRemaining=Math.Max(0,familiarization);
        armedAt = now; Collecting = true; Audit("calibration_start"); State = "Collecting measured repetitions";
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
            || (eventIds.Count > 0 && reading.Timestamp <= lastTimestamp)) return Reject(reading,"identity_provenance_timing_or_quantity");
        if(FamiliarizationRemaining > 0) { FamiliarizationRemaining--;eventIds.Add(reading.EventId);lastTimestamp=reading.Timestamp;Audit("calibration_familiarization",reading);State="Familiarization: " + FamiliarizationRemaining + " remaining";return true; }
        if(values.Count==0) { eventIds.Clear();State="Collecting " + referenceKind + " reference"; }
        if (values.Count == 0) firstTimestamp = reading.Timestamp;
        lastTimestamp = reading.Timestamp; timestamps.Add(reading.Timestamp); Audit("calibration_sample",reading); values.Add(reading.RawValue); eventIds.Add(reading.EventId);
        if (values.Count == RequiredSamples)
        {
            double[] sorted = values.ToArray(); Array.Sort(sorted);
            double[] intervals=new double[Math.Max(0,timestamps.Count-1)];for(int i=0;i<intervals.Length;i++)intervals[i]=timestamps[i+1]-timestamps[i];Array.Sort(intervals);
            double interval=intervals.Length>0?(intervals[(intervals.Length-1)/2]+intervals[intervals.Length/2])/2:0;
            Result = new CalibrationBaseline { calibrationId=Guid.NewGuid().ToString("N"), referenceKind=referenceKind, algorithm=referenceKind=="speed"?"median_inter_action_interval_of5_v1":"median_of_5_v1", rejectedSamples=RejectedSamples,
                sourceTimestamps=timestamps.ToArray(), medianIntervalSeconds=interval, actionsPerSecond=interval>0?1/interval:0,
                appVersion=Application.version, buildRevision=Resources.Load<TextAsset>("ResearchBuildInfo")?.text ?? "unrecorded",
 studyId = study, deviceId = device, connectionId = connection, family = family,
                side = side, quantity = quantity, unit = "unknown", provenance = "dynamics_sdk", sdkBuildMode = mode,
                createdUtc = DateTime.UtcNow.ToString("O"), sampleCount = values.Count, firstSourceTimestamp = firstTimestamp,
                lastSourceTimestamp = lastTimestamp, baseline = sorted[RequiredSamples / 2], eventIds = eventIds.ToArray(), values = values.ToArray() };
            Collecting = false; State = "Reference complete — save to this profile. Hardware qualification pending";Audit("calibration_complete",reason:Result.calibrationId);
        }
        return true;
    }
    public void Cancel(string reason) { Collecting = false; Result = null; RejectedSamples=0;FamiliarizationRemaining=0;timestamps.Clear(); values.Clear(); eventIds.Clear(); firstTimestamp = lastTimestamp = 0; State = reason; }
    public string Save(string directory, string currentStudy)
    {
        if (Result == null || Result.studyId != currentStudy || Result.sampleCount != RequiredSamples) throw new InvalidOperationException("No complete reference for this participant");
        Directory.CreateDirectory(directory);
        // No user-controlled identifier is used in a filename; each explicit save creates a new audit record.
        string path = Path.Combine(directory, "reference-" + Guid.NewGuid().ToString("N") + ".json");
        using (var stream = new FileStream(path, FileMode.CreateNew, FileAccess.Write))
        using (var writer = new StreamWriter(stream)) writer.Write(JsonUtility.ToJson(Result, true));
        State = "Reference saved - personal game reference, not a force measurement";
        return path;
    }
}
