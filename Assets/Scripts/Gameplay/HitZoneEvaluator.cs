using UnityEngine;
using System;
using System.Collections.Generic;

public class HitZoneEvaluator : MonoBehaviour
{
    public static event Action<HitQuality, int> OnHitEvaluated;
    public static event Action<int> OnTargetMissed;

    private List<TargetObject> activeTargets = new List<TargetObject>();

    private const float PerfectWindow = 0.1f;
    private const float GoodWindow = 0.25f;
    private const float EarlyLateWindow = 0.5f;

    private const int PerfectScore = 100;
    private const int GoodScore = 50;
    private const int EarlyLateScore = 25;

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
            activeTargets.Remove(bestTarget);
            Destroy(bestTarget.gameObject);
            return;
        }

        int score = GetScoreForQuality(quality);
        OnHitEvaluated?.Invoke(quality, score);

        activeTargets.Remove(bestTarget);
        Destroy(bestTarget.gameObject);
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

    private int GetScoreForQuality(HitQuality quality)
    {
        switch (quality)
        {
            case HitQuality.Perfect: return PerfectScore;
            case HitQuality.Good: return GoodScore;
            case HitQuality.Early:
            case HitQuality.Late: return EarlyLateScore;
            default: return 0;
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
            UnregisterTarget(target);
        }
    }
}
