using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;

public static class DigitalDojoAssetIntegration
{
    const string Art = "Assets/Art/DigitalDojo/";
    const string ResourcesPath = "Assets/Resources/DigitalDojo/";
    static readonly Dictionary<string,Color> Colors = new Dictionary<string,Color> {
        {"MatteBlack",new Color(.026f,.029f,.032f)}, {"MetalDark",new Color(.09f,.10f,.115f)},
        {"Padding",new Color(.12f,.13f,.145f)}, {"White",new Color(.86f,.83f,.77f)},
        {"RedAccent",new Color(.65f,.045f,.028f)}, {"BlueAccent",new Color(.07f,.29f,.48f)},
        {"EmissiveRed",new Color(.95f,.12f,.075f)}, {"EmissiveBlue",new Color(.15f,.52f,.78f)},
        {"Wood_Dark",new Color(.16f,.082f,.037f)}, {"Concrete",new Color(.075f,.081f,.085f)},
        {"WarmLight",new Color(.9f,.63f,.34f)} };

    [MenuItem("BoxReha/Digital Dojo/Integrate Blender Kit")]
    public static void Run() => Integrate(false);
    public static void RunMounted() => Integrate(true);
    static void Integrate(bool mountedOnly)
    {
        Directory.CreateDirectory(Art+"Materials"); Directory.CreateDirectory(Art+"Prefabs");
        Directory.CreateDirectory(ResourcesPath); AssetDatabase.Refresh();
        if(AssetDatabase.LoadAssetAtPath<Font>(ResourcesPath+"DojoUI.ttf")==null)
            AssetDatabase.CopyAsset("Assets/Art/Generated/DigitalDojo/Fonts/Bahnschrift.ttf", ResourcesPath+"DojoUI.ttf");
        foreach(var item in Colors)
        {
            string path=Art+"Materials/M_DD_"+item.Key+".mat";
            var material=AssetDatabase.LoadAssetAtPath<Material>(path);
            if(material==null){ material=new Material(Shader.Find("Standard")); AssetDatabase.CreateAsset(material,path); }
            material.color=item.Value; material.SetFloat("_Glossiness",item.Key=="MetalDark"?.45f:.2f);
            material.SetFloat("_Metallic",item.Key=="MetalDark"?.55f:0);
            if(item.Key.StartsWith("Emissive")||item.Key=="WarmLight") {material.EnableKeyword("_EMISSION");material.SetColor("_EmissionColor",item.Value*.65f);}
            EditorUtility.SetDirty(material);
        }
        foreach(string path in Directory.GetFiles(Art+"Models","*.fbx"))
        {
            if(mountedOnly && !Path.GetFileName(path).StartsWith("Mount"))continue;
            var importer=(ModelImporter)AssetImporter.GetAtPath(path);
            importer.importCameras=false; importer.importLights=false; importer.importAnimation=false;
            importer.materialImportMode=ModelImporterMaterialImportMode.ImportStandard;
            importer.SaveAndReimport();
            var model=AssetDatabase.LoadAssetAtPath<GameObject>(path);
            var instance=new GameObject(Path.GetFileNameWithoutExtension(path));
            var imported=(GameObject)PrefabUtility.InstantiatePrefab(model);
            PrefabUtility.UnpackPrefabInstance(imported,PrefabUnpackMode.Completely,InteractionMode.AutomatedAction);
            imported.transform.SetParent(instance.transform, false);
            imported.name="Model"; // Preserve FBX's axis/unit conversion below an identity gameplay root.
            if(instance.name.EndsWith("Target")) imported.transform.localRotation = Quaternion.Euler(0,180,0) * imported.transform.localRotation;
            foreach(var renderer in instance.GetComponentsInChildren<Renderer>())
            {
                var materials=renderer.sharedMaterials;
                for(int i=0;i<materials.Length;i++)
                {
                    string key=materials[i] != null ? materials[i].name : "M_DD_MatteBlack";
                    var shared=AssetDatabase.LoadAssetAtPath<Material>(Art+"Materials/"+key+".mat");
                    materials[i]=shared ?? AssetDatabase.LoadAssetAtPath<Material>(Art+"Materials/M_DD_MatteBlack.mat");
                }
                renderer.sharedMaterials=materials; renderer.shadowCastingMode=UnityEngine.Rendering.ShadowCastingMode.Off;
            }
            if(instance.name.EndsWith("Target"))instance.AddComponent<DigitalDojoTargetVisual>();
            PrefabUtility.SaveAsPrefabAsset(instance,Art+"Prefabs/"+instance.name+".prefab");
            UnityEngine.Object.DestroyImmediate(instance);
        }
        foreach(string mount in new[]{"MountArm","MountPlate"})
        {
            string destination=ResourcesPath+mount+".prefab";
            var copy=UnityEngine.Object.Instantiate(AssetDatabase.LoadAssetAtPath<GameObject>(Art+"Prefabs/"+mount+".prefab"));
            PrefabUtility.SaveAsPrefabAsset(copy,destination);UnityEngine.Object.DestroyImmediate(copy);
        }
        if(!mountedOnly)BuildRoom();
        var scene=EditorSceneManager.OpenScene("Assets/Scenes/Game.unity");
        foreach(var spawner in UnityEngine.Object.FindObjectsByType<TargetSpawner>(FindObjectsSortMode.None))
        {
            var so=new SerializedObject(spawner);
            string[] fields={"punchVisualPrefab","kickVisualPrefab","toughVisualPrefab","heavyKickVisualPrefab"};
            string[] names={"MountedPunchTarget","MountedKickTarget","MountedHeavyTarget","MountedHeavyKickTarget"};
            for(int i=0;i<4;i++)so.FindProperty(fields[i]).objectReferenceValue=AssetDatabase.LoadAssetAtPath<GameObject>(Art+"Prefabs/"+names[i]+".prefab");
            foreach(string field in new[]{"spawnPointLeft","spawnPointRight"})
            {var point=(Transform)so.FindProperty(field).objectReferenceValue;var pos=point.position;pos.x=field=="spawnPointLeft"?-2.4f:2.4f;point.position=pos;}
            so.ApplyModifiedPropertiesWithoutUndo();
        }
        EditorSceneManager.SaveScene(scene);
        if(mountedOnly){AssetDatabase.SaveAssets();Debug.Log("DIGITAL_DOJO_INTEGRATION_COMPLETE");return;}
        scene=EditorSceneManager.OpenScene("Assets/Scenes/MainMenu.unity");
        foreach(var root in scene.GetRootGameObjects())
        {
            // Preserve UI and core components; replace only the existing room/preview geometry.
            if(root.GetComponent<Camera>()==null && root.GetComponent<Light>()==null && root.GetComponent<Canvas>()==null
                && root.GetComponent<UnityEngine.EventSystems.EventSystem>()==null && root.GetComponent<MeshRenderer>()!=null)
                UnityEngine.Object.DestroyImmediate(root);
        }
        var existing=GameObject.Find("DigitalDojoAuthoredRoom"); if(existing!=null)UnityEngine.Object.DestroyImmediate(existing);
        var room=(GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>(ResourcesPath+"DojoRoom.prefab"));
        room.name="DigitalDojoAuthoredRoom";
        var camera=Camera.main; if(camera!=null){camera.transform.position=new Vector3(1.5f,2.2f,-6);camera.transform.LookAt(new Vector3(0,1.8f,12));camera.fieldOfView=42;}
        RenderSettings.ambientLight=new Color(.28f,.25f,.22f);
        foreach(var light in UnityEngine.Object.FindObjectsByType<Light>(FindObjectsSortMode.None)){light.intensity=1.1f;light.color=new Color(1,.86f,.71f);}
        EditorSceneManager.SaveScene(scene);
        AssetDatabase.SaveAssets(); Debug.Log("DIGITAL_DOJO_INTEGRATION_COMPLETE");
    }
    static void BuildRoom()
    {
        var root=new GameObject("DojoRoom");
        for(int x=-3;x<=3;x++)for(int z=-5;z<16;z++)Module(root,"FloorPanel",new Vector3(x*2,-.6f,z*2),Quaternion.identity);
        for(int x=-3;x<=3;x++)Module(root,x%2==0?"WallPanel_A":"WoodSlatPanel",new Vector3(x*2,-.6f,29),Quaternion.identity);
        for(int z=-5;z<14;z+=2)
        {
            Module(root,"WallPanel_A",new Vector3(-7,-.6f,z*2),Quaternion.Euler(0,90,0));
            Module(root,"WallPanel_A",new Vector3(7,-.6f,z*2),Quaternion.Euler(0,-90,0));
            Module(root,"WoodSlatPanel",new Vector3(-6.9f,-.6f,z*2+2),Quaternion.Euler(0,90,0));
            Module(root,"WoodSlatPanel",new Vector3(6.9f,-.6f,z*2+2),Quaternion.Euler(0,-90,0));
            Module(root,"LightStripHousing",new Vector3(-6.65f,2.55f,z*2),Quaternion.Euler(0,90,0));
            Module(root,"LightStripHousing",new Vector3(6.65f,2.55f,z*2),Quaternion.Euler(0,-90,0));
        }
        Module(root,"TrainingFrame",new Vector3(0,-.6f,27.5f),Quaternion.identity);
        Module(root,"HeavyTarget",new Vector3(0,1.25f,27.3f),Quaternion.identity);
        var ceiling=GameObject.CreatePrimitive(PrimitiveType.Cube);ceiling.name="Ceiling";ceiling.transform.SetParent(root.transform);
        ceiling.transform.localPosition=new Vector3(0,4.85f,10);ceiling.transform.localScale=new Vector3(14.2f,.15f,42);
        ceiling.GetComponent<Renderer>().sharedMaterial=AssetDatabase.LoadAssetAtPath<Material>(Art+"Materials/M_DD_Concrete.mat");
        UnityEngine.Object.DestroyImmediate(ceiling.GetComponent<Collider>());
        // The background hero prop is a static room asset, not a live target.
        foreach(var visual in root.GetComponentsInChildren<DigitalDojoTargetVisual>())UnityEngine.Object.DestroyImmediate(visual);
        PrefabUtility.SaveAsPrefabAsset(root,ResourcesPath+"DojoRoom.prefab"); UnityEngine.Object.DestroyImmediate(root);
    }
    static void Module(GameObject root,string name,Vector3 position,Quaternion rotation)
    {
        var obj=(GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>(Art+"Prefabs/"+name+".prefab"));
        obj.transform.SetParent(root.transform);obj.transform.localPosition=position;obj.transform.localRotation=rotation;
        if(name=="WallPanel_A"||name=="WoodSlatPanel")obj.transform.localScale=new Vector3(1,1.8f,1);
        GameObjectUtility.SetStaticEditorFlags(obj,StaticEditorFlags.BatchingStatic);
    }
}
