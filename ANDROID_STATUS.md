# Android status — 2026-09-14

**LEVEL 5 reached: a real, signed Unity Android APK is available in explicit COMPATIBILITY mode.** Installation, launch, JNI/BLE and physical sensor behavior remain untested: `adb devices -l` completed successfully with no devices listed.

Develop on Windows; the Unity game and Dynamics SDK run together on Android. A separate manufacturer's phone app is not used as a Windows relay.

## Candidate

- Output: `Builds/AndroidCandidate/DigitalDojo.apk`
- SHA-256: `4bb20600a7e17d41fbc3ef4dbdb9be32d348b82d1556f6b421ebfea3d5bff8d5`
- Actual APK size: 34,182,352 bytes. BuildReport totalBytes includes other build output and is not APK size.
- Package `com.boxreha.digitaldojo`, version 1.0 / code 1, ARM64 IL2CPP, landscape, min API 26, target/compile API 36.
- Unity 6000.6.0f1; Unity Gradle 9.1.0 / AGP 9.0.0 / OpenJDK 17.0.18; Kotlin 2.3.21.
- Final BuildPipeline result: Succeeded, 0 errors, 0 warnings, 21.64 seconds. APK v2 signature and zipalign 16-KB check pass.

Authoritative evidence: [APK metadata](artifacts/validation/apk-artifact.json), [build report](artifacts/validation/unity-android-candidate-build.json), [manifest](artifacts/validation/apk-badging.txt), [signature](artifacts/validation/apk-signature.txt), [DEX inventory](artifacts/validation/apk-contents.json).

## SDK and build modes

The original SDK still fails its unchanged dependency graph on missing Resource 2.11.1. A local explicit 2.12.0 dependency rule plus Java/narrow-reflection adapter now compiles the full collector. No SDK binary, metadata or bytecode is patched. All 4,085 files in `C:/dynamics-sdk-main` remain unchanged. Four critical Android AAR hashes are enforced by the build.

Native library + 16 JVM tests pass; the dependency graph resolves. Unity packages the real collector, adapter, SDK and Unity classes. Original Kotlin `Power.Alpha` failure and successful Java consumer remain separately reproducible. Details: [compatibility report](SDK_COMPATIBILITY_REPORT.md), [reproduction commands](vendor-compat/dynamics-0.25.6/README.md).

Default builds remain VENDOR-UNCHANGED. Build this candidate with `scripts/verify-unity.ps1 -BuildCandidate -SdkMode COMPATIBILITY`. The mode appears in native status and research build identity. No mock fallback is enabled.

## Devices and acquisition scope

One device or a left/right pair of one family is implemented and compiles: ALPHA for punches; DELTA power-index events for experimental kick mapping. Neither pair has been tested physically. Mixed ALPHA + DELTA gameplay remains blocked. Actual DB bytecode rejects multiple pairs and parallel active sessions; separate raw API entry points exist and compile, but concurrent physical operation is unproven. [T1–T7 investigation](MULTI_SENSOR_REPORT.md).

Permission denial/settings recovery, reconnect epochs, source identity, duplicate/stale events, pause/background and session acknowledgements have implementation and logic tests. They are not yet Android hardware evidence. Unused legacy storage/phone permissions implied by vendor manifests were removed and verified absent from the APK.

Calibration now supports explicit collection and local persistence of five valid repetitions per device/side/quantity. Records remain UNQUALIFIED; no baseline was fabricated or collected here. Gameplay normalization and heart-rate adaptation remain disabled.

## Next physical test

Connect the selected OnePlus or Galaxy tablet by USB, enable USB debugging and accept this PC's RSA prompt. Neither proposed device is qualified yet. Confirm one entry marked `device`, then install this APK and launch `com.boxreha.digitaldojo/com.unity3d.player.UnityPlayerActivity`.

Verify application startup first, then Bluetooth permission dialogs, scan, one ALPHA and one DELTA separately, side mapping, actual events in Unity, each same-family pair, disconnect/pause/resume and exports. No vendor correction is needed to attempt this compatibility candidate; an official corrected publication remains preferable for qualification.

The previous failed-build status is historical; its immutable findings are retained in `SDK_PACKAGE_BLOCKERS_2026-09-14.md` and the separate original-build evidence.
