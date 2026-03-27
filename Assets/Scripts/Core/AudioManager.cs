using UnityEngine;

/// <summary>
/// Singleton AudioManager. MVP: Debug.Log placeholder.
/// Ready for later AudioSource + AudioClip integration.
/// </summary>
public class AudioManager : MonoBehaviour
{
    public static AudioManager Instance { get; private set; }

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    public void PlayHitSound()
    {
        Debug.Log("[AudioManager] PlayHitSound");
    }

    public void PlayMissSound()
    {
        Debug.Log("[AudioManager] PlayMissSound");
    }

    public void PlayComboSound()
    {
        Debug.Log("[AudioManager] PlayComboSound");
    }

    public void PlayBlockSound()
    {
        Debug.Log("[AudioManager] PlayBlockSound");
    }

    public void PlayDodgeSound()
    {
        Debug.Log("[AudioManager] PlayDodgeSound");
    }

    public void PlayMenuClick()
    {
        Debug.Log("[AudioManager] PlayMenuClick");
    }

    public void PlayCountdownTick()
    {
        Debug.Log("[AudioManager] PlayCountdownTick");
    }

    /// <summary>
    /// v3: Sound when hitting a tough target (not destroyed yet).
    /// </summary>
    public void PlayToughHitSound()
    {
        Debug.Log("[AudioManager] PlayToughHitSound");
    }

    /// <summary>
    /// v3: Sound when a tough target is finally destroyed.
    /// </summary>
    public void PlayToughBreakSound()
    {
        Debug.Log("[AudioManager] PlayToughBreakSound");
    }
}
