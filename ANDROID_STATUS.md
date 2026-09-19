# Android status — 18 September 2026

## Current candidate
- `Builds/AndroidCandidate/DigitalDojo.apk`: version **1.5 / code 6**, package `com.boxreha.digitaldojo`.
- Actual file size **422,993,513 bytes** (Unity report aggregate; APK file is smaller); SHA-256 `d22cc028a1de8f9ffbc4f7a900f739057ef72d78fe1d00727785d9aa9bbf272a`.
- Built on macOS with Unity **6000.6.1f1** (the exact 6000.6.0f1 used for the 17 September candidate was not installable here; this is a later patch of the same 6000.6 stream), ARM64 / IL2CPP, landscape, min API 26, target/compile API 36; explicit SDK **COMPATIBILITY**.
- Build receipt at `artifacts/validation/unity-android-candidate-build.json`: 2026-09-18 13:28 UTC, **Succeeded**, **0 errors / 0 warnings**, 31.4 s.
- This build required a genuine toolchain fix, not a code/gameplay change: Unity 6000.6.1f1 bundles a newer Android Gradle Plugin (9.0.0) whose decorated `LibraryExtension` cannot be cast to the legacy `BaseExtension` the classic external Kotlin Gradle plugin expects, so applying `org.jetbrains.kotlin.android` to `DynamicsSdkUnityBridge.androidlib` failed with a `ClassCastException`. `Assets/Editor/DynamicsGradleExportConfig.cs` now detects AGP 9+ at export time and switches that one exported module to AGP 9's own built-in Kotlin support (`android.builtInKotlin=true`, external plugin/`kotlinOptions` block stripped from the *exported copy only*); AGP 8.x exports (and the separate `tools/android` qualification project, which pins AGP 8.13.2) are unaffected and keep the classic external-plugin path unchanged.
- Latest speed/order code was compile/build-checked; earlier Editor/Play Mode checks do not validate that exact gameplay revision. No Play Mode/gameplay tests were run for this documentation update.

## Evidence limits
Latest APK installation, JNI/BLE operation and prolonged gameplay on a real Android device remain unverified. The user's previous APK launch/discovery/ALPHA paired UI are real reported observations, not evidence of latest-build physical actions. Earlier signature/alignment/source-manifest reports and capture files must be matched to their original hashes; they do not automatically certify this APK.

## SDK modes
Windows develops/builds; Unity and SDK run together on Android without a relay app. VENDOR-UNCHANGED remains blocked by missing resource 2.11.1. Explicit COMPATIBILITY uses 2.12.0 and a Java/narrow-reflection adapter and has produced the current APK. It is not vendor runtime certification. See [SDK_COMPATIBILITY_REPORT.md](SDK_COMPATIBILITY_REPORT.md).

Current policy supports a single device or same-family Left/Right pair; unknown/mixed families and third/fourth devices are blocked. [MULTI_SENSOR_REPORT.md](MULTI_SENSOR_REPORT.md). Strong/Rapid references and calibrated normalization are implemented but physically unqualified.

18 September fixes: `SessionInputSelection` no longer defaults to ALPHA when only DELTA hardware is connected (it now fails closed with `null` until the SDK reports a real family, fixing a `family_downgrade_refused` rejection for DELTA-only setups); the standalone Gradle projects no longer fall back to a hardcoded Windows Maven path; and the androidlib's `consumer-rules.pro` now keeps every class `Sdk0256Compat` reaches by reflection (it previously missed `GloveRepository`, `SensorDataRepository`, `PairingRepository` and `SensorDataPacket`, a latent break under R8/ProGuard minification). See [SDK_COMPATIBILITY_REPORT.md](SDK_COMPATIBILITY_REPORT.md).

## Next device gate
Authorize USB debugging, verify the actual device ABI/OS against ARM64/min API 26, install the exact APK, then record permissions, pairing/removal/side swap, real ALPHA/DELTA actions separately, profile/reference isolation, pause/reconnect and sustained performance. OnePlus 15 and Tab S3 remain candidate devices pending qualification. [TODO.md](TODO.md).

Older 1.0–1.4 candidate identities are historical, not the current artifact. See dated reports and `docs/history/` for preserved evidence.
