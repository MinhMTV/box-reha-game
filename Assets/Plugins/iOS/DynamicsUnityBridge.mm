#import <Foundation/Foundation.h>

extern "C" void UnitySendMessage(const char *obj, const char *method, const char *msg);

extern "C" void DynamicsUnityBridgeSendSensorData(const char *json)
{
    UnitySendMessage("DynamicsSdkBridge", "ReceiveSensorDataJson", json != NULL ? json : "");
}

extern "C" void DynamicsUnityBridgeSendPunch(const char *json)
{
    UnitySendMessage("DynamicsSdkBridge", "ReceivePunchJson", json != NULL ? json : "");
}
