using System;
using System.IO;
using System.Reflection;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/// <summary>Opt-in, real Play Mode captures. Uses an isolated QA profile, no hardware claims.</summary>
[InitializeOnLoad]
public static class DigitalDojoCapture
{
    const string Key = "DigitalDojoCapture.Active";
    static double next;
    static int step;
    static readonly string[] Pages = { "ShowHome", "StartLevelMode", "ShowCalibration", "ShowStatistics", "ShowPlayerProfile", "ShowSettings", "ShowSensorSetup" };
    static DigitalDojoCapture()
    {
        if (SessionState.GetBool(Key, false)) EditorApplication.update += Tick;
    }
    public static void Run()
    {
        Environment.SetEnvironmentVariable("DOJO_VISUAL_QA", "1");
        SessionState.SetBool(Key, true);
        SessionState.SetInt("DD.CaptureStep", 0);
        EditorSceneManager.OpenScene("Assets/Scenes/MainMenu.unity");
        EditorApplication.isPlaying = true;
    }
    static void Tick()
    {
        if (!EditorApplication.isPlaying || EditorApplication.isCompiling || EditorApplication.timeSinceStartup < next) return;
        next = EditorApplication.timeSinceStartup + 1.5;
        try
        {
            step = SessionState.GetInt("DD.CaptureStep", 0);
            if (step < Pages.Length * 2)
            {
                var menu = UnityEngine.Object.FindFirstObjectByType<DigitalDojoMenuController>();
                if (menu == null) return;
                if (step % 2 == 0) typeof(DigitalDojoMenuController).GetMethod(Pages[step / 2]).Invoke(menu, null);
                else Capture(Pages[step / 2].Replace("Show", ""));
            }
            else if (step == Pages.Length * 2) SceneManager.LoadScene("Game");
            else if (step == Pages.Length * 2 + 1)
            {
                GameManager.EnsureInstance().CurrentState = GameState.Paused;
                var spawner = UnityEngine.Object.FindFirstObjectByType<TargetSpawner>();
                spawner.StopSpawning();
                foreach (var target in UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None)) UnityEngine.Object.Destroy(target.gameObject);
                var create = typeof(TargetSpawner).GetMethod("CreateTargetObject", BindingFlags.Instance | BindingFlags.NonPublic);
                var types = new[] { TargetType.Punch, TargetType.Kick, TargetType.ToughPunch };
                var positions = new[] { new Vector3(-3, 2.1f, 7), new Vector3(3, 0.45f, 7), new Vector3(0, 2.1f, 11) };
                for (int i = 0; i < types.Length; i++)
                {
                    var go = (GameObject)create.Invoke(spawner, new object[] { positions[i], types[i] });
                    var t = go.GetComponent<TargetObject>(); t.Type = types[i]; t.Lane = i == 0 ? LaneType.Left : i == 1 ? LaneType.Right : LaneType.Center;
                    t.VertPosition = i == 1 ? VerticalPosition.Low : VerticalPosition.High; t.MaxHits = i == 2 ? 8 : 1;
                    go.GetComponent<TargetMover>().enabled = false;
                }
            }
            else if (step == Pages.Length * 2 + 2) Capture("Gameplay-Targets-HUD");
            else if (step == Pages.Length * 2 + 3) SceneManager.LoadScene("Results");
            else if (step == Pages.Length * 2 + 4) Capture("Results-Empty");
            else
            {
                SessionState.SetBool(Key, false);
                EditorApplication.update -= Tick;
                Debug.Log("DIGITAL_DOJO_CAPTURE_COMPLETE");
                EditorApplication.Exit(0);
                return;
            }
            SessionState.SetInt("DD.CaptureStep", step + 1);
        }
        catch (Exception ex)
        {
            Debug.LogException(ex); SessionState.SetBool(Key, false); EditorApplication.Exit(1);
        }
    }
    static void Capture(string label)
    {
        string pass = Environment.GetEnvironmentVariable("DOJO_CAPTURE_PASS") ?? "Before";
        string directory = Path.GetFullPath("DesignReferences/CurrentBuild/" + pass);
        Directory.CreateDirectory(directory);
        foreach (var size in new[] { new Vector2Int(1920,1080), new Vector2Int(1280,720), new Vector2Int(2400,1080), new Vector2Int(1024,768) })
            Render(label, directory, size.x, size.y);
    }
    static void Render(string label, string directory, int width, int height)
    {
        Camera camera = Camera.main;
        if (camera == null) camera = new GameObject("QA Camera", typeof(Camera)).GetComponent<Camera>();
        var target = new RenderTexture(width, height, 24);
        var canvases = UnityEngine.Object.FindObjectsByType<Canvas>(FindObjectsSortMode.None);
        var oldModes = new RenderMode[canvases.Length];
        var oldCameras = new Camera[canvases.Length];
        var oldDistances = new float[canvases.Length];
        var oldTarget = camera.targetTexture;
        var oldActive = RenderTexture.active;
        float oldAspect = camera.aspect;
        Texture2D texture = null;
        try
        {
            camera.targetTexture = target; camera.aspect = (float)width / height;
            for (int i = 0; i < canvases.Length; i++)
            {
                var canvas = canvases[i]; oldModes[i] = canvas.renderMode; oldCameras[i] = canvas.worldCamera; oldDistances[i] = canvas.planeDistance;
                if (!canvas.isRootCanvas || canvas.renderMode != RenderMode.ScreenSpaceOverlay) continue;
                canvas.renderMode = RenderMode.ScreenSpaceCamera; canvas.worldCamera = camera; canvas.planeDistance = 0.5f;
                var scaler = canvas.GetComponent<CanvasScaler>();
                if (scaler != null) { scaler.enabled = false; canvas.scaleFactor = Mathf.Min(width / 1600f, height / 900f); }
            }
            Canvas.ForceUpdateCanvases(); camera.Render(); RenderTexture.active = target;
            texture = new Texture2D(width,height,TextureFormat.RGB24,false);
            texture.ReadPixels(new Rect(0,0,width,height),0,0); texture.Apply();
            File.WriteAllBytes(Path.Combine(directory, label + "-" + width + "x" + height + ".png"), texture.EncodeToPNG());
        }
        finally
        {
            for(int i=0;i<canvases.Length;i++)
            {
                canvases[i].renderMode=oldModes[i]; canvases[i].worldCamera=oldCameras[i]; canvases[i].planeDistance=oldDistances[i];
                var scaler=canvases[i].GetComponent<CanvasScaler>(); if(scaler!=null) scaler.enabled=true;
            }
            camera.targetTexture=oldTarget; camera.aspect=oldAspect; RenderTexture.active=oldActive;
            if(texture!=null) UnityEngine.Object.DestroyImmediate(texture);
            target.Release(); UnityEngine.Object.DestroyImmediate(target);
        }
    }
}
