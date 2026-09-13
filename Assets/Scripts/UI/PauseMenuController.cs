using UnityEngine;
using UnityEngine.UI;

/// <summary>Pause overlay remains active so Escape also works while the panel is hidden.</summary>
public class PauseMenuController : MonoBehaviour
{
    [SerializeField] private Button resumeButton;
    [SerializeField] private Button quitButton;
    [SerializeField] private GameObject pausePanel;
    private CanvasGroup visibility;
    public bool IsPaused => GameManager.Instance != null && GameManager.Instance.CurrentState == GameState.Paused;
    void Start()
    {
        if (pausePanel == null) pausePanel = gameObject;
        visibility = pausePanel.GetComponent<CanvasGroup>() ?? pausePanel.AddComponent<CanvasGroup>();
        SetVisible(false);
        // Serialized persistent listeners already exist in current scene. Do not double-register them.
        if (resumeButton != null && resumeButton.onClick.GetPersistentEventCount() == 0)
            resumeButton.onClick.AddListener(OnResume);
        if (quitButton != null)
        {
            Text label = quitButton.GetComponentInChildren<Text>();
            if (label != null) label.text = "Finish & Results";
            if (quitButton.onClick.GetPersistentEventCount() == 0) quitButton.onClick.AddListener(OnQuitToMenu);
        }
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape)) TogglePause();
    }
    private void SetVisible(bool visible)
    {
        if (visibility == null) return;
        visibility.alpha = visible ? 1f : 0f;
        visibility.interactable = visible;
        visibility.blocksRaycasts = visible;
        if (visible) visibility.transform.SetAsLastSibling();
    }
    public void TogglePause() { if (IsPaused) Resume(); else Pause(); }
    public void Pause()
    {
        if (GameManager.Instance == null || GameManager.Instance.CurrentState != GameState.Playing) return;
        GameManager.Instance.PauseGame();
        SetVisible(true);
    }
    public void Resume()
    {
        GameManager.Instance?.ResumeGame();
        SetVisible(false);
    }
    public void OnResume() { Resume(); }
    public void OnQuitToMenu()
    {
        GameRoundController round = FindObjectOfType<GameRoundController>();
        if (round != null) round.FinishRound("player_stop");
        else GameManager.Instance?.LoadMainMenu();
    }
}
