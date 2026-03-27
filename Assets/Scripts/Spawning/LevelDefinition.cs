using UnityEngine;

[CreateAssetMenu(fileName = "Level", menuName = "BoxReha/LevelDefinition")]
public class LevelDefinition : ScriptableObject
{
    public int LevelNumber;
    public string DisplayName = "Level";
    public float DurationSeconds = 60f;
    public bool IsEndless;
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

    [Header("Difficulty Ramp")]
    public float RampDurationSeconds = 60f;
    public float StartSpeedMultiplier = 0.9f;
    public float MaxSpeedMultiplier = 1.3f;
    public float StartIntervalMultiplier = 1f;
    public float MinIntervalMultiplier = 0.7f;
    [Range(0f, 1f)]
    public float MaxToughTargetChance = 0.35f;
    [Range(0f, 1f)]
    public float MaxRapidFireChance = 0.25f;

    public static LevelDefinition CreateLevel1()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 1;
        level.DisplayName = "Level 1 - Easy";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
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
        level.RampDurationSeconds = 60f;
        level.StartSpeedMultiplier = 0.9f;
        level.MaxSpeedMultiplier = 1.2f;
        level.StartIntervalMultiplier = 1f;
        level.MinIntervalMultiplier = 0.78f;
        level.MaxToughTargetChance = 0.18f;
        level.MaxRapidFireChance = 0.10f;
        return level;
    }

    public static LevelDefinition CreateLevel2()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 2;
        level.DisplayName = "Level 2 - Medium";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
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
        level.RampDurationSeconds = 60f;
        level.StartSpeedMultiplier = 0.95f;
        level.MaxSpeedMultiplier = 1.35f;
        level.StartIntervalMultiplier = 1f;
        level.MinIntervalMultiplier = 0.68f;
        level.MaxToughTargetChance = 0.28f;
        level.MaxRapidFireChance = 0.18f;
        return level;
    }

    public static LevelDefinition CreateLevel3()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 3;
        level.DisplayName = "Level 3 - Hard";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
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
        level.RampDurationSeconds = 60f;
        level.StartSpeedMultiplier = 1f;
        level.MaxSpeedMultiplier = 1.5f;
        level.StartIntervalMultiplier = 0.95f;
        level.MinIntervalMultiplier = 0.55f;
        level.MaxToughTargetChance = 0.38f;
        level.MaxRapidFireChance = 0.28f;
        return level;
    }

    public static LevelDefinition CreateEndless()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 4;
        level.DisplayName = "Endless Mode";
        level.DurationSeconds = 0f;
        level.IsEndless = true;
        level.SpawnInterval = 1.8f;
        level.TargetSpeed = 5.2f;
        level.HitWindowSeconds = 0.95f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Block, TargetType.Dodge };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Center, LaneType.Right };
        level.MinPower = 0f;
        level.AllowedVerticalPositions = new VerticalPosition[] { VerticalPosition.Low, VerticalPosition.Mid, VerticalPosition.High };
        level.ToughTargetChance = 0.16f;
        level.MinToughHits = 3;
        level.MaxToughHits = 5;
        level.RapidFireChance = 0.12f;
        level.MinChainLength = 3;
        level.MaxChainLength = 6;
        level.RampDurationSeconds = 180f;
        level.StartSpeedMultiplier = 0.95f;
        level.MaxSpeedMultiplier = 1.9f;
        level.StartIntervalMultiplier = 1f;
        level.MinIntervalMultiplier = 0.4f;
        level.MaxToughTargetChance = 0.50f;
        level.MaxRapidFireChance = 0.35f;
        return level;
    }
}
