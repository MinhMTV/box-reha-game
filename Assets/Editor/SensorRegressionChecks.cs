using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>Deterministic regression checks; all readings below are SYNTHETIC / NOT EMPIRICAL DATA.</summary>
public static class SensorRegressionChecks
{
#if UNITY_EDITOR
    [UnityEditor.MenuItem("BoxReha/Run Sensor Regression Checks")]
#endif
    public static void RunAll()
    {
        var tests = new Action[] {
            BufferConsumesAndBounds, SimultaneousSidesStayIndependent, CooldownIsPerDevice,
            BufferedEventsUseArrivalTime, DuplicatesCannotReplay, StaleAndFutureSamplesRejected,
            InvalidComputedValuesRejected, IdentityAndQuantityAreExplicit,
            DisconnectReconnectRejectOldEvents, DisabledQueuesCannotReplay,
            RawHeuristicIsOptInAndEdgeTriggered, PayloadPreservesSemantics,
            KeyboardMappingHasHonestProvenance, SensorActionsHaveNoInventedForce, HeartRateIsSeparateAndFresh,
            ConnectionReadinessExpires
        };
        foreach (Action test in tests) test();
        Debug.Log("SENSOR_REGRESSION_PASS " + tests.Length + " deterministic checks; NOT VERIFIED WITH PHYSICAL HARDWARE.");
    }
    private static void Require(bool condition, string message)
    {
        if (!condition) throw new InvalidOperationException("Sensor regression: " + message);
    }
    private static SensorEventProcessor Processor()
    {
        var processor = new SensorEventProcessor();
        Require(processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", true), "left connect");
        Require(processor.SetConnection("right", "c1", SensorDeviceType.Alpha, BodySide.Right, "sdk_mock", true), "right connect");
        return processor;
    }
    private static SensorReading Reading(string device = "left", long sequence = 0, double received = 100)
    {
        return new SensorReading {
            SchemaVersion = 2, IsValid = true, HasTiming = true, IsComputedPunch = true,
            DeviceId = device, ConnectionId = "c1", SensorType = SensorDeviceType.Alpha,
            BodySide = device == "left" ? BodySide.Left : BodySide.Right, Provenance = "sdk_mock",
            EventId = device + sequence, Sequence = sequence, Timestamp = 1700000000 + received,
            SourceClock = "unix_seconds", ReceivedTimestamp = received,
            Quantity = "alpha.impact", Unit = "unknown", RawValue = 23, AlphaImpact = 23,
            ValidityReason = "synthetic_computed_valid", Detector = "sdk_computed_punch"
        };
    }
    private static void BufferConsumesAndBounds()
    {
        var buffer = new SensorDataBuffer(2);
        buffer.Push(Reading(sequence: 0)); buffer.Push(Reading(sequence: 1)); buffer.Push(Reading(sequence: 2));
        Require(buffer.DroppedCount == 1 && buffer.Count == 2, "bounded overflow");
        Require(buffer.TryPop(out SensorReading first) && first.Sequence == 1, "oldest retained consumed first");
        Require(buffer.TryPop(out SensorReading second) && second.Sequence == 2, "second consumed");
        Require(!buffer.TryPop(out _) && buffer.GetAverageAccelerationMagnitude(0) == 0, "empty/zero window safe");
        Require(buffer.GetLatest(-1).Length == 0, "negative request safe");
        bool threw = false;
        try { new SensorDataBuffer(0); } catch (ArgumentOutOfRangeException) { threw = true; }
        Require(threw, "invalid capacity rejected");
    }
    private static void SimultaneousSidesStayIndependent()
    {
        SensorEventProcessor processor = Processor();
        Require(processor.Enqueue(Reading(), 100) && processor.Enqueue(Reading("right"), 100), "simultaneous enqueue");
        List<SensorReading> actions = processor.ConsumeActions(100);
        Require(actions.Count == 2 && actions[0].DeviceId != actions[1].DeviceId, "both sides emitted");
        Require(processor.ConsumeActions(100.4).Count == 0, "no stale-buffer repeat");
    }
    private static void CooldownIsPerDevice()
    {
        SensorEventProcessor processor = Processor();
        processor.Enqueue(Reading(), 100); processor.ConsumeActions(100);
        processor.Enqueue(Reading(sequence: 1, received: 100.05), 100.05);
        processor.Enqueue(Reading("right", received: 100.05), 100.05);
        List<SensorReading> actions = processor.ConsumeActions(100.05);
        Require(actions.Count == 1 && actions[0].DeviceId == "right", "only same device refractory");
    }
    private static void BufferedEventsUseArrivalTime()
    {
        SensorEventProcessor processor = Processor();
        processor.Enqueue(Reading(), 100);
        processor.Enqueue(Reading(sequence: 1, received: 100.2), 100.2);
        Require(processor.ConsumeActions(100.4).Count == 2, "slow render frame retains distinct arrivals");
    }
    private static void DuplicatesCannotReplay()
    {
        SensorEventProcessor processor = Processor();
        SensorReading sample = Reading();
        processor.Enqueue(sample, 100); processor.ConsumeActions(100);
        Require(!processor.Enqueue(sample, 100.1), "duplicate sequence/id");
        sample.Sequence = 9;
        Require(!processor.Enqueue(sample, 100.1), "UUID dedup independent from transport sequence");
    }
    private static void StaleAndFutureSamplesRejected()
    {
        SensorEventProcessor processor = Processor();
        Require(!processor.Enqueue(Reading(), 100.6), "stale at ingress");
        Require(!processor.Enqueue(Reading(received: 101), 100), "future ingress clock");
        Require(processor.Enqueue(Reading(), 100), "fresh before slow consumer");
        Require(processor.ConsumeActions(100.6).Count == 0, "stale at consumption");
        SensorReading delayed = Reading(sequence: 1, received: 101);
        delayed.SourceAgeSeconds = 1;
        Require(!processor.Enqueue(delayed, 101), "native queue age counted");
    }
    private static void InvalidComputedValuesRejected()
    {
        SensorEventProcessor processor = Processor();
        SensorReading sample = Reading(); sample.IsValid = false;
        Require(!processor.Enqueue(sample, 100), "invalid SDK computation");
        sample = Reading(); sample.RawValue = float.NaN;
        Require(!processor.Enqueue(sample, 100), "NaN rejected");
        sample = Reading(); sample.HasTiming = false;
        Require(!processor.Enqueue(sample, 100), "missing timing rejected");
    }
    private static void IdentityAndQuantityAreExplicit()
    {
        SensorEventProcessor processor = Processor();
        SensorReading sample = Reading(); sample.BodySide = BodySide.Unknown;
        Require(!processor.Enqueue(sample, 100), "unknown side rejected");
        sample = Reading(); sample.SensorType = SensorDeviceType.Delta;
        Require(!processor.Enqueue(sample, 100), "family mismatch rejected");
        sample = Reading(); sample.Unit = "N";
        Require(!processor.Enqueue(sample, 100), "unsupported physical unit rejected");
        sample = Reading(); sample.Quantity = "delta.power_index";
        Require(!processor.Enqueue(sample, 100), "cross-family quantity rejected");
        sample = Reading(); sample.Provenance = "dynamics_sdk";
        Require(!processor.Enqueue(sample, 100), "mock cannot masquerade as physical");
    }
    private static void DisconnectReconnectRejectOldEvents()
    {
        SensorEventProcessor processor = Processor();
        processor.Enqueue(Reading(), 100);
        processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", false);
        Require(processor.ConsumeActions(100).Count == 0, "disconnect clears queue");
        Require(!processor.Enqueue(Reading(sequence: 1), 100), "disconnected data rejected");
        Require(!processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", true), "new epoch required");
        Require(processor.SetConnection("left", "c2", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", true), "new epoch accepted");
        Require(!processor.Enqueue(Reading(sequence: 1), 100), "old epoch rejected");
        SensorReading fresh = Reading(sequence: 1); fresh.ConnectionId = "c2";
        Require(processor.Enqueue(fresh, 100), "new epoch reading accepted");
        Require(!processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", false), "old disconnect ignored");
        Require(!processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", true), "old online epoch ignored");
        Require(processor.ConsumeActions(100).Count == 1, "new epoch survives delayed disconnect");
        SensorReading historical = Reading(sequence: 3, received: 99.9); historical.ConnectionId = "c2";
        Require(!processor.Enqueue(historical, 100), "historical punch rejected after reconnect");
    }
    private static void DisabledQueuesCannotReplay()
    {
        SensorEventProcessor processor = Processor();
        processor.Enqueue(Reading(), 100); processor.ClearPending();
        Require(processor.ConsumeActions(100).Count == 0 && !processor.Enqueue(Reading(), 100), "pause drops pending and remembers id");
    }
    private static void RawHeuristicIsOptInAndEdgeTriggered()
    {
        SensorEventProcessor processor = Processor();
        SensorReading sample = Reading(); sample.IsComputedPunch = false;
        sample.Quantity = "acceleration.magnitude"; sample.Unit = "m/s^2";
        sample.Acceleration = new Vector3(25, 0, 0); sample.RawValue = 25;
        sample.SourceClock = "device_relative_seconds"; sample.Timestamp = 0;
        processor.Enqueue(sample, 100);
        Require(processor.ConsumeActions(100).Count == 0, "raw telemetry not silently classified");
        processor.EnableAccelerationHeuristic = true;
        sample.Sequence = 1; sample.EventId = "raw1"; sample.ReceivedTimestamp = 100.2;
        processor.Enqueue(sample, 100.2);
        Require(processor.ConsumeActions(100.2).Count == 1, "rising edge detected");
        sample.Sequence = 2; sample.EventId = "raw2"; sample.ReceivedTimestamp = 100.4;
        processor.Enqueue(sample, 100.4);
        Require(processor.ConsumeActions(100.4).Count == 0, "sustained high acceleration not repeated");
    }
    private static void PayloadPreservesSemantics()
    {
        var payload = new DynamicsSensorPayload {
            sensorType = "Delta", bodySide = "Right", quantity = "delta.power_index", unit = "unknown",
            powerIndex = 17, impact = 50, peakForceBasedOnBaro = 400, timestamp = 0,
            timestampClock = "device_relative_seconds", isValid = true, areComputedValuesValid = false
        };
        SensorReading sample = payload.ToSensorReading(20, true);
        Require(sample.RawValue == 17 && sample.AlphaImpact == 50 && sample.AlphaPeakForceBasedOnBaro == 400,
            "no force/index fallback; secondary values retained");
        Require(sample.Timestamp == 0 && sample.ReceivedTimestamp == 20 && !sample.IsValid, "timestamp zero preserved; validity propagated");
        Require(DynamicsSensorPayload.ParseBodySide("right_hand") == BodySide.Unknown
            && DynamicsSensorPayload.ParseSensorType("some_delta_id") == SensorDeviceType.Unknown, "identity not guessed");
    }
    private static void KeyboardMappingHasHonestProvenance()
    {
        foreach (BodySide side in new[] { BodySide.Left, BodySide.Right })
        foreach (ActionType type in new[] { ActionType.Punch, ActionType.Kick })
        {
            PlayerActionEvent action = KeyboardActionFactory.Create(type, side);
            Require(action.ActionType == type && action.BodySide == side
                && action.Lane == (side == BodySide.Left ? LaneType.Left : LaneType.Right), "keyboard side/action mapping");
            Require(action.SourceType == InputSourceType.Keyboard && action.Provenance == "keyboard"
                && action.SensorDevice == SensorDeviceType.Unknown && action.IsValid && action.RawForce == 0,
                "keyboard provenance and no invented sensor");
        }
    }
    private static void SensorActionsHaveNoInventedForce()
    {
        PlayerActionEvent action = BleSensorInputProvider.CreateSensorAction(Reading());
        Require(action.IsValid && action.RawValue == 23 && action.RawForce == 0 && !action.NormalizationValid
            && action.Power == 1 && action.Unit == "unknown", "metric retained with neutral uncalibrated power");
        Require(action.Provenance == "sdk_mock" && action.SourceEventId == "left0"
            && action.SourceTimestamp == 1700000100 && action.ReceivedTimestamp == 100, "event source times and provenance preserved");
    }
    private static void HeartRateIsSeparateAndFresh()
    {
        var sample = new HRSample {
            EventId = "hr1", DeviceId = "hr", Provenance = "hr_mock", IsValid = true,
            SourceTimestamp = 1700000000, SourceClock = "unix_seconds", ReceivedTimestamp = 100, BeatsPerMinute = 90
        };
        Require(!HeartRateSampleValidator.IsFresh(sample, 100), "mock HR disabled by default");
        Require(HeartRateSampleValidator.IsFresh(sample, 100, allowMock: true), "explicit HR mock validation");
        Require(!HeartRateSampleValidator.IsFresh(sample, 106, allowMock: true), "stale HR rejected");
        sample.BeatsPerMinute = float.NaN;
        Require(!HeartRateSampleValidator.IsFresh(sample, 100, allowMock: true), "invalid HR rejected");
    }
    private static void ConnectionReadinessExpires()
    {
        SensorEventProcessor processor = Processor();
        processor.ExpireConnections(9);
        Require(processor.ConnectedCount == 2, "recent connection status remains ready");
        processor.ExpireConnections(11);
        Require(processor.ConnectedCount == 0, "stale connection status is not ready");
        Require(!processor.SetConnection("left", "c1", SensorDeviceType.Alpha, BodySide.Left, "sdk_mock", true, 11),
            "expired stream requires explicit new epoch");
    }
}
