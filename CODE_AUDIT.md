# Repository Code Audit — 18–19 September 2026

Full source-level audit against the actual current implementation (not the older status docs). Baseline: uncommitted changes on top of main `b1925ef`. Validated by an actual C# compile, a full Unity Android build (`GameRegressionChecks.BuildAndroidCandidate`, Unity 6000.6.1f1), and the `DynamicsSdkInspector` Gradle build — all succeeded with 0 errors / 0 warnings after the fixes below. A follow-up pass on 19 September covered the remaining gameplay/sensor support classes and repository asset bloat (unused third-party assets and redundant QA screenshots); see "19 September follow-up" below.

## P0 — Real bugs / correctness risks

- **`Assets/Scripts/Platform/AndroidSessionPolicy.cs`** — `SessionInputSelection.resolvedFamily` defaulted to hardcoded `"Alpha"`, so DELTA-only hardware silently attempted an ALPHA computed session and was rejected (`family_downgrade_refused`). Fixed: defaults to `null`, fails closed until the SDK reports the real family.
- **`Assets/Scripts/Data/PlayerProfileStore.cs`** — a corrupt/unreadable profile database was correctly refused by the repository layer, but the exception was never caught, so it crashed app init instead of degrading gracefully. Fixed: falls back to an in-memory `TransientProfileRepository` (new, in `ProfileRepository.cs`), surfaces the error, never touches the original file.
- **`Assets/Scripts/Data/SessionHistoryStore.cs`** — the 200-entry history cap applied to the *combined* history across all profiles, not per participant. In a multi-participant study, once the combined total passed 200, an earlier participant's session-history rows could be silently evicted (raw JSONL research logs were unaffected). Fixed: cap is now applied per `StudyId`.
- **Android Gradle Plugin 9 / Kotlin toolchain (`Assets/Editor/DynamicsGradleExportConfig.cs`)** — building on Unity 6000.6.1f1 (AGP 9.0.0) failed with a `ClassCastException` applying the classic external Kotlin Gradle plugin to the exported `DynamicsSdkUnityBridge.androidlib`. Fixed: AGP 9+ exports now use AGP's own built-in Kotlin support instead; AGP 8.x exports (and the separate `tools/android` project) are untouched.
- **`consumer-rules.pro`** (androidlib) — missing `-keep` rules for `SensorDataPacket`, `GloveRepository`, `SensorDataRepository`, `PairingRepository`; any consumer build enabling R8/ProGuard minification would have broken `Sdk0256Compat`'s reflective SDK bridge. Fixed (latent risk, not yet observed since minification isn't currently enabled).
- Every reflected SDK method name in `Sdk0256Compat` (Unity + Inspector) re-verified against actual `javap` output of the shipped 0.25.6 AARs — all correct, no stale ABI.

## P1 — Dead / obsolete code

Removed (all HIGH CONFIDENCE — zero code references, zero scene/prefab serialization, zero reflection/MenuItem reachability, verified before deletion):
- `Assets/Scripts/Data/LeaderboardManager.cs` — PlayerPrefs Top-10 system, fully superseded by `SessionHistoryStore`.
- `Assets/Scripts/Core/SceneLoader.cs` — scene-nav helper duplicating `GameManager`'s own scene handling.
- `Assets/Scripts/UI/LevelSelectController.cs` — zero scene/prefab instances, superseded by `DigitalDojoMenuController`; also duplicated round-start logic incorrectly (missing the physical-sensor lane restriction), so it was both dead and wrong.
- `Assets/Scripts/Gameplay/GameVisualPalette.GetSpawnWarningDuration` — leftover from an already-deleted `SpawnWarningEffect`.
- `Assets/Scripts/UI/ComboMilestonePopup.cs` — dead `shakeIntensity`/`shakeDuration` fields and an orphaned `CameraShake` class (43 lines, superseded by `DojoGameFeel`).
- `Assets/Scripts/Visuals/DigitalDojoRuntimeDressing.cs` — 3 stale entries (`PunchHitLabel`, `KickHitLabel`, `HeavyGateLabel`) in a legacy-object cleanup list; confirmed absent from `Game.unity`.
- **`Assets/Scenes/MainMenu.unity`** — a ~1450-object legacy concept-UI tree (317 GameObjects, disabled German-labeled calibration/statistics placeholders) fully replaced by `DigitalDojoMenuController`'s runtime-built UI. Verified self-contained via hierarchy fileID reachability before removal. File: 799,959 → ~13.6 KB.
- **`Assets/Scenes/Results.unity`** — a matching legacy Results UI tree, plus 17 stale serialized fields on `ResultsController` referencing class members that no longer exist (the class builds everything at runtime).
- **DynamicsSdkInspector**: `SdkFields.kt` (unused generic-reflection serializer, contradicted the app's own "explicit serializers" design), `DynamicsSdkManager.reconnect()`, and 12 unused `Sdk0256Compat.java` wrapper methods that duplicated already-used Kotlin extension properties.
- Repository hygiene: 13 committed Gradle build-cache files under `Assets/Plugins/Android/DynamicsSdkUnityBridge.androidlib/.gradle/` (leaked from the separate `tools/android` project, whose settings.gradle resolves into this shared folder) untracked; a stray unreferenced `box-reha-game.rar` (100 KB, repo root) untracked; both now covered by `.gitignore`.

Found but deliberately **retained** (MEDIUM/LOW confidence — see "Intentional inactive code" and "Remaining uncertain candidates" below).

## P2 — Architecture / maintainability

- **Compiler warnings**: 93 obsolete-API warnings existed (18 in shipped runtime code, ~75 in Editor-only tooling) — `FindObjectOfType`/`FindObjectsOfType`/`FindFirstObjectByType`/`FindObjectsByType(FindObjectsSortMode)` and 4 `PlayerSettings(BuildTargetGroup)` overloads. All resolved: singleton-style lookups → `FindAnyObjectByType`; multi-object enumeration → `FindObjectsByType<T>()`/`FindObjectsByType<T>(FindObjectsInactive.Include)`; `PlayerSettings` → the `NamedBuildTarget` overloads. Two `#if UNITY_EDITOR || DEVELOPMENT_BUILD` diagnostic blocks in `TargetSpawner.Update` converted to `if (Debug.isDebugBuild)` runtime guards (Unity's own recommended migration, identical behavior). Final build: **0 warnings**.
- **`TargetSpawner.cs`** null-`GameConfig` fallback used `2.1f` for the High vertical offset while `GameConfig.VerticalOffsetHigh` defaults to `2.6f`. Aligned the fallback to match.
- **`HUDController` vs `DebugUI`** — both live, both bound to the same on-screen Text object with independent, conflicting F1-toggle logic. Real redundancy; left alone since resolving it is a design call, not a dead-code deletion.
- Three Unity packages (`com.unity.cinemachine`, `com.unity.probuilder`, `com.unity.visualeffectgraph`) have zero references anywhere in `Assets/` — high-confidence unused/template-leftover candidates. Not removed (package removal wasn't in scope for this pass).
- `.gitattributes` added (`* text=auto eol=lf`) — file didn't exist; repo was already 100% LF, so this is a zero-diff policy going forward, not a mass rewrite.

## P3 — Repository / documentation cleanup

- Four current-reading root docs (`OPEN_DECISIONS.md`, `GAME_DECISIONS.md`, `PROJECT_STRUCTURE.md`, `SETUP_GUIDE.md`) still stated Unity 6000.6.0f1 as current; corrected to 6000.6.1f1 with a cross-reference to `ANDROID_STATUS.md`. Dated historical validation reports were left untouched (they already self-identify as historical snapshots).
- No stale `TODO`/`FIXME`/`HACK`/`LEGACY` markers found anywhere in `.cs`/`.kt`/`.java`/`.gradle` source — the codebase has no leftover debt comments to clean up.
- `TODO.md` and `GAME_STATUS.md` updated to reflect all of the above.

## Intentional inactive code (not touched)

- **Heart-rate scaffold** (`Assets/Scripts/Sensors/HeartRateChannel.cs`: `HRSample`, `IHeartRateProvider`, `HeartRateSampleValidator`) — completely inert, zero branching in the active Punch/Kick path, only exercised by `SensorRegressionChecks.cs` in isolation. Matches its documented status in TODO.md as planned/optional future scope. Left untouched.
- **`PlayerProfile.PreferredLevel`** — serialized to disk, never read/written elsewhere. Left untouched: it's part of the on-disk JSON schema, and removing it is a save-compatibility decision outside this pass's scope.
- **DynamicsSdkInspector's raw-stream / remove-lifecycle / ABI-compatibility code** — extensively re-verified against actual shipped SDK bytecode; all of it is genuinely load-bearing for the documented AGP/JVM ABI discrepancy, not dead reflection.
- **Editor tooling** (`DigitalDojoCapture.cs`, `PacingRuntimeProbe.cs`, `HitGatePlayModeChecks.cs`, `DigitalDojoReferenceImport.cs`, and all `[MenuItem]`-only generators) — all trace to a live `[MenuItem]`, `[InitializeOnLoad]`, a `.ps1` `-executeMethod` entrypoint, or a call from another live Editor script. None removed.

## Remaining uncertain candidates (reported, not changed)

- `Assets/Scripts/UI/MainMenuController.cs` / `PlayerProfilePanelController.cs` — zero scene/prefab instances, but both are `AddComponent<>`'d at runtime by `Assets/Editor/SceneAutoSetup.cs`. Confirmed live; do not delete.
- `Assets/Scripts/Input/MouseTouchInputProvider.cs` — `gameConfig` field is explicitly assigned a real asset in `Game.unity` but never read in the class. Non-default serialized value argues against blind deletion.
- `Assets/Scripts/Visuals/DigitalDojoHudSkin.cs` deactivates the Text object that `HUDController.inputStateText` still writes to every frame — visually inert but still "live" code; not touched since it spans a file outside this pass's edits.

## 19 September follow-up

A second pass, prompted by a request to check for unused assets, old screenshots, unused methods, error scenarios, and further code improvements.

**Real bug fixed:**
- `Assets/Scripts/Gameplay/TargetMover.cs` — the miss-zone fallback had a logically unreachable inner branch: an early `if (targetObject != null && evaluator != null) return;` guarantees both can never be simultaneously non-null afterward, yet the next line's condition required exactly that to call `evaluator.Miss(...)`. That call could never fire. Simplified to the two lines that actually execute; behavior is unchanged (confirmed `HitZoneEvaluator.Miss` still has its two other live call sites).

**Dead code removed (HIGH CONFIDENCE — zero callers repo-wide, verified before deletion):**
- `Assets/Scripts/Gameplay/StarRating.cs` — entire file (static class, zero references anywhere).
- `Assets/Scripts/Core/AudioManager.cs` — `PlayBlockSound`, `PlayDodgeSound`, `PlayMenuClick`, `PlayCountdownTick` and their unused clip-building entries; none of these four cue names exist in the actual `DojoAudioCue` enum used elsewhere.
- `Assets/Scripts/Sensors/ISensorDataProvider.cs` — the interface itself (zero implementers/consumers); kept the `SensorReading` struct in the same file, which is used throughout the sensor pipeline.
- `Assets/Scripts/Sensors/SensorDataBuffer.cs` — `GetAll()` and `GetPeakAccelerationMagnitude()` (zero callers; `GetAverageAccelerationMagnitude`, which *is* used by `SensorRegressionChecks.cs`, was kept).

**Defensive fix:** `Assets/Scripts/Platform/MobileSafeArea.cs` — `Refresh()` used `GetComponent<RectTransform>()` unchecked. Not reachable today (all call sites go through `Create()`, which guarantees a `RectTransform`), but it's a public `MonoBehaviour` addable to any GameObject via the Inspector, which would NRE every frame. Added a one-line null guard.

**Repository bloat (unused assets / old screenshots):**
- `artifacts/validation/*.log` — 25 of 95 tracked raw debug/build logs (14 MB, dominated by one 13 MB "first-failure" transcript) had zero references anywhere in any doc or script; removed. The remaining 7 referenced logs (cited by `SDK_PACKAGE_BLOCKERS_2026-09-14.md`, `ANDROID_VALIDATION_2026-09-14.md`, or the `scripts/*.ps1` verification scripts) were kept.
- `ExternalAssets/` (48 MB) — three downloaded Kenney.nl third-party asset kits (both as `.zip` and fully extracted), sitting outside the Unity project (`Assets/`) entirely, with zero references anywhere in code or docs. Untracked from git and added to `.gitignore`; files left on disk in case they're still wanted locally.
- `DesignReferences/CurrentBuild/` (QA-capture screenshots, was 1.1 GB / 1645 tracked files) — a dedicated pass cross-referenced every subdirectory against the docs that cite it by name (`VISUAL_STATUS.md`, `HIT_GATE_SYSTEM.md`, `FITNESS_PACING_VALIDATION.md`, `GAMEPLAY_UI_AUDIT.md`, `hardware-validation-index.md`, `REFERENCE_REFINEMENT_STATUS.md`). Removed only directories with **zero** citations anywhere or explicitly documented as superseded by a named replacement: `Gameplay-Consolidation-Final` (213 MB, uncited — its cited sibling `Gameplay-Consolidation` was kept), `Punch-Heavy-Refinement` (193 MB, uncited), `Mounted-Targets` (16 MB, uncited), `Reference-Animation` (16 MB, uncited), `Before` (6.6 MB, doc explicitly says "the `Final` set supersedes them"), `Reference-Imported` (53 MB, doc narrative describes it as the failed first attempt that `Reference-Imported-Final` replaced). Every directory a doc actually points to for evidence (`Compatibility-Final`, `Final`, `Fitness-Pacing`, `Gameplay-Consolidation`, `Hardware-Feedback`, `Hit-Gate-Pacing`, `Reference-Imported-Final`) was left untouched. Net: **1.1 GB → 597 MB**, no documentation link broken. Also removed `ArtSource/.../room-assembly-review.png` (1.8 MB, zero references; the source `.blend` is still cited, just not this rendered PNG).
- Note: `git rm` only shrinks the working tree/future checkouts, not existing `.git` history (rewriting history was out of scope and not done).

**Checked and left alone:** `GameplayRules`, `ScoreSystem`, `GameSessionStats`, `SensorEventProcessor`, `SessionTimer`, `ArenaPulseAnimator`, `ComboSystem`, `LevelDefinition`, `TargetVisualFactory`, `PlayerActionEvent`, `Enums.cs`, `AndroidNativeClock`, `Bootstrapper`, `SettingsManager`, all `Input/*` files — reviewed line by line, all live, no bugs found. `DojoAudioCue.TargetTravel` has zero dispatch sites — flagged only (enum member, not code; may be intentional scaffolding, consistent with the project's existing pattern for the heart-rate scaffold). `Fitness-Pacing`/`Hit-Gate-Pacing` DesignReferences directories are cited but their own citing doc calls them "dated snapshots" with no named replacement — kept since removing them would break a live doc link.

## Build/compile validation

- C# compile: 0 warnings, 0 errors (state as of the 18 September build).
- Unity Android build (`Builds/AndroidCandidate/DigitalDojo.apk`, Unity 6000.6.1f1): **Succeeded, 0 errors, 0 warnings** as of 18 September — this validated the deprecated-API fixes and the two scene rewrites (MainMenu.unity, Results.unity) end to end, since scene loading/serialization is part of the player build.
- `DynamicsSdkInspector` Gradle build: unaffected by either pass, last verified build was successful.
- 19 September changes were re-validated with a fresh Unity build once the Editor was closed — see "Final cleanup" below for the result.

## Final cleanup — 19 September 2026

**Resolved**
- **HUDController / DebugUI ownership.** Both components' `debugText` fields pointed at the *same* scene Text object (confirmed via matching scene YAML fileIDs), each with its own independent F1 handler and content format. `HUDController` is now player-facing-HUD-only (score/combo/timer/accuracy/feedback); its `debugText`, `debugVisible`, FPS display, F1 handling, and the dead `UpdateDebug()` method were removed. `DebugUI` is now the sole debug overlay, with its own dedicated `DebugCanvas`/Text object (previously it silently reused the same object `HUDController` was writing to — fixed in both the scene and the scene-generator, `Assets/Editor/SceneAutoSetup.cs`, so regenerating the scene can't reintroduce the conflict).
- **F1 ownership.** `DebugUI` is now the only component handling `KeyCode.F1`. `DigitalDojoHudSkin` had a *third*, independent F1 handler toggling its own runtime-built "OptionalDebugOverlay" Text showing sensor/input-provider status — removed, and that content (provider status / `ResearchSessionLog.Error` / physical-sensor notice) was folded into `DebugUI`'s display instead.
- **`inputStateText` decision.** Diagnostic, not player-facing: it showed input-provider status, and `DigitalDojoHudSkin.Start()` was already permanently disabling the scene object it pointed to (replacing it with the now-removed "OptionalDebugOverlay") — meaning `HUDController.UpdateInputState()` was updating text on a GameObject nothing could ever see. Removed the field, the method, its one call site (`GameRoundController.cs`), and the stale scene object/serialization (`Assets/Scenes/Game.unity`: removed the `InputStateText` GameObject, its 3 components, its parent's child-list entry, and the dangling `inputStateText`/`debugText` serialized properties on `HUDController`'s block).
- **`MouseTouchInputProvider.gameConfig` decision.** Confirmed dead: zero reads anywhere in the class; the only reason it had a scene value was `Assets/Editor/SceneAutoSetup.cs` uniformly wiring `gameConfig` into every input-related component regardless of actual use. Removed the field and its now-dead wiring call in the generator.
- **`DojoAudioCue.TargetTravel` decision.** Stale, not scaffolding: no dispatch site, no `AudioManager.PlayCue` case (so it would have silently no-opped if ever fired), no clip, and no comment indicating planned use. Confirmed not `[SerializeField]`/scene-serialized anywhere, so removing it from the enum carries no ordinal-corruption risk. Removed.
- **Package removals** (see below).

**Retained intentionally**
- `Fitness-Pacing`/`Hit-Gate-Pacing` DesignReferences directories, the heart-rate scaffold, `PlayerProfile.PreferredLevel`, and everything else listed in "Intentional inactive code" above — unchanged, out of scope for this pass.

**Removed packages**
- `com.unity.probuilder` (6.1.2), `com.unity.cinemachine` (6.6.0), `com.unity.visualeffectgraph` (17.6.0) — each verified individually with zero references across scripts, scenes, prefabs, materials, and shaders (not just C# namespaces), zero `.asmdef` dependencies, and confirmed as root-level (`depth: 0`) manifest entries that nothing else depends on. Removed one at a time from `Packages/manifest.json`; a Unity compile/package-resolve check after each showed zero errors/warnings before proceeding to the next.

**Validation**
- C# compile: 0 errors, 0 warnings.
- Unity Android build (`GameRegressionChecks.BuildAndroidCandidate`): **Succeeded**, `Builds/AndroidCandidate/DigitalDojo.apk`, 0 errors, 0 warnings (this run validated the 19 September changes, all six items above, and the three package removals together).
- `git diff --check`: clean (only pre-existing Unity-native trailing-whitespace in `MainMenu.unity`'s standard YAML fields, not introduced by this pass).
