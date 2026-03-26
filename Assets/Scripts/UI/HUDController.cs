using UnityEngine;
using UnityEngine.UI;

public class HUDController : MonoBehaviour
{
    [SerializeField] private Text scoreText;
    [SerializeField] private Text comboText;
    [SerializeField] private Text timerText;
    [SerializeField] private Text accuracyText;
    [SerializeField] private Text debugText;

    void OnEnable()
    {
        ScoreSystem.OnScoreChanged += UpdateScore;
        ComboSystem.OnComboChanged += UpdateCombo;
        SessionTimer.OnTimeChanged += UpdateTimer;
    }

    void OnDisable()
    {
        ScoreSystem.OnScoreChanged -= UpdateScore;
        ComboSystem.OnComboChanged -= UpdateCombo;
        SessionTimer.OnTimeChanged -= UpdateTimer;
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

    public void UpdateDebug(string message)
    {
        if (debugText != null)
            debugText.text = message;
    }
}
