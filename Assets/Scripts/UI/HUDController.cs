using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 2: Shows accuracy. Phase 4: Debug toggle with D key.
/// v3: Tough target and rapid fire chain feedback display.
/// </summary>
public class HUDController : MonoBehaviour
{
    [SerializeField] private Text scoreText;
    [SerializeField] private Text comboText;
    [SerializeField] private Text timerText;
    [SerializeField] private Text accuracyText;
    [SerializeField] private Text debugText;
    [SerializeField] private Text inputStateText;
    // v3: Tough target and rapid fire feedback
    [SerializeField] private Text feedbackText;

    private int totalHits;
    private int goodOrBetterHits;
    private bool debugVisible;

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
    }

    void Update()
    {
        // Phase 4: Debug toggle
        if (Input.GetKeyDown(KeyCode.D))
        {
            debugVisible = !debugVisible;
            if (debugText != null) debugText.gameObject.SetActive(debugVisible);
            if (inputStateText != null) inputStateText.gameObject.SetActive(debugVisible);
        }

        // Phase 4: Show FPS in debug mode
        if (debugVisible && debugText != null)
        {
            float fps = 1f / Time.unscaledDeltaTime;
            debugText.text = $"FPS: {fps:F0}\nHits: {totalHits} | Good+: {goodOrBetterHits}";
        }

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
            scoreText.text = $"Score: {score}";
    }

    private void UpdateCombo(int combo)
    {
        if (comboText != null)
            comboText.text = combo > 0 ? $"Combo: {combo}x" : "";
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
            accuracyText.text = $"Accuracy: {accuracy:F0}%";
        }
    }

    /// <summary>
    /// v3: Show tough target hit feedback.
    /// </summary>
    private void ShowToughHitFeedback(int hitsLeft, int maxHits, LaneType lane, Vector3 position)
    {
        if (feedbackText != null)
        {
            feedbackText.text = $"TOUGH! HITS LEFT: {hitsLeft}";
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
            feedbackText.text = "TOUGH TARGET BROKEN!";
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

    public void UpdateDebug(string message)
    {
        if (debugText != null)
            debugText.text = message;
    }

    public void UpdateInputState(string state)
    {
        if (inputStateText != null)
            inputStateText.text = state;
    }

    private void ShowComboMilestone(int combo)
    {
        ComboMilestonePopup.Show(combo);
    }
}
