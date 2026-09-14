# ALPHA / DELTA topology investigation

Date: 2026-09-14. No physical topology has been demonstrated. The APK includes a compiled collector for one device or one left/right pair of one family. A source-level guard is not a statement about the maximum capacity of the Bluetooth radio.

## Evidence beyond public documentation

Inspection used actual Android AAR bytecode, descriptors, model constructors, repository ownership and database methods. Files are under `vendor-compat/dynamics-0.25.6/evidence`.

- `di-ownership-signatures.txt`: SDK DI exposes static repository getters backed by static Lazy instances. Database and GloveManager accessors are private. Repeated `initSdk` calls are not independent per-family SDK contexts.
- `session-ownership-bytecode.txt`: TrainingSessionRepository owns one `MutableStateFlow` active session ID; state/stats flows share that repository. `readyActiveTrainingSession` accepts one `TrainingSessionSensorType`, not a set or per-device map.
- `multi-sensor-bytecode.txt`: TrainingSession stores one glovePairId and one sensorType. GloveManager separately owns peripherals and per-peripheral observation methods. Pairing is serialized and persists through `Database.insertOrUpdatePeripheral`; scanning itself was not proven to reject mixed advertising devices.
- `db-initializeTrainingSession.txt`: the actual database method checks the glove pair list and fails for multiple pairs, no pair or an existing ongoing session. These are bytecode error branches, not merely documentation prose.
- `raw-sensor-bytecode.txt`: SensorDataRepository offers `observeSensorData(PeripheralId)` and `observeSensorDataFromAllGloves()`. The latter observes the database peripheral flow and creates a `channelFlow`; it is separate from TrainingSessionRepository's computed statistics flow.
- `session-ownership-bytecode.txt`: GloveModeDto has Single/Double variants, with one or two peripheral DTOs. The training sensor enum contains ALPHA and DELTA, with no MIXED option.
- `db-topology-internals.txt`: readiness writes one sensor type and binds the required body profile to a training session.
- `probe/java/RawApiProbe.java`: raw-all, computed statistics and active state entry points compile against actual Android dependencies. Merely constructing a Flow does not test subscription or firmware behavior.

## T1–T7 matrix

| Topology | Application policy fixture | Actual SDK/API finding | Physical runtime |
|---|---|---|---|
| T1 one ALPHA | accepts | Single model and ALPHA session API compile | not tested |
| T2 ALPHA left + right | accepts | Double model, one ALPHA session | not tested |
| T3 one DELTA | accepts | Single model and DELTA session API compile | not tested |
| T4 DELTA left + right | accepts | Double model, one DELTA session | not tested |
| T5 ALPHA left + DELTA left | rejects duplicate side | One family per computed session; raw route exists separately | not tested |
| T6 ALPHA left/right + DELTA left | rejects third device | Multiple pairs rejected by current DB session initialization | not tested |
| T7 ALPHA left/right + DELTA left/right | rejects third/fourth devices | Multiple pairs and parallel active session paths rejected | not tested |

All seven deterministic application-policy tests pass. Existing mixed-family tests also reject an ALPHA-left/DELTA-right pair. These tests execute our guard, **not** the SDK's database or BLE stack. Native compiler evidence applies to the collector implementation, not to a physical topology.

## Alternative paths assessed

**Multiple active sessions in one SDK:** contradicted by the database ongoing-session branch and single active-session state holder. Creating more collector objects would share these objects and cannot provide an independent family session.

**Multiple isolated SDK instances:** public DI exposes singletons; no supported context factory, independent database selection or per-instance lifecycle is exposed through initSdk. Manually constructing lower-level databases/managers would require replacing SDK ownership and lifecycle, not a narrow compatibility adapter. No such bypass is deployed.

**ALPHA computed + DELTA raw:** the raw data API is real and compiles, so this remains a potential experimental path. It does not itself provide DELTA power-index events, prove simultaneous firmware modes or bind a third device to the existing computed session. Without hardware, the current package cannot establish that concurrent subscriptions produce the required streams reliably. No raw acceleration heuristic is silently substituted for computed DELTA events.

**Low-level multi-peripheral ownership:** GloveManager has per-device flows and a peripheral manager; no global two-connection radio limit was demonstrated. Its database pairing and computed session constraints are the proven narrower limits. Raw multi-device logging needs a separate explicit experiment with vendor-supported firmware mode control and physical devices.

## Required hardware sequence

Install/launch the signed compatibility APK on an authorized Android device. Verify startup and permissions first, then T1 and T3 independently, T2 and T4 with unique physical sides, raw/computed concurrency on T5, then T6/T7 only if a supported acquisition route is established. Record device model, Android version, firmware, SDK mode, identity/epoch, quantity, timestamps, event counts, disconnect and background behavior. Maximum demonstrated topology currently: **none**.
