using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

/// <summary>
/// Phase 4: Shows reaction time in results. Updated event signature.
/// </summary>
public class ResultsController : MonoBehaviour
{
    [SerializeField] private Text scoreText;
    [SerializeField] private Text accuracyText;
    [SerializeField] private Text perfectText;
    [SerializeField] private Text goodText;
    [SerializeField] private Text earlyText;
    [SerializeField] private Text lateText;
    [SerializeField] private Text missText;
    [SerializeField] private Text maxComboText;
    [SerializeField] private Text reactionTimeText;

    void Start()
    {
        DisplayResults();
    }

    private void DisplayResults()
    {
        if (GameManager.Instance == null || GameManager.Instance.SessionStats == null) return;

        GameSessionStats stats = GameManager.Instance.SessionStats;

        if (scoreText != null) scoreText.text = $"Final Score: {stats.Score}";
        if (accuracyText != null) accuracyText.text = $"Accuracy: {stats.Accuracy:P0}";
        if (perfectText != null) perfectText.text = $"Perfect: {stats.PerfectHits}";
        if (goodText != null) goodText.text = $"Good: {stats.GoodHits}";
        if (earlyText != null) earlyText.text = $"Early: {stats.EarlyHits}";
        if (lateText != null) lateText.text = $"Late: {stats.LateHits}";
        if (missText != null) missText.text = $"Misses: {stats.Misses}";
        if (maxComboText != null) maxComboText.text = $"Max Combo: {stats.MaxCombo}";
        if (reactionTimeText != null) reactionTimeText.text = $"Avg Reaction: {stats.AverageReactionTime:F2}s";
    }

    public void OnRestartButton()
    {
        GameManager.Instance?.StartGame();
    }

    public void OnMainMenuButton()
    {
        GameManager.Instance?.LoadMainMenu();
    }
}
