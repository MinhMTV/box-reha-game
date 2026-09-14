# Digital Dojo — current status

Updated 2026-09-14. Windows development; Unity and the native Dynamics SDK run together on Android. **Unity prototype verified; physical Android integration remains unqualified.** This supersedes earlier reports that the Editor, Blender and runtime screenshots were unavailable.

Unity 6000.6.0f1 was imported with the actual Editor. Android Build Support, bundled SDK/NDK/OpenJDK are installed. Blender 5.2.1 LTS generated the original nine-model kit. Built-in rendering and uGUI remain the project architecture.

## Delivered implementation

- Reproducible Blender source, nine FBX models, shared Standard materials, identity-root gameplay prefabs and a modular dojo. Punch is circular/high; kick is upright/low; heavy has separate damage segments. Camera, lighting, feedback and scoring-plane brackets integrate with the existing spawner.
- Shared menu, settings, profile, statistics, preparation wizard, HUD, pause and results presentation. Touch controls and safe-area handling remain. Navigation reflects the active page. Pause now creates its missing CanvasGroup correctly and disables hidden content while retaining the Escape handler.
- Native permission-denial state distinguishes permanent denial; connection UI can open Android app/Bluetooth settings. Source implementation is not device verification.
- Existing provenance, timestamps, device/side assignment and fail-closed session gates remain. Keyboard actions are synthetic and do not become physical sensor evidence.
- Seven-step calibration **preparation** UI, including a skipped optional HR step. No measured baseline, HR adaptation or validated force calibration is claimed.

## Verification

Actual Unity Play Mode captures and synthetic gameplay checks are in [VISUAL_STATUS](VISUAL_STATUS.md). Unity regression checks passed 9 groups. The Play Mode action path passed 18 assertions: all four actions, wrong-side/action rejection, repeated same-hand heavy hits, scoring/provenance and pause/resume. Capture guards additionally verify visible/hidden pause state.

Host checks passed 26 groups plus 47 Android policy assertions; 13 Gradle-export transformation checks; 71 C# files across five conditional configurations; 635 static scene assertions. Host checks are not JNI/Bluetooth execution.

The real native dependency graph still fails on missing vendor artifact resource:2.11.1. See [ANDROID_STATUS](ANDROID_STATUS.md) for the full Unity Android attempt and hardware boundary. Previous diagnostic vendor metadata defects remain in [SDK_PACKAGE_BLOCKERS_2026-09-14](SDK_PACKAGE_BLOCKERS_2026-09-14.md).

## Remaining qualification

Obtain a supported corrected SDK publication; build and install the Android candidate; qualify permissions, Bluetooth off, each side/device, foreground/background, reconnect, latency and exports on an attached phone/tablet. The user proposed OnePlus 15 or Galaxy Tab S3; neither is qualified. Simultaneous two ALPHA plus DELTA still needs a confirmed SDK session route. Current collector supports one/two devices of the same family. Study readiness remains RED.

The approved expose, thesis scope and authoritative C:/dynamics-sdk-main were not changed. Local workflow and review: [project documents](docs/projects/digital-dojo/REVIEW.md).
