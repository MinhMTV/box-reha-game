using UnityEngine;
using UnityEngine.SceneManagement;

public class Bootstrapper : MonoBehaviour
{
    [SerializeField] private bool autoLoadMainMenu = true;
    [SerializeField] private float delay = 0.5f;

    void Start()
    {
        if (GameManager.Instance == null)
        {
            GameObject managerObj = new GameObject("GameManager");
            managerObj.AddComponent<GameManager>();
        }

        if (autoLoadMainMenu)
        {
            Invoke(nameof(LoadMainMenu), delay);
        }
    }

    private void LoadMainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}
