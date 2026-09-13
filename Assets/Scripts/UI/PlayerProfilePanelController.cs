using UnityEngine;
using UnityEngine.UI;
public class PlayerProfilePanelController : MonoBehaviour
{
    [SerializeField] private InputField nameInput;
    [SerializeField] private Text summaryText;
    void Start()
    {
        if (nameInput != null) nameInput.text = PlayerProfileStore.Load().Name;
        RefreshSummary();
    }
    public void SaveProfile()
    {
        PlayerProfile profile = PlayerProfileStore.Load();
        if (nameInput != null) profile.Name = nameInput.text;
        GameManager.EnsureInstance().SetPlayerProfile(profile);
        RefreshSummary();
    }
    private void RefreshSummary()
    {
        if (summaryText != null)
            summaryText.text = "Local player profile. No demographic force estimate.\nSensor calibration: no verified baseline available.";
    }
}
