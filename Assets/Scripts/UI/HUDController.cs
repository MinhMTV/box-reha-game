using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Player-facing gameplay HUD only (score, combo, timer, accuracy, feedback). Diagnostics/debug
/// overlays are owned by DebugUI; do not add debug-only fields or F1 handling back here.
/// </summary>
public class HUDController : MonoBehaviour
{
    [SerializeField] private Text scoreText;
    [SerializeField] private Text comboText;
    [SerializeField] private Text timerText;
    [SerializeField] private Text accuracyText;
    // v3: Tough target and rapid fire feedback
    [SerializeField] private Text feedbackText;

    private int totalHits;
    private int goodOrBetterHits;

    // v3: Feedback text timer
    private float feedbackTimer = 0f;
    private const float FeedbackDuration = 1.5f;

    void OnEnable()
    {
        ScoreSystem.OnScoreChanged += UpdateScore;
        ComboSystem.OnComboChanged += UpdateCombo;
        ComboSystem.OnComboMilestone += ShowComboMilestone;
        SessionTimer.OnTimeChanged += UpdateTimer;
        HitZoneEvaluator.OnHitEvaluated += TrackAccuracy;
        HitZoneEvaluator.OnTargetMissed += TrackMissForAccuracy;
        // v3: Tough target events
        HitZoneEvaluator.OnToughTargetHit += ShowToughHitFeedback;
        HitZoneEvaluator.OnToughTargetDestroyed += ShowToughDestroyedFeedback;
        // v3: Rapid fire events
        HitZoneEvaluator.OnRapidFireChainProgress += ShowRapidFireProgress;
        HitZoneEvaluator.OnRapidFireChainComplete += ShowRapidFireComplete;
        HitZoneEvaluator.OnSensorForceEvaluated += ShowSensorForceFeedback;
    }

    void OnDisable()
    {
        ScoreSystem.OnScoreChanged -= UpdateScore;
        ComboSystem.OnComboChanged -= UpdateCombo;
        ComboSystem.OnComboMilestone -= ShowComboMilestone;
        SessionTimer.OnTimeChanged -= UpdateTimer;
        HitZoneEvaluator.OnHitEvaluated -= TrackAccuracy;
        HitZoneEvaluator.OnTargetMissed -= TrackMissForAccuracy;
        HitZoneEvaluator.OnToughTargetHit -= ShowToughHitFeedback;
        HitZoneEvaluator.OnToughTargetDestroyed -= ShowToughDestroyedFeedback;
        HitZoneEvaluator.OnRapidFireChainProgress -= ShowRapidFireProgress;
        HitZoneEvaluator.OnRapidFireChainComplete -= ShowRapidFireComplete;
        HitZoneEvaluator.OnSensorForceEvaluated -= ShowSensorForceFeedback;
    }

    void Update()
    {
        // v3: Auto-hide feedback text
        if (feedbackTimer > 0f)
        {
            feedbackTimer -= Time.deltaTime;
            if (feedbackTimer <= 0f && feedbackText != null)
            {
                feedbackText.text = "";
            }
        }
    }

    private void UpdateScore(int score)
    {
        if (scoreText != null)
            scoreText.text = score.ToString("N0");
    }

    private void UpdateCombo(int combo)
    {
        if (comboText != null)
            comboText.text = combo > 0 ? combo.ToString() : "";
    }

    private void UpdateTimer(float time)
    {
        if (timerText != null)
        {
            int minutes = Mathf.FloorToInt(time / 60f);
            int seconds = Mathf.FloorToInt(time % 60f);
            timerText.text = $"{minutes:00}:{seconds:00}";
        }
    }

    public void SetTimerLabel(string label)
    {
        if (timerText != null)
        {
            timerText.text = label;
        }
    }

    private void TrackAccuracy(HitQuality quality, int score, LaneType lane)
    {
        totalHits++;
        if (quality == HitQuality.Perfect || quality == HitQuality.Good)
            goodOrBetterHits++;

        UpdateAccuracyDisplay();
    }

    private void TrackMissForAccuracy(int lane)
    {
        totalHits++;
        UpdateAccuracyDisplay();
    }

    private void UpdateAccuracyDisplay()
    {
        if (accuracyText != null)
        {
            float accuracy = totalHits > 0 ? (float)goodOrBetterHits / totalHits * 100f : 0f;
            accuracyText.text = $"{accuracy:F0}%";
        }
    }

    /// <summary>
    /// v3: Show tough target hit feedback.
    /// </summary>
    private void ShowToughHitFeedback(int hitsLeft, int maxHits, LaneType lane, Vector3 position)
    {
        if (feedbackText != null)
        {
            feedbackText.text = $"HEAVY  {hitsLeft} / {maxHits}";
            feedbackText.color = new Color(1f, 0.3f, 0.3f);
            feedbackTimer = FeedbackDuration;
        }
    }

    /// <summary>
    /// v3: Show tough target destroyed feedback.
    /// </summary>
    private void ShowToughDestroyedFeedback(HitQuality quality, LaneType lane, Vector3 position)
    {
        if (feedbackText != null)
        {
            feedbackText.text = "HEAVY COMPLETE";
            feedbackText.color = Color.yellow;
            feedbackTimer = FeedbackDuration;
        }
    }

    /// <summary>
    /// v3: Show rapid fire chain progress.
    /// </summary>
    private void ShowRapidFireProgress(int current, int total, LaneType lane)
    {
        if (feedbackText != null)
        {
            feedbackText.text = $"RAPID FIRE CHAIN: {current}/{total}";
            feedbackText.color = new Color(1f, 0.5f, 0f);
            feedbackTimer = FeedbackDuration;
        }
    }

    /// <summary>
    /// v3: Show rapid fire chain complete.
    /// </summary>
    private void ShowRapidFireComplete(int bonus, LaneType lane)
    {
        if (feedbackText != null)
        {
            feedbackText.text = $"RAPID FIRE COMPLETE! +{bonus}";
            feedbackText.color = Color.yellow;
            feedbackTimer = 2f;
        }
    }

    private void ShowSensorForceFeedback(ForceBand forceBand, float normalizedForce)
    {
        if (feedbackText == null)
        {
            return;
        }

        switch (forceBand)
        {
            case ForceBand.Low:
                feedbackText.text = $"BELOW BASELINE ({normalizedForce:P0})";
                feedbackText.color = new Color(0.45f, 0.85f, 1f);
                break;
            case ForceBand.OnTarget:
                feedbackText.text = $"NEAR BASELINE ({normalizedForce:P0})";
                feedbackText.color = Color.green;
                break;
            default:
                feedbackText.text = $"ABOVE BASELINE ({normalizedForce:P0})";
                feedbackText.color = new Color(1f, 0.55f, 0.15f);
                break;
        }

        feedbackTimer = FeedbackDuration;
    }

    private void ShowComboMilestone(int combo)
    {
        ComboMilestonePopup.Show(combo);
    }
}
