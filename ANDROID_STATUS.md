# Android status — 17 September 2026

## Current candidate — final script cleanup build

The current main-checkout APK is **1.4 / code 5**, `Builds/AndroidCandidate/DigitalDojo.apk`, 41,272,553 bytes, SHA-256 `1874D999390AC432B45193B1744D85B48FCE0198E92A2CFC1658C91F496D27D2`. Unity 6000.6.0f1, ARM64 IL2CPP, min API 26, target/compile 36, SDK COMPATIBILITY. Build succeeded in 56.68 s with zero errors and 20 warnings. Evidence: `artifacts/validation/unity-android-candidate-build.json` and `artifacts/validation/unity-player-build.log`. ADB has no device; installation/physical runtime are not verified.

The older candidate details below are historical and do not identify the current APK.

New hardware-feedback APK built successfully in explicit COMPATIBILITY mode. Version 1.1 / code 2. New APK install and physical runtime are NOT RUN because ADB lists no devices. The user's previous APK launch/discovery/ALPHA pairing are accepted real observations and are not erased by this limitation.

## Candidate

- Path: `Builds/AndroidCandidate/DigitalDojo.apk` in the main checkout `E:/Programming Projekte/box-reha-game` (original build retained in the detached worktree).
- SHA-256: `aa82afe63a2a0afc76b999f563c3214094217d63c941ceaec4efa207d4fcf472`
- Actual APK size: 34,189,756 bytes.
- Package `com.boxreha.digitaldojo`, version 1.1 / code 2, ARM64 IL2CPP, landscape, min API 26, target/compile API 36.
- Unity 6000.6.0f1 BuildPipeline: Succeeded, 0 errors, 17 warnings, 141.86 seconds.
- Warnings: 15 deprecated Unity object-finding API uses and two unused serialized evaluator fields. Not Android compilation failures. Separate editor SearchDatabase startup exception remains documented.
- Android debug certificate, APK v2 signature verified; zipalign 16-KB pass; all five ARM64 libraries have at least 16-KB LOAD alignment. DEX descriptors for collector, bridge, adapter, SDK entry and UnityPlayer are present. This does not prove JNI loading on device.
- Source revision d1165f8; source digest `d1f67d948f63d90765c44453d1afec886a5ac90fc6d7a70b5f4d17426f72ba61`. Build identity correctly records dirty=True because Prepare updated the serialized version to 1.1/code2 before the snapshot. Those exact settings are preserved in the final commit.

Evidence: [artifact](artifacts/validation/apk-artifact.json), [BuildReport](artifacts/validation/unity-android-candidate-build.json), [signature](artifacts/validation/apk-signature.txt), [manifest](artifacts/validation/apk-badging.txt), [DEX inventory](artifacts/validation/apk-contents.json), [ELF alignment](artifacts/validation/apk-elf-alignment.json), [source manifest](artifacts/validation/unity-source-manifest.json).

## SDK and functionality

Windows is the development host; Unity and Dynamics run together on Android, without a manufacturer-app relay. Resource 2.11.1 remains missing in VENDOR-UNCHANGED. COMPATIBILITY uses the explicit 2.12.0 substitution and Java/narrow-reflection adapter; vendor binaries are unmodified, with 4,085 files checked and critical AAR hashes enforced. Native compilation plus 16 JVM tests pass.

Removal waits for persisted and observed absence, side correction uses swapGloveSideForId, pairing stores the advertised name, and all reported devices remain visible. Single ALPHA/DELTA Left or Right and same-family pairs are allowed by tested policy. Unknown family or mixed acquisition remains blocked with explanation. Actual corrected radio/database behavior still requires hardware.

Separate strength/rapid references and per-profile normalization are now implemented (superseding the old disabled-normalization status). No measured baseline was generated here; records remain unqualified gameplay references. See HARDWARE_FEEDBACK_REPORT.md, SENSOR_PAIRING_FLOW.md and STATISTICS_DEFINITIONS.md.

## Next physical test

Enable USB debugging and accept the computer RSA prompt. Once `adb devices -l` shows an authorized device, install this exact APK with `adb install -r` without uninstalling profile data. Check removal/re-pair/swap, names and each single-family side first, then real actions, measured references, profile switching/restart and weak-hit retry. DELTA pairs and mixed acquisition must not be inferred from ALPHA discovery. No candidate device is yet qualified by this pass.

Previous candidate 1.0/code1 and previous status are historical; see docs/history/pre-hardware-feedback/ANDROID_STATUS.md. Update: all source changes have since been merged into local main and this exact APK copied to the main checkout; see artifacts/validation/main-checkout-delivery.json.
