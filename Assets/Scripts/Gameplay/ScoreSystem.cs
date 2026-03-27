using UnityEngine;
using System;

public class ScoreSystem : MonoBehaviour
{
    public static event Action<int> OnScoreChanged;
    // v3: Rapid fire events for HUD
    public static event Action<int> OnRapidFireBonusAwarded;

    public int CurrentScore { get; private set; }

    private static ScoreSystem instance;

    void Awake()
    {
        instance = this;
    }

    void OnEnable()
    {
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

    /// <summary>
    /// v3: Add partial hit score for tough targets (not affected by combo).
    /// </summary>
    public static void AddToughPartialHit(int score)
    {
        if (instance == null) return;
        instance.CurrentScore += score;
        OnScoreChanged?.Invoke(instance.CurrentScore);
    }

    /// <summary>
    /// v3: Add rapid fire chain completion bonus.
    /// </summary>
    public static void AddRapidFireChainBonus(int bonus)
    {
        if (instance == null) return;
        instance.CurrentScore += bonus;
        OnScoreChanged?.Invoke(instance.CurrentScore);
        OnRapidFireBonusAwarded?.Invoke(bonus);
    }

    public void ResetScore()
    {
        CurrentScore = 0;
        OnScoreChanged?.Invoke(CurrentScore);
    }
}
