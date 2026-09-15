using System;
using System.IO;
using System.Linq;
using UnityEngine;
public static class HardwareFeedbackChecks
{
    private static int checks;
    private static void Check(bool condition,string message){if(!condition)throw new Exception("Hardware feedback: "+message);checks++;}
    public static void Run()
    {
        string dir=Path.Combine(Path.GetTempPath(),"dojo-feedback-synthetic-"+Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(dir);
        try
        {
            var db=new FileProfileRepository(dir);var legacy=new PlayerProfile{Name="A",StudyId="legacy-a"};db.Migrate(legacy);db.Migrate(legacy);
            Check(db.GetAll().Count==1&&db.ActiveId=="legacy-a","idempotent legacy migration");
            var b=db.Create("A");Check(b.StudyId!=legacy.StudyId,"same name never merges identity");
            db.SetActive(b.StudyId);db=new FileProfileRepository(dir);Check(db.ActiveId==b.StudyId,"active survives reload");
            var a=db.Get("legacy-a");a.Name="Renamed";db.Update(a);db.SetActive(a.StudyId);Check(db.Get("legacy-a").Name=="Renamed","rename preserves identity");
            db.Archive(b.StudyId);Check(db.GetAll().Count==1&&db.Get(b.StudyId).Archived,"archive preserves stored profile");
            bool refused=false;try{db.Archive(a.StudyId);}catch(InvalidOperationException){refused=true;}Check(refused,"cannot archive active participant");
            Check(File.Exists(Path.Combine(dir,"profiles-v1.json.bak")),"backup exists");
            var processor=new SensorEventProcessor();
            for(int i=0;i<25;i++){string id="removed-"+i,epoch="epoch-"+i;Check(processor.SetConnection(id,epoch,SensorDeviceType.Alpha,BodySide.Left,"dynamics_sdk",true,10),"new binding capacity");processor.ForgetDevice(id,epoch);Check(processor.ConnectedCount==0,"removed binding gone");Check(!processor.SetConnection(id,epoch,SensorDeviceType.Alpha,BodySide.Left,"dynamics_sdk",true,11),"retired epoch cannot resurrect");}
            Check(processor.SetConnection("removed-0","fresh-epoch",SensorDeviceType.Alpha,BodySide.Right,"dynamics_sdk",true,12),"re-pair on opposite side with fresh epoch");
            var c=new MeasuredCalibration();
            c.Begin(a.StudyId,"physical-fixture","epoch","Alpha","Left","COMPATIBILITY",10,"speed");
            for(int i=0;i<5;i++)
            {
                double time=11+i*.25;
                var r=new SensorReading{DeviceId="physical-fixture",ConnectionId="epoch",SensorType=SensorDeviceType.Alpha,BodySide=BodySide.Left,Quantity="alpha.impact",Unit="unknown",Provenance="dynamics_sdk",IsComputedPunch=true,IsValid=true,HasTiming=true,SourceClock="unix_seconds",Timestamp=1000+i*.25,RawValue=10+i,SourceAgeSeconds=0,ReceivedTimestamp=time,EventId="e"+i};
                Check(c.Add(r,time),"accept fresh rapid repetition");
            }
            Check(c.Result.actionsPerSecond==4&&c.Result.referenceKind=="speed","rapid reference uses median inter-event interval");
            c.Save(dir,a.StudyId);Check(CalibrationLibrary.Load(dir,b.StudyId).Count==0,"reference profile isolation");
            var rbase=c.Result;rbase.referenceKind="strength";
            var action=PlayerActionEvent.Create(ActionType.Punch,LaneType.Left,1,Vector2.zero,Vector2.zero,0,InputSourceType.Sensor,VerticalPosition.High,0,SensorDeviceType.Alpha,BodySide.Left);
            action.DeviceId="physical-fixture";action.IsValid=true;action.Provenance="dynamics_sdk";action.Quantity="alpha.impact";action.Unit="unknown";action.RawValue=6;
            Check(CalibrationLibrary.TryNormalize(rbase,action,a.StudyId,out float relative)&&Math.Abs(relative-.5)<1e-5,"same quantity personal reference");
            action.SensorDevice=SensorDeviceType.Delta;Check(!CalibrationLibrary.TryNormalize(rbase,action,a.StudyId,out _),"families never cross-normalize");action.SensorDevice=SensorDeviceType.Alpha;
            Check(!CalibrationLibrary.TryNormalize(rbase,action,b.StudyId,out _),"profiles never cross-normalize");
            action.RawValue=10000;Check(CalibrationLibrary.TryNormalize(rbase,action,a.StudyId,out relative)&&relative==2.5f,"outlier bounded");
            rbase.baseline=double.NaN;Check(!CalibrationLibrary.TryNormalize(rbase,action,a.StudyId,out _),"invalid baseline neutral");
            foreach(string family in new[]{"Alpha","Delta"})foreach(string side in new[]{"Left","Right"})
            {
                var state=new AndroidNativeStatus{schemaVersion=1,initialized=true,permissionsGranted=true,profileReady=true,devices=new[]{new AndroidNativeDevice{id="only",name="SG-fixture",family=family,side=side,online=true,connectionId="epoch"}}};
                Check(AndroidSessionPolicy.CanPrepare(state,family,out _),"single "+family+" "+side);
                state.devices[0].family="Unknown";Check(!AndroidSessionPolicy.CanPrepare(state,family,out string reason)&&reason.Contains("SG-fixture")&&reason.Contains(side),"actionable unresolved identity");
                state.devices=Array.Empty<AndroidNativeDevice>();Check(!AndroidSessionPolicy.CanPrepare(state,family,out _),"removed binding never ready");
            }
            File.WriteAllText(Path.Combine(dir,"profiles-v1.json"),"{broken");refused=false;try{new FileProfileRepository(dir);}catch(Exception){refused=true;}Check(refused&&File.ReadAllText(Path.Combine(dir,"profiles-v1.json"))=="{broken","corrupt database preserved");
            Console.WriteLine("HARDWARE_FEEDBACK_HOST_PASS "+checks+" assertions; synthetic only, no hardware claim.");
        }
        finally {Directory.Delete(dir,true);}
    }
}
