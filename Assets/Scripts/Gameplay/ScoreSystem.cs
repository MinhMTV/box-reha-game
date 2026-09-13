using UnityEngine;
using System;

public class ScoreSystem : MonoBehaviour
{
    public static event Action<int> OnScoreChanged;
    public static event Action<int> OnRapidFireBonusAwarded;
    public int CurrentScore { get; private set; }
    private static ScoreSystem instance;
    void Awake() { instance = this; }
    void OnDestroy() { if (instance == this) instance = null; }

    public static int AwardHit(int baseScore, string targetId, string actionId)
    {
        // Combo is advanced explicitly before scoring, independent of Unity subscriber order.
        ComboSystem.Instance?.RegisterHit();
        int combo = ComboSystem.Instance != null ? ComboSystem.Instance.CurrentCombo : 1;
        float multiplier = GameplayRules.ComboMultiplier(combo);
        return Award(baseScore, multiplier, combo, targetId, actionId, "hit");
    }
    private static int Award(int score, float multiplier, int combo, string targetId, string actionId, string reason)
    {
        if (instance == null) return 0;
        int awarded = Mathf.Max(0, Mathf.RoundToInt(score * multiplier));
        instance.CurrentScore += awarded;
        ResearchSessionLog.Score(score, multiplier, combo, awarded, instance.CurrentScore, targetId, actionId, reason);
        OnScoreChanged?.Invoke(instance.CurrentScore);
        return awarded;
    }
    public static void AddToughPartialHit(int score, string targetId = null, string actionId = null)
    { Award(score, 1f, ComboSystem.Instance != null ? ComboSystem.Instance.CurrentCombo : 0, targetId, actionId, "heavy_partial"); }
    public static void AddRapidFireChainBonus(int bonus, string targetId = null, string actionId = null)
    {
        Award(bonus, 1f, ComboSystem.Instance != null ? ComboSystem.Instance.CurrentCombo : 0, targetId, actionId, "chain_complete");
        OnRapidFireBonusAwarded?.Invoke(bonus);
    }
    public void ResetScore() { CurrentScore = 0; OnScoreChanged?.Invoke(CurrentScore); }
}
