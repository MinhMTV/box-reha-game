using System;
using System.IO;
using System.Text;
using UnityEngine;

/// <summary>Append-only local research records. No participant name or demographic data is exported.</summary>
public static class ResearchSessionLog
{
    [Serializable]
    public class Record
    {
        public int schemaVersion = 1;
        public string kind, sessionId, eventId, studyId, utc;
        public double monotonicSeconds;
        public float gameplaySeconds;
        public string mode, buildVersion, buildRevision, unityVersion, configJson, gameConfigJson, stopReason, statsJson, inputStatus;
        public string acquisitionJson, calibrationId;
        public float strengthThreshold;
        public string actionType, side, lane, inputSource, deviceType, deviceId, provenance;
        public string sourceEventId, sourceClock, quantity, unit, validityReason;
        public string connectionId, detector, sensorEvidenceJson;
        public double sourceTimestamp, receivedTimestamp;
        public float power, rawValue;
        public bool isValid, normalizationValid;
        public string targetId, targetType, matchedEventId, outcome, hitQuality;
        public float spawnGameplaySeconds, hitWindowSeconds, timingOffsetSeconds, resolutionSeconds;
        public float targetSpeed, hitZoneZ, expectedHitGameplaySeconds, heavyTimeoutSeconds;
        public int maxHealth, remainingHealth;
        public int baseScore, combo, awardedScore, totalScore, healthDamage;
        public float multiplier;
    }

    private static StreamWriter writer;
    private static string sessionId, studyId;
    private static float startTime;
    public static string CurrentSessionId => sessionId;
    public static string CurrentPath { get; private set; }
    public static string Error { get; private set; }
    public static bool IsOpen => writer != null;

    public static string Begin(PlayerProfile profile, LevelDefinition level, string inputStatus, GameConfig config = null, string acquisitionJson = null)
    {
        Close();
        Error = null;
        sessionId = Guid.NewGuid().ToString("N");
        studyId = profile != null ? profile.StudyId : "unassigned";
        startTime = Time.time;
        try
        {
            string directory = Path.Combine(Application.persistentDataPath,
#if UNITY_EDITOR
                Environment.GetEnvironmentVariable("DOJO_VISUAL_QA") == "1" ? "synthetic-visual-qa" :
#endif
                "research");
            Directory.CreateDirectory(directory);
            CurrentPath = Path.Combine(directory, sessionId + ".jsonl");
            writer = new StreamWriter(CurrentPath, false, new UTF8Encoding(false));
            writer.AutoFlush = true;
            TextAsset build = Resources.Load<TextAsset>("ResearchBuildInfo");
            Write(new Record { kind = "session_start", mode = level.DisplayName,
                buildVersion = Application.version, unityVersion = Application.unityVersion,
                buildRevision = build != null ? build.text.Trim() : "unrecorded",
                configJson = JsonUtility.ToJson(level), gameConfigJson = config != null ? JsonUtility.ToJson(config) : null,
                inputStatus = inputStatus, acquisitionJson = acquisitionJson });
        }
        catch (Exception ex) when (ex is IOException || ex is UnauthorizedAccessException)
        { Fail(ex); }
        return sessionId;
    }

    public static void Acquisition(string snapshotJson)
    {
        Write(new Record { kind = "acquisition_state", acquisitionJson = snapshotJson });
    }

    public static void Action(PlayerActionEvent action)
    {
        Write(new Record { calibrationId=action.CalibrationId, kind = "action", eventId = action.EventId,
            actionType = action.ActionType.ToString(), side = action.BodySide.ToString(), lane = action.Lane.ToString(),
            inputSource = action.SourceType.ToString(), deviceType = action.SensorDevice.ToString(),
            deviceId = action.DeviceId, provenance = action.Provenance, sourceEventId = action.SourceEventId,
            connectionId = action.ConnectionId, detector = action.Detector,
            sensorEvidenceJson = action.SourceType == InputSourceType.Sensor ? JsonUtility.ToJson(action.SensorEvidence) : null,
            sourceTimestamp = action.SourceTimestamp, sourceClock = action.SourceClock,
            receivedTimestamp = action.ReceivedTimestamp, power = action.Power,
            normalizationValid = action.NormalizationValid, rawValue = action.RawValue,
            quantity = action.Quantity, unit = action.Unit, isValid = action.IsValid, validityReason = action.ValidityReason });
    }

    public static void TargetSpawn(TargetObject target)
    {
        Write(TargetRecord("target_spawn", target));
    }
    public static void TargetResolved(TargetObject target, string outcome, string actionId = null,
        HitQuality quality = HitQuality.Miss, float timingOffset = 0f)
    {
        Record record = TargetRecord("target_resolved", target);
        record.outcome = outcome;
        record.matchedEventId = actionId;
        record.hitQuality = quality.ToString();
        record.timingOffsetSeconds = timingOffset;
        record.resolutionSeconds = Mathf.Max(0f, Time.time - target.SpawnTime);
        Write(record);
    }
    public static void BelowStrength(TargetObject target, PlayerActionEvent action, float threshold)
    {
        Record r=TargetRecord("below_strength_threshold",target);r.matchedEventId=action.EventId;r.power=action.Power;r.strengthThreshold=threshold;r.calibrationId=action.CalibrationId;r.normalizationValid=action.NormalizationValid;Write(r);
    }
    public static void HeavyImpact(TargetObject target, PlayerActionEvent action, int damage)
    {
        Record record = TargetRecord("heavy_impact", target);
        record.matchedEventId = action.EventId;
        record.healthDamage = damage;
        Write(record);
    }
    private static Record TargetRecord(string kind, TargetObject target)
    {
        HitZoneEvaluator evaluator = UnityEngine.Object.FindObjectOfType<HitZoneEvaluator>();
        float zone = evaluator != null ? evaluator.HitZoneZ : 5f;
        return new Record { kind = kind, targetId = target.TargetId, targetType = target.Type.ToString(),
            lane = target.Lane.ToString(), spawnGameplaySeconds = target.SpawnTime - startTime,
            hitWindowSeconds = target.HitWindow, targetSpeed = target.MoveSpeed, hitZoneZ = zone,
            expectedHitGameplaySeconds = target.ExpectedHitTime - startTime,
            maxHealth = target.MaxHits, remainingHealth = Mathf.Max(0, target.MaxHits - target.CurrentHits),
            heavyTimeoutSeconds = target.IsTough ? target.HeavyTimeoutSeconds : 0f };
    }
    public static void Score(int baseScore, float multiplier, int combo, int awarded, int total,
        string targetId, string actionId, string reason = "hit")
    {
        Write(new Record { kind = "score", baseScore = baseScore, multiplier = multiplier,
            combo = combo, awardedScore = awarded, totalScore = total, targetId = targetId,
            matchedEventId = actionId, outcome = reason });
    }
    public static void State(string kind) { Write(new Record { kind = kind }); }
    public static void End(GameSessionStats stats, string reason)
    {
        Write(new Record { kind = "session_end", stopReason = reason, statsJson = JsonUtility.ToJson(stats) });
        Close();
    }
    public static void Write(Record record)
    {
        if (writer == null) return;
        record.sessionId = sessionId;
        record.studyId = studyId;
        if (string.IsNullOrEmpty(record.eventId)) record.eventId = Guid.NewGuid().ToString("N");
        record.utc = DateTime.UtcNow.ToString("O");
        record.monotonicSeconds = Time.realtimeSinceStartupAsDouble;
        record.gameplaySeconds = Time.time - startTime;
        try { writer.WriteLine(JsonUtility.ToJson(record)); }
        catch (Exception ex) when (ex is IOException || ex is UnauthorizedAccessException) { Fail(ex); }
    }
    private static void Fail(Exception ex)
    {
        Error = "Research logging unavailable: " + ex.Message;
        Debug.LogError(Error);
        Close();
    }
    public static void Close()
    {
        try { writer?.Dispose(); }
        catch (IOException ex) { Error = ex.Message; }
        writer = null;
    }
}
