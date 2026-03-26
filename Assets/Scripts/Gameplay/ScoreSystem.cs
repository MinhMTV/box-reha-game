using UnityEngine;
using System;

public class ScoreSystem : MonoBehaviour
{
    public static event Action<int> OnScoreChanged;

    public int CurrentScore { get; private set; }

    void OnEnable()
    {
        // Updated event signature: now includes LaneType
        HitZoneEvaluator.OnHitEvaluated += HandleHit;
    }

    void OnDisable()
    {
        HitZoneEvaluator.OnHitEvaluated -= HandleHit;
    }

    private void HandleHit(HitQuality quality, int baseScore, LaneType lane)
    {
        int combo = ComboSystem.Instance != null ? ComboSystem.Instance.CurrentCombo : 0;
        float multiplier = Mathf.Min(1f + combo * 0.1f, 3f);
        int finalScore = Mathf.RoundToInt(baseScore * multiplier);
        CurrentScore += finalScore;
        OnScoreChanged?.Invoke(CurrentScore);
    }

    public void ResetScore()
    {
        CurrentScore = 0;
        OnScoreChanged?.Invoke(CurrentScore);
    }
}
