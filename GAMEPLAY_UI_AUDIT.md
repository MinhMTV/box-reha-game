# Gameplay / UI audit and engineering handoff

Audit date: 2026-09-13. Source branch: codex/research-hardening-2026-09-13.
Scope: Unity gameplay, interface, persistence, research event recording and QA.
This document records source inspection and changes. It is not evidence of a Unity build, rendered scene test, sensor accuracy, or participant evaluation.

## Initial findings and disposition

| Priority | Finding at audit | Evidence in original source | Disposition |
|---|---|---|---|
| P0 | Main menu displayed invented calibration, performance, identity and connected sensors | DigitalDojoSceneGenerator:405-406, 452-485, 756; also serialized in MainMenu.unity | Runtime hub reconstructs its canvas in Awake. Invented generator UI removed. Historical serialized concept children are disabled and destroyed before rendering. |
| P0 | HUD showed invented limb percentages | DigitalDojoHudSkin:96-99 | Removed. HUD now contains live score/combo/time/timing accuracy, actual provider status and controls. |
| P0 | Height/weight/sex heuristic was presented as punch/kick force in N | PlayerProfile:14-61; ResultsController:143 | Removed from profile logic and UI. Profile has display name and pseudonymous ID. Uncalibrated sensor events use neutral gameplay power without a physical claim. |
| P0 | Pause controller disabled its own object, preventing Escape polling | PauseMenuController:18-19, SceneAutoSetup:378 onward | Overlay uses CanvasGroup. Controller remains active. Pause disables input router; explicit round/evaluator guards reject paused actions. |
| P0 | No reconstructable study event stream | No logger existed; only score-sorted PlayerPrefs top ten | Local append-only JSONL + recent session history added. Event IDs and target IDs reconcile action/target/score. See RESEARCH_LOG_SCHEMA.md. |
| P1 | Resolution time mixed scaled spawn clock and realtime clock | TargetObject.Start and HitZoneEvaluator:197,262 | Duration now Time.time - SpawnTime, excluding pause; labelled target resolution, not reaction time. |
| P1 | Spatial trigger could only expose a small subset of advertised timing window | HitZoneEvaluator trigger registration and fixed timing thresholds | All spawned targets register. Temporal window is full Level.HitWindowSeconds / 2 on each side; early input outside it does not consume target. |
| P1 | Heavy could block endless indefinitely | TargetMover stopped after zone entry without deadline | Heavy locks on actual hit line, accepts either side repeatedly, expires after 12 active seconds as heavy_timeout. |
| P1 | Rapid chain awarded for unrelated same-lane hits | HitZoneEvaluator single currentChain | Unique chain membership; failed chains cannot award completion bonus. |
| P1 | Score/Combo/Stats event subscriber ordering influenced scoring | ScoreSystem and ComboSystem both subscribed to hit event | Explicit combo increment then deterministic score award then public notification. First combo multiplier 1.0, +0.1 per subsequent completion, cap 3.0. |
| P1 | Stopping discarded partial session | Pause QuitToMenu | Finish & Results saves session; remaining targets resolve as aborted and are excluded from resolved-target denominators. |
| P1 | Changing display name could pool different participants | New profile flow initially preserved one ID only | Explicit New participant ID action generates a new GUID. Name edits preserve identity. Historical records remain. |
| P2 | Fast heavy impacts could compound target scale | Concurrent wiggle coroutines | Previous wiggle cancelled and original resting scale restored. |
| P1 | Review found that a history read failure could be mistaken for empty history and overwritten | Initial SessionHistoryStore.Load/Save implementation | Load validates identities, Save refuses on read/parse error, original file remains intact, Statistics shows the failure. |

## Current source-level implementation

- Existing Boot -> MainMenu -> Game -> Results scenes retained. No scene or asset generator was run in this work cycle.
- Keyboard and sensors use the shared input router / PlayerActionEvent pipeline. Sensor agent owns provider changes and detailed qualification.
- Punches: left/right and upper position. Kicks: left/right and lower upright pad. Regular patterns exclude center. Heavy disc uses center.
- Heavy accepts successive left punches or successive right punches, with neutral damage 1 for uncalibrated sensor actions. Only explicitly normalized values affect damage and score multiplier.
- Timed levels retain existing 60-second presets. Endless ramps to preset bounded maxima and ends using Enter or Pause -> Finish & Results.
- The pause clock freezes target movement, timeout, spawn intervals, timer and target resolution time.
- Profile name/ID and reduced-motion/SFX settings persist locally. Local history is separate from old global leaderboard PlayerPrefs, retains at most 200 summaries and filters the active profile.
- No raw force aggregation remains in session statistics. Unrelated SDK quantities are retained in action evidence, not pooled.
- File write failures are surfaced in live HUD / results; no silent claim of successful export is made.
- Research output is local only. Sharing/export submission is a separate operator action.

## UI design principles

These are design rationales, not a completed empirical comparison or usability validation of benchmark games.

| Reference principle requested by user | Applied in Digital Dojo | Verification still required |
|---|---|---|
| Clear target vocabulary and immediate feedback | Height + side + shape + explicit action label; brief timing label; heavy health bar on target | Actual gameplay capture, target contrast and occlusion review |
| Simple entry and visible session structure | Level chooser, 60 active-second explanation, controls on home and HUD | First-use walkthrough with a new participant |
| Results explain progress | Completion and timing accuracy separated, recent sessions and arm/leg split | Small-screen text fit and real-session reconciliation |
| Positive feedback without physiological claims | Neutral gameplay scoring and short heavy completion response | Expert feedback on wording and task intensity |
| Accessibility | SFX controls, reduced motion, labels and shape supplement color | Contrast, visual impairment and motor accessibility evaluation |
| Physiological adaptation | Explicitly unavailable HR channel; no fabricated display | Separate HR acquisition / controller qualification |

The target style remains warm wood, matte dark surfaces and restrained red accents. Existing procedural target/environment assets are reused. Runtime menus use a 1600x900 reference with CanvasScaler Expand; results and controls use explicit spacing. Visual layout has not been rendered or verified on this host.

## Verification and remaining gates

1. Host production-rule checks live in tests/sensor and cover deterministic logic only. Their own result file is the evidence; this document does not predeclare a pass.
2. GameRegressionChecks.RunBatch is an unexecuted Unity Editor entrypoint until a compatible Editor is available. It verifies timing, mapping, same-side heavy policy, scoring, patterns, metrics, scene assets, missing scripts and serialized gameplay references.
3. Required Play Mode/build gates: actual four-key input, repeated heavy damage/completion/timeout, chain failure, level/endless, Escape/resume/finish, profile/history round-trip, logging failure, pause/reconnect and scene lifecycle.
4. Required screenshots from a running build: main menu, punch, kick, heavy, calibration preparation, results, statistics and profile. Do not substitute historical mock panels or generated illustrations.
5. Real calibration capture and baseline persistence remain unimplemented. The current screen states this; no baseline is inferred from demographics.
6. No Unity runtime, Android/iOS build, BLE lifecycle or physical sensor test is claimed here. Hardware status: NOT VERIFIED WITH PHYSICAL HARDWARE.
7. Calibration-specific and HR/adaptation event producers are absent. Native bridge messages still require a collector; HR controller status is owned by sensor review.
8. Profile switching currently creates a new active ID; a list for restoring an older profile is not implemented. Its histories remain on disk.
9. A crash/power loss can leave a JSONL session without session_end. Treat it as incomplete, not as a completed study session.
10. The existing MainMenu scene asset contains the old serialized concept children. They are unreachable at runtime because the hub replaces them before rendering; regenerate the scene only in a controlled Unity session when ready to remove that historical serialization.

Executed static check: `python tests/check_scene_assets.py` produced 635 passing YAML/reference assertions, zero failures in `artifacts/validation/static-scene-checks.json`. External package script GUIDs are listed separately as unresolved by this static check. No Awake/Start code, button, pause behavior or scene transition was executed by it.
