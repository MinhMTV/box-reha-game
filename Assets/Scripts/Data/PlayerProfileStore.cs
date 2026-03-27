using UnityEngine;

public static class PlayerProfileStore
{
    private const string HeightKey = "player_profile_height_cm";
    private const string WeightKey = "player_profile_weight_kg";
    private const string SexKey = "player_profile_sex";

    public static PlayerProfile Load()
    {
        return new PlayerProfile
        {
            HeightCm = PlayerPrefs.GetFloat(HeightKey, 175f),
            WeightKg = PlayerPrefs.GetFloat(WeightKey, 70f),
            Sex = (SexCategory)PlayerPrefs.GetInt(SexKey, (int)SexCategory.Unspecified)
        };
    }

    public static void Save(PlayerProfile profile)
    {
        if (profile == null)
        {
            return;
        }

        PlayerPrefs.SetFloat(HeightKey, Mathf.Clamp(profile.HeightCm, 120f, 220f));
        PlayerPrefs.SetFloat(WeightKey, Mathf.Clamp(profile.WeightKg, 30f, 180f));
        PlayerPrefs.SetInt(SexKey, (int)profile.Sex);
        PlayerPrefs.Save();
    }
}
