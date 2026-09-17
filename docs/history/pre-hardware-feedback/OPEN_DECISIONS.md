> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](../../../GAME_STATUS.md), [CURRENT_GAMEPLAY.md](../../../CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](../../../ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](../../../TODO.md). Reviewed 17 September 2026; no tests rerun.

# Open decisions

Updated 2026-09-14. The deployment platform is now decided: Android game plus SDK, Windows development. OnePlus 15 or Galaxy Tab S3 are user-named candidates. No device test or study approval is inferred.

| ID | Priority | Decision / missing evidence | Proposed interim handling | Decision owner |
|---|---|---|---|---|
| D01 | P0 | Android selected; actual OS/ABI, firmware and concurrent two-ALPHA-plus-one-DELTA SDK route remain unverified. SDK resource 2.11.1 is missing, and inspected Android AAR metadata/inner-class stripping blocks documented Kotlin APIs. | Implemented Android collector awaits a corrected matching SDK bundle, actual APK and device qualification. Same-family modes do not prove combined use. | User + SDK vendor |
| D02 | P0 | Approved recruitment, physical activity protocol, consent, storage/access/retention and withdrawal rules | Complete draft instruments; do not recruit or collect | Supervisor / institution |
| D03 | P0 | Real interview and study records | Preserve result placeholders; use synthetic tests only in clearly labelled fixtures | User |
| D04 | P1 | Optional HR device/protocol and whether RQ3 is conceptual or empirical | HR disabled; no physiological adaptation claim | User + supervisor |
| D05 | P1 | Required quantitative calibration and verified Alpha/Delta units/reference quantities | Do not use demographic pseudo-force baselines; measured calibration unavailable | Supervisor + vendor |
| D06 | P1 | Expert-role coverage, recruitment stopping rationale, interview/study language, second coder availability | Versioned proposed common interview/coding workflow; no fictitious coder or saturation | Supervisor + user |
| D07 | P1 | Final frozen build, task exposure, rest schedule and missing-data policy | Prepare technical gate and analysis; freeze after pilot | Supervisor + user |
| D08 | P1 | SDK-required body-profile processing, algorithm dependence, finished-session snapshots, backup/export/deletion and exact profile version per study session | Explicit empty profile input; pseudonymous SDK name; sanitized game metadata only. Verify the separately stored SDK configuration before participant use. | Supervisor + SDK vendor |

Normal engineering choices are recorded in `GAME_DECISIONS.md`; they do not require repeated permission. This list is not a claim that all internal work is finished.
