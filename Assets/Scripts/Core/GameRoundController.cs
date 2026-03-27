using UnityEngine;
using System;

public class GameRoundController : MonoBehaviour
{
    [SerializeField] private TargetSpawner targetSpawner;
    [SerializeField] private SessionTimer sessionTimer;
    [SerializeField] private ScoreSystem scoreSystem;
    [SerializeField] private ComboSystem comboSystem;
    [SerializeField] private HitZoneEvaluator hitZoneEvaluator;
    [SerializeField] private MouseTouchInputProvider inputProvider;
    [SerializeField] private HUDController hudController;

    private LevelDefinition currentLevel;
    private GameSessionStats sessionStats;
    private float roundStartTime;

    public static event Action<GameSessionStats> OnRoundEnd;

    void Start()
    {
        InitializeRound();
    }

    void OnEnable()
    {
        SessionTimer.OnTimeUp += HandleTimeUp;
        // Updated event signature
        HitZoneEvaluator.OnHitEvaluated += TrackHit;
        HitZoneEvaluator.OnTargetMissed += TrackMiss;
    }

    void OnDisable()
    {
        SessionTimer.OnTimeUp -= HandleTimeUp;
        HitZoneEvaluator.OnHitEvaluated -= TrackHit;
        HitZoneEvaluator.OnTargetMissed -= TrackMiss;
    }

    void Update()
    {
        // Difficulty ramp-up: update spawner speed/interval based on elapsed time
        if (currentLevel == null || targetSpawner == null) return;
        if (GameManager.Instance == null || GameManager.Instance.CurrentState != GameState.Playing) return;

        float elapsed = Time.time - roundStartTime;
        float ratio = Mathf.Clamp01(elapsed / currentLevel.DurationSeconds);

        // Speed: 80% → 130%
        float speedMultiplier = Mathf.Lerp(0.8f, 1.3f, ratio);
        // Spawn interval: 100% → 70%
        float intervalMultiplier = Mathf.Lerp(1f, 0.7f, ratio);

        targetSpawner.SetDifficultyModifiers(speedMultiplier, intervalMultiplier);
    }

    /// <summary>
    /// Get the current speed multiplier based on elapsed time (for use by spawner).
    /// </summary>
    public float GetCurrentSpeedMultiplier()
    {
        if (currentLevel == null) return 1f;
        float elapsed = Time.time - roundStartTime;
        float ratio = Mathf.Clamp01(elapsed / currentLevel.DurationSeconds);
        return Mathf.Lerp(0.8f, 1.3f, ratio);
    }

    public float GetCurrentIntervalMultiplier()
    {
        if (currentLevel == null) return 1f;
        float elapsed = Time.time - roundStartTime;
        float ratio = Mathf.Clamp01(elapsed / currentLevel.DurationSeconds);
        return Mathf.Lerp(1f, 0.7f, ratio);
    }

    private void InitializeRound()
    {
        if (GameManager.Instance == null) return;

        currentLevel = GameManager.Instance.CurrentLevel;
        if (currentLevel == null)
        {
            currentLevel = LevelDefinition.CreateLevel1();
        }

        sessionStats = GameManager.Instance.SessionStats;
        sessionStats.Reset();
        roundStartTime = Time.time;

        if (inputProvider != null)
        {
            inputProvider.IsEnabled = true;
        }

        if (scoreSystem != null)
        {
            scoreSystem.ResetScore();
        }

        if (comboSystem != null)
        {
            comboSystem.ResetCombo();
        }

        if (sessionTimer != null)
        {
            sessionTimer.StartTimer(currentLevel.DurationSeconds);
        }

        if (targetSpawner != null)
        {
            targetSpawner.StartSpawning(currentLevel);
        }

        if (inputProvider != null)
        {
            inputProvider.OnActionDetected += HandlePlayerAction;
        }
    }

    private void HandlePlayerAction(PlayerActionEvent action)
    {
        if (hitZoneEvaluator != null)
        {
            hitZoneEvaluator.EvaluateHit(action);
        }
    }

    private void TrackHit(HitQuality quality, int score, LaneType lane)
    {
        sessionStats.TotalTargets++;

        switch (quality)
        {
            case HitQuality.Perfect: sessionStats.PerfectHits++; break;
            case HitQuality.Good: sessionStats.GoodHits++; break;
            case HitQuality.Early: sessionStats.EarlyHits++; break;
            case HitQuality.Late: sessionStats.LateHits++; break;
        }

        sessionStats.Score = scoreSystem != null ? scoreSystem.CurrentScore : sessionStats.Score;
        sessionStats.FinalCombo = comboSystem != null ? comboSystem.CurrentCombo : sessionStats.FinalCombo;
        sessionStats.MaxCombo = comboSystem != null ? comboSystem.MaxCombo : sessionStats.MaxCombo;
    }

    private void TrackMiss(int lane)
    {
        sessionStats.TotalTargets++;
        sessionStats.Misses++;
        sessionStats.FinalCombo = 0;
    }

    private void HandleTimeUp()
    {
        EndRound();
    }

    private void EndRound()
    {
        if (inputProvider != null)
        {
            inputProvider.IsEnabled = false;
            inputProvider.OnActionDetected -= HandlePlayerAction;
        }

        if (targetSpawner != null)
        {
            targetSpawner.StopSpawning();
        }

        if (sessionTimer != null)
        {
            sessionTimer.StopTimer();
        }

        sessionStats.Score = scoreSystem != null ? scoreSystem.CurrentScore : sessionStats.Score;
        sessionStats.FinalCombo = comboSystem != null ? comboSystem.CurrentCombo : sessionStats.FinalCombo;
        sessionStats.MaxCombo = comboSystem != null ? comboSystem.MaxCombo : sessionStats.MaxCombo;

        OnRoundEnd?.Invoke(sessionStats);

        if (GameManager.Instance != null)
        {
            GameManager.Instance.EndGame();
        }
    }
}
