using UnityEngine;

[CreateAssetMenu(fileName = "GameConfig", menuName = "BoxReha/GameConfig")]
public class GameConfig : ScriptableObject
{


    public float SensorPunchAccelerationThreshold = 18f;
    public float SensorKickAccelerationThreshold = 16f;
    public float SensorActionCooldown = 0.35f;




    [Header("Vertical Position")]
    public float VerticalOffsetHigh = 2.6f;
    public float VerticalOffsetMid = 1.55f;
    public float VerticalOffsetLow = 0.45f;

    // Phase 3: Input source selection
    [Header("Input Source")]
    public InputSourceType ActiveInputSourceType = InputSourceType.Mouse;

    public float GetVerticalOffset(VerticalPosition pos)
    {
        switch (pos)
        {
            case VerticalPosition.High: return VerticalOffsetHigh;
            case VerticalPosition.Low: return VerticalOffsetLow;
            default: return VerticalOffsetMid;
        }
    }
}
