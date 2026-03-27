using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

/// <summary>
/// Phase 4+: Shows reaction time, stars, best score, new high score, games played.
/// Saves to leaderboard after each round.
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
    // New fields
    [SerializeField] private Text starsText;
    [SerializeField] private Text bestScoreText;
    [SerializeField] private Text newHighScoreText;
    [SerializeField] private Text gamesPlayedText;

    void Start()
    {
        SaveToLeaderboard();
        DisplayResults();
    }

    private void SaveToLeaderboard()
    {
        if (GameManager.Instance == null || GameManager.Instance.SessionStats == null) return;

        GameSessionStats stats = GameManager.Instance.SessionStats;
        int level = GameManager.Instance.SelectedLevel;

        // Increment games played
        int gamesPlayed = LeaderboardManager.IncrementGamesPlayed();

        // Save score to leaderboard
        LeaderboardManager.SaveScore(level, stats.Score, stats.Accuracy, stats.MaxCombo);
    }

    private void DisplayResults()
    {
        if (GameManager.Instance == null || GameManager.Instance.SessionStats == null) return;

        GameSessionStats stats = GameManager.Instance.SessionStats;
        int level = GameManager.Instance.SelectedLevel;

        if (scoreText != null) scoreText.text = $"Final Score: {stats.Score}";
        if (accuracyText != null) accuracyText.text = $"Accuracy: {stats.Accuracy:P0}";
        if (perfectText != null) perfectText.text = $"Perfect: {stats.PerfectHits}";
        if (goodText != null) goodText.text = $"Good: {stats.GoodHits}";
        if (earlyText != null) earlyText.text = $"Early: {stats.EarlyHits}";
        if (lateText != null) lateText.text = $"Late: {stats.LateHits}";
        if (missText != null) missText.text = $"Misses: {stats.Misses}";
        if (maxComboText != null) maxComboText.text = $"Max Combo: {stats.MaxCombo}";
        if (reactionTimeText != null) reactionTimeText.text = $"Avg Reaction: {stats.AverageReactionTime:F2}s";

        // Star rating
        int stars = StarRating.CalculateStars(stats.Accuracy);
        if (starsText != null)
        {
            starsText.text = StarRating.GetStarDisplay(stars);
            starsText.color = StarRating.GetStarColor(stars);
            starsText.fontSize = 48;
        }

        // Best score for this level
        int bestScore = LeaderboardManager.GetBestScore(level);
        if (bestScoreText != null)
            bestScoreText.text = $"Best Score (Lv{level}): {bestScore}";

        // New high score indicator
        if (newHighScoreText != null)
        {
            if (LeaderboardManager.IsNewHighScore(level, stats.Score))
            {
                newHighScoreText.text = "★ NEW HIGH SCORE! ★";
                newHighScoreText.color = Color.yellow;
                newHighScoreText.fontSize = 36;
            }
            else
            {
                newHighScoreText.text = "";
            }
        }

        // Games played
        if (gamesPlayedText != null)
        {
            int totalGames = LeaderboardManager.GetGamesPlayed();
            gamesPlayedText.text = $"Games Played: {totalGames}";
        }
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
