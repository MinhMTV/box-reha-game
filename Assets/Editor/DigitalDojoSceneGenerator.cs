using System.Reflection;
using UnityEditor;
using UnityEditor.Events;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class DigitalDojoSceneGenerator
{
    private const string MainMenuScenePath = "Assets/Scenes/MainMenu.unity";
    private const string UiFontPath = "Assets/Art/Generated/DigitalDojo/Fonts/Bahnschrift.ttf";
    private const string DigitalDojoFolder = "Assets/Art/Generated/DigitalDojo";
    private const string DigitalDojoMaterialFolder = DigitalDojoFolder + "/Materials";
    private const string NeonPunchTargetPrefabPath = "Assets/Art/Generated/NeonCombat/Prefabs/PF_PunchTarget_NeonRed.prefab";
    private const string NeonKickPadPrefabPath = "Assets/Art/Generated/NeonCombat/Prefabs/PF_KickPad_NeonBlue.prefab";
    private const string NeonHeavyCorePrefabPath = "Assets/Art/Generated/NeonCombat/Prefabs/PF_HeavyCore_GoldBlocker.prefab";

    private static Font uiFont;
    private static Material matWall;
    private static Material matWood;
    private static Material matBlack;
    private static Material matRed;
    private static Material matBlue;
    private static Material matWarmLight;
    private static Material matIconWhite;

    [MenuItem("BoxReha/Build Digital Dojo Menu Scene")]
    public static void BuildDigitalDojoMenuScene()
    {
        EnsureFolders();
        NeonCombatAssetGenerator.GenerateAll();
        LoadSharedAssets();

        EditorSceneManager.NewScene(NewSceneSetup.DefaultGameObjects, NewSceneMode.Single);
        ConfigureCamera();
        CreateDigitalDojoRoom();
        EnsureEventSystem();

        Canvas canvas = CreateCanvas("DigitalDojoCanvas");
        RectTransform vignette = CreatePanel(canvas.transform, "CinematicVignette", new Color(0f, 0f, 0f, 0.10f));
        StretchRect(vignette, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        DigitalDojoMenuController controller = canvas.gameObject.AddComponent<DigitalDojoMenuController>();
        CanvasGroup pageGroup = CreateRect(canvas.transform, "PageGroup").gameObject.AddComponent<CanvasGroup>();
        StretchRect(pageGroup.transform as RectTransform, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        CreateTopBar(canvas.transform);

        GameObject homePanel = CreateHomePage(pageGroup.transform, controller);
        GameObject calibrationPanel = CreateCalibrationPage(pageGroup.transform, controller);
        GameObject statisticsPanel = CreateStatisticsPage(pageGroup.transform, controller);
        GameObject profilePanel = CreateProfilePage(pageGroup.transform, controller);
        GameObject settingsPanel = CreateSettingsPage(pageGroup.transform, controller);

        homePanel.SetActive(true);
        calibrationPanel.SetActive(false);
        statisticsPanel.SetActive(false);
        profilePanel.SetActive(false);
        settingsPanel.SetActive(false);

        SetPrivateField(controller, "homePanel", homePanel);
        SetPrivateField(controller, "calibrationPanel", calibrationPanel);
        SetPrivateField(controller, "statisticsPanel", statisticsPanel);
        SetPrivateField(controller, "playerProfilePanel", profilePanel);
        SetPrivateField(controller, "settingsPanel", settingsPanel);
        SetPrivateField(controller, "pageGroup", pageGroup);

        EditorSceneManager.SaveScene(SceneManager.GetActiveScene(), MainMenuScenePath);
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        Selection.activeObject = AssetDatabase.LoadAssetAtPath<SceneAsset>(MainMenuScenePath);
        Debug.Log("Digital Dojo menu scene rebuilt: " + MainMenuScenePath);
    }

    private static void EnsureFolders()
    {
        if (!AssetDatabase.IsValidFolder("Assets/Scenes"))
        {
            AssetDatabase.CreateFolder("Assets", "Scenes");
        }

        EnsureFolder("Assets/Art");
        EnsureFolder("Assets/Art/Generated");
        EnsureFolder(DigitalDojoFolder);
        EnsureFolder(DigitalDojoMaterialFolder);
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

    private static void LoadSharedAssets()
    {
        uiFont = AssetDatabase.LoadAssetAtPath<Font>(UiFontPath);
        if (uiFont == null)
        {
            uiFont = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        }

        matWall = CreateSceneMaterial("DD_WarmCharcoalWall", new Color(0.24f, 0.205f, 0.165f), 0f);
        matWood = CreateSceneMaterial("DD_DarkDojoWood", new Color(0.22f, 0.13f, 0.07f), 0f);
        matBlack = CreateSceneMaterial("DD_BlackRubber", new Color(0.018f, 0.019f, 0.02f), 0f);
        matRed = CreateSceneMaterial("DD_NeonRed", new Color(1f, 0.17f, 0.13f), 2.4f);
        matBlue = CreateSceneMaterial("DD_NeonBlue", new Color(0.16f, 0.58f, 1f), 2.2f);
        matWarmLight = CreateSceneMaterial("DD_WarmBacklight", new Color(1f, 0.66f, 0.42f), 2.5f);
        matIconWhite = CreateSceneMaterial("DD_IconWarmWhite", new Color(0.96f, 0.92f, 0.84f), 1.8f);
    }

    private static Material CreateSceneMaterial(string name, Color color, float emission)
    {
        string path = DigitalDojoMaterialFolder + "/" + name + ".mat";
        Shader shader = GetCompatibleLitShader();
        Material material = AssetDatabase.LoadAssetAtPath<Material>(path);
        if (material == null)
        {
            material = new Material(shader);
            AssetDatabase.CreateAsset(material, path);
        }
        else if (material.shader == null || material.shader.name == "Hidden/InternalErrorShader")
        {
            material.shader = shader;
        }

        material.color = color;
        SetColorIfPresent(material, "_BaseColor", color);
        SetColorIfPresent(material, "_Color", color);
        if (emission > 0f)
        {
            material.EnableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", color * emission);
        }
        EditorUtility.SetDirty(material);
        return material;
    }

    private static Shader GetCompatibleLitShader()
    {
        return Shader.Find("Universal Render Pipeline/Lit")
               ?? Shader.Find("Standard")
               ?? Shader.Find("Sprites/Default");
    }

    private static void SetColorIfPresent(Material material, string propertyName, Color color)
    {
        if (material.HasProperty(propertyName))
        {
            material.SetColor(propertyName, color);
        }
    }

    private static void ConfigureCamera()
    {
        Camera camera = Camera.main;
        if (camera == null)
        {
            GameObject cameraObject = new GameObject("Main Camera");
            camera = cameraObject.AddComponent<Camera>();
            camera.tag = "MainCamera";
        }

        camera.transform.position = new Vector3(0f, 2.15f, -7.2f);
        camera.transform.LookAt(new Vector3(0f, 1.75f, 6.8f));
        camera.fieldOfView = 38f;
        camera.clearFlags = CameraClearFlags.SolidColor;
        camera.backgroundColor = new Color(0.01f, 0.008f, 0.006f, 1f);

        RenderSettings.ambientMode = UnityEngine.Rendering.AmbientMode.Flat;
        RenderSettings.ambientLight = new Color(0.50f, 0.42f, 0.33f, 1f);

        Light light = Object.FindObjectOfType<Light>();
        if (light == null)
        {
            light = new GameObject("Key Light").AddComponent<Light>();
        }
        light.type = LightType.Directional;
        light.transform.rotation = Quaternion.Euler(50f, -24f, 0f);
        light.intensity = 1.95f;
        light.color = new Color(1f, 0.86f, 0.72f, 1f);
    }

    private static void CreateDigitalDojoRoom()
    {
        CreatePrimitive("DojoFloor", PrimitiveType.Cube, new Vector3(0f, -0.08f, 3.8f), new Vector3(15f, 0.12f, 15f), matWood);
        CreatePrimitive("BackWall", PrimitiveType.Cube, new Vector3(0f, 2.4f, 8.9f), new Vector3(15f, 4.8f, 0.22f), matWall);
        CreatePrimitive("LeftWall", PrimitiveType.Cube, new Vector3(-7.4f, 2.4f, 2.8f), new Vector3(0.18f, 4.8f, 12f), matWall);
        CreatePrimitive("RightWall", PrimitiveType.Cube, new Vector3(7.4f, 2.4f, 2.8f), new Vector3(0.18f, 4.8f, 12f), matWall);
        CreatePrimitive("Ceiling", PrimitiveType.Cube, new Vector3(0f, 4.85f, 3.8f), new Vector3(15f, 0.16f, 15f), matWood);

        for (int i = 0; i < 5; i++)
        {
            float x = -5.4f + i * 2.7f;
            CreatePrimitive("BackWallPanel_" + i, PrimitiveType.Cube, new Vector3(x, 2.35f, 8.74f), new Vector3(1.85f, 3.2f, 0.08f), matWall);
            CreatePrimitive("WarmWallLight_" + i, PrimitiveType.Cube, new Vector3(x, 4.05f, 8.58f), new Vector3(1.95f, 0.055f, 0.08f), matWarmLight);
            CreatePrimitive("PanelLowerGlow_" + i, PrimitiveType.Cube, new Vector3(x, 0.78f, 8.57f), new Vector3(1.55f, 0.035f, 0.06f), matWarmLight);
        }

        CreatePrimitive("DojoWallLogoOuter", PrimitiveType.Cylinder, new Vector3(0f, 3.05f, 8.52f), new Vector3(0.72f, 0.025f, 0.72f), matBlack).transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        CreatePrimitive("DojoWallLogoInner", PrimitiveType.Cylinder, new Vector3(0f, 3.05f, 8.48f), new Vector3(0.50f, 0.02f, 0.50f), matWall).transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        CreatePrimitive("DojoWallLogoSlashA", PrimitiveType.Cube, new Vector3(-0.12f, 3.05f, 8.44f), new Vector3(0.055f, 0.62f, 0.045f), matBlack).transform.rotation = Quaternion.Euler(0f, 0f, -28f);
        CreatePrimitive("DojoWallLogoSlashB", PrimitiveType.Cube, new Vector3(0.12f, 3.05f, 8.43f), new Vector3(0.055f, 0.62f, 0.045f), matBlack).transform.rotation = Quaternion.Euler(0f, 0f, 28f);

        for (int i = 0; i < 15; i++)
        {
            float z = -1.4f + i * 0.55f;
            CreatePrimitive("LeftWoodSlat_" + i, PrimitiveType.Cube, new Vector3(-6.88f, 2.2f, z), new Vector3(0.08f, 3.8f, 0.055f), matWood);
            CreatePrimitive("RightWoodSlat_" + i, PrimitiveType.Cube, new Vector3(6.88f, 2.2f, z), new Vector3(0.08f, 3.8f, 0.055f), matWood);
        }

        CreatePrimitive("HitLineRed", PrimitiveType.Cube, new Vector3(0f, 0.04f, -1.15f), new Vector3(13.2f, 0.035f, 0.055f), matRed);
        CreatePrimitive("LeftLaneRed", PrimitiveType.Cube, new Vector3(-2.5f, 0.02f, 3.7f), new Vector3(0.045f, 0.04f, 9.2f), matRed);
        CreatePrimitive("RightLaneBlue", PrimitiveType.Cube, new Vector3(2.5f, 0.02f, 3.7f), new Vector3(0.045f, 0.04f, 9.2f), matBlue);

        CreatePreviewPunchTarget("DojoPreviewPunchLeft", new Vector3(-3.25f, 2.60f, 5.98f), matRed);
        CreatePreviewPunchTarget("DojoPreviewPunchRight", new Vector3(3.25f, 2.60f, 5.98f), matBlue);
        CreatePreviewKickPad("DojoPreviewKickLeft", new Vector3(-3.45f, 0.86f, 5.72f), matRed);
        CreatePreviewKickPad("DojoPreviewKickRight", new Vector3(3.45f, 0.86f, 5.72f), matBlue);
        CreatePreviewHeavyTarget("DojoPreviewHeavyTarget", new Vector3(0f, 1.82f, 5.85f));
    }

    private static void CreatePreviewPunchTarget(string name, Vector3 center, Material accent)
    {
        CreateSceneDisc(name + "_Shadow", center + new Vector3(0.08f, -0.08f, 0.16f), 0.86f, 0.15f, matBlack);
        CreateSceneDisc(name + "_SteelBezel", center + new Vector3(0f, 0f, 0.08f), 0.78f, 0.08f, matWood);
        CreateSceneDisc(name + "_NeonRing", center + new Vector3(0f, 0f, 0f), 0.68f, 0.045f, accent);
        CreateSceneDisc(name + "_StrikePad", center + new Vector3(0f, 0f, -0.07f), 0.52f, 0.06f, matBlack);
        CreateSceneDisc(name + "_InnerPad", center + new Vector3(0f, 0f, -0.12f), 0.38f, 0.05f, accent);
        CreateFistIcon(name + "_Icon", center + new Vector3(0f, -0.02f, -0.22f), 1f);
    }

    private static void CreatePreviewKickPad(string name, Vector3 center, Material accent)
    {
        CreatePrimitive(name + "_OuterFrame", PrimitiveType.Cube, center + new Vector3(0f, 0f, 0.08f), new Vector3(0.86f, 1.28f, 0.16f), matWood);
        CreatePrimitive(name + "_NeonFrame", PrimitiveType.Cube, center + new Vector3(0f, 0f, -0.02f), new Vector3(0.72f, 1.10f, 0.08f), accent);
        CreatePrimitive(name + "_RubberPad", PrimitiveType.Cube, center + new Vector3(0f, 0f, -0.11f), new Vector3(0.55f, 0.88f, 0.08f), matBlack);
        CreatePrimitive(name + "_TopLip", PrimitiveType.Cube, center + new Vector3(0f, 0.51f, -0.18f), new Vector3(0.52f, 0.035f, 0.045f), matIconWhite);
        CreatePrimitive(name + "_FootSole", PrimitiveType.Cube, center + new Vector3(0f, -0.04f, -0.22f), new Vector3(0.24f, 0.48f, 0.045f), matIconWhite);
        for (int i = 0; i < 5; i++)
        {
            CreateSceneDisc(name + "_Toe_" + i, center + new Vector3(-0.16f + i * 0.08f, 0.30f, -0.24f), 0.04f, 0.018f, matIconWhite);
        }
    }

    private static void CreatePreviewHeavyTarget(string name, Vector3 center)
    {
        CreateSceneDisc(name + "_BackPlate", center + new Vector3(0.08f, -0.08f, 0.22f), 1.60f, 0.26f, matBlack);
        CreateSceneDisc(name + "_OuterLeather", center + new Vector3(0f, 0f, 0.12f), 1.42f, 0.13f, matBlack);
        CreateSceneDisc(name + "_WarmPaddedRing", center + new Vector3(0f, 0f, 0.02f), 1.14f, 0.10f, matWarmLight);
        CreateSceneDisc(name + "_RedRing", center + new Vector3(0f, 0f, -0.08f), 0.82f, 0.10f, matRed);
        CreateSceneDisc(name + "_BlackCore", center + new Vector3(0f, 0f, -0.18f), 0.54f, 0.09f, matBlack);
        CreateFistIcon(name + "_Icon", center + new Vector3(0f, -0.01f, -0.31f), 1.35f);

        CreateTextWorld("DIGITAL DOJO", new Vector3(0f, 3.65f, 5.72f), 0.22f, Color.black);
        CreatePrimitive(name + "_HealthBack", PrimitiveType.Cube, center + new Vector3(0f, 1.55f, -0.22f), new Vector3(1.72f, 0.065f, 0.05f), matBlack);
        CreatePrimitive(name + "_HealthFill", PrimitiveType.Cube, center + new Vector3(-0.08f, 1.55f, -0.27f), new Vector3(1.46f, 0.042f, 0.045f), matRed);
    }

    private static void CreateFistIcon(string prefix, Vector3 center, float scale)
    {
        CreatePrimitive(prefix + "_Palm", PrimitiveType.Cube, center + new Vector3(0f, -0.07f * scale, 0f), new Vector3(0.36f, 0.22f, 0.045f) * scale, matIconWhite);
        for (int i = 0; i < 4; i++)
        {
            CreatePrimitive(prefix + "_Knuckle_" + i, PrimitiveType.Cube, center + new Vector3((-0.17f + i * 0.11f) * scale, 0.10f * scale, -0.01f), new Vector3(0.085f, 0.11f, 0.045f) * scale, matIconWhite);
        }
        GameObject thumb = CreatePrimitive(prefix + "_Thumb", PrimitiveType.Cube, center + new Vector3(0.24f * scale, -0.04f * scale, -0.01f), new Vector3(0.075f, 0.18f, 0.045f) * scale, matIconWhite);
        thumb.transform.rotation = Quaternion.Euler(0f, 0f, -28f);
    }

    private static GameObject CreateSceneDisc(string name, Vector3 position, float radius, float depth, Material material)
    {
        GameObject disc = CreatePrimitive(name, PrimitiveType.Cylinder, position, new Vector3(radius, depth, radius), material);
        disc.transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        return disc;
    }

    private static void CreateTextWorld(string value, Vector3 position, float characterSize, Color color)
    {
        GameObject go = new GameObject(value.Replace(" ", "") + "WorldLabel");
        go.transform.position = position;
        TextMesh mesh = go.AddComponent<TextMesh>();
        mesh.text = value;
        mesh.font = uiFont;
        mesh.fontSize = 72;
        mesh.characterSize = characterSize;
        mesh.anchor = TextAnchor.MiddleCenter;
        mesh.alignment = TextAlignment.Center;
        mesh.color = color;
    }

    private static GameObject CreatePrimitive(string name, PrimitiveType type, Vector3 position, Vector3 scale, Material material)
    {
        GameObject primitive = GameObject.CreatePrimitive(type);
        primitive.name = name;
        primitive.transform.position = position;
        primitive.transform.localScale = scale;
        Renderer renderer = primitive.GetComponent<Renderer>();
        if (renderer != null)
        {
            renderer.sharedMaterial = material;
        }
        Collider collider = primitive.GetComponent<Collider>();
        if (collider != null)
        {
            Object.DestroyImmediate(collider);
        }
        return primitive;
    }

    private static void InstantiateGeneratedTarget(string path, string name, Vector3 position, Quaternion rotation, Vector3 scale)
    {
        GameObject prefab = AssetDatabase.LoadAssetAtPath<GameObject>(path);
        if (prefab == null)
        {
            return;
        }

        GameObject instance = PrefabUtility.InstantiatePrefab(prefab) as GameObject;
        if (instance == null)
        {
            return;
        }

        instance.name = name;
        instance.transform.position = position;
        instance.transform.rotation = rotation;
        instance.transform.localScale = scale;
        foreach (Collider collider in instance.GetComponentsInChildren<Collider>())
        {
            Object.DestroyImmediate(collider);
        }
    }

    private static GameObject CreateHomePage(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform root = CreateRect(parent, "HomePanel");
        StretchRect(root, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);

        RectTransform nav = CreateGlassCard(root, "MainMenuCard", new Vector2(94f, -122f), new Vector2(620f, 835f), TextAnchor.UpperLeft);
        CreateText(nav, "BrandLine", "BOX REHA GAME", 42, TextAnchor.UpperLeft, new Vector2(40f, -36f), new Vector2(460f, 56f), Color.white);
        CreateText(nav, "HubSubtitle", "DIGITAL DOJO TRAINING", 18, TextAnchor.UpperLeft, new Vector2(42f, -91f), new Vector2(420f, 28f), new Color(1f, 0.28f, 0.22f, 1f));

        Button start = CreateDojoButton(nav, "StartTrainingButton", "START TRAINING", new Vector2(40f, -152f), true);
        UnityEventTools.AddPersistentListener(start.onClick, controller.StartTraining);
        Button level = CreateDojoButton(nav, "LevelModeButton", "LEVEL MODE", new Vector2(40f, -236f), false);
        UnityEventTools.AddPersistentListener(level.onClick, controller.StartLevelMode);
        Button endless = CreateDojoButton(nav, "EndlessModeButton", "ENDLESS MODE", new Vector2(40f, -320f), false);
        UnityEventTools.AddPersistentListener(endless.onClick, controller.StartEndlessMode);
        Button profile = CreateDojoButton(nav, "PlayerProfileButton", "PLAYER PROFILE", new Vector2(40f, -404f), false);
        UnityEventTools.AddPersistentListener(profile.onClick, controller.ShowPlayerProfile);
        Button stats = CreateDojoButton(nav, "StatisticsButton", "STATISTICS", new Vector2(40f, -488f), false);
        UnityEventTools.AddPersistentListener(stats.onClick, controller.ShowStatistics);
        Button calibration = CreateDojoButton(nav, "CalibrationButton", "CALIBRATION MODE", new Vector2(40f, -572f), false);
        UnityEventTools.AddPersistentListener(calibration.onClick, controller.ShowCalibration);
        Button settings = CreateDojoButton(nav, "SettingsButton", "SETTINGS", new Vector2(40f, -656f), false);
        UnityEventTools.AddPersistentListener(settings.onClick, controller.ShowSettings);
        Button quit = CreateDojoButton(nav, "QuitButton", "QUIT", new Vector2(168f, -752f), false, 300f);
        UnityEventTools.AddPersistentListener(quit.onClick, controller.Quit);

        RectTransform trainingCard = CreateGlassCard(root, "CalibrationInfoCard", new Vector2(760f, -708f), new Vector2(300f, 335f), TextAnchor.UpperLeft);
        CreateText(trainingCard, "Title", "CALIBRATION MODE", 23, TextAnchor.UpperCenter, new Vector2(18f, -28f), new Vector2(264f, 34f), Color.white);
        CreateText(trainingCard, "Copy", "Measures punch strength, maximum kick strength, and average heart rate.\n\nThese values adapt Level Mode and Endless Mode to you.", 17, TextAnchor.UpperLeft, new Vector2(30f, -112f), new Vector2(238f, 190f), new Color(0.88f, 0.9f, 0.86f, 1f));

        RectTransform todayCard = CreateGlassCard(root, "TodayTrainingCard", new Vector2(1090f, -730f), new Vector2(505f, 284f), TextAnchor.UpperLeft);
        CreateText(todayCard, "Title", "TODAY'S TRAINING", 24, TextAnchor.UpperCenter, new Vector2(22f, -28f), new Vector2(460f, 34f), Color.white);
        CreateStatRow(todayCard, "ACCURACY", "92%", new Vector2(40f, -92f), new Color(0.52f, 1f, 0.35f, 1f));
        CreateStatRow(todayCard, "COMBO BEST", "36", new Vector2(40f, -154f), new Color(1f, 0.24f, 0.22f, 1f));
        CreateStatRow(todayCard, "AVG. POWER", "128 W", new Vector2(40f, -216f), new Color(0.3f, 0.72f, 1f, 1f));

        CreateFooter(root, "PRESS  ENTER  /  A  TO START");
        return root.gameObject;
    }

    private static GameObject CreateCalibrationPage(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform root = CreatePageBase(parent, "CalibrationPanel", "KALIBRIERUNG");
        Button back = CreateBackButton(root, controller);
        UnityEventTools.AddPersistentListener(back.onClick, controller.ShowHome);

        RectTransform steps = CreateGlassCard(root, "CalibrationSteps", new Vector2(92f, -142f), new Vector2(300f, 310f), TextAnchor.UpperLeft);
        CreateStepButton(steps, "1   SCHLAG KALIBRIERUNG", new Vector2(20f, -28f), true);
        CreateStepButton(steps, "2   TRITT KALIBRIERUNG", new Vector2(20f, -86f), false);
        CreateStepButton(steps, "3   PULS KALIBRIERUNG", new Vector2(20f, -144f), false);
        CreateStepButton(steps, "4   ZUSAMMENFASSUNG", new Vector2(20f, -202f), false);

        RectTransform center = CreateGlassCard(root, "CalibrationMainCard", new Vector2(470f, -132f), new Vector2(760f, 480f), TextAnchor.UpperLeft);
        CreateText(center, "Headline", "1. SCHLAG KALIBRIERUNG", 30, TextAnchor.UpperLeft, new Vector2(36f, -42f), new Vector2(520f, 42f), Color.white);
        CreateText(center, "Intro", "Schlage mit maximaler Kraft mit deinem linken und rechten Arm auf die Targets.", 18, TextAnchor.UpperLeft, new Vector2(36f, -90f), new Vector2(650f, 60f), new Color(0.82f, 0.84f, 0.82f, 1f));
        CreateGauge(center, "LINKER ARM", "92%", "MAX KRAFT\n480 N", new Vector2(80f, -172f), new Color(1f, 0.24f, 0.2f, 1f));
        CreateGauge(center, "RECHTER ARM", "94%", "MAX KRAFT\n495 N", new Vector2(520f, -172f), new Color(0.25f, 0.65f, 1f, 1f));
        CreateText(center, "Count", "3 / 3", 34, TextAnchor.MiddleCenter, new Vector2(326f, -228f), new Vector2(120f, 50f), Color.white);
        CreateProgressBar(center, new Vector2(36f, -408f), new Vector2(678f, 18f), 0.78f, new Color(1f, 0.25f, 0.2f, 1f));

        RectTransform why = CreateGlassCard(root, "WhyCard", new Vector2(1285f, -132f), new Vector2(360f, 240f), TextAnchor.UpperLeft);
        CreateText(why, "Title", "WARUM KALIBRIEREN?", 23, TextAnchor.UpperLeft, new Vector2(28f, -34f), new Vector2(300f, 34f), Color.white);
        CreateText(why, "Body", "Die Kalibrierung passt das Spiel an deine individuelle Leistungsfaehigkeit an und sorgt fuer ein optimales Trainingserlebnis.", 17, TextAnchor.UpperLeft, new Vector2(28f, -92f), new Vector2(300f, 120f), new Color(0.82f, 0.84f, 0.82f, 1f));

        RectTransform sensors = CreateGlassCard(root, "SensorCard", new Vector2(1285f, -405f), new Vector2(360f, 255f), TextAnchor.UpperLeft);
        CreateText(sensors, "Title", "BENOETIGTE SENSOREN", 22, TextAnchor.UpperLeft, new Vector2(28f, -34f), new Vector2(300f, 34f), Color.white);
        CreateText(sensors, "Body", "RD-ALPHA  (Arme)\nRD-DELTA   (Fuesse)\nHerzfrequenz-Sensor", 19, TextAnchor.UpperLeft, new Vector2(48f, -100f), new Vector2(290f, 120f), new Color(0.94f, 0.95f, 0.92f, 1f));
        return root.gameObject;
    }

    private static GameObject CreateStatisticsPage(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform root = CreatePageBase(parent, "StatisticsPanel", "STATISTIK");
        Button back = CreateBackButton(root, controller);
        UnityEventTools.AddPersistentListener(back.onClick, controller.ShowHome);

        RectTransform overview = CreateGlassCard(root, "OverviewCard", new Vector2(78f, -160f), new Vector2(450f, 750f), TextAnchor.UpperLeft);
        CreateText(overview, "Title", "UEBERSICHT", 24, TextAnchor.UpperLeft, new Vector2(34f, -34f), new Vector2(360f, 34f), Color.white);
        CreateStatTile(overview, "GESAMTSPIELZEIT", "12:45:30", new Vector2(32f, -105f));
        CreateStatTile(overview, "GESAMTEINHEITEN", "48", new Vector2(32f, -220f));
        CreateStatTile(overview, "GESAMTPUNKTE", "1,245,300", new Vector2(32f, -335f));
        CreateStatTile(overview, "DURCHSCHNITT ACCURACY", "91%", new Vector2(32f, -450f));
        CreateStatTile(overview, "DURCHSCHNITT COMBO", "48", new Vector2(32f, -565f));

        RectTransform radar = CreateGlassCard(root, "RadarCard", new Vector2(560f, -160f), new Vector2(690f, 750f), TextAnchor.UpperLeft);
        CreateText(radar, "Title", "LEISTUNG UEBERSICHT", 24, TextAnchor.UpperLeft, new Vector2(34f, -34f), new Vector2(440f, 34f), Color.white);
        CreateRadarPlaceholder(radar);

        RectTransform last = CreateGlassCard(root, "LastSessionCard", new Vector2(1285f, -160f), new Vector2(365f, 750f), TextAnchor.UpperLeft);
        CreateText(last, "Title", "LETZTE EINHEIT", 24, TextAnchor.UpperLeft, new Vector2(32f, -34f), new Vector2(300f, 34f), Color.white);
        CreateText(last, "Body", "17.05.2025        18:42\n\nMODUS\nEndless\n\nDAUER\n18:34\n\nPUNKTE\n127,350\n\nMAX COMBO\n76\n\nACCURACY\n92%", 22, TextAnchor.UpperLeft, new Vector2(32f, -105f), new Vector2(300f, 445f), new Color(0.9f, 0.92f, 0.9f, 1f));
        return root.gameObject;
    }

    private static GameObject CreateProfilePage(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform root = CreatePageBase(parent, "PlayerProfilePanel", "PLAYER PROFILE");
        Button back = CreateBackButton(root, controller);
        UnityEventTools.AddPersistentListener(back.onClick, controller.ShowHome);

        RectTransform sidebar = CreateGlassCard(root, "ProfileSidebar", new Vector2(92f, -158f), new Vector2(410f, 752f), TextAnchor.UpperLeft);
        CreateAvatar(sidebar, new Vector2(54f, -54f), 92f);
        CreateText(sidebar, "Name", "Alex", 28, TextAnchor.UpperLeft, new Vector2(170f, -62f), new Vector2(180f, 40f), Color.white);
        CreateText(sidebar, "Level", "Level 12", 18, TextAnchor.UpperLeft, new Vector2(170f, -102f), new Vector2(180f, 30f), new Color(0.78f, 0.8f, 0.76f, 1f));
        CreateProgressBar(sidebar, new Vector2(54f, -166f), new Vector2(300f, 14f), 0.7f, new Color(1f, 0.22f, 0.18f, 1f));
        CreateStepButton(sidebar, "PROFIL INFORMATIONEN", new Vector2(34f, -230f), true, 340f);
        CreateStepButton(sidebar, "TRAININGSZIELE", new Vector2(34f, -292f), false, 340f);
        CreateStepButton(sidebar, "BENACHRICHTIGUNGEN", new Vector2(34f, -354f), false, 340f);
        CreateStepButton(sidebar, "DATENSCHUTZ", new Vector2(34f, -416f), false, 340f);

        RectTransform info = CreateGlassCard(root, "ProfileInfoCard", new Vector2(540f, -158f), new Vector2(760f, 752f), TextAnchor.UpperLeft);
        CreateText(info, "Title", "PROFIL INFORMATIONEN", 24, TextAnchor.UpperLeft, new Vector2(34f, -34f), new Vector2(430f, 34f), Color.white);
        CreateText(info, "Body", "SPIELERNAME\nAlex\n\nALTER\n25\n\nGESCHLECHT\nMaennlich\n\nTRAININGSZIEL\nFit bleiben\n\nERFAHRUNGSSTUFE\nFortgeschritten", 23, TextAnchor.UpperLeft, new Vector2(54f, -120f), new Vector2(600f, 430f), new Color(0.9f, 0.92f, 0.9f, 1f));

        RectTransform goals = CreateGlassCard(root, "TrainingGoalCard", new Vector2(1330f, -158f), new Vector2(325f, 335f), TextAnchor.UpperLeft);
        CreateText(goals, "Title", "TRAININGSZIEL", 23, TextAnchor.UpperLeft, new Vector2(26f, -32f), new Vector2(260f, 34f), Color.white);
        CreateText(goals, "Body", "Fit bleiben\n\nHalte dich fit und verbessere deine Ausdauer und Kraft.", 19, TextAnchor.UpperLeft, new Vector2(28f, -98f), new Vector2(260f, 150f), new Color(0.9f, 0.92f, 0.9f, 1f));
        CreateSmallButton(goals, "GoalButton", "ZIEL AENDERN", new Vector2(28f, -260f), 260f);

        RectTransform mode = CreateGlassCard(root, "PreferredModeCard", new Vector2(1330f, -532f), new Vector2(325f, 295f), TextAnchor.UpperLeft);
        CreateText(mode, "Title", "BEVORZUGTER MODUS", 22, TextAnchor.UpperLeft, new Vector2(26f, -32f), new Vector2(260f, 34f), Color.white);
        CreateText(mode, "Body", "Endless Mode\n\nUnendliche Herausforderung mit ansteigendem Schwierigkeitsgrad.", 18, TextAnchor.UpperLeft, new Vector2(28f, -98f), new Vector2(260f, 125f), new Color(0.9f, 0.92f, 0.9f, 1f));
        CreateSmallButton(mode, "ModeButton", "AENDERN", new Vector2(28f, -220f), 260f);
        return root.gameObject;
    }

    private static GameObject CreateSettingsPage(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform root = CreatePageBase(parent, "SettingsPanel", "SETTINGS");
        Button back = CreateBackButton(root, controller);
        UnityEventTools.AddPersistentListener(back.onClick, controller.ShowHome);

        CreateAudioSettingsCard(root, new Vector2(82f, -142f));
        CreateToggleSettingsCard(root, "2. GAMEPLAY", new Vector2(625f, -142f), new[] { "Difficulty Adaptation|ON", "Hit Feedback|ON", "Combo Popups|ON", "Heavy Target Assist|OFF" });
        CreateControlsSettingsCard(root, new Vector2(1168f, -142f));
        CreateToggleSettingsCard(root, "4. SENSORS", new Vector2(82f, -560f), new[] { "RD ALPHA (Glove)|CONNECTED", "RD DELTA (Foot)|CONNECTED", "Heart-Rate Monitor|NOT CONNECTED" });
        
        CreateAudioSettingsCard(root, new Vector2(625f, -560f), "5. VISUALS / ACCESSIBILITY", new[] { "UI Scale|100%|1.0", "Colorblind Mode|OFF|0", "Brightness|60%|0.6", "High-Contrast Mode|OFF|0" });
        CreateToggleSettingsCard(root, "6. PROFILE / DATA", new Vector2(1168f, -560f), new[] { "Save Profile Automatically|ON", "Reset Calibration Data|RESET", "Export Training Data|EXPORT" });

        Button reset = CreateBottomButton(root, "ResetDefaultsButton", "RESET TO DEFAULTS", new Vector2(1164f, -965f), 310f, false);
        Button save = CreateBottomButton(root, "SaveSettingsButton", "SAVE SETTINGS", new Vector2(1490f, -965f), 300f, true);
        return root.gameObject;
    }

    private static RectTransform CreatePageBase(Transform parent, string name, string title)
    {
        RectTransform root = CreateRect(parent, name);
        StretchRect(root, Vector2.zero, Vector2.one, Vector2.zero, Vector2.zero);
        CreateText(root, "PageTitle", title, 40, TextAnchor.UpperLeft, new Vector2(135f, -92f), new Vector2(720f, 54f), Color.white);
        return root;
    }

    private static void CreateTopBar(Transform parent)
    {
        RectTransform bar = CreatePanel(parent, "TopBar", new Color(0f, 0f, 0f, 0.72f));
        StretchRect(bar, new Vector2(0f, 0.91f), new Vector2(1f, 1f), Vector2.zero, Vector2.zero);
        CreateMiniLogo(bar, new Vector2(30f, -24f), 54f);
        CreateText(bar, "Title", "BOX REHA GAME", 28, TextAnchor.UpperLeft, new Vector2(98f, -22f), new Vector2(360f, 40f), Color.white);
        CreateText(bar, "Subtitle", "DIGITAL DOJO", 18, TextAnchor.UpperLeft, new Vector2(98f, -58f), new Vector2(320f, 28f), new Color(1f, 0.24f, 0.19f, 1f));
        RectTransform user = CreateGlassCard(bar, "UserBadge", new Vector2(1548f, -20f), new Vector2(210f, 62f), TextAnchor.UpperLeft);
        CreateAvatar(user, new Vector2(18f, -10f), 42f);
        CreateText(user, "Name", "Alex", 18, TextAnchor.UpperLeft, new Vector2(72f, -10f), new Vector2(100f, 24f), Color.white);
        CreateText(user, "Level", "Level 12", 13, TextAnchor.UpperLeft, new Vector2(72f, -34f), new Vector2(100f, 20f), new Color(0.78f, 0.8f, 0.78f, 1f));
    }

    private static Canvas CreateCanvas(string name)
    {
        GameObject canvasObject = new GameObject(name);
        Canvas canvas = canvasObject.AddComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        canvas.sortingOrder = 10;

        CanvasScaler scaler = canvasObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1920f, 1080f);
        scaler.matchWidthOrHeight = 0.5f;
        canvasObject.AddComponent<GraphicRaycaster>();
        return canvas;
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

    private static RectTransform CreateRect(Transform parent, string name)
    {
        GameObject go = new GameObject(name);
        RectTransform rect = go.AddComponent<RectTransform>();
        rect.SetParent(parent, false);
        return rect;
    }

    private static RectTransform CreatePanel(Transform parent, string name, Color color)
    {
        RectTransform rect = CreateRect(parent, name);
        Image image = rect.gameObject.AddComponent<Image>();
        image.color = color;
        return rect;
    }

    private static RectTransform CreateGlassCard(Transform parent, string name, Vector2 anchoredPosition, Vector2 size, TextAnchor anchor)
    {
        RectTransform card = CreatePanel(parent, name, new Color(0.02f, 0.023f, 0.023f, 0.90f));
        AnchorRect(card, anchor, anchoredPosition, size);
        Outline outline = card.gameObject.AddComponent<Outline>();
        outline.effectColor = new Color(1f, 1f, 1f, 0.08f);
        outline.effectDistance = new Vector2(1.4f, -1.4f);

        RectTransform topGlow = CreatePanel(card, "TopGlow", new Color(1f, 0.18f, 0.14f, 0.22f));
        AnchorRect(topGlow, TextAnchor.UpperLeft, new Vector2(0f, 0f), new Vector2(size.x, 2f));
        RectTransform bottomShade = CreatePanel(card, "BottomShade", new Color(0f, 0f, 0f, 0.18f));
        AnchorRect(bottomShade, TextAnchor.LowerLeft, new Vector2(0f, 0f), new Vector2(size.x, 36f));
        return card;
    }

    private static Button CreateDojoButton(Transform parent, string name, string label, Vector2 anchoredPosition, bool primary, float width = 520f)
    {
        RectTransform rect = CreatePanel(parent, name, primary ? new Color(0.72f, 0.12f, 0.09f, 0.95f) : new Color(0.035f, 0.037f, 0.038f, 0.92f));
        AnchorRect(rect, TextAnchor.UpperLeft, anchoredPosition, new Vector2(width, 66f));
        Button button = rect.gameObject.AddComponent<Button>();
        ColorBlock colors = button.colors;
        colors.normalColor = Color.white;
        colors.highlightedColor = new Color(1f, 0.28f, 0.22f, 1f);
        colors.pressedColor = new Color(0.55f, 0.06f, 0.045f, 1f);
        button.colors = colors;

        Outline outline = rect.gameObject.AddComponent<Outline>();
        outline.effectColor = primary ? new Color(1f, 0.6f, 0.55f, 0.5f) : new Color(1f, 1f, 1f, 0.12f);
        outline.effectDistance = new Vector2(1.5f, -1.5f);
        RectTransform iconSlot = CreatePanel(rect, "IconSlot", primary ? new Color(1f, 1f, 1f, 0.18f) : new Color(1f, 1f, 1f, 0.07f));
        AnchorRect(iconSlot, TextAnchor.MiddleLeft, new Vector2(34f, -33f), new Vector2(44f, 44f));
        RectTransform accent = CreatePanel(iconSlot, "AccentCore", primary ? new Color(1f, 0.86f, 0.78f, 0.96f) : new Color(1f, 1f, 1f, 0.64f));
        AnchorRect(accent, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(18f, 18f));
        CreateText(iconSlot, "IconText", GetButtonIcon(label), primary ? 13 : 11, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(44f, 44f), primary ? new Color(0.72f, 0.12f, 0.09f, 1f) : new Color(0.02f, 0.022f, 0.023f, 1f));
        CreateText(rect, "Label", label, 27, TextAnchor.MiddleLeft, new Vector2(100f, -33f), new Vector2(width - 120f, 40f), Color.white);
        return button;
    }

    private static string GetButtonIcon(string label)
    {
        switch (label)
        {
            case "START TRAINING":
                return "GO";
            case "LEVEL MODE":
                return "LV";
            case "ENDLESS MODE":
                return "END";
            case "PLAYER PROFILE":
                return "PRO";
            case "STATISTICS":
                return "ST";
            case "CALIBRATION MODE":
                return "CAL";
            case "SETTINGS":
                return "SET";
            case "QUIT":
                return "Q";
            default:
                return "";
        }
    }

    private static Button CreateBackButton(Transform parent, DigitalDojoMenuController controller)
    {
        RectTransform rect = CreatePanel(parent, "BackButton", new Color(0.035f, 0.037f, 0.038f, 0.92f));
        AnchorRect(rect, TextAnchor.UpperLeft, new Vector2(24f, -28f), new Vector2(70f, 62f));
        Button button = rect.gameObject.AddComponent<Button>();
        CreateText(rect, "Label", "<", 38, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(70f, 62f), Color.white);
        return button;
    }

    private static void CreateStepButton(Transform parent, string label, Vector2 anchoredPosition, bool active, float width = 260f)
    {
        RectTransform rect = CreatePanel(parent, label, active ? new Color(0.72f, 0.12f, 0.09f, 0.92f) : new Color(0.02f, 0.022f, 0.023f, 0.9f));
        AnchorRect(rect, TextAnchor.UpperLeft, anchoredPosition, new Vector2(width, 45f));
        CreateText(rect, "Label", label, 15, TextAnchor.MiddleLeft, new Vector2(18f, -22.5f), new Vector2(width - 24f, 30f), Color.white);
    }

    private static Button CreateSmallButton(Transform parent, string name, string label, Vector2 anchoredPosition, float width)
    {
        RectTransform rect = CreatePanel(parent, name, new Color(0.055f, 0.058f, 0.06f, 0.95f));
        AnchorRect(rect, TextAnchor.UpperLeft, anchoredPosition, new Vector2(width, 48f));
        Button button = rect.gameObject.AddComponent<Button>();
        CreateText(rect, "Label", label, 17, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(width, 48f), Color.white);
        return button;
    }

    private static Button CreateBottomButton(Transform parent, string name, string label, Vector2 anchoredPosition, float width, bool primary)
    {
        RectTransform rect = CreatePanel(parent, name, primary ? new Color(0.72f, 0.12f, 0.09f, 0.95f) : new Color(0.025f, 0.027f, 0.028f, 0.95f));
        AnchorRect(rect, TextAnchor.UpperLeft, anchoredPosition, new Vector2(width, 58f));
        Button button = rect.gameObject.AddComponent<Button>();
        CreateText(rect, "Label", label, 22, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(width, 58f), Color.white);
        return button;
    }

    private static RectTransform CreateAudioSettingsCard(Transform parent, Vector2 position)
    {
        return CreateAudioSettingsCard(parent, position, "1. AUDIO", new[] { "Master Volume|80%|0.8", "Music Volume|60%|0.6", "SFX Volume|90%|0.9", "Voice / Coach|75%|0.75" });
    }

    private static RectTransform CreateAudioSettingsCard(Transform parent, Vector2 position, string title, string[] rows)
    {
        RectTransform card = CreateGlassCard(parent, title, position, new Vector2(500f, 350f), TextAnchor.UpperLeft);
        CreateText(card, "Title", title, 23, TextAnchor.UpperLeft, new Vector2(30f, -30f), new Vector2(420f, 34f), Color.white);
        for (int i = 0; i < rows.Length; i++)
        {
            string[] parts = rows[i].Split('|');
            float fill = parts.Length > 2 ? float.Parse(parts[2], System.Globalization.CultureInfo.InvariantCulture) : 0f;
            CreateText(card, "RowLabel_" + i, parts[0], 18, TextAnchor.MiddleLeft, new Vector2(30f, -102f - i * 55f), new Vector2(220f, 30f), Color.white);
            CreateText(card, "RowValue_" + i, parts[1], 16, TextAnchor.MiddleRight, new Vector2(398f, -102f - i * 55f), new Vector2(58f, 30f), new Color(0.82f, 0.84f, 0.82f, 1f));
            CreateProgressBar(card, new Vector2(245f, -107f - i * 55f), new Vector2(135f, 8f), fill, new Color(1f, 0.22f, 0.18f, 1f));
        }
        return card;
    }

    private static void CreateToggleSettingsCard(Transform parent, string title, Vector2 position, string[] rows)
    {
        RectTransform card = CreateGlassCard(parent, title, position, new Vector2(500f, 350f), TextAnchor.UpperLeft);
        CreateText(card, "Title", title, 23, TextAnchor.UpperLeft, new Vector2(30f, -30f), new Vector2(420f, 34f), Color.white);
        for (int i = 0; i < rows.Length; i++)
        {
            string[] parts = rows[i].Split('|');
            Color chipColor = parts[1].Contains("CONNECTED") || parts[1] == "ON" ? new Color(0.70f, 0.12f, 0.10f, 0.95f) : new Color(0.035f, 0.037f, 0.038f, 0.95f);
            if (parts[1].Contains("NOT CONNECTED"))
            {
                chipColor = new Color(0.16f, 0.10f, 0.02f, 0.95f);
            }
            CreateText(card, "RowLabel_" + i, parts[0], 18, TextAnchor.MiddleLeft, new Vector2(30f, -104f - i * 58f), new Vector2(280f, 32f), Color.white);
            RectTransform chip = CreatePanel(card, "Chip_" + i, chipColor);
            AnchorRect(chip, TextAnchor.UpperRight, new Vector2(-28f, -90f - i * 58f), new Vector2(118f, 34f));
            CreateText(chip, "ChipLabel", parts[1], 14, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(118f, 34f), Color.white);
        }
    }

    private static void CreateControlsSettingsCard(Transform parent, Vector2 position)
    {
        RectTransform card = CreateGlassCard(parent, "3. CONTROLS", position, new Vector2(500f, 350f), TextAnchor.UpperLeft);
        CreateText(card, "Title", "3. CONTROLS", 23, TextAnchor.UpperLeft, new Vector2(30f, -30f), new Vector2(420f, 34f), Color.white);
        string[] rows = { "Left Arrow|Left Punch", "Right Arrow|Right Punch", "A|Left Kick", "D|Right Kick" };
        for (int i = 0; i < rows.Length; i++)
        {
            string[] parts = rows[i].Split('|');
            RectTransform row = CreatePanel(card, "ControlRow_" + i, new Color(1f, 1f, 1f, i % 2 == 0 ? 0.045f : 0.025f));
            AnchorRect(row, TextAnchor.UpperLeft, new Vector2(30f, -88f - i * 39f), new Vector2(420f, 38f));
            CreateText(row, "Key", parts[0], 16, TextAnchor.MiddleLeft, new Vector2(18f, -19f), new Vector2(150f, 28f), Color.white);
            CreateText(row, "Equals", "=", 16, TextAnchor.MiddleCenter, new Vector2(205f, -19f), new Vector2(24f, 28f), new Color(0.62f, 0.64f, 0.62f, 1f));
            CreateText(row, "Action", parts[1], 16, TextAnchor.MiddleLeft, new Vector2(250f, -19f), new Vector2(150f, 28f), Color.white);
        }
        CreateText(card, "Hint", "Keyboard test mode bleibt kompatibel mit RD ALPHA / RD DELTA Sensorinput.", 15, TextAnchor.UpperLeft, new Vector2(30f, -260f), new Vector2(420f, 50f), new Color(0.78f, 0.8f, 0.78f, 1f));
    }

    private static void CreateStatTile(Transform parent, string label, string value, Vector2 position)
    {
        RectTransform tile = CreatePanel(parent, label, new Color(1f, 1f, 1f, 0.045f));
        AnchorRect(tile, TextAnchor.UpperLeft, position, new Vector2(385f, 86f));
        CreateText(tile, "Label", label, 14, TextAnchor.UpperLeft, new Vector2(24f, -16f), new Vector2(300f, 24f), new Color(0.62f, 0.64f, 0.62f, 1f));
        CreateText(tile, "Value", value, 30, TextAnchor.UpperLeft, new Vector2(24f, -42f), new Vector2(300f, 38f), Color.white);
    }

    private static void CreateStatRow(Transform parent, string label, string value, Vector2 position, Color accent)
    {
        CreateText(parent, label + "Label", label, 22, TextAnchor.MiddleLeft, position, new Vector2(250f, 40f), Color.white);
        CreateText(parent, label + "Value", value, 30, TextAnchor.MiddleRight, position + new Vector2(260f, 0f), new Vector2(160f, 40f), accent);
    }

    private static void CreateGauge(Transform parent, string label, string percent, string detail, Vector2 position, Color accent)
    {
        RectTransform gauge = CreatePanel(parent, label, new Color(1f, 1f, 1f, 0.045f));
        AnchorRect(gauge, TextAnchor.UpperLeft, position, new Vector2(160f, 210f));
        CreateText(gauge, "Label", label, 16, TextAnchor.UpperCenter, new Vector2(0f, -14f), new Vector2(160f, 26f), Color.white);
        RectTransform ring = CreatePanel(gauge, "Ring", accent);
        AnchorRect(ring, TextAnchor.UpperLeft, new Vector2(36f, -58f), new Vector2(88f, 88f));
        ring.gameObject.AddComponent<Mask>().showMaskGraphic = true;
        CreatePanel(ring, "Inner", new Color(0.02f, 0.022f, 0.024f, 1f));
        RectTransform inner = ring.Find("Inner") as RectTransform;
        AnchorRect(inner, TextAnchor.UpperLeft, new Vector2(12f, -12f), new Vector2(64f, 64f));
        CreateText(gauge, "Percent", percent, 28, TextAnchor.MiddleCenter, new Vector2(0f, -100f), new Vector2(160f, 44f), Color.white);
        CreateText(gauge, "Detail", detail, 15, TextAnchor.UpperCenter, new Vector2(0f, -146f), new Vector2(160f, 56f), new Color(0.88f, 0.9f, 0.86f, 1f));
    }

    private static void CreateRadarPlaceholder(Transform parent)
    {
        RectTransform center = CreateRect(parent, "RadarGraph");
        AnchorRect(center, TextAnchor.UpperLeft, new Vector2(135f, -115f), new Vector2(420f, 420f));

        for (int i = 0; i < 5; i++)
        {
            CreateRadarSpoke(center, "RadarSpoke_" + i, i * 72f, 165f, new Color(1f, 1f, 1f, 0.11f));
        }

        CreateRadarSpoke(center, "PowerLeft", -90f, 138f, new Color(1f, 0.22f, 0.18f, 0.92f), 7f);
        CreateRadarSpoke(center, "PowerRight", -18f, 148f, new Color(1f, 0.22f, 0.18f, 0.92f), 7f);
        CreateRadarSpoke(center, "KickRight", 54f, 136f, new Color(1f, 0.22f, 0.18f, 0.92f), 7f);
        CreateRadarSpoke(center, "KickLeft", 126f, 132f, new Color(1f, 0.22f, 0.18f, 0.92f), 7f);
        CreateRadarSpoke(center, "Accuracy", 198f, 150f, new Color(1f, 0.22f, 0.18f, 0.92f), 7f);
        CreateText(parent, "RadarLabels", "SCHLAG KRAFT (Links) 86%        SCHLAG KRAFT (Rechts) 88%\n\nTRITT KRAFT (Links) 83%          TRITT KRAFT (Rechts) 82%\n\nACCURACY 91%", 18, TextAnchor.MiddleCenter, new Vector2(70f, -552f), new Vector2(550f, 125f), Color.white);
    }

    private static void CreateRadarSpoke(Transform parent, string name, float degrees, float length, Color color, float thickness = 3f)
    {
        RectTransform spoke = CreatePanel(parent, name, color);
        AnchorRect(spoke, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(length, thickness));
        spoke.localRotation = Quaternion.Euler(0f, 0f, degrees);
    }

    private static void CreateProgressBar(Transform parent, Vector2 position, Vector2 size, float fill, Color accent)
    {
        RectTransform background = CreatePanel(parent, "ProgressBackground", new Color(1f, 1f, 1f, 0.12f));
        AnchorRect(background, TextAnchor.UpperLeft, position, size);
        RectTransform foreground = CreatePanel(background, "ProgressFill", accent);
        AnchorRect(foreground, TextAnchor.UpperLeft, Vector2.zero, new Vector2(size.x * Mathf.Clamp01(fill), size.y));
    }

    private static void CreateMiniLogo(Transform parent, Vector2 position, float size)
    {
        RectTransform outer = CreatePanel(parent, "LogoRing", new Color(1f, 0.12f, 0.1f, 0.95f));
        AnchorRect(outer, TextAnchor.UpperLeft, position, new Vector2(size, size));
        RectTransform inner = CreatePanel(outer, "LogoInner", new Color(0.02f, 0.02f, 0.022f, 1f));
        AnchorRect(inner, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(size * 0.62f, size * 0.62f));
        RectTransform core = CreatePanel(inner, "LogoCore", new Color(1f, 0.12f, 0.1f, 1f));
        AnchorRect(core, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(size * 0.28f, size * 0.28f));
    }

    private static void CreateAvatar(Transform parent, Vector2 position, float size)
    {
        RectTransform avatar = CreatePanel(parent, "Avatar", new Color(1f, 1f, 1f, 0.92f));
        AnchorRect(avatar, TextAnchor.UpperLeft, position, new Vector2(size, size));
        RectTransform inner = CreatePanel(avatar, "AvatarInner", new Color(0.045f, 0.047f, 0.05f, 1f));
        AnchorRect(inner, TextAnchor.MiddleCenter, Vector2.zero, new Vector2(size * 0.84f, size * 0.84f));
    }

    private static void CreateFooter(Transform parent, string text)
    {
        CreateText(parent, "FooterHint", text, 23, TextAnchor.MiddleCenter, new Vector2(740f, -1010f), new Vector2(520f, 42f), Color.white);
    }

    private static Text CreateText(Transform parent, string name, string value, int size, TextAnchor alignment, Vector2 anchoredPosition, Vector2 dimensions, Color color)
    {
        RectTransform rect = CreateRect(parent, name);
        AnchorRect(rect, alignment, anchoredPosition, dimensions);
        Text text = rect.gameObject.AddComponent<Text>();
        text.text = value;
        text.font = uiFont;
        text.fontSize = size;
        text.fontStyle = size >= 18 ? FontStyle.Bold : FontStyle.Normal;
        text.alignment = alignment;
        text.color = color;
        text.horizontalOverflow = HorizontalWrapMode.Wrap;
        text.verticalOverflow = VerticalWrapMode.Overflow;
        Shadow shadow = rect.gameObject.AddComponent<Shadow>();
        shadow.effectColor = new Color(0f, 0f, 0f, 0.72f);
        shadow.effectDistance = new Vector2(1.2f, -1.2f);
        return text;
    }

    private static void StretchRect(RectTransform rect, Vector2 anchorMin, Vector2 anchorMax, Vector2 offsetMin, Vector2 offsetMax)
    {
        rect.anchorMin = anchorMin;
        rect.anchorMax = anchorMax;
        rect.offsetMin = offsetMin;
        rect.offsetMax = offsetMax;
        rect.pivot = new Vector2(0.5f, 0.5f);
    }

    private static void AnchorRect(RectTransform rect, TextAnchor anchor, Vector2 anchoredPosition, Vector2 size)
    {
        Vector2 anchorVector = AlignmentToAnchor(anchor);
        rect.anchorMin = anchorVector;
        rect.anchorMax = anchorVector;
        rect.pivot = AnchorToPivot(anchor);
        rect.anchoredPosition = anchoredPosition;
        rect.sizeDelta = size;
    }

    private static Vector2 AlignmentToAnchor(TextAnchor anchor)
    {
        switch (anchor)
        {
            case TextAnchor.UpperLeft:
            case TextAnchor.MiddleLeft:
            case TextAnchor.LowerLeft:
                return new Vector2(0f, 1f);
            case TextAnchor.UpperRight:
            case TextAnchor.MiddleRight:
            case TextAnchor.LowerRight:
                return new Vector2(1f, 1f);
            case TextAnchor.MiddleCenter:
                return new Vector2(0.5f, 0.5f);
            case TextAnchor.LowerCenter:
                return new Vector2(0.5f, 0f);
            default:
                return new Vector2(0.5f, 1f);
        }
    }

    private static Vector2 AnchorToPivot(TextAnchor anchor)
    {
        switch (anchor)
        {
            case TextAnchor.UpperLeft:
                return new Vector2(0f, 1f);
            case TextAnchor.UpperCenter:
                return new Vector2(0.5f, 1f);
            case TextAnchor.UpperRight:
                return new Vector2(1f, 1f);
            case TextAnchor.MiddleLeft:
                return new Vector2(0f, 0.5f);
            case TextAnchor.MiddleRight:
                return new Vector2(1f, 0.5f);
            case TextAnchor.LowerLeft:
                return new Vector2(0f, 0f);
            case TextAnchor.LowerCenter:
                return new Vector2(0.5f, 0f);
            case TextAnchor.LowerRight:
                return new Vector2(1f, 0f);
            default:
                return new Vector2(0.5f, 0.5f);
        }
    }

    private static void SetPrivateField(object instance, string fieldName, object value)
    {
        FieldInfo field = instance.GetType().GetField(fieldName, BindingFlags.Instance | BindingFlags.NonPublic);
        if (field != null)
        {
            field.SetValue(instance, value);
            EditorUtility.SetDirty(instance as Object);
        }
    }
}
