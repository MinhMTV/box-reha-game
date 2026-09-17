# Sensor integration — 17 September 2026

Current implementation: native Android Dynamics 0.25.6 collector → JNI/Unity bridge → per-device SensorEventProcessor → abstract Punch/Kick action pipeline. Explicit COMPATIBILITY mode has native/Unity build evidence. It does not establish physical sensor accuracy. [ANDROID_STATUS.md](ANDROID_STATUS.md).

## Quantities and supported policy

| Family | Implemented input | Retained SDK quantities | Qualification |
|---|---|---|---|
| ALPHA | Left/Right Punch from computed SDK events | impact, peakForceBasedOnBaro plus reported speed/detail evidence; collector selects alpha.impact | Physical events/units/latency not qualified |
| DELTA | Left/Right experimental Kick mapping from SDK Punch events | powerIndex, reported speed/detail evidence; delta.power_index | Placement and Kick detection not qualified; powerIndex is not physical force |

Computed units remain `unknown` where the inspected SDK contract does not specify them. No invented N/J/W units, body-weight force estimate or physical equivalence between ALPHA and DELTA. Matching Strong references produce dimensionless game ratios only.

Same-family single or uniquely sided Left/Right pair is allowed by tested application policy. Production mixed ALPHA+DELTA, third/fourth-device and clean 2 ALPHA+2 DELTA acquisition are blocked/not implemented. SDK one-pair/active-session ownership is the established limit; no radio-wide maximum is inferred. [MULTI_SENSOR_REPORT.md](MULTI_SENSOR_REPORT.md), [SDK_MULTI_SENSOR_FEASIBILITY.md](SDK_MULTI_SENSOR_FEASIBILITY.md).

## Integrity, setup and lifecycle
Actual advertised names, SDK-reported family, side and observed state remain visible. Unknown family blocks preparation without hiding the device. Persistent removal is confirmed; side changes use pair-aware swapGloveSideForId. Profile/session acknowledgements, connection epochs, freshness and duplicate rejection guard input. Identity, family, side, quantity/unit, provenance and source/transport timestamps survive into accepted-action evidence.

Computed events are collected; raw streams are not simultaneously forwarded by the native production collector. The Unity contract has raw telemetry fields and an explicitly unvalidated opt-in acceleration heuristic, disabled by default. SDK raw APIs exist per peripheral/all-gloves; availability in the API does not prove a supported mixed binding or reliable recording route.

## Raw data and future classification
SDK raw fields where supplied include acceleration (m/s²), gyro (degrees/s), magnetometer (µT) and barometer (Pa), with separate sample rates/counters. Timing and stream availability require physical qualification. An end-to-end labelled ALPHA/DELTA raw recorder remains TODO.
Not implemented: Straight/Jab/Cross/Hook/Uppercut; Front/Side/Roundhouse Kick; Block/Parry; camera pose tracking. Raw IMU makes future classification plausible but accuracy requires labelled datasets and evaluation. [TODO.md](TODO.md).

## Calibration and HR
Strong and Rapid references are separately persisted by profile/device/channel. Strong normalization is enabled for a matching valid reference (cap 2.5); uncalibrated input remains neutral. References are scientifically UNQUALIFIED. Technique calibration is future work. [PROFILE_DATA_MODEL.md](PROFILE_DATA_MODEL.md).
HR has separate interfaces/validation scaffold only, without active transport, feedback or adaptive controller.

## Evidence boundary
The user reported earlier APK launch/discovery/ALPHA pairing UI. No qualified physical Punch/DELTA/mixed/reference result is established. Prior native 16 JVM tests and application policy/host tests validate their recorded software scope only. Latest source must be matched to each dated report; no tests ran in this documentation pass.
Preserved initial audit: [13 September snapshot](docs/history/SENSOR_INTEGRATION_AUDIT_2026-09-13.md). Detailed bridge contract: [DynamicsSdkBridgeNotes.md](Assets/Scripts/Sensors/DynamicsSdkBridgeNotes.md). Remaining device tasks: [TODO.md](TODO.md).
