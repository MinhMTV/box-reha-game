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
    public float MaxComboMultiplier = 3f;
    public float ComboMultiplierStep = 0.1f;

    [Header("Input")]
    public float PowerHoldThreshold = 0.3f;
    public float SwipeMinDistance = 50f;

    [Header("Visual")]
    public Color PunchColor = Color.red;
    public Color BlockColor = Color.blue;
    public Color DodgeColor = Color.green;

    [Header("Spawn")]
    public float DefaultTargetSpeed = 5f;
    public float DefaultSpawnInterval = 2f;
    public float DefaultDuration = 60f;

    [Header("Lanes")]
    public float LaneSpacing = 3f;
    public float SpawnDistance = 30f;
    public float HitZoneDistance = 5f;
}
