package com.unity3d.player;

/** Compile-only boundary for the standalone collector check. Never package in an APK. */
public final class UnityPlayer {
    public static android.app.Activity currentActivity;
    public static void UnitySendMessage(String objectName, String methodName, String message) {
        throw new UnsupportedOperationException("Compile-only Unity boundary; no Unity runtime available");
    }
}
