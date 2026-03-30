using UnityEngine;

public static class GameVisualPalette
{
    public static readonly Color PunchColor = new Color(1f, 0.29f, 0.22f, 1f);
    public static readonly Color ToughPunchColor = new Color(1f, 0.62f, 0.16f, 1f);
    public static readonly Color BlockColor = new Color(0.20f, 0.78f, 1f, 1f);
    public static readonly Color DodgeColor = new Color(0.34f, 1f, 0.62f, 1f);
    public static readonly Color PerfectColor = new Color(1f, 0.92f, 0.24f, 1f);
    public static readonly Color MissColor = new Color(1f, 0.24f, 0.34f, 1f);

    public static Color GetTargetColor(TargetType type)
    {
        switch (type)
        {
            case TargetType.Block:
                return BlockColor;
            case TargetType.Dodge:
                return DodgeColor;
            case TargetType.ToughPunch:
                return ToughPunchColor;
            default:
                return PunchColor;
        }
    }

    public static Color GetTargetHighlight(TargetType type)
    {
        switch (type)
        {
            case TargetType.Block:
                return new Color(0.82f, 0.97f, 1f, 1f);
            case TargetType.Dodge:
                return new Color(0.86f, 1f, 0.92f, 1f);
            case TargetType.ToughPunch:
                return new Color(1f, 0.86f, 0.24f, 1f);
            default:
                return new Color(1f, 0.95f, 0.36f, 1f);
        }
    }

    public static Color GetLaneBaseColor(LaneType lane)
    {
        switch (lane)
        {
            case LaneType.Left:
                return new Color(0.10f, 0.34f, 0.56f, 1f);
            case LaneType.Center:
                return new Color(0.14f, 0.47f, 0.70f, 1f);
            case LaneType.Right:
                return new Color(0.10f, 0.34f, 0.56f, 1f);
            default:
                return new Color(0.14f, 0.47f, 0.70f, 1f);
        }
    }

    public static int GetParticleCount(TargetType type)
    {
        switch (type)
        {
            case TargetType.Block:
                return 18;
            case TargetType.Dodge:
                return 16;
            case TargetType.ToughPunch:
                return 30;
            default:
                return 22;
        }
    }

    public static float GetSpawnWarningDuration(TargetType type)
    {
        switch (type)
        {
            case TargetType.ToughPunch:
                return 0.42f;
            case TargetType.Block:
                return 0.28f;
            case TargetType.Dodge:
                return 0.22f;
            default:
                return 0.24f;
        }
    }
}
