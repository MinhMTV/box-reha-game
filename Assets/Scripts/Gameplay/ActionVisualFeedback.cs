using UnityEngine;
using System.Collections;

/// <summary>
/// Phase 2 & 4: Visual feedback when player acts (brief color flash on lane).
/// Shows text popups (PERFECT/GOOD/MISS) and lane flashes.
/// Attach to a GameObject in the Game scene.
/// </summary>
public class ActionVisualFeedback : MonoBehaviour
{
    [Header("Lane Flash")]
    [SerializeField] private Renderer leftLaneRenderer;
    [SerializeField] private Renderer centerLaneRenderer;
    [SerializeField] private Renderer rightLaneRenderer;
    [SerializeField] private float flashDuration = 0.15f;

    [Header("Colors")]
    [SerializeField] private Color hitFlashColor = new Color(0.3f, 1f, 0.65f, 1f);
    [SerializeField] private Color missFlashColor = new Color(1f, 0.25f, 0.35f, 1f);
    [SerializeField] private Color perfectColor = new Color(1f, 0.9f, 0.2f, 1f);
    [SerializeField] private Color defaultLeftColor = new Color(0.11f, 0.33f, 0.55f, 1f);
    [SerializeField] private Color defaultCenterColor = new Color(0.16f, 0.52f, 0.72f, 1f);
    [SerializeField] private Color defaultRightColor = new Color(0.11f, 0.33f, 0.55f, 1f);

    void Awake()
    {
        defaultLeftColor = GameVisualPalette.GetLaneBaseColor(LaneType.Left);
        defaultCenterColor = GameVisualPalette.GetLaneBaseColor(LaneType.Center);
        defaultRightColor = GameVisualPalette.GetLaneBaseColor(LaneType.Right);
        hitFlashColor = GameVisualPalette.DodgeColor;
        missFlashColor = GameVisualPalette.MissColor;
        perfectColor = GameVisualPalette.PerfectColor;
    }

    void OnEnable()
    {
        HitZoneEvaluator.OnHitVisualFeedback += HandleHitFeedback;
        HitZoneEvaluator.OnMissVisualFeedback += HandleMissFeedback;
    }

    void OnDisable()
    {
        HitZoneEvaluator.OnHitVisualFeedback -= HandleHitFeedback;
        HitZoneEvaluator.OnMissVisualFeedback -= HandleMissFeedback;
    }

    private void HandleHitFeedback(HitQuality quality, LaneType lane, Vector3 position)
    {
        Color flashColor = quality == HitQuality.Perfect ? perfectColor : hitFlashColor;
        FlashLane(lane, flashColor);
    }

    private void HandleMissFeedback(LaneType lane, Vector3 position)
    {
        FlashLane(lane, missFlashColor);
    }

    private void FlashLane(LaneType lane, Color color)
    {
        Renderer renderer = GetLaneRenderer(lane);
        if (renderer != null)
        {
            StartCoroutine(FlashCoroutine(renderer, color, GetDefaultColor(lane)));
        }
    }

    private Renderer GetLaneRenderer(LaneType lane)
    {
        switch (lane)
        {
            case LaneType.Left: return leftLaneRenderer;
            case LaneType.Center: return centerLaneRenderer;
            case LaneType.Right: return rightLaneRenderer;
            default: return centerLaneRenderer;
        }
    }

    private Color GetDefaultColor(LaneType lane)
    {
        switch (lane)
        {
            case LaneType.Left: return defaultLeftColor;
            case LaneType.Center: return defaultCenterColor;
            case LaneType.Right: return defaultRightColor;
            default: return defaultCenterColor;
        }
    }

    private IEnumerator FlashCoroutine(Renderer renderer, Color flashColor, Color defaultColor)
    {
        Material material = renderer.material;
        Vector3 originalScale = renderer.transform.localScale;
        float elapsed = 0f;

        material.EnableKeyword("_EMISSION");
        while (elapsed < flashDuration)
        {
            elapsed += Time.deltaTime;
            float t = Mathf.Clamp01(elapsed / flashDuration);
            float pulse = 1f + Mathf.Sin(t * Mathf.PI) * 0.08f;
            renderer.transform.localScale = originalScale * pulse;
            material.color = Color.Lerp(flashColor, defaultColor, t);
            material.SetColor("_EmissionColor", Color.Lerp(flashColor * 2f, defaultColor * 1.2f, t));
            yield return null;
        }

        renderer.transform.localScale = originalScale;
        material.color = defaultColor;
        material.SetColor("_EmissionColor", defaultColor * 1.2f);
    }
}
