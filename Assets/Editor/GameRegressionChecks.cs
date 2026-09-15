using System;
using System.Collections.Generic;
using System.IO;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEditor.Build.Reporting;
using UnityEngine;

/// <summary>Batch Editor checks; this is not a substitute for a rendered Play Mode walkthrough.</summary>
public static class GameRegressionChecks
{
    private static string ProjectRoot => Path.GetFullPath(Path.Combine(Application.dataPath, ".."));
    [Serializable] private class CandidateBuildSummary
    {
        public string scope = "DEVELOPMENT BUILD CANDIDATE ONLY / NOT STUDY-READY OR HARDWARE QUALIFIED";
        public string utc, unityVersion, result, outputPath, totalBytes;
        public int errors, warnings;
        public double durationSeconds;
    }
    [Serializable] private class Report
    {
        public string scope = "UNITY EDITOR CHECKS / NOT PHYSICAL HARDWARE VERIFICATION";
        public string utc, unityVersion;
        public int passed, failed;
        public List<string> checks = new List<string>();
    }
    private static Report report;

    public static void BuildStudyCandidate()
    {
        BuildCandidate(BuildTarget.StandaloneWindows64, "StudyCandidate", "DigitalDojo.exe", "unity-candidate-build.json");
    }

    public static void PrepareAndroidCandidate()
    {
        if (!Application.isBatchMode) throw new InvalidOperationException("Run in a dedicated Unity batch process.");
        if (!BuildPipeline.IsBuildTargetSupported(BuildTargetGroup.Android, BuildTarget.Android))
            throw new InvalidOperationException("Install Android Build Support for this project's exact Editor, including SDK/NDK and OpenJDK.");
        PlayerSettings.SetApplicationIdentifier(BuildTargetGroup.Android, "com.boxreha.digitaldojo");
        PlayerSettings.productName = "Digital Dojo";
        PlayerSettings.bundleVersion = "1.2";
        PlayerSettings.Android.bundleVersionCode = 3;
        PlayerSettings.Android.minSdkVersion = RequiredAndroidMinimum();
        PlayerSettings.Android.targetSdkVersion = (AndroidSdkVersions)36;
        PlayerSettings.SetScriptingBackend(BuildTargetGroup.Android, ScriptingImplementation.IL2CPP);
        PlayerSettings.Android.targetArchitectures = AndroidArchitecture.ARM64;
        PlayerSettings.defaultInterfaceOrientation = UIOrientation.LandscapeLeft;
        PlayerSettings.allowedAutorotateToPortrait = false;
        PlayerSettings.allowedAutorotateToPortraitUpsideDown = false;
        EditorUserBuildSettings.buildAppBundle = false;
        AssetDatabase.SaveAssets();
        Debug.Log("BOXREHA_ANDROID_PREPARATION_COMPLETED");
    }

    private static AndroidSdkVersions RequiredAndroidMinimum()
    {
        // Unity 6.6 migration is a separate, explicit project import gate.
        return (AndroidSdkVersions)(Application.unityVersion.StartsWith("6000.6.", StringComparison.Ordinal) ? 26 : 23);
    }

    public static void BuildAndroidCandidate()
    {
        if (PlayerSettings.GetApplicationIdentifier(BuildTargetGroup.Android) != "com.boxreha.digitaldojo"
            || PlayerSettings.Android.minSdkVersion != RequiredAndroidMinimum()
            || (int)PlayerSettings.Android.targetSdkVersion != 36
            || PlayerSettings.GetScriptingBackend(BuildTargetGroup.Android) != ScriptingImplementation.IL2CPP
            || PlayerSettings.Android.targetArchitectures != AndroidArchitecture.ARM64
            || PlayerSettings.defaultInterfaceOrientation != UIOrientation.LandscapeLeft
            || EditorUserBuildSettings.buildAppBundle)
            throw new InvalidOperationException("Run PrepareAndroidCandidate before stamping the source manifest and building.");
        BuildCandidate(BuildTarget.Android, "AndroidCandidate", "DigitalDojo.apk", "unity-android-candidate-build.json");
    }

    private static void BuildCandidate(BuildTarget target, string subdirectory, string fileName, string reportName)
    {
        if (!Application.isBatchMode) throw new InvalidOperationException("Run in a dedicated Unity batch process.");
        List<string> enabledScenes = new List<string>();
        foreach (EditorBuildSettingsScene scene in EditorBuildSettings.scenes)
            if (scene.enabled) enabledScenes.Add(scene.path);
        if (enabledScenes.Count == 0) throw new InvalidOperationException("No enabled scenes to build.");
        string directory = Path.Combine(ProjectRoot, "Builds", subdirectory);
        Directory.CreateDirectory(directory);
        BuildReport build = BuildPipeline.BuildPlayer(new BuildPlayerOptions
        {
            scenes = enabledScenes.ToArray(),
            locationPathName = Path.Combine(directory, fileName),
            target = target,
            options = BuildOptions.Development
        });
        CandidateBuildSummary summary = new CandidateBuildSummary
        {
            utc = DateTime.UtcNow.ToString("O"), unityVersion = Application.unityVersion,
            result = build.summary.result.ToString(), outputPath = build.summary.outputPath,
            totalBytes = build.summary.totalSize.ToString(), errors = build.summary.totalErrors,
            warnings = build.summary.totalWarnings, durationSeconds = build.summary.totalTime.TotalSeconds
        };
        string reportPath = Path.Combine(ProjectRoot, "artifacts", "validation", reportName);
        Directory.CreateDirectory(Path.GetDirectoryName(reportPath));
        File.WriteAllText(reportPath, JsonUtility.ToJson(summary, true));
        Debug.Log("Development candidate build report: " + reportPath);
        if (build.summary.result != BuildResult.Succeeded || build.summary.totalErrors > 0)
            throw new Exception("Development candidate build failed: " + build.summary.result);
    }

    public static void RunBatch()
    {
        if (!Application.isBatchMode) throw new InvalidOperationException("Run in a dedicated Unity batch process.");
        report = new Report { utc = DateTime.UtcNow.ToString("O"), unityVersion = Application.unityVersion };
        Check("timing boundaries and signs", () =>
        {
            Require(GameplayRules.Timing(0.1f, 0.45f) == HitQuality.Perfect);
            Require(GameplayRules.Timing(-0.25f, 0.45f) == HitQuality.Good);
            Require(GameplayRules.Timing(-0.45f, 0.45f) == HitQuality.Early);
            Require(GameplayRules.Timing(0.45f, 0.45f) == HitQuality.Late);
            Require(GameplayRules.Timing(0.451f, 0.45f) == HitQuality.Miss);
            Require(GameplayRules.Timing(float.NaN, 0.45f) == HitQuality.Miss);
        });
        Check("four action mappings, wrong side/action and repeated heavy side", () =>
        {
            foreach (BodySide side in new[] { BodySide.Left, BodySide.Right })
            {
                LaneType lane = side == BodySide.Left ? LaneType.Left : LaneType.Right;
                Require(GameplayRules.Matches(ActionType.Punch, side, lane, VerticalPosition.High, TargetType.Punch, lane, false));
                Require(GameplayRules.Matches(ActionType.Kick, side, lane, VerticalPosition.Low, TargetType.Kick, lane, false));
                Require(!GameplayRules.Matches(ActionType.Kick, side, lane, VerticalPosition.Low, TargetType.Punch, lane, false));
                Require(!GameplayRules.Matches(ActionType.Punch, side, lane, VerticalPosition.High, TargetType.Punch,
                    lane == LaneType.Left ? LaneType.Right : LaneType.Left, false));
                for (int i = 0; i < 5; i++)
                    Require(GameplayRules.Matches(ActionType.Punch, side, lane, VerticalPosition.High, TargetType.ToughPunch, LaneType.Center, true));
            }
        });
        Check("heavy damage and bounded combo scoring", () =>
        {
            Require(GameplayRules.HeavyDamage(0.9f) == 1 && GameplayRules.HeavyDamage(1.65f) == 2);
            Require(GameplayRules.HeavyDamage(float.NaN) == 0);
            Require(Math.Abs(GameplayRules.ComboMultiplier(1) - 1f) < 0.001f);
            Require(Math.Abs(GameplayRules.ComboMultiplier(2) - 1.1f) < 0.001f);
            Require(GameplayRules.ComboMultiplier(100) == 3f);
        });
        Check("levels and endless lane policy", () =>
        {
            foreach (LevelDefinition level in new[] { LevelDefinition.CreateLevel1(), LevelDefinition.CreateLevel2(),
                LevelDefinition.CreateLevel3(), LevelDefinition.CreateEndless() })
            {
                Require(level.IsEndless ? level.DurationSeconds == 0f : level.DurationSeconds > 0f);
                for (int i = 0; i < 250; i++)
                {
                    SpawnPatternData pattern = SpawnPatternGenerator.GetNextPattern(level);
                    Require(pattern.Lane != LaneType.Center);
                    Require(pattern.Type == TargetType.Punch ? pattern.VerticalPos == VerticalPosition.High : pattern.VerticalPos == VerticalPosition.Low);
                }
                UnityEngine.Object.DestroyImmediate(level);
            }
        });
        Check("session metrics distinguish timing and completion", () =>
        {
            GameSessionStats stats = new GameSessionStats { TotalTargets = 4, PerfectHits = 1, GoodHits = 1, EarlyHits = 1, Misses = 1 };
            Require(stats.Accuracy == 0.5f && stats.CompletionRate == 0.75f);
            stats.TrackReactionTime(2f); stats.TrackReactionTime(float.NaN); stats.TrackReactionTime(-1f);
            Require(stats.AverageReactionTime == 2f);
            stats.Reset(); Require(stats.TotalTargets == 0 && stats.AverageReactionTime == 0f);
        });
        Check("mounted assets have meshes, materials and no implicit physics", () =>
        {
            foreach(string name in new[]{"MountedPunchTarget","MountedKickTarget","MountedHeavyTarget","MountedHeavyKickTarget","MountArm","MountPlate"})
            {
                var prefab=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/DigitalDojo/Prefabs/"+name+".prefab");Require(prefab!=null);
                Require(prefab.GetComponentsInChildren<Collider>(true).Length==0);
                foreach(var mesh in prefab.GetComponentsInChildren<MeshFilter>(true))Require(mesh.sharedMesh!=null);
                foreach(var renderer in prefab.GetComponentsInChildren<Renderer>(true))foreach(var material in renderer.sharedMaterials)Require(material!=null);
                foreach(var t in prefab.GetComponentsInChildren<Transform>(true))Require(GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(t.gameObject)==0);
            }
        });
        Check("reference room bake and fracture geometry are imported", () =>
        {
            var room=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Resources/DigitalDojo/DojoRoom.prefab");
            var renderers=room.GetComponentsInChildren<Renderer>();
            Require(renderers.Length==1,"Baked room must use one renderer");
            Require(renderers[0].sharedMaterial.mainTexture!=null,"Room light/colour atlas missing");
            foreach(string name in new[]{"MountedPunchTarget","MountedKickTarget","MountedHeavyTarget","MountedHeavyKickTarget"})
            {
                var prefab=AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/DigitalDojo/Prefabs/"+name+".prefab");
                int fragments=0;
                foreach(var mesh in prefab.GetComponentsInChildren<MeshFilter>())
                    if(mesh.name.StartsWith("FracturePiece_")){fragments++;Require(mesh.sharedMesh.uv.Length>0,"Fragment UVs missing");}
                Require(fragments>=6,"Authored fracture pieces missing: "+name);
            }
        });
        foreach (EditorBuildSettingsScene scene in EditorBuildSettings.scenes)
        {
            if (!scene.enabled) continue;
            Check("scene references: " + scene.path, () => InspectScene(scene.path));
        }
        string path = Path.Combine(ProjectRoot, "artifacts", "validation", "unity-editor-checks.json");
        Directory.CreateDirectory(Path.GetDirectoryName(path));
        File.WriteAllText(path, JsonUtility.ToJson(report, true));
        Debug.Log("Game regression report: " + path + " / passed=" + report.passed + " failed=" + report.failed);
        if (report.failed != 0) throw new Exception("Game regression failures; see report.");
    }
    private static void InspectScene(string path)
    {
        Require(AssetDatabase.LoadAssetAtPath<SceneAsset>(path) != null);
        var scene = EditorSceneManager.OpenScene(path, OpenSceneMode.Single);
        foreach (GameObject root in scene.GetRootGameObjects())
            foreach (Transform child in root.GetComponentsInChildren<Transform>(true))
                Require(GameObjectUtility.GetMonoBehavioursWithMissingScriptCount(child.gameObject) == 0);
        if (scene.name != "Game") return;
        GameRoundController round = UnityEngine.Object.FindObjectOfType<GameRoundController>();
        Require(round != null);
        SerializedObject serialized = new SerializedObject(round);
        foreach (string field in new[] { "targetSpawner", "sessionTimer", "scoreSystem", "comboSystem", "hitZoneEvaluator", "inputProvider", "hudController" })
            Require(serialized.FindProperty(field).objectReferenceValue != null);
        Require(UnityEngine.Object.FindObjectOfType<PauseMenuController>() != null);
    }
    private static void Check(string name, Action action)
    {
        try { action(); report.passed++; report.checks.Add("PASS " + name); }
        catch (Exception ex) { report.failed++; report.checks.Add("FAIL " + name + ": " + ex.Message); }
    }
    private static void Require(bool condition, string message="Assertion failed") { if (!condition) throw new Exception(message); }
}
