using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Adds the Digital Dojo atmosphere to the playable Game scene at runtime.
/// Keeps gameplay systems untouched while providing warm dojo atmosphere.
/// </summary>
public class DigitalDojoRuntimeDressing : MonoBehaviour
{
    private const string RootName = "DigitalDojoRuntimeDressing";

    private Material wallMaterial;
    private Material woodMaterial;
    private Material redLightMaterial;
    private Material blueLightMaterial;
    private Material warmLightMaterial;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    private static void InstallForCurrentScene()
    {
        TryCreate(SceneManager.GetActiveScene());
        SceneManager.sceneLoaded -= OnSceneLoaded;
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private static void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        TryCreate(scene);
    }

    private static void TryCreate(Scene scene)
    {
        if (!scene.isLoaded || scene.name != "Game")
        {
            return;
        }

        if (GameObject.Find(RootName) != null)
        {
            return;
        }

        GameObject root = new GameObject(RootName);
        root.AddComponent<DigitalDojoRuntimeDressing>().Build();
    }

    private void Build()
    {
        RemoveLegacySceneObjects();

        wallMaterial = CreateMaterial("Runtime_Dojo_Wall", new Color(0.115f, 0.095f, 0.075f), 0f);
        woodMaterial = CreateMaterial("Runtime_Dojo_Wood", new Color(0.105f, 0.060f, 0.035f), 0f);
        redLightMaterial = CreateMaterial("Runtime_Dojo_RedLight", new Color(1f, 0.16f, 0.12f), 1.85f);
        blueLightMaterial = CreateMaterial("Runtime_Dojo_BlueLight", new Color(0.16f, 0.58f, 1f), 1.75f);
        warmLightMaterial = CreateMaterial("Runtime_Dojo_WarmLight", new Color(1f, 0.62f, 0.36f), 1.35f);

        GameObject authoredRoom = Resources.Load<GameObject>("DigitalDojo/DojoRoom");
        if (authoredRoom != null)
        {
            var room=Instantiate(authoredRoom, transform);
            StaticBatchingUtility.Combine(room);
        }
        else BuildRoomShell();
        BuildLaneLighting();
        BuildCameraPolish();
    }

    private static void RemoveLegacySceneObjects()
    {
        string[] legacyNames =
        {
            "Guide_Left",
            "Guide_CenterHeavy",
            "Guide_Right",
            "PunchHitLine",
            "KickHitLine",
            "LeftLaneGuide",
            "RightLaneGuide",
            "HeavyGateTop",
            "HeavyGateBottom",
            "HeavyGateLeft",
            "HeavyGateRight"
        };

        foreach (string legacyName in legacyNames)
        {
            GameObject legacyObject = GameObject.Find(legacyName);
            if (legacyObject != null)
            {
                Destroy(legacyObject);
            }
        }
    }

    private void BuildRoomShell()
    {
        CreateCube("DojoFloor", new Vector3(0f, -0.64f, 13.2f), new Vector3(13.8f, 0.08f, 30f), woodMaterial);
        CreateCube("DojoBackWall", new Vector3(0f, 2.2f, 29.25f), new Vector3(13.8f, 5.6f, 0.2f), wallMaterial);
        CreateCube("DojoLeftWall", new Vector3(-6.9f, 2.2f, 13.8f), new Vector3(0.18f, 5.6f, 33.0f), wallMaterial);
        CreateCube("DojoRightWall", new Vector3(6.9f, 2.2f, 13.8f), new Vector3(0.18f, 5.6f, 33.0f), wallMaterial);
        CreateCube("DojoCeiling", new Vector3(0f, 4.85f, 13.2f), new Vector3(13.8f, 0.12f, 30f), woodMaterial);

        for (int i = 0; i < 7; i++)
        {
            float x = -5.4f + i * 1.8f;
            CreateCube("DojoBackPanel_" + i, new Vector3(x, 2.15f, 29.08f), new Vector3(1.2f, 3.6f, 0.08f), wallMaterial);
            CreateCube("DojoBackWarmLight_" + i, new Vector3(x, 4.1f, 28.94f), new Vector3(1.25f, 0.05f, 0.08f), warmLightMaterial);
            CreateCube("DojoBackLowerGlow_" + i, new Vector3(x, 0.58f, 28.92f), new Vector3(1.05f, 0.035f, 0.06f), warmLightMaterial);
        }

        CreateCylinder("DojoLogoOuter", new Vector3(0f, 3.08f, 28.88f), new Vector3(0.72f, 0.035f, 0.72f), wallMaterial);
        CreateCylinder("DojoLogoInner", new Vector3(0f, 3.08f, 28.82f), new Vector3(0.50f, 0.025f, 0.50f), woodMaterial);
        CreateCube("DojoLogoSlashA", new Vector3(-0.12f, 3.08f, 28.78f), new Vector3(0.055f, 0.62f, 0.045f), woodMaterial).transform.rotation = Quaternion.Euler(0f, 0f, -28f);
        CreateCube("DojoLogoSlashB", new Vector3(0.12f, 3.08f, 28.77f), new Vector3(0.055f, 0.62f, 0.045f), woodMaterial).transform.rotation = Quaternion.Euler(0f, 0f, 28f);

        for (int i = 0; i < 32; i++)
        {
            float z = -2f + i * 1.05f;
            CreateCube("DojoLeftSlat_" + i, new Vector3(-6.62f, 2.15f, z), new Vector3(0.06f, 4.1f, 0.08f), woodMaterial);
            CreateCube("DojoRightSlat_" + i, new Vector3(6.62f, 2.15f, z), new Vector3(0.06f, 4.1f, 0.08f), woodMaterial);
        }
    }

    private void BuildLaneLighting() { /* Logical lanes remain; the dojo floor supplies depth without rails. */ }

    private void BuildCameraPolish()
    {
        Camera camera = Camera.main;
        if (camera != null)
        {
            camera.transform.position = new Vector3(0f, 2.55f, -6.35f);
            camera.transform.LookAt(new Vector3(0f, 1.42f, 9.1f));
            camera.fieldOfView = 38f;
            camera.clearFlags = CameraClearFlags.SolidColor;
            camera.backgroundColor = new Color(0.010f, 0.008f, 0.006f, 1f);
        }

        Light key = null;
        foreach(var light in FindObjectsByType<Light>())
        {
            if(light.type==LightType.Directional)key=light;
            else if(light.name.StartsWith("AccentLight_"))light.enabled=false;
        }
        if (key != null)
        {
            key.color = new Color(1f, 0.9f, 0.79f, 1f);
            key.intensity = 1.5f;
            key.shadows = LightShadows.None; // Interior fill: the modular ceiling must not black out every target.
            key.transform.rotation = Quaternion.Euler(28f, -18f, 0f);
        }

        RenderSettings.ambientMode = UnityEngine.Rendering.AmbientMode.Flat;
        RenderSettings.ambientLight = new Color(0.38f, 0.35f, 0.32f, 1f);
    }

    private GameObject CreateCube(string name, Vector3 position, Vector3 scale, Material material)
    {
        GameObject cube = VisualPrimitive.Create(PrimitiveType.Cube);
        cube.name = name;
        cube.transform.SetParent(transform, false);
        cube.transform.position = position;
        cube.transform.localScale = scale;

        Renderer renderer = cube.GetComponent<Renderer>();
        if (renderer != null)
        {
            renderer.sharedMaterial = material;
        }

        Collider collider = cube.GetComponent<Collider>();
        if (collider != null)
        {
            Destroy(collider);
        }

        return cube;
    }

    private GameObject CreateCylinder(string name, Vector3 position, Vector3 scale, Material material)
    {
        GameObject cylinder = VisualPrimitive.Create(PrimitiveType.Cylinder);
        cylinder.name = name;
        cylinder.transform.SetParent(transform, false);
        cylinder.transform.position = position;
        cylinder.transform.rotation = Quaternion.Euler(90f, 0f, 0f);
        cylinder.transform.localScale = scale;

        Renderer renderer = cylinder.GetComponent<Renderer>();
        if (renderer != null)
        {
            renderer.sharedMaterial = material;
        }

        Collider collider = cylinder.GetComponent<Collider>();
        if (collider != null)
        {
            Destroy(collider);
        }

        return cylinder;
    }

    private static Material CreateMaterial(string name, Color color, float emission)
    {
        Material material = new Material(GetCompatibleLitShader());
        material.name = name;
        material.color = color;
        SetColorIfPresent(material, "_BaseColor", color);
        SetColorIfPresent(material, "_Color", color);
        if (emission > 0f)
        {
            material.EnableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", color * emission);
        }
        return material;
    }

    private static Shader GetCompatibleLitShader()
    {
        return Shader.Find("Standard")
               ?? Shader.Find("Sprites/Default");
    }

    void OnDestroy()
    {
        foreach (Material material in new[] { wallMaterial, woodMaterial, redLightMaterial, blueLightMaterial, warmLightMaterial })
            if (material != null) Destroy(material);
    }

    private static void SetColorIfPresent(Material material, string propertyName, Color color)
    {
        if (material.HasProperty(propertyName))
        {
            material.SetColor(propertyName, color);
        }
    }
}
