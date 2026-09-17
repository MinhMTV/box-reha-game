# Spawning architecture — 17 September 2026

GameplayPacingProfile → GameplayPatternPlanner → ComboPlan → PacingActionTimeline → TargetSpawner → TargetObject / TargetMover / TargetMountMotion → HitZoneEvaluator.

## Reference audit
Performed against main e1e6341 and current source, including C# callers and asset/scene/prefab GUID references.
- Production: profile/planner/plan/timeline/spawner; evaluator, visualizer, target/mover/mount; particles, arena pulse, palette, timer, scoring and combo.
- Editor/test: PacingRuntimeProbe.FixedPlanner forces 10/30/50/125 actions but uses the production scheduler. It is not a second production spawning path.
- Removed legacy: SpawnPatternGenerator (+meta), its old random-pattern test, SpawnWarningEffect (+meta), unused runtime hit-guide methods, TargetSpawnData, target label and side placeholders.
- No serialized GUID references to the removed scripts or LevelDefinition existed. Levels are created by four factories; no level asset values need conversion. Every former factory ToughTargetChance was positive, so HeavyTargetsEnabled=true preserves enablement. A float-to-bool FormerlySerializedAs cast was deliberately not used.
- Removed duplicate LevelDefinition speed/interval/ramp/chain fields and unused GameConfig default speed/interval keys. Game scene targetPrefab was unused; only that stale reference was removed.
- Block/Dodge enum numbers remain reserved for serialized compatibility. Production planner accepts only Punch/Kick; physical mixed remains rejected.
- SessionTimer.OnTimeWarning has no subscriber in this repository. It does not explain a historical 30-second stall.
- ComboSystem counts completed targets. Heavy partial hits award partial score, not completed-target combo increments.

## Scheduling
Difficulty curves and category distributions live together in GameplayPacingProfile. Opening differs from recovery. StartIntensity is .25/.50/.80; the opening blends half that intensity into travel and normal interval to preserve preview readability. Hard starts at .73 s travel and .268 s action spacing, then .22–.27 s normal and down to .18 s bursts.
Opening Punch lengths: 2–4 / 4–6 / 5–8. Active recovery: 2–3 / 2–4 / 2–4, interval multiplied by 1.8 (minimum .4 s). No unused recovery wait budget.
Hard phase boundaries: 5/18/35/48/60/65/78/88/100 percent. Names: Opening, Build, Burst, Long, Conditioning, Recovery, HighIntensity, HeavyOpportunity, FinalBurst. HeavyOpportunity changes category weights only; there is one Heavy due timer.
Easy and Medium have independent curves. See source Phase arrays for editable normal/long/burst/conditioning weights.
Punch ranges retain 30–50 Hard conditioning; Endless lengths grow separately from capped speed tier. Pure Kick remains <=20 (normal defaults <=12, rare <=15).
Mixed development uses seeded, authored PPPK/PPPPK/PPPPPK motifs with configurable family weight selecting motif density; physical mixed is blocked.
SafeDouble repeats LRLRRLLR or its mirror: max two same-side actions when both sides exist. Single-device projection necessarily repeats that one side and retains physical refractory.

## Heavy and preview
Heavy interval timers: Easy18–25 / Medium12–18 / Hard8–14 seconds; advanced Endless approaches7–10. Minimum separations13/10/7/6. Due Heavy waits for the next 12-Punch / 4-Kick-action work boundary or next pattern start, without cancelling the logical sequence. Health is sampled inclusively from MinToughHits..MaxToughHits using the session-seeded random source.
Rolling lookahead is 4/5/7, advanced Endless8. Actual scheduled timestamps include Kick cadence and independent per-side refractory; preview depth derives from that horizon. If delayed, speed is reduced to retain the room bound rather than placing a target beyond the spawn plane. First queue is created immediately, deployment .28s; Heavy .58s.

## Lifecycle and ownership
Evaluator is injected by spawner into targets and movers; no per-target scene search. TOO LIGHT stays nonterminal. Terminal targets leave the active list once and update completion once; cleanup is armed before presentation.
Target Resolution Time is spawn-to-success duration. AverageReactionTime is retained solely as the historical serialized data key; runtime callers use AverageTargetResolutionTime and TrackTargetResolutionTime, with unchanged numbers.
Hit gate follows full evaluator XYZ. Pre-action states are visual only: Dormant/Approaching/Ready/PerfectWindow. Text is reserved for evaluated outcome feedback.
Arena pulse, target feedback and healthbar use property blocks. Fallback materials are cached per spawner and destroyed with it. Mount prefab references are cached, retired mount structures retained up to10; hit particles up to4; existing debris pool48 remains. Targets and healthbar geometry still instantiate per action/Heavy; full target pooling is intentionally deferred because damage-state restoration is more complex than mount/effect reuse.
Native material/object counts are sampled by synthetic Play Mode stress tests. This is not Android frame/GC/thermal qualification.

## Validation
The current Unity/Android build receipt is `artifacts/validation/unity-android-candidate-build.json`; older fitness reports describe earlier builds. Sensor SDK, physical semantics, calibration, ownership and mixed-family restrictions are unchanged.
