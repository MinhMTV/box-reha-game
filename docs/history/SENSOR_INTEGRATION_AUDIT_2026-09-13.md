> Historical snapshot — current behavior is documented in [GAME_STATUS.md](../../GAME_STATUS.md) and [SENSOR_INTEGRATION_AUDIT.md](../../SENSOR_INTEGRATION_AUDIT.md). Relative evidence paths in the original text are game-root-relative.

# Sensor integration audit

Date: 2026-09-13. Baseline inspected read-only: `8b736f6b7e96615231a6808fb154ec9814214dbb`.
Sensor/input implementation commit: `548ac7d`. The host harness also links concurrently reviewed gameplay/logger source; final repository commits and the source hash manifest identify that combined test input.
Current project: `E:\Programming Projekte\box-reha-game`. Authoritative SDK: `C:\dynamics-sdk-main` (**0.25.6**).

## Status

| Channel | Current level | Evidence boundary |
|---|---|---|
| RD ALPHA | Unity boundary implemented; host mock logic tested | Native SDK collector and mobile build absent; physical hardware unverified |
| RD DELTA | Unity boundary implemented; host mock logic tested | App maps configured DELTA to kick; physical placement/classification and mixed-session support unverified |
| Heart rate | Separate sample/provider interface and validator scaffold | No transport adapter, active HR UI or adaptation controller |

**NOT VERIFIED WITH PHYSICAL HARDWARE. Not study ready for a sensor or HR evaluation.**

## Initial P0/P1 findings and resolution

Line numbers in this table refer to the inspected baseline commit; current replacements are named separately.

| Priority | Initial finding and evidence | Resolution |
|---|---|---|
| P0 | `BleSensorInputProvider.cs:177-239`: one global buffer/cooldown, latest high sample never consumed; repeated ghost hits and cross-device peaks | Replaced by `SensorEventProcessor`: bounded per-device consumable queues, independent refractory state, dedup UUID/sequence, freshness checks |
| P0 | `BleSensorInputProvider.cs:242-260`: keyboard simulation emitted Sensor source | Shared keyboard factory emits Keyboard, no invented device family; one key-down event |
| P0 | `BleSensorInputProvider.cs:272-295`: impact/force/DELTA index interchange and weight × acceleration estimate | Removed. Explicit quantity + unknown SDK unit; neutral uncalibrated gameplay power |
| P0 | `DynamicsSdkBridge.cs:215-224`: selected max between DELTA index and ALPHA-style force, validity lost | Version 2 payload validates family/quantity, computed validity and finite values; original components retained |
| P0 | `DynamicsSdkBridge.cs:155,222`: missing timestamps silently replaced; original time discarded when action created | Original source clock/time preserved separately from Unity receipt/delivery; explicit native source-age qualification required |
| P0 | Android Java/iOS mm only forward strings; no SDK dependencies, collectors, native lifecycle or connect messages | Truthful integration gate retained; explicit per-device state endpoint added. Native collector remains external implementation work |
| P1 | `ISensorDataProvider.cs:44` claimed rad/s although SDK gyroData is degrees/s | Corrected contract/documentation; no unsupported conversion |
| P1 | `SensorDataBuffer` claimed thread safety without locking and divided by zero for zero window | Synchronized ring buffer, consumed entries, bounded accounting, safe empty/window handling |
| P1 | No separate HR contract/validation | Inactive `HRSample` / `IHeartRateProvider` / freshness validator; no adaptation claimed |

## SDK source evidence

All paths below are relative to `C:\dynamics-sdk-main\docs`. These are local generated API documents, not inferred library methods.

| SDK surface | Exact documentation path | Verified behavior |
|---|---|---|
| Initialization | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.di/init-sdk.html` | `initSdk(DynamicsSettings,...)` must precede repository access |
| Discovery/pairing | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.repository/-pairing-repository/index.html` | Observe scannerState, subscribe nearbyGloves to scan, pair selected glove, unsubscribe to stop scanning; errors include missing BLE permissions |
| Device status/identity | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.repository/-glove-repository/index.html`; `dynamics-models/com.riseworld.dynamics.models/-peripheral-dto/index.html` | observeGloves/observeGloveById, peripheral UUID/side, isMock, online/connecting/offline errors |
| Raw flow | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.repository/-sensor-data-repository/index.html` | observeSensorData(peripheralId): Flow<List<SensorDataPacket>>; iOS observeSensorDataNative; convenience all-gloves flow |
| Raw units/timing | `dynamics-models/com.riseworld.dynamics.models.ble.data/-sensor-data-packet/index.html` | acc m/s², gyro deg/s, mag µT, baro Pa; distinct channel rates; no assumed normalized cross-sensor axis; relative time counter has 100 ms ticks and repeats within a tick |
| Computed Punch | `dynamics-models/com.riseworld.dynamics.models.domain.punch/-punch/index.html` | UUID, peripheral UUID, side, timestamp Instant at first-packet SDK arrival, areComputedValuesValid, speed, power |
| ALPHA/DELTA power | `dynamics-models/com.riseworld.dynamics.models.domain.punch/-power/index.html`; `-power/-alpha/index.html`; `-power/-delta/index.html` | Alpha uses pressure-derived impact/peakForceBasedOnBaro; Delta uses acceleration-derived powerIndex. Computed units not specified on these pages |
| Speed | `dynamics-models/com.riseworld.dynamics.models.domain.punch/-speed/index.html` | punchDuration, contactDuration, peakAcceleration, peakVelocity, displacement; iOS duration wrappers in nanoseconds |
| Punch repository | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.repository/-punch-repository/index.html` | Database retrieval by ID, not an independent live punch stream |
| Session lifecycle | `dynamics-multiplatform/com.riseworld.dynamics.multiplatform.repository/-training-session-repository/index.html` | One active session required to obtain/persist punches; initialize, ready, toggle pause/resume, finish; autoResume requires conscious policy |
| Live punches | `dynamics-models/com.riseworld.dynamics.models.domain.session/-training-session-stats/index.html` | activeTrainingSessionStats.punches list; latest last; snapshots must be deduplicated |
| Sensor mode | `dynamics-models/com.riseworld.dynamics.models.domain.session/-training-session-sensor-type/index.html` | readyActiveTrainingSession takes ALPHA or DELTA, no combined enum value; mixed-family operation requires vendor/physical qualification |

The docs state HIGH sampling mode currently, but code must preserve declared packet rates. No numerical rate was guessed from that label. ALPHA/DELTA are different measurement families; equality of their normalized gameplay values would not establish equality of physical quantities.

## Native build gates

- The Android library currently has no Dynamics dependency or Kotlin flow collector. The iOS helper does not initialize or link a functioning collector.
- The supplied Android `dynamics-multiplatform-android/0.25.6` POM lists several launchpad dependency versions as 0.25.6, whereas rich `.module` metadata requests resource 2.11.1, BLE 0.24.0 and kable 0.8.0. The matching local `resource/resource/2.11.1` directory is absent; the bundle has resource 2.12.0. This is a dependency-resolution gate, not evidence that Gradle was run or failed. Honor module metadata and verify vendor-supported resolution instead of silently replacing versions.
- Native collector clock alignment must establish age of the SDK event, whose timestamp is first-packet arrival, before Unity accepts it.
- DELTA is mapped to Kick by application policy and configured placement. SDK Punch data alone does not establish kick classification accuracy.
- Mixed ALPHA/DELTA within a single active SDK training session is unresolved.
- Physical sensor availability and platform permission/connection qualification remain required.

## Implemented technical contract

See [DynamicsSdkBridgeNotes.md](../../Assets/Scripts/Sensors/DynamicsSdkBridgeNotes.md) for complete JSON and collector obligations.

Current code: `Assets/Scripts/Sensors/SensorEventProcessor.cs` (queue/lifecycle/validation), `DynamicsSdkBridge.cs` (v2 payload), `BleSensorInputProvider.cs` (action mapping), `Assets/Scripts/Data/PlayerActionEvent.cs` (measurement evidence), `HeartRateChannel.cs` (independent HR).

The contract preserves source UUID, device alias, connection epoch, side/family, provenance, clock/time, receipt time, native age, validity, quantity/unit and original SDK components. Unknown/invalid identities and stale samples fail closed. Raw acceleration detection is explicitly unvalidated and off by default. Default freshness is 0.5 s, connection heartbeat timeout 10 s, queue capacity 128/device, identity capacity 100,000/device/process. Serialized GameConfig controls action cooldown; these policies require qualification before a sensor study.

The saved Game scene has sensor keyboard simulation disabled; opting into the sensor source does not implicitly enable keyboard events.

Keyboard is one event per key-down through the same abstract action pipeline. Pause disables forwarding and clears pending input; repeated/disconnected/retired streams cannot produce ghost actions. Sensor data never receives demographic force normalization.

## Verification evidence

Executed on Windows with .NET SDK **10.0.112**:

```powershell
dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release
```

Observed exit code **0**, output:

```text
HOST LOGIC TESTS: narrow Unity API stubs; not a Unity compile or physical sensor test.
SENSOR_REGRESSION_PASS 16 deterministic checks; NOT VERIFIED WITH PHYSICAL HARDWARE.
HOST_ADDITIONAL_PASS 3 checks (provider key transitions, concurrent buffer, explicit routing).
GAMEPLAY_HOST_PASS 5 production rule/statistics checks; not Unity runtime tests.
LOGGER_HOST_PASS 1 production JSONL lifecycle/privacy check; SYNTHETIC / NOT EMPIRICAL DATA.
HISTORY_HOST_PASS 1 production IO preservation/profile-filter check; SYNTHETIC / NOT EMPIRICAL DATA.
```

Fixtures in the check source are **SYNTHETIC / NOT EMPIRICAL DATA**. Sixteen sensor groups cover queue consumption/overflow, simultaneous sides, independent cooldown, buffered timing, UUID/sequence replay, stale/future/native age, invalid values, family/unit/provenance mismatch, disconnect/reconnect/old state, pause, raw opt-in/edge detection, SDK mapping, keyboard identity, neutral uncalibrated action, HR validation and heartbeat expiry. Three host groups exercise keyboard key transitions, producer/consumer buffer accounting and explicit routing without silent fallback. Five host gameplay groups cover mapping, timing boundaries/nonfinite windows, repeated same-side heavy rules, combo caps and statistics definitions/reset. A final group executes the actual production logger lifecycle and checks privacy and synthetic labelling (26 groups total including the additional history preservation group).

Actual stdout: [sensor-host-checks.txt](../../artifacts/validation/sensor-host-checks.txt). The production logger emitted [production-logger.synthetic.jsonl](../../artifacts/validation/synthetic/production-logger.synthetic.jsonl) through typed host fixtures; the analysis pipeline replayed it successfully in [production-logger.replay.json](../../artifacts/validation/synthetic/production-logger.replay.json). These artifacts are explicitly synthetic, not a played session or participant evidence.

Only `SensorRegressionChecks.RunAll` is exposed as a Unity editor menu/executeMethod; that Unity execution has **not** run. The host stubs intentionally do not emulate scene lifecycle, physics, Unity JSON serialization, native/BLE timing or mobile platforms. A full Unity compile/build and actual screenshots remain required.

## Independent technical red-team review

| Problem | Severity | Evidence | Resolution status |
|---|---|---|---|
| Initial ghost hits/provenance/quantity ambiguity | P0 | Baseline findings above | Corrected and host logic regression checked |
| Unbounded/NaN gameplay half-window accepted | P1 | Review of GameplayRules.Timing during integration | Reported to gameplay owner, finite guard implemented and host boundary checks pass |
| Legacy mixed-unit force aggregate API could be reused | P1 | Review of GameSessionStats.TrackForce during integration | Reported to gameplay owner; unused API/fields removed |
| Router silently changed input source when a selected component was absent | P1 | Coordinator review of InputProviderRouter.SelectProvider | Explicit unavailable state and host routing/menu/pause checks added |
| History Save accepted incomplete incoming identity and could replace unreadable data | P1 | Coordinator/gameplay/sensor cross-review of SessionHistoryStore | Gameplay owner guards both IDs and aborts on load error; production IO host test preserves existing bytes |
| Unity scene/mobile/hardware tests absent | P0 for study | No executable Unity editor/device tests performed | External qualification remains open |
| Native session/clock/dependency integration absent | P0 for sensor study | SDK and plugin code audit | Exact integration contract prepared; no fabricated implementation claim |

## Next sensor tasks (13 September baseline, superseded by Android continuation below)

1. Install/locate Unity 2022.3.62f3, run real editor checks, build keyboard prototype and inspect scene behavior.
2. Resolve SDK dependency packaging and mixed-session supported modes with vendor documentation/hardware.
3. Implement a platform-native collector using the exact repository lifecycle and v2 contract.
4. Qualify source-age alignment, heartbeat/background behavior, side placement and raw/computed event dedup.
5. Run physical ALPHA and DELTA evaluation with independently annotated events and hardware latency measurements.
6. Implement metric-specific, side-specific calibration with provenance and persistence before normalized metric feedback.
7. Add HR adapter/adaptation only after approved study scope and actual valid HR data exist.

## Android continuation, 14 September 2026

The user selected Windows development with the complete game/SDK runtime on Android. Native Kotlin acquisition, permission/pairing/profile/session lifecycle, Unity request acknowledgements, same-family one/two-device modes and touch controls are now implemented in source. See `DynamicsSdkBridgeNotes.md`, `GAME_STATUS.md` and `ANDROID_VALIDATION_2026-09-14.md` for current findings. The earlier statement that native endpoints only forward payloads describes the prior baseline.

Actual Gradle dependency resolution confirms the missing `com.riseworld.launchpad.resource:resource:2.11.1` package. The supplied 2.12.0 artifact is used only in an explicitly separate diagnostic compile, not silently substituted into the production graph. AAR metadata independently establishes compileSdk 36. A real Unity 6.6 import, JNI/game APK execution, permissions, physical timing and mixed-family hardware support remain unverified. OnePlus 15 and Galaxy Tab S3 are possible test devices, not passed device configurations.
