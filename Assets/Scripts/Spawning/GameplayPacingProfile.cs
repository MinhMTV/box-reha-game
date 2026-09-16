using System;

public enum PacingPhase { Warmup, Rhythm, Build, Burst, Recovery, Heavy }

/// <summary>Game balance only. Independent bounded speed and growing logical sequence length.</summary>
[Serializable]
public sealed class GameplayPacingProfile
{
    [Serializable] public sealed class Tier
    {
        public float TravelMin,TravelMax,ComboMin,ComboMax,BurstMin,BurstMax;
        public float TransitionMin,TransitionMax,RecoveryMax;
        public int NormalMin,NormalMax,LongMin,LongMax,BurstLengthMin,BurstLengthMax,FlurryMin,FlurryMax,MaxConcurrent;
        public Tier(float t0,float t1,float c0,float c1,float b0,float b1,float gap0,float gap1,float recovery,
            int n0,int n1,int l0,int l1,int bLen0,int bLen1,int f0,int f1,int visible)
        {
            TravelMin=t0;TravelMax=t1;ComboMin=c0;ComboMax=c1;BurstMin=b0;BurstMax=b1;
            TransitionMin=gap0;TransitionMax=gap1;RecoveryMax=recovery;
            NormalMin=n0;NormalMax=n1;LongMin=l0;LongMax=l1;BurstLengthMin=bLen0;BurstLengthMax=bLen1;
            FlurryMin=f0;FlurryMax=f1;MaxConcurrent=visible;
        }
    }
    public Tier Easy=new Tier(1,1.4f,.40f,.55f,.30f,.40f,.7f,1.2f,1.5f,3,6,6,8,6,10,10,12,4);
    public Tier Medium=new Tier(.75f,1.1f,.28f,.38f,.22f,.30f,.5f,.9f,1.2f,5,10,10,15,15,20,20,25,5);
    public Tier Hard=new Tier(.55f,.85f,.22f,.30f,.18f,.22f,.3f,.7f,1,8,15,15,25,20,35,30,50,7);
    public float AbsoluteMinimumActionSpacingSeconds=.18f,MinimumPhysicalActionSpacingSeconds=.18f;
    public float KickIntervalMin=.55f,KickIntervalMax=.90f;
    public float NormalDeploySeconds=.20f,HeavyDeploySeconds=.50f,MountTelegraphSeconds=.08f;
    public float EndlessRampSeconds=25,EndlessCycleSeconds=60,MissRecoveryCooldownSeconds=8;
    public int MaxPacingTier=6,HeavyEveryCycles=1,Seed;
    public int MissesBeforeRecovery=3;
    public float MissObservationSeconds=5;
    public bool UsePersonalRapidReferenceForPacing=false;
    public float MinimumSpacing=>Math.Max(.18f,Math.Max(AbsoluteMinimumActionSpacingSeconds,MinimumPhysicalActionSpacingSeconds));
    public Tier GetTier(int level)=>level<=1?Easy:level==2?Medium:Hard;
    public PacingSample Sample(int level,bool endless,float activeSeconds,float duration=60)
    {
        float cycle=Math.Max(12,endless?EndlessCycleSeconds:duration);
        float elapsed=Math.Max(0,activeSeconds),phase=elapsed%cycle/cycle;
        var wave=phase<.04f?PacingPhase.Warmup:phase<.12f?PacingPhase.Rhythm:
            phase<.30f?PacingPhase.Build:phase<.43f?PacingPhase.Burst:
            phase<.47f?PacingPhase.Recovery:phase<.68f?PacingPhase.Build:
            phase<.80f?PacingPhase.Burst:phase<.90f?PacingPhase.Heavy:PacingPhase.Burst;
        int speedTier=endless?Math.Min(Math.Max(1,MaxPacingTier),(int)(elapsed/Math.Max(20,EndlessRampSeconds))):Math.Max(0,level-1);
        float ramp=endless?speedTier/(float)Math.Max(1,MaxPacingTier):Math.Min(1,elapsed/cycle);
        var a=GetTier(endless?2:level);var b=endless?Hard:a;
        bool burst=wave==PacingPhase.Burst;
        return new PacingSample {
            Phase=wave,Wave=wave.ToString(),PacingTier=speedTier,Difficulty=endless?(ramp>=.5f?3:2):level,
            ComboLengthTier=endless?elapsed/60f:0,Endless=endless,Cycle=(int)(elapsed/cycle),
            TravelSeconds=Lerp(a.TravelMax,b.TravelMin,ramp),
            IntervalSeconds=Math.Max(MinimumSpacing,burst?Lerp(a.BurstMax,b.BurstMin,ramp):Lerp(a.ComboMax,b.ComboMin,ramp)),
            TransitionSeconds=Lerp(a.TransitionMax,b.TransitionMin,ramp),
            RecoverySeconds=Math.Min(1.5f,Lerp(a.RecoveryMax,b.RecoveryMax,ramp)),
            KickIntervalSeconds=Math.Max(.55f,Lerp(KickIntervalMax,KickIntervalMin,ramp)),
            MaxConcurrent=endless&&speedTier==MaxPacingTier?8:b.MaxConcurrent,
            Recovery=wave==PacingPhase.Recovery,Heavy=wave==PacingPhase.Heavy&&((int)(elapsed/cycle)%Math.Max(1,HeavyEveryCycles)==0),
            Prepared=true
        };
    }
    static float Lerp(float a,float b,float t)=>a+(b-a)*t;
}
public struct PacingSample
{
    public PacingPhase Phase;
    public string Wave;
    public float TravelSeconds,IntervalSeconds,TransitionSeconds,RecoverySeconds,KickIntervalSeconds,ComboLengthTier;
    public int MaxConcurrent,PacingTier,Difficulty,Cycle;
    public bool Recovery,Heavy,Prepared,Endless;
}

/// <summary>Constant-size representation regardless of logical action count. No growing action array.</summary>
public sealed class ComboPlan
{
    public string PatternId,Category;
    public TargetType Type;
    public int Length,Generator;
    public LaneType StartSide;
    public bool LeftAvailable,RightAvailable;
    public float Interval,TravelSeconds,TransitionSeconds;
    public LaneType SideAt(int index)
    {
        if(!LeftAvailable)return LaneType.Right;
        if(!RightAvailable)return LaneType.Left;
        bool left=(index&1)==0;
        if(Generator==1&&index%8==4)left=!left; // safe double, timestamp guard handles reuse
        if(Generator==2&&index==Length-1&&index>0)left=((index-1)&1)==0; // power finish
        if(StartSide==LaneType.Right)left=!left;
        return left?LaneType.Left:LaneType.Right;
    }
}

/// <summary>Persistent independent hand timestamps, also across patterns; never impose one device's delay globally.</summary>
public sealed class PacingActionTimeline
{
    public float LastAction { get; private set; }=float.NegativeInfinity;
    public float LastLeft { get; private set; }=float.NegativeInfinity;
    public float LastRight { get; private set; }=float.NegativeInfinity;
    public float Next(LaneType side,float requested,float globalMinimum,float sameSideMinimum)
        =>Math.Max(requested,Math.Max(LastAction+globalMinimum,(side==LaneType.Left?LastLeft:LastRight)+sameSideMinimum));
    public void Commit(LaneType side,float at)
    { LastAction=at;if(side==LaneType.Left)LastLeft=at;else LastRight=at; }
}
public class GameplayPatternPlanner
{
    readonly Random random;
    int previousGenerator=-1;
    public GameplayPatternPlanner(int seed){random=new Random(seed);}
    public virtual ComboPlan Select(PacingSample sample,GameplayPacingProfile profile,TargetType[] types,LaneType[] lanes,bool physical,float refractory)
    {
        bool punch=Contains(types,TargetType.Punch),kick=Contains(types,TargetType.Kick);
        bool left=Contains(lanes,LaneType.Left),right=Contains(lanes,LaneType.Right);
        if((!punch&&!kick)||(!left&&!right)||(physical&&punch&&kick))return null;
        var tier=profile.GetTier(sample.Difficulty);
        double choice=random.NextDouble();
        int lo,hi;string category;
        if(sample.Recovery||sample.Phase==PacingPhase.Warmup){lo=1;hi=2;category="micro-recovery";}
        else if(choice<(sample.Endless?Math.Min(.65,.20+sample.ComboLengthTier*.025):.20))
        {lo=tier.FlurryMin;hi=tier.FlurryMax;category="conditioning";}
        else if(sample.Phase==PacingPhase.Burst||choice<.45)
        {lo=tier.BurstLengthMin;hi=tier.BurstLengthMax;category="burst";}
        else if(choice<.65){lo=tier.LongMin;hi=tier.LongMax;category="long";}
        else {lo=tier.NormalMin;hi=tier.NormalMax;category="normal";}
        if(sample.Endless&&category!="micro-recovery")
        {
            // Smoothly increasing length envelope; speed and physical target count remain bounded.
            double growth=sample.ComboLengthTier;
            lo=(int)Math.Min(int.MaxValue-1,5+5*growth);
            hi=(int)Math.Min(int.MaxValue-1,15+10*growth);
        }
        int length=lo+(int)(random.NextDouble()*(hi-lo+1d));
        int generator=random.Next(3);if(generator==previousGenerator)generator=(generator+1)%3;previousGenerator=generator;
        var type=punch&&(!kick||random.Next(2)==0)?TargetType.Punch:TargetType.Kick;
        float interval=sample.IntervalSeconds;
        if(category=="conditioning")interval=Math.Max(profile.MinimumSpacing,tier.BurstMin);
        if(category=="micro-recovery")interval=Math.Max(interval,.6f);
        if(type==TargetType.Kick)interval=Math.Max(sample.KickIntervalSeconds,interval);
        return new ComboPlan{PatternId=(type==TargetType.Punch?"P":"K")+"-"+category+"-"+generator+"-"+length,
            Category=category,Type=type,Length=length,Generator=generator,
            LeftAvailable=left,RightAvailable=right,StartSide=random.Next(2)==0?LaneType.Left:LaneType.Right,
            Interval=interval,TravelSeconds=sample.TravelSeconds,TransitionSeconds=sample.TransitionSeconds};
    }
    static bool Contains<T>(T[] values,T value)=>values!=null&&Array.IndexOf(values,value)>=0;
}
