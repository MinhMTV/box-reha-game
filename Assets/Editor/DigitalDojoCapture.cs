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
    static float debrisCleanupAt;
    static PacingRuntimeProbe pacingProbe;
    static readonly string[] Pages = { "ShowHome", "StartLevelMode", "ShowCalibration", "ShowMeasuredCalibration", "ShowStatistics", "ShowPlayerProfile", "ShowProfiles", "ShowRelativePerformance", "ShowPerformanceReferences", "ShowSettings", "ShowSensorSetup" };
    static DigitalDojoCapture()
    {
        if (SessionState.GetBool(Key, false)) EditorApplication.update += Tick;
    }
    public static void Run()
    {
        GameRegressionChecks.RunBatch();
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
            else if (step == Pages.Length * 2) { SessionInputSelection.Override = InputSourceType.Keyboard; SceneManager.LoadScene("Game"); }
            else if (step == Pages.Length * 2 + 1)
            {
                GameManager.EnsureInstance().CurrentState = GameState.Playing;
                Time.timeScale = 0;
                var spawner = UnityEngine.Object.FindFirstObjectByType<TargetSpawner>();
                spawner.StopSpawning();
                foreach (var target in UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None)) UnityEngine.Object.Destroy(target.gameObject);
                var create = typeof(TargetSpawner).GetMethod("CreateTargetObject", BindingFlags.Instance | BindingFlags.NonPublic);
                var types = new[] { TargetType.Punch, TargetType.Kick, TargetType.ToughPunch, TargetType.ToughKick };
                var positions = new[] { new Vector3(-2.4f, 2.1f, 7), new Vector3(2.4f, 0.45f, 7), new Vector3(0, 2.1f, 11), new Vector3(0,.45f,15) };
                for (int i = 0; i < types.Length; i++)
                {
                    var go = (GameObject)create.Invoke(spawner, new object[] { positions[i], types[i] });
                    var t = go.GetComponent<TargetObject>(); t.Type = types[i]; t.Lane = i == 0 ? LaneType.Left : i == 1 ? LaneType.Right : LaneType.Center;
                    t.VertPosition = (i == 1 || i == 3) ? VerticalPosition.Low : VerticalPosition.High; t.MaxHits = i >= 2 ? 8 : 1;
                    go.GetComponent<TargetMover>().enabled = false;
                    if(i==3){t.MoveSpeed=2;t.HitWindow=1;go.GetComponent<TargetMover>().Initialize(2,0);go.GetComponent<TargetMover>().enabled=true;}
                }
            }
            else if (step == Pages.Length * 2 + 2)
            {
                foreach(var m in UnityEngine.Object.FindObjectsByType<TargetMountMotion>(FindObjectsSortMode.None))
                    {
                    if(m.Ready || m.Phase != "Idle")throw new Exception("Deployment must pause with gameplay time");
                    var owned=m.transform.Find("TargetOwnedMount");
                    if(owned==null || owned.childCount!=4)throw new Exception("Expected three telescope sleeves and one owned mounting plate");
                    if(owned.GetComponentsInChildren<Collider>().Length!=0)throw new Exception("Decorative telescope has an implicit collider");
                    m.Impact(true);
                    if(m.Ready)throw new Exception("Below-threshold recoil must not unlock deployment");
                }
                if(Mathf.Abs(Array.Find(UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None),t=>t.Type==TargetType.ToughKick).transform.position.z-15)>0.001f)throw new Exception("Target moved during paused deployment");
                Capture("Mounts-Deploy");Time.timeScale=1;
            }
            else if (step == Pages.Length * 2 + 3)
            {
                foreach(var m in UnityEngine.Object.FindObjectsByType<TargetMountMotion>(FindObjectsSortMode.None))
                    if(!m.Ready || m.transform.Find("TargetOwnedMount")==null)throw new Exception("Mount did not deploy into owned travel state");
                if(Array.Find(UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None),t=>t.Type==TargetType.ToughKick).transform.position.z>=14.9f)throw new Exception("Deployed target did not travel toward hit plane");
                Capture("Gameplay-Targets-HUD");
                var targets=UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None);
                var oldPositions=Array.ConvertAll(targets,t=>t.transform.position);
                foreach(var selected in targets)
                {
                    foreach(var t in targets)t.gameObject.SetActive(t==selected);
                    var p=selected.transform.position;p.z=HitZoneEvaluator.PlayerHitPlaneZ;selected.transform.position=p;
                    Capture("Gameplay-StrikePlane-"+selected.Type);
                }
                for(int i=0;i<targets.Length;i++){targets[i].gameObject.SetActive(true);targets[i].transform.position=oldPositions[i];}
                UnityEngine.Object.FindFirstObjectByType<PauseMenuController>().Pause();
            }
            else if (step == Pages.Length * 2 + 4) Capture("Pause");
            else if (step == Pages.Length * 2 + 5) { UnityEngine.Object.FindFirstObjectByType<PauseMenuController>().Resume(); VerifyGameplay(); }
            else if (step == Pages.Length * 2 + 6)
            {
                if(UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None).Length != 0)throw new Exception("Resolved target orphan after destruction grace");
                if(UnityEngine.Object.FindObjectsByType<TargetMountMotion>(FindObjectsInactive.Include, FindObjectsSortMode.None).Length != 0)throw new Exception("Orphaned target mount");
                if(UnityEngine.Object.FindObjectsByType<ToughTargetHealthBar>(FindObjectsInactive.Include, FindObjectsSortMode.None).Length != 0)throw new Exception("Orphaned heavy target health bar");
                File.AppendAllText("artifacts/validation/dd-runtime-checks.txt","\nPASS mount deploy pauses and then physically travels with owned geometry\nPASS three telescope sleeves, mounted plate and no implicit collider\nPASS weak recoil does not unlock deployment\nPASS no mount orphans\nPASS no heavy health bar orphans\nPASS normal/kick/weak-then-strong/miss/heavy completion/heavy timeout have no target orphans after next frames");
                HitGatePlayModeChecks.Run(Capture);
                debrisCleanupAt=Time.time+DojoDebrisPool.Lifetime+.2f;
            }
            else if (step == Pages.Length * 2 + 7)
            {
                if(Time.time<debrisCleanupAt)return;
                var pool=UnityEngine.Object.FindFirstObjectByType<DojoDebrisPool>();
                if(pool!=null && pool.ActiveCount!=0)throw new Exception("Debris still active beyond bounded lifetime");
                if(UnityEngine.Object.FindObjectsByType<TargetMountMotion>(FindObjectsInactive.Include,FindObjectsSortMode.None).Length!=0)throw new Exception("Hit gate QA left mounts");
                File.AppendAllText("artifacts/validation/hit-gate-playmode.txt","\nPASS pooled debris inactive after lifetime; no target mounts left");
                pacingProbe=new PacingRuntimeProbe();pacingProbe.Start(Capture);
            }
            else if (step == Pages.Length * 2 + 8)
            {
                var probe=pacingProbe;
                if(probe.Failure!=null)throw new Exception(probe.Failure);
                if(!probe.Complete)return;
                UnityEngine.Object.FindFirstObjectByType<GameRoundController>().FinishRound("synthetic_qa_complete");
            }
            else if (step == Pages.Length * 2 + 9) Capture("Results-Synthetic-QA");
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
    static void VerifyGameplay()
    {
        var manager=GameManager.EnsureInstance();
        var evaluator=UnityEngine.Object.FindFirstObjectByType<HitZoneEvaluator>();
        var spawner=UnityEngine.Object.FindFirstObjectByType<TargetSpawner>();
        var round=UnityEngine.Object.FindFirstObjectByType<GameRoundController>();
        var checks=new System.Collections.Generic.List<string>();
        Action<bool,string> require=(ok,name)=>{if(!ok)throw new Exception("Runtime QA: "+name);checks.Add("PASS "+name);};
        foreach(var target in UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None))
        { evaluator.UnregisterTarget(target); target.Resolve(); UnityEngine.Object.Destroy(target.gameObject); }
        var create=typeof(TargetSpawner).GetMethod("CreateTargetObject",BindingFlags.NonPublic|BindingFlags.Instance);
        var input=typeof(GameRoundController).GetMethod("HandlePlayerAction",BindingFlags.NonPublic|BindingFlags.Instance);
        Action<ActionType,BodySide> act=(kind,side)=>input.Invoke(round,new object[]{KeyboardActionFactory.Create(kind,side)});
        foreach(var kind in new[]{ActionType.Punch,ActionType.Kick}) foreach(var side in new[]{BodySide.Left,BodySide.Right})
        {
            var type=kind==ActionType.Punch?TargetType.Punch:TargetType.Kick;
            var go=(GameObject)create.Invoke(spawner,new object[]{new Vector3(side==BodySide.Left?-3:3,kind==ActionType.Punch?2.1f:.45f,evaluator.HitZoneZ),type});
            var target=go.GetComponent<TargetObject>();target.Type=type;target.Lane=side==BodySide.Left?LaneType.Left:LaneType.Right;
            target.VertPosition=kind==ActionType.Punch?VerticalPosition.High:VerticalPosition.Low;target.MoveSpeed=4;target.HitWindow=1;
            target.GetComponent<TargetMountMotion>().enabled=false;target.EnsureTrackedSpawn();
            act(kind,side==BodySide.Left?BodySide.Right:BodySide.Left);
            require(!target.IsResolved,kind+" "+side+" wrong side rejected");
            act(kind==ActionType.Punch?ActionType.Kick:ActionType.Punch,side);
            require(!target.IsResolved,kind+" "+side+" wrong action rejected");
            act(kind,side);require(target.IsResolved,kind+" "+side+" resolves through game action handler");
        }
        var weakObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(-3,2.1f,evaluator.HitZoneZ),TargetType.Punch});
        var weak=weakObject.GetComponent<TargetObject>();weak.Type=TargetType.Punch;weak.Lane=LaneType.Left;weak.MoveSpeed=4;weak.HitWindow=1;weak.GetComponent<TargetMountMotion>().enabled=false;weak.EnsureTrackedSpawn();
        KeyboardActionFactory.DevelopmentPower=.2f;int below=manager.SessionStats.BelowStrengthHits;
        act(ActionType.Punch,BodySide.Left);require(!weak.IsResolved&&manager.SessionStats.BelowStrengthHits==below+1,"weak action gives separate outcome and target persists");
        Capture("Weak-hit-SYNTHETIC");KeyboardActionFactory.DevelopmentPower=1;act(ActionType.Punch,BodySide.Left);require(weak.IsResolved,"weak target accepts later normal hit");
        var missedObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(3,.45f,evaluator.HitZoneZ-4),TargetType.Kick});
        var missed=missedObject.GetComponent<TargetObject>();missed.Type=TargetType.Kick;missed.MoveSpeed=4;missed.HitWindow=1;missed.GetComponent<TargetMountMotion>().enabled=false;missed.EnsureTrackedSpawn();
        typeof(HitZoneEvaluator).GetMethod("Update",BindingFlags.Instance|BindingFlags.NonPublic).Invoke(evaluator,null);require(missed.IsResolved,"miss beyond window resolves");
        var heavyObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(0,2,evaluator.HitZoneZ),TargetType.ToughPunch});
        var heavy=heavyObject.GetComponent<TargetObject>();heavy.Type=TargetType.ToughPunch;heavy.Lane=LaneType.Center;
        heavy.VertPosition=VerticalPosition.High;heavy.MaxHits=5;heavy.MoveSpeed=4;heavy.HitWindow=1;heavy.GetComponent<TargetMountMotion>().enabled=false;heavy.EnsureTrackedSpawn();heavy.LockInHitZone(evaluator.HitZoneZ);
        for(int i=0;i<5;i++)
        {
            act(ActionType.Punch,BodySide.Left);
            if(i==0)
            {
                var segment=Array.Find(heavy.GetComponentsInChildren<Renderer>(),r=>r.name.StartsWith("DamageSegment_"));
                var propertyBlock=new MaterialPropertyBlock();segment.GetPropertyBlock(propertyBlock);
                require(propertyBlock.GetColor("_EmissionColor")==Color.black,"heavy damage segment persists after hit flash");
            }
        }
        require(heavy.IsResolved && heavy.CurrentHits==5,"heavy accepts five same-side punches");
        var fractureVisual=heavy.GetComponentInChildren<DigitalDojoTargetVisual>();
        var fragment=Array.Find(fractureVisual.GetComponentsInChildren<Transform>(),t=>t.name.StartsWith("FracturePiece_"));
        require(fragment!=null,"imported heavy target contains fracture geometry");
        var fragmentBefore=fragment.localPosition;
        typeof(DigitalDojoTargetVisual).GetField("breakAt",BindingFlags.NonPublic|BindingFlags.Instance).SetValue(fractureVisual,Time.unscaledTime-.12f);
        typeof(DigitalDojoTargetVisual).GetMethod("Update",BindingFlags.NonPublic|BindingFlags.Instance).Invoke(fractureVisual,null);
        require(SettingsManager.ReducedMotion ? fragment.localPosition==fragmentBefore : fragment.localPosition!=fragmentBefore,"fracture animation respects reduced motion");
        var kickHeavyObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(0,.45f,evaluator.HitZoneZ),TargetType.ToughKick});
        var kickHeavy=kickHeavyObject.GetComponent<TargetObject>();kickHeavy.Type=TargetType.ToughKick;kickHeavy.Lane=LaneType.Center;kickHeavy.VertPosition=VerticalPosition.Low;kickHeavy.MaxHits=4;kickHeavy.MoveSpeed=4;kickHeavy.HitWindow=1;
        kickHeavy.GetComponent<TargetMountMotion>().enabled=false;kickHeavy.EnsureTrackedSpawn();kickHeavy.LockInHitZone(evaluator.HitZoneZ);
        act(ActionType.Punch,BodySide.Left);require(kickHeavy.CurrentHits==0,"heavy kick rejects punch");
        KeyboardActionFactory.DevelopmentPower=.2f;act(ActionType.Kick,BodySide.Left);require(kickHeavy.CurrentHits==0&&!kickHeavy.IsResolved,"heavy kick TOO LIGHT persists");KeyboardActionFactory.DevelopmentPower=1;
        act(ActionType.Kick,BodySide.Left);act(ActionType.Kick,BodySide.Left);act(ActionType.Kick,BodySide.Right);act(ActionType.Kick,BodySide.Right);
        require(kickHeavy.IsResolved&&kickHeavy.CurrentHits==4,"heavy kick accepts same or alternating feet");
        var timeoutObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(0,2,evaluator.HitZoneZ),TargetType.ToughPunch});
        var timeout=timeoutObject.GetComponent<TargetObject>();timeout.Type=TargetType.ToughPunch;timeout.MaxHits=5;timeout.MoveSpeed=4;timeout.HitWindow=1;timeout.HeavyTimeoutSeconds=0;timeout.GetComponent<TargetMountMotion>().enabled=false;timeout.EnsureTrackedSpawn();
        typeof(HitZoneEvaluator).GetMethod("Update",BindingFlags.Instance|BindingFlags.NonPublic).Invoke(evaluator,null);require(timeout.IsResolved,"heavy timeout resolves");
        foreach(var primitive in new[]{PrimitiveType.Cylinder,PrimitiveType.Cube,PrimitiveType.Sphere}){var visual=VisualPrimitive.Create(primitive);require(visual.GetComponent<Collider>()==null,"visual "+primitive+" has no physics dependency");UnityEngine.Object.Destroy(visual);}
        require(GameObject.Find("DojoLeftArmLane")==null&&GameObject.Find("DojoRightArmLane")==null,"no visible lane rails");
        require(evaluator.HitZoneZ==HitZoneEvaluator.PlayerHitPlaneZ,"closer hit plane used by evaluator");
        var abortedObject=(GameObject)create.Invoke(spawner,new object[]{new Vector3(-3,2,20),TargetType.Punch});
        var aborted=abortedObject.GetComponent<TargetObject>();aborted.MoveSpeed=4;aborted.HitWindow=1;aborted.GetComponent<TargetMountMotion>().enabled=false;aborted.EnsureTrackedSpawn();
        int previousAborted=manager.SessionStats.AbortedTargets;evaluator.AbortRemaining();
        require(aborted.IsResolved&&manager.SessionStats.AbortedTargets==previousAborted+1,"finish cleanup aborts pending target exactly once");
        require(manager.SessionStats.Score>0 && manager.SessionStats.MaxCombo>0,"score and combo recorded");
        require(manager.SessionStats.SensorActions==0 && manager.SessionStats.KeyboardActions>0,"synthetic keyboard provenance retained");
        manager.PauseGame();require(manager.CurrentState==GameState.Paused && Time.timeScale==0,"pause stops scaled time");
        manager.ResumeGame();require(manager.CurrentState==GameState.Playing && Time.timeScale==1,"development resume restores gameplay");
        File.WriteAllText(Path.GetFullPath("artifacts/validation/dd-runtime-checks.txt"),"UNITY PLAY MODE / SYNTHETIC ACTIONS / NO PHYSICAL HARDWARE\n"+string.Join("\n",checks));
    }
    static void Capture(string label)
    {
        string pass = Environment.GetEnvironmentVariable("DOJO_CAPTURE_PASS") ?? "Before";
        string directory = Path.GetFullPath("DesignReferences/CurrentBuild/" + pass);
        Directory.CreateDirectory(directory);
        if(label.StartsWith("Gameplay") || label=="Pause")
        {
            var pauseGroup=UnityEngine.Object.FindFirstObjectByType<PauseMenuController>().GetComponent<CanvasGroup>();
            if(pauseGroup==null || pauseGroup.alpha!=(label=="Pause"?1:0)) throw new Exception("Pause visibility does not match captured game state");
            var lines=new System.Collections.Generic.List<string>{ "state="+GameManager.Instance.CurrentState };
            foreach(var graphic in UnityEngine.Object.FindObjectsByType<Graphic>(FindObjectsInactive.Include,FindObjectsSortMode.None))
                lines.Add(graphic.name+" parent="+graphic.transform.parent.name+" active="+graphic.gameObject.activeInHierarchy+" enabled="+graphic.enabled+" alpha="+graphic.canvasRenderer.GetInheritedAlpha());
            File.WriteAllLines(Path.Combine(directory,label+"-ui-state.txt"),lines);
        }
        foreach (var size in new[] { new Vector2Int(1920,1080), new Vector2Int(1280,720), new Vector2Int(2400,1080), new Vector2Int(1024,768) })
            Render(label, directory, size.x, size.y);
        if(label=="SensorSetup")
        {
            var native=AndroidDynamicsController.EnsureInstance();
            DynamicsSdkBridge.EnsureInstance().ReceiveNativeStatusJson(JsonUtility.ToJson(new AndroidNativeStatus {schemaVersion=1,statusSequence=100,initialized=true,permissionsGranted=true,state="ready",sessionState="idle",code="synthetic_ui_fixture",message="SYNTHETIC UI FIXTURE — NOT A HARDWARE CAPTURE",devices=new[]{new AndroidNativeDevice{id="synthetic-alpha",name="SG-2300003 (fixture)",family="Alpha",side="Left",online=true,connectionId="fixture-epoch"}}}));
            var menu=UnityEngine.Object.FindFirstObjectByType<DigitalDojoMenuController>();menu.ShowSensorSetup();
            foreach(var size in new[]{new Vector2Int(1280,720),new Vector2Int(2400,1080),new Vector2Int(1024,768)})Render("NamedAlpha-SYNTHETIC-UI",directory,size.x,size.y);
        }
        if(label.StartsWith("Gameplay"))
        {
            var rows=new System.Collections.Generic.List<string>();
            foreach(var r in UnityEngine.Object.FindObjectsByType<Renderer>(FindObjectsSortMode.None))
                rows.Add(r.name+" | "+r.transform.position+" | "+r.bounds.size+" | "+(r.sharedMaterial==null?"MISSING":r.sharedMaterial.name+" / "+r.sharedMaterial.shader.name+" / "+(r.sharedMaterial.HasProperty("_Color")?r.sharedMaterial.color.ToString():"no color")));
            File.WriteAllLines(Path.Combine(directory,"runtime-renderers.txt"),rows);
        }
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
            if(label.StartsWith("Gameplay-StrikePlane"))
            {
                foreach(var targetObject in UnityEngine.Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None))
                {
                    var body=targetObject.GetComponentInChildren<DigitalDojoTargetVisual>();
                    foreach(var renderer in body.GetComponentsInChildren<Renderer>())
                    {
                        var bounds=renderer.bounds;
                        foreach(float x in new[]{bounds.min.x,bounds.max.x})foreach(float y in new[]{bounds.min.y,bounds.max.y})
                        {
                            var point=camera.WorldToViewportPoint(new Vector3(x,y,bounds.min.z));
                            if(point.x<0||point.x>1||point.y<0||point.y>.90f)throw new Exception("Strike-plane body clipped or touches HUD: "+label+" / "+width+"x"+height);
                        }
                    }
                }
            }
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
