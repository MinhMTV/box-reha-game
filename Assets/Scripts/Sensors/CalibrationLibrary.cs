using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;

public static class CalibrationLibrary
{
    private static string loadedStudy, loadedDirectory;
    private static readonly List<CalibrationBaseline> references=new List<CalibrationBaseline>();
    public static void Invalidate() { loadedStudy=null; }
    public static List<CalibrationBaseline> Load(string directory,string study)
    {
        var result=new List<CalibrationBaseline>();
        if(!Directory.Exists(directory))return result;
        foreach(string path in Directory.GetFiles(directory,"reference-*.json"))
        {
            try { var r=JsonUtility.FromJson<CalibrationBaseline>(File.ReadAllText(path));if(r!=null&&r.studyId==study&&(r.schemaVersion==1||r.schemaVersion==2))
                {if(string.IsNullOrEmpty(r.referenceKind))r.referenceKind="strength";if(string.IsNullOrEmpty(r.calibrationId))r.calibrationId="legacy-"+Path.GetFileNameWithoutExtension(path);result.Add(r);} }
            catch(Exception e) when(e is IOException||e is ArgumentException) { /* Preserve unreadable records, never use as a baseline. */ }
        }
        result.Sort((a,b)=>string.CompareOrdinal(b.createdUtc,a.createdUtc));return result;
    }
    public static bool TryNormalize(CalibrationBaseline r, PlayerActionEvent action, string study, out float relative)
    {
        relative=1;
        if(r==null||(r.schemaVersion!=1&&r.schemaVersion!=2)||r.studyId!=study||r.referenceKind!="strength"||r.sampleCount!=MeasuredCalibration.RequiredSamples
            ||r.values==null||r.values.Length!=r.sampleCount||r.eventIds==null||r.eventIds.Length!=r.sampleCount
            ||r.deviceId!=action.DeviceId||r.family!=action.SensorDevice.ToString()||r.side!=action.BodySide.ToString()
            ||r.quantity!=action.Quantity||r.unit!=action.Unit||r.provenance!="dynamics_sdk"||action.Provenance!=r.provenance
            ||!action.IsValid||action.SourceType!=InputSourceType.Sensor||!SensorEventProcessor.Finite(r.baseline)||r.baseline<=0
            ||!SensorEventProcessor.Finite(action.RawValue)||action.RawValue<=0)return false;
        var unique=new HashSet<string>();
        foreach(string id in r.eventIds)if(string.IsNullOrWhiteSpace(id)||!unique.Add(id))return false;
        foreach(double v in r.values)if(!SensorEventProcessor.Finite(v)||v<=0)return false;
        double[] sorted=(double[])r.values.Clone();Array.Sort(sorted);
        if(Math.Abs(sorted[sorted.Length/2]-r.baseline)>1e-6*Math.Max(1,r.baseline))return false;
        double ratio=action.RawValue/r.baseline;if(!SensorEventProcessor.Finite(ratio))return false;
        relative=(float)Math.Min(2.5,ratio);return true;
    }
    public static PlayerActionEvent Apply(PlayerActionEvent action,string study,string directory,string sdkMode)
    {
        if(loadedStudy!=study||loadedDirectory!=directory){references.Clear();references.AddRange(Load(directory,study));loadedStudy=study;loadedDirectory=directory;}
        foreach(var r in references)
            if(r.sdkVersion=="0.25.6"&&r.sdkBuildMode==sdkMode&&TryNormalize(r,action,study,out float relative))
            { action.Power=relative;action.NormalizationValid=true;action.CalibrationId=r.calibrationId;return action; }
        return action;
    }
}

public static class PersonalGameplayBalance
{
    // Dimensionless game-balance choices, not clinical or biomechanical thresholds.
    public static float RequiredStrength(int level) => level<=1?.45f:level==2?.60f:.75f;
    public const float MaximumRelativeSignal=2.5f;
}
