# Build result — 18 September 2026

Inspector 0.1.1 / version code 2, package com.digitaldojo.sdkinspector. Final Gradle assembleDebug: BUILD SUCCESSFUL in 43s. Java 17, Gradle 9.1.0, AGP 8.13.2, Kotlin 2.3.21, API 26 minimum / 36 target. Original SDK hash gate passed. Both adapter source files are identical to Unity's copies.

- APK: app/build/outputs/apk/debug/app-debug.apk
- Convenient copy: DynamicsSdkInspector-debug.apk
- Bytes: 13157610
- SHA-256: ec3910c4508a8fd09bf3b916dd54dc5ab7308f60459bcf98359b62e1fdb344d2
- Log: build.log (local, ignored)

Unity 6000.6.0f1 compile and final Android build also succeeded, 0 errors and 0 warnings in BuildReport (existing compiler deprecation warnings remain in the editor log). APK: ../../Builds/AndroidCandidate/DigitalDojo.apk. Final log: ../../Logs/sensor-fix-build-final.log. BuildReport: ../../artifacts/validation/unity-android-candidate-build.json. Source-manifest file hashes verified unchanged after build.

No test suites, screenshots, emulator or physical sensor tests were run, as requested. Both APKs use explicit COMPATIBILITY mode with resource 2.12.0 in place of unavailable 2.11.1. Vendor binaries are unchanged. ABI mismatch corrected using the exact public mangled methods; runtime Bluetooth discovery, re-pairing after removal, pair side swap, single ALPHA/DELTA sides, multiple devices, raw/computed coexistence and recording background continuity still need hardware validation. Independent connect/disconnect remains SDK-owned; no guessed or private GATT API is used.

A concurrent Inspector build was interrupted by a Gradle daemon stop during Unity shutdown; the final two builds were run sequentially and completed. Gradle deprecation warnings remain non-blocking.
