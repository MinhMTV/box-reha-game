using System;
using System.IO;
using UnityEngine;

/// <summary>SYNTHETIC / NOT EMPIRICAL DATA; exercises real history file IO with host serialization.</summary>
internal static class HistoryHostCheck
{
    public static void Run()
    {
        string previousPath = Application.persistentDataPath;
        string testDirectory = Path.Combine(Path.GetTempPath(), "box-reha-SYNTHETIC-history-" + Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(testDirectory);
        Application.persistentDataPath = testDirectory;
        try
        {
            var first = new GameSessionStats { SessionId = "SYNTHETIC_SESSION_A", StudyId = "SYNTHETIC_STUDY_A", Score = 100 };
            var second = new GameSessionStats { SessionId = "SYNTHETIC_SESSION_B", StudyId = "SYNTHETIC_STUDY_B", Score = 200 };
            SessionHistoryStore.Save(first);
            SessionHistoryStore.Save(first);
            SessionHistoryStore.Save(second);
            if (SessionHistoryStore.Load().Count != 2 || SessionHistoryStore.Load("SYNTHETIC_STUDY_A").Count != 1)
                throw new Exception("History save/load, deduplication or study filter failed: " + SessionHistoryStore.Error);
            string validBytes = File.ReadAllText(SessionHistoryStore.PathName);
            SessionHistoryStore.Save(new GameSessionStats { SessionId = "SYNTHETIC_INVALID_MISSING_STUDY" });
            if (SessionHistoryStore.Error == null || File.ReadAllText(SessionHistoryStore.PathName) != validBytes)
                throw new Exception("Missing incoming study identity changed valid history.");
            string corruptBytes = "{\"data_status\":\"SYNTHETIC / NOT EMPIRICAL DATA\"}";
            File.WriteAllText(SessionHistoryStore.PathName, corruptBytes);
            if (SessionHistoryStore.Load().Count != 0 || SessionHistoryStore.Error == null)
                throw new Exception("Malformed history was silently accepted.");
            SessionHistoryStore.Save(first);
            if (SessionHistoryStore.Error == null || File.ReadAllText(SessionHistoryStore.PathName) != corruptBytes)
                throw new Exception("Save overwrote unreadable history.");
            Console.WriteLine("HISTORY_HOST_PASS 1 production IO preservation/profile-filter check; SYNTHETIC / NOT EMPIRICAL DATA.");
        }
        finally
        {
            // Only files created by this test in its unique directory are removed; no recursive deletion.
            if (File.Exists(SessionHistoryStore.PathName)) File.Delete(SessionHistoryStore.PathName);
            if (File.Exists(SessionHistoryStore.PathName + ".tmp")) File.Delete(SessionHistoryStore.PathName + ".tmp");
            Directory.Delete(testDirectory, false);
            Application.persistentDataPath = previousPath;
        }
    }
}
