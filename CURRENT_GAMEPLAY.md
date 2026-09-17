# Current gameplay — 17 September 2026

Source baseline: main `3f99b17`. Boot → MainMenu → Game → Results. Windows is the development host; Android runs the complete game and SDK.

Players can choose timed difficulty levels or Endless, play abstract Left/Right Punch and Kick actions, complete repeated-hit Heavy Punch/Kick targets, pause/resume and finish with results/history. Physical action families/sides are restricted by reported sensor readiness; mixed Punch/Kick is a development-input configuration only. Development keys: Left/Right Arrow for punches, A/D for kicks; F2/F3/F4 select weak/normal/strong development values. Keyboard input is labelled keyboard.

Medium/Hard start at their configured intensity, with short opening combinations and fast travel; later phases include long Punch sequences, bursts and active recovery. Seeded side/type motifs vary combinations. Endless increases logical sequence length while travel speed and visible target count remain bounded. Same-lane predecessors and spacing gate spawning; the latest order changes still require runtime validation. Exact values: [GAMEPLAY_PACING.md](GAMEPLAY_PACING.md).

Strike when the target reaches the transverse Hit Gate (default Z=2). Red upper/blue lower markers show approaching, ready and perfect-window states through brightness/thickness. Deployment is not actionable. Evaluated input produces PERFECT/GOOD/EARLY/LATE/MISS or TOO LIGHT feedback. A TOO LIGHT target remains available until a valid hit or timeout. Heavy targets lock for repeated accepted impacts. Persistent target action labels and longitudinal floor rails are removed.

HUD shows score, combo, time and timing accuracy, with pause and contextual feedback. Target Resolution Time in results is active spawn-to-success duration. Stopping cleans unfinished targets and marks them aborted. [HIT_GATE_SYSTEM.md](HIT_GATE_SYSTEM.md), [STATISTICS_DEFINITIONS.md](STATISTICS_DEFINITIONS.md).

Sensor setup lists actual device names, side, connection and known family; unknown families stay visible but cannot start acquisition. Removal waits for confirmation; side swap uses the SDK operation and may affect the pair. Same-family single/pair policy is implemented, not physically qualified. [SENSOR_PAIRING_FLOW.md](SENSOR_PAIRING_FLOW.md).

Saved profiles support create/select/edit/archive. Strong references use three practice actions plus five valid samples; Rapid uses five events and their intervals. References are scoped to profile/device/side/quantity; only matching Strong references normalize game strength. Uncalibrated input remains neutral. No technique calibration exists.

Not implemented: Straight/Jab/Cross/Hook/Uppercut recognition; Front/Side/Roundhouse Kick recognition; Block/Parry; camera pose tracking; active HR control; physical mixed ALPHA+DELTA. Raw SDK APIs make classification a research possibility, not an existing feature. [TODO.md](TODO.md) tracks these dependencies.
