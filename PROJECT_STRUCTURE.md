# Project structure — 17 September 2026

Main checkout: `E:/Programming Projekte/box-reha-game`, source baseline `3f99b17`. Unity 6000.6.1f1 (later patch of the originally targeted 6000.6.0f1 stream; see [ANDROID_STATUS.md](ANDROID_STATUS.md)). Enabled scenes: Boot, MainMenu, Game, Results. Do not use the historical detached worktree as current authority.

| Location | Responsibility |
|---|---|
| Assets/Scripts/Config | Game/level configuration and factories |
| Assets/Scripts/Core | Round/session orchestration and shared services |
| Assets/Scripts/Spawning/GameplayPacingProfile.cs | GameplayPacingProfile, GameplayPatternPlanner, ComboPlan, PacingActionTimeline |
| Assets/Scripts/Spawning/TargetSpawner.cs | Rolling work, Heavy insertion, capacity and path spacing |
| Assets/Scripts/Gameplay | Target lifecycle/movement, evaluator, timing/scoring/combo |
| Assets/Scripts/Input | Abstract input routing and development keyboard source |
| Assets/Scripts/Platform | Android session controller, acknowledgement/readiness/topology policy |
| Assets/Scripts/Sensors | SDK bridge/contract, per-device processing, measured references, calibration library and inactive HR scaffold |
| Assets/Scripts/Data | Profile repository/migration, action model, statistics/history |
| Assets/Scripts/Research | Append-only session JSONL and provenance |
| Assets/Scripts/UI | Runtime menu, pairing/profiles/references, HUD/results/statistics |
| Assets/Scripts/Visuals | Room dressing, gate, mounts, visual feedback, mesh-only primitives and bounded effects |
| Assets/Plugins/Android/DynamicsSdkUnityBridge.androidlib | Kotlin collector/JNI facade and explicit SDK compatibility adapter |
| Assets/Editor | Build/integration tools and opt-in synthetic regression/capture helpers |
| Assets/Art, Assets/Resources | Imported meshes/materials/prefabs and runtime resources |
| ArtSource/Blender/DigitalDojo | Blender authoring/generation and reference kit sources |
| tests, scripts, tools/android | Host/native/Editor validation entry points; different evidence boundaries |
| vendor-compat/dynamics-0.25.6 | Compatibility evidence and pinned vendor-artifact inspection |
| Builds/AndroidCandidate | Latest APK; identity in ANDROID_STATUS.md |
| artifacts/validation, DesignReferences/CurrentBuild | Dated test/build evidence and synthetic Editor captures |
| docs/history, docs/projects/digital-dojo | Historical snapshots, issues and milestone records |

The authoritative external SDK distribution is `C:/dynamics-sdk-main`; the repository's SDK copy is not authoritative. No full buildable SDK core source is supplied. No SDK files changed in this documentation pass.

Documentation map: [GAME_STATUS.md](GAME_STATUS.md) overview; [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) player behavior; [GAMEPLAY_PACING.md](GAMEPLAY_PACING.md) values; [SPAWNING_ARCHITECTURE.md](SPAWNING_ARCHITECTURE.md) ownership; [SENSOR_INTEGRATION_AUDIT.md](SENSOR_INTEGRATION_AUDIT.md) sensor contract; [TODO.md](TODO.md) remaining work; [OPEN_DECISIONS.md](OPEN_DECISIONS.md) unresolved choices.
