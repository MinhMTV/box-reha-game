using UnityEngine;
using System;
using System.Collections.Generic;

/// <summary>
/// Evaluates hits against targets in the hit zone.
/// Phase 2: Handles Block and Dodge targets, tracks reaction time.
/// v3: ToughTarget multi-hit support. RapidFire chain tracking.
/// </summary>
public class HitZoneEvaluator : MonoBehaviour
{
    public static event Action<HitQuality, int, LaneType> OnHitEvaluated;
    public static event Action<int> OnTargetMissed;
    // v3: Tough target events
    public static event Action<int, int, LaneType, Vector3> OnToughTargetHit; // hitsLeft, maxHits, lane, position
    public static event Action<HitQuality, LaneType, Vector3> OnToughTargetDestroyed;
    // v3: Rapid fire chain events
    public static event Action<int, int, LaneType> OnRapidFireChainProgress; // current, total, lane
    public static event Action<int, LaneType> OnRapidFireChainComplete; // bonus, lane

    // Phase 2: Visual feedback events
    public static event Action<HitQuality, LaneType, Vector3> OnHitVisualFeedback;
    public static event Action<LaneType, Vector3> OnMissVisualFeedback;
    public static event Action<ForceBand, float> OnSensorForceEvaluated;

    private List<TargetObject> activeTargets = new List<TargetObject>();

    // v3: Rapid fire chain tracking
    private struct RapidFireChain
    {
        public LaneType Lane;
        public int Total;
        public int Completed;
        public bool Active;
    }
    private RapidFireChain currentChain;

    private const float PerfectWindow = 0.1f;
    private const float GoodWindow = 0.25f;
    private const float EarlyLateWindow = 0.5f;

    private const int PerfectScore = 100;
    private const int GoodScore = 50;
    private const int EarlyLateScore = 25;
    private const int BlockScore = 75;
    private const int DodgeScore = 75;

    // v3: Partial hit score for tough targets
    private const int ToughPartialScore = 10;
    // v3: Rapid fire chain bonus
    public const int RapidFireChainBonus = 500;

    [SerializeField] private Transform hitZoneCenter;
    [SerializeField] private float minimumSensorPowerMultiplier = 0.75f;
    [SerializeField] private float maximumSensorPowerMultiplier = 1.25f;
    [SerializeField] private bool createRuntimeHitGuide = true;

    void Start()
    {
        if (hitZoneCenter == null)
        {
            hitZoneCenter = transform;
        }

        if (createRuntimeHitGuide)
        {
            EnsureHitGuide();
        }
    }

    /// <summary>
    /// v3: Start a rapid fire chain in a lane.
    /// </summary>
    public void StartRapidFireChain(LaneType lane, int totalTargets)
    {
        currentChain = new RapidFireChain
        {
            Lane = lane,
            Total = totalTargets,
            Completed = 0,
            Active = true
        };
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
            TextPopup.CreateMiss(bestTarget.transform.position);
            activeTargets.Remove(bestTarget);
            Destroy(bestTarget.gameObject);
            return;
        }

        // v3: Handle tough targets
        if (bestTarget.IsTough)
        {
            bool destroyed = bestTarget.TakeHit();
            int hitsLeft = bestTarget.MaxHits - bestTarget.CurrentHits;

            if (!destroyed)
            {
                // Partial hit - give small score, don't count as full hit
                ScoreSystem.AddToughPartialHit(ToughPartialScore);

                // Show tough hit feedback
                OnToughTargetHit?.Invoke(hitsLeft, bestTarget.MaxHits, bestTarget.Lane, bestTarget.transform.position);

                // Play tough hit sound
                if (AudioManager.Instance != null)
                    AudioManager.Instance.PlayToughHitSound();

                // Show popup
                TextPopup.Create(bestTarget.transform.position, $"HITS LEFT: {hitsLeft}", new Color(1f, 0.3f, 0.3f));

                // Flash
                bestTarget.Flash(Color.yellow, 0.1f);
                return; // Don't destroy, don't count in combo
            }

            // Destroyed - full scoring
            int score = GetScoreForQuality(quality, bestTarget.Type);

            if (AudioManager.Instance != null)
                AudioManager.Instance.PlayToughBreakSound();

            Color particleColor = HitParticleEffect.GetColorForTargetType(bestTarget.Type);
            HitParticleEffect.Spawn(bestTarget.transform.position, particleColor);

            float reactionTime = (float)(Time.realtimeSinceStartupAsDouble - bestTarget.SpawnTime);
            if (GameManager.Instance?.SessionStats != null)
            {
                GameManager.Instance.SessionStats.TrackReactionTime(reactionTime);
            }

            OnToughTargetDestroyed?.Invoke(quality, bestTarget.Lane, bestTarget.transform.position);
            OnHitEvaluated?.Invoke(quality, score, bestTarget.Lane);
            OnHitVisualFeedback?.Invoke(quality, bestTarget.Lane, bestTarget.transform.position);
            TextPopup.CreateForHitQuality(quality, bestTarget.transform.position);

            activeTargets.Remove(bestTarget);
            bestTarget.PlayDestroyAnimation(() => Destroy(bestTarget.gameObject));
            return;
        }

        // v3: Rapid fire chain tracking
        if (currentChain.Active && bestTarget.Lane == currentChain.Lane)
        {
            currentChain.Completed++;
            OnRapidFireChainProgress?.Invoke(currentChain.Completed, currentChain.Total, currentChain.Lane);

            if (currentChain.Completed >= currentChain.Total)
            {
                // Chain complete!
                OnRapidFireChainComplete?.Invoke(RapidFireChainBonus, currentChain.Lane);
                ScoreSystem.AddRapidFireChainBonus(RapidFireChainBonus);
                currentChain.Active = false;
            }
        }

        // Normal hit scoring
        int normalScore = GetScoreForQuality(quality, bestTarget.Type);
        normalScore = ApplyPowerNormalization(normalScore, action);

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

        if (quality != HitQuality.Miss)
        {
            Color particleColor = HitParticleEffect.GetColorForTargetType(bestTarget.Type);
            HitParticleEffect.Spawn(bestTarget.transform.position, particleColor);
        }

        float reactionTime2 = (float)(Time.realtimeSinceStartupAsDouble - bestTarget.SpawnTime);
        if (GameManager.Instance?.SessionStats != null)
        {
            GameManager.Instance.SessionStats.TrackReactionTime(reactionTime2);
            if (action.SourceType == InputSourceType.Sensor && action.RawForce > 0f)
            {
                PlayerProfile profile = GameManager.Instance.PlayerProfile;
                ForceBand forceBand = profile != null ? profile.GetForceBand(action.Power) : ForceBand.OnTarget;
                GameManager.Instance.SessionStats.TrackForce(action.RawForce, action.Power, forceBand);
                OnSensorForceEvaluated?.Invoke(forceBand, action.Power);
            }
        }

        OnHitEvaluated?.Invoke(quality, normalScore, bestTarget.Lane);
        OnHitVisualFeedback?.Invoke(quality, bestTarget.Lane, bestTarget.transform.position);
        TextPopup.CreateForHitQuality(quality, bestTarget.transform.position);

        activeTargets.Remove(bestTarget);
        bestTarget.PlayDestroyAnimation(() => Destroy(bestTarget.gameObject));
    }

    /// <summary>
    /// Check if the player's action matches the target type.
    /// v3: ToughPunch matches Punch action.
    /// </summary>
    private bool DoesActionMatchTarget(ActionType action, TargetType target)
    {
        switch (target)
        {
            case TargetType.Punch: return action == ActionType.Punch;
            case TargetType.ToughPunch: return action == ActionType.Punch;
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

        switch (targetType)
        {
            case TargetType.Block: return Mathf.Max(baseScore, BlockScore);
            case TargetType.Dodge: return Mathf.Max(baseScore, DodgeScore);
            case TargetType.ToughPunch: return Mathf.Max(baseScore, PerfectScore); // Tough targets give full punch score
            default: return baseScore;
        }
    }

    private int ApplyPowerNormalization(int baseScore, PlayerActionEvent action)
    {
        if (action.SourceType != InputSourceType.Sensor)
        {
            return baseScore;
        }

        float multiplier = Mathf.Clamp(action.Power, minimumSensorPowerMultiplier, maximumSensorPowerMultiplier);
        return Mathf.RoundToInt(baseScore * multiplier);
    }

    void OnTriggerEnter(Collider other)
    {
        TargetObject target = other.GetComponent<TargetObject>();
        if (target != null && !target.HasSpawnedInHitZone && !target.IsBreaking)
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
            if (!target.IsBreaking && activeTargets.Contains(target))
            {
                OnTargetMissed?.Invoke(target.Lane.GetHashCode());
                OnMissVisualFeedback?.Invoke(target.Lane, target.transform.position);
                TextPopup.CreateMiss(target.transform.position);
                activeTargets.Remove(target);
            }
        }
    }

    private void EnsureHitGuide()
    {
        if (transform.Find("HitGuideRoot") != null)
        {
            return;
        }

        GameObject guideRoot = new GameObject("HitGuideRoot");
        guideRoot.transform.SetParent(transform, false);
        guideRoot.transform.localPosition = Vector3.zero;

        CreateGuideBar(guideRoot.transform, "HitLine", new Vector3(0f, -2.25f, 0f), new Vector3(9.5f, 0.08f, 0.08f), new Color(0.20f, 0.82f, 1f, 1f), 2.4f);
        CreateGuideBar(guideRoot.transform, "HitFrameTop", new Vector3(0f, 2.25f, 0f), new Vector3(9.5f, 0.08f, 0.08f), new Color(0.12f, 0.42f, 0.72f, 1f), 1.2f);
        CreateGuideBar(guideRoot.transform, "HitFrameLeft", new Vector3(-4.5f, 0f, 0f), new Vector3(0.08f, 4.6f, 0.08f), new Color(0.12f, 0.42f, 0.72f, 1f), 1.2f);
        CreateGuideBar(guideRoot.transform, "HitFrameRight", new Vector3(4.5f, 0f, 0f), new Vector3(0.08f, 4.6f, 0.08f), new Color(0.12f, 0.42f, 0.72f, 1f), 1.2f);
    }

    private void CreateGuideBar(Transform parent, string name, Vector3 localPosition, Vector3 localScale, Color color, float emissionStrength)
    {
        GameObject guide = GameObject.CreatePrimitive(PrimitiveType.Cube);
        guide.name = name;
        guide.transform.SetParent(parent, false);
        guide.transform.localPosition = localPosition;
        guide.transform.localScale = localScale;

        Collider guideCollider = guide.GetComponent<Collider>();
        if (guideCollider != null)
        {
            Destroy(guideCollider);
        }

        Renderer renderer = guide.GetComponent<Renderer>();
        if (renderer == null)
        {
            return;
        }

        Material material = new Material(Shader.Find("Standard"));
        material.color = color;
        material.SetFloat("_Glossiness", 0.85f);
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", color * emissionStrength);
        renderer.sharedMaterial = material;
    }
}
