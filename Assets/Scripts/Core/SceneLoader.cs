using UnityEngine;
using UnityEngine.SceneManagement;

public static class SceneLoader
{
    public const string BOOT = "Boot";
    public const string MAIN_MENU = "MainMenu";
    public const string GAME = "Game";
    public const string RESULTS = "Results";

    public static void LoadScene(string sceneName)
    {
        SceneManager.LoadScene(sceneName);
    }

    public static void LoadBoot() { LoadScene(BOOT); }
    public static void LoadMainMenu() { LoadScene(MAIN_MENU); }
    public static void LoadGame() { LoadScene(GAME); }
    public static void LoadResults() { LoadScene(RESULTS); }

    public static string GetCurrentSceneName()
    {
        return SceneManager.GetActiveScene().name;
    }
}
