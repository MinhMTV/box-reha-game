# Digital Dojo status — 18 September 2026

Documentation baseline: uncommitted changes on top of main `b1925ef`, after a full code/thesis audit pass plus a second full repository dead-code/hygiene audit ([CODE_AUDIT.md](CODE_AUDIT.md)) the same day. The Inspector Gradle build, the Unity Android build (twice), and the thesis LaTeX build were all run and succeeded — the final Unity build has 0 errors and 0 compiler warnings. No Play Mode/gameplay tests were run. Detailed remaining work: [TODO.md](TODO.md).

## Gameplay
Implemented: difficulty curves, long seeded Punch combinations, Punch-dominant mixed development patterns, bounded Kick sequences, growing Endless length, rolling lookahead, lane predecessor spacing, Heavy encounters and active recovery. Hit Gate shows readiness; TOO LIGHT leaves a target available within its window. Latest speed/order changes have compile/build evidence, but no new Play Mode validation. See [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [GAMEPLAY_PACING.md](GAMEPLAY_PACING.md).

## Visuals
Imported Blender room/target kit, baked room atlas, mechanical deployment, impact/damage stages and bounded debris/effect pools. Concept fidelity and on-device readability/performance remain limited by untested hardware. Existing captures precede the latest pacing pass; see [VISUAL_STATUS.md](VISUAL_STATUS.md).

## Sensors
Android collector and Unity bridge compile in explicit SDK COMPATIBILITY mode. Application policy accepts one device or a uniquely sided pair of one reported family. ALPHA maps to Punch; DELTA to experimental Kick. Physical mixed ALPHA/DELTA and 2+2 acquisition are blocked. A real DELTA computed-session bug (hardcoded ALPHA family default causing `family_downgrade_refused` for DELTA-only hardware) was found and fixed 18 September; every reflected SDK ABI descriptor was re-verified against actual `javap` output of the shipped AARs and found correct; a latent ProGuard keep-rules gap was fixed. Physical event accuracy, removal/swap and DELTA remain unqualified on real hardware. See [SENSOR_INTEGRATION_AUDIT.md](SENSOR_INTEGRATION_AUDIT.md), [SDK_COMPATIBILITY_REPORT.md](SDK_COMPATIBILITY_REPORT.md).

## Android
ARM64/IL2CPP; minimum API 26, target 36. 18 September build receipt (Unity 6000.6.1f1 on macOS, after fixing an AGP 9/Kotlin-toolchain incompatibility unrelated to game code): Succeeded, 0 errors, 0 warnings; APK 1.5/code 6. Latest-device installation/runtime not verified. [ANDROID_STATUS.md](ANDROID_STATUS.md) identifies the artifact and evidence limits.

## Calibration/Profile
Create/select/edit/archive and legacy migration; profile-scoped Strong and Rapid references, schema-2 persistence with schema-1 read compatibility. Matching Strong references enable dimensionless normalization capped at 2.5. References remain UNQUALIFIED; technique calibration is not implemented. A crash on a corrupt profile database (exception thrown but never caught) was fixed 18 September; it now falls back to a transient in-memory profile without touching the original file. See [PROFILE_DATA_MODEL.md](PROFILE_DATA_MODEL.md).

## Research
JSONL action/target/score provenance and profile-filtered summaries exist. Target Resolution Time is spawn-to-success duration, not human reaction time. HR is an inactive interface/scaffold. The thesis previously presented a fully fabricated user study (n=16, questionnaire scores, invented interview quotes) as completed results; this was removed 18 September and the evaluation chapter now correctly describes it as a planned, not-yet-executed protocol. Empirical interviews, real user data and final results remain open. See [RESEARCH_WORKPLAN.md](RESEARCH_WORKPLAN.md).

## Major limitations
No qualified physical sensor session or Android performance measurement; SDK core source absent from supplied distribution; no technique classification, Block/Parry or camera tracking. Historical test passes do not validate the latest speed/order behavior.

## Next steps
ALPHA hardware → DELTA hardware → latest gameplay/order manual validation → raw recording/classification feasibility, with study scope agreed separately. Follow [TODO.md](TODO.md).
