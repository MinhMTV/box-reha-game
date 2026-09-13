using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    public GameState CurrentState { get; set; }
    public GameSessionStats SessionStats { get; private set; }
    public LevelDefinition CurrentLevel { get; private set; }
    public PlayerProfile PlayerProfile { get; private set; }
    // Phase 4: Track selected level number
    public int SelectedLevel { get; private set; } = 1;

    [SerializeField] private string bootSceneName = "Boot";
    [SerializeField] private string mainMenuSceneName = "MainMenu";
    [SerializeField] private string gameSceneName = "Game";
    [SerializeField] private string resultsSceneName = "Results";

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void EnsureRuntimeInstance()
    {
        EnsureInstance();
    }

    public static GameManager EnsureInstance()
    {
        if (Instance != null)
        {
            return Instance;
        }

        GameObject managerObject = new GameObject("GameManager");
        return managerObject.AddComponent<GameManager>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        if (SessionStats == null)
        {
            SessionStats = new GameSessionStats();
        }
        if (PlayerProfile == null)
        {
            PlayerProfile = PlayerProfileStore.Load();
        }
        CurrentState = GameState.Menu;
        AndroidDynamicsController.EnsureInstance().SelectParticipant(PlayerProfile.StudyId);

        // Ensure AudioManager exists
        if (AudioManager.Instance == null)
        {
            GameObject audioObj = new GameObject("AudioManager");
            audioObj.AddComponent<AudioManager>();
        }
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
            case 4: CurrentLevel = LevelDefinition.CreateEndless(); break;
            default: CurrentLevel = LevelDefinition.CreateLevel1(); break;
        }
    }

    public void StartGame()
    {
        if (SessionInputSelection.Physical)
        {
            AndroidDynamicsController.EnsureInstance().RequestGameStart();
            return;
        }
        StartRoundScene();
    }

    public void StartAcknowledgedSensorGame()
    {
        if (SessionInputSelection.Physical && AndroidDynamicsController.EnsureInstance().Running) StartRoundScene();
    }

    private void StartRoundScene()
    {
        Time.timeScale = 1f;
        PlayerProfile = PlayerProfileStore.Load();
        SessionStats.Reset();
        SetLevel(SelectedLevel);
        if (SessionInputSelection.Physical)
        {
            CurrentLevel.RestrictToSensorFamily(SessionInputSelection.Family);
            CurrentLevel.AllowedLanes = AndroidSessionPolicy.ConnectedLanes(AndroidDynamicsController.EnsureInstance().Status, SessionInputSelection.Family);
        }
        CurrentState = GameState.Playing;
        SceneManager.LoadScene(gameSceneName);
    }

    public void EndGame()
    {
        AndroidDynamicsController.Instance?.FinishSession();
        Time.timeScale = 1f;
        CurrentState = GameState.Results;
        SceneManager.LoadScene(resultsSceneName);
    }

    public void LoadMainMenu()
    {
        AndroidDynamicsController.Instance?.FinishSession();
        Time.timeScale = 1f;
        CurrentState = GameState.Menu;
        SceneManager.LoadScene(mainMenuSceneName);
    }

    public void PauseGame()
    {
        if (CurrentState == GameState.Playing)
        {
            CurrentState = GameState.Paused;
            ResearchSessionLog.State("pause");
            InputProviderRouter router = FindObjectOfType<InputProviderRouter>();
            if (router != null) router.IsEnabled = false;
            Time.timeScale = 0f;
            AndroidDynamicsController.Instance?.PauseSession();
        }
    }

    public void ResumeGame()
    {
        if (SessionInputSelection.Physical)
        {
            AndroidDynamicsController.EnsureInstance().RequestResume();
            return;
        }
        ResumeAcknowledgedSensorGame();
    }

    public void ResumeAcknowledgedSensorGame()
    {
        if (SessionInputSelection.Physical && !AndroidDynamicsController.EnsureInstance().Running) return;
        if (CurrentState == GameState.Paused)
        {
            CurrentState = GameState.Playing;
            Time.timeScale = 1f;
            ResearchSessionLog.State("resume");
            InputProviderRouter router = FindObjectOfType<InputProviderRouter>();
            if (router != null) router.IsEnabled = true;
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

    public void SetPlayerProfile(PlayerProfile profile)
    {
        if (profile == null)
        {
            return;
        }

        PlayerProfile = profile;
        PlayerProfileStore.Save(profile);
        AndroidDynamicsController.EnsureInstance().SelectParticipant(profile.StudyId);
    }
}

public enum SceneType { Boot, MainMenu, Game, Results }
