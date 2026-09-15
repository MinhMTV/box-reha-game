/// <summary>Acquisition adapters submit original identity/evidence to the shared validation queues.
/// Availability of this interface does not enable any unqualified native acquisition route.</summary>
public interface ISensorReadingSink
{
    bool SetDeviceConnection(string deviceId, string connectionId, SensorDeviceType family,
        BodySide side, string provenance, bool connected);
    bool PushSensorReading(SensorReading reading);
    void ForgetDevice(string deviceId, string connectionId);
}
