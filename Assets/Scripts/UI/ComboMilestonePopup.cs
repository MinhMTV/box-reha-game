using UnityEngine;
using UnityEngine.UI;
using System.Collections;

/// <summary>
/// Shows big "COMBO X!" text popup at combo milestones.
/// Includes camera shake effect.
/// Spawns on HUDCanvas and fades out.
/// </summary>
public class ComboMilestonePopup : MonoBehaviour
{
    private static readonly int[] Milestones = { 5, 10, 15, 20, 30, 50 };

    [SerializeField] private float popupDuration = 1.2f;
    [SerializeField] private float scalePunch = 1.5f;
    [SerializeField] private float shakeIntensity = 0.1f;
    [SerializeField] private float shakeDuration = 0.15f;

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
        Canvas canvas = FindObjectOfType<Canvas>();
        if (canvas == null) return;

        GameObject obj = new GameObject("ComboMilestonePopup");
        obj.transform.SetParent(canvas.transform, false);

        Text text = obj.AddComponent<Text>();
        text.text = $"COMBO {combo}!";
        text.fontSize = 64;
        text.fontStyle = FontStyle.Bold;
        text.alignment = TextAnchor.MiddleCenter;
        text.color = Color.yellow;

        Outline outline = obj.AddComponent<Outline>();
        outline.effectColor = Color.black;
        outline.effectDistance = new Vector2(2, -2);

        RectTransform rect = obj.GetComponent<RectTransform>();
        rect.sizeDelta = new Vector2(500, 100);
        rect.anchoredPosition = Vector2.zero;

        ComboMilestonePopup popup = obj.AddComponent<ComboMilestonePopup>();
        popup.popupText = text;
        popup.startColor = text.color;
        popup.originalScale = Vector3.one * popup.scalePunch;

        // Camera shake
        CameraShake.ShakeAll(popup.shakeIntensity, popup.shakeDuration);
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
        float scale = Mathf.Lerp(scalePunch, 1f, scaleT);
        transform.localScale = Vector3.one * scale;

        // Float upward
        transform.localPosition += Vector3.up * 30f * Time.deltaTime;

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

/// <summary>
/// Simple camera shake utility.
/// </summary>
public class CameraShake : MonoBehaviour
{
    private static CameraShake instance;
    private Vector3 originalPosition;
    private float shakeIntensity;
    private float shakeTimer;

    public static void ShakeAll(float intensity, float duration)
    {
        Camera cam = Camera.main;
        if (cam == null) return;

        CameraShake shake = cam.GetComponent<CameraShake>();
        if (shake == null)
        {
            shake = cam.gameObject.AddComponent<CameraShake>();
        }
        shake.Shake(intensity, duration);
    }

    public void Shake(float intensity, float duration)
    {
        originalPosition = transform.localPosition;
        shakeIntensity = intensity;
        shakeTimer = duration;
    }

    void Update()
    {
        if (shakeTimer > 0f)
        {
            shakeTimer -= Time.deltaTime;
            float x = Random.Range(-1f, 1f) * shakeIntensity;
            float y = Random.Range(-1f, 1f) * shakeIntensity;
            transform.localPosition = originalPosition + new Vector3(x, y, 0f);

            if (shakeTimer <= 0f)
            {
                transform.localPosition = originalPosition;
            }
        }
    }
}
