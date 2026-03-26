using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    public GameState CurrentState { get; set; }
    public GameSessionStats SessionStats { get; private set; }
    public LevelDefinition CurrentLevel { get; private set; }
    // Phase 4: Track selected level number
    public int SelectedLevel { get; private set; } = 1;

    [SerializeField] private string bootSceneName = "Boot";
    [SerializeField] private string mainMenuSceneName = "MainMenu";
    [SerializeField] private string gameSceneName = "Game";
    [SerializeField] private string resultsSceneName = "Results";

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        SessionStats = new GameSessionStats();
        CurrentState = GameState.Menu;
    }

    /// <summary>
    /// Phase 4: Set level by number. Default is level 1.
    /// </summary>
    public void SetLevel(int levelNumber)
    {
        SelectedLevel = levelNumber;
        switch (levelNumber)
        {
            case 2: CurrentLevel = LevelDefinition.CreateLevel2(); break;
            case 3: CurrentLevel = LevelDefinition.CreateLevel3(); break;
            default: CurrentLevel = LevelDefinition.CreateLevel1(); break;
        }
    }

    public void StartGame()
    {
        SessionStats.Reset();
        if (CurrentLevel == null)
            CurrentLevel = LevelDefinition.CreateLevel1();
        CurrentState = GameState.Playing;
        SceneManager.LoadScene(gameSceneName);
    }

    public void EndGame()
    {
        CurrentState = GameState.Results;
        SceneManager.LoadScene(resultsSceneName);
    }

    public void LoadMainMenu()
    {
        CurrentState = GameState.Menu;
        SceneManager.LoadScene(mainMenuSceneName);
    }

    public void PauseGame()
    {
        if (CurrentState == GameState.Playing)
        {
            CurrentState = GameState.Paused;
            Time.timeScale = 0f;
        }
    }

    public void ResumeGame()
    {
        if (CurrentState == GameState.Paused)
        {
            CurrentState = GameState.Playing;
            Time.timeScale = 1f;
        }
    }

    public string GetSceneName(SceneType type)
    {
        switch (type)
        {
            case SceneType.Boot: return bootSceneName;
            case SceneType.MainMenu: return mainMenuSceneName;
            case SceneType.Game: return gameSceneName;
            case SceneType.Results: return resultsSceneName;
            default: return mainMenuSceneName;
        }
    }
}

public enum SceneType { Boot, MainMenu, Game, Results }
