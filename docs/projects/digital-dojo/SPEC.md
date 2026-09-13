# Digital Dojo — Android prototype

Authoritative request: attached 89-section task, 14 September 2026. Existing game is the deliverable. Develop on Windows, run Unity and Dynamics together on Android. Approved expose v3 and current research scope remain unchanged.

## Product contract

Landscape training game with two normal lanes: circular upper punch pads, upright lower kick pads, and a large segmented center heavy pad. Heavy accepts repeated punches from either side, blocks spawning while active, and retains timeout/pause/finish escape paths. Keyboard arrows and A/D remain explicitly synthetic input through the same action abstraction.

Use the existing Built-in render pipeline and uGUI runtime controllers. Dark wood, charcoal, restrained metal, warm light and off-white typography establish the room; red punch and blue kick accents establish action meaning. Blender sources, FBX exports, material separation and generation scripts must be reproducible. Visual children integrate with TargetSpawner; gameplay components and scoring remain authoritative.

Menu, level/endless selection, profile, statistics, settings, sensor setup, calibration preparation, HUD and results share readable typography and touch controls. Persist only actual data. Calibration must distinguish a preparation wizard from measured, validated baselines. HR remains an optional separate inactive channel.

## Sensor contract

Dynamics native SDK -> Kotlin/Java collector -> DynamicsSdkBridge -> SensorReading -> action provider -> PlayerActionEvent -> gameplay/logging. Keep identity, side, family, validity, clocks, vendor quantity and provenance. ALPHA impact and DELTA powerIndex are not interchangeable force. Fail closed on missing/invalid native readiness; connection failures pause play rather than generate misses.

Support explicit side binding. Current same-family one/two-device implementation is a transition boundary; combined two ALPHA plus DELTA remains a required investigation and cannot be declared supported without SDK and hardware evidence.

## Delivery gates

Actual Unity 6.6 compilation; reviewed migration; render captures before/after at 1920x1080, 1280x720 and Android landscape ratios; behavior regression; native compiler and APK attempt; truthful status and remaining external blockers. No store publication, participant data fabrication, unrelated thesis rewrite, or unverified hardware success.
