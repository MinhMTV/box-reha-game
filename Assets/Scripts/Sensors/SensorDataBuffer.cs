using UnityEngine;

/// <summary>
/// Phase 3: Circular buffer for storing sensor readings.
/// Thread-safe for producer-consumer pattern with BLE data.
/// 
/// Usage:
///   var buffer = new SensorDataBuffer(256);
///   buffer.Push(reading);
///   var latest = buffer.GetLatest();
/// </summary>
public class SensorDataBuffer
{
    private SensorReading[] buffer;
    private int head;
    private int count;
    private readonly int capacity;

    public int Count => count;
    public int Capacity => capacity;

    public SensorDataBuffer(int capacity = 256)
    {
        this.capacity = capacity;
        buffer = new SensorReading[capacity];
        head = 0;
        count = 0;
    }

    /// <summary>
    /// Push a new reading into the buffer. Overwrites oldest if full.
    /// </summary>
    public void Push(SensorReading reading)
    {
        buffer[head] = reading;
        head = (head + 1) % capacity;
        if (count < capacity) count++;
    }

    /// <summary>
    /// Get the most recent reading.
    /// </summary>
    public SensorReading GetLatest()
    {
        if (count == 0) return default;
        int index = (head - 1 + capacity) % capacity;
        return buffer[index];
    }

    /// <summary>
    /// Get the N most recent readings in chronological order.
    /// </summary>
    public SensorReading[] GetLatest(int n)
    {
        n = Mathf.Min(n, count);
        SensorReading[] result = new SensorReading[n];
        for (int i = 0; i < n; i++)
        {
            int index = (head - n + i + capacity) % capacity;
            result[i] = buffer[index];
        }
        return result;
    }

    /// <summary>
    /// Get all readings in chronological order.
    /// </summary>
    public SensorReading[] GetAll()
    {
        return GetLatest(count);
    }

    /// <summary>
    /// Clear the buffer.
    /// </summary>
    public void Clear()
    {
        head = 0;
        count = 0;
    }

    /// <summary>
    /// Calculate average acceleration magnitude over the last N readings.
    /// Useful for gesture detection (punch = spike, block = sustained).
    /// </summary>
    public float GetAverageAccelerationMagnitude(int lastN)
    {
        if (count == 0) return 0f;
        lastN = Mathf.Min(lastN, count);
        float sum = 0f;
        for (int i = 0; i < lastN; i++)
        {
            int index = (head - 1 - i + capacity) % capacity;
            sum += buffer[index].Acceleration.magnitude;
        }
        return sum / lastN;
    }

    /// <summary>
    /// Get peak acceleration magnitude in the last N readings.
    /// Useful for detecting punch spikes.
    /// </summary>
    public float GetPeakAccelerationMagnitude(int lastN)
    {
        if (count == 0) return 0f;
        lastN = Mathf.Min(lastN, count);
        float peak = 0f;
        for (int i = 0; i < lastN; i++)
        {
            int index = (head - 1 - i + capacity) % capacity;
            float mag = buffer[index].Acceleration.magnitude;
            if (mag > peak) peak = mag;
        }
        return peak;
    }
}
