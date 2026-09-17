# Dynamics SDK bridge contract v2

Status on 2026-09-17: **Android Kotlin collector and Unity C# boundary compile in the explicit COMPATIBILITY mode; physical hardware remains unverified.** The vendor-unchanged dependency blocker is retained historically in SDK_PACKAGE_BLOCKERS_2026-09-14.md. The intended deployment is the complete Unity game on Android, developed on Windows. There is no phone-to-PC gateway or Windows BLE port. iOS remains a forwarding scaffold.

The authoritative SDK is `C:\dynamics-sdk-main`, version **0.25.6**. The copy under this Unity repository is not the current authority. See [SENSOR_INTEGRATION_AUDIT.md](../../../SENSOR_INTEGRATION_AUDIT.md) for repository APIs and remaining gates.

## Endpoints

The persistent Unity object is `DynamicsSdkBridge`. Android `DynamicsUnityBridge.sendSensorData/sendPunch/sendDeviceState` and iOS `DynamicsUnityBridgeSendSensorData/SendPunch/SendDeviceState` forward JSON to:

- `ReceiveSensorDataJson`: raw telemetry; action detection disabled by default.
- `ReceivePunchJson`: SDK-computed, discrete Punch event.
- `ReceiveDeviceStateJson`: explicit per-device online/offline/error state.

The Android facade delegates initialization, discovery, pairing and the active SDK session to `DynamicsCollector.kt`. Its static JNI commands are:

- `initialize()`, `requestPermissions()`, `startScan()`, `stopScan()`.
- `selectParticipant(studyId)`, `setBodyProfile(studyId, weightKg, heightCm, gender)`.
- `pair(nearbyId, side)`, `unpair(deviceId)`; unpair removes the SDK database record and disconnects BLE.
- `startSession(family, requestId)`, `pauseSession()`, `resumeSession(requestId)`, `finishSession()`; legacy overloads without request IDs remain.
- `setApplicationPaused(paused)`, `shutdown()`.

`ReceiveNativeStatusJson` carries status schema 1: `state`, `code`, `message`, `initialized`, `permissionsGranted`, `profileReady`, `sessionState`, `devices`, `nearby`, `sdkVersion`, `profileReference`, `profileStudyId`, `sessionFamily`. Monotonic `statusSequence` excludes reordered callbacks; `controlRequestId` acknowledges only the caller's successfully confirmed running request. Device entries contain pseudonymous `id`, `name`, explicit `side`, SDK-derived `family`, `online`, `connectionId`, `isMock`, and `firmwareVersion`. Nearby IDs are temporary tokens; family remains `Unknown` until connected SDK data identifies it. The permission fragment preserves Unity's Activity. Android 12+ requests nearby-device scan/connect permissions; earlier versions request fine location for BLE discovery. The app never derives physical location from scanning. See [Android permission documentation](https://developer.android.com/develop/connectivity/bluetooth/bt-permissions).

The SDK `BodyProfile` is separate from the game's study profile and from force normalization. The pseudonymous study ID is its name. SDK 0.25.6 validates name length 3–50, weight 20–250 kg, height 50–250 cm, and `Gender.MALE` / `Gender.FEMALE`. No demographic values are prefilled or inferred. Participant changes clear readiness; active sessions must finish before profile or device changes. The SDK stores its body profile locally and retains finished sessions. Its internal use of these inputs in computed metrics is not independently established.

The collector uses `TrainingSessionSettings.Free(false)` to prevent automatic resume and `finishCurrentActiveSession=false` to preserve existing sessions. It calls `readyActiveTrainingSession`, explicitly resumes, then waits for the SDK's resumed state before acknowledging `running`. An existing session from another process is paused and must be explicitly finished. Observer errors stop forwarding; explicit initialization restarts registered lazy observers without duplicate subscriptions. Background entry immediately closes the forwarding gate, retires connection epochs, stops scanning and pauses the session. Foreground entry does not resume a workout automatically. SDK background disconnect timeout is one second. Status and device heartbeats are emitted every second; status heartbeats preserve outstanding errors.

Physical sessions reject mock peripherals, dummy impacts, battery mocks and `acceptAllPunches`. `setKeepAllPunchDetails(true)` preserves source samples. The collector forwards computed punches only; raw streaming and heuristics are not concurrently enabled. Rolling snapshots are deduplicated by actual punch UUID and checked against a fresh resume cutoff.

The native policy permits one or two uniquely sided online devices of the same SDK-reported family. Mixed families, a third device, offline paired devices and a family downgrade fail closed. This is the collector's explicit support boundary, not a claim that the hardware cannot support other configurations.

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

SDK `Punch.areComputedValuesValid` must be true. `Punch.timestamp` is the SDK arrival time of the first packet, not physical action onset. The Android collector preserves its Kotlin `Instant` as Unix seconds. It compares wall-clock progression against elapsed realtime from explicit resume, using an absolute 100 ms drift bound, and rejects future/pre-resume/over-500 ms events. It drops events with unqualified age and pauses on clock jumps. These are engineering policies, not measured hardware latency. Forwarding time never replaces the original timestamp.

All Android punch, device-state and status payloads include `emittedAndroidMonotonicSeconds`, sampled from `SystemClock.elapsedRealtimeNanos() / 1e9`. For punches this is the exact monotonic sample used when computing native source age. At Unity callback delivery, the bridge reads that same Android clock through JNI and rejects missing/nonfinite/future timing. It adds transport age to source age, preserving `NativeSourceAgeSeconds`, `NativeTransportAgeSeconds`, `HasNativeTransportTiming` and `EmittedAndroidMonotonicSeconds` in sensor evidence. Thus delayed `UnitySendMessage` delivery cannot relabel an old punch as fresh. Device/status delivery older than three seconds is rejected.

The Unity bridge independently sets `ReceivedTimestamp` to `Time.realtimeSinceStartupAsDouble`. No wall-clock timestamp is directly compared against Unity time. The accepted 0.5-second action age includes native source age, native-to-Unity transport age, and time in the Unity sensor queue. This is an engineering policy, not measured hardware latency or a clinical criterion.

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
- The native snapshot deduplicator also has an explicit 100,000-ID session limit. Saturation pauses with an error and requires finishing and starting a new SDK session. Native dedup resets only after successful creation of that new session; resume/reconnect never resets it. Unity's independent per-device process dedup remains in place.
- Cooldown is per physical device. Queued events compare their source arrival times, not render-frame times. Left/right devices can emit in one frame.
- Pausing/disabling discards pending events and retains dedup identity; raw detection must rearm after pause.
- Sensor `Power=1` is neutral gameplay damage; `NormalizationValid=false` until a real quantity/side-specific calibration is implemented. `RawForce=0` is a legacy compatibility field, not a measurement.
- Keyboard arrows and A/D use the common pipeline with `SourceType.Keyboard`, one event per key-down and no fictitious sensor family.
- HR has a separate sample interface/validator only. No HR adapter, corridor, feedback display or adaptation loop is active.

## Remaining integration and physical verification

1. Resolve and record the exact rich Gradle dependency graph. The actual standard build is currently blocked because `com.riseworld.launchpad.resource:resource:2.11.1` required by the supplied SDK is absent. A separately labelled diagnostic run with delivered 2.12.0 cannot qualify the unmodified SDK graph. No production substitution or bundle edit is performed. The supplied SDK uses Kotlin 2.3.21 / Java 17 and its AAR metadata requires Android compile API 36 or newer.
2. Obtain corrected Android SDK publications preserving the documented Kotlin API; even the alternate-graph diagnostic compiler fails on missing metadata/nesting attributes. Then build the Android plugin and complete Unity player. Standalone compiler/unit checks do not establish player or Bluetooth runtime correctness.
3. Verify actual pairing, repeated/rapid/simultaneous actions, dropout/reconnect, participant switches, process restart, background and latency on physical devices. SDK docs state firmware compatibility through 0.10.3; verify actual firmware before measurement.
4. Obtain a supported SDK mixed-family lifecycle before enabling a third sensor or mixed session.
5. Add raw streaming only as an independent explicit mode with verified punch-mode interaction.

Consult the current Android validation report for actual build/test results. No physical hardware result is implied here.

`Assets/Editor/DynamicsAndroidGradleIntegration.cs` configures only the generated export: it supplies Kotlin 2.3.21, adds the authoritative Maven repository (environment override `DYNAMICS_MAVEN_PATH`), ensures API 36 or newer in both Unity modules, and applies the documented AGP 9 external-Kotlin opt-outs. It preserves Unity's AGP/Gradle and rejects unsupported or unresolved configuration. AGP 7 from the old Unity 2022 default toolchain is deliberately rejected; the intended Unity 6.6 toolchain must be installed and validated. [Android AGP 9 migration documentation](https://developer.android.com/build/migrate-to-built-in-kotlin) explains the temporary `android.builtInKotlin=false` / `android.newDsl=false` settings. The host tests under `tests/android-export` check synthetic generated-file transformations only.
