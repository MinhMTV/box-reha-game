using System;

/// <summary>
/// Phase 3: Interface for raw sensor data from BLE/IMU devices.
/// Implement this to provide sensor-based input to the game.
/// </summary>
public interface ISensorDataProvider
{
    /// <summary>
    /// Fired when new sensor data is available.
    /// </summary>
    event Action<SensorReading> OnDataReceived;

    /// <summary>
    /// Whether the sensor is currently connected and providing data.
    /// </summary>
    bool IsConnected { get; }

    /// <summary>
    /// Attempt to connect to the sensor device.
    /// </summary>
    void Connect();

    /// <summary>
    /// Disconnect from the sensor device.
    /// </summary>
    void Disconnect();

    /// <summary>
    /// Get the latest sensor reading.
    /// </summary>
    SensorReading GetLatestReading();
}

/// <summary>
/// Represents a single sensor reading from an IMU or similar device.
/// </summary>
[System.Serializable]
public struct SensorReading
{
    /// <summary>Acceleration vector (m/s²)</summary>
    public UnityEngine.Vector3 Acceleration;

    /// <summary>Gyroscope angular velocity (rad/s)</summary>
    public UnityEngine.Vector3 Gyroscope;

    /// <summary>Timestamp of the reading (seconds since start)</summary>
    public double Timestamp;

    /// <summary>Device identifier (e.g., "left_hand", "right_hand")</summary>
    public string DeviceId;
}
