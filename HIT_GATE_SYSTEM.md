# Hit gate — 15 September 2026

`HitZoneVisualizer` is installed by `HitZoneEvaluator` in the existing Game scene. The root is placed at the evaluator's **current world HitZoneZ** every frame, including when its separate center is moved. Default is Z=2. The visualizer never accepts or scores an action.

The red upper gate and blue lower gate read their heights from GameConfig. Thin transverse lines, three small center ticks and short side brackets mark the plane. There are no longitudinal lane rails or opaque panels. Heavy targets increase the transverse line thickness.

Timing comes from `HitZoneEvaluator.PreviewTiming`, which uses the same `GameplayRules.Timing` as acceptance: outside half of HitWindow is not actionable; within 100 ms is Perfect; within 250 ms is Good; the remaining accepted range is Early/Late. Thresholds are capped by the actual half-window. A latched heavy target remains Good / HIT AGAIN. Deploying targets cannot be hit.

States: READY (15% intensity), APPROACH, EARLY, HIT / GOOD, NOW / PERFECT, LATE, short accepted feedback, TOO LIGHT / RETRY and MISS decay. Red/blue retain their action meaning. TOO LIGHT does not consume the target or change the timing rules: a normal target must still be retried before its real late window expires. Reduced motion retains the information and removes camera/debris displacement.

The old fixed mover cutoff at Z=0 no longer truncates the Late window for high-speed registered targets. The evaluator alone expires or locks those targets; the old spatial cutoff remains only as a fallback for unregistered movement without an evaluator.

Evidence: `artifacts/validation/hit-gate-playmode.txt` and `DesignReferences/CurrentBuild/Hit-Gate-Pacing/`. These are synthetic Editor cases, not measured BLE/display latency.
