# Visual status — 15 September 2026

16 September fitness captures: `DesignReferences/CurrentBuild/Fitness-Pacing/` includes the full existing gate/impact suite and rolling long-sequence previews in four landscape sizes. These are synthetic Editor captures; their fixture HUD timer is stopped deliberately, while the separate scheduler clock drives the timed regression. Dense target labels can overlap in depth; phone readability still requires on-device review.

Current captures: `DesignReferences/CurrentBuild/Hit-Gate-Pacing/`, all four landscape sizes. New cases include dormant gate, Punch/Kick Good and Perfect windows, TOO LIGHT retry, both heavy types at 70%/40% health, break, mechanical deployment, minimum-separation burst and reduced motion. Red/blue transverse timing gates are intentionally visible; old longitudinal rails remain absent. See ROOM_VALIDATION_REVIEW.md for unresolved plugin-contract gates versus actual runtime findings. Hardware readability/performance remain unverified.

Fresh Play Mode captures are under `DesignReferences/CurrentBuild/Hardware-Feedback/` at 1024x768, 1280x720, 1920x1080 and 2400x1080. The owned Editor exited normally with the completion marker; see `artifacts/validation/hardware-playmode-process.json` and `dd-runtime-checks.txt`.

The actual strike plane is Z=2, consistently used by evaluator/movers/expected timing. Bright lane rails and action guide bars are removed. Production HUD retains score/combo/time/timing and touch pause; keyboard controls/debug panel are hidden by default. PAUSE is bottom-center to avoid the close right-side KICK label at 4:3. Heavy health bars belong to their targets, preventing detached visibility or lifetime.

Reviewed close punch/kick/heavy views and measured calibration at 4:3, plus sensor/profile workflow captures. Sensor-state fixtures are explicitly synthetic UI evidence, not a Bluetooth connection. No claim of physical sensor motion, Android rendering performance or display readability in actual use.
