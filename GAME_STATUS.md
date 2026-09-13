# Current Status

Updated 2026-09-13. **Study readiness: RED.** This is a hardened source candidate with bounded automated evidence. No Unity Editor/player build or rendered interaction test was possible on this host, and no physical device was tested. Read this file together with `VALIDATION_REPORT_2026-09-13.md`, `GAME_KNOWN_ISSUES.md` and `SENSOR_INTEGRATION_AUDIT.md`.

Working root: `E:\Programming Projekte\box-reha-game`; branch `codex/research-hardening-2026-09-13`; initial revision `8b736f6b7e96615231a6808fb154ec9814214dbb`. The companion thesis is `E:\Programming Projekte\latex_diplom`; approved expose is `E:\Programming Projekte\expose_latex_diplom`; authoritative SDK is `C:\dynamics-sdk-main`. The expose and SDK were not changed.

## Working

Checked boxes below mean implemented and inspected in source; the Tested section defines the actual execution boundary.

- [x] Common input pipeline; Left/Right Arrow punch and A/D kick on key down, with explicit keyboard provenance.
- [x] Per-device consumable sensor queues, validity/age/duplicate/cooldown checks and reconnect epochs.
- [x] Level/Endless source flow, left/right ordinary targets, center heavy targets, same-side repeated heavy hits and bounded heavy timeout.
- [x] Consistent timing-window, scoring/combo, pause/stop, target resolution and results source paths.
- [x] Runtime Digital Dojo hub, real local summaries, participant-ID separation, effective SFX/reduced-motion settings.
- [x] Versioned JSONL session/action/target/score logging and a strict external replay analyzer.
- [ ] Verified interactive executable, complete native collector, physical Alpha/Delta qualification and measured calibration.

## Tested

- [x] 26 deterministic host test groups: 16 sensor, 3 input/buffer/router, 5 gameplay/statistics, 1 logger and 1 history. `artifacts/validation/sensor-host-checks.txt`; exact linked source hashes in `sensor-host-source-manifest.json`. These use .NET and narrow Unity stubs.
- [x] 61 C# source files parsed as C# 9 in four conditional configurations; zero syntax errors. `artifacts/validation/csharp-syntax.json`. This does not resolve Unity APIs or platform dependencies.
- [x] 635 static scene/asset assertions passed. `artifacts/validation/static-scene-checks.json`; package-owned external GUIDs remain separately unverified.
- [x] Production JSONL logger exercised through a labelled synthetic host fixture and independently replayed by the Python analyzer. `artifacts/validation/synthetic/`; no participant data.
- [ ] Unity Editor compilation, Editor checks, Windows candidate build and manual scene walkthrough. `artifacts/validation/unity-environment.json` records NOT RUN because the Editor is unavailable.
- [ ] BLE/native lifecycle, both physical families, mixed-device operation, independent sensor ground truth and real HR.

## Sensor Integration

| Channel | Current status | Qualification boundary |
|---|---|---|
| RD ALPHA | Unity contract/provider/event processing implemented; mock tested | Native endpoints forward payloads but do not implement the full SDK collector. No hardware test. Computed impact/barometer quantity units remain unknown. |
| RD DELTA | Unity contract/provider/event processing implemented; mock tested | Delta power index preserved separately. Continuous kick detection, placement, native acquisition and physical accuracy remain unqualified. |
| HR | Separate inactive scaffold and sample validation | No active acquisition or adaptation controller; no hardware or physiological result. |

None is Hardware tested or Study ready. Selecting unavailable sensor input fails closed; it does not quietly substitute keyboard measurements. Mixed Alpha/Delta support within the SDK's single active session must be established before promising concurrent physical use.

## Gameplay

Normal targets stay left/right, punches high and kicks low; the center is reserved for heavy targets. Timing uses half the configured full window and actual travel time. Heavy targets accept repeated same-side punches and expire after 12 active seconds. Chain identifiers isolate overlapping sequences. Partial heavy targets and other unresolved targets receive explicit aborted outcomes when stopping. Host policy tests cover the rules; live transforms, callbacks, scene transitions and animation have not been exercised in Unity.

## UI

The `DigitalDojoMenuController` builds a consistent UGUI hub at runtime and removes historical decorative children before the first frame. Level, Endless, Calibration, Statistics, Profile, Settings and Exit are source-wired. Calibration has an honest unavailable state; statistics bind stored sessions. The serialized MainMenu scene can still show historical concept UI in the Editor, so it is not a current screenshot. New hub layout, keyboard navigation, resolution behavior and target/HUD occlusion require rendered review.

## Calibration

Measured comfortable-action baseline capture and persistence are **not implemented**. Demographic pseudo-force normalization was removed. Sensor gameplay magnitude remains neutral and normalization invalid until a qualified quantity/device/side-specific baseline exists. Alpha and Delta values must not be pooled or relabelled as force. HR baseline remains optional and inactive.

## Statistics

Session summaries distinguish timing accuracy `(Perfect + Good) / resolved targets` from completion `(all hits) / resolved targets`. Misses include heavy timeouts; aborted targets are reported separately. The UI/statistics source uses a zero display convention for an empty denominator; analysis reports undefined ratios as null. Target-resolution duration is spawn-to-successful-resolution active time, not pure human reaction time. Left/right/center, punch/kick, input source, score and combo remain distinct. The local history retains up to 200 summaries; full JSONL logs are separate.

## Logging

Schema-v1 JSONL links session, participant pseudonym, build/configuration, action, target, score and stop reason. Accepted sensor actions retain original contract-v2 evidence with metric and clock semantics. Profile names are not exported to the research stream. Source build stamping is provided by `scripts/verify-unity.ps1`. Rejected raw packets and connection-coverage intervals are not fully exported; the current log cannot alone establish packet loss, physical sampling rate or coverage-corrected movement frequency. Abrupt termination can leave an explicitly incomplete recording.

## Known Issues

No current Unity compiler/runtime result exists, so absence of critical runtime bugs is not established. Highest risks are unrendered UI/lifecycle, unfinished native collection, absent measured calibration, and incomplete technical diagnostic export. Known boundaries and concrete verification steps are maintained in `GAME_KNOWN_ISSUES.md`. Historical screenshots and synthetic fixture passes are not runtime evidence.

## High-Priority Improvements

1. Open the existing project in licensed Unity 2022.3.62f3, restore its locked packages, run Editor checks and build a development candidate.
2. Perform and record the full manual scene/input/pause/results/history walkthrough; fix import, API, rendering or lifecycle issues it reveals.
3. Complete native SDK collection for the selected platform, confirm mixed-family support and preserve actual timestamps/units/identity.
4. Add the diagnostic acquisition export required by the technical protocol, then qualify real device events against independent labels.
5. Implement and qualify measured baseline capture if retained in the agreed study configuration; keep HR excluded unless specifically completed.

## Nice-to-Have Improvements

Fresh scene serialization of the runtime hub; participant-history selection for repeat visits; further audio/transition polish after rendered review; accessibility checks with users. These must not obscure the evidence gates above.

## External Blockers

Installed/licensed compatible Unity environment; actual Alpha/Delta hardware, firmware and platform; manufacturer clarification of unknown computed units and combined lifecycle; institutional/supervisor study decisions; actual consented interviews and study records. Internal collector/calibration/diagnostic and literature work also remains; this is not a claim that only external blockers exist.

## Last Verified Build

**None for Unity in this cycle.** Host .NET regression execution is not a Unity build. `scripts/verify-unity.ps1` records missing Editor explicitly and, when a compatible Editor is supplied, requires fresh successful reports before accepting qualification. A development candidate does not itself constitute study readiness.

## Screenshots

No new Unity screenshot was generated. Existing `Assets/Screenshots` images predate these changes. Required real captures and scientific captions are specified in the thesis `figures/SCREENSHOT_SPECIFICATIONS.md`; do not replace them with generated mockups.

## Next Agent Tasks

Read `RESEARCH_WORKPLAN.md`, this status, `VALIDATION_REPORT_2026-09-13.md`, `GAME_DECISIONS.md` and the thesis status before further changes. Run only the checks justified by the next change; preserve source hashes and keep empirical data separate. Record Unity/player/device outcomes individually. Follow `SETUP_GUIDE.md` to use the existing project; do not recreate scenes or silently regenerate historical concept assets.
