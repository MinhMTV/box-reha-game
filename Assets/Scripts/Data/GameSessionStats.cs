[System.Serializable]
public class GameSessionStats
{
    public string SessionId, StudyId, StartedUtc, Mode, StopReason, LogPath;
    public int BelowStrengthHits;
    public int AlphaLeftSamples, AlphaRightSamples, DeltaLeftSamples, DeltaRightSamples;
    public double AlphaLeftRelativeSum, AlphaRightRelativeSum, DeltaLeftRelativeSum, DeltaRightRelativeSum;
    public float DurationSeconds;
    public int SpawnedTargets, AbortedTargets, HeavyTimeouts;
    public int Actions, LeftActions, RightActions, PunchActions, KickActions;
    public int KeyboardActions, SensorActions, OtherActions;
    public int LeftTargets, RightTargets, CenterTargets, LeftHits, RightHits, CenterHits;
    public int SuccessfulHits => PerfectHits + GoodHits + EarlyHits + LateHits;
    // Historical "Accuracy" is retained as good-or-better timing accuracy, not sensor accuracy.
    public float CompletionRate => TotalTargets > 0 ? (float)SuccessfulHits / TotalTargets : 0f;
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
    public int ArmTargets;
    public int ArmHits;
    public int ArmMisses;
    public int LegTargets;
    public int LegHits;
    public int LegMisses;

    // Phase 2: Track reaction times for averaging
    private float totalReactionTime;
    private int reactionTimeCount;
    public void TrackReactionTime(float reactionTime)
    {
        if (float.IsNaN(reactionTime) || float.IsInfinity(reactionTime) || reactionTime < 0f) return;
        totalReactionTime += reactionTime;
        reactionTimeCount++;
        AverageReactionTime = reactionTimeCount > 0 ? totalReactionTime / reactionTimeCount : 0f;
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
        SessionId = StudyId = StartedUtc = Mode = StopReason = LogPath = null;
        BelowStrengthHits=AlphaLeftSamples=AlphaRightSamples=DeltaLeftSamples=DeltaRightSamples=0;
        AlphaLeftRelativeSum=AlphaRightRelativeSum=DeltaLeftRelativeSum=DeltaRightRelativeSum=0;
        DurationSeconds = 0f;
        SpawnedTargets = AbortedTargets = HeavyTimeouts = 0;
        Actions = LeftActions = RightActions = PunchActions = KickActions = 0;
        KeyboardActions = SensorActions = OtherActions = 0;
        LeftTargets = RightTargets = CenterTargets = LeftHits = RightHits = CenterHits = 0;
        TotalTargets = 0;
        PerfectHits = 0;
        GoodHits = 0;
        EarlyHits = 0;
        LateHits = 0;
        Misses = 0;
        MaxCombo = 0;
        AverageReactionTime = 0f;
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
    }

    public void TrackAction(PlayerActionEvent action)
    {
        if(action.SourceType==InputSourceType.Sensor && action.NormalizationValid)
        {
            if(action.SensorDevice==SensorDeviceType.Alpha && action.BodySide==BodySide.Left){AlphaLeftSamples++;AlphaLeftRelativeSum+=action.Power;}
            if(action.SensorDevice==SensorDeviceType.Alpha && action.BodySide==BodySide.Right){AlphaRightSamples++;AlphaRightRelativeSum+=action.Power;}
            if(action.SensorDevice==SensorDeviceType.Delta && action.BodySide==BodySide.Left){DeltaLeftSamples++;DeltaLeftRelativeSum+=action.Power;}
            if(action.SensorDevice==SensorDeviceType.Delta && action.BodySide==BodySide.Right){DeltaRightSamples++;DeltaRightRelativeSum+=action.Power;}
        }
        Actions++;
        if (action.BodySide == BodySide.Left) LeftActions++;
        if (action.BodySide == BodySide.Right) RightActions++;
        if (action.ActionType == ActionType.Punch) PunchActions++;
        if (action.ActionType == ActionType.Kick) KickActions++;
        if (action.SourceType == InputSourceType.Keyboard) KeyboardActions++;
        else if (action.SourceType == InputSourceType.Sensor) SensorActions++;
        else OtherActions++;
    }

    public void TrackLane(LaneType lane, bool hit)
    {
        if (lane == LaneType.Left) { LeftTargets++; if (hit) LeftHits++; }
        else if (lane == LaneType.Right) { RightTargets++; if (hit) RightHits++; }
        else { CenterTargets++; if (hit) CenterHits++; }
    }
}
