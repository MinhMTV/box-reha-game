using UnityEngine;
using System;
using System.Collections.Generic;

/// <summary>
/// Local leaderboard system using PlayerPrefs.
/// Stores Top 10 scores per level with JSON serialization.
/// </summary>
public static class LeaderboardManager
{
    private const string KeyPrefix = "leaderboard_level_";
    private const string GamesPlayedKey = "games_played";

    [Serializable]
    public class ScoreEntry
    {
        public int Score;
        public float Accuracy;
        public int MaxCombo;
        public long DateTimestamp;
        public int Level;

        public DateTime Date => DateTimeOffset.FromUnixTimeSeconds(DateTimestamp).LocalDateTime;
    }

    [Serializable]
    private class ScoreList
    {
        public List<ScoreEntry> Entries = new List<ScoreEntry>();
    }

    public static void SaveScore(int level, int score, float accuracy, int maxCombo)
    {
        ScoreList list = LoadScoreList(level);

        ScoreEntry entry = new ScoreEntry
        {
            Score = score,
            Accuracy = accuracy,
            MaxCombo = maxCombo,
            DateTimestamp = DateTimeOffset.UtcNow.ToUnixTimeSeconds(),
            Level = level
        };

        list.Entries.Add(entry);

        // Sort descending by score
        list.Entries.Sort((a, b) => b.Score.CompareTo(a.Score));

        // Keep top 10
        if (list.Entries.Count > 10)
        {
            list.Entries.RemoveRange(10, list.Entries.Count - 10);
        }

        string json = JsonUtility.ToJson(list);
        PlayerPrefs.SetString(KeyPrefix + level, json);
        PlayerPrefs.Save();
    }

    public static List<ScoreEntry> GetTopScores(int level, int count = 10)
    {
        ScoreList list = LoadScoreList(level);
        int take = Mathf.Min(count, list.Entries.Count);
        return list.Entries.GetRange(0, take);
    }

    public static int GetBestScore(int level)
    {
        ScoreList list = LoadScoreList(level);
        if (list.Entries.Count == 0) return 0;
        return list.Entries[0].Score;
    }

    public static float GetBestAccuracy(int level)
    {
        ScoreList list = LoadScoreList(level);
        if (list.Entries.Count == 0) return 0f;
        float best = 0f;
        foreach (var entry in list.Entries)
        {
            if (entry.Accuracy > best) best = entry.Accuracy;
        }
        return best;
    }

    private static ScoreList LoadScoreList(int level)
    {
        string key = KeyPrefix + level;
        if (PlayerPrefs.HasKey(key))
        {
            string json = PlayerPrefs.GetString(key);
            try
            {
                ScoreList list = JsonUtility.FromJson<ScoreList>(json);
                if (list != null) return list;
            }
            catch
            {
                // Corrupted data, start fresh
            }
        }
        return new ScoreList();
    }

    /// <summary>
    /// Increment and return total games played.
    /// </summary>
    public static int IncrementGamesPlayed()
    {
        int count = PlayerPrefs.GetInt(GamesPlayedKey, 0) + 1;
        PlayerPrefs.SetInt(GamesPlayedKey, count);
        PlayerPrefs.Save();
        return count;
    }

    public static int GetGamesPlayed()
    {
        return PlayerPrefs.GetInt(GamesPlayedKey, 0);
    }

    public static bool IsNewHighScore(int level, int score)
    {
        return score > GetBestScore(level);
    }
}
