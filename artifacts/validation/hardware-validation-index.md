# Final evidence for hardware-feedback pass

Authoritative latest run: hardware-playmode-final.log + hardware-playmode-process.json + dd-runtime-checks.txt. The older hardware-playmode.log is an intermediate historical capture log, not the final source validation. Final screenshots: DesignReferences/CurrentBuild/Hardware-Feedback (75 PNGs).

hardware-host.log / hardware-export.log and csharp-syntax.json / static-scene-checks.json are final host/static runs. Native final compilation: COMPATIBILITY/android-collector-build.json (16 tests, source hashes). Source did not change after its final native compilation. hardware-vendor-integrity.json records 4,085 unchanged vendor files.

Latest new APK: apk-artifact.json; Unity result: unity-environment.json and unity-android-candidate-build.json. unity-source-manifest.json records the exact Assets/Packages/ProjectSettings snapshot, including build-generated version 1.1/code2. Build warnings remain documented in ANDROID_STATUS.md. adb devices: hardware-adb-devices.txt, no device. Old android-compat-delivery.json concerns the prior APK/primary delivery only and is not a receipt for this new build.

No synthetic record constitutes physical participant data. The new APK has not been installed or sensor-tested here.
