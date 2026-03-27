using System.Collections.Generic;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class SceneAutoSetup
{
    private const string ScenesFolder = "Assets/Scenes";
    private const string BootScenePath = "Assets/Scenes/Boot.unity";
    private const string MainMenuScenePath = "Assets/Scenes/MainMenu.unity";
    private const string GameScenePath = "Assets/Scenes/Game.unity";
    private const string ResultsScenePath = "Assets/Scenes/Results.unity";
    private const string GameConfigPath = "Assets/Resources/GameConfig.asset";
    private const string UiFontPath = "Assets/Imported/Kenney/UI/Fonts/Kenney Future.ttf";
    private const string ButtonSpritePath = "Assets/Imported/Kenney/UI/Sprites/button_blue.png";
    private const string PanelSpritePath = "Assets/Imported/Kenney/UI/Sprites/panel_grey.png";
    private const string StarSpritePath = "Assets/Imported/Kenney/UI/Sprites/star_yellow.png";
    private const string FloorModelPath = "Assets/Imported/Kenney/Prototype/Models/floor-thick.fbx";
    private const string ColumnModelPath = "Assets/Imported/Kenney/Prototype/Models/column-rounded.fbx";
    private const string IndicatorModelPath = "Assets/Imported/Kenney/Prototype/Models/indicator-square-a.fbx";
    private const string SpaceFloorModelPath = "Assets/Imported/Kenney/SpaceKit/Models/template-floor-big.fbx";
    private const string SpaceFloorDetailModelPath = "Assets/Imported/Kenney/SpaceKit/Models/template-floor-detail-a.fbx";
    private const string SpaceWallModelPath = "Assets/Imported/Kenney/SpaceKit/Models/template-wall.fbx";
    private const string SpaceWallHalfModelPath = "Assets/Imported/Kenney/SpaceKit/Models/template-wall-half.fbx";
    private const string SpaceGateModelPath = "Assets/Imported/Kenney/SpaceKit/Models/gate-door-window.fbx";
    private const string SpaceGateLaserModelPath = "Assets/Imported/Kenney/SpaceKit/Models/gate-lasers.fbx";
    private const string SpaceCablesModelPath = "Assets/Imported/Kenney/SpaceKit/Models/cables.fbx";
    private const string TargetModelPath = "Assets/Imported/Kenney/Prototype/Models/target-a-square.fbx";
    private const string TargetPrefabPath = "Assets/Resources/Generated/TargetPrefab.prefab";

    public static void CreateAllScenes()
    {
        EnsureFolders();
        PrepareImportedAssets();

        GameConfig config = EnsureGameConfig();
        GameObject targetPrefab = EnsureTargetPrefab();
        CreateBootScene();
        CreateMainMenuScene();
        CreateGameScene(config, targetPrefab);
        CreateResultsScene();
        UpdateBuildSettings();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        Debug.Log("Scene auto-setup completed.");
    }

    private static void EnsureFolders()
    {
        EnsureFolder("Assets/Editor");
        EnsureFolder("Assets/Resources");
        EnsureFolder(ScenesFolder);
    }

    private static void EnsureFolder(string path)
    {
        if (AssetDatabase.IsValidFolder(path))
        {
            return;
        }

        string[] parts = path.Split('/');
        string current = parts[0];
        for (int i = 1; i < parts.Length; i++)
        {
            string next = current + "/" + parts[i];
            if (!AssetDatabase.IsValidFolder(next))
            {
                AssetDatabase.CreateFolder(current, parts[i]);
            }
            current = next;
        }
    }

    private static void PrepareImportedAssets()
    {
        ConfigureSpriteAsset(ButtonSpritePath);
        ConfigureSpriteAsset(PanelSpritePath);
        ConfigureSpriteAsset(StarSpritePath);
    }

    private static void ConfigureSpriteAsset(string assetPath)
    {
        TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
        if (importer == null)
        {
            return;
        }

        if (importer.textureType != TextureImporterType.Sprite)
        {
            importer.textureType = TextureImporterType.Sprite;
            importer.spriteImportMode = SpriteImportMode.Single;
            importer.mipmapEnabled = false;
            importer.alphaIsTransparency = true;
            importer.SaveAndReimport();
        }
    }

    private static GameConfig EnsureGameConfig()
    {
        GameConfig config = AssetDatabase.LoadAssetAtPath<GameConfig>(GameConfigPath);
        if (config != null)
        {
            return config;
        }

        config = ScriptableObject.CreateInstance<GameConfig>();
        AssetDatabase.CreateAsset(config, GameConfigPath);
        return config;
    }

    private static GameObject EnsureTargetPrefab()
    {
        EnsureFolder("Assets/Resources/Generated");

        GameObject existingPrefab = AssetDatabase.LoadAssetAtPath<GameObject>(TargetPrefabPath);
        if (existingPrefab != null)
        {
            return existingPrefab;
        }

        GameObject root = new GameObject("TargetPrefab");
        root.AddComponent<TargetObject>();
        root.AddComponent<TargetMover>();

        Rigidbody rigidbody = root.AddComponent<Rigidbody>();
        rigidbody.useGravity = false;
        rigidbody.isKinematic = true;

        BoxCollider collider = root.AddComponent<BoxCollider>();
        collider.isTrigger = true;
        collider.size = new Vector3(1.5f, 1.5f, 1.5f);

        GameObject modelAsset = AssetDatabase.LoadAssetAtPath<GameObject>(TargetModelPath);
        if (modelAsset != null)
        {
            GameObject modelInstance = PrefabUtility.InstantiatePrefab(modelAsset) as GameObject;
            if (modelInstance != null)
            {
                modelInstance.name = "Visual";
                modelInstance.transform.SetParent(root.transform, false);
                modelInstance.transform.localPosition = Vector3.zero;
                modelInstance.transform.localRotation = Quaternion.identity;
                modelInstance.transform.localScale = Vector3.one * 1.25f;
                ApplyRendererColor(modelInstance, new Color(1f, 0.22f, 0.22f, 1f), 1.8f);
            }
        }

        GameObject prefab = PrefabUtility.SaveAsPrefabAsset(root, TargetPrefabPath);
        Object.DestroyImmediate(root);
        AssetDatabase.SaveAssets();
        return prefab;
    }

    private static void CreateBootScene()
    {
        EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);

        CreateDirectionalLight();
        CreateMainCamera(new Vector3(0f, 4f, -10f), Quaternion.Euler(15f, 0f, 0f));

        GameObject manager = new GameObject("GameManager");
        manager.AddComponent<GameManager>();

        GameObject bootstrapper = new GameObject("Bootstrapper");
        Bootstrapper bootstrapperComponent = bootstrapper.AddComponent<Bootstrapper>();
        SetPrivateField(bootstrapperComponent, "autoLoadMainMenu", true);
        SetPrivateField(bootstrapperComponent, "delay", 0.5f);

        EditorSceneManager.SaveScene(SceneManager.GetActiveScene(), BootScenePath);
    }

    private static void CreateMainMenuScene()
    {
        EditorSceneManager.NewScene(NewSceneSetup.DefaultGameObjects, NewSceneMode.Single);
        EnsureEventSystem();

        Canvas canvas = CreateCanvas("MainMenuCanvas");
        RectTransform background = CreatePanel(canvas.transform, "Background", new Color(0.03f, 0.05f, 0.09f, 1f));
        StretchRect(background, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        RectTransform panel = CreatePanel(canvas.transform, "MainPanel", new Color(0.07f, 0.12f, 0.19f, 0.94f));
        StretchRect(panel, new Vector2(0.06f, 0.10f), new Vector2(0.46f, 0.90f), Vector2.zero, Vector2.zero);

        RectTransform accentPanel = CreatePanel(canvas.transform, "AccentPanel", new Color(0.09f, 0.22f, 0.35f, 0.45f));
        StretchRect(accentPanel, new Vector2(0.48f, 0.10f), new Vector2(0.94f, 0.90f), Vector2.zero, Vector2.zero);

        MainMenuController controller = panel.gameObject.AddComponent<MainMenuController>();

        Text title = CreateText(panel, "Title", "BOXREHA ARENA", 46, TextAnchor.MiddleCenter);
        title.color = new Color(0.87f, 0.96f, 1f, 1f);
        AnchorRect(title.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -56f), new Vector2(420f, 60f));

        Text subtitle = CreateText(panel, "Subtitle", "Reaction training for punch, block and dodge", 19, TextAnchor.MiddleCenter);
        subtitle.color = new Color(0.58f, 0.84f, 1f, 0.95f);
        AnchorRect(subtitle.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -104f), new Vector2(420f, 32f));

        Button startButton = CreateButton(panel, "StartGameButton", "Quick Start", new Vector2(0f, -170f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(startButton.onClick, controller.OnStartGameButton);

        Button level1Button = CreateButton(panel, "Level1Button", "Level 1 - Easy", new Vector2(0f, -250f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(level1Button.onClick, controller.OnStartLevel1);

        Button level2Button = CreateButton(panel, "Level2Button", "Level 2 - Medium", new Vector2(0f, -320f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(level2Button.onClick, controller.OnStartLevel2);

        Button level3Button = CreateButton(panel, "Level3Button", "Level 3 - Hard", new Vector2(0f, -390f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(level3Button.onClick, controller.OnStartLevel3);

        Button endlessButton = CreateButton(panel, "EndlessButton", "Endless Mode", new Vector2(0f, -460f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(endlessButton.onClick, controller.OnStartEndless);

        Button quitButton = CreateButton(panel, "QuitButton", "Quit", new Vector2(0f, -540f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(quitButton.onClick, controller.OnQuitButton);

        RectTransform profilePanel = CreatePanel(canvas.transform, "ProfilePanel", new Color(0.06f, 0.11f, 0.18f, 0.92f));
        StretchRect(profilePanel, new Vector2(0.54f, 0.18f), new Vector2(0.90f, 0.78f), Vector2.zero, Vector2.zero);

        PlayerProfilePanelController profileController = profilePanel.gameObject.AddComponent<PlayerProfilePanelController>();

        Text profileTitle = CreateText(profilePanel, "ProfileTitle", "PLAYER PROFILE", 28, TextAnchor.MiddleCenter);
        profileTitle.color = new Color(0.89f, 0.97f, 1f, 1f);
        AnchorRect(profileTitle.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -38f), new Vector2(520f, 34f));

        Text profileHint = CreateText(profilePanel, "ProfileHint", "Used to normalize sensor force so smaller and bigger players are judged fairly.", 18, TextAnchor.MiddleCenter);
        profileHint.color = new Color(0.62f, 0.84f, 1f, 0.92f);
        AnchorRect(profileHint.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -76f), new Vector2(500f, 48f));

        Text heightLabel = CreateText(profilePanel, "HeightLabel", "Height (cm)", 18, TextAnchor.MiddleLeft);
        AnchorRect(heightLabel.rectTransform, new Vector2(0f, 1f), new Vector2(0f, 1f), new Vector2(110f, -140f), new Vector2(160f, 28f));
        InputField heightInput = CreateInputField(profilePanel, "HeightInput", "175", new Vector2(110f, -175f));

        Text weightLabel = CreateText(profilePanel, "WeightLabel", "Weight (kg)", 18, TextAnchor.MiddleLeft);
        AnchorRect(weightLabel.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -140f), new Vector2(160f, 28f));
        InputField weightInput = CreateInputField(profilePanel, "WeightInput", "70", new Vector2(0f, -175f));

        Text sexLabel = CreateText(profilePanel, "SexLabel", "Sex", 18, TextAnchor.MiddleLeft);
        AnchorRect(sexLabel.rectTransform, new Vector2(1f, 1f), new Vector2(1f, 1f), new Vector2(-110f, -140f), new Vector2(160f, 28f));
        InputField sexInput = CreateInputField(profilePanel, "SexInput", "Unspecified", new Vector2(-110f, -175f));

        Button saveProfileButton = CreateButton(profilePanel, "SaveProfileButton", "Save Profile", new Vector2(0f, -255f));
        Text summaryText = CreateText(profilePanel, "ProfileSummary", string.Empty, 16, TextAnchor.MiddleCenter);
        AnchorRect(summaryText.rectTransform, new Vector2(0.5f, 0f), new Vector2(0.5f, 0f), new Vector2(0f, 48f), new Vector2(560f, 56f));

        UnityEditor.Events.UnityEventTools.AddPersistentListener(saveProfileButton.onClick, profileController.SaveProfile);
        SetPrivateField(profileController, "heightInput", heightInput);
        SetPrivateField(profileController, "weightInput", weightInput);
        SetPrivateField(profileController, "sexInput", sexInput);
        SetPrivateField(profileController, "summaryText", summaryText);

        EditorSceneManager.SaveScene(SceneManager.GetActiveScene(), MainMenuScenePath);
    }

    private static void CreateGameScene(GameConfig config, GameObject targetPrefab)
    {
        EditorSceneManager.NewScene(NewSceneSetup.DefaultGameObjects, NewSceneMode.Single);
        EnsureEventSystem();

        Camera mainCamera = Camera.main;
        if (mainCamera == null)
        {
            mainCamera = CreateMainCamera(new Vector3(0f, 2.45f, -7.8f), Quaternion.Euler(10f, 0f, 0f));
            mainCamera.fieldOfView = 52f;
        }
        else
        {
            mainCamera.transform.position = new Vector3(0f, 2.45f, -7.8f);
            mainCamera.transform.rotation = Quaternion.Euler(10f, 0f, 0f);
            mainCamera.fieldOfView = 52f;
        }

        GameObject roundControllerObject = new GameObject("GameRoundController");
        GameRoundController roundController = roundControllerObject.AddComponent<GameRoundController>();

        GameObject spawnerObject = new GameObject("TargetSpawner");
        TargetSpawner targetSpawner = spawnerObject.AddComponent<TargetSpawner>();

        GameObject timerObject = new GameObject("SessionTimer");
        SessionTimer sessionTimer = timerObject.AddComponent<SessionTimer>();

        GameObject scoreSystemObject = new GameObject("ScoreSystem");
        ScoreSystem scoreSystem = scoreSystemObject.AddComponent<ScoreSystem>();

        GameObject comboSystemObject = new GameObject("ComboSystem");
        ComboSystem comboSystem = comboSystemObject.AddComponent<ComboSystem>();

        GameObject hitZoneObject = new GameObject("HitZoneEvaluator");
        hitZoneObject.transform.position = new Vector3(0f, 2.5f, 5f);
        BoxCollider hitZoneCollider = hitZoneObject.AddComponent<BoxCollider>();
        hitZoneCollider.isTrigger = true;
        hitZoneCollider.size = new Vector3(10f, 5f, 2f);
        HitZoneEvaluator hitZoneEvaluator = hitZoneObject.AddComponent<HitZoneEvaluator>();

        GameObject inputObject = new GameObject("InputManager");
        MouseTouchInputProvider mouseInputProvider = inputObject.AddComponent<MouseTouchInputProvider>();
        BleSensorInputProvider bleSensorInputProvider = inputObject.AddComponent<BleSensorInputProvider>();
        InputProviderRouter inputProvider = inputObject.AddComponent<InputProviderRouter>();

        GameObject playerRoot = new GameObject("PlayerRoot");
        playerRoot.transform.position = new Vector3(0f, 0f, 5f);

        GameObject spawnRoot = new GameObject("SpawnRoot");
        spawnRoot.transform.position = new Vector3(0f, 0f, 30f);

        Transform spawnLeft = CreateChild(spawnRoot.transform, "SpawnPoint_Left", new Vector3(-3f, 1f, 0f));
        Transform spawnCenter = CreateChild(spawnRoot.transform, "SpawnPoint_Center", new Vector3(0f, 1f, 0f));
        Transform spawnRight = CreateChild(spawnRoot.transform, "SpawnPoint_Right", new Vector3(3f, 1f, 0f));

        CreateSciFiBackdrop();
        CreatePrototypeFloor("ArenaFloor", new Vector3(0f, -0.42f, 13f), new Vector3(4.6f, 0.16f, 9.6f), new Color(0.13f, 0.21f, 0.31f, 1f));
        CreateSciFiFloor("ArenaFloorDeck", new Vector3(0f, -0.55f, 13f), new Vector3(6.2f, 0.4f, 11.5f), new Color(0.14f, 0.22f, 0.30f, 1f));
        CreateArenaLighting();

        Renderer leftLane = CreatePrototypeGuide("Guide_Left", new Vector3(-3f, 1.4f, 14f), new Vector3(0.42f, 4.2f, 0.42f), new Color(0.10f, 0.34f, 0.58f, 1f));
        Renderer centerLane = CreatePrototypeGuide("Guide_Center", new Vector3(0f, 1.4f, 14f), new Vector3(0.50f, 4.4f, 0.50f), new Color(0.16f, 0.50f, 0.73f, 1f));
        Renderer rightLane = CreatePrototypeGuide("Guide_Right", new Vector3(3f, 1.4f, 14f), new Vector3(0.42f, 4.2f, 0.42f), new Color(0.10f, 0.34f, 0.58f, 1f));
        CreateHitGrid(config);

        GameObject visualFeedbackObject = new GameObject("ActionVisualFeedback");
        ActionVisualFeedback visualFeedback = visualFeedbackObject.AddComponent<ActionVisualFeedback>();

        Canvas hudCanvas = CreateCanvas("HUDCanvas");
        HUDController hudController = hudCanvas.gameObject.AddComponent<HUDController>();

        Text scoreText = CreateHudText(hudCanvas.transform, "ScoreText", "Score: 0", 24, new Vector2(120f, -30f), new Vector2(220f, 40f), TextAnchor.MiddleLeft);
        Text comboText = CreateHudText(hudCanvas.transform, "ComboText", string.Empty, 28, new Vector2(0f, -30f), new Vector2(240f, 40f), TextAnchor.MiddleCenter);
        Text timerText = CreateHudText(hudCanvas.transform, "TimerText", "01:00", 32, new Vector2(-120f, -30f), new Vector2(220f, 40f), TextAnchor.MiddleRight, rightAnchor: true);
        Text accuracyText = CreateHudText(hudCanvas.transform, "AccuracyText", "Accuracy: 0%", 20, new Vector2(120f, -65f), new Vector2(220f, 30f), TextAnchor.MiddleLeft);
        Text debugText = CreateHudText(hudCanvas.transform, "DebugText", string.Empty, 16, new Vector2(120f, -110f), new Vector2(260f, 70f), TextAnchor.UpperLeft);
        Text inputStateText = CreateHudText(hudCanvas.transform, "InputStateText", string.Empty, 16, new Vector2(120f, -180f), new Vector2(260f, 40f), TextAnchor.UpperLeft);
        Text feedbackText = CreateHudText(hudCanvas.transform, "FeedbackText", string.Empty, 28, new Vector2(0f, -90f), new Vector2(520f, 40f), TextAnchor.MiddleCenter);

        debugText.gameObject.SetActive(false);
        inputStateText.gameObject.SetActive(false);

        GameObject pausePanelObject = CreateUiObject("PausePanel", hudCanvas.transform);
        Image pausePanelImage = pausePanelObject.AddComponent<Image>();
        pausePanelImage.color = new Color(0f, 0f, 0f, 0.65f);
        RectTransform pauseRect = pausePanelObject.GetComponent<RectTransform>();
        StretchRect(pauseRect, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        PauseMenuController pauseController = pausePanelObject.AddComponent<PauseMenuController>();
        Text pausedText = CreateText(pauseRect, "PausedText", "PAUSED", 48, TextAnchor.MiddleCenter);
        AnchorRect(pausedText.rectTransform, new Vector2(0.5f, 0.5f), new Vector2(0.5f, 0.5f), new Vector2(0f, 80f), new Vector2(320f, 60f));
        Button resumeButton = CreateButton(pauseRect, "ResumeButton", "Resume", new Vector2(0f, 0f));
        Button quitButton = CreateButton(pauseRect, "QuitButton", "Quit To Menu", new Vector2(0f, -80f));
        UnityEditor.Events.UnityEventTools.AddPersistentListener(resumeButton.onClick, pauseController.OnResume);
        UnityEditor.Events.UnityEventTools.AddPersistentListener(quitButton.onClick, pauseController.OnQuitToMenu);

        GameObject debugCanvasObject = new GameObject("DebugCanvas");
        debugCanvasObject.transform.SetParent(hudCanvas.transform, false);
        DebugUI debugUi = debugCanvasObject.AddComponent<DebugUI>();

        SetPrivateField(mouseInputProvider, "gameConfig", config);
        SetPrivateField(bleSensorInputProvider, "gameConfig", config);
        SetPrivateField(inputProvider, "gameConfig", config);
        SetPrivateField(inputProvider, "mouseTouchInputProvider", mouseInputProvider);
        SetPrivateField(inputProvider, "bleSensorInputProvider", bleSensorInputProvider);
        SetPrivateField(targetSpawner, "spawnPointLeft", spawnLeft);
        SetPrivateField(targetSpawner, "spawnPointCenter", spawnCenter);
        SetPrivateField(targetSpawner, "spawnPointRight", spawnRight);
        SetPrivateField(targetSpawner, "missZoneZ", 0f);
        SetPrivateField(targetSpawner, "gameConfig", config);
        SetPrivateField(targetSpawner, "hitZoneEvaluator", hitZoneEvaluator);
        SetPrivateField(targetSpawner, "targetPrefab", targetPrefab);

        SetPrivateField(visualFeedback, "leftLaneRenderer", leftLane);
        SetPrivateField(visualFeedback, "centerLaneRenderer", centerLane);
        SetPrivateField(visualFeedback, "rightLaneRenderer", rightLane);

        SetPrivateField(hudController, "scoreText", scoreText);
        SetPrivateField(hudController, "comboText", comboText);
        SetPrivateField(hudController, "timerText", timerText);
        SetPrivateField(hudController, "accuracyText", accuracyText);
        SetPrivateField(hudController, "debugText", debugText);
        SetPrivateField(hudController, "inputStateText", inputStateText);
        SetPrivateField(hudController, "feedbackText", feedbackText);

        SetPrivateField(pauseController, "resumeButton", resumeButton);
        SetPrivateField(pauseController, "quitButton", quitButton);
        SetPrivateField(pauseController, "pausePanel", pausePanelObject);

        SetPrivateField(debugUi, "debugText", debugText);

        SetPrivateField(roundController, "targetSpawner", targetSpawner);
        SetPrivateField(roundController, "sessionTimer", sessionTimer);
        SetPrivateField(roundController, "scoreSystem", scoreSystem);
        SetPrivateField(roundController, "comboSystem", comboSystem);
        SetPrivateField(roundController, "hitZoneEvaluator", hitZoneEvaluator);
        SetPrivateField(roundController, "inputProvider", inputProvider);
        SetPrivateField(roundController, "hudController", hudController);

        EditorSceneManager.SaveScene(SceneManager.GetActiveScene(), GameScenePath);
    }

    private static void CreateResultsScene()
    {
        EditorSceneManager.NewScene(NewSceneSetup.DefaultGameObjects, NewSceneMode.Single);
        EnsureEventSystem();

        Canvas canvas = CreateCanvas("ResultsCanvas");
        RectTransform background = CreatePanel(canvas.transform, "Background", new Color(0.03f, 0.05f, 0.09f, 1f));
        StretchRect(background, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        RectTransform card = CreatePanel(canvas.transform, "ResultsCard", new Color(0.07f, 0.12f, 0.19f, 0.94f));
        StretchRect(card, new Vector2(0.18f, 0.08f), new Vector2(0.82f, 0.92f), Vector2.zero, Vector2.zero);

        ResultsController controller = canvas.gameObject.AddComponent<ResultsController>();

        Text title = CreateText(card.transform, "Title", "SESSION RESULTS", 42, TextAnchor.MiddleCenter);
        title.color = new Color(0.90f, 0.97f, 1f, 1f);
        AnchorRect(title.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -40f), new Vector2(320f, 50f));

        Dictionary<string, Text> texts = new Dictionary<string, Text>();
        string[] lines =
        {
            "ScoreText", "AccuracyText", "PerfectText", "GoodText", "EarlyText", "LateText",
            "MissText", "MaxComboText", "ReactionTimeText", "ForceText", "NormalizedForceText",
            "ProfileBaselineText", "ForceBandSummaryText", "StarsText", "BestScoreText", "NewHighScoreText", "GamesPlayedText"
        };

        for (int i = 0; i < lines.Length; i++)
        {
            Text text = CreateText(card.transform, lines[i], lines[i], lines[i] == "StarsText" ? 48 : 24, TextAnchor.MiddleCenter);
            AnchorRect(text.rectTransform, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), new Vector2(0f, -100f - (i * 36f)), new Vector2(700f, 32f));
            texts.Add(lines[i], text);
        }

        texts["StarsText"].color = Color.yellow;
        texts["NewHighScoreText"].color = Color.yellow;
        AddStarDecor(card, new Vector2(-250f, -42f));
        AddStarDecor(card, new Vector2(250f, -42f));

        Button restartButton = CreateButton(card.transform as RectTransform, "RestartButton", "Restart", new Vector2(-130f, 36f), bottomAnchor: true);
        Button menuButton = CreateButton(card.transform as RectTransform, "MainMenuButton", "Main Menu", new Vector2(130f, 36f), bottomAnchor: true);
        UnityEditor.Events.UnityEventTools.AddPersistentListener(restartButton.onClick, controller.OnRestartButton);
        UnityEditor.Events.UnityEventTools.AddPersistentListener(menuButton.onClick, controller.OnMainMenuButton);

        SetPrivateField(controller, "scoreText", texts["ScoreText"]);
        SetPrivateField(controller, "accuracyText", texts["AccuracyText"]);
        SetPrivateField(controller, "perfectText", texts["PerfectText"]);
        SetPrivateField(controller, "goodText", texts["GoodText"]);
        SetPrivateField(controller, "earlyText", texts["EarlyText"]);
        SetPrivateField(controller, "lateText", texts["LateText"]);
        SetPrivateField(controller, "missText", texts["MissText"]);
        SetPrivateField(controller, "maxComboText", texts["MaxComboText"]);
        SetPrivateField(controller, "reactionTimeText", texts["ReactionTimeText"]);
        SetPrivateField(controller, "forceText", texts["ForceText"]);
        SetPrivateField(controller, "normalizedForceText", texts["NormalizedForceText"]);
        SetPrivateField(controller, "profileBaselineText", texts["ProfileBaselineText"]);
        SetPrivateField(controller, "forceBandSummaryText", texts["ForceBandSummaryText"]);
        SetPrivateField(controller, "starsText", texts["StarsText"]);
        SetPrivateField(controller, "bestScoreText", texts["BestScoreText"]);
        SetPrivateField(controller, "newHighScoreText", texts["NewHighScoreText"]);
        SetPrivateField(controller, "gamesPlayedText", texts["GamesPlayedText"]);

        EditorSceneManager.SaveScene(SceneManager.GetActiveScene(), ResultsScenePath);
    }

    private static void UpdateBuildSettings()
    {
        EditorBuildSettings.scenes = new[]
        {
            new EditorBuildSettingsScene(BootScenePath, true),
            new EditorBuildSettingsScene(MainMenuScenePath, true),
            new EditorBuildSettingsScene(GameScenePath, true),
            new EditorBuildSettingsScene(ResultsScenePath, true)
        };
    }

    private static Camera CreateMainCamera(Vector3 position, Quaternion rotation)
    {
        GameObject cameraObject = new GameObject("Main Camera");
        cameraObject.tag = "MainCamera";
        Camera camera = cameraObject.AddComponent<Camera>();
        cameraObject.AddComponent<AudioListener>();
        camera.transform.position = position;
        camera.transform.rotation = rotation;
        return camera;
    }

    private static void CreateDirectionalLight()
    {
        GameObject lightObject = new GameObject("Directional Light");
        Light light = lightObject.AddComponent<Light>();
        light.type = LightType.Directional;
        light.intensity = 1.1f;
        light.transform.rotation = Quaternion.Euler(50f, -30f, 0f);
    }

    private static void EnsureEventSystem()
    {
        if (Object.FindObjectOfType<EventSystem>() != null)
        {
            return;
        }

        GameObject eventSystem = new GameObject("EventSystem");
        eventSystem.AddComponent<EventSystem>();
        eventSystem.AddComponent<StandaloneInputModule>();
    }

    private static Canvas CreateCanvas(string name)
    {
        GameObject canvasObject = new GameObject(name);
        Canvas canvas = canvasObject.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        CanvasScaler scaler = canvasObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1920f, 1080f);
        scaler.matchWidthOrHeight = 0.5f;
        canvasObject.AddComponent<GraphicRaycaster>();
        return canvas;
    }

    private static RectTransform CreatePanel(Transform parent, string name, Color color)
    {
        GameObject panelObject = CreateUiObject(name, parent);
        Image image = panelObject.AddComponent<Image>();
        image.color = color;
        ApplyOptionalSprite(image, PanelSpritePath, true);
        return panelObject.GetComponent<RectTransform>();
    }

    private static Button CreateButton(RectTransform parent, string name, string label, Vector2 anchoredPosition, bool bottomAnchor = false)
    {
        GameObject buttonObject = CreateUiObject(name, parent);
        Image image = buttonObject.AddComponent<Image>();
        image.color = new Color(0.12f, 0.45f, 0.76f, 0.96f);
        ApplyOptionalSprite(image, ButtonSpritePath, true);
        Button button = buttonObject.AddComponent<Button>();
        ColorBlock colors = button.colors;
        colors.normalColor = new Color(0.12f, 0.45f, 0.76f, 0.96f);
        colors.highlightedColor = new Color(0.22f, 0.58f, 0.92f, 1f);
        colors.pressedColor = new Color(0.09f, 0.28f, 0.48f, 1f);
        colors.selectedColor = colors.highlightedColor;
        button.colors = colors;

        RectTransform rect = buttonObject.GetComponent<RectTransform>();
        Vector2 anchor = bottomAnchor ? new Vector2(0.5f, 0f) : new Vector2(0.5f, 0.5f);
        AnchorRect(rect, anchor, anchor, anchoredPosition, new Vector2(240f, 50f));

        Text text = CreateText(rect, "Label", label, 24, TextAnchor.MiddleCenter);
        StretchRect(text.rectTransform, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        return button;
    }

    private static InputField CreateInputField(RectTransform parent, string name, string placeholder, Vector2 anchoredPosition)
    {
        GameObject inputObject = CreateUiObject(name, parent);
        Image image = inputObject.AddComponent<Image>();
        image.color = new Color(0.92f, 0.97f, 1f, 0.97f);

        InputField inputField = inputObject.AddComponent<InputField>();
        RectTransform rect = inputObject.GetComponent<RectTransform>();
        AnchorRect(rect, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), anchoredPosition, new Vector2(150f, 38f));

        Text text = CreateText(rect, "Text", string.Empty, 18, TextAnchor.MiddleCenter);
        text.color = new Color(0.1f, 0.12f, 0.18f);
        StretchRect(text.rectTransform, Vector2.zero, Vector2.one, new Vector2(10f, 6f), new Vector2(-10f, -6f));

        Text placeholderText = CreateText(rect, "Placeholder", placeholder, 18, TextAnchor.MiddleCenter);
        placeholderText.color = new Color(0.4f, 0.45f, 0.52f, 0.8f);
        StretchRect(placeholderText.rectTransform, Vector2.zero, Vector2.one, new Vector2(10f, 6f), new Vector2(-10f, -6f));

        inputField.textComponent = text;
        inputField.placeholder = placeholderText;
        inputField.text = placeholder;
        return inputField;
    }

    private static Text CreateText(Transform parent, string name, string value, int fontSize, TextAnchor anchor)
    {
        GameObject textObject = CreateUiObject(name, parent);
        Text text = textObject.AddComponent<Text>();
        text.text = value;
        text.font = LoadUiFont();
        text.fontSize = fontSize;
        text.alignment = anchor;
        text.color = Color.white;
        text.supportRichText = false;
        return text;
    }

    private static Text CreateHudText(Transform parent, string name, string value, int fontSize, Vector2 anchoredPosition, Vector2 size, TextAnchor anchor, bool rightAnchor = false)
    {
        Text text = CreateText(parent, name, value, fontSize, anchor);
        Vector2 anchorPos = rightAnchor ? new Vector2(1f, 1f) : new Vector2(0f, 1f);
        AnchorRect(text.rectTransform, anchorPos, anchorPos, rightAnchor ? new Vector2(anchoredPosition.x, anchoredPosition.y) : anchoredPosition, size);
        return text;
    }

    private static Renderer CreateLane(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject lane = GameObject.CreatePrimitive(PrimitiveType.Cube);
        lane.name = name;
        lane.transform.position = position;
        lane.transform.localScale = scale;
        Renderer renderer = lane.GetComponent<Renderer>();
        renderer.sharedMaterial = new Material(Shader.Find("Standard"));
        renderer.sharedMaterial.color = color;
        return renderer;
    }

    private static void CreateArenaSurface(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject surface = GameObject.CreatePrimitive(PrimitiveType.Cube);
        surface.name = name;
        surface.transform.position = position;
        surface.transform.localScale = scale;
        Renderer renderer = surface.GetComponent<Renderer>();
        renderer.sharedMaterial = new Material(Shader.Find("Standard"));
        renderer.sharedMaterial.color = color;
        renderer.sharedMaterial.SetFloat("_Glossiness", 0.75f);
        renderer.sharedMaterial.EnableKeyword("_EMISSION");
        renderer.sharedMaterial.SetColor("_EmissionColor", color * 0.6f);
    }

    private static void CreateSciFiBackdrop()
    {
        CreateSciFiModule(SpaceGateModelPath, "BackGate", new Vector3(0f, 1.4f, 28.3f), Quaternion.identity, new Vector3(4.6f, 4.0f, 1f), new Color(0.18f, 0.30f, 0.42f, 1f), 1.0f);
        CreateSciFiModule(SpaceGateLaserModelPath, "BackGateLasers", new Vector3(0f, 1.25f, 27.75f), Quaternion.identity, new Vector3(4.0f, 3.5f, 1f), new Color(0.18f, 0.70f, 1f, 1f), 1.8f);
        CreateSciFiModule(SpaceWallModelPath, "BackWallLeft", new Vector3(-6.2f, 1.3f, 24f), Quaternion.Euler(0f, 90f, 0f), new Vector3(4.2f, 3.6f, 1f), new Color(0.14f, 0.24f, 0.35f, 1f), 0.8f);
        CreateSciFiModule(SpaceWallModelPath, "BackWallRight", new Vector3(6.2f, 1.3f, 24f), Quaternion.Euler(0f, -90f, 0f), new Vector3(4.2f, 3.6f, 1f), new Color(0.14f, 0.24f, 0.35f, 1f), 0.8f);
        CreateSciFiModule(SpaceWallHalfModelPath, "FrontWallLeft", new Vector3(-6.2f, 1.2f, 9.5f), Quaternion.Euler(0f, 90f, 0f), new Vector3(3.2f, 3.0f, 1f), new Color(0.12f, 0.20f, 0.30f, 1f), 0.6f);
        CreateSciFiModule(SpaceWallHalfModelPath, "FrontWallRight", new Vector3(6.2f, 1.2f, 9.5f), Quaternion.Euler(0f, -90f, 0f), new Vector3(3.2f, 3.0f, 1f), new Color(0.12f, 0.20f, 0.30f, 1f), 0.6f);
        CreateSciFiModule(SpaceCablesModelPath, "CeilingCables", new Vector3(0f, 4.3f, 18f), Quaternion.Euler(0f, 90f, 0f), new Vector3(6.5f, 1f, 1f), new Color(0.18f, 0.40f, 0.56f, 1f), 0.9f);
    }

    private static void CreateSciFiFloor(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject floor = CreatePrototypeObject(SpaceFloorModelPath, name, position, Quaternion.identity, scale);
        if (floor == null)
        {
            return;
        }

        ApplyRendererColor(floor, color, 0.7f);
        CreateSciFiModule(SpaceFloorDetailModelPath, name + "_Detail", position + new Vector3(0f, 0.06f, 0f), Quaternion.identity, new Vector3(scale.x * 0.92f, scale.y, scale.z * 0.92f), new Color(0.18f, 0.60f, 0.82f, 1f), 1.1f);
    }

    private static void CreateSciFiModule(string assetPath, string name, Vector3 position, Quaternion rotation, Vector3 scale, Color color, float emission)
    {
        GameObject module = CreatePrototypeObject(assetPath, name, position, rotation, scale);
        if (module == null)
        {
            return;
        }

        ApplyRendererColor(module, color, emission);
    }

    private static void CreatePrototypeFloor(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject prototype = CreatePrototypeObject(FloorModelPath, name, position, Quaternion.identity, scale);
        if (prototype == null)
        {
            CreateArenaSurface(name, position, scale, color);
            return;
        }

        ApplyRendererColor(prototype, color, 0.95f);
    }

    private static Renderer CreatePrototypeGuide(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject prototype = CreatePrototypeObject(ColumnModelPath, name, position, Quaternion.identity, scale);
        if (prototype == null)
        {
            return CreateGuideColumn(name, position, scale, color);
        }

        ApplyRendererColor(prototype, color, 1.6f);
        return prototype.GetComponentInChildren<Renderer>();
    }

    private static Renderer CreateGuideColumn(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject guide = GameObject.CreatePrimitive(PrimitiveType.Cube);
        guide.name = name;
        guide.transform.position = position;
        guide.transform.localScale = scale;
        Renderer renderer = guide.GetComponent<Renderer>();
        renderer.sharedMaterial = new Material(Shader.Find("Standard"));
        renderer.sharedMaterial.color = color;
        renderer.sharedMaterial.SetFloat("_Glossiness", 0.82f);
        renderer.sharedMaterial.EnableKeyword("_EMISSION");
        renderer.sharedMaterial.SetColor("_EmissionColor", color * 1.5f);
        return renderer;
    }

    private static void CreateHitGrid(GameConfig config)
    {
        float[] lanePositions = { -3f, 0f, 3f };
        float[] heightPositions =
        {
            config != null ? config.GetVerticalOffset(VerticalPosition.Low) : 0.2f,
            config != null ? config.GetVerticalOffset(VerticalPosition.Mid) : 1.2f,
            config != null ? config.GetVerticalOffset(VerticalPosition.High) : 2.5f
        };

        for (int row = 0; row < heightPositions.Length; row++)
        {
            for (int col = 0; col < lanePositions.Length; col++)
            {
                Vector3 position = new Vector3(lanePositions[col], heightPositions[row], 5f);
                Vector3 scale = new Vector3(1.2f, 0.22f, 0.48f);
                GameObject pad = CreatePrototypeObject(IndicatorModelPath, "HitPad_" + row + "_" + col, position, Quaternion.Euler(90f, 0f, 0f), scale);
                if (pad == null)
                {
                    pad = GameObject.CreatePrimitive(PrimitiveType.Cube);
                    pad.name = "HitPad_" + row + "_" + col;
                    pad.transform.position = position;
                    pad.transform.localScale = scale;
                }

                Color color = col == 1 ? new Color(0.32f, 0.78f, 1f, 1f) : new Color(0.18f, 0.46f, 0.72f, 1f);
                ApplyRendererColor(pad, color, 2.1f);
                CreatePadFrame("HitPadFrame_" + row + "_" + col, position, new Vector3(1.55f, 0.08f, 0.72f), color * 0.9f);
            }
        }
    }

    private static void CreatePadFrame(string name, Vector3 position, Vector3 scale, Color color)
    {
        GameObject frame = GameObject.CreatePrimitive(PrimitiveType.Cube);
        frame.name = name;
        frame.transform.position = position + new Vector3(0f, 0f, 0.18f);
        frame.transform.localScale = scale;

        Collider collider = frame.GetComponent<Collider>();
        if (collider != null)
        {
            Object.DestroyImmediate(collider);
        }

        Renderer renderer = frame.GetComponent<Renderer>();
        if (renderer != null)
        {
            Material material = new Material(Shader.Find("Standard"));
            material.color = color;
            material.SetFloat("_Glossiness", 0.78f);
            material.EnableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", color * 1.8f);
            renderer.sharedMaterial = material;
        }
    }

    private static GameObject CreatePrototypeObject(string assetPath, string name, Vector3 position, Quaternion rotation, Vector3 scale)
    {
        GameObject asset = AssetDatabase.LoadAssetAtPath<GameObject>(assetPath);
        if (asset == null)
        {
            return null;
        }

        GameObject instance = PrefabUtility.InstantiatePrefab(asset) as GameObject;
        if (instance == null)
        {
            return null;
        }

        instance.name = name;
        instance.transform.position = position;
        instance.transform.rotation = rotation;
        instance.transform.localScale = scale;
        return instance;
    }

    private static void ApplyRendererColor(GameObject root, Color color, float emissionStrength)
    {
        Renderer[] renderers = root.GetComponentsInChildren<Renderer>(true);
        for (int i = 0; i < renderers.Length; i++)
        {
            Renderer renderer = renderers[i];
            Material material = renderer.sharedMaterial;
            if (material == null)
            {
                material = new Material(Shader.Find("Standard"));
                renderer.sharedMaterial = material;
            }

            material.color = color;
            material.SetFloat("_Glossiness", 0.72f);
            material.EnableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", color * emissionStrength);
        }
    }

    private static void ApplyOptionalSprite(Image image, string assetPath, bool preserveAspect)
    {
        Sprite sprite = AssetDatabase.LoadAssetAtPath<Sprite>(assetPath);
        if (sprite == null)
        {
            return;
        }

        image.sprite = sprite;
        image.type = Image.Type.Simple;
        image.preserveAspect = preserveAspect;
    }

    private static Font LoadUiFont()
    {
        Font font = AssetDatabase.LoadAssetAtPath<Font>(UiFontPath);
        if (font != null)
        {
            return font;
        }

        return Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
    }

    private static void AddStarDecor(RectTransform parent, Vector2 anchoredPosition)
    {
        GameObject starObject = CreateUiObject("StarDecor", parent);
        Image image = starObject.AddComponent<Image>();
        image.color = new Color(1f, 0.88f, 0.2f, 1f);
        ApplyOptionalSprite(image, StarSpritePath, true);

        RectTransform rect = starObject.GetComponent<RectTransform>();
        AnchorRect(rect, new Vector2(0.5f, 1f), new Vector2(0.5f, 1f), anchoredPosition, new Vector2(64f, 64f));
    }

    private static void CreateArenaLighting()
    {
        CreateAccentLight("AccentLight_Left", new Vector3(-4.8f, 3.6f, 10f), new Color(0.18f, 0.72f, 1f, 1f), 4.5f, 18f);
        CreateAccentLight("AccentLight_Right", new Vector3(4.8f, 3.6f, 10f), new Color(0.18f, 0.72f, 1f, 1f), 4.5f, 18f);
        CreateAccentLight("AccentLight_Back", new Vector3(0f, 3.4f, 23f), new Color(1f, 0.36f, 0.22f, 1f), 5.5f, 20f);
    }

    private static void CreateAccentLight(string name, Vector3 position, Color color, float intensity, float range)
    {
        GameObject lightObject = new GameObject(name);
        lightObject.transform.position = position;
        Light light = lightObject.AddComponent<Light>();
        light.type = LightType.Point;
        light.color = color;
        light.intensity = intensity;
        light.range = range;
    }

    private static Transform CreateChild(Transform parent, string name, Vector3 localPosition)
    {
        GameObject child = new GameObject(name);
        child.transform.SetParent(parent, false);
        child.transform.localPosition = localPosition;
        return child.transform;
    }

    private static GameObject CreateUiObject(string name, Transform parent)
    {
        GameObject obj = new GameObject(name, typeof(RectTransform));
        obj.transform.SetParent(parent, false);
        return obj;
    }

    private static void AnchorRect(RectTransform rect, Vector2 min, Vector2 max, Vector2 anchoredPosition, Vector2 size)
    {
        rect.anchorMin = min;
        rect.anchorMax = max;
        rect.anchoredPosition = anchoredPosition;
        rect.sizeDelta = size;
    }

    private static void StretchRect(RectTransform rect, Vector2 min, Vector2 max, Vector2 offsetMin, Vector2 offsetMax)
    {
        rect.anchorMin = min;
        rect.anchorMax = max;
        rect.offsetMin = offsetMin;
        rect.offsetMax = offsetMax;
    }

    private static void SetPrivateField<T>(Object target, string fieldName, T value)
    {
        SerializedObject serializedObject = new SerializedObject(target);
        SerializedProperty property = serializedObject.FindProperty(fieldName);
        if (property == null)
        {
            return;
        }

        if (typeof(Object).IsAssignableFrom(typeof(T)))
        {
            property.objectReferenceValue = value as Object;
        }
        else if (typeof(T) == typeof(float))
        {
            property.floatValue = (float)(object)value;
        }
        else if (typeof(T) == typeof(bool))
        {
            property.boolValue = (bool)(object)value;
        }

        serializedObject.ApplyModifiedPropertiesWithoutUndo();
    }
}
