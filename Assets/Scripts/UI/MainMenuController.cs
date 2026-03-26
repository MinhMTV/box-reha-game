using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Phase 4: Main menu with level selection.
/// </summary>
public class MainMenuController : MonoBehaviour
{
    private const string GameSceneName = "Game";

    public void OnStartGameButton()
    {
        GameManager.Instance?.StartGame();
    }

    // Phase 4: Level selection buttons
    public void OnStartLevel1()
    {
        if (GameManager.Instance == null) return;
        GameManager.Instance.SessionStats.Reset();
        GameManager.Instance.SetLevel(1);
        GameManager.Instance.CurrentState = GameState.Playing;
        SceneManager.LoadScene(GameSceneName);
    }

    public void OnStartLevel2()
    {
        if (GameManager.Instance == null) return;
        GameManager.Instance.SessionStats.Reset();
        GameManager.Instance.SetLevel(2);
        GameManager.Instance.CurrentState = GameState.Playing;
        SceneManager.LoadScene(GameSceneName);
    }

    public void OnStartLevel3()
    {
        if (GameManager.Instance == null) return;
        GameManager.Instance.SessionStats.Reset();
        GameManager.Instance.SetLevel(3);
        GameManager.Instance.CurrentState = GameState.Playing;
        SceneManager.LoadScene(GameSceneName);
    }

    public void OnQuitButton()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}
