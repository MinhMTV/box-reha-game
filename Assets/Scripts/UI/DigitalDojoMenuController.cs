using UnityEngine;

/// <summary>
/// Controls the Digital Dojo hub. The scene is still a normal Unity menu scene,
/// but each reference screen is represented as a switchable panel.
/// </summary>
public class DigitalDojoMenuController : MonoBehaviour
{
    [SerializeField] private GameObject homePanel;
    [SerializeField] private GameObject calibrationPanel;
    [SerializeField] private GameObject statisticsPanel;
    [SerializeField] private GameObject playerProfilePanel;
    [SerializeField] private GameObject settingsPanel;

    [SerializeField] private CanvasGroup pageGroup;

    private GameObject activePanel;
    private float pageTimer;

    void Start()
    {
        ShowHome();
    }

    void Update()
    {
        if (pageGroup == null)
        {
            return;
        }

        pageTimer += Time.unscaledDeltaTime;
        float t = Mathf.Clamp01(pageTimer / 0.18f);
        pageGroup.alpha = Mathf.Lerp(0.2f, 1f, t);
        pageGroup.transform.localScale = Vector3.one * Mathf.Lerp(0.985f, 1f, t);
    }

    public void ShowHome()
    {
        ShowPanel(homePanel);
    }

    public void ShowCalibration()
    {
        ShowPanel(calibrationPanel);
    }

    public void ShowStatistics()
    {
        ShowPanel(statisticsPanel);
    }

    public void ShowPlayerProfile()
    {
        ShowPanel(playerProfilePanel);
    }

    public void ShowSettings()
    {
        ShowPanel(settingsPanel);
    }

    public void StartTraining()
    {
        GameManager manager = GameManager.EnsureInstance();
        manager.SetLevel(1);
        manager.StartGame();
    }

    public void StartLevelMode()
    {
        GameManager manager = GameManager.EnsureInstance();
        manager.SetLevel(2);
        manager.StartGame();
    }

    public void StartEndlessMode()
    {
        GameManager manager = GameManager.EnsureInstance();
        manager.SetLevel(4);
        manager.StartGame();
    }

    public void Quit()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }

    private void ShowPanel(GameObject nextPanel)
    {
        if (activePanel == nextPanel && nextPanel != null)
        {
            return;
        }

        SetActive(homePanel, false);
        SetActive(calibrationPanel, false);
        SetActive(statisticsPanel, false);
        SetActive(playerProfilePanel, false);
        SetActive(settingsPanel, false);

        activePanel = nextPanel != null ? nextPanel : homePanel;
        SetActive(activePanel, true);

        pageTimer = 0f;
        if (pageGroup != null)
        {
            pageGroup.alpha = 0.2f;
        }
    }

    private static void SetActive(GameObject target, bool active)
    {
        if (target != null)
        {
            target.SetActive(active);
        }
    }
}
