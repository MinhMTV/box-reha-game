using System;
using System.IO;
internal static class CalibrationHostChecks
{
    internal static void Run()
    {
        var c = new MeasuredCalibration();
        void Check(bool ok, string what) { if (!ok) throw new Exception("Calibration: " + what); }
        SensorReading Reading(int n) => new SensorReading { SchemaVersion=2, DeviceId="fixture-device", ConnectionId="fixture-epoch",
            SensorType=SensorDeviceType.Alpha, BodySide=BodySide.Left, Quantity="alpha.impact", Unit="unknown", Provenance="dynamics_sdk",
            IsComputedPunch=true, IsValid=true, HasTiming=true, SourceClock="unix_seconds", Timestamp=1000+n,
            ReceivedTimestamp=10+n, SourceAgeSeconds=0, RawValue=n*10, EventId="fixture-event-"+n };
        void Start() => c.Begin("fixture-study","fixture-device","fixture-epoch","Alpha","Left","COMPATIBILITY",10);
        Start(); var r=Reading(1); r.Provenance="sdk_mock"; Check(!c.Add(r,11),"mock excluded");
        r=Reading(1); r.BodySide=BodySide.Right; Check(!c.Add(r,11),"side isolated");
        r=Reading(1); r.ConnectionId="reconnected"; Check(!c.Add(r,11),"epoch isolated");
        r=Reading(1); r.Quantity="delta.power_index"; Check(!c.Add(r,11),"quantity isolated");
        r=Reading(1); r.RawValue=float.NaN; Check(!c.Add(r,11),"NaN rejected");
        Check(!c.Add(Reading(1),12),"stale rejected");
        Check(c.Add(Reading(1),11) && !c.Add(Reading(1),11),"duplicate rejected");
        for(int i=2;i<=5;i++) Check(c.Add(Reading(i),10+i),"valid fixture accepted");
        Check(!c.Collecting && c.Result.baseline==30 && c.Result.sampleCount==5 && c.Result.qualification=="UNQUALIFIED", "median and qualification");
        Check(c.Result.deviceId=="fixture-device" && c.Result.eventIds.Length==5 && c.Result.sdkBuildMode=="COMPATIBILITY", "audit identities");
        bool refused=false; try { c.Save(Path.GetTempPath(),"other-study"); } catch(InvalidOperationException) { refused=true; } Check(refused,"participant isolation");
        string folder=Path.Combine(Path.GetTempPath(),"calibration-synthetic-"+Guid.NewGuid().ToString("N"));
        string saved=c.Save(folder,"fixture-study"); Check(File.ReadAllText(saved).Contains("UNQUALIFIED"),"saved qualifier");
        File.Delete(saved); Directory.Delete(folder);
        Start(); c.Cancel("interrupted"); Check(!c.Add(Reading(1),11) && c.Result==null,"cancel fails closed");
        Start(); Check(!c.Add(Reading(1),131) && !c.Collecting,"timeout fails closed");
        c.Begin("fixture-study","fixture-device","fixture-epoch","Alpha","Left","COMPATIBILITY",10,"strength",3);
        for(int i=1;i<=3;i++)Check(c.Add(Reading(i),10+i)&&c.SampleCount==0,"practice is not a strong sample");
        for(int i=4;i<=8;i++)Check(c.Add(Reading(i),10+i),"strong sample after practice");
        Check(c.Result.baseline==60&&c.Result.eventIds.Length==5,"practice excluded from median");
        Console.WriteLine("CALIBRATION_HOST_PASS 26 assertions; synthetic fixtures only, no measured baseline produced.");
    }
}
