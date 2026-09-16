using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 4: Debug UI overlay. Toggle with F1 key.
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
    private TargetSpawner spawner;

    void Start()
    {
        isVisible = visibleByDefault;
        spawner=FindFirstObjectByType<TargetSpawner>();
#if !UNITY_EDITOR
        isVisible=false;
#endif
        if (debugText != null)
            debugText.gameObject.SetActive(isVisible);
    }

    void Update()
    {
#if UNITY_EDITOR
        if (Input.GetKeyDown(KeyCode.F1))
        {
            isVisible = !isVisible;
            if (debugText != null)
                debugText.gameObject.SetActive(isVisible);
        }
#endif

        if (!isVisible) return;

        // FPS calculation
        fpsTimer += Time.unscaledDeltaTime;
        if (fpsTimer >= fpsUpdateInterval)
        {
            currentFps = 1f / Time.unscaledDeltaTime;
            fpsTimer = 0f;
        }

        if(fpsTimer==0)UpdateDisplay();
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
                         $"Press F1 to toggle";
        if(spawner!=null)debugText.text+=$"\nPhase: {spawner.CurrentWave} / Tier {spawner.CurrentPacingTier}\nPattern: {spawner.CurrentPatternId} [{spawner.PatternActionIndex+1}]\nTravel: {spawner.CurrentTravelSeconds:F2}s / Next: {spawner.NextExpectedActionTime:F2}s\nActive: {spawner.ActiveTargetCount} / Min: {spawner.Pacing.MinimumSpacing:F2}s\nChannels: {spawner.Availability}";
        if(spawner!=null)debugText.text+=$"\nLength tier: {spawner.ComboLengthTier:F1} / Pending: {spawner.PendingActions} / Lookahead: {spawner.Lookahead}\nWait: {spawner.WaitingReason} / Spawn: {spawner.NextSpawnTime:F2}\nWork/Low/Idle: {spawner.ActiveWorkTime:F1}/{spawner.LowIntensityTime:F1}/{spawner.EmptyIdleTime:F1}s";
    }

    public void SetActiveTargetCount(int count)
    {
        activeTargetCount = count;
    }
}
