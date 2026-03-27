using UnityEngine;

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

    private System.Collections.IEnumerator FlashCoroutine(Renderer renderer, Color flashColor, Color defaultColor)
    {
        renderer.material.color = flashColor;
        yield return new WaitForSeconds(flashDuration);
        renderer.material.color = defaultColor;
    }
}
