using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Phase 4: Level selection controller for main menu.
/// Assign buttons in inspector, call OnSelectLevel from each button's OnClick.
/// </summary>
public class LevelSelectController : MonoBehaviour
{
    [SerializeField] private Button level1Button;
    [SerializeField] private Button level2Button;
    [SerializeField] private Button level3Button;
    [SerializeField] private Text titleText;

    void Start()
    {
        if (titleText != null)
            titleText.text = "BoxReha - Select Level";

        // Wire up buttons if not done in inspector
        if (level1Button != null)
            level1Button.onClick.AddListener(() => SelectLevel(1));
        if (level2Button != null)
            level2Button.onClick.AddListener(() => SelectLevel(2));
        if (level3Button != null)
            level3Button.onClick.AddListener(() => SelectLevel(3));
    }

    public void SelectLevel(int level)
    {
        if (GameManager.Instance == null) return;

        GameManager.Instance.SessionStats.Reset();
        GameManager.Instance.SetLevel(level);
        GameManager.Instance.CurrentState = GameState.Playing;
        UnityEngine.SceneManagement.SceneManager.LoadScene("Game");
    }
}
