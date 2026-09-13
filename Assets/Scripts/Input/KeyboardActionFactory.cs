using UnityEngine;

/// <summary>Shared keyboard mapping. Each key-down produces one abstract action, with no sensor identity.</summary>
public static class KeyboardActionFactory
{
    public static PlayerActionEvent Create(ActionType action, BodySide side)
    {
        return PlayerActionEvent.Create(action, side == BodySide.Left ? LaneType.Left : LaneType.Right,
            1f, Vector2.zero, Vector2.zero, 0f, InputSourceType.Keyboard,
            action == ActionType.Kick ? VerticalPosition.Low : VerticalPosition.High,
            0f, SensorDeviceType.Unknown, side);
    }
}
