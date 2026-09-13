# Setup and qualification

Use the existing repository at `E:\Programming Projekte\box-reha-game` with **Unity 2022.3.62f3**, matching ProjectSettings/ProjectVersion.txt. Do not create a new Unity project, import scripts separately or regenerate scenes as a setup step.

## Open the project

1. Install/activate Unity 2022.3.62f3 through Unity Hub, including Windows build support for the candidate build.
2. In Hub, add the existing repository directory. Allow package resolution and inspect compiler/import errors.
3. Open Assets/Scenes/Boot.unity and enter Play Mode for the normal scene flow.
4. Use the runtime hub to select a level or endless session. Left/Right Arrow = punches; A/D = kicks; each KeyDown emits one abstract action. ESC pauses/resumes. Enter ends endless, or choose Pause -> Finish & Results.

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

Replace the executable path if your installation differs. The script stamps the current source revision/hash, runs GameRegressionChecks.RunBatch and optionally builds the enabled scenes as a Windows x64 development candidate. Omit -BuildCandidate for Editor checks only. Output goes to artifacts/validation/; the candidate executable is Builds/StudyCandidate/DigitalDojo.exe.

A successful development build is not a study-readiness decision. The script does not launch the player or validate hardware. Without an installed Editor, the Unity gate remains **NOT RUN**; do not substitute host-test results.

## Player QA after a successful build

Exercise Boot/menu/all panels, all three timed levels, endless, all four action keys, wrong-side/action rejection, early/late timing, score/combo, rapid-chain success/failure and heavy damage/completion. Repeat heavy punches on the same side and allow one heavy to expire after 12 active seconds. Check ESC/resume and Finish & Results, including unfinished targets.

Verify profile/name persistence, explicit new-participant IDs, history isolation, reduced motion, audio settings and error display. Reconcile JSONL action/target/score records against displayed results, including pauses and interrupted sessions. Capture real runtime screenshots of the hub, punch, kick, heavy, calibration preparation, results, statistics and profile. Record console errors and actual build/source identity.

## Sensor and study boundaries

The authoritative external SDK path is `C:\dynamics-sdk-main`. Native forwarding code does not prove discovery, SDK initialization, connection, subscription or physical detection. Follow SENSOR_INTEGRATION_AUDIT.md and the bridge notes, then independently qualify RD ALPHA and RD DELTA. Preserve device, side, quantity, unit, clock, validity and provenance. Keep keyboard/SDK mocks separate from physical observations.

Calibration capture/persistence and active HR adaptation are not provided by the current hub. Explicitly exclude unqualified channels from a study configuration. Physical status remains **NOT VERIFIED WITH PHYSICAL HARDWARE** until evidence exists.

Actual runtime data uses Application.persistentDataPath: research/<sessionId>.jsonl plus session-history-v1.json. Display names are not exported in the research log; generated study IDs link records. A different participant requires the explicit New participant ID action. RESEARCH_LOG_SCHEMA.md defines metrics and incomplete-session handling.

GAME_STATUS.md and GAME_KNOWN_ISSUES.md are the handoff checklist. Scene generators rewrite scenes/assets and are maintenance tools; do not run them merely to inspect or qualify this project.
