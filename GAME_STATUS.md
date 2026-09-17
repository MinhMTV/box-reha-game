# Digital Dojo status — 17 September 2026

Documentation baseline: main `3f99b17` (fast pacing pass). This update changes documentation only; no new tests, captures or builds were run. Detailed remaining work: [TODO.md](TODO.md).

## Gameplay
Implemented: difficulty curves, long seeded Punch combinations, Punch-dominant mixed development patterns, bounded Kick sequences, growing Endless length, rolling lookahead, lane predecessor spacing, Heavy encounters and active recovery. Hit Gate shows readiness; TOO LIGHT leaves a target available within its window. Latest speed/order changes have compile/build evidence, but no new Play Mode validation. See [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [GAMEPLAY_PACING.md](GAMEPLAY_PACING.md).

## Visuals
Imported Blender room/target kit, baked room atlas, mechanical deployment, impact/damage stages and bounded debris/effect pools. Concept fidelity and on-device readability/performance remain limited by untested hardware. Existing captures precede the latest pacing pass; see [VISUAL_STATUS.md](VISUAL_STATUS.md).

## Sensors
Android collector and Unity bridge compile in explicit SDK COMPATIBILITY mode. Application policy accepts one device or a uniquely sided pair of one reported family. ALPHA maps to Punch; DELTA to experimental Kick. Physical mixed ALPHA/DELTA and 2+2 acquisition are blocked. The user reported launch/discovery/ALPHA pairing on an earlier APK; physical event accuracy, removal/swap and DELTA remain unqualified. See [SENSOR_INTEGRATION_AUDIT.md](SENSOR_INTEGRATION_AUDIT.md).

## Android
Unity 6000.6.0f1; ARM64/IL2CPP; minimum API 26, target 36. Existing 17 September build receipt: Succeeded, 0 errors, 20 warnings; APK 1.5/code 6. Latest-device installation/runtime not verified. [ANDROID_STATUS.md](ANDROID_STATUS.md) identifies the artifact and evidence limits.

## Calibration/Profile
Create/select/edit/archive and legacy migration; profile-scoped Strong and Rapid references, schema-2 persistence with schema-1 read compatibility. Matching Strong references enable dimensionless normalization capped at 2.5. References remain UNQUALIFIED; technique calibration is not implemented. See [PROFILE_DATA_MODEL.md](PROFILE_DATA_MODEL.md).

## Research
JSONL action/target/score provenance and profile-filtered summaries exist. Target Resolution Time is spawn-to-success duration, not human reaction time. HR is an inactive interface/scaffold. Thesis methods/analysis are prepared; empirical interviews, user data and final results remain open. See [RESEARCH_WORKPLAN.md](RESEARCH_WORKPLAN.md).

## Major limitations
No qualified physical sensor session or Android performance measurement; SDK core source absent from supplied distribution; no technique classification, Block/Parry or camera tracking. Historical test passes do not validate the latest speed/order behavior.

## Next steps
ALPHA hardware → DELTA hardware → latest gameplay/order manual validation → raw recording/classification feasibility, with study scope agreed separately. Follow [TODO.md](TODO.md).
