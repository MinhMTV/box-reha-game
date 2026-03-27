using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 4: Debug UI overlay. Toggle with D key.
/// Shows FPS, input state, active target count.
/// Attach to Canvas in Game scene.
/// </summary>
public class DebugUI : MonoBehaviour
{
    [SerializeField] private Text debugText;
    [SerializeField] private bool visibleByDefault = false;

    private bool isVisible;
    private float fpsUpdateInterval = 0.5f;
    private float fpsTimer;
    private float currentFps;

    private int activeTargetCount;

    void Start()
    {
        isVisible = visibleByDefault;
        if (debugText != null)
            debugText.gameObject.SetActive(isVisible);
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.D))
        {
            isVisible = !isVisible;
            if (debugText != null)
                debugText.gameObject.SetActive(isVisible);
        }

        if (!isVisible) return;

        // FPS calculation
        fpsTimer += Time.unscaledDeltaTime;
        if (fpsTimer >= fpsUpdateInterval)
        {
            currentFps = 1f / Time.unscaledDeltaTime;
            fpsTimer = 0f;
        }

        UpdateDisplay();
    }

    private void UpdateDisplay()
    {
        if (debugText == null) return;

        string inputState = GameManager.Instance != null ? GameManager.Instance.CurrentState.ToString() : "N/A";
        string level = "N/A";
        if (GameManager.Instance != null)
        {
            LevelDefinition currentLevel = GameManager.Instance.CurrentLevel;
            level = currentLevel != null && !string.IsNullOrEmpty(currentLevel.DisplayName)
                ? currentLevel.DisplayName
                : GameManager.Instance.SelectedLevel.ToString();
        }

        debugText.text = $"[DEBUG]\n" +
                         $"FPS: {currentFps:F0}\n" +
                         $"State: {inputState}\n" +
                         $"Level: {level}\n" +
                         $"Targets: {activeTargetCount}\n" +
                         $"Press D to toggle";
    }

    public void SetActiveTargetCount(int count)
    {
        activeTargetCount = count;
    }
}
