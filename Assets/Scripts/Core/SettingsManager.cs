using UnityEngine;

/// <summary>
/// PlayerPrefs-based settings manager. Static methods for get/set.
/// </summary>
public static class SettingsManager
{
    private const string SfxVolumeKey = "settings_sfx_volume";
    private const string MusicVolumeKey = "settings_music_volume";
    private const string ShowDebugUIKey = "settings_show_debug_ui";
    private const string MouseSensitivityKey = "settings_mouse_sensitivity";

    private const float DefaultSfxVolume = 1f;
    private const float DefaultMusicVolume = 0.7f;
    private const float DefaultMouseSensitivity = 1f;

    public static float SfxVolume
    {
        get => PlayerPrefs.GetFloat(SfxVolumeKey, DefaultSfxVolume);
        set { PlayerPrefs.SetFloat(SfxVolumeKey, Mathf.Clamp01(value)); PlayerPrefs.Save(); }
    }

    public static float MusicVolume
    {
        get => PlayerPrefs.GetFloat(MusicVolumeKey, DefaultMusicVolume);
        set { PlayerPrefs.SetFloat(MusicVolumeKey, Mathf.Clamp01(value)); PlayerPrefs.Save(); }
    }

    public static bool ShowDebugUI
    {
        get => PlayerPrefs.GetInt(ShowDebugUIKey, 0) == 1;
        set { PlayerPrefs.SetInt(ShowDebugUIKey, value ? 1 : 0); PlayerPrefs.Save(); }
    }

    public static float MouseSensitivity
    {
        get => PlayerPrefs.GetFloat(MouseSensitivityKey, DefaultMouseSensitivity);
        set { PlayerPrefs.SetFloat(MouseSensitivityKey, Mathf.Max(0.1f, value)); PlayerPrefs.Save(); }
    }

    public static void ResetToDefaults()
    {
        SfxVolume = DefaultSfxVolume;
        MusicVolume = DefaultMusicVolume;
        ShowDebugUI = false;
        MouseSensitivity = DefaultMouseSensitivity;
    }
}
