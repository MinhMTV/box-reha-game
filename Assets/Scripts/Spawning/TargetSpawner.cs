using UnityEngine;
using System.Collections;

/// <summary>Single production scheduler: reaction targets and fully preannounced authored combinations.</summary>
public class TargetSpawner : MonoBehaviour
{
    public GameConfig Configuration => gameConfig;
    [SerializeField] private GameObject targetPrefab;
    [SerializeField] private Transform spawnPointLeft,spawnPointCenter,spawnPointRight;
    [SerializeField] private float missZoneZ;
    [SerializeField] private GameConfig gameConfig;
    [SerializeField] private GameObject punchVisualPrefab,kickVisualPrefab,toughVisualPrefab,heavyKickVisualPrefab;
    [SerializeField] private HitZoneEvaluator hitZoneEvaluator;
    [SerializeField] private GameplayPacingProfile pacing=new GameplayPacingProfile();
    public GameplayPacingProfile Pacing=>pacing;
    public string CurrentWave { get; private set; }="Warmup";
    public string CurrentPatternId { get; private set; }="";
    public int CurrentPacingTier { get; private set; }
    public int PatternActionIndex { get; private set; }
    public float CurrentTravelSeconds { get; private set; }
    public float NextExpectedActionTime { get; private set; }
    public int SessionSeed { get; private set; }
    public int ActiveTargetCount=>hitZoneEvaluator==null?0:ActiveCount();
    public string Availability=>currentLevel==null?"none":string.Join(",",currentLevel.AllowedTargetTypes)+" / "+string.Join(",",currentLevel.AllowedLanes);
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
        if(hitZoneEvaluator==null)hitZoneEvaluator=FindFirstObjectByType<HitZoneEvaluator>();
        if(hitZoneEvaluator==null)return;
        SessionSeed=pacing.Seed==0?(System.Environment.TickCount&int.MaxValue):pacing.Seed;
        planner=new GameplayPatternPlanner(SessionSeed);previousArrival=float.NegativeInfinity;
        misses=0;RecoveryRequested=false;missWindowStart=Time.time;pacingStarted=Time.time;isSpawning=true;
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
    public int ReservedCapacity=>0;
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
    public string Diagnostic => $"remaining={Remaining:F2} phase={CurrentWave} pattern={CurrentPatternId} pending={PendingActions} lookahead={Lookahead} active={ActiveTargetCount} reserved=0 nextSpawn={NextSpawnTime:F2} nextPattern={NextPatternTime:F2} recoveryUntil={RecoveryUntil:F2} heavy={HasActiveToughTarget()} missRecovery={RecoveryRequested} wait={WaitingReason}";
    float idleFor,nextDiagnostic,missRecoveryAfter;
    bool expedite;
    PacingActionTimeline timeline;
    float Remaining=>currentLevel==null?0:currentLevel.IsEndless?float.PositiveInfinity:currentLevel.DurationSeconds-(Time.time-pacingStarted);
    void Update()
    {
        if(!isSpawning||Time.deltaTime<=0)return;
        int active=ActiveCount();PeakActive=Mathf.Max(PeakActive,active);
        if(active>0)
        {
            idleFor=0;
            if(CurrentWave=="Recovery")LowIntensityTime+=Time.deltaTime;else ActiveWorkTime+=Time.deltaTime;
        }
        else
        {
            idleFor+=Time.deltaTime;EmptyIdleTime+=Time.deltaTime;MaxEmptyIdle=Mathf.Max(MaxEmptyIdle,idleFor);
            float threshold=currentLevel.LevelNumber<=1?1.3f:currentLevel.LevelNumber==2?1:.7f;
            if(idleFor>threshold&&Time.time>=RecoveryUntil&&Remaining>.3f&&CurrentPatternId!="unavailable")
            {
                Debug.LogWarning("PACING_IDLE_DIAGNOSTIC "+Diagnostic);
                expedite=true;RecoveryUntil=Time.time;NextPatternTime=Time.time;idleFor=0;
            }
        }
        if(Remaining<=34&&Remaining>=26&&Time.time>=nextDiagnostic)
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
            CurrentWave=sample.Wave;CurrentPacingTier=sample.PacingTier;ComboLengthTier=sample.ComboLengthTier;
            Lookahead=Mathf.Clamp(sample.MaxConcurrent,2,8);
            if(RecoveryRequested)
            {
                sample.Recovery=true;sample.Phase=PacingPhase.Recovery;CurrentWave="Recovery";
                RecoveryRequested=false;misses=0;missWindowStart=Time.time;
                missRecoveryAfter=Time.time+pacing.MissRecoveryCooldownSeconds;
            }
            var plan=planner.Select(sample,pacing,currentLevel.AllowedTargetTypes,currentLevel.AllowedLanes,
                SessionInputSelection.Physical,gameConfig!=null?gameConfig.SensorActionCooldown:.35f);
            if(plan==null){CurrentPatternId="unavailable";WaitingReason="no supported input";yield return new WaitForSeconds(.25f);continue;}
            CurrentPatternId=plan.PatternId;PatternActionIndex=0;
            CurrentTravelSeconds=plan.TravelSeconds;
            float deploy=pacing.MountTelegraphSeconds+Mathf.Clamp(pacing.NormalDeploySeconds,.2f,.4f);
            float sameSide=SessionInputSelection.Physical?(gameConfig!=null?gameConfig.SensorActionCooldown:.35f):0;
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
            float maxDistance=float.MaxValue;
            for(int i=0;i<Mathf.Min(count,Lookahead);i++)
            {var point=GetSpawnPoint(plan.SideAt(i));if(point!=null)maxDistance=Mathf.Min(maxDistance,point.position.z-hitZoneEvaluator.HitZoneZ);}
            if(maxDistance==float.MaxValue||maxDistance<=0){WaitingReason="missing spawn point";yield return null;continue;}
            float speedShared=maxDistance/(CurrentTravelSeconds+plan.Interval*(Lookahead-1));
            float requestedArrival=first;
            NextPatternTime=first;
            for(int i=0;i<count&&isSpawning&&Remaining>0;i++)
            {
                PendingActions=count-i;PatternActionIndex=i;
                var side=plan.SideAt(i);
                if(requestedArrival>=nextHeavyAt && currentLevel.ToughTargetChance>0 && Remaining>4)
                {
                    yield return SpawnHeavy(sample,plan);
                    CurrentPatternId=plan.PatternId;
                    requestedArrival=Mathf.Max(requestedArrival,Time.time+deploy+CurrentTravelSeconds);
                }
                var actionType=plan.TypeAt(i);
                float due=timeline.Next(side,requestedArrival,Mathf.Max(globalMinimum,i==0?0:plan.IntervalBefore(i)),sameSide);
                NextExpectedActionTime=due;
                // Rolling preview consumes only live logical slots. No full-pattern reservation.
                NextSpawnTime=due-deploy-CurrentTravelSeconds-plan.Interval*(Lookahead-1);
                WaitingReason="rolling lookahead";
                while(isSpawning&&Remaining>0&&(ActiveCount()>=Lookahead||(!expedite&&Time.time<NextSpawnTime)))yield return null;
                if(!isSpawning||Remaining<=0)yield break;
                expedite=false;
                // Slow frames/capacity pressure preserve a small honest lead, never teleport through the hit plane.
                due=timeline.Next(side,Mathf.Max(due,Time.time+deploy+.12f),globalMinimum,sameSide);
                float travel=Mathf.Max(.12f,due-Time.time-deploy);
                float z=hitZoneEvaluator.HitZoneZ+speedShared*travel;
                var target=SpawnPaced(actionType,side,z,speedShared,deploy,false,chain,i,count);
                if(target!=null)
                {
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
    float nextHeavyAt;
    public int HeavyEncounters { get; private set; }
    public float LastHeavyArrival { get; private set; }
    IEnumerator SpawnHeavy(PacingSample sample,ComboPlan plan)
    {
        WaitingReason="heavy preview slot";
        while(isSpawning&&ActiveCount()>=Lookahead)yield return null;
        if(!isSpawning)yield break;
        bool kick=plan.Type==TargetType.Kick || (plan.Mixed&&heavyRandom.NextDouble()<.25);
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
        WaitingReason="heavy work";CurrentWave="Heavy";
        while(isSpawning&&!target.IsResolved&&Remaining>0)yield return null;
        CurrentWave="Recovery";WaitingReason="resume prepared sequence";
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
        position.y=gameConfig!=null?gameConfig.GetVerticalOffset(height):height==VerticalPosition.Low?.45f:2.1f;
        var obj=CreateTargetObject(position,type);var target=obj.GetComponent<TargetObject>();
        target.Lane=lane;target.Type=type;target.VertPosition=height;target.MoveSpeed=speed;
        target.HitWindow=currentLevel.HitWindowSeconds;target.MinPower=currentLevel.MinPower;
        target.MaxHits=heavy?Mathf.Max(2,currentLevel.MinToughHits):1;target.ChainId=chain;
        target.SequenceIndex=index;target.SequenceLength=count;
        var mount=obj.GetComponent<TargetMountMotion>();mount.Duration=deploy;mount.TelegraphSeconds=pacing.MountTelegraphSeconds;
        obj.GetComponent<TargetMover>().Initialize(speed,missZoneZ);target.EnsureTrackedSpawn();return target;
    }
    Transform GetSpawnPoint(LaneType lane)=>lane==LaneType.Left?spawnPointLeft:lane==LaneType.Right?spawnPointRight:spawnPointCenter;

    private GameObject CreateTargetObject(Vector3 position, TargetType type)
    {
        GameObject target = new GameObject(type + "Target");
        target.transform.position = position;

        BoxCollider collider = target.AddComponent<BoxCollider>();
        collider.center = Vector3.zero;

        switch (type)
        {
            case TargetType.Kick:
                if (!TryAttachVisualPrefab(kickVisualPrefab, target.transform))
                {
                    BuildKickTarget(target.transform);
                }
                collider.size = new Vector3(1.9f, 1.25f, 0.9f);
                break;
            case TargetType.ToughKick:
                if (!TryAttachVisualPrefab(heavyKickVisualPrefab, target.transform)) BuildKickTarget(target.transform);
                collider.size = new Vector3(1.8f, 1.6f, 0.65f);
                break;
            case TargetType.Block:
                BuildBlockTarget(target.transform);
                collider.size = new Vector3(1.9f, 2.1f, 0.9f);
                break;
            case TargetType.Dodge:
                BuildDodgeTarget(target.transform);
                collider.size = new Vector3(2.8f, 1.0f, 1.0f);
                break;
            case TargetType.ToughPunch:
                if (!TryAttachVisualPrefab(toughVisualPrefab, target.transform))
                {
                    BuildTargetDisc(target.transform, GameVisualPalette.GetTargetColor(TargetType.ToughPunch), true);
                }
                collider.size = new Vector3(2.7f, 2.9f, 1.1f);
                break;
            default: // Punch
                if (!TryAttachVisualPrefab(punchVisualPrefab, target.transform))
                {
                    BuildTargetDisc(target.transform, GameVisualPalette.GetTargetColor(TargetType.Punch), false);
                }
                collider.size = new Vector3(1.7f, 1.7f, 0.8f);
                break;
        }

        target.AddComponent<TargetObject>();
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

    private void BuildBlockTarget(Transform parent)
    {
        GameObject shield = VisualPrimitive.Create(PrimitiveType.Cube);
        shield.name = "Shield";
        shield.transform.SetParent(parent, false);
        shield.transform.localPosition = Vector3.zero;
        shield.transform.localScale = new Vector3(1.65f, 1.95f, 0.42f);
        ApplyMaterial(shield, GameVisualPalette.GetTargetColor(TargetType.Block), 1.7f);

        GameObject core = VisualPrimitive.Create(PrimitiveType.Cube);
        core.name = "ShieldCore";
        core.transform.SetParent(parent, false);
        core.transform.localPosition = new Vector3(0f, 0f, -0.08f);
        core.transform.localScale = new Vector3(1.0f, 1.2f, 0.20f);
        ApplyMaterial(core, new Color(0.05f, 0.14f, 0.22f, 1f), 0.4f);
    }

    private void BuildDodgeTarget(Transform parent)
    {
        GameObject bar = VisualPrimitive.Create(PrimitiveType.Cylinder);
        bar.name = "DodgeBar";
        bar.transform.SetParent(parent, false);
        bar.transform.localPosition = Vector3.zero;
        bar.transform.localRotation = Quaternion.Euler(0f, 0f, 90f);
        bar.transform.localScale = new Vector3(0.42f, 1.45f, 0.42f);
        ApplyMaterial(bar, GameVisualPalette.GetTargetColor(TargetType.Dodge), 1.5f);

        GameObject leftCap = VisualPrimitive.Create(PrimitiveType.Sphere);
        leftCap.name = "DodgeCapLeft";
        leftCap.transform.SetParent(parent, false);
        leftCap.transform.localPosition = new Vector3(-1.4f, 0f, 0f);
        leftCap.transform.localScale = Vector3.one * 0.45f;
        ApplyMaterial(leftCap, GameVisualPalette.GetTargetHighlight(TargetType.Dodge), 1.0f);

        GameObject rightCap = VisualPrimitive.Create(PrimitiveType.Sphere);
        rightCap.name = "DodgeCapRight";
        rightCap.transform.SetParent(parent, false);
        rightCap.transform.localPosition = new Vector3(1.4f, 0f, 0f);
        rightCap.transform.localScale = Vector3.one * 0.45f;
        ApplyMaterial(rightCap, GameVisualPalette.GetTargetHighlight(TargetType.Dodge), 1.0f);
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

        Material material = new Material(Shader.Find("Standard"));
        material.color = color;
        material.SetFloat("_Metallic", 0.12f);
        material.SetFloat("_Glossiness", 0.75f);
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", color * emissionStrength);
        renderer.sharedMaterial = material;
    }
}
