using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Phase 4: Main menu with level selection.
/// </summary>
public class MainMenuController : MonoBehaviour
{
    public void OnStartGameButton()
    {
        GameManager.EnsureInstance().StartGame();
    }

    // Phase 4: Level selection buttons
    public void OnStartLevel1()
    {
        StartLevel(1);
    }

    public void OnStartLevel2()
    {
        StartLevel(2);
    }

    public void OnStartLevel3()
    {
        StartLevel(3);
    }

    public void OnStartEndless()
    {
        StartLevel(4);
    }

    public void OnQuitButton()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }

    private void StartLevel(int level)
    {
        GameManager manager = GameManager.EnsureInstance();
        manager.SetLevel(level);
        manager.StartGame();
    }
}
