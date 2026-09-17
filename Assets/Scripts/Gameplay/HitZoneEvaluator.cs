using UnityEngine;
using System;
using System.Collections.Generic;

/// <summary>Time-based action matching. Targets resolve once; pause uses the scaled gameplay clock.</summary>
public class HitZoneEvaluator : MonoBehaviour
{
    public static event Action<HitQuality, int, LaneType> OnHitEvaluated;
    public static event Action<int> OnTargetMissed;
    public static event Action<int, int, LaneType, Vector3> OnToughTargetHit;
    public static event Action<HitQuality, LaneType, Vector3> OnToughTargetDestroyed;
    public static event Action<int, int, LaneType> OnRapidFireChainProgress;
    public static event Action<int, LaneType> OnRapidFireChainComplete;
    public static event Action<HitQuality, LaneType, Vector3> OnHitVisualFeedback;
    public static event Action<LaneType, Vector3> OnMissVisualFeedback;
    public static event Action<ForceBand, float> OnSensorForceEvaluated;
    public static event Action<TargetObject, HitQuality, bool> OnTargetFeedback;
    public static event Action<string,int> OnPatternComplete;
    public const int RapidFireChainBonus = 500;
    [SerializeField] private Transform hitZoneCenter;
    [SerializeField] private float minimumSensorPowerMultiplier = 0.75f;
    [SerializeField] private float maximumSensorPowerMultiplier = 1.25f;
    [SerializeField] private bool createRuntimeHitGuide = true;
    private readonly List<TargetObject> activeTargets = new List<TargetObject>();
    private class Chain { public int Total, Completed; public bool Failed; public LaneType Lane; public string PatternId; }
    private readonly Dictionary<string, Chain> chains = new Dictionary<string, Chain>();
    public Vector3 HitZonePosition => hitZoneCenter != null ? hitZoneCenter.position : transform.position;
    public float HitZoneZ => HitZonePosition.z;
    public IReadOnlyList<TargetObject> ActiveTargets => activeTargets;

    public const float PlayerHitPlaneZ = 2f;
    void Awake() { if(hitZoneCenter != null) { var p=hitZoneCenter.position; p.z=PlayerHitPlaneZ; hitZoneCenter.position=p; } else {var p=transform.position;p.z=PlayerHitPlaneZ;transform.position=p;} }
    void Start()
    {
        if (createRuntimeHitGuide && GetComponent<HitZoneVisualizer>() == null)
            gameObject.AddComponent<HitZoneVisualizer>();
        if (GetComponent<DojoGameFeel>() == null) gameObject.AddComponent<DojoGameFeel>();
    }
    public string StartRapidFireChain(LaneType lane, int totalTargets)
    {
        string id = Guid.NewGuid().ToString("N");
        chains[id] = new Chain { Lane = lane, Total = totalTargets };
        return id;
    }
    public string StartActionPattern(string patternId,LaneType lane,int total)
    {
        string id=StartRapidFireChain(lane,total);chains[id].PatternId=patternId;return id;
    }
    public void RegisterTarget(TargetObject target)
    {
        if (target != null && !target.IsResolved && !activeTargets.Contains(target)) activeTargets.Add(target);
    }
    public void UnregisterTarget(TargetObject target) { activeTargets.Remove(target); }
    void Update()
    {
        if (GameManager.Instance != null && GameManager.Instance.CurrentState != GameState.Playing) return;
        for (int i = activeTargets.Count - 1; i >= 0; i--)
        {
            TargetObject target = activeTargets[i];
            if (target == null || target.IsResolved) { activeTargets.RemoveAt(i); continue; }
            if (target.IsDeploying) continue;
            float offset = TimingOffset(target);
            if (target.IsTough && target.transform.position.z <= HitZoneZ)
            {
                target.LockInHitZone(HitZoneZ);
                if (Time.time - target.LockedTime >= target.HeavyTimeoutSeconds) Miss(target, "heavy_timeout");
            }
            else if (offset > HalfWindow(target)) Miss(target, "miss");
        }
    }
    public static float HalfWindow(TargetObject target) { return target.HitWindow * 0.5f; }
    public float TimingOffset(TargetObject target)
    { return (HitZoneZ - target.transform.position.z) / Mathf.Max(0.01f, target.MoveSpeed); }
    public HitQuality PreviewTiming(TargetObject target)
    {
        if (target == null || target.IsResolved || target.IsDeploying) return HitQuality.Miss;
        return target.IsLockedInHitZone ? HitQuality.Good : DetermineHitQuality(TimingOffset(target), HalfWindow(target));
    }
    public static HitQuality DetermineHitQuality(float offset, float halfWindow)
    {
        return GameplayRules.Timing(offset, halfWindow);
    }
    public static bool Matches(PlayerActionEvent action, TargetObject target)
    {
        if (target == null || target.IsBreaking || target.IsResolved || target.IsDeploying) return false;
        return GameplayRules.Matches(action.ActionType, action.BodySide, action.Lane, action.VerticalPos,
            target.Type, target.Lane, target.IsTough);
    }
    public void EvaluateHit(PlayerActionEvent action)
    {
        if (GameManager.Instance != null && GameManager.Instance.CurrentState != GameState.Playing) return;
        if (!action.IsValid || float.IsNaN(action.Power) || float.IsInfinity(action.Power) || action.Power < 0f) return;
        TargetObject best = null;
        float bestDistance = float.MaxValue;
        foreach (TargetObject target in activeTargets)
        {
            if (!Matches(action, target)) continue;
            if (target.IsDeploying) continue;
            float offset = TimingOffset(target);
            if (!target.IsLockedInHitZone && Mathf.Abs(offset) > HalfWindow(target)) continue;
            float distance = Mathf.Abs(offset);
            if (distance < bestDistance) { best = target; bestDistance = distance; }
        }
        // An unmatched / premature action is logged by GameRoundController; it does not destroy a future target.
        if (best == null) return;
        float timing = TimingOffset(best);
        HitQuality quality = best.IsLockedInHitZone ? HitQuality.Good : DetermineHitQuality(timing, HalfWindow(best));
        if (quality == HitQuality.Miss) return;
        float threshold = PersonalGameplayBalance.RequiredStrength(GameManager.Instance != null ? GameManager.Instance.SelectedLevel : 1);
        if(action.NormalizationValid && action.Power < threshold)
        {
            if(GameManager.Instance?.SessionStats != null)GameManager.Instance.SessionStats.BelowStrengthHits++;
            ResearchSessionLog.BelowStrength(best,action,threshold);
            best.GetComponent<TargetMountMotion>()?.Impact(true);
            OnTargetFeedback?.Invoke(best, quality, true);
            TextPopup.Create(best.transform.position,"TOO LIGHT",new Color(1f,.72f,.3f));best.Flash(Color.white,.08f);
            return;
        }
        best.GetComponent<TargetMountMotion>()?.Impact();
        if (best.IsTough)
        {
            // Uncalibrated sensor events receive neutral gameplay damage, never an invented physical baseline.
            float power = action.NormalizationValid ? action.Power : 1f;
            int before = best.CurrentHits;
            bool broken = best.TakeHit(power);
            ResearchSessionLog.HeavyImpact(best, action, best.CurrentHits - before);
            if (!broken)
            {
                ScoreSystem.AddToughPartialHit(10, best.TargetId, action.EventId);
                OnToughTargetHit?.Invoke(best.MaxHits - best.CurrentHits, best.MaxHits, best.Lane, best.transform.position);
                HitParticleEffect.Spawn(best.transform.position, HitParticleEffect.GetColorForTargetType(best.Type), 12);
                DojoGameFeel.Cue(DojoAudioCue.HeavyDamage,best.IsKick);
                best.Flash(Color.white, 0.08f);
                OnTargetFeedback?.Invoke(best, quality, false);
                return;
            }

        }
        if (!ResolveTarget(best)) return;
        int baseScore = quality == HitQuality.Perfect ? 100 : quality == HitQuality.Good ? 50 : 25;
        if (best.IsTough) baseScore = 100;
        if (action.SourceType == InputSourceType.Sensor && action.NormalizationValid)
        {
            baseScore = Mathf.RoundToInt(baseScore * Mathf.Clamp(action.Power, minimumSensorPowerMultiplier, maximumSensorPowerMultiplier));
            ForceBand band = GameManager.Instance?.PlayerProfile != null
                ? GameManager.Instance.PlayerProfile.GetForceBand(action.Power) : ForceBand.OnTarget;
            OnSensorForceEvaluated?.Invoke(band, action.Power);
        }
        if (best.IsTough) baseScore += 350;

        TrackResolution(best, true);
        GameManager.Instance?.SessionStats?.TrackTargetResolutionTime(Mathf.Max(0f, Time.time - best.SpawnTime));
        ResearchSessionLog.TargetResolved(best, "hit", action.EventId, quality, timing);
        int awarded = ScoreSystem.AwardHit(baseScore, best.TargetId, action.EventId);
        TrackChain(best, true, action.EventId);
        best.PlayDestroyAnimation(null, best.IsTough || quality == HitQuality.Perfect);
        OnTargetFeedback?.Invoke(best, quality, false);
        OnHitEvaluated?.Invoke(quality, awarded, best.Lane);
        OnHitVisualFeedback?.Invoke(quality, best.Lane, best.transform.position);
        if(best.IsTough){OnToughTargetDestroyed?.Invoke(quality,best.Lane,best.transform.position);DojoGameFeel.Cue(DojoAudioCue.HeavyBreak,best.IsKick);}
        else DojoGameFeel.Cue(best.IsKick?DojoAudioCue.KickImpact:DojoAudioCue.PunchImpact);
        HitParticleEffect.Spawn(best.transform.position, HitParticleEffect.GetColorForTargetType(best.Type),
            HitParticleEffect.GetParticleCountForTargetType(best.Type));
        TextPopup.CreateForHitQuality(quality, best.transform.position);

    }
    private bool ResolveTarget(TargetObject target)
    {
        if(target==null||!target.Resolve())return false;
        activeTargets.Remove(target);
        return true;
    }
    public void Miss(TargetObject target, string outcome)
    {
        if (!ResolveTarget(target)) return;
        Destroy(target.gameObject);
        TrackResolution(target, false);
        TrackChain(target, false, null);
        if (outcome == "heavy_timeout" && GameManager.Instance?.SessionStats != null)
            GameManager.Instance.SessionStats.HeavyTimeouts++;
        ResearchSessionLog.TargetResolved(target, outcome);
        OnTargetFeedback?.Invoke(target, HitQuality.Miss, false);
        OnTargetMissed?.Invoke((int)target.Lane);
        OnMissVisualFeedback?.Invoke(target.Lane, target.transform.position);
        TextPopup.CreateMiss(target.transform.position);
        AudioManager.Instance?.PlayMissSound();
    }
    public void AbortRemaining()
    {
        // Include objects spawned this frame whose Start has not yet run.
        foreach (TargetObject target in FindObjectsByType<TargetObject>(FindObjectsSortMode.None))
        {
            target.EnsureTrackedSpawn();
            if (!target.IsResolved && target.Resolve())
            {
                if (GameManager.Instance?.SessionStats != null) GameManager.Instance.SessionStats.AbortedTargets++;
                ResearchSessionLog.TargetResolved(target, "aborted");
            }
            Destroy(target.gameObject);
        }
        activeTargets.Clear();
        chains.Clear();
    }
    private void TrackResolution(TargetObject target, bool hit)
    {
        if (GameManager.Instance?.SessionStats == null) return;
        GameManager.Instance.SessionStats.TrackTargetType(target.Type, hit);
        GameManager.Instance.SessionStats.TrackLane(target.Lane, hit);
    }
    private void TrackChain(TargetObject target, bool hit, string actionId)
    {
        if (string.IsNullOrEmpty(target.ChainId) || !chains.TryGetValue(target.ChainId, out Chain chain)) return;
        if (!hit) chain.Failed = true;
        chain.Completed++;
        if(chain.PatternId==null)OnRapidFireChainProgress?.Invoke(chain.Completed, chain.Total, chain.Lane);
        if (chain.Completed < chain.Total) return;
        if (!chain.Failed)
        {
            if(chain.PatternId!=null)
            {
                OnPatternComplete?.Invoke(chain.PatternId,chain.Total);
                TextPopup.Create(target.transform.position,chain.Total+" HIT",GameVisualPalette.GetTargetColor(target.Type));
            }
            else
            {
                ScoreSystem.AddRapidFireChainBonus(RapidFireChainBonus, target.TargetId, actionId);
                OnRapidFireChainComplete?.Invoke(RapidFireChainBonus, chain.Lane);
            }
        }
        chains.Remove(target.ChainId);
    }
}
