# Visual status — 17 September 2026

Current consolidation captures: `DesignReferences/CurrentBuild/Gameplay-Consolidation/`, all four landscape sizes. Includes immediate Hard opening, rolling 10/30/50/125 work, both Heavy types, Kick and mixed development, actual EARLY/LATE feedback, weak retry and full XYZ gate checks. Pre-action labels are removed; marker readiness is visual. Gate row offsets account for the evaluator origin so marker heights align with target heights. The current Android build receipt is `artifacts/validation/unity-android-candidate-build.json`.

The following older capture sets are historical:

16 September fitness captures: `DesignReferences/CurrentBuild/Fitness-Pacing/` includes the full existing gate/impact suite and rolling long-sequence previews in four landscape sizes. These are synthetic Editor captures; their fixture HUD timer is stopped deliberately, while the separate scheduler clock drives the timed regression. Target action labels were subsequently removed; phone readability still requires on-device review.

Current captures: `DesignReferences/CurrentBuild/Hit-Gate-Pacing/`, all four landscape sizes. New cases include dormant gate, Punch/Kick Good and Perfect windows, TOO LIGHT retry, both heavy types at 70%/40% health, break, mechanical deployment, minimum-separation burst and reduced motion. Red/blue transverse timing gates are intentionally visible; old longitudinal rails remain absent. See ROOM_VALIDATION_REVIEW.md for unresolved plugin-contract gates versus actual runtime findings. Hardware readability/performance remain unverified.

Fresh Play Mode captures are under `DesignReferences/CurrentBuild/Hardware-Feedback/` at 1024x768, 1280x720, 1920x1080 and 2400x1080. The owned Editor exited normally with the completion marker; see `artifacts/validation/hardware-playmode-process.json` and `dd-runtime-checks.txt`.

The actual strike plane is Z=2, consistently used by evaluator/movers/expected timing. Bright lane rails and action guide bars are removed. Production HUD retains score/combo/time/timing and touch pause; keyboard controls/debug panel are hidden by default. PAUSE is bottom-center; action labels are absent at 4:3. Heavy health bars belong to their targets, preventing detached visibility or lifetime.

Reviewed close punch/kick/heavy views and measured calibration at 4:3, plus sensor/profile workflow captures. Sensor-state fixtures are explicitly synthetic UI evidence, not a Bluetooth connection. No claim of physical sensor motion, Android rendering performance or display readability in actual use.
