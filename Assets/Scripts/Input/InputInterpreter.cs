using UnityEngine;

public static class InputInterpreter
{
    public static bool IsSwipe(Vector2 start, Vector2 end, float minDistance)
    {
        return Vector2.Distance(start, end) >= minDistance;
    }

    public static bool IsHold(float holdDuration, float threshold)
    {
        return holdDuration >= threshold;
    }

    public static LaneType GetLaneFromScreenX(float screenX)
    {
        float third = Screen.width / 3f;
        if (screenX < third) return LaneType.Left;
        if (screenX < third * 2) return LaneType.Center;
        return LaneType.Right;
    }
}
