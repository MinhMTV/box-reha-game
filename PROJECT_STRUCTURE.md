# Project structure — current hardware feedback pass

Existing Unity 6000.6.0f1 project. Active engineering worktree: E:/Programming Projekte/worktrees/wt-agent-root-digital-dojo. Primary user checkout: E:/Programming Projekte/box-reha-game. Four scenes and existing assets retained.

- Assets/Plugins/Android/DynamicsSdkUnityBridge.androidlib: real Android SDK collector/JNI facade, compatibility build and ABI hash gates.
- Assets/Scripts/Platform: acknowledged SDK lifecycle, current-participant readiness and topology policy.
- Assets/Scripts/Sensors: native contract, identity/epoch/freshness processing, measured references and CalibrationLibrary.
- Assets/Scripts/Data: FileProfileRepository, legacy profile facade, existing session summaries/history and action schema.
- Assets/Scripts/Gameplay and Spawning: common action matching, TOO LIGHT, bounded heavy damage and terminal cleanup.
- Assets/Scripts/Visuals: retained dojo/art, collider-free VisualPrimitive and uncluttered HUD.
- Assets/Scripts/UI: named sensor setup, profiles, real reference workflow and scoped statistics/results.
- Assets/Scripts/Research: append-only game JSONL; calibration audit is separately recorded under persistentDataPath/calibration.
- Assets/Editor/DigitalDojoCapture.cs: opt-in synthetic Play Mode regression and layout captures.
- tests/sensor: production host logic/persistence tests; tests/android-export and tests/syntax remain separate checks.
- scripts/verify-unity.ps1 and verify-android-collector.ps1: existing build paths. verify-hardware-feedback-playmode.ps1 owns only its batch Editor.

Current behavior: CURRENT_GAMEPLAY.md. Artifact and runtime boundaries: ANDROID_STATUS.md and HARDWARE_FEEDBACK_REPORT.md. Historical pre-hardware descriptions are under docs/history/pre-hardware-feedback.
