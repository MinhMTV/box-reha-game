using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 4: Floating text popup on hit/miss.
/// Shows "PERFECT", "GOOD", "MISS" etc. floats up and fades.
/// </summary>
public class TextPopup : MonoBehaviour
{
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
        uiText.fontSize = 32;
        uiText.fontStyle = FontStyle.Bold;
        uiText.alignment = TextAnchor.MiddleCenter;

        RectTransform rect = popupObj.GetComponent<RectTransform>();
        rect.sizeDelta = new Vector2(200, 50);

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
                color = Color.yellow;
                break;
            case HitQuality.Good:
                text = "GOOD";
                color = Color.green;
                break;
            case HitQuality.Early:
                text = "EARLY";
                color = Color.cyan;
                break;
            case HitQuality.Late:
                text = "LATE";
                color = new Color(1f, 0.5f, 0f); // orange
                break;
            default:
                text = "MISS";
                color = Color.red;
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
