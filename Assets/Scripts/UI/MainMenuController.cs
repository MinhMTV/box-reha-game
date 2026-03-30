using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Main menu with simple runtime polish: staged button reveal and subtle panel motion.
/// </summary>
public class MainMenuController : MonoBehaviour
{
    private readonly List<CanvasGroup> animatedGroups = new List<CanvasGroup>();
    private readonly List<Vector2> animatedStartPositions = new List<Vector2>();

    private RectTransform rectTransform;
    private RectTransform accentPanel;
    private RectTransform backgroundPanel;
    private Text titleText;
    private float introTimer;

    void Start()
    {
        rectTransform = transform as RectTransform;
        titleText = FindChildText("Title");
        accentPanel = transform.parent != null ? transform.parent.Find("AccentPanel") as RectTransform : null;
        backgroundPanel = transform.parent != null ? transform.parent.Find("Background") as RectTransform : null;

        BuildIntroAnimation();
    }

    void Update()
    {
        introTimer += Time.unscaledDeltaTime;

        if (titleText != null)
        {
            float pulse = 1f + Mathf.Sin(introTimer * 1.8f) * 0.03f;
            titleText.transform.localScale = Vector3.one * pulse;
        }

        if (accentPanel != null)
        {
            Vector3 localPosition = accentPanel.localPosition;
            localPosition.y = Mathf.Sin(introTimer * 0.7f) * 8f;
            accentPanel.localPosition = localPosition;
        }

        if (backgroundPanel != null)
        {
            Vector3 backgroundScale = Vector3.one * (1f + Mathf.Sin(introTimer * 0.45f) * 0.015f);
            backgroundPanel.localScale = backgroundScale;
        }

        for (int i = 0; i < animatedGroups.Count; i++)
        {
            float delay = i * 0.08f;
            float t = Mathf.Clamp01((introTimer - delay) / 0.35f);
            CanvasGroup group = animatedGroups[i];
            group.alpha = t;

            RectTransform groupRect = group.transform as RectTransform;
            if (groupRect != null)
            {
                Vector2 target = animatedStartPositions[i];
                groupRect.anchoredPosition = Vector2.Lerp(target + new Vector2(0f, 24f), target, 1f - Mathf.Pow(1f - t, 3f));
            }
        }
    }

    public void OnStartGameButton()
    {
        GameManager.EnsureInstance().StartGame();
    }

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

    private void BuildIntroAnimation()
    {
        animatedGroups.Clear();
        animatedStartPositions.Clear();

        RegisterAnimatedElement(FindChildRect("Subtitle"));
        RegisterAnimatedElement(FindChildRect("StartGameButton"));
        RegisterAnimatedElement(FindChildRect("Level1Button"));
        RegisterAnimatedElement(FindChildRect("Level2Button"));
        RegisterAnimatedElement(FindChildRect("Level3Button"));
        RegisterAnimatedElement(FindChildRect("EndlessButton"));
        RegisterAnimatedElement(FindChildRect("QuitButton"));

        RectTransform profilePanel = transform.parent != null ? transform.parent.Find("ProfilePanel") as RectTransform : null;
        RegisterAnimatedElement(profilePanel);
    }

    private void RegisterAnimatedElement(RectTransform rect)
    {
        if (rect == null)
        {
            return;
        }

        CanvasGroup group = rect.GetComponent<CanvasGroup>();
        if (group == null)
        {
            group = rect.gameObject.AddComponent<CanvasGroup>();
        }

        group.alpha = 0f;
        animatedGroups.Add(group);
        animatedStartPositions.Add(rect.anchoredPosition);
    }

    private RectTransform FindChildRect(string name)
    {
        Transform child = transform.Find(name);
        return child as RectTransform;
    }

    private Text FindChildText(string name)
    {
        Transform child = transform.Find(name);
        return child != null ? child.GetComponent<Text>() : null;
    }
}
