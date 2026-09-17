# Android status — 17 September 2026

## Current candidate
- `Builds/AndroidCandidate/DigitalDojo.apk`: version **1.5 / code 6**, package `com.boxreha.digitaldojo`.
- Actual file size **39,524,313 bytes**; SHA-256 `D3A61E445EAF4EF795BE8741F7B79FE4A45B49D9252611153BCACACAA069DF5C`.
- Unity **6000.6.0f1**, ARM64 / IL2CPP, landscape, min API 26, target/compile API 36; explicit SDK **COMPATIBILITY**.
- Existing build receipt at `artifacts/validation/unity-android-candidate-build.json`: 2026-09-17 11:33 UTC, **Succeeded**, **0 errors / 20 warnings**, 135.997 s. Receipt totalBytes is the Unity report aggregate, not APK file size.
- Latest speed/order code was compile/build-checked; earlier Editor/Play Mode checks do not validate that exact gameplay revision. No tests/builds were run for this documentation update.

## Evidence limits
Latest APK installation, JNI/BLE operation and prolonged gameplay on a real Android device remain unverified. The user's previous APK launch/discovery/ALPHA paired UI are real reported observations, not evidence of latest-build physical actions. Earlier signature/alignment/source-manifest reports and capture files must be matched to their original hashes; they do not automatically certify this APK.

## SDK modes
Windows develops/builds; Unity and SDK run together on Android without a relay app. VENDOR-UNCHANGED remains blocked by missing resource 2.11.1. Explicit COMPATIBILITY uses 2.12.0 and a Java/narrow-reflection adapter and has produced the current APK. It is not vendor runtime certification. See [SDK_COMPATIBILITY_REPORT.md](SDK_COMPATIBILITY_REPORT.md).

Current policy supports a single device or same-family Left/Right pair; unknown/mixed families and third/fourth devices are blocked. [MULTI_SENSOR_REPORT.md](MULTI_SENSOR_REPORT.md). Strong/Rapid references and calibrated normalization are implemented but physically unqualified.

## Next device gate
Authorize USB debugging, verify the actual device ABI/OS against ARM64/min API 26, install the exact APK, then record permissions, pairing/removal/side swap, real ALPHA/DELTA actions separately, profile/reference isolation, pause/reconnect and sustained performance. OnePlus 15 and Tab S3 remain candidate devices pending qualification. [TODO.md](TODO.md).

Older 1.0–1.4 candidate identities are historical, not the current artifact. See dated reports and `docs/history/` for preserved evidence.
