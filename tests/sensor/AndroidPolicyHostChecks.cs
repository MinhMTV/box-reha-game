using System;

internal static class AndroidPolicyHostChecks
{
    public static void Run()
    {
        int checks = 0;
        void Check(bool value) { checks++; if (!value) throw new Exception("Android policy host assertion " + checks); }
        Check(AndroidSessionPolicy.StatusIsFresh(10, 13));
        Check(!AndroidSessionPolicy.StatusIsFresh(10, 13.001));
        Check(!AndroidSessionPolicy.StatusIsFresh(10, 9));
        Check(!AndroidSessionPolicy.StatusIsFresh(double.NegativeInfinity, 10));
        Check(!AndroidSessionPolicy.StatusIsFresh(10, double.NaN));
        Check(AndroidSessionPolicy.TryTransportAge(100, 100.25, out double transport) && transport == 0.25);
        Check(!AndroidSessionPolicy.TryTransportAge(0, 100, out _));
        Check(!AndroidSessionPolicy.TryTransportAge(double.NaN, 100, out _));
        Check(!AndroidSessionPolicy.TryTransportAge(101, 100, out _));
        Check(!AndroidSessionPolicy.TryTransportAge(100, double.PositiveInfinity, out _));
        Check(!AndroidSessionPolicy.StatusIsFresh(10 - 3.1, 10)); // callback arrival alone cannot refresh queued status
        var processor = new SensorEventProcessor();
        processor.SetConnection("SYNTHETIC_DEVICE", "SYNTHETIC_EPOCH", SensorDeviceType.Alpha, BodySide.Left, "dynamics_sdk", true, 100);
        var payload = new DynamicsSensorPayload { schemaVersion = 2, sensorType = "Alpha", bodySide = "Left",
            deviceId = "SYNTHETIC_DEVICE", connectionId = "SYNTHETIC_EPOCH", eventId = "SYNTHETIC_DELAY", sequence = 1,
            provenance = "dynamics_sdk", isValid = true, areComputedValuesValid = true, hasTiming = true,
            timestamp = 1700000000, timestampClock = "unix_seconds", sourceAgeSeconds = 0.2,
            emittedAndroidMonotonicSeconds = 99.6, quantity = "alpha.impact", impact = 12, unit = "unknown" };
        SensorReading delayed = payload.ToSensorReading(100, true, 0.4, true);
        Check(!processor.Enqueue(delayed, 100)); // 0.2 SDK age + 0.4 JNI transport exceeds 0.5 freshness
        Check(delayed.HasNativeTransportTiming && delayed.NativeTransportAgeSeconds == 0.4 && delayed.NativeSourceAgeSeconds == 0.2);
        SensorReading timely = payload.ToSensorReading(100, true, 0.1, true);
        Check(processor.Enqueue(timely, 100));
        AndroidNativeStatus state = new AndroidNativeStatus { schemaVersion = 1, initialized = true, permissionsGranted = true, profileReady = true, state = "ready", sessionState = "idle",
            devices = new[] {
                new AndroidNativeDevice { id = "left", connectionId = "c1", side = "Left", family = "Alpha", online = true },
                new AndroidNativeDevice { id = "right", connectionId = "c2", side = "Right", family = "Alpha", online = true } } };
        Check(!AndroidSessionPolicy.CanPrepare(null, "Alpha", out _));
        state.initialized = false; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.initialized = true;
        state.permissionsGranted = false; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.permissionsGranted = true;
        Check(AndroidSessionPolicy.CanPrepare(state, "Alpha", out _));
        Check(!AndroidSessionPolicy.CanPrepare(state, "Delta", out _));
        state.profileReady = false; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.profileReady = true;
        state.devices[1].side = "Left"; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.devices[1].side = "Right";
        state.devices[1].family = "Delta"; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.devices[1].family = "Alpha";
        state.devices[1].online = false; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.devices[1].online = true;
        state.devices[1].connectionId = ""; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.devices[1].connectionId = "c2";
        state.state = "error"; Check(!AndroidSessionPolicy.CanPrepare(state, "Alpha", out _)); state.state = "ready";
        state.devices = new[] { state.devices[0] }; Check(AndroidSessionPolicy.CanPrepare(state, "Alpha", out _));
        Check(AndroidSessionPolicy.ConnectedLanes(state, "Alpha").Length == 1 && AndroidSessionPolicy.ConnectedLanes(state, "Alpha")[0] == LaneType.Left);
        state.devices[0].family = "Delta"; state.devices[0].side = "Right";
        Check(AndroidSessionPolicy.CanPrepare(state, "Delta", out _));
        Check(AndroidSessionPolicy.ConnectedLanes(state, "Delta")[0] == LaneType.Right);
        state.devices[0].side = "Unknown"; Check(!AndroidSessionPolicy.CanPrepare(state, "Delta", out _)); state.devices[0].side = "Right";
        state.devices[0].isMock = true; Check(!AndroidSessionPolicy.CanPrepare(state, "Delta", out _)); state.devices[0].isMock = false;
        state.profileStudyId = "participant-current"; state.profileReference = "profile-id";
        state.sessionState = "running"; state.sessionFamily = "Delta"; state.controlRequestId = "request-current";
        Check(AndroidSessionPolicy.AcceptsRunningAck(state, "request-current", "participant-current", "Delta"));
        Check(!AndroidSessionPolicy.AcceptsRunningAck(state, "request-next", "participant-current", "Delta"));
        Check(!AndroidSessionPolicy.AcceptsRunningAck(state, "request-current", "participant-next", "Delta"));
        Check(!AndroidSessionPolicy.AcceptsRunningAck(state, "request-current", "participant-current", "Alpha"));
        Check(!AndroidSessionPolicy.AcceptsRunningAck(state, "", "participant-current", "Delta"));
        state.sessionState = "paused"; Check(!AndroidSessionPolicy.AcceptsRunningAck(state, "request-current", "participant-current", "Delta"));
        Check(AndroidSessionPolicy.ValidBodyProfile(20, 50, "MALE"));
        Check(AndroidSessionPolicy.ValidBodyProfile(250, 250, "FEMALE"));
        Check(!AndroidSessionPolicy.ValidBodyProfile(double.NaN, 170, "MALE"));
        Check(!AndroidSessionPolicy.ValidBodyProfile(70, double.PositiveInfinity, "FEMALE"));
        Check(!AndroidSessionPolicy.ValidBodyProfile(19.99, 170, "MALE"));
        Check(!AndroidSessionPolicy.ValidBodyProfile(70, 250.01, "FEMALE"));
        Check(!AndroidSessionPolicy.ValidBodyProfile(70, 170, null));
        LevelDefinition delta = LevelDefinition.CreateLevel3(); delta.RestrictToSensorFamily("Delta");
        Check(delta.AllowedTargetTypes.Length == 1 && delta.AllowedTargetTypes[0] == TargetType.Kick);
        Check(delta.ToughTargetChance == 0 && delta.MaxToughTargetChance == 0 && delta.RapidFireChance == 0 && delta.MaxRapidFireChance == 0);
        LevelDefinition alpha = LevelDefinition.CreateLevel1(); alpha.RestrictToSensorFamily("Alpha");
        Check(alpha.AllowedTargetTypes.Length == 1 && alpha.AllowedTargetTypes[0] == TargetType.Punch);
        Console.WriteLine("ANDROID_POLICY_HOST_PASS " + checks + " assertions; state fixtures only, no JNI or hardware execution.");
    }
}
