using System;
using System.IO;
using UnityEngine;

/// <summary>Runs the actual production logger with typed host fixtures; all data is synthetic.</summary>
internal static class LoggerHostCheck
{
    public static void Run()
    {
        Application.persistentDataPath = Path.GetFullPath("artifacts/validation/synthetic");
        Time.time = 0; Time.realtimeSinceStartupAsDouble = 100;
        var profile = new PlayerProfile { Name = "DO_NOT_EXPORT_THIS_NAME", StudyId = "SYNTHETIC_NOT_EMPIRICAL_DATA" };
        LevelDefinition level = LevelDefinition.CreateLevel1();
        level.DisplayName = "SYNTHETIC / NOT EMPIRICAL DATA";
        string sessionId = ResearchSessionLog.Begin(profile, level, "SYNTHETIC_HOST_FIXTURE sdk_mock + keyboard", new GameConfig());
        if (!ResearchSessionLog.IsOpen) throw new Exception("Production logger failed to open: " + ResearchSessionLog.Error);
        var target = new TargetObject {
            TargetId = "SYNTHETIC_TARGET_1", Type = TargetType.Punch, Lane = LaneType.Left,
            SpawnTime = 0, HitWindow = 0.9f, MoveSpeed = 8, ExpectedHitTime = 2, MaxHits = 1
        };
        ResearchSessionLog.TargetSpawn(target);
        Time.time = 2; Time.realtimeSinceStartupAsDouble = 102;
        PlayerActionEvent action = KeyboardActionFactory.Create(ActionType.Punch, BodySide.Left);
        ResearchSessionLog.Action(action);
        ResearchSessionLog.TargetResolved(target, "hit", action.EventId, HitQuality.Perfect, 0);
        ResearchSessionLog.Score(100, 1, 1, 100, 100, target.TargetId, action.EventId);
        var stats = new GameSessionStats {
            SessionId = sessionId, StudyId = profile.StudyId, Mode = level.DisplayName,
            SpawnedTargets = 1, TotalTargets = 1, PerfectHits = 1, Score = 100, MaxCombo = 1, FinalCombo = 1,
            DurationSeconds = 3, StopReason = "synthetic_complete", ArmTargets = 1, ArmHits = 1,
            LeftTargets = 1, LeftHits = 1
        };
        stats.TrackAction(action);
        stats.TrackReactionTime(2);
        // An unmatched valid SDK mock event tests complete source/quantity/clock serialization.
        var reading = new SensorReading {
            SchemaVersion = 2, EventId = "SYNTHETIC_SDK_PUNCH_1", DeviceId = "SYNTHETIC_DEVICE_RIGHT",
            ConnectionId = "SYNTHETIC_CONNECTION", SensorType = SensorDeviceType.Alpha, BodySide = BodySide.Right,
            Provenance = "sdk_mock", IsValid = true, HasTiming = true, IsComputedPunch = true,
            Sequence = 1, Timestamp = 1700000002.7, SourceClock = "unix_seconds", ReceivedTimestamp = 102.8,
            SourceAgeSeconds = 0.1, RawValue = 30, AlphaImpact = 30, Quantity = "alpha.impact", Unit = "unknown",
            NativeSourceAgeSeconds = 0.08, NativeTransportAgeSeconds = 0.02, HasNativeTransportTiming = true,
            EmittedAndroidMonotonicSeconds = 77.5,
            ValidityReason = "synthetic_computed_valid", Detector = "sdk_computed_punch"
        };
        Time.time = 2.8f; Time.realtimeSinceStartupAsDouble = 102.8;
        action = BleSensorInputProvider.CreateSensorAction(reading);
        ResearchSessionLog.Action(action);
        stats.TrackAction(action);
        // A deliberately unready/mock state exercises the metadata serializer, never a physical start claim.
        ResearchSessionLog.Acquisition(JsonUtility.ToJson(new AndroidAcquisitionSnapshot
        {
            requestedFamily = "Alpha", effectiveFamily = "Alpha", sdkVersion = "SYNTHETIC_SDK_VERSION",
            sdkSessionState = "error", initialized = true, permissionsGranted = true, profileReady = false,
            profileReference = "", profileStudyId = profile.StudyId,
            devices = new[] { new AndroidAcquisitionDevice { deviceId = "SYNTHETIC_DEVICE_RIGHT",
                connectionId = "SYNTHETIC_CONNECTION", family = "Alpha", side = "Right", online = false, isMock = true } }
        }));
        Time.time = 3; Time.realtimeSinceStartupAsDouble = 103;
        ResearchSessionLog.End(stats, "synthetic_complete");
        if (ResearchSessionLog.IsOpen || ResearchSessionLog.Error != null) throw new Exception("Logger end/close failed.");
        string actualPath = ResearchSessionLog.CurrentPath;
        string destination = Path.Combine(Application.persistentDataPath, "production-logger.synthetic.jsonl");
        File.Move(actualPath, destination, true);
        string[] lines = File.ReadAllLines(destination);
        if (lines.Length != 8) throw new Exception("Unexpected logger record count: " + lines.Length);
        int acquisitionRecords = 0;
        foreach (string line in lines)
        {
            using var record = System.Text.Json.JsonDocument.Parse(line);
            if (record.RootElement.GetProperty("studyId").GetString() != "SYNTHETIC_NOT_EMPIRICAL_DATA")
                throw new Exception("Synthetic provenance marker missing.");
            if (line.Contains("DO_NOT_EXPORT_THIS_NAME")) throw new Exception("Player name leaked into research log.");
            if (record.RootElement.GetProperty("kind").GetString() == "acquisition_state")
            {
                acquisitionRecords++;
                using var snapshot = System.Text.Json.JsonDocument.Parse(record.RootElement.GetProperty("acquisitionJson").GetString());
                if (snapshot.RootElement.GetProperty("profileReady").GetBoolean()
                    || !snapshot.RootElement.GetProperty("devices")[0].GetProperty("isMock").GetBoolean())
                    throw new Exception("Synthetic unready/mock acquisition metadata was changed.");
            }
        }
        if (acquisitionRecords != 1) throw new Exception("Acquisition metadata record missing.");
        Console.WriteLine("LOGGER_HOST_PASS 1 production JSONL lifecycle/privacy check; SYNTHETIC / NOT EMPIRICAL DATA.");
        Console.WriteLine("SYNTHETIC_LOG_PATH " + destination);
    }
}
