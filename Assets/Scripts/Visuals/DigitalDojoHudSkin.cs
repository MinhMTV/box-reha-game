using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class DigitalDojoHudSkin : MonoBehaviour
{
    private const string RootName = "DigitalDojoHudSkin";
    private Font font;
    private Text inputStatus;
    private float refreshTimer;
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    private static void Install()
    {
        TryCreate(SceneManager.GetActiveScene());
        SceneManager.sceneLoaded -= OnSceneLoaded;
        SceneManager.sceneLoaded += OnSceneLoaded;
    }
    private static void OnSceneLoaded(Scene scene, LoadSceneMode mode) { TryCreate(scene); }
    private static void TryCreate(Scene scene)
    {
        if (scene.name == "Game" && FindObjectOfType<DigitalDojoHudSkin>() == null)
            new GameObject(RootName).AddComponent<DigitalDojoHudSkin>();
    }
    private IEnumerator Start()
    {
        GameObject hud = GameObject.Find("HUDCanvas");
        if (hud == null) yield break;
        font = DojoUiStyle.Font;
        CanvasScaler scaler = hud.GetComponent<CanvasScaler>();
        if (scaler != null)
        {
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1600f, 900f);
            scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.Expand;
            scaler.matchWidthOrHeight = 0.5f;
        }
        Transform canvas = MobileSafeArea.Create(hud.transform);
        RectTransform bar = Panel(canvas, "DojoTopBar");
        bar.anchorMin = new Vector2(0.015f, 0.89f); bar.anchorMax = new Vector2(0.985f, 0.99f);
        bar.offsetMin = bar.offsetMax = Vector2.zero; bar.SetAsFirstSibling();
        string[] ids = { "ScoreText", "ComboText", "TimerText", "AccuracyText" };
        string[] labels = { "SCORE", "COMBO", "TIME", "TIMING ACCURACY" };
        for (int i = 0; i < ids.Length; i++)
        {
            float x = 0.135f + i * 0.243f;
            GameObject go = GameObject.Find(ids[i]);
            if (go != null)
            {
                Text live = go.GetComponent<Text>(); live.font = font; live.fontSize = 32;
                live.transform.SetParent(canvas, false);
                live.alignment = TextAnchor.MiddleCenter; live.raycastTarget = false;
                Anchor(live.rectTransform, x, 0.925f, 330f, 43f);
            }
            Text label = Label(canvas, labels[i], labels[i], 15);
            Anchor(label.rectTransform, x, 0.965f, 330f, 25f);
        }
        GameObject feedbackObject = GameObject.Find("FeedbackText");
        if (feedbackObject != null)
        {
            Text feedback = feedbackObject.GetComponent<Text>();
            feedback.transform.SetParent(canvas, false);
            feedback.font = font; feedback.fontSize = 29; feedback.raycastTarget = false;
            Anchor(feedback.rectTransform, 0.5f, 0.18f, 960f, 48f);
        }
        GameObject oldInput = GameObject.Find("InputStateText");
        if (oldInput != null) oldInput.SetActive(false);
        inputStatus = Label(canvas, "LiveInputStatus", "Keyboard practice", 16);
        Anchor(inputStatus.rectTransform, 0.5f, 0.045f, 1450f, 32f);
        Text controls = Label(canvas, "ControlGuide", SessionInputSelection.Physical
            ? SessionInputSelection.Family + " physical sensors / use PAUSE to stop or finish"
            : "LEFT / RIGHT ARROW  punch     A / D  kick     ESC  pause", 19);
        Anchor(controls.rectTransform, 0.45f, 0.085f, 1140f, 32f);
        RectTransform pause = Panel(canvas, "TouchPauseButton");
        Anchor(pause, 0.89f, 0.1f, 230f, 72f);
        pause.GetComponent<UnityEngine.UI.Image>().raycastTarget = true;
        UnityEngine.UI.Button pauseButton = pause.gameObject.AddComponent<UnityEngine.UI.Button>();
        pauseButton.targetGraphic = pause.GetComponent<UnityEngine.UI.Image>();
        DojoUiStyle.Style(pauseButton);
        pauseButton.onClick.AddListener(() => FindObjectOfType<PauseMenuController>()?.Pause());
        Text pauseLabel = Label(pause, "Label", "PAUSE", 25);
        Anchor(pauseLabel.rectTransform, 0.5f, 0.5f, 220f, 60f);
        yield return null;
    }
    void Update()
    {
        refreshTimer += Time.unscaledDeltaTime;
        if (refreshTimer < 0.5f || inputStatus == null) return;
        refreshTimer = 0f;
        InputProviderRouter router = FindObjectOfType<InputProviderRouter>();
        inputStatus.text = ResearchSessionLog.Error ?? (SessionInputSelection.Physical
            ? AndroidDynamicsController.EnsureInstance().Notice : router != null ? router.GetStatusLine() : "No input provider");
        inputStatus.color = ResearchSessionLog.Error != null ? new Color(1f, 0.45f, 0.35f) : new Color(0.82f, 0.84f, 0.83f);
    }
    private RectTransform Panel(Transform parent, string name)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        go.transform.SetParent(parent, false);
        Image image = go.GetComponent<Image>(); image.color = new Color(0.035f, 0.036f, 0.038f, 0.92f); image.raycastTarget = false;
        return go.GetComponent<RectTransform>();
    }
    private Text Label(Transform parent, string name, string value, int size)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        go.transform.SetParent(parent, false);
        Text text = go.GetComponent<Text>(); text.font = font; text.text = value; text.fontSize = size;
        text.color = Color.white; text.raycastTarget = false; text.alignment = TextAnchor.MiddleCenter;
        return text;
    }
    private static void Anchor(RectTransform rect, float x, float y, float width, float height)
    {
        rect.anchorMin = rect.anchorMax = new Vector2(x, y); rect.pivot = new Vector2(0.5f, 0.5f);
        rect.anchoredPosition = Vector2.zero; rect.sizeDelta = new Vector2(width, height);
    }
}
