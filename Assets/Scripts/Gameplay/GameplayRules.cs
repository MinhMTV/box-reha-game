using System;

/// <summary>Deterministic gameplay policy shared by production code and host regression checks.</summary>
public static class GameplayRules
{
    public static HitQuality Timing(float offset, float halfWindow)
    {
        if (float.IsNaN(offset) || float.IsInfinity(offset) || float.IsNaN(halfWindow) ||
            float.IsInfinity(halfWindow) || halfWindow <= 0f) return HitQuality.Miss;
        float distance = Math.Abs(offset);
        if (distance > halfWindow) return HitQuality.Miss;
        if (distance <= Math.Min(0.1f, halfWindow)) return HitQuality.Perfect;
        if (distance <= Math.Min(0.25f, halfWindow)) return HitQuality.Good;
        return offset < 0f ? HitQuality.Early : HitQuality.Late;
    }
    public static bool Matches(ActionType action, BodySide side, LaneType actionLane, VerticalPosition position,
        TargetType targetType, LaneType targetLane, bool heavy)
    {
        if (side != BodySide.Left && side != BodySide.Right) return false;
        if (heavy) return action == ActionType.Punch && position != VerticalPosition.Low;
        if (targetLane == LaneType.Center || targetLane != actionLane) return false;
        if ((targetLane == LaneType.Left) != (side == BodySide.Left)) return false;
        if (targetType == TargetType.Punch) return action == ActionType.Punch && position != VerticalPosition.Low;
        if (targetType == TargetType.Kick) return action == ActionType.Kick && position == VerticalPosition.Low;
        return false;
    }
    public static int HeavyDamage(float value)
    {
        if (float.IsNaN(value) || float.IsInfinity(value) || value < 0f) return 0;
        return Math.Max(1, (int)Math.Round(Math.Max(0.8f, Math.Min(2.2f, value)), MidpointRounding.ToEven));
    }
    public static float ComboMultiplier(int combo)
    { return Math.Min(1f + Math.Max(0, combo - 1) * 0.1f, 3f); }
}
