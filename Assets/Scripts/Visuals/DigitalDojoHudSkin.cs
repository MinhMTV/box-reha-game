using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/// <summary>
/// Skins the existing HUDController output to match the Digital Dojo mockups.
/// It keeps the live score/combo/timer/accuracy Text objects intact.
/// </summary>
public class DigitalDojoHudSkin : MonoBehaviour
{
    private const string RootName = "DigitalDojoHudSkin";

    private Font font;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    private static void InstallForCurrentScene()
    {
        TryCreate(SceneManager.GetActiveScene());
        SceneManager.sceneLoaded -= OnSceneLoaded;
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private static void OnSceneLoaded(Scene scene, LoadSceneMode mode)
    {
        TryCreate(scene);
    }

    private static void TryCreate(Scene scene)
    {
        if (!scene.isLoaded || scene.name != "Game" || GameObject.Find(RootName) != null || FindObjectOfType<DigitalDojoHudSkin>() != null)
        {
            return;
        }

        new GameObject(RootName).AddComponent<DigitalDojoHudSkin>();
    }

    private IEnumerator Start()
    {
        Canvas hudCanvas = null;
        for (int i = 0; i < 30 && hudCanvas == null; i++)
        {
            GameObject hud = GameObject.Find("HUDCanvas");
            hudCanvas = hud != null ? hud.GetComponent<Canvas>() : null;
            yield return null;
        }

        if (hudCanvas == null)
        {
            yield break;
        }

        font = Font.CreateDynamicFontFromOSFont("Bahnschrift", 24);
        if (font == null)
        {
            font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        }
        BuildHud(hudCanvas.transform);
    }

    private void BuildHud(Transform canvas)
    {
        Color redAccent = new Color(1f, 0.24f, 0.2f, 1f);
        Color blueAccent = new Color(0.3f, 0.75f, 1f, 1f);
        Color greenAccent = new Color(0.52f, 1f, 0.35f, 1f);

        RectTransform topBar = CreatePanel(canvas, "DigitalDojoTopBar", new Color(0f, 0f, 0f, 0.78f));
        Stretch(topBar, new Vector2(0.015f, 0.865f), new Vector2(0.985f, 0.985f));
        topBar.SetAsFirstSibling();

        StyleLiveText("ScoreText", "SCORE", new Vector2(130f, -38f), new Vector2(245f, 54f), TextAnchor.MiddleCenter, Color.white, 30);
        StyleLiveText("ComboText", "COMBO", new Vector2(565f, -38f), new Vector2(245f, 54f), TextAnchor.MiddleCenter, redAccent, 30);
        StyleLiveText("TimerText", "TIME", new Vector2(1000f, -38f), new Vector2(245f, 54f), TextAnchor.MiddleCenter, Color.white, 30);
        StyleLiveText("AccuracyText", "ACCURACY", new Vector2(1435f, -38f), new Vector2(245f, 54f), TextAnchor.MiddleCenter, blueAccent, 30);

        CreateTopLabel(canvas, "ScoreLabel", "SCORE", new Vector2(130f, -14f), Color.white);
        CreateTopLabel(canvas, "ComboLabel", "COMBO", new Vector2(565f, -14f), redAccent);
        CreateTopLabel(canvas, "TimerLabel", "TIME", new Vector2(1000f, -14f), Color.white);
        CreateTopLabel(canvas, "AccuracyLabel", "ACCURACY", new Vector2(1435f, -14f), blueAccent);

        RectTransform hitLineLabel = CreateText(canvas, "HitLineLabel", "HIT LINE", 24, TextAnchor.MiddleCenter, Color.white);
        Anchor(hitLineLabel, new Vector2(0.5f, 0.13f), Vector2.zero, new Vector2(240f, 42f), new Vector2(0.5f, 0.5f));

        Text feedback = GameObject.Find("FeedbackText") != null ? GameObject.Find("FeedbackText").GetComponent<Text>() : null;
        if (feedback != null)
        {
            feedback.font = font;
            feedback.fontSize = 38;
            feedback.fontStyle = FontStyle.Bold;
            feedback.alignment = TextAnchor.MiddleCenter;
            feedback.color = new Color(1f, 0.82f, 0.25f, 1f);
            Anchor(feedback.rectTransform, new Vector2(0.5f, 0.2f), Vector2.zero, new Vector2(720f, 60f), new Vector2(0.5f, 0.5f));
        }

        CreateLimbCard(canvas, "LeftArmCard", "LEFT ARM", "78%", new Vector2(0.12f, 0.045f), redAccent);
        CreateLimbCard(canvas, "RightArmCard", "RIGHT ARM", "82%", new Vector2(0.36f, 0.045f), blueAccent);
        CreateLimbCard(canvas, "LeftLegCard", "LEFT LEG", "74%", new Vector2(0.60f, 0.045f), greenAccent);
        CreateLimbCard(canvas, "RightLegCard", "RIGHT LEG", "81%", new Vector2(0.84f, 0.045f), greenAccent);
    }

    private void StyleLiveText(string name, string fallback, Vector2 position, Vector2 size, TextAnchor alignment, Color color, int fontSize)
    {
        GameObject go = GameObject.Find(name);
        if (go == null)
        {
            return;
        }

        Text text = go.GetComponent<Text>();
        if (text == null)
        {
            return;
        }

        text.font = font;
        text.fontSize = fontSize;
        text.fontStyle = FontStyle.Bold;
        text.alignment = alignment;
        text.color = color;
        if (string.IsNullOrEmpty(text.text))
        {
            text.text = fallback;
        }

        Anchor(text.rectTransform, new Vector2(0f, 1f), position, size, new Vector2(0f, 1f));
    }

    private void CreateTopLabel(Transform parent, string name, string text, Vector2 position, Color color)
    {
        RectTransform label = CreateText(parent, name, text.ToUpperInvariant(), 16, TextAnchor.MiddleCenter, color);
        Anchor(label, new Vector2(0f, 1f), position, new Vector2(245f, 28f), new Vector2(0f, 1f));
    }

    private void CreateLimbCard(Transform parent, string name, string title, string value, Vector2 anchor, Color accent)
    {
        RectTransform card = CreatePanel(parent, name, new Color(0f, 0f, 0f, 0.78f));
        Anchor(card, anchor, Vector2.zero, new Vector2(300f, 82f), new Vector2(0.5f, 0.5f));

        Outline outline = card.gameObject.AddComponent<Outline>();
        outline.effectColor = new Color(1f, 1f, 1f, 0.14f);
        outline.effectDistance = new Vector2(1.4f, -1.4f);

        RectTransform icon = CreatePanel(card, "Accent", accent);
        Anchor(icon, new Vector2(0f, 0.5f), new Vector2(28f, 0f), new Vector2(34f, 34f), new Vector2(0f, 0.5f));

        RectTransform titleText = CreateText(card, "Title", title, 18, TextAnchor.MiddleLeft, Color.white);
        Anchor(titleText, new Vector2(0f, 0.5f), new Vector2(78f, 10f), new Vector2(145f, 28f), new Vector2(0f, 0.5f));

        RectTransform valueText = CreateText(card, "Value", value, 26, TextAnchor.MiddleLeft, Color.white);
        Anchor(valueText, new Vector2(0f, 0.5f), new Vector2(78f, -18f), new Vector2(80f, 36f), new Vector2(0f, 0.5f));

        RectTransform bars = CreatePanel(card, "Bars", new Color(1f, 1f, 1f, 0.1f));
        Anchor(bars, new Vector2(1f, 0.5f), new Vector2(-92f, -18f), new Vector2(105f, 10f), new Vector2(1f, 0.5f));
        RectTransform fill = CreatePanel(bars, "Fill", accent);
        Anchor(fill, new Vector2(0f, 0.5f), Vector2.zero, new Vector2(75f, 10f), new Vector2(0f, 0.5f));
    }

    private RectTransform CreateText(Transform parent, string name, string value, int size, TextAnchor alignment, Color color)
    {
        GameObject go = new GameObject(name);
        go.transform.SetParent(parent, false);
        RectTransform rect = go.AddComponent<RectTransform>();
        Text text = go.AddComponent<Text>();
        text.text = value;
        text.font = font;
        text.fontSize = size;
        text.fontStyle = FontStyle.Bold;
        text.alignment = alignment;
        text.color = color;
        text.horizontalOverflow = HorizontalWrapMode.Overflow;
        text.verticalOverflow = VerticalWrapMode.Overflow;
        return rect;
    }

    private RectTransform CreatePanel(Transform parent, string name, Color color)
    {
        GameObject go = new GameObject(name);
        go.transform.SetParent(parent, false);
        RectTransform rect = go.AddComponent<RectTransform>();
        Image image = go.AddComponent<Image>();
        image.color = color;
        return rect;
    }

    private static void Stretch(RectTransform rect, Vector2 min, Vector2 max)
    {
        rect.anchorMin = min;
        rect.anchorMax = max;
        rect.offsetMin = Vector2.zero;
        rect.offsetMax = Vector2.zero;
    }

    private static void Anchor(RectTransform rect, Vector2 anchor, Vector2 position, Vector2 size, Vector2 pivot)
    {
        rect.anchorMin = anchor;
        rect.anchorMax = anchor;
        rect.pivot = pivot;
        rect.anchoredPosition = position;
        rect.sizeDelta = size;
    }
}
