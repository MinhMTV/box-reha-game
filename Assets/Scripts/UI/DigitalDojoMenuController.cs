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
    private readonly Color ink = new Color(0.065f, 0.067f, 0.069f, 0.96f);
    private readonly Color red = new Color(0.78f, 0.16f, 0.13f, 1f);
    private readonly Color muted = new Color(0.73f, 0.76f, 0.76f, 1f);

    void Awake() { BuildInterface(); }
    void Start() { ShowHome(); }
    void Update()
    {
        statusRefresh += Time.unscaledDeltaTime;
        if (statusRefresh < 0.5f) return;
        statusRefresh = 0f;
        if (status != null)
        {
            BleSensorInputProvider provider = FindObjectOfType<BleSensorInputProvider>();
            status.text = provider != null ? provider.Status : "Keyboard practice  /  sensor channel inactive";
        }
        if (identity != null) identity.text = GameManager.EnsureInstance().PlayerProfile.Name;
    }
    public void BuildInterface()
    {
        foreach (Transform child in transform)
        {
            child.gameObject.SetActive(false);
            Destroy(child.gameObject);
        }
        font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        CanvasScaler scaler = GetComponent<CanvasScaler>() ?? gameObject.AddComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1600f, 900f);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.Expand;
        scaler.matchWidthOrHeight = 0.5f;
        RectTransform shade = Panel(transform, "Backdrop", new Color(0f, 0f, 0f, 0.27f));
        Stretch(shade, Vector2.zero, Vector2.one);
        RectTransform header = Panel(transform, "Header", ink);
        Stretch(header, new Vector2(0f, 0.88f), Vector2.one);
        Label(header, "Brand", "DIGITAL DOJO", 34, new Vector2(40f, -22f), new Vector2(440f, 54f), Color.white);
        identity = Label(header, "PlayerName", "Player", 22, new Vector2(1070f, -18f), new Vector2(450f, 32f), Color.white);
        status = Label(header, "SensorStatus", "Keyboard practice  /  sensor channel inactive", 16,
            new Vector2(900f, -58f), new Vector2(630f, 32f), muted);
        RectTransform nav = Panel(transform, "Navigation", ink);
        Stretch(nav, new Vector2(0.025f, 0.07f), new Vector2(0.28f, 0.85f));
        Label(nav, "Section", "TRAINING HUB", 15, new Vector2(28f, -25f), new Vector2(330f, 28f), muted);
        string[] names = { "Home", "Level mode", "Endless mode", "Calibration", "Statistics", "Player profile", "Settings", "Exit" };
        UnityEngine.Events.UnityAction[] actions = { ShowHome, StartLevelMode, StartEndlessMode, ShowCalibration,
            ShowStatistics, ShowPlayerProfile, ShowSettings, Quit };
        for (int i = 0; i < names.Length; i++)
            Button(nav, names[i], new Vector2(24f, -74f - i * 69f), 355f, actions[i], i == 1);
        content = Panel(transform, "Content", ink);
        Stretch(content, new Vector2(0.305f, 0.07f), new Vector2(0.975f, 0.85f));
        Label(transform, "Footer", "ARROWS  punch    A / D  kick    ESC  pause    ENTER  finish endless",
            17, new Vector2(50f, -855f), new Vector2(1480f, 30f), Color.white);
    }
    private void Page(string title, string eyebrow)
    {
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
        Page("Find your rhythm.", "Combat fitness arcade");
        Body("Intro", "Two sides. Clear actions. A training space at your pace.\nPunch the upper targets and kick the lower pads as they reach the hit line.", 180f, 120f, 25);
        Body("HeavyGuide", "HEAVY TARGET\nThe large center disc accepts repeated punches from either side.\nIt waits at the hit line for up to 12 active seconds.", 345f, 130f);
        Button(content, "Start Level 1", new Vector2(40f, -545f), 350f, StartTraining, true);
        Body("Evidence", "Local practice prototype  /  No medical measurement or verified hardware connection is implied.", 630f, 50f, 16);
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
        Body("Duration", "Each level lasts 60 active seconds. Pause at any time with ESC.\nTargets remaining when you stop are recorded as unfinished.", 565f, 100f);
    }
    public void ShowCalibration()
    {
        Page("Sensor calibration", "Preparation");
        Body("State", "NO VERIFIED BASELINE AVAILABLE", 180f, 45f, 27);
        Body("Plan", "The planned routine uses repeated comfortable actions:\n\n01   Left punch     02   Right punch\n03   Left kick        04   Right kick\n\nBaselines must retain device, side, quantity, unit and provenance.\nALPHA impact and DELTA power index are different quantities.", 255f, 280f);
        Body("Unavailable", "Collection and baseline persistence are not yet available in this screen.\nKeyboard power is a gameplay value. Heart rate is a separate optional channel.", 575f, 100f, 19);
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
        GameSessionStats latest = sessions[0];
        Body("Latest", "LATEST  " + latest.Mode + "\nScore  " + latest.Score.ToString("N0") +
            "     Timing accuracy  " + latest.Accuracy.ToString("P0") + "     Completion  " + latest.CompletionRate.ToString("P0"),
            180f, 90f, 23);
        Body("Split", "Targets hit:  arms " + latest.ArmHits + "/" + latest.ArmTargets +
            "   legs " + latest.LegHits + "/" + latest.LegTargets + "\nActions:  left " + latest.LeftActions +
            "   right " + latest.RightActions + "   |   Avg resolution " + latest.AverageReactionTime.ToString("F2") + " s",
            290f, 90f, 21);
        string rows = "RECENT HISTORY\n";
        for (int i = 0; i < Mathf.Min(4, sessions.Count); i++)
        {
            GameSessionStats s = sessions[i];
            DateTime.TryParse(s.StartedUtc, out DateTime date);
            rows += "\n" + date.ToLocalTime().ToString("dd MMM HH:mm") + "   " + s.Mode +
                "   " + s.Score.ToString("N0") + " pts   " + s.StopReason;
        }
        Body("History", rows, 415f, 230f, 20);
        Body("Provenance", "Latest input: " + latest.KeyboardActions + " keyboard / " + latest.SensorActions +
            " sensor / " + latest.OtherActions + " other.  Unfinished targets: " + latest.AbortedTargets, 650f, 40f, 16);
    }
    public void ShowPlayerProfile()
    {
        Page("Player profile", "Local preferences");
        PlayerProfile profile = GameManager.EnsureInstance().PlayerProfile;
        Body("NameLabel", "DISPLAY NAME", 185f, 35f, 18);
        InputField field = Input(content, profile.Name, new Vector2(40f, -240f), new Vector2(780f, 60f));
        Body("Privacy", "Only the display name is shown in the interface.\nResearch exports use a generated pseudonymous ID.\nNo age, sex, weight or medical attributes are required.", 345f, 160f);
        Body("Id", "LOCAL STUDY ID   " + profile.StudyId, 535f, 50f, 16);
        Button(content, "Save profile", new Vector2(40f, -610f), 350f, () =>
        {
            profile.Name = field.text;
            GameManager.EnsureInstance().SetPlayerProfile(profile);
            ShowPlayerProfile();
        }, true);
        Button(content, "New participant ID", new Vector2(435f, -610f), 460f, () =>
        {
            // Explicit operator action: a display-name change alone never changes the study identity.
            GameManager.EnsureInstance().SetPlayerProfile(new PlayerProfile { Name = field.text });
            ShowPlayerProfile();
        });
        Body("IdentityHint", "For a different study participant, create a new ID. Prior session files remain stored.", 675f, 25f, 15);
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
        Body("Input", "INPUT   Arrows: punches  /  A, D: kicks\nSENSOR   Requires a configured native collector and verified channel.\nHEART RATE   Not active. No physiological adaptation is applied.", 585f, 110f, 19);
    }
    private void BeginLevel(int level) { GameManager manager = GameManager.EnsureInstance(); manager.SetLevel(level); manager.StartGame(); }
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
        RectTransform rect = Panel(parent, label, primary ? red : new Color(0.15f, 0.16f, 0.17f, 1f));
        Place(rect, position, new Vector2(width, 56f));
        rect.GetComponent<Image>().raycastTarget = true;
        Button button = rect.gameObject.AddComponent<Button>();
        button.targetGraphic = rect.GetComponent<Image>();
        ColorBlock colors = button.colors;
        colors.highlightedColor = new Color(1.25f, 1.25f, 1.25f, 1f);
        colors.selectedColor = new Color(1.18f, 1.18f, 1.18f, 1f);
        button.colors = colors;
        Label(rect, "Label", label, 21, new Vector2(18f, -12f), new Vector2(width - 30f, 38f), Color.white);
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
