using System;

/// <summary>Independent physiological channel contract. No device adapter or adaptation is activated.</summary>
[Serializable]
public struct HRSample
{
    public string EventId;
    public string DeviceId;
    public string Provenance;
    public double SourceTimestamp;
    public string SourceClock;
    public double ReceivedTimestamp;
    public double SourceAgeSeconds;
    public float BeatsPerMinute;
    public bool IsValid;
}

public interface IHeartRateProvider
{
    bool IsConnected { get; }
    event Action<HRSample> OnSample;
}

/// <summary>Engineering validation only; no clinical targets or intensity prescription.</summary>
public static class HeartRateSampleValidator
{
    public static bool IsFresh(HRSample sample, double now, double maximumAgeSeconds = 5,
        bool allowMock = false)
    {
        if (!sample.IsValid || string.IsNullOrWhiteSpace(sample.EventId) || string.IsNullOrWhiteSpace(sample.DeviceId))
            return false;
        if (sample.Provenance != "heart_rate_sensor" && !(allowMock && sample.Provenance == "hr_mock"))
            return false;
        if (sample.SourceClock != "unix_seconds" || !SensorEventProcessor.Finite(sample.SourceTimestamp)
            || sample.SourceTimestamp <= 0) return false;
        if (!SensorEventProcessor.Finite(sample.BeatsPerMinute) || sample.BeatsPerMinute <= 0
            || sample.BeatsPerMinute > 300) return false; // Broad encoding sanity bound, not a training zone.
        return SensorEventProcessor.Finite(now) && SensorEventProcessor.Finite(sample.ReceivedTimestamp)
            && SensorEventProcessor.Finite(sample.SourceAgeSeconds) && sample.SourceAgeSeconds >= 0
            && SensorEventProcessor.Finite(maximumAgeSeconds) && maximumAgeSeconds >= 0
            && now >= sample.ReceivedTimestamp
            && sample.SourceAgeSeconds + now - sample.ReceivedTimestamp <= maximumAgeSeconds;
    }
}
