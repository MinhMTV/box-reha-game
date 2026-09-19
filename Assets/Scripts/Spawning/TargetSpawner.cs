using UnityEngine;
using System.Collections;

/// <summary>Single production scheduler: reaction targets and fully preannounced authored combinations.</summary>
public class TargetSpawner : MonoBehaviour
{
    public GameConfig Configuration => gameConfig;
    [SerializeField] private Transform spawnPointLeft,spawnPointCenter,spawnPointRight;
    [SerializeField] private float missZoneZ;
    [SerializeField] private GameConfig gameConfig;
    [SerializeField] private GameObject punchVisualPrefab,kickVisualPrefab,toughVisualPrefab,heavyKickVisualPrefab;
    [SerializeField] private HitZoneEvaluator hitZoneEvaluator;
    [SerializeField] private GameplayPacingProfile pacing=new GameplayPacingProfile();
    public GameplayPacingProfile Pacing=>pacing;
    public string CurrentWave { get; private set; }="Opening";
    public PacingPhase CurrentPhase { get; private set; }=PacingPhase.Opening;
    public string CurrentPatternId { get; private set; }="";
    public int CurrentPacingTier { get; private set; }
    public int PatternActionIndex { get; private set; }
    public float CurrentTravelSeconds { get; private set; }
    public float NextExpectedActionTime { get; private set; }
    public int SessionSeed { get; private set; }
    public int ActiveTargetCount=>hitZoneEvaluator==null?0:ActiveCount();
    public string Availability=>currentLevel==null?"none":string.Join(",",currentLevel.AllowedTargetTypes)+" / "+string.Join(",",currentLevel.AllowedLanes);
    readonly System.Collections.Generic.Dictionary<Vector4,Material> fallbackMaterials=new System.Collections.Generic.Dictionary<Vector4,Material>();
    void OnDestroy(){foreach(var material in fallbackMaterials.Values)if(material!=null)Destroy(material);}
    LevelDefinition currentLevel;
    GameplayPatternPlanner planner;
    bool isSpawning;
    float previousArrival=float.NegativeInfinity,missWindowStart,pacingStarted;
    int misses;
    public bool RecoveryRequested { get; private set; }

    void Awake(){EnsureGeneratedVisualPrefabs();}
    void OnEnable(){HitZoneEvaluator.OnTargetMissed+=OnMiss;}
    void OnDisable(){HitZoneEvaluator.OnTargetMissed-=OnMiss;StopSpawning();}
    void OnMiss(int lane)
    {
        if(!isSpawning||Time.time<missRecoveryAfter)return;
        if(Time.time-missWindowStart>pacing.MissObservationSeconds){misses=0;missWindowStart=Time.time;}
        if(++misses>=pacing.MissesBeforeRecovery)RecoveryRequested=true;
    }
    public void StartSpawning(LevelDefinition level)
    {
        StopAllCoroutines();EnsureGeneratedVisualPrefabs();currentLevel=level;
        if(hitZoneEvaluator==null)hitZoneEvaluator=FindAnyObjectByType<HitZoneEvaluator>();
        if(hitZoneEvaluator==null)return;
        SessionSeed=pacing.Seed==0?(System.Environment.TickCount&int.MaxValue):pacing.Seed;
        planner=new GameplayPatternPlanner(SessionSeed);previousArrival=float.NegativeInfinity;
        misses=0;RecoveryRequested=false;missWindowStart=Time.time;pacingStarted=Time.time;isSpawning=true;
        System.Array.Clear(pathPredecessors,0,pathPredecessors.Length);
        ResearchSessionLog.PacingConfiguration(JsonUtility.ToJson(pacing),SessionSeed);
        StartCoroutine(SpawnRoutine());
    }
    public void StopSpawning(){isSpawning=false;PendingActions=0;WaitingReason="stopped";StopAllCoroutines();}
    void EnsureGeneratedVisualPrefabs()
    {
#if UNITY_EDITOR
        if(punchVisualPrefab==null)punchVisualPrefab=UnityEditor.AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/DigitalDojo/Prefabs/MountedPunchTarget.prefab");
        if(kickVisualPrefab==null)kickVisualPrefab=UnityEditor.AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/Generated/NeonCombat/Prefabs/PF_KickPad_NeonBlue.prefab");
        if(toughVisualPrefab==null)toughVisualPrefab=UnityEditor.AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/DigitalDojo/Prefabs/MountedHeavyTarget.prefab");
        if(heavyKickVisualPrefab==null)heavyKickVisualPrefab=UnityEditor.AssetDatabase.LoadAssetAtPath<GameObject>("Assets/Art/DigitalDojo/Prefabs/MountedHeavyKickTarget.prefab");
#endif
    }
    public int PendingActions { get; private set; }
    public int Lookahead { get; private set; }
    public float NextSpawnTime { get; private set; }
    public float NextPatternTime { get; private set; }
    public float RecoveryUntil { get; private set; }
    public string WaitingReason { get; private set; }="stopped";
    public float ActiveWorkTime { get; private set; }
    public float LowIntensityTime { get; private set; }
    public float EmptyIdleTime { get; private set; }
    public float MaxEmptyIdle { get; private set; }
    public int PeakActive { get; private set; }
    public float ComboLengthTier { get; private set; }
    public int MaxLogicalLength { get; private set; }
    public string Diagnostic => $"remaining={Remaining:F2} phase={CurrentPhase} pattern={CurrentPatternId} pending={PendingActions} lookahead={Lookahead} active={ActiveTargetCount} nextSpawn={NextSpawnTime:F2} nextPattern={NextPatternTime:F2} recoveryUntil={RecoveryUntil:F2} heavy={HasActiveToughTarget()} missRecovery={RecoveryRequested} wait={WaitingReason}";
    float idleFor,nextDiagnostic,missRecoveryAfter;
    PacingActionTimeline timeline;
    float Remaining=>currentLevel==null?0:currentLevel.IsEndless?float.PositiveInfinity:currentLevel.DurationSeconds-(Time.time-pacingStarted);
    void Update()
    {
        if(!isSpawning||Time.deltaTime<=0)return;
        int active=ActiveCount();PeakActive=Mathf.Max(PeakActive,active);
        if(active>0)
        {
            idleFor=0;
            if(CurrentPhase==PacingPhase.Recovery)LowIntensityTime+=Time.deltaTime;else ActiveWorkTime+=Time.deltaTime;
        }
        else
        {
            idleFor+=Time.deltaTime;EmptyIdleTime+=Time.deltaTime;MaxEmptyIdle=Mathf.Max(MaxEmptyIdle,idleFor);
            float threshold=currentLevel.LevelNumber<=1?1.3f:currentLevel.LevelNumber==2?1:.7f;
            if(idleFor>threshold&&Time.time>=RecoveryUntil&&Remaining>.3f&&CurrentPatternId!="unavailable")
            {
                if(Debug.isDebugBuild)Debug.LogWarning("PACING_IDLE_DIAGNOSTIC "+Diagnostic);
                RecoveryUntil=Time.time;NextPatternTime=Time.time;idleFor=0;
            }
        }
        if(Debug.isDebugBuild&&Remaining<=34&&Remaining>=26&&Time.time>=nextDiagnostic)
        {nextDiagnostic=Time.time+.5f;Debug.Log("PACING_WINDOW_DIAGNOSTIC "+Diagnostic);}
    }
    IEnumerator SpawnRoutine()
    {
        heavyRandom=new System.Random(SessionSeed^1931);
        nextHeavyAt=Time.time+pacing.HeavyInterval(currentLevel.LevelNumber,currentLevel.IsEndless,0,heavyRandom.NextDouble());
        HeavyEncounters=0;LastHeavyArrival=float.NegativeInfinity;
        timeline=new PacingActionTimeline();
        ActiveWorkTime=LowIntensityTime=EmptyIdleTime=MaxEmptyIdle=idleFor=0;PeakActive=MaxLogicalLength=0;
        while(isSpawning&&Remaining>0)
        {
            var sample=pacing.Sample(currentLevel.LevelNumber,currentLevel.IsEndless,Time.time-pacingStarted,currentLevel.DurationSeconds);
            CurrentWave=sample.Wave;CurrentPhase=sample.Phase;CurrentPacingTier=sample.PacingTier;ComboLengthTier=sample.ComboLengthTier;
            Lookahead=Mathf.Clamp(sample.MaxConcurrent,2,8);
            if(RecoveryRequested)
            {
                sample.Recovery=true;sample.Phase=PacingPhase.Recovery;CurrentPhase=sample.Phase;CurrentWave="Recovery";
                RecoveryRequested=false;misses=0;missWindowStart=Time.time;
                missRecoveryAfter=Time.time+pacing.MissRecoveryCooldownSeconds;
            }
            var plan=planner.Select(sample,pacing,currentLevel.AllowedTargetTypes,currentLevel.AllowedLanes,
                SessionInputSelection.Physical,gameConfig!=null?gameConfig.SensorActionCooldown:.35f);
            if(plan==null){CurrentPatternId="unavailable";WaitingReason="no supported input";yield return new WaitForSeconds(.25f);continue;}
            CurrentPatternId=plan.PatternId;PatternActionIndex=0;
            CurrentTravelSeconds=plan.TravelSeconds;
            float deploy=pacing.MountTelegraphSeconds+Mathf.Clamp(pacing.NormalDeploySeconds,.2f,.4f);
            float sameSide=SessionInputSelection.Physical?Mathf.Max(.35f,gameConfig!=null?gameConfig.SensorActionCooldown:.35f):0;
            // Ordinary transitions are scheduled between actions, not added after visual cleanup and travel.
            float first=Mathf.Max(Time.time+deploy+CurrentTravelSeconds,timeline.LastAction+plan.TransitionSeconds);
            float globalMinimum=plan.Type==TargetType.Kick?Mathf.Max(.55f,pacing.MinimumSpacing):pacing.MinimumSpacing;
            int count=plan.Length;
            if(!currentLevel.IsEndless)
            {
                float deadline=pacingStarted+currentLevel.DurationSeconds-.02f;
                var probe=new PacingActionTimeline();
                float requested=first;
                int fitting=0;
                for(int i=0;i<count;i++)
                {
                    var side=plan.SideAt(i);
                    float due=probe.Next(side,requested,Mathf.Max(globalMinimum,i==0?0:plan.IntervalBefore(i)),sameSide);
                    due=timeline.Next(side,due,globalMinimum,sameSide);
                    if(due>deadline)break;
                    fitting++;probe.Commit(side,due);requested=due+plan.IntervalBefore(i+1);
                }
                count=fitting;
            }
            if(count==0){WaitingReason="round boundary";yield return null;continue;}
            MaxLogicalLength=Mathf.Max(MaxLogicalLength,count);
            string chain=count>1?hitZoneEvaluator.StartActionPattern(plan.PatternId,plan.SideAt(0),count):null;
            float requestedArrival=first;
            NextPatternTime=first;
            for(int i=0;i<count&&isSpawning&&Remaining>0;i++)
            {
                PendingActions=count-i;PatternActionIndex=i;
                var side=plan.SideAt(i);
                if(requestedArrival>=nextHeavyAt && plan.IsWorkBoundary(i) && currentLevel.HeavyTargetsEnabled && Remaining>4)
                {
                    yield return SpawnHeavy(sample,plan);
                    CurrentPatternId=plan.PatternId;CurrentWave=sample.Wave;CurrentPhase=sample.Phase;
                    requestedArrival=Mathf.Max(requestedArrival,Time.time+deploy+CurrentTravelSeconds);
                }
                var actionType=plan.TypeAt(i);
                var point=GetSpawnPoint(side);
                if(point==null){WaitingReason="missing spawn point";yield break;}
                float distance=point.position.z-hitZoneEvaluator.HitZoneZ;
                if(distance<=0){WaitingReason="invalid spawn distance";yield break;}
                float travel=Mathf.Max(.12f,CurrentTravelSeconds);
                float actionSpeed=distance/travel;
                float due=timeline.Next(side,requestedArrival,Mathf.Max(globalMinimum,i==0?0:plan.IntervalBefore(i)),sameSide);
                var predecessor=pathPredecessors[(int)side];
                float spacing=Mathf.Max(.01f,pacing.MinimumVisualSpacing);
                // At travel start and at the earlier hit time the gap must both be legal.
                // Linear motion then preserves the gap throughout the interval, even across speed changes.
                if(predecessor!=null&&!predecessor.IsResolved)
                    due=Mathf.Max(due,predecessor.ExpectedHitTime+spacing/Mathf.Min(actionSpeed,Mathf.Max(.01f,predecessor.MoveSpeed)));
                NextExpectedActionTime=due;
                NextSpawnTime=due-deploy-travel;
                WaitingReason="rolling lookahead";
                while(isSpawning&&Remaining>0&&(ActiveCount()>=Lookahead||Time.time<NextSpawnTime||!PathHasRoom(side,point.position.z,spacing)))yield return null;
                if(!isSpawning||Remaining<=0)yield break;
                // Capacity pressure delays the timestamp, never increases speed or changes the spawn region.
                due=Time.time+deploy+travel;
                if(!currentLevel.IsEndless&&due>pacingStarted+currentLevel.DurationSeconds)break;
                var target=SpawnPaced(actionType,side,point.position.z,actionSpeed,deploy,false,chain,i,count);
                if(target!=null)
                {
                    pathPredecessors[(int)side]=target;
                    NextExpectedActionTime=target.ExpectedHitTime;
                    timeline.Commit(side,target.ExpectedHitTime);
                    ResearchSessionLog.PacingTarget(target.TargetId,CurrentWave,sample.PacingTier,CurrentPatternId,i,
                        i==0?0:target.ExpectedHitTime-previousArrival,travel);
                    previousArrival=target.ExpectedHitTime;
                }
                requestedArrival=due+plan.IntervalBefore(i+1);
            }
            PendingActions=0;
            // Rolling tail stays visible while selecting the next sequence. No last-hit-window or VFX wait.
            NextPatternTime=timeline.LastAction+plan.TransitionSeconds;
            RecoveryUntil=0;
        }
        WaitingReason="round ended";PendingActions=0;
    }
    System.Random heavyRandom;
    readonly TargetObject[] pathPredecessors=new TargetObject[3];
    bool PathHasRoom(LaneType lane,float spawnZ,float spacing)
    {
        var previous=pathPredecessors[(int)lane];
        return previous==null||previous.IsResolved||spawnZ>=previous.transform.position.z+spacing;
    }
    float nextHeavyAt;
    public int HeavyEncounters { get; private set; }
    public float LastHeavyArrival { get; private set; }
    IEnumerator SpawnHeavy(PacingSample sample,ComboPlan plan)
    {
        WaitingReason="heavy preview slot";
        while(isSpawning&&ActiveCount()>=Lookahead)yield return null;
        if(!isSpawning)yield break;
        bool kick=plan.Type==TargetType.Kick || (plan.Mixed&&heavyRandom.NextDouble()<pacing.MixedKickWeight/System.Math.Max(.001f,pacing.MixedPunchWeight+pacing.MixedKickWeight));
        var point=GetSpawnPoint(LaneType.Center);
        if(point==null){nextHeavyAt=Time.time+1;yield break;}
        float delay=pacing.MountTelegraphSeconds+Mathf.Clamp(pacing.HeavyDeploySeconds,.5f,.8f);
        float arrival=Mathf.Max(Time.time+delay+sample.TravelSeconds,
            timeline.LastAction+currentLevel.HitWindowSeconds*.5f+.15f);
        arrival=Mathf.Max(arrival,LastHeavyArrival+pacing.HeavyMinimumSeparation(currentLevel.LevelNumber,currentLevel.IsEndless));
        float speed=Mathf.Max(.01f,point.position.z-hitZoneEvaluator.HitZoneZ)/Mathf.Max(.12f,arrival-Time.time-delay);
        var target=SpawnPaced(kick?TargetType.ToughKick:TargetType.ToughPunch,LaneType.Center,point.position.z,speed,delay,true,null,0,1);
        if(target==null)yield break;
        LastHeavyArrival=target.ExpectedHitTime;HeavyEncounters++;
        nextHeavyAt=LastHeavyArrival+pacing.HeavyInterval(currentLevel.LevelNumber,currentLevel.IsEndless,Time.time-pacingStarted,heavyRandom.NextDouble());
        WaitingReason="heavy work";CurrentWave="Heavy";CurrentPhase=PacingPhase.HeavyOpportunity;
        while(isSpawning&&!target.IsResolved&&Remaining>0)yield return null;
        CurrentWave="Recovery";CurrentPhase=PacingPhase.Recovery;WaitingReason="resume prepared sequence";
        // Continue the existing logical combo after the heavy; no cancellation, sleep or VFX gate.
    }
    int ActiveCount()
    {
        int count=0;var targets=hitZoneEvaluator.ActiveTargets;
        for(int i=0;i<targets.Count;i++)if(targets[i]!=null&&!targets[i].IsResolved)count++;
        return count;
    }
    bool HasActiveToughTarget()
    {
        var targets=hitZoneEvaluator.ActiveTargets;
        for(int i=0;i<targets.Count;i++)if(targets[i]!=null&&!targets[i].IsResolved&&targets[i].IsTough)return true;
        return false;
    }
    TargetObject SpawnPaced(TargetType type,LaneType lane,float z,float speed,float deploy,bool heavy,string chain,int index,int count)
    {
        var point=GetSpawnPoint(lane);if(point==null)return null;
        var position=point.position;position.z=z;
        var height=type==TargetType.Kick||type==TargetType.ToughKick?VerticalPosition.Low:VerticalPosition.High;
        position.y=gameConfig!=null?gameConfig.GetVerticalOffset(height):height==VerticalPosition.Low?.45f:2.6f;
        var obj=CreateTargetObject(position,type);var target=obj.GetComponent<TargetObject>();
        target.Lane=lane;target.Type=type;target.VertPosition=height;target.MoveSpeed=speed;
        target.HitWindow=currentLevel.HitWindowSeconds;target.BindEvaluator(hitZoneEvaluator);
        target.MaxHits=heavy?heavyRandom.Next(Mathf.Max(2,currentLevel.MinToughHits),Mathf.Max(2,Mathf.Max(currentLevel.MinToughHits,currentLevel.MaxToughHits))+1):1;target.ChainId=chain;
        target.SequenceIndex=index;target.SequenceLength=count;
        var mount=obj.GetComponent<TargetMountMotion>();mount.Duration=deploy;mount.TelegraphSeconds=pacing.MountTelegraphSeconds;
        obj.GetComponent<TargetMover>().Initialize(speed,missZoneZ,hitZoneEvaluator);target.EnsureTrackedSpawn();return target;
    }
    Transform GetSpawnPoint(LaneType lane)=>lane==LaneType.Left?spawnPointLeft:lane==LaneType.Right?spawnPointRight:spawnPointCenter;

    private GameObject CreateTargetObject(Vector3 position, TargetType type)
    {
        if(type==TargetType.Block||type==TargetType.Dodge)throw new System.ArgumentException("Reserved target type is not supported",nameof(type));
        GameObject target = new GameObject(type + "Target");
        target.transform.position = position;

        BoxCollider collider = target.AddComponent<BoxCollider>();
        collider.center = Vector3.zero;

        switch (type)
        {
            case TargetType.Kick:
                if (!TryAttachVisualPrefab(kickVisualPrefab, target.transform))
                {
                    TargetVisualFactory.BuildFallback(target.transform, type, BuildKickTarget, BuildTargetDisc);
                }
                collider.size = new Vector3(1.9f, 1.25f, 0.9f);
                break;
            case TargetType.ToughKick:
                if (!TryAttachVisualPrefab(heavyKickVisualPrefab, target.transform)) TargetVisualFactory.BuildFallback(target.transform, type, BuildKickTarget, BuildTargetDisc);
                collider.size = new Vector3(1.8f, 1.6f, 0.65f);
                break;
            case TargetType.ToughPunch:
                if (!TryAttachVisualPrefab(toughVisualPrefab, target.transform))
                {
                    TargetVisualFactory.BuildFallback(target.transform, type, BuildKickTarget, BuildTargetDisc);
                }
                collider.size = new Vector3(2.7f, 2.9f, 1.1f);
                break;
            default: // Punch
                if (!TryAttachVisualPrefab(punchVisualPrefab, target.transform))
                {
                    TargetVisualFactory.BuildFallback(target.transform, type, BuildKickTarget, BuildTargetDisc);
                }
                collider.size = new Vector3(1.7f, 1.7f, 0.8f);
                break;
        }

        target.AddComponent<TargetObject>().BindEvaluator(hitZoneEvaluator);
        target.AddComponent<TargetMover>();
        target.AddComponent<TargetMountMotion>();
        Rigidbody rb = target.GetComponent<Rigidbody>();
        if (rb == null)
        {
            rb = target.AddComponent<Rigidbody>();
        }

        rb.useGravity = false;
        rb.isKinematic = true;
        return target;
    }

    private bool TryAttachVisualPrefab(GameObject prefab, Transform parent)
    {
        if (prefab == null)
        {
            return false;
        }

        GameObject visual = Instantiate(prefab, parent);
        visual.name = prefab.name + "_Visual";
        visual.transform.localPosition = Vector3.zero;
        visual.transform.localRotation = Quaternion.identity;
        visual.transform.localScale = Vector3.one;
        RemoveColliders(visual);
        return true;
    }

    private void RemoveColliders(GameObject root)
    {
        Collider[] colliders = root.GetComponentsInChildren<Collider>(true);
        for (int i = 0; i < colliders.Length; i++)
        {
            Destroy(colliders[i]);
        }
    }

    private void BuildTargetDisc(Transform parent, Color targetColor, bool heavyTarget)
    {
        float baseRadius = heavyTarget ? 0.95f : 0.82f;
        float depth = heavyTarget ? 0.26f : 0.22f;

        GameObject backPlate = VisualPrimitive.Create(PrimitiveType.Cylinder);
        backPlate.name = "BackPlate";
        backPlate.transform.SetParent(parent, false);
        backPlate.transform.localPosition = Vector3.zero;
        backPlate.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        backPlate.transform.localScale = new Vector3(baseRadius, depth, baseRadius);
        ApplyMaterial(backPlate, new Color(0.09f, 0.13f, 0.18f, 1f), 0.3f);

        GameObject outerRing = VisualPrimitive.Create(PrimitiveType.Cylinder);
        outerRing.name = "OuterRing";
        outerRing.transform.SetParent(parent, false);
        outerRing.transform.localPosition = new Vector3(0f, 0f, -0.03f);
        outerRing.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        outerRing.transform.localScale = new Vector3(baseRadius * 0.92f, depth * 0.65f, baseRadius * 0.92f);
        ApplyMaterial(outerRing, targetColor, heavyTarget ? 2.4f : 1.9f);

        GameObject midRing = VisualPrimitive.Create(PrimitiveType.Cylinder);
        midRing.name = "MidRing";
        midRing.transform.SetParent(parent, false);
        midRing.transform.localPosition = new Vector3(0f, 0f, -0.06f);
        midRing.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        midRing.transform.localScale = new Vector3(baseRadius * 0.62f, depth * 0.55f, baseRadius * 0.62f);
        ApplyMaterial(midRing, new Color(1f, 0.93f, 0.82f, 1f), 0.8f);

        GameObject bullseye = VisualPrimitive.Create(PrimitiveType.Cylinder);
        bullseye.name = "Bullseye";
        bullseye.transform.SetParent(parent, false);
        bullseye.transform.localPosition = new Vector3(0f, 0f, -0.09f);
        bullseye.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        bullseye.transform.localScale = new Vector3(baseRadius * 0.28f, depth * 0.42f, baseRadius * 0.28f);
        ApplyMaterial(bullseye, heavyTarget ? new Color(1f, 0.72f, 0.12f, 1f) : new Color(1f, 0.96f, 0.35f, 1f), heavyTarget ? 2.8f : 2.2f);

        GameObject innerGlow = VisualPrimitive.Create(PrimitiveType.Cylinder);
        innerGlow.name = heavyTarget ? "HeavyCoreGlow" : "PunchCoreGlow";
        innerGlow.transform.SetParent(parent, false);
        innerGlow.transform.localPosition = new Vector3(0f, 0f, -0.13f);
        innerGlow.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        innerGlow.transform.localScale = new Vector3(baseRadius * 0.16f, depth * 0.25f, baseRadius * 0.16f);
        ApplyMaterial(innerGlow, Color.white, heavyTarget ? 2.6f : 1.8f);

        GameObject mount = VisualPrimitive.Create(PrimitiveType.Cube);
        mount.name = "Mount";
        mount.transform.SetParent(parent, false);
        mount.transform.localPosition = new Vector3(0f, 0f, 0.18f);
        mount.transform.localScale = new Vector3(baseRadius * 1.2f, baseRadius * 1.2f, 0.08f);
        ApplyMaterial(mount, new Color(0.12f, 0.18f, 0.25f, 1f), 0.25f);

        int markerCount = heavyTarget ? 8 : 4;
        for (int i = 0; i < markerCount; i++)
        {
            float angle = i * (360f / markerCount);
            Vector3 markerPosition = Quaternion.Euler(0f, 0f, angle) * new Vector3(0f, baseRadius * 0.92f, -0.15f);
            GameObject marker = VisualPrimitive.Create(PrimitiveType.Cube);
            marker.name = heavyTarget ? "HeavyWarningTick" : "PunchAimTick";
            marker.transform.SetParent(parent, false);
            marker.transform.localPosition = markerPosition;
            marker.transform.localRotation = Quaternion.Euler(0f, 0f, angle);
            marker.transform.localScale = new Vector3(0.08f, heavyTarget ? 0.34f : 0.24f, 0.08f);
            ApplyMaterial(marker, heavyTarget ? new Color(1f, 0.23f, 0.08f, 1f) : new Color(1f, 0.86f, 0.25f, 1f), heavyTarget ? 2.8f : 1.7f);
        }

        if (heavyTarget)
        {
            GameObject shieldFrame = VisualPrimitive.Create(PrimitiveType.Cube);
            shieldFrame.name = "HeavyBlockerFrame";
            shieldFrame.transform.SetParent(parent, false);
            shieldFrame.transform.localPosition = new Vector3(0f, 0f, 0.04f);
            shieldFrame.transform.localScale = new Vector3(baseRadius * 2.1f, 0.16f, 0.18f);
            ApplyMaterial(shieldFrame, new Color(1f, 0.34f, 0.08f, 1f), 2.4f);

            GameObject warningSlash = VisualPrimitive.Create(PrimitiveType.Cube);
            warningSlash.name = "HeavyDiagonalWarning";
            warningSlash.transform.SetParent(parent, false);
            warningSlash.transform.localPosition = new Vector3(0f, 0f, -0.18f);
            warningSlash.transform.localRotation = Quaternion.Euler(0f, 0f, -35f);
            warningSlash.transform.localScale = new Vector3(baseRadius * 1.55f, 0.13f, 0.08f);
            ApplyMaterial(warningSlash, new Color(1f, 0.92f, 0.18f, 1f), 2.3f);
        }
    }

    private void BuildKickTarget(Transform parent)
    {
        Color kickColor = GameVisualPalette.GetTargetColor(TargetType.Kick);

        GameObject pad = VisualPrimitive.Create(PrimitiveType.Cylinder);
        pad.name = "KickPad";
        pad.transform.SetParent(parent, false);
        pad.transform.localPosition = Vector3.zero;
        pad.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        pad.transform.localScale = new Vector3(0.98f, 0.22f, 0.62f);
        ApplyMaterial(pad, kickColor, 2.0f);

        GameObject core = VisualPrimitive.Create(PrimitiveType.Cube);
        core.name = "KickCore";
        core.transform.SetParent(parent, false);
        core.transform.localPosition = new Vector3(0f, 0f, -0.09f);
        core.transform.localScale = new Vector3(1.15f, 0.42f, 0.16f);
        ApplyMaterial(core, GameVisualPalette.GetTargetHighlight(TargetType.Kick), 1.4f);

        GameObject soleLine = VisualPrimitive.Create(PrimitiveType.Cube);
        soleLine.name = "KickSoleLine";
        soleLine.transform.SetParent(parent, false);
        soleLine.transform.localPosition = new Vector3(0f, -0.34f, -0.18f);
        soleLine.transform.localScale = new Vector3(1.42f, 0.09f, 0.08f);
        ApplyMaterial(soleLine, new Color(0.88f, 1f, 0.86f, 1f), 1.7f);

        GameObject leftStripe = VisualPrimitive.Create(PrimitiveType.Cube);
        leftStripe.name = "KickStripeLeft";
        leftStripe.transform.SetParent(parent, false);
        leftStripe.transform.localPosition = new Vector3(-0.32f, -0.08f, -0.16f);
        leftStripe.transform.localRotation = Quaternion.Euler(0f, 0f, -18f);
        leftStripe.transform.localScale = new Vector3(0.12f, 0.78f, 0.10f);
        ApplyMaterial(leftStripe, new Color(0.04f, 0.16f, 0.18f, 1f), 0.35f);

        GameObject rightStripe = VisualPrimitive.Create(PrimitiveType.Cube);
        rightStripe.name = "KickStripeRight";
        rightStripe.transform.SetParent(parent, false);
        rightStripe.transform.localPosition = new Vector3(0.32f, -0.08f, -0.16f);
        rightStripe.transform.localRotation = Quaternion.Euler(0f, 0f, 18f);
        rightStripe.transform.localScale = new Vector3(0.12f, 0.78f, 0.10f);
        ApplyMaterial(rightStripe, new Color(0.04f, 0.16f, 0.18f, 1f), 0.35f);

        GameObject toeCap = VisualPrimitive.Create(PrimitiveType.Sphere);
        toeCap.name = "KickToeCap";
        toeCap.transform.SetParent(parent, false);
        toeCap.transform.localPosition = new Vector3(0f, 0.25f, -0.12f);
        toeCap.transform.localScale = new Vector3(0.78f, 0.28f, 0.16f);
        ApplyMaterial(toeCap, new Color(0.08f, 0.34f, 0.32f, 1f), 0.6f);
    }

    private void ApplyMaterial(GameObject visual, Color color, float emissionStrength)
    {
        Collider primitiveCollider = visual.GetComponent<Collider>();
        if (primitiveCollider != null)
        {
            Destroy(primitiveCollider);
        }

        Renderer renderer = visual.GetComponent<Renderer>();
        if (renderer == null)
        {
            return;
        }

        var key=new Vector4(color.r,color.g,color.b,emissionStrength);
        if(fallbackMaterials.TryGetValue(key,out var cached)&&cached!=null){renderer.sharedMaterial=cached;return;}
        Material material = new Material(Shader.Find("Standard"));
        fallbackMaterials[key]=material;
        material.color = color;
        material.SetFloat("_Metallic", 0.12f);
        material.SetFloat("_Glossiness", 0.75f);
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", color * emissionStrength);
        renderer.sharedMaterial = material;
    }
}
