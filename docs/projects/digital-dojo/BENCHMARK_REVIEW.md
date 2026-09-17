> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](../../../GAME_STATUS.md), [CURRENT_GAMEPLAY.md](../../../CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](../../../ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](../../../TODO.md). Reviewed 17 September 2026; no tests rerun.

# Benchmark review — design principles, 14 September 2026

This is a source-grounded design review, not a claim of hands-on comparative user testing. No competitor assets are copied.

| Reference | Source evidence | Digital Dojo decision |
| --- | --- | --- |
| Beat Saber | [Official terminology](https://beatsaber.com/documentation/terminology/index.html) describes incoming blocks, lanes and action direction; [note placement](https://beatsaber.com/documentation/placing-notes/index.html) describes grid/color coding. | Stable frontal framing, distinct silhouette plus action text, predictable lanes. Color communicates action family; physical side comes from position and binding. No VR saber gestures copied. |
| Ring Fit Adventure | [Nintendo official overview](https://www.nintendo.com/sg/switch/al3p/index.html) presents real exercise actions within a game journey. | Short preparation steps, clear action expectation, concise session completion and readable results. Do not import calorie or physiological claims. |

Our inferred design criteria: target readability before room decoration; bounded feedback rather than full-screen punishment; four HUD metrics; visible pause/finish controls; empty statistics until actual sessions exist; no decorative charts. These are decisions drawn from the references, not measured evidence that this prototype achieves their quality.

Review against current captures: baseline menu obscures most of its room and includes implementation-heavy copy. Target color and material identity need consistency. Keep the dominant uGUI architecture and improve composition rather than replacing the framework.
