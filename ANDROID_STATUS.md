# Android status — 2026-09-14

Target: develop on Windows, install the Unity game on Android, and connect sensors from that game through the native SDK. A separate manufacturer Android app is not the intended bridge. **No working APK or physical sensor session is claimed.**

## Toolchain and implementation

Unity 6000.6.0f1 is installed with Android Build Support, SDK, NDK and OpenJDK. The actual generated project uses AGP 9.0.0 and Unity's Gradle 9.1.0, with Kotlin 2.3.21 configuration supplied by the existing export hook. The bundled Java runtime reports 17.0.18. Candidate settings were written through Unity Editor API: application id `com.boxreha.digitaldojo`, minimum API 26, target API 36, ARM64/IL2CPP and landscape.

The Android-native collector remains source-implemented against Dynamics 0.25.6. JNI command/status transport, fresh readiness acknowledgements, participant/side/family binding, pause/background gates and sensor provenance are preserved. This pass adds permanent-denial status and app/Bluetooth settings entrypoints. Those native paths still require full Kotlin compilation and hardware qualification.

## Build evidence

- `scripts/verify-android-collector.ps1`: actual native Gradle execution still fails to resolve `com.riseworld.launchpad.resource:resource:2.11.1`; the supplied local SDK contains 2.12.0. The production graph was not replaced. See `artifacts/validation/android-collector-build.json` and `.log`.
- Android-target Unity Editor checks: 9 passed, 0 failed. Candidate preparation exited successfully. The checks Editor wrote its complete report but remained alive during shutdown; the owned process was terminated. Therefore the wrapper is not a clean success.
- A separate real `GameRegressionChecks.BuildAndroidCandidate` invocation proceeds through BuildPipeline, IL2CPP/graphics generation and the generated Gradle export. Its final result is recorded below after execution, with `artifacts/validation/unity-player-build.log` and `unity-android-candidate-build.json` as authority.
- Prior explicitly diagnostic resource substitution exposed stripped Kotlin metadata/InnerClasses in Android SDK artifacts. That is not a supported dependency fix. [Exact vendor package findings](SDK_PACKAGE_BLOCKERS_2026-09-14.md).

## Devices and session scope

OnePlus 15 and Galaxy Tab S3 were proposed by the user; neither is qualified. Bundled `adb devices -l` timed out after 15 seconds, so it did not establish an authorized USB device. Windows PnP Bluetooth entries are not proof of an Android debugging connection. No APK was installed or BLE session executed.

Current collector supports one sensor or explicit left/right pair **of the same family**. ALPHA actions map to punches; DELTA actions use the documented power-index channel for experimental kick mapping. Simultaneous two ALPHA gloves plus DELTA requires a confirmed vendor session route and tests; it is neither silently emulated nor declared impossible. Heart rate is a separate inactive channel.

## Exact next qualification

1. Obtain the corrected, mutually compatible vendor Maven publication (including resource dependency and usable Kotlin metadata).
2. Run `scripts/verify-android-collector.ps1` with the documented Java/Gradle/SDK paths, then `scripts/verify-unity.ps1 -Target Android -BuildCandidate` using Unity 6000.6.0f1.
3. Connect the chosen Android device by USB, enable USB debugging and authorize this PC. Confirm an authorized `adb devices -l` entry before installing the new candidate.
4. Test initial denial/permanent denial, Bluetooth off, each physical side, disconnect while playing, pause/background/resume acknowledgement and finishing the session. Verify raw quantity, timestamps, source/device identity and research exports; do not count technical faults as misses.
5. Separately qualify combined-device topology, measured calibration and optional HR before making those claims.

## Final result

Final BuildPipeline attempt: **Failed**, 2026-09-14T00:30:34Z, 48.46 seconds, 3 reported errors and 15 warnings. Both native Kotlin compilation and launcher resource processing fail because resource 2.11.1 is unavailable. No successful APK exists. The first uncached attempt also failed on that dependency after 249.68 seconds. Additional SDK read-only metadata and deprecated Gradle-option warnings are retained in the logs; they are not substituted for the actual dependency failure.

Final game implementation: commit 68914a5. The exact source manifest stamped before the build remained byte-for-byte unchanged through the build. See digital-dojo-final-qualification.json for the build stamp and delivery digest; the latter excludes generated performance-test metadata. Environment-variable dumps have been removed from shareable Unity logs, with redaction recorded separately.
