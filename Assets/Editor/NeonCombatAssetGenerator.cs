using UnityEditor;
using UnityEngine;

public static class NeonCombatAssetGenerator
{
    private const string RootFolder = "Assets/Art/Generated/NeonCombat";
    private const string MaterialFolder = RootFolder + "/Materials";
    private const string PrefabFolder = RootFolder + "/Prefabs";

    [MenuItem("BoxReha/Generate Neon Combat Assets")]
    public static void GenerateAll()
    {
        EnsureFolders();

        Material darkMetal = CreateMaterial("M_DarkGunmetal", new Color(0.015f, 0.022f, 0.035f, 1f), Color.black, 0.55f, 0.88f);
        Material rubberBlack = CreateMaterial("M_BlackRubber", new Color(0.018f, 0.016f, 0.017f, 1f), Color.black, 0.08f, 0.55f);
        Material neonBlue = CreateMaterial("M_NeonBlue", new Color(0.02f, 0.42f, 1f, 1f), new Color(0.02f, 0.78f, 1f, 1f) * 4.2f, 0.1f, 0.95f);
        Material neonRed = CreateMaterial("M_NeonRed", new Color(1f, 0.04f, 0.03f, 1f), new Color(1f, 0.05f, 0.02f, 1f) * 4.6f, 0.1f, 0.95f);
        Material neonMagenta = CreateMaterial("M_NeonMagentaHitLine", new Color(0.9f, 0.1f, 1f, 1f), new Color(1f, 0.1f, 1f, 1f) * 5f, 0.05f, 1f);
        Material neonYellow = CreateMaterial("M_NeonYellowCore", new Color(1f, 0.7f, 0.08f, 1f), new Color(1f, 0.55f, 0.04f, 1f) * 3.8f, 0.1f, 0.9f);
        Material whiteGlow = CreateMaterial("M_WhiteIconGlow", Color.white, Color.white * 2.2f, 0f, 0.8f);
        Material glassPanel = CreateMaterial("M_HologlassPanel", new Color(0.02f, 0.08f, 0.12f, 0.62f), new Color(0.02f, 0.35f, 0.55f, 1f) * 1.5f, 0f, 0.65f);

        CreatePunchTargetPrefab(darkMetal, rubberBlack, neonRed, whiteGlow);
        CreateKickPadPrefab(darkMetal, rubberBlack, neonBlue, whiteGlow);
        CreateHeavyCorePrefab(darkMetal, rubberBlack, neonYellow, whiteGlow);
        CreateRunwaySegmentPrefab(darkMetal, neonBlue, neonRed, neonYellow);
        CreateWallGatePrefab(darkMetal, neonBlue, neonRed);
        CreateHitLinePrefab(neonMagenta);
        CreateHudPanelPrefab(glassPanel, neonBlue, neonMagenta);

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        Object folder = AssetDatabase.LoadAssetAtPath<Object>(RootFolder);
        if (folder != null)
        {
            Selection.activeObject = folder;
            EditorGUIUtility.PingObject(folder);
        }

        Debug.Log("Generated Neon Combat asset pack in " + RootFolder + ". Open Project window: Assets > Art > Generated > NeonCombat");
    }

    private static void EnsureFolders()
    {
        EnsureFolder("Assets/Art");
        EnsureFolder("Assets/Art/Generated");
        EnsureFolder(RootFolder);
        EnsureFolder(MaterialFolder);
        EnsureFolder(PrefabFolder);
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

    private static Material CreateMaterial(string name, Color baseColor, Color emissionColor, float metallic, float smoothness)
    {
        string path = MaterialFolder + "/" + name + ".mat";
        Material material = AssetDatabase.LoadAssetAtPath<Material>(path);
        if (material == null)
        {
            material = new Material(Shader.Find("Standard"));
            AssetDatabase.CreateAsset(material, path);
        }

        material.color = baseColor;
        material.SetFloat("_Metallic", metallic);
        material.SetFloat("_Glossiness", smoothness);
        if (emissionColor.maxColorComponent > 0f)
        {
            material.EnableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", emissionColor);
        }
        else
        {
            material.DisableKeyword("_EMISSION");
            material.SetColor("_EmissionColor", Color.black);
        }

        EditorUtility.SetDirty(material);
        return material;
    }

    private static void CreatePunchTargetPrefab(Material darkMetal, Material rubberBlack, Material neonRed, Material whiteGlow)
    {
        GameObject root = new GameObject("PF_PunchTarget_NeonRed");
        AddDisc(root.transform, "BackPlate", 0.92f, 0.18f, new Vector3(0f, 0f, 0.08f), darkMetal);
        AddDisc(root.transform, "OuterRedRing", 0.82f, 0.08f, Vector3.zero, neonRed);
        AddDisc(root.transform, "InnerPad", 0.58f, 0.09f, new Vector3(0f, 0f, -0.05f), rubberBlack);
        AddDisc(root.transform, "CoreGlow", 0.34f, 0.05f, new Vector3(0f, 0f, -0.11f), neonRed);

        AddBox(root.transform, "FistPalm", new Vector3(0f, -0.03f, -0.18f), new Vector3(0.36f, 0.24f, 0.06f), whiteGlow);
        for (int i = 0; i < 4; i++)
        {
            AddBox(root.transform, "FistKnuckle_" + i, new Vector3(-0.18f + i * 0.12f, 0.13f, -0.19f), new Vector3(0.09f, 0.11f, 0.06f), whiteGlow);
        }
        AddBox(root.transform, "FistThumb", new Vector3(0.25f, -0.04f, -0.19f), new Vector3(0.08f, 0.22f, 0.06f), whiteGlow, Quaternion.Euler(0f, 0f, -28f));

        for (int i = 0; i < 8; i++)
        {
            float angle = i * 45f;
            Vector3 pos = Quaternion.Euler(0f, 0f, angle) * new Vector3(0f, 0.98f, -0.02f);
            AddBox(root.transform, "RedTick_" + i, pos, new Vector3(0.045f, 0.20f, 0.045f), neonRed, Quaternion.Euler(0f, 0f, angle));
        }

        SavePrefab(root, "PF_PunchTarget_NeonRed");
    }

    private static void CreateKickPadPrefab(Material darkMetal, Material rubberBlack, Material neonBlue, Material whiteGlow)
    {
        GameObject root = new GameObject("PF_KickPad_NeonBlue");
        AddDisc(root.transform, "MetalBase", 0.78f, 0.16f, new Vector3(0f, 0f, 0.08f), darkMetal, new Vector3(1.35f, 1f, 0.7f));
        AddDisc(root.transform, "BlueRim", 0.69f, 0.08f, Vector3.zero, neonBlue, new Vector3(1.32f, 1f, 0.64f));
        AddBox(root.transform, "RubberFootPad", new Vector3(0f, -0.05f, -0.08f), new Vector3(0.95f, 0.40f, 0.08f), rubberBlack);
        AddBox(root.transform, "SoleGlow", new Vector3(0f, -0.30f, -0.14f), new Vector3(1.05f, 0.055f, 0.06f), neonBlue);

        AddBox(root.transform, "FootSole", new Vector3(0f, -0.02f, -0.18f), new Vector3(0.33f, 0.48f, 0.06f), whiteGlow);
        for (int i = 0; i < 5; i++)
        {
            AddDisc(root.transform, "FootToe_" + i, 0.052f, 0.025f, new Vector3(-0.18f + i * 0.09f, 0.31f, -0.20f), whiteGlow);
        }

        SavePrefab(root, "PF_KickPad_NeonBlue");
    }

    private static void CreateHeavyCorePrefab(Material darkMetal, Material rubberBlack, Material neonYellow, Material whiteGlow)
    {
        GameObject root = new GameObject("PF_HeavyCore_GoldBlocker");
        AddDisc(root.transform, "ArmorBack", 1.24f, 0.24f, new Vector3(0f, 0f, 0.12f), darkMetal);
        AddDisc(root.transform, "GoldOuterRing", 1.06f, 0.12f, Vector3.zero, neonYellow);
        AddDisc(root.transform, "BlackCore", 0.72f, 0.12f, new Vector3(0f, 0f, -0.07f), rubberBlack);
        AddDisc(root.transform, "GoldInnerRing", 0.50f, 0.08f, new Vector3(0f, 0f, -0.14f), neonYellow);
        AddDisc(root.transform, "ShieldCore", 0.28f, 0.05f, new Vector3(0f, 0f, -0.20f), whiteGlow);

        for (int i = 0; i < 12; i++)
        {
            float angle = i * 30f;
            Vector3 pos = Quaternion.Euler(0f, 0f, angle) * new Vector3(0f, 1.18f, -0.02f);
            AddBox(root.transform, "ArmorTooth_" + i, pos, new Vector3(0.16f, 0.34f, 0.12f), i % 2 == 0 ? darkMetal : neonYellow, Quaternion.Euler(0f, 0f, angle));
        }

        AddBox(root.transform, "HealthBarBack", new Vector3(0f, 1.62f, -0.03f), new Vector3(1.7f, 0.08f, 0.08f), rubberBlack);
        AddBox(root.transform, "HealthBarGold", new Vector3(0f, 1.62f, -0.09f), new Vector3(1.55f, 0.045f, 0.045f), neonYellow);
        SavePrefab(root, "PF_HeavyCore_GoldBlocker");
    }

    private static void CreateRunwaySegmentPrefab(Material darkMetal, Material neonBlue, Material neonRed, Material neonYellow)
    {
        GameObject root = new GameObject("PF_RunwaySegment_TriLane");
        AddBox(root.transform, "GlossyFloor", Vector3.zero, new Vector3(8.2f, 0.12f, 10f), darkMetal);
        AddBox(root.transform, "LeftBlueRail", new Vector3(-3.1f, 0.10f, 0f), new Vector3(0.08f, 0.08f, 9.6f), neonBlue);
        AddBox(root.transform, "RightRedRail", new Vector3(3.1f, 0.10f, 0f), new Vector3(0.08f, 0.08f, 9.6f), neonRed);
        AddBox(root.transform, "CenterGoldRailLeft", new Vector3(-0.55f, 0.12f, 0f), new Vector3(0.045f, 0.055f, 9.4f), neonYellow);
        AddBox(root.transform, "CenterGoldRailRight", new Vector3(0.55f, 0.12f, 0f), new Vector3(0.045f, 0.055f, 9.4f), neonYellow);

        for (int i = 0; i < 6; i++)
        {
            float z = -3.5f + i * 1.35f;
            AddBox(root.transform, "CenterChevronA_" + i, new Vector3(-0.16f, 0.16f, z), new Vector3(0.06f, 0.045f, 0.52f), neonYellow, Quaternion.Euler(0f, 32f, 0f));
            AddBox(root.transform, "CenterChevronB_" + i, new Vector3(0.16f, 0.16f, z), new Vector3(0.06f, 0.045f, 0.52f), neonYellow, Quaternion.Euler(0f, -32f, 0f));
        }

        SavePrefab(root, "PF_RunwaySegment_TriLane");
    }

    private static void CreateWallGatePrefab(Material darkMetal, Material neonBlue, Material neonRed)
    {
        GameObject root = new GameObject("PF_SciFiWallGate_BlueRed");
        AddBox(root.transform, "LeftColumn", new Vector3(-4.4f, 1.65f, 0f), new Vector3(0.45f, 3.3f, 0.4f), darkMetal);
        AddBox(root.transform, "RightColumn", new Vector3(4.4f, 1.65f, 0f), new Vector3(0.45f, 3.3f, 0.4f), darkMetal);
        AddBox(root.transform, "TopBeam", new Vector3(0f, 3.35f, 0f), new Vector3(8.8f, 0.38f, 0.4f), darkMetal);
        AddBox(root.transform, "BackPanel", new Vector3(0f, 1.65f, 0.24f), new Vector3(4.0f, 2.3f, 0.16f), darkMetal);

        AddBox(root.transform, "LeftBlueNeon", new Vector3(-3.8f, 1.75f, -0.25f), new Vector3(0.08f, 2.7f, 0.08f), neonBlue, Quaternion.Euler(0f, 0f, -18f));
        AddBox(root.transform, "RightBlueNeon", new Vector3(3.8f, 1.75f, -0.25f), new Vector3(0.08f, 2.7f, 0.08f), neonBlue, Quaternion.Euler(0f, 0f, 18f));
        AddBox(root.transform, "TopBlueNeon", new Vector3(0f, 3.02f, -0.25f), new Vector3(5.2f, 0.08f, 0.08f), neonBlue);
        AddBox(root.transform, "RedSidePulseLeft", new Vector3(-1.65f, 1.6f, -0.3f), new Vector3(0.07f, 1.8f, 0.07f), neonRed);
        AddBox(root.transform, "RedSidePulseRight", new Vector3(1.65f, 1.6f, -0.3f), new Vector3(0.07f, 1.8f, 0.07f), neonRed);
        SavePrefab(root, "PF_SciFiWallGate_BlueRed");
    }

    private static void CreateHitLinePrefab(Material neonMagenta)
    {
        GameObject root = new GameObject("PF_HitLine_MagentaBeam");
        AddBox(root.transform, "HitBeam", Vector3.zero, new Vector3(8.8f, 0.045f, 0.06f), neonMagenta);
        AddDisc(root.transform, "CenterBurst", 0.24f, 0.03f, new Vector3(0f, 0f, -0.02f), neonMagenta);
        SavePrefab(root, "PF_HitLine_MagentaBeam");
    }

    private static void CreateHudPanelPrefab(Material glassPanel, Material neonBlue, Material neonMagenta)
    {
        GameObject root = new GameObject("PF_HUDPanel_Hologlass");
        AddBox(root.transform, "GlassPanel", Vector3.zero, new Vector3(2.8f, 1.2f, 0.04f), glassPanel);
        AddBox(root.transform, "TopBorder", new Vector3(0f, 0.62f, -0.04f), new Vector3(2.8f, 0.04f, 0.04f), neonBlue);
        AddBox(root.transform, "BottomBorder", new Vector3(0f, -0.62f, -0.04f), new Vector3(2.8f, 0.04f, 0.04f), neonBlue);
        AddBox(root.transform, "AccentSlashLeft", new Vector3(-1.18f, 0.38f, -0.06f), new Vector3(0.04f, 0.48f, 0.04f), neonMagenta, Quaternion.Euler(0f, 0f, -28f));
        AddBox(root.transform, "AccentSlashRight", new Vector3(1.18f, -0.38f, -0.06f), new Vector3(0.04f, 0.48f, 0.04f), neonMagenta, Quaternion.Euler(0f, 0f, -28f));
        SavePrefab(root, "PF_HUDPanel_Hologlass");
    }

    private static GameObject AddDisc(Transform parent, string name, float radius, float depth, Vector3 localPosition, Material material)
    {
        return AddDisc(parent, name, radius, depth, localPosition, material, Vector3.one);
    }

    private static GameObject AddDisc(Transform parent, string name, float radius, float depth, Vector3 localPosition, Material material, Vector3 nonUniformScale)
    {
        GameObject disc = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        disc.name = name;
        disc.transform.SetParent(parent, false);
        disc.transform.localPosition = localPosition;
        disc.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        disc.transform.localScale = new Vector3(radius * nonUniformScale.x, depth * nonUniformScale.y, radius * nonUniformScale.z);
        AssignMaterialAndRemoveCollider(disc, material);
        return disc;
    }

    private static GameObject AddBox(Transform parent, string name, Vector3 localPosition, Vector3 localScale, Material material)
    {
        return AddBox(parent, name, localPosition, localScale, material, Quaternion.identity);
    }

    private static GameObject AddBox(Transform parent, string name, Vector3 localPosition, Vector3 localScale, Material material, Quaternion localRotation)
    {
        GameObject box = GameObject.CreatePrimitive(PrimitiveType.Cube);
        box.name = name;
        box.transform.SetParent(parent, false);
        box.transform.localPosition = localPosition;
        box.transform.localRotation = localRotation;
        box.transform.localScale = localScale;
        AssignMaterialAndRemoveCollider(box, material);
        return box;
    }

    private static void AssignMaterialAndRemoveCollider(GameObject obj, Material material)
    {
        Collider collider = obj.GetComponent<Collider>();
        if (collider != null)
        {
            Object.DestroyImmediate(collider);
        }

        Renderer renderer = obj.GetComponent<Renderer>();
        if (renderer != null)
        {
            renderer.sharedMaterial = material;
        }
    }

    private static void SavePrefab(GameObject root, string name)
    {
        string path = PrefabFolder + "/" + name + ".prefab";
        PrefabUtility.SaveAsPrefabAsset(root, path);
        Object.DestroyImmediate(root);
    }
}
