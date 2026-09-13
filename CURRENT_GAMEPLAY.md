# Current gameplay source status

This Unity 2022.3.62f3 project is an existing 2.5D combat-fitness prototype. Source changes are not a claim that Unity compilation, runtime behavior or physical hardware has been verified. See GAME_STATUS.md for the current evidence gate and GAMEPLAY_UI_AUDIT.md for findings.

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

Calibration currently explains the planned comfortable-action protocol and clearly states that no baseline is available. Capture/persistence of real calibration remains unimplemented. No fabricated force, power, heart rate or sensor connection appears in the runtime HUD or hub.
