using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>Data-backed Digital Dojo hub. Legacy concept panels are replaced before the first rendered frame.</summary>
public class DigitalDojoMenuController : MonoBehaviour
{
    private RectTransform content;
    private Font font;
    private Text status;
    private Text identity;
    private float statusRefresh;
    private string referenceKind = "strength", calibrationError;
    private Button strongReferenceButton, speedReferenceButton, referenceStartButton, referenceLeftButton, referenceRightButton, referenceSaveButton;
    private Text sensorNotice, sensorDevices, nearbyLabel;
    private Button initializeButton, permissionsButton, scanButton, profileButton, leftPairButton, rightPairButton, leftRemoveButton, rightRemoveButton, swapButton;
    private UnityEngine.UI.Button sensorStartButton;
    private int nearbyIndex;
    private string sdkGender;
    private int preparationStep;
    private Text calibrationProgress;
    private readonly Dictionary<string, UnityEngine.UI.Button> navigation = new Dictionary<string, UnityEngine.UI.Button>();
    public static bool OpenSensorSessionOnStart;
    private readonly Color ink = DojoUiStyle.Ink;
    private readonly Color red = DojoUiStyle.Red;
    private readonly Color muted = DojoUiStyle.Muted;

    void Awake() { BuildInterface(); }
    void Start()
    {
        if (OpenSensorSessionOnStart && SessionInputSelection.Physical) ShowSensorSession(); else ShowHome();
        OpenSensorSessionOnStart = false;
    }
    void Update()
    {
        statusRefresh += Time.unscaledDeltaTime;
        if (statusRefresh < 0.5f) return;
        statusRefresh = 0f;
        if (status != null)
        {
            status.text = SessionInputSelection.Label;
        }
        if (identity != null) identity.text = GameManager.EnsureInstance().PlayerProfile.Name;
        RefreshSensorStatus();
        if (calibrationProgress != null)
        {
            var measured = MeasuredCalibration.Current;
            var native=AndroidDynamicsController.EnsureInstance();
            calibrationProgress.text = calibrationError ?? (referenceKind.ToUpperInvariant()+" / "+native.Notice + "\n" + measured.State + "\nPractice remaining: "+measured.FamiliarizationRemaining+"  |  Reference actions: " + measured.SampleCount + "/5");
            RefreshReferenceControls();
        }
    }
    public void BuildInterface()
    {
        foreach (Transform child in transform)
        {
            child.gameObject.SetActive(false);
            Destroy(child.gameObject);
        }
        font = DojoUiStyle.Font;
        CanvasScaler scaler = GetComponent<CanvasScaler>() ?? gameObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1600f, 900f);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.Expand;
        scaler.matchWidthOrHeight = 0.5f;
        Transform safeArea = MobileSafeArea.Create(transform);
        RectTransform shade = Panel(safeArea, "Backdrop", new Color(0f, 0f, 0f, 0.27f));
        Stretch(shade, Vector2.zero, Vector2.one);
        RectTransform header = Panel(safeArea, "Header", ink);
        Stretch(header, new Vector2(0f, 0.88f), Vector2.one);
        Label(header, "Brand", "DIGITAL DOJO", 34, new Vector2(40f, -22f), new Vector2(440f, 54f), Color.white);
        identity = Label(header, "PlayerName", "Player", 22, new Vector2(1070f, -18f), new Vector2(450f, 32f), Color.white);
        status = Label(header, "SensorStatus", "Keyboard practice  /  sensor channel inactive", 16,
            new Vector2(900f, -58f), new Vector2(630f, 32f), muted);
        RectTransform nav = Panel(safeArea, "Navigation", ink);
        Stretch(nav, new Vector2(0.025f, 0.07f), new Vector2(0.28f, 0.85f));
        Label(nav, "Section", "TRAINING HUB", 15, new Vector2(28f, -25f), new Vector2(330f, 28f), muted);
        string[] names = { "Home", "Level mode", "Endless mode", "Sensor setup", "Calibration", "Statistics", "Player profile", "Settings", "Exit" };
        UnityEngine.Events.UnityAction[] actions = { ShowHome, StartLevelMode, StartEndlessMode, ShowSensorSetup, ShowCalibration,
            ShowStatistics, ShowPlayerProfile, ShowSettings, Quit };
        navigation.Clear();
        for (int i = 0; i < names.Length; i++)
            navigation[names[i]] = Button(nav, names[i], new Vector2(24f, -62f - i * 69f), 355f, actions[i]);
        content = Panel(safeArea, "Content", ink);
        Stretch(content, new Vector2(0.305f, 0.07f), new Vector2(0.975f, 0.85f));
        Text footer = Label(safeArea, "Footer", "Move at your own pace. Pause whenever you need.",
            DojoUiStyle.Caption, Vector2.zero, new Vector2(1480f, 30f), muted);
        footer.rectTransform.anchorMin = footer.rectTransform.anchorMax = new Vector2(0f,0f);
        footer.rectTransform.pivot = new Vector2(0f,0f); footer.rectTransform.anchoredPosition = new Vector2(50f,16f);
    }
    private void Page(string title, string eyebrow)
    {
        if (calibrationProgress != null && title != "Training setup / references")
        {
            AndroidDynamicsController.EnsureInstance().FinishSession();
            if (MeasuredCalibration.Current.Collecting) MeasuredCalibration.Current.Cancel("Reference page closed");
        }
        string selected = eyebrow.StartsWith("Android", StringComparison.OrdinalIgnoreCase) ? "Sensor setup"
            : title == "Your space. Your rhythm." ? "Home"
            : eyebrow.IndexOf("preparation", StringComparison.OrdinalIgnoreCase) >= 0 ? "Calibration"
            : title == "Your recent sessions" ? "Statistics"
            : title.IndexOf("profile", StringComparison.OrdinalIgnoreCase) >= 0 ? "Player profile"
            : title.IndexOf("settings", StringComparison.OrdinalIgnoreCase) >= 0 ? "Settings" : "Level mode";
        foreach (var item in navigation) item.Value.GetComponent<Image>().color = item.Key == selected ? red : DojoUiStyle.Surface;
        content.GetComponent<UnityEngine.UI.Image>().color = ink;
        sensorNotice = sensorDevices = nearbyLabel = null;
        sensorStartButton = null;
        calibrationProgress = null;
        foreach (Transform child in content) { child.gameObject.SetActive(false); Destroy(child.gameObject); }
        Label(content, "Eyebrow", eyebrow.ToUpperInvariant(), 15, new Vector2(40f, -26f), new Vector2(910f, 28f), muted);
        Label(content, "Title", title, 42, new Vector2(40f, -68f), new Vector2(920f, 64f), Color.white);
        RectTransform rule = Panel(content, "Accent", red);
        Place(rule, new Vector2(40f, -145f), new Vector2(68f, 4f));
    }
    private void Body(string name, string text, float y, float height = 180f, int size = 22)
    { Label(content, name, text, size, new Vector2(40f, -y), new Vector2(960f, height), muted); }
    public void ShowHome()
    {
        Page("Your space. Your rhythm.", "Digital Dojo / Training");
        content.GetComponent<UnityEngine.UI.Image>().color = new Color(.03f,.035f,.04f,.78f);
        Body("Intro", "Read the target. Find the beat.\nUpper circles: PUNCH. Lower upright pads: KICK.", 185f, 110f, 25);
        Body("HeavyGuide", "THE CENTER CHALLENGE\nLand repeated punches on the heavy target.\nEither hand works. Keep a comfortable rhythm.", 355f, 130f);
        Button(content, "Start training", new Vector2(40f, -535f), 420f, StartTraining, true);
        Body("Evidence", SessionInputSelection.Physical ? "Connect your sensors before starting." : "Development practice / keyboard input is synthetic.", 625f, 50f, 18);
    }
    public void StartLevelMode()
    {
        Page("Choose a session.", "Level mode");
        string[] descriptions = { "Rhythm Basics  /  gentle introduction", "Arms & Legs  /  faster sequences", "Combat Flow  /  challenging pace" };
        for (int i = 0; i < 3; i++)
        {
            int level = i + 1;
            Button(content, "Level " + level + "  -  " + descriptions[i], new Vector2(40f, -190f - i * 112f),
                900f, () => BeginLevel(level), i == 0);
        }
        Body("Duration", "Each level lasts 60 active seconds. Use the Pause button at any time.\nSensor sessions use one family: Alpha punches or experimental Delta kick mapping.\nTargets remaining when you stop are recorded as unfinished.", 545f, 130f);
    }
    public void ShowCalibration()
    {
        ShowMeasuredCalibration();
    }
    private void ShowPreparationStep()
    {
        string[] titles={"Check your sensors", "Left punch", "Right punch", "Left kick", "Right kick", "Heart rate (optional)", "Preparation summary"};
        Page(titles[preparationStep], "Calibration preparation / " + (preparationStep + 1) + " of 7");
        for(int i=0;i<7;i++) {var bar=Panel(content,"Step"+i,i<=preparationStep?red:DojoUiStyle.Surface);Place(bar,new Vector2(40+i*135,-170),new Vector2(118,5));}
        var native=AndroidDynamicsController.EnsureInstance();
        if(preparationStep==0)
        {
            Body("Guide","Put on the sensors and confirm the physical left/right assignments.\nUse Sensor setup to connect them before a measured session.",220,125,25);
            Body("Readiness",native.Notice,385,125,22);
        }
        else if(preparationStep<5)
        {
            string family=preparationStep<3?"Alpha":"Delta";
            string side=preparationStep==1||preparationStep==3?"Left":"Right";
            bool connected=Array.Exists(native.Status?.devices??Array.Empty<AndroidNativeDevice>(),d=>d!=null&&d.family==family&&d.side==side&&d.online);
            Body("Guide", "Prepare comfortable, repeatable movements on your " + side.ToLowerInvariant() + " side.\nKeep the sensor firmly attached. Stop if the movement feels uncomfortable.",220,130,25);
            Body("Readiness","RD "+family.ToUpperInvariant()+" / "+side+": "+(connected?"SDK reports connected":"not connected")+"\nMeasured repetitions: unavailable\nNo measurement collection or baseline is active in this preparation wizard.",390,160,22);
        }
        else if(preparationStep==5) Body("Guide","No heart-rate provider is connected.\nThis optional step is skipped. Training uses its selected difficulty.\nHeart rate is separate from punch and kick measurements.",230,220,25);
        else Body("Guide","Preparation reviewed. No measured baseline was created.\n\nConnect sensors to prepare a training session. ALPHA impact and\nDELTA power index retain their own meanings. Neither is presented\nas a calibrated force measurement.",220,270,25);
        if (preparationStep == 6) Button(content,"Collect measured reference",new Vector2(40,-520),500,ShowMeasuredCalibration,true);
        if(preparationStep>0) Button(content,"Back",new Vector2(40,-610),230,()=>{preparationStep--;ShowPreparationStep();});
        Button(content,"Retry step",new Vector2(295,-610),250,ShowPreparationStep);
        Button(content,preparationStep<6?"Next step":"Sensor setup",new Vector2(575,-610),380,()=>{if(preparationStep<6){preparationStep++;ShowPreparationStep();}else ShowSensorSetup();},true);
    }
    public void ShowMeasuredCalibration()
    {
        calibrationError=null;
        Page("Training setup / references", "Calibration preparation / measured samples");
        Body("ReferenceGuide", "Connect sensors and confirm your SDK body profile first.\nStrong reference: 3 practice actions, then 5 at your strongest comfortable effort.\nFast sequence: 5 quick, controlled actions. Stop if uncomfortable.",175,90,20);
        var native = AndroidDynamicsController.EnsureInstance();
        strongReferenceButton = Button(content,"Strong effort",new Vector2(40,-270),440,()=>{referenceKind="strength";MeasuredCalibration.Current.Cancel("Strong reference selected");ShowMeasuredCalibration();});
        speedReferenceButton = Button(content,"Fast controlled sequence",new Vector2(510,-270),440,()=>{referenceKind="speed";MeasuredCalibration.Current.Cancel("Fast sequence selected");ShowMeasuredCalibration();});
        referenceStartButton = Button(content,"Start reference session",new Vector2(40,-340),460,native.RequestCalibrationSession,true);
        Button(content,"End SDK session",new Vector2(530,-340),420,native.FinishSession);
        referenceLeftButton = Button(content,"Collect left",new Vector2(40,-430),290,()=>BeginReference("Left"));
        referenceRightButton = Button(content,"Collect right",new Vector2(350,-430),290,()=>BeginReference("Right"));
        referenceSaveButton = Button(content,"Save reference",new Vector2(660,-430),290,()=> {
            try { var p=GameManager.EnsureInstance().PlayerProfile;
                string path=MeasuredCalibration.Current.Save(System.IO.Path.Combine(Application.persistentDataPath,"calibration"),p.StudyId);
                var refs=new System.Collections.Generic.List<string>(p.CalibrationReferences??Array.Empty<string>());refs.Add(System.IO.Path.GetFileName(path));p.CalibrationReferences=refs.ToArray();PlayerProfileStore.Save(p);CalibrationLibrary.Invalidate();
            }
            catch (Exception e) { calibrationError = "Save failed: " + e.Message; }
        });
        calibrationProgress = Label(content,"ReferenceStatus","",21,new Vector2(40,-525),new Vector2(950,115),Color.white);
        Button(content,"Sensor setup",new Vector2(40,-665),440,()=>{ native.FinishSession(); ShowSensorSetup(); });
        Button(content,"Cancel reference",new Vector2(510,-665),440,()=>{ MeasuredCalibration.Current.Cancel("Cancelled by user"); native.FinishSession(); });
        RefreshReferenceControls();
    }
    private void RefreshReferenceControls()
    {
        var native=AndroidDynamicsController.EnsureInstance();var measured=MeasuredCalibration.Current;
        StepState(strongReferenceButton,false,!measured.Collecting);
        StepState(speedReferenceButton,false,!measured.Collecting);
        if(strongReferenceButton!=null)strongReferenceButton.GetComponentInChildren<Text>().text="Strong effort"+(referenceKind=="strength"?" / selected":"");
        if(speedReferenceButton!=null)speedReferenceButton.GetComponentInChildren<Text>().text="Fast sequence"+(referenceKind=="speed"?" / selected":"");
        StepState(referenceStartButton,native.CalibrationRunning,SessionInputSelection.Physical&&native.Ready(out _)&&!native.Pending&&!native.CalibrationRunning);
        StepState(referenceLeftButton,false,native.CalibrationRunning&&!measured.Collecting&&Array.Exists(native.Status?.devices??Array.Empty<AndroidNativeDevice>(),d=>d!=null&&d.online&&d.side=="Left"&&d.family==SessionInputSelection.Family));
        StepState(referenceRightButton,false,native.CalibrationRunning&&!measured.Collecting&&Array.Exists(native.Status?.devices??Array.Empty<AndroidNativeDevice>(),d=>d!=null&&d.online&&d.side=="Right"&&d.family==SessionInputSelection.Family));
        StepState(referenceSaveButton,measured.Result!=null,measured.Result!=null&&measured.Result.studyId==GameManager.EnsureInstance().PlayerProfile.StudyId);
    }
    private void BeginReference(string side)
    {
        calibrationError=null;
        var native = AndroidDynamicsController.EnsureInstance();
        if (!native.CalibrationRunning) { MeasuredCalibration.Current.Cancel("Start and await the SDK reference session first"); return; }
        AndroidNativeDevice device = Array.Find(native.Status.devices ?? Array.Empty<AndroidNativeDevice>(),
            d=>d!=null && d.online && !d.isMock && d.side==side && d.family==SessionInputSelection.Family);
        if (device == null) { MeasuredCalibration.Current.Cancel("No ready physical sensor on this side"); return; }
        MeasuredCalibration.Current.ConfigureAudit(System.IO.Path.Combine(Application.persistentDataPath,"calibration"));
        MeasuredCalibration.Current.Begin(GameManager.EnsureInstance().PlayerProfile.StudyId,device.id,device.connectionId,
            device.family,side,native.Status.sdkBuildMode,Time.realtimeSinceStartupAsDouble,referenceKind,referenceKind=="strength"?3:0);
    }
    public void ShowStatistics()
    {
        Page("Your recent sessions", "Local recorded gameplay");
        List<GameSessionStats> sessions = SessionHistoryStore.Load(GameManager.EnsureInstance().PlayerProfile.StudyId);
        if (!string.IsNullOrEmpty(SessionHistoryStore.Error))
        {
            Body("HistoryError", "Local history could not be read.\n" + SessionHistoryStore.Error +
                "\n\nThe original file is preserved. Inspect the local data directory before collecting another study session.", 210f, 260f, 23);
            return;
        }
        if (sessions.Count == 0)
        {
            Body("Empty", "No recorded sessions yet.\nComplete a level or finish an endless session to see your results.", 210f, 150f, 25);
            Body("Definition", "Timing accuracy = (Perfect + Good) / resolved targets.\nCompletion = all successful hits / resolved targets.\nNeither metric measures sensor detection accuracy.", 425f, 140f, 21);
            return;
        }
        int score=0,best=0,combo=0,perfect=0,good=0,early=0,late=0,miss=0,resolved=0,punch=0,kick=0,left=0,right=0,heavyTimeout=0,below=0;
        float duration=0;foreach(var x in sessions){score+=x.Score;best=Math.Max(best,x.Score);combo=Math.Max(combo,x.MaxCombo);duration+=x.DurationSeconds;perfect+=x.PerfectHits;good+=x.GoodHits;early+=x.EarlyHits;late+=x.LateHits;miss+=x.Misses;resolved+=x.TotalTargets;punch+=x.PunchActions;kick+=x.KickActions;left+=x.LeftActions;right+=x.RightActions;heavyTimeout+=x.HeavyTimeouts;below+=x.BelowStrengthHits;}
        Body("Overview",sessions.Count+" SESSIONS    "+(duration/60).ToString("F1")+" MINUTES    BEST "+best+"    AVG SCORE "+(score/(double)sessions.Count).ToString("F0")+"    BEST COMBO "+combo,175,55,20);
        Body("Timing","Timing accuracy "+(resolved>0?(perfect+good)/(double)resolved:0).ToString("P0")+"    Completion "+(resolved>0?(perfect+good+early+late)/(double)resolved:0).ToString("P0")+"\nPerfect "+perfect+" / Good "+good+" / Early "+early+" / Late "+late+" / Miss "+miss,240,80,21);
        Body("Activity","Punches "+punch+" / Kicks "+kick+"    Left "+left+" / Right "+right+"\nHeavy timeouts "+heavyTimeout+"    TOO LIGHT actions "+below,335,80,21);
        var latest=sessions[0];
        Body("Latest","LATEST: Average target resolution time "+latest.AverageTargetResolutionTime.ToString("F2")+" s\nInput: "+latest.KeyboardActions+" keyboard / "+latest.SensorActions+" sensor. Unfinished targets: "+latest.AbortedTargets,430,80,20);
        string rows="GAME PERFORMANCE BY SESSION — SCORE / TIMING / COMPLETION\n";
        for(int i=0;i<Math.Min(3,sessions.Count);i++){var x=sessions[i];rows+="\n"+x.StartedUtc+"  "+x.Score+" / "+x.Accuracy.ToString("P0")+" / "+x.CompletionRate.ToString("P0");}
        Body("History",rows,535,130,18);
        Button(content,"Personal performance",new Vector2(620,-680),340,ShowRelativePerformance);
    }
    public void ShowRelativePerformance()
    {
        Page("Personal performance","Game signals / active profile only");
        var sessions=SessionHistoryStore.Load(GameManager.EnsureInstance().PlayerProfile.StudyId);
        double[] sums=new double[4];int[] counts=new int[4];int actions=0;double duration=0;
        foreach(var x in sessions){sums[0]+=x.AlphaLeftRelativeSum;sums[1]+=x.AlphaRightRelativeSum;sums[2]+=x.DeltaLeftRelativeSum;sums[3]+=x.DeltaRightRelativeSum;counts[0]+=x.AlphaLeftSamples;counts[1]+=x.AlphaRightSamples;counts[2]+=x.DeltaLeftSamples;counts[3]+=x.DeltaRightSamples;actions+=x.Actions;duration+=x.DurationSeconds;}
        string[] labels={"ALPHA left punch","ALPHA right punch","DELTA left kick signal","DELTA right kick signal"};
        string rows="MEAN RELATIVE SIGNAL (dimensionless)\n\n";
        for(int i=0;i<4;i++)rows+=labels[i]+": "+(counts[i]>0?(sums[i]/counts[i]).ToString("F2")+" x reference / "+counts[i]+" actions":"Not available")+"\n\n";
        Body("RelativeSignals",rows,180,300,22);
        Body("Rate","Gameplay action rate: "+(duration>0?(actions/duration).ToString("F2"):"0")+" actions/s\nIncludes the displayed profile's input modes. This is not a sensor accuracy metric.\nReferences can change between sessions; compare the recorded calibration IDs.",500,105,20);
        Button(content,"Reference dates / versions",new Vector2(40,-640),560,ShowPerformanceReferences);
    }
    public void ShowPerformanceReferences()
    {
        Page("Personal game references","Separate quantities / active profile only");
        string study=GameManager.EnsureInstance().PlayerProfile.StudyId;
        var refs=CalibrationLibrary.Load(System.IO.Path.Combine(Application.persistentDataPath,"calibration"),study);
        string rows="";var channels=new HashSet<string>();
        foreach(var r in refs){string key=r.family+"/"+r.side+"/"+r.referenceKind;if(!channels.Add(key))continue;rows+=key+"  "+(r.referenceKind=="speed"?r.actionsPerSecond.ToString("F2")+" actions/s":r.baseline.ToString("F2")+" "+r.quantity)+"\n"+r.createdUtc+"  ["+ShortId(r.calibrationId)+"]\n\n";if(channels.Count>=6)break;}
        Body("References",rows.Length==0?"No measured references saved for this profile.":rows,180,430,20);
        Body("Meaning","References personalize game performance. No force unit or health improvement is inferred.\nSpeed = reciprocal median interval of five controlled physical actions.",630,70,19);
    }
    private int profilePage;
    public void ShowProfiles()
    {
        Page("Profiles", "Saved on this device");
        var repo=PlayerProfileStore.Repository; var profiles=repo.GetAll();
        profilePage=Mathf.Clamp(profilePage,0,Mathf.Max(0,(profiles.Count-1)/4));
        Body("ProfileHelp","Select a saved profile. Each profile has its own history and references.\nMatching display names do not merge identities.",175,80,21);
        for(int i=profilePage*4;i<Math.Min(profiles.Count,profilePage*4+4);i++)
        {
            var p=profiles[i];float y=-285-(i%4)*78;
            Button(content,(p.StudyId==repo.ActiveId?"ACTIVE  ":"")+p.Name+"  ["+ShortId(p.StudyId)+"]",new Vector2(40,y),630,()=>{GameManager.EnsureInstance().SetPlayerProfile(p);ShowPlayerProfile();});
            Button(content,"Archive",new Vector2(695,y),250,()=>{try{repo.Archive(p.StudyId);ShowProfiles();}catch(Exception e){Body("Error",e.Message,650,65,19);}}).interactable=p.StudyId!=repo.ActiveId;
        }
        Button(content,"Create profile",new Vector2(40,-630),350,()=>{var p=repo.Create("New player");GameManager.EnsureInstance().SetPlayerProfile(p);ShowPlayerProfile();},true);
        Button(content,"Previous",new Vector2(420,-630),250,()=>{profilePage--;ShowProfiles();});
        Button(content,"Next",new Vector2(695,-630),250,()=>{profilePage++;ShowProfiles();});
    }
    public void ShowPlayerProfile()
    {
        Page("Player profile", "Local preferences");
        PlayerProfile profile = GameManager.EnsureInstance().PlayerProfile;
        Body("NameLabel", "DISPLAY NAME", 185f, 35f, 18);
        InputField field = Input(content, profile.Name, new Vector2(40f, -240f), new Vector2(780f, 60f));
        Body("Privacy", "The game profile stores a display name and pseudonymous study ID.\nAndroid sensor use separately requires an SDK body profile.\nWeight, height and SDK gender are not gameplay force calibration.\nThey are not included in this game's research JSONL export.", 345f, 160f);
        Body("Id", "LOCAL STUDY ID   " + profile.StudyId, 535f, 50f, 16);
        Button(content, "Save profile", new Vector2(40f, -610f), 350f, () =>
        {
            profile.Name = field.text;
            GameManager.EnsureInstance().SetPlayerProfile(profile);
            ShowPlayerProfile();
        }, true);
        Button(content, "Saved profiles", new Vector2(435f, -610f), 460f, () =>
        {
            ShowProfiles();
        });
        Body("IdentityHint", "Create or reopen another participant under Saved profiles. History stays linked to its study ID.", 675f, 25f, 15);
    }
    public void ShowSettings()
    {
        Page("Settings", "Saved locally");
        Body("Audio", "SOUND EFFECTS", 190f, 40f, 19);
        Button(content, "Volume -", new Vector2(40f, -250f), 220f, () =>
        { SettingsManager.SfxVolume -= 0.1f; ShowSettings(); });
        Label(content, "Volume", SettingsManager.SfxVolume.ToString("P0"), 29, new Vector2(305f, -260f), new Vector2(150f, 45f), Color.white);
        Button(content, "Volume +", new Vector2(510f, -250f), 220f, () =>
        { SettingsManager.SfxVolume += 0.1f; ShowSettings(); });
        Button(content, "Reduced motion: " + (SettingsManager.ReducedMotion ? "ON" : "OFF"), new Vector2(40f, -365f), 690f, () =>
        { SettingsManager.ReducedMotion = !SettingsManager.ReducedMotion; ShowSettings(); });
        Body("Accessibility", "Reduced motion limits target glow, hit wiggle and break animation.\nActions are identified by labels, shape, side and height as well as color.", 460f, 100f, 21);
        Button(content, "Android physical input", new Vector2(40f, -580f), 425f, () =>
        { SessionInputSelection.Override = InputSourceType.Sensor; ShowSensorSetup(); });
        Button(content, "Development input", new Vector2(490f, -580f), 425f, () =>
        { AndroidDynamicsController.Instance?.FinishSession(); SessionInputSelection.Override = InputSourceType.Keyboard; ShowSettings(); });
        Body("Input", SessionInputSelection.Label + "  |  No automatic input fallback. No heart-rate adaptation.", 650f, 45f, 17);
    }
    public void ShowSensorSetup()
    {
        Page("Connect your sensors", "Android / 1 — connection");
        AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
        SessionInputSelection.Override = InputSourceType.Sensor;
        Button(content, "Bluetooth settings", new Vector2(710f,-72f), 280f, controller.OpenBluetoothSettings);
        sensorNotice = Label(content, "NativeNotice", "", 21, new Vector2(40f, -175f), new Vector2(960f, 80f), muted);
        initializeButton = Button(content, "Initialize SDK", new Vector2(40f, -265f), 220f, controller.Initialize, true);
        bool blockedPermissions = controller.Status?.code == "permissions_permanently_denied";
        permissionsButton = Button(content, blockedPermissions ? "App settings" : "Permissions", new Vector2(280f, -265f), 220f,
            () => { if(controller.Status?.code == "permissions_permanently_denied")controller.OpenAppSettings();else controller.RequestPermissions(); });
        scanButton = Button(content, "Scan", new Vector2(520f, -265f), 220f, controller.StartScan);
        Button(content, "Stop scan", new Vector2(760f, -265f), 220f, controller.StopScan);
        nearbyLabel = Label(content, "Nearby", "No discovery results", 20, new Vector2(40f, -340f), new Vector2(960f, 65f), Color.white);
        Button(content, "Next discovered device", new Vector2(40f, -410f), 435f, () => { nearbyIndex++; RefreshSensorStatus(); });
        leftPairButton = Button(content, "Assign LEFT", new Vector2(505f, -410f), 220f, () => PairSelected("Left"));
        rightPairButton = Button(content, "Assign RIGHT", new Vector2(755f, -410f), 225f, () => PairSelected("Right"));
        sensorDevices = Label(content, "Connected", "", 20, new Vector2(40f, -485f), new Vector2(960f, 82f), muted);
        leftRemoveButton = Button(content, "Remove LEFT", new Vector2(40f, -575f), 295f, () => RemoveSide("Left"));
        rightRemoveButton = Button(content, "Remove RIGHT", new Vector2(355f, -575f), 300f, () => RemoveSide("Right"));
        swapButton = Button(content, "Change / swap sides", new Vector2(675f, -575f), 305f, () => { var ds = controller.Status?.devices; if(ds != null && ds.Length > 0) controller.ChangeSide(ds[0].id); });
        profileButton = Button(content, "Next: SDK body profile", new Vector2(40f, -645f), 550f, ShowSdkProfile, true);
        Button(content, "End SDK session", new Vector2(620f, -645f), 360f, controller.FinishSession);
        RefreshSensorStatus();
    }
    private void PairSelected(string side)
    {
        AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
        AndroidNearbyDevice[] nearby = controller.Status?.nearby;
        if (nearby == null || nearby.Length == 0) return;
        AndroidNearbyDevice selected = nearby[nearbyIndex % nearby.Length];
        if (selected != null) controller.Pair(selected.id, side);
    }
    private void RemoveSide(string side)
    {
        AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
        foreach (AndroidNativeDevice device in controller.Status?.devices ?? Array.Empty<AndroidNativeDevice>())
            if (device != null && device.side == side) { controller.Remove(device.id); return; }
    }
    private void ShowSdkProfile()
    {
        Page("SDK body profile", "Android / 2 — required SDK inputs");
        Body("Purpose", "Required by Dynamics SDK; separate from the game profile and force calibration.\nThe SDK stores these locally on Android. Game research logs exclude them.\nEnter this participant's values explicitly. No preset values are supplied.", 175f, 115f, 21);
        Body("WeightLabel", "WEIGHT (kg, 20–250)", 305f, 35f, 19);
        Body("HeightLabel", "HEIGHT (cm, 50–250)", 410f, 35f, 19);
        UnityEngine.UI.InputField weight = Input(content, GameManager.EnsureInstance().PlayerProfile.WeightKg > 0 ? GameManager.EnsureInstance().PlayerProfile.WeightKg.ToString(System.Globalization.CultureInfo.InvariantCulture) : "", new Vector2(510f, -300f), new Vector2(440f, 60f));
        UnityEngine.UI.InputField height = Input(content, GameManager.EnsureInstance().PlayerProfile.HeightCm > 0 ? GameManager.EnsureInstance().PlayerProfile.HeightCm.ToString(System.Globalization.CultureInfo.InvariantCulture) : "", new Vector2(510f, -405f), new Vector2(440f, 60f));
        weight.contentType = height.contentType = UnityEngine.UI.InputField.ContentType.DecimalNumber;
        sdkGender = null;
        UnityEngine.UI.Text genderLabel = Label(content, "SdkGender", "SDK GENDER: no selection", 19, new Vector2(40f, -500f), new Vector2(430f, 50f), muted);
        Button(content, "MALE", new Vector2(510f, -495f), 200f, () => { sdkGender = "MALE"; genderLabel.text = "SDK GENDER: MALE"; });
        Button(content, "FEMALE", new Vector2(740f, -495f), 210f, () => { sdkGender = "FEMALE"; genderLabel.text = "SDK GENDER: FEMALE"; });
        Button(content, "Apply to SDK", new Vector2(40f, -575f), 430f, () =>
        {
            double.TryParse(weight.text.Replace(',', '.'), System.Globalization.NumberStyles.Float,
                System.Globalization.CultureInfo.InvariantCulture, out double kg);
            double.TryParse(height.text.Replace(',', '.'), System.Globalization.NumberStyles.Float,
                System.Globalization.CultureInfo.InvariantCulture, out double cm);
            if(AndroidSessionPolicy.ValidBodyProfile(kg,cm,sdkGender)) { var p=GameManager.EnsureInstance().PlayerProfile;p.WeightKg=kg;p.HeightCm=cm;p.SdkGender=sdkGender;PlayerProfileStore.Save(p); }
            AndroidDynamicsController.EnsureInstance().SetBodyProfile(kg, cm, sdkGender);
        }, true);
        Button(content, "Next: sensor session", new Vector2(510f, -575f), 440f, ShowSensorSession);
        sensorNotice = Label(content, "NativeNotice", "", 18, new Vector2(40f, -645f), new Vector2(950f, 60f), muted);
        RefreshSensorStatus();
    }
    private void ShowSensorSession()
    {
        Page("Start sensor training", "Android / 3 — session gate");
        Body("Scope", "Use one device or one left/right pair of one sensor family.\nTargets use only the connected physical sides. Alpha + Delta and three devices\nare unsupported. Alpha and experimental Delta kicks need separate validation.", 175f, 125f, 22);
        Button(content, "Alpha / punches", new Vector2(40f, -330f), 440f, () => SelectFamily("Alpha"));
        Button(content, "Delta / kick mapping", new Vector2(510f, -330f), 440f, () => SelectFamily("Delta"));
        sensorDevices = Label(content, "Connected", "", 20, new Vector2(40f, -420f), new Vector2(950f, 85f), muted);
        sensorNotice = Label(content, "NativeNotice", "", 21, new Vector2(40f, -520f), new Vector2(950f, 92f), Color.white);
        sensorStartButton = Button(content, "Start selected level", new Vector2(40f, -635f), 300f,
            () => GameManager.EnsureInstance().StartGame(), true);
        Button(content, "Connection", new Vector2(360f, -635f), 300f, ShowSensorSetup);
        Button(content, "End SDK session", new Vector2(680f, -635f), 300f, AndroidDynamicsController.EnsureInstance().FinishSession);
        RefreshSensorStatus();
    }
    private void SelectFamily(string family)
    {
        AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
        if (controller.Pending || SessionInputSelection.Family == family) return;
        controller.FinishSession();
        SessionInputSelection.Family = family;
        RefreshSensorStatus();
    }
    private void RefreshSensorStatus()
    {
        if (sensorNotice == null && sensorDevices == null && nearbyLabel == null) return;
        AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
        bool ready = controller.Ready(out string reason);
        if (sensorNotice != null) sensorNotice.text = sensorStartButton != null
            ? SessionInputSelection.Family + " / Level " + GameManager.EnsureInstance().SelectedLevel + "\n" +
                (controller.Pending ? controller.Notice : ready ? "SDK prerequisites reported ready. Tap Start to request a session." : reason)
            : controller.Notice;
        if (sensorNotice != null && controller.Status?.sdkBuildMode == "COMPATIBILITY") sensorNotice.text += "\nLocal SDK compatibility build / hardware unqualified";
        if (sensorStartButton != null) sensorStartButton.interactable = ready && !controller.Pending;
        if (sensorDevices != null)
        {
            string rows = "";
            foreach(var d in controller.Status?.devices ?? Array.Empty<AndroidNativeDevice>())
                if(d != null) rows += d.side.ToUpperInvariant() + "  " + d.name + "  / " + d.family + "  / " + (d.online ? "Connected" : "Paired, offline") + "  [" + ShortId(d.id) + "]\n";
            if(rows.Length == 0) rows = "LEFT: empty     RIGHT: empty — scan and assign a physical side.";
            sensorDevices.text = rows;
        }
        var status = controller.Status;
        bool initialized = status != null && status.initialized;
        bool permissions = status != null && status.permissionsGranted;
        bool discovered = status?.nearby != null && status.nearby.Length > 0;
        bool locked = controller.Pending || status?.state == "pairing" || status?.state == "removing" || status?.state == "changing_side" || (status != null && status.sessionState != "idle" && status.sessionState != "finished");
        var devices = status?.devices ?? Array.Empty<AndroidNativeDevice>();
        bool left = Array.Exists(devices,d=>d != null && d.side == "Left"), right = Array.Exists(devices,d=>d != null && d.side == "Right");
        StepState(initializeButton, initialized, true);
        StepState(permissionsButton, permissions, true);
        StepState(scanButton, discovered, initialized && permissions && !locked);
        StepState(profileButton, status != null && status.profileReady, initialized);
        StepState(leftPairButton, left, discovered && !left && !locked && devices.Length < 2);
        StepState(rightPairButton, right, discovered && !right && !locked && devices.Length < 2);
        StepState(leftRemoveButton, false, left && !locked);
        StepState(rightRemoveButton, false, right && !locked);
        StepState(swapButton, false, devices.Length > 0 && !locked);
        if (nearbyLabel != null)
        {
            AndroidNearbyDevice[] nearby = controller.Status?.nearby;
            if (nearby == null || nearby.Length == 0) nearbyLabel.text = "No discovery results. Initialize, grant permissions, then scan.";
            else
            {
                nearbyIndex %= nearby.Length;
                AndroidNearbyDevice selected = nearby[nearbyIndex];
                nearbyLabel.text = (nearbyIndex + 1) + "/" + nearby.Length + "  " + selected?.name + "  " + ShortId(selected?.id) + "\nFamily is identified after connection. Select the actual physical side below.";
            }
        }
    }
    private static string ShortId(string id) => string.IsNullOrEmpty(id) ? "?" : id.Substring(Math.Max(0, id.Length - 8));
    private static void StepState(Button button, bool complete, bool actionable)
    {
        if(button == null) return;
        button.interactable = actionable;
        button.GetComponent<Image>().color = complete ? new Color(.13f,.4f,.29f) : actionable ? new Color(.16f,.31f,.46f) : new Color(.19f,.20f,.21f);
    }
    private void BeginLevel(int level)
    {
        GameManager manager = GameManager.EnsureInstance(); manager.SetLevel(level);
        if (SessionInputSelection.Physical) ShowSensorSession();
        else manager.StartGame();
    }
    public void StartTraining() { BeginLevel(1); }
    public void StartEndlessMode() { BeginLevel(4); }
    public void Quit()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
    private RectTransform Panel(Transform parent, string name, Color color)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        go.transform.SetParent(parent, false);
        Image image = go.GetComponent<Image>(); image.color = color; image.raycastTarget = false;
        return go.GetComponent<RectTransform>();
    }
    private Text Label(Transform parent, string name, string text, int size, Vector2 position, Vector2 extent, Color color)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        go.transform.SetParent(parent, false);
        Text label = go.GetComponent<Text>(); label.font = font; label.fontSize = size;
        label.color = color; label.text = text; label.alignment = TextAnchor.UpperLeft;
        label.raycastTarget = false; label.horizontalOverflow = HorizontalWrapMode.Wrap;
        Place(label.rectTransform, position, extent);
        return label;
    }
    private Button Button(Transform parent, string label, Vector2 position, float width, UnityEngine.Events.UnityAction action, bool primary = false)
    {
        RectTransform rect = Panel(parent, label, primary ? red : DojoUiStyle.Surface);
        Place(rect, position, new Vector2(width, DojoUiStyle.TouchHeight));
        rect.GetComponent<Image>().raycastTarget = true;
        Button button = rect.gameObject.AddComponent<Button>();
        button.targetGraphic = rect.GetComponent<Image>();
        DojoUiStyle.Style(button);
        Label(rect, "Label", label, DojoUiStyle.Button, new Vector2(18f, -17f), new Vector2(width - 30f, 40f), DojoUiStyle.Paper);
        button.onClick.AddListener(action);
        return button;
    }
    private InputField Input(Transform parent, string value, Vector2 position, Vector2 size)
    {
        RectTransform rect = Panel(parent, "ProfileNameInput", new Color(0.19f, 0.2f, 0.21f, 1f));
        Place(rect, position, size);
        rect.GetComponent<Image>().raycastTarget = true;
        Text text = Label(rect, "Value", value, 25, new Vector2(16f, -12f), size - new Vector2(32f, 16f), Color.white);
        InputField field = rect.gameObject.AddComponent<InputField>();
        field.targetGraphic = rect.GetComponent<Image>(); field.textComponent = text;
        field.characterLimit = 32; field.text = value;
        return field;
    }
    private static void Place(RectTransform rect, Vector2 position, Vector2 size)
    {
        rect.anchorMin = rect.anchorMax = new Vector2(0f, 1f); rect.pivot = new Vector2(0f, 1f);
        rect.anchoredPosition = position; rect.sizeDelta = size;
    }
    private static void Stretch(RectTransform rect, Vector2 min, Vector2 max)
    { rect.anchorMin = min; rect.anchorMax = max; rect.offsetMin = rect.offsetMax = Vector2.zero; }
}
