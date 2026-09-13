using UnityEngine;
using UnityEngine.UI;

public class ResultsController : MonoBehaviour
{
    private Font font;
    private RectTransform card;
    void Start()
    {
        foreach (Transform child in transform) { child.gameObject.SetActive(false); Destroy(child.gameObject); }
        font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        CanvasScaler scaler = GetComponent<CanvasScaler>();
        if (scaler != null)
        {
            scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
            scaler.referenceResolution = new Vector2(1600f, 900f);
            scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.Expand;
            scaler.matchWidthOrHeight = 0.5f;
        }
        RectTransform background = Panel(transform, "Background", new Color(0.045f, 0.046f, 0.049f, 1f));
        Stretch(background, Vector2.zero, Vector2.one);
        card = Panel(transform, "ResultsCard", new Color(0.085f, 0.088f, 0.09f, 1f));
        Stretch(card, new Vector2(0.1f, 0.07f), new Vector2(0.9f, 0.93f));
        Text("Eyebrow", "DIGITAL DOJO  /  SESSION RESULTS", 18, 38f, 38f, 1150f, 30f, Color.gray);
        GameSessionStats stats = GameManager.Instance?.SessionStats;
        if (stats == null || string.IsNullOrEmpty(stats.SessionId))
        {
            Text("Empty", "No completed session is available.", 38, 38f, 130f, 1150f, 70f, Color.white);
            Button("Main menu", 40f, 650f, OnMainMenuButton);
            return;
        }
        Text("Score", stats.Score.ToString("N0") + " pts", 66, 38f, 95f, 570f, 100f, Color.white);
        Text("Mode", stats.Mode + "\n" + stats.DurationSeconds.ToString("F1") + " active seconds  /  " + stats.StopReason,
            22, 670f, 118f, 530f, 100f, new Color(0.85f, 0.85f, 0.82f));
        Text("Timing", "TIMING ACCURACY\n" + stats.Accuracy.ToString("P0"), 27, 40f, 250f, 365f, 90f, Color.white);
        Text("Completion", "TARGET COMPLETION\n" + stats.CompletionRate.ToString("P0"), 27, 445f, 250f, 365f, 90f, Color.white);
        Text("Combo", "BEST COMBO\n" + stats.MaxCombo, 27, 850f, 250f, 330f, 90f, new Color(1f, 0.38f, 0.3f));
        Text("Hits", "Perfect  " + stats.PerfectHits + "    Good  " + stats.GoodHits + "    Early  " + stats.EarlyHits +
            "    Late  " + stats.LateHits + "    Miss  " + stats.Misses,
            24, 40f, 380f, 1160f, 55f, Color.white);
        Text("Split", "Arms  " + stats.ArmHits + "/" + stats.ArmTargets + "    Legs  " + stats.LegHits + "/" + stats.LegTargets +
            "    Actions left / right  " + stats.LeftActions + " / " + stats.RightActions +
            "\nAverage target resolution  " + (stats.SuccessfulHits > 0 ? stats.AverageReactionTime.ToString("F2") + " s" : "n/a") +
            "    Unfinished  " + stats.AbortedTargets + "    Heavy timeouts  " + stats.HeavyTimeouts,
            22, 40f, 455f, 1160f, 95f, new Color(0.76f, 0.79f, 0.8f));
        Text("Provenance", "Input events: " + stats.KeyboardActions + " keyboard / " + stats.SensorActions + " sensor / " +
            stats.OtherActions + " other.  No force or heart-rate baseline is inferred.", 17, 40f, 570f, 1170f, 42f, Color.gray);
        Text("Definition", "Timing accuracy: Perfect + Good / resolved. Completion: all hits / resolved. Unfinished targets are excluded.",
            16, 40f, 615f, 1170f, 35f, Color.gray);
        Button("Train again", 40f, 682f, OnRestartButton);
        Button("Main menu", 450f, 682f, OnMainMenuButton);
        string issue = ResearchSessionLog.Error ?? SessionHistoryStore.Error;
        if (!string.IsNullOrEmpty(issue))
            Text("SaveError", "Data save needs attention: " + issue, 16, 850f, 670f, 330f, 85f, new Color(1f, 0.5f, 0.35f));
    }
    public void OnRestartButton() { GameManager.Instance?.StartGame(); }
    public void OnMainMenuButton() { GameManager.Instance?.LoadMainMenu(); }
    private RectTransform Panel(Transform parent, string name, Color color)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        go.transform.SetParent(parent, false);
        go.GetComponent<Image>().color = color;
        go.GetComponent<Image>().raycastTarget = false;
        return go.GetComponent<RectTransform>();
    }
    private void Text(string name, string value, int size, float x, float y, float w, float h, Color color)
    {
        GameObject go = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        go.transform.SetParent(card, false);
        Text text = go.GetComponent<Text>(); text.font = font; text.fontSize = size;
        text.text = value; text.color = color; text.raycastTarget = false;
        Place(text.rectTransform, x, y, w, h);
    }
    private void Button(string label, float x, float y, UnityEngine.Events.UnityAction callback)
    {
        RectTransform rect = Panel(card, label, new Color(0.65f, 0.13f, 0.11f, 1f));
        Place(rect, x, y, 360f, 60f);
        rect.GetComponent<Image>().raycastTarget = true;
        Button button = rect.gameObject.AddComponent<Button>(); button.targetGraphic = rect.GetComponent<Image>();
        button.onClick.AddListener(callback);
        GameObject go = new GameObject("Label", typeof(RectTransform), typeof(CanvasRenderer), typeof(Text));
        go.transform.SetParent(rect, false);
        Text text = go.GetComponent<Text>(); text.font = font; text.fontSize = 25; text.text = label;
        text.alignment = TextAnchor.MiddleCenter; text.raycastTarget = false;
        Stretch(text.rectTransform, Vector2.zero, Vector2.one);
    }
    private static void Place(RectTransform rect, float x, float y, float w, float h)
    {
        rect.anchorMin = rect.anchorMax = rect.pivot = new Vector2(0f, 1f);
        rect.anchoredPosition = new Vector2(x, -y); rect.sizeDelta = new Vector2(w, h);
    }
    private static void Stretch(RectTransform rect, Vector2 min, Vector2 max)
    { rect.anchorMin = min; rect.anchorMax = max; rect.offsetMin = rect.offsetMax = Vector2.zero; }
}
