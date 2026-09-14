using System;

internal static class Program
{
    private static int Main()
    {
        try
        {
            Console.WriteLine("HOST LOGIC TESTS: narrow Unity API stubs; not a Unity compile or physical sensor test.");
            SensorRegressionChecks.RunAll();
            KeyboardProviderEmitsOncePerPress();
            RingBufferSurvivesConcurrentProducerConsumer();
            RouterDoesNotSilentlyFallback();
            Console.WriteLine("HOST_ADDITIONAL_PASS 3 checks (provider key transitions, concurrent buffer, explicit routing).");
            GameplayHostChecks.Run();
            LoggerHostCheck.Run();
            HistoryHostCheck.Run();
            AndroidPolicyHostChecks.Run();
            CalibrationHostChecks.Run();
            return 0;
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine(ex);
            return 1;
        }
    }

    private static void KeyboardProviderEmitsOncePerPress()
    {
        var provider = new MouseTouchInputProvider { IsEnabled = true };
        int count = 0;
        provider.OnActionDetected += action => count++;
        UnityEngine.Input.DownKeys.Add(UnityEngine.KeyCode.LeftArrow);
        provider.UpdateInput(); provider.UpdateInput();
        if (count != 1) throw new Exception("One frame dispatched more than one keyboard event.");
        UnityEngine.Input.DownKeys.Clear();
        UnityEngine.Time.frameCount++;
        provider.UpdateInput();
        if (count != 1) throw new Exception("Key release produced an extra action.");
        provider.IsEnabled = false;
        UnityEngine.Input.DownKeys.Add(UnityEngine.KeyCode.RightArrow);
        UnityEngine.Time.frameCount++;
        provider.UpdateInput();
        UnityEngine.Input.DownKeys.Clear();
        provider.IsEnabled = true;
        UnityEngine.Time.frameCount++;
        provider.UpdateInput();
        if (count != 1) throw new Exception("Disabled keyboard press replayed after resume.");
    }

    private static void RingBufferSurvivesConcurrentProducerConsumer()
    {
        var buffer = new SensorDataBuffer(64);
        var seen = new System.Collections.Generic.HashSet<long>();
        var producer = System.Threading.Tasks.Task.Run(() => {
            for (long sequence = 0; sequence < 10000; sequence++)
                buffer.Push(new SensorReading { Sequence = sequence });
        });
        while (!producer.IsCompleted || buffer.Count > 0)
        {
            if (buffer.TryPop(out SensorReading reading) && !seen.Add(reading.Sequence))
                throw new Exception("Concurrent buffer emitted a duplicate.");
        }
        producer.GetAwaiter().GetResult();
        if (seen.Count + buffer.DroppedCount != 10000 || buffer.Count != 0)
            throw new Exception("Concurrent buffer accounting lost a reading.");
    }

    private static void RouterDoesNotSilentlyFallback()
    {
        var router = new InputProviderRouter();
        var fields = System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.NonPublic;
        var select = typeof(InputProviderRouter).GetMethod("SelectProvider", fields);
        typeof(InputProviderRouter).GetField("mouseTouchInputProvider", fields).SetValue(router, new MouseTouchInputProvider());
        if (select.Invoke(router, new object[] { InputSourceType.Sensor }) != null)
            throw new Exception("Missing sensor silently fell back to keyboard.");
        typeof(InputProviderRouter).GetField("mouseTouchInputProvider", fields).SetValue(router, null);
        typeof(InputProviderRouter).GetField("bleSensorInputProvider", fields).SetValue(router, new BleSensorInputProvider());
        if (select.Invoke(router, new object[] { InputSourceType.Keyboard }) != null)
            throw new Exception("Missing keyboard silently fell back to sensor.");
        router.IsEnabled = true;
        var allows = typeof(InputProviderRouter).GetMethod("AllowsInput", fields);
        GameManager.Instance = new GameManager { CurrentState = GameState.Menu };
        if ((bool)allows.Invoke(router, null)) throw new Exception("Router accepts actions in menu.");
        GameManager.Instance.CurrentState = GameState.Playing;
        if (!(bool)allows.Invoke(router, null)) throw new Exception("Router rejects playing state.");
        GameManager.Instance.CurrentState = GameState.Paused;
        if ((bool)allows.Invoke(router, null)) throw new Exception("Router accepts paused action.");
        GameManager.Instance = null;
    }
}
