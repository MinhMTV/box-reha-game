> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](../../../GAME_STATUS.md), [CURRENT_GAMEPLAY.md](../../../CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](../../../ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](../../../TODO.md). Reviewed 17 September 2026; no tests rerun.

# Current gameplay source status

This Unity 2022.3.62f3 project is an existing 2.5D combat-fitness prototype. Source changes are not a claim that Unity compilation, runtime behavior or physical hardware has been verified. See GAME_STATUS.md for the current evidence gate and GAMEPLAY_UI_AUDIT.md for findings.

Updated 2026-09-14: the complete Unity game and Dynamics SDK are intended to run together on Android. Windows is the development host; there is no PC gateway. Unity 6.6 installation/migration is pending; the checked-in version remains 2022.3.62f3 until a real import is performed. OnePlus 15 and Galaxy Tab S3 are intended device test targets, not verified devices.

**Native compilation is blocked.** The collector/control flow is implemented in source against the documented SDK API. The production dependency graph lacks `com.riseworld.launchpad.resource:resource:2.11.1`. A separate diagnostic substitution with 2.12.0 also cannot compile the documented API because the supplied Android AARs have stripped Kotlin metadata/InnerClasses information. This is not a working native build or APK. Evidence and required vendor correction: [SDK package blockers](SDK_PACKAGE_BLOCKERS_2026-09-14.md).

## Android sensor flow

1. Open Sensor setup, initialize the SDK, request permissions and scan.
2. Select a discovered device, explicitly assign its physical Left or Right side, and inspect its actual family/connection status. Remove a device to correct pairing.
3. Enter the separate SDK body profile: weight 20–250 kg, height 50–250 cm and explicit MALE/FEMALE SDK category. Inputs start empty; no category is preselected. These SDK requirements are not gameplay force normalization.
4. Choose Alpha punches or experimental Delta kick mapping and start the selected level. One device or one left/right pair of the same family is supported by the source policy. Mixed Alpha+Delta and three-device configurations are blocked. Targets only use connected sides; Delta has no punch chains or heavy targets.
5. The game loads only after a matching request-ID acknowledgement of a running SDK session for the current participant/profile/family. A stale status sequence cannot replace newer state. SDK mock devices cannot qualify as physical input.
6. Use the visible PAUSE button, Resume, or Finish & Results. Connection loss/backgrounding pauses gameplay and closes input. Native status heartbeats arrive every second; a gap over three monotonic seconds closes readiness and pauses the game. Resume waits for a fresh SDK acknowledgement. A changed device selection requires finishing the round. End SDK session in setup is available for recovery from failed starts. Backgrounding cancels a pending scene-start request.

Android defaults to physical input. Settings can explicitly select development input; failed physical input never falls back silently. Results expose native finish status and route the next physical session through setup again.

## Development controls and rules

| Key | Action | Side / height |
|---|---|---|
| Left Arrow | One punch per key press | Left / upper |
| Right Arrow | One punch per key press | Right / upper |
| A | One kick per key press | Left / lower |
| D | One kick per key press | Right / lower |
| Escape | Pause / resume | Inputs disabled while paused |
| Enter | Finish endless and show results | Endless only |
| F1 | Debug information | Development aid |

Keyboard, mouse/touch and validated sensor actions enter the same PlayerActionEvent router. Keyboard input has explicit development provenance and does not claim a physical ALPHA/DELTA device. There is no charged-release second keyboard action.

Normal targets use left/right lanes; the center is reserved for the heavy disc. Heavy accepts repeated punches from the same side, locks on the hit line, and times out after 12 active seconds if incomplete. No forced left/right alternation exists. Uncalibrated sensor actions use neutral unitless gameplay damage, with raw sensor semantics retained separately.

Level presets last 60 active seconds. Endless uses the existing bounded difficulty ramp. Pause freezes target movement, spawn intervals, timer and heavy timeout. Finish & Results records unfinished targets as aborted rather than discarded misses.

Matching uses the full per-level HitWindowSeconds split around arrival at the hit line. A premature action outside this window cannot destroy a distant target. Combo increments explicitly before scoring; the first target multiplier is 1, subsequent completions add 0.1 up to 3.

Local pseudonymous sessions, actions, target outcomes and score increments are recorded as JSONL. Recent statistics use actual saved sessions. Timing accuracy and target completion are separate metrics, and neither is sensor detection accuracy. See RESEARCH_LOG_SCHEMA.md.

Sensor session_start and acquisition_state records additionally contain a sanitized acquisitionJson snapshot: requested/effective family, SDK version/session state, pseudonymous SDK profile reference/study ID, device and connection IDs, physical sides, firmware as reported, and readiness/mock flags. Device display names and body values are excluded. This is a state snapshot, not a complete raw-packet or rejection audit. New participant ID invalidates SDK profile readiness and requests the previous SDK session to finish; earlier game history is retained.

The SDK punch timestamp is the arrival of its first packet, not physical movement onset. On Android, the collector and C# callback both sample Android SystemClock elapsed realtime to measure JNI delivery age. Effective source age includes native source age, transport age and subsequent Unity queue age; missing/future Android emission clocks are rejected. SensorEvidenceJson retains NativeSourceAgeSeconds, NativeTransportAgeSeconds, HasNativeTransportTiming and EmittedAndroidMonotonicSeconds. The 0.5-second action freshness and 3-second status limits are engineering policies awaiting hardware qualification.

Calibration currently explains the planned comfortable-action protocol and clearly states that no baseline is available. Capture/persistence of real calibration remains unimplemented. No fabricated force, power, heart rate or sensor connection appears in the runtime HUD or hub.
