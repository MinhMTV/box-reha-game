using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;

public static class DigitalDojoReferenceImport
{
    public static void Run()
    {
        DigitalDojoAssetIntegration.RunMounted();
        const string art="Assets/Art/DigitalDojo/";
        foreach(string key in new[]{"MatteBlack","MetalDark","Padding"})
        {
            string path=art+"Textures/M_DD_"+key+"_Normal.png";
            var normal=(TextureImporter)AssetImporter.GetAtPath(path);normal.textureType=TextureImporterType.NormalMap;normal.maxTextureSize=512;normal.SaveAndReimport();
            var targetMaterial=AssetDatabase.LoadAssetAtPath<Material>(art+"Materials/M_DD_"+key+".mat");
            targetMaterial.EnableKeyword("_NORMALMAP");targetMaterial.SetTexture("_BumpMap",AssetDatabase.LoadAssetAtPath<Texture2D>(path));targetMaterial.SetFloat("_BumpScale",.35f);EditorUtility.SetDirty(targetMaterial);
        }
        string texPath=art+"Textures/DojoRoomBaked.png";
        var ti=(TextureImporter)AssetImporter.GetAtPath(texPath);
        ti.maxTextureSize=4096;ti.mipmapEnabled=true;ti.sRGBTexture=true;ti.textureCompression=TextureImporterCompression.Compressed;
        var android=ti.GetPlatformTextureSettings("Android");android.overridden=true;android.maxTextureSize=4096;android.format=TextureImporterFormat.ASTC_6x6;ti.SetPlatformTextureSettings(android);ti.SaveAndReimport();
        string materialPath=art+"Materials/M_DD_RoomBaked.mat";
        var material=AssetDatabase.LoadAssetAtPath<Material>(materialPath);
        if(material==null){material=new Material(Shader.Find("Unlit/Texture"));AssetDatabase.CreateAsset(material,materialPath);}
        material.mainTexture=AssetDatabase.LoadAssetAtPath<Texture2D>(texPath);EditorUtility.SetDirty(material);
        var importer=(ModelImporter)AssetImporter.GetAtPath(art+"Models/ReferenceRoom.fbx");
        importer.importCameras=false;importer.importLights=false;importer.importAnimation=false;importer.SaveAndReimport();
        var root=new GameObject("DojoRoom");
        var model=(GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>(art+"Models/ReferenceRoom.fbx"));
        model.transform.SetParent(root.transform,false);
        // Same meter/axis conversion as the authored targets. Scale the bay layout to the existing travel envelope.
        model.transform.localRotation=Quaternion.Euler(0,180,0)*model.transform.localRotation;
        var geometry=new GameObject("GameplayRoomEnvelope");geometry.transform.SetParent(root.transform,false);
        model.transform.SetParent(geometry.transform,false);
        geometry.transform.localScale=new Vector3(1.70f,1.8f,4f);
        geometry.transform.localPosition=new Vector3(0,-.60f,9f);
        foreach(var r in root.GetComponentsInChildren<Renderer>()){r.sharedMaterial=material;r.shadowCastingMode=UnityEngine.Rendering.ShadowCastingMode.Off;}
        PrefabUtility.SaveAsPrefabAsset(root,"Assets/Resources/DigitalDojo/DojoRoom.prefab");Object.DestroyImmediate(root);
        var scene=EditorSceneManager.OpenScene("Assets/Scenes/MainMenu.unity");
        var old=GameObject.Find("DigitalDojoAuthoredRoom");if(old!=null)Object.DestroyImmediate(old);
        var room=(GameObject)PrefabUtility.InstantiatePrefab(AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Resources/DigitalDojo/DojoRoom.prefab"));room.name="DigitalDojoAuthoredRoom";
        EditorSceneManager.SaveScene(scene);AssetDatabase.SaveAssets();
        Debug.Log("REFERENCE_UNITY_IMPORT_COMPLETE");
    }
}
