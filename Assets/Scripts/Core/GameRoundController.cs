using UnityEngine;
using System;

public class GameRoundController : MonoBehaviour
{
    [SerializeField] private TargetSpawner targetSpawner;
    [SerializeField] private SessionTimer sessionTimer;
    [SerializeField] private ScoreSystem scoreSystem;
    [SerializeField] private ComboSystem comboSystem;
    [SerializeField] private HitZoneEvaluator hitZoneEvaluator;
    [SerializeField] private InputProviderRouter inputProvider;
    [SerializeField] private HUDController hudController;

    private LevelDefinition currentLevel;
    private GameSessionStats sessionStats;
    private float roundStartTime;
    private bool roundEnded;
    private static readonly Vector3 GameplayCameraPosition = new Vector3(0f, 2.45f, -7.8f);
    private static readonly Vector3 GameplayCameraRotation = new Vector3(10f, 0f, 0f);
    private const float GameplayCameraFov = 52f;

    public static event Action<GameSessionStats> OnRoundEnd;

    void Start()
    {
        InitializeRound();
    }

    void OnEnable()
    {
        SessionTimer.OnTimeUp += HandleTimeUp;
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
        if (currentLevel == null || targetSpawner == null)
        {
            return;
        }

        if (GameManager.Instance == null || GameManager.Instance.CurrentState != GameState.Playing)
        {
            return;
        }

        if (hudController != null && inputProvider != null)
        {
            hudController.UpdateInputState(inputProvider.GetStatusLine());
        }

        if (currentLevel.IsEndless && Input.GetKeyDown(KeyCode.Return))
        {
            EndRound();
            return;
        }

        float elapsed = Time.time - roundStartTime;
        float difficultyProgress = GetDifficultyProgress(elapsed);
        float speedMultiplier = Mathf.Lerp(currentLevel.StartSpeedMultiplier, currentLevel.MaxSpeedMultiplier, difficultyProgress);
        float intervalMultiplier = Mathf.Lerp(currentLevel.StartIntervalMultiplier, currentLevel.MinIntervalMultiplier, difficultyProgress);
        float toughChanceExtra = Mathf.Lerp(0f, Mathf.Max(0f, currentLevel.MaxToughTargetChance - currentLevel.ToughTargetChance), difficultyProgress);
        float rapidFireChanceExtra = Mathf.Lerp(0f, Mathf.Max(0f, currentLevel.MaxRapidFireChance - currentLevel.RapidFireChance), difficultyProgress);

        targetSpawner.SetDifficultyModifiers(speedMultiplier, intervalMultiplier, toughChanceExtra, rapidFireChanceExtra);
    }

    public float GetCurrentSpeedMultiplier()
    {
        if (currentLevel == null)
        {
            return 1f;
        }

        float elapsed = Time.time - roundStartTime;
        return Mathf.Lerp(currentLevel.StartSpeedMultiplier, currentLevel.MaxSpeedMultiplier, GetDifficultyProgress(elapsed));
    }

    public float GetCurrentIntervalMultiplier()
    {
        if (currentLevel == null)
        {
            return 1f;
        }

        float elapsed = Time.time - roundStartTime;
        return Mathf.Lerp(currentLevel.StartIntervalMultiplier, currentLevel.MinIntervalMultiplier, GetDifficultyProgress(elapsed));
    }

    private void InitializeRound()
    {
        GameManager manager = GameManager.EnsureInstance();
        if (manager == null)
        {
            return;
        }

        currentLevel = manager.CurrentLevel;
        if (currentLevel == null)
        {
            currentLevel = LevelDefinition.CreateLevel1();
        }

        manager.CurrentState = GameState.Playing;
        sessionStats = manager.SessionStats;
        sessionStats.Reset();
        roundStartTime = Time.time;
        roundEnded = false;
        EnsureGameplayCameraView();

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
            if (currentLevel.IsEndless)
            {
                sessionTimer.StopTimer();
            }
            else
            {
                sessionTimer.StartTimer(currentLevel.DurationSeconds);
            }
        }

        if (targetSpawner != null)
        {
            targetSpawner.StartSpawning(currentLevel);
        }

        if (hudController != null && currentLevel.IsEndless)
        {
            hudController.SetTimerLabel("ENDLESS");
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
        if (roundEnded)
        {
            return;
        }

        roundEnded = true;

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

    private float GetDifficultyProgress(float elapsed)
    {
        if (currentLevel == null)
        {
            return 0f;
        }

        return Mathf.Clamp01(elapsed / Mathf.Max(1f, currentLevel.RampDurationSeconds));
    }

    private void EnsureGameplayCameraView()
    {
        Camera camera = Camera.main;
        if (camera == null)
        {
            return;
        }

        camera.transform.position = GameplayCameraPosition;
        camera.transform.rotation = Quaternion.Euler(GameplayCameraRotation);
        camera.fieldOfView = GameplayCameraFov;
    }
}
