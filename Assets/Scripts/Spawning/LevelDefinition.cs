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
    // Phase 3: Allowed vertical positions
    public VerticalPosition[] AllowedVerticalPositions = { VerticalPosition.Mid };

    // v3: Tough target configuration
    [Header("Tough Targets")]
    [Range(0f, 1f)]
    public float ToughTargetChance = 0.15f;
    public int MinToughHits = 3;
    public int MaxToughHits = 5;

    // v3: Rapid fire chain configuration
    [Header("Rapid Fire Chains")]
    [Range(0f, 1f)]
    public float RapidFireChance = 0.1f;
    public int MinChainLength = 3;
    public int MaxChainLength = 5;

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
        level.AllowedVerticalPositions = new VerticalPosition[] { VerticalPosition.Mid };
        // v3: Easy tough targets
        level.ToughTargetChance = 0.10f;
        level.MinToughHits = 3;
        level.MaxToughHits = 4;
        level.RapidFireChance = 0.05f;
        level.MinChainLength = 3;
        level.MaxChainLength = 4;
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
        level.AllowedVerticalPositions = new VerticalPosition[] { VerticalPosition.Mid };
        // v3: Medium tough targets
        level.ToughTargetChance = 0.15f;
        level.MinToughHits = 3;
        level.MaxToughHits = 5;
        level.RapidFireChance = 0.10f;
        level.MinChainLength = 3;
        level.MaxChainLength = 5;
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
        level.AllowedVerticalPositions = new VerticalPosition[] { VerticalPosition.Low, VerticalPosition.Mid, VerticalPosition.High };
        // v3: Hard tough targets
        level.ToughTargetChance = 0.20f;
        level.MinToughHits = 4;
        level.MaxToughHits = 5;
        level.RapidFireChance = 0.15f;
        level.MinChainLength = 4;
        level.MaxChainLength = 5;
        return level;
    }
}
