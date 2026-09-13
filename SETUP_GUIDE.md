# Setup and qualification

Use the existing repository at `E:\Programming Projekte\box-reha-game` with **Unity 2022.3.62f3**, matching ProjectSettings/ProjectVersion.txt. Do not create a new Unity project, import scripts separately or regenerate scenes as a setup step.

The deployment target is the complete Unity game plus Dynamics SDK on Android. Windows is only the development host; no gateway PC is required at runtime. Unity 6.6 is being installed but has not yet been imported/qualified for this project. Keep the recorded version until the actual migration; record and review all import/package/build changes. OnePlus 15 and Galaxy Tab S3 are the intended device checks.

**Android build prerequisite currently blocked:** the full collector exists as source against the documented SDK API, but the production graph lacks `resource:2.11.1`. A separate diagnostic substitution with 2.12.0 also fails to compile the documented API because the supplied Android AARs have stripped Kotlin metadata/InnerClasses. Obtain corrected SDK artifacts before expecting a native build/APK. Do not treat that substitution as a production dependency fix. See [SDK package blockers](SDK_PACKAGE_BLOCKERS_2026-09-14.md).

## Open the project

1. Install/activate the exact recorded Editor through Unity Hub with Android Build Support, SDK/NDK and OpenJDK. A future Unity 6.6 migration uses that Editor's bundled Android toolchain, not a manually assumed compatible old export.
2. In Hub, add the existing repository directory. Allow package resolution and inspect compiler/import errors.
3. Open Assets/Scenes/Boot.unity and enter Play Mode for the normal scene flow.
4. Windows Editor play uses development input: Left/Right Arrow = punches; A/D = kicks; each KeyDown emits one abstract action. Use the visible PAUSE button or ESC; Enter ends endless, or choose Pause -> Finish & Results.

The live hub replaces old serialized concept UI in Awake. Inspect it in Play Mode: Editor-only previews of MainMenu.unity can still display dormant historical mock values. The hub shows actual local profile/history and clearly unavailable calibration. No hardware connection, calibration baseline or HR value is implied by opening it.

## Reproducible checks

From the repository root:

```powershell
dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release
dotnet run --project tests/syntax/SyntaxChecks.csproj -- .
python tests/check_scene_assets.py
```

The host harness uses .NET 10 and minimal Unity stubs. Its fixtures are **SYNTHETIC / NOT EMPIRICAL DATA**. Syntax parsing and serialized-reference checks do not establish Unity API compilation, rendering or sensor behavior.

With a licensed Editor installed, run:

```powershell
.\scripts\verify-unity.ps1 -UnityPath "C:\Program Files\Unity\Hub\Editor\2022.3.62f3\Editor\Unity.exe" -BuildCandidate
```

Replace the executable path with the exact installed and imported Editor. The Android verification path prepares PlayerSettings before stamping the source revision/hash, runs GameRegressionChecks.RunBatch and optionally builds an ARM64 IL2CPP Development APK. Omit -BuildCandidate for Editor checks only. Output goes to artifacts/validation/; Android candidate output is Builds/AndroidCandidate/DigitalDojo.apk with unity-android-candidate-build.json. The separate BuildStudyCandidate entrypoint remains a Windows development build, not the sensor deployment target.

GameRegressionChecks.PrepareAndroidCandidate configures com.boxreha.digitaldojo, landscape, target API 36 and ARM64/IL2CPP. SDK 0.25.6 AAR metadata requires compile API 36, which must be installed in the chosen Android toolchain. The current 2022 Editor candidate uses minimum API 23; the planned actual 6000.6.x import uses minimum API 26. BuildAndroidCandidate verifies those settings before building and does not change them after the source stamp. Native Gradle/export compatibility is a separate required gate; see the sensor integration notes and consolidated status.

A successful development build is not a study-readiness decision. The script does not launch the player or validate hardware. Without an installed Editor, the Unity gate remains **NOT RUN**; do not substitute host-test results.

## Player QA after a successful build

Exercise Boot/menu/all panels, all three timed levels, endless, all four action keys, wrong-side/action rejection, early/late timing, score/combo, rapid-chain success/failure and heavy damage/completion. Repeat heavy punches on the same side and allow one heavy to expire after 12 active seconds. Check ESC/resume and Finish & Results, including unfinished targets.

Verify profile/name persistence, explicit new-participant IDs, history isolation, reduced motion, audio settings and error display. Reconcile JSONL action/target/score records against displayed results, including pauses and interrupted sessions. Capture real runtime screenshots of the hub, punch, kick, heavy, calibration preparation, results, statistics and profile. Record console errors and actual build/source identity.

## Sensor and study boundaries

On the Android candidate:

1. Choose Sensor setup; initialize SDK, grant requested Android permissions, and scan.
2. Cycle discovered devices and pair each to its **actual physical** Left or Right side. Family is identified after connection. Inspect online/offline/error status; Remove corrects a wrong assignment.
3. Enter this participant's SDK body profile: weight 20–250 kg, height 50–250 cm, explicit MALE or FEMALE. Fields start empty; no category is preselected. These are SDK prerequisites with local SDK persistence, not game-force calibration. Missing/invalid/rejected entries keep readiness closed.
4. Choose Alpha punches or experimental Delta kick mapping. Use one device or one left/right pair of one family; targets only use connected sides. Mixed Alpha+Delta and three-device setups are unsupported. Delta mode excludes heavy targets and punch chains.
5. Start the selected level. The scene opens only after the matching running acknowledgement for this request, study/profile and family. UI status must remain honest on denied permissions, failures and missing devices. End SDK session is available for failed-start recovery.
6. Exercise touch PAUSE/Resume/Finish, disconnect/reconnect, background/foreground and new-participant changes. Resume requires a fresh acknowledgement. A changed device selection requires a new round. Finish must retain game results even when the SDK reports a finish failure.
7. Delay Unity callback handling deliberately and verify that Android emission time prevents queued punches/status from becoming fresh again. Source age must include native first-packet age, measured JNI transport age and Unity queue age. Do not interpret the SDK timestamp as movement onset.

The authoritative external SDK checkout is `C:\dynamics-sdk-main`. Source integration and native compilation do not prove actual discovery, SDK initialization, connection, subscription or physical detection. Follow SENSOR_INTEGRATION_AUDIT.md and the bridge notes, then qualify Alpha and Delta separately. Preserve device, side, quantity, unit, clock, validity and provenance. Keyboard/SDK mocks are not physical observations.

Calibration capture/persistence and active HR adaptation are not provided by the current hub. Explicitly exclude unqualified channels from a study configuration. Physical status remains **NOT VERIFIED WITH PHYSICAL HARDWARE** until evidence exists.

Actual runtime data uses Application.persistentDataPath: research/<sessionId>.jsonl plus session-history-v1.json. On Android, obtain these app-specific files through an explicitly controlled device/export workflow; do not assume the Windows data path. Display names and SDK body values are not exported in game JSONL. Generated study IDs link records; acquisitionJson snapshots contain SDK/profile/device/connection/firmware and family state. A different participant requires New participant ID and a newly acknowledged SDK body profile. Earlier history remains intact. RESEARCH_LOG_SCHEMA.md defines metrics and incomplete-session handling; acquisition snapshots are not a complete raw-packet/rejection log.

GAME_STATUS.md and GAME_KNOWN_ISSUES.md are the handoff checklist. Scene generators rewrite scenes/assets and are maintenance tools; do not run them merely to inspect or qualify this project.
