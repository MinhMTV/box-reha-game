using UnityEngine;

[System.Serializable]
public struct PlayerActionEvent
{
    public ActionType ActionType;
    public LaneType Lane;
    public float Power;
    public double Timestamp;
    public Vector2 StartScreenPosition;
    public Vector2 EndScreenPosition;
    public float HoldDuration;
    public InputSourceType SourceType;
    // Phase 3: Vertical position for future high/low punches
    public VerticalPosition VerticalPos;

    public static PlayerActionEvent Create(ActionType action, LaneType lane, float power,
        Vector2 startPos, Vector2 endPos, float holdDuration, InputSourceType source,
        VerticalPosition verticalPos = VerticalPosition.Mid)
    {
        return new PlayerActionEvent
        {
            ActionType = action,
            Lane = lane,
            Power = power,
            Timestamp = Time.realtimeSinceStartupAsDouble,
            StartScreenPosition = startPos,
            EndScreenPosition = endPos,
            HoldDuration = holdDuration,
            SourceType = source,
            VerticalPos = verticalPos
        };
    }
}
