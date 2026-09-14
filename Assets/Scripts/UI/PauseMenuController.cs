using UnityEngine;
using UnityEngine.UI;

/// <summary>Pause overlay remains active so Escape also works while the panel is hidden.</summary>
public class PauseMenuController : MonoBehaviour
{
    [SerializeField] private Button resumeButton;
    [SerializeField] private Button quitButton;
    [SerializeField] private GameObject pausePanel;
    private CanvasGroup visibility;
    private GameObject content;
    private Image backdrop;
    private UnityEngine.UI.Text sensorMessage;
    public bool IsPaused => GameManager.Instance != null && GameManager.Instance.CurrentState == GameState.Paused;
    void Start()
    {
        if (pausePanel == null) pausePanel = gameObject;
        visibility = pausePanel.GetComponent<CanvasGroup>();
        // Unity's missing-component sentinel must use Unity's null comparison, not ?? .
        if (visibility == null) visibility = pausePanel.AddComponent<CanvasGroup>();
        backdrop = pausePanel.GetComponent<Image>();
        content = new GameObject("PauseContent", typeof(RectTransform));
        var contentRect = content.GetComponent<RectTransform>();
        contentRect.SetParent(pausePanel.transform, false);
        contentRect.anchorMin = Vector2.zero; contentRect.anchorMax = Vector2.one;
        contentRect.offsetMin = contentRect.offsetMax = Vector2.zero;
        var existing = new System.Collections.Generic.List<Transform>();
        foreach (Transform child in pausePanel.transform) if (child != contentRect) existing.Add(child);
        foreach (var child in existing) child.SetParent(contentRect, false);
        GameObject message = new GameObject("SensorPauseStatus", typeof(RectTransform), typeof(CanvasRenderer), typeof(UnityEngine.UI.Text));
        message.transform.SetParent(content.transform, false);
        sensorMessage = message.GetComponent<UnityEngine.UI.Text>();
        sensorMessage.font = DojoUiStyle.Font;
        sensorMessage.fontSize = 24; sensorMessage.color = Color.white;
        sensorMessage.alignment = TextAnchor.MiddleCenter; sensorMessage.raycastTarget = false;
        RectTransform messageRect = sensorMessage.rectTransform;
        messageRect.anchorMin = new Vector2(0.1f, 0.12f); messageRect.anchorMax = new Vector2(0.9f, 0.3f);
        messageRect.offsetMin = messageRect.offsetMax = Vector2.zero;
        // Serialized persistent listeners already exist in current scene. Do not double-register them.
        if (resumeButton != null && resumeButton.onClick.GetPersistentEventCount() == 0)
            resumeButton.onClick.AddListener(OnResume);
        if (quitButton != null)
        {
            Text label = quitButton.GetComponentInChildren<Text>();
            if (label != null) label.text = "Finish & Results";
            if (quitButton.onClick.GetPersistentEventCount() == 0) quitButton.onClick.AddListener(OnQuitToMenu);
        }
        foreach (var button in new[] { resumeButton, quitButton })
        {
            if (button == null) continue;
            var rect = button.GetComponent<RectTransform>(); rect.sizeDelta = new Vector2(360, DojoUiStyle.TouchHeight);
            button.GetComponent<Image>().color = DojoUiStyle.Red;
            DojoUiStyle.Style(button);
            var label = button.GetComponentInChildren<Text>();
            if (label != null) { label.font = DojoUiStyle.Font; label.fontSize = 24; }
        }
        SetVisible(false);
    }
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Escape)) TogglePause();
        SetVisible(IsPaused);
        if (sensorMessage != null && IsPaused)
        {
            AndroidDynamicsController controller = AndroidDynamicsController.EnsureInstance();
            sensorMessage.text = SessionInputSelection.Physical ? controller.Ready(out string reason)
                ? controller.Notice + "\nResume requests a new SDK acknowledgement. Finish always remains available."
                : reason + "\nFinish this round to return to sensor setup." : "Resume training or finish this round to save results.";
            if (resumeButton != null) resumeButton.interactable = !SessionInputSelection.Physical || (!controller.Pending && controller.Ready(out _));
        }
    }
    private void SetVisible(bool visible)
    {
        if (visibility == null) return;
        visibility.alpha = visible ? 1f : 0f;
        visibility.interactable = visible;
        visibility.blocksRaycasts = visible;
        if (content != null) content.SetActive(visible);
        if (backdrop != null) backdrop.enabled = visible;
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
        SetVisible(IsPaused);
    }
    public void OnResume() { Resume(); }
    public void OnQuitToMenu()
    {
        GameRoundController round = FindObjectOfType<GameRoundController>();
        if (round != null) round.FinishRound("player_stop");
        else GameManager.Instance?.LoadMainMenu();
    }
}
