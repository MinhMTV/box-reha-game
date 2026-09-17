using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Main-thread consumer with per-device queues. Clock values are supplied explicitly so
/// rejection/consumption can be tested without physical hardware or a running scene.
/// </summary>
public sealed class SensorEventProcessor
{
    private sealed class DeviceState
    {
        public string ConnectionId;
        public SensorDeviceType Type;
        public BodySide Side;
        public string Provenance;
        public bool Connected;
        public double LastHeartbeat;
        public readonly HashSet<string> RetiredConnections = new HashSet<string>();
        public long LastSequence = -1;
        public double LastEmitTime = double.NegativeInfinity;
        public bool AccelerationArmed = true;
        public readonly SensorDataBuffer Pending = new SensorDataBuffer(128);
        public readonly HashSet<string> SeenIds = new HashSet<string>();
        public double LastComputedTimestamp = double.NegativeInfinity;
    }

    private readonly Dictionary<string, DeviceState> devices = new Dictionary<string, DeviceState>();
    public double MaximumAgeSeconds { get; set; } = 0.5;
    public double CooldownSeconds { get; set; } = 0.35;
    public double ConnectionTimeoutSeconds { get; set; } = 10;
    public bool EnableAccelerationHeuristic { get; set; }
    public float PunchThreshold { get; set; } = 18f;
    public float KickThreshold { get; set; } = 16f;
    public int RejectedCount { get; private set; }
    public string LastRejection { get; private set; } = string.Empty;
    public int ConnectedCount
    {
        get { int count = 0; foreach (DeviceState state in devices.Values) if (state.Connected) count++; return count; }
    }
    public int MockConnectedCount
    {
        get { int count = 0; foreach (DeviceState state in devices.Values) if (state.Connected && state.Provenance == "sdk_mock") count++; return count; }
    }
    public int DroppedCount
    {
        get { int count = 0; foreach (DeviceState state in devices.Values) count += state.Pending.DroppedCount; return count; }
    }

    private readonly HashSet<string> forgottenEpochs = new HashSet<string>();
    public void ForgetDevice(string deviceId, string connectionId)
    {
        if(!devices.TryGetValue(deviceId,out DeviceState state) || state.ConnectionId != connectionId)return;
        if(!string.IsNullOrEmpty(connectionId))forgottenEpochs.Add(connectionId);
        state.Pending.Clear();devices.Remove(deviceId);
    }
    public bool SetConnection(string deviceId, string connectionId, SensorDeviceType type, BodySide side,
        string provenance, bool connected, double now = 0)
    {
        if(connected && (forgottenEpochs.Contains(connectionId) || forgottenEpochs.Count>=1024))return Reject("forgotten_or_retirement_limit");
        if (string.IsNullOrWhiteSpace(deviceId) || string.IsNullOrWhiteSpace(connectionId)
            || (type != SensorDeviceType.Alpha && type != SensorDeviceType.Delta)
            || (side != BodySide.Left && side != BodySide.Right) || !IsSensorProvenance(provenance) || !Finite(now))
            return Reject("invalid_connection_identity");
        if (!devices.TryGetValue(deviceId, out DeviceState state))
        {
            if (!connected) return Reject("unknown_disconnect");
            if (devices.Count >= 16) return Reject("device_limit");
            state = new DeviceState();
            devices.Add(deviceId, state);
        }
        if (!connected && state.ConnectionId != connectionId) return Reject("obsolete_disconnect");
        if (connected && state.RetiredConnections.Contains(connectionId)) return Reject("obsolete_connection");
        if (state.Connected && connected && state.ConnectionId == connectionId)
        {
            if (state.Type != type || state.Side != side || state.Provenance != provenance)
                return Reject("identity_changed_without_reconnect");
            state.LastHeartbeat = now;
            return true; // Repeated online notifications do not reset queue/dedup state.
        }
        if (connected && state.ConnectionId == connectionId)
            return Reject("reconnect_requires_new_connection_id");
        if (state.ConnectionId != null && state.ConnectionId != connectionId)
            state.RetiredConnections.Add(state.ConnectionId);
        state.Pending.Clear();
        state.ConnectionId = connectionId;
        state.Type = type;
        state.Side = side;
        state.Provenance = provenance;
        state.Connected = connected;
        state.LastHeartbeat = now;
        state.LastSequence = -1;
        state.LastEmitTime = double.NegativeInfinity;
        state.AccelerationArmed = true;
        return true;
    }

    public void ExpireConnections(double now)
    {
        foreach (DeviceState state in devices.Values)
        {
            if (state.Connected && (!Finite(now) || now < state.LastHeartbeat
                || now - state.LastHeartbeat > ConnectionTimeoutSeconds))
            {
                state.Connected = false;
                state.Pending.Clear();
                Reject("connection_heartbeat_expired");
            }
        }
    }

    public bool Enqueue(SensorReading reading, double now)
    {
        if (!Finite(MaximumAgeSeconds) || MaximumAgeSeconds < 0) return Reject("invalid_freshness_configuration");
        if (reading.SchemaVersion != 2 || !reading.IsValid || !reading.HasTiming)
            return Reject("invalid_or_incomplete_contract");
        if (string.IsNullOrWhiteSpace(reading.DeviceId) || !devices.TryGetValue(reading.DeviceId, out DeviceState state)
            || !state.Connected || reading.ConnectionId != state.ConnectionId)
            return Reject("device_not_connected");
        if (reading.SensorType != state.Type || reading.BodySide != state.Side || reading.Provenance != state.Provenance)
            return Reject("identity_mismatch");
        if (string.IsNullOrWhiteSpace(reading.EventId) || reading.Sequence < 0 || reading.Sequence <= state.LastSequence
            || state.SeenIds.Contains(reading.EventId))
            return Reject("duplicate_or_out_of_order");
        if (!Finite(reading.Timestamp) || reading.Timestamp < 0
            || (reading.SourceClock != "unix_seconds" && reading.SourceClock != "device_relative_seconds")
            || (reading.IsComputedPunch && (reading.SourceClock != "unix_seconds" || reading.Timestamp <= 0)))
            return Reject("invalid_source_clock");
        if (reading.IsComputedPunch && reading.Timestamp < state.LastComputedTimestamp)
            return Reject("historical_computed_event");
        if (!Finite(now) || !Finite(reading.ReceivedTimestamp) || !Finite(reading.SourceAgeSeconds)
            || reading.SourceAgeSeconds < 0 || now < reading.ReceivedTimestamp
            || Age(reading, now) > MaximumAgeSeconds)
            return Reject("stale_or_invalid_age");
        if (!Finite(reading.Acceleration) || !Finite(reading.Gyroscope)
            || !Finite(reading.RawValue) || reading.RawValue < 0
            || !Finite(reading.AlphaImpact) || !Finite(reading.AlphaPeakForceBasedOnBaro)
            || !Finite(reading.DeltaPowerIndex) || !Finite(reading.PeakAcceleration)
            || !Finite(reading.PeakVelocity) || !Finite(reading.Displacement)
            || !Finite(reading.PunchDurationSeconds) || !Finite(reading.ContactDurationSeconds)
            || (reading.HasMagnetometer && !Finite(reading.Magnetometer))
            || (reading.HasBarometer && !Finite(reading.Barometer)))
            return Reject("nonfinite_quantity");
        if (!ValidQuantity(reading)) return Reject("quantity_family_or_unit_mismatch");
        state.LastSequence = reading.Sequence;
        // Retained across reconnects so repeated SDK statistics snapshots cannot replay punches.
        // Bound memory by failing closed; a new study/game process starts a new audit scope.
        if (state.SeenIds.Count >= 100000) return Reject("event_identity_capacity_reached");
        state.SeenIds.Add(reading.EventId);
        if (reading.IsComputedPunch) state.LastComputedTimestamp = reading.Timestamp;
        state.Pending.Push(reading);
        return true;
    }

    public List<SensorReading> ConsumeActions(double now)
    {
        var actions = new List<SensorReading>();
        if (!Finite(CooldownSeconds) || CooldownSeconds < 0 || !Finite(MaximumAgeSeconds) || MaximumAgeSeconds < 0)
        { ClearPending(); Reject("invalid_detection_configuration"); return actions; }
        foreach (DeviceState state in devices.Values)
        {
            while (state.Pending.TryPop(out SensorReading reading))
            {
                if (!state.Connected || !Finite(now) || now < reading.ReceivedTimestamp || Age(reading, now) > MaximumAgeSeconds)
                { Reject("stale_at_consumption"); continue; }
                bool detected = reading.IsComputedPunch;
                if (!detected && EnableAccelerationHeuristic)
                {
                    float threshold = state.Type == SensorDeviceType.Delta ? KickThreshold : PunchThreshold;
                    float magnitude = reading.Acceleration.magnitude;
                    if (magnitude < threshold * 0.6f) state.AccelerationArmed = true;
                    detected = state.AccelerationArmed && magnitude >= threshold;
                    if (detected) state.AccelerationArmed = false;
                    reading.Detector = "acceleration_threshold_unvalidated";
                }
                if (!detected) continue;
                // Compare arrival times, not render-frame times: distinct buffered events must
                // survive one slow frame, while each physical device has its own refractory period.
                double actionTime = reading.ReceivedTimestamp - reading.SourceAgeSeconds;
                if (actionTime - state.LastEmitTime < CooldownSeconds)
                { Reject("device_cooldown"); continue; }
                state.LastEmitTime = actionTime;
                actions.Add(reading);
            }
        }
        actions.Sort((left, right) => left.ReceivedTimestamp.CompareTo(right.ReceivedTimestamp));
        return actions;
    }

    public void ClearPending()
    {
        foreach (DeviceState state in devices.Values)
        {
            state.Pending.Clear();
            // Raw movement must return to baseline after pause; no held acceleration at resume.
            state.AccelerationArmed = false;
        }
    }

    private static bool ValidQuantity(SensorReading reading)
    {
        if (!reading.IsComputedPunch)
            return reading.Quantity == "acceleration.magnitude" && reading.Unit == "m/s^2";
        if (reading.Unit != "unknown") return false; // SDK 0.25.6 docs do not specify these units.
        return reading.SensorType == SensorDeviceType.Alpha
            ? reading.Quantity == "alpha.impact" || reading.Quantity == "alpha.peak_force_baro"
            : reading.SensorType == SensorDeviceType.Delta && reading.Quantity == "delta.power_index";
    }
    private static double Age(SensorReading reading, double now) => reading.SourceAgeSeconds + now - reading.ReceivedTimestamp;
    private bool Reject(string reason) { RejectedCount++; LastRejection = reason; return false; }
    public static bool IsSensorProvenance(string value) => value == "dynamics_sdk" || value == "sdk_mock";
    public static bool Finite(double value) => !double.IsNaN(value) && !double.IsInfinity(value);
    private static bool Finite(Vector3 value) => Finite(value.x) && Finite(value.y) && Finite(value.z);
}
