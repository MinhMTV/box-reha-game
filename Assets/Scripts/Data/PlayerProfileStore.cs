using System;
using UnityEngine;
public static class PlayerProfileStore
{
    private const string ProfileKey = "dojo_profile_v2";
    public static PlayerProfile Load()
    {
#if UNITY_EDITOR
        if (Environment.GetEnvironmentVariable("DOJO_VISUAL_QA") == "1")
            return new PlayerProfile { Name = "QA preview", StudyId = "synthetic-visual-qa" };
#endif
        PlayerProfile profile = null;
        try { profile = JsonUtility.FromJson<PlayerProfile>(PlayerPrefs.GetString(ProfileKey, "")); }
        catch (ArgumentException) { }
        if (profile == null) profile = new PlayerProfile();
        if (string.IsNullOrWhiteSpace(profile.Name)) profile.Name = "Player";
        if (string.IsNullOrWhiteSpace(profile.StudyId)) profile.StudyId = Guid.NewGuid().ToString("N");
        Save(profile);
        return profile;
    }
    public static void Save(PlayerProfile profile)
    {
#if UNITY_EDITOR
        if (Environment.GetEnvironmentVariable("DOJO_VISUAL_QA") == "1") return;
#endif
        if (profile == null) return;
        profile.Name = string.IsNullOrWhiteSpace(profile.Name) ? "Player" : profile.Name.Trim();
        if (profile.Name.Length > 32) profile.Name = profile.Name.Substring(0, 32);
        if (string.IsNullOrWhiteSpace(profile.StudyId)) profile.StudyId = Guid.NewGuid().ToString("N");
        PlayerPrefs.SetString(ProfileKey, JsonUtility.ToJson(profile));
        PlayerPrefs.Save();
    }
}
