using UnityEngine;

[CreateAssetMenu(fileName = "Level", menuName = "BoxReha/LevelDefinition")]
public class LevelDefinition : ScriptableObject
{
    public int LevelNumber;
    public string DisplayName = "Level";
    public float DurationSeconds = 60f;
    public bool IsEndless;
    public float HitWindowSeconds = 0.85f;
    public TargetType[] AllowedTargetTypes = { TargetType.Punch, TargetType.Kick };
    public LaneType[] AllowedLanes = { LaneType.Left, LaneType.Right };

    public bool HeavyTargetsEnabled = true;
    public int MinToughHits = 8;
    public int MaxToughHits = 12;



    public void RestrictToSensorFamily(string family)
    {
        if (family != "Alpha" && family != "Delta") throw new System.ArgumentException("Unsupported sensor family", nameof(family));
        bool alpha = family == "Alpha";
        AllowedTargetTypes = new[] { alpha ? TargetType.Punch : TargetType.Kick };
        DisplayName += alpha ? " / Alpha punches" : " / Delta kick mapping (experimental)";
    }

    public static LevelDefinition CreateLevel1()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 1;
        level.DisplayName = "Level 1 - Rhythm Basics";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
        level.HitWindowSeconds = 0.9f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Kick };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Right };
        level.HeavyTargetsEnabled = true;
        level.MinToughHits = 8;
        level.MaxToughHits = 10;
        return level;
    }

    public static LevelDefinition CreateLevel2()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 2;
        level.DisplayName = "Level 2 - Arms & Legs";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
        level.HitWindowSeconds = 0.85f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Kick };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Right };
        level.HeavyTargetsEnabled = true;
        level.MinToughHits = 10;
        level.MaxToughHits = 12;
        return level;
    }

    public static LevelDefinition CreateLevel3()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 3;
        level.DisplayName = "Level 3 - Combat Flow";
        level.DurationSeconds = 60f;
        level.IsEndless = false;
        level.HitWindowSeconds = 0.8f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Kick };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Right };
        level.HeavyTargetsEnabled = true;
        level.MinToughHits = 12;
        level.MaxToughHits = 15;
        return level;
    }

    public static LevelDefinition CreateEndless()
    {
        LevelDefinition level = CreateInstance<LevelDefinition>();
        level.LevelNumber = 4;
        level.DisplayName = "Endless Mode";
        level.DurationSeconds = 0f;
        level.IsEndless = true;
        level.HitWindowSeconds = 0.8f;
        level.AllowedTargetTypes = new TargetType[] { TargetType.Punch, TargetType.Kick };
        level.AllowedLanes = new LaneType[] { LaneType.Left, LaneType.Right };
        level.HeavyTargetsEnabled = true;
        level.MinToughHits = 10;
        level.MaxToughHits = 18;
        return level;
    }
}
