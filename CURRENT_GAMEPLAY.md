# Current gameplay — hardware feedback pass, 15 September 2026

Unity 6000.6.0f1; existing Boot > MainMenu > Game > Results, Built-in renderer, Digital Dojo assets. Windows development, Android ARM64/IL2CPP target. Explicit SDK COMPATIBILITY and VENDOR-UNCHANGED modes remain. See ANDROID_STATUS.md for the actual candidate build evidence.

Sensor setup supports named discovered/paired devices, explicit sides, confirmed persistent removal and SDK side swap. Unknown families remain visible with an actionable message. Same-family one/two devices are supported by policy; only connected sides receive targets. Mixed ALPHA/DELTA stays blocked for the reasons in MULTI_SENSOR_REPORT.md.

Player profile > Saved profiles creates, reopens, edits and archives local participants. Migration preserves the previous StudyId and history. Training setup provides real event-gated strong references (3 practice + 5 samples) and fast sequences (5 events); no Next button can fabricate a physical calibration. Saved references are versioned and profile/device/channel specific, still scientifically UNQUALIFIED.

Calibrated physical actions use currentMeasurement/reference, dimensionless and capped at 2.5, only for matching family/side/device/quantity/unit/provenance/SDK mode. Uncalibrated events retain explicitly neutral damage. Too-weak timed matching actions show TOO LIGHT and leave the target available. Heavy accepted damage remains bounded. Keyboard F2/F3/F4 selects weak/normal/strong development values; provenance remains keyboard.

The gameplay hit plane is Z=2 (formerly 5), shared by evaluator, expected hit time and heavy locking; misses still follow timing-window expiry. Targets arm destruction before terminal presentation, use an unscaled cleanup fallback and are explicitly cleaned when stopping. VisualPrimitive creates mesh-only effects and geometry, eliminating implicit CapsuleCollider creation. No bright lane rails/hit guides or persistent control manual remain. Logical left/right/center lanes remain.

HUD: score, combo, time, timing accuracy, pause and contextual hit/connection feedback. Optional F1 development overlay is off by default and unavailable as a production Android control manual.

User physically installed/launched the old APK, discovered ALPHA SG devices and observed paired/connected UI. This does not establish punch delivery, calibrated gameplay, DELTA, mixed sensing or reconnection reliability. Current automated tests are synthetic; hardware must repeat the cases in SENSOR_PAIRING_FLOW.md.
