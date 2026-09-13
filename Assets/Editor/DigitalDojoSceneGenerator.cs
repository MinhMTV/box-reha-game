using UnityEditor;
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
        // The data-backed runtime hub replaces the earlier concept-only UI.
        canvas.gameObject.AddComponent<DigitalDojoMenuController>();

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

}
