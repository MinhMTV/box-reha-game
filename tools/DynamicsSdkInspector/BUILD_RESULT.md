# Build result � 18 September 2026

Inspector 0.1.1 / version code 2, package com.digitaldojo.sdkinspector. Final Gradle assembleDebug: BUILD SUCCESSFUL in 43s. Java 17, Gradle 9.1.0, AGP 8.13.2, Kotlin 2.3.21, API 26 minimum / 36 target. Original SDK hash gate passed. Both adapter source files are identical to Unity's copies.

- APK: app/build/outputs/apk/debug/app-debug.apk
- Convenient copy: DynamicsSdkInspector-debug.apk
- Bytes: 13157610
- SHA-256: ec3910c4508a8fd09bf3b916dd54dc5ab7308f60459bcf98359b62e1fdb344d2
- Log: build.log (local, ignored)

Unity 6000.6.0f1 compile and final Android build also succeeded, 0 errors and 0 warnings in BuildReport (existing compiler deprecation warnings remain in the editor log). APK: ../../Builds/AndroidCandidate/DigitalDojo.apk. Final log: ../../Logs/sensor-fix-build-final.log. BuildReport: ../../artifacts/validation/unity-android-candidate-build.json. Source-manifest file hashes verified unchanged after build.

No test suites, screenshots, emulator or physical sensor tests were run, as requested. Both APKs use explicit COMPATIBILITY mode with resource 2.12.0 in place of unavailable 2.11.1. Vendor binaries are unchanged. ABI mismatch corrected using the exact public mangled methods; runtime Bluetooth discovery, re-pairing after removal, pair side swap, single ALPHA/DELTA sides, multiple devices, raw/computed coexistence and recording background continuity still need hardware validation. Independent connect/disconnect remains SDK-owned; no guessed or private GATT API is used.

A concurrent Inspector build was interrupted by a Gradle daemon stop during Unity shutdown; the final two builds were run sequentially and completed. Gradle deprecation warnings remain non-blocking.

## Follow-up audit — 18 September 2026 (second pass)

Re-verified every Sdk0256Compat reflective descriptor against `javap -p -s` output extracted from the shipped 0.25.6 classes.jar (dynamics-multiplatform-android, dynamics-models-android, dynamics-ble-android, dynamics-models-composite-android AARs): `deleteGloveById-gP7SR54`, `swapGloveSideForId-gP7SR54`, `observeSensorData-16HgSWs`, `deleteAllGloves`, `observeSensorDataFromAllGloves`, `PairingRepository.pair`, `PeripheralDto.getId-WPD2SKI`, `PeripheralId.box-impl`/`unbox-impl`, `Punch.getId-x1nF_Dg`/`getPeripheralId-WPD2SKI`, `SensorDataPacket.getRelativeTimeCounter-UwyO8pc`, `BodyProfile.getId-vSVUwiQ`, `Speed.getPunchDuration-UwyO8pc`/`getContactDuration-UwyO8pc`, and `Power`/`Power.Alpha`/`Power.Delta` (`getImpactOrPowerIndex`, `getPeakForce`, `getImpact`, `getPeakForceBasedOnBaro`, `getPowerIndex`) all match exactly. No stale mangled names found; no `NoSuchMethodError` is swallowed (lookup and invocation failures both `throw`).

Removed dead code with no behavioral change: the unused `reconnect()` command in DynamicsSdkManager.kt, the entirely-unreferenced `SdkFields.kt` generic reflection-based serializer (superseded by the explicit serializers this project already committed to — see FIELD_COVERAGE.md), and twelve unused Sdk0256Compat.java methods (`resourceGetOrThrow`, `peripheralId`, `belongsTo`, `profileId`, `validName`, `online`, the eight `isGlove*` wrappers, `missingScanningRequirements`, `durationSeconds`) plus their now-orphaned `BOX_ID`/`PROFILE_ID` reflective fields and imports, narrowing the ABI bridge to only what the app actually calls. No other functional bug was found in scan/pair/remove/swap lifecycle, raw acquisition envelope, computed session lifecycle, or recording/export paths on this pass.

Rebuilt after the cleanup: `assembleDebug` BUILD SUCCESSFUL. APK: app/build/outputs/apk/debug/app-debug.apk, bytes 13056066, SHA-256 6ad8928c61a41f3be44f00fb6b8418450eef7e03c6d3e9b36a5cff6c609f59c0. Still no tests, screenshots, emulator or physical hardware runs performed.
