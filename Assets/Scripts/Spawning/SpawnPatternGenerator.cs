using UnityEngine;

/// <summary>
/// Phase 3: Supports vertical position for Y offset on targets.
/// </summary>
public struct SpawnPatternData
{
    public LaneType Lane;
    public TargetType Type;
    public float Speed;
    public VerticalPosition VerticalPos;
}

/// <summary>
/// Phase 3: Generates spawn patterns with vertical position support.
/// </summary>
public static class SpawnPatternGenerator
{
    private static int patternIndex;

    public static void Reset()
    {
        patternIndex = 0;
    }

    public static SpawnPatternData GetNextPattern(LevelDefinition level)
    {
        LaneType[] lanes = level.AllowedLanes;
        TargetType[] types = level.AllowedTargetTypes;

        LaneType lane = lanes[Random.Range(0, lanes.Length)];
        TargetType type = types[Random.Range(0, types.Length)];

        // Phase 3: Random vertical position (default Mid for now)
        VerticalPosition vertPos = VerticalPosition.Mid;
        if (level.AllowedVerticalPositions != null && level.AllowedVerticalPositions.Length > 0)
        {
            vertPos = level.AllowedVerticalPositions[Random.Range(0, level.AllowedVerticalPositions.Length)];
        }

        patternIndex++;

        return new SpawnPatternData
        {
            Lane = lane,
            Type = type,
            Speed = level.TargetSpeed,
            VerticalPos = vertPos
        };
    }
}
