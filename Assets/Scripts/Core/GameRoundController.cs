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
    private static readonly Vector3 GameplayCameraPosition = new Vector3(0f, 2.25f, -5.75f);
    private static readonly Vector3 GameplayCameraRotation = new Vector3(4f, 0f, 0f);
    private const float GameplayCameraFov = 42f;

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
        if (inputProvider != null) inputProvider.OnActionDetected -= HandlePlayerAction;
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

        if (SessionInputSelection.Physical && !AndroidDynamicsController.EnsureInstance().Running)
        {
            if (inputProvider != null) inputProvider.IsEnabled = false;
            manager.LoadMainMenu();
            return;
        }

        currentLevel = manager.CurrentLevel;
        if (currentLevel == null)
        {
            currentLevel = LevelDefinition.CreateLevel1();
        }

        manager.CurrentState = GameState.Playing;
        Time.timeScale = 1f;
        sessionStats = manager.SessionStats;
        sessionStats.Reset();
        roundStartTime = Time.time;
        roundEnded = false;
        sessionStats.StartedUtc = DateTime.UtcNow.ToString("O");
        sessionStats.Mode = currentLevel.DisplayName;
        sessionStats.StudyId = manager.PlayerProfile.StudyId;
        sessionStats.SessionId = ResearchSessionLog.Begin(manager.PlayerProfile, currentLevel,
            SessionInputSelection.Label + " | " + (inputProvider != null ? inputProvider.GetStatusLine() : "No input provider"),
            targetSpawner != null ? targetSpawner.Configuration : null,
            SessionInputSelection.Physical ? AndroidDynamicsController.EnsureInstance().AcquisitionJson() : null);
        // Avoid exporting an absolute OS user-directory path with a pseudonymous session summary.
        sessionStats.LogPath = System.IO.Path.GetFileName(ResearchSessionLog.CurrentPath);
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
        if (roundEnded || sessionStats == null || GameManager.Instance == null ||
            GameManager.Instance.CurrentState != GameState.Playing) return;
        ResearchSessionLog.Action(action);
        sessionStats.TrackAction(action);
        if (hitZoneEvaluator != null)
        {
            hitZoneEvaluator.EvaluateHit(action);
        }
    }

    private void TrackHit(HitQuality quality, int score, LaneType lane)
    {
        if (sessionStats == null || roundEnded) return;
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
        if (sessionStats == null || roundEnded) return;
        sessionStats.TotalTargets++;
        sessionStats.Misses++;
        sessionStats.FinalCombo = 0;
    }

    private void HandleTimeUp()
    {
        FinishRound("time_limit");
    }

    private void EndRound()
    {
        FinishRound("player_stop");
    }

    public void FinishRound(string reason = "player_stop")
    {
        if (roundEnded || sessionStats == null)
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

        hitZoneEvaluator?.AbortRemaining();
        sessionStats.DurationSeconds = Mathf.Max(0f, Time.time - roundStartTime);
        sessionStats.StopReason = reason;

        sessionStats.Score = scoreSystem != null ? scoreSystem.CurrentScore : sessionStats.Score;
        sessionStats.FinalCombo = comboSystem != null ? comboSystem.CurrentCombo : sessionStats.FinalCombo;
        sessionStats.MaxCombo = comboSystem != null ? comboSystem.MaxCombo : sessionStats.MaxCombo;

        ResearchSessionLog.End(sessionStats, reason);
        SessionHistoryStore.Save(sessionStats);

        OnRoundEnd?.Invoke(sessionStats);

        if (GameManager.Instance != null)
        {
            GameManager.Instance.EndGame();
        }
    }

    void OnApplicationQuit()
    {
        if (!roundEnded && sessionStats != null)
        {
            roundEnded = true;
            hitZoneEvaluator?.AbortRemaining();
            sessionStats.DurationSeconds = Mathf.Max(0f, Time.time - roundStartTime);
            sessionStats.StopReason = "application_quit";
            sessionStats.Score = scoreSystem != null ? scoreSystem.CurrentScore : sessionStats.Score;
            ResearchSessionLog.End(sessionStats, "application_quit");
            SessionHistoryStore.Save(sessionStats);
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
