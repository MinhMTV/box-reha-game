using UnityEngine;
using System;
using System.Collections.Generic;

/// <summary>
/// Evaluates hits against targets in the hit zone.
/// Phase 2: Handles Block and Dodge targets, tracks reaction time.
/// Phase 2: Fires visual feedback events.
/// </summary>
public class HitZoneEvaluator : MonoBehaviour
{
    public static event Action<HitQuality, int, LaneType> OnHitEvaluated;
    public static event Action<int> OnTargetMissed;
    // Phase 2: Visual feedback events
    public static event Action<HitQuality, LaneType, Vector3> OnHitVisualFeedback;
    public static event Action<LaneType, Vector3> OnMissVisualFeedback;

    private List<TargetObject> activeTargets = new List<TargetObject>();

    private const float PerfectWindow = 0.1f;
    private const float GoodWindow = 0.25f;
    private const float EarlyLateWindow = 0.5f;

    private const int PerfectScore = 100;
    private const int GoodScore = 50;
    private const int EarlyLateScore = 25;
    private const int BlockScore = 75;
    private const int DodgeScore = 75;

    [SerializeField] private Transform hitZoneCenter;

    void Start()
    {
        if (hitZoneCenter == null)
        {
            hitZoneCenter = transform;
        }
    }

    public void RegisterTarget(TargetObject target)
    {
        if (!activeTargets.Contains(target))
        {
            activeTargets.Add(target);
        }
    }

    public void UnregisterTarget(TargetObject target)
    {
        activeTargets.Remove(target);
    }

    public void EvaluateHit(PlayerActionEvent action)
    {
        TargetObject bestTarget = null;
        float bestDistance = float.MaxValue;

        for (int i = activeTargets.Count - 1; i >= 0; i--)
        {
            TargetObject target = activeTargets[i];
            if (target == null)
            {
                activeTargets.RemoveAt(i);
                continue;
            }

            if (target.Lane != action.Lane) continue;

            // Phase 2: Check action type matches target type
            if (!DoesActionMatchTarget(action.ActionType, target.Type)) continue;

            float distance = Mathf.Abs(target.transform.position.z - hitZoneCenter.position.z);
            if (distance < bestDistance)
            {
                bestDistance = distance;
                bestTarget = target;
            }
        }

        if (bestTarget == null) return;

        float timingOffset = (hitZoneCenter.position.z - bestTarget.transform.position.z) / bestTarget.MoveSpeed;
        HitQuality quality = DetermineHitQuality(timingOffset);

        if (quality == HitQuality.Miss)
        {
            OnTargetMissed?.Invoke(bestTarget.Lane.GetHashCode());
            OnMissVisualFeedback?.Invoke(bestTarget.Lane, bestTarget.transform.position);
            // Phase 4: Miss popup
            TextPopup.CreateMiss(bestTarget.transform.position);
            activeTargets.Remove(bestTarget);
            Destroy(bestTarget.gameObject);
            return;
        }

        int score = GetScoreForQuality(quality, bestTarget.Type);

        // Play audio feedback
        if (AudioManager.Instance != null)
        {
            switch (quality)
            {
                case HitQuality.Miss:
                    AudioManager.Instance.PlayMissSound();
                    break;
                case HitQuality.Perfect:
                case HitQuality.Good:
                case HitQuality.Early:
                case HitQuality.Late:
                    switch (bestTarget.Type)
                    {
                        case TargetType.Punch: AudioManager.Instance.PlayHitSound(); break;
                        case TargetType.Block: AudioManager.Instance.PlayBlockSound(); break;
                        case TargetType.Dodge: AudioManager.Instance.PlayDodgeSound(); break;
                    }
                    break;
            }
        }

        // Spawn particle effect on hit
        if (quality != HitQuality.Miss)
        {
            Color particleColor = HitParticleEffect.GetColorForTargetType(bestTarget.Type);
            HitParticleEffect.Spawn(bestTarget.transform.position, particleColor);
        }

        // Phase 2: Track reaction time (time from spawn to player action)
        float reactionTime = (float)(Time.realtimeSinceStartupAsDouble - bestTarget.SpawnTime);
        if (GameManager.Instance?.SessionStats != null)
        {
            GameManager.Instance.SessionStats.TrackReactionTime(reactionTime);
        }

        OnHitEvaluated?.Invoke(quality, score, bestTarget.Lane);
        OnHitVisualFeedback?.Invoke(quality, bestTarget.Lane, bestTarget.transform.position);

        // Phase 4: Spawn floating text popup
        TextPopup.CreateForHitQuality(quality, bestTarget.transform.position);

        activeTargets.Remove(bestTarget);
        Destroy(bestTarget.gameObject);
    }

    /// <summary>
    /// Phase 2: Check if the player's action matches the target type.
    /// </summary>
    private bool DoesActionMatchTarget(ActionType action, TargetType target)
    {
        switch (target)
        {
            case TargetType.Punch: return action == ActionType.Punch;
            case TargetType.Block: return action == ActionType.Block;
            case TargetType.Dodge: return action == ActionType.Dodge;
            default: return false;
        }
    }

    private HitQuality DetermineHitQuality(float timingOffset)
    {
        float absOffset = Mathf.Abs(timingOffset);

        if (absOffset <= PerfectWindow) return HitQuality.Perfect;
        if (absOffset <= GoodWindow) return HitQuality.Good;
        if (absOffset <= EarlyLateWindow)
        {
            return timingOffset < 0 ? HitQuality.Early : HitQuality.Late;
        }
        return HitQuality.Miss;
    }

    private int GetScoreForQuality(HitQuality quality, TargetType targetType)
    {
        int baseScore;
        switch (quality)
        {
            case HitQuality.Perfect: baseScore = PerfectScore; break;
            case HitQuality.Good: baseScore = GoodScore; break;
            case HitQuality.Early:
            case HitQuality.Late: baseScore = EarlyLateScore; break;
            default: return 0;
        }

        // Block and Dodge get bonus based on type
        switch (targetType)
        {
            case TargetType.Block: return Mathf.Max(baseScore, BlockScore);
            case TargetType.Dodge: return Mathf.Max(baseScore, DodgeScore);
            default: return baseScore;
        }
    }

    void OnTriggerEnter(Collider other)
    {
        TargetObject target = other.GetComponent<TargetObject>();
        if (target != null && !target.HasSpawnedInHitZone)
        {
            target.HasSpawnedInHitZone = true;
            RegisterTarget(target);
        }
    }

    void OnTriggerExit(Collider other)
    {
        TargetObject target = other.GetComponent<TargetObject>();
        if (target != null)
        {
            // Auto-miss targets that leave the zone without being hit
            if (activeTargets.Contains(target))
            {
                OnTargetMissed?.Invoke(target.Lane.GetHashCode());
                OnMissVisualFeedback?.Invoke(target.Lane, target.transform.position);
                // Phase 4: Miss popup for auto-missed targets
                TextPopup.CreateMiss(target.transform.position);
                activeTargets.Remove(target);
            }
        }
    }
}
