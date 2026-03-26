using UnityEngine;

[CreateAssetMenu(fileName = "GameConfig", menuName = "BoxReha/GameConfig")]
public class GameConfig : ScriptableObject
{
    [Header("Timing")]
    public float PerfectWindow = 0.1f;
    public float GoodWindow = 0.25f;
    public float EarlyLateWindow = 0.5f;

    [Header("Scoring")]
    public int PerfectScore = 100;
    public int GoodScore = 50;
    public int EarlyLateScore = 25;
    public int BlockScore = 75;
    public int DodgeScore = 75;
    public float MaxComboMultiplier = 3f;
    public float ComboMultiplierStep = 0.1f;

    [Header("Input")]
    public float PowerHoldThreshold = 0.3f;
    public float SwipeMinDistance = 200f;
    public float BlockHoldDuration = 0.5f;
    public float SwipeMaxDuration = 0.3f;
    public float BlockMaxMovement = 10f;

    [Header("Visual")]
    public Color PunchColor = Color.red;
    public Color BlockColor = Color.blue;
    public Color DodgeColor = Color.green;
    public Color HitFlashColor = Color.green;
    public Color MissFlashColor = Color.red;

    [Header("Spawn")]
    public float DefaultTargetSpeed = 5f;
    public float DefaultSpawnInterval = 2f;
    public float DefaultDuration = 60f;

    [Header("Lanes")]
    public float LaneSpacing = 3f;
    public float SpawnDistance = 30f;
    public float HitZoneDistance = 5f;

    [Header("Vertical Position")]
    public float VerticalOffsetHigh = 2.5f;
    public float VerticalOffsetMid = 1.2f;
    public float VerticalOffsetLow = 0.2f;

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
