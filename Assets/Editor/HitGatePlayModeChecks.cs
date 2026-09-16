using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using UnityEngine;
using Object=UnityEngine.Object;

/// <summary>Real imported prefabs and evaluator in Play Mode. Fixtures are synthetic, never hardware evidence.</summary>
public static class HitGatePlayModeChecks
{
    static readonly BindingFlags Private=BindingFlags.Instance|BindingFlags.NonPublic;
    static readonly List<string> checks=new List<string>();
    static HitZoneEvaluator evaluator;
    static HitZoneVisualizer gate;
    static TargetSpawner spawner;
    static void Require(bool value,string name){if(!value)throw new Exception("Hit gate QA: "+name);checks.Add("PASS "+name);}
    static void Invoke(object obj,string method)=>obj.GetType().GetMethod(method,Private).Invoke(obj,null);
    static void Refresh()=>Invoke(gate,"LateUpdate");
    static TargetObject Create(TargetType type,float offset=0,LaneType lane=LaneType.Left)
    {
        // Independent visual fixtures: previous-case transient feedback is not part of this scenario.
        foreach(var popup in Object.FindObjectsByType<TextPopup>(FindObjectsSortMode.None))Object.DestroyImmediate(popup.gameObject);
        foreach(var popup in Object.FindObjectsByType<ComboMilestonePopup>(FindObjectsSortMode.None))Object.DestroyImmediate(popup.gameObject);
        var oldPool=Object.FindFirstObjectByType<DojoDebrisPool>();
        if(oldPool!=null)typeof(DojoDebrisPool).GetMethod("Advance",Private).Invoke(oldPool,new object[]{DojoDebrisPool.Lifetime});
        bool kick=type==TargetType.Kick||type==TargetType.ToughKick;
        bool heavy=type==TargetType.ToughPunch||type==TargetType.ToughKick;
        if(heavy)lane=LaneType.Center;
        var p=new Vector3(lane==LaneType.Center?0:lane==LaneType.Left?-2.4f:2.4f,kick?.45f:2.1f,evaluator.HitZoneZ-offset*8);
        var go=(GameObject)typeof(TargetSpawner).GetMethod("CreateTargetObject",Private).Invoke(spawner,new object[]{p,type});
        var target=go.GetComponent<TargetObject>();target.Type=type;target.Lane=lane;target.VertPosition=kick?VerticalPosition.Low:VerticalPosition.High;
        target.MaxHits=heavy?10:1;target.MoveSpeed=8;target.HitWindow=.9f;
        go.GetComponent<TargetMountMotion>().enabled=false;go.GetComponent<TargetMover>().enabled=false;
        Invoke(target,"Start");return target;
    }
    static void Clear(TargetObject t)
    { evaluator.UnregisterTarget(t);t.Resolve();t.gameObject.SetActive(false);Object.Destroy(t.gameObject); }
    static void ClearFlash(){Array.Clear((float[])typeof(HitZoneVisualizer).GetField("flashUntil",Private).GetValue(gate),0,2);}
    static void Action(TargetObject target,float power=1)
    {
        KeyboardActionFactory.DevelopmentPower=power;
        evaluator.EvaluateHit(KeyboardActionFactory.Create(target.IsKick?ActionType.Kick:ActionType.Punch,target.Lane==LaneType.Right?BodySide.Right:BodySide.Left));
        KeyboardActionFactory.DevelopmentPower=1;Refresh();
    }
    public static void Run(Action<string> capture)
    {
        checks.Clear();evaluator=Object.FindFirstObjectByType<HitZoneEvaluator>();gate=evaluator.GetComponent<HitZoneVisualizer>();spawner=Object.FindFirstObjectByType<TargetSpawner>();
        Require(gate!=null,"gate installed by runtime evaluator");
        ClearFlash();Refresh();
        Require(gate.PunchState=="READY"&&gate.KickState=="READY","dormant with no target");capture("Gate-Dormant");
        var root=evaluator.transform.Find("HitGate");
        Require(root!=null && Mathf.Abs(root.position.z-evaluator.HitZoneZ)<.0001f,"exact logical visual plane");
        var center=(Transform)typeof(HitZoneEvaluator).GetField("hitZoneCenter",Private).GetValue(evaluator);
        if(center==null)center=evaluator.transform;
        var original=center.position;center.position+=Vector3.forward*1.25f;Refresh();
        Require(Mathf.Abs(root.position.z-evaluator.HitZoneZ)<.0001f,"gate follows changed evaluator plane");center.position=original;
        Require(Mathf.Abs(gate.PunchHeight-2.1f)<.001f&&Mathf.Abs(gate.KickHeight-.45f)<.001f,"separate upper punch and lower kick heights");
        Require(root.GetComponentsInChildren<Collider>().Length==0,"gate has no collider");
        Require(GameObject.Find("DojoLeftArmLane")==null&&GameObject.Find("DojoRightArmLane")==null,"old longitudinal rails remain absent");
        foreach(var type in new[]{TargetType.Punch,TargetType.Kick})
        foreach(float offset in new[]{-.6f,-.35f,-.2f,0f,.35f,.6f})
        {
            ClearFlash();var target=Create(type,offset);Refresh();
            var expected=GameplayRules.Timing(offset,.45f);
            Require(evaluator.PreviewTiming(target)==expected,type+" preview "+expected+" agrees with evaluator");
            string state=type==TargetType.Punch?gate.PunchState:gate.KickState;
            Require(expected==HitQuality.Miss?state=="APPROACH":state.Contains(expected.ToString().ToUpperInvariant()),"label matches "+expected);
            if(offset==0)capture(type==TargetType.Punch?"Gate-Punch-Perfect-Window":"Gate-Kick-Perfect-Window");
            if(offset==-.2f)capture("Gate-"+type+"-Good-Window");
            Action(target);
            Require(target.IsResolved==(expected!=HitQuality.Miss),"actual acceptance "+type+" "+offset);
            if(offset==0)capture("Gate-"+type+"-Perfect-Feedback");
            Clear(target);
        }
        ClearFlash();var weak=Create(TargetType.Punch);Action(weak,.1f);
        Require(!weak.IsResolved&&gate.PunchState.Contains("TOO LIGHT"),"TOO LIGHT preserves target and gate retry");capture("Gate-Too-Light");
        Action(weak);Require(weak.IsResolved,"retry resolves weak target");Clear(weak);
        foreach(var type in new[]{TargetType.ToughPunch,TargetType.ToughKick})
        {
            ClearFlash();var heavy=Create(type);heavy.LockInHitZone(evaluator.HitZoneZ);Refresh();
            Require((heavy.IsKick?gate.KickState:gate.PunchState)=="HIT AGAIN","heavy stays actionable");capture("Gate-"+type);
            var visual=heavy.GetComponentInChildren<DigitalDojoTargetVisual>();
            Require(visual.DamageStage==0,"heavy intact stage");
            for(int i=0;i<3;i++)Action(heavy);
            Require(visual.DamageStage==1&&!heavy.IsResolved,"heavy 70 percent stage");capture("Damage-70-"+type);
            for(int i=0;i<3;i++)Action(heavy);
            Require(visual.DamageStage==2&&!heavy.IsResolved,"heavy 40 percent stage");capture("Damage-40-"+type);
            for(int i=0;i<4;i++)Action(heavy);
            Require(visual.DamageStage==3&&heavy.IsResolved,"heavy zero health breaks");
            var pool=Object.FindFirstObjectByType<DojoDebrisPool>();
            Require(SettingsManager.ReducedMotion||pool!=null&&pool.ActiveCount<=DojoDebrisPool.Capacity,"bounded authored fracture pool");
            if(pool!=null){Require(pool.GetComponentsInChildren<Collider>().Length==0,"debris has no implicit collider");for(int i=0;i<12;i++)typeof(DojoDebrisPool).GetMethod("Advance",Private).Invoke(pool,new object[]{.02f});}
            capture("Break-"+type);Clear(heavy);
        }
        var deploy=Create(TargetType.Punch,-1);var mount=deploy.GetComponent<TargetMountMotion>();mount.enabled=true;Invoke(mount,"Start");
        Require(!mount.Ready&&evaluator.PreviewTiming(deploy)==HitQuality.Miss,"deployment cannot be hit");
        typeof(TargetMountMotion).GetField("born",Private).SetValue(mount,Time.time-.15f);Invoke(mount,"LateUpdate");capture("Mechanical-Deploy");
        Require(mount.Phase=="Deploy","normal mechanical deploy phase");
        typeof(TargetMountMotion).GetField("born",Private).SetValue(mount,Time.time-.27f);Require(mount.Phase=="Align","alignment phase");
        typeof(TargetMountMotion).GetField("born",Private).SetValue(mount,Time.time-.4f);Require(mount.Ready,"normal deploy ends at profile duration");Clear(deploy);
        bool reduced=SettingsManager.ReducedMotion;
        try
        {
            SettingsManager.ReducedMotion=true;var simple=Create(TargetType.Punch);Action(simple);
            Require(simple.IsResolved,"reduced motion keeps hit evaluation");capture("Reduced-Motion-Perfect");Clear(simple);
        }
        finally {SettingsManager.ReducedMotion=reduced;}
        ClearFlash();var burst=new List<TargetObject>();
        for(int i=0;i<5;i++)burst.Add(Create(i%2==0?TargetType.Punch:TargetType.Kick,-.05f-i*.30f,i%2==0?LaneType.Left:LaneType.Right));
        Refresh();capture("Burst-Minimum-Separation");
        Require(burst.Count<=spawner.Pacing.Hard.MaxConcurrent,"high speed burst within concurrent bound");
        foreach(var t in burst)Clear(t);
        Require(Time.timeScale==1,"effects never apply global hit stop");
        File.WriteAllLines("artifacts/validation/hit-gate-playmode.txt",checks);
    }
}
