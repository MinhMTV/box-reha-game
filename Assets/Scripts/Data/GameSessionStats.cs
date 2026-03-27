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
    public int LowForceHits;
    public int OnTargetForceHits;
    public int HighForceHits;

    // Phase 2: Track reaction times for averaging
    private float totalReactionTime;
    private int reactionTimeCount;
    private float totalRawForce;
    private float totalNormalizedForce;
    private int forceSampleCount;

    public void TrackReactionTime(float reactionTime)
    {
        totalReactionTime += reactionTime;
        reactionTimeCount++;
        AverageReactionTime = reactionTimeCount > 0 ? totalReactionTime / reactionTimeCount : 0f;
    }

    public void TrackForce(float rawForce, float normalizedForce, ForceBand forceBand)
    {
        totalRawForce += rawForce;
        totalNormalizedForce += normalizedForce;
        forceSampleCount++;
        AverageRawForce = forceSampleCount > 0 ? totalRawForce / forceSampleCount : 0f;
        AverageNormalizedForce = forceSampleCount > 0 ? totalNormalizedForce / forceSampleCount : 0f;

        switch (forceBand)
        {
            case ForceBand.Low: LowForceHits++; break;
            case ForceBand.OnTarget: OnTargetForceHits++; break;
            case ForceBand.High: HighForceHits++; break;
        }
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
        LowForceHits = 0;
        OnTargetForceHits = 0;
        HighForceHits = 0;
        Score = 0;
        FinalCombo = 0;
        totalReactionTime = 0f;
        reactionTimeCount = 0;
        totalRawForce = 0f;
        totalNormalizedForce = 0f;
        forceSampleCount = 0;
    }
}
