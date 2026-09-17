> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](GAME_STATUS.md), [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](TODO.md). Reviewed 17 September 2026; no tests rerun.

# Hardware feedback audit — 15 September 2026

This pass follows a real user Android test. The former pre-installation audit is preserved in docs/history/pre-hardware-feedback/GAMEPLAY_UI_AUDIT.md; it is not current status.

Implemented: SDK-backed Remove with disappearance acknowledgements, actual advertised/display names, SDK side swap, visible unknown/offline entries, state-derived step colors, device-specific family errors, profile repository/selector/migration, strong and rapid physical reference workflows, relative strength and TOO LIGHT, profile-scoped statistics, mesh-only visual primitives, closer shared hit plane and terminal cleanup independent of effects.

Play Mode checks exercise wrong action/side, punch/kick hits, weak persistence then later hit, miss expiry, heavy completion/timeout, finish abortion and no orphan targets after frames. Captures under DesignReferences/CurrentBuild/Hardware-Feedback cover 16:9, wide and 4:3 layouts. Named SG screenshots are clearly labelled SYNTHETIC UI fixtures, not captured hardware connections.

Qualification limits: actual remove/swap/re-pair on the SDK database, single/pair punch delivery, Android touch/soft keyboard and performance need a connected device. ADB is empty in this run. Earlier UnityEditor.Search.SearchDatabase startup exception recurred during capture; it is outside game scripts. Passing gameplay assertions do not imply a zero-error Editor startup or establish the root cause of the original Android collider/despawn report.

See HARDWARE_FEEDBACK_REPORT.md, STATISTICS_DEFINITIONS.md and PROFILE_DATA_MODEL.md for the detailed change/evidence boundaries.
