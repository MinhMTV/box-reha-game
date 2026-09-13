package com.boxreha.dynamics;

import com.unity3d.player.UnityPlayer;

/** Stable JNI facade. All SDK work and lifecycle ownership live in DynamicsCollector. */
public final class DynamicsUnityBridge {
    private static final String UNITY_BRIDGE_OBJECT = "DynamicsSdkBridge";

    private DynamicsUnityBridge() {
    }

    public static void initialize() { DynamicsCollector.initialize(); }
    public static void requestPermissions() { DynamicsCollector.requestPermissions(); }
    public static void selectParticipant(String studyId) { DynamicsCollector.selectParticipant(studyId); }
    public static void startScan() { DynamicsCollector.startScan(); }
    public static void stopScan() { DynamicsCollector.stopScan(); }
    public static void pair(String nearbyId, String side) { DynamicsCollector.pair(nearbyId, side); }
    public static void unpair(String deviceId) { DynamicsCollector.unpair(deviceId); }
    public static void setBodyProfile(String studyId, double weightKg, double heightCm, String gender) {
        DynamicsCollector.setBodyProfile(studyId, weightKg, heightCm, gender);
    }
    public static void startSession(String family) { DynamicsCollector.startSession(family); }
    public static void startSession(String family, String requestId) { DynamicsCollector.startSession(family, requestId); }
    public static void pauseSession() { DynamicsCollector.pauseSession(); }
    public static void resumeSession() { DynamicsCollector.resumeSession(); }
    public static void resumeSession(String requestId) { DynamicsCollector.resumeSession(requestId); }
    public static void finishSession() { DynamicsCollector.finishSession(); }
    public static void setApplicationPaused(boolean paused) { DynamicsCollector.setApplicationPaused(paused); }
    public static void shutdown() { DynamicsCollector.shutdown(); }

    public static void sendNativeStatus(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceiveNativeStatusJson", json);
    }

    public static void sendSensorData(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceiveSensorDataJson", json);
    }

    public static void sendPunch(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceivePunchJson", json);
    }

    public static void sendDeviceState(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceiveDeviceStateJson", json);
    }
}
