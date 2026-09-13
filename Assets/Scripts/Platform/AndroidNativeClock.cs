using System;
using UnityEngine;

/// <summary>Measures JNI delivery age in Android's own monotonic clock; never compares absolute Unity/Android clocks.</summary>
public static class AndroidNativeClock
{
    public static bool IsDeviceRuntime
    {
        get {
#if UNITY_ANDROID && !UNITY_EDITOR
            return true;
#else
            return false;
#endif
        }
    }
    public static bool TryTransportAge(double emittedAndroidSeconds, out double ageSeconds)
    {
        ageSeconds = double.NaN;
#if UNITY_ANDROID && !UNITY_EDITOR
        try
        {
            using (AndroidJavaClass clock = new AndroidJavaClass("android.os.SystemClock"))
            {
                double now = clock.CallStatic<long>("elapsedRealtimeNanos") / 1000000000.0;
                return AndroidSessionPolicy.TryTransportAge(emittedAndroidSeconds, now, out ageSeconds);
            }
        }
        catch (Exception) { return false; }
#else
        return false;
#endif
    }
}
