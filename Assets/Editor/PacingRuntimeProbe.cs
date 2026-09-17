using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using UnityEngine;
using Object=UnityEngine.Object;

/// <summary>Synthetic full production scheduler, mover and evaluator; never a physical sensor qualification.</summary>
public sealed class PacingRuntimeProbe
{
    static readonly BindingFlags Private=BindingFlags.Instance|BindingFlags.NonPublic;
    sealed class FixedPlanner:GameplayPatternPlanner
    {
        readonly int size;
        public FixedPlanner(int n):base(73){size=n;}
        public override ComboPlan Select(PacingSample s,GameplayPacingProfile p,TargetType[] types,LaneType[] sides,bool physical,float refractory)
        {
            var plan=base.Select(s,p,types,sides,physical,refractory);
            if(plan!=null){plan.Length=size;plan.Generator=0;plan.Interval=plan.Type==TargetType.Kick?.6f:.18f;plan.PatternId="synthetic-alternating-"+size;}
            return plan;
        }
    }
    TargetSpawner spawner;HitZoneEvaluator evaluator;LevelDefinition level;GameplayPacingProfile original;
    readonly HashSet<string> seen=new HashSet<string>();
    readonly List<TargetObject> sorted=new List<TargetObject>();
    readonly List<string> evidence=new List<string>();
    readonly string[] cases={"hard-60-seconds","alternating-50","endless-125","one-side-50","kick-10","heavy-punch","heavy-kick","miss-continuity","easy-60","medium-60","delta-60","mixed-60","punch-10","punch-30"};
    Action<string> capture;
    float caseStarted,lastArrival,lastHeavyHit,cleanupAt=-1,nextWindowSample;
    int stage,count,peak,completed,heavyHits,peakObjects,peakDebris;bool captured;string missedChain;
    float maxWindowIdle;
    float lastHeavyArrival=float.NegativeInfinity;
    public bool Complete { get; private set; }
    public string Failure { get; private set; }
    public void Start(Action<string> screenshot)
    {
        capture=screenshot;spawner=Object.FindFirstObjectByType<TargetSpawner>();evaluator=Object.FindFirstObjectByType<HitZoneEvaluator>();
        Object.FindFirstObjectByType<SessionTimer>()?.StopTimer();
        original=spawner.Pacing;HitZoneEvaluator.OnPatternComplete+=PatternComplete;
        BeginCase();UnityEditor.EditorApplication.update+=Update;
    }
    void PatternComplete(string id,int size){completed=Math.Max(completed,size);}
    void BeginCase()
    {
        seen.Clear();count=peak=completed=heavyHits=peakObjects=peakDebris=0;captured=false;cleanupAt=-1;missedChain=null;maxWindowIdle=0;
        lastArrival=lastHeavyHit=float.NegativeInfinity;
        lastHeavyArrival=float.NegativeInfinity;
        var p=new GameplayPacingProfile{Seed=73};
        level=stage==2?LevelDefinition.CreateEndless():stage==8?LevelDefinition.CreateLevel1():stage==9?LevelDefinition.CreateLevel2():LevelDefinition.CreateLevel3();
        if(stage!=11)level.RestrictToSensorFamily(stage==4||stage==6||stage==10?"Delta":"Alpha");
        level.AllowedLanes=stage==3?new[]{LaneType.Right}:new[]{LaneType.Left,LaneType.Right};
        level.DurationSeconds=stage==0||stage>=8&&stage<=11?60:120;
        typeof(TargetSpawner).GetField("pacing",Private).SetValue(spawner,p);
        caseStarted=Time.time;nextWindowSample=caseStarted+26;spawner.StartSpawning(level);
        if(stage==1||stage==3||stage==7)typeof(TargetSpawner).GetField("planner",Private).SetValue(spawner,new FixedPlanner(50));
        if(stage==2)
        {
            typeof(TargetSpawner).GetField("planner",Private).SetValue(spawner,new FixedPlanner(125));
            typeof(TargetSpawner).GetField("pacingStarted",Private).SetValue(spawner,Time.time-612);
        }
        if(stage==4)typeof(TargetSpawner).GetField("planner",Private).SetValue(spawner,new FixedPlanner(10));
        if(stage>=12)typeof(TargetSpawner).GetField("planner",Private).SetValue(spawner,new FixedPlanner(stage==12?10:30));
        if(stage==5||stage==6)typeof(TargetSpawner).GetField("pacingStarted",Private).SetValue(spawner,Time.time-98);
    }
    void Update()
    {
        if(Complete||Failure!=null)return;
        try
        {
            if(cleanupAt>=0)
            {
                if(Time.time<cleanupAt)return;
                if(Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None).Length!=0||
                    Object.FindObjectsByType<TargetMountMotion>(FindObjectsSortMode.None).Length!=0||
                    Object.FindObjectsByType<ToughTargetHealthBar>(FindObjectsSortMode.None).Length!=0)
                    throw new Exception("Owned object cleanup failed");
                var pool=Object.FindFirstObjectByType<DojoDebrisPool>();
                if(pool!=null&&pool.ActiveCount>0)throw new Exception("Active debris survived cleanup");
                evidence.Add($"PASS {cases[stage]} heavies={spawner.HeavyEncounters} targets={count} peak={peak} objectsIncludingResolving={peakObjects} debris={peakDebris} completed={completed} logicalMax={spawner.MaxLogicalLength} maxIdle={spawner.MaxEmptyIdle:F3}s work={spawner.ActiveWorkTime:F2}s low={spawner.LowIntensityTime:F2}s idle={spawner.EmptyIdleTime:F2}s");
                File.WriteAllLines("artifacts/validation/pacing-playmode.txt",evidence);
                Object.Destroy(level);
                if(++stage==cases.Length){Finish();return;}BeginCase();return;
            }
            float elapsed=Time.time-caseStarted;
            if(elapsed>85)throw new Exception("Timed out "+cases[stage]+" "+spawner.Diagnostic);
            var active=evaluator.ActiveTargets;sorted.Clear();
            for(int i=0;i<active.Count;i++)if(active[i]!=null&&!active[i].IsResolved)sorted.Add(active[i]);
            sorted.Sort((a,b)=>a.ExpectedHitTime.CompareTo(b.ExpectedHitTime));peak=Mathf.Max(peak,sorted.Count);
            foreach(var target in sorted)
            {
                bool kick=target.IsKick;
                if(stage!=11&&kick!=(stage==4||stage==6||stage==10))throw new Exception("Wrong family");
                if(stage==3&&!target.IsTough&&target.Lane!=LaneType.Right)throw new Exception("Unavailable side");
                if(target.GetComponentsInChildren<TextMesh>(true).Length!=0||target.transform.Find("TargetLabel")!=null)throw new Exception("Target action label survived");
                if(stage==10&&target.SequenceLength>20)throw new Exception("Kick cap bypassed");
                if(seen.Add(target.TargetId))
                {
                    count++;
                    if(target.IsTough)
                    {
                        if(target.ExpectedHitTime-lastHeavyArrival<spawner.Pacing.HeavyMinimumSeparation(level.LevelNumber,level.IsEndless)-.01f)throw new Exception("Heavy minimum separation");
                        lastHeavyArrival=target.ExpectedHitTime;
                    }
                    if(!target.IsTough&&target.ExpectedHitTime-lastArrival<(kick?.549f:.179f))throw new Exception("Arrival spacing violated");
                    lastArrival=target.ExpectedHitTime;
                }
                if(stage==7&&target.SequenceLength==50&&target.SequenceIndex<3)
                {
                    if(missedChain==null)missedChain=target.ChainId;
                    if(target.ChainId==missedChain)continue;
                }
                if(target.IsTough)
                {
                    if(target.IsLockedInHitZone&&Time.time-lastHeavyHit>=.35f)
                    {lastHeavyHit=Time.time;heavyHits++;evaluator.EvaluateHit(KeyboardActionFactory.Create(kick?ActionType.Kick:ActionType.Punch,BodySide.Left));}
                }
                else if(evaluator.PreviewTiming(target)==HitQuality.Perfect)
                    evaluator.EvaluateHit(KeyboardActionFactory.Create(kick?ActionType.Kick:ActionType.Punch,target.Lane==LaneType.Left?BodySide.Left:BodySide.Right));
            }
            if(peak>8)throw new Exception("Rolling cap exceeded");
            peakObjects=Mathf.Max(peakObjects,Object.FindObjectsByType<TargetObject>(FindObjectsSortMode.None).Length);
            var livePool=Object.FindFirstObjectByType<DojoDebrisPool>();
            if(livePool!=null)peakDebris=Mathf.Max(peakDebris,livePool.ActiveCount);
            if(peakObjects>11||peakDebris>DojoDebrisPool.Capacity)throw new Exception("Presentation object bound exceeded");
            if(stage==0&&elapsed>=26&&elapsed<=34&&Time.time>=nextWindowSample)
            {
                nextWindowSample=Time.time+.5f;maxWindowIdle=Mathf.Max(maxWindowIdle,spawner.MaxEmptyIdle);
                evidence.Add("WINDOW "+spawner.Diagnostic);
            }
            if(!captured&&elapsed>2&&sorted.Count>=3&&sorted.Exists(t=>t.SequenceLength>=(stage==2?125:stage==1||stage==3||stage==7?50:stage==4?10:8)))
            {capture("Fitness-"+cases[stage]+"-Rolling");captured=true;}
            bool done=stage==0?elapsed>=60:stage==1||stage==3?completed>=50:stage==2?completed>=125:
                stage==4?completed>=10:stage==5||stage==6?heavyHits>=2&&!sorted.Exists(t=>t.IsTough):
                stage==7?missedChain!=null&&seen.Count>=52&&!sorted.Exists(t=>t.ChainId==missedChain):stage<=11?elapsed>=60:completed>=(stage==12?10:30);
            if(done)
            {
                if(stage==0&&(spawner.MaxLogicalLength<30||completed<20))throw new Exception("Hard did not execute long fitness sequences");
                if((stage==0||stage==10)&&spawner.HeavyEncounters<4)throw new Exception("Hard heavy frequency below acceptance");
                if(stage==8&&spawner.HeavyEncounters<2||stage==9&&spawner.HeavyEncounters<3)throw new Exception("Easy/Medium heavy frequency below acceptance");
                if(stage<=3&&spawner.MaxEmptyIdle>1)throw new Exception("Unexplained idle >1 second "+spawner.Diagnostic);
                if(stage==0&&maxWindowIdle>1)throw new Exception("30-second regression");
                spawner.StopSpawning();evaluator.AbortRemaining();cleanupAt=Time.time+DojoDebrisPool.Lifetime+.4f;
            }
        }
        catch(Exception ex){Failure=ex.ToString();evidence.Add("FAIL "+cases[stage]+" "+Failure);Finish();}
    }
    void Finish()
    {
        spawner.StopSpawning();UnityEditor.EditorApplication.update-=Update;HitZoneEvaluator.OnPatternComplete-=PatternComplete;
        typeof(TargetSpawner).GetField("pacing",Private).SetValue(spawner,original);
        Complete=Failure==null;File.WriteAllLines("artifacts/validation/pacing-playmode.txt",evidence);
    }
}
