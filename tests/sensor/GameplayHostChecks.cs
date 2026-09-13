using System;

internal static class GameplayHostChecks
{
    public static void Run()
    {
        Action[] checks = { MappingRejectsWrongActions, TimingBoundariesAreSigned, HeavyAcceptsRepeatedSides,
            ScoreMultiplierIsBounded, StatisticsKeepDenominatorsDistinct };
        foreach (Action check in checks) check();
        Console.WriteLine("GAMEPLAY_HOST_PASS " + checks.Length + " production rule/statistics checks; not Unity runtime tests.");
    }
    private static void Require(bool condition, string message)
    { if (!condition) throw new InvalidOperationException("Gameplay host: " + message); }
    private static void MappingRejectsWrongActions()
    {
        foreach (BodySide side in new[] { BodySide.Left, BodySide.Right })
        foreach (ActionType type in new[] { ActionType.Punch, ActionType.Kick })
        {
            LaneType lane = side == BodySide.Left ? LaneType.Left : LaneType.Right;
            VerticalPosition height = type == ActionType.Punch ? VerticalPosition.High : VerticalPosition.Low;
            TargetType target = type == ActionType.Punch ? TargetType.Punch : TargetType.Kick;
            Require(GameplayRules.Matches(type, side, lane, height, target, lane, false), "correct action/side");
            Require(!GameplayRules.Matches(type, side == BodySide.Left ? BodySide.Right : BodySide.Left,
                lane, height, target, lane, false), "wrong side");
            Require(!GameplayRules.Matches(type == ActionType.Punch ? ActionType.Kick : ActionType.Punch,
                side, lane, height, target, lane, false), "wrong action");
            Require(!GameplayRules.Matches(type, side, lane, height == VerticalPosition.High ? VerticalPosition.Low : VerticalPosition.High,
                target, lane, false), "wrong height");
            Require(!GameplayRules.Matches(type, side, LaneType.Center, height, target, LaneType.Center, false), "no regular center target");
        }
    }
    private static void TimingBoundariesAreSigned()
    {
        Require(GameplayRules.Timing(0.1f, 0.45f) == HitQuality.Perfect, "perfect inclusive");
        Require(GameplayRules.Timing(0.1001f, 0.45f) == HitQuality.Good, "after perfect boundary");
        Require(GameplayRules.Timing(-0.25f, 0.45f) == HitQuality.Good, "good inclusive");
        Require(GameplayRules.Timing(-0.45f, 0.45f) == HitQuality.Early, "negative window boundary");
        Require(GameplayRules.Timing(0.45f, 0.45f) == HitQuality.Late, "positive window boundary");
        Require(GameplayRules.Timing(0.451f, 0.45f) == HitQuality.Miss, "outside window");
        Require(GameplayRules.Timing(float.NaN, 0.45f) == HitQuality.Miss, "NaN offset");
        Require(GameplayRules.Timing(0.5f, float.NaN) == HitQuality.Miss, "NaN window");
        Require(GameplayRules.Timing(0.5f, float.PositiveInfinity) == HitQuality.Miss, "infinite window");
    }
    private static void HeavyAcceptsRepeatedSides()
    {
        foreach (BodySide side in new[] { BodySide.Left, BodySide.Right })
        for (int hit = 0; hit < 3; hit++)
            Require(GameplayRules.Matches(ActionType.Punch, side,
                side == BodySide.Left ? LaneType.Left : LaneType.Right, VerticalPosition.High,
                TargetType.ToughPunch, LaneType.Center, true), "same-side heavy sequence");
        Require(!GameplayRules.Matches(ActionType.Kick, BodySide.Left, LaneType.Left, VerticalPosition.Low,
            TargetType.ToughPunch, LaneType.Center, true), "kick rejected for heavy");
        Require(GameplayRules.HeavyDamage(0.9f) == 1 && GameplayRules.HeavyDamage(1.65f) == 2,
            "relative gameplay damage");
        Require(GameplayRules.HeavyDamage(float.NaN) == 0, "NaN heavy damage");
    }
    private static void ScoreMultiplierIsBounded()
    {
        Require(GameplayRules.ComboMultiplier(1) == 1f && Math.Abs(GameplayRules.ComboMultiplier(2) - 1.1f) < 0.0001f,
            "combo progression");
        Require(GameplayRules.ComboMultiplier(21) == 3 && GameplayRules.ComboMultiplier(100) == 3,
            "combo upper bound");
    }
    private static void StatisticsKeepDenominatorsDistinct()
    {
        var stats = new GameSessionStats { TotalTargets = 5, PerfectHits = 1, GoodHits = 1, EarlyHits = 1, LateHits = 1, Misses = 1 };
        Require(Math.Abs(stats.Accuracy - 0.4f) < 0.0001f && Math.Abs(stats.CompletionRate - 0.8f) < 0.0001f,
            "timing accuracy versus completion");
        stats.TrackReactionTime(2); stats.TrackReactionTime(4); stats.TrackReactionTime(-3); stats.TrackReactionTime(float.NaN);
        Require(stats.AverageReactionTime == 3, "invalid resolution durations rejected");
        stats.TrackAction(KeyboardActionFactory.Create(ActionType.Kick, BodySide.Right));
        Require(stats.Actions == 1 && stats.RightActions == 1 && stats.KickActions == 1 && stats.KeyboardActions == 1,
            "action counts preserve keyboard and body side");
        stats.Reset();
        Require(stats.Actions == 0 && stats.TotalTargets == 0 && stats.AverageReactionTime == 0
            && stats.Accuracy == 0 && stats.CompletionRate == 0, "reset clears statistics");
    }
}
