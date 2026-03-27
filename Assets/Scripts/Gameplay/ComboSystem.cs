using UnityEngine;
using System;

public class ComboSystem : MonoBehaviour
{
    public static ComboSystem Instance { get; private set; }
    public static event Action<int> OnComboChanged;

    public int CurrentCombo { get; private set; }
    public int MaxCombo { get; private set; }

    public static event Action<int> OnComboMilestone;

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    void OnEnable()
    {
        // Updated event signature
        HitZoneEvaluator.OnHitEvaluated += HandleHit;
        HitZoneEvaluator.OnTargetMissed += HandleMiss;
    }

    void OnDisable()
    {
        HitZoneEvaluator.OnHitEvaluated -= HandleHit;
        HitZoneEvaluator.OnTargetMissed -= HandleMiss;
    }

    private void HandleHit(HitQuality quality, int score, LaneType lane)
    {
        CurrentCombo++;
        if (CurrentCombo > MaxCombo)
        {
            MaxCombo = CurrentCombo;
        }
        OnComboChanged?.Invoke(CurrentCombo);

        // Fire milestone event at combo milestones: 5, 10, 15, 20, 30, 50
        if (ComboMilestonePopup.IsMilestone(CurrentCombo))
        {
            OnComboMilestone?.Invoke(CurrentCombo);
            // Play combo sound
            if (AudioManager.Instance != null)
                AudioManager.Instance.PlayComboSound();
        }
    }

    private void HandleMiss(int lane)
    {
        CurrentCombo = 0;
        OnComboChanged?.Invoke(CurrentCombo);
    }

    public void ResetCombo()
    {
        CurrentCombo = 0;
        MaxCombo = 0;
        OnComboChanged?.Invoke(CurrentCombo);
    }
}
