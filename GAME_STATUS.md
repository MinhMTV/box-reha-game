# Current status — Android focus

Updated 2026-09-14. **Target: develop on Windows; run the game and native Dynamics SDK together on Android. Study readiness: RED.** The user selected OnePlus 15 or Samsung Galaxy Tab S3 as possible test devices and confirmed that Unity 6.6 is still being installed. Neither device has been qualified.

Game: `E:\Programming Projekte\box-reha-game`. Thesis: `E:\Programming Projekte\latex_diplom`. Approved expose: `E:\Programming Projekte\expose_latex_diplom`. Authoritative SDK: `C:\dynamics-sdk-main`, version 0.25.6. Expose and SDK remain unchanged. The project still records Unity 2022.3.62f3; Unity 6.6 migration is pending an actual Editor import. Editing the version text alone would not constitute a migration.

## Implemented source

- Android Kotlin collector initializes the SDK, requests permissions, scans, pairs with explicit side assignment, configures the SDK body profile, controls sessions and forwards computed punch events with original quantity/clock/identity evidence.
- Unity uses an Android connection screen and native acknowledgements before starting or resuming. Participant, request, family and device configuration must match; stale or missing status blocks the physical game.
- ALPHA punch mode and DELTA kick mapping accept one device or an explicit left/right pair of the same family. Targets use only connected sides. DELTA excludes punch-only heavy/chain mechanics. Two ALPHA gloves plus one DELTA together remain unsupported by this collector pending a confirmed SDK route.
- Android touch pause/finish, landscape and safe-area handling are present. Windows keyboard/pointer input is explicitly a development condition.
- Research JSONL retains sensor evidence plus optional sanitized Android acquisition metadata. Weight, height, gender and display names are excluded from that stream; the SDK's own local profile/session storage is separate.
- Android preparation, APK build entrypoint, generated-Gradle integration and standalone native verification scripts are present.

These are implementation claims. They do not establish that the game launches, the JNI bridge works on a device or physical detection is accurate.

## Current build blocker

The actual standard Gradle build fails to resolve `com.riseworld.launchpad.resource:resource:2.11.1`, requested by SDK 0.25.6 and its components. The supplied SDK repository contains 2.12.0 instead. See `artifacts/validation/android-collector-build.log`. The production dependency graph is not silently changed. A separately labelled diagnostic build using 2.12.0 can find source errors but cannot qualify the supplied SDK configuration.

That diagnostic compile exposes a second package defect: Android `Power` lacks Kotlin metadata and inner-class attributes, while inspected `BleGloveState`/`ScannerState` retain Kotlin metadata but lack inner-class attributes. Documented nested/value-class APIs are consequently unavailable to the Kotlin compiler. No mangled-ABI/reflection workaround was added. Exact evidence and the required corrected vendor bundle are in `SDK_PACKAGE_BLOCKERS_2026-09-14.md`.

SDK AAR metadata additionally requires **compileSdk 36**. The Android library/build preparation reflects this requirement. Java 17, Android API 36 and the standalone Gradle qualification tools are available; Unity 6.6 import/export/APK and device tests remain separate gates. Unity Personal is active, but an installed Editor was not available for these checks.

## Verification

Current evidence is recorded in `ANDROID_VALIDATION_2026-09-14.md` and `artifacts/validation`. Deterministic host logic, pure Gradle-export transformations and static source/assets are checked independently of Unity. The 13 September checks remain historical in `VALIDATION_REPORT_2026-09-13.md` and must not be relabelled as current Android execution.

No Unity compilation, APK, rendered scene walkthrough, physical BLE connection or sensor ground-truth evaluation has passed in this cycle. No real gameplay screenshots were generated. The UI layout and Android lifecycle still require runtime review.

## Remaining scope

1. Obtain the matching missing SDK artifacts or vendor confirmation of an exact supported dependency replacement.
2. Finish the Unity 6.6 installation with Android Build Support, SDK/NDK and OpenJDK; import the existing project, inspect migration changes, then run the Android verification command in `SETUP_GUIDE.md`.
3. Install the development APK on the selected Android device and qualify permissions, each device/side, pause/background/reconnect, timing and local exports.
4. Establish whether simultaneous two-glove plus foot-sensor use is supported. Separate ALPHA/DELTA tests do not answer that combined-device claim.
5. Complete measured calibration and technical coverage/rejection instrumentation if required by the frozen study protocol. HR remains inactive.

Research questions and substantive expose logic are unchanged. No clinical efficacy, completed interviews, user-study results, measured force normalization or study readiness is inferred from code or synthetic tests. Read `GAME_KNOWN_ISSUES.md`, `OPEN_DECISIONS.md` and the thesis status for the remaining methodological gates.
