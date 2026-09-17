> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](../../../GAME_STATUS.md), [CURRENT_GAMEPLAY.md](../../../CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](../../../ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](../../../TODO.md). Reviewed 17 September 2026; no tests rerun.

# Engineering decisions, updated 14 September 2026

These are implementation decisions within the user's authorized scope. They are not supervisor approval or empirical findings. Source hierarchy and baseline revisions are in `RESEARCH_WORKPLAN.md`; external decisions are in `OPEN_DECISIONS.md`.

| ID | Decision and reason | Evidence / remaining qualification |
|---|---|---|
| GD01 | Keep the existing Unity project and four-scene flow. The recorded baseline is 2022.3.62f3; the user is installing Unity 6.6 for Android. | Real Editor import/migration must precede a 6.6 qualification claim. GD16 updates the deployment target. |
| GD02 | Produce one keyboard action per key down through the shared provider/router; arrows punch, A/D kick. | Production provider/factory host tests. Keyboard remains keyboard provenance, never SDK measurement. |
| GD03 | Selected provider must exist and the game must be Playing; fail closed otherwise. | Host routing tests include missing sensor source and paused/finished states. |
| GD04 | Keep per-device, per-connection event consumption, duplicate history and cooldown; retire old epochs across reconnect. | Sensor regression groups and retained source hashes. Physical reconnect not verified. |
| GD05 | Preserve raw Alpha/Delta quantity identities and unknown units; use neutral gameplay magnitude without a real baseline. | Contract v2 and normalized event evidence. No demographic normalization or force claim. |
| GD06 | Normal targets use left/right lanes; heavy center targets accept repeated same-side punches and have a 12-active-second timeout. | User-requested mechanics and tested policy. Timeout is a documented engineering default, not a physiological threshold. |
| GD07 | Evaluate configured temporal eligibility using travel distance/speed and half the full hit window; do not depend on collider volume as the timing definition. | Timing rules tested; transform/callback operation still requires Unity. |
| GD08 | Keep runtime hub construction to bind real profile/history/settings and remove dormant decorative UI before rendering. | Bounded change reuses existing room/art. Re-serialization and visual qualification postponed until Unity is available. |
| GD09 | Store display name locally; use explicit fresh study ID for a new participant. Name editing retains identity. | Profile source and host persistence tests; old participant history is preserved. No medically unjustified profile fields. |
| GD10 | Distinguish timing accuracy, target completion, aborted targets and spawn-to-resolution time. | Production stats and external replay agreement; no sensor-accuracy or pure reaction-time reinterpretation. |
| GD11 | Export one flushed JSONL stream per session, with original sensor evidence, action/target links and source/config identifiers. | Synthetic production-logger execution plus independent replay. Full raw diagnostic and connection-coverage export remains open. |
| GD12 | Use local JSON summaries capped at 200 and retain full research logs separately; preserve corrupt input on load errors. | Real file IO host regression with synthetic records. Retention/access/encryption policy remains an institutional decision. |
| GD13 | Keep HR provider/scaffold separate and inactive; calibration view explicitly unavailable. | No false connection, baselines, HR display or adaptation claim. Scope and actual implementation still pending. |
| GD14 | Pin the existing Unity MCP dependency to its already resolved commit b92c05a25820cfc9f59ce4094eb46aaec8632ea2 instead of mutable main. | Manifest and lock agree; no new dependency resolution is claimed. |
| GD15 | Separate C# syntax, host logic, static assets, Unity build/runtime and physical qualification. | Each report states its boundary; overall status remains RED while the required gates are absent. |
| GD16 | Develop/build on Windows; run the full game plus native Dynamics SDK on Android. | Explicit user decision, 14 September. No Windows BLE port or phone-to-PC gateway is part of this route. |
| GD17 | Start with separate same-family ALPHA/DELTA modes, one device or an explicit left/right pair; target only connected sides. | SDK exposes ALPHA or DELTA session type. Three-device mixed-family use remains unconfirmed, not silently represented by separate tests. |
| GD18 | Require explicit SDK body-profile input and acknowledgement for each participant, with correlated start/resume and bounded status freshness. | SDK readiness requirement; no preset personal values and no restored demographic force normalization. SDK database/export/deletion require separate qualification. |
| GD19 | Preserve SDK 0.25.6's production dependency requests; label any alternate resource-version compilation diagnostic only. | Actual standard Gradle resolution lacks resource 2.11.1. Vendor-supplied 2.12.0 alone is not compatibility approval. |
| GD20 | Compile against Android API 36, retain Java 17/Kotlin 2.3.21 and configure the generated Unity export explicitly. | Actual SDK AAR metadata requires API 36. Standalone native compilation and the different Unity 6.6 Gradle/AGP toolchain need separate evidence. |

The documentary benchmark in `GAME_BENCHMARK_REVIEW.md` guides readability, feedback, progression and restrained information density. It is not a hands-on comparative game evaluation, and its principles still need rendered/user checks in this prototype.
