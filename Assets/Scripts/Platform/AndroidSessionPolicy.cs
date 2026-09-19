using System;

[Serializable]
public class AndroidNativeDevice
{
    public string id, name, side, family, connectionId, firmwareVersion;
    public bool online, isMock;
}
[Serializable]
public class AndroidNearbyDevice { public string id, name, family; }
[Serializable]
public class AndroidNativeStatus
{
    public int schemaVersion;
    public long statusSequence;
    public double emittedAndroidMonotonicSeconds;
    public string state, code, message, sessionState;
    public string sdkVersion, sdkBuildMode, profileReference, profileStudyId, sessionFamily;
    public string controlRequestId;
    public bool profileReady, initialized, permissionsGranted, hasActiveSession, deviceMutation;
    public AndroidNativeDevice[] devices;
    public AndroidNearbyDevice[] nearby;
}

/// <summary>Fail-closed checks of reported SDK state; this is not physical hardware qualification.</summary>
public static class AndroidSessionPolicy
{
    public const double StatusTimeoutSeconds = 3.0;
    public static bool TryTransportAge(double emittedAt, double androidNow, out double age)
    {
        age = double.NaN;
        if (double.IsNaN(emittedAt) || double.IsInfinity(emittedAt) || emittedAt <= 0
            || double.IsNaN(androidNow) || double.IsInfinity(androidNow) || androidNow < emittedAt) return false;
        age = androidNow - emittedAt;
        return true;
    }
    public static bool StatusIsFresh(double receivedAt, double now)
    {
        return !double.IsNaN(receivedAt) && !double.IsInfinity(receivedAt)
            && !double.IsNaN(now) && !double.IsInfinity(now)
            && now >= receivedAt && now - receivedAt <= StatusTimeoutSeconds;
    }
    public static bool CanPrepare(AndroidNativeStatus status, string family, out string reason)
    {
        reason = null;
        if (status == null || status.schemaVersion != 1) reason = "Initialize the Android SDK first.";
        else if (!status.initialized) reason = "Initialize the Android SDK first.";
        else if (!status.permissionsGranted) reason = "Grant the required Android Bluetooth permissions.";
        else if (status.state == "error" || status.sessionState == "error") reason = status.message ?? "SDK error; resolve it before starting.";
        else if (!status.profileReady) reason = "Enter the required SDK body profile for this participant.";
        else if (family != "Alpha" && family != "Delta") reason = "Select Alpha punches or Delta kick mapping.";
        if (reason != null) return false;
        int left = 0, right = 0, count = 0;
        string firstId = null;
        foreach (AndroidNativeDevice device in status.devices ?? Array.Empty<AndroidNativeDevice>())
        {
            if (device == null) { reason = "Invalid device status."; return false; }
            if (device.isMock) { reason = "SDK mock devices cannot start a physical session."; return false; }
            if (device.family != family) { reason = string.IsNullOrEmpty(device.family) || device.family == "Unknown"
                ? (device.name ?? "Device") + " / " + device.side + ": family not resolved. Reconnect or remove this device, then scan again."
                : (device.name ?? "Device") + " / " + device.side + ": reports " + device.family + "; selected " + family + ". Select the matching mode. ALPHA + DELTA combined mode is not qualified."; return false; }
            if (!device.online || string.IsNullOrWhiteSpace(device.id) || string.IsNullOrWhiteSpace(device.connectionId))
            { reason = "Every selected device must report an active connection."; return false; }
            if (device.id == firstId) { reason = "Duplicate device identity."; return false; }
            firstId = device.id;
            if (device.side == "Left") left++;
            else if (device.side == "Right") right++;
            count++;
        }
        if (count < 1 || count > 2 || left > 1 || right > 1 || left + right != count)
            reason = "Pair one device or one left/right pair from the same family, with an explicit physical side.";
        return reason == null;
    }

    public static LaneType[] ConnectedLanes(AndroidNativeStatus status, string family)
    {
        if (!CanPrepare(status, family, out string reason)) throw new InvalidOperationException(reason);
        LaneType[] lanes = new LaneType[status.devices.Length];
        for (int i = 0; i < lanes.Length; i++) lanes[i] = status.devices[i].side == "Left" ? LaneType.Left : LaneType.Right;
        return lanes;
    }

    public static string Topology(AndroidNativeStatus status)
    {
        if (status?.devices == null) return "";
        string[] identities = new string[status.devices.Length];
        for (int i = 0; i < identities.Length; i++)
        {
            AndroidNativeDevice device = status.devices[i];
            identities[i] = device == null ? "invalid" : device.id + "/" + device.family + "/" + device.side;
        }
        Array.Sort(identities, StringComparer.Ordinal);
        return string.Join(";", identities);
    }

    public static bool ValidBodyProfile(double weight, double height, string gender)
    {
        return !double.IsNaN(weight) && !double.IsInfinity(weight) && weight >= 20 && weight <= 250
            && !double.IsNaN(height) && !double.IsInfinity(height) && height >= 50 && height <= 250
            && (gender == "MALE" || gender == "FEMALE");
    }

    /// <summary>
    /// The single sensor family reported by the SDK for the devices that are actually connected, or
    /// null when it is not unambiguous (nothing connected, family not yet reported, or mixed).
    /// Never guesses and never falls back to Alpha.
    /// </summary>
    public static string ConnectedFamily(AndroidNativeStatus status)
    {
        if (status?.devices == null) return null;
        string family = null;
        foreach (AndroidNativeDevice device in status.devices)
        {
            if (device == null || device.isMock || !device.online) continue;
            if (device.family != "Alpha" && device.family != "Delta") return null;
            if (family == null) family = device.family;
            else if (family != device.family) return null;
        }
        return family;
    }

    public static bool AcceptsRunningAck(AndroidNativeStatus status, string requestId, string studyId, string family)
    {
        return !string.IsNullOrWhiteSpace(requestId) && !string.IsNullOrWhiteSpace(studyId)
            && CanPrepare(status, family, out _) && status.controlRequestId == requestId
            && status.profileStudyId == studyId && !string.IsNullOrWhiteSpace(status.profileReference)
            && status.sessionState == "running" && status.sessionFamily == family;
    }
}

[Serializable]
public class AndroidAcquisitionDevice
{
    public string deviceId, connectionId, family, side, firmwareVersion;
    public bool online, isMock;
}
[Serializable]
public class AndroidAcquisitionSnapshot
{
    public string platform = "Android", source = "physical_sensor";
    public string requestedFamily, effectiveFamily, sdkVersion, sdkSessionState, profileReference, profileStudyId;
    public bool initialized, permissionsGranted, profileReady;
    public AndroidAcquisitionDevice[] devices;
}

/// <summary>Transient operator choice, independent of serialized development GameConfig.</summary>
public static class SessionInputSelection
{
#if UNITY_ANDROID && !UNITY_EDITOR
    public static InputSourceType? Override = InputSourceType.Sensor;
#else
    public static InputSourceType? Override;
#endif
    public static bool Physical => Override == InputSourceType.Sensor;

    // The operator's explicit pick, or null while the connected hardware decides.
    private static string explicitFamily;
    private static string resolvedFamily;

    /// <summary>
    /// The family actually used. A DELTA-only setup never falls back to ALPHA: the SDK-reported family
    /// of the connected devices wins over any earlier operator pick.
    /// </summary>
    public static string Family
    {
        get { return explicitFamily ?? resolvedFamily; }
        set { explicitFamily = value; }
    }

    /// <summary>True while the family comes from connected hardware rather than an operator pick.</summary>
    public static bool FamilyResolvedFromHardware => explicitFamily == null;

    /// <summary>Called on every fresh native status so the selection tracks the real hardware.</summary>
    public static void SyncFromStatus(AndroidNativeStatus status)
    {
        string detected = AndroidSessionPolicy.ConnectedFamily(status);
        if (detected == null) return;
        resolvedFamily = detected;
        if (explicitFamily != null && explicitFamily != detected) explicitFamily = null;
    }

    public static string Label => Physical ? "Android physical / " + Family : "Development keyboard / pointer";
}
