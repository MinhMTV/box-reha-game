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

        TargetType type = ResolveTargetType(types);
        LaneType lane = ResolveLane(type, lanes);

        VerticalPosition vertPos = ResolveVerticalPosition(type, level);

        patternIndex++;

        return new SpawnPatternData
        {
            Lane = lane,
            Type = type,
            Speed = level.TargetSpeed,
            VerticalPos = vertPos
        };
    }

    private static VerticalPosition ResolveVerticalPosition(TargetType type, LevelDefinition level)
    {
        switch (type)
        {
            case TargetType.Kick:
                return VerticalPosition.Low;
            case TargetType.Punch:
            case TargetType.ToughPunch:
                return VerticalPosition.High;
            case TargetType.Dodge:
            case TargetType.Block:
                return VerticalPosition.Mid;
            default:
                return GetAllowedFallback(level);
        }
    }

    private static TargetType ResolveTargetType(TargetType[] allowedTypes)
    {
        if (allowedTypes == null || allowedTypes.Length == 0)
        {
            return Random.value < 0.5f ? TargetType.Punch : TargetType.Kick;
        }

        int validCount = 0;
        for (int i = 0; i < allowedTypes.Length; i++)
        {
            if (allowedTypes[i] == TargetType.Punch || allowedTypes[i] == TargetType.Kick)
            {
                validCount++;
            }
        }

        if (validCount == 0)
        {
            return Random.value < 0.5f ? TargetType.Punch : TargetType.Kick;
        }

        int selectedIndex = Random.Range(0, validCount);
        for (int i = 0; i < allowedTypes.Length; i++)
        {
            if (allowedTypes[i] != TargetType.Punch && allowedTypes[i] != TargetType.Kick)
            {
                continue;
            }

            if (selectedIndex == 0)
            {
                return allowedTypes[i];
            }

            selectedIndex--;
        }

        return TargetType.Punch;
    }

    private static LaneType ResolveLane(TargetType type, LaneType[] allowedLanes)
    {
        if (type == TargetType.ToughPunch)
        {
            return LaneType.Center;
        }

        if (allowedLanes == null || allowedLanes.Length == 0)
        {
            return Random.value < 0.5f ? LaneType.Left : LaneType.Right;
        }

        int validCount = 0;
        for (int i = 0; i < allowedLanes.Length; i++)
        {
            if (allowedLanes[i] != LaneType.Center)
            {
                validCount++;
            }
        }

        if (validCount == 0)
        {
            return Random.value < 0.5f ? LaneType.Left : LaneType.Right;
        }

        int selectedIndex = Random.Range(0, validCount);
        for (int i = 0; i < allowedLanes.Length; i++)
        {
            if (allowedLanes[i] == LaneType.Center)
            {
                continue;
            }

            if (selectedIndex == 0)
            {
                return allowedLanes[i];
            }

            selectedIndex--;
        }

        return LaneType.Left;
    }

    private static VerticalPosition GetAllowedFallback(LevelDefinition level)
    {
        if (level.AllowedVerticalPositions != null && level.AllowedVerticalPositions.Length > 0)
        {
            return level.AllowedVerticalPositions[Random.Range(0, level.AllowedVerticalPositions.Length)];
        }

        return VerticalPosition.Mid;
    }
}
