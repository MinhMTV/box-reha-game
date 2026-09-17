using System;
static class PacingHostChecks
{
    static int checks;
    static void Require(bool value,string message){checks++;if(!value)throw new Exception("Pacing: "+message);}
    public static void Run()
    {
        var p=new GameplayPacingProfile();
        Require(!p.UsePersonalRapidReferenceForPacing,"calibration unused");
        for(int level=1;level<=3;level++)
        for(int t=0;t<60;t++)
        {
            var s=p.Sample(level,false,t);var tier=p.GetTier(level);
            Require(s.IntervalSeconds>=.17999f,"speed floor");
            Require(s.TravelSeconds>=tier.TravelMin-.0001f&&s.TravelSeconds<=tier.TravelMax+.0001f,"travel range");
            Require(s.RecoverySeconds<=1.5f&&s.MaxConcurrent<=8,"bounded recovery and visible count");
        }
        var planner=new GameplayPatternPlanner(73);bool fifty=false,thirty=false;
        for(int i=0;i<500;i++)
        {
            var plan=planner.Select(p.Sample(3,false,i%60),p,new[]{TargetType.Punch},new[]{LaneType.Left,LaneType.Right},true,.35f);
            Require(plan.Length<=50&&plan.Length>=1,"Hard bounded length");
            fifty|=plan.Length>=40;thirty|=plan.Length>=30;
        }
        Require(fifty&&thirty,"Hard samples 40-50 flurries");
        foreach(var types in new[]{new[]{TargetType.Punch},new[]{TargetType.Kick},new[]{TargetType.Punch,TargetType.Kick}})
        foreach(var lanes in new[]{new[]{LaneType.Left},new[]{LaneType.Right},new[]{LaneType.Left,LaneType.Right}})
        foreach(bool physical in new[]{false,true})
        {
            var generator=new GameplayPatternPlanner(42);var timeline=new PacingActionTimeline();
            for(int sequence=0;sequence<30;sequence++)
            {
                var plan=generator.Select(p.Sample(3,false,sequence),p,types,lanes,physical,.35f);
                if(physical&&types.Length==2){Require(plan==null,"physical mixed blocked");continue;}
                Require(plan!=null,"supported input");
                float requested=float.IsNegativeInfinity(timeline.LastAction)?0:timeline.LastAction+.18f;
                for(int i=0;i<plan.Length;i++)
                {
                    var side=plan.SideAt(i);
                    Require(Array.IndexOf(lanes,side)>=0,"available side only");
                    float minimum=plan.Type==TargetType.Kick?.55f:p.MinimumSpacing;
                    float due=timeline.Next(side,requested,minimum,physical?.35f:0);
                    Require(due-timeline.LastAction>=minimum-.0001f,"global spacing across sequences");
                    if(physical)Require(due-(side==LaneType.Left?timeline.LastLeft:timeline.LastRight)>=.3499f,"independent per-device spacing");
                    timeline.Commit(side,due);requested=due+plan.Interval;
                }
            }
        }
        var alternating=new PacingActionTimeline();
        for(int i=0;i<100;i++)
        {
            var side=i%2==0?LaneType.Left:LaneType.Right;
            float due=alternating.Next(side,i*.18f,.18f,.35f);
            Require(Math.Abs(due-i*.18f)<.001,"no global 350ms clamp");
            alternating.Commit(side,due);
        }
        int previous=0;
        foreach(int minute in new[]{0,1,3,5,10,30,120,1000})
        {
            var sample=p.Sample(4,true,minute*60+12);var gen=new GameplayPatternPlanner(1);
            var plan=gen.Select(sample,p,new[]{TargetType.Punch},new[]{LaneType.Left,LaneType.Right},true,.35f);
            Require(plan.Length>previous,"Endless length grows without design cap");previous=plan.Length;
            Require(sample.MaxConcurrent<=8&&sample.IntervalSeconds>=.18f,"Endless speed/count bounded");
            if(minute>=5)Require(sample.PacingTier==p.MaxPacingTier,"speed tier capped separately");
        }
        var a=new GameplayPatternPlanner(19);var b=new GameplayPatternPlanner(19);
        for(int i=0;i<100;i++)
        {
            var sample=p.Sample(3,false,i%60);
            var x=a.Select(sample,p,new[]{TargetType.Punch},new[]{LaneType.Left,LaneType.Right},false,0);
            var y=b.Select(sample,p,new[]{TargetType.Punch},new[]{LaneType.Left,LaneType.Right},false,0);
            Require(x.PatternId==y.PatternId&&x.StartSide==y.StartSide,"seed repeatability");
        }
        Require(new GameplayPatternPlanner(1).Select(p.Sample(3,false,20),p,new TargetType[0],new[]{LaneType.Left},false,0)==null,"empty family stays empty");
        p.AbsoluteMinimumActionSpacingSeconds=.1f;p.MinimumPhysicalActionSpacingSeconds=.1f;
        Require(p.MinimumSpacing>=.18f,"absolute safety floor");
        var refined=new GameplayPacingProfile();int mixedPunch=0,mixedKick=0;
        var mixPlanner=new GameplayPatternPlanner(991);
        for(int n=0;n<1000;n++)
        {
            var sample=refined.Sample(3,n%2==0,n*61+12);
            var kicks=mixPlanner.Select(sample,refined,new[]{TargetType.Kick},new[]{LaneType.Left,LaneType.Right},true,.35f);
            Require(kicks.Length<=20&&kicks.Length<=refined.KickAbsoluteMaxLength,"Endless cannot bypass kick cap");
            Require(kicks.Length<=15,"production rare kick bound");
            var mix=mixPlanner.Select(refined.Sample(3,false,20),refined,new[]{TargetType.Punch,TargetType.Kick},new[]{LaneType.Left,LaneType.Right},false,0);
            int streak=0;
            for(int i=0;i<mix.Length;i++)
            {
                if(mix.TypeAt(i)==TargetType.Kick){mixedKick++;streak++;}else{mixedPunch++;streak=0;}
                Require(streak<=refined.MaxConsecutiveKicks,"mixed kick streak bounded");
                if(mix.TypeAt(i)==TargetType.Kick)Require(mix.IntervalBefore(i)>=.55f,"mixed kick cadence conservative");
            }
            foreach(int level in new[]{1,2,3})
                Require(refined.HeavyInterval(level,false,n,n%100/100d)>=refined.HeavyMinimumSeparation(level,false),"heavy separation");
        }
        float share=mixedPunch/(float)(mixedPunch+mixedKick);
        Require(share>=.70f&&share<=.85f,"mixed statistical punch dominance");
        Console.WriteLine("MIXED_PUNCH_SHARE "+share);
        Console.WriteLine("PACING_HOST_PASS "+checks+" deterministic assertions; no hardware qualification.");
    }
}
