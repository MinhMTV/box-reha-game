using System;
using UnityEngine;

/// <summary>Bounded, synchronized ring buffer. TryPop consumes each reading once.</summary>
public class SensorDataBuffer
{
    private readonly SensorReading[] buffer;
    private readonly object gate = new object();
    private int head;
    private int count;
    public int Count { get { lock (gate) return count; } }
    public int Capacity => buffer.Length;
    public int DroppedCount { get; private set; }

    public SensorDataBuffer(int capacity = 256)
    {
        if (capacity <= 0) throw new ArgumentOutOfRangeException(nameof(capacity));
        buffer = new SensorReading[capacity];
    }

    public void Push(SensorReading reading)
    {
        lock (gate)
        {
            buffer[head] = reading;
            head = (head + 1) % Capacity;
            if (count < Capacity) count++;
            else DroppedCount++;
        }
    }

    public bool TryPop(out SensorReading reading)
    {
        lock (gate)
        {
            reading = default;
            if (count == 0) return false;
            int index = (head - count + Capacity) % Capacity;
            reading = buffer[index];
            buffer[index] = default;
            count--;
            return true;
        }
    }

    public SensorReading GetLatest()
    {
        lock (gate) return count == 0 ? default : buffer[(head - 1 + Capacity) % Capacity];
    }

    public SensorReading[] GetLatest(int n)
    {
        lock (gate)
        {
            n = Math.Max(0, Math.Min(n, count));
            var result = new SensorReading[n];
            for (int i = 0; i < n; i++) result[i] = buffer[(head - n + i + Capacity) % Capacity];
            return result;
        }
    }

    public SensorReading[] GetAll() { lock (gate) return GetLatest(count); }
    public void Clear() { lock (gate) { Array.Clear(buffer, 0, Capacity); head = count = 0; } }
    public float GetAverageAccelerationMagnitude(int lastN)
    {
        SensorReading[] readings = GetLatest(lastN);
        float sum = 0f;
        foreach (SensorReading reading in readings) sum += reading.Acceleration.magnitude;
        return readings.Length == 0 ? 0f : sum / readings.Length;
    }
    public float GetPeakAccelerationMagnitude(int lastN)
    {
        float peak = 0f;
        foreach (SensorReading reading in GetLatest(lastN)) peak = Mathf.Max(peak, reading.Acceleration.magnitude);
        return peak;
    }
}
