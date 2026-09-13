# Project structure

This is the existing Unity **2022.3.62f3** project at `E:\Programming Projekte\box-reha-game`. Open this project directly. Do not create a replacement project or copy its scripts into a new template.

## Runtime flow

Enabled scenes: `Boot -> MainMenu -> Game -> Results`.

| Area | Main implementation | Responsibility |
|---|---|---|
| Round/state | Assets/Scripts/Core/GameManager.cs, GameRoundController.cs | Level selection, timed/endless sessions, pause, finish and scene transitions |
| Input | Assets/Scripts/Input/ | KeyboardActionFactory, pointer provider and InputProviderRouter emit the common PlayerActionEvent |
| Sensors | Assets/Scripts/Sensors/ | Explicit native contract, per-device identity/queues, validity/freshness and provenance; HR is separate |
| Gameplay | Assets/Scripts/Gameplay/ | Time-based target matching, heavy health/timeout, score, combo and effects; GameplayRules contains deterministic policy |
| Spawning | Assets/Scripts/Spawning/ | Existing level presets, left/right regular targets, center heavy targets and explicit rapid-chain membership |
| Profile/statistics | Assets/Scripts/Data/ | Display name and pseudonymous ID, session summaries and local history |
| Research logging | Assets/Scripts/Research/ResearchSessionLog.cs | Append-only JSONL with session/action/target/score linkage |
| Interface | Assets/Scripts/UI/, Assets/Scripts/Visuals/ | Runtime Digital Dojo hub, live HUD, results and reused dojo dressing |
| Configuration | Assets/Resources/GameConfig.asset, ProjectSettings/, Packages/ | Existing input/configuration, enabled scenes and package resolution |
| Qualification | Assets/Editor/GameRegressionChecks.cs, tests/, scripts/verify-unity.ps1 | Separate host, static, Editor and candidate-build gates |

Left/Right Arrow emit left/right punches on **KeyDown**; A/D emit left/right kicks. A held key does not add a charged-release second action. Development input has explicit provenance and uses the same abstract event route as sensor input. ESC pauses/resumes; Enter finishes endless. Pause -> Finish & Results also ends a session.

The current DigitalDojoMenuController rebuilds its UI in Awake from actual state. Historical concept panels remain serialized in MainMenu.unity but are disabled/replaced before rendering. An Editor preview outside Play Mode may therefore show obsolete concept values; it is not an implementation screenshot. Calibration is explicitly unavailable, with its intended comfortable-action procedure explained.

## Data

Research JSONL: `Application.persistentDataPath/research/<sessionId>.jsonl`.
Recent summaries: `Application.persistentDataPath/session-history-v1.json`.
Profile/settings use local PlayerPrefs. Display-name changes preserve the current study ID; New participant ID creates a different ID without deleting earlier records. Corrupt history is preserved and reported instead of replaced with an empty history.

See RESEARCH_LOG_SCHEMA.md for fields, clocks, denominator rules and limits. Timing accuracy is Perfect+Good over resolved targets; completion also includes Early/Late. Neither measures sensor recognition accuracy. Calibration, HR and adaptation producers are not active gameplay channels.

## Evidence boundaries

Source inspection establishes what is written. Host tests execute production logic against minimal Unity stubs. Syntax/static-YAML checks do not compile or run Unity. Editor checks, actual player interaction and physical-sensor verification are separate gates. Synthetic fixtures are labelled and isolated; they are not empirical results.

Current status and limitations: GAME_STATUS.md, GAME_KNOWN_ISSUES.md, GAMEPLAY_UI_AUDIT.md and SENSOR_INTEGRATION_AUDIT.md. Setup and exact qualification commands: SETUP_GUIDE.md.
