# Dynamics SDK Unity Bridge

This project now has a Unity-side endpoint for RISE Dynamics SDK data.

Unity GameObject:

```text
DynamicsSdkBridge
```

Callable methods:

```text
ReceiveSensorDataJson(string json)
ReceivePunchJson(string json)
```

Android helper:

```java
com.boxreha.dynamics.DynamicsUnityBridge.sendSensorData(json);
com.boxreha.dynamics.DynamicsUnityBridge.sendPunch(json);
```

iOS helper:

```objc
DynamicsUnityBridgeSendSensorData(json);
DynamicsUnityBridgeSendPunch(json);
```

Sensor JSON:

```json
{
  "sensorType": "Alpha",
  "bodySide": "Left",
  "deviceId": "alpha_left",
  "timestamp": 0,
  "ax": 0,
  "ay": 0,
  "az": 0,
  "gx": 0,
  "gy": 0,
  "gz": 0,
  "impactForce": 0,
  "powerIndex": 0
}
```

Punch JSON:

```json
{
  "sensorType": "Delta",
  "bodySide": "Right",
  "deviceId": "delta_right",
  "timestamp": 0,
  "impact": 0,
  "peakForce": 0,
  "powerIndex": 0,
  "peakAcceleration": 0
}
```

SDK mapping found in the local docs:

- `SensorDataRepository.observeSensorData(...)` / `observeSensorDataNative(...)` emits `Flow<List<SensorDataPacket>>`.
- `SensorDataPacket` contains `accData`, `gyroData`, `magnetoData`, `baroData`, `samplingRate`, and `relativeTimeCounter`.
- `Punch.power` is a sealed type:
  - `Power.Alpha` exposes `impact` and `peakForceBasedOnBaro`.
  - `Power.Delta` exposes `powerIndex`.

The remaining native task is to collect the SDK flows on Android/iOS and call the helper methods above.
