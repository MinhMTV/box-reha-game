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
    [SerializeField] private Text starsText;
    [SerializeField] private Text bestScoreText;
    [SerializeField] private Text newHighScoreText;
    [SerializeField] private Text gamesPlayedText;
    [SerializeField] private Text forceText;
    [SerializeField] private Text normalizedForceText;
    [SerializeField] private Text profileBaselineText;
    [SerializeField] private Text forceBandSummaryText;

    private int totalGamesPlayed;
    private bool isNewHighScore;

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
        int previousBestScore = LeaderboardManager.GetBestScore(level);

        isNewHighScore = stats.Score > previousBestScore;
        totalGamesPlayed = LeaderboardManager.IncrementGamesPlayed();

        LeaderboardManager.SaveScore(level, stats.Score, stats.Accuracy, stats.MaxCombo);
    }

    private void DisplayResults()
    {
        if (GameManager.Instance == null || GameManager.Instance.SessionStats == null) return;

        GameSessionStats stats = GameManager.Instance.SessionStats;
        int level = GameManager.Instance.SelectedLevel;
        string levelLabel = GetCurrentLevelLabel();

        if (scoreText != null) scoreText.text = $"Final Score: {stats.Score}";
        if (accuracyText != null) accuracyText.text = $"Accuracy: {stats.Accuracy:P0}";
        if (perfectText != null) perfectText.text = $"Perfect: {stats.PerfectHits}";
        if (goodText != null) goodText.text = $"Good: {stats.GoodHits}";
        if (earlyText != null) earlyText.text = $"Early: {stats.EarlyHits}";
        if (lateText != null) lateText.text = $"Late: {stats.LateHits}";
        if (missText != null) missText.text = $"Misses: {stats.Misses}";
        if (maxComboText != null) maxComboText.text = $"Max Combo: {stats.MaxCombo}";
        if (reactionTimeText != null) reactionTimeText.text = $"Avg Reaction: {stats.AverageReactionTime:F2}s";
        if (forceText != null) forceText.text = $"Avg Force: {stats.AverageRawForce:F0} N";
        if (normalizedForceText != null) normalizedForceText.text = $"Force vs Profile: {stats.AverageNormalizedForce:P0}";

        PlayerProfile profile = GameManager.Instance.PlayerProfile;
        if (profileBaselineText != null && profile != null)
        {
            profileBaselineText.text = $"Profile Baseline: {profile.GetEstimatedAveragePunchForce():F0} N";
        }
        if (forceBandSummaryText != null)
        {
            forceBandSummaryText.text =
                $"Force bands - Low: {stats.LowForceHits} | On target: {stats.OnTargetForceHits} | High: {stats.HighForceHits}";
        }

        int stars = StarRating.CalculateStars(stats.Accuracy);
        if (starsText != null)
        {
            starsText.text = StarRating.GetStarDisplay(stars);
            starsText.color = StarRating.GetStarColor(stars);
            starsText.fontSize = 48;
        }

        int bestScore = LeaderboardManager.GetBestScore(level);
        if (bestScoreText != null)
            bestScoreText.text = $"Best Score ({levelLabel}): {bestScore}";

        if (newHighScoreText != null)
        {
            if (isNewHighScore)
            {
                newHighScoreText.text = "NEW HIGH SCORE!";
                newHighScoreText.color = Color.yellow;
                newHighScoreText.fontSize = 36;
            }
            else
            {
                newHighScoreText.text = string.Empty;
            }
        }

        if (gamesPlayedText != null)
        {
            gamesPlayedText.text = $"Games Played: {totalGamesPlayed}";
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

    private string GetCurrentLevelLabel()
    {
        LevelDefinition currentLevel = GameManager.Instance != null ? GameManager.Instance.CurrentLevel : null;
        if (currentLevel != null && !string.IsNullOrEmpty(currentLevel.DisplayName))
        {
            return currentLevel.DisplayName;
        }

        int level = GameManager.Instance != null ? GameManager.Instance.SelectedLevel : 1;
        return $"Level {level}";
    }
}
