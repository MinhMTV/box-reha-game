using UnityEngine;
using System.Collections.Generic;

public struct SpawnPatternData
{
    public LaneType Lane;
    public TargetType Type;
    public float Speed;
}

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

        patternIndex++;

        return new SpawnPatternData
        {
            Lane = lane,
            Type = type,
            Speed = level.TargetSpeed
        };
    }
}
