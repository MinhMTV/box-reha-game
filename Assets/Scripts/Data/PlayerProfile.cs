using System;
[Serializable]
public class PlayerProfile
{
    public string Name = "Player";
    public string StudyId = Guid.NewGuid().ToString("N");
    public ForceBand GetForceBand(float value)
    {
        if (value < 0.85f) return ForceBand.Low;
        return value <= 1.15f ? ForceBand.OnTarget : ForceBand.High;
    }
    public string GetForceBandLabel(float value)
    {
        switch (GetForceBand(value))
        {
            case ForceBand.Low: return "Below baseline";
            case ForceBand.OnTarget: return "Near baseline";
            default: return "Above baseline";
        }
    }
}
public enum ForceBand { Low, OnTarget, High }
