# Spawning architecture — 17 September 2026

`GameplayPacingProfile → GameplayPatternPlanner → ComboPlan → PacingActionTimeline → TargetSpawner → TargetObject / TargetMover / TargetMountMotion → HitZoneEvaluator`

## Ownership
Profile, planner, plan and timeline are declared together in `Assets/Scripts/Spawning/GameplayPacingProfile.cs`. The profile owns difficulty/phase tuning; the planner selects seeded logical work; ComboPlan exposes actions by index without allocating a sequence-sized array. Timeline retains independent hand timestamps across patterns. TargetSpawner owns scheduling, rolling capacity, Heavy insertion and evaluator injection. Evaluator owns action matching, timing, scoring outcomes and terminal resolution.

Deleted legacy SpawnPatternGenerator, SpawnWarningEffect and TargetSpawnData are not runtime dependencies. Level factories provide level rules; pacing values belong to the profile. PacingRuntimeProbe is an Editor fixture, not a second production scheduler. Block/Dodge enum reservations are not implemented actions.

## Scheduling and no-overtake implementation
See [GAMEPLAY_PACING.md](GAMEPLAY_PACING.md) for current numbers. Opening uses full configured starting intensity. Seeded side and type motifs replace the old fixed SafeDouble pattern. Physical same-side timestamps enforce at least .35 s; Kick transitions are explicit.
Spawner keeps one path predecessor per lane. Proposed due time is constrained by predecessor expected time and spacing divided by the slower speed. It waits for rolling capacity, NextSpawnTime and PathHasRoom, then recomputes arrival from actual spawn time + deployment + sampled travel. Speed remains distance/travel; preview horizon does not set speed. MinimumVisualSpacing is 1.1 world units. TargetMover uses the shared clock and expected hit time when the evaluator is injected. TargetMountMotion aligns deployment with the tracked spawn timestamp.
These guards implement target ordering. The latest speed/order revision is compile/build-checked only; no proof of all runtime no-overtake cases is claimed. Delays under capacity/path pressure can change delivered cadence and need manual/automated runtime verification.

## Heavy and lifecycle
One Heavy timer is serviced at plan/work boundaries. Seeded durability uses the inclusive configured bounds. Heavy resolves before regular work continues; visual debris does not hold scheduling. Rolling lookahead is 4/5/7, up to 8 in advanced Endless.
TOO LIGHT is nonterminal. Terminal cleanup is armed before optional effects; stop/abort cleans targets and owned health bars. Target Resolution Time is spawn-to-success; AverageReactionTime remains a legacy serialized field only.
HitZoneVisualizer follows evaluator XYZ and conveys pre-action readiness visually. Effects/mounts use bounded reuse and shared materials/property blocks. Full target objects are still instantiated per action; no full target-pooling claim is made.

## Evidence
Existing build receipt: `artifacts/validation/unity-android-candidate-build.json`. Prior synthetic Play Mode/capture runs apply to their earlier source states. This documentation update ran no tests/builds. [TODO.md](TODO.md) tracks latest-runtime and physical validation.
