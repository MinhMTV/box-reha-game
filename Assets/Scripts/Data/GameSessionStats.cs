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
        Score = 0;
        FinalCombo = 0;
    }
}
