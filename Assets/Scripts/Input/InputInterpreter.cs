using UnityEngine;

public static class InputInterpreter
{
    /// <summary>
    /// Classify input based on hold duration and swipe distance.
    /// </summary>
    public static ActionType ClassifyAction(float holdDuration, float swipeDistance, float swipeDuration,
        float blockHoldThreshold, float swipeMinDistance, float swipeMaxDuration, float blockMaxMovement)
    {
        // Fast horizontal swipe → Dodge
        if (swipeDistance >= swipeMinDistance && swipeDuration <= swipeMaxDuration)
        {
            return ActionType.Dodge;
        }

        // Hold without significant movement → Block
        if (holdDuration >= blockHoldThreshold && swipeDistance < blockMaxMovement)
        {
            return ActionType.Block;
        }

        // Quick click/release → Punch
        return ActionType.Punch;
    }

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

    // Phase 3: Map vertical screen position to VerticalPosition
    public static VerticalPosition GetVerticalPositionFromScreenY(float screenY)
    {
        float third = Screen.height / 3f;
        if (screenY < third) return VerticalPosition.Low;
        if (screenY < third * 2) return VerticalPosition.Mid;
        return VerticalPosition.High;
    }
}
