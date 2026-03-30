using UnityEngine;
using UnityEngine.UI;

public class PlayerProfilePanelController : MonoBehaviour
{
    [SerializeField] private InputField heightInput;
    [SerializeField] private InputField weightInput;
    [SerializeField] private InputField sexInput;
    [SerializeField] private Text summaryText;

    private bool isRefreshing;

    void Start()
    {
        LoadProfileIntoUi();
        RefreshSummary();
    }

    public void SaveProfile()
    {
        if (isRefreshing)
        {
            return;
        }

        PlayerProfile profile = ReadProfileFromUi();
        PlayerProfileStore.Save(profile);
        GameManager.EnsureInstance().SetPlayerProfile(profile);
        RefreshSummary();
    }

    private void LoadProfileIntoUi()
    {
        PlayerProfile profile = PlayerProfileStore.Load();

        isRefreshing = true;
        if (heightInput != null) heightInput.text = profile.HeightCm.ToString("F0");
        if (weightInput != null) weightInput.text = profile.WeightKg.ToString("F0");
        if (sexInput != null) sexInput.text = profile.Sex.ToString();
        isRefreshing = false;
    }

    private PlayerProfile ReadProfileFromUi()
    {
        PlayerProfile profile = PlayerProfileStore.Load();

        if (heightInput != null && float.TryParse(heightInput.text, out float height))
        {
            profile.HeightCm = Mathf.Clamp(height, 120f, 220f);
        }

        if (weightInput != null && float.TryParse(weightInput.text, out float weight))
        {
            profile.WeightKg = Mathf.Clamp(weight, 30f, 180f);
        }

        if (sexInput != null)
        {
            profile.Sex = ParseSex(sexInput.text);
        }

        return profile;
    }

    private SexCategory ParseSex(string value)
    {
        if (string.IsNullOrWhiteSpace(value))
        {
            return SexCategory.Unspecified;
        }

        string normalized = value.Trim().ToLowerInvariant();
        if (normalized.StartsWith("f"))
        {
            return SexCategory.Female;
        }
        if (normalized.StartsWith("m"))
        {
            return SexCategory.Male;
        }
        if (normalized.StartsWith("n") || normalized.Contains("binary"))
        {
            return SexCategory.NonBinary;
        }

        return SexCategory.Unspecified;
    }

    private void RefreshSummary()
    {
        if (summaryText == null)
        {
            return;
        }

        PlayerProfile profile = ReadProfileFromUi();
        summaryText.text =
            $"Estimated avg punch force: {profile.GetEstimatedAveragePunchForce():F0} N\n" +
            "Used to normalize glove force fairly across players.";
        summaryText.color = new Color(0.78f, 0.90f, 1f, 1f);
    }
}
