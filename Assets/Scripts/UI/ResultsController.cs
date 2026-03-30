using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Shows session results with a small reveal animation and score count-up.
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

    private readonly List<CanvasGroup> revealGroups = new List<CanvasGroup>();
    private readonly List<Vector2> revealPositions = new List<Vector2>();

    private int totalGamesPlayed;
    private bool isNewHighScore;
    private GameSessionStats stats;
    private int bestScore;
    private string levelLabel = "Level 1";
    private float revealTimer;
    private RectTransform resultsCard;

    void Start()
    {
        resultsCard = transform.Find("ResultsCard") as RectTransform;
        SaveToLeaderboard();
        DisplayResults();
        BuildRevealAnimation();
    }

    void Update()
    {
        revealTimer += Time.unscaledDeltaTime;

        for (int i = 0; i < revealGroups.Count; i++)
        {
            float delay = i * 0.06f;
            float t = Mathf.Clamp01((revealTimer - delay) / 0.28f);
            CanvasGroup group = revealGroups[i];
            group.alpha = t;

            RectTransform rect = group.transform as RectTransform;
            if (rect != null)
            {
                Vector2 targetPosition = revealPositions[i];
                rect.anchoredPosition = Vector2.Lerp(targetPosition + new Vector2(0f, 18f), targetPosition, 1f - Mathf.Pow(1f - t, 3f));
            }
        }

        if (stats == null)
        {
            return;
        }

        float countUp = Mathf.Clamp01(revealTimer / 0.8f);
        if (scoreText != null)
        {
            int animatedScore = Mathf.RoundToInt(Mathf.Lerp(0f, stats.Score, 1f - Mathf.Pow(1f - countUp, 3f)));
            scoreText.text = $"Final Score: {animatedScore}";
        }

        if (starsText != null)
        {
            float starPulse = 1f + Mathf.Sin(Time.unscaledTime * 3.4f) * 0.06f;
            starsText.transform.localScale = Vector3.one * starPulse;
        }

        if (resultsCard != null)
        {
            float cardPulse = 1f + Mathf.Sin(Time.unscaledTime * 1.4f) * 0.01f;
            resultsCard.localScale = Vector3.one * cardPulse;
        }

        if (newHighScoreText != null && isNewHighScore)
        {
            Color highlight = Color.Lerp(new Color(1f, 0.82f, 0.18f, 1f), Color.white, (Mathf.Sin(Time.unscaledTime * 4f) + 1f) * 0.5f);
            newHighScoreText.color = highlight;
        }
    }

    private void SaveToLeaderboard()
    {
        if (GameManager.Instance == null || GameManager.Instance.SessionStats == null)
        {
            return;
        }

        stats = GameManager.Instance.SessionStats;
        int level = GameManager.Instance.SelectedLevel;
        int previousBestScore = LeaderboardManager.GetBestScore(level);

        isNewHighScore = stats.Score > previousBestScore;
        totalGamesPlayed = LeaderboardManager.IncrementGamesPlayed();

        LeaderboardManager.SaveScore(level, stats.Score, stats.Accuracy, stats.MaxCombo);
        bestScore = LeaderboardManager.GetBestScore(level);
        levelLabel = GetCurrentLevelLabel();
    }

    private void DisplayResults()
    {
        if (stats == null)
        {
            return;
        }

        SetText(scoreText, $"Final Score: {stats.Score}", new Color(0.95f, 0.98f, 1f, 1f));
        SetText(accuracyText, $"Accuracy: {stats.Accuracy:P0}", new Color(0.60f, 0.88f, 1f, 1f));
        SetText(perfectText, $"Perfect: {stats.PerfectHits}", new Color(1f, 0.92f, 0.28f, 1f));
        SetText(goodText, $"Good: {stats.GoodHits}", new Color(0.38f, 1f, 0.68f, 1f));
        SetText(earlyText, $"Early: {stats.EarlyHits}", new Color(0.42f, 0.90f, 1f, 1f));
        SetText(lateText, $"Late: {stats.LateHits}", new Color(1f, 0.60f, 0.18f, 1f));
        SetText(missText, $"Misses: {stats.Misses}", new Color(1f, 0.38f, 0.44f, 1f));
        SetText(maxComboText, $"Max Combo: {stats.MaxCombo}", new Color(1f, 0.86f, 0.28f, 1f));
        SetText(reactionTimeText, $"Avg Reaction: {stats.AverageReactionTime:F2}s", new Color(0.84f, 0.92f, 1f, 1f));
        SetText(forceText, $"Avg Force: {stats.AverageRawForce:F0} N", new Color(1f, 0.80f, 0.42f, 1f));
        SetText(normalizedForceText, $"Force vs Profile: {stats.AverageNormalizedForce:P0}", new Color(0.76f, 0.92f, 1f, 1f));

        PlayerProfile profile = GameManager.Instance != null ? GameManager.Instance.PlayerProfile : null;
        if (profileBaselineText != null)
        {
            profileBaselineText.text = profile != null
                ? $"Profile Baseline: {profile.GetEstimatedAveragePunchForce():F0} N"
                : "Profile Baseline: n/a";
            profileBaselineText.color = new Color(0.72f, 0.84f, 0.96f, 1f);
        }

        if (forceBandSummaryText != null)
        {
            forceBandSummaryText.text =
                $"Force bands - Low: {stats.LowForceHits} | On target: {stats.OnTargetForceHits} | High: {stats.HighForceHits}";
            forceBandSummaryText.color = new Color(0.86f, 0.92f, 1f, 1f);
        }

        int stars = StarRating.CalculateStars(stats.Accuracy);
        if (starsText != null)
        {
            starsText.text = StarRating.GetStarDisplay(stars);
            starsText.color = StarRating.GetStarColor(stars);
            starsText.fontSize = 52;
        }

        SetText(bestScoreText, $"Best Score ({levelLabel}): {bestScore}", new Color(0.78f, 0.90f, 1f, 1f));

        if (newHighScoreText != null)
        {
            if (isNewHighScore)
            {
                newHighScoreText.text = "NEW HIGH SCORE!";
                newHighScoreText.color = new Color(1f, 0.84f, 0.2f, 1f);
                newHighScoreText.fontSize = 38;
            }
            else
            {
                newHighScoreText.text = string.Empty;
            }
        }

        SetText(gamesPlayedText, $"Games Played: {totalGamesPlayed}", new Color(0.72f, 0.84f, 0.96f, 1f));
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

    private void SetText(Text textComponent, string value, Color color)
    {
        if (textComponent == null)
        {
            return;
        }

        textComponent.text = value;
        textComponent.color = color;
    }

    private void BuildRevealAnimation()
    {
        revealGroups.Clear();
        revealPositions.Clear();
        revealTimer = 0f;

        RegisterReveal(scoreText);
        RegisterReveal(accuracyText);
        RegisterReveal(perfectText);
        RegisterReveal(goodText);
        RegisterReveal(earlyText);
        RegisterReveal(lateText);
        RegisterReveal(missText);
        RegisterReveal(maxComboText);
        RegisterReveal(reactionTimeText);
        RegisterReveal(forceText);
        RegisterReveal(normalizedForceText);
        RegisterReveal(profileBaselineText);
        RegisterReveal(forceBandSummaryText);
        RegisterReveal(starsText);
        RegisterReveal(bestScoreText);
        RegisterReveal(newHighScoreText);
        RegisterReveal(gamesPlayedText);
    }

    private void RegisterReveal(Text textComponent)
    {
        if (textComponent == null)
        {
            return;
        }

        CanvasGroup group = textComponent.GetComponent<CanvasGroup>();
        if (group == null)
        {
            group = textComponent.gameObject.AddComponent<CanvasGroup>();
        }

        group.alpha = 0f;
        revealGroups.Add(group);
        revealPositions.Add(textComponent.rectTransform.anchoredPosition);
    }
}
