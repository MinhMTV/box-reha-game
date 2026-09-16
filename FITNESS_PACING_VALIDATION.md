# Fitness pacing validation — 16 September 2026

Implemented in the main checkout, `main`, based on `a9aee35`, with uncommitted changes. This report supersedes the earlier conservative boxing-pacing values. See GAMEPLAY_PACING.md for exact configuration and generation formulas.

## Stall and behavior

Code inspection found repeated recovery waits while the scheduler remained inside the same recovery phase, plus waiting for the final target's complete hit window before adding recovery/deployment/travel. Full-pattern capacity reservation would also deadlock any sequence longer than its live-target cap. The replacement streams actions through live slots, schedules the next pattern while the tail is visible, and uses low-intensity targets for recovery. No VFX lifetime gates progression. The historical on-device pause was not traced, so these are verified scheduling defects rather than a claim to have captured that exact device incident.

Fastest alternating punch spacing: .18 s. Physical per-device refractory remains .35 s and is checked independently for left/right, across patterns. Kick spacing remains at least .55 s. Hard normal/long/burst/conditioning lengths are 8–15 / 15–25 / 20–35 / 30–50. Endless logical length has no design cap: at active minutes t its envelope is floor(5+5t)..floor(15+10t), while speed tier is capped at six and live lookahead at eight. There are no intentional empty recovery sleeps; slower recovery work uses budgets up to 1.5/1.2/1 s by difficulty. Unsupported input remains explicitly blocked.

## Executed tests

- Host pacing: 26,093 deterministic assertions, including seeded generation, Hard 40–50 selection, unbounded length progression, separate same-side timestamps, cross-pattern spacing, kick limits, available sides and mixed-family blocking.
- Existing host checks: 16 sensor, 3 provider/buffer/router, 6 gameplay, 1 logger, 1 history, 47 Android policy, 26 calibration and 108 hardware-feedback assertions/checks passed. Synthetic fixtures only.
- Android export: 18 host file-transformation checks passed.
- C# syntax: 85 files × five configurations, zero errors. This is separate from Unity compilation.
- Static scene checks: 635 passed, zero failures.
- Actual Unity Play Mode: 39 base gameplay/mount checks and 67 hit-gate/effect checks passed, plus all eight scheduler scenarios below. Owned Unity process exited zero, not forcibly terminated. Evidence: artifacts/validation/hardware-playmode-process.json, dd-runtime-checks.txt, hit-gate-playmode.txt, pacing-playmode.txt.

| Actual Play Mode scenario | Result |
|---|---|
| Hard, full 60 active seconds | 201 targets; completed 38-action sequence; max empty interval .289 s |
| Forced alternating 50 | All 50 completed; peak seven logical active targets |
| Advanced Endless, forced 125 | All 125 completed; peak eight logical active targets |
| One-side 50 | All 50 completed on the available side; synthetic keyboard timings, physical .35 s guard covered separately by host tests |
| Kick 10 | Completed; slower kick spacing preserved |
| Heavy Punch and Heavy Kick | Repeated .35-second synthetic actions complete both; no cleanup blockage |
| Three intentional misses in a 50 | Remaining sequence continues through resolution; next sequence starts without idle |

Hard visibility counters: 58.48 seconds work, 1.23 seconds low intensity, .29 seconds empty. The instrumented 34–26 seconds remaining window shows active rolling work, with no full-pattern reservation or stall. These counters measure visible game work, not actual human exertion.

Maximum observed target objects including resolving visuals: ten; maximum active fragments: 42 within a fixed 48-slot pool. Cleanup assertions confirm no surviving target, mount, health-bar or active debris objects after each scenario. No device heap/GC/FPS/thermal benchmark is claimed. Long logical sequence representation is constant-size; synthetic host progression additionally covers much larger lengths without action arrays.

One intermediate strengthened QA run failed because its miss injector selected each subsequent chain instead of only the first. The fixture now retains exactly one chosen chain; the final full rerun passes. This was a test-control error, not a suppressed gameplay assertion.

## Visual and product review

Captures: DesignReferences/CurrentBuild/Fitness-Pacing, 1024×768, 1280×720, 1920×1080 and 2400×1080. Reviewed gate visibility and actual rolling-sequence captures at 4:3, 16:9 and wide aspect. The fixture deliberately stops the displayed session timer; scheduler elapsed time independently drives the regression. Dense world-space action labels still overlap in perspective and need phone readability testing. Concept-art parity remains outside the achieved result.

The measured flow is sustained combinations rather than waiting for individual targets: the 60-second test has less than .3 seconds total empty time and executes long series. Whether .18-second pacing is readable and reliably captured on the user's devices remains a hardware question.

## Build and hardware

The final Android build identity and signature/alignment checks are recorded in artifacts/validation/fitness-apk.json and unity-android-candidate-build.json. Intended output: Builds/AndroidCandidate/DigitalDojo.apk, version 1.3/code 4, Unity 6000.6.0f1, ARM64 IL2CPP, explicit SDK COMPATIBILITY mode.

Final build succeeded in 20.04 seconds, zero errors/warnings in the incremental BuildReport. The preceding full compilation reported 21 warnings (deprecated Unity object-finding APIs and unused fields among them); the incremental result does not mean those source warnings were fixed. APK: 39,552,513 bytes; SHA-256 `974da657a3984ea07269f4ab21642bb4db85fe59f7dccb9700ab21c7063cec67`. Source digest `919fe68d4e9ecf25f255aa25580659dbe1fa9c06e6b8d427fd6292185b49e304`. Signature verification and 16-KB APK alignment succeeded. Manifest confirms version 1.3/code 4, ARM64, min API 26 and target API 36. The final source stamp includes the corrected QA fixture.

## Saved changes

Tracked source/settings/test diff: 19 files, 405 insertions and 411 deletions. This excludes newly created files and evidence/docs. New source includes GameplayPacingProfile (configuration, lazy planner and per-side timeline), HitZoneVisualizer, DojoDebrisPool, DojoGameFeel, two Editor test fixtures and host pacing checks, with Unity metadata. Full `git diff --stat` and the untracked file inventory are saved in artifacts/validation/fitness-diff-stat.txt.

TargetSpawner now streams plans instead of random isolated spawns/full reservations; GameRoundController no longer stacks old speed/interval ramps. HitZoneEvaluator still decides every hit, with a read-only gate and logical resolution before effects. Animation/audio/UI changes remain part of the preceding hit-gate pass. Research logging adds optional pacing context only. No SDK, calibration or sensor configuration diff was introduced by this pass.

ADB lists no device. APK installation and physical runtime have not been re-verified. Outstanding: real dual-hand event cadence at .18-second global spacing, one-side .35-second behavior, DELTA cadence, BLE latency/reconnection, sustained readability and phone performance. Existing physical mixed ALPHA/DELTA restriction and calibration semantics are unchanged.
