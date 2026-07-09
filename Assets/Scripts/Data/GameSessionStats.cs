[System.Serializable]
public class GameSessionStats
{
    public int TotalTargets;
    public int PerfectHits;
    public int GoodHits;
    public int EarlyHits;
    public int LateHits;
    public int Misses;
    public int MaxCombo;
    public float Accuracy => TotalTargets > 0 ? (float)(PerfectHits + GoodHits) / TotalTargets : 0f;
    public float AverageReactionTime;
    public int Score;
    public int FinalCombo;
    public float AverageRawForce;
    public float AverageNormalizedForce;
    public float AverageArmRawForce;
    public float AverageArmNormalizedForce;
    public float AverageLegRawForce;
    public float AverageLegNormalizedForce;
    public int LowForceHits;
    public int OnTargetForceHits;
    public int HighForceHits;
    public int ArmTargets;
    public int ArmHits;
    public int ArmMisses;
    public int LegTargets;
    public int LegHits;
    public int LegMisses;

    // Phase 2: Track reaction times for averaging
    private float totalReactionTime;
    private int reactionTimeCount;
    private float totalRawForce;
    private float totalNormalizedForce;
    private int forceSampleCount;
    private float totalArmRawForce;
    private float totalArmNormalizedForce;
    private int armForceSampleCount;
    private float totalLegRawForce;
    private float totalLegNormalizedForce;
    private int legForceSampleCount;

    public void TrackReactionTime(float reactionTime)
    {
        totalReactionTime += reactionTime;
        reactionTimeCount++;
        AverageReactionTime = reactionTimeCount > 0 ? totalReactionTime / reactionTimeCount : 0f;
    }

    public void TrackForce(float rawForce, float normalizedForce, ForceBand forceBand, bool isLegStrike = false)
    {
        totalRawForce += rawForce;
        totalNormalizedForce += normalizedForce;
        forceSampleCount++;
        AverageRawForce = forceSampleCount > 0 ? totalRawForce / forceSampleCount : 0f;
        AverageNormalizedForce = forceSampleCount > 0 ? totalNormalizedForce / forceSampleCount : 0f;

        if (isLegStrike)
        {
            totalLegRawForce += rawForce;
            totalLegNormalizedForce += normalizedForce;
            legForceSampleCount++;
            AverageLegRawForce = totalLegRawForce / legForceSampleCount;
            AverageLegNormalizedForce = totalLegNormalizedForce / legForceSampleCount;
        }
        else
        {
            totalArmRawForce += rawForce;
            totalArmNormalizedForce += normalizedForce;
            armForceSampleCount++;
            AverageArmRawForce = totalArmRawForce / armForceSampleCount;
            AverageArmNormalizedForce = totalArmNormalizedForce / armForceSampleCount;
        }

        switch (forceBand)
        {
            case ForceBand.Low: LowForceHits++; break;
            case ForceBand.OnTarget: OnTargetForceHits++; break;
            case ForceBand.High: HighForceHits++; break;
        }
    }

    public void TrackTargetType(TargetType targetType, bool wasHit)
    {
        bool isLegTarget = targetType == TargetType.Kick;

        if (isLegTarget)
        {
            LegTargets++;
            if (wasHit) LegHits++;
            else LegMisses++;
            return;
        }

        ArmTargets++;
        if (wasHit) ArmHits++;
        else ArmMisses++;
    }

    public void Reset()
    {
        TotalTargets = 0;
        PerfectHits = 0;
        GoodHits = 0;
        EarlyHits = 0;
        LateHits = 0;
        Misses = 0;
        MaxCombo = 0;
        AverageReactionTime = 0f;
        AverageRawForce = 0f;
        AverageNormalizedForce = 0f;
        AverageArmRawForce = 0f;
        AverageArmNormalizedForce = 0f;
        AverageLegRawForce = 0f;
        AverageLegNormalizedForce = 0f;
        LowForceHits = 0;
        OnTargetForceHits = 0;
        HighForceHits = 0;
        ArmTargets = 0;
        ArmHits = 0;
        ArmMisses = 0;
        LegTargets = 0;
        LegHits = 0;
        LegMisses = 0;
        Score = 0;
        FinalCombo = 0;
        totalReactionTime = 0f;
        reactionTimeCount = 0;
        totalRawForce = 0f;
        totalNormalizedForce = 0f;
        forceSampleCount = 0;
        totalArmRawForce = 0f;
        totalArmNormalizedForce = 0f;
        armForceSampleCount = 0;
        totalLegRawForce = 0f;
        totalLegNormalizedForce = 0f;
        legForceSampleCount = 0;
    }
}
