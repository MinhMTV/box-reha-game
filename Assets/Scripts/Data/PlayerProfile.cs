using UnityEngine;

[System.Serializable]
public class PlayerProfile
{
    public float HeightCm = 175f;
    public float WeightKg = 70f;
    public SexCategory Sex = SexCategory.Unspecified;

    /// <summary>
    /// Heuristic baseline for expected strike force.
    /// This is not a medical measurement and is only used to normalize sensor values fairly.
    /// </summary>
    public float GetEstimatedAveragePunchForce()
    {
        float clampedHeight = Mathf.Clamp(HeightCm, 120f, 220f);
        float clampedWeight = Mathf.Clamp(WeightKg, 30f, 180f);

        float weightComponent = clampedWeight * 11.5f;
        float heightComponent = Mathf.Max(0f, clampedHeight - 140f) * 1.75f;
        float sexFactor = GetSexFactor();

        return Mathf.Max(150f, (weightComponent + heightComponent) * sexFactor);
    }

    public float NormalizePunchForce(float measuredForce)
    {
        float baseline = GetEstimatedAveragePunchForce();
        if (baseline <= 0f)
        {
            return 1f;
        }

        return measuredForce / baseline;
    }

    public ForceBand GetForceBand(float normalizedForce)
    {
        if (normalizedForce < 0.85f) return ForceBand.Low;
        if (normalizedForce <= 1.15f) return ForceBand.OnTarget;
        return ForceBand.High;
    }

    public string GetForceBandLabel(float normalizedForce)
    {
        switch (GetForceBand(normalizedForce))
        {
            case ForceBand.Low: return "Below target";
            case ForceBand.OnTarget: return "On target";
            default: return "Above target";
        }
    }

    private float GetSexFactor()
    {
        switch (Sex)
        {
            case SexCategory.Female: return 0.82f;
            case SexCategory.Male: return 1f;
            case SexCategory.NonBinary: return 0.91f;
            default: return 0.9f;
        }
    }
}

public enum ForceBand
{
    Low,
    OnTarget,
    High
}
