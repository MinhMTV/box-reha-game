using UnityEngine;
using System;

/// <summary>
/// Phase 3: Stub BLE sensor input provider.
/// Implements IPlayerActionInputProvider for future BLE glove/sensor integration.
/// Currently logs "BLE not connected" when used.
/// 
/// To use: attach to InputManager GameObject, set as the input provider in GameRoundController.
/// When BLE is available, this will translate sensor data into PlayerActionEvents.
/// </summary>
public class BleSensorInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event Action<PlayerActionEvent> OnActionDetected;
    public bool IsEnabled { get; set; }

    [SerializeField] private string deviceId = "default_sensor";

    private bool isConnected;

    void Start()
    {
        Debug.Log("[BleSensorInputProvider] BLE sensor not connected. Stub implementation active.");
        isConnected = false;
    }

    void Update()
    {
        if (!IsEnabled) return;
        UpdateInput();
    }

    public void UpdateInput()
    {
        if (!isConnected)
        {
            // Stub: log once per second max
            if (Time.frameCount % 60 == 0)
            {
                Debug.Log("[BleSensorInputProvider] Waiting for BLE connection...");
            }
            return;
        }

        // Future: Read from ISensorDataProvider, classify gestures, emit PlayerActionEvents
        // Example classification:
        // - Sharp acceleration spike → Punch
        // - Sustained high acceleration → Block
        // - Lateral gyroscope spike → Dodge
    }

    /// <summary>
    /// Called when BLE device connects. Future implementation.
    /// </summary>
    public void OnSensorConnected()
    {
        isConnected = true;
        Debug.Log($"[BleSensorInputProvider] Sensor connected: {deviceId}");
    }

    /// <summary>
    /// Called when BLE device disconnects. Future implementation.
    /// </summary>
    public void OnSensorDisconnected()
    {
        isConnected = false;
        Debug.Log($"[BleSensorInputProvider] Sensor disconnected: {deviceId}");
    }

    void OnDestroy()
    {
        if (isConnected)
        {
            OnSensorDisconnected();
        }
    }
}
