using UnityEngine;

[CreateAssetMenu(fileName = "Level", menuName = "BoxReha/LevelDefinition")]
public class LevelDefinition : ScriptableObject
{
    public int LevelNumber;
    public float DurationSeconds = 60f;
    public float SpawnInterval = 2f;
    public float TargetSpeed = 5f;
    public float HitWindowSeconds = 1f;
    public TargetType[] AllowedTargetTypes = { TargetType.Punch };
    public LaneType[] AllowedLanes = { LaneType.Left, LaneType.Center, LaneType.Right };
    public float MinPower = 0f;

    public static LevelDefinition CreateLevel1()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 1;
        level.DurationSeconds = 60f;
        level.SpawnInterval = 2.5f;
        level.TargetSpeed = 4f;
        level.HitWindowSeconds = 1f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Center, LaneType.Right };
        level.MinPower = 0f;
        return level;
    }

    public static LevelDefinition CreateLevel2()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 2;
        level.DurationSeconds = 60f;
        level.SpawnInterval = 2f;
        level.TargetSpeed = 5f;
        level.HitWindowSeconds = 1f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Block };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Center, LaneType.Right };
        level.MinPower = 0f;
        return level;
    }

    public static LevelDefinition CreateLevel3()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 3;
        level.DurationSeconds = 60f;
        level.SpawnInterval = 1.5f;
        level.TargetSpeed = 6f;
        level.HitWindowSeconds = 1f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Block, TargetType.Dodge };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Center, LaneType.Right };
        level.MinPower = 0f;
        return level;
    }
}
