using System;

public enum PacingPhase { Opening, Rhythm, Build, Burst, Recovery, Long, Conditioning, HighIntensity, HeavyOpportunity, FinalBurst }

/// <summary>Game balance only. Independent bounded speed and growing logical sequence length.</summary>
[Serializable]
public sealed class GameplayPacingProfile
{
    [Serializable] public sealed class Tier
    {
        public float TravelMin,TravelMax,ComboMin,ComboMax,BurstMin,BurstMax;
        public float TransitionMin,TransitionMax;
        public int NormalMin,NormalMax,LongMin,LongMax,BurstLengthMin,BurstLengthMax,FlurryMin,FlurryMax,MaxConcurrent;
        public Tier(float t0,float t1,float c0,float c1,float b0,float b1,float gap0,float gap1,
            int n0,int n1,int l0,int l1,int bLen0,int bLen1,int f0,int f1,int visible)
        {
            TravelMin=t0;TravelMax=t1;ComboMin=c0;ComboMax=c1;BurstMin=b0;BurstMax=b1;
            TransitionMin=gap0;TransitionMax=gap1;
            NormalMin=n0;NormalMax=n1;LongMin=l0;LongMax=l1;BurstLengthMin=bLen0;BurstLengthMax=bLen1;
            FlurryMin=f0;FlurryMax=f1;MaxConcurrent=visible;
        }
    }
    public Tier Easy=new Tier(1,1.4f,.40f,.55f,.30f,.40f,.7f,1.2f,3,6,6,8,6,10,10,12,4);
    public Tier Medium=new Tier(.55f,.75f,.22f,.30f,.20f,.25f,.25f,.40f,10,15,15,25,15,25,20,30,5);
    public Tier Hard=new Tier(.45f,.60f,.20f,.25f,.18f,.22f,.20f,.30f,15,25,20,35,25,35,25,50,7);
    public float AbsoluteMinimumActionSpacingSeconds=.18f,MinimumPhysicalActionSpacingSeconds=.18f;
    public float KickIntervalMin=.55f,KickIntervalMax=.90f;
    public int KickAbsoluteMaxLength=20;
    public int KickEasyMin=2,KickEasyMax=5,KickMediumMin=3,KickMediumMax=8,KickHardMin=4,KickHardMax=12;
    public int KickRareHardMax=15;
    public float MixedPunchWeight=.80f,MixedKickWeight=.20f;
    public float PunchToKickSeconds=.35f,KickToPunchSeconds=.30f;
    public float MinimumVisualSpacing=1.1f;
    public float HeavyEasyMin=18,HeavyEasyMax=25,HeavyMediumMin=12,HeavyMediumMax=18,HeavyHardMin=8,HeavyHardMax=14;
    public float HeavyMinimumSeparationEasy=13,HeavyMinimumSeparationMedium=10,HeavyMinimumSeparationHard=7,HeavyMinimumSeparationEndless=6;
    public float HeavyInterval(int level,bool endless,float elapsed,double randomUnit)
    {
        float min=level<=1?HeavyEasyMin:level==2?HeavyMediumMin:HeavyHardMin;
        float max=level<=1?HeavyEasyMax:level==2?HeavyMediumMax:HeavyHardMax;
        if(endless){float t=Math.Min(1,elapsed/300);min=Lerp(HeavyMediumMin,7,t);max=Lerp(HeavyMediumMax,10,t);}
        return Math.Max(HeavyMinimumSeparation(level,endless),Lerp(min,max,(float)randomUnit));
    }
    public float HeavyMinimumSeparation(int level,bool endless)=>endless?HeavyMinimumSeparationEndless:level<=1?HeavyMinimumSeparationEasy:level==2?HeavyMinimumSeparationMedium:HeavyMinimumSeparationHard;
    public float NormalDeploySeconds=.20f,HeavyDeploySeconds=.50f,MountTelegraphSeconds=.08f;
    public float EndlessRampSeconds=25,EndlessCycleSeconds=60,MissRecoveryCooldownSeconds=8;
    public int MaxPacingTier=6,Seed;
    public int MissesBeforeRecovery=3;
    public float MissObservationSeconds=5;
    public float MinimumSpacing=>Math.Max(.18f,Math.Max(AbsoluteMinimumActionSpacingSeconds,MinimumPhysicalActionSpacingSeconds));
    public Tier GetTier(int level)=>level<=1?Easy:level==2?Medium:Hard;
    [Serializable] public sealed class Phase
    {
        public PacingPhase Name;
        public float End,Normal,Long,Burst,Conditioning;
        public Phase(PacingPhase name,float end,float normal,float longer,float burst,float conditioning)
        {Name=name;End=end;Normal=normal;Long=longer;Burst=burst;Conditioning=conditioning;}
        public string Category(double choice)
        {
            float total=Math.Max(.001f,Normal+Long+Burst+Conditioning);
            double roll=choice*total;
            return roll<Normal?"normal":roll<Normal+Long?"long":roll<Normal+Long+Burst?"burst":"conditioning";
        }
    }
    [Serializable] public sealed class Curve
    {
        public float StartIntensity;
        public int OpeningMin,OpeningMax,RecoveryMin=2,RecoveryMax;
        public Phase[] Phases;
        public Curve(float intensity,int min,int max,int recovery,params Phase[] phases)
        {StartIntensity=intensity;OpeningMin=min;OpeningMax=max;RecoveryMax=recovery;Phases=phases;}
        public Phase At(float progress)
        {foreach(var phase in Phases)if(progress<phase.End)return phase;return Phases[Phases.Length-1];}
    }
    public Curve EasyCurve=new Curve(.25f,2,4,3,
        new Phase(PacingPhase.Opening,.08f,70,25,5,0),
        new Phase(PacingPhase.Rhythm,.30f,60,25,10,5),
        new Phase(PacingPhase.Build,.55f,40,30,20,10),
        new Phase(PacingPhase.Burst,.65f,20,30,40,10),
        new Phase(PacingPhase.Rhythm,.80f,60,25,10,5),
        new Phase(PacingPhase.HeavyOpportunity,.90f,40,30,20,10),
        new Phase(PacingPhase.FinalBurst,1,10,20,50,20));
    public Curve MediumCurve=new Curve(.5f,4,6,4,
        new Phase(PacingPhase.Opening,.06f,60,30,10,0),
        new Phase(PacingPhase.Build,.22f,30,35,25,10),
        new Phase(PacingPhase.Burst,.38f,10,20,45,25),
        new Phase(PacingPhase.Recovery,.44f,100,0,0,0),
        new Phase(PacingPhase.Long,.62f,10,55,25,10),
        new Phase(PacingPhase.Build,.80f,20,30,30,20),
        new Phase(PacingPhase.HeavyOpportunity,.90f,10,25,40,25),
        new Phase(PacingPhase.FinalBurst,1,0,10,45,45));
    public Curve HardCurve=new Curve(.8f,5,8,4,
        new Phase(PacingPhase.Opening,.05f,50,35,15,0),
        new Phase(PacingPhase.Build,.18f,20,35,30,15),
        new Phase(PacingPhase.Burst,.35f,5,10,50,35),
        new Phase(PacingPhase.Long,.48f,0,60,25,15),
        new Phase(PacingPhase.Conditioning,.60f,0,15,35,50),
        new Phase(PacingPhase.Recovery,.65f,100,0,0,0),
        new Phase(PacingPhase.HighIntensity,.78f,0,15,35,50),
        new Phase(PacingPhase.HeavyOpportunity,.88f,0,15,35,50),
        new Phase(PacingPhase.FinalBurst,1,0,0,30,70));
    public Curve GetCurve(int level)=>level<=1?EasyCurve:level==2?MediumCurve:HardCurve;
    public float RecoveryIntervalMultiplier=1.8f;
    public int WorkSegmentActions=12,KickWorkSegmentActions=4;
    public PacingSample Sample(int level,bool endless,float activeSeconds,float duration=60)
    {
        float cycle=Math.Max(12,endless?EndlessCycleSeconds:duration);
        float elapsed=Math.Max(0,activeSeconds),progress=elapsed%cycle/cycle;
        int speedTier=endless?Math.Min(Math.Max(1,MaxPacingTier),(int)(elapsed/Math.Max(20,EndlessRampSeconds))):Math.Max(0,level-1);
        float progression=endless?speedTier/(float)Math.Max(1,MaxPacingTier):Math.Min(1,elapsed/cycle);
        int difficulty=endless?(progression>=.5f?3:2):level;
        var curve=GetCurve(difficulty);var phase=curve.At(progress);
        float intensity=curve.StartIntensity+(1-curve.StartIntensity)*progression;
        var a=GetTier(endless?2:level);var b=endless?Hard:a;
        bool burst=phase.Name==PacingPhase.Burst||phase.Name==PacingPhase.Conditioning||
            phase.Name==PacingPhase.HighIntensity||phase.Name==PacingPhase.FinalBurst||phase.Name==PacingPhase.HeavyOpportunity;
        return new PacingSample {
            Phase=phase.Name,Wave=phase.Name.ToString(),PacingTier=speedTier,Difficulty=difficulty,
            ComboLengthTier=endless?elapsed/60f:0,Endless=endless,Cycle=(int)(elapsed/cycle),Distribution=phase,
            TravelSeconds=Lerp(a.TravelMax,b.TravelMin,intensity),
            IntervalSeconds=Math.Max(MinimumSpacing,burst?Lerp(a.BurstMax,b.BurstMin,intensity):Lerp(a.ComboMax,b.ComboMin,intensity)),
            TransitionSeconds=Lerp(a.TransitionMax,b.TransitionMin,intensity),
            KickIntervalSeconds=Math.Max(.55f,Lerp(KickIntervalMax,KickIntervalMin,intensity)),
            MaxConcurrent=endless&&speedTier==MaxPacingTier?8:b.MaxConcurrent,
            Recovery=phase.Name==PacingPhase.Recovery
        };
    }
    static float Lerp(float a,float b,float t)=>a+(b-a)*t;
}
public struct PacingSample
{
    public PacingPhase Phase;
    public string Wave;
    public float TravelSeconds,IntervalSeconds,TransitionSeconds,KickIntervalSeconds,ComboLengthTier;
    public int MaxConcurrent,PacingTier,Difficulty,Cycle;
    public bool Recovery,Endless;
    public GameplayPacingProfile.Phase Distribution;
}

/// <summary>Constant-size representation regardless of logical action count. No growing action array.</summary>
public sealed class ComboPlan
{
    public string PatternId,Category;
    public TargetType Type;
    public int Length;
    public LaneType StartSide;
    public bool LeftAvailable,RightAvailable;
    public float Interval,TravelSeconds,TransitionSeconds;
    public bool Mixed;
    public uint ActionSeed;
    public float KickInterval;
    public float PunchToKick=.35f,KickToPunch=.30f;
    public bool ExtendedRuns;
    // Equal-sized segments allow random access without allocating an Endless-sized action array.
    static readonly string[] SideMotifs={"LLRRLRLR","LRRLLRLR","LLRLRRLR","LRLLRRLR","LLRRRLLR","LRRRLLRR","LLLRRLRR","LRRLLLRR"};
    static readonly string[] HardSideMotifs={"LLLLRRRR","LRRRRLLR","LLLLLRRR","LRRRRRLR","LLRRRLLR","LLLRRLRR","LRRLLLRR","LLRRLLRR"};
    static readonly string[] TypeMotifs={"PPPKPPPPKP","PPKPPPKPPP","PPPPPKPPKP","PKPPPPPKPP","PPKKPPPPPP","PPPPPPPPKP","PPPKPPPKPP","PPKPPPPPPK"};
    static uint Mix(uint value){unchecked{value^=value>>16;value*=0x7feb352du;value^=value>>15;value*=0x846ca68bu;return value^(value>>16);}}
    int MotifAt(int segment,uint salt)
    {
        // Disjoint alternating banks prevent immediate reuse; each segment has a seeded selection.
        uint hash=Mix(ActionSeed^salt^(uint)(segment/2));
        return (int)((hash>>((segment&1)*8))&3u)*2+(segment&1);
    }
    public int SegmentLength=12;
    public bool IsWorkBoundary(int index)=>index==0||index%Math.Max(2,SegmentLength)==0;
    public TargetType TypeAt(int index)
    {
        if(!Mixed)return Type;
        return TypeMotifs[MotifAt(index/10,0x91u)][index%10]=='K'?TargetType.Kick:TargetType.Punch;
    }
    public float IntervalBefore(int index)
    {
        if(index<=0)return Interval;
        bool previousKick=TypeAt(index-1)==TargetType.Kick,currentKick=TypeAt(index)==TargetType.Kick;
        if(previousKick&&currentKick)return Math.Max(.55f,KickInterval);
        if(currentKick)return Math.Max(.18f,PunchToKick);
        if(previousKick)return Math.Max(.18f,KickToPunch);
        return Math.Max(.18f,Interval);
    }
    public LaneType SideAt(int index)
    {
        if(!LeftAvailable)return LaneType.Right;
        if(!RightAvailable)return LaneType.Left;
        int segment=index/8;
        var library=ExtendedRuns&&Mix(ActionSeed+(uint)segment)%4==0?HardSideMotifs:SideMotifs;
        bool left=library[MotifAt(segment,0x37u)][index%8]=='L';
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
    bool hasStarted;
    public GameplayPatternPlanner(int seed){random=new Random(seed);}
    public virtual ComboPlan Select(PacingSample sample,GameplayPacingProfile profile,TargetType[] types,LaneType[] lanes,bool physical,float refractory)
    {
        bool punch=Contains(types,TargetType.Punch),kick=Contains(types,TargetType.Kick);
        bool left=Contains(lanes,LaneType.Left),right=Contains(lanes,LaneType.Right);
        if((!punch&&!kick)||(!left&&!right)||(physical&&punch&&kick))return null;
        var tier=profile.GetTier(sample.Difficulty);
        double choice=random.NextDouble();
        int lo,hi;string category;
        var curve=profile.GetCurve(sample.Difficulty);
        category=(sample.Distribution??curve.At(0)).Category(choice);
        if(category=="conditioning"){lo=tier.FlurryMin;hi=tier.FlurryMax;}
        else if(category=="burst"){lo=tier.BurstLengthMin;hi=tier.BurstLengthMax;}
        else if(category=="long"){lo=tier.LongMin;hi=tier.LongMax;}
        else {lo=tier.NormalMin;hi=tier.NormalMax;}
        if(!hasStarted&&sample.Phase==PacingPhase.Opening&&sample.Cycle==0)
        {lo=curve.OpeningMin;hi=curve.OpeningMax;category="opening";}
        if(sample.Recovery){lo=curve.RecoveryMin;hi=curve.RecoveryMax;category="micro-recovery";}
        if(sample.Endless&&punch&&category!="micro-recovery"&&category!="opening")
        {
            // Smoothly increasing length envelope; speed and physical target count remain bounded.
            double growth=sample.ComboLengthTier;
            lo=(int)Math.Min(int.MaxValue-1,5+5*growth);
            hi=(int)Math.Min(int.MaxValue-1,15+10*growth);
        }
        if(!punch)
        {
            if(category!="micro-recovery"&&category!="opening")
            {
                lo=sample.Difficulty<=1?profile.KickEasyMin:sample.Difficulty==2?profile.KickMediumMin:profile.KickHardMin;
                hi=sample.Difficulty<=1?profile.KickEasyMax:sample.Difficulty==2?profile.KickMediumMax:profile.KickHardMax;
                if(sample.Difficulty>=3&&category!="normal"&&choice<.05)hi=profile.KickRareHardMax;
            }
            hi=Math.Max(1,Math.Min(20,Math.Min(profile.KickAbsoluteMaxLength,hi)));lo=Math.Min(lo,hi);
        }
        int length=lo+(int)(random.NextDouble()*(hi-lo+1d));
        uint actionSeed=(uint)random.Next();
        var type=punch?TargetType.Punch:TargetType.Kick;
        float interval=sample.IntervalSeconds;
        if(category=="conditioning")interval=Math.Max(profile.MinimumSpacing,tier.BurstMin);
        if(category=="micro-recovery")interval=Math.Max(interval*profile.RecoveryIntervalMultiplier,.4f);
        if(type==TargetType.Kick)interval=Math.Max(sample.KickIntervalSeconds,interval);
        hasStarted=true;
        return new ComboPlan{PatternId=(type==TargetType.Punch?"P":"K")+"-"+category+"-"+actionSeed+"-"+length,
            Category=category,Type=type,Length=length,
            Mixed=punch&&kick,ActionSeed=actionSeed,SegmentLength=Math.Max(2,punch?profile.WorkSegmentActions:profile.KickWorkSegmentActions),
            ExtendedRuns=sample.Difficulty>=3,PunchToKick=profile.PunchToKickSeconds,KickToPunch=profile.KickToPunchSeconds,
            KickInterval=sample.KickIntervalSeconds,
            LeftAvailable=left,RightAvailable=right,StartSide=random.Next(2)==0?LaneType.Left:LaneType.Right,
            Interval=interval,TravelSeconds=sample.TravelSeconds,TransitionSeconds=sample.TransitionSeconds};
    }
    static bool Contains<T>(T[] values,T value)=>values!=null&&Array.IndexOf(values,value)>=0;
}
