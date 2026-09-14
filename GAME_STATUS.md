# Digital Dojo — current status

Updated 2026-09-14. **Unity prototype and COMPATIBILITY Android APK built and verified; physical acquisition remains unqualified (LEVEL 5).** Windows is the development host, Android the sensor/game target.

Unity 6000.6.0f1, Android Build Support and Blender 5.2.1 LTS are installed. Existing Built-in rendering, uGUI, nine-model Blender kit, dojo, three target types, levels/endless, pause, results and research logging are preserved.

## Implemented in this integration pass

- Explicit original/compatibility SDK modes. Resource dependency repair lives in application Gradle rules; a small Java adapter handles stripped Android SDK metadata. No original SDK changes.
- Full native compilation and actual Unity ARM64 IL2CPP APK. Mode, source digest and acquisition identity are traceable.
- Measured-reference collection linked from the seven-step preparation wizard: acknowledged SDK session, five valid repetitions for an explicit device/side, median and local JSON audit record. All records remain UNQUALIFIED; no reference was fabricated. Gameplay damage remains neutral for unnormalized sensor actions. HR is inactive.
- Bounded owned-Editor process handling and locale-independent JSON timestamps. Current prepare/check/build/Play Mode processes exit cleanly. Earlier Search exception is not reproduced; no engine root-cause claim.
- Unused legacy permissions implicitly added by SDK manifests removed and verified absent in the APK.

## Verification

- 9 Unity Editor regression groups; 18 real Play Mode gameplay assertions with synthetic keyboard inputs, plus pause visibility guards.
- 50 Play Mode camera/UI screenshots across four aspect ratios, including the measured-reference screen and all preparation steps.
- 16 native Android JVM tests, including 5 tests of actual supplied SDK classes; 18 isolated Kotlin policy tests including T1–T7.
- 26 existing host groups, 47 Android policy assertions, 17 measured-reference assertions; 18 Gradle-export host checks.
- 72 C# files × 5 platform configurations: zero syntax errors. 635 static scene checks. 60 existing Python analysis tests passed without modifying thesis analysis sources.
- Real APK: 0 build errors/warnings, valid signature and ZIP alignment; metadata and SHA-256 in [Android status](ANDROID_STATUS.md).

No physical sensor, Android launch, touch or mobile performance test has run. ADB reports no devices. One/two same-family acquisition routes compile; mixed gameplay is intentionally unavailable pending a supported and physically tested path. See [multi-sensor report](MULTI_SENSOR_REPORT.md).

Study readiness remains RED. Expose/thesis content and the authoritative SDK are unchanged. [Compatibility evidence](SDK_COMPATIBILITY_REPORT.md), [visual evidence](VISUAL_STATUS.md), [remaining issues](GAME_KNOWN_ISSUES.md).
