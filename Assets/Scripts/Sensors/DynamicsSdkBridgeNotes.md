# Dynamics SDK bridge contract v2

Status on 2026-09-13: **Unity C# boundary implemented and host logic tested; native SDK collector absent; NOT VERIFIED WITH PHYSICAL HARDWARE.**

The authoritative SDK is `C:\dynamics-sdk-main`, version **0.25.6**. The copy under this Unity repository is not the current authority. See [SENSOR_INTEGRATION_AUDIT.md](../../../SENSOR_INTEGRATION_AUDIT.md) for repository APIs and remaining gates.

## Endpoints

The persistent Unity object is `DynamicsSdkBridge`. Android `DynamicsUnityBridge.sendSensorData/sendPunch/sendDeviceState` and iOS `DynamicsUnityBridgeSendSensorData/SendPunch/SendDeviceState` forward JSON to:

- `ReceiveSensorDataJson`: raw telemetry; action detection disabled by default.
- `ReceivePunchJson`: SDK-computed, discrete Punch event.
- `ReceiveDeviceStateJson`: explicit per-device online/offline/error state.

These helpers **do not initialize, discover, pair, subscribe to, or run the SDK**.

## Identity and lifecycle

A collector must send an online state before readings. All identity fields are explicit; neither side nor family is inferred from a name, numeric value or default.

```json
{
  "schemaVersion": 2,
  "deviceId": "pseudonymous-device-id",
  "connectionId": "new-uuid-for-this-connection",
  "sensorType": "Alpha",
  "bodySide": "Left",
  "provenance": "dynamics_sdk",
  "status": "online"
}
```

Allowed provenance: `dynamics_sdk` or `sdk_mock` (derived from SDK peripheral mock state).
Allowed family: `Alpha`/`Delta`; side: `Left`/`Right`.
Send offline/error promptly, and repeat the online heartbeat at least every 5 seconds.
Unity expires connection readiness after 10 seconds without a heartbeat. Reconnect or timeout recovery requires a new connection UUID. Delayed states/readings from retired connection UUIDs are rejected.

Device IDs should be pseudonymous aliases. Keep the mapping to SDK peripheral UUIDs privately in the collector. Never export a BLE MAC address or player name as a research device ID.

## Computed event example

The following values are **SYNTHETIC / NOT EMPIRICAL DATA**. This is an example contract, not a measured result.

```json
{
  "schemaVersion": 2,
  "deviceId": "pseudonymous-device-id",
  "connectionId": "new-uuid-for-this-connection",
  "eventId": "sdk-punch-uuid",
  "sequence": 1,
  "sensorType": "Alpha",
  "bodySide": "Left",
  "provenance": "sdk_mock",
  "isValid": true,
  "areComputedValuesValid": true,
  "validityReason": "sdk_computation_valid",
  "timestamp": 1700000000.25,
  "timestampClock": "unix_seconds",
  "hasTiming": true,
  "sourceAgeSeconds": 0.08,
  "quantity": "alpha.impact",
  "unit": "unknown",
  "impact": 23.0,
  "peakForceBasedOnBaro": 180.0,
  "peakAcceleration": 24.0,
  "peakVelocity": 2.0,
  "displacement": 0.4,
  "punchDurationSeconds": 0.3,
  "contactDurationSeconds": 0.05
}
```

The online message and event must use the **same** provenance, side, family, device and connection identifiers. To replay this synthetic example, its online state must also use `sdk_mock`.

For ALPHA, explicitly select `alpha.impact` or `alpha.peak_force_baro`. For DELTA select `delta.power_index` with `powerIndex`. Secondary SDK fields remain in `SensorEvidence`. There is no fallback between quantities and no acceleration × body-weight calculation. SDK-generated units for these computed fields are not specified in the inspected API pages: use `unknown`. No Newton, joule or watt label is claimed.

SDK `Punch.areComputedValuesValid` must be true. A source `Punch.timestamp` is an SDK arrival timestamp for the first packet, not the onset of the physical action. The collector must preserve it as Unix seconds and attach a separately qualified native source age. `sourceAgeSeconds` measures delay since that source event using a qualified native clock alignment; if this age cannot be established, send `hasTiming:false`, and Unity rejects gameplay use. Do not substitute the forwarding time for the original timestamp.

The Unity bridge independently sets `ReceivedTimestamp` to `Time.realtimeSinceStartupAsDouble`. No wall-clock timestamp is directly compared against Unity time. Default accepted age is 0.5 seconds, including native source age plus time in the Unity queue. This is an engineering freshness policy, not a measured hardware latency or clinical criterion.

## Raw telemetry

Raw messages require the same version/identity/validity/timing fields and additionally:

- `quantity:"acceleration.magnitude"`, `unit:"m/s^2"`; `ax,ay,az` preserve SDK acceleration.
- `gx,gy,gz`: **degrees/s**.
- Optional `hasMagnetometer,mx,my,mz`: microtesla; optional `hasBarometer,barometerPa`: pascal.
- `imuSamplingRateHz,barometerSamplingRateHz,magnetometerSamplingRateHz`.
- `bleCounter,sampleIndex,relativeTimeCounterSeconds`.
- `timestampClock:"device_relative_seconds"` for the original device time axis.

The SDK's coarse counter advances in 100 ms ticks; several packets may have the same time. Emit a unique event ID and increasing `sequence` for every forwarded sample. Preserve the BLE counter, within-packet sample index and rate. Do not resample magnetometer/barometer into IMU slots or assume all sensors share a synchronized time axis. Derivation of sub-packet timing requires an explicit qualified native mapping.

Raw telemetry is consumed without generating actions by default. The inspector option `enableAccelerationHeuristic` enables an **unvalidated** high-threshold crossing detector with a below-60%-threshold rearm requirement. It is not SDK punch/kick accuracy evidence. Computed SDK punches should be the gameplay source; do not enable simultaneous raw heuristic events for the same physical action.

## Gameplay and measurement boundaries

- ALPHA events map to Punch; DELTA events map to Kick under the app's configured placement assumption. The SDK calls both objects Punch. DELTA placement/kick recognition is not validated by this mapping.
- Per-device queues hold 128 samples; oldest entries are overwritten with an overflow counter.
- Each accepted UUID is consumed at most once in the current process, including across reconnect. Sequence rejects out-of-order transport events. More than 100,000 event identities per device fails closed.
- Cooldown is per physical device. Queued events compare their source arrival times, not render-frame times. Left/right devices can emit in one frame.
- Pausing/disabling discards pending events and retains dedup identity; raw detection must rearm after pause.
- Sensor `Power=1` is neutral gameplay damage; `NormalizationValid=false` until a real quantity/side-specific calibration is implemented. `RawForce=0` is a legacy compatibility field, not a measurement.
- Keyboard arrows and A/D use the common pipeline with `SourceType.Keyboard`, one event per key-down and no fictitious sensor family.
- HR has a separate sample interface/validator only. No HR adapter, corridor, feedback display or adaptation loop is active.

## Required native collector work

1. Resolve the SDK dependency graph using rich Gradle metadata, or package the iOS framework with its platform prerequisites.
2. Initialize SDK once, then obtain repositories; propagate permissions, discovery, pairing, online/error and background states.
3. Subscribe/unsubscribe flows with platform lifecycle; cancel scan subscriptions when discovery ends.
4. Create/read/ready/pause/resume/finish the active SDK session deliberately. Do not delete other persisted sessions.
5. Observe active session statistics, deduplicate Punch UUIDs, and exclude historical snapshot entries before forwarding.
6. Observe raw sensor streams per peripheral, preserving rate/counter/channel semantics.
7. Qualify clock alignment/source age, connection heartbeats, side assignment and mock provenance.
8. Resolve whether one active SDK session supports mixed ALPHA/DELTA input; the inspected ready-session enum exposes separate ALPHA or DELTA values.
9. Run mobile build, actual pairing, repeated/rapid/simultaneous actions, dropout/reconnect, pause/background and latency qualification with physical devices.

No successful native build or hardware result is implied by this document.
