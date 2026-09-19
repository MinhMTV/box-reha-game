using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Shows big "COMBO X!" text popup at combo milestones.
/// Spawns on HUDCanvas and fades out.
/// </summary>
public class ComboMilestonePopup : MonoBehaviour
{
    private static readonly int[] Milestones = { 5, 10, 15, 20, 30, 50 };
    private const string BuiltInFontName = "LegacyRuntime.ttf";

    [SerializeField] private float popupDuration = .7f;
    [SerializeField] private float scalePunch = 1.08f;
    static ComboMilestonePopup current;

    private Text popupText;
    private float timer;
    private Vector3 originalScale;
    private Color startColor;

    public static bool IsMilestone(int combo)
    {
        for (int i = 0; i < Milestones.Length; i++)
        {
            if (combo == Milestones[i]) return true;
        }
        return false;
    }

    public static void Show(int combo)
    {
        Canvas canvas = FindAnyObjectByType<Canvas>();
        if (canvas == null) return;
        if(current!=null){current.gameObject.SetActive(false);Destroy(current.gameObject);}

        GameObject obj = new GameObject("ComboMilestonePopup");
        obj.transform.SetParent(canvas.transform, false);

        Text text = obj.AddComponent<Text>();
        text.text = $"COMBO {combo}!";
        text.font = Resources.GetBuiltinResource<Font>(BuiltInFontName);
        text.fontSize = 28;
        text.raycastTarget = false;
        text.fontStyle = FontStyle.Bold;
        text.alignment = TextAnchor.MiddleCenter;
        text.color = new Color(1f, 0.92f, 0.22f, 1f);

        Outline outline = obj.AddComponent<Outline>();
        outline.effectColor = new Color(0.02f, 0.06f, 0.1f, 1f);
        outline.effectDistance = new Vector2(3f, -3f);

        Shadow shadow = obj.AddComponent<Shadow>();
        shadow.effectColor = new Color(0f, 0f, 0f, 0.5f);
        shadow.effectDistance = new Vector2(0f, -5f);

        RectTransform rect = obj.GetComponent<RectTransform>();
        rect.sizeDelta = new Vector2(280, 50);
        rect.anchorMin=rect.anchorMax=new Vector2(.5f,.82f);
        rect.anchoredPosition = Vector2.zero;

        ComboMilestonePopup popup = obj.AddComponent<ComboMilestonePopup>();
        current=popup;
        popup.popupText = text;
        popup.startColor = text.color;
        popup.originalScale = Vector3.one * popup.scalePunch;

        // Camera shake: shared DojoGameFeel supplies the small bounded camera impulse.
    }

    void Start()
    {
        timer = popupDuration;
        transform.localScale = originalScale;
    }

    void Update()
    {
        timer -= Time.deltaTime;
        if (timer <= 0f)
        {
            Destroy(gameObject);
            return;
        }

        float t = 1f - (timer / popupDuration);

        // Scale punch: start big, settle to normal
        float scaleT = Mathf.Clamp01(t * 3f);
        float scale = SettingsManager.ReducedMotion?1:Mathf.Lerp(scalePunch, 1f, scaleT);
        transform.localScale = Vector3.one * scale;

        // Float upward
        if(!SettingsManager.ReducedMotion)transform.localPosition += Vector3.up * 10f * Time.deltaTime;

        // Fade out in last half
        if (t > 0.5f)
        {
            float alpha = 1f - ((t - 0.5f) / 0.5f);
            if (popupText != null)
            {
                popupText.color = new Color(startColor.r, startColor.g, startColor.b, alpha);
            }
        }
    }
}
