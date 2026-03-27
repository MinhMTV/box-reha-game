using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 4: Floating text popup on hit/miss.
/// Shows "PERFECT", "GOOD", "MISS" etc. floats up and fades.
/// </summary>
public class TextPopup : MonoBehaviour
{
    private const string BuiltInFontName = "LegacyRuntime.ttf";

    [SerializeField] private float floatSpeed = 50f;
    [SerializeField] private float lifetime = 0.8f;

    private Text textComponent;
    private float timer;
    private Color startColor;

    void Start()
    {
        textComponent = GetComponent<Text>();
        if (textComponent != null)
        {
            startColor = textComponent.color;
        }
        timer = lifetime;
    }

    void Update()
    {
        timer -= Time.deltaTime;
        if (timer <= 0f)
        {
            Destroy(gameObject);
            return;
        }

        // Float upward
        transform.localPosition += Vector3.up * floatSpeed * Time.deltaTime;

        // Fade out
        if (textComponent != null)
        {
            float alpha = Mathf.Clamp01(timer / lifetime);
            textComponent.color = new Color(startColor.r, startColor.g, startColor.b, alpha);
        }
    }

    /// <summary>
    /// Create a text popup at the given world position.
    /// </summary>
    public static void Create(Vector3 worldPosition, string text, Color color, Transform parent = null)
    {
        // Create a UI canvas overlay if needed
        Canvas canvas = FindObjectOfType<Canvas>();
        if (canvas == null) return;

        GameObject popupObj = new GameObject("TextPopup");
        popupObj.transform.SetParent(canvas.transform, false);

        Text uiText = popupObj.AddComponent<Text>();
        uiText.text = text;
        uiText.color = color;
        uiText.font = Resources.GetBuiltinResource<Font>(BuiltInFontName);
        uiText.fontSize = 36;
        uiText.fontStyle = FontStyle.Bold;
        uiText.alignment = TextAnchor.MiddleCenter;

        Outline outline = popupObj.AddComponent<Outline>();
        outline.effectColor = new Color(0.02f, 0.06f, 0.1f, 0.95f);
        outline.effectDistance = new Vector2(2.5f, -2.5f);

        Shadow shadow = popupObj.AddComponent<Shadow>();
        shadow.effectColor = new Color(0f, 0f, 0f, 0.55f);
        shadow.effectDistance = new Vector2(0f, -4f);

        RectTransform rect = popupObj.GetComponent<RectTransform>();
        rect.sizeDelta = new Vector2(280, 68);

        // Convert world position to screen position
        Camera cam = Camera.main;
        if (cam != null)
        {
            Vector3 screenPos = cam.WorldToScreenPoint(worldPosition);
            rect.position = screenPos;
        }

        TextPopup popup = popupObj.AddComponent<TextPopup>();
        popup.textComponent = uiText;
        popup.startColor = color;
    }

    /// <summary>
    /// Create popup for hit quality.
    /// </summary>
    public static void CreateForHitQuality(HitQuality quality, Vector3 worldPosition)
    {
        string text;
        Color color;

        switch (quality)
        {
            case HitQuality.Perfect:
                text = "PERFECT!";
                color = new Color(1f, 0.92f, 0.25f, 1f);
                break;
            case HitQuality.Good:
                text = "GOOD";
                color = new Color(0.35f, 1f, 0.65f, 1f);
                break;
            case HitQuality.Early:
                text = "EARLY";
                color = new Color(0.35f, 0.9f, 1f, 1f);
                break;
            case HitQuality.Late:
                text = "LATE";
                color = new Color(1f, 0.6f, 0.15f, 1f);
                break;
            default:
                text = "MISS";
                color = new Color(1f, 0.28f, 0.35f, 1f);
                break;
        }

        Create(worldPosition, text, color);
    }

    /// <summary>
    /// Create miss popup.
    /// </summary>
    public static void CreateMiss(Vector3 worldPosition)
    {
        Create(worldPosition, "MISS", Color.red);
    }
}
