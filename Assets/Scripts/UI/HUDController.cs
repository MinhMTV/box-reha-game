using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 2: Shows accuracy. Phase 4: Debug toggle with D key.
/// </summary>
public class HUDController : MonoBehaviour
{
    [SerializeField] private Text scoreText;
    [SerializeField] private Text comboText;
    [SerializeField] private Text timerText;
    [SerializeField] private Text accuracyText;
    [SerializeField] private Text debugText;
    [SerializeField] private Text inputStateText;

    private int totalHits;
    private int goodOrBetterHits;
    private bool debugVisible;

    void OnEnable()
    {
        ScoreSystem.OnScoreChanged += UpdateScore;
        ComboSystem.OnComboChanged += UpdateCombo;
        SessionTimer.OnTimeChanged += UpdateTimer;
        HitZoneEvaluator.OnHitEvaluated += TrackAccuracy;
        HitZoneEvaluator.OnTargetMissed += TrackMissForAccuracy;
    }

    void OnDisable()
    {
        ScoreSystem.OnScoreChanged -= UpdateScore;
        ComboSystem.OnComboChanged -= UpdateCombo;
        SessionTimer.OnTimeChanged -= UpdateTimer;
        HitZoneEvaluator.OnHitEvaluated -= TrackAccuracy;
        HitZoneEvaluator.OnTargetMissed -= TrackMissForAccuracy;
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
}
