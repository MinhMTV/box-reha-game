using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public static class SessionHistoryStore
{
    [Serializable] private class History { public List<GameSessionStats> sessions; }
    public static string PathName => Path.Combine(Application.persistentDataPath,
#if UNITY_EDITOR
        Environment.GetEnvironmentVariable("DOJO_VISUAL_QA") == "1" ? "synthetic-visual-qa-history.json" :
#endif
        "session-history-v1.json");
    public static string Error { get; private set; }
    public static List<GameSessionStats> Load(string studyId = null)
    {
        Error = null;
        try
        {
            if (!File.Exists(PathName)) return new List<GameSessionStats>();
            History history = JsonUtility.FromJson<History>(File.ReadAllText(PathName));
            if (history?.sessions == null) throw new FormatException("History has no sessions array.");
            List<GameSessionStats> entries = history.sessions;
            if (entries.Exists(s => s == null || string.IsNullOrWhiteSpace(s.SessionId) || string.IsNullOrWhiteSpace(s.StudyId)))
                throw new FormatException("History contains an incomplete session identity.");
            return studyId == null ? entries : entries.FindAll(s => s != null && s.StudyId == studyId);
        }
        catch (Exception ex) when (ex is IOException || ex is UnauthorizedAccessException || ex is ArgumentException || ex is FormatException)
        { Error = ex.Message; return new List<GameSessionStats>(); }
    }
    public static void Save(GameSessionStats stats)
    {
        if (stats == null || string.IsNullOrWhiteSpace(stats.SessionId) || string.IsNullOrWhiteSpace(stats.StudyId))
        {
            Error = "Cannot save a session without session and study identities.";
            return;
        }
        List<GameSessionStats> entries = Load();
        // Never replace an existing unreadable/corrupt file with a fresh, apparently empty history.
        if (Error != null) return;
        if (entries.Exists(s => s != null && s.SessionId == stats.SessionId)) return;
        entries.Insert(0, JsonUtility.FromJson<GameSessionStats>(JsonUtility.ToJson(stats)));
        // Cap per study/participant, not globally: a shared 200-entry cap across all participants would
        // silently evict an earlier participant's sessions once a multi-participant study's combined
        // total passed 200, even though each participant is individually far below that limit.
        Dictionary<string, int> perStudyCount = new Dictionary<string, int>();
        for (int i = 0; i < entries.Count; i++)
        {
            string id = entries[i]?.StudyId;
            if (id == null) continue;
            perStudyCount.TryGetValue(id, out int count);
            perStudyCount[id] = ++count;
            if (count > 200) { entries.RemoveAt(i); i--; }
        }
        try
        {
            Directory.CreateDirectory(Application.persistentDataPath);
            File.WriteAllText(PathName + ".tmp", JsonUtility.ToJson(new History { sessions = entries }, true));
            if (File.Exists(PathName))
            {
                try { File.Replace(PathName + ".tmp", PathName, null); }
                catch (PlatformNotSupportedException)
                {
                    File.Copy(PathName + ".tmp", PathName, true);
                    File.Delete(PathName + ".tmp");
                }
            }
            else File.Move(PathName + ".tmp", PathName);
            Error = null;
        }
        catch (Exception ex) when (ex is IOException || ex is UnauthorizedAccessException)
        { Error = ex.Message; Debug.LogError("Session history could not be saved: " + Error); }
    }
}
