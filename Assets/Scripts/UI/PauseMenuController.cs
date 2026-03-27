using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Pause menu overlay. ESC toggles pause. Shows Resume + Quit buttons.
/// Add to a Panel child of HUDCanvas in the Game scene.
/// </summary>
public class PauseMenuController : MonoBehaviour
{
    [SerializeField] private Button resumeButton;
    [SerializeField] private Button quitButton;
    [SerializeField] private GameObject pausePanel;

    private bool isPaused;

    void Start()
    {
        if (pausePanel != null)
            pausePanel.SetActive(false);

        if (resumeButton != null)
            resumeButton.onClick.AddListener(OnResume);
        if (quitButton != null)
            quitButton.onClick.AddListener(OnQuitToMenu);
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            TogglePause();
        }
    }

    public void TogglePause()
    {
        if (GameManager.Instance == null) return;

        if (GameManager.Instance.CurrentState == GameState.Playing)
        {
            Pause();
        }
        else if (GameManager.Instance.CurrentState == GameState.Paused)
        {
            Resume();
        }
    }

    public void Pause()
    {
        if (GameManager.Instance == null) return;
        GameManager.Instance.PauseGame();
        isPaused = true;
        if (pausePanel != null)
            pausePanel.SetActive(true);
    }

    public void Resume()
    {
        if (GameManager.Instance == null) return;
        GameManager.Instance.ResumeGame();
        isPaused = false;
        if (pausePanel != null)
            pausePanel.SetActive(false);
    }

    public void OnResume()
    {
        Resume();
    }

    public void OnQuitToMenu()
    {
        Time.timeScale = 1f;
        isPaused = false;
        if (GameManager.Instance != null)
            GameManager.Instance.LoadMainMenu();
    }

    public bool IsPaused => isPaused;
}
