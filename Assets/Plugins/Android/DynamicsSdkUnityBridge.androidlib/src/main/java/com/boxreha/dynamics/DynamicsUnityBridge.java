package com.boxreha.dynamics;

import com.unity3d.player.UnityPlayer;

/**
 * Tiny Android endpoint used by native Dynamics SDK code.
 * The actual SDK collector can call these methods after mapping SDK models to JSON.
 */
public final class DynamicsUnityBridge {
    private static final String UNITY_BRIDGE_OBJECT = "DynamicsSdkBridge";

    private DynamicsUnityBridge() {
    }

    public static void sendSensorData(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceiveSensorDataJson", json);
    }

    public static void sendPunch(String json) {
        UnityPlayer.UnitySendMessage(UNITY_BRIDGE_OBJECT, "ReceivePunchJson", json);
    }
}
