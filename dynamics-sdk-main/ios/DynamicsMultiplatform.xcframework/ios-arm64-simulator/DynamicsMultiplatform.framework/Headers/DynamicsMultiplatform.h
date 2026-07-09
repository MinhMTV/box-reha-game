#import <Foundation/NSArray.h>
#import <Foundation/NSDictionary.h>
#import <Foundation/NSError.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <Foundation/NSValue.h>

@class CBPeripheral, DynamicsMultiplatformAccStreamData, DynamicsMultiplatformActiveTrainingSessionInputSecondary, DynamicsMultiplatformActiveTrainingSessionInputSecondaryCompanion, DynamicsMultiplatformAdvertisingConfigOption, DynamicsMultiplatformAllAdvertisingConfigs, DynamicsMultiplatformAllAdvertisingConfigsCompanion, DynamicsMultiplatformAllDeepSleepWakeUpConfigs, DynamicsMultiplatformAllDeepSleepWakeUpConfigsCompanion, DynamicsMultiplatformAllImpactConfigs, DynamicsMultiplatformAllOperationalConfigs, DynamicsMultiplatformAllOperationalConfigsCompanion, DynamicsMultiplatformAlpha, DynamicsMultiplatformAmPmMarker, DynamicsMultiplatformAntilog, DynamicsMultiplatformAppInfo, DynamicsMultiplatformBasicValidationAboveMax, DynamicsMultiplatformBasicValidationBelowMin, DynamicsMultiplatformBasicValidationInvalidFormat, DynamicsMultiplatformBasicValidationMissing, DynamicsMultiplatformBasicValidationOk, DynamicsMultiplatformBatteryChargeLevel, DynamicsMultiplatformBatteryChargeState, DynamicsMultiplatformBestPunch, DynamicsMultiplatformBestPunchCategory, DynamicsMultiplatformBestPunchCompanion, DynamicsMultiplatformBleError, DynamicsMultiplatformBleErrorBondRemoval, DynamicsMultiplatformBleErrorOperation, DynamicsMultiplatformBleException, DynamicsMultiplatformBleGloveState, DynamicsMultiplatformBleGloveStateOffline, DynamicsMultiplatformBleGloveStateOnline, DynamicsMultiplatformBleHeader, DynamicsMultiplatformBleHeaderCompanion, DynamicsMultiplatformBleHeaderSingle, DynamicsMultiplatformBleHeaderStartCompanion, DynamicsMultiplatformBleMultiplexLogMessage, DynamicsMultiplatformBleMultiplexLogMessageIOOperationRequest, DynamicsMultiplatformBleMultiplexLogMessageObserveOperation, DynamicsMultiplatformBleMultiplexLogMessagePlainMessage, DynamicsMultiplatformBleMultiplexLogMessageRssiRequest, DynamicsMultiplatformBleMultiplexLogMessageWithAddress, DynamicsMultiplatformBleOperationType, DynamicsMultiplatformBlePacket, DynamicsMultiplatformBleRequirements, DynamicsMultiplatformBleRequirementsState, DynamicsMultiplatformBle_multiplexBleScope, DynamicsMultiplatformBle_multiplex_uuidBleUuid, DynamicsMultiplatformBle_multiplex_uuidVersion, DynamicsMultiplatformBluetoothException, DynamicsMultiplatformBodyProfile, DynamicsMultiplatformBodyProfileCompanion, DynamicsMultiplatformBodyProfileValidation, DynamicsMultiplatformBodyProfileValidationCompanion, DynamicsMultiplatformBodyProfileValidationException, DynamicsMultiplatformBondState, DynamicsMultiplatformBondingSettings, DynamicsMultiplatformCRCResult, DynamicsMultiplatformCapCombination, DynamicsMultiplatformCapOptions, DynamicsMultiplatformCapShape, DynamicsMultiplatformCapShapeCompanion, DynamicsMultiplatformCapShapeMeta, DynamicsMultiplatformChargingFaultReason, DynamicsMultiplatformChargingType, DynamicsMultiplatformCoreAdvertisement, DynamicsMultiplatformCoreBluetoothState, DynamicsMultiplatformCoreBondState, DynamicsMultiplatformCoreLocationState, DynamicsMultiplatformCoreLocationStateCompanion, DynamicsMultiplatformCoreManufacturerData, DynamicsMultiplatformCorePermissionState, DynamicsMultiplatformDataPacket, DynamicsMultiplatformDataPacketCompanion, DynamicsMultiplatformDataPipePacket, DynamicsMultiplatformDataPipePacketDataPipeProtocol, DynamicsMultiplatformDataPipePacketRaw, DynamicsMultiplatformDateBasedDateTimeUnitSerializer, DynamicsMultiplatformDatePeriod, DynamicsMultiplatformDatePeriodCompanion, DynamicsMultiplatformDatePeriodComponentSerializer, DynamicsMultiplatformDatePeriodIso8601Serializer, DynamicsMultiplatformDateTimeComponents, DynamicsMultiplatformDateTimeComponentsCompanion, DynamicsMultiplatformDateTimeComponentsFormats, DynamicsMultiplatformDateTimeFormatCompanion, DynamicsMultiplatformDateTimePeriod, DynamicsMultiplatformDateTimePeriodCompanion, DynamicsMultiplatformDateTimePeriodComponentSerializer, DynamicsMultiplatformDateTimePeriodIso8601Serializer, DynamicsMultiplatformDateTimeUnit, DynamicsMultiplatformDateTimeUnitCompanion, DynamicsMultiplatformDateTimeUnitDateBased, DynamicsMultiplatformDateTimeUnitDateBasedCompanion, DynamicsMultiplatformDateTimeUnitDayBased, DynamicsMultiplatformDateTimeUnitDayBasedCompanion, DynamicsMultiplatformDateTimeUnitMonthBased, DynamicsMultiplatformDateTimeUnitMonthBasedCompanion, DynamicsMultiplatformDateTimeUnitSerializer, DynamicsMultiplatformDateTimeUnitTimeBased, DynamicsMultiplatformDateTimeUnitTimeBasedCompanion, DynamicsMultiplatformDayBasedDateTimeUnitSerializer, DynamicsMultiplatformDayOfWeek, DynamicsMultiplatformDayOfWeekNames, DynamicsMultiplatformDayOfWeekNamesCompanion, DynamicsMultiplatformDayOfWeekSerializer, DynamicsMultiplatformDeepSleepWakeUpAccConfig, DynamicsMultiplatformDeepSleepWakeUpAccConfigCompanion, DynamicsMultiplatformDeepSleepWakeUpConfigOption, DynamicsMultiplatformDeepSleepWakeUpConfiguration, DynamicsMultiplatformDeepSleepWakeUpConfigurationCompanion, DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc, DynamicsMultiplatformDelta, DynamicsMultiplatformDeviceInfo, DynamicsMultiplatformDeviceInfo_, DynamicsMultiplatformDynamicsContext, DynamicsMultiplatformDynamicsContextObserver, DynamicsMultiplatformDynamicsDbError, DynamicsMultiplatformDynamicsOpError, DynamicsMultiplatformDynamicsOpException, DynamicsMultiplatformDynamicsSettings, DynamicsMultiplatformDynamicsSettingsCompanion, DynamicsMultiplatformDynamicsTestOptions, DynamicsMultiplatformDynamicsTestOptionsCompanion, DynamicsMultiplatformDynamics_bleGloveManager, DynamicsMultiplatformDynamics_bleGloveManagerCompanion, DynamicsMultiplatformDynamics_bleGloveOptions, DynamicsMultiplatformDynamics_bleGlovePeripheralServices, DynamicsMultiplatformDynamics_bleGlovePeripheralServicesCompanion, DynamicsMultiplatformDynamics_dbDatabase, DynamicsMultiplatformDynamics_dbDatabaseCompanion, DynamicsMultiplatformDynamics_dbGloveModeGenericNullable<T>, DynamicsMultiplatformDynamics_utilsNanoSeconds, DynamicsMultiplatformDynamics_utilsSamplingRateMark, DynamicsMultiplatformDynamics_utilsSamplingRateMarkCompanion, DynamicsMultiplatformExportRepository, DynamicsMultiplatformExtendedDeviceInfo, DynamicsMultiplatformFinishedTrainingSession, DynamicsMultiplatformFinishedTrainingSessionRepository, DynamicsMultiplatformFinishedTrainingSessionStats, DynamicsMultiplatformFinishedTrainingSessionWithPunchIdsAndStats, DynamicsMultiplatformFinishedTrainingSessionWithStats, DynamicsMultiplatformFirmwareImage, DynamicsMultiplatformFirmwareImageManifest, DynamicsMultiplatformFirmwareImageMeta, DynamicsMultiplatformFirmwareImageSettings, DynamicsMultiplatformFirmwareUpdateExtensions, DynamicsMultiplatformFirmwareUpdateMode, DynamicsMultiplatformFirmwareUpdateRepository, DynamicsMultiplatformFixedOffsetTimeZone, DynamicsMultiplatformFixedOffsetTimeZoneCompanion, DynamicsMultiplatformFixedOffsetTimeZoneSerializer, DynamicsMultiplatformGattStatusException, DynamicsMultiplatformGender, DynamicsMultiplatformGlove, DynamicsMultiplatformGloveBattery, DynamicsMultiplatformGloveConfigurationRepository, DynamicsMultiplatformGloveConnectionError, DynamicsMultiplatformGloveConnectionErrorBondLost, DynamicsMultiplatformGloveConnectionErrorMissingRequirements, DynamicsMultiplatformGloveData, DynamicsMultiplatformGloveMode, DynamicsMultiplatformGloveModeDto, DynamicsMultiplatformGlovePair, DynamicsMultiplatformGlovePairCompatibility, DynamicsMultiplatformGlovePairCompatibilityEquipmentIncompatible, DynamicsMultiplatformGlovePairCompatibilityOffline, DynamicsMultiplatformGlovePairCompatibilityOk, DynamicsMultiplatformGlovePairCompatibilityOneGloveOnly, DynamicsMultiplatformGlovePairCompatibilityOneSideOffline, DynamicsMultiplatformGlovePairCompatibilityStatus, DynamicsMultiplatformGlovePairCompatibilityStatusError, DynamicsMultiplatformGlovePairCompatibilityStatusOk, DynamicsMultiplatformGlovePairCompatibilityStatusWarning, DynamicsMultiplatformGlovePairDto, DynamicsMultiplatformGloveRepository, DynamicsMultiplatformGloveRepositoryCompanion, DynamicsMultiplatformGloveTime, DynamicsMultiplatformGloveWithSensorData, DynamicsMultiplatformGloveWithThroughputTest, DynamicsMultiplatformHttpClientLogLevel, DynamicsMultiplatformIOException, DynamicsMultiplatformImpactConfigOption, DynamicsMultiplatformImpactDataPacket, DynamicsMultiplatformImpactDataPacketReason, DynamicsMultiplatformImpactDataTransmission, DynamicsMultiplatformImpactHeader, DynamicsMultiplatformImpactHeaderCompanion, DynamicsMultiplatformIncompatible, DynamicsMultiplatformKableState, DynamicsMultiplatformKableStateConnected, DynamicsMultiplatformKableStateConnecting, DynamicsMultiplatformKableStateConnectingBluetooth, DynamicsMultiplatformKableStateConnectingObserves, DynamicsMultiplatformKableStateConnectingServices, DynamicsMultiplatformKableStateDisconnected, DynamicsMultiplatformKableStateDisconnectedStatus, DynamicsMultiplatformKableStateDisconnectedStatusCancelled, DynamicsMultiplatformKableStateDisconnectedStatusCentralDisconnected, DynamicsMultiplatformKableStateDisconnectedStatusConnectionLimitReached, DynamicsMultiplatformKableStateDisconnectedStatusEncryptionTimedOut, DynamicsMultiplatformKableStateDisconnectedStatusFailed, DynamicsMultiplatformKableStateDisconnectedStatusL2CapFailure, DynamicsMultiplatformKableStateDisconnectedStatusLinkManagerProtocolTimeout, DynamicsMultiplatformKableStateDisconnectedStatusPeerRemovedPairingInformation, DynamicsMultiplatformKableStateDisconnectedStatusPeripheralDisconnected, DynamicsMultiplatformKableStateDisconnectedStatusTimeout, DynamicsMultiplatformKableStateDisconnectedStatusUnknown, DynamicsMultiplatformKableStateDisconnectedStatusUnknownDevice, DynamicsMultiplatformKableStateDisconnecting, DynamicsMultiplatformKeyValueIntSetting, DynamicsMultiplatformKeyValueSetting, DynamicsMultiplatformKeyValueStringSetting, DynamicsMultiplatformKeychainSettings, DynamicsMultiplatformKotlinArray<T>, DynamicsMultiplatformKotlinByteArray, DynamicsMultiplatformKotlinByteIterator, DynamicsMultiplatformKotlinEnum<E>, DynamicsMultiplatformKotlinEnumCompanion, DynamicsMultiplatformKotlinException, DynamicsMultiplatformKotlinIllegalArgumentException, DynamicsMultiplatformKotlinIllegalStateException, DynamicsMultiplatformKotlinInstant, DynamicsMultiplatformKotlinInstantCompanion, DynamicsMultiplatformKotlinIntIterator, DynamicsMultiplatformKotlinIntProgression, DynamicsMultiplatformKotlinIntProgressionCompanion, DynamicsMultiplatformKotlinIntRange, DynamicsMultiplatformKotlinIntRangeCompanion, DynamicsMultiplatformKotlinKTypeProjection, DynamicsMultiplatformKotlinKTypeProjectionCompanion, DynamicsMultiplatformKotlinKVariance, DynamicsMultiplatformKotlinLongIterator, DynamicsMultiplatformKotlinLongProgression, DynamicsMultiplatformKotlinLongProgressionCompanion, DynamicsMultiplatformKotlinLongRange, DynamicsMultiplatformKotlinLongRangeCompanion, DynamicsMultiplatformKotlinNothing, DynamicsMultiplatformKotlinPair<__covariant A, __covariant B>, DynamicsMultiplatformKotlinRandom, DynamicsMultiplatformKotlinRandomDefault, DynamicsMultiplatformKotlinRuntimeException, DynamicsMultiplatformKotlinThrowable, DynamicsMultiplatformKotlinUnit, DynamicsMultiplatformKotlinUuid, DynamicsMultiplatformKotlinUuidCompanion, DynamicsMultiplatformKotlinx_serialization_coreAbstractPolymorphicSerializer<T>, DynamicsMultiplatformKotlinx_serialization_coreSerialKind, DynamicsMultiplatformKotlinx_serialization_coreSerializersModule, DynamicsMultiplatformLifeCycleState, DynamicsMultiplatformLifeCycleStateDisposed, DynamicsMultiplatformLifeCycleStateInitializing, DynamicsMultiplatformLifeCycleStatePreparing, DynamicsMultiplatformLifeCycleStateReady, DynamicsMultiplatformLocalDate, DynamicsMultiplatformLocalDateCompanion, DynamicsMultiplatformLocalDateComponentSerializer, DynamicsMultiplatformLocalDateFormats, DynamicsMultiplatformLocalDateIso8601Serializer, DynamicsMultiplatformLocalDateProgression, DynamicsMultiplatformLocalDateProgressionCompanion, DynamicsMultiplatformLocalDateRange, DynamicsMultiplatformLocalDateRangeCompanion, DynamicsMultiplatformLocalDateTime, DynamicsMultiplatformLocalDateTimeCompanion, DynamicsMultiplatformLocalDateTimeComponentSerializer, DynamicsMultiplatformLocalDateTimeFormats, DynamicsMultiplatformLocalDateTimeIso8601Serializer, DynamicsMultiplatformLocalTime, DynamicsMultiplatformLocalTimeCompanion, DynamicsMultiplatformLocalTimeComponentSerializer, DynamicsMultiplatformLocalTimeFormats, DynamicsMultiplatformLocalTimeIso8601Serializer, DynamicsMultiplatformLogLevel, DynamicsMultiplatformLogLevel_, DynamicsMultiplatformMonth, DynamicsMultiplatformMonthBasedDateTimeUnitSerializer, DynamicsMultiplatformMonthNames, DynamicsMultiplatformMonthNamesCompanion, DynamicsMultiplatformMonthSerializer, DynamicsMultiplatformNSUserDefaultsSettings, DynamicsMultiplatformNapier, DynamicsMultiplatformNearbyGlove, DynamicsMultiplatformNearbyGloveState, DynamicsMultiplatformNearbyPeripheral, DynamicsMultiplatformNotConnectedException, DynamicsMultiplatformOperationConfigOption, DynamicsMultiplatformOperationalState, DynamicsMultiplatformOperationalStateCompanion, DynamicsMultiplatformOverloadMarker, DynamicsMultiplatformPadding, DynamicsMultiplatformPairingRepository, DynamicsMultiplatformPeripheralData, DynamicsMultiplatformPeripheralDataWithThroughputTest, DynamicsMultiplatformPeripheralDto, DynamicsMultiplatformPeripheralDtoCompanion, DynamicsMultiplatformPeripheralPair, DynamicsMultiplatformPeripheralState, DynamicsMultiplatformPeripheralStateCompanion, DynamicsMultiplatformPlatform, DynamicsMultiplatformPower, DynamicsMultiplatformPowerAlpha, DynamicsMultiplatformPowerDelta, DynamicsMultiplatformPowerSamples, DynamicsMultiplatformPowerSamplesCompanion, DynamicsMultiplatformPowerState, DynamicsMultiplatformProfileRepository, DynamicsMultiplatformPunch, DynamicsMultiplatformPunchExport, DynamicsMultiplatformPunchRepository, DynamicsMultiplatformPunchWithRawData, DynamicsMultiplatformPunchWithSamples, DynamicsMultiplatformRawDataPipePacket, DynamicsMultiplatformRawDataPipePacketCompanion, DynamicsMultiplatformRecordedSensorStreamSequence, DynamicsMultiplatformResourceResource<T>, DynamicsMultiplatformResourceResourceSuccess<T>, DynamicsMultiplatformScannerError, DynamicsMultiplatformScannerInactiveReason, DynamicsMultiplatformScannerState, DynamicsMultiplatformScannerStateActive, DynamicsMultiplatformSelfTestOutput, DynamicsMultiplatformSensorDataPacket, DynamicsMultiplatformSensorDataRepository, DynamicsMultiplatformSensorDataStreamState, DynamicsMultiplatformSensorDataStreamStateInit, DynamicsMultiplatformSensorDataStreamStateRecording, DynamicsMultiplatformSensorDataStreamStateStopped, DynamicsMultiplatformSensorSamplingRate, DynamicsMultiplatformSensorSamplingRateCompanion, DynamicsMultiplatformSettingsCompanion, DynamicsMultiplatformSide, DynamicsMultiplatformSpeed, DynamicsMultiplatformSpeedSamples, DynamicsMultiplatformSpeedSamplesCompanion, DynamicsMultiplatformTestRepository, DynamicsMultiplatformThroughputTest, DynamicsMultiplatformThroughputTestDto, DynamicsMultiplatformThroughputTestEventDto, DynamicsMultiplatformThroughputTestExport, DynamicsMultiplatformThroughputTestInput, DynamicsMultiplatformThroughputTestInputCompanion, DynamicsMultiplatformTimeBasedDateTimeUnitSerializer, DynamicsMultiplatformTimeSampleDouble, DynamicsMultiplatformTimeSampleInt, DynamicsMultiplatformTimeZone, DynamicsMultiplatformTimeZoneCompanion, DynamicsMultiplatformTimeZoneSerializer, DynamicsMultiplatformTrainingSession, DynamicsMultiplatformTrainingSessionAverageStats, DynamicsMultiplatformTrainingSessionAverageStatsCompanion, DynamicsMultiplatformTrainingSessionBestStats, DynamicsMultiplatformTrainingSessionBestStatsCompanion, DynamicsMultiplatformTrainingSessionEvent, DynamicsMultiplatformTrainingSessionEventType, DynamicsMultiplatformTrainingSessionExtendedState, DynamicsMultiplatformTrainingSessionExtendedStateCompanion, DynamicsMultiplatformTrainingSessionExtendedStateFinished, DynamicsMultiplatformTrainingSessionExtendedStateInitializing, DynamicsMultiplatformTrainingSessionExtendedStatePaused, DynamicsMultiplatformTrainingSessionExtendedStateReady, DynamicsMultiplatformTrainingSessionExtendedStateResumed, DynamicsMultiplatformTrainingSessionInput, DynamicsMultiplatformTrainingSessionInputCompanion, DynamicsMultiplatformTrainingSessionRepository, DynamicsMultiplatformTrainingSessionSensorType, DynamicsMultiplatformTrainingSessionSettings, DynamicsMultiplatformTrainingSessionState, DynamicsMultiplatformTrainingSessionStateActor, DynamicsMultiplatformTrainingSessionStats, DynamicsMultiplatformTrainingSessionStatsCompanion, DynamicsMultiplatformTrainingSessionStatsDetails, DynamicsMultiplatformTrainingSessionStatsDetailsCompanion, DynamicsMultiplatformTrainingSessionTime, DynamicsMultiplatformTrainingSessionTimeCompanion, DynamicsMultiplatformTrainingSessionWithTime, DynamicsMultiplatformUnknown, DynamicsMultiplatformUtcOffset, DynamicsMultiplatformUtcOffsetCompanion, DynamicsMultiplatformUtcOffsetFormats, DynamicsMultiplatformUtcOffsetIso8601Serializer, DynamicsMultiplatformUtcOffsetSerializer, DynamicsMultiplatformVector3d<T>, DynamicsMultiplatformVector3dBoolean, DynamicsMultiplatformVector3dCompanion, DynamicsMultiplatformVector3dDouble, DynamicsMultiplatformVector3dDoubleCompanion, DynamicsMultiplatformVector3dInt, DynamicsMultiplatformVector3dMicroTesla, DynamicsMultiplatformVector3dQ15, DynamicsMultiplatformVector3dShort, DynamicsMultiplatformWiredExternalPowerSourceConnected, DynamicsMultiplatformWirelessExternalPowerSourceConnected, DynamicsMultiplatformYearMonth, DynamicsMultiplatformYearMonthCompanion, DynamicsMultiplatformYearMonthComponentSerializer, DynamicsMultiplatformYearMonthFormats, DynamicsMultiplatformYearMonthIso8601Serializer, DynamicsMultiplatformYearMonthProgression, DynamicsMultiplatformYearMonthProgressionCompanion, DynamicsMultiplatformYearMonthRange, DynamicsMultiplatformYearMonthRangeCompanion, NSData, NSDate, NSDateComponents, NSError, NSTimeZone, NSUUID, NSUserDefaults;

@protocol DynamicsMultiplatformBasicValidation, DynamicsMultiplatformBleMultiplexLogEngine, DynamicsMultiplatformBle_multiplexBatteryService, DynamicsMultiplatformBle_multiplexBleOperationsProvider, DynamicsMultiplatformBle_multiplexDeviceInformationService, DynamicsMultiplatformBle_multiplexGenericAccessService, DynamicsMultiplatformCommonDevice, DynamicsMultiplatformCoreLogEngine, DynamicsMultiplatformDateTimeFormat, DynamicsMultiplatformDateTimeFormatBuilder, DynamicsMultiplatformDateTimeFormatBuilderWithDate, DynamicsMultiplatformDateTimeFormatBuilderWithDateTime, DynamicsMultiplatformDateTimeFormatBuilderWithDateTimeComponents, DynamicsMultiplatformDateTimeFormatBuilderWithTime, DynamicsMultiplatformDateTimeFormatBuilderWithUtcOffset, DynamicsMultiplatformDateTimeFormatBuilderWithYearMonth, DynamicsMultiplatformDynamics_bleAdvertisingConfigService, DynamicsMultiplatformDynamics_bleBondingConfigurationService, DynamicsMultiplatformDynamics_bleCustomDeviceNameService, DynamicsMultiplatformDynamics_bleDataPipeService, DynamicsMultiplatformDynamics_bleGenericPeripheral, DynamicsMultiplatformDynamics_bleGlovePeripheral, DynamicsMultiplatformDynamics_bleImpactConfigurationService, DynamicsMultiplatformDynamics_bleOperationConnectionService, DynamicsMultiplatformDynamics_bleTestAndErrorService, DynamicsMultiplatformDynamics_bleWakeUpConfigurationService, DynamicsMultiplatformDynamics_dbBodyProfileDao, DynamicsMultiplatformKotlinAnnotation, DynamicsMultiplatformKotlinAppendable, DynamicsMultiplatformKotlinClock, DynamicsMultiplatformKotlinClosedFloatingPointRange, DynamicsMultiplatformKotlinClosedRange, DynamicsMultiplatformKotlinCollection, DynamicsMultiplatformKotlinComparable, DynamicsMultiplatformKotlinComparator, DynamicsMultiplatformKotlinCoroutineContext, DynamicsMultiplatformKotlinCoroutineContextElement, DynamicsMultiplatformKotlinCoroutineContextKey, DynamicsMultiplatformKotlinIterable, DynamicsMultiplatformKotlinIterator, DynamicsMultiplatformKotlinKAnnotatedElement, DynamicsMultiplatformKotlinKCallable, DynamicsMultiplatformKotlinKClass, DynamicsMultiplatformKotlinKClassifier, DynamicsMultiplatformKotlinKDeclarationContainer, DynamicsMultiplatformKotlinKProperty, DynamicsMultiplatformKotlinKType, DynamicsMultiplatformKotlinOpenEndRange, DynamicsMultiplatformKotlinReadOnlyProperty, DynamicsMultiplatformKotlinReadWriteProperty, DynamicsMultiplatformKotlinTimeMark, DynamicsMultiplatformKotlinTimeSource, DynamicsMultiplatformKotlinTimeSourceWithComparableMarks, DynamicsMultiplatformKotlinx_coroutines_coreCoroutineScope, DynamicsMultiplatformKotlinx_coroutines_coreFlow, DynamicsMultiplatformKotlinx_coroutines_coreFlowCollector, DynamicsMultiplatformKotlinx_coroutines_coreSharedFlow, DynamicsMultiplatformKotlinx_coroutines_coreStateFlow, DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder, DynamicsMultiplatformKotlinx_serialization_coreCompositeEncoder, DynamicsMultiplatformKotlinx_serialization_coreDecoder, DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy, DynamicsMultiplatformKotlinx_serialization_coreEncoder, DynamicsMultiplatformKotlinx_serialization_coreKSerializer, DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor, DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy, DynamicsMultiplatformKotlinx_serialization_coreSerializersModuleCollector, DynamicsMultiplatformObservableSettings, DynamicsMultiplatformSettings, DynamicsMultiplatformSettingsFactory, DynamicsMultiplatformSettingsListener, DynamicsMultiplatformTrainingSessionSensorTypeExtended;

NS_ASSUME_NONNULL_BEGIN
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-warning-option"
#pragma clang diagnostic ignored "-Wincompatible-property-type"
#pragma clang diagnostic ignored "-Wnullability"

#pragma push_macro("_Nullable_result")
#if !__has_feature(nullability_nullable_result)
#undef _Nullable_result
#define _Nullable_result _Nullable
#endif

__attribute__((swift_name("KotlinBase")))
@interface DynamicsMultiplatformBase : NSObject
- (instancetype)init __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (void)initialize __attribute__((objc_requires_super));
@end

@interface DynamicsMultiplatformBase (DynamicsMultiplatformBaseCopying) <NSCopying>
@end

__attribute__((swift_name("KotlinMutableSet")))
@interface DynamicsMultiplatformMutableSet<ObjectType> : NSMutableSet<ObjectType>
@end

__attribute__((swift_name("KotlinMutableDictionary")))
@interface DynamicsMultiplatformMutableDictionary<KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>
@end

@interface NSError (NSErrorDynamicsMultiplatformKotlinException)
@property (readonly) id _Nullable kotlinException;
@end

__attribute__((swift_name("KotlinNumber")))
@interface DynamicsMultiplatformNumber : NSNumber
- (instancetype)initWithChar:(char)value __attribute__((unavailable));
- (instancetype)initWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
- (instancetype)initWithShort:(short)value __attribute__((unavailable));
- (instancetype)initWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
- (instancetype)initWithInt:(int)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
- (instancetype)initWithLong:(long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
- (instancetype)initWithLongLong:(long long)value __attribute__((unavailable));
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
- (instancetype)initWithFloat:(float)value __attribute__((unavailable));
- (instancetype)initWithDouble:(double)value __attribute__((unavailable));
- (instancetype)initWithBool:(BOOL)value __attribute__((unavailable));
- (instancetype)initWithInteger:(NSInteger)value __attribute__((unavailable));
- (instancetype)initWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
+ (instancetype)numberWithChar:(char)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedChar:(unsigned char)value __attribute__((unavailable));
+ (instancetype)numberWithShort:(short)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedShort:(unsigned short)value __attribute__((unavailable));
+ (instancetype)numberWithInt:(int)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInt:(unsigned int)value __attribute__((unavailable));
+ (instancetype)numberWithLong:(long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLong:(unsigned long)value __attribute__((unavailable));
+ (instancetype)numberWithLongLong:(long long)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value __attribute__((unavailable));
+ (instancetype)numberWithFloat:(float)value __attribute__((unavailable));
+ (instancetype)numberWithDouble:(double)value __attribute__((unavailable));
+ (instancetype)numberWithBool:(BOOL)value __attribute__((unavailable));
+ (instancetype)numberWithInteger:(NSInteger)value __attribute__((unavailable));
+ (instancetype)numberWithUnsignedInteger:(NSUInteger)value __attribute__((unavailable));
@end

__attribute__((swift_name("KotlinByte")))
@interface DynamicsMultiplatformByte : DynamicsMultiplatformNumber
- (instancetype)initWithChar:(char)value;
+ (instancetype)numberWithChar:(char)value;
@end

__attribute__((swift_name("KotlinUByte")))
@interface DynamicsMultiplatformUByte : DynamicsMultiplatformNumber
- (instancetype)initWithUnsignedChar:(unsigned char)value;
+ (instancetype)numberWithUnsignedChar:(unsigned char)value;
@end

__attribute__((swift_name("KotlinShort")))
@interface DynamicsMultiplatformShort : DynamicsMultiplatformNumber
- (instancetype)initWithShort:(short)value;
+ (instancetype)numberWithShort:(short)value;
@end

__attribute__((swift_name("KotlinUShort")))
@interface DynamicsMultiplatformUShort : DynamicsMultiplatformNumber
- (instancetype)initWithUnsignedShort:(unsigned short)value;
+ (instancetype)numberWithUnsignedShort:(unsigned short)value;
@end

__attribute__((swift_name("KotlinInt")))
@interface DynamicsMultiplatformInt : DynamicsMultiplatformNumber
- (instancetype)initWithInt:(int)value;
+ (instancetype)numberWithInt:(int)value;
@end

__attribute__((swift_name("KotlinUInt")))
@interface DynamicsMultiplatformUInt : DynamicsMultiplatformNumber
- (instancetype)initWithUnsignedInt:(unsigned int)value;
+ (instancetype)numberWithUnsignedInt:(unsigned int)value;
@end

__attribute__((swift_name("KotlinLong")))
@interface DynamicsMultiplatformLong : DynamicsMultiplatformNumber
- (instancetype)initWithLongLong:(long long)value;
+ (instancetype)numberWithLongLong:(long long)value;
@end

__attribute__((swift_name("KotlinULong")))
@interface DynamicsMultiplatformULong : DynamicsMultiplatformNumber
- (instancetype)initWithUnsignedLongLong:(unsigned long long)value;
+ (instancetype)numberWithUnsignedLongLong:(unsigned long long)value;
@end

__attribute__((swift_name("KotlinFloat")))
@interface DynamicsMultiplatformFloat : DynamicsMultiplatformNumber
- (instancetype)initWithFloat:(float)value;
+ (instancetype)numberWithFloat:(float)value;
@end

__attribute__((swift_name("KotlinDouble")))
@interface DynamicsMultiplatformDouble : DynamicsMultiplatformNumber
- (instancetype)initWithDouble:(double)value;
+ (instancetype)numberWithDouble:(double)value;
@end

__attribute__((swift_name("KotlinBoolean")))
@interface DynamicsMultiplatformBoolean : DynamicsMultiplatformNumber
- (instancetype)initWithBool:(BOOL)value;
+ (instancetype)numberWithBool:(BOOL)value;
@end

__attribute__((swift_name("KotlinThrowable")))
@interface DynamicsMultiplatformKotlinThrowable : DynamicsMultiplatformBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));

/**
 * @note annotations
 *   kotlin.experimental.ExperimentalNativeApi
*/
- (DynamicsMultiplatformKotlinArray<NSString *> *)getStackTrace __attribute__((swift_name("getStackTrace()")));
- (void)printStackTrace __attribute__((swift_name("printStackTrace()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) NSString * _Nullable message __attribute__((swift_name("message")));
- (NSError *)asError __attribute__((swift_name("asError()")));
@end

__attribute__((swift_name("KotlinException")))
@interface DynamicsMultiplatformKotlinException : DynamicsMultiplatformKotlinThrowable
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("IOException")))
@interface DynamicsMultiplatformIOException : DynamicsMultiplatformKotlinException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((swift_name("GattStatusException")))
@interface DynamicsMultiplatformGattStatusException : DynamicsMultiplatformIOException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("AppleGattStatusException")))
@interface DynamicsMultiplatformAppleGattStatusException : DynamicsMultiplatformGattStatusException
- (instancetype)initWithError:(NSError *)error message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(error:message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) NSError *error __attribute__((swift_name("error")));
@end


/** Failure occurred with the underlying Bluetooth system. */
__attribute__((swift_name("BluetoothException")))
@interface DynamicsMultiplatformBluetoothException : DynamicsMultiplatformKotlinException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BluetoothDisabledException")))
@interface DynamicsMultiplatformBluetoothDisabledException : DynamicsMultiplatformBluetoothException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("NotConnectedException")))
@interface DynamicsMultiplatformNotConnectedException : DynamicsMultiplatformIOException
- (instancetype)initWithStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(status:message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConnectionLostException")))
@interface DynamicsMultiplatformConnectionLostException : DynamicsMultiplatformNotConnectedException
- (instancetype)initWithStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(status:message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConnectionRejectedException")))
@interface DynamicsMultiplatformConnectionRejectedException : DynamicsMultiplatformIOException
- (instancetype)initWithStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(status:message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable status __attribute__((swift_name("status")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NotReadyException")))
@interface DynamicsMultiplatformNotReadyException : DynamicsMultiplatformNotConnectedException
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(status:message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@end


/**
 * The rename for objc is necessary as State will clash with SwiftUI.State.
 */
__attribute__((swift_name("KableState")))
@interface DynamicsMultiplatformKableState : DynamicsMultiplatformBase
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * [Peripheral] is ready (i.e. has connected, discovered services and wired up [observers][Peripheral.observe]).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.Connected")))
@interface DynamicsMultiplatformKableStateConnected : DynamicsMultiplatformKableState
+ (instancetype)alloc __attribute__((unavailable));

/**
 * [Peripheral] is ready (i.e. has connected, discovered services and wired up [observers][Peripheral.observe]).
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)connected __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateConnected *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KableState.Connecting")))
@interface DynamicsMultiplatformKableStateConnecting : DynamicsMultiplatformKableState
@end


/**
 * [Peripheral] has initiated the process of connecting, via Bluetooth.
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) will throw [NotReadyException]
 * while in this state.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.ConnectingBluetooth")))
@interface DynamicsMultiplatformKableStateConnectingBluetooth : DynamicsMultiplatformKableStateConnecting
+ (instancetype)alloc __attribute__((unavailable));

/**
 * [Peripheral] has initiated the process of connecting, via Bluetooth.
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) will throw [NotReadyException]
 * while in this state.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)bluetooth __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateConnectingBluetooth *shared __attribute__((swift_name("shared")));
@end


/**
 * [Peripheral] is wiring up [Observers][Peripheral.observe].
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) are permitted while in this state.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.ConnectingObserves")))
@interface DynamicsMultiplatformKableStateConnectingObserves : DynamicsMultiplatformKableStateConnecting
+ (instancetype)alloc __attribute__((unavailable));

/**
 * [Peripheral] is wiring up [Observers][Peripheral.observe].
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) are permitted while in this state.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)observes __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateConnectingObserves *shared __attribute__((swift_name("shared")));
@end


/**
 * [Peripheral] has connected, but has not yet discovered services.
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) will throw [IllegalStateOperation]
 * while in this state.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.ConnectingServices")))
@interface DynamicsMultiplatformKableStateConnectingServices : DynamicsMultiplatformKableStateConnecting
+ (instancetype)alloc __attribute__((unavailable));

/**
 * [Peripheral] has connected, but has not yet discovered services.
 *
 * I/O operations (e.g. [write][Peripheral.write] and [read][Peripheral.read]) will throw [IllegalStateOperation]
 * while in this state.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)services __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateConnectingServices *shared __attribute__((swift_name("shared")));
@end


/**
 * Triggered either after an established connection has dropped or after a connection attempt has failed.
 *
 * @param status represents status (cause) of [Disconnected] [State]. Always `null` for Javascript target.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.Disconnected")))
@interface DynamicsMultiplatformKableStateDisconnected : DynamicsMultiplatformKableState
- (instancetype)initWithStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status __attribute__((swift_name("init(status:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKableStateDisconnected *)doCopyStatus:(DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable)status __attribute__((swift_name("doCopy(status:)")));

/**
 * Triggered either after an established connection has dropped or after a connection attempt has failed.
 *
 * @param status represents status (cause) of [Disconnected] [State]. Always `null` for Javascript target.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Triggered either after an established connection has dropped or after a connection attempt has failed.
 *
 * @param status represents status (cause) of [Disconnected] [State]. Always `null` for Javascript target.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKableStateDisconnectedStatus * _Nullable status __attribute__((swift_name("status")));
@end


/**
 * State statuses translated from their respective platforms:
 *
 * - Android: https://android.googlesource.com/platform/external/bluetooth/bluedroid/+/lollipop-release/stack/include/gatt_api.h#106
 * - Apple: `CBError.h` from the Core Bluetooth framework headers
 */
__attribute__((swift_name("KableState.DisconnectedStatus")))
@interface DynamicsMultiplatformKableStateDisconnectedStatus : DynamicsMultiplatformBase
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * - Android: `GATT_CONN_CANCEL`
 * - Apple: `CBErrorOperationCancelled`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusCancelled")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusCancelled : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_CANCEL`
 * - Apple: `CBErrorOperationCancelled`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)cancelled __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusCancelled *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_TERMINATE_LOCAL_HOST`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusCentralDisconnected")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusCentralDisconnected : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_TERMINATE_LOCAL_HOST`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)centralDisconnected __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusCentralDisconnected *shared __attribute__((swift_name("shared")));
@end


/**
 * - Apple: `CBErrorConnectionLimitReached`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusConnectionLimitReached")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusConnectionLimitReached : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Apple: `CBErrorConnectionLimitReached`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)connectionLimitReached __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusConnectionLimitReached *shared __attribute__((swift_name("shared")));
@end


/**
 * - Apple: `CBErrorEncryptionTimedOut`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusEncryptionTimedOut")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusEncryptionTimedOut : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Apple: `CBErrorEncryptionTimedOut`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)encryptionTimedOut __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusEncryptionTimedOut *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_FAIL_ESTABLISH`
 * - Apple: `CBErrorConnectionFailed`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusFailed")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusFailed : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_FAIL_ESTABLISH`
 * - Apple: `CBErrorConnectionFailed`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)failed __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusFailed *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_L2C_FAILURE`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusL2CapFailure")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusL2CapFailure : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_L2C_FAILURE`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)l2CapFailure __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusL2CapFailure *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_LMP_TIMEOUT`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusLinkManagerProtocolTimeout")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusLinkManagerProtocolTimeout : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_LMP_TIMEOUT`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)linkManagerProtocolTimeout __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusLinkManagerProtocolTimeout *shared __attribute__((swift_name("shared")));
@end


/**
 * - Apple: `CBErrorPeerRemovedPairingInformation`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusPeerRemovedPairingInformation")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusPeerRemovedPairingInformation : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Apple: `CBErrorPeerRemovedPairingInformation`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)peerRemovedPairingInformation __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusPeerRemovedPairingInformation *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_TERMINATE_PEER_USER`
 * - Apple: `CBErrorPeripheralDisconnected`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusPeripheralDisconnected")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusPeripheralDisconnected : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_TERMINATE_PEER_USER`
 * - Apple: `CBErrorPeripheralDisconnected`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)peripheralDisconnected __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusPeripheralDisconnected *shared __attribute__((swift_name("shared")));
@end


/**
 * - Android: `GATT_CONN_TIMEOUT`
 * - Apple: `CBErrorConnectionTimeout`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusTimeout")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusTimeout : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Android: `GATT_CONN_TIMEOUT`
 * - Apple: `CBErrorConnectionTimeout`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)timeout __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusTimeout *shared __attribute__((swift_name("shared")));
@end


/** Catch-all for any statuses that are unknown for a platform. */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusUnknown")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusUnknown : DynamicsMultiplatformKableStateDisconnectedStatus
- (instancetype)initWithStatus:(int32_t)status __attribute__((swift_name("init(status:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKableStateDisconnectedStatusUnknown *)doCopyStatus:(int32_t)status __attribute__((swift_name("doCopy(status:)")));

/** Catch-all for any statuses that are unknown for a platform. */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/** Catch-all for any statuses that are unknown for a platform. */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/** Catch-all for any statuses that are unknown for a platform. */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t status __attribute__((swift_name("status")));
@end


/**
 * - Apple: `CBErrorUnknownDevice`
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.DisconnectedStatusUnknownDevice")))
@interface DynamicsMultiplatformKableStateDisconnectedStatusUnknownDevice : DynamicsMultiplatformKableStateDisconnectedStatus
+ (instancetype)alloc __attribute__((unavailable));

/**
 * - Apple: `CBErrorUnknownDevice`
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unknownDevice __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnectedStatusUnknownDevice *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableState.Disconnecting")))
@interface DynamicsMultiplatformKableStateDisconnecting : DynamicsMultiplatformKableState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)disconnecting __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKableStateDisconnecting *shared __attribute__((swift_name("shared")));
@end


/**
 * Represents a common bluetooth device instance.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("CommonDevice")))
@protocol DynamicsMultiplatformCommonDevice
@required
@end


/**
 * A wrapper for the apple's [CBPeripheral].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AppleDevice")))
@interface DynamicsMultiplatformAppleDevice : DynamicsMultiplatformBase <DynamicsMultiplatformCommonDevice>
- (instancetype)initWithCbPeripheral:(CBPeripheral *)cbPeripheral __attribute__((swift_name("init(cbPeripheral:)"))) __attribute__((objc_designated_initializer));
@property (readonly) CBPeripheral *cbPeripheral __attribute__((swift_name("cbPeripheral")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AccStreamData")))
@interface DynamicsMultiplatformAccStreamData : DynamicsMultiplatformBase
- (instancetype)initWithPeripheralId:(id)peripheralId acc:(DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *)acc __attribute__((swift_name("init(peripheralId:acc:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformAccStreamData *)doCopyPeripheralId:(id)peripheralId acc:(DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *)acc __attribute__((swift_name("doCopy(peripheralId:acc:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("BleGloveState")))
@interface DynamicsMultiplatformBleGloveState : DynamicsMultiplatformBase
@property (readonly) DynamicsMultiplatformGloveData * _Nullable data __attribute__((swift_name("data")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleGloveState.Connecting")))
@interface DynamicsMultiplatformBleGloveStateConnecting : DynamicsMultiplatformBleGloveState
- (instancetype)initWithData:(DynamicsMultiplatformGloveData * _Nullable)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("BleGloveState.Offline")))
@interface DynamicsMultiplatformBleGloveStateOffline : DynamicsMultiplatformBleGloveState
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleGloveState.OfflineError")))
@interface DynamicsMultiplatformBleGloveStateOfflineError : DynamicsMultiplatformBleGloveStateOffline
- (instancetype)initWithData:(DynamicsMultiplatformGloveData * _Nullable)data gloveConnectionError:(DynamicsMultiplatformGloveConnectionError *)gloveConnectionError __attribute__((swift_name("init(data:gloveConnectionError:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGloveConnectionError *gloveConnectionError __attribute__((swift_name("gloveConnectionError")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleGloveState.OfflineOutOfRange")))
@interface DynamicsMultiplatformBleGloveStateOfflineOutOfRange : DynamicsMultiplatformBleGloveStateOffline
- (instancetype)initWithData:(DynamicsMultiplatformGloveData * _Nullable)data __attribute__((swift_name("init(data:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleGloveState.Online")))
@interface DynamicsMultiplatformBleGloveStateOnline : DynamicsMultiplatformBleGloveState
- (instancetype)initWithOnlineData:(DynamicsMultiplatformGloveData *)onlineData __attribute__((swift_name("init(onlineData:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleGloveStateOnline *)doCopyOnlineData:(DynamicsMultiplatformGloveData *)onlineData __attribute__((swift_name("doCopy(onlineData:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGloveData *onlineData __attribute__((swift_name("onlineData")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Glove")))
@interface DynamicsMultiplatformGlove : DynamicsMultiplatformBase
- (instancetype)initWithDto:(DynamicsMultiplatformPeripheralDto *)dto bleGloveState:(DynamicsMultiplatformBleGloveState *)bleGloveState __attribute__((swift_name("init(dto:bleGloveState:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlove *)doCopyDto:(DynamicsMultiplatformPeripheralDto *)dto bleGloveState:(DynamicsMultiplatformBleGloveState *)bleGloveState __attribute__((swift_name("doCopy(dto:bleGloveState:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *address __attribute__((swift_name("address")));
@property (readonly) DynamicsMultiplatformBleGloveState *bleGloveState __attribute__((swift_name("bleGloveState")));
@property (readonly) DynamicsMultiplatformGloveData * _Nullable data __attribute__((swift_name("data")));
@property (readonly) DynamicsMultiplatformPeripheralDto *dto __attribute__((swift_name("dto")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveBattery")))
@interface DynamicsMultiplatformGloveBattery : DynamicsMultiplatformBase
- (instancetype)initWithBatteryLevel:(int32_t)batteryLevel isChargerAttached:(BOOL)isChargerAttached isCharging:(BOOL)isCharging __attribute__((swift_name("init(batteryLevel:isChargerAttached:isCharging:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveBattery *)doCopyBatteryLevel:(int32_t)batteryLevel isChargerAttached:(BOOL)isChargerAttached isCharging:(BOOL)isCharging __attribute__((swift_name("doCopy(batteryLevel:isChargerAttached:isCharging:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t batteryLevel __attribute__((swift_name("batteryLevel")));
@property (readonly) BOOL isChargerAttached __attribute__((swift_name("isChargerAttached")));
@property (readonly) BOOL isCharging __attribute__((swift_name("isCharging")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("GloveConnectionError")))
@interface DynamicsMultiplatformGloveConnectionError : DynamicsMultiplatformBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveConnectionError.BondLost")))
@interface DynamicsMultiplatformGloveConnectionErrorBondLost : DynamicsMultiplatformGloveConnectionError
- (instancetype)initWithState:(DynamicsMultiplatformBondState *)state __attribute__((swift_name("init(state:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveConnectionErrorBondLost *)doCopyState:(DynamicsMultiplatformBondState *)state __attribute__((swift_name("doCopy(state:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformBondState *state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveConnectionError.MissingRequirements")))
@interface DynamicsMultiplatformGloveConnectionErrorMissingRequirements : DynamicsMultiplatformGloveConnectionError
- (instancetype)initWithBleRequirementsState:(DynamicsMultiplatformBleRequirementsState *)bleRequirementsState __attribute__((swift_name("init(bleRequirementsState:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveConnectionErrorMissingRequirements *)doCopyBleRequirementsState:(DynamicsMultiplatformBleRequirementsState *)bleRequirementsState __attribute__((swift_name("doCopy(bleRequirementsState:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformBleRequirementsState *bleRequirementsState __attribute__((swift_name("bleRequirementsState")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveData")))
@interface DynamicsMultiplatformGloveData : DynamicsMultiplatformBase
- (instancetype)initWithDeviceName:(NSString *)deviceName deviceInfo:(DynamicsMultiplatformDeviceInfo *)deviceInfo battery:(DynamicsMultiplatformGloveBattery *)battery operationalState:(DynamicsMultiplatformOperationalState *)operationalState sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(deviceName:deviceInfo:battery:operationalState:sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveData *)doCopyDeviceName:(NSString *)deviceName deviceInfo:(DynamicsMultiplatformDeviceInfo *)deviceInfo battery:(DynamicsMultiplatformGloveBattery *)battery operationalState:(DynamicsMultiplatformOperationalState *)operationalState sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(deviceName:deviceInfo:battery:operationalState:sensorType:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGloveBattery *battery __attribute__((swift_name("battery")));
@property (readonly) DynamicsMultiplatformDeviceInfo *deviceInfo __attribute__((swift_name("deviceInfo")));
@property (readonly) NSString *deviceName __attribute__((swift_name("deviceName")));
@property (readonly) DynamicsMultiplatformOperationalState *operationalState __attribute__((swift_name("operationalState")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveWithThroughputTest")))
@interface DynamicsMultiplatformGloveWithThroughputTest : DynamicsMultiplatformBase
- (instancetype)initWithGlove:(DynamicsMultiplatformGlove *)glove throughputTest:(DynamicsMultiplatformThroughputTest * _Nullable)throughputTest __attribute__((swift_name("init(glove:throughputTest:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveWithThroughputTest *)doCopyGlove:(DynamicsMultiplatformGlove *)glove throughputTest:(DynamicsMultiplatformThroughputTest * _Nullable)throughputTest __attribute__((swift_name("doCopy(glove:throughputTest:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGlove *glove __attribute__((swift_name("glove")));
@property (readonly) DynamicsMultiplatformThroughputTest * _Nullable throughputTest __attribute__((swift_name("throughputTest")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("LifeCycleState")))
@interface DynamicsMultiplatformLifeCycleState : DynamicsMultiplatformBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LifeCycleState.Disposed")))
@interface DynamicsMultiplatformLifeCycleStateDisposed : DynamicsMultiplatformLifeCycleState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)disposed __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLifeCycleStateDisposed *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LifeCycleState.Initializing")))
@interface DynamicsMultiplatformLifeCycleStateInitializing : DynamicsMultiplatformLifeCycleState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)initializing __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLifeCycleStateInitializing *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LifeCycleState.Preparing")))
@interface DynamicsMultiplatformLifeCycleStatePreparing : DynamicsMultiplatformLifeCycleState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)preparing __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLifeCycleStatePreparing *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LifeCycleState.Ready")))
@interface DynamicsMultiplatformLifeCycleStateReady : DynamicsMultiplatformLifeCycleState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)ready __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLifeCycleStateReady *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralData")))
@interface DynamicsMultiplatformPeripheralData : DynamicsMultiplatformBase
- (instancetype)initWithLifecycleState:(DynamicsMultiplatformLifeCycleState *)lifecycleState peripheralState:(DynamicsMultiplatformPeripheralState *)peripheralState gloveContent:(DynamicsMultiplatformGloveData *)gloveContent __attribute__((swift_name("init(lifecycleState:peripheralState:gloveContent:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPeripheralData *)doCopyLifecycleState:(DynamicsMultiplatformLifeCycleState *)lifecycleState peripheralState:(DynamicsMultiplatformPeripheralState *)peripheralState gloveContent:(DynamicsMultiplatformGloveData *)gloveContent __attribute__((swift_name("doCopy(lifecycleState:peripheralState:gloveContent:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGloveData *gloveContent __attribute__((swift_name("gloveContent")));
@property (readonly) DynamicsMultiplatformLifeCycleState *lifecycleState __attribute__((swift_name("lifecycleState")));
@property (readonly) DynamicsMultiplatformPeripheralState *peripheralState __attribute__((swift_name("peripheralState")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralDataWithThroughputTest")))
@interface DynamicsMultiplatformPeripheralDataWithThroughputTest : DynamicsMultiplatformBase
- (instancetype)initWithPeripheralData:(DynamicsMultiplatformPeripheralData *)peripheralData throughputTest:(DynamicsMultiplatformThroughputTest * _Nullable)throughputTest __attribute__((swift_name("init(peripheralData:throughputTest:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPeripheralDataWithThroughputTest *)doCopyPeripheralData:(DynamicsMultiplatformPeripheralData *)peripheralData throughputTest:(DynamicsMultiplatformThroughputTest * _Nullable)throughputTest __attribute__((swift_name("doCopy(peripheralData:throughputTest:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformPeripheralData *peripheralData __attribute__((swift_name("peripheralData")));
@property (readonly) DynamicsMultiplatformThroughputTest * _Nullable throughputTest __attribute__((swift_name("throughputTest")));
@end

__attribute__((swift_name("GloveMode")))
@interface DynamicsMultiplatformGloveMode : DynamicsMultiplatformBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @return a [GlovePairCompatibility] object which describes the different compatibility states.
 */
@property (readonly) DynamicsMultiplatformGlovePairCompatibility *compatibility __attribute__((swift_name("compatibility")));
@property (readonly) DynamicsMultiplatformGlovePairCompatibilityStatus *compatibilityStatus __attribute__((swift_name("compatibilityStatus")));

/**
 * Returns both the left and right glove, in this order, if they exist. If a glove
 * is missing, it will be `null`.
 */
@property (readonly) NSArray<id> *leftAndRightGlove __attribute__((swift_name("leftAndRightGlove")));
@property (readonly) DynamicsMultiplatformGlove * _Nullable leftGloveOrNull __attribute__((swift_name("leftGloveOrNull")));
@property (readonly) DynamicsMultiplatformGlove * _Nullable rightGloveOrNull __attribute__((swift_name("rightGloveOrNull")));
@property (readonly) DynamicsMultiplatformGlove *singleOrLeft __attribute__((swift_name("singleOrLeft")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveMode.Double")))
@interface DynamicsMultiplatformGloveModeDouble : DynamicsMultiplatformGloveMode
- (instancetype)initWithLeft:(DynamicsMultiplatformGlove *)left right:(DynamicsMultiplatformGlove *)right __attribute__((swift_name("init(left:right:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGlove *left __attribute__((swift_name("left")));
@property (readonly) DynamicsMultiplatformGlove *right __attribute__((swift_name("right")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveMode.Single")))
@interface DynamicsMultiplatformGloveModeSingle : DynamicsMultiplatformGloveMode
- (instancetype)initWithGlove:(DynamicsMultiplatformGlove *)glove __attribute__((swift_name("init(glove:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGlove *glove __attribute__((swift_name("glove")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePair")))
@interface DynamicsMultiplatformGlovePair : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id name:(NSString *)name mode:(DynamicsMultiplatformGloveMode *)mode __attribute__((swift_name("init(id:name:mode:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePair *)doCopyId:(id)id name:(NSString *)name mode:(DynamicsMultiplatformGloveMode *)mode __attribute__((swift_name("doCopy(id:name:mode:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGloveMode *mode __attribute__((swift_name("mode")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * The glove mode indicates if there is only one peripheral ([GloveModeDto.Single]) or two
 * [[GloveModeDto.Double]].
 */
__attribute__((swift_name("GloveModeDto")))
@interface DynamicsMultiplatformGloveModeDto : DynamicsMultiplatformBase
@property (readonly) NSArray<DynamicsMultiplatformPeripheralDto *> *peripherals __attribute__((swift_name("peripherals")));
@property (readonly) DynamicsMultiplatformPeripheralDto * _Nullable rightWhenDouble __attribute__((swift_name("rightWhenDouble")));
@property (readonly) DynamicsMultiplatformPeripheralDto *singleOrLeft __attribute__((swift_name("singleOrLeft")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveModeDto.Double")))
@interface DynamicsMultiplatformGloveModeDtoDouble : DynamicsMultiplatformGloveModeDto
- (instancetype)initWithLeft:(DynamicsMultiplatformPeripheralDto *)left right:(DynamicsMultiplatformPeripheralDto *)right __attribute__((swift_name("init(left:right:)"))) __attribute__((objc_designated_initializer));
@property (readonly) DynamicsMultiplatformPeripheralDto *left __attribute__((swift_name("left")));
@property (readonly) DynamicsMultiplatformPeripheralDto *right __attribute__((swift_name("right")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveModeDto.Single")))
@interface DynamicsMultiplatformGloveModeDtoSingle : DynamicsMultiplatformGloveModeDto
- (instancetype)initWithPeripheral:(DynamicsMultiplatformPeripheralDto *)peripheral __attribute__((swift_name("init(peripheral:)"))) __attribute__((objc_designated_initializer));
@property (readonly) DynamicsMultiplatformPeripheralDto *peripheral __attribute__((swift_name("peripheral")));
@end


/**
 * Represents the glove pair.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairDto")))
@interface DynamicsMultiplatformGlovePairDto : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id name:(NSString *)name mode:(DynamicsMultiplatformGloveModeDto *)mode __attribute__((swift_name("init(id:name:mode:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePairDto *)doCopyId:(id)id name:(NSString *)name mode:(DynamicsMultiplatformGloveModeDto *)mode __attribute__((swift_name("doCopy(id:name:mode:)")));

/**
 * Represents the glove pair.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the glove pair.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the glove pair.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The id of the glove pair.
 */
@property (readonly) id id __attribute__((swift_name("id")));

/**
 * The mode of the glove pair.
 */
@property (readonly) DynamicsMultiplatformGloveModeDto *mode __attribute__((swift_name("mode")));

/**
 * The name of the glove pair.
 */
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * Represents the general data of any peripheral.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralDto")))
@interface DynamicsMultiplatformPeripheralDto : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id address:(NSString *)address modelNumber:(NSString *)modelNumber manufacturerName:(NSString *)manufacturerName serialNumber:(NSString *)serialNumber firmwareVersion:(NSString *)firmwareVersion hardwareVersion:(NSString *)hardwareVersion name:(NSString *)name side:(DynamicsMultiplatformSide *)side bondState:(DynamicsMultiplatformBondState *)bondState __attribute__((swift_name("init(id:address:modelNumber:manufacturerName:serialNumber:firmwareVersion:hardwareVersion:name:side:bondState:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformPeripheralDtoCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformPeripheralDto *)doCopyId:(id)id address:(NSString *)address modelNumber:(NSString *)modelNumber manufacturerName:(NSString *)manufacturerName serialNumber:(NSString *)serialNumber firmwareVersion:(NSString *)firmwareVersion hardwareVersion:(NSString *)hardwareVersion name:(NSString *)name side:(DynamicsMultiplatformSide *)side bondState:(DynamicsMultiplatformBondState *)bondState __attribute__((swift_name("doCopy(id:address:modelNumber:manufacturerName:serialNumber:firmwareVersion:hardwareVersion:name:side:bondState:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The bluetooth address of the peripheral. The format may vary depending on the target consumer
 * platform.
 */
@property (readonly) NSString *address __attribute__((swift_name("address")));

/**
 * The bond state.
 */
@property (readonly) DynamicsMultiplatformBondState *bondState __attribute__((swift_name("bondState")));

/**
 * The firmware version according to the device information service.
 */
@property (readonly) NSString *firmwareVersion __attribute__((swift_name("firmwareVersion")));

/**
 * The hardware version according to the device information service.
 */
@property (readonly) NSString *hardwareVersion __attribute__((swift_name("hardwareVersion")));

/**
 * A simple combination of the [id] and [address] which serves as an internal key.
 */
@property (readonly) NSString *idAndAddressKey __attribute__((swift_name("idAndAddressKey")));
@property (readonly) BOOL isMock __attribute__((swift_name("isMock")));

/**
 * The manufacturer name according to the device information service.
 */
@property (readonly) NSString *manufacturerName __attribute__((swift_name("manufacturerName")));

/**
 * The model number according to the device information service.
 */
@property (readonly) NSString *modelNumber __attribute__((swift_name("modelNumber")));

/**
 * The glove pair name, see [com.riseworld.dynamics.models.GlovePairDto].
 */
@property (readonly) NSString *name __attribute__((swift_name("name")));

/**
 * The serial number according to the device information service.
 */
@property (readonly) NSString *serialNumber __attribute__((swift_name("serialNumber")));

/**
 * The side to which the peripheral is associated.
 */
@property (readonly) DynamicsMultiplatformSide *side __attribute__((swift_name("side")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralDto.Companion")))
@interface DynamicsMultiplatformPeripheralDtoCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformPeripheralDtoCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *NO_BLE_ADDRESS_DUE_TO_MOCK __attribute__((swift_name("NO_BLE_ADDRESS_DUE_TO_MOCK")));
@end

__attribute__((swift_name("KotlinComparable")))
@protocol DynamicsMultiplatformKotlinComparable
@required
- (int32_t)compareToOther:(id _Nullable)other __attribute__((swift_name("compareTo(other:)")));
@end

__attribute__((swift_name("KotlinEnum")))
@interface DynamicsMultiplatformKotlinEnum<E> : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinEnumCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(E)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) int32_t ordinal __attribute__((swift_name("ordinal")));
@end


/**
 * Defines the side of a peripheral that can be either left or right.
 *
 * DO NOT change the names of existing entries as otherwise this would break the DB.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Side")))
@interface DynamicsMultiplatformSide : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformSide *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Defines the side of a peripheral that can be either left or right.
 *
 * DO NOT change the names of existing entries as otherwise this would break the DB.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformSide *left __attribute__((swift_name("left")));
@property (class, readonly) DynamicsMultiplatformSide *right __attribute__((swift_name("right")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformSide *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformSide *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * Represents different states for bonded peripherals - the DB only allows [BONDED] state initially.
 *
 * The states are mutually exclusive as with [BOND_LOST_ON_CENTRAL] it's impossible to determine
 * if the [BOND_LOST_ON_PERIPHERAL] is also true.
 *
 * DO NOT change the names of existing entries as otherwise this would break the DB.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BondState")))
@interface DynamicsMultiplatformBondState : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformBondState *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Represents different states for bonded peripherals - the DB only allows [BONDED] state initially.
 *
 * The states are mutually exclusive as with [BOND_LOST_ON_CENTRAL] it's impossible to determine
 * if the [BOND_LOST_ON_PERIPHERAL] is also true.
 *
 * DO NOT change the names of existing entries as otherwise this would break the DB.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformBondState *bonded __attribute__((swift_name("bonded")));
@property (class, readonly) DynamicsMultiplatformBondState *bondLostOnCentral __attribute__((swift_name("bondLostOnCentral")));
@property (class, readonly) DynamicsMultiplatformBondState *bondLostOnPeripheral __attribute__((swift_name("bondLostOnPeripheral")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformBondState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformBondState *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AdvertisingConfigOption")))
@interface DynamicsMultiplatformAdvertisingConfigOption : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformAdvertisingConfigOption *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformAdvertisingConfigOption *deepSleepAdvertisingInterval __attribute__((swift_name("deepSleepAdvertisingInterval")));
@property (class, readonly) DynamicsMultiplatformAdvertisingConfigOption *deepSleepAdvertisingTimeout __attribute__((swift_name("deepSleepAdvertisingTimeout")));
@property (class, readonly) DynamicsMultiplatformAdvertisingConfigOption *advertisingInterval __attribute__((swift_name("advertisingInterval")));
@property (class, readonly) DynamicsMultiplatformAdvertisingConfigOption *advertisingTimeout __attribute__((swift_name("advertisingTimeout")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformAdvertisingConfigOption *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformAdvertisingConfigOption *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllAdvertisingConfigs")))
@interface DynamicsMultiplatformAllAdvertisingConfigs : DynamicsMultiplatformBase
- (instancetype)initWithDeepSleepAdvertisingInterval:(int64_t)deepSleepAdvertisingInterval deepSleepAdvertisingTimeout:(int64_t)deepSleepAdvertisingTimeout advertisingInterval:(int64_t)advertisingInterval advertisingTimeout:(int64_t)advertisingTimeout __attribute__((swift_name("init(deepSleepAdvertisingInterval:deepSleepAdvertisingTimeout:advertisingInterval:advertisingTimeout:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformAllAdvertisingConfigsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformAllAdvertisingConfigs *)doCopyDeepSleepAdvertisingInterval:(int64_t)deepSleepAdvertisingInterval deepSleepAdvertisingTimeout:(int64_t)deepSleepAdvertisingTimeout advertisingInterval:(int64_t)advertisingInterval advertisingTimeout:(int64_t)advertisingTimeout __attribute__((swift_name("doCopy(deepSleepAdvertisingInterval:deepSleepAdvertisingTimeout:advertisingInterval:advertisingTimeout:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllAdvertisingConfigs.Companion")))
@interface DynamicsMultiplatformAllAdvertisingConfigsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformAllAdvertisingConfigsCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BondingSettings")))
@interface DynamicsMultiplatformBondingSettings : DynamicsMultiplatformBase
- (instancetype)initWithResetBondingInformation:(BOOL)resetBondingInformation deleteAllBonds:(BOOL)deleteAllBonds __attribute__((swift_name("init(resetBondingInformation:deleteAllBonds:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBondingSettings *)doCopyResetBondingInformation:(BOOL)resetBondingInformation deleteAllBonds:(BOOL)deleteAllBonds __attribute__((swift_name("doCopy(resetBondingInformation:deleteAllBonds:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * - [Boolean.true] Deletes all stored bonds on the peripheral.
 * - [Boolean.false] Deletes all stored bonds except the last one.
 */
@property (readonly) BOOL deleteAllBonds __attribute__((swift_name("deleteAllBonds")));

/**
 * - [Boolean.true] Resets bonding information.
 * - [Boolean.false] Does nothing
 */
@property (readonly) BOOL resetBondingInformation __attribute__((swift_name("resetBondingInformation")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CapCombination")))
@interface DynamicsMultiplatformCapCombination : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformCapCombination *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformCapCombination *sumUpAllSelectedDirections __attribute__((swift_name("sumUpAllSelectedDirections")));
@property (class, readonly) DynamicsMultiplatformCapCombination *calculateEuclideanNormOfAllSelectedDirections __attribute__((swift_name("calculateEuclideanNormOfAllSelectedDirections")));
@property (class, readonly) DynamicsMultiplatformCapCombination *unknown __attribute__((swift_name("unknown")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformCapCombination *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformCapCombination *> *entries __attribute__((swift_name("entries")));
@property (readonly) uint8_t byte __attribute__((swift_name("byte")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CapOptions")))
@interface DynamicsMultiplatformCapOptions : DynamicsMultiplatformBase
- (instancetype)initWithInvertData:(BOOL)invertData __attribute__((swift_name("init(invertData:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformCapOptions *)doCopyInvertData:(BOOL)invertData __attribute__((swift_name("doCopy(invertData:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL invertData __attribute__((swift_name("invertData")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CapShape")))
@interface DynamicsMultiplatformCapShape : DynamicsMultiplatformBase
- (instancetype)initWithCapHeight:(NSArray<id> *)capHeight meta:(DynamicsMultiplatformCapShapeMeta *)meta __attribute__((swift_name("init(capHeight:meta:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformCapShapeCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformCapShape *)doCopyCapHeight:(NSArray<id> *)capHeight meta:(DynamicsMultiplatformCapShapeMeta *)meta __attribute__((swift_name("doCopy(capHeight:meta:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformCapShapeMeta *meta __attribute__((swift_name("meta")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CapShape.Companion")))
@interface DynamicsMultiplatformCapShapeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformCapShapeCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CapShapeMeta")))
@interface DynamicsMultiplatformCapShapeMeta : DynamicsMultiplatformBase
- (instancetype)initWithCapSize:(int32_t)capSize capAnchorIndex:(int32_t)capAnchorIndex __attribute__((swift_name("init(capSize:capAnchorIndex:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformCapShapeMeta *)doCopyCapSize:(int32_t)capSize capAnchorIndex:(int32_t)capAnchorIndex __attribute__((swift_name("doCopy(capSize:capAnchorIndex:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t capAnchorIndex __attribute__((swift_name("capAnchorIndex")));
@property (readonly) int32_t capSize __attribute__((swift_name("capSize")));
@end


/**
 * Represents the header of a [BlePacket].
 *
 * Every [BlePacket] always starts with a header.
 *
 * The header can be a [Start], [End] or [Within] header.
 *
 * @param version The version of the packet. (0)
 * @param impactId the id of the impact to which this ble header and content belongs. Increments
 * monotonically when a new impact packet is transferred.
 * @param totalBlePacketCountSinceDeviceStart The total number of BLE packets since the start of the device.
 * Resets on restart of the device's BLE interface.
 */
__attribute__((swift_name("BleHeader")))
@interface DynamicsMultiplatformBleHeader : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformBleHeaderCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t impactId __attribute__((swift_name("impactId")));
@property (readonly) DynamicsMultiplatformKotlinByteArray *rawContent __attribute__((swift_name("rawContent")));
@property (readonly) uint16_t totalBlePacketCountSinceDeviceStart __attribute__((swift_name("totalBlePacketCountSinceDeviceStart")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@property (readonly) int32_t version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.Companion")))
@interface DynamicsMultiplatformBleHeaderCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBleHeaderCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformBleHeaderSingle *EMPTY __attribute__((swift_name("EMPTY")));

/**
 * The size of the header in bytes.
 */
@property (readonly) int32_t SIZE __attribute__((swift_name("SIZE")));
@end


/**
 * Represents the end of an [ImpactDataPacket].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.End")))
@interface DynamicsMultiplatformBleHeaderEnd : DynamicsMultiplatformBleHeader
- (instancetype)initWithRawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent version:(int32_t)version impactId:(int32_t)impactId totalBlePacketCountSinceDeviceStart:(uint16_t)totalBlePacketCountSinceDeviceStart __attribute__((swift_name("init(rawContent:version:impactId:totalBlePacketCountSinceDeviceStart:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.Single")))
@interface DynamicsMultiplatformBleHeaderSingle : DynamicsMultiplatformBleHeader
- (instancetype)initWithRawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent version:(int32_t)version impactId:(int32_t)impactId totalBlePacketCountSinceDeviceStart:(uint16_t)totalBlePacketCountSinceDeviceStart __attribute__((swift_name("init(rawContent:version:impactId:totalBlePacketCountSinceDeviceStart:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@end


/**
 * Represents the start of an [ImpactDataPacket].
 *
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.Start")))
@interface DynamicsMultiplatformBleHeaderStart : DynamicsMultiplatformBleHeader
- (instancetype)initWithRawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent version:(int32_t)version impactId:(int32_t)impactId totalBlePacketCountSinceDeviceStart:(uint16_t)totalBlePacketCountSinceDeviceStart __attribute__((swift_name("init(rawContent:version:impactId:totalBlePacketCountSinceDeviceStart:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformBleHeaderStartCompanion *companion __attribute__((swift_name("companion")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.StartCompanion")))
@interface DynamicsMultiplatformBleHeaderStartCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBleHeaderStartCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *BLE_HEADER_START __attribute__((swift_name("BLE_HEADER_START")));
@end


/**
 * Represents a packet within an [ImpactDataPacket].
 *
 * @property currentPacketCount The current packet number of the impact.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleHeader.Within")))
@interface DynamicsMultiplatformBleHeaderWithin : DynamicsMultiplatformBleHeader
- (instancetype)initWithRawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent version:(int32_t)version impactId:(int32_t)impactId totalBlePacketCountSinceDeviceStart:(uint16_t)totalBlePacketCountSinceDeviceStart __attribute__((swift_name("init(rawContent:version:impactId:totalBlePacketCountSinceDeviceStart:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *type __attribute__((swift_name("type")));
@end


/**
 * Represents a packet of data sent over BLE.
 *
 * Every packet starts with a [BleHeader].
 * The total size of the packet (incl. header) cannot exceed 247 bytes.
 *
 * @property bleHeader The header of the packet.
 * @property rawContent The raw content of the packet.
 * @property instant The timestamp when this objet was created.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlePacket")))
@interface DynamicsMultiplatformBlePacket : DynamicsMultiplatformBase
- (instancetype)initWithBleHeader:(DynamicsMultiplatformBleHeader *)bleHeader rawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent instant:(DynamicsMultiplatformKotlinInstant *)instant __attribute__((swift_name("init(bleHeader:rawContent:instant:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBlePacket *)doCopyBleHeader:(DynamicsMultiplatformBleHeader *)bleHeader rawContent:(DynamicsMultiplatformKotlinByteArray *)rawContent instant:(DynamicsMultiplatformKotlinInstant *)instant __attribute__((swift_name("doCopy(bleHeader:rawContent:instant:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformBleHeader *bleHeader __attribute__((swift_name("bleHeader")));
@property (readonly) DynamicsMultiplatformKotlinByteArray *rawContent __attribute__((swift_name("rawContent")));
@end


/**
 * Represents the result of a CRC-16 check.
 *
 * @property expectedCRC The expected CRC value taken from the packet.
 * @property actualCRC The actual CRC value calculated from the packet.
 * @property isValid Whether or not the CRC check has succeeded (i.e. [expectedCRC] == [actualCRC]).
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CRCResult")))
@interface DynamicsMultiplatformCRCResult : DynamicsMultiplatformBase
- (instancetype)initWithExpectedCRC:(uint16_t)expectedCRC actualCRC:(uint16_t)actualCRC isValid:(BOOL)isValid __attribute__((swift_name("init(expectedCRC:actualCRC:isValid:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformCRCResult *)doCopyExpectedCRC:(uint16_t)expectedCRC actualCRC:(uint16_t)actualCRC isValid:(BOOL)isValid __attribute__((swift_name("doCopy(expectedCRC:actualCRC:isValid:)")));

/**
 * Represents the result of a CRC-16 check.
 *
 * @property expectedCRC The expected CRC value taken from the packet.
 * @property actualCRC The actual CRC value calculated from the packet.
 * @property isValid Whether or not the CRC check has succeeded (i.e. [expectedCRC] == [actualCRC]).
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the result of a CRC-16 check.
 *
 * @property expectedCRC The expected CRC value taken from the packet.
 * @property actualCRC The actual CRC value calculated from the packet.
 * @property isValid Whether or not the CRC check has succeeded (i.e. [expectedCRC] == [actualCRC]).
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the result of a CRC-16 check.
 *
 * @property expectedCRC The expected CRC value taken from the packet.
 * @property actualCRC The actual CRC value calculated from the packet.
 * @property isValid Whether or not the CRC check has succeeded (i.e. [expectedCRC] == [actualCRC]).
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint16_t actualCRC __attribute__((swift_name("actualCRC")));
@property (readonly) uint16_t expectedCRC __attribute__((swift_name("expectedCRC")));
@property (readonly) BOOL isValid __attribute__((swift_name("isValid")));
@end


/**
 * Represents a data packet of the dynamics data pipe protocol.
 *
 * A data packet may contain number of measurements from the accelerometer, gyroscope, barometer and
 * or magnetometer.
 *
 * The minimum size of a data packet is [HEADER_SIZE] bytes.
 *
 * @property preTrigger This is set to 1 if the packet contains pre-trigger data.
 * After the instant of trigger, this is always 0.
 * @property samplingRate The sampling rate of the data packet.
 * @property baroData A list of barometer measurements.
 * @property accData A list of [Vector3d] measurements.
 * @property gyroData A list of [Vector3d] measurements.
 * @property magnetoData A list of [Vector3d] measurements.
 * @property packetSize The size of the packet in bytes.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataPacket")))
@interface DynamicsMultiplatformDataPacket : DynamicsMultiplatformBase
- (instancetype)initWithPreTrigger:(BOOL)preTrigger samplingRate:(DynamicsMultiplatformSensorSamplingRate *)samplingRate baroData:(NSArray<DynamicsMultiplatformUShort *> *)baroData accData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)accData gyroData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)gyroData magnetoData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)magnetoData packetSize:(int32_t)packetSize __attribute__((swift_name("init(preTrigger:samplingRate:baroData:accData:gyroData:magnetoData:packetSize:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDataPacketCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDataPacket *)doCopyPreTrigger:(BOOL)preTrigger samplingRate:(DynamicsMultiplatformSensorSamplingRate *)samplingRate baroData:(NSArray<DynamicsMultiplatformUShort *> *)baroData accData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)accData gyroData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)gyroData magnetoData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *)magnetoData packetSize:(int32_t)packetSize __attribute__((swift_name("doCopy(preTrigger:samplingRate:baroData:accData:gyroData:magnetoData:packetSize:)")));

/**
 * Represents a data packet of the dynamics data pipe protocol.
 *
 * A data packet may contain number of measurements from the accelerometer, gyroscope, barometer and
 * or magnetometer.
 *
 * The minimum size of a data packet is [HEADER_SIZE] bytes.
 *
 * @property preTrigger This is set to 1 if the packet contains pre-trigger data.
 * After the instant of trigger, this is always 0.
 * @property samplingRate The sampling rate of the data packet.
 * @property baroData A list of barometer measurements.
 * @property accData A list of [Vector3d] measurements.
 * @property gyroData A list of [Vector3d] measurements.
 * @property magnetoData A list of [Vector3d] measurements.
 * @property packetSize The size of the packet in bytes.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents a data packet of the dynamics data pipe protocol.
 *
 * A data packet may contain number of measurements from the accelerometer, gyroscope, barometer and
 * or magnetometer.
 *
 * The minimum size of a data packet is [HEADER_SIZE] bytes.
 *
 * @property preTrigger This is set to 1 if the packet contains pre-trigger data.
 * After the instant of trigger, this is always 0.
 * @property samplingRate The sampling rate of the data packet.
 * @property baroData A list of barometer measurements.
 * @property accData A list of [Vector3d] measurements.
 * @property gyroData A list of [Vector3d] measurements.
 * @property magnetoData A list of [Vector3d] measurements.
 * @property packetSize The size of the packet in bytes.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a data packet of the dynamics data pipe protocol.
 *
 * A data packet may contain number of measurements from the accelerometer, gyroscope, barometer and
 * or magnetometer.
 *
 * The minimum size of a data packet is [HEADER_SIZE] bytes.
 *
 * @property preTrigger This is set to 1 if the packet contains pre-trigger data.
 * After the instant of trigger, this is always 0.
 * @property samplingRate The sampling rate of the data packet.
 * @property baroData A list of barometer measurements.
 * @property accData A list of [Vector3d] measurements.
 * @property gyroData A list of [Vector3d] measurements.
 * @property magnetoData A list of [Vector3d] measurements.
 * @property packetSize The size of the packet in bytes.
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *accData __attribute__((swift_name("accData")));
@property (readonly) NSArray<DynamicsMultiplatformUShort *> *baroData __attribute__((swift_name("baroData")));
@property (readonly) NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *gyroData __attribute__((swift_name("gyroData")));
@property (readonly) NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformShort *> *> *magnetoData __attribute__((swift_name("magnetoData")));
@property (readonly) int32_t packetSize __attribute__((swift_name("packetSize")));
@property (readonly) BOOL preTrigger __attribute__((swift_name("preTrigger")));
@property (readonly) DynamicsMultiplatformSensorSamplingRate *samplingRate __attribute__((swift_name("samplingRate")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataPacket.Companion")))
@interface DynamicsMultiplatformDataPacketCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDataPacketCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t HEADER_SIZE __attribute__((swift_name("HEADER_SIZE")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("DataPipePacket")))
@interface DynamicsMultiplatformDataPipePacket : DynamicsMultiplatformBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataPipePacket.DataPipeProtocol")))
@interface DynamicsMultiplatformDataPipePacketDataPipeProtocol : DynamicsMultiplatformDataPipePacket
- (instancetype)initWithBlePacket:(DynamicsMultiplatformBlePacket *)blePacket __attribute__((swift_name("init(blePacket:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDataPipePacketDataPipeProtocol *)doCopyBlePacket:(DynamicsMultiplatformBlePacket *)blePacket __attribute__((swift_name("doCopy(blePacket:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformBlePacket *blePacket __attribute__((swift_name("blePacket")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataPipePacket.Raw")))
@interface DynamicsMultiplatformDataPipePacketRaw : DynamicsMultiplatformDataPipePacket
- (instancetype)initWithRawDataPipePacket:(DynamicsMultiplatformRawDataPipePacket *)rawDataPipePacket __attribute__((swift_name("init(rawDataPipePacket:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDataPipePacketRaw *)doCopyRawDataPipePacket:(DynamicsMultiplatformRawDataPipePacket *)rawDataPipePacket __attribute__((swift_name("doCopy(rawDataPipePacket:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformRawDataPipePacket *rawDataPipePacket __attribute__((swift_name("rawDataPipePacket")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveWithSensorData")))
@interface DynamicsMultiplatformGloveWithSensorData : DynamicsMultiplatformBase
- (instancetype)initWithPeripheralId:(id)peripheralId sensorDataPackets:(NSArray<DynamicsMultiplatformSensorDataPacket *> *)sensorDataPackets __attribute__((swift_name("init(peripheralId:sensorDataPackets:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveWithSensorData *)doCopyPeripheralId:(id)peripheralId sensorDataPackets:(NSArray<DynamicsMultiplatformSensorDataPacket *> *)sensorDataPackets __attribute__((swift_name("doCopy(peripheralId:sensorDataPackets:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id peripheralId __attribute__((swift_name("peripheralId")));
@property (readonly) NSArray<DynamicsMultiplatformSensorDataPacket *> *sensorDataPackets __attribute__((swift_name("sensorDataPackets")));
@end


/**
 * Represents a candidate impact data packet with [blePackets] with either one these states:
 *
 * - [MergeFailed] the merging of the [BlePacket] has failed.
 * - [CRCCheckFailed] the CRC check has failed.
 * - [InvalidData] the CRC has succeeded, but the data is invalid as it violates some constraints.
 * - [Success] the [blePackets] are successfully parsed into a fully intact impact data packet.
 */
__attribute__((swift_name("ImpactDataPacket")))
@interface DynamicsMultiplatformImpactDataPacket : DynamicsMultiplatformBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isPacketNotEmpty __attribute__((swift_name("isPacketNotEmpty()")));
- (BOOL)isPacketValid __attribute__((swift_name("isPacketValid()")));

/**
 * @return the timestamp taken by the app for the very first ble packet.
 */
@property (readonly) DynamicsMultiplatformKotlinInstant *appTimeStamp __attribute__((swift_name("appTimeStamp")));
@property (readonly) NSArray<DynamicsMultiplatformBlePacket *> *blePackets __attribute__((swift_name("blePackets")));

/**
 * The raw content of the impact header and the data packets. This doesn't contain the
 * [BleHeader].
 */
@property (readonly) DynamicsMultiplatformKotlinByteArray *dataRawContent __attribute__((swift_name("dataRawContent")));
@property (readonly) DynamicsMultiplatformKotlinUuid *id __attribute__((swift_name("id")));

/**
 * The full raw content of all packets from [blePackets]. This also contains the [BleHeader].
 */
@property (readonly) DynamicsMultiplatformKotlinByteArray *rawContent __attribute__((swift_name("rawContent")));

/**
 * The total size of the [ImpactDataPacket] in bytes.
 */
@property (readonly) int32_t totalSize __attribute__((swift_name("totalSize")));

/**
 * The transmission meta data.
 */
@property (readonly) DynamicsMultiplatformImpactDataTransmission *transmission __attribute__((swift_name("transmission")));
@end


/**
 * Represents a [ImpactDataPacket] where the CRC check failed.
 *
 * @property expectedCRC The expected CRC taken from [ImpactHeader.CRC_OFFSET].
 * @property actualCRC The actual (calculated) CRC.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.CRCCheckFailed")))
@interface DynamicsMultiplatformImpactDataPacketCRCCheckFailed : DynamicsMultiplatformImpactDataPacket
- (instancetype)initWithBlePackets:(NSArray<DynamicsMultiplatformBlePacket *> *)blePackets expectedCRC:(uint16_t)expectedCRC actualCRC:(uint16_t)actualCRC __attribute__((swift_name("init(blePackets:expectedCRC:actualCRC:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint16_t actualCRC __attribute__((swift_name("actualCRC")));
@property (readonly) uint16_t expectedCRC __attribute__((swift_name("expectedCRC")));
@end


/**
 * Represents a [ImpactDataPacket] where data validation failed.
 *
 * @property reason The reason why the data validation failed.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.InvalidData")))
@interface DynamicsMultiplatformImpactDataPacketInvalidData : DynamicsMultiplatformImpactDataPacket
- (instancetype)initWithBlePackets:(NSArray<DynamicsMultiplatformBlePacket *> *)blePackets reason:(DynamicsMultiplatformImpactDataPacketReason *)reason cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(blePackets:reason:cause:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) DynamicsMultiplatformImpactDataPacketReason *reason __attribute__((swift_name("reason")));
@end


/**
 * Merging of subsequent data packets has failed before the CRC check was even performed.
 *
 * This happens if either packets are dropped or the firmware sends wrong packet types, for
 * example this error is raised if a packet of type [BleHeader.Start] is followed by
 * [BleHeader.Start] again.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.MergeFailed")))
@interface DynamicsMultiplatformImpactDataPacketMergeFailed : DynamicsMultiplatformImpactDataPacket
- (instancetype)initWithBlePackets:(NSArray<DynamicsMultiplatformBlePacket *> *)blePackets reason:(DynamicsMultiplatformImpactDataPacketReason *)reason cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(blePackets:reason:cause:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) DynamicsMultiplatformImpactDataPacketReason *reason __attribute__((swift_name("reason")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.None")))
@interface DynamicsMultiplatformImpactDataPacketNone : DynamicsMultiplatformImpactDataPacket
- (instancetype)initWithBlePackets:(NSArray<DynamicsMultiplatformBlePacket *> *)blePackets __attribute__((swift_name("init(blePackets:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.Reason")))
@interface DynamicsMultiplatformImpactDataPacketReason : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformImpactDataPacketReason *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *emptyOrTooSmall __attribute__((swift_name("emptyOrTooSmall")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *packetTypeIncorrect __attribute__((swift_name("packetTypeIncorrect")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *packetTypeImpactIdInconsistent __attribute__((swift_name("packetTypeImpactIdInconsistent")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *packetTimeout __attribute__((swift_name("packetTimeout")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *packetPreTriggerNotContinuous __attribute__((swift_name("packetPreTriggerNotContinuous")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *actualPacketSizeNotEqualToPacketSizeInHeader __attribute__((swift_name("actualPacketSizeNotEqualToPacketSizeInHeader")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *packetDecoderError __attribute__((swift_name("packetDecoderError")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *dataPacketOverflow __attribute__((swift_name("dataPacketOverflow")));
@property (class, readonly) DynamicsMultiplatformImpactDataPacketReason *unexpectedError __attribute__((swift_name("unexpectedError")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformImpactDataPacketReason *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformImpactDataPacketReason *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Represents a successful [ImpactDataPacket].
 *
 * @property impactHeader The header of the packet.
 * @property dataPackets The data packets of the packet.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacket.Success")))
@interface DynamicsMultiplatformImpactDataPacketSuccess : DynamicsMultiplatformImpactDataPacket
- (instancetype)initWithBlePackets:(NSArray<DynamicsMultiplatformBlePacket *> *)blePackets impactHeader:(DynamicsMultiplatformImpactHeader *)impactHeader dataPackets:(NSArray<DynamicsMultiplatformDataPacket *> *)dataPackets __attribute__((swift_name("init(blePackets:impactHeader:dataPackets:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DynamicsMultiplatformDataPacket *> *dataPackets __attribute__((swift_name("dataPackets")));
@property (readonly) DynamicsMultiplatformImpactHeader *impactHeader __attribute__((swift_name("impactHeader")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacketSimplified")))
@interface DynamicsMultiplatformImpactDataPacketSimplified : DynamicsMultiplatformBase
- (instancetype)initWithHeader:(DynamicsMultiplatformImpactHeader *)header packets:(NSArray<DynamicsMultiplatformDataPacket *> *)packets __attribute__((swift_name("init(header:packets:)"))) __attribute__((objc_designated_initializer));
@property (readonly) DynamicsMultiplatformImpactHeader *header __attribute__((swift_name("header")));
@property (readonly) NSArray<DynamicsMultiplatformDataPacket *> *packets __attribute__((swift_name("packets")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataTransmission")))
@interface DynamicsMultiplatformImpactDataTransmission : DynamicsMultiplatformBase
- (instancetype)initWithImpactDataPacket:(DynamicsMultiplatformImpactDataPacket *)impactDataPacket __attribute__((swift_name("init(impactDataPacket:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformImpactDataTransmission *)doCopyImpactDataPacket:(DynamicsMultiplatformImpactDataPacket *)impactDataPacket __attribute__((swift_name("doCopy(impactDataPacket:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @return the transmission offsets between each adjacent [BlePacket].
 */
@property (readonly) NSArray<DynamicsMultiplatformLong *> *transmissionOffsetsInMs __attribute__((swift_name("transmissionOffsetsInMs")));
@end


/**
 * Represents the header of an [ImpactDataPacket.Success].
 *
 * The [ImpactDataPacket.rawContent] must always start with a [ImpactHeader].
 *
 * The [SIZE] of the header is fixed.
 *
 * There are two versions known:
 * - [version] == 0 from the first hardware revision, where the sampling rate was varying, and the
 * baro sampling started in the post trigger region.
 * - [version] == 1 from the second hardware revision, where the sampling rate is stable, all
 * sensor are sampling. magneto sensor values are included.
 *
 * @property packetSize The size of the packet (incl. header) in bytes (max. 2^14 bytes = 16kByte).
 * @property version The version of the packet.
 * @property crc The CRC of the packet. When calculating the CRC, the CRC bytes must be set to 0.
 * @property timestamp The timestamp of the packet with a resolution of 0.100 seconds.
 * @property counter The counter of the packet. Rolls over at 0xFFFF.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactHeader")))
@interface DynamicsMultiplatformImpactHeader : DynamicsMultiplatformBase
- (instancetype)initWithPacketSize:(uint16_t)packetSize version:(uint16_t)version crc:(uint16_t)crc timestamp:(uint32_t)timestamp counter:(uint16_t)counter __attribute__((swift_name("init(packetSize:version:crc:timestamp:counter:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformImpactHeaderCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformImpactHeader *)doCopyPacketSize:(uint16_t)packetSize version:(uint16_t)version crc:(uint16_t)crc timestamp:(uint32_t)timestamp counter:(uint16_t)counter __attribute__((swift_name("doCopy(packetSize:version:crc:timestamp:counter:)")));

/**
 * Represents the header of an [ImpactDataPacket.Success].
 *
 * The [ImpactDataPacket.rawContent] must always start with a [ImpactHeader].
 *
 * The [SIZE] of the header is fixed.
 *
 * There are two versions known:
 * - [version] == 0 from the first hardware revision, where the sampling rate was varying, and the
 * baro sampling started in the post trigger region.
 * - [version] == 1 from the second hardware revision, where the sampling rate is stable, all
 * sensor are sampling. magneto sensor values are included.
 *
 * @property packetSize The size of the packet (incl. header) in bytes (max. 2^14 bytes = 16kByte).
 * @property version The version of the packet.
 * @property crc The CRC of the packet. When calculating the CRC, the CRC bytes must be set to 0.
 * @property timestamp The timestamp of the packet with a resolution of 0.100 seconds.
 * @property counter The counter of the packet. Rolls over at 0xFFFF.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the header of an [ImpactDataPacket.Success].
 *
 * The [ImpactDataPacket.rawContent] must always start with a [ImpactHeader].
 *
 * The [SIZE] of the header is fixed.
 *
 * There are two versions known:
 * - [version] == 0 from the first hardware revision, where the sampling rate was varying, and the
 * baro sampling started in the post trigger region.
 * - [version] == 1 from the second hardware revision, where the sampling rate is stable, all
 * sensor are sampling. magneto sensor values are included.
 *
 * @property packetSize The size of the packet (incl. header) in bytes (max. 2^14 bytes = 16kByte).
 * @property version The version of the packet.
 * @property crc The CRC of the packet. When calculating the CRC, the CRC bytes must be set to 0.
 * @property timestamp The timestamp of the packet with a resolution of 0.100 seconds.
 * @property counter The counter of the packet. Rolls over at 0xFFFF.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint16_t counter __attribute__((swift_name("counter")));
@property (readonly) uint16_t crc __attribute__((swift_name("crc")));
@property (readonly) uint16_t packetSize __attribute__((swift_name("packetSize")));

/**
 * [timestamp] multiplied by [RELATIVE_TIME_COUNTER_TICK_DURATION].
 */
@property (readonly) int64_t timeStampAsRelativeDuration __attribute__((swift_name("timeStampAsRelativeDuration")));
@property (readonly) uint32_t timestamp __attribute__((swift_name("timestamp")));
@property (readonly) uint16_t version __attribute__((swift_name("version")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactHeader.Companion")))
@interface DynamicsMultiplatformImpactHeaderCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformImpactHeaderCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t CRC_OFFSET __attribute__((swift_name("CRC_OFFSET")));
@property (readonly) DynamicsMultiplatformImpactHeader *EMPTY __attribute__((swift_name("EMPTY")));
@property (readonly) int32_t SIZE __attribute__((swift_name("SIZE")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunchExport")))
@interface DynamicsMultiplatformPunchExport : DynamicsMultiplatformBase
- (instancetype)initWithAbsolutePathToCsv:(NSString *)absolutePathToCsv __attribute__((swift_name("init(absolutePathToCsv:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPunchExport *)doCopyAbsolutePathToCsv:(NSString *)absolutePathToCsv __attribute__((swift_name("doCopy(absolutePathToCsv:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *absolutePathToCsv __attribute__((swift_name("absolutePathToCsv")));
@end


/**
 * Represents raw data packets for testing purposes of the data test pipe.
 *
 * @property instant The timestamp of the packet, set by the client.
 * @property counter The counter of the packet. Rolls over at 0xFFFF.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RawDataPipePacket")))
@interface DynamicsMultiplatformRawDataPipePacket : DynamicsMultiplatformBase
- (instancetype)initWithInstant:(DynamicsMultiplatformKotlinInstant *)instant data:(DynamicsMultiplatformKotlinByteArray *)data __attribute__((swift_name("init(instant:data:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformRawDataPipePacketCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformRawDataPipePacket *)doCopyInstant:(DynamicsMultiplatformKotlinInstant *)instant data:(DynamicsMultiplatformKotlinByteArray *)data __attribute__((swift_name("doCopy(instant:data:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t counter __attribute__((swift_name("counter")));
@property (readonly) DynamicsMultiplatformKotlinByteArray *data __attribute__((swift_name("data")));
@property (readonly) NSString *dataAsHex __attribute__((swift_name("dataAsHex")));
@property (readonly) int32_t dataSize __attribute__((swift_name("dataSize")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RawDataPipePacket.Companion")))
@interface DynamicsMultiplatformRawDataPipePacketCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformRawDataPipePacketCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformRawDataPipePacket *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents a sensor data packet of the dynamics data pipe protocol.
 *
 * Each sensor has an own sampling rate defined by [samplingRate] except for [magnetoData] which
 * always operates at [SensorSamplingRate.MAX_MAGNETO_FREQUENCY] hertz.
 *
 * **Important:** Do not assume that the time axis is normalized across different sensors.
 *
 * @property relativeTimeCounter The relative time counter of the packet. The glove's clock tick is
 * 100 ms (see RELATIVE_TIME_COUNTER_TICK_DURATION), i.e. this is the finest level of time
 * resolution. Note that multiple [SensorDataPacket]s may have the same [relativeTimeCounter]
 * as there are sent within the same 100ms window.
 * @property samplingRate The sampling rate of the samples that is being sent within each
 * [SensorDataPacket], currently [SensorSamplingRate] is always [SensorSamplingRate.HIGH].
 * @property baroData A list of barometer sensor measurements in P (Pascal).
 * @property accData A list acceleration sensor measurements in m/s^2 (Meters per second squared).
 * @property gyroData A list of gyroscope sensor measurements in °/s (Degrees per second).
 * @property magnetoData A list of magneto sensor measurements in µT (MicroTesla). The sampling rate
 * is [SensorSamplingRate.MAX_MAGNETO_FREQUENCY].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorDataPacket")))
@interface DynamicsMultiplatformSensorDataPacket : DynamicsMultiplatformBase
- (instancetype)initWithRelativeTimeCounter:(int64_t)relativeTimeCounter bleCounter:(int32_t)bleCounter samplingRate:(DynamicsMultiplatformSensorSamplingRate *)samplingRate baroData:(NSArray<DynamicsMultiplatformInt *> *)baroData accData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)accData gyroData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)gyroData magnetoData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)magnetoData __attribute__((swift_name("init(relativeTimeCounter:bleCounter:samplingRate:baroData:accData:gyroData:magnetoData:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSensorDataPacket *)doCopyRelativeTimeCounter:(int64_t)relativeTimeCounter bleCounter:(int32_t)bleCounter samplingRate:(DynamicsMultiplatformSensorSamplingRate *)samplingRate baroData:(NSArray<DynamicsMultiplatformInt *> *)baroData accData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)accData gyroData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)gyroData magnetoData:(NSArray<DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *> *)magnetoData __attribute__((swift_name("doCopy(relativeTimeCounter:bleCounter:samplingRate:baroData:accData:gyroData:magnetoData:)")));

/**
 * Represents a sensor data packet of the dynamics data pipe protocol.
 *
 * Each sensor has an own sampling rate defined by [samplingRate] except for [magnetoData] which
 * always operates at [SensorSamplingRate.MAX_MAGNETO_FREQUENCY] hertz.
 *
 * **Important:** Do not assume that the time axis is normalized across different sensors.
 *
 * @property relativeTimeCounter The relative time counter of the packet. The glove's clock tick is
 * 100 ms (see RELATIVE_TIME_COUNTER_TICK_DURATION), i.e. this is the finest level of time
 * resolution. Note that multiple [SensorDataPacket]s may have the same [relativeTimeCounter]
 * as there are sent within the same 100ms window.
 * @property samplingRate The sampling rate of the samples that is being sent within each
 * [SensorDataPacket], currently [SensorSamplingRate] is always [SensorSamplingRate.HIGH].
 * @property baroData A list of barometer sensor measurements in P (Pascal).
 * @property accData A list acceleration sensor measurements in m/s^2 (Meters per second squared).
 * @property gyroData A list of gyroscope sensor measurements in °/s (Degrees per second).
 * @property magnetoData A list of magneto sensor measurements in µT (MicroTesla). The sampling rate
 * is [SensorSamplingRate.MAX_MAGNETO_FREQUENCY].
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents a sensor data packet of the dynamics data pipe protocol.
 *
 * Each sensor has an own sampling rate defined by [samplingRate] except for [magnetoData] which
 * always operates at [SensorSamplingRate.MAX_MAGNETO_FREQUENCY] hertz.
 *
 * **Important:** Do not assume that the time axis is normalized across different sensors.
 *
 * @property relativeTimeCounter The relative time counter of the packet. The glove's clock tick is
 * 100 ms (see RELATIVE_TIME_COUNTER_TICK_DURATION), i.e. this is the finest level of time
 * resolution. Note that multiple [SensorDataPacket]s may have the same [relativeTimeCounter]
 * as there are sent within the same 100ms window.
 * @property samplingRate The sampling rate of the samples that is being sent within each
 * [SensorDataPacket], currently [SensorSamplingRate] is always [SensorSamplingRate.HIGH].
 * @property baroData A list of barometer sensor measurements in P (Pascal).
 * @property accData A list acceleration sensor measurements in m/s^2 (Meters per second squared).
 * @property gyroData A list of gyroscope sensor measurements in °/s (Degrees per second).
 * @property magnetoData A list of magneto sensor measurements in µT (MicroTesla). The sampling rate
 * is [SensorSamplingRate.MAX_MAGNETO_FREQUENCY].
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a sensor data packet of the dynamics data pipe protocol.
 *
 * Each sensor has an own sampling rate defined by [samplingRate] except for [magnetoData] which
 * always operates at [SensorSamplingRate.MAX_MAGNETO_FREQUENCY] hertz.
 *
 * **Important:** Do not assume that the time axis is normalized across different sensors.
 *
 * @property relativeTimeCounter The relative time counter of the packet. The glove's clock tick is
 * 100 ms (see RELATIVE_TIME_COUNTER_TICK_DURATION), i.e. this is the finest level of time
 * resolution. Note that multiple [SensorDataPacket]s may have the same [relativeTimeCounter]
 * as there are sent within the same 100ms window.
 * @property samplingRate The sampling rate of the samples that is being sent within each
 * [SensorDataPacket], currently [SensorSamplingRate] is always [SensorSamplingRate.HIGH].
 * @property baroData A list of barometer sensor measurements in P (Pascal).
 * @property accData A list acceleration sensor measurements in m/s^2 (Meters per second squared).
 * @property gyroData A list of gyroscope sensor measurements in °/s (Degrees per second).
 * @property magnetoData A list of magneto sensor measurements in µT (MicroTesla). The sampling rate
 * is [SensorSamplingRate.MAX_MAGNETO_FREQUENCY].
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DynamicsMultiplatformInt *> *baroData __attribute__((swift_name("baroData")));
@property (readonly) int32_t bleCounter __attribute__((swift_name("bleCounter")));
@property (readonly) int64_t relativeTimeCounter __attribute__((swift_name("relativeTimeCounter")));
@property (readonly) DynamicsMultiplatformSensorSamplingRate *samplingRate __attribute__((swift_name("samplingRate")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorSamplingRate")))
@interface DynamicsMultiplatformSensorSamplingRate : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformSensorSamplingRate *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) DynamicsMultiplatformSensorSamplingRateCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) DynamicsMultiplatformSensorSamplingRate *accStream __attribute__((swift_name("accStream")));
@property (class, readonly) DynamicsMultiplatformSensorSamplingRate *low __attribute__((swift_name("low")));
@property (class, readonly) DynamicsMultiplatformSensorSamplingRate *high __attribute__((swift_name("high")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformSensorSamplingRate *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformSensorSamplingRate *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t baroFrequency __attribute__((swift_name("baroFrequency")));
@property (readonly) int32_t imuFrequency __attribute__((swift_name("imuFrequency")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorSamplingRate.Companion")))
@interface DynamicsMultiplatformSensorSamplingRateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformSensorSamplingRateCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t MAX_MAGNETO_FREQUENCY __attribute__((swift_name("MAX_MAGNETO_FREQUENCY")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTest")))
@interface DynamicsMultiplatformThroughputTest : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id rawDataPipePacket:(DynamicsMultiplatformRawDataPipePacket *)rawDataPipePacket bytesPerSecond:(int32_t)bytesPerSecond rssi:(int32_t)rssi __attribute__((swift_name("init(id:rawDataPipePacket:bytesPerSecond:rssi:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformThroughputTest *)doCopyId:(id)id rawDataPipePacket:(DynamicsMultiplatformRawDataPipePacket *)rawDataPipePacket bytesPerSecond:(int32_t)bytesPerSecond rssi:(int32_t)rssi __attribute__((swift_name("doCopy(id:rawDataPipePacket:bytesPerSecond:rssi:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bytesPerSecond __attribute__((swift_name("bytesPerSecond")));
@property (readonly) DynamicsMultiplatformKotlinInstant *instant __attribute__((swift_name("instant")));
@property (readonly) DynamicsMultiplatformRawDataPipePacket *rawDataPipePacket __attribute__((swift_name("rawDataPipePacket")));
@property (readonly) int32_t rssi __attribute__((swift_name("rssi")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTestDto")))
@interface DynamicsMultiplatformThroughputTestDto : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id peripheralId:(id)peripheralId startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime mtu:(int32_t)mtu text:(NSString * _Nullable)text __attribute__((swift_name("init(id:peripheralId:startDateTime:mtu:text:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformThroughputTestDto *)doCopyId:(id)id peripheralId:(id)peripheralId startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime mtu:(int32_t)mtu text:(NSString * _Nullable)text __attribute__((swift_name("doCopy(id:peripheralId:startDateTime:mtu:text:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t mtu __attribute__((swift_name("mtu")));
@property (readonly) NSString * _Nullable text __attribute__((swift_name("text")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTestEventDto")))
@interface DynamicsMultiplatformThroughputTestEventDto : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id instant:(DynamicsMultiplatformKotlinInstant *)instant bytesPerSecond:(int32_t)bytesPerSecond rssi:(int32_t)rssi __attribute__((swift_name("init(id:instant:bytesPerSecond:rssi:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformThroughputTestEventDto *)doCopyId:(id)id instant:(DynamicsMultiplatformKotlinInstant *)instant bytesPerSecond:(int32_t)bytesPerSecond rssi:(int32_t)rssi __attribute__((swift_name("doCopy(id:instant:bytesPerSecond:rssi:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t bytesPerSecond __attribute__((swift_name("bytesPerSecond")));
@property (readonly) id id __attribute__((swift_name("id")));
@property (readonly) int32_t rssi __attribute__((swift_name("rssi")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTestExport")))
@interface DynamicsMultiplatformThroughputTestExport : DynamicsMultiplatformBase
- (instancetype)initWithAbsolutePathToCsv:(NSString *)absolutePathToCsv __attribute__((swift_name("init(absolutePathToCsv:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformThroughputTestExport *)doCopyAbsolutePathToCsv:(NSString *)absolutePathToCsv __attribute__((swift_name("doCopy(absolutePathToCsv:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *absolutePathToCsv __attribute__((swift_name("absolutePathToCsv")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3d")))
@interface DynamicsMultiplatformVector3d<T> : DynamicsMultiplatformBase
- (instancetype)initWithX:(T _Nullable)x y:(T _Nullable)y z:(T _Nullable)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformVector3dCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformVector3d<T> *)doCopyX:(T _Nullable)x y:(T _Nullable)y z:(T _Nullable)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) T _Nullable x __attribute__((swift_name("x")));
@property (readonly) T _Nullable y __attribute__((swift_name("y")));
@property (readonly) T _Nullable z __attribute__((swift_name("z")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dCompanion")))
@interface DynamicsMultiplatformVector3dCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformVector3dCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *EMPTY_D __attribute__((swift_name("EMPTY_D")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dBoolean")))
@interface DynamicsMultiplatformVector3dBoolean : DynamicsMultiplatformBase
- (instancetype)initWithX:(BOOL)x y:(BOOL)y z:(BOOL)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformVector3dBoolean *)doCopyX:(BOOL)x y:(BOOL)y z:(BOOL)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL x __attribute__((swift_name("x")));
@property (readonly) BOOL y __attribute__((swift_name("y")));
@property (readonly) BOOL z __attribute__((swift_name("z")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dDouble")))
@interface DynamicsMultiplatformVector3dDouble : DynamicsMultiplatformBase
- (instancetype)initWithX:(double)x y:(double)y z:(double)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformVector3dDoubleCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformVector3dDouble *)doCopyX:(double)x y:(double)y z:(double)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double x __attribute__((swift_name("x")));
@property (readonly) double y __attribute__((swift_name("y")));
@property (readonly) double z __attribute__((swift_name("z")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dDouble.Companion")))
@interface DynamicsMultiplatformVector3dDoubleCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformVector3dDoubleCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformVector3dDouble *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dInt")))
@interface DynamicsMultiplatformVector3dInt : DynamicsMultiplatformBase
- (instancetype)initWithX:(int32_t)x y:(int32_t)y z:(int32_t)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformVector3dInt *)doCopyX:(int32_t)x y:(int32_t)y z:(int32_t)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t x __attribute__((swift_name("x")));
@property (readonly) int32_t y __attribute__((swift_name("y")));
@property (readonly) int32_t z __attribute__((swift_name("z")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dMicroTesla")))
@interface DynamicsMultiplatformVector3dMicroTesla : DynamicsMultiplatformBase
- (instancetype)initWithX:(double)x y:(double)y z:(double)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformVector3dMicroTesla *)doCopyX:(double)x y:(double)y z:(double)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double x __attribute__((swift_name("x")));
@property (readonly) double y __attribute__((swift_name("y")));
@property (readonly) double z __attribute__((swift_name("z")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dQ15")))
@interface DynamicsMultiplatformVector3dQ15 : DynamicsMultiplatformBase
- (instancetype)initWithX:(float)x y:(float)y z:(float)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformVector3dQ15 *)doCopyX:(float)x y:(float)y z:(float)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) float x __attribute__((swift_name("x")));
@property (readonly) float y __attribute__((swift_name("y")));
@property (readonly) float z __attribute__((swift_name("z")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Vector3dShort")))
@interface DynamicsMultiplatformVector3dShort : DynamicsMultiplatformBase
- (instancetype)initWithX:(int16_t)x y:(int16_t)y z:(int16_t)z __attribute__((swift_name("init(x:y:z:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformVector3dShort *)doCopyX:(int16_t)x y:(int16_t)y z:(int16_t)z __attribute__((swift_name("doCopy(x:y:z:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int16_t x __attribute__((swift_name("x")));
@property (readonly) int16_t y __attribute__((swift_name("y")));
@property (readonly) int16_t z __attribute__((swift_name("z")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExtendedDeviceInfo")))
@interface DynamicsMultiplatformExtendedDeviceInfo : DynamicsMultiplatformBase
- (instancetype)initWithModelNumber:(NSString *)modelNumber serialNumber:(NSString *)serialNumber firmwareRevision:(NSString *)firmwareRevision hardwareRevision:(NSString *)hardwareRevision manufacturerName:(NSString *)manufacturerName deviceName:(NSString *)deviceName __attribute__((swift_name("init(modelNumber:serialNumber:firmwareRevision:hardwareRevision:manufacturerName:deviceName:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformExtendedDeviceInfo *)doCopyModelNumber:(NSString *)modelNumber serialNumber:(NSString *)serialNumber firmwareRevision:(NSString *)firmwareRevision hardwareRevision:(NSString *)hardwareRevision manufacturerName:(NSString *)manufacturerName deviceName:(NSString *)deviceName __attribute__((swift_name("doCopy(modelNumber:serialNumber:firmwareRevision:hardwareRevision:manufacturerName:deviceName:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *deviceName __attribute__((swift_name("deviceName")));
@property (readonly) NSString *firmwareRevision __attribute__((swift_name("firmwareRevision")));
@property (readonly) NSString *hardwareRevision __attribute__((swift_name("hardwareRevision")));
@property (readonly) NSString *manufacturerName __attribute__((swift_name("manufacturerName")));
@property (readonly) NSString *modelNumber __attribute__((swift_name("modelNumber")));
@property (readonly) NSString *serialNumber __attribute__((swift_name("serialNumber")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllImpactConfigs")))
@interface DynamicsMultiplatformAllImpactConfigs : DynamicsMultiplatformBase
- (instancetype)initWithWakeUpTriggerThreshold:(double)wakeUpTriggerThreshold wakeUpTriggerDebounceTime:(int64_t)wakeUpTriggerDebounceTime countOfPreTriggerSamples:(int32_t)countOfPreTriggerSamples countOfPostImpactSamples:(int32_t)countOfPostImpactSamples minimumAbsoluteAccelerationForValidImpact:(double)minimumAbsoluteAccelerationForValidImpact maximumWaitingTimeForValidation:(int64_t)maximumWaitingTimeForValidation magnetoCalibrationOffsetValues:(DynamicsMultiplatformVector3d<id> *)magnetoCalibrationOffsetValues magnetoCalibrationScaleValues:(DynamicsMultiplatformVector3d<id> *)magnetoCalibrationScaleValues backToMeasurementIdleTimeout:(int64_t)backToMeasurementIdleTimeout capDetectionDirection:(DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *)capDetectionDirection capCombination:(DynamicsMultiplatformCapCombination *)capCombination capOptions:(DynamicsMultiplatformCapOptions *)capOptions capShape:(DynamicsMultiplatformCapShape *)capShape __attribute__((swift_name("init(wakeUpTriggerThreshold:wakeUpTriggerDebounceTime:countOfPreTriggerSamples:countOfPostImpactSamples:minimumAbsoluteAccelerationForValidImpact:maximumWaitingTimeForValidation:magnetoCalibrationOffsetValues:magnetoCalibrationScaleValues:backToMeasurementIdleTimeout:capDetectionDirection:capCombination:capOptions:capShape:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformAllImpactConfigs *)doCopyWakeUpTriggerThreshold:(double)wakeUpTriggerThreshold wakeUpTriggerDebounceTime:(int64_t)wakeUpTriggerDebounceTime countOfPreTriggerSamples:(int32_t)countOfPreTriggerSamples countOfPostImpactSamples:(int32_t)countOfPostImpactSamples minimumAbsoluteAccelerationForValidImpact:(double)minimumAbsoluteAccelerationForValidImpact maximumWaitingTimeForValidation:(int64_t)maximumWaitingTimeForValidation magnetoCalibrationOffsetValues:(DynamicsMultiplatformVector3d<id> *)magnetoCalibrationOffsetValues magnetoCalibrationScaleValues:(DynamicsMultiplatformVector3d<id> *)magnetoCalibrationScaleValues backToMeasurementIdleTimeout:(int64_t)backToMeasurementIdleTimeout capDetectionDirection:(DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *)capDetectionDirection capCombination:(DynamicsMultiplatformCapCombination *)capCombination capOptions:(DynamicsMultiplatformCapOptions *)capOptions capShape:(DynamicsMultiplatformCapShape *)capShape __attribute__((swift_name("doCopy(wakeUpTriggerThreshold:wakeUpTriggerDebounceTime:countOfPreTriggerSamples:countOfPostImpactSamples:minimumAbsoluteAccelerationForValidImpact:maximumWaitingTimeForValidation:magnetoCalibrationOffsetValues:magnetoCalibrationScaleValues:backToMeasurementIdleTimeout:capDetectionDirection:capCombination:capOptions:capShape:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformCapCombination *capCombination __attribute__((swift_name("capCombination")));
@property (readonly) DynamicsMultiplatformCapOptions *capOptions __attribute__((swift_name("capOptions")));
@property (readonly) DynamicsMultiplatformCapShape *capShape __attribute__((swift_name("capShape")));

/**
 * Changed from [Duration] to [Int] since the second hardware revision. As the count is
 * independent of the used sampling rate.
 */
@property (readonly) int32_t countOfPostImpactSamples __attribute__((swift_name("countOfPostImpactSamples")));

/**
 * Changed from [Duration] to [Int] since the second hardware revision. As the count is
 * independent of the used sampling rate.
 */
@property (readonly) int32_t countOfPreTriggerSamples __attribute__((swift_name("countOfPreTriggerSamples")));
@property (readonly) double minimumAbsoluteAccelerationForValidImpact __attribute__((swift_name("minimumAbsoluteAccelerationForValidImpact")));
@property (readonly) double wakeUpTriggerThreshold __attribute__((swift_name("wakeUpTriggerThreshold")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactConfigOption")))
@interface DynamicsMultiplatformImpactConfigOption : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformImpactConfigOption *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *wakeUpTriggerThreshold __attribute__((swift_name("wakeUpTriggerThreshold")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *wakeUpTriggerDebounceTime __attribute__((swift_name("wakeUpTriggerDebounceTime")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *countOfPreTriggerSamples __attribute__((swift_name("countOfPreTriggerSamples")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *countOfPostImpactSamples __attribute__((swift_name("countOfPostImpactSamples")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *minimumAbsoluteAccelerationForValidImpact __attribute__((swift_name("minimumAbsoluteAccelerationForValidImpact")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *maximumWaitingTimeForValidation __attribute__((swift_name("maximumWaitingTimeForValidation")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *backToMeasurementIdleTimeout __attribute__((swift_name("backToMeasurementIdleTimeout")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *magnetoCalibrationOffsetValues __attribute__((swift_name("magnetoCalibrationOffsetValues")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *magnetoCalibrationScaleValues __attribute__((swift_name("magnetoCalibrationScaleValues")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *capDetectionDirection __attribute__((swift_name("capDetectionDirection")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *capCombination __attribute__((swift_name("capCombination")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *capOptions __attribute__((swift_name("capOptions")));
@property (class, readonly) DynamicsMultiplatformImpactConfigOption *capShape __attribute__((swift_name("capShape")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformImpactConfigOption *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformImpactConfigOption *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NearbyGlove")))
@interface DynamicsMultiplatformNearbyGlove : DynamicsMultiplatformBase
- (instancetype)initWithAddress:(NSString *)address advertisingName:(NSString * _Nullable)advertisingName rssi:(int32_t)rssi state:(DynamicsMultiplatformNearbyGloveState *)state __attribute__((swift_name("init(address:advertisingName:rssi:state:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformNearbyGlove *)doCopyAddress:(NSString *)address advertisingName:(NSString * _Nullable)advertisingName rssi:(int32_t)rssi state:(DynamicsMultiplatformNearbyGloveState *)state __attribute__((swift_name("doCopy(address:advertisingName:rssi:state:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *address __attribute__((swift_name("address")));
@property (readonly) NSString * _Nullable advertisingName __attribute__((swift_name("advertisingName")));
@property (readonly) int32_t rssi __attribute__((swift_name("rssi")));
@property (readonly) DynamicsMultiplatformNearbyGloveState *state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NearbyGloveState")))
@interface DynamicsMultiplatformNearbyGloveState : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformNearbyGloveState *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformNearbyGloveState *none __attribute__((swift_name("none")));
@property (class, readonly) DynamicsMultiplatformNearbyGloveState *disabled __attribute__((swift_name("disabled")));
@property (class, readonly) DynamicsMultiplatformNearbyGloveState *isConnecting __attribute__((swift_name("isConnecting")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformNearbyGloveState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformNearbyGloveState *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllOperationalConfigs")))
@interface DynamicsMultiplatformAllOperationalConfigs : DynamicsMultiplatformBase
- (instancetype)initWithDeactivateOfflineMeasurementModeTimeout:(int64_t)deactivateOfflineMeasurementModeTimeout __attribute__((swift_name("init(deactivateOfflineMeasurementModeTimeout:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformAllOperationalConfigsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformAllOperationalConfigs *)doCopyDeactivateOfflineMeasurementModeTimeout:(int64_t)deactivateOfflineMeasurementModeTimeout __attribute__((swift_name("doCopy(deactivateOfflineMeasurementModeTimeout:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllOperationalConfigs.Companion")))
@interface DynamicsMultiplatformAllOperationalConfigsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformAllOperationalConfigsCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveTime")))
@interface DynamicsMultiplatformGloveTime : DynamicsMultiplatformBase
- (instancetype)initWithRequestedAt:(DynamicsMultiplatformKotlinInstant *)requestedAt absoluteTimeReference:(DynamicsMultiplatformKotlinInstant *)absoluteTimeReference relativeTimeReference:(int64_t)relativeTimeReference __attribute__((swift_name("init(requestedAt:absoluteTimeReference:relativeTimeReference:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGloveTime *)doCopyRequestedAt:(DynamicsMultiplatformKotlinInstant *)requestedAt absoluteTimeReference:(DynamicsMultiplatformKotlinInstant *)absoluteTimeReference relativeTimeReference:(int64_t)relativeTimeReference __attribute__((swift_name("doCopy(requestedAt:absoluteTimeReference:relativeTimeReference:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OperationConfigOption")))
@interface DynamicsMultiplatformOperationConfigOption : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformOperationConfigOption *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformOperationConfigOption *deactivateOfflineMeasurementModeTimeout __attribute__((swift_name("deactivateOfflineMeasurementModeTimeout")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformOperationConfigOption *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformOperationConfigOption *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OperationalState")))
@interface DynamicsMultiplatformOperationalState : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformOperationalState *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly, getter=companion) DynamicsMultiplatformOperationalStateCompanion *companion __attribute__((swift_name("companion")));
@property (class, readonly) DynamicsMultiplatformOperationalState *idle __attribute__((swift_name("idle")));
@property (class, readonly) DynamicsMultiplatformOperationalState *accStream __attribute__((swift_name("accStream")));
@property (class, readonly) DynamicsMultiplatformOperationalState *measurement __attribute__((swift_name("measurement")));
@property (class, readonly) DynamicsMultiplatformOperationalState *offlineMeasurement __attribute__((swift_name("offlineMeasurement")));
@property (class, readonly) DynamicsMultiplatformOperationalState *readDataFlash __attribute__((swift_name("readDataFlash")));
@property (class, readonly) DynamicsMultiplatformOperationalState *eraseFlash __attribute__((swift_name("eraseFlash")));
@property (class, readonly) DynamicsMultiplatformOperationalState *enterDeepSleep __attribute__((swift_name("enterDeepSleep")));
@property (class, readonly) DynamicsMultiplatformOperationalState *allSensorsStreamState __attribute__((swift_name("allSensorsStreamState")));
@property (class, readonly) DynamicsMultiplatformOperationalState *forceBarometerReadout __attribute__((swift_name("forceBarometerReadout")));
@property (class, readonly) DynamicsMultiplatformOperationalState *selfTest __attribute__((swift_name("selfTest")));
@property (class, readonly) DynamicsMultiplatformOperationalState *dummyDataAccGyro __attribute__((swift_name("dummyDataAccGyro")));
@property (class, readonly) DynamicsMultiplatformOperationalState *dummyDataAccGyroBaro __attribute__((swift_name("dummyDataAccGyroBaro")));
@property (class, readonly) DynamicsMultiplatformOperationalState *throughputTest __attribute__((swift_name("throughputTest")));
@property (class, readonly) DynamicsMultiplatformOperationalState *calibrateSensors __attribute__((swift_name("calibrateSensors")));
@property (class, readonly) DynamicsMultiplatformOperationalState *factoryReset __attribute__((swift_name("factoryReset")));
@property (class, readonly) DynamicsMultiplatformOperationalState *reboot __attribute__((swift_name("reboot")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformOperationalState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformOperationalState *> *entries __attribute__((swift_name("entries")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint16_t value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OperationalState.Companion")))
@interface DynamicsMultiplatformOperationalStateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformOperationalStateCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformOperationalState *)fromValueValue:(uint16_t)value __attribute__((swift_name("fromValue(value:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SelfTestOutput")))
@interface DynamicsMultiplatformSelfTestOutput : DynamicsMultiplatformBase
- (instancetype)initWithIsBatteryBeingCharged:(BOOL)isBatteryBeingCharged isChargerAttached:(BOOL)isChargerAttached adcSelfTestCannotTurnOffMosfet:(BOOL)adcSelfTestCannotTurnOffMosfet adcSelfTestBadBatteryVoltage:(BOOL)adcSelfTestBadBatteryVoltage adcAcquisitionError:(BOOL)adcAcquisitionError adcGenericError:(BOOL)adcGenericError spiNorSelfTestNoCommunication:(BOOL)spiNorSelfTestNoCommunication spiNorSelfTestWrongJedecId:(BOOL)spiNorSelfTestWrongJedecId ms5837SelfTestI2cError:(BOOL)ms5837SelfTestI2cError ms5837SelfTestPromCrcError:(BOOL)ms5837SelfTestPromCrcError kx134SelfTestInternalCommunicationError:(BOOL)kx134SelfTestInternalCommunicationError kx134SelfTestAsicError:(BOOL)kx134SelfTestAsicError kx134SelfTestDigitizerError:(BOOL)kx134SelfTestDigitizerError kx134SelfTestInt1Error:(BOOL)kx134SelfTestInt1Error kx134SelfTestInt2Error:(BOOL)kx134SelfTestInt2Error kx134SelfTestPartIdError:(BOOL)kx134SelfTestPartIdError kx134SelfTestUnspecifiedError:(BOOL)kx134SelfTestUnspecifiedError bmi270SelfTestInternalCommunicationError:(BOOL)bmi270SelfTestInternalCommunicationError bmi270SelfTestAccError:(BOOL)bmi270SelfTestAccError bmi270SelfTestGyroDriveError:(BOOL)bmi270SelfTestGyroDriveError bmi270SelfTestGyroSenseError:(BOOL)bmi270SelfTestGyroSenseError bmi270SelfTestGyroDataPathError:(BOOL)bmi270SelfTestGyroDataPathError bmi270SelfTestInt1Error:(BOOL)bmi270SelfTestInt1Error bmi270SelfTestInt2Error:(BOOL)bmi270SelfTestInt2Error bmi270SelfTestPartIdError:(BOOL)bmi270SelfTestPartIdError __attribute__((swift_name("init(isBatteryBeingCharged:isChargerAttached:adcSelfTestCannotTurnOffMosfet:adcSelfTestBadBatteryVoltage:adcAcquisitionError:adcGenericError:spiNorSelfTestNoCommunication:spiNorSelfTestWrongJedecId:ms5837SelfTestI2cError:ms5837SelfTestPromCrcError:kx134SelfTestInternalCommunicationError:kx134SelfTestAsicError:kx134SelfTestDigitizerError:kx134SelfTestInt1Error:kx134SelfTestInt2Error:kx134SelfTestPartIdError:kx134SelfTestUnspecifiedError:bmi270SelfTestInternalCommunicationError:bmi270SelfTestAccError:bmi270SelfTestGyroDriveError:bmi270SelfTestGyroSenseError:bmi270SelfTestGyroDataPathError:bmi270SelfTestInt1Error:bmi270SelfTestInt2Error:bmi270SelfTestPartIdError:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSelfTestOutput *)doCopyIsBatteryBeingCharged:(BOOL)isBatteryBeingCharged isChargerAttached:(BOOL)isChargerAttached adcSelfTestCannotTurnOffMosfet:(BOOL)adcSelfTestCannotTurnOffMosfet adcSelfTestBadBatteryVoltage:(BOOL)adcSelfTestBadBatteryVoltage adcAcquisitionError:(BOOL)adcAcquisitionError adcGenericError:(BOOL)adcGenericError spiNorSelfTestNoCommunication:(BOOL)spiNorSelfTestNoCommunication spiNorSelfTestWrongJedecId:(BOOL)spiNorSelfTestWrongJedecId ms5837SelfTestI2cError:(BOOL)ms5837SelfTestI2cError ms5837SelfTestPromCrcError:(BOOL)ms5837SelfTestPromCrcError kx134SelfTestInternalCommunicationError:(BOOL)kx134SelfTestInternalCommunicationError kx134SelfTestAsicError:(BOOL)kx134SelfTestAsicError kx134SelfTestDigitizerError:(BOOL)kx134SelfTestDigitizerError kx134SelfTestInt1Error:(BOOL)kx134SelfTestInt1Error kx134SelfTestInt2Error:(BOOL)kx134SelfTestInt2Error kx134SelfTestPartIdError:(BOOL)kx134SelfTestPartIdError kx134SelfTestUnspecifiedError:(BOOL)kx134SelfTestUnspecifiedError bmi270SelfTestInternalCommunicationError:(BOOL)bmi270SelfTestInternalCommunicationError bmi270SelfTestAccError:(BOOL)bmi270SelfTestAccError bmi270SelfTestGyroDriveError:(BOOL)bmi270SelfTestGyroDriveError bmi270SelfTestGyroSenseError:(BOOL)bmi270SelfTestGyroSenseError bmi270SelfTestGyroDataPathError:(BOOL)bmi270SelfTestGyroDataPathError bmi270SelfTestInt1Error:(BOOL)bmi270SelfTestInt1Error bmi270SelfTestInt2Error:(BOOL)bmi270SelfTestInt2Error bmi270SelfTestPartIdError:(BOOL)bmi270SelfTestPartIdError __attribute__((swift_name("doCopy(isBatteryBeingCharged:isChargerAttached:adcSelfTestCannotTurnOffMosfet:adcSelfTestBadBatteryVoltage:adcAcquisitionError:adcGenericError:spiNorSelfTestNoCommunication:spiNorSelfTestWrongJedecId:ms5837SelfTestI2cError:ms5837SelfTestPromCrcError:kx134SelfTestInternalCommunicationError:kx134SelfTestAsicError:kx134SelfTestDigitizerError:kx134SelfTestInt1Error:kx134SelfTestInt2Error:kx134SelfTestPartIdError:kx134SelfTestUnspecifiedError:bmi270SelfTestInternalCommunicationError:bmi270SelfTestAccError:bmi270SelfTestGyroDriveError:bmi270SelfTestGyroSenseError:bmi270SelfTestGyroDataPathError:bmi270SelfTestInt1Error:bmi270SelfTestInt2Error:bmi270SelfTestPartIdError:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL adcAcquisitionError __attribute__((swift_name("adcAcquisitionError")));
@property (readonly) BOOL adcGenericError __attribute__((swift_name("adcGenericError")));
@property (readonly) BOOL adcSelfTestBadBatteryVoltage __attribute__((swift_name("adcSelfTestBadBatteryVoltage")));
@property (readonly) BOOL adcSelfTestCannotTurnOffMosfet __attribute__((swift_name("adcSelfTestCannotTurnOffMosfet")));
@property (readonly) BOOL bmi270SelfTestAccError __attribute__((swift_name("bmi270SelfTestAccError")));
@property (readonly) BOOL bmi270SelfTestGyroDataPathError __attribute__((swift_name("bmi270SelfTestGyroDataPathError")));
@property (readonly) BOOL bmi270SelfTestGyroDriveError __attribute__((swift_name("bmi270SelfTestGyroDriveError")));
@property (readonly) BOOL bmi270SelfTestGyroSenseError __attribute__((swift_name("bmi270SelfTestGyroSenseError")));
@property (readonly) BOOL bmi270SelfTestInt1Error __attribute__((swift_name("bmi270SelfTestInt1Error")));
@property (readonly) BOOL bmi270SelfTestInt2Error __attribute__((swift_name("bmi270SelfTestInt2Error")));
@property (readonly) BOOL bmi270SelfTestInternalCommunicationError __attribute__((swift_name("bmi270SelfTestInternalCommunicationError")));
@property (readonly) BOOL bmi270SelfTestPartIdError __attribute__((swift_name("bmi270SelfTestPartIdError")));
@property (readonly) BOOL isBatteryBeingCharged __attribute__((swift_name("isBatteryBeingCharged")));
@property (readonly) BOOL isChargerAttached __attribute__((swift_name("isChargerAttached")));
@property (readonly) BOOL kx134SelfTestAsicError __attribute__((swift_name("kx134SelfTestAsicError")));
@property (readonly) BOOL kx134SelfTestDigitizerError __attribute__((swift_name("kx134SelfTestDigitizerError")));
@property (readonly) BOOL kx134SelfTestInt1Error __attribute__((swift_name("kx134SelfTestInt1Error")));
@property (readonly) BOOL kx134SelfTestInt2Error __attribute__((swift_name("kx134SelfTestInt2Error")));
@property (readonly) BOOL kx134SelfTestInternalCommunicationError __attribute__((swift_name("kx134SelfTestInternalCommunicationError")));
@property (readonly) BOOL kx134SelfTestPartIdError __attribute__((swift_name("kx134SelfTestPartIdError")));
@property (readonly) BOOL kx134SelfTestUnspecifiedError __attribute__((swift_name("kx134SelfTestUnspecifiedError")));
@property (readonly) BOOL ms5837SelfTestI2cError __attribute__((swift_name("ms5837SelfTestI2cError")));
@property (readonly) BOOL ms5837SelfTestPromCrcError __attribute__((swift_name("ms5837SelfTestPromCrcError")));
@property (readonly) BOOL spiNorSelfTestNoCommunication __attribute__((swift_name("spiNorSelfTestNoCommunication")));
@property (readonly) BOOL spiNorSelfTestWrongJedecId __attribute__((swift_name("spiNorSelfTestWrongJedecId")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllDeepSleepWakeUpConfigs")))
@interface DynamicsMultiplatformAllDeepSleepWakeUpConfigs : DynamicsMultiplatformBase
- (instancetype)initWithDeepSleepWakeUpConfiguration:(DynamicsMultiplatformDeepSleepWakeUpConfiguration *)deepSleepWakeUpConfiguration deepSleepWakeUpAccConfig:(DynamicsMultiplatformDeepSleepWakeUpAccConfig *)deepSleepWakeUpAccConfig __attribute__((swift_name("init(deepSleepWakeUpConfiguration:deepSleepWakeUpAccConfig:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformAllDeepSleepWakeUpConfigsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformAllDeepSleepWakeUpConfigs *)doCopyDeepSleepWakeUpConfiguration:(DynamicsMultiplatformDeepSleepWakeUpConfiguration *)deepSleepWakeUpConfiguration deepSleepWakeUpAccConfig:(DynamicsMultiplatformDeepSleepWakeUpAccConfig *)deepSleepWakeUpAccConfig __attribute__((swift_name("doCopy(deepSleepWakeUpConfiguration:deepSleepWakeUpAccConfig:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformDeepSleepWakeUpAccConfig *deepSleepWakeUpAccConfig __attribute__((swift_name("deepSleepWakeUpAccConfig")));
@property (readonly) DynamicsMultiplatformDeepSleepWakeUpConfiguration *deepSleepWakeUpConfiguration __attribute__((swift_name("deepSleepWakeUpConfiguration")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AllDeepSleepWakeUpConfigs.Companion")))
@interface DynamicsMultiplatformAllDeepSleepWakeUpConfigsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformAllDeepSleepWakeUpConfigsCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpAccConfig")))
@interface DynamicsMultiplatformDeepSleepWakeUpAccConfig : DynamicsMultiplatformBase
- (instancetype)initWithWakeUpTriggerIncrease:(double)wakeUpTriggerIncrease wakeUpTriggerDebounceTime:(int64_t)wakeUpTriggerDebounceTime __attribute__((swift_name("init(wakeUpTriggerIncrease:wakeUpTriggerDebounceTime:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDeepSleepWakeUpAccConfigCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDeepSleepWakeUpAccConfig *)doCopyWakeUpTriggerIncrease:(double)wakeUpTriggerIncrease wakeUpTriggerDebounceTime:(int64_t)wakeUpTriggerDebounceTime __attribute__((swift_name("doCopy(wakeUpTriggerIncrease:wakeUpTriggerDebounceTime:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpAccConfig.Companion")))
@interface DynamicsMultiplatformDeepSleepWakeUpAccConfigCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDeepSleepWakeUpAccConfigCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpConfigOption")))
@interface DynamicsMultiplatformDeepSleepWakeUpConfigOption : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformDeepSleepWakeUpConfigOption *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformDeepSleepWakeUpConfigOption *deepSleepWakeUpConfiguration __attribute__((swift_name("deepSleepWakeUpConfiguration")));
@property (class, readonly) DynamicsMultiplatformDeepSleepWakeUpConfigOption *deepSleepWakeUpAccelerationIncreaseThresholdAndDebounceTime __attribute__((swift_name("deepSleepWakeUpAccelerationIncreaseThresholdAndDebounceTime")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformDeepSleepWakeUpConfigOption *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformDeepSleepWakeUpConfigOption *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpConfiguration")))
@interface DynamicsMultiplatformDeepSleepWakeUpConfiguration : DynamicsMultiplatformBase
- (instancetype)initWithIsAlwaysAdvertisingDuringDeepSleep:(BOOL)isAlwaysAdvertisingDuringDeepSleep isAdvertisingForGivenTimeWhenMinorAccelerationDetected:(BOOL)isAdvertisingForGivenTimeWhenMinorAccelerationDetected isAdvertisingAfterDoubleTap:(BOOL)isAdvertisingAfterDoubleTap isWakeUpForOfflineMode:(BOOL)isWakeUpForOfflineMode isWakeUpOnChargerAttached:(BOOL)isWakeUpOnChargerAttached __attribute__((swift_name("init(isAlwaysAdvertisingDuringDeepSleep:isAdvertisingForGivenTimeWhenMinorAccelerationDetected:isAdvertisingAfterDoubleTap:isWakeUpForOfflineMode:isWakeUpOnChargerAttached:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDeepSleepWakeUpConfigurationCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDeepSleepWakeUpConfiguration *)doCopyIsAlwaysAdvertisingDuringDeepSleep:(BOOL)isAlwaysAdvertisingDuringDeepSleep isAdvertisingForGivenTimeWhenMinorAccelerationDetected:(BOOL)isAdvertisingForGivenTimeWhenMinorAccelerationDetected isAdvertisingAfterDoubleTap:(BOOL)isAdvertisingAfterDoubleTap isWakeUpForOfflineMode:(BOOL)isWakeUpForOfflineMode isWakeUpOnChargerAttached:(BOOL)isWakeUpOnChargerAttached __attribute__((swift_name("doCopy(isAlwaysAdvertisingDuringDeepSleep:isAdvertisingForGivenTimeWhenMinorAccelerationDetected:isAdvertisingAfterDoubleTap:isWakeUpForOfflineMode:isWakeUpOnChargerAttached:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isAdvertisingAfterDoubleTap __attribute__((swift_name("isAdvertisingAfterDoubleTap")));
@property (readonly) BOOL isAdvertisingForGivenTimeWhenMinorAccelerationDetected __attribute__((swift_name("isAdvertisingForGivenTimeWhenMinorAccelerationDetected")));
@property (readonly) BOOL isAlwaysAdvertisingDuringDeepSleep __attribute__((swift_name("isAlwaysAdvertisingDuringDeepSleep")));
@property (readonly) BOOL isWakeUpForOfflineMode __attribute__((swift_name("isWakeUpForOfflineMode")));
@property (readonly) BOOL isWakeUpOnChargerAttached __attribute__((swift_name("isWakeUpOnChargerAttached")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpConfiguration.Companion")))
@interface DynamicsMultiplatformDeepSleepWakeUpConfigurationCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDeepSleepWakeUpConfigurationCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) int32_t BIT_POS_0 __attribute__((swift_name("BIT_POS_0")));
@property (readonly) int32_t BIT_POS_1 __attribute__((swift_name("BIT_POS_1")));
@property (readonly) int32_t BIT_POS_2 __attribute__((swift_name("BIT_POS_2")));
@property (readonly) int32_t BIT_POS_3 __attribute__((swift_name("BIT_POS_3")));
@property (readonly) int32_t BIT_POS_4 __attribute__((swift_name("BIT_POS_4")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeepSleepWakeUpDoubleTapAcc")))
@interface DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc : DynamicsMultiplatformBase
- (instancetype)initWithTapDetectionThresholdControl:(uint32_t)tapDetectionThresholdControl tapThresholdHigh:(uint32_t)tapThresholdHigh tapThresholdLow:(uint32_t)tapThresholdLow filterTapDetection:(uint32_t)filterTapDetection setTapDuration:(uint32_t)setTapDuration tapLatencyTimer:(uint32_t)tapLatencyTimer tapWindowSize:(uint32_t)tapWindowSize __attribute__((swift_name("init(tapDetectionThresholdControl:tapThresholdHigh:tapThresholdLow:filterTapDetection:setTapDuration:tapLatencyTimer:tapWindowSize:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc *)doCopyTapDetectionThresholdControl:(uint32_t)tapDetectionThresholdControl tapThresholdHigh:(uint32_t)tapThresholdHigh tapThresholdLow:(uint32_t)tapThresholdLow filterTapDetection:(uint32_t)filterTapDetection setTapDuration:(uint32_t)setTapDuration tapLatencyTimer:(uint32_t)tapLatencyTimer tapWindowSize:(uint32_t)tapWindowSize __attribute__((swift_name("doCopy(tapDetectionThresholdControl:tapThresholdHigh:tapThresholdLow:filterTapDetection:setTapDuration:tapLatencyTimer:tapWindowSize:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) uint32_t filterTapDetection __attribute__((swift_name("filterTapDetection")));
@property (readonly) uint32_t setTapDuration __attribute__((swift_name("setTapDuration")));
@property (readonly) uint32_t tapDetectionThresholdControl __attribute__((swift_name("tapDetectionThresholdControl")));
@property (readonly) uint32_t tapLatencyTimer __attribute__((swift_name("tapLatencyTimer")));
@property (readonly) uint32_t tapThresholdHigh __attribute__((swift_name("tapThresholdHigh")));
@property (readonly) uint32_t tapThresholdLow __attribute__((swift_name("tapThresholdLow")));
@property (readonly) uint32_t tapWindowSize __attribute__((swift_name("tapWindowSize")));
@end


/**
 * This class describes the compatibility states for two gloves (i.e. one pair), which is necessary
 * for starting a workout.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("GlovePairCompatibility")))
@interface DynamicsMultiplatformGlovePairCompatibility : DynamicsMultiplatformBase
@end


/**
 * One glove has a different [sensorType] than then other.
 *
 * @param sensorType the affected sensor type of the [affectedSide] that is incompatible.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibility.EquipmentIncompatible")))
@interface DynamicsMultiplatformGlovePairCompatibilityEquipmentIncompatible : DynamicsMultiplatformGlovePairCompatibility
- (instancetype)initWithAffectedSide:(DynamicsMultiplatformSide *)affectedSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(affectedSide:sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePairCompatibilityEquipmentIncompatible *)doCopyAffectedSide:(DynamicsMultiplatformSide *)affectedSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(affectedSide:sensorType:)")));

/**
 * One glove has a different [sensorType] than then other.
 *
 * @param sensorType the affected sensor type of the [affectedSide] that is incompatible.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * One glove has a different [sensorType] than then other.
 *
 * @param sensorType the affected sensor type of the [affectedSide] that is incompatible.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformSide *affectedSide __attribute__((swift_name("affectedSide")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * Both gloves are offline. The sensor type cannot be determined.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibility.Offline")))
@interface DynamicsMultiplatformGlovePairCompatibilityOffline : DynamicsMultiplatformGlovePairCompatibility
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Both gloves are offline. The sensor type cannot be determined.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)offline __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformGlovePairCompatibilityOffline *shared __attribute__((swift_name("shared")));

/**
 * Both gloves are offline. The sensor type cannot be determined.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Both gloves are offline. The sensor type cannot be determined.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * The glove pair is ready and fully compatible for any workout with the [sensorType].
 *
 * @param sensorType the sensor type that both gloves currently support.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibility.Ok")))
@interface DynamicsMultiplatformGlovePairCompatibilityOk : DynamicsMultiplatformGlovePairCompatibility
- (instancetype)initWithSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePairCompatibilityOk *)doCopySensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(sensorType:)")));

/**
 * The glove pair is ready and fully compatible for any workout with the [sensorType].
 *
 * @param sensorType the sensor type that both gloves currently support.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The glove pair is ready and fully compatible for any workout with the [sensorType].
 *
 * @param sensorType the sensor type that both gloves currently support.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * Only one glove is added.
 *
 * @param availableSide the side of the glove which is available.
 * @param sensorType the sensor type that the currently does support.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibility.OneGloveOnly")))
@interface DynamicsMultiplatformGlovePairCompatibilityOneGloveOnly : DynamicsMultiplatformGlovePairCompatibility
- (instancetype)initWithAvailableSide:(DynamicsMultiplatformSide *)availableSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(availableSide:sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePairCompatibilityOneGloveOnly *)doCopyAvailableSide:(DynamicsMultiplatformSide *)availableSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(availableSide:sensorType:)")));

/**
 * Only one glove is added.
 *
 * @param availableSide the side of the glove which is available.
 * @param sensorType the sensor type that the currently does support.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Only one glove is added.
 *
 * @param availableSide the side of the glove which is available.
 * @param sensorType the sensor type that the currently does support.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformSide *availableSide __attribute__((swift_name("availableSide")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * One glove is offline.
 *
 * @param affectedSide the side of the glove which is offline.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibility.OneSideOffline")))
@interface DynamicsMultiplatformGlovePairCompatibilityOneSideOffline : DynamicsMultiplatformGlovePairCompatibility
- (instancetype)initWithAffectedSide:(DynamicsMultiplatformSide *)affectedSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(affectedSide:sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformGlovePairCompatibilityOneSideOffline *)doCopyAffectedSide:(DynamicsMultiplatformSide *)affectedSide sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(affectedSide:sensorType:)")));

/**
 * One glove is offline.
 *
 * @param affectedSide the side of the glove which is offline.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * One glove is offline.
 *
 * @param affectedSide the side of the glove which is offline.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformSide *affectedSide __attribute__((swift_name("affectedSide")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("GlovePairCompatibilityStatus")))
@interface DynamicsMultiplatformGlovePairCompatibilityStatus : DynamicsMultiplatformBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibilityStatus.Error")))
@interface DynamicsMultiplatformGlovePairCompatibilityStatusError : DynamicsMultiplatformGlovePairCompatibilityStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)error __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformGlovePairCompatibilityStatusError *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibilityStatus.Ok")))
@interface DynamicsMultiplatformGlovePairCompatibilityStatusOk : DynamicsMultiplatformGlovePairCompatibilityStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)ok __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformGlovePairCompatibilityStatusOk *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GlovePairCompatibilityStatus.Warning")))
@interface DynamicsMultiplatformGlovePairCompatibilityStatusWarning : DynamicsMultiplatformGlovePairCompatibilityStatus
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)warning __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformGlovePairCompatibilityStatusWarning *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents information about the consumer app.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AppInfo")))
@interface DynamicsMultiplatformAppInfo : DynamicsMultiplatformBase
- (instancetype)initWithId:(NSString *)id version:(NSString *)version code:(NSString *)code ciCommitSha:(NSString *)ciCommitSha ciCommitTag:(NSString *)ciCommitTag installationId:(NSString * _Nullable)installationId __attribute__((swift_name("init(id:version:code:ciCommitSha:ciCommitTag:installationId:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformAppInfo *)doCopyId:(NSString *)id version:(NSString *)version code:(NSString *)code ciCommitSha:(NSString *)ciCommitSha ciCommitTag:(NSString *)ciCommitTag installationId:(NSString * _Nullable)installationId __attribute__((swift_name("doCopy(id:version:code:ciCommitSha:ciCommitTag:installationId:)")));

/**
 * Represents information about the consumer app.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents information about the consumer app.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents information about the consumer app.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The CI/GIT commit sha.
 */
@property (readonly) NSString *ciCommitSha __attribute__((swift_name("ciCommitSha")));

/**
 * The CI commit tag.
 */
@property (readonly) NSString *ciCommitTag __attribute__((swift_name("ciCommitTag")));

/**
 * The unique code of the version of the app.
 */
@property (readonly) NSString *code __attribute__((swift_name("code")));

/**
 * The id of the app.
 */
@property (readonly) NSString *id __attribute__((swift_name("id")));

/**
 * The installation id.
 */
@property (readonly) NSString * _Nullable installationId __attribute__((swift_name("installationId")));

/**
 * The version of the app.
 */
@property (readonly) NSString *version __attribute__((swift_name("version")));
@end


/**
 * Represents information about the consumer device (smartphone) info.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceInfo_")))
@interface DynamicsMultiplatformDeviceInfo_ : DynamicsMultiplatformBase
- (instancetype)initWithPlatform:(DynamicsMultiplatformPlatform *)platform platformOsVersion:(NSString *)platformOsVersion model:(NSString *)model modelId:(NSString *)modelId __attribute__((swift_name("init(platform:platformOsVersion:model:modelId:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDeviceInfo_ *)doCopyPlatform:(DynamicsMultiplatformPlatform *)platform platformOsVersion:(NSString *)platformOsVersion model:(NSString *)model modelId:(NSString *)modelId __attribute__((swift_name("doCopy(platform:platformOsVersion:model:modelId:)")));

/**
 * Represents information about the consumer device (smartphone) info.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents information about the consumer device (smartphone) info.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents information about the consumer device (smartphone) info.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The model of the consumer device.
 */
@property (readonly) NSString *model __attribute__((swift_name("model")));

/**
 * The model id of the consumer device.
 */
@property (readonly) NSString *modelId __attribute__((swift_name("modelId")));

/**
 * The target platform.
 */
@property (readonly) DynamicsMultiplatformPlatform *platform __attribute__((swift_name("platform")));

/**
 * The platform OS version.
 */
@property (readonly) NSString *platformOsVersion __attribute__((swift_name("platformOsVersion")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Platform")))
@interface DynamicsMultiplatformPlatform : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformPlatform *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformPlatform *android __attribute__((swift_name("android")));
@property (class, readonly) DynamicsMultiplatformPlatform *ios __attribute__((swift_name("ios")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformPlatform *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformPlatform *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsTestOptions")))
@interface DynamicsMultiplatformDynamicsTestOptions : DynamicsMultiplatformBase
- (instancetype)initWithCheckConfigCharacteristics:(BOOL)checkConfigCharacteristics __attribute__((swift_name("init(checkConfigCharacteristics:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamicsTestOptionsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDynamicsTestOptions *)doCopyCheckConfigCharacteristics:(BOOL)checkConfigCharacteristics __attribute__((swift_name("doCopy(checkConfigCharacteristics:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Runs checks for all configuration characteristics after a connection has been established:
 * 1. checks min/max ranges, but sets value to the already existing one.
 */
@property (readonly) BOOL checkConfigCharacteristics __attribute__((swift_name("checkConfigCharacteristics")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsTestOptions.Companion")))
@interface DynamicsMultiplatformDynamicsTestOptionsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamicsTestOptionsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformDynamicsTestOptions *NONE __attribute__((swift_name("NONE")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfile")))
@interface DynamicsMultiplatformBodyProfile : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id name:(NSString *)name weight:(double)weight height:(double)height gender:(DynamicsMultiplatformGender *)gender __attribute__((swift_name("init(id:name:weight:height:gender:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformBodyProfileCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformBodyProfile *)doCopyId:(id)id name:(NSString *)name weight:(double)weight height:(double)height gender:(DynamicsMultiplatformGender *)gender __attribute__((swift_name("doCopy(id:name:weight:height:gender:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformGender *gender __attribute__((swift_name("gender")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfile.Companion")))
@interface DynamicsMultiplatformBodyProfileCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBodyProfileCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfileValidation")))
@interface DynamicsMultiplatformBodyProfileValidation : DynamicsMultiplatformBase
- (instancetype)initWithName:(id<DynamicsMultiplatformBasicValidation>)name weight:(id<DynamicsMultiplatformBasicValidation>)weight height:(id<DynamicsMultiplatformBasicValidation>)height gender:(id<DynamicsMultiplatformBasicValidation>)gender __attribute__((swift_name("init(name:weight:height:gender:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformBodyProfileValidationCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformBodyProfileValidation *)doCopyName:(id<DynamicsMultiplatformBasicValidation>)name weight:(id<DynamicsMultiplatformBasicValidation>)weight height:(id<DynamicsMultiplatformBasicValidation>)height gender:(id<DynamicsMultiplatformBasicValidation>)gender __attribute__((swift_name("doCopy(name:weight:height:gender:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<DynamicsMultiplatformBasicValidation> gender __attribute__((swift_name("gender")));
@property (readonly) id<DynamicsMultiplatformBasicValidation> height __attribute__((swift_name("height")));
@property (readonly) BOOL isValidationOk __attribute__((swift_name("isValidationOk")));
@property (readonly) id<DynamicsMultiplatformBasicValidation> name __attribute__((swift_name("name")));
@property (readonly) id<DynamicsMultiplatformBasicValidation> weight __attribute__((swift_name("weight")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfileValidation.Companion")))
@interface DynamicsMultiplatformBodyProfileValidationCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBodyProfileValidationCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformKotlinClosedFloatingPointRange> heightRange __attribute__((swift_name("heightRange")));
@property (readonly) DynamicsMultiplatformKotlinIntRange *nameNumberOfCharactersRange __attribute__((swift_name("nameNumberOfCharactersRange")));
@property (readonly) id<DynamicsMultiplatformKotlinClosedFloatingPointRange> weightRange __attribute__((swift_name("weightRange")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Gender")))
@interface DynamicsMultiplatformGender : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformGender *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformGender *male __attribute__((swift_name("male")));
@property (class, readonly) DynamicsMultiplatformGender *female __attribute__((swift_name("female")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformGender *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformGender *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * The computation of power properties depends on the type of the sensors:
 *
 * - [Alpha] uses barometric pressure values.
 * - [Delta] only uses acceleration values.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Power")))
@interface DynamicsMultiplatformPower : DynamicsMultiplatformBase
@property (readonly) double impactOrPowerIndex __attribute__((swift_name("impactOrPowerIndex")));
@property (readonly) double peakForce __attribute__((swift_name("peakForce")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Power.Alpha")))
@interface DynamicsMultiplatformPowerAlpha : DynamicsMultiplatformPower
- (instancetype)initWithImpact:(double)impact peakForceBasedOnBaro:(double)peakForceBasedOnBaro __attribute__((swift_name("init(impact:peakForceBasedOnBaro:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPowerAlpha *)doCopyImpact:(double)impact peakForceBasedOnBaro:(double)peakForceBasedOnBaro __attribute__((swift_name("doCopy(impact:peakForceBasedOnBaro:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double impact __attribute__((swift_name("impact")));
@property (readonly) double peakForceBasedOnBaro __attribute__((swift_name("peakForceBasedOnBaro")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Power.Delta")))
@interface DynamicsMultiplatformPowerDelta : DynamicsMultiplatformPower
- (instancetype)initWithPowerIndex:(double)powerIndex __attribute__((swift_name("init(powerIndex:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPowerDelta *)doCopyPowerIndex:(double)powerIndex __attribute__((swift_name("doCopy(powerIndex:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double powerIndex __attribute__((swift_name("powerIndex")));
@end


/**
 * Represents the samples of the power related values.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PowerSamples")))
@interface DynamicsMultiplatformPowerSamples : DynamicsMultiplatformBase
- (instancetype)initWithBaroTimeOffset:(int64_t)baroTimeOffset baroSamplingRateMarks:(NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *)baroSamplingRateMarks force:(NSArray<DynamicsMultiplatformDouble *> *)force __attribute__((swift_name("init(baroTimeOffset:baroSamplingRateMarks:force:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformPowerSamplesCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformPowerSamples *)doCopyBaroTimeOffset:(int64_t)baroTimeOffset baroSamplingRateMarks:(NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *)baroSamplingRateMarks force:(NSArray<DynamicsMultiplatformDouble *> *)force __attribute__((swift_name("doCopy(baroTimeOffset:baroSamplingRateMarks:force:)")));

/**
 * Represents the samples of the power related values.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the samples of the power related values.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the samples of the power related values.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The sampling rate marks indicate changes in the sampling rate.
 */
@property (readonly) NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *baroSamplingRateMarks __attribute__((swift_name("baroSamplingRateMarks")));

/**
 * The force values.
 */
@property (readonly) NSArray<DynamicsMultiplatformDouble *> *force __attribute__((swift_name("force")));
@property (readonly) NSArray<DynamicsMultiplatformTimeSampleDouble *> *forceTimeSamples __attribute__((swift_name("forceTimeSamples")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PowerSamples.Companion")))
@interface DynamicsMultiplatformPowerSamplesCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformPowerSamplesCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformPowerSamples *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * A punch class holds the computed and structured data based on a single raw data sequence.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Punch")))
@interface DynamicsMultiplatformPunch : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id peripheralId:(id)peripheralId side:(DynamicsMultiplatformSide *)side timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp areComputedValuesValid:(BOOL)areComputedValuesValid speed:(DynamicsMultiplatformSpeed *)speed power:(DynamicsMultiplatformPower *)power __attribute__((swift_name("init(id:peripheralId:side:timestamp:areComputedValuesValid:speed:power:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPunch *)doCopyId:(id)id peripheralId:(id)peripheralId side:(DynamicsMultiplatformSide *)side timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp areComputedValuesValid:(BOOL)areComputedValuesValid speed:(DynamicsMultiplatformSpeed *)speed power:(DynamicsMultiplatformPower *)power __attribute__((swift_name("doCopy(id:peripheralId:side:timestamp:areComputedValuesValid:speed:power:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * A punch class holds the computed and structured data based on a single raw data sequence.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * Indicates if the computations for the punch were successful. If not, then any further
 * processing with the values might lead to errors.
 */
@property (readonly) BOOL areComputedValuesValid __attribute__((swift_name("areComputedValuesValid")));

/**
 * The power properties.
 */
@property (readonly) DynamicsMultiplatformPower *power __attribute__((swift_name("power")));

/**
 * The side of a punch.
 */
@property (readonly) DynamicsMultiplatformSide *side __attribute__((swift_name("side")));

/**
 * The speed properties.
 */
@property (readonly) DynamicsMultiplatformSpeed *speed __attribute__((swift_name("speed")));
@end


/**
 * Used for internal purposes only.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunchWithRawData")))
@interface DynamicsMultiplatformPunchWithRawData : DynamicsMultiplatformBase
- (instancetype)initWithPunch:(DynamicsMultiplatformPunch *)punch algorithmId:(NSString *)algorithmId basePressure:(int32_t)basePressure rawData:(DynamicsMultiplatformKotlinByteArray * _Nullable)rawData __attribute__((swift_name("init(punch:algorithmId:basePressure:rawData:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPunchWithRawData *)doCopyPunch:(DynamicsMultiplatformPunch *)punch algorithmId:(NSString *)algorithmId basePressure:(int32_t)basePressure rawData:(DynamicsMultiplatformKotlinByteArray * _Nullable)rawData __attribute__((swift_name("doCopy(punch:algorithmId:basePressure:rawData:)")));

/**
 * Used for internal purposes only.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Used for internal purposes only.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Used for internal purposes only.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *algorithmId __attribute__((swift_name("algorithmId")));
@property (readonly) int32_t basePressure __attribute__((swift_name("basePressure")));
@property (readonly) DynamicsMultiplatformPunch *punch __attribute__((swift_name("punch")));
@property (readonly) DynamicsMultiplatformKotlinByteArray * _Nullable rawData __attribute__((swift_name("rawData")));
@end


/**
 * Same as [Punch] but contains the sequences of all time-based data.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunchWithSamples")))
@interface DynamicsMultiplatformPunchWithSamples : DynamicsMultiplatformBase
- (instancetype)initWithPunch:(DynamicsMultiplatformPunch *)punch powerSamples:(DynamicsMultiplatformPowerSamples *)powerSamples speedSamples:(DynamicsMultiplatformSpeedSamples *)speedSamples __attribute__((swift_name("init(punch:powerSamples:speedSamples:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPunchWithSamples *)doCopyPunch:(DynamicsMultiplatformPunch *)punch powerSamples:(DynamicsMultiplatformPowerSamples *)powerSamples speedSamples:(DynamicsMultiplatformSpeedSamples *)speedSamples __attribute__((swift_name("doCopy(punch:powerSamples:speedSamples:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Same as [Punch] but contains the sequences of all time-based data.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformPowerSamples *powerSamples __attribute__((swift_name("powerSamples")));

/**
 * The main punch object.
 */
@property (readonly) DynamicsMultiplatformPunch *punch __attribute__((swift_name("punch")));
@property (readonly) DynamicsMultiplatformSpeedSamples *speedSamples __attribute__((swift_name("speedSamples")));
@end


/**
 * Represents properties that can be related to "speed".
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Speed")))
@interface DynamicsMultiplatformSpeed : DynamicsMultiplatformBase
- (instancetype)initWithPunchDuration:(int64_t)punchDuration contactDuration:(int64_t)contactDuration peakAcceleration:(double)peakAcceleration peakVelocity:(double)peakVelocity displacement:(double)displacement __attribute__((swift_name("init(punchDuration:contactDuration:peakAcceleration:peakVelocity:displacement:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSpeed *)doCopyPunchDuration:(int64_t)punchDuration contactDuration:(int64_t)contactDuration peakAcceleration:(double)peakAcceleration peakVelocity:(double)peakVelocity displacement:(double)displacement __attribute__((swift_name("doCopy(punchDuration:contactDuration:peakAcceleration:peakVelocity:displacement:)")));

/**
 * Represents properties that can be related to "speed".
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents properties that can be related to "speed".
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents properties that can be related to "speed".
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The displacement of the punch.
 */
@property (readonly) double displacement __attribute__((swift_name("displacement")));

/**
 * The global peak (max) acceleration.
 */
@property (readonly) double peakAcceleration __attribute__((swift_name("peakAcceleration")));

/**
 * The global peak (max) velocity.
 */
@property (readonly) double peakVelocity __attribute__((swift_name("peakVelocity")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpeedSamples")))
@interface DynamicsMultiplatformSpeedSamples : DynamicsMultiplatformBase
- (instancetype)initWithImuSamplingRateMarks:(NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *)imuSamplingRateMarks acceleration:(NSArray<DynamicsMultiplatformDouble *> *)acceleration velocity:(NSArray<DynamicsMultiplatformDouble *> *)velocity displacement:(NSArray<DynamicsMultiplatformDouble *> *)displacement __attribute__((swift_name("init(imuSamplingRateMarks:acceleration:velocity:displacement:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformSpeedSamplesCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformSpeedSamples *)doCopyImuSamplingRateMarks:(NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *)imuSamplingRateMarks acceleration:(NSArray<DynamicsMultiplatformDouble *> *)acceleration velocity:(NSArray<DynamicsMultiplatformDouble *> *)velocity displacement:(NSArray<DynamicsMultiplatformDouble *> *)displacement __attribute__((swift_name("doCopy(imuSamplingRateMarks:acceleration:velocity:displacement:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<DynamicsMultiplatformDouble *> *acceleration __attribute__((swift_name("acceleration")));
@property (readonly) NSArray<DynamicsMultiplatformTimeSampleDouble *> *accelerationTimeSamples __attribute__((swift_name("accelerationTimeSamples")));
@property (readonly) NSArray<DynamicsMultiplatformDouble *> *displacement __attribute__((swift_name("displacement")));
@property (readonly) NSArray<DynamicsMultiplatformTimeSampleDouble *> *displacementTimeSamples __attribute__((swift_name("displacementTimeSamples")));
@property (readonly) NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *imuSamplingRateMarks __attribute__((swift_name("imuSamplingRateMarks")));
@property (readonly) NSArray<DynamicsMultiplatformDouble *> *velocity __attribute__((swift_name("velocity")));
@property (readonly) NSArray<DynamicsMultiplatformTimeSampleDouble *> *velocityTimeSamples __attribute__((swift_name("velocityTimeSamples")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SpeedSamples.Companion")))
@interface DynamicsMultiplatformSpeedSamplesCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformSpeedSamplesCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformSpeedSamples *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeSampleDouble")))
@interface DynamicsMultiplatformTimeSampleDouble : DynamicsMultiplatformBase
- (instancetype)initWithOffset:(int64_t)offset value:(double)value __attribute__((swift_name("init(offset:value:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformTimeSampleDouble *)doCopyOffset:(int64_t)offset value:(double)value __attribute__((swift_name("doCopy(offset:value:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) double value __attribute__((swift_name("value")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeSampleInt")))
@interface DynamicsMultiplatformTimeSampleInt : DynamicsMultiplatformBase
- (instancetype)initWithOffset:(int64_t)offset value:(int32_t)value __attribute__((swift_name("init(offset:value:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformTimeSampleInt *)doCopyOffset:(int64_t)offset value:(int32_t)value __attribute__((swift_name("doCopy(offset:value:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t value __attribute__((swift_name("value")));
@end


/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActiveTrainingSessionInputSecondary")))
@interface DynamicsMultiplatformActiveTrainingSessionInputSecondary : DynamicsMultiplatformBase
- (instancetype)initWithTrainingSessionId:(id _Nullable)trainingSessionId timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("init(trainingSessionId:timestamp:actor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformActiveTrainingSessionInputSecondaryCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformActiveTrainingSessionInputSecondary *)doCopyTrainingSessionId:(id _Nullable)trainingSessionId timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("doCopy(trainingSessionId:timestamp:actor:)")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionStateActor *actor __attribute__((swift_name("actor")));
@property (readonly) id _Nullable trainingSessionId __attribute__((swift_name("trainingSessionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ActiveTrainingSessionInputSecondary.Companion")))
@interface DynamicsMultiplatformActiveTrainingSessionInputSecondaryCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformActiveTrainingSessionInputSecondaryCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("TrainingSessionSensorTypeExtended")))
@protocol DynamicsMultiplatformTrainingSessionSensorTypeExtended
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Alpha")))
@interface DynamicsMultiplatformAlpha : DynamicsMultiplatformBase <DynamicsMultiplatformTrainingSessionSensorTypeExtended>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)alpha __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformAlpha *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents the best punch for a specific [category]. Each side of the glove is treated
 * separately, therefore a distinction between [BestPunch.Single] and [BestPunch.Double] exists.
 * So one [category] may have two best punches, one fore the left, and the other for the right side.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("BestPunch")))
@interface DynamicsMultiplatformBestPunch : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformBestPunchCompanion *companion __attribute__((swift_name("companion")));

/**
 * @return the [BestPunch], if [BestPunch.Double] is used and the values that are compared
 * are equal, then [BestPunch.Double.left] is the first and therefore will be taken.
 */
@property (readonly) DynamicsMultiplatformPunch * _Nullable best __attribute__((swift_name("best")));

/**
 * @return the best left punch if available.
 */
@property (readonly) DynamicsMultiplatformPunch * _Nullable bestLeft __attribute__((swift_name("bestLeft")));

/**
 * @return the best right punch if available.
 */
@property (readonly) DynamicsMultiplatformPunch * _Nullable bestRight __attribute__((swift_name("bestRight")));
@property (readonly) DynamicsMultiplatformBestPunchCategory *category __attribute__((swift_name("category")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BestPunch.Companion")))
@interface DynamicsMultiplatformBestPunchCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBestPunchCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformBestPunch *)doInitCategory:(DynamicsMultiplatformBestPunchCategory *)category left:(DynamicsMultiplatformPunch * _Nullable)left right:(DynamicsMultiplatformPunch * _Nullable)right __attribute__((swift_name("doInit(category:left:right:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BestPunch.Double")))
@interface DynamicsMultiplatformBestPunchDouble : DynamicsMultiplatformBestPunch
- (instancetype)initWithCategory:(DynamicsMultiplatformBestPunchCategory *)category left:(DynamicsMultiplatformPunch *)left right:(DynamicsMultiplatformPunch *)right __attribute__((swift_name("init(category:left:right:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) DynamicsMultiplatformPunch *left __attribute__((swift_name("left")));
@property (readonly) DynamicsMultiplatformPunch *right __attribute__((swift_name("right")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BestPunch.None")))
@interface DynamicsMultiplatformBestPunchNone : DynamicsMultiplatformBestPunch
- (instancetype)initWithCategory:(DynamicsMultiplatformBestPunchCategory *)category __attribute__((swift_name("init(category:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BestPunch.Single")))
@interface DynamicsMultiplatformBestPunchSingle : DynamicsMultiplatformBestPunch
- (instancetype)initWithCategory:(DynamicsMultiplatformBestPunchCategory *)category side:(DynamicsMultiplatformSide *)side punch:(DynamicsMultiplatformPunch *)punch __attribute__((swift_name("init(category:side:punch:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) DynamicsMultiplatformPunch *punch __attribute__((swift_name("punch")));
@property (readonly) DynamicsMultiplatformSide *side __attribute__((swift_name("side")));
@end


/**
 * Represents best punch categories. A best punch must be always defined by the category.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BestPunchCategory")))
@interface DynamicsMultiplatformBestPunchCategory : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformBestPunchCategory *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Represents best punch categories. A best punch must be always defined by the category.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformBestPunchCategory *impact __attribute__((swift_name("impact")));
@property (class, readonly) DynamicsMultiplatformBestPunchCategory *peakForce __attribute__((swift_name("peakForce")));
@property (class, readonly) DynamicsMultiplatformBestPunchCategory *peakAcc __attribute__((swift_name("peakAcc")));
@property (class, readonly) DynamicsMultiplatformBestPunchCategory *peakVelo __attribute__((swift_name("peakVelo")));
@property (class, readonly) DynamicsMultiplatformBestPunchCategory *fastestPunchDuration __attribute__((swift_name("fastestPunchDuration")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformBestPunchCategory *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformBestPunchCategory *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Delta")))
@interface DynamicsMultiplatformDelta : DynamicsMultiplatformBase <DynamicsMultiplatformTrainingSessionSensorTypeExtended>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)delta __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDelta *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents a finished training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("FinishedTrainingSession")))
@interface DynamicsMultiplatformFinishedTrainingSession : DynamicsMultiplatformBase

/**
 * The body profile used for this session.
 */
@property (readonly) DynamicsMultiplatformBodyProfile *bodyProfile __attribute__((swift_name("bodyProfile")));

/**
 * The sensor type of the training session.
 */
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FinishedTrainingSession.Free")))
@interface DynamicsMultiplatformFinishedTrainingSessionFree : DynamicsMultiplatformFinishedTrainingSession
- (instancetype)initWithId:(id)id sensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType glovePairId:(id)glovePairId startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime endDateTime:(DynamicsMultiplatformKotlinInstant *)endDateTime resumedDuration:(int64_t)resumedDuration pausedDuration:(int64_t)pausedDuration bodyProfile:(DynamicsMultiplatformBodyProfile *)bodyProfile __attribute__((swift_name("init(id:sensorType:glovePairId:startDateTime:endDateTime:resumedDuration:pausedDuration:bodyProfile:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FinishedTrainingSessionStats")))
@interface DynamicsMultiplatformFinishedTrainingSessionStats : DynamicsMultiplatformBase
- (instancetype)initWithStats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats __attribute__((swift_name("init(stats:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFinishedTrainingSessionStats *)doCopyStats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats __attribute__((swift_name("doCopy(stats:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionStatsDetails *stats __attribute__((swift_name("stats")));
@end


/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FinishedTrainingSessionWithPunchIdsAndStats")))
@interface DynamicsMultiplatformFinishedTrainingSessionWithPunchIdsAndStats : DynamicsMultiplatformBase
- (instancetype)initWithFinishedTrainingSession:(DynamicsMultiplatformFinishedTrainingSession *)finishedTrainingSession stats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<id> *)punches __attribute__((swift_name("init(finishedTrainingSession:stats:punches:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFinishedTrainingSessionWithPunchIdsAndStats *)doCopyFinishedTrainingSession:(DynamicsMultiplatformFinishedTrainingSession *)finishedTrainingSession stats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<id> *)punches __attribute__((swift_name("doCopy(finishedTrainingSession:stats:punches:)")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The general info about the training session.
 */
@property (readonly) DynamicsMultiplatformFinishedTrainingSession *finishedTrainingSession __attribute__((swift_name("finishedTrainingSession")));

/**
 * The list of all punchIds of the training session.
 */
@property (readonly) NSArray<id> *punches __attribute__((swift_name("punches")));

/**
 * The global stats of the training session.
 */
@property (readonly) DynamicsMultiplatformTrainingSessionStatsDetails *stats __attribute__((swift_name("stats")));
@end


/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FinishedTrainingSessionWithStats")))
@interface DynamicsMultiplatformFinishedTrainingSessionWithStats : DynamicsMultiplatformBase
- (instancetype)initWithFinishedTrainingSession:(DynamicsMultiplatformFinishedTrainingSession *)finishedTrainingSession stats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<DynamicsMultiplatformPunch *> *)punches __attribute__((swift_name("init(finishedTrainingSession:stats:punches:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFinishedTrainingSessionWithStats *)doCopyFinishedTrainingSession:(DynamicsMultiplatformFinishedTrainingSession *)finishedTrainingSession stats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<DynamicsMultiplatformPunch *> *)punches __attribute__((swift_name("doCopy(finishedTrainingSession:stats:punches:)")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Same as [FinishedTrainingSession] but includes more details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The general info about the training session.
 */
@property (readonly) DynamicsMultiplatformFinishedTrainingSession *finishedTrainingSession __attribute__((swift_name("finishedTrainingSession")));

/**
 * The list of all punches of the training session.
 */
@property (readonly) NSArray<DynamicsMultiplatformPunch *> *punches __attribute__((swift_name("punches")));

/**
 * The global stats of the training session.
 */
@property (readonly) DynamicsMultiplatformTrainingSessionStatsDetails *stats __attribute__((swift_name("stats")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Incompatible")))
@interface DynamicsMultiplatformIncompatible : DynamicsMultiplatformBase <DynamicsMultiplatformTrainingSessionSensorTypeExtended>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)incompatible __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformIncompatible *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSession")))
@interface DynamicsMultiplatformTrainingSession : DynamicsMultiplatformBase
- (instancetype)initWithId:(id)id glovePairId:(id)glovePairId state:(DynamicsMultiplatformTrainingSessionState *)state isAutoResume:(BOOL)isAutoResume time:(DynamicsMultiplatformTrainingSessionTime * _Nullable)time sensorType:(DynamicsMultiplatformTrainingSessionSensorType * _Nullable)sensorType __attribute__((swift_name("init(id:glovePairId:state:isAutoResume:time:sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformTrainingSession *)doCopyId:(id)id glovePairId:(id)glovePairId state:(DynamicsMultiplatformTrainingSessionState *)state isAutoResume:(BOOL)isAutoResume time:(DynamicsMultiplatformTrainingSessionTime * _Nullable)time sensorType:(DynamicsMultiplatformTrainingSessionSensorType * _Nullable)sensorType __attribute__((swift_name("doCopy(id:glovePairId:state:isAutoResume:time:sensorType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id glovePairId __attribute__((swift_name("glovePairId")));
@property (readonly) id id __attribute__((swift_name("id")));
@property (readonly) BOOL isAutoResume __attribute__((swift_name("isAutoResume")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType * _Nullable sensorType __attribute__((swift_name("sensorType")));
@property (readonly) DynamicsMultiplatformTrainingSessionState *state __attribute__((swift_name("state")));
@property (readonly) DynamicsMultiplatformTrainingSessionTime * _Nullable time __attribute__((swift_name("time")));
@end


/**
 * Represents the average statistics the training session.
 *
 * If a value is null, then it means that there is no valid average value for a category.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionAverageStats")))
@interface DynamicsMultiplatformTrainingSessionAverageStats : DynamicsMultiplatformBase
- (instancetype)initWithAvgPunchDuration:(id _Nullable)avgPunchDuration avgPeakAcc:(DynamicsMultiplatformDouble * _Nullable)avgPeakAcc avgPeakVelocity:(DynamicsMultiplatformDouble * _Nullable)avgPeakVelocity avgPeakForce:(DynamicsMultiplatformDouble * _Nullable)avgPeakForce avgImpact:(DynamicsMultiplatformDouble * _Nullable)avgImpact __attribute__((swift_name("init(avgPunchDuration:avgPeakAcc:avgPeakVelocity:avgPeakForce:avgImpact:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionAverageStatsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionAverageStats *)doCopyAvgPunchDuration:(id _Nullable)avgPunchDuration avgPeakAcc:(DynamicsMultiplatformDouble * _Nullable)avgPeakAcc avgPeakVelocity:(DynamicsMultiplatformDouble * _Nullable)avgPeakVelocity avgPeakForce:(DynamicsMultiplatformDouble * _Nullable)avgPeakForce avgImpact:(DynamicsMultiplatformDouble * _Nullable)avgImpact __attribute__((swift_name("doCopy(avgPunchDuration:avgPeakAcc:avgPeakVelocity:avgPeakForce:avgImpact:)")));

/**
 * Represents the average statistics the training session.
 *
 * If a value is null, then it means that there is no valid average value for a category.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the average statistics the training session.
 *
 * If a value is null, then it means that there is no valid average value for a category.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the average statistics the training session.
 *
 * If a value is null, then it means that there is no valid average value for a category.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The average impact..
 */
@property (readonly) DynamicsMultiplatformDouble * _Nullable avgImpact __attribute__((swift_name("avgImpact")));

/**
 * The average peak acceleration.
 */
@property (readonly) DynamicsMultiplatformDouble * _Nullable avgPeakAcc __attribute__((swift_name("avgPeakAcc")));

/**
 * The average peak force.
 */
@property (readonly) DynamicsMultiplatformDouble * _Nullable avgPeakForce __attribute__((swift_name("avgPeakForce")));

/**
 * The average peak velocity.
 */
@property (readonly) DynamicsMultiplatformDouble * _Nullable avgPeakVelocity __attribute__((swift_name("avgPeakVelocity")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionAverageStats.Companion")))
@interface DynamicsMultiplatformTrainingSessionAverageStatsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionAverageStatsCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformTrainingSessionAverageStats *)doInitAvgPunchDuration:(id _Nullable)avgPunchDuration avgPeakAcc:(DynamicsMultiplatformDouble * _Nullable)avgPeakAcc avgPeakVelocity:(DynamicsMultiplatformDouble * _Nullable)avgPeakVelocity avgPeakForce:(DynamicsMultiplatformDouble * _Nullable)avgPeakForce avgImpact:(DynamicsMultiplatformDouble * _Nullable)avgImpact __attribute__((swift_name("doInit(avgPunchDuration:avgPeakAcc:avgPeakVelocity:avgPeakForce:avgImpact:)")));
@property (readonly) DynamicsMultiplatformTrainingSessionAverageStats *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents the best statistics of a training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionBestStats")))
@interface DynamicsMultiplatformTrainingSessionBestStats : DynamicsMultiplatformBase
- (instancetype)initWithImpact:(DynamicsMultiplatformBestPunch *)impact peakForce:(DynamicsMultiplatformBestPunch *)peakForce peakAcceleration:(DynamicsMultiplatformBestPunch *)peakAcceleration peakVelocity:(DynamicsMultiplatformBestPunch *)peakVelocity punchDuration:(DynamicsMultiplatformBestPunch *)punchDuration __attribute__((swift_name("init(impact:peakForce:peakAcceleration:peakVelocity:punchDuration:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionBestStatsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionBestStats *)doCopyImpact:(DynamicsMultiplatformBestPunch *)impact peakForce:(DynamicsMultiplatformBestPunch *)peakForce peakAcceleration:(DynamicsMultiplatformBestPunch *)peakAcceleration peakVelocity:(DynamicsMultiplatformBestPunch *)peakVelocity punchDuration:(DynamicsMultiplatformBestPunch *)punchDuration __attribute__((swift_name("doCopy(impact:peakForce:peakAcceleration:peakVelocity:punchDuration:)")));
- (DynamicsMultiplatformTrainingSessionBestStats *)doCopyByCategory:(DynamicsMultiplatformBestPunchCategory *)category bestPunch:(DynamicsMultiplatformBestPunch *)bestPunch __attribute__((swift_name("doCopyBy(category:bestPunch:)")));

/**
 * Represents the best statistics of a training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSArray<id> *)getAllPunchIds __attribute__((swift_name("getAllPunchIds()")));

/**
 * Represents the best statistics of a training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the best statistics of a training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The best punch(es) for the impact category.
 */
@property (readonly) DynamicsMultiplatformBestPunch *impact __attribute__((swift_name("impact")));

/**
 * The best punch(es) for the peak acceleration category.
 */
@property (readonly) DynamicsMultiplatformBestPunch *peakAcceleration __attribute__((swift_name("peakAcceleration")));

/**
 * The best punch(es) for the peak force category.
 */
@property (readonly) DynamicsMultiplatformBestPunch *peakForce __attribute__((swift_name("peakForce")));

/**
 * The best punch(es) for the peak velocity category.
 */
@property (readonly) DynamicsMultiplatformBestPunch *peakVelocity __attribute__((swift_name("peakVelocity")));

/**
 * The best punch(es) for the punch duration category.
 */
@property (readonly) DynamicsMultiplatformBestPunch *punchDuration __attribute__((swift_name("punchDuration")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionBestStats.Companion")))
@interface DynamicsMultiplatformTrainingSessionBestStatsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionBestStatsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformTrainingSessionBestStats *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents an internal training session event.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionEvent")))
@interface DynamicsMultiplatformTrainingSessionEvent : DynamicsMultiplatformBase
- (instancetype)initWithTimeStamp:(DynamicsMultiplatformKotlinInstant *)timeStamp type:(DynamicsMultiplatformTrainingSessionEventType *)type __attribute__((swift_name("init(timeStamp:type:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformTrainingSessionEvent *)doCopyTimeStamp:(DynamicsMultiplatformKotlinInstant *)timeStamp type:(DynamicsMultiplatformTrainingSessionEventType *)type __attribute__((swift_name("doCopy(timeStamp:type:)")));

/**
 * Represents an internal training session event.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents an internal training session event.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents an internal training session event.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionEventType *type __attribute__((swift_name("type")));
@end


/**
 * Unlike [TrainingSessionState], this enum represents a single event in time, but no state.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionEventType")))
@interface DynamicsMultiplatformTrainingSessionEventType : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformTrainingSessionEventType *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Unlike [TrainingSessionState], this enum represents a single event in time, but no state.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformTrainingSessionEventType *resume __attribute__((swift_name("resume")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionEventType *pause __attribute__((swift_name("pause")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionEventType *stop __attribute__((swift_name("stop")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformTrainingSessionEventType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformTrainingSessionEventType *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * An extended state of [TrainingSessionState] which contains additional data for the specific state
 * in which the session currently resides.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("TrainingSessionExtendedState")))
@interface DynamicsMultiplatformTrainingSessionExtendedState : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionExtendedStateCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Companion")))
@interface DynamicsMultiplatformTrainingSessionExtendedStateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionExtendedStateCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformTrainingSessionExtendedState *)getByStateAndTimeSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType state:(DynamicsMultiplatformTrainingSessionState *)state time:(DynamicsMultiplatformTrainingSessionTime *(^)(void))time __attribute__((swift_name("getByStateAndTime(sensorType:state:time:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Finished")))
@interface DynamicsMultiplatformTrainingSessionExtendedStateFinished : DynamicsMultiplatformTrainingSessionExtendedState
- (instancetype)initWithSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime endDateTime:(DynamicsMultiplatformKotlinInstant *)endDateTime resumedDuration:(int64_t)resumedDuration pausedDuration:(int64_t)pausedDuration __attribute__((swift_name("init(sensorType:startDateTime:endDateTime:resumedDuration:pausedDuration:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Initializing")))
@interface DynamicsMultiplatformTrainingSessionExtendedStateInitializing : DynamicsMultiplatformTrainingSessionExtendedState
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)initializing __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionExtendedStateInitializing *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Paused")))
@interface DynamicsMultiplatformTrainingSessionExtendedStatePaused : DynamicsMultiplatformTrainingSessionExtendedState
- (instancetype)initWithSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime accumulatedResumedDurationUntilLastPauseEvent:(int64_t)accumulatedResumedDurationUntilLastPauseEvent pausedSince:(DynamicsMultiplatformKotlinInstant *)pausedSince __attribute__((swift_name("init(sensorType:startDateTime:accumulatedResumedDurationUntilLastPauseEvent:pausedSince:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Ready")))
@interface DynamicsMultiplatformTrainingSessionExtendedStateReady : DynamicsMultiplatformTrainingSessionExtendedState
- (instancetype)initWithSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("init(sensorType:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformTrainingSessionExtendedStateReady *)doCopySensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType __attribute__((swift_name("doCopy(sensorType:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionExtendedState.Resumed")))
@interface DynamicsMultiplatformTrainingSessionExtendedStateResumed : DynamicsMultiplatformTrainingSessionExtendedState
- (instancetype)initWithSensorType:(DynamicsMultiplatformTrainingSessionSensorType *)sensorType startDateTime:(DynamicsMultiplatformKotlinInstant *)startDateTime accumulatedResumedDurationUntilLastPauseEvent:(int64_t)accumulatedResumedDurationUntilLastPauseEvent resumedSince:(DynamicsMultiplatformKotlinInstant *)resumedSince __attribute__((swift_name("init(sensorType:startDateTime:accumulatedResumedDurationUntilLastPauseEvent:resumedSince:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionSensorType *sensorType __attribute__((swift_name("sensorType")));
@end


/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionInput")))
@interface DynamicsMultiplatformTrainingSessionInput : DynamicsMultiplatformBase
- (instancetype)initWithTrainingSessionId:(id)trainingSessionId timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp state:(DynamicsMultiplatformTrainingSessionState *)state actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("init(trainingSessionId:timestamp:state:actor:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionInputCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionInput *)doCopyTrainingSessionId:(id)trainingSessionId timestamp:(DynamicsMultiplatformKotlinInstant *)timestamp state:(DynamicsMultiplatformTrainingSessionState *)state actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("doCopy(trainingSessionId:timestamp:state:actor:)")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * The input parameter for controlling a training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionStateActor *actor __attribute__((swift_name("actor")));
@property (readonly) DynamicsMultiplatformTrainingSessionState *state __attribute__((swift_name("state")));
@property (readonly) id trainingSessionId __attribute__((swift_name("trainingSessionId")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionInput.Companion")))
@interface DynamicsMultiplatformTrainingSessionInputCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionInputCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionSensorType")))
@interface DynamicsMultiplatformTrainingSessionSensorType : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformTrainingSessionSensorType *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformTrainingSessionSensorType *alpha __attribute__((swift_name("alpha")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionSensorType *delta __attribute__((swift_name("delta")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformTrainingSessionSensorType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformTrainingSessionSensorType *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("TrainingSessionSettings")))
@interface DynamicsMultiplatformTrainingSessionSettings : DynamicsMultiplatformBase
@property (readonly) BOOL isAutoResume __attribute__((swift_name("isAutoResume")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionSettings.Free")))
@interface DynamicsMultiplatformTrainingSessionSettingsFree : DynamicsMultiplatformTrainingSessionSettings
- (instancetype)initWithIsAutoResume:(BOOL)isAutoResume __attribute__((swift_name("init(isAutoResume:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * Represents the simplified state for a training session without any additional data.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionState")))
@interface DynamicsMultiplatformTrainingSessionState : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformTrainingSessionState *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Represents the simplified state for a training session without any additional data.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformTrainingSessionState *theInit __attribute__((swift_name("theInit")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionState *ready __attribute__((swift_name("ready")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionState *resumed __attribute__((swift_name("resumed")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionState *paused __attribute__((swift_name("paused")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionState *finished __attribute__((swift_name("finished")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformTrainingSessionState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformTrainingSessionState *> *entries __attribute__((swift_name("entries")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * Represents the actor of training sessions.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionStateActor")))
@interface DynamicsMultiplatformTrainingSessionStateActor : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformTrainingSessionStateActor *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Represents the actor of training sessions.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformTrainingSessionStateActor *manual __attribute__((swift_name("manual")));
@property (class, readonly) DynamicsMultiplatformTrainingSessionStateActor *auto_ __attribute__((swift_name("auto_")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformTrainingSessionStateActor *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformTrainingSessionStateActor *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Same as [FinishedTrainingSessionWithStats] but without the [FinishedTrainingSession] object.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionStats")))
@interface DynamicsMultiplatformTrainingSessionStats : DynamicsMultiplatformBase
- (instancetype)initWithStats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<DynamicsMultiplatformPunch *> *)punches __attribute__((swift_name("init(stats:punches:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionStatsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionStats *)doCopyStats:(DynamicsMultiplatformTrainingSessionStatsDetails *)stats punches:(NSArray<DynamicsMultiplatformPunch *> *)punches __attribute__((swift_name("doCopy(stats:punches:)")));

/**
 * Same as [FinishedTrainingSessionWithStats] but without the [FinishedTrainingSession] object.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Same as [FinishedTrainingSessionWithStats] but without the [FinishedTrainingSession] object.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Same as [FinishedTrainingSessionWithStats] but without the [FinishedTrainingSession] object.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformPunch * _Nullable lastLeftPunch __attribute__((swift_name("lastLeftPunch")));
@property (readonly) DynamicsMultiplatformPunch * _Nullable lastPunch __attribute__((swift_name("lastPunch")));
@property (readonly) DynamicsMultiplatformPunch * _Nullable lastRightPunch __attribute__((swift_name("lastRightPunch")));

/**
 * The latest punch is the last element in the list.
 */
@property (readonly) NSArray<DynamicsMultiplatformPunch *> *punches __attribute__((swift_name("punches")));
@property (readonly) DynamicsMultiplatformTrainingSessionStatsDetails *stats __attribute__((swift_name("stats")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionStats.Companion")))
@interface DynamicsMultiplatformTrainingSessionStatsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionStatsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformTrainingSessionStats *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents the statistic details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionStatsDetails")))
@interface DynamicsMultiplatformTrainingSessionStatsDetails : DynamicsMultiplatformBase
- (instancetype)initWithTotalPunchCount:(int32_t)totalPunchCount avgStats:(DynamicsMultiplatformTrainingSessionAverageStats *)avgStats bestStats:(DynamicsMultiplatformTrainingSessionBestStats *)bestStats __attribute__((swift_name("init(totalPunchCount:avgStats:bestStats:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionStatsDetailsCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionStatsDetails *)doCopyTotalPunchCount:(int32_t)totalPunchCount avgStats:(DynamicsMultiplatformTrainingSessionAverageStats *)avgStats bestStats:(DynamicsMultiplatformTrainingSessionBestStats *)bestStats __attribute__((swift_name("doCopy(totalPunchCount:avgStats:bestStats:)")));

/**
 * Represents the statistic details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the statistic details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the statistic details about the training session.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The average stats of the session.
 */
@property (readonly) DynamicsMultiplatformTrainingSessionAverageStats *avgStats __attribute__((swift_name("avgStats")));

/**
 * The best stats of the session.
 */
@property (readonly) DynamicsMultiplatformTrainingSessionBestStats *bestStats __attribute__((swift_name("bestStats")));

/**
 * The total number of punches which also includes punches that may not be counted for the stats
 * in a case when the computation fails.
 */
@property (readonly) int32_t totalPunchCount __attribute__((swift_name("totalPunchCount")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionStatsDetails.Companion")))
@interface DynamicsMultiplatformTrainingSessionStatsDetailsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionStatsDetailsCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformTrainingSessionStatsDetails *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents the time properties for an active training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionTime")))
@interface DynamicsMultiplatformTrainingSessionTime : DynamicsMultiplatformBase
- (instancetype)initWithStart:(DynamicsMultiplatformKotlinInstant *)start end:(DynamicsMultiplatformKotlinInstant *)end resumedDuration:(int64_t)resumedDuration pausedDuration:(int64_t)pausedDuration lastEvent:(DynamicsMultiplatformTrainingSessionEvent *)lastEvent __attribute__((swift_name("init(start:end:resumedDuration:pausedDuration:lastEvent:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformTrainingSessionTimeCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformTrainingSessionTime *)doCopyStart:(DynamicsMultiplatformKotlinInstant *)start end:(DynamicsMultiplatformKotlinInstant *)end resumedDuration:(int64_t)resumedDuration pausedDuration:(int64_t)pausedDuration lastEvent:(DynamicsMultiplatformTrainingSessionEvent *)lastEvent __attribute__((swift_name("doCopy(start:end:resumedDuration:pausedDuration:lastEvent:)")));

/**
 * Represents the time properties for an active training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the time properties for an active training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the time properties for an active training session.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformTrainingSessionEvent *lastEvent __attribute__((swift_name("lastEvent")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionTime.Companion")))
@interface DynamicsMultiplatformTrainingSessionTimeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTrainingSessionTimeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformTrainingSessionTime *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * Represents a training session with time, [state] contains the information about the time
 * properties.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("TrainingSessionWithTime")))
@interface DynamicsMultiplatformTrainingSessionWithTime : DynamicsMultiplatformBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL isAutoResume __attribute__((swift_name("isAutoResume")));
@property (readonly) DynamicsMultiplatformTrainingSessionExtendedState *state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionWithTime.Free")))
@interface DynamicsMultiplatformTrainingSessionWithTimeFree : DynamicsMultiplatformTrainingSessionWithTime
- (instancetype)initWithId:(id)id glovePairId:(id)glovePairId extendedState:(DynamicsMultiplatformTrainingSessionExtendedState *)extendedState isAutoResume:(BOOL)isAutoResume __attribute__((swift_name("init(id:glovePairId:extendedState:isAutoResume:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Unknown")))
@interface DynamicsMultiplatformUnknown : DynamicsMultiplatformBase <DynamicsMultiplatformTrainingSessionSensorTypeExtended>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unknown __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformUnknown *shared __attribute__((swift_name("shared")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents the input object for modifying properties of a throughput test entry.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTestInput")))
@interface DynamicsMultiplatformThroughputTestInput : DynamicsMultiplatformBase
- (instancetype)initWithThroughputTestId:(id)throughputTestId text:(NSString * _Nullable)text __attribute__((swift_name("init(throughputTestId:text:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformThroughputTestInputCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformThroughputTestInput *)doCopyThroughputTestId:(id)throughputTestId text:(NSString * _Nullable)text __attribute__((swift_name("doCopy(throughputTestId:text:)")));

/**
 * Represents the input object for modifying properties of a throughput test entry.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the input object for modifying properties of a throughput test entry.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents the input object for modifying properties of a throughput test entry.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable text __attribute__((swift_name("text")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ThroughputTestInput.Companion")))
@interface DynamicsMultiplatformThroughputTestInputCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformThroughputTestInputCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareImage")))
@interface DynamicsMultiplatformFirmwareImage : DynamicsMultiplatformBase
- (instancetype)initWithBinImageFilePath:(NSString *)binImageFilePath manifest:(DynamicsMultiplatformFirmwareImageManifest *)manifest settings:(DynamicsMultiplatformFirmwareImageSettings *)settings updateMode:(DynamicsMultiplatformFirmwareUpdateMode *)updateMode __attribute__((swift_name("init(binImageFilePath:manifest:settings:updateMode:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFirmwareImage *)doCopyBinImageFilePath:(NSString *)binImageFilePath manifest:(DynamicsMultiplatformFirmwareImageManifest *)manifest settings:(DynamicsMultiplatformFirmwareImageSettings *)settings updateMode:(DynamicsMultiplatformFirmwareUpdateMode *)updateMode __attribute__((swift_name("doCopy(binImageFilePath:manifest:settings:updateMode:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The absolute filepath to the .bin file of the firmware image.
 */
@property (readonly) NSString *binImageFilePath __attribute__((swift_name("binImageFilePath")));

/**
 * The name of the file of the release version.
 */
@property (readonly) DynamicsMultiplatformFirmwareImageManifest *manifest __attribute__((swift_name("manifest")));

/**
 * The settings for DFU operation.
 */
@property (readonly) DynamicsMultiplatformFirmwareImageSettings *settings __attribute__((swift_name("settings")));

/**
 * The firmware update mode.
 */
@property (readonly) DynamicsMultiplatformFirmwareUpdateMode *updateMode __attribute__((swift_name("updateMode")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareImageManifest")))
@interface DynamicsMultiplatformFirmwareImageManifest : DynamicsMultiplatformBase
- (instancetype)initWithSlot:(int32_t)slot index:(int32_t)index __attribute__((swift_name("init(slot:index:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFirmwareImageManifest *)doCopySlot:(int32_t)slot index:(int32_t)index __attribute__((swift_name("doCopy(slot:index:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The index of the image.
 */
@property (readonly) int32_t index __attribute__((swift_name("index")));

/**
 * The slot to which the firmware image is uploaded/written into.
 */
@property (readonly) int32_t slot __attribute__((swift_name("slot")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareImageMeta")))
@interface DynamicsMultiplatformFirmwareImageMeta : DynamicsMultiplatformBase
- (instancetype)initWithVersion:(DynamicsMultiplatformBle_multiplex_uuidVersion *)version release:(NSString *)release debug:(NSString * _Nullable)debug __attribute__((swift_name("init(version:release:debug:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFirmwareImageMeta *)doCopyVersion:(DynamicsMultiplatformBle_multiplex_uuidVersion *)version release:(NSString *)release debug:(NSString * _Nullable)debug __attribute__((swift_name("doCopy(version:release:debug:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The name of the file of the debug version.
 */
@property (readonly) NSString * _Nullable debug __attribute__((swift_name("debug")));

/**
 * The name of the file of the release version.
 */
@property (readonly, getter=release_) NSString *release __attribute__((swift_name("release")));

/**
 * The version of the firmware image.
 */
@property (readonly) DynamicsMultiplatformBle_multiplex_uuidVersion *version __attribute__((swift_name("version")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareImageSettings")))
@interface DynamicsMultiplatformFirmwareImageSettings : DynamicsMultiplatformBase
- (instancetype)initWithEraseAppSettings:(BOOL)eraseAppSettings estimatedSwapTime:(int64_t)estimatedSwapTime __attribute__((swift_name("init(eraseAppSettings:estimatedSwapTime:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformFirmwareImageSettings *)doCopyEraseAppSettings:(BOOL)eraseAppSettings estimatedSwapTime:(int64_t)estimatedSwapTime __attribute__((swift_name("doCopy(eraseAppSettings:estimatedSwapTime:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL eraseAppSettings __attribute__((swift_name("eraseAppSettings")));
@end


/**
 * The DFU libs have several modes on how to proceed with a firmware update.
 * - Android doc: https://github.com/NordicSemiconductor/Android-nRF-Connect-Device-Manager?tab=readme-ov-file#firmware-upgrade-mode
 * - iOS doc: https://github.com/NordicSemiconductor/Android-nRF-Connect-Device-Manager?tab=readme-ov-file#firmware-upgrade-mode
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareUpdateMode")))
@interface DynamicsMultiplatformFirmwareUpdateMode : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformFirmwareUpdateMode *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * The DFU libs have several modes on how to proceed with a firmware update.
 * - Android doc: https://github.com/NordicSemiconductor/Android-nRF-Connect-Device-Manager?tab=readme-ov-file#firmware-upgrade-mode
 * - iOS doc: https://github.com/NordicSemiconductor/Android-nRF-Connect-Device-Manager?tab=readme-ov-file#firmware-upgrade-mode
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformFirmwareUpdateMode *testAndConfirm __attribute__((swift_name("testAndConfirm")));
@property (class, readonly) DynamicsMultiplatformFirmwareUpdateMode *testOnly __attribute__((swift_name("testOnly")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformFirmwareUpdateMode *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformFirmwareUpdateMode *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((swift_name("KotlinRuntimeException")))
@interface DynamicsMultiplatformKotlinRuntimeException : DynamicsMultiplatformKotlinException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("KotlinIllegalArgumentException")))
@interface DynamicsMultiplatformKotlinIllegalArgumentException : DynamicsMultiplatformKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfileValidationException")))
@interface DynamicsMultiplatformBodyProfileValidationException : DynamicsMultiplatformKotlinIllegalArgumentException
- (instancetype)initWithBodyProfileValidation:(DynamicsMultiplatformBodyProfileValidation *)bodyProfileValidation __attribute__((swift_name("init(bodyProfileValidation:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformBodyProfileValidation *bodyProfileValidation __attribute__((swift_name("bodyProfileValidation")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsDatabaseException")))
@interface DynamicsMultiplatformDynamicsDatabaseException : DynamicsMultiplatformKotlinException
- (instancetype)initWithError:(DynamicsMultiplatformDynamicsDbError *)error msg:(NSString *)msg cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(error:msg:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformDynamicsDbError *error __attribute__((swift_name("error")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) NSString *msg __attribute__((swift_name("msg")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsDbError")))
@interface DynamicsMultiplatformDynamicsDbError : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformDynamicsDbError *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *notFound __attribute__((swift_name("notFound")));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *constraintViolation __attribute__((swift_name("constraintViolation")));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *obsoleteAction __attribute__((swift_name("obsoleteAction")));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *apiMisuse __attribute__((swift_name("apiMisuse")));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *nullProperty __attribute__((swift_name("nullProperty")));
@property (class, readonly) DynamicsMultiplatformDynamicsDbError *na __attribute__((swift_name("na")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformDynamicsDbError *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformDynamicsDbError *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsOpError")))
@interface DynamicsMultiplatformDynamicsOpError : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformDynamicsOpError *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformDynamicsOpError *debugFirmwareUpdateImageNotAvailable __attribute__((swift_name("debugFirmwareUpdateImageNotAvailable")));
@property (class, readonly) DynamicsMultiplatformDynamicsOpError *invalidCapDetectionDirections __attribute__((swift_name("invalidCapDetectionDirections")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformDynamicsOpError *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformDynamicsOpError *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsOpException")))
@interface DynamicsMultiplatformDynamicsOpException : DynamicsMultiplatformKotlinException
- (instancetype)initWithError:(DynamicsMultiplatformDynamicsOpError *)error msg:(NSString *)msg cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(error:msg:cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformDynamicsOpError *error __attribute__((swift_name("error")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@property (readonly) NSString *msg __attribute__((swift_name("msg")));
@end


/**
 * Represents a cases for basic validation of data properties.
 *
 * The defined cases are very generic so that they may be applied on any kind of raw input.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("BasicValidation")))
@protocol DynamicsMultiplatformBasicValidation
@required
@end


/**
 * Indicates that the current property is above the defined maximum.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BasicValidationAboveMax")))
@interface DynamicsMultiplatformBasicValidationAboveMax : DynamicsMultiplatformBase <DynamicsMultiplatformBasicValidation>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Indicates that the current property is above the defined maximum.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)aboveMax __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBasicValidationAboveMax *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Indicates that the current property is below the defined minimum.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BasicValidationBelowMin")))
@interface DynamicsMultiplatformBasicValidationBelowMin : DynamicsMultiplatformBase <DynamicsMultiplatformBasicValidation>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Indicates that the current property is below the defined minimum.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)belowMin __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBasicValidationBelowMin *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Indicates that the current property has an invalid format.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BasicValidationInvalidFormat")))
@interface DynamicsMultiplatformBasicValidationInvalidFormat : DynamicsMultiplatformBase <DynamicsMultiplatformBasicValidation>
- (instancetype)initWithReason:(NSString *)reason __attribute__((swift_name("init(reason:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBasicValidationInvalidFormat *)doCopyReason:(NSString *)reason __attribute__((swift_name("doCopy(reason:)")));

/**
 * Indicates that the current property has an invalid format.
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Indicates that the current property has an invalid format.
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *reason __attribute__((swift_name("reason")));
@end


/**
 * Indicates that the current value of the property is missing or empty.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BasicValidationMissing")))
@interface DynamicsMultiplatformBasicValidationMissing : DynamicsMultiplatformBase <DynamicsMultiplatformBasicValidation>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Indicates that the current value of the property is missing or empty.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)missing __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBasicValidationMissing *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Indicates that the current value of the property satisfies the requirements.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BasicValidationOk")))
@interface DynamicsMultiplatformBasicValidationOk : DynamicsMultiplatformBase <DynamicsMultiplatformBasicValidation>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Indicates that the current value of the property satisfies the requirements.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)ok __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformBasicValidationOk *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents the http client log levels, this is the same as ktor's log level.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("HttpClientLogLevel")))
@interface DynamicsMultiplatformHttpClientLogLevel : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformHttpClientLogLevel *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Represents the http client log levels, this is the same as ktor's log level.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformHttpClientLogLevel *all __attribute__((swift_name("all")));
@property (class, readonly) DynamicsMultiplatformHttpClientLogLevel *headers __attribute__((swift_name("headers")));
@property (class, readonly) DynamicsMultiplatformHttpClientLogLevel *body __attribute__((swift_name("body")));
@property (class, readonly) DynamicsMultiplatformHttpClientLogLevel *info __attribute__((swift_name("info")));
@property (class, readonly) DynamicsMultiplatformHttpClientLogLevel *none __attribute__((swift_name("none")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformHttpClientLogLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformHttpClientLogLevel *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareUpdateExtensions")))
@interface DynamicsMultiplatformFirmwareUpdateExtensions : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)firmwareUpdateExtensions __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformFirmwareUpdateExtensions *shared __attribute__((swift_name("shared")));

/**
 * Checks semantic versioning for [peripheralVersion] and [imageVersion], and returns true
 * if [imageVersion] is newer than [peripheralVersion].
 */
- (BOOL)isUpdateAvailablePeripheralVersion:(NSString *)peripheralVersion imageVersion:(DynamicsMultiplatformBle_multiplex_uuidVersion *)imageVersion __attribute__((swift_name("isUpdateAvailable(peripheralVersion:imageVersion:)")));
@end


/**
 * Provides functions to export punch data with samples from the database.
 *
 * - Every export function will return an absolute file path (in the temporary/cached storage) to a
 * folder where all the exported data resides or a single file.
 * - The consumer is responsible for cleaning up no longer used files.
 * - If an error occurs, then a clean-up is automatically performed.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ExportRepository")))
@interface DynamicsMultiplatformExportRepository : DynamicsMultiplatformBase
@end


/**
 * Provides functions to access the data of finished training sessions.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FinishedTrainingSessionRepository")))
@interface DynamicsMultiplatformFinishedTrainingSessionRepository : DynamicsMultiplatformBase

/**
 * @return a list of [FinishedTrainingSession] of all current finished training sessions.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^finishedTrainingSessions)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformFinishedTrainingSession *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("finishedTrainingSessions")));
@end


/**
 * Provides functions to check for available firmware updates of peripherals, and download the
 * firmware image content.
 *
 * Some debugging functionality can be influenced through [GloveOptions], such as:
 * - [GloveOptions.firmwareUpdateBaseUrl] allows to change the baseUrl of the remote firmware image
 * location.
 * - [GloveOptions.useDebugFirmwareUpdateImage] allows to use the debug image instead of the release
 * image firmware.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FirmwareUpdateRepository")))
@interface DynamicsMultiplatformFirmwareUpdateRepository : DynamicsMultiplatformBase
@end


/**
 * Represents the API mainly for for configuring a glove device.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveConfigurationRepository")))
@interface DynamicsMultiplatformGloveConfigurationRepository : DynamicsMultiplatformBase
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveRepository")))
@interface DynamicsMultiplatformGloveRepository : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformGloveRepositoryCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformGlovePair *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeGlovePairs __attribute__((swift_name("observeGlovePairs()")));

/**
 * @return a flow of all gloves' acceleration streams.
 */
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformAccStreamData *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeGlovesAccelerationStream __attribute__((swift_name("observeGlovesAccelerationStream()")));

/**
 * Returns a flow of all gloves. The flow will emit a new list of gloves whenever one of the
 * gloves inside the list changes.
 *
 * @return a flow of all gloves.
 */
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformGlove *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeGloves __attribute__((swift_name("observeGloves()")));

/**
 * Returns all persisted peripherals.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^savedPeripherals)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformPeripheralDto *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("savedPeripherals")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("GloveRepository.Companion")))
@interface DynamicsMultiplatformGloveRepositoryCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformGloveRepositoryCompanion *shared __attribute__((swift_name("shared")));
@end


/**
 * Provides functions for scanning for glove devices and connecting to them.
 *
 * The consumer has to follow these instructions:
 * 1. Subscribe to [scannerState] and check its [ScannerState]. The state may be of type
 * [com.riseworld.launchpad.ble.multiplex.models.exception.ScannerError] which is expected if
 * e.g. there are no bluetooth permissions granted. In that case, the consumer has to resolve the
 * errors in order to proceed. The state may be also of type [ScannerState.Inactive] if for example
 * no one is subscribed to [nearbyGloves] or the consumer app is in background.
 * 2. If [scannerState] is not of type
 * [com.riseworld.launchpad.ble.multiplex.models.exception.ScannerError], then proceed with a
 * subscription to the [nearbyGloves] flow, [scannerState] should then transition to
 * [ScannerState.Active] and [nearbyGloves] will emit regularly.
 * 3. Ensure that the glove device is advertising.
 * 4. Identify your device in the list [nearbyGloves] and call [pair], [NearbyGlove.state] will
 * indicate the state of the nearby glove, in that case the device that is pairing will move to
 * [NearbyGloveState.IS_CONNECTING].
 * 5. If [pair] succeeds, then the glove is registered in the multiplatform module, if it fails then
 * a new pair attempt has to be started.
 * 6. It is crucial to stop the scanning by unsubscribing from [nearbyGloves], otherwise scanning
 * will be continued indefinitely.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PairingRepository")))
@interface DynamicsMultiplatformPairingRepository : DynamicsMultiplatformBase

/**
 * Starts to scan for nearby gloves if there is at least one subscriber. State of the scanner is
 * delivered through [scannerState].
 *
 * - The list of nearby gloves is only cached if there is at least one subscriber, if
 * [scannerState] moves to [ScannerState.Inactive] then the list is cleared.
 * - android-only: Every time the [ScannerState] transitions to [ScannerState.Active], the bonds
 * of all unknown gloves starting with
 * [com.riseworld.dynamics.constants.DynamicsConstants.DEFAULT_ADVERTISING_NAME_PREFIX]
 * are cleared programmatically unless the glove is bonded and persisted in the database.
 *
 * @return a flow with the recently found [NearbyGlove]s.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^nearbyGloves)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformNearbyGlove *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("nearbyGloves")));

/**
 * The most recent state of the ble scanner.
 *
 * For apple targets it is required to subscribe to [nearbyGloves] at least once within the
 * app's lifetime in order to receive a valid scanner state.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^scannerState)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformScannerState *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("scannerState")));
@end


/**
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ProfileRepository")))
@interface DynamicsMultiplatformProfileRepository : DynamicsMultiplatformBase

/**
 * @return the current [BodyProfile] of the user's profile.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^bodyProfile)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformBodyProfile * _Nullable, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("bodyProfile")));
@end


/**
 * Provides functions to retrieve punch data from the database.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunchRepository")))
@interface DynamicsMultiplatformPunchRepository : DynamicsMultiplatformBase
@end


/**
 * Provides functions to retrieve raw sensor data from the gloves.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorDataRepository")))
@interface DynamicsMultiplatformSensorDataRepository : DynamicsMultiplatformBase

/**
 * A convenience function for [observeSensorData] to observe sensor data from all gloves.
 */
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformGloveWithSensorData *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeSensorDataFromAllGloves __attribute__((swift_name("observeSensorDataFromAllGloves()")));

/**
 * Pre-Condition: For iOS consumers, add the NSMotionUsageDescription key into your Info.plist as
 * this permission is used to obtain the current atmospheric pressure.
 *
 * Observes the barometer sensor of the smartphone.
 *
 * This flow may also emit nothing if the smartphone doesn't have any built-in barometer
 * sensor.
 *
 * @return a flow of [Pascal].
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeSmartphoneBarometer __attribute__((swift_name("observeSmartphoneBarometer()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformInt *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeSmartphoneBarometerNative __attribute__((swift_name("observeSmartphoneBarometerNative()")));
@end


/**
 * Provides functions to run tests.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TestRepository")))
@interface DynamicsMultiplatformTestRepository : DynamicsMultiplatformBase

/**
 * Observes throughput tests for all peripherals.
 */
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformGloveWithThroughputTest *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeAllThroughputTests __attribute__((swift_name("observeAllThroughputTests()")));

/**
 * @return all [ThroughputTestDto] from [Database].
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^throughPutTests)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformThroughputTestDto *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("throughPutTests")));
@end


/**
 * Pre-Condition: For iOS consumers, add the NSMotionUsageDescription key into your Info.plist as
 * this permission is used to obtain the current atmospheric pressure.
 *
 * Provides functions for starting and manipulating sessions (workouts), a short intro on how the
 * workflow is designed:
 *
 * - An active session is required in order to start obtaining punch data and persist it in the
 * [Database].
 * - A session has multiple [TrainingSessionState]s, if it's [TrainingSessionState.FINISHED], then
 * the session becomes immutable, punches can no longer be added and the session can be retrieved
 * via [FinishedTrainingSessionRepository].
 * - If the session's state is not [TrainingSessionState.FINISHED], then it's active, there can be
 * only one active session in the [Database].
 *
 * How to start/pause/finish a session:
 * - First, initialize a new session with [initializeActiveTrainingSession] or check if there is already an
 * active one by using the flows [activeTrainingSessionStats] and [activeTrainingSessionTime].
 * - Second, control the session's state by using [toggleActiveTrainingSessionState] in order to
 * pause/resume a session.
 * - Finally, to finish the session, use [finishActiveTrainingSession]. After that, the training
 * session will be available via [FinishedTrainingSessionRepository].
 *
 * Further enhancements:
 * - The "autoResume" flag allows a session to resume automatically for any new incoming punches.
 * - The time of an active session can be tracked with [activeTrainingSessionTime] where the resumed
 * and paused duration can be calculated, this can be used to synchronize the timer in the UI with
 * the time in the database.
 *
 * If an active session is started, the [GloveDataObserver] automatically requests the firmware
 * to start sending punch data.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionRepository")))
@interface DynamicsMultiplatformTrainingSessionRepository : DynamicsMultiplatformBase

/**
 * @return [TrainingSessionStats] for the active training session. No emissions are performed
 * if there is no active training session.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^activeTrainingSessionStats)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformTrainingSessionStats *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("activeTrainingSessionStats")));

/**
 * @return [TrainingSessionWithTime] or null if there is no active training session.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^activeTrainingSessionTime)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformTrainingSessionWithTime * _Nullable, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("activeTrainingSessionTime")));
@end


/**
 * Represents the settings for the dynamics module.
 *
 * Please note that not all settings that represented here have implications on the internal state
 * of the dynamics multiplatform module, some of the keys are only intended for the consumer.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsSettings")))
@interface DynamicsMultiplatformDynamicsSettings : DynamicsMultiplatformBase
- (instancetype)initWithDefaultSettings:(id<DynamicsMultiplatformObservableSettings>)defaultSettings __attribute__((swift_name("init(defaultSettings:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamicsSettingsCompanion *companion __attribute__((swift_name("companion")));

/**
 * @return the installation unique id that is initially set if it doesn't exist yet.
 */
- (NSString * _Nullable)getInstallationId __attribute__((swift_name("getInstallationId()")));

/**
 * Incoming punch data is usually not always persisted in the database, there are constraints
 * that ignore punches, for example if the pressure is too low, then a punch is ignored.
 *
 * If this option is enabled, then all constraints that decide if a punch should be persisted
 * or not are ignored.
 *
 * This option is useful for testing and debugging purposes.
 */
- (void)setAcceptAllPunchesAcceptAllPunches:(BOOL)acceptAllPunches __attribute__((swift_name("setAcceptAllPunches(acceptAllPunches:)")));

/**
 * Set the [BACKGROUND_DISCONNECT_TIMEOUT].
 */
- (void)setBackgroundDisconnectTimeoutDuration:(int64_t)duration __attribute__((swift_name("setBackgroundDisconnectTimeout(duration:)")));

/**
 * Set the [BACKGROUND_DISCONNECT_TIMEOUT].
 */
- (void)setBackgroundDisconnectTimeoutInSecondsSeconds:(int32_t)seconds __attribute__((swift_name("setBackgroundDisconnectTimeoutInSeconds(seconds:)")));
- (void)setDebuggingModeIsEnabled:(BOOL)isEnabled __attribute__((swift_name("setDebuggingMode(isEnabled:)")));

/**
 * If the dummy impact data mode is enabled, then the glove firmware will send dummy data during
 * a session (workout) instead of actively measuring real data.
 *
 * This option is useful for testing and debugging purposes.
 */
- (void)setDummyImpactDataEnabledIsDummyDataEnabled:(BOOL)isDummyDataEnabled __attribute__((swift_name("setDummyImpactDataEnabled(isDummyDataEnabled:)")));

/**
 * Set the [DEBUG_FIRMWARE_UPDATE_BASE_URL].
 */
- (void)setFirmwareUpdateBaseUrlUrl:(NSString *)url __attribute__((swift_name("setFirmwareUpdateBaseUrl(url:)")));

/**
 * Punch details are usually not always kept as soon as a training session is finished.
 *
 * Enable this option to ignore all constraints that decide if punch details (samples) should
 * be removed.
 */
- (void)setKeepAllPunchDetailsIsEnabled:(BOOL)isEnabled __attribute__((swift_name("setKeepAllPunchDetails(isEnabled:)")));

/**
 * Set the flag for showing onboarding UI for an app start.
 */
- (void)setShowOnboardingIsEnabled:(BOOL)isEnabled __attribute__((swift_name("setShowOnboarding(isEnabled:)")));

/**
 * Set the [DEBUG_USE_DEBUG_FIRMWARE_UPDATE_IMAGE].
 */
- (void)setUseDebugImageForFirmwareUpdateUseDebug:(BOOL)useDebug __attribute__((swift_name("setUseDebugImageForFirmwareUpdate(useDebug:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsSettings.Companion")))
@interface DynamicsMultiplatformDynamicsSettingsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamicsSettingsCompanion *shared __attribute__((swift_name("shared")));

/**
 * The [KeyValueSetting] for allowing an unset serial number on peripherals.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *ALLOW_UNSET_SERIAL_NUMBER __attribute__((swift_name("ALLOW_UNSET_SERIAL_NUMBER")));

/**
 * The [KeyValueIntSetting] for the background disconnect timeout.
 */
@property (readonly) DynamicsMultiplatformKeyValueIntSetting *BACKGROUND_DISCONNECT_TIMEOUT __attribute__((swift_name("BACKGROUND_DISCONNECT_TIMEOUT")));

/**
 * The [KeyValueSetting] for the debug mode.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUGGING_MODE __attribute__((swift_name("DEBUGGING_MODE")));

/**
 * The [KeyValueSetting] for the debug option for accepting all punches.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUG_ACCEPT_ALL_PUNCHES __attribute__((swift_name("DEBUG_ACCEPT_ALL_PUNCHES")));

/**
 * The [KeyValueSetting] for the advertising prefix.
 */
@property (readonly) DynamicsMultiplatformKeyValueStringSetting *DEBUG_ADVERTISING_PREFIX __attribute__((swift_name("DEBUG_ADVERTISING_PREFIX")));

/**
 * The [KeyValueSetting] for the firmware update base url.
 */
@property (readonly) DynamicsMultiplatformKeyValueStringSetting *DEBUG_FIRMWARE_UPDATE_BASE_URL __attribute__((swift_name("DEBUG_FIRMWARE_UPDATE_BASE_URL")));

/**
 * The [KeyValueSetting] for the battery mock.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUG_IS_BATTERY_MOCK_ENABLED __attribute__((swift_name("DEBUG_IS_BATTERY_MOCK_ENABLED")));

/**
 * The [KeyValueSetting] for the dummy impact data mode.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUG_IS_DUMMY_IMPACT_DATA_ENABLED __attribute__((swift_name("DEBUG_IS_DUMMY_IMPACT_DATA_ENABLED")));

/**
 * The [KeyValueSetting] for keeping all punch details.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUG_KEEP_ALL_PUNCH_DETAILS __attribute__((swift_name("DEBUG_KEEP_ALL_PUNCH_DETAILS")));

/**
 * The [KeyValueSetting] for a boolean flag
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *DEBUG_USE_DEBUG_FIRMWARE_UPDATE_IMAGE __attribute__((swift_name("DEBUG_USE_DEBUG_FIRMWARE_UPDATE_IMAGE")));

/**
 * The settings key for the installation id.
 */
@property (readonly) NSString *INSTALLATION_ID_KEY __attribute__((swift_name("INSTALLATION_ID_KEY")));

/**
 * The [KeyValueSetting] for the onboarding option.
 */
@property (readonly) DynamicsMultiplatformKeyValueSetting *SHOW_ONBOARDING __attribute__((swift_name("SHOW_ONBOARDING")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyValueIntSetting")))
@interface DynamicsMultiplatformKeyValueIntSetting : DynamicsMultiplatformBase
- (instancetype)initWithKey:(NSString *)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("init(key:defaultValue:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKeyValueIntSetting *)doCopyKey:(NSString *)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("doCopy(key:defaultValue:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t defaultValue __attribute__((swift_name("defaultValue")));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end


/**
 * A wrapper class that used to store the key and default value for each setting.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyValueSetting")))
@interface DynamicsMultiplatformKeyValueSetting : DynamicsMultiplatformBase
- (instancetype)initWithKey:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("init(key:defaultValue:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKeyValueSetting *)doCopyKey:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("doCopy(key:defaultValue:)")));

/**
 * A wrapper class that used to store the key and default value for each setting.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * A wrapper class that used to store the key and default value for each setting.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * A wrapper class that used to store the key and default value for each setting.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL defaultValue __attribute__((swift_name("defaultValue")));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end


/**
 * Same as [KeyValueSetting] but for type [String].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeyValueStringSetting")))
@interface DynamicsMultiplatformKeyValueStringSetting : DynamicsMultiplatformBase
- (instancetype)initWithKey:(NSString *)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("init(key:defaultValue:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKeyValueStringSetting *)doCopyKey:(NSString *)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("doCopy(key:defaultValue:)")));

/**
 * Same as [KeyValueSetting] but for type [String].
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Same as [KeyValueSetting] but for type [String].
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Same as [KeyValueSetting] but for type [String].
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *defaultValue __attribute__((swift_name("defaultValue")));
@property (readonly) NSString *key __attribute__((swift_name("key")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RecordedSensorStreamSequence")))
@interface DynamicsMultiplatformRecordedSensorStreamSequence : DynamicsMultiplatformBase
- (instancetype)initWithPeripheralId:(id)peripheralId sessionStartTime:(DynamicsMultiplatformKotlinInstant *)sessionStartTime offset:(int64_t)offset sequenceNumber:(int32_t)sequenceNumber sessionAbsolutePath:(NSString *)sessionAbsolutePath absolutePath:(NSString *)absolutePath __attribute__((swift_name("init(peripheralId:sessionStartTime:offset:sequenceNumber:sessionAbsolutePath:absolutePath:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformRecordedSensorStreamSequence *)doCopyPeripheralId:(id)peripheralId sessionStartTime:(DynamicsMultiplatformKotlinInstant *)sessionStartTime offset:(int64_t)offset sequenceNumber:(int32_t)sequenceNumber sessionAbsolutePath:(NSString *)sessionAbsolutePath absolutePath:(NSString *)absolutePath __attribute__((swift_name("doCopy(peripheralId:sessionStartTime:offset:sequenceNumber:sessionAbsolutePath:absolutePath:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * The absolute file path of the recorded sequence.
 */
@property (readonly) NSString *absolutePath __attribute__((swift_name("absolutePath")));

/**
 * The current time offset of the recorded sequence.
 */
@property (readonly) int64_t offset __attribute__((swift_name("offset")));

/**
 * The id of the peripheral.
 */
@property (readonly) id peripheralId __attribute__((swift_name("peripheralId")));

/**
 * The number of the sequence.
 */
@property (readonly) int32_t sequenceNumber __attribute__((swift_name("sequenceNumber")));

/**
 * The absolute file path to the recording session.
 */
@property (readonly) NSString *sessionAbsolutePath __attribute__((swift_name("sessionAbsolutePath")));

/**
 * The start time of the recording session.
 */
@property (readonly) DynamicsMultiplatformKotlinInstant *sessionStartTime __attribute__((swift_name("sessionStartTime")));
@end

__attribute__((swift_name("SensorDataStreamState")))
@interface DynamicsMultiplatformSensorDataStreamState : DynamicsMultiplatformBase
@property (readonly) int32_t sequenceNumber __attribute__((swift_name("sequenceNumber")));
@property (readonly) DynamicsMultiplatformKotlinInstant *startTime __attribute__((swift_name("startTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorDataStreamState.Init")))
@interface DynamicsMultiplatformSensorDataStreamStateInit : DynamicsMultiplatformSensorDataStreamState
- (instancetype)initWithSequenceNumber:(int32_t)sequenceNumber startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("init(sequenceNumber:startTime:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSensorDataStreamStateInit *)doCopySequenceNumber:(int32_t)sequenceNumber startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("doCopy(sequenceNumber:startTime:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t sequenceNumber __attribute__((swift_name("sequenceNumber")));
@property (readonly) DynamicsMultiplatformKotlinInstant *startTime __attribute__((swift_name("startTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorDataStreamState.Recording")))
@interface DynamicsMultiplatformSensorDataStreamStateRecording : DynamicsMultiplatformSensorDataStreamState
- (instancetype)initWithInit:(DynamicsMultiplatformSensorDataStreamStateInit *)init __attribute__((swift_name("init(init:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithStopped:(DynamicsMultiplatformSensorDataStreamStateStopped *)stopped __attribute__((swift_name("init(stopped:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithSequenceNumber:(int32_t)sequenceNumber sequenceTimeOffset:(int64_t)sequenceTimeOffset startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("init(sequenceNumber:sequenceTimeOffset:startTime:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSensorDataStreamStateRecording *)doCopySequenceNumber:(int32_t)sequenceNumber sequenceTimeOffset:(int64_t)sequenceTimeOffset startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("doCopy(sequenceNumber:sequenceTimeOffset:startTime:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t sequenceNumber __attribute__((swift_name("sequenceNumber")));
@property (readonly) int64_t sequenceTimeOffset __attribute__((swift_name("sequenceTimeOffset")));
@property (readonly) DynamicsMultiplatformKotlinInstant *startTime __attribute__((swift_name("startTime")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorDataStreamState.Stopped")))
@interface DynamicsMultiplatformSensorDataStreamStateStopped : DynamicsMultiplatformSensorDataStreamState
- (instancetype)initWithRecording:(DynamicsMultiplatformSensorDataStreamStateRecording *)recording __attribute__((swift_name("init(recording:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithSequenceNumber:(int32_t)sequenceNumber startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("init(sequenceNumber:startTime:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformSensorDataStreamStateStopped *)doCopySequenceNumber:(int32_t)sequenceNumber startTime:(DynamicsMultiplatformKotlinInstant *)startTime __attribute__((swift_name("doCopy(sequenceNumber:startTime:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t sequenceNumber __attribute__((swift_name("sequenceNumber")));
@property (readonly) DynamicsMultiplatformKotlinInstant *startTime __attribute__((swift_name("startTime")));
@end


/**
 * Represents a helper class which will record and write the continuous sensor data stream from
 * the firmware to the internal storage.
 *
 * 1. Initialize this class accordingly with the [stream] that belongs to [peripheralId].
 * 2. Subscribe to [sensorStream] which will initialize the correct state on the firmware to start
 * sending the data.
 * 3. Use [toggleRecording] to start recording the current data stream. Optionally, [splitCurrentRecording]
 * can be used to split the current session into multiple sequences. Using [toggleRecording] has
 * the same effect.
 * 4. Subscribe to [recordingState] to observe the current state, to [recordedSequences] which will
 * return all current sequences.
 *
 *
 * @param sessionFolderPrefix a prefix for the session folder that is created upon init of this class.
 * @param initialSessionStartTime the start time of the session.
 * @param peripheralId the id of the peripheral, which is just used for IO purposes.
 * @param stream the stream of the continuous data.
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SensorStreamRecordingHelper")))
@interface DynamicsMultiplatformSensorStreamRecordingHelper : DynamicsMultiplatformBase
- (instancetype)initWithSessionFolderPrefix:(NSString *)sessionFolderPrefix initialSessionStartTime:(DynamicsMultiplatformKotlinInstant *)initialSessionStartTime peripheralId:(id)peripheralId stream:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)stream __attribute__((swift_name("init(sessionFolderPrefix:initialSessionStartTime:peripheralId:stream:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))splitCurrentRecording __attribute__((swift_name("splitCurrentRecording()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))toggleRecording __attribute__((swift_name("toggleRecording()")));
@property (readonly) DynamicsMultiplatformKotlinInstant *initialSessionStartTime __attribute__((swift_name("initialSessionStartTime")));
@property (readonly) id peripheralId __attribute__((swift_name("peripheralId")));
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^recordedSequences)(DynamicsMultiplatformKotlinUnit *(^)(NSMutableArray<DynamicsMultiplatformRecordedSensorStreamSequence *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("recordedSequences")));
@property (readonly) NSMutableArray<DynamicsMultiplatformRecordedSensorStreamSequence *> *recordedSequencesValue __attribute__((swift_name("recordedSequencesValue")));
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^recordingState)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformSensorDataStreamState *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("recordingState")));
@property (readonly) DynamicsMultiplatformSensorDataStreamState *recordingStateValue __attribute__((swift_name("recordingStateValue")));
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^sensorStream)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformSensorDataPacket *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("sensorStream")));
@property (readonly) NSString *sessionFolderPrefix __attribute__((swift_name("sessionFolderPrefix")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsContext")))
@interface DynamicsMultiplatformDynamicsContext : DynamicsMultiplatformBase
- (instancetype)initWithName:(NSString *)name map:(NSDictionary<NSString *, NSString *> *)map __attribute__((swift_name("init(name:map:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDynamicsContext *)doCopyName:(NSString *)name map:(NSDictionary<NSString *, NSString *> *)map __attribute__((swift_name("doCopy(name:map:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * A map with key/values for that context.
 */
@property (readonly) NSDictionary<NSString *, NSString *> *map __attribute__((swift_name("map")));

/**
 * The name of the context.
 */
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * This observer provides contexts from the dynamics multiplatform SDK - this data can be passed
 * into logging frameworks on the consumer side, for example for sentry where each [DynamicsContext]
 * can be used as a context shown for sentry events.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsContextObserver")))
@interface DynamicsMultiplatformDynamicsContextObserver : DynamicsMultiplatformBase
- (instancetype)initWithDb:(DynamicsMultiplatformDynamics_dbDatabase *)db gloveManager:(DynamicsMultiplatformDynamics_bleGloveManager *)gloveManager dynamicsSettings:(DynamicsMultiplatformDynamicsSettings *)dynamicsSettings __attribute__((swift_name("init(db:gloveManager:dynamicsSettings:)"))) __attribute__((objc_designated_initializer));

/**
 * Provides all dynamics contexts.
 *
 * If the [DynamicsContext.map] is empty, then this is an indicator to remove the context
 * from the logging framework.
 */
@property (readonly) DynamicsMultiplatformKotlinUnit *(^(^contexts)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformDynamicsContext *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void) __attribute__((swift_name("contexts")));

/**
 * Provides all dynamics contexts.
 *
 * If the [DynamicsContext.map] is empty, then this is an indicator to remove the context
 * from the logging framework.
 */
@property (readonly) NSArray<DynamicsMultiplatformDynamicsContext *> *contextsValue __attribute__((swift_name("contextsValue")));
@end


/**
 * Represents a nearby device from the result of BLE advertisements.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NearbyPeripheral")))
@interface DynamicsMultiplatformNearbyPeripheral : DynamicsMultiplatformBase
- (instancetype)initWithAdvertisement:(DynamicsMultiplatformCoreAdvertisement *)advertisement __attribute__((swift_name("init(advertisement:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformNearbyPeripheral *)doCopyAdvertisement:(DynamicsMultiplatformCoreAdvertisement *)advertisement __attribute__((swift_name("doCopy(advertisement:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) NSString *addressNative __attribute__((swift_name("addressNative")));
@property (readonly) DynamicsMultiplatformCoreAdvertisement *advertisement __attribute__((swift_name("advertisement")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));
@property (readonly) int32_t rssi __attribute__((swift_name("rssi")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralPair")))
@interface DynamicsMultiplatformPeripheralPair : DynamicsMultiplatformBase
- (instancetype)initWithBleAddress:(id)bleAddress name:(NSString *)name __attribute__((swift_name("init(bleAddress:name:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPeripheralPair *)doCopyBleAddress:(id)bleAddress name:(NSString *)name __attribute__((swift_name("doCopy(bleAddress:name:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id bleAddress __attribute__((swift_name("bleAddress")));
@property (readonly) NSString *bleAddressNative __attribute__((swift_name("bleAddressNative")));
@property (readonly) NSString *name __attribute__((swift_name("name")));
@end


/**
 * Represents states of a BLE peripheral along with platform states.
 *
 * - [address] the BLE address of the peripheral.
 * - [permissionState] the permission state of the platform.
 * - [bluetoothState] the bluetooth state of the platform.
 * - [state] the connection states of [com.juul.kable.Peripheral.state].
 * - [bondState] the bond states of [com.juul.kable.Peripheral.bondState].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralState")))
@interface DynamicsMultiplatformPeripheralState : DynamicsMultiplatformBase
- (instancetype)initWithAddress:(id)address permissionState:(DynamicsMultiplatformCorePermissionState *)permissionState bluetoothState:(DynamicsMultiplatformCoreBluetoothState *)bluetoothState state:(DynamicsMultiplatformKableState *)state bondState:(DynamicsMultiplatformCoreBondState *)bondState __attribute__((swift_name("init(address:permissionState:bluetoothState:state:bondState:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformPeripheralStateCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformPeripheralState *)doCopyAddress:(id)address permissionState:(DynamicsMultiplatformCorePermissionState *)permissionState bluetoothState:(DynamicsMultiplatformCoreBluetoothState *)bluetoothState state:(DynamicsMultiplatformKableState *)state bondState:(DynamicsMultiplatformCoreBondState *)bondState __attribute__((swift_name("doCopy(address:permissionState:bluetoothState:state:bondState:)")));

/**
 * Represents states of a BLE peripheral along with platform states.
 *
 * - [address] the BLE address of the peripheral.
 * - [permissionState] the permission state of the platform.
 * - [bluetoothState] the bluetooth state of the platform.
 * - [state] the connection states of [com.juul.kable.Peripheral.state].
 * - [bondState] the bond states of [com.juul.kable.Peripheral.bondState].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents states of a BLE peripheral along with platform states.
 *
 * - [address] the BLE address of the peripheral.
 * - [permissionState] the permission state of the platform.
 * - [bluetoothState] the bluetooth state of the platform.
 * - [state] the connection states of [com.juul.kable.Peripheral.state].
 * - [bondState] the bond states of [com.juul.kable.Peripheral.bondState].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) DynamicsMultiplatformBleRequirementsState *bleRequirementsState __attribute__((swift_name("bleRequirementsState")));
@property (readonly) DynamicsMultiplatformCoreBluetoothState *bluetoothState __attribute__((swift_name("bluetoothState")));
@property (readonly) DynamicsMultiplatformCoreBondState *bondState __attribute__((swift_name("bondState")));
@property (readonly) BOOL hasConnectionPermissions __attribute__((swift_name("hasConnectionPermissions")));
@property (readonly) BOOL isBluetoothEnabled __attribute__((swift_name("isBluetoothEnabled")));
@property (readonly) DynamicsMultiplatformBoolean * _Nullable isBonded __attribute__((swift_name("isBonded")));
@property (readonly) BOOL isConnected __attribute__((swift_name("isConnected")));
@property (readonly) DynamicsMultiplatformCorePermissionState *permissionState __attribute__((swift_name("permissionState")));
@property (readonly) DynamicsMultiplatformKableState *state __attribute__((swift_name("state")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PeripheralState.Companion")))
@interface DynamicsMultiplatformPeripheralStateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformPeripheralStateCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformPeripheralState *)doNewInstanceAddress:(id)address isBonded:(DynamicsMultiplatformBoolean * _Nullable)isBonded permissionState:(DynamicsMultiplatformCorePermissionState *)permissionState bluetoothState:(DynamicsMultiplatformCoreBluetoothState *)bluetoothState __attribute__((swift_name("doNewInstance(address:isBonded:permissionState:bluetoothState:)")));
@end


/**
 * Defines reasons for [ScannerState.Inactive.reason].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerInactiveReason")))
@interface DynamicsMultiplatformScannerInactiveReason : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformScannerInactiveReason *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Defines reasons for [ScannerState.Inactive.reason].
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformScannerInactiveReason *noSubscribers __attribute__((swift_name("noSubscribers")));
@property (class, readonly) DynamicsMultiplatformScannerInactiveReason *appInBackground __attribute__((swift_name("appInBackground")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformScannerInactiveReason *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformScannerInactiveReason *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Represents states of the scanner.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("ScannerState")))
@interface DynamicsMultiplatformScannerState : DynamicsMultiplatformBase
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Scanner is actively scanning for nearby devices.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerState.Active")))
@interface DynamicsMultiplatformScannerStateActive : DynamicsMultiplatformScannerState
+ (instancetype)alloc __attribute__((unavailable));

/**
 * Scanner is actively scanning for nearby devices.
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)active __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformScannerStateActive *shared __attribute__((swift_name("shared")));
@end


/**
 * Scanner cannot run due to an error, e.g. missing pre-conditions.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerState.Error")))
@interface DynamicsMultiplatformScannerStateError : DynamicsMultiplatformScannerState
- (instancetype)initWithScannerError:(DynamicsMultiplatformScannerError *)scannerError __attribute__((swift_name("init(scannerError:)"))) __attribute__((objc_designated_initializer));
@property (readonly) DynamicsMultiplatformScannerError *scannerError __attribute__((swift_name("scannerError")));
@end


/**
 * Scanner is inactive due to zero subscriptions.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerState.Inactive")))
@interface DynamicsMultiplatformScannerStateInactive : DynamicsMultiplatformScannerState
- (instancetype)initWithReason:(DynamicsMultiplatformScannerInactiveReason *)reason __attribute__((swift_name("init(reason:)"))) __attribute__((objc_designated_initializer));
@property (readonly) DynamicsMultiplatformScannerInactiveReason *reason __attribute__((swift_name("reason")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DeviceInfo")))
@interface DynamicsMultiplatformDeviceInfo : DynamicsMultiplatformBase
- (instancetype)initWithModelNumber:(NSString *)modelNumber serialNumber:(NSString *)serialNumber firmwareRevision:(NSString *)firmwareRevision hardwareRevision:(NSString *)hardwareRevision manufacturerName:(NSString *)manufacturerName __attribute__((swift_name("init(modelNumber:serialNumber:firmwareRevision:hardwareRevision:manufacturerName:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformDeviceInfo *)doCopyModelNumber:(NSString *)modelNumber serialNumber:(NSString *)serialNumber firmwareRevision:(NSString *)firmwareRevision hardwareRevision:(NSString *)hardwareRevision manufacturerName:(NSString *)manufacturerName __attribute__((swift_name("doCopy(modelNumber:serialNumber:firmwareRevision:hardwareRevision:manufacturerName:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *firmwareRevision __attribute__((swift_name("firmwareRevision")));
@property (readonly) NSString *hardwareRevision __attribute__((swift_name("hardwareRevision")));
@property (readonly) NSString *manufacturerName __attribute__((swift_name("manufacturerName")));
@property (readonly) NSString *modelNumber __attribute__((swift_name("modelNumber")));
@property (readonly) NSString *serialNumber __attribute__((swift_name("serialNumber")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BatteryChargeLevel")))
@interface DynamicsMultiplatformBatteryChargeLevel : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformBatteryChargeLevel *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformBatteryChargeLevel *unknown __attribute__((swift_name("unknown")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeLevel *good __attribute__((swift_name("good")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeLevel *low __attribute__((swift_name("low")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeLevel *critical __attribute__((swift_name("critical")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformBatteryChargeLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformBatteryChargeLevel *> *entries __attribute__((swift_name("entries")));
@property (readonly) int8_t id __attribute__((swift_name("id")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BatteryChargeState")))
@interface DynamicsMultiplatformBatteryChargeState : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformBatteryChargeState *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformBatteryChargeState *unknown __attribute__((swift_name("unknown")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeState *charging __attribute__((swift_name("charging")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeState *dischargingActive __attribute__((swift_name("dischargingActive")));
@property (class, readonly) DynamicsMultiplatformBatteryChargeState *dischargingInactive __attribute__((swift_name("dischargingInactive")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformBatteryChargeState *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformBatteryChargeState *> *entries __attribute__((swift_name("entries")));
@property (readonly) int8_t id __attribute__((swift_name("id")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChargingFaultReason")))
@interface DynamicsMultiplatformChargingFaultReason : DynamicsMultiplatformBase
- (instancetype)initWithBattery:(BOOL)battery externalPowerSource:(BOOL)externalPowerSource other:(BOOL)other __attribute__((swift_name("init(battery:externalPowerSource:other:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformChargingFaultReason *)doCopyBattery:(BOOL)battery externalPowerSource:(BOOL)externalPowerSource other:(BOOL)other __attribute__((swift_name("doCopy(battery:externalPowerSource:other:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) BOOL battery __attribute__((swift_name("battery")));
@property (readonly) BOOL externalPowerSource __attribute__((swift_name("externalPowerSource")));
@property (readonly) BOOL other __attribute__((swift_name("other")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ChargingType")))
@interface DynamicsMultiplatformChargingType : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformChargingType *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformChargingType *unknownOrNotCharging __attribute__((swift_name("unknownOrNotCharging")));
@property (class, readonly) DynamicsMultiplatformChargingType *constantCurrent __attribute__((swift_name("constantCurrent")));
@property (class, readonly) DynamicsMultiplatformChargingType *constantVoltage __attribute__((swift_name("constantVoltage")));
@property (class, readonly) DynamicsMultiplatformChargingType *trickle __attribute__((swift_name("trickle")));
@property (class, readonly) DynamicsMultiplatformChargingType *float_ __attribute__((swift_name("float_")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformChargingType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformChargingType *> *entries __attribute__((swift_name("entries")));
@property (readonly) int8_t id __attribute__((swift_name("id")));
@end


/**
 * Represents the power state of the battery level status characteristics from the bluetooth SIG.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PowerState")))
@interface DynamicsMultiplatformPowerState : DynamicsMultiplatformBase
- (instancetype)initWithIsBatteryPresent:(BOOL)isBatteryPresent wiredExternalPowerSourceConnected:(DynamicsMultiplatformWiredExternalPowerSourceConnected *)wiredExternalPowerSourceConnected wirelessExternalPowerSourceConnected:(DynamicsMultiplatformWirelessExternalPowerSourceConnected *)wirelessExternalPowerSourceConnected batteryChargeState:(DynamicsMultiplatformBatteryChargeState *)batteryChargeState batteryChargeLevel:(DynamicsMultiplatformBatteryChargeLevel *)batteryChargeLevel chargingType:(DynamicsMultiplatformChargingType *)chargingType chargingFaultReason:(DynamicsMultiplatformChargingFaultReason *)chargingFaultReason __attribute__((swift_name("init(isBatteryPresent:wiredExternalPowerSourceConnected:wirelessExternalPowerSourceConnected:batteryChargeState:batteryChargeLevel:chargingType:chargingFaultReason:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformPowerState *)doCopyIsBatteryPresent:(BOOL)isBatteryPresent wiredExternalPowerSourceConnected:(DynamicsMultiplatformWiredExternalPowerSourceConnected *)wiredExternalPowerSourceConnected wirelessExternalPowerSourceConnected:(DynamicsMultiplatformWirelessExternalPowerSourceConnected *)wirelessExternalPowerSourceConnected batteryChargeState:(DynamicsMultiplatformBatteryChargeState *)batteryChargeState batteryChargeLevel:(DynamicsMultiplatformBatteryChargeLevel *)batteryChargeLevel chargingType:(DynamicsMultiplatformChargingType *)chargingType chargingFaultReason:(DynamicsMultiplatformChargingFaultReason *)chargingFaultReason __attribute__((swift_name("doCopy(isBatteryPresent:wiredExternalPowerSourceConnected:wirelessExternalPowerSourceConnected:batteryChargeState:batteryChargeLevel:chargingType:chargingFaultReason:)")));

/**
 * Represents the power state of the battery level status characteristics from the bluetooth SIG.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents the power state of the battery level status characteristics from the bluetooth SIG.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformBatteryChargeLevel *batteryChargeLevel __attribute__((swift_name("batteryChargeLevel")));
@property (readonly) DynamicsMultiplatformBatteryChargeState *batteryChargeState __attribute__((swift_name("batteryChargeState")));
@property (readonly) DynamicsMultiplatformChargingFaultReason *chargingFaultReason __attribute__((swift_name("chargingFaultReason")));
@property (readonly) DynamicsMultiplatformChargingType *chargingType __attribute__((swift_name("chargingType")));
@property (readonly) BOOL isBatteryPresent __attribute__((swift_name("isBatteryPresent")));
@property (readonly) DynamicsMultiplatformWiredExternalPowerSourceConnected *wiredExternalPowerSourceConnected __attribute__((swift_name("wiredExternalPowerSourceConnected")));
@property (readonly) DynamicsMultiplatformWirelessExternalPowerSourceConnected *wirelessExternalPowerSourceConnected __attribute__((swift_name("wirelessExternalPowerSourceConnected")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WiredExternalPowerSourceConnected")))
@interface DynamicsMultiplatformWiredExternalPowerSourceConnected : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformWiredExternalPowerSourceConnected *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformWiredExternalPowerSourceConnected *no __attribute__((swift_name("no")));
@property (class, readonly) DynamicsMultiplatformWiredExternalPowerSourceConnected *yes __attribute__((swift_name("yes")));
@property (class, readonly) DynamicsMultiplatformWiredExternalPowerSourceConnected *unknown __attribute__((swift_name("unknown")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformWiredExternalPowerSourceConnected *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformWiredExternalPowerSourceConnected *> *entries __attribute__((swift_name("entries")));
@property (readonly) int8_t id __attribute__((swift_name("id")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("WirelessExternalPowerSourceConnected")))
@interface DynamicsMultiplatformWirelessExternalPowerSourceConnected : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformWirelessExternalPowerSourceConnected *>
+ (instancetype)alloc __attribute__((unavailable));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformWirelessExternalPowerSourceConnected *no __attribute__((swift_name("no")));
@property (class, readonly) DynamicsMultiplatformWirelessExternalPowerSourceConnected *yes __attribute__((swift_name("yes")));
@property (class, readonly) DynamicsMultiplatformWirelessExternalPowerSourceConnected *unknown __attribute__((swift_name("unknown")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformWirelessExternalPowerSourceConnected *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformWirelessExternalPowerSourceConnected *> *entries __attribute__((swift_name("entries")));
@property (readonly) int8_t id __attribute__((swift_name("id")));
@end

__attribute__((swift_name("BleError")))
@interface DynamicsMultiplatformBleError : DynamicsMultiplatformBase
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable throwable __attribute__((swift_name("throwable")));
@end

__attribute__((swift_name("BleError.BondRemoval")))
@interface DynamicsMultiplatformBleErrorBondRemoval : DynamicsMultiplatformBleError
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.BondRemovalMissingPermissions")))
@interface DynamicsMultiplatformBleErrorBondRemovalMissingPermissions : DynamicsMultiplatformBleErrorBondRemoval
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @param peripherals a list of peripherals with an address and name that needs to be presented
 * to the user, so he/she needs to manually forget (iOS) or unpair (android) in the settings.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.BondRemovalRemoveBondByUserRequired")))
@interface DynamicsMultiplatformBleErrorBondRemovalRemoveBondByUserRequired : DynamicsMultiplatformBleErrorBondRemoval
- (instancetype)initWithPeripherals:(NSArray<DynamicsMultiplatformPeripheralPair *> *)peripherals throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(peripherals:throwable:)"))) __attribute__((objc_designated_initializer));
@property (readonly) NSArray<DynamicsMultiplatformPeripheralPair *> *peripherals __attribute__((swift_name("peripherals")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.GenericError")))
@interface DynamicsMultiplatformBleErrorGenericError : DynamicsMultiplatformBleError
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("BleError.Operation")))
@interface DynamicsMultiplatformBleErrorOperation : DynamicsMultiplatformBleError
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.OperationConnectFailed")))
@interface DynamicsMultiplatformBleErrorOperationConnectFailed : DynamicsMultiplatformBleErrorOperation
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.OperationDisconnectFailed")))
@interface DynamicsMultiplatformBleErrorOperationDisconnectFailed : DynamicsMultiplatformBleErrorOperation
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.OperationObserveFailed")))
@interface DynamicsMultiplatformBleErrorOperationObserveFailed : DynamicsMultiplatformBleErrorOperation
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.OperationReadFailed")))
@interface DynamicsMultiplatformBleErrorOperationReadFailed : DynamicsMultiplatformBleErrorOperation
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleError.OperationWriteFailed")))
@interface DynamicsMultiplatformBleErrorOperationWriteFailed : DynamicsMultiplatformBleErrorOperation
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleException")))
@interface DynamicsMultiplatformBleException : DynamicsMultiplatformKotlinException
- (instancetype)initWithError:(DynamicsMultiplatformBleError *)error __attribute__((swift_name("init(error:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@property (readonly) DynamicsMultiplatformBleError *error __attribute__((swift_name("error")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ByteArrayConverterException")))
@interface DynamicsMultiplatformByteArrayConverterException : DynamicsMultiplatformKotlinException
- (instancetype)initWithE:(DynamicsMultiplatformKotlinException *)e bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid __attribute__((swift_name("init(e:bleUuid:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (readonly) DynamicsMultiplatformBle_multiplex_uuidBleUuid *bleUuid __attribute__((swift_name("bleUuid")));
@property (readonly) NSString *message __attribute__((swift_name("message")));
@end


/**
 * An error class that may occur while using the ble scanner.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("ScannerError")))
@interface DynamicsMultiplatformScannerError : DynamicsMultiplatformBase
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformKotlinThrowable * _Nullable cause __attribute__((swift_name("cause")));
@end


/**
 * A generic error that may occur from the scanning APIs.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerError.GenericError")))
@interface DynamicsMultiplatformScannerErrorGenericError : DynamicsMultiplatformScannerError
- (instancetype)initWithThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable __attribute__((swift_name("init(throwable:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * A missing scanning requirements error that will indicate which requirements are missing in order to start or
 * continue scanning.
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ScannerError.MissingScanningRequirements")))
@interface DynamicsMultiplatformScannerErrorMissingScanningRequirements : DynamicsMultiplatformScannerError
- (instancetype)initWithBleRequirementsState:(DynamicsMultiplatformBleRequirementsState *)bleRequirementsState __attribute__((swift_name("init(bleRequirementsState:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
@property (readonly) DynamicsMultiplatformBleRequirementsState *bleRequirementsState __attribute__((swift_name("bleRequirementsState")));
@end


/**
 * The engine for ble-multiplex logging that can be customized to save logs to various targets.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("BleMultiplexLogEngine")))
@protocol DynamicsMultiplatformBleMultiplexLogEngine
@required
- (BOOL)isEnabledPriority:(DynamicsMultiplatformLogLevel *)priority tag:(NSString * _Nullable)tag __attribute__((swift_name("isEnabled(priority:tag:)")));
- (void)logPriority:(DynamicsMultiplatformLogLevel *)priority throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(DynamicsMultiplatformBleMultiplexLogMessage *(^)(void))message __attribute__((swift_name("log(priority:throwable:tag:message:)")));
@end

__attribute__((swift_name("BleMultiplexLogMessage")))
@interface DynamicsMultiplatformBleMultiplexLogMessage : DynamicsMultiplatformBase
- (NSString *)formatMessageDataFormatter:(NSString *(^)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *, DynamicsMultiplatformKotlinByteArray * _Nullable))dataFormatter addressFormatter:(NSString *(^)(NSString *))addressFormatter bleUuidFormatter:(NSString *(^)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *))bleUuidFormatter __attribute__((swift_name("formatMessage(dataFormatter:addressFormatter:bleUuidFormatter:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogMessage.IOOperationRequest")))
@interface DynamicsMultiplatformBleMultiplexLogMessageIOOperationRequest : DynamicsMultiplatformBleMultiplexLogMessage
- (instancetype)initWithAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid type:(DynamicsMultiplatformBleOperationType *)type data:(DynamicsMultiplatformKotlinByteArray * _Nullable)data message:(NSString *(^)(void))message __attribute__((swift_name("init(address:bleUuid:type:data:message:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleMultiplexLogMessageIOOperationRequest *)doCopyAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid type:(DynamicsMultiplatformBleOperationType *)type data:(DynamicsMultiplatformKotlinByteArray * _Nullable)data message:(NSString *(^)(void))message __attribute__((swift_name("doCopy(address:bleUuid:type:data:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) DynamicsMultiplatformBle_multiplex_uuidBleUuid *bleUuid __attribute__((swift_name("bleUuid")));
@property (readonly) DynamicsMultiplatformKotlinByteArray * _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString *(^message)(void) __attribute__((swift_name("message")));
@property (readonly) DynamicsMultiplatformBleOperationType *type __attribute__((swift_name("type")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogMessage.ObserveOperation")))
@interface DynamicsMultiplatformBleMultiplexLogMessageObserveOperation : DynamicsMultiplatformBleMultiplexLogMessage
- (instancetype)initWithAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid data:(DynamicsMultiplatformKotlinByteArray * _Nullable)data message:(NSString *(^)(void))message __attribute__((swift_name("init(address:bleUuid:data:message:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleMultiplexLogMessageObserveOperation *)doCopyAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid data:(DynamicsMultiplatformKotlinByteArray * _Nullable)data message:(NSString *(^)(void))message __attribute__((swift_name("doCopy(address:bleUuid:data:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) DynamicsMultiplatformBle_multiplex_uuidBleUuid *bleUuid __attribute__((swift_name("bleUuid")));
@property (readonly) DynamicsMultiplatformKotlinByteArray * _Nullable data __attribute__((swift_name("data")));
@property (readonly) NSString *(^message)(void) __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogMessage.PlainMessage")))
@interface DynamicsMultiplatformBleMultiplexLogMessagePlainMessage : DynamicsMultiplatformBleMultiplexLogMessage
- (instancetype)initWithMessage:(NSString *(^)(void))message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleMultiplexLogMessagePlainMessage *)doCopyMessage:(NSString *(^)(void))message __attribute__((swift_name("doCopy(message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *(^message)(void) __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogMessage.RssiRequest")))
@interface DynamicsMultiplatformBleMultiplexLogMessageRssiRequest : DynamicsMultiplatformBleMultiplexLogMessage
- (instancetype)initWithAddress:(id)address rssi:(DynamicsMultiplatformInt * _Nullable)rssi message:(NSString *(^)(void))message __attribute__((swift_name("init(address:rssi:message:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleMultiplexLogMessageRssiRequest *)doCopyAddress:(id)address rssi:(DynamicsMultiplatformInt * _Nullable)rssi message:(NSString *(^)(void))message __attribute__((swift_name("doCopy(address:rssi:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) NSString *(^message)(void) __attribute__((swift_name("message")));
@property (readonly) DynamicsMultiplatformInt * _Nullable rssi __attribute__((swift_name("rssi")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogMessage.WithAddress")))
@interface DynamicsMultiplatformBleMultiplexLogMessageWithAddress : DynamicsMultiplatformBleMultiplexLogMessage
- (instancetype)initWithAddress:(NSString *)address message:(NSString *(^)(void))message __attribute__((swift_name("init(address:message:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBleMultiplexLogMessageWithAddress *)doCopyAddress:(NSString *)address message:(NSString *(^)(void))message __attribute__((swift_name("doCopy(address:message:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *address __attribute__((swift_name("address")));
@property (readonly) NSString *(^message)(void) __attribute__((swift_name("message")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleOperationType")))
@interface DynamicsMultiplatformBleOperationType : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformBleOperationType *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformBleOperationType *read __attribute__((swift_name("read")));
@property (class, readonly) DynamicsMultiplatformBleOperationType *write __attribute__((swift_name("write")));
@property (class, readonly) DynamicsMultiplatformBleOperationType *writeWithResponse __attribute__((swift_name("writeWithResponse")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformBleOperationType *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformBleOperationType *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel")))
@interface DynamicsMultiplatformLogLevel : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformLogLevel *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformLogLevel *verbose __attribute__((swift_name("verbose")));
@property (class, readonly) DynamicsMultiplatformLogLevel *debug __attribute__((swift_name("debug")));
@property (class, readonly) DynamicsMultiplatformLogLevel *info __attribute__((swift_name("info")));
@property (class, readonly) DynamicsMultiplatformLogLevel *warning __attribute__((swift_name("warning")));
@property (class, readonly) DynamicsMultiplatformLogLevel *error __attribute__((swift_name("error")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformLogLevel *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformLogLevel *> *entries __attribute__((swift_name("entries")));
@property (readonly) int32_t level __attribute__((swift_name("level")));
@end


/**
 * An empty implementation of the kable [LogEngine] to disable logging.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("EmptyLogEngine")))
@interface DynamicsMultiplatformEmptyLogEngine : DynamicsMultiplatformBase <DynamicsMultiplatformBleMultiplexLogEngine>

/**
 * An empty implementation of the kable [LogEngine] to disable logging.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));

/**
 * An empty implementation of the kable [LogEngine] to disable logging.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (void)logPriority:(DynamicsMultiplatformLogLevel *)priority throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(DynamicsMultiplatformBleMultiplexLogMessage *(^)(void))message __attribute__((swift_name("log(priority:throwable:tag:message:)")));
@end

__attribute__((swift_name("CoreLogEngine")))
@protocol DynamicsMultiplatformCoreLogEngine
@required
- (void)assertThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("assert(throwable:tag:message:)")));
- (void)debugThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("debug(throwable:tag:message:)")));
- (void)errorThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("error(throwable:tag:message:)")));
- (void)infoThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("info(throwable:tag:message:)")));
- (void)verboseThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("verbose(throwable:tag:message:)")));
- (void)warnThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("warn(throwable:tag:message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableLogEngineToBleMultiplexLogEngine")))
@interface DynamicsMultiplatformKableLogEngineToBleMultiplexLogEngine : DynamicsMultiplatformBase <DynamicsMultiplatformCoreLogEngine>
- (instancetype)initWithBleMultiplexLogEngine:(id<DynamicsMultiplatformBleMultiplexLogEngine>)bleMultiplexLogEngine __attribute__((swift_name("init(bleMultiplexLogEngine:)"))) __attribute__((objc_designated_initializer));
- (void)assertThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("assert(throwable:tag:message:)")));
- (void)debugThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("debug(throwable:tag:message:)")));
- (void)errorThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("error(throwable:tag:message:)")));
- (void)infoThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("info(throwable:tag:message:)")));
- (void)verboseThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("verbose(throwable:tag:message:)")));
- (void)warnThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("warn(throwable:tag:message:)")));
@end


/**
 * A mapper class for translating a [BleMultiplexLogEngine] to [io.github.aakira.napier.Antilog].
 *
 * @param log Napier's [Antilog] impl.
 * @param _addressFormatter the formatter for the Ble address.
 * @param _bleUuidFormatter the formatter for [BleUuid].
 * @param _dataFormatter the formatter for the data from ble operations.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogEngineToNapierAntiLog")))
@interface DynamicsMultiplatformBleMultiplexLogEngineToNapierAntiLog : DynamicsMultiplatformBase <DynamicsMultiplatformBleMultiplexLogEngine>
- (instancetype)initWithLog:(DynamicsMultiplatformAntilog *)log _addressFormatter:(NSString *(^)(NSString *))_addressFormatter _bleUuidFormatter:(NSString *(^)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *))_bleUuidFormatter _dataFormatter:(NSString *(^)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *, DynamicsMultiplatformKotlinByteArray * _Nullable, NSString *(^)(DynamicsMultiplatformKotlinByteArray *)))_dataFormatter _bleUuidFilter:(DynamicsMultiplatformBoolean *(^)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *))_bleUuidFilter logRssi:(BOOL)logRssi __attribute__((swift_name("init(log:_addressFormatter:_bleUuidFormatter:_dataFormatter:_bleUuidFilter:logRssi:)"))) __attribute__((objc_designated_initializer));
- (void)logPriority:(DynamicsMultiplatformLogLevel *)priority throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(DynamicsMultiplatformBleMultiplexLogMessage *(^)(void))message __attribute__((swift_name("log(priority:throwable:tag:message:)")));
@end


/**
 * A mapper class for translating a [LogEngine] to [io.github.aakira.napier.Antilog].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KableLogEngineToNapierAntiLog")))
@interface DynamicsMultiplatformKableLogEngineToNapierAntiLog : DynamicsMultiplatformBase <DynamicsMultiplatformCoreLogEngine>
- (instancetype)initWithLog:(DynamicsMultiplatformAntilog *)log __attribute__((swift_name("init(log:)"))) __attribute__((objc_designated_initializer));
- (void)assertThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("assert(throwable:tag:message:)")));
- (void)debugThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("debug(throwable:tag:message:)")));
- (void)errorThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("error(throwable:tag:message:)")));
- (void)infoThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("info(throwable:tag:message:)")));
- (void)verboseThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("verbose(throwable:tag:message:)")));
- (void)warnThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString *)tag message:(NSString *)message __attribute__((swift_name("warn(throwable:tag:message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleRequirements")))
@interface DynamicsMultiplatformBleRequirements : DynamicsMultiplatformBase
- (instancetype)initWithIsBluetoothPermissionRequired:(BOOL)isBluetoothPermissionRequired isBluetoothRequired:(BOOL)isBluetoothRequired __attribute__((swift_name("init(isBluetoothPermissionRequired:isBluetoothRequired:)"))) __attribute__((objc_designated_initializer));
@property (readonly) BOOL isBluetoothPermissionRequired __attribute__((swift_name("isBluetoothPermissionRequired")));
@property (readonly) BOOL isBluetoothRequired __attribute__((swift_name("isBluetoothRequired")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleRequirementsState")))
@interface DynamicsMultiplatformBleRequirementsState : DynamicsMultiplatformBase
- (instancetype)initWithCbManagerAuthorization:(int64_t)cbManagerAuthorization isBluetoothEnabled:(BOOL)isBluetoothEnabled __attribute__((swift_name("init(cbManagerAuthorization:isBluetoothEnabled:)"))) __attribute__((objc_designated_initializer));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t cbManagerAuthorization __attribute__((swift_name("cbManagerAuthorization")));
@property (readonly) BOOL isBluetoothEnabled __attribute__((swift_name("isBluetoothEnabled")));
@property (readonly) BOOL isBluetoothPermissionAllowed __attribute__((swift_name("isBluetoothPermissionAllowed")));
@property (readonly) BOOL isBluetoothPermissionDenied __attribute__((swift_name("isBluetoothPermissionDenied")));
@property (readonly) BOOL isBluetoothPermissionNotDetermined __attribute__((swift_name("isBluetoothPermissionNotDetermined")));
@end

__attribute__((swift_name("Settings")))
@protocol DynamicsMultiplatformSettings
@required
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)getBooleanKey:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("getBoolean(key:defaultValue:)")));
- (DynamicsMultiplatformBoolean * _Nullable)getBooleanOrNullKey:(NSString *)key __attribute__((swift_name("getBooleanOrNull(key:)")));
- (double)getDoubleKey:(NSString *)key defaultValue:(double)defaultValue __attribute__((swift_name("getDouble(key:defaultValue:)")));
- (DynamicsMultiplatformDouble * _Nullable)getDoubleOrNullKey:(NSString *)key __attribute__((swift_name("getDoubleOrNull(key:)")));
- (float)getFloatKey:(NSString *)key defaultValue:(float)defaultValue __attribute__((swift_name("getFloat(key:defaultValue:)")));
- (DynamicsMultiplatformFloat * _Nullable)getFloatOrNullKey:(NSString *)key __attribute__((swift_name("getFloatOrNull(key:)")));
- (int32_t)getIntKey:(NSString *)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("getInt(key:defaultValue:)")));
- (DynamicsMultiplatformInt * _Nullable)getIntOrNullKey:(NSString *)key __attribute__((swift_name("getIntOrNull(key:)")));
- (int64_t)getLongKey:(NSString *)key defaultValue:(int64_t)defaultValue __attribute__((swift_name("getLong(key:defaultValue:)")));
- (DynamicsMultiplatformLong * _Nullable)getLongOrNullKey:(NSString *)key __attribute__((swift_name("getLongOrNull(key:)")));
- (NSString *)getStringKey:(NSString *)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("getString(key:defaultValue:)")));
- (NSString * _Nullable)getStringOrNullKey:(NSString *)key __attribute__((swift_name("getStringOrNull(key:)")));
- (BOOL)hasKeyKey:(NSString *)key __attribute__((swift_name("hasKey(key:)")));
- (void)putBooleanKey:(NSString *)key value:(BOOL)value __attribute__((swift_name("putBoolean(key:value:)")));
- (void)putDoubleKey:(NSString *)key value:(double)value __attribute__((swift_name("putDouble(key:value:)")));
- (void)putFloatKey:(NSString *)key value:(float)value __attribute__((swift_name("putFloat(key:value:)")));
- (void)putIntKey:(NSString *)key value:(int32_t)value __attribute__((swift_name("putInt(key:value:)")));
- (void)putLongKey:(NSString *)key value:(int64_t)value __attribute__((swift_name("putLong(key:value:)")));
- (void)putStringKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("putString(key:value:)")));
- (void)removeKey:(NSString *)key __attribute__((swift_name("remove(key:)")));
@property (readonly) NSSet<NSString *> *keys __attribute__((swift_name("keys")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeychainSettings")))
@interface DynamicsMultiplatformKeychainSettings : DynamicsMultiplatformBase <DynamicsMultiplatformSettings>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithDefaultProperties:(DynamicsMultiplatformKotlinArray<DynamicsMultiplatformKotlinPair<id, id> *> *)defaultProperties __attribute__((swift_name("init(defaultProperties:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithService:(NSString *)service __attribute__((swift_name("init(service:)"))) __attribute__((objc_designated_initializer));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)getBooleanKey:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("getBoolean(key:defaultValue:)")));
- (DynamicsMultiplatformBoolean * _Nullable)getBooleanOrNullKey:(NSString *)key __attribute__((swift_name("getBooleanOrNull(key:)")));
- (double)getDoubleKey:(NSString *)key defaultValue:(double)defaultValue __attribute__((swift_name("getDouble(key:defaultValue:)")));
- (DynamicsMultiplatformDouble * _Nullable)getDoubleOrNullKey:(NSString *)key __attribute__((swift_name("getDoubleOrNull(key:)")));
- (float)getFloatKey:(NSString *)key defaultValue:(float)defaultValue __attribute__((swift_name("getFloat(key:defaultValue:)")));
- (DynamicsMultiplatformFloat * _Nullable)getFloatOrNullKey:(NSString *)key __attribute__((swift_name("getFloatOrNull(key:)")));
- (int32_t)getIntKey:(NSString *)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("getInt(key:defaultValue:)")));
- (DynamicsMultiplatformInt * _Nullable)getIntOrNullKey:(NSString *)key __attribute__((swift_name("getIntOrNull(key:)")));
- (int64_t)getLongKey:(NSString *)key defaultValue:(int64_t)defaultValue __attribute__((swift_name("getLong(key:defaultValue:)")));
- (DynamicsMultiplatformLong * _Nullable)getLongOrNullKey:(NSString *)key __attribute__((swift_name("getLongOrNull(key:)")));
- (NSString *)getStringKey:(NSString *)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("getString(key:defaultValue:)")));
- (NSString * _Nullable)getStringOrNullKey:(NSString *)key __attribute__((swift_name("getStringOrNull(key:)")));
- (BOOL)hasKeyKey:(NSString *)key __attribute__((swift_name("hasKey(key:)")));
- (void)putBooleanKey:(NSString *)key value:(BOOL)value __attribute__((swift_name("putBoolean(key:value:)")));
- (void)putDoubleKey:(NSString *)key value:(double)value __attribute__((swift_name("putDouble(key:value:)")));
- (void)putFloatKey:(NSString *)key value:(float)value __attribute__((swift_name("putFloat(key:value:)")));
- (void)putIntKey:(NSString *)key value:(int32_t)value __attribute__((swift_name("putInt(key:value:)")));
- (void)putLongKey:(NSString *)key value:(int64_t)value __attribute__((swift_name("putLong(key:value:)")));
- (void)putStringKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("putString(key:value:)")));
- (void)removeKey:(NSString *)key __attribute__((swift_name("remove(key:)")));
@property (readonly) NSSet<NSString *> *keys __attribute__((swift_name("keys")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("SettingsFactory")))
@protocol DynamicsMultiplatformSettingsFactory
@required
- (id<DynamicsMultiplatformSettings>)createName:(NSString * _Nullable)name __attribute__((swift_name("create(name:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KeychainSettings.Factory")))
@interface DynamicsMultiplatformKeychainSettingsFactory : DynamicsMultiplatformBase <DynamicsMultiplatformSettingsFactory>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DynamicsMultiplatformKeychainSettings *)createName:(NSString * _Nullable)name __attribute__((swift_name("create(name:)")));
@end

__attribute__((swift_name("ObservableSettings")))
@protocol DynamicsMultiplatformObservableSettings <DynamicsMultiplatformSettings>
@required
- (id<DynamicsMultiplatformSettingsListener>)addBooleanListenerKey:(NSString *)key defaultValue:(BOOL)defaultValue callback:(void (^)(DynamicsMultiplatformBoolean *))callback __attribute__((swift_name("addBooleanListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addBooleanOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformBoolean * _Nullable))callback __attribute__((swift_name("addBooleanOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addDoubleListenerKey:(NSString *)key defaultValue:(double)defaultValue callback:(void (^)(DynamicsMultiplatformDouble *))callback __attribute__((swift_name("addDoubleListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addDoubleOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformDouble * _Nullable))callback __attribute__((swift_name("addDoubleOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addFloatListenerKey:(NSString *)key defaultValue:(float)defaultValue callback:(void (^)(DynamicsMultiplatformFloat *))callback __attribute__((swift_name("addFloatListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addFloatOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformFloat * _Nullable))callback __attribute__((swift_name("addFloatOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addIntListenerKey:(NSString *)key defaultValue:(int32_t)defaultValue callback:(void (^)(DynamicsMultiplatformInt *))callback __attribute__((swift_name("addIntListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addIntOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformInt * _Nullable))callback __attribute__((swift_name("addIntOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addLongListenerKey:(NSString *)key defaultValue:(int64_t)defaultValue callback:(void (^)(DynamicsMultiplatformLong *))callback __attribute__((swift_name("addLongListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addLongOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformLong * _Nullable))callback __attribute__((swift_name("addLongOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addStringListenerKey:(NSString *)key defaultValue:(NSString *)defaultValue callback:(void (^)(NSString *))callback __attribute__((swift_name("addStringListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addStringOrNullListenerKey:(NSString *)key callback:(void (^)(NSString * _Nullable))callback __attribute__((swift_name("addStringOrNullListener(key:callback:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NSUserDefaultsSettings")))
@interface DynamicsMultiplatformNSUserDefaultsSettings : DynamicsMultiplatformBase <DynamicsMultiplatformObservableSettings>
- (instancetype)initWithDelegate:(NSUserDefaults *)delegate __attribute__((swift_name("init(delegate:)"))) __attribute__((objc_designated_initializer));
- (id<DynamicsMultiplatformSettingsListener>)addBooleanListenerKey:(NSString *)key defaultValue:(BOOL)defaultValue callback:(void (^)(DynamicsMultiplatformBoolean *))callback __attribute__((swift_name("addBooleanListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addBooleanOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformBoolean * _Nullable))callback __attribute__((swift_name("addBooleanOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addDoubleListenerKey:(NSString *)key defaultValue:(double)defaultValue callback:(void (^)(DynamicsMultiplatformDouble *))callback __attribute__((swift_name("addDoubleListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addDoubleOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformDouble * _Nullable))callback __attribute__((swift_name("addDoubleOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addFloatListenerKey:(NSString *)key defaultValue:(float)defaultValue callback:(void (^)(DynamicsMultiplatformFloat *))callback __attribute__((swift_name("addFloatListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addFloatOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformFloat * _Nullable))callback __attribute__((swift_name("addFloatOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addIntListenerKey:(NSString *)key defaultValue:(int32_t)defaultValue callback:(void (^)(DynamicsMultiplatformInt *))callback __attribute__((swift_name("addIntListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addIntOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformInt * _Nullable))callback __attribute__((swift_name("addIntOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addLongListenerKey:(NSString *)key defaultValue:(int64_t)defaultValue callback:(void (^)(DynamicsMultiplatformLong *))callback __attribute__((swift_name("addLongListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addLongOrNullListenerKey:(NSString *)key callback:(void (^)(DynamicsMultiplatformLong * _Nullable))callback __attribute__((swift_name("addLongOrNullListener(key:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addStringListenerKey:(NSString *)key defaultValue:(NSString *)defaultValue callback:(void (^)(NSString *))callback __attribute__((swift_name("addStringListener(key:defaultValue:callback:)")));
- (id<DynamicsMultiplatformSettingsListener>)addStringOrNullListenerKey:(NSString *)key callback:(void (^)(NSString * _Nullable))callback __attribute__((swift_name("addStringOrNullListener(key:callback:)")));
- (void)clear __attribute__((swift_name("clear()")));
- (BOOL)getBooleanKey:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("getBoolean(key:defaultValue:)")));
- (DynamicsMultiplatformBoolean * _Nullable)getBooleanOrNullKey:(NSString *)key __attribute__((swift_name("getBooleanOrNull(key:)")));
- (double)getDoubleKey:(NSString *)key defaultValue:(double)defaultValue __attribute__((swift_name("getDouble(key:defaultValue:)")));
- (DynamicsMultiplatformDouble * _Nullable)getDoubleOrNullKey:(NSString *)key __attribute__((swift_name("getDoubleOrNull(key:)")));
- (float)getFloatKey:(NSString *)key defaultValue:(float)defaultValue __attribute__((swift_name("getFloat(key:defaultValue:)")));
- (DynamicsMultiplatformFloat * _Nullable)getFloatOrNullKey:(NSString *)key __attribute__((swift_name("getFloatOrNull(key:)")));
- (int32_t)getIntKey:(NSString *)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("getInt(key:defaultValue:)")));
- (DynamicsMultiplatformInt * _Nullable)getIntOrNullKey:(NSString *)key __attribute__((swift_name("getIntOrNull(key:)")));
- (int64_t)getLongKey:(NSString *)key defaultValue:(int64_t)defaultValue __attribute__((swift_name("getLong(key:defaultValue:)")));
- (DynamicsMultiplatformLong * _Nullable)getLongOrNullKey:(NSString *)key __attribute__((swift_name("getLongOrNull(key:)")));
- (NSString *)getStringKey:(NSString *)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("getString(key:defaultValue:)")));
- (NSString * _Nullable)getStringOrNullKey:(NSString *)key __attribute__((swift_name("getStringOrNull(key:)")));
- (BOOL)hasKeyKey:(NSString *)key __attribute__((swift_name("hasKey(key:)")));
- (void)putBooleanKey:(NSString *)key value:(BOOL)value __attribute__((swift_name("putBoolean(key:value:)")));
- (void)putDoubleKey:(NSString *)key value:(double)value __attribute__((swift_name("putDouble(key:value:)")));
- (void)putFloatKey:(NSString *)key value:(float)value __attribute__((swift_name("putFloat(key:value:)")));
- (void)putIntKey:(NSString *)key value:(int32_t)value __attribute__((swift_name("putInt(key:value:)")));
- (void)putLongKey:(NSString *)key value:(int64_t)value __attribute__((swift_name("putLong(key:value:)")));
- (void)putStringKey:(NSString *)key value:(NSString *)value __attribute__((swift_name("putString(key:value:)")));
- (void)removeKey:(NSString *)key __attribute__((swift_name("remove(key:)")));
@property (readonly) NSSet<NSString *> *keys __attribute__((swift_name("keys")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NSUserDefaultsSettings.Factory")))
@interface DynamicsMultiplatformNSUserDefaultsSettingsFactory : DynamicsMultiplatformBase <DynamicsMultiplatformSettingsFactory>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DynamicsMultiplatformNSUserDefaultsSettings *)createName:(NSString * _Nullable)name __attribute__((swift_name("create(name:)")));
@end

__attribute__((swift_name("SettingsListener")))
@protocol DynamicsMultiplatformSettingsListener
@required
- (void)deactivate __attribute__((swift_name("deactivate()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NSUserDefaultsSettings.Listener")))
@interface DynamicsMultiplatformNSUserDefaultsSettingsListener : DynamicsMultiplatformBase <DynamicsMultiplatformSettingsListener>
- (void)deactivate __attribute__((swift_name("deactivate()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("SettingsCompanion")))
@interface DynamicsMultiplatformSettingsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformSettingsCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("Antilog")))
@interface DynamicsMultiplatformAntilog : DynamicsMultiplatformBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (BOOL)isEnablePriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag __attribute__((swift_name("isEnable(priority:tag:)")));
- (void)logPriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable message:(NSString * _Nullable)message __attribute__((swift_name("log(priority:tag:throwable:message:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)performLogPriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable message:(NSString * _Nullable)message __attribute__((swift_name("performLog(priority:tag:throwable:message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DebugAntilog")))
@interface DynamicsMultiplatformDebugAntilog : DynamicsMultiplatformAntilog
- (instancetype)initWithDefaultTag:(NSString *)defaultTag __attribute__((swift_name("init(defaultTag:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithDefaultTag:(NSString *)defaultTag coroutinesSuffix:(BOOL)coroutinesSuffix __attribute__((swift_name("init(defaultTag:coroutinesSuffix:)"))) __attribute__((objc_designated_initializer));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (void)performLogPriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable message:(NSString * _Nullable)message __attribute__((swift_name("performLog(priority:tag:throwable:message:)")));
- (void)setDateFormatterStringFormatter:(NSString *)formatter __attribute__((swift_name("setDateFormatterString(formatter:)")));
- (void)setTagLevel:(DynamicsMultiplatformLogLevel_ *)level tag:(NSString *)tag __attribute__((swift_name("setTag(level:tag:)")));
@property BOOL crashAssert __attribute__((swift_name("crashAssert")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LogLevel_")))
@interface DynamicsMultiplatformLogLevel_ : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformLogLevel_ *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *verbose __attribute__((swift_name("verbose")));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *debug __attribute__((swift_name("debug")));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *info __attribute__((swift_name("info")));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *warning __attribute__((swift_name("warning")));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *error __attribute__((swift_name("error")));
@property (class, readonly) DynamicsMultiplatformLogLevel_ *assert __attribute__((swift_name("assert")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformLogLevel_ *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformLogLevel_ *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Napier")))
@interface DynamicsMultiplatformNapier : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)napier __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformNapier *shared __attribute__((swift_name("shared")));
- (void)baseAntilog:(DynamicsMultiplatformAntilog *)antilog __attribute__((swift_name("base(antilog:)")));
- (void)dMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("d(message:throwable:tag:)")));
- (void)dThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("d(throwable:tag:message:)")));
- (void)eMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("e(message:throwable:tag:)")));
- (void)eThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("e(throwable:tag:message:)")));
- (void)iMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("i(message:throwable:tag:)")));
- (void)iThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("i(throwable:tag:message:)")));
- (BOOL)isEnablePriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag __attribute__((swift_name("isEnable(priority:tag:)")));
- (void)logPriority:(DynamicsMultiplatformLogLevel_ *)priority tag:(NSString * _Nullable)tag throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable message:(NSString *)message __attribute__((swift_name("log(priority:tag:throwable:message:)")));
- (void)takeLogarithm __attribute__((swift_name("takeLogarithm()")));
- (void)takeLogarithmAntilog:(DynamicsMultiplatformAntilog *)antilog __attribute__((swift_name("takeLogarithm(antilog:)")));
- (void)vMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("v(message:throwable:tag:)")));
- (void)vThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("v(throwable:tag:message:)")));
- (void)wMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("w(message:throwable:tag:)")));
- (void)wThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("w(throwable:tag:message:)")));
- (void)wtfMessage:(NSString *)message throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag __attribute__((swift_name("wtf(message:throwable:tag:)")));
- (void)wtfThrowable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("wtf(throwable:tag:message:)")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/DateTimePeriodSerializer))
*/
__attribute__((swift_name("DateTimePeriod")))
@interface DynamicsMultiplatformDateTimePeriod : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimePeriodCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t days __attribute__((swift_name("days")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) int32_t months __attribute__((swift_name("months")));
@property (readonly) int32_t nanoseconds __attribute__((swift_name("nanoseconds")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@property (readonly) int32_t years __attribute__((swift_name("years")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/DatePeriodSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DatePeriod")))
@interface DynamicsMultiplatformDatePeriod : DynamicsMultiplatformDateTimePeriod
- (instancetype)initWithYears:(int32_t)years months:(int32_t)months days:(int32_t)days __attribute__((swift_name("init(years:months:days:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDatePeriodCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) int32_t days __attribute__((swift_name("days")));
@property (readonly) int32_t hours __attribute__((swift_name("hours")));
@property (readonly) int32_t minutes __attribute__((swift_name("minutes")));
@property (readonly) int32_t nanoseconds __attribute__((swift_name("nanoseconds")));
@property (readonly) int32_t seconds __attribute__((swift_name("seconds")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DatePeriod.Companion")))
@interface DynamicsMultiplatformDatePeriodCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDatePeriodCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDatePeriod *)parseText:(NSString *)text __attribute__((swift_name("parse(text:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeArithmeticException")))
@interface DynamicsMultiplatformDateTimeArithmeticException : DynamicsMultiplatformKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable *)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString *)message cause:(DynamicsMultiplatformKotlinThrowable *)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimePeriod.Companion")))
@interface DynamicsMultiplatformDateTimePeriodCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimePeriodCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimePeriod *)parseText:(NSString *)text __attribute__((swift_name("parse(text:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/DateTimeUnitSerializer))
*/
__attribute__((swift_name("DateTimeUnit")))
@interface DynamicsMultiplatformDateTimeUnit : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeUnitCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)formatToStringValue:(int32_t)value unit:(NSString *)unit __attribute__((swift_name("formatToString(value:unit:)")));

/**
 * @note This method has protected visibility in Kotlin source and is intended only for use by subclasses.
*/
- (NSString *)formatToStringValue:(int64_t)value unit_:(NSString *)unit __attribute__((swift_name("formatToString(value:unit_:)")));
- (DynamicsMultiplatformDateTimeUnit *)timesScalar:(int32_t)scalar __attribute__((swift_name("times(scalar:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.Companion")))
@interface DynamicsMultiplatformDateTimeUnitCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) DynamicsMultiplatformDateTimeUnitMonthBased *CENTURY __attribute__((swift_name("CENTURY")));
@property (readonly) DynamicsMultiplatformDateTimeUnitDayBased *DAY __attribute__((swift_name("DAY")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *HOUR __attribute__((swift_name("HOUR")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *MICROSECOND __attribute__((swift_name("MICROSECOND")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *MILLISECOND __attribute__((swift_name("MILLISECOND")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *MINUTE __attribute__((swift_name("MINUTE")));
@property (readonly) DynamicsMultiplatformDateTimeUnitMonthBased *MONTH __attribute__((swift_name("MONTH")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *NANOSECOND __attribute__((swift_name("NANOSECOND")));
@property (readonly) DynamicsMultiplatformDateTimeUnitMonthBased *QUARTER __attribute__((swift_name("QUARTER")));
@property (readonly) DynamicsMultiplatformDateTimeUnitTimeBased *SECOND __attribute__((swift_name("SECOND")));
@property (readonly) DynamicsMultiplatformDateTimeUnitDayBased *WEEK __attribute__((swift_name("WEEK")));
@property (readonly) DynamicsMultiplatformDateTimeUnitMonthBased *YEAR __attribute__((swift_name("YEAR")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/DateBasedDateTimeUnitSerializer))
*/
__attribute__((swift_name("DateTimeUnit.DateBased")))
@interface DynamicsMultiplatformDateTimeUnitDateBased : DynamicsMultiplatformDateTimeUnit
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeUnitDateBasedCompanion *companion __attribute__((swift_name("companion")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.DateBasedCompanion")))
@interface DynamicsMultiplatformDateTimeUnitDateBasedCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitDateBasedCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/DayBasedDateTimeUnitSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.DayBased")))
@interface DynamicsMultiplatformDateTimeUnitDayBased : DynamicsMultiplatformDateTimeUnitDateBased
- (instancetype)initWithDays:(int32_t)days __attribute__((swift_name("init(days:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeUnitDayBasedCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformDateTimeUnitDayBased *)timesScalar:(int32_t)scalar __attribute__((swift_name("times(scalar:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t days __attribute__((swift_name("days")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.DayBasedCompanion")))
@interface DynamicsMultiplatformDateTimeUnitDayBasedCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitDayBasedCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/MonthBasedDateTimeUnitSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.MonthBased")))
@interface DynamicsMultiplatformDateTimeUnitMonthBased : DynamicsMultiplatformDateTimeUnitDateBased
- (instancetype)initWithMonths:(int32_t)months __attribute__((swift_name("init(months:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeUnitMonthBasedCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformDateTimeUnitMonthBased *)timesScalar:(int32_t)scalar __attribute__((swift_name("times(scalar:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t months __attribute__((swift_name("months")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.MonthBasedCompanion")))
@interface DynamicsMultiplatformDateTimeUnitMonthBasedCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitMonthBasedCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/TimeBasedDateTimeUnitSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.TimeBased")))
@interface DynamicsMultiplatformDateTimeUnitTimeBased : DynamicsMultiplatformDateTimeUnit
- (instancetype)initWithNanoseconds:(int64_t)nanoseconds __attribute__((swift_name("init(nanoseconds:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeUnitTimeBasedCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformDateTimeUnitTimeBased *)timesScalar:(int32_t)scalar __attribute__((swift_name("times(scalar:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t duration __attribute__((swift_name("duration")));
@property (readonly) int64_t nanoseconds __attribute__((swift_name("nanoseconds")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnit.TimeBasedCompanion")))
@interface DynamicsMultiplatformDateTimeUnitTimeBasedCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitTimeBasedCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayOfWeek")))
@interface DynamicsMultiplatformDayOfWeek : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformDayOfWeek *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *monday __attribute__((swift_name("monday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *tuesday __attribute__((swift_name("tuesday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *wednesday __attribute__((swift_name("wednesday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *thursday __attribute__((swift_name("thursday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *friday __attribute__((swift_name("friday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *saturday __attribute__((swift_name("saturday")));
@property (class, readonly) DynamicsMultiplatformDayOfWeek *sunday __attribute__((swift_name("sunday")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformDayOfWeek *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformDayOfWeek *> *entries __attribute__((swift_name("entries")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/TimeZoneSerializer))
*/
__attribute__((swift_name("TimeZone")))
@interface DynamicsMultiplatformTimeZone : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformTimeZoneCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformKotlinInstant *)toInstant:(DynamicsMultiplatformLocalDateTime *)receiver youShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("toInstant(_:youShallNotPass:)")));
- (DynamicsMultiplatformLocalDateTime *)toLocalDateTime:(DynamicsMultiplatformKotlinInstant *)receiver __attribute__((swift_name("toLocalDateTime(_:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/FixedOffsetTimeZoneSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FixedOffsetTimeZone")))
@interface DynamicsMultiplatformFixedOffsetTimeZone : DynamicsMultiplatformTimeZone
- (instancetype)initWithOffset:(DynamicsMultiplatformUtcOffset *)offset __attribute__((swift_name("init(offset:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformFixedOffsetTimeZoneCompanion *companion __attribute__((swift_name("companion")));
@property (readonly) NSString *id __attribute__((swift_name("id")));
@property (readonly) DynamicsMultiplatformUtcOffset *offset __attribute__((swift_name("offset")));
@property (readonly) int32_t totalSeconds __attribute__((swift_name("totalSeconds"))) __attribute__((deprecated("Use offset.totalSeconds")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FixedOffsetTimeZone.Companion")))
@interface DynamicsMultiplatformFixedOffsetTimeZoneCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformFixedOffsetTimeZoneCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("IllegalTimeZoneException")))
@interface DynamicsMultiplatformIllegalTimeZoneException : DynamicsMultiplatformKotlinIllegalArgumentException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString *)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable *)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString *)message cause:(DynamicsMultiplatformKotlinThrowable *)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/LocalDateSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDate")))
@interface DynamicsMultiplatformLocalDate : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithYear:(int32_t)year month:(int32_t)month day:(int32_t)day __attribute__((swift_name("init(year:month:day:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month day_:(int32_t)day __attribute__((swift_name("init(year:month:day_:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformLocalDateCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformLocalDateRange *)rangeToThat:(DynamicsMultiplatformLocalDate *)that __attribute__((swift_name("rangeTo(that:)")));
- (DynamicsMultiplatformLocalDateRange *)rangeUntilThat:(DynamicsMultiplatformLocalDate *)that __attribute__((swift_name("rangeUntil(that:)")));
- (int64_t)toEpochDays __attribute__((swift_name("toEpochDays()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t day __attribute__((swift_name("day")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth"))) __attribute__((deprecated("Use the 'day' property instead")));
@property (readonly) DynamicsMultiplatformDayOfWeek *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) DynamicsMultiplatformMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t monthNumber __attribute__((swift_name("monthNumber"))) __attribute__((deprecated("Use the 'month' property instead")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDate.Companion")))
@interface DynamicsMultiplatformLocalDateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBlock:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithDate>))block __attribute__((swift_name("Format(block:)")));
- (DynamicsMultiplatformLocalDate *)fromEpochDaysEpochDays:(int32_t)epochDays __attribute__((swift_name("fromEpochDays(epochDays:)")));
- (DynamicsMultiplatformLocalDate *)fromEpochDaysEpochDays_:(int64_t)epochDays __attribute__((swift_name("fromEpochDays(epochDays_:)")));
- (DynamicsMultiplatformLocalDate *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDate.Formats")))
@interface DynamicsMultiplatformLocalDateFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO __attribute__((swift_name("ISO")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO_BASIC __attribute__((swift_name("ISO_BASIC")));
@end

__attribute__((swift_name("KotlinIterable")))
@protocol DynamicsMultiplatformKotlinIterable
@required
- (id<DynamicsMultiplatformKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
@end

__attribute__((swift_name("KotlinCollection")))
@protocol DynamicsMultiplatformKotlinCollection <DynamicsMultiplatformKotlinIterable>
@required
- (BOOL)containsElement:(id _Nullable)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsAllElements:(id)elements __attribute__((swift_name("containsAll(elements:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((swift_name("LocalDateProgression")))
@interface DynamicsMultiplatformLocalDateProgression : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinCollection>
@property (class, readonly, getter=companion) DynamicsMultiplatformLocalDateProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsElement:(DynamicsMultiplatformLocalDate *)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsAllElements:(id)elements __attribute__((swift_name("containsAll(elements:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (id<DynamicsMultiplatformKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformLocalDate *first __attribute__((swift_name("first")));
@property (readonly) DynamicsMultiplatformLocalDate *last __attribute__((swift_name("last")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateProgression.Companion")))
@interface DynamicsMultiplatformLocalDateProgressionCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateProgressionCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((swift_name("KotlinClosedRange")))
@protocol DynamicsMultiplatformKotlinClosedRange
@required
- (BOOL)containsValue:(id)value __attribute__((swift_name("contains(value:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) id start __attribute__((swift_name("start")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinOpenEndRange")))
@protocol DynamicsMultiplatformKotlinOpenEndRange
@required
- (BOOL)containsValue_:(id)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
@property (readonly) id endExclusive __attribute__((swift_name("endExclusive")));
@property (readonly) id start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateRange")))
@interface DynamicsMultiplatformLocalDateRange : DynamicsMultiplatformLocalDateProgression <DynamicsMultiplatformKotlinClosedRange, DynamicsMultiplatformKotlinOpenEndRange>
- (instancetype)initWithStart:(DynamicsMultiplatformLocalDate *)start endInclusive:(DynamicsMultiplatformLocalDate *)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformLocalDateRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsElement:(DynamicsMultiplatformLocalDate *)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsValue:(DynamicsMultiplatformLocalDate *)element __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(DynamicsMultiplatformLocalDate *)element __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformLocalDate *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("This throws an exception if the exclusive end if not inside the platform-specific boundaries for LocalDate. The 'endInclusive' property does not throw and should be preferred.")));
@property (readonly) DynamicsMultiplatformLocalDate *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) DynamicsMultiplatformLocalDate *start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateRange.Companion")))
@interface DynamicsMultiplatformLocalDateRangeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformLocalDateRange *EMPTY __attribute__((swift_name("EMPTY")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/LocalDateTimeSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTime")))
@interface DynamicsMultiplatformLocalDateTime : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithDate:(DynamicsMultiplatformLocalDate *)date time:(DynamicsMultiplatformLocalTime *)time __attribute__((swift_name("init(date:time:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithYear:(int32_t)year month:(int32_t)month day:(int32_t)day hour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond:(int32_t)nanosecond __attribute__((swift_name("init(year:month:day:hour:minute:second:nanosecond:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month day:(int32_t)day hour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond_:(int32_t)nanosecond __attribute__((swift_name("init(year:month:day:hour:minute:second:nanosecond_:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformLocalDateTimeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(DynamicsMultiplatformLocalDateTime *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformLocalDate *date __attribute__((swift_name("date")));
@property (readonly) int32_t day __attribute__((swift_name("day")));
@property (readonly) int32_t dayOfMonth __attribute__((swift_name("dayOfMonth"))) __attribute__((deprecated("Use the 'day' property instead")));
@property (readonly) DynamicsMultiplatformDayOfWeek *dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property (readonly) int32_t dayOfYear __attribute__((swift_name("dayOfYear")));
@property (readonly) int32_t hour __attribute__((swift_name("hour")));
@property (readonly) int32_t minute __attribute__((swift_name("minute")));
@property (readonly) DynamicsMultiplatformMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t monthNumber __attribute__((swift_name("monthNumber"))) __attribute__((deprecated("Use the 'month' property instead")));
@property (readonly) int32_t nanosecond __attribute__((swift_name("nanosecond")));
@property (readonly) int32_t second __attribute__((swift_name("second")));
@property (readonly) DynamicsMultiplatformLocalTime *time __attribute__((swift_name("time")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTime.Companion")))
@interface DynamicsMultiplatformLocalDateTimeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateTimeCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBuilder:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithDateTime>))builder __attribute__((swift_name("Format(builder:)")));
- (DynamicsMultiplatformLocalDateTime *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTime.Formats")))
@interface DynamicsMultiplatformLocalDateTimeFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateTimeFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO __attribute__((swift_name("ISO")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/LocalTimeSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTime")))
@interface DynamicsMultiplatformLocalTime : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithHour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond:(int32_t)nanosecond __attribute__((swift_name("init(hour:minute:second:nanosecond:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformLocalTimeCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(DynamicsMultiplatformLocalTime *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (int32_t)toMillisecondOfDay __attribute__((swift_name("toMillisecondOfDay()")));
- (int64_t)toNanosecondOfDay __attribute__((swift_name("toNanosecondOfDay()")));
- (int32_t)toSecondOfDay __attribute__((swift_name("toSecondOfDay()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t hour __attribute__((swift_name("hour")));
@property (readonly) int32_t minute __attribute__((swift_name("minute")));
@property (readonly) int32_t nanosecond __attribute__((swift_name("nanosecond")));
@property (readonly) int32_t second __attribute__((swift_name("second")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTime.Companion")))
@interface DynamicsMultiplatformLocalTimeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalTimeCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBuilder:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithTime>))builder __attribute__((swift_name("Format(builder:)")));
- (DynamicsMultiplatformLocalTime *)fromMillisecondOfDayMillisecondOfDay:(int32_t)millisecondOfDay __attribute__((swift_name("fromMillisecondOfDay(millisecondOfDay:)")));
- (DynamicsMultiplatformLocalTime *)fromNanosecondOfDayNanosecondOfDay:(int64_t)nanosecondOfDay __attribute__((swift_name("fromNanosecondOfDay(nanosecondOfDay:)")));
- (DynamicsMultiplatformLocalTime *)fromSecondOfDaySecondOfDay:(int32_t)secondOfDay __attribute__((swift_name("fromSecondOfDay(secondOfDay:)")));
- (DynamicsMultiplatformLocalTime *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTime.Formats")))
@interface DynamicsMultiplatformLocalTimeFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalTimeFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO __attribute__((swift_name("ISO")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Month")))
@interface DynamicsMultiplatformMonth : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformMonth *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformMonth *january __attribute__((swift_name("january")));
@property (class, readonly) DynamicsMultiplatformMonth *february __attribute__((swift_name("february")));
@property (class, readonly) DynamicsMultiplatformMonth *march __attribute__((swift_name("march")));
@property (class, readonly) DynamicsMultiplatformMonth *april __attribute__((swift_name("april")));
@property (class, readonly) DynamicsMultiplatformMonth *may __attribute__((swift_name("may")));
@property (class, readonly) DynamicsMultiplatformMonth *june __attribute__((swift_name("june")));
@property (class, readonly) DynamicsMultiplatformMonth *july __attribute__((swift_name("july")));
@property (class, readonly) DynamicsMultiplatformMonth *august __attribute__((swift_name("august")));
@property (class, readonly) DynamicsMultiplatformMonth *september __attribute__((swift_name("september")));
@property (class, readonly) DynamicsMultiplatformMonth *october __attribute__((swift_name("october")));
@property (class, readonly) DynamicsMultiplatformMonth *november __attribute__((swift_name("november")));
@property (class, readonly) DynamicsMultiplatformMonth *december __attribute__((swift_name("december")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformMonth *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformMonth *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OverloadMarker")))
@interface DynamicsMultiplatformOverloadMarker : DynamicsMultiplatformBase
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeZone.Companion")))
@interface DynamicsMultiplatformTimeZoneCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTimeZoneCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformTimeZone *)currentSystemDefault __attribute__((swift_name("currentSystemDefault()")));
- (DynamicsMultiplatformTimeZone *)ofZoneId:(NSString *)zoneId __attribute__((swift_name("of(zoneId:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) DynamicsMultiplatformFixedOffsetTimeZone *UTC __attribute__((swift_name("UTC")));
@property (readonly) NSSet<NSString *> *availableZoneIds __attribute__((swift_name("availableZoneIds")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/UtcOffsetSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffset")))
@interface DynamicsMultiplatformUtcOffset : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformUtcOffsetCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t totalSeconds __attribute__((swift_name("totalSeconds")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffset.Companion")))
@interface DynamicsMultiplatformUtcOffsetCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformUtcOffsetCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBlock:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithUtcOffset>))block __attribute__((swift_name("Format(block:)")));
- (DynamicsMultiplatformUtcOffset *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@property (readonly) DynamicsMultiplatformUtcOffset *ZERO __attribute__((swift_name("ZERO")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffset.Formats")))
@interface DynamicsMultiplatformUtcOffsetFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformUtcOffsetFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> FOUR_DIGITS __attribute__((swift_name("FOUR_DIGITS")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO __attribute__((swift_name("ISO")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO_BASIC __attribute__((swift_name("ISO_BASIC")));
@end


/**
 * @note annotations
 *   kotlinx.serialization.Serializable(with=NormalClass(value=kotlinx/datetime/serializers/YearMonthSerializer))
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonth")))
@interface DynamicsMultiplatformYearMonth : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithYear:(int32_t)year month:(int32_t)month __attribute__((swift_name("init(year:month:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithYear:(int32_t)year month_:(DynamicsMultiplatformMonth *)month __attribute__((swift_name("init(year:month_:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformYearMonthCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(DynamicsMultiplatformYearMonth *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformYearMonthRange *)rangeToThat:(DynamicsMultiplatformYearMonth *)that __attribute__((swift_name("rangeTo(that:)")));
- (DynamicsMultiplatformYearMonthRange *)rangeUntilThat:(DynamicsMultiplatformYearMonth *)that __attribute__((swift_name("rangeUntil(that:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformLocalDateRange *days __attribute__((swift_name("days")));
@property (readonly) DynamicsMultiplatformLocalDate *firstDay __attribute__((swift_name("firstDay")));
@property (readonly) DynamicsMultiplatformLocalDate *lastDay __attribute__((swift_name("lastDay")));
@property (readonly) DynamicsMultiplatformMonth *month __attribute__((swift_name("month")));
@property (readonly) int32_t numberOfDays __attribute__((swift_name("numberOfDays")));
@property (readonly) int32_t year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonth.Companion")))
@interface DynamicsMultiplatformYearMonthCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBlock:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithYearMonth>))block __attribute__((swift_name("Format(block:)")));
- (DynamicsMultiplatformYearMonth *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("serializer()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonth.Formats")))
@interface DynamicsMultiplatformYearMonthFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO __attribute__((swift_name("ISO")));
@end

__attribute__((swift_name("YearMonthProgression")))
@interface DynamicsMultiplatformYearMonthProgression : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinCollection>
@property (class, readonly, getter=companion) DynamicsMultiplatformYearMonthProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsElement:(DynamicsMultiplatformYearMonth *)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsAllElements:(id)elements __attribute__((swift_name("containsAll(elements:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (id<DynamicsMultiplatformKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformYearMonth *first __attribute__((swift_name("first")));
@property (readonly) DynamicsMultiplatformYearMonth *last __attribute__((swift_name("last")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonthProgression.Companion")))
@interface DynamicsMultiplatformYearMonthProgressionCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthProgressionCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonthRange")))
@interface DynamicsMultiplatformYearMonthRange : DynamicsMultiplatformYearMonthProgression <DynamicsMultiplatformKotlinClosedRange, DynamicsMultiplatformKotlinOpenEndRange>
- (instancetype)initWithStart:(DynamicsMultiplatformYearMonth *)start endInclusive:(DynamicsMultiplatformYearMonth *)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformYearMonthRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsElement:(DynamicsMultiplatformYearMonth *)element __attribute__((swift_name("contains(element:)")));
- (BOOL)containsValue:(DynamicsMultiplatformYearMonth *)element __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(DynamicsMultiplatformYearMonth *)element __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) DynamicsMultiplatformYearMonth *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("This throws an exception if the exclusive end if not inside the platform-specific boundaries for YearMonth. The 'endInclusive' property does not throw and should be preferred.")));
@property (readonly) DynamicsMultiplatformYearMonth *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) DynamicsMultiplatformYearMonth *start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonthRange.Companion")))
@interface DynamicsMultiplatformYearMonthRangeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformYearMonthRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AmPmMarker")))
@interface DynamicsMultiplatformAmPmMarker : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformAmPmMarker *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformAmPmMarker *am __attribute__((swift_name("am")));
@property (class, readonly) DynamicsMultiplatformAmPmMarker *pm __attribute__((swift_name("pm")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformAmPmMarker *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformAmPmMarker *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeComponents")))
@interface DynamicsMultiplatformDateTimeComponents : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformDateTimeComponentsCompanion *companion __attribute__((swift_name("companion")));
- (void)setDateLocalDate:(DynamicsMultiplatformLocalDate *)localDate __attribute__((swift_name("setDate(localDate:)")));
- (void)setDateTimeLocalDateTime:(DynamicsMultiplatformLocalDateTime *)localDateTime __attribute__((swift_name("setDateTime(localDateTime:)")));
- (void)setDateTimeOffsetInstant:(DynamicsMultiplatformKotlinInstant *)instant utcOffset:(DynamicsMultiplatformUtcOffset *)utcOffset __attribute__((swift_name("setDateTimeOffset(instant:utcOffset:)")));
- (void)setDateTimeOffsetLocalDateTime:(DynamicsMultiplatformLocalDateTime *)localDateTime utcOffset:(DynamicsMultiplatformUtcOffset *)utcOffset __attribute__((swift_name("setDateTimeOffset(localDateTime:utcOffset:)")));
- (void)setOffsetUtcOffset:(DynamicsMultiplatformUtcOffset *)utcOffset __attribute__((swift_name("setOffset(utcOffset:)")));
- (void)setTimeLocalTime:(DynamicsMultiplatformLocalTime *)localTime __attribute__((swift_name("setTime(localTime:)")));
- (void)setYearMonthYearMonth:(DynamicsMultiplatformYearMonth *)yearMonth __attribute__((swift_name("setYearMonth(yearMonth:)")));
- (DynamicsMultiplatformKotlinInstant *)toInstantUsingOffsetYouShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("toInstantUsingOffset(youShallNotPass:)")));
- (DynamicsMultiplatformLocalDate *)toLocalDate __attribute__((swift_name("toLocalDate()")));
- (DynamicsMultiplatformLocalDateTime *)toLocalDateTime __attribute__((swift_name("toLocalDateTime()")));
- (DynamicsMultiplatformLocalTime *)toLocalTime __attribute__((swift_name("toLocalTime()")));
- (DynamicsMultiplatformUtcOffset *)toUtcOffset __attribute__((swift_name("toUtcOffset()")));
- (DynamicsMultiplatformYearMonth *)toYearMonth __attribute__((swift_name("toYearMonth()")));
@property DynamicsMultiplatformAmPmMarker * _Nullable amPm __attribute__((swift_name("amPm")));
@property DynamicsMultiplatformInt * _Nullable day __attribute__((swift_name("day")));
@property DynamicsMultiplatformInt * _Nullable dayOfMonth __attribute__((swift_name("dayOfMonth"))) __attribute__((deprecated("Use 'day' instead")));
@property DynamicsMultiplatformDayOfWeek * _Nullable dayOfWeek __attribute__((swift_name("dayOfWeek")));
@property DynamicsMultiplatformInt * _Nullable dayOfYear __attribute__((swift_name("dayOfYear")));
@property DynamicsMultiplatformInt * _Nullable hour __attribute__((swift_name("hour")));
@property DynamicsMultiplatformInt * _Nullable hourOfAmPm __attribute__((swift_name("hourOfAmPm")));
@property DynamicsMultiplatformInt * _Nullable minute __attribute__((swift_name("minute")));
@property DynamicsMultiplatformMonth * _Nullable month __attribute__((swift_name("month")));
@property DynamicsMultiplatformInt * _Nullable monthNumber __attribute__((swift_name("monthNumber")));
@property DynamicsMultiplatformInt * _Nullable nanosecond __attribute__((swift_name("nanosecond")));
@property DynamicsMultiplatformInt * _Nullable offsetHours __attribute__((swift_name("offsetHours")));
@property DynamicsMultiplatformBoolean * _Nullable offsetIsNegative __attribute__((swift_name("offsetIsNegative")));
@property DynamicsMultiplatformInt * _Nullable offsetMinutesOfHour __attribute__((swift_name("offsetMinutesOfHour")));
@property DynamicsMultiplatformInt * _Nullable offsetSecondsOfMinute __attribute__((swift_name("offsetSecondsOfMinute")));
@property DynamicsMultiplatformInt * _Nullable second __attribute__((swift_name("second")));
@property NSString * _Nullable timeZoneId __attribute__((swift_name("timeZoneId")));
@property DynamicsMultiplatformInt * _Nullable year __attribute__((swift_name("year")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeComponents.Companion")))
@interface DynamicsMultiplatformDateTimeComponentsCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeComponentsCompanion *shared __attribute__((swift_name("shared")));
- (id<DynamicsMultiplatformDateTimeFormat>)FormatBlock:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilderWithDateTimeComponents>))block __attribute__((swift_name("Format(block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeComponents.Formats")))
@interface DynamicsMultiplatformDateTimeComponentsFormats : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)formats __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeComponentsFormats *shared __attribute__((swift_name("shared")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> ISO_DATE_TIME_OFFSET __attribute__((swift_name("ISO_DATE_TIME_OFFSET")));
@property (readonly) id<DynamicsMultiplatformDateTimeFormat> RFC_1123 __attribute__((swift_name("RFC_1123")));
@end

__attribute__((swift_name("DateTimeFormat")))
@protocol DynamicsMultiplatformDateTimeFormat
@required
- (NSString *)formatValue:(id _Nullable)value __attribute__((swift_name("format(value:)")));
- (id<DynamicsMultiplatformKotlinAppendable>)formatToAppendable:(id<DynamicsMultiplatformKotlinAppendable>)appendable value:(id _Nullable)value __attribute__((swift_name("formatTo(appendable:value:)")));
- (id _Nullable)parseInput:(id)input __attribute__((swift_name("parse(input:)")));
- (id _Nullable)parseOrNullInput:(id)input __attribute__((swift_name("parseOrNull(input:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeFormatCompanion")))
@interface DynamicsMultiplatformDateTimeFormatCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeFormatCompanion *shared __attribute__((swift_name("shared")));
- (NSString *)formatAsKotlinBuilderDslFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("formatAsKotlinBuilderDsl(format:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilder")))
@protocol DynamicsMultiplatformDateTimeFormatBuilder
@required
- (void)charsValue:(NSString *)value __attribute__((swift_name("chars(value:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithYearMonth")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithYearMonth <DynamicsMultiplatformDateTimeFormatBuilder>
@required
- (void)monthNameNames:(DynamicsMultiplatformMonthNames *)names __attribute__((swift_name("monthName(names:)")));
- (void)monthNumberPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("monthNumber(padding:)")));
- (void)yearPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("year(padding:)")));
- (void)yearMonthFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("yearMonth(format:)")));
- (void)yearTwoDigitsBaseYear:(int32_t)baseYear __attribute__((swift_name("yearTwoDigits(baseYear:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithDate")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithDate <DynamicsMultiplatformDateTimeFormatBuilderWithYearMonth>
@required
- (void)dateFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("date(format:)")));
- (void)dayPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("day(padding:)")));
- (void)dayOfMonthPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("dayOfMonth(padding:)"))) __attribute__((deprecated("Use 'day' instead")));
- (void)dayOfWeekNames:(DynamicsMultiplatformDayOfWeekNames *)names __attribute__((swift_name("dayOfWeek(names:)")));
- (void)dayOfYearPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("dayOfYear(padding:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithTime")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithTime <DynamicsMultiplatformDateTimeFormatBuilder>
@required
- (void)amPmHourPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("amPmHour(padding:)")));
- (void)amPmMarkerAm:(NSString *)am pm:(NSString *)pm __attribute__((swift_name("amPmMarker(am:pm:)")));
- (void)hourPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("hour(padding:)")));
- (void)minutePadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("minute(padding:)")));
- (void)secondPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("second(padding:)")));
- (void)secondFractionFixedLength:(int32_t)fixedLength __attribute__((swift_name("secondFraction(fixedLength:)")));
- (void)secondFractionMinLength:(int32_t)minLength maxLength:(int32_t)maxLength __attribute__((swift_name("secondFraction(minLength:maxLength:)")));
- (void)timeFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("time(format:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithDateTime")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithDateTime <DynamicsMultiplatformDateTimeFormatBuilderWithDate, DynamicsMultiplatformDateTimeFormatBuilderWithTime>
@required
- (void)dateTimeFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("dateTime(format:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithUtcOffset")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithUtcOffset <DynamicsMultiplatformDateTimeFormatBuilder>
@required
- (void)offsetFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("offset(format:)")));
- (void)offsetHoursPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("offsetHours(padding:)")));
- (void)offsetMinutesOfHourPadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("offsetMinutesOfHour(padding:)")));
- (void)offsetSecondsOfMinutePadding:(DynamicsMultiplatformPadding *)padding __attribute__((swift_name("offsetSecondsOfMinute(padding:)")));
@end

__attribute__((swift_name("DateTimeFormatBuilderWithDateTimeComponents")))
@protocol DynamicsMultiplatformDateTimeFormatBuilderWithDateTimeComponents <DynamicsMultiplatformDateTimeFormatBuilderWithDateTime, DynamicsMultiplatformDateTimeFormatBuilderWithUtcOffset>
@required
- (void)dateTimeComponentsFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("dateTimeComponents(format:)")));
- (void)timeZoneId __attribute__((swift_name("timeZoneId()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayOfWeekNames")))
@interface DynamicsMultiplatformDayOfWeekNames : DynamicsMultiplatformBase
- (instancetype)initWithNames:(NSArray<NSString *> *)names __attribute__((swift_name("init(names:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMonday:(NSString *)monday tuesday:(NSString *)tuesday wednesday:(NSString *)wednesday thursday:(NSString *)thursday friday:(NSString *)friday saturday:(NSString *)saturday sunday:(NSString *)sunday __attribute__((swift_name("init(monday:tuesday:wednesday:thursday:friday:saturday:sunday:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDayOfWeekNamesCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> *names __attribute__((swift_name("names")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayOfWeekNames.Companion")))
@interface DynamicsMultiplatformDayOfWeekNamesCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDayOfWeekNamesCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformDayOfWeekNames *ENGLISH_ABBREVIATED __attribute__((swift_name("ENGLISH_ABBREVIATED")));
@property (readonly) DynamicsMultiplatformDayOfWeekNames *ENGLISH_FULL __attribute__((swift_name("ENGLISH_FULL")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonthNames")))
@interface DynamicsMultiplatformMonthNames : DynamicsMultiplatformBase
- (instancetype)initWithNames:(NSArray<NSString *> *)names __attribute__((swift_name("init(names:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithJanuary:(NSString *)january february:(NSString *)february march:(NSString *)march april:(NSString *)april may:(NSString *)may june:(NSString *)june july:(NSString *)july august:(NSString *)august september:(NSString *)september october:(NSString *)october november:(NSString *)november december:(NSString *)december __attribute__((swift_name("init(january:february:march:april:may:june:july:august:september:october:november:december:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformMonthNamesCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSArray<NSString *> *names __attribute__((swift_name("names")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonthNames.Companion")))
@interface DynamicsMultiplatformMonthNamesCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformMonthNamesCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformMonthNames *ENGLISH_ABBREVIATED __attribute__((swift_name("ENGLISH_ABBREVIATED")));
@property (readonly) DynamicsMultiplatformMonthNames *ENGLISH_FULL __attribute__((swift_name("ENGLISH_FULL")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Padding")))
@interface DynamicsMultiplatformPadding : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformPadding *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformPadding *none __attribute__((swift_name("none")));
@property (class, readonly) DynamicsMultiplatformPadding *zero __attribute__((swift_name("zero")));
@property (class, readonly) DynamicsMultiplatformPadding *space __attribute__((swift_name("space")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformPadding *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformPadding *> *entries __attribute__((swift_name("entries")));
@end


/**
 * Serialization strategy defines the serial form of a type [T], including its structural description,
 * declared by the [descriptor] and the actual serialization process, defined by the implementation
 * of the [serialize] method.
 *
 * [serialize] method takes an instance of [T] and transforms it into its serial form (a sequence of primitives),
 * calling the corresponding [Encoder] methods.
 *
 * A serial form of the type is a transformation of the concrete instance into a sequence of primitive values
 * and vice versa. The serial form is not required to completely mimic the structure of the class, for example,
 * a specific implementation may represent multiple integer values as a single string, omit or add some
 * values that are present in the type, but not in the instance.
 *
 * For a more detailed explanation of the serialization process, please refer to [KSerializer] documentation.
 */
__attribute__((swift_name("Kotlinx_serialization_coreSerializationStrategy")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy
@required

/**
 * Serializes the [value] of type [T] using the format that is represented by the given [encoder].
 * [serialize] method is format-agnostic and operates with a high-level structured [Encoder] API.
 * Throws [SerializationException] if value cannot be serialized.
 *
 * Example of serialize method:
 * ```
 * class MyData(int: Int, stringList: List<String>, alwaysZero: Long)
 *
 * fun serialize(encoder: Encoder, value: MyData): Unit = encoder.encodeStructure(descriptor) {
 *     // encodeStructure encodes beginning and end of the structure
 *     // encode 'int' property as Int
 *     encodeIntElement(descriptor, index = 0, value.int)
 *     // encode 'stringList' property as List<String>
 *     encodeSerializableElement(descriptor, index = 1, serializer<List<String>>, value.stringList)
 *     // don't encode 'alwaysZero' property because we decided to do so
 * } // end of the structure
 * ```
 *
 * @throws SerializationException in case of any serialization-specific error
 * @throws IllegalArgumentException if the supplied input does not comply encoder's specification
 * @see KSerializer for additional information about general contracts and exception specifics
 */
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(id _Nullable)value __attribute__((swift_name("serialize(encoder:value:)")));

/**
 * Describes the structure of the serializable representation of [T], produced
 * by this serializer.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * Deserialization strategy defines the serial form of a type [T], including its structural description,
 * declared by the [descriptor] and the actual deserialization process, defined by the implementation
 * of the [deserialize] method.
 *
 * [deserialize] method takes an instance of [Decoder], and, knowing the serial form of the [T],
 * invokes primitive retrieval methods on the decoder and then transforms the received primitives
 * to an instance of [T].
 *
 * A serial form of the type is a transformation of the concrete instance into a sequence of primitive values
 * and vice versa. The serial form is not required to completely mimic the structure of the class, for example,
 * a specific implementation may represent multiple integer values as a single string, omit or add some
 * values that are present in the type, but not in the instance.
 *
 * For a more detailed explanation of the serialization process, please refer to [KSerializer] documentation.
 */
__attribute__((swift_name("Kotlinx_serialization_coreDeserializationStrategy")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy
@required

/**
 * Deserializes the value of type [T] using the format that is represented by the given [decoder].
 * [deserialize] method is format-agnostic and operates with a high-level structured [Decoder] API.
 * As long as most of the formats imply an arbitrary order of properties, deserializer should be able
 * to decode these properties in an arbitrary order and in a format-agnostic way.
 * For that purposes, [CompositeDecoder.decodeElementIndex]-based loop is used: decoder firstly
 * signals property at which index it is ready to decode and then expects caller to decode
 * property with the given index.
 *
 * Throws [SerializationException] if value cannot be deserialized.
 *
 * Example of deserialize method:
 * ```
 * class MyData(int: Int, stringList: List<String>, alwaysZero: Long)
 *
 * fun deserialize(decoder: Decoder): MyData = decoder.decodeStructure(descriptor) {
 *     // decodeStructure decodes beginning and end of the structure
 *     var int: Int? = null
 *     var list: List<String>? = null
 *     loop@ while (true) {
 *         when (val index = decodeElementIndex(descriptor)) {
 *             DECODE_DONE -> break@loop
 *             0 -> {
 *                 // Decode 'int' property as Int
 *                 int = decodeIntElement(descriptor, index = 0)
 *             }
 *             1 -> {
 *                 // Decode 'stringList' property as List<String>
 *                 list = decodeSerializableElement(descriptor, index = 1, serializer<List<String>>())
 *             }
 *             else -> throw SerializationException("Unexpected index $index")
 *         }
 *      }
 *     if (int == null || list == null) throwMissingFieldException()
 *     // Always use 0 as a value for alwaysZero property because we decided to do so.
 *     return MyData(int, list, alwaysZero = 0L)
 * }
 * ```
 *
 * @throws MissingFieldException if non-optional fields were not found during deserialization
 * @throws SerializationException in case of any deserialization-specific error
 * @throws IllegalArgumentException if the decoded input is not a valid instance of [T]
 * @see KSerializer for additional information about general contracts and exception specifics
 */
- (id _Nullable)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));

/**
 * Describes the structure of the serializable representation of [T], that current
 * deserializer is able to deserialize.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end


/**
 * KSerializer is responsible for the representation of a serial form of a type [T]
 * in terms of [encoders][Encoder] and [decoders][Decoder] and for constructing and deconstructing [T]
 * from/to a sequence of encoding primitives. For classes marked with [@Serializable][Serializable], can be
 * obtained from generated companion extension `.serializer()` or from [serializer<T>()][serializer] function.
 *
 * Serialization is decoupled from the encoding process to make it completely format-agnostic.
 * Serialization represents a type as its serial form and is abstracted from the actual
 * format (whether its JSON, ProtoBuf or a hashing) and unaware of the underlying storage
 * (whether it is a string builder, byte array or a network socket), while
 * encoding/decoding is abstracted from a particular type and its serial form and is responsible
 * for transforming primitives ("here in an int property 'foo'" call from a serializer) into a particular
 * format-specific representation ("for a given int, append a property name in quotation marks,
 * then append a colon, then append an actual value" for JSON) and how to retrieve a primitive
 * ("give me an int that is 'foo' property") from the underlying representation ("expect the next string to be 'foo',
 * parse it, then parse colon, then parse a string until the next comma as an int and return it).
 *
 * Serial form consists of a structural description, declared by the [descriptor] and
 * actual serialization and deserialization processes, defined by the corresponding
 * [serialize] and [deserialize] methods implementation.
 *
 * Structural description specifies how the [T] is represented in the serial form:
 * its [kind][SerialKind] (e.g. whether it is represented as a primitive, a list or a class),
 * its [elements][SerialDescriptor.elementNames] and their [positional names][SerialDescriptor.getElementName].
 *
 * Serialization process is defined as a sequence of calls to an [Encoder], and transforms a type [T]
 * into a stream of format-agnostic primitives that represent [T], such as "here is an int, here is a double
 * and here is another nested object". It can be demonstrated by the example:
 * ```
 * class MyData(int: Int, stringList: List<String>, alwaysZero: Long)
 *
 * // .. serialize method of a corresponding serializer
 * fun serialize(encoder: Encoder, value: MyData): Unit = encoder.encodeStructure(descriptor) {
 *     // encodeStructure encodes beginning and end of the structure
 *     // encode 'int' property as Int
 *     encodeIntElement(descriptor, index = 0, value.int)
 *     // encode 'stringList' property as List<String>
 *     encodeSerializableElement(descriptor, index = 1, serializer<List<String>>, value.stringList)
 *     // don't encode 'alwaysZero' property because we decided to do so
 * } // end of the structure
 * ```
 *
 * Deserialization process is symmetric and uses [Decoder].
 *
 * ### Exception types for `KSerializer` implementation
 *
 * Implementations of [serialize] and [deserialize] methods are allowed to throw
 * any subtype of [IllegalArgumentException] in order to indicate serialization
 * and deserialization errors.
 *
 * For serializer implementations, it is recommended to throw subclasses of [SerializationException] for
 * any serialization-specific errors related to invalid or unsupported format of the data
 * and [IllegalStateException] for errors during validation of the data.
 */
__attribute__((swift_name("Kotlinx_serialization_coreKSerializer")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreKSerializer <DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy, DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy>
@required
@end


/**
 * Base class for providing multiplatform polymorphic serialization.
 *
 * This class cannot be implemented by library users. To learn how to use it for your case,
 * please refer to [PolymorphicSerializer] for interfaces/abstract classes and [SealedClassSerializer] for sealed classes.
 *
 * By default, without special support from [Encoder], polymorphic types are serialized as list with
 * two elements: class [serial name][SerialDescriptor.serialName] (String) and the object itself.
 * Serial name equals to fully qualified class name by default and can be changed via @[SerialName] annotation.
 *
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreAbstractPolymorphicSerializer")))
@interface DynamicsMultiplatformKotlinx_serialization_coreAbstractPolymorphicSerializer<T> : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (T)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));

/**
 * Lookups an actual serializer for given [klassName] withing the current [base class][baseClass].
 * May use context from the [decoder].
 *
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable)findPolymorphicSerializerOrNullDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder>)decoder klassName:(NSString * _Nullable)klassName __attribute__((swift_name("findPolymorphicSerializerOrNull(decoder:klassName:)")));

/**
 * Lookups an actual serializer for given [value] within the current [base class][baseClass].
 * May use context from the [encoder].
 *
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy> _Nullable)findPolymorphicSerializerOrNullEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(T)value __attribute__((swift_name("findPolymorphicSerializerOrNull(encoder:value:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(T)value __attribute__((swift_name("serialize(encoder:value:)")));

/**
 * Base class for all classes that this polymorphic serializer can serialize or deserialize.
 */
@property (readonly) id<DynamicsMultiplatformKotlinKClass> baseClass __attribute__((swift_name("baseClass")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateBasedDateTimeUnitSerializer")))
@interface DynamicsMultiplatformDateBasedDateTimeUnitSerializer : DynamicsMultiplatformKotlinx_serialization_coreAbstractPolymorphicSerializer<DynamicsMultiplatformDateTimeUnitDateBased *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dateBasedDateTimeUnitSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateBasedDateTimeUnitSerializer *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable)findPolymorphicSerializerOrNullDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder>)decoder klassName:(NSString * _Nullable)klassName __attribute__((swift_name("findPolymorphicSerializerOrNull(decoder:klassName:)")));

/**
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy> _Nullable)findPolymorphicSerializerOrNullEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimeUnitDateBased *)value __attribute__((swift_name("findPolymorphicSerializerOrNull(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinKClass> baseClass __attribute__((swift_name("baseClass")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DatePeriodComponentSerializer")))
@interface DynamicsMultiplatformDatePeriodComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)datePeriodComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDatePeriodComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDatePeriod *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDatePeriod *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DatePeriodIso8601Serializer")))
@interface DynamicsMultiplatformDatePeriodIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)datePeriodIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDatePeriodIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDatePeriod *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDatePeriod *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimePeriodComponentSerializer")))
@interface DynamicsMultiplatformDateTimePeriodComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dateTimePeriodComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimePeriodComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimePeriod *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimePeriod *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimePeriodIso8601Serializer")))
@interface DynamicsMultiplatformDateTimePeriodIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dateTimePeriodIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimePeriodIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimePeriod *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimePeriod *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeUnitSerializer")))
@interface DynamicsMultiplatformDateTimeUnitSerializer : DynamicsMultiplatformKotlinx_serialization_coreAbstractPolymorphicSerializer<DynamicsMultiplatformDateTimeUnit *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dateTimeUnitSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDateTimeUnitSerializer *shared __attribute__((swift_name("shared")));

/**
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable)findPolymorphicSerializerOrNullDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder>)decoder klassName:(NSString * _Nullable)klassName __attribute__((swift_name("findPolymorphicSerializerOrNull(decoder:klassName:)")));

/**
 * @note annotations
 *   kotlinx.serialization.InternalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy> _Nullable)findPolymorphicSerializerOrNullEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimeUnit *)value __attribute__((swift_name("findPolymorphicSerializerOrNull(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinKClass> baseClass __attribute__((swift_name("baseClass")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayBasedDateTimeUnitSerializer")))
@interface DynamicsMultiplatformDayBasedDateTimeUnitSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dayBasedDateTimeUnitSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDayBasedDateTimeUnitSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimeUnitDayBased *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimeUnitDayBased *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayOfWeekSerializer")))
@interface DynamicsMultiplatformDayOfWeekSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)dayOfWeekSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDayOfWeekSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDayOfWeek *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDayOfWeek *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("FixedOffsetTimeZoneSerializer")))
@interface DynamicsMultiplatformFixedOffsetTimeZoneSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)fixedOffsetTimeZoneSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformFixedOffsetTimeZoneSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformFixedOffsetTimeZone *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformFixedOffsetTimeZone *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedInstantSerializer")))
@interface DynamicsMultiplatformFormattedInstantSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKotlinInstant *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformKotlinInstant *)value __attribute__((swift_name("serialize(encoder:value:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedLocalDateSerializer")))
@interface DynamicsMultiplatformFormattedLocalDateSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformLocalDate *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDate *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedLocalDateTimeSerializer")))
@interface DynamicsMultiplatformFormattedLocalDateTimeSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformLocalDateTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDateTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedLocalTimeSerializer")))
@interface DynamicsMultiplatformFormattedLocalTimeSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformLocalTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedUtcOffsetSerializer")))
@interface DynamicsMultiplatformFormattedUtcOffsetSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformUtcOffset *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformUtcOffset *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((swift_name("FormattedYearMonthSerializer")))
@interface DynamicsMultiplatformFormattedYearMonthSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
- (instancetype)initWithName:(NSString *)name format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("init(name:format:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformYearMonth *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformYearMonth *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateComponentSerializer")))
@interface DynamicsMultiplatformLocalDateComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localDateComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalDate *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDate *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateIso8601Serializer")))
@interface DynamicsMultiplatformLocalDateIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localDateIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalDate *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDate *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTimeComponentSerializer")))
@interface DynamicsMultiplatformLocalDateTimeComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localDateTimeComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateTimeComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalDateTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDateTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTimeIso8601Serializer")))
@interface DynamicsMultiplatformLocalDateTimeIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localDateTimeIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalDateTimeIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalDateTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalDateTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTimeComponentSerializer")))
@interface DynamicsMultiplatformLocalTimeComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localTimeComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalTimeComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTimeIso8601Serializer")))
@interface DynamicsMultiplatformLocalTimeIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)localTimeIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformLocalTimeIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformLocalTime *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformLocalTime *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonthBasedDateTimeUnitSerializer")))
@interface DynamicsMultiplatformMonthBasedDateTimeUnitSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)monthBasedDateTimeUnitSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformMonthBasedDateTimeUnitSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimeUnitMonthBased *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimeUnitMonthBased *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonthSerializer")))
@interface DynamicsMultiplatformMonthSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)monthSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformMonthSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformMonth *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformMonth *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeBasedDateTimeUnitSerializer")))
@interface DynamicsMultiplatformTimeBasedDateTimeUnitSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)timeBasedDateTimeUnitSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTimeBasedDateTimeUnitSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDateTimeUnitTimeBased *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformDateTimeUnitTimeBased *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TimeZoneSerializer")))
@interface DynamicsMultiplatformTimeZoneSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)timeZoneSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformTimeZoneSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformTimeZone *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformTimeZone *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffsetIso8601Serializer")))
@interface DynamicsMultiplatformUtcOffsetIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)utcOffsetIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformUtcOffsetIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformUtcOffset *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformUtcOffset *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffsetSerializer")))
@interface DynamicsMultiplatformUtcOffsetSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)utcOffsetSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformUtcOffsetSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformUtcOffset *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformUtcOffset *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonthComponentSerializer")))
@interface DynamicsMultiplatformYearMonthComponentSerializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)yearMonthComponentSerializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthComponentSerializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformYearMonth *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformYearMonth *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("YearMonthIso8601Serializer")))
@interface DynamicsMultiplatformYearMonthIso8601Serializer : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinx_serialization_coreKSerializer>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)yearMonthIso8601Serializer __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformYearMonthIso8601Serializer *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformYearMonth *)deserializeDecoder:(id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decoder __attribute__((swift_name("deserialize(decoder:)")));
- (void)serializeEncoder:(id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encoder value:(DynamicsMultiplatformYearMonth *)value __attribute__((swift_name("serialize(encoder:value:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor> descriptor __attribute__((swift_name("descriptor")));
@end

@interface DynamicsMultiplatformAccStreamData (Extensions)
@property (readonly) DynamicsMultiplatformVector3dDouble *acc __attribute__((swift_name("acc")));
@property (readonly) NSUUID *peripheralId __attribute__((swift_name("peripheralId")));
@end

@interface DynamicsMultiplatformGlove (Extensions)
@property (readonly) BOOL isBaroAttached __attribute__((swift_name("isBaroAttached")));
@property (readonly) BOOL isBatteryLow __attribute__((swift_name("isBatteryLow")));
@property (readonly) BOOL isBonded __attribute__((swift_name("isBonded")));
@property (readonly) BOOL isChargerAttached __attribute__((swift_name("isChargerAttached")));
@property (readonly) BOOL isCharging __attribute__((swift_name("isCharging")));
@property (readonly) BOOL isConnecting __attribute__((swift_name("isConnecting")));
@property (readonly) BOOL isNotBonded __attribute__((swift_name("isNotBonded")));
@property (readonly) BOOL isOfflineError __attribute__((swift_name("isOfflineError")));
@property (readonly) BOOL isOfflineOutOfRange __attribute__((swift_name("isOfflineOutOfRange")));
@property (readonly) BOOL isOnline __attribute__((swift_name("isOnline")));
@end

@interface DynamicsMultiplatformGlovePair (Extensions)

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@end

@interface DynamicsMultiplatformPeripheralDto (Extensions)
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@end

@interface DynamicsMultiplatformPeripheralDtoCompanion (Extensions)

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (DynamicsMultiplatformPeripheralDto *)doInitNativeId:(NSUUID *)id address:(NSString *)address modelNumber:(NSString *)modelNumber manufacturerName:(NSString *)manufacturerName serialNumber:(NSString *)serialNumber firmwareVersion:(NSString *)firmwareVersion hardwareVersion:(NSString *)hardwareVersion name:(NSString *)name side:(DynamicsMultiplatformSide *)side bondState:(DynamicsMultiplatformBondState *)bondState __attribute__((swift_name("doInitNative(id:address:modelNumber:manufacturerName:serialNumber:firmwareVersion:hardwareVersion:name:side:bondState:)")));
@end

@interface DynamicsMultiplatformSide (Extensions)

/**
 * Inverts [this].
 */
- (DynamicsMultiplatformSide *)invert __attribute__((swift_name("invert()")));
@end

@interface DynamicsMultiplatformAllAdvertisingConfigs (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *advertisingInterval __attribute__((swift_name("advertisingInterval")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *advertisingTimeout __attribute__((swift_name("advertisingTimeout")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *deepSleepAdvertisingInterval __attribute__((swift_name("deepSleepAdvertisingInterval")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *deepSleepAdvertisingTimeout __attribute__((swift_name("deepSleepAdvertisingTimeout")));
@end

@interface DynamicsMultiplatformAllAdvertisingConfigsCompanion (Extensions)
- (DynamicsMultiplatformAllAdvertisingConfigs *)doInitNativeDeepSleepAdvertisingInterval:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)deepSleepAdvertisingInterval deepSleepAdvertisingTimeout:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)deepSleepAdvertisingTimeout advertisingInterval:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)advertisingInterval advertisingTimeout:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)advertisingTimeout __attribute__((swift_name("doInitNative(deepSleepAdvertisingInterval:deepSleepAdvertisingTimeout:advertisingInterval:advertisingTimeout:)")));
@end

@interface DynamicsMultiplatformCapShape (Extensions)
@property (readonly) NSArray<DynamicsMultiplatformDouble *> *capHeight __attribute__((swift_name("capHeight")));
@end

@interface DynamicsMultiplatformCapShapeCompanion (Extensions)
- (DynamicsMultiplatformCapShape *)doInitNativeCapHeight:(NSArray<DynamicsMultiplatformDouble *> *)capHeight meta:(DynamicsMultiplatformCapShapeMeta *)meta __attribute__((swift_name("doInitNative(capHeight:meta:)")));
@end

@interface DynamicsMultiplatformBlePacket (Extensions)
- (DynamicsMultiplatformKotlinByteArray *)totalContent __attribute__((swift_name("totalContent()")));
@property (readonly) NSDate *instant __attribute__((swift_name("instant")));
@end

@interface DynamicsMultiplatformImpactDataTransmission (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *transmissionDuration __attribute__((swift_name("transmissionDuration")));
@end

@interface DynamicsMultiplatformRawDataPipePacket (Extensions)
@property (readonly) NSDate *instant __attribute__((swift_name("instant")));
@end

@interface DynamicsMultiplatformSensorDataPacket (Extensions)
@property (readonly) NSArray<DynamicsMultiplatformVector3dDouble *> *accData __attribute__((swift_name("accData")));
@property (readonly) NSArray<DynamicsMultiplatformVector3dDouble *> *gyroData __attribute__((swift_name("gyroData")));
@property (readonly) NSArray<DynamicsMultiplatformVector3dDouble *> *magnetoData __attribute__((swift_name("magnetoData")));
@end

@interface DynamicsMultiplatformThroughputTest (Extensions)
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@end

@interface DynamicsMultiplatformThroughputTestDto (Extensions)
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@property (readonly) NSDate *startDateTime __attribute__((swift_name("startDateTime")));
@property (readonly) NSUUID *peripheralId __attribute__((swift_name("peripheralId")));
@end

@interface DynamicsMultiplatformThroughputTestEventDto (Extensions)
@property (readonly) NSDate *instant __attribute__((swift_name("instant")));
@end

@interface DynamicsMultiplatformVector3d (Extensions)
- (DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *)convertConversionFactor:(double)conversionFactor __attribute__((swift_name("convert(conversionFactor:)")));
- (DynamicsMultiplatformVector3d<DynamicsMultiplatformDouble *> *)convertToDoubleConversionFactor:(double)conversionFactor __attribute__((swift_name("convertToDouble(conversionFactor:)")));
- (DynamicsMultiplatformVector3dBoolean *)toVector3dBoolean __attribute__((swift_name("toVector3dBoolean()")));
- (DynamicsMultiplatformVector3dMicroTesla *)toVector3dMicroTesla __attribute__((swift_name("toVector3dMicroTesla()")));
- (DynamicsMultiplatformVector3dQ15 *)toVector3dQ15Float __attribute__((swift_name("toVector3dQ15Float()")));
- (DynamicsMultiplatformVector3dDouble *)toVector3dVector3dDouble __attribute__((swift_name("toVector3dVector3dDouble()")));
@end

@interface DynamicsMultiplatformVector3dBoolean (Extensions)
- (DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *)toVector3d __attribute__((swift_name("toVector3d()")));
@end

@interface DynamicsMultiplatformVector3dMicroTesla (Extensions)
- (DynamicsMultiplatformVector3d<id> *)toVector3d __attribute__((swift_name("toVector3d()")));
@end

@interface DynamicsMultiplatformVector3dQ15 (Extensions)
- (DynamicsMultiplatformVector3d<id> *)toVector3d __attribute__((swift_name("toVector3d()")));
@end

@interface DynamicsMultiplatformAllImpactConfigs (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *backToMeasurementIdleTimeout __attribute__((swift_name("backToMeasurementIdleTimeout")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (readonly) DynamicsMultiplatformVector3dBoolean *capDetectionDirection __attribute__((swift_name("capDetectionDirection")));
@property (readonly) DynamicsMultiplatformVector3dMicroTesla *magnetoCalibrationOffsetValues __attribute__((swift_name("magnetoCalibrationOffsetValues")));
@property (readonly) DynamicsMultiplatformVector3dQ15 *magnetoCalibrationScaleValues __attribute__((swift_name("magnetoCalibrationScaleValues")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *maximumWaitingTimeForValidation __attribute__((swift_name("maximumWaitingTimeForValidation")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *wakeUpTriggerDebounceTime __attribute__((swift_name("wakeUpTriggerDebounceTime")));
@end

@interface DynamicsMultiplatformAllOperationalConfigs (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *deactivateOfflineMeasurementModeTimeout __attribute__((swift_name("deactivateOfflineMeasurementModeTimeout")));
@end

@interface DynamicsMultiplatformAllOperationalConfigsCompanion (Extensions)
- (DynamicsMultiplatformAllOperationalConfigs *)doInitNativeDeactivateOfflineMeasurementModeTimeout:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)deactivateOfflineMeasurementModeTimeout __attribute__((swift_name("doInitNative(deactivateOfflineMeasurementModeTimeout:)")));
@end

@interface DynamicsMultiplatformGloveTime (Extensions)
@property (readonly) NSDate *absoluteTimeReference __attribute__((swift_name("absoluteTimeReference")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *relativeTimeReference __attribute__((swift_name("relativeTimeReference")));
@property (readonly) NSDate *requestedAt __attribute__((swift_name("requestedAt")));
@property (readonly) NSDate *time __attribute__((swift_name("time")));
@end

@interface DynamicsMultiplatformOperationalState (Extensions)
- (BOOL)isDataPipeExpected __attribute__((swift_name("isDataPipeExpected()")));
- (BOOL)isDummyData __attribute__((swift_name("isDummyData()")));
- (BOOL)isIdle __attribute__((swift_name("isIdle()")));
- (BOOL)isMeasurement __attribute__((swift_name("isMeasurement()")));
- (BOOL)isProcessingImpacts __attribute__((swift_name("isProcessingImpacts()")));
- (BOOL)isThroughputTest __attribute__((swift_name("isThroughputTest()")));
@end

@interface DynamicsMultiplatformSelfTestOutput (Extensions)

/**
 * @return a string containing all property names for which an error is reported.
 *
 * This does not include [SelfTestOutput.isBatteryBeingCharged] and
 * [SelfTestOutput.isChargerAttached].
 */
- (NSString *)reportErrorsDelimiter:(NSString *)delimiter __attribute__((swift_name("reportErrors(delimiter:)")));
@end

@interface DynamicsMultiplatformAllDeepSleepWakeUpConfigsCompanion (Extensions)
- (DynamicsMultiplatformAllDeepSleepWakeUpConfigs *)doInitNativeDeepSleepWakeUpConfiguration:(DynamicsMultiplatformDeepSleepWakeUpConfiguration *)deepSleepWakeUpConfiguration deepSleepWakeUpAccConfig:(DynamicsMultiplatformDeepSleepWakeUpAccConfig *)deepSleepWakeUpAccConfig __attribute__((swift_name("doInitNative(deepSleepWakeUpConfiguration:deepSleepWakeUpAccConfig:)")));
@end

@interface DynamicsMultiplatformDeepSleepWakeUpAccConfig (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *wakeUpTriggerDebounceTime __attribute__((swift_name("wakeUpTriggerDebounceTime")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (readonly) double wakeUpTriggerIncrease __attribute__((swift_name("wakeUpTriggerIncrease")));
@end

@interface DynamicsMultiplatformDeepSleepWakeUpAccConfigCompanion (Extensions)
- (DynamicsMultiplatformDeepSleepWakeUpAccConfig *)doInitNativeWakeUpTriggerIncrease:(double)wakeUpTriggerIncrease wakeUpTriggerDebounceTime:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)wakeUpTriggerDebounceTime __attribute__((swift_name("doInitNative(wakeUpTriggerIncrease:wakeUpTriggerDebounceTime:)")));
@end

@interface DynamicsMultiplatformGlovePairCompatibility (Extensions)

/**
 * @return a [TrainingSessionSensorType] that is compatible to both gloves. If null is returned,
 * then there is no chance to determine a compatible sensor type.
 *
 * Note that the returned sensor type might not be necessarily desired by the user as this could
 * mean that the baro is attached to one glove but not to the other one. In that case, the sensor
 * type would be downgraded.
 */
- (DynamicsMultiplatformTrainingSessionSensorType * _Nullable)compatibleTrainingSessionSensorType __attribute__((swift_name("compatibleTrainingSessionSensorType()")));
@end

@interface DynamicsMultiplatformBodyProfile (Extensions)
@property (readonly) double heightInCm __attribute__((swift_name("heightInCm")));
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@property (readonly) double weightInKg __attribute__((swift_name("weightInKg")));
@end

@interface DynamicsMultiplatformBodyProfileCompanion (Extensions)
- (DynamicsMultiplatformBodyProfile *)doInitNativeId:(NSUUID *)id name:(NSString *)name weightInKg:(double)weightInKg heightInCm:(double)heightInCm gender:(DynamicsMultiplatformGender *)gender __attribute__((swift_name("doInitNative(id:name:weightInKg:heightInCm:gender:)")));
@end

@interface DynamicsMultiplatformPowerSamples (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *baroTimeOffset __attribute__((swift_name("baroTimeOffset")));
@end

@interface DynamicsMultiplatformPunch (Extensions)

/**
 * Compares two punches and returns the "best" one based on [category]. If those are equal, then
 * [this] is preferred.
 */
- (DynamicsMultiplatformPunch *)bestByThat:(DynamicsMultiplatformPunch *)that category:(DynamicsMultiplatformBestPunchCategory *)category __attribute__((swift_name("bestBy(that:category:)")));

/**
 * Converts [this] with empty samples as [PunchWithSamples].
 */
- (DynamicsMultiplatformPunchWithSamples *)withEmptySamples __attribute__((swift_name("withEmptySamples()")));
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@property (readonly) NSUUID *peripheralId __attribute__((swift_name("peripheralId")));
@property (readonly) NSDate *timestamp __attribute__((swift_name("timestamp")));
@end

@interface DynamicsMultiplatformPunchWithSamples (Extensions)
- (DynamicsMultiplatformPunchWithSamples *)bestByThat:(DynamicsMultiplatformPunchWithSamples *)that category:(DynamicsMultiplatformBestPunchCategory *)category __attribute__((swift_name("bestBy(that:category:)")));
@end

@interface DynamicsMultiplatformSpeed (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *contactDuration __attribute__((swift_name("contactDuration")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *punchDuration __attribute__((swift_name("punchDuration")));
@end

@interface DynamicsMultiplatformTimeSampleDouble (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *offset __attribute__((swift_name("offset")));
@end

@interface DynamicsMultiplatformTimeSampleInt (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *offset __attribute__((swift_name("offset")));
@end

@interface DynamicsMultiplatformActiveTrainingSessionInputSecondary (Extensions)
@property (readonly) NSDate *timestamp __attribute__((swift_name("timestamp")));
@end

@interface DynamicsMultiplatformActiveTrainingSessionInputSecondaryCompanion (Extensions)
- (DynamicsMultiplatformActiveTrainingSessionInputSecondary *)doInitNativeTrainingSessionId:(NSUUID * _Nullable)trainingSessionId timestamp:(NSDate *)timestamp actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("doInitNative(trainingSessionId:timestamp:actor:)")));
@end

@interface DynamicsMultiplatformBestPunch (Extensions)

/**
 * Returns the best punch based on the [side]. If [side] is null, then the best punch overall
 * is returned.
 */
- (DynamicsMultiplatformPunch * _Nullable)bestBySide:(DynamicsMultiplatformSide * _Nullable)side __attribute__((swift_name("bestBy(side:)")));
@property (readonly) NSArray<NSUUID *> *punchIds __attribute__((swift_name("punchIds")));
@end

@interface DynamicsMultiplatformFinishedTrainingSession (Extensions)
@property (readonly) NSDate *endDateTime __attribute__((swift_name("endDateTime")));
@property (readonly) NSUUID *glovePairId __attribute__((swift_name("glovePairId")));
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *pausedDuration __attribute__((swift_name("pausedDuration")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *resumedDuration __attribute__((swift_name("resumedDuration")));
@property (readonly) NSDate *startDateTime __attribute__((swift_name("startDateTime")));
@end

@interface DynamicsMultiplatformTrainingSession (Extensions)
@property (readonly) NSUUID *glovePairId_ __attribute__((swift_name("glovePairId_")));
@property (readonly) NSUUID *id_ __attribute__((swift_name("id_")));
@end

@interface DynamicsMultiplatformTrainingSessionAverageStats (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds * _Nullable avgPunchDuration __attribute__((swift_name("avgPunchDuration")));
@end

@interface DynamicsMultiplatformTrainingSessionEvent (Extensions)
@property (readonly) NSDate *timestamp __attribute__((swift_name("timestamp")));
@end

@interface DynamicsMultiplatformTrainingSessionExtendedState (Extensions)
- (DynamicsMultiplatformTrainingSessionSensorType * _Nullable)getSensorType __attribute__((swift_name("getSensorType()")));
- (BOOL)isActive __attribute__((swift_name("isActive()")));
- (BOOL)isFinished __attribute__((swift_name("isFinished()")));
- (BOOL)isInitializing __attribute__((swift_name("isInitializing()")));
- (BOOL)isPaused __attribute__((swift_name("isPaused()")));
- (BOOL)isResumed __attribute__((swift_name("isResumed()")));
- (DynamicsMultiplatformTrainingSessionState *)toState __attribute__((swift_name("toState()")));
@end

@interface DynamicsMultiplatformTrainingSessionExtendedStateFinished (Extensions)
@property (readonly) NSDate *endDateTime __attribute__((swift_name("endDateTime")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *pausedDuration __attribute__((swift_name("pausedDuration")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *resumedDuration __attribute__((swift_name("resumedDuration")));
@property (readonly) NSDate *startDateTime __attribute__((swift_name("startDateTime")));
@end

@interface DynamicsMultiplatformTrainingSessionExtendedStatePaused (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *accumulatedResumedDurationUntilLastPauseEvent __attribute__((swift_name("accumulatedResumedDurationUntilLastPauseEvent")));
@property (readonly) NSDate *pausedSince __attribute__((swift_name("pausedSince")));
@property (readonly) NSDate *startDateTime __attribute__((swift_name("startDateTime")));
@end

@interface DynamicsMultiplatformTrainingSessionExtendedStateResumed (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *accumulatedResumedDurationUntilLastPauseEvent __attribute__((swift_name("accumulatedResumedDurationUntilLastPauseEvent")));
@property (readonly) NSDate *resumedSince __attribute__((swift_name("resumedSince")));
@property (readonly) NSDate *startDateTime __attribute__((swift_name("startDateTime")));
@end

@interface DynamicsMultiplatformTrainingSessionInput (Extensions)
@property (readonly) NSDate *timestamp __attribute__((swift_name("timestamp")));
@end

@interface DynamicsMultiplatformTrainingSessionInputCompanion (Extensions)
- (DynamicsMultiplatformTrainingSessionInput *)doInitNativeTrainingSessionId:(NSUUID *)trainingSessionId timestamp:(NSDate *)timestamp state:(DynamicsMultiplatformTrainingSessionState *)state actor:(DynamicsMultiplatformTrainingSessionStateActor *)actor __attribute__((swift_name("doInitNative(trainingSessionId:timestamp:state:actor:)")));
@end

@interface DynamicsMultiplatformTrainingSessionState (Extensions)
- (BOOL)isActive __attribute__((swift_name("isActive()")));
- (BOOL)isFinished __attribute__((swift_name("isFinished()")));
- (BOOL)isInitializing __attribute__((swift_name("isInitializing()")));
- (BOOL)isPaused __attribute__((swift_name("isPaused()")));
- (BOOL)isReady __attribute__((swift_name("isReady()")));
- (BOOL)isResumed __attribute__((swift_name("isResumed()")));
@end

@interface DynamicsMultiplatformTrainingSessionStats (Extensions)
- (DynamicsMultiplatformFinishedTrainingSessionStats *)toFinishedStats __attribute__((swift_name("toFinishedStats()")));
@end

@interface DynamicsMultiplatformTrainingSessionTime (Extensions)
@property (readonly) NSDate *end __attribute__((swift_name("end")));
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *pausedDuration __attribute__((swift_name("pausedDuration")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *resumedDuration __attribute__((swift_name("resumedDuration")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (readonly) NSDate *resumedDuration_ __attribute__((swift_name("resumedDuration_")));
@end

@interface DynamicsMultiplatformTrainingSessionWithTime (Extensions)
@property (readonly) NSUUID *glovePairId __attribute__((swift_name("glovePairId")));
@property (readonly) NSUUID *id __attribute__((swift_name("id")));
@end

@interface DynamicsMultiplatformThroughputTestInputCompanion (Extensions)
- (DynamicsMultiplatformThroughputTestInput *)doInitNativeThroughputTestId:(NSUUID *)throughputTestId text:(NSString *)text __attribute__((swift_name("doInitNative(throughputTestId:text:)")));
@end

@interface DynamicsMultiplatformFirmwareImageSettings (Extensions)
@property (readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *estimatedSwapTime __attribute__((swift_name("estimatedSwapTime")));
@end

@interface DynamicsMultiplatformExportRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSString *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))exportPunchPunchId:(NSUUID *)punchId __attribute__((swift_name("exportPunch(punchId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSString *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))exportThroughputTestThroughputTestId:(NSUUID *)throughputTestId __attribute__((swift_name("exportThroughputTest(throughputTestId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSString *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))exportTrainingSessionThroughputTestId:(NSUUID *)throughputTestId __attribute__((swift_name("exportTrainingSession(throughputTestId:)")));
@end

@interface DynamicsMultiplatformFinishedTrainingSessionRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteTrainingSessionId:(NSUUID *)id __attribute__((swift_name("deleteTrainingSession(id:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformFinishedTrainingSessionWithStats *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getFinishedTrainingSessionByIdId:(NSUUID *)id __attribute__((swift_name("getFinishedTrainingSessionById(id:)")));
@end

@interface DynamicsMultiplatformFirmwareUpdateRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformFirmwareImage *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))downloadFirmwareImageMeta:(DynamicsMultiplatformFirmwareImageMeta *)meta peripheralId:(NSUUID *)peripheralId __attribute__((swift_name("downloadFirmwareImage(meta:peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformFirmwareImageMeta * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getLatestAvailableFirmwareImageMetaPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getLatestAvailableFirmwareImageMeta(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformFirmwareImageMeta * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))isUpdateAvailableForPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("isUpdateAvailableFor(peripheralId:)")));
@end

@interface DynamicsMultiplatformGloveConfigurationRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))calibrateSensorsPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("calibrateSensors(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))eraseFlashPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("eraseFlash(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))factoryResetPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("factoryReset(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformAllAdvertisingConfigs *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getAdvertisingConfigsForceRefresh:(BOOL)forceRefresh peripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getAdvertisingConfigs(forceRefresh:peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformAllDeepSleepWakeUpConfigs *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getDeepSleepWakeUpConfigsForceRefresh:(BOOL)forceRefresh peripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getDeepSleepWakeUpConfigs(forceRefresh:peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSString *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getDeviceNamePeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getDeviceName(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformGloveTime *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getGloveTimePeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getGloveTime(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformAllImpactConfigs *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getImpactConfigsForceRefresh:(BOOL)forceRefresh peripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getImpactConfigs(forceRefresh:peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformAllOperationalConfigs *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getOperationalConfigsPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getOperationalConfigs(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))putToDeepSleepPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("putToDeepSleep(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setAdvertisingConfigAdvertisingIntervalPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setAdvertisingConfigAdvertisingInterval(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setAdvertisingConfigAdvertisingTimeoutPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setAdvertisingConfigAdvertisingTimeout(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setAdvertisingConfigDeepSleepAdvertisingIntervalPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setAdvertisingConfigDeepSleepAdvertisingInterval(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setAdvertisingConfigDeepSleepAdvertisingTimeoutPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setAdvertisingConfigDeepSleepAdvertisingTimeout(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setBackToMeasurementIdleTimeoutPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setBackToMeasurementIdleTimeout(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformCapCombination *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setCapCombinationPeripheralId:(NSUUID *)peripheralId combination:(DynamicsMultiplatformCapCombination *)combination __attribute__((swift_name("setCapCombination(peripheralId:combination:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformVector3dBoolean *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setCapDetectionDirectionPeripheralId:(NSUUID *)peripheralId directions:(DynamicsMultiplatformVector3dBoolean *)directions __attribute__((swift_name("setCapDetectionDirection(peripheralId:directions:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformCapOptions *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setCapOptionsPeripheralId:(NSUUID *)peripheralId options:(DynamicsMultiplatformCapOptions *)options __attribute__((swift_name("setCapOptions(peripheralId:options:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformCapShape *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setCapShapePeripheralId:(NSUUID *)peripheralId shape:(DynamicsMultiplatformCapShape *)shape __attribute__((swift_name("setCapShape(peripheralId:shape:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDeepSleepWakeUpAccConfig *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setDeepSleepWakeUpConfigDeepSleepWakeUpAccelerationThresholdAndDebounceTimePeripheralId:(NSUUID *)peripheralId deepSleepWakeUpAccConfig:(DynamicsMultiplatformDeepSleepWakeUpAccConfig *)deepSleepWakeUpAccConfig __attribute__((swift_name("setDeepSleepWakeUpConfigDeepSleepWakeUpAccelerationThresholdAndDebounceTime(peripheralId:deepSleepWakeUpAccConfig:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDeepSleepWakeUpConfiguration *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setDeepSleepWakeUpConfigDeepSleepWakeUpConfigurationPeripheralId:(NSUUID *)peripheralId deepSleepWakeUpConfiguration:(DynamicsMultiplatformDeepSleepWakeUpConfiguration *)deepSleepWakeUpConfiguration __attribute__((swift_name("setDeepSleepWakeUpConfigDeepSleepWakeUpConfiguration(peripheralId:deepSleepWakeUpConfiguration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformInt *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigCountOfPostImpactSamplesPeripheralId:(NSUUID *)peripheralId count:(int32_t)count __attribute__((swift_name("setImpactConfigCountOfPostImpactSamples(peripheralId:count:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformInt *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigCountOfPreTriggerSamplesPeripheralId:(NSUUID *)peripheralId count:(int32_t)count __attribute__((swift_name("setImpactConfigCountOfPreTriggerSamples(peripheralId:count:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigMaximumWaitingTimeForValidationPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setImpactConfigMaximumWaitingTimeForValidation(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDouble *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigMinimumAbsoluteAccelerationForValidImpactPeripheralId:(NSUUID *)peripheralId gravity:(double)gravity __attribute__((swift_name("setImpactConfigMinimumAbsoluteAccelerationForValidImpact(peripheralId:gravity:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigWakeUpDebounceTimePeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setImpactConfigWakeUpDebounceTime(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDouble *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setImpactConfigWakeUpTriggerThresholdPeripheralId:(NSUUID *)peripheralId gravity:(double)gravity __attribute__((swift_name("setImpactConfigWakeUpTriggerThreshold(peripheralId:gravity:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformVector3dMicroTesla *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setMagnetoCalibrationOffsetValuesPeripheralId:(NSUUID *)peripheralId offset:(DynamicsMultiplatformVector3dMicroTesla *)offset __attribute__((swift_name("setMagnetoCalibrationOffsetValues(peripheralId:offset:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformVector3dQ15 *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setMagnetoCalibrationScaleValuesPeripheralId:(NSUUID *)peripheralId scale:(DynamicsMultiplatformVector3dQ15 *)scale __attribute__((swift_name("setMagnetoCalibrationScaleValues(peripheralId:scale:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformDynamics_utilsNanoSeconds *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))setOperationalConfigDeactivateOfflineMeasurementModeTimeoutPeripheralId:(NSUUID *)peripheralId duration:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)duration __attribute__((swift_name("setOperationalConfigDeactivateOfflineMeasurementModeTimeout(peripheralId:duration:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))softRebootPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("softReboot(peripheralId:)")));
@end

@interface DynamicsMultiplatformGloveRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteAllGloves __attribute__((swift_name("deleteAllGloves()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteGloveByIdId:(NSUUID *)id __attribute__((swift_name("deleteGloveById(id:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(id<DynamicsMultiplatformCommonDevice>, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getCommonDeviceForGloveId:(NSUUID *)id __attribute__((swift_name("getCommonDeviceForGlove(id:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformGlovePairDto *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getGlovePairByPeripheralIdPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("getGlovePairByPeripheralId(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformGlovePairDto *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getGlovePairGlovePairId:(NSUUID *)glovePairId __attribute__((swift_name("getGlovePair(glovePairId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformGlove * _Nullable, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeGloveByIdPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("observeGloveById(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))swapGloveSideForIdId:(NSUUID *)id __attribute__((swift_name("swapGloveSideForId(id:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))updateGlovePairNameByPeripheralIdId:(NSUUID *)id name:(NSString *)name __attribute__((swift_name("updateGlovePairNameByPeripheralId(id:name:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))updateGlovePairNameId:(NSUUID *)id name:(NSString *)name __attribute__((swift_name("updateGlovePairName(id:name:)")));
@end

@interface DynamicsMultiplatformPairingRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformPeripheralDto *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))insertPeripheralMockExplicitSide:(DynamicsMultiplatformSide * _Nullable)explicitSide glovePairName:(NSString *)glovePairName __attribute__((swift_name("insertPeripheralMock(explicitSide:glovePairName:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSUUID *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))pairNearbyGlove:(DynamicsMultiplatformNearbyGlove *)nearbyGlove glovePairName:(NSString *)glovePairName explicitSide:(DynamicsMultiplatformSide * _Nullable)explicitSide __attribute__((swift_name("pair(nearbyGlove:glovePairName:explicitSide:)")));
@end

@interface DynamicsMultiplatformProfileRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformBodyProfile *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getBodyProfile __attribute__((swift_name("getBodyProfile()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))insertOrUpdateBodyProfileBodyProfile:(DynamicsMultiplatformBodyProfile *)bodyProfile __attribute__((swift_name("insertOrUpdateBodyProfile(bodyProfile:)")));
@end

@interface DynamicsMultiplatformPunchRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformPunch *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getPunchPunchId:(NSUUID *)punchId __attribute__((swift_name("getPunch(punchId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformInt *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getPunchNumberPunchId:(NSUUID *)punchId __attribute__((swift_name("getPunchNumber(punchId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformPunchWithSamples *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))getPunchWithSamplesPunchId:(NSUUID *)punchId __attribute__((swift_name("getPunchWithSamples(punchId:)")));
@end

@interface DynamicsMultiplatformSensorDataRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(NSArray<DynamicsMultiplatformSensorDataPacket *> *, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeSensorDataPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("observeSensorData(peripheralId:)")));
@end

@interface DynamicsMultiplatformTestRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteAllThroughputTests __attribute__((swift_name("deleteAllThroughputTests()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteThroughputTestThroughputTestId:(NSUUID *)throughputTestId __attribute__((swift_name("deleteThroughputTest(throughputTestId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformGloveWithThroughputTest * _Nullable, DynamicsMultiplatformKotlinUnit *(^)(void), DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError * _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))observeThroughputTestPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("observeThroughputTest(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformSelfTestOutput *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))runSelfTestPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("runSelfTest(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformBoolean *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))toggleThroughputTestPeripheralId:(NSUUID *)peripheralId __attribute__((swift_name("toggleThroughputTest(peripheralId:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformThroughputTestDto *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))updateThroughputTestInput:(DynamicsMultiplatformThroughputTestInput *)input __attribute__((swift_name("updateThroughputTest(input:)")));
@end

@interface DynamicsMultiplatformTrainingSessionRepository (Extensions)
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))deleteActiveTrainingSession __attribute__((swift_name("deleteActiveTrainingSession()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(id _Nullable, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))finishActiveTrainingSession __attribute__((swift_name("finishActiveTrainingSession()")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformTrainingSessionWithTime *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))initializeActiveTrainingSessionFinishCurrentActiveSession:(BOOL)finishCurrentActiveSession settings:(DynamicsMultiplatformTrainingSessionSettings *)settings __attribute__((swift_name("initializeActiveTrainingSession(finishCurrentActiveSession:settings:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))readyActiveTrainingSessionType:(DynamicsMultiplatformTrainingSessionSensorType *)type __attribute__((swift_name("readyActiveTrainingSession(type:)")));
- (DynamicsMultiplatformKotlinUnit *(^(^)(DynamicsMultiplatformKotlinUnit *(^)(DynamicsMultiplatformKotlinUnit *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *), DynamicsMultiplatformKotlinUnit *(^)(NSError *, DynamicsMultiplatformKotlinUnit *)))(void))toggleActiveTrainingSessionState __attribute__((swift_name("toggleActiveTrainingSessionState()")));
@end

@interface DynamicsMultiplatformBleError (Extensions)
- (DynamicsMultiplatformBleException *)asBleException __attribute__((swift_name("asBleException()")));
- (DynamicsMultiplatformResourceResource<id> *)asFailure __attribute__((swift_name("asFailure()")));
@end

@interface DynamicsMultiplatformBleRequirementsState (Extensions)
- (BOOL)areRequirementsFulfilled __attribute__((swift_name("areRequirementsFulfilled()")));
@end

@interface DynamicsMultiplatformKotlinThrowable (Extensions)
- (NSString *)allMessages __attribute__((swift_name("allMessages()")));
- (DynamicsMultiplatformBodyProfileValidationException * _Nullable)bodyProfileValidationException __attribute__((swift_name("bodyProfileValidationException()")));

/**
 * @return true if either [this] or any child of [Throwable.cause] is of type
 * [CancellationException].
 */
- (BOOL)isRecursiveCancellationException __attribute__((swift_name("isRecursiveCancellationException()")));

/**
 * Exposes stacktrace in order to make use of it for the native targets.
 */
- (NSString *)stacktrace __attribute__((swift_name("stacktrace()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinInstant")))
@interface DynamicsMultiplatformKotlinInstant : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinInstantCompanion *companion __attribute__((swift_name("companion")));
- (int32_t)compareToOther:(DynamicsMultiplatformKotlinInstant *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformKotlinInstant *)minusDuration:(int64_t)duration __attribute__((swift_name("minus(duration:)")));
- (int64_t)minusOther:(DynamicsMultiplatformKotlinInstant *)other __attribute__((swift_name("minus(other:)")));
- (DynamicsMultiplatformKotlinInstant *)plusDuration:(int64_t)duration __attribute__((swift_name("plus(duration:)")));
- (int64_t)toEpochMilliseconds __attribute__((swift_name("toEpochMilliseconds()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t epochSeconds __attribute__((swift_name("epochSeconds")));
@property (readonly) int32_t nanosecondsOfSecond __attribute__((swift_name("nanosecondsOfSecond")));
@end

@interface DynamicsMultiplatformKotlinInstant (Extensions)
- (int32_t)daysUntilOther:(DynamicsMultiplatformKotlinInstant *)other timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("daysUntil(other:timeZone:)")));
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format offset:(DynamicsMultiplatformUtcOffset *)offset __attribute__((swift_name("format(format:offset:)")));
- (DynamicsMultiplatformKotlinInstant *)minusUnit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("minus(unit:)"))) __attribute__((deprecated("Use the minus overload with an explicit number of units")));
- (DynamicsMultiplatformKotlinInstant *)minusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("minus(value:unit:)")));
- (DynamicsMultiplatformKotlinInstant *)minusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("minus(value:unit_:)")));
- (int64_t)minusOther:(DynamicsMultiplatformKotlinInstant *)other unit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("minus(other:unit:)")));
- (DynamicsMultiplatformDateTimePeriod *)minusOther:(DynamicsMultiplatformKotlinInstant *)other timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(other:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)minusPeriod:(DynamicsMultiplatformDateTimePeriod *)period timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(period:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)minusUnit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(unit:timeZone:)"))) __attribute__((deprecated("Use the minus overload with an explicit number of units")));
- (DynamicsMultiplatformKotlinInstant *)minusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(value:unit:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)minusValue:(int64_t)value unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone_:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(value:unit:timeZone_:)")));
- (int64_t)minusOther:(DynamicsMultiplatformKotlinInstant *)other unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("minus(other:unit:timeZone:)")));
- (int32_t)monthsUntilOther:(DynamicsMultiplatformKotlinInstant *)other timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("monthsUntil(other:timeZone:)")));
- (DynamicsMultiplatformUtcOffset *)offsetInTimeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("offsetIn(timeZone:)")));
- (DynamicsMultiplatformDateTimePeriod *)periodUntilOther:(DynamicsMultiplatformKotlinInstant *)other timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("periodUntil(other:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)plusUnit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("plus(unit:)"))) __attribute__((deprecated("Use the plus overload with an explicit number of units")));
- (DynamicsMultiplatformKotlinInstant *)plusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("plus(value:unit:)")));
- (DynamicsMultiplatformKotlinInstant *)plusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("plus(value:unit_:)")));
- (DynamicsMultiplatformKotlinInstant *)plusPeriod:(DynamicsMultiplatformDateTimePeriod *)period timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("plus(period:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)plusUnit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("plus(unit:timeZone:)"))) __attribute__((deprecated("Use the plus overload with an explicit number of units")));
- (DynamicsMultiplatformKotlinInstant *)plusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("plus(value:unit:timeZone:)")));
- (DynamicsMultiplatformKotlinInstant *)plusValue:(int64_t)value unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone_:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("plus(value:unit:timeZone_:)")));
- (DynamicsMultiplatformLocalDateTime *)toLocalDateTimeTimeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("toLocalDateTime(timeZone:)")));
- (NSDate *)toNSDate __attribute__((swift_name("toNSDate()")));
- (int64_t)untilOther:(DynamicsMultiplatformKotlinInstant *)other unit:(DynamicsMultiplatformDateTimeUnitTimeBased *)unit __attribute__((swift_name("until(other:unit:)")));
- (int64_t)untilOther:(DynamicsMultiplatformKotlinInstant *)other unit:(DynamicsMultiplatformDateTimeUnit *)unit timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("until(other:unit:timeZone:)")));
- (int32_t)yearsUntilOther:(DynamicsMultiplatformKotlinInstant *)other timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("yearsUntil(other:timeZone:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinInstant.Companion")))
@interface DynamicsMultiplatformKotlinInstantCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinInstantCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformKotlinInstant *)fromEpochMillisecondsEpochMilliseconds:(int64_t)epochMilliseconds __attribute__((swift_name("fromEpochMilliseconds(epochMilliseconds:)")));
- (DynamicsMultiplatformKotlinInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment:(int32_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment:)")));
- (DynamicsMultiplatformKotlinInstant *)fromEpochSecondsEpochSeconds:(int64_t)epochSeconds nanosecondAdjustment_:(int64_t)nanosecondAdjustment __attribute__((swift_name("fromEpochSeconds(epochSeconds:nanosecondAdjustment_:)")));
- (DynamicsMultiplatformKotlinInstant *)now __attribute__((swift_name("now()"))) __attribute__((unavailable("Use Clock.System.now() instead")));
- (DynamicsMultiplatformKotlinInstant *)parseInput:(id)input __attribute__((swift_name("parse(input:)")));
- (DynamicsMultiplatformKotlinInstant * _Nullable)parseOrNullInput:(id)input __attribute__((swift_name("parseOrNull(input:)")));
@property (readonly) DynamicsMultiplatformKotlinInstant *DISTANT_FUTURE __attribute__((swift_name("DISTANT_FUTURE")));
@property (readonly) DynamicsMultiplatformKotlinInstant *DISTANT_PAST __attribute__((swift_name("DISTANT_PAST")));
@end

@interface DynamicsMultiplatformKotlinInstantCompanion (Extensions)
- (DynamicsMultiplatformKotlinInstant *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
@end

@interface DynamicsMultiplatformDatePeriod (Extensions)
- (DynamicsMultiplatformDatePeriod *)plusOther:(DynamicsMultiplatformDatePeriod *)other __attribute__((swift_name("plus(other:)"))) __attribute__((deprecated("Adding periods is not a well-defined operation. See https://github.com/Kotlin/kotlinx-datetime/issues/381")));
@end

@interface DynamicsMultiplatformDateTimePeriod (Extensions)
- (DynamicsMultiplatformDateTimePeriod *)plusOther_:(DynamicsMultiplatformDateTimePeriod *)other __attribute__((swift_name("plus(other_:)"))) __attribute__((deprecated("Adding periods is not a well-defined operation. See https://github.com/Kotlin/kotlinx-datetime/issues/381")));
@end

@interface DynamicsMultiplatformDayOfWeek (Extensions)
@property (readonly) int32_t isoDayNumber __attribute__((swift_name("isoDayNumber")));
@end

@interface DynamicsMultiplatformLocalDate (Extensions)
- (DynamicsMultiplatformKotlinInstant *)atStartOfDayInTimeZone:(DynamicsMultiplatformTimeZone *)timeZone youShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("atStartOfDayIn(timeZone:youShallNotPass:)")));
- (DynamicsMultiplatformLocalDateTime *)atTimeTime:(DynamicsMultiplatformLocalTime *)time __attribute__((swift_name("atTime(time:)")));
- (DynamicsMultiplatformLocalDateTime *)atTimeHour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond:(int32_t)nanosecond __attribute__((swift_name("atTime(hour:minute:second:nanosecond:)")));
- (int32_t)daysUntilOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("daysUntil(other:)")));
- (DynamicsMultiplatformLocalDateProgression *)downToThat:(DynamicsMultiplatformLocalDate *)that __attribute__((swift_name("downTo(that:)")));
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("format(format:)")));
- (DynamicsMultiplatformLocalDate *)minusPeriod:(DynamicsMultiplatformDatePeriod *)period __attribute__((swift_name("minus(period:)")));
- (DynamicsMultiplatformLocalDate *)minusUnit:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("minus(unit:)"))) __attribute__((deprecated("Use the minus overload with an explicit number of units")));
- (DynamicsMultiplatformDatePeriod *)minusOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("minus(other:)")));
- (DynamicsMultiplatformLocalDate *)minusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("minus(value:unit:)")));
- (DynamicsMultiplatformLocalDate *)minusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("minus(value:unit_:)")));
- (int32_t)monthsUntilOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("monthsUntil(other:)")));
- (DynamicsMultiplatformDatePeriod *)periodUntilOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("periodUntil(other:)")));
- (DynamicsMultiplatformLocalDate *)plusPeriod:(DynamicsMultiplatformDatePeriod *)period __attribute__((swift_name("plus(period:)")));
- (DynamicsMultiplatformLocalDate *)plusUnit:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("plus(unit:)"))) __attribute__((deprecated("Use the plus overload with an explicit number of units")));
- (DynamicsMultiplatformLocalDate *)plusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("plus(value:unit:)")));
- (DynamicsMultiplatformLocalDate *)plusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("plus(value:unit_:)")));
- (NSDateComponents *)toNSDateComponents __attribute__((swift_name("toNSDateComponents()")));
- (int64_t)untilOther:(DynamicsMultiplatformLocalDate *)other unit:(DynamicsMultiplatformDateTimeUnitDateBased *)unit __attribute__((swift_name("until(other:unit:)")));
- (int32_t)yearsUntilOther:(DynamicsMultiplatformLocalDate *)other __attribute__((swift_name("yearsUntil(other:)")));
@property (readonly) DynamicsMultiplatformYearMonth *yearMonth __attribute__((swift_name("yearMonth")));
@end

@interface DynamicsMultiplatformLocalDateProgression (Extensions)
- (DynamicsMultiplatformLocalDate *)first_ __attribute__((swift_name("first()")));
- (DynamicsMultiplatformLocalDate * _Nullable)firstOrNull __attribute__((swift_name("firstOrNull()")));
- (DynamicsMultiplatformLocalDate *)last_ __attribute__((swift_name("last()")));
- (DynamicsMultiplatformLocalDate * _Nullable)lastOrNull __attribute__((swift_name("lastOrNull()")));
- (DynamicsMultiplatformLocalDate *)randomRandom:(DynamicsMultiplatformKotlinRandom *)random __attribute__((swift_name("random(random:)")));
- (DynamicsMultiplatformLocalDate * _Nullable)randomOrNullRandom:(DynamicsMultiplatformKotlinRandom *)random __attribute__((swift_name("randomOrNull(random:)")));
- (DynamicsMultiplatformLocalDateProgression *)reversed __attribute__((swift_name("reversed()")));
- (DynamicsMultiplatformLocalDateProgression *)stepValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitDayBased *)unit __attribute__((swift_name("step(value:unit:)")));
- (DynamicsMultiplatformLocalDateProgression *)stepValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitDayBased *)unit __attribute__((swift_name("step(value:unit_:)")));
@end

@interface DynamicsMultiplatformLocalDateTime (Extensions)
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("format(format:)")));
- (DynamicsMultiplatformKotlinInstant *)toInstantTimeZone:(DynamicsMultiplatformTimeZone *)timeZone youShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("toInstant(timeZone:youShallNotPass:)")));
- (DynamicsMultiplatformKotlinInstant *)toInstantOffset:(DynamicsMultiplatformUtcOffset *)offset youShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("toInstant(offset:youShallNotPass:)")));
- (NSDateComponents *)toNSDateComponents __attribute__((swift_name("toNSDateComponents()")));
@end

@interface DynamicsMultiplatformLocalTime (Extensions)
- (DynamicsMultiplatformLocalDateTime *)atDateDate:(DynamicsMultiplatformLocalDate *)date __attribute__((swift_name("atDate(date:)")));
- (DynamicsMultiplatformLocalDateTime *)atDateYear:(int32_t)year month:(int32_t)month day:(int32_t)day __attribute__((swift_name("atDate(year:month:day:)")));
- (DynamicsMultiplatformLocalDateTime *)atDateYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month day_:(int32_t)day __attribute__((swift_name("atDate(year:month:day_:)")));
- (DynamicsMultiplatformLocalDateTime *)atDateYear:(int32_t)year monthNumber:(int32_t)monthNumber dayOfMonth:(int32_t)dayOfMonth fakeArgument:(DynamicsMultiplatformKotlinUnit *)fakeArgument __attribute__((swift_name("atDate(year:monthNumber:dayOfMonth:fakeArgument:)"))) __attribute__((deprecated("Use the overload that accepts a 'month' and a 'day' instead")));
- (DynamicsMultiplatformLocalDateTime *)atDateYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month dayOfMonth:(int32_t)dayOfMonth fakeArgument:(DynamicsMultiplatformKotlinUnit *)fakeArgument __attribute__((swift_name("atDate(year:month:dayOfMonth:fakeArgument:)"))) __attribute__((deprecated("Use the overload that accepts a 'month' and a 'day' instead")));
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("format(format:)")));
@end

@interface DynamicsMultiplatformMonth (Extensions)
@property (readonly) int32_t number __attribute__((swift_name("number")));
@end

@interface DynamicsMultiplatformTimeZone (Extensions)
- (DynamicsMultiplatformUtcOffset *)offsetAtInstant:(DynamicsMultiplatformKotlinInstant *)instant __attribute__((swift_name("offsetAt(instant:)")));
- (NSTimeZone *)toNSTimeZone __attribute__((swift_name("toNSTimeZone()")));
@end

@interface DynamicsMultiplatformUtcOffset (Extensions)
- (DynamicsMultiplatformFixedOffsetTimeZone *)asTimeZone __attribute__((swift_name("asTimeZone()")));
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("format(format:)")));
@end

@interface DynamicsMultiplatformYearMonth (Extensions)
- (DynamicsMultiplatformYearMonthProgression *)downToThat:(DynamicsMultiplatformYearMonth *)that __attribute__((swift_name("downTo(that:)")));
- (NSString *)formatFormat:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("format(format:)")));
- (DynamicsMultiplatformYearMonth *)minusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("minus(value:unit:)")));
- (DynamicsMultiplatformYearMonth *)minusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("minus(value:unit_:)")));
- (DynamicsMultiplatformYearMonth *)minusMonth __attribute__((swift_name("minusMonth()")));
- (DynamicsMultiplatformYearMonth *)minusYear __attribute__((swift_name("minusYear()")));
- (int32_t)monthsUntilOther:(DynamicsMultiplatformYearMonth *)other __attribute__((swift_name("monthsUntil(other:)")));
- (DynamicsMultiplatformLocalDate *)onDayDay:(int32_t)day __attribute__((swift_name("onDay(day:)")));
- (DynamicsMultiplatformYearMonth *)plusValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("plus(value:unit:)")));
- (DynamicsMultiplatformYearMonth *)plusValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("plus(value:unit_:)")));
- (DynamicsMultiplatformYearMonth *)plusMonth __attribute__((swift_name("plusMonth()")));
- (DynamicsMultiplatformYearMonth *)plusYear __attribute__((swift_name("plusYear()")));
- (NSDateComponents *)toNSDateComponents __attribute__((swift_name("toNSDateComponents()")));
- (int64_t)untilOther:(DynamicsMultiplatformYearMonth *)other unit:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("until(other:unit:)")));
- (int32_t)yearsUntilOther:(DynamicsMultiplatformYearMonth *)other __attribute__((swift_name("yearsUntil(other:)")));
@end

@interface DynamicsMultiplatformYearMonthProgression (Extensions)
- (DynamicsMultiplatformYearMonth *)first_ __attribute__((swift_name("first()")));
- (DynamicsMultiplatformYearMonth * _Nullable)firstOrNull __attribute__((swift_name("firstOrNull()")));
- (DynamicsMultiplatformYearMonth *)last_ __attribute__((swift_name("last()")));
- (DynamicsMultiplatformYearMonth * _Nullable)lastOrNull __attribute__((swift_name("lastOrNull()")));
- (DynamicsMultiplatformYearMonth *)randomRandom:(DynamicsMultiplatformKotlinRandom *)random __attribute__((swift_name("random(random:)")));
- (DynamicsMultiplatformYearMonth * _Nullable)randomOrNullRandom:(DynamicsMultiplatformKotlinRandom *)random __attribute__((swift_name("randomOrNull(random:)")));
- (DynamicsMultiplatformYearMonthProgression *)reversed __attribute__((swift_name("reversed()")));
- (DynamicsMultiplatformYearMonthProgression *)stepValue:(int32_t)value unit:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("step(value:unit:)")));
- (DynamicsMultiplatformYearMonthProgression *)stepValue:(int64_t)value unit_:(DynamicsMultiplatformDateTimeUnitMonthBased *)unit __attribute__((swift_name("step(value:unit_:)")));
@end

@interface DynamicsMultiplatformDateTimeComponentsCompanion (Extensions)
- (DynamicsMultiplatformDateTimeComponents *)parseInput:(id)input format:(id<DynamicsMultiplatformDateTimeFormat>)format __attribute__((swift_name("parse(input:format:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("AppleDeviceKt")))
@interface DynamicsMultiplatformAppleDeviceKt : DynamicsMultiplatformBase

/**
 * @return the [CBPeripheral] from [CommonDevice].
 */
+ (CBPeripheral *)getCbPeripheral:(id<DynamicsMultiplatformCommonDevice>)receiver __attribute__((swift_name("getCbPeripheral(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleMultiplexLogEngineKt")))
@interface DynamicsMultiplatformBleMultiplexLogEngineKt : DynamicsMultiplatformBase
@property (class, readonly) NSString *(^addressFormatter)(NSString *) __attribute__((swift_name("addressFormatter")));
@property (class, readonly) NSString *(^bleUuidFormatter)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *) __attribute__((swift_name("bleUuidFormatter")));
@property (class, readonly) NSString *(^dataFormatter)(DynamicsMultiplatformBle_multiplex_uuidBleUuid *, DynamicsMultiplatformKotlinByteArray * _Nullable, NSString *(^)(DynamicsMultiplatformKotlinByteArray *)) __attribute__((swift_name("dataFormatter")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BlePacketKt")))
@interface DynamicsMultiplatformBlePacketKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformKotlinByteArray *)dataContent:(NSArray<DynamicsMultiplatformBlePacket *> *)receiver __attribute__((swift_name("dataContent(_:)")));
+ (DynamicsMultiplatformKotlinByteArray *)totalContent:(NSArray<DynamicsMultiplatformBlePacket *> *)receiver __attribute__((swift_name("totalContent(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleRequirementsKt")))
@interface DynamicsMultiplatformBleRequirementsKt : DynamicsMultiplatformBase

/**
 * @return a flow collecting the [BleRequirementsState].
 */
+ (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)bleRequirements:(id<DynamicsMultiplatformKotlinx_coroutines_coreCoroutineScope>)receiver includeRequirementsForScanning:(BOOL)includeRequirementsForScanning __attribute__((swift_name("bleRequirements(_:includeRequirementsForScanning:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BleRequirementsIosKt")))
@interface DynamicsMultiplatformBleRequirementsIosKt : DynamicsMultiplatformBase

/**
 * Please note that if bt state is [BluetoothState.Unknown] but [PermissionState] is granted, then isBluetoothEnabled
 * is set to true since it's just in an undetermined state until the CBManager's delegate is called after init.
 */
+ (DynamicsMultiplatformBleRequirementsState *)convertToBleRequirementsStateExpectScanningRequirements:(BOOL)expectScanningRequirements permissionState:(DynamicsMultiplatformCorePermissionState *)permissionState bluetoothState:(DynamicsMultiplatformCoreBluetoothState *)bluetoothState locationState:(DynamicsMultiplatformCoreLocationState *)locationState __attribute__((swift_name("convertToBleRequirementsState(expectScanningRequirements:permissionState:bluetoothState:locationState:)")));
+ (DynamicsMultiplatformBleRequirements *)getBleRequirementsIncludeRequirementsForScanning:(BOOL)includeRequirementsForScanning __attribute__((swift_name("getBleRequirements(includeRequirementsForScanning:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("BodyProfileKt")))
@interface DynamicsMultiplatformBodyProfileKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformBodyProfile * _Nullable)constructBodyProfileId:(id _Nullable)id name:(NSString * _Nullable)name weight:(id _Nullable)weight height:(id _Nullable)height gender:(DynamicsMultiplatformGender * _Nullable)gender __attribute__((swift_name("constructBodyProfile(id:name:weight:height:gender:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ClockKt")))
@interface DynamicsMultiplatformClockKt : DynamicsMultiplatformBase
+ (id<DynamicsMultiplatformKotlinClock>)asClock:(id<DynamicsMultiplatformKotlinTimeSource>)receiver origin:(DynamicsMultiplatformKotlinInstant *)origin __attribute__((swift_name("asClock(_:origin:)")));

/**
 * @note annotations
 *   kotlin.time.ExperimentalTime
*/
+ (id<DynamicsMultiplatformKotlinTimeSourceWithComparableMarks>)asTimeSource:(id<DynamicsMultiplatformKotlinClock>)receiver __attribute__((swift_name("asTimeSource(_:)"))) __attribute__((deprecated("This function is deprecated because Clock.System.asTimeSource can be confused with TimeSource.Monotonic, which are very different. See https://github.com/Kotlin/kotlinx-datetime/issues/372")));
+ (DynamicsMultiplatformLocalDate *)todayAt:(id<DynamicsMultiplatformKotlinClock>)receiver timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("todayAt(_:timeZone:)"))) __attribute__((deprecated("Use Clock.todayIn instead")));
+ (DynamicsMultiplatformLocalDate *)todayIn:(id<DynamicsMultiplatformKotlinClock>)receiver timeZone:(DynamicsMultiplatformTimeZone *)timeZone __attribute__((swift_name("todayIn(_:timeZone:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConfigurationRangesKt")))
@interface DynamicsMultiplatformConfigurationRangesKt : DynamicsMultiplatformBase
@property (class, readonly) DynamicsMultiplatformKotlinIntRange *countOfPostImpactSamplesRange __attribute__((swift_name("countOfPostImpactSamplesRange")));
@property (class, readonly) int32_t countOfPostImpactSamplesStep __attribute__((swift_name("countOfPostImpactSamplesStep")));
@property (class, readonly) DynamicsMultiplatformKotlinIntRange *countOfPreTriggerSamplesRange __attribute__((swift_name("countOfPreTriggerSamplesRange")));
@property (class, readonly) int32_t countOfPreTriggerSamplesStep __attribute__((swift_name("countOfPreTriggerSamplesStep")));
@property (class, readonly) id<DynamicsMultiplatformKotlinClosedFloatingPointRange> deepSleepWakeUpTriggerThresholdIncreaseRange __attribute__((swift_name("deepSleepWakeUpTriggerThresholdIncreaseRange")));
@property (class, readonly) double deepSleepWakeUpTriggerThresholdIncreaseStep __attribute__((swift_name("deepSleepWakeUpTriggerThresholdIncreaseStep")));
@property (class, readonly) id<DynamicsMultiplatformKotlinClosedFloatingPointRange> minAbsAccForValidImpactRange __attribute__((swift_name("minAbsAccForValidImpactRange")));
@property (class, readonly) double minAbsAccForValidImpactStep __attribute__((swift_name("minAbsAccForValidImpactStep")));
@property (class, readonly) id<DynamicsMultiplatformKotlinClosedFloatingPointRange> wakeUpTriggerThresholdIncreaseRange __attribute__((swift_name("wakeUpTriggerThresholdIncreaseRange")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
@property (class, readonly) double wakeUpTriggerThresholdIncreaseStep __attribute__((swift_name("wakeUpTriggerThresholdIncreaseStep")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConstantsKt")))
@interface DynamicsMultiplatformConstantsKt : DynamicsMultiplatformBase
@property (class, readonly) NSString *KABLE_RESTORE_IDENTIFIER_KEY_VALUE __attribute__((swift_name("KABLE_RESTORE_IDENTIFIER_KEY_VALUE")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ConvertersKt")))
@interface DynamicsMultiplatformConvertersKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformKotlinInstant *)toKotlinInstant:(NSDate *)receiver youShallNotPass:(DynamicsMultiplatformOverloadMarker *)youShallNotPass __attribute__((swift_name("toKotlinInstant(_:youShallNotPass:)")));
+ (DynamicsMultiplatformTimeZone *)toKotlinTimeZone:(NSTimeZone *)receiver __attribute__((swift_name("toKotlinTimeZone(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DataPacketKt")))
@interface DynamicsMultiplatformDataPacketKt : DynamicsMultiplatformBase
+ (int32_t)countAccSamples:(NSArray<DynamicsMultiplatformDataPacket *> *)receiver __attribute__((swift_name("countAccSamples(_:)")));
+ (int32_t)countBaroSamples:(NSArray<DynamicsMultiplatformDataPacket *> *)receiver __attribute__((swift_name("countBaroSamples(_:)")));
+ (int32_t)countGyroSamples:(NSArray<DynamicsMultiplatformDataPacket *> *)receiver __attribute__((swift_name("countGyroSamples(_:)")));

/**
 * The count of imu samples always assumes that [countAccSamples] and [countGyroSamples] are
 * equal.
 *
 * However, in some streaming modes it may happen that those two sensor values will differ, e.g.
 * in [com.riseworld.dynamics.models.ble.operation.OperationalState.ACC_STREAM].
 */
+ (int32_t)countImuSamples:(NSArray<DynamicsMultiplatformDataPacket *> *)receiver __attribute__((swift_name("countImuSamples(_:)")));
+ (int32_t)countMagnetoSamples:(NSArray<DynamicsMultiplatformDataPacket *> *)receiver __attribute__((swift_name("countMagnetoSamples(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeComponentsKt")))
@interface DynamicsMultiplatformDateTimeComponentsKt : DynamicsMultiplatformBase
+ (NSString *)format:(id<DynamicsMultiplatformDateTimeFormat>)receiver block:(void (^)(DynamicsMultiplatformDateTimeComponents *))block __attribute__((swift_name("format(_:block:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimeFormatBuilderKt")))
@interface DynamicsMultiplatformDateTimeFormatBuilderKt : DynamicsMultiplatformBase
+ (void)alternativeParsing:(id<DynamicsMultiplatformDateTimeFormatBuilder>)receiver alternativeFormats:(DynamicsMultiplatformKotlinArray<DynamicsMultiplatformKotlinUnit *(^)(id<DynamicsMultiplatformDateTimeFormatBuilder>)> *)alternativeFormats primaryFormat:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilder>))primaryFormat __attribute__((swift_name("alternativeParsing(_:alternativeFormats:primaryFormat:)")));
+ (void)char:(id<DynamicsMultiplatformDateTimeFormatBuilder>)receiver value:(unichar)value __attribute__((swift_name("char(_:value:)")));
+ (void)optional:(id<DynamicsMultiplatformDateTimeFormatBuilder>)receiver ifZero:(NSString *)ifZero format:(void (^)(id<DynamicsMultiplatformDateTimeFormatBuilder>))format __attribute__((swift_name("optional(_:ifZero:format:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DateTimePeriodKt")))
@interface DynamicsMultiplatformDateTimePeriodKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformDateTimePeriod *)DateTimePeriodYears:(int32_t)years months:(int32_t)months days:(int32_t)days hours:(int32_t)hours minutes:(int32_t)minutes seconds:(int32_t)seconds nanoseconds:(int64_t)nanoseconds __attribute__((swift_name("DateTimePeriod(years:months:days:hours:minutes:seconds:nanoseconds:)")));
+ (DynamicsMultiplatformDatePeriod *)toDatePeriod:(NSString *)receiver __attribute__((swift_name("toDatePeriod(_:)"))) __attribute__((deprecated("Removed to support more idiomatic code. See https://github.com/Kotlin/kotlinx-datetime/issues/339")));
+ (DynamicsMultiplatformDateTimePeriod *)toDateTimePeriod:(NSString *)receiver __attribute__((swift_name("toDateTimePeriod(_:)"))) __attribute__((deprecated("Removed to support more idiomatic code. See https://github.com/Kotlin/kotlinx-datetime/issues/339")));
+ (DynamicsMultiplatformDateTimePeriod *)toDateTimePeriod_:(int64_t)receiver __attribute__((swift_name("toDateTimePeriod(__:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DayOfWeekKt")))
@interface DynamicsMultiplatformDayOfWeekKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformDayOfWeek *)DayOfWeekIsoDayNumber:(int32_t)isoDayNumber __attribute__((swift_name("DayOfWeek(isoDayNumber:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DelegatesKt")))
@interface DynamicsMultiplatformDelegatesKt : DynamicsMultiplatformBase
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)boolean:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("boolean(_:key:defaultValue:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)double:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(double)defaultValue __attribute__((swift_name("double(_:key:defaultValue:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)float:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(float)defaultValue __attribute__((swift_name("float(_:key:defaultValue:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)int:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(int32_t)defaultValue __attribute__((swift_name("int(_:key:defaultValue:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)long:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(int64_t)defaultValue __attribute__((swift_name("long(_:key:defaultValue:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableBoolean:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableBoolean(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableDouble:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableDouble(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableFloat:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableFloat(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableInt:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableInt(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableLong:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableLong(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)nullableString:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key __attribute__((swift_name("nullableString(_:key:)")));
+ (id<DynamicsMultiplatformKotlinReadWriteProperty>)string:(id<DynamicsMultiplatformSettings>)receiver key:(NSString * _Nullable)key defaultValue:(NSString *)defaultValue __attribute__((swift_name("string(_:key:defaultValue:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DurationExtensionsKt")))
@interface DynamicsMultiplatformDurationExtensionsKt : DynamicsMultiplatformBase
@property (class, readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *deepSleepWakeUpTriggerDebounceTimeStep __attribute__((swift_name("deepSleepWakeUpTriggerDebounceTimeStep")));
@property (class, readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *maxWaitingTimeForAbsValidationStep __attribute__((swift_name("maxWaitingTimeForAbsValidationStep")));
@property (class, readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *wakeUpTriggerDebounceTimeStep __attribute__((swift_name("wakeUpTriggerDebounceTimeStep")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DurationRangeExtensionsKt")))
@interface DynamicsMultiplatformDurationRangeExtensionsKt : DynamicsMultiplatformBase
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *advertisingRange __attribute__((swift_name("advertisingRange")));
@property (class, readonly) DynamicsMultiplatformDynamics_utilsNanoSeconds *advertisingRangesStep __attribute__((swift_name("advertisingRangesStep")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *advertisingTimeoutRange __attribute__((swift_name("advertisingTimeoutRange")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *backToMeasurementIdleTimeoutRange __attribute__((swift_name("backToMeasurementIdleTimeoutRange")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *deactivateOfflineMeasurementModeTimeoutRange __attribute__((swift_name("deactivateOfflineMeasurementModeTimeoutRange")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *deepSleepWakeUpTriggerDebounceTimeRange __attribute__((swift_name("deepSleepWakeUpTriggerDebounceTimeRange")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *maxWaitingTimeForAbsValidationRange __attribute__((swift_name("maxWaitingTimeForAbsValidationRange")));
@property (class, readonly) DynamicsMultiplatformKotlinLongRange *wakeUpTriggerDebounceTimeRange __attribute__((swift_name("wakeUpTriggerDebounceTimeRange")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsMultiplatformKt")))
@interface DynamicsMultiplatformDynamicsMultiplatformKt : DynamicsMultiplatformBase

/**
 * Initializes the Napier logger.
 *
 * @param antilogs a list of Napier Antilog instances.
 * @param bleMultiplexLogEngines provides [BleMultiplexLogEngine]s that can be used to log events from ble-multiplex.
 * @param kableLogEngine provides a single optional [Antilog] that can be used to log events from kable
 * -fork. One can expect to see only BleMultiplexLogMessage of type PlainMessage as the kable log engine is internally
 * mapped to the bleMultiplexLogEngine.
 */
+ (void)doInitLoggersAntilogs:(NSArray<DynamicsMultiplatformAntilog *> *)antilogs bleMultiplexLogEngines:(NSArray<id<DynamicsMultiplatformBleMultiplexLogEngine>> *)bleMultiplexLogEngines kableLogEngine:(DynamicsMultiplatformAntilog * _Nullable)kableLogEngine __attribute__((swift_name("doInitLoggers(antilogs:bleMultiplexLogEngines:kableLogEngine:)")));

/**
 * Initializes the multiplatform SDK. This needs be called before any properties and functions
 * from are accessed.
 *
 * @param dynamicsSettings The [DynamicsSettings] instance, see
 * https://github.com/russhwolf/multiplatform-settings for more details on how to initialize this.
 * @param testOptions for enabling testing options for dynamics.
 * @param app for providing meta information of the consumer app.
 * @param device for providing meta information of the consumer device.
 * @param httpClientLogLevel the log level for the http logger, if there are no loggers registered
 * via [initLoggers], then this option has no effect.
 */
+ (void)doInitSdkDynamicsSettings:(DynamicsMultiplatformDynamicsSettings *)dynamicsSettings testOptions:(DynamicsMultiplatformDynamicsTestOptions *)testOptions app:(DynamicsMultiplatformAppInfo * _Nullable)app device:(DynamicsMultiplatformDeviceInfo_ * _Nullable)device httpClientLogLevel:(DynamicsMultiplatformHttpClientLogLevel *)httpClientLogLevel __attribute__((swift_name("doInitSdk(dynamicsSettings:testOptions:app:device:httpClientLogLevel:)")));

/**
 * The string tag for the http client logger.
 */
@property (class, readonly) NSString *LOG_TAG_HTTP_CLIENT __attribute__((swift_name("LOG_TAG_HTTP_CLIENT")));

/**
 * The current information object holding app meta data.
 */
@property (class) DynamicsMultiplatformAppInfo * _Nullable appInfo __attribute__((swift_name("appInfo")));

/**
 * A function which takes [ByteArray] and applies [ByteArray.asHexLine] with the default dynamics
 * formatter.
 */
@property (class, readonly) NSString *(^bleMultiplexLoggerHexFormat)(DynamicsMultiplatformKotlinByteArray *) __attribute__((swift_name("bleMultiplexLoggerHexFormat")));

/**
 * The UUID of the data pipe.
 */
@property (class, readonly) DynamicsMultiplatformBle_multiplex_uuidBleUuid *dataPipeBleUuid __attribute__((swift_name("dataPipeBleUuid")));

/**
 * The current information object holding device meta data.
 */
@property (class) DynamicsMultiplatformDeviceInfo_ * _Nullable deviceInfo __attribute__((swift_name("deviceInfo")));
@property (class, readonly) DynamicsMultiplatformDynamicsContextObserver *dynamicsContextObserver __attribute__((swift_name("dynamicsContextObserver")));

/**
 * The [ExportRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformExportRepository *exportRepository __attribute__((swift_name("exportRepository")));

/**
 * The [FinishedTrainingSessionRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformFinishedTrainingSessionRepository *finishedTrainingSessionRepository __attribute__((swift_name("finishedTrainingSessionRepository")));

/**
 * The [FirmwareUpdateRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformFirmwareUpdateRepository *firmwareUpdateRepository __attribute__((swift_name("firmwareUpdateRepository")));

/**
 * The [ExportRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformGloveConfigurationRepository *gloveConfigurationRepository __attribute__((swift_name("gloveConfigurationRepository")));

/**
 * The [GloveRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformGloveRepository *gloveRepository __attribute__((swift_name("gloveRepository")));

/**
 * The [PairingRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformPairingRepository *pairingRepository __attribute__((swift_name("pairingRepository")));

/**
 * The [ProfileRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformProfileRepository *profileRepository __attribute__((swift_name("profileRepository")));

/**
 * The [PunchRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformPunchRepository *punchRepository __attribute__((swift_name("punchRepository")));

/**
 * The [SensorDataRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformSensorDataRepository *sensorDataRepository __attribute__((swift_name("sensorDataRepository")));

/**
 * The [TestRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformTestRepository *testRepository __attribute__((swift_name("testRepository")));

/**
 * The [TrainingSessionRepository] instance.
 */
@property (class, readonly) DynamicsMultiplatformTrainingSessionRepository *trainingSessionRepository __attribute__((swift_name("trainingSessionRepository")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("DynamicsOpExceptionKt")))
@interface DynamicsMultiplatformDynamicsOpExceptionKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformDynamicsOpException *)opExceptionError:(DynamicsMultiplatformDynamicsOpError *)error message:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("opException(error:message:cause:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ImpactDataPacketKt")))
@interface DynamicsMultiplatformImpactDataPacketKt : DynamicsMultiplatformBase

/**
 * Returns a [String] in CSV format of the [ImpactDataPacket]s.
 *
 * The CSV format includes the following columns which are separated by a semi-colon (`;`):
 * - type: The type of the [ImpactDataPacket].
 * - failureReason: (optional) The reason why the [ImpactDataPacket] failed.
 * - rawContent: The raw content of the [ImpactDataPacket] in Hex format.
 */
+ (NSString *)toCsvString:(NSArray<DynamicsMultiplatformImpactDataPacket *> *)receiver __attribute__((swift_name("toCsvString(_:)")));

/**
 * Returns a [String] of the [ImpactDataPacket]'s raw content in Hex format separated by new lines.
 */
+ (NSString *)toRawContentDumpString:(NSArray<DynamicsMultiplatformImpactDataPacket *> *)receiver __attribute__((swift_name("toRawContentDumpString(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateKt")))
@interface DynamicsMultiplatformLocalDateKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformLocalDate *)LocalDateYear:(int32_t)year monthNumber:(int32_t)monthNumber dayOfMonth:(int32_t)dayOfMonth __attribute__((swift_name("LocalDate(year:monthNumber:dayOfMonth:)"))) __attribute__((deprecated("Use the constructor that accepts a 'month' and a 'day'")));
+ (DynamicsMultiplatformLocalDate *)LocalDateYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month dayOfMonth:(int32_t)dayOfMonth __attribute__((swift_name("LocalDate(year:month:dayOfMonth:)"))) __attribute__((deprecated("Use the constructor that accepts a 'day'")));
+ (DynamicsMultiplatformLocalDate *)toLocalDate:(NSString *)receiver __attribute__((swift_name("toLocalDate(_:)"))) __attribute__((deprecated("Removed to support more idiomatic code. See https://github.com/Kotlin/kotlinx-datetime/issues/339")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalDateTimeKt")))
@interface DynamicsMultiplatformLocalDateTimeKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformLocalDateTime *)LocalDateTimeYear:(int32_t)year monthNumber:(int32_t)monthNumber dayOfMonth:(int32_t)dayOfMonth hour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond:(int32_t)nanosecond __attribute__((swift_name("LocalDateTime(year:monthNumber:dayOfMonth:hour:minute:second:nanosecond:)"))) __attribute__((deprecated("Use the constructor that accepts a 'month' and a 'day'")));
+ (DynamicsMultiplatformLocalDateTime *)LocalDateTimeYear:(int32_t)year month:(DynamicsMultiplatformMonth *)month dayOfMonth:(int32_t)dayOfMonth hour:(int32_t)hour minute:(int32_t)minute second:(int32_t)second nanosecond:(int32_t)nanosecond __attribute__((swift_name("LocalDateTime(year:month:dayOfMonth:hour:minute:second:nanosecond:)"))) __attribute__((deprecated("Use the constructor that accepts a 'day'")));
+ (DynamicsMultiplatformLocalDateTime *)toLocalDateTime:(NSString *)receiver __attribute__((swift_name("toLocalDateTime(_:)"))) __attribute__((deprecated("Removed to support more idiomatic code. See https://github.com/Kotlin/kotlinx-datetime/issues/339")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("LocalTimeKt")))
@interface DynamicsMultiplatformLocalTimeKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformLocalTime *)toLocalTime:(NSString *)receiver __attribute__((swift_name("toLocalTime(_:)"))) __attribute__((deprecated("Removed to support more idiomatic code. See https://github.com/Kotlin/kotlinx-datetime/issues/339")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MeterPerSec2Kt")))
@interface DynamicsMultiplatformMeterPerSec2Kt : DynamicsMultiplatformBase
+ (double)toGravity:(double)receiver __attribute__((swift_name("toGravity(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("MonthKt")))
@interface DynamicsMultiplatformMonthKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformMonth *)MonthNumber:(int32_t)number __attribute__((swift_name("Month(number:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("NapierKt")))
@interface DynamicsMultiplatformNapierKt : DynamicsMultiplatformBase
+ (void)logPriority:(DynamicsMultiplatformLogLevel_ *)priority throwable:(DynamicsMultiplatformKotlinThrowable * _Nullable)throwable tag:(NSString * _Nullable)tag message:(NSString *(^)(void))message __attribute__((swift_name("log(priority:throwable:tag:message:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("OperatorsKt")))
@interface DynamicsMultiplatformOperatorsKt : DynamicsMultiplatformBase
+ (BOOL)contains:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key __attribute__((swift_name("contains(_:key:)")));
+ (id _Nullable)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key __attribute__((swift_name("get(_:key:)")));
+ (BOOL)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue:(BOOL)defaultValue __attribute__((swift_name("get(_:key:defaultValue:)")));
+ (double)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue_:(double)defaultValue __attribute__((swift_name("get(_:key:defaultValue_:)")));
+ (float)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue__:(float)defaultValue __attribute__((swift_name("get(_:key:defaultValue__:)")));
+ (int32_t)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue___:(int32_t)defaultValue __attribute__((swift_name("get(_:key:defaultValue___:)")));
+ (int64_t)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue____:(int64_t)defaultValue __attribute__((swift_name("get(_:key:defaultValue____:)")));
+ (NSString *)get:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key defaultValue_____:(NSString *)defaultValue __attribute__((swift_name("get(_:key:defaultValue_____:)")));
+ (void)minusAssign:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key __attribute__((swift_name("minusAssign(_:key:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value:(id _Nullable)value __attribute__((swift_name("set(_:key:value:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value_:(BOOL)value __attribute__((swift_name("set(_:key:value_:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value__:(double)value __attribute__((swift_name("set(_:key:value__:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value___:(float)value __attribute__((swift_name("set(_:key:value___:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value____:(int32_t)value __attribute__((swift_name("set(_:key:value____:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value_____:(int64_t)value __attribute__((swift_name("set(_:key:value_____:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value______:(DynamicsMultiplatformKotlinNothing * _Nullable)value __attribute__((swift_name("set(_:key:value______:)")));
+ (void)set:(id<DynamicsMultiplatformSettings>)receiver key:(NSString *)key value_______:(NSString *)value __attribute__((swift_name("set(_:key:value_______:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("PunchKt")))
@interface DynamicsMultiplatformPunchKt : DynamicsMultiplatformBase
+ (NSArray<DynamicsMultiplatformTimeSampleDouble *> *)toTimeSamples:(NSArray<DynamicsMultiplatformDouble *> *)receiver samplingRates:(NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *)samplingRates offset:(int64_t)offset __attribute__((swift_name("toTimeSamples(_:samplingRates:offset:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("RangeExtensionsKt")))
@interface DynamicsMultiplatformRangeExtensionsKt : DynamicsMultiplatformBase
+ (double)endInclusiveNative:(id<DynamicsMultiplatformKotlinClosedFloatingPointRange>)receiver __attribute__((swift_name("endInclusiveNative(_:)")));
+ (double)startNative:(id<DynamicsMultiplatformKotlinClosedFloatingPointRange>)receiver __attribute__((swift_name("startNative(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("StateKt")))
@interface DynamicsMultiplatformStateKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformKableStateDisconnectedStatus *)toStatus:(NSError *)receiver __attribute__((swift_name("toStatus(_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("TrainingSessionBestPunchesKt")))
@interface DynamicsMultiplatformTrainingSessionBestPunchesKt : DynamicsMultiplatformBase

/**
 * @return [Punch] from a list of punches for a [category]. See [bestBy] for more details.
 */
+ (DynamicsMultiplatformPunch *)bestBy:(NSArray<DynamicsMultiplatformPunch *> *)receiver category:(DynamicsMultiplatformBestPunchCategory *)category __attribute__((swift_name("bestBy(_:category:)")));

/**
 * @return [PunchWithSamples] from a list of punches for a [category]. If there are multiple best
 * punches for the same [category], then [maxBy] will choose the first occurrence.
 */
+ (DynamicsMultiplatformPunchWithSamples *)bestBy:(NSArray<DynamicsMultiplatformPunchWithSamples *> *)receiver category_:(DynamicsMultiplatformBestPunchCategory *)category __attribute__((swift_name("bestBy(_:category_:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UnicodeKt")))
@interface DynamicsMultiplatformUnicodeKt : DynamicsMultiplatformBase

/**
 * @note annotations
 *   kotlinx.datetime.format.FormatStringsInDatetimeFormats
*/
+ (void)byUnicodePattern:(id<DynamicsMultiplatformDateTimeFormatBuilder>)receiver pattern:(NSString *)pattern __attribute__((swift_name("byUnicodePattern(_:pattern:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("UtcOffsetKt")))
@interface DynamicsMultiplatformUtcOffsetKt : DynamicsMultiplatformBase
+ (DynamicsMultiplatformUtcOffset *)UtcOffset __attribute__((swift_name("UtcOffset()"))) __attribute__((unavailable("Use UtcOffset.ZERO instead")));
+ (DynamicsMultiplatformUtcOffset *)UtcOffsetHours:(DynamicsMultiplatformInt * _Nullable)hours minutes:(DynamicsMultiplatformInt * _Nullable)minutes seconds:(DynamicsMultiplatformInt * _Nullable)seconds __attribute__((swift_name("UtcOffset(hours:minutes:seconds:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinArray")))
@interface DynamicsMultiplatformKotlinArray<T> : DynamicsMultiplatformBase
+ (instancetype)arrayWithSize:(int32_t)size init:(T _Nullable (^)(DynamicsMultiplatformInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (T _Nullable)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (id<DynamicsMultiplatformKotlinIterator>)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(T _Nullable)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinEnumCompanion")))
@interface DynamicsMultiplatformKotlinEnumCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinEnumCompanion *shared __attribute__((swift_name("shared")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinByteArray")))
@interface DynamicsMultiplatformKotlinByteArray : DynamicsMultiplatformBase
+ (instancetype)arrayWithSize:(int32_t)size __attribute__((swift_name("init(size:)")));
+ (instancetype)arrayWithSize:(int32_t)size init:(DynamicsMultiplatformByte *(^)(DynamicsMultiplatformInt *))init __attribute__((swift_name("init(size:init:)")));
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (int8_t)getIndex:(int32_t)index __attribute__((swift_name("get(index:)")));
- (DynamicsMultiplatformKotlinByteIterator *)iterator __attribute__((swift_name("iterator()")));
- (void)setIndex:(int32_t)index value:(int8_t)value __attribute__((swift_name("set(index:value:)")));
@property (readonly) int32_t size __attribute__((swift_name("size")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.0")
 *   kotlin.uuid.ExperimentalUuidApi
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUuid")))
@interface DynamicsMultiplatformKotlinUuid : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinUuidCompanion *companion __attribute__((swift_name("companion")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.1")
*/
- (int32_t)compareToOther:(DynamicsMultiplatformKotlinUuid *)other __attribute__((swift_name("compareTo(other:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformKotlinByteArray *)toByteArray __attribute__((swift_name("toByteArray()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.1")
*/
- (NSString *)toHexDashString __attribute__((swift_name("toHexDashString()")));
- (NSString *)toHexString __attribute__((swift_name("toHexString()")));
- (id _Nullable)toLongsAction:(id _Nullable (^)(DynamicsMultiplatformLong *, DynamicsMultiplatformLong *))action __attribute__((swift_name("toLongs(action:)")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.1")
 *   kotlin.ExperimentalUnsignedTypes
*/
- (id)toUByteArray __attribute__((swift_name("toUByteArray()")));
- (id _Nullable)toULongsAction:(id _Nullable (^)(DynamicsMultiplatformULong *, DynamicsMultiplatformULong *))action __attribute__((swift_name("toULongs(action:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinClosedFloatingPointRange")))
@protocol DynamicsMultiplatformKotlinClosedFloatingPointRange <DynamicsMultiplatformKotlinClosedRange>
@required
- (BOOL)lessThanOrEqualsA:(id)a b:(id)b __attribute__((swift_name("lessThanOrEquals(a:b:)")));
@end

__attribute__((swift_name("KotlinIntProgression")))
@interface DynamicsMultiplatformKotlinIntProgression : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinIterable>
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinIntProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (DynamicsMultiplatformKotlinIntIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t first __attribute__((swift_name("first")));
@property (readonly) int32_t last __attribute__((swift_name("last")));
@property (readonly) int32_t step __attribute__((swift_name("step")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange")))
@interface DynamicsMultiplatformKotlinIntRange : DynamicsMultiplatformKotlinIntProgression <DynamicsMultiplatformKotlinClosedRange, DynamicsMultiplatformKotlinOpenEndRange>
- (instancetype)initWithStart:(int32_t)start endInclusive:(int32_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinIntRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(DynamicsMultiplatformInt *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(DynamicsMultiplatformInt *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) DynamicsMultiplatformInt *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Int type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) DynamicsMultiplatformInt *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) DynamicsMultiplatformInt *start __attribute__((swift_name("start")));
@end


/**
 * A sampling rate mark which indicates changes to the sampling rate of the data starting from
 * [index].
 * @param index the index from which a new sampling rate is used.
 * @param frequency the frequency in hertz.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_utilsSamplingRateMark")))
@interface DynamicsMultiplatformDynamics_utilsSamplingRateMark : DynamicsMultiplatformBase
- (instancetype)initWithIndex:(int32_t)index frequency:(int32_t)frequency __attribute__((swift_name("init(index:frequency:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamics_utilsSamplingRateMarkCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDynamics_utilsSamplingRateMark *)doCopyIndex:(int32_t)index frequency:(int32_t)frequency __attribute__((swift_name("doCopy(index:frequency:)")));

/**
 * A sampling rate mark which indicates changes to the sampling rate of the data starting from
 * [index].
 * @param index the index from which a new sampling rate is used.
 * @param frequency the frequency in hertz.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * A sampling rate mark which indicates changes to the sampling rate of the data starting from
 * [index].
 * @param index the index from which a new sampling rate is used.
 * @param frequency the frequency in hertz.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * A sampling rate mark which indicates changes to the sampling rate of the data starting from
 * [index].
 * @param index the index from which a new sampling rate is used.
 * @param frequency the frequency in hertz.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t frequency __attribute__((swift_name("frequency")));
@property (readonly) int32_t index __attribute__((swift_name("index")));
@property (readonly) int64_t timePerSample __attribute__((swift_name("timePerSample")));
@property (readonly) int32_t timePerSampleInMicroS __attribute__((swift_name("timePerSampleInMicroS")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ble_multiplex_uuidVersion")))
@interface DynamicsMultiplatformBle_multiplex_uuidVersion : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithMajor:(int32_t)major minor:(int32_t)minor patch:(int32_t)patch suffix:(NSString * _Nullable)suffix __attribute__((swift_name("init(major:minor:patch:suffix:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(DynamicsMultiplatformBle_multiplex_uuidVersion *)other __attribute__((swift_name("compareTo(other:)")));
- (DynamicsMultiplatformBle_multiplex_uuidVersion *)doCopyMajor:(int32_t)major minor:(int32_t)minor patch:(int32_t)patch suffix:(NSString * _Nullable)suffix __attribute__((swift_name("doCopy(major:minor:patch:suffix:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int32_t major __attribute__((swift_name("major")));
@property (readonly) int32_t minor __attribute__((swift_name("minor")));
@property (readonly) int32_t patch __attribute__((swift_name("patch")));
@property (readonly) NSString * _Nullable suffix __attribute__((swift_name("suffix")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUnit")))
@interface DynamicsMultiplatformKotlinUnit : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)unit __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinUnit *shared __attribute__((swift_name("shared")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlow")))
@protocol DynamicsMultiplatformKotlinx_coroutines_coreFlow
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)collectCollector:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlowCollector>)collector completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("collect(collector:completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("ResourceResource")))
@interface DynamicsMultiplatformResourceResource<T> : DynamicsMultiplatformBase

/**
 * @return [Resource.Failure.exception] or null.
 */
- (DynamicsMultiplatformKotlinException * _Nullable)exceptionOrNull __attribute__((swift_name("exceptionOrNull()")));

/**
 * @return [Resource.Success.result] or null.
 */
- (T _Nullable)getOrNull __attribute__((swift_name("getOrNull()")));

/**
 * @return [Resource.Success.result] or throw [Resource.Failure.exception].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (T _Nullable)getOrThrowAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getOrThrow()"))) __attribute__((swift_error(nonnull_error)));

/**
 * @return [Resource.Success] or throw [Resource.Failure.exception].
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (DynamicsMultiplatformResourceResourceSuccess<T> * _Nullable)getSuccessOrThrowAndReturnError:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getSuccessOrThrow()")));

/**
 * @return [Resource.Success.warning] or null.
 */
- (DynamicsMultiplatformKotlinException * _Nullable)warningOrNull __attribute__((swift_name("warningOrNull()")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_dbDatabase")))
@interface DynamicsMultiplatformDynamics_dbDatabase : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamics_dbDatabaseCompanion *companion __attribute__((swift_name("companion")));

/**
 * Deletes the active training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteActiveTrainingSessionWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteActiveTrainingSession(completionHandler:)")));

/**
 * Deletes all peripherals.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteAllPeripheralsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteAllPeripherals(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteAllThroughputTestsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteAllThroughputTests(completionHandler:)")));

/**
 * Deletes a peripheral for the given id.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deletePeripheralPeripheralId:(id)peripheralId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deletePeripheral(peripheralId:completionHandler:)")));

/**
 * Deletes a punch by [punchId] with all associated samples.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deletePunchPunchId:(id)punchId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deletePunch(punchId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteThroughputTestThroughputTestId:(id)throughputTestId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteThroughputTest(throughputTestId:completionHandler:)")));

/**
 * Deletes a session by [id].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)deleteTrainingSessionId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("deleteTrainingSession(id:completionHandler:)")));

/**
 * Finishes an active training session if there is even any.
 *
 * @return the [TrainingSessionId] of the finished active training session or null if there
 * wasn't any active training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)finishActiveTrainingSessionTimestamp:(DynamicsMultiplatformKotlinInstant *)timestamp completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("finishActiveTrainingSession(timestamp:completionHandler:)")));

/**
 * Currently only for testing purposes only!
 *
 * @return all glove pairs.
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)getAllGlovePairIds __attribute__((swift_name("getAllGlovePairIds()")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)getAllGlovePairs __attribute__((swift_name("getAllGlovePairs()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAllPunchesWithSamplesTrainingSessionId:(id)trainingSessionId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSArray<DynamicsMultiplatformPunchWithSamples *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAllPunchesWithSamples(trainingSessionId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAllThroughputTestEventsThroughputTestId:(id)throughputTestId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSArray<DynamicsMultiplatformThroughputTestEventDto *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAllThroughputTestEvents(throughputTestId:completionHandler:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)getAllThroughputTests __attribute__((swift_name("getAllThroughputTests()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFinishedTrainingSessionWithPunchIdsAndStatsId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformFinishedTrainingSessionWithPunchIdsAndStats *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFinishedTrainingSessionWithPunchIdsAndStats(id:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFinishedTrainingSessionWithStatsByIdId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformFinishedTrainingSessionWithStats *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFinishedTrainingSessionWithStatsById(id:completionHandler:)")));

/**
 * Currently only for testing purposes only!
 *
 * @return a [GlovePairDto].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getGlovePairByIdGlovePairId:(id)glovePairId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformGlovePairDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getGlovePairById(glovePairId:completionHandler:)")));

/**
 * Currently only for testing purposes only!
 *
 * @return a [GlovePairDto].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getGlovePairByPeripheralIdPeripheralId:(id)peripheralId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformGlovePairDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getGlovePairByPeripheralId(peripheralId:completionHandler:)")));

/**
 * Returns a peripheral for the given address.
 *
 * @param address
 * @return [Resource] with the peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPeripheralByAddressAddress:(NSString *)address completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPeripheralDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPeripheralByAddress(address:completionHandler:)")));

/**
 * Returns a peripheral for the given id.
 *
 * @param id
 * @return [Resource] with the peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPeripheralByIdId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPeripheralDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPeripheralById(id:completionHandler:)")));

/**
 * Returns all peripherals as a flow.
 *
 * @return [Flow] with the list of peripherals.
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)getPeripheralsAsFlow __attribute__((swift_name("getPeripheralsAsFlow()")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPunchPunchId:(id)punchId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPunch *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPunch(punchId:completionHandler:)")));

/**
 * Determines the punch index:
 * - Looks for the training session id.
 * - Selects all punch ids for the training session.
 * - Looks for the occurrence of [punchId] and returns the index.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPunchIndexPunchId:(id)punchId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPunchIndex(punchId:completionHandler:)")));

/**
 * The number of the punch is determined by the order of the [Punch.start_date_time], i.e.
 * the 5th punch 5th element in the list if the punches are sorted by [Punch.start_date_time]
 * ins ascending order.
 *
 * @return the number of the punch.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPunchNumberId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPunchNumber(id:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPunchWithRawDataPunchId:(id)punchId requireRawData:(BOOL)requireRawData completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPunchWithRawData *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPunchWithRawData(punchId:requireRawData:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPunchWithSamplesPunchId:(id)punchId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPunchWithSamples *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPunchWithSamples(punchId:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSideByPunchIdId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformSide *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSideByPunchId(id:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getThroughputTestByIdThroughputTestId:(id)throughputTestId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformThroughputTestDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getThroughputTestById(throughputTestId:completionHandler:)")));

/**
 * @note This method converts instances of DynamicsDatabaseException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (DynamicsMultiplatformThroughputTestDto * _Nullable)getThroughputTestByIdInternalThroughputTestId:(id)throughputTestId error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("getThroughputTestByIdInternal(throughputTestId:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionByIdId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformTrainingSessionWithTime *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionById(id:completionHandler:)")));

/**
 * @return the dynamics settings of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionDynamicsSettingsId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionDynamicsSettings(id:completionHandler:)")));

/**
 * @return the firmware device info of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionFirmwareDeviceInfoId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDynamics_dbGloveModeGenericNullable<NSString *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionFirmwareDeviceInfo(id:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionIdByPunchId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionIdByPunch(id:completionHandler:)")));

/**
 * @return the impact config of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionImpactConfigId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDynamics_dbGloveModeGenericNullable<NSString *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionImpactConfig(id:completionHandler:)")));

/**
 * @return the impact config of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTrainingSessionImpactConfigByPunchId:(id)id completionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTrainingSessionImpactConfigByPunch(id:completionHandler:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)getTrainingSessionStatsTrainingSessionId:(id)trainingSessionId __attribute__((swift_name("getTrainingSessionStats(trainingSessionId:)")));

/**
 * Inserts a new training session, the following list of constraints will apply:
 * - [input]'s [TrainingSessionState] must not be [TrainingSessionState.FINISHED].
 * - a single [GlovePairDto] must be available to which the session is associated.
 * - any other training session must be in the state [TrainingSessionState.FINISHED].
 *
 * Additionally, if [input]'s [TrainingSessionState] is [TrainingSessionState.PAUSED] or
 * [TrainingSessionState.RESUMED], then an initial [TrainingSessionEvent] is also added.
 *
 * [TrainingSessionState.INIT] can be used to prepare an upcoming session, which might be
 * useful if the start is delayed, but it should not count to the duration.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)initializeTrainingSessionInput:(DynamicsMultiplatformTrainingSessionInput *)input completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformTrainingSessionWithTime *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("initializeTrainingSession(input:completionHandler:)")));

/**
 * Inserts the [peripheralDto] if it's not existing or updates it if the serial number already
 * exists.
 *
 * @param peripheralDto the peripheral to insert or update.
 * @param glovePairName the peripheral's pair name. this param is ignored if the glove pair
 * already exists.
 * @param explicitSideUponInsert the side of the peripheral. This is only used if there is no peripheral yet. If
 * this is null, the [INITIAL_SIDE] will be used.
 *
 * @return [Resource] with the peripheral inserted or updated.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)insertOrUpdatePeripheralPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto explicitSideUponInsert:(DynamicsMultiplatformSide * _Nullable)explicitSideUponInsert glovePairName:(NSString * _Nullable)glovePairName completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPeripheralDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("insertOrUpdatePeripheral(peripheralDto:explicitSideUponInsert:glovePairName:completionHandler:)")));

/**
 * Inserts a punch with samples.
 *
 * A punch can be only inserted with the following constraints:
 * - [Punch.start_date_time] must be within a resumed time range, if not then only if a session
 * can be successfully auto-resumed, the punch will be added + the training session resumed.
 * - the associated training session must not be finished.
 *
 * @param peripheral from where the punch data originates.
 * @param trainingSessionId to which training session it belongs, if null, then
 * [getActiveTrainingSession] is used instead.
 * @param punchWithSamples the computed punch data values with its detailed samples.
 * @param algorithmId the id of the algorithm that has been used to compute the variables.
 * @param basePressure the atmospheric base pressure in [Pascal] that has been used for
 * calculating the increase in pressure.
 * @param rawDataContent the raw data content.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)insertPunchPeripheral:(DynamicsMultiplatformPeripheralDto *)peripheral trainingSessionId:(id _Nullable)trainingSessionId punchWithSamples:(DynamicsMultiplatformPunchWithSamples *)punchWithSamples algorithmId:(NSString *)algorithmId basePressure:(id _Nullable)basePressure rawDataContent:(DynamicsMultiplatformKotlinByteArray *)rawDataContent completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("insertPunch(peripheral:trainingSessionId:punchWithSamples:algorithmId:basePressure:rawDataContent:completionHandler:)")));

/**
 * Throughput test
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)insertThroughputTestPeripheralId:(id)peripheralId throughputTest:(DynamicsMultiplatformThroughputTest *)throughputTest completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("insertThroughputTest(peripheralId:throughputTest:completionHandler:)")));

/**
 * @return a [Flow] with [Boolean] to indicate if a training session is currently active.
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)isTrainingSessionActive __attribute__((swift_name("isTrainingSessionActive()")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeActiveTrainingSession __attribute__((swift_name("observeActiveTrainingSession()")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeFinishedTrainingSessionId:(id)id __attribute__((swift_name("observeFinishedTrainingSession(id:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeFinishedTrainingSessions __attribute__((swift_name("observeFinishedTrainingSessions()")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeTrainingSessionTrainingSessionId:(id)trainingSessionId __attribute__((swift_name("observeTrainingSession(trainingSessionId:)")));

/**
 * Transitions an active training session in state [TrainingSessionState.INIT] to
 * [TrainingSessionState.READY].
 * - Requires a body profile to be set.
 * - Requires the [type] of the current session to be not set yet.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readyTrainingSessionStateType:(DynamicsMultiplatformTrainingSessionSensorType *)type completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("readyTrainingSessionState(type:completionHandler:)")));

/**
 * Swaps the side of the peripheral with the given id. If there are 2 peripherals, both will be swapped.
 *
 * @param peripheralId the peripheral id.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)swapSidePeripheralId:(id)peripheralId completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("swapSide(peripheralId:completionHandler:)")));

/**
 * Toggles the [TrainingSession.state] to the "next" obvious state.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)toggleTrainingSessionStateInput:(DynamicsMultiplatformActiveTrainingSessionInputSecondary *)input completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toggleTrainingSessionState(input:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateBondStatePeripheralId:(id)peripheralId bondState:(DynamicsMultiplatformBondState *)bondState completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateBondState(peripheralId:bondState:completionHandler:)")));

/**
 * Updates the device info of a Peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateDeviceInfoPeripheralId:(id)peripheralId extendedDeviceInfo:(DynamicsMultiplatformExtendedDeviceInfo *)extendedDeviceInfo completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateDeviceInfo(peripheralId:extendedDeviceInfo:completionHandler:)")));

/**
 * Updates the firmware revision of a Peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateDeviceNamePeripheralId:(id)peripheralId name:(NSString *)name completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateDeviceName(peripheralId:name:completionHandler:)")));

/**
 * Updates the firmware revision of a Peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateFirmwareRevisionPeripheralId:(id)peripheralId firmwareRevision:(NSString *)firmwareRevision completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateFirmwareRevision(peripheralId:firmwareRevision:completionHandler:)")));

/**
 * Updates the name of the glove pair.
 *
 * @param peripheralId the id of the peripheral which is associated with the glove pair.
 * @param name the name of the glove pair.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateNamePeripheralId:(id)peripheralId name:(NSString *)name completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateName(peripheralId:name:completionHandler:)")));

/**
 * Updates the name of a glove pair.
 *
 * @param glovePairId the id of the glove pair.
 * @param name the name of the glove pair.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateNameGlovePairId:(id)glovePairId name:(NSString *)name completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateName(glovePairId:name:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateThroughputTestInput:(DynamicsMultiplatformThroughputTestInput *)input completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformThroughputTestDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateThroughputTest(input:completionHandler:)")));

/**
 * Updates the training session based on [input].
 *
 * - If the session transitions from [TrainingSessionState.INIT] to
 * [TrainingSessionState.FINISHED], then the session will be deleted.
 * - A session may always transition to [TrainingSessionState.FINISHED].
 * - A session cannot be updated with the same state twice.
 * - A session in the state [TrainingSessionState.FINISHED] can no longer be modified.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateTrainingSessionInput:(DynamicsMultiplatformTrainingSessionInput *)input completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateTrainingSession(input:completionHandler:)")));

/**
 * Updates the dynamics settings for a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateTrainingSessionDynamicsSettingsId:(id)id settings:(NSString *)settings completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateTrainingSessionDynamicsSettings(id:settings:completionHandler:)")));

/**
 * Updates the firmware device info json of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateTrainingSessionFirmwareDeviceInfoId:(id)id side:(DynamicsMultiplatformSide *)side firmwareDeviceInfoJson:(NSString *)firmwareDeviceInfoJson completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateTrainingSessionFirmwareDeviceInfo(id:side:firmwareDeviceInfoJson:completionHandler:)")));

/**
 * Updates the impact config json of a training session.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)updateTrainingSessionImpactConfigId:(id)id side:(DynamicsMultiplatformSide *)side impactConfig:(NSString *)impactConfig completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("updateTrainingSessionImpactConfig(id:side:impactConfig:completionHandler:)")));
@property (readonly) id<DynamicsMultiplatformDynamics_dbBodyProfileDao> bodyProfileDao __attribute__((swift_name("bodyProfileDao")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_bleGloveManager")))
@interface DynamicsMultiplatformDynamics_bleGloveManager : DynamicsMultiplatformBase
- (instancetype)initWithPeripheralAddresses:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)peripheralAddresses testOptions:(DynamicsMultiplatformDynamicsTestOptions *)testOptions gloveOptions:(DynamicsMultiplatformDynamics_bleGloveOptions *)gloveOptions __attribute__((swift_name("init(peripheralAddresses:testOptions:gloveOptions:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamics_bleGloveManagerCompanion *companion __attribute__((swift_name("companion")));

/**
 * Pre-Condition: ensure that [bleAddress] is no longer present in [peripheralAddressState].
 *
 * Performs a cleanup of the glove:
 * - Removes the BP manually from the underlying BLE layer (if possible).
 * - Clears the bonding based on the current available addresses.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)cleanUpGloveBleAddress:(id)bleAddress completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("cleanUpGlove(bleAddress:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)connectAndSaveNearbyPeripheral:(DynamicsMultiplatformNearbyPeripheral *)nearbyPeripheral completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPeripheralDto *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("connectAndSave(nearbyPeripheral:completionHandler:)")));

/** Disconnects from a peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectBleAddress:(id)bleAddress completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("disconnect(bleAddress:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectAllWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("disconnectAll(completionHandler:)")));

/** Gets the [CommonDevice] with the given [BleAddress].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCommonDeviceBleAddress:(id)bleAddress completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id<DynamicsMultiplatformCommonDevice>> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCommonDevice(bleAddress:completionHandler:)")));
- (DynamicsMultiplatformResourceResource<id<DynamicsMultiplatformDynamics_bleGlovePeripheral>> *)getGloveId:(id)id __attribute__((swift_name("getGlove(id:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeAccelerationStreamPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeAccelerationStream(peripheralDto:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeContinuousDataPacketsPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeContinuousDataPackets(peripheralDto:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeExtendedDeviceInfoPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeExtendedDeviceInfo(peripheralDto:)")));

/** A flow emitting the [PeripheralData] of a peripheral. */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeGlovePeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeGlove(peripheralDto:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeImpactConfigsPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeImpactConfigs(peripheralDto:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeImpactsPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeImpacts(peripheralDto:)")));

/** A flow emitting the [PeripheralState] of a peripheral. */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observePeripheralStatePeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observePeripheralState(peripheralDto:)")));

/**
 * While a subscription is active, rapid baro readouts will be performed (every [interval]).
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeRapidBaroReadoutsPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto interval:(int64_t)interval __attribute__((swift_name("observeRapidBaroReadouts(peripheralDto:interval:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeSuccessImpactsPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeSuccessImpacts(peripheralDto:)")));
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeThroughputTestPeripheralDto:(DynamicsMultiplatformPeripheralDto *)peripheralDto __attribute__((swift_name("observeThroughputTest(peripheralDto:)")));

/**
 * A flow emitting the nearby peripherals.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> nearbyPeripherals __attribute__((swift_name("nearbyPeripherals")));

/**
 * A flow of the current scanner state.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> scannerState __attribute__((swift_name("scannerState")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreAdvertisement")))
@interface DynamicsMultiplatformCoreAdvertisement : DynamicsMultiplatformBase
- (instancetype)initWithRssi:(int32_t)rssi data:(NSDictionary<NSString *, id> *)data cbPeripheral:(CBPeripheral *)cbPeripheral __attribute__((swift_name("init(rssi:data:cbPeripheral:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformCoreAdvertisement *)doCopyRssi:(int32_t)rssi data:(NSDictionary<NSString *, id> *)data cbPeripheral:(CBPeripheral *)cbPeripheral __attribute__((swift_name("doCopy(rssi:data:cbPeripheral:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (DynamicsMultiplatformKotlinByteArray * _Nullable)manufacturerDataCompanyIdentifierCode:(int32_t)companyIdentifierCode __attribute__((swift_name("manufacturerData(companyIdentifierCode:)")));
- (NSData * _Nullable)manufacturerDataAsNSDataCompanyIdentifierCode:(int32_t)companyIdentifierCode __attribute__((swift_name("manufacturerDataAsNSData(companyIdentifierCode:)")));
- (DynamicsMultiplatformKotlinByteArray * _Nullable)serviceDataUuid:(DynamicsMultiplatformKotlinUuid *)uuid __attribute__((swift_name("serviceData(uuid:)")));
- (NSData * _Nullable)serviceDataAsNSDataUuid:(DynamicsMultiplatformKotlinUuid *)uuid __attribute__((swift_name("serviceDataAsNSData(uuid:)")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSDictionary<NSString *, id> *data __attribute__((swift_name("data")));
@property (readonly) DynamicsMultiplatformKotlinUuid *identifier __attribute__((swift_name("identifier")));

/** https://developer.apple.com/documentation/corebluetooth/cbadvertisementdataisconnectable */
@property (readonly) DynamicsMultiplatformBoolean * _Nullable isConnectable __attribute__((swift_name("isConnectable")));
@property (readonly) DynamicsMultiplatformCoreManufacturerData * _Nullable manufacturerData __attribute__((swift_name("manufacturerData")));
@property (readonly) NSData * _Nullable manufacturerDataAsNSData __attribute__((swift_name("manufacturerDataAsNSData")));
@property (readonly) NSString * _Nullable name __attribute__((swift_name("name")));

/**
 * The [peripheralName] property may contain either advertising, or GAP name, dependent on various conditions:
 *
 * | Condition(s)                               | `gapName` value                                      |
 * |--------------------------------------------|------------------------------------------------------|
 * | Initial peripheral discovery (active scan) | `advertisementData(CBAdvertisementDataLocalNameKey)` |
 * | Connected to peripheral                    | GAP name                                             |
 * | Subsequent discovery (disconnected)        | GAP name (from cache)                                |
 *
 * https://developer.apple.com/forums/thread/72343
 */
@property (readonly) NSString * _Nullable peripheralName __attribute__((swift_name("peripheralName")));
@property (readonly) int32_t rssi __attribute__((swift_name("rssi")));
@property (readonly) DynamicsMultiplatformInt * _Nullable txPower __attribute__((swift_name("txPower")));
@property (readonly) NSArray<DynamicsMultiplatformKotlinUuid *> *uuids __attribute__((swift_name("uuids")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CorePermissionState")))
@interface DynamicsMultiplatformCorePermissionState : DynamicsMultiplatformBase
- (instancetype)initWithCbManagerAuthorization:(int64_t)cbManagerAuthorization __attribute__((swift_name("init(cbManagerAuthorization:)"))) __attribute__((objc_designated_initializer));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t cbManagerAuthorization __attribute__((swift_name("cbManagerAuthorization")));
@end

__attribute__((swift_name("CoreBluetoothState")))
@interface DynamicsMultiplatformCoreBluetoothState : DynamicsMultiplatformBase
- (NSString *)description __attribute__((swift_name("description()")));
@end


/**
 * Represents bond states which may vary on each platform:
 * - android: Every bond state defined in this class may be triggered, except for [BondLostOnPeripheral] as this
 * may already be handled by the system which would then automatically result in [BondNone].
 * - iOS: Bond state retrieval is not explicitly possible, however some assumptions can be made if one may assume that
 * bonding is required but some error codes are returned that indicate a bonding error. Therefore, this state will
 * very likely remain in [Unknown] but in some cases it may indicate [BondLostOnPeripheral].
 */
__attribute__((swift_name("CoreBondState")))
@interface DynamicsMultiplatformCoreBondState : DynamicsMultiplatformBase
@end


/**
 * A wrapper class for holding a [service] UUID and a [characteristic] UUID which can be used to address a specific
 * bluetooth LE Api.
 * - [alias] is an optional string property for which a human-readable name can be set to reduce verbosity in the logs.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ble_multiplex_uuidBleUuid")))
@interface DynamicsMultiplatformBle_multiplex_uuidBleUuid : DynamicsMultiplatformBase
- (instancetype)initWithService:(DynamicsMultiplatformKotlinUuid *)service characteristic:(DynamicsMultiplatformKotlinUuid *)characteristic alias:(NSString * _Nullable)alias __attribute__((swift_name("init(service:characteristic:alias:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformBle_multiplex_uuidBleUuid *)doCopyService:(DynamicsMultiplatformKotlinUuid *)service characteristic:(DynamicsMultiplatformKotlinUuid *)characteristic alias:(NSString * _Nullable)alias __attribute__((swift_name("doCopy(service:characteristic:alias:)")));

/**
 * A wrapper class for holding a [service] UUID and a [characteristic] UUID which can be used to address a specific
 * bluetooth LE Api.
 * - [alias] is an optional string property for which a human-readable name can be set to reduce verbosity in the logs.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * A wrapper class for holding a [service] UUID and a [characteristic] UUID which can be used to address a specific
 * bluetooth LE Api.
 * - [alias] is an optional string property for which a human-readable name can be set to reduce verbosity in the logs.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) NSString * _Nullable alias __attribute__((swift_name("alias")));
@property (readonly) DynamicsMultiplatformKotlinUuid *characteristic __attribute__((swift_name("characteristic")));
@property (readonly) DynamicsMultiplatformKotlinUuid *service __attribute__((swift_name("service")));
@property (readonly) NSString *shortString __attribute__((swift_name("shortString")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinPair")))
@interface DynamicsMultiplatformKotlinPair<__covariant A, __covariant B> : DynamicsMultiplatformBase
- (instancetype)initWithFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("init(first:second:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformKotlinPair<A, B> *)doCopyFirst:(A _Nullable)first second:(B _Nullable)second __attribute__((swift_name("doCopy(first:second:)")));
- (BOOL)equalsOther:(id _Nullable)other __attribute__((swift_name("equals(other:)")));
- (int32_t)hashCode __attribute__((swift_name("hashCode()")));
- (NSString *)toString __attribute__((swift_name("toString()")));
@property (readonly) A _Nullable first __attribute__((swift_name("first")));
@property (readonly) B _Nullable second __attribute__((swift_name("second")));
@end

__attribute__((swift_name("KotlinIterator")))
@protocol DynamicsMultiplatformKotlinIterator
@required
- (BOOL)hasNext __attribute__((swift_name("hasNext()")));
- (id _Nullable)next __attribute__((swift_name("next()")));
@end

__attribute__((swift_name("KotlinAppendable")))
@protocol DynamicsMultiplatformKotlinAppendable
@required

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<DynamicsMultiplatformKotlinAppendable>)appendValue:(unichar)value __attribute__((swift_name("append(value:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<DynamicsMultiplatformKotlinAppendable>)appendValue_:(id _Nullable)value __attribute__((swift_name("append(value_:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (id<DynamicsMultiplatformKotlinAppendable>)appendValue:(id _Nullable)value startIndex:(int32_t)startIndex endIndex:(int32_t)endIndex __attribute__((swift_name("append(value:startIndex:endIndex:)")));
@end


/**
 * Encoder is a core serialization primitive that encapsulates the knowledge of the underlying
 * format and its storage, exposing only structural methods to the serializer, making it completely
 * format-agnostic. Serialization process transforms a single value into the sequence of its
 * primitive elements, also called its serial form, while encoding transforms these primitive elements into an actual
 * format representation: JSON string, ProtoBuf ByteArray, in-memory map representation etc.
 *
 * Encoder provides high-level API that operates with basic primitive types, collections
 * and nested structures. Internally, encoder represents output storage and operates with its state
 * and lower level format-specific details.
 *
 * To be more specific, serialization transforms a value into a sequence of "here is an int, here is
 * a double, here a list of strings and here is another object that is a nested int", while encoding
 * transforms this sequence into a format-specific commands such as "insert opening curly bracket
 * for a nested object start, insert a name of the value, and the value separated with colon for an int etc."
 *
 * The symmetric interface for the deserialization process is [Decoder].
 *
 * ### Serialization. Primitives
 *
 * If a class is represented as a single [primitive][PrimitiveKind] value in its serialized form,
 * then one of the `encode*` methods (e.g. [encodeInt]) can be used directly.
 *
 * ### Serialization. Structured types.
 *
 * If a class is represented as a structure or has multiple values in its serialized form,
 * `encode*` methods are not that helpful, because they do not allow working with collection types or establish structure boundaries.
 * All these capabilities are delegated to the [CompositeEncoder] interface with a more specific API surface.
 * To denote a structure start, [beginStructure] should be used.
 * ```
 * // Denote the structure start,
 * val composite = encoder.beginStructure(descriptor)
 * // Encoding all elements within the structure using 'composite'
 * ...
 * // Denote the structure end
 * composite.endStructure(descriptor)
 * ```
 *
 * E.g. if the encoder belongs to JSON format, then [beginStructure] will write an opening bracket
 * (`{` or `[`, depending on the descriptor kind), returning the [CompositeEncoder] that is aware of colon separator,
 * that should be appended between each key-value pair, whilst [CompositeEncoder.endStructure] will write a closing bracket.
 *
 * ### Exception guarantees
 *
 * For the regular exceptions, such as invalid input, conflicting serial names,
 * [SerializationException] can be thrown by any encoder methods.
 * It is recommended to declare a format-specific subclass of [SerializationException] and throw it.
 *
 * ### Exception safety
 *
 * In general, catching [SerializationException] from any of `encode*` methods is not allowed and produces unspecified behaviour.
 * After thrown exception, the current encoder is left in an arbitrary state, no longer suitable for further encoding.
 *
 * ### Format encapsulation
 *
 * For example, for the following serializer:
 * ```
 * class StringHolder(val stringValue: String)
 *
 * object StringPairDeserializer : SerializationStrategy<StringHolder> {
 *    override val descriptor = ...
 *
 *    override fun serializer(encoder: Encoder, value: StringHolder) {
 *        // Denotes start of the structure, StringHolder is not a "plain" data type
 *        val composite = encoder.beginStructure(descriptor)
 *        // Encode the nested string value
 *        composite.encodeStringElement(descriptor, index = 0)
 *        // Denotes end of the structure
 *        composite.endStructure(descriptor)
 *    }
 * }
 * ```
 *
 * This serializer does not know anything about the underlying storage and will work with any properly-implemented encoder.
 * JSON, for example, writes an opening bracket `{` during the `beginStructure` call, writes `stringValue` key along
 * with its value in `encodeStringElement` and writes the closing bracket `}` during the `endStructure`.
 * XML would do roughly the same, but with different separators and structures, while ProtoBuf
 * machinery could be completely different.
 * In any case, all these parsing details are encapsulated by an encoder.
 *
 * ### Encoder implementation.
 *
 * While being strictly typed, an underlying format can transform actual types in the way it wants.
 * For example, a format can support only string types and encode/decode all primitives in a string form:
 * ```
 * StringFormatEncoder : Encoder {
 *
 *     ...
 *     override fun encodeDouble(value: Double) = encodeString(value.toString())
 *     override fun encodeInt(value: Int) = encodeString(value.toString())
 *     ...
 * }
 * ```
 *
 * ### Not stable for inheritance
 *
 * `Encoder` interface is not stable for inheritance in 3rd party libraries, as new methods
 * might be added to this interface or contracts of the existing methods can be changed.
 */
__attribute__((swift_name("Kotlinx_serialization_coreEncoder")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreEncoder
@required

/**
 * Encodes the beginning of the collection with size [collectionSize] and the given serializer of its type parameters.
 * This method has to be implemented only if you need to know collection size in advance, otherwise, [beginStructure] can be used.
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreCompositeEncoder>)beginCollectionDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor collectionSize:(int32_t)collectionSize __attribute__((swift_name("beginCollection(descriptor:collectionSize:)")));

/**
 * Encodes the beginning of the nested structure in a serialized form
 * and returns [CompositeDecoder] responsible for encoding this very structure.
 * E.g the hierarchy:
 * ```
 * class StringHolder(val stringValue: String)
 * class Holder(val stringHolder: StringHolder)
 * ```
 *
 * with the following serialized form in JSON:
 * ```
 * {
 *   "stringHolder" : { "stringValue": "value" }
 * }
 * ```
 *
 * will be roughly represented as the following sequence of calls:
 * ```
 * // Holder serializer
 * fun serialize(encoder: Encoder, value: Holder) {
 *     val composite = encoder.beginStructure(descriptor) // the very first opening bracket '{'
 *     composite.encodeSerializableElement(descriptor, 0, value.stringHolder) // Serialize nested StringHolder
 *     composite.endStructure(descriptor) // The very last closing bracket
 * }
 *
 * // StringHolder serializer
 * fun serialize(encoder: Encoder, value: StringHolder) {
 *     val composite = encoder.beginStructure(descriptor) // One more '{' when the key "stringHolder" is already written
 *     composite.encodeStringElement(descriptor, 0, value.stringValue) // Serialize actual value
 *     composite.endStructure(descriptor) // Closing bracket
 * }
 * ```
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreCompositeEncoder>)beginStructureDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));

/**
 * Encodes a boolean value.
 * Corresponding kind is [PrimitiveKind.BOOLEAN].
 */
- (void)encodeBooleanValue:(BOOL)value __attribute__((swift_name("encodeBoolean(value:)")));

/**
 * Encodes a single byte value.
 * Corresponding kind is [PrimitiveKind.BYTE].
 */
- (void)encodeByteValue:(int8_t)value __attribute__((swift_name("encodeByte(value:)")));

/**
 * Encodes a 16-bit unicode character value.
 * Corresponding kind is [PrimitiveKind.CHAR].
 */
- (void)encodeCharValue:(unichar)value __attribute__((swift_name("encodeChar(value:)")));

/**
 * Encodes a 64-bit IEEE 754 floating point value.
 * Corresponding kind is [PrimitiveKind.DOUBLE].
 */
- (void)encodeDoubleValue:(double)value __attribute__((swift_name("encodeDouble(value:)")));

/**
 * Encodes a enum value that is stored at the [index] in [enumDescriptor] elements collection.
 * Corresponding kind is [SerialKind.ENUM].
 *
 * E.g. for the enum `enum class Letters { A, B, C, D }` and
 * serializable value "C", [encodeEnum] method should be called with `2` as am index.
 *
 * This method does not imply any restrictions on the output format,
 * the format is free to store the enum by its name, index, ordinal or any other
 */
- (void)encodeEnumEnumDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)enumDescriptor index:(int32_t)index __attribute__((swift_name("encodeEnum(enumDescriptor:index:)")));

/**
 * Encodes a 32-bit IEEE 754 floating point value.
 * Corresponding kind is [PrimitiveKind.FLOAT].
 */
- (void)encodeFloatValue:(float)value __attribute__((swift_name("encodeFloat(value:)")));

/**
 * Returns [Encoder] for encoding an underlying type of a value class in an inline manner.
 * [descriptor] describes a serializable value class.
 *
 * Namely, for the `@Serializable @JvmInline value class MyInt(val my: Int)`,
 * the following sequence is used:
 * ```
 * thisEncoder.encodeInline(MyInt.serializer().descriptor).encodeInt(my)
 * ```
 *
 * Current encoder may return any other instance of [Encoder] class, depending on the provided [descriptor].
 * For example, when this function is called on Json encoder with `UInt.serializer().descriptor`, the returned encoder is able
 * to encode unsigned integers.
 *
 * Note that this function returns [Encoder] instead of the [CompositeEncoder]
 * because value classes always have the single property.
 * Calling [Encoder.beginStructure] on returned instance leads to an unspecified behavior and, in general, is prohibited.
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encodeInlineDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("encodeInline(descriptor:)")));

/**
 * Encodes a 32-bit integer value.
 * Corresponding kind is [PrimitiveKind.INT].
 */
- (void)encodeIntValue:(int32_t)value __attribute__((swift_name("encodeInt(value:)")));

/**
 * Encodes a 64-bit integer value.
 * Corresponding kind is [PrimitiveKind.LONG].
 */
- (void)encodeLongValue:(int64_t)value __attribute__((swift_name("encodeLong(value:)")));

/**
 * Notifies the encoder that value of a nullable type that is
 * being serialized is not null. It should be called before writing a non-null value
 * of nullable type:
 * ```
 * // Could be String? serialize method
 * if (value != null) {
 *     encoder.encodeNotNullMark()
 *     encoder.encodeStringValue(value)
 * } else {
 *     encoder.encodeNull()
 * }
 * ```
 *
 * This method has a use in highly-performant binary formats and can
 * be safely ignore by most of the regular formats.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNotNullMark __attribute__((swift_name("encodeNotNullMark()")));

/**
 * Encodes `null` value.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNull __attribute__((swift_name("encodeNull()")));

/**
 * Encodes the nullable [value] of type [T] by delegating the encoding process to the given [serializer].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableValueSerializer:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableValue(serializer:value:)")));

/**
 * Encodes the [value] of type [T] by delegating the encoding process to the given [serializer].
 * For example, `encodeInt` call is equivalent to delegating integer encoding to [Int.serializer][Int.Companion.serializer]:
 * `encodeSerializableValue(Int.serializer())`
 */
- (void)encodeSerializableValueSerializer:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableValue(serializer:value:)")));

/**
 * Encodes a 16-bit short value.
 * Corresponding kind is [PrimitiveKind.SHORT].
 */
- (void)encodeShortValue:(int16_t)value __attribute__((swift_name("encodeShort(value:)")));

/**
 * Encodes a string value.
 * Corresponding kind is [PrimitiveKind.STRING].
 */
- (void)encodeStringValue:(NSString *)value __attribute__((swift_name("encodeString(value:)")));

/**
 * Context of the current serialization process, including contextual and polymorphic serialization and,
 * potentially, a format-specific configuration.
 */
@property (readonly) DynamicsMultiplatformKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * Serial descriptor is an inherent property of [KSerializer] that describes the structure of the serializable type.
 * The structure of the serializable type is not only the characteristic of the type itself, but also of the serializer as well,
 * meaning that one type can have multiple descriptors that have completely different structures.
 *
 * For example, the class `class Color(val rgb: Int)` can have multiple serializable representations,
 * such as `{"rgb": 255}`, `"#0000FF"`, `[0, 0, 255]` and `{"red": 0, "green": 0, "blue": 255}`.
 * Representations are determined by serializers, and each such serializer has its own descriptor that identifies
 * each structure in a distinguishable and format-agnostic manner.
 *
 * ### Structure
 * Serial descriptor is identified by its [name][serialName] and consists of a kind, potentially empty set of
 * children elements, and additional metadata.
 *
 * * [serialName] uniquely identifies the descriptor (and the corresponding serializer) for non-generic types.
 *   For generic types, the actual type substitution is omitted from the string representation, and the name
 *   identifies the family of the serializers without type substitutions. However, type substitution is accounted for
 *   in [equals] and [hashCode] operations, meaning that descriptors of generic classes with the same name but different type
 *   arguments are not equal to each other.
 *   [serialName] is typically used to specify the type of the target class during serialization of polymorphic and sealed
 *   classes, for observability and diagnostics.
 * * [Kind][SerialKind] defines what this descriptor represents: primitive, enum, object, collection, etc.
 * * Children elements are represented as serial descriptors as well and define the structure of the type's elements.
 * * Metadata carries additional information, such as [nullability][nullable], [optionality][isElementOptional]
 *   and [serial annotations][getElementAnnotations].
 *
 * ### Usages
 * There are two general usages of the descriptors: THE serialization process and serialization introspection.
 *
 * #### Serialization
 * Serial descriptor is used as a bridge between decoders/encoders and serializers.
 * When asking for a next element, the serializer provides an expected descriptor to the decoder, and,
 * based on the descriptor content, the decoder decides how to parse its input.
 * In JSON, for example, when the encoder is asked to encode the next element and this element
 * is a subtype of [List], the encoder receives a descriptor with [StructureKind.LIST] and, based on that,
 * first writes an opening square bracket before writing the content of the list.
 *
 * Serial descriptor _encapsulates_ the structure of the data, so serializers can be free from
 * format-specific details. `ListSerializer` knows nothing about JSON and square brackets, providing
 * only the structure of the data and delegating encoding decision to the format itself.
 *
 * #### Introspection
 * Another usage of a serial descriptor is type introspection without its serialization.
 * Introspection can be used to check whether the given serializable class complies the
 * corresponding scheme and to generate JSON or ProtoBuf schema from the given class.
 *
 * ### Indices
 * Serial descriptor API operates with children indices.
 * For the fixed-size structures, such as regular classes, index is represented by a value in
 * the range from zero to [elementsCount] and represent and index of the property in this class.
 * Consequently, primitives do not have children and their element count is zero.
 *
 * For collections and maps indices do not have a fixed bound. Regular collections descriptors usually
 * have one element (`T`, maps have two, one for keys and one for values), but potentially unlimited
 * number of actual children values. Valid indices range is not known statically,
 * and implementations of such a descriptor should provide consistent and unbounded names and indices.
 *
 * In practice, for regular classes it is allowed to invoke `getElement*(index)` methods
 * with an index from `0` to [elementsCount] range and the element at the particular index corresponds to the
 * serializable property at the given position.
 * For collections and maps, index parameter for `getElement*(index)` methods is effectively bounded
 * by the maximal number of collection/map elements.
 *
 * ### Thread-safety and mutability
 * Serial descriptor implementation should be immutable and, thus, thread-safe.
 *
 * ### Equality and caching
 * Serial descriptor can be used as a unique identifier for format-specific data or schemas and
 * this implies the following restrictions on its `equals` and `hashCode`:
 *
 * An [equals] implementation should use both [serialName] and elements structure.
 * Comparing [elementDescriptors] directly is discouraged,
 * because it may cause a stack overflow error, e.g., if a serializable class `T` contains elements of type `T`.
 * To avoid it, a serial descriptor implementation should compare only descriptors
 * of class' type parameters, in a way that `serializer<Box<Int>>().descriptor != serializer<Box<String>>().descriptor`.
 * If type parameters are equal, descriptor structure should be compared by using children elements
 * descriptors' [serialName]s, which correspond to class names
 * (do not confuse with elements' own names, which correspond to properties' names); and/or other [SerialDescriptor]
 * properties, such as [kind].
 * An example of [equals] implementation:
 * ```
 * if (this === other) return true
 * if (other::class != this::class) return false
 * if (serialName != other.serialName) return false
 * if (!typeParametersAreEqual(other)) return false
 * if (this.elementDescriptors().map { it.serialName } != other.elementDescriptors().map { it.serialName }) return false
 * return true
 * ```
 *
 * [hashCode] implementation should use the same properties for computing the result.
 *
 * ### User-defined serial descriptors
 * The best way to define a custom descriptor is to use [buildClassSerialDescriptor] builder function, where
 * for each serializable property the corresponding element is declared.
 *
 * Example:
 * ```
 * // Class with custom serializer and custom serial descriptor
 * class Data(
 *     val intField: Int, // This field is ignored by custom serializer
 *     val longField: Long, // This field is written as long, but in serialized form is named as "_longField"
 *     val stringList: List<String> // This field is written as regular list of strings
 * )
 *
 * // Descriptor for such class:
 * buildClassSerialDescriptor("my.package.Data") {
 *     // intField is deliberately ignored by serializer -- not present in the descriptor as well
 *     element<Long>("_longField") // longField is named as _longField
 *     element("stringField", listSerialDescriptor<String>())
 * }
 *
 * // Example of 'serialize' function for such descriptor
 * override fun serialize(encoder: Encoder, value: Data) {
 *     encoder.encodeStructure(descriptor) {
 *         encodeLongElement(descriptor, 0, value.longField) // Will be written as "_longField" because descriptor's child at index 0 says so
 *         encodeSerializableElement(descriptor, 1, ListSerializer(String.serializer()), value.stringList)
 *     }
 * }
 * ```
 *
 * For classes that are represented as a single primitive value, [PrimitiveSerialDescriptor] builder function can be used instead.
 *
 * ### Consistency violations
 * An implementation of [SerialDescriptor] should be consistent with the implementation of the corresponding [KSerializer].
 * Yet it is not type-checked statically, thus making it possible to declare a non-consistent implementation of descriptor and serializer.
 * In such cases, the behavior of an underlying format is unspecified and may lead to both runtime errors and encoding of
 * corrupted data that is impossible to decode back.
 *
 * ### Not for implementation
 *
 * `SerialDescriptor` interface should not be implemented in 3rd party libraries, as new methods
 * might be added to this interface when kotlinx.serialization adds support for new Kotlin features.
 * This interface is safe to use and construct via [buildClassSerialDescriptor], [PrimitiveSerialDescriptor], and `SerialDescriptor` factory function.
 *
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/serialization/SealedSerializationApi)])
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerialDescriptor")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor
@required

/**
 * Returns serial annotations of the child element at the given [index].
 * This method differs from `getElementDescriptor(index).annotations` by reporting only
 * element-specific annotations:
 * ```
 * @Serializable
 * @OnClassSerialAnnotation
 * class Nested(...)
 *
 * @Serializable
 * class Outer(@OnPropertySerialAnnotation val nested: Nested)
 *
 * val outerDescriptor = Outer.serializer().descriptor
 *
 * outerDescriptor.getElementAnnotations(0) // Returns [@OnPropertySerialAnnotation]
 * outerDescriptor.getElementDescriptor(0).annotations // Returns [@OnClassSerialAnnotation]
 * ```
 * Only annotations marked with [SerialInfo] are added to the resulting list.
 *
 * @throws IndexOutOfBoundsException for an illegal [index] values.
 * @throws IllegalStateException if the current descriptor does not support children elements (e.g. is a primitive).
 */
- (NSArray<id<DynamicsMultiplatformKotlinAnnotation>> *)getElementAnnotationsIndex:(int32_t)index __attribute__((swift_name("getElementAnnotations(index:)")));

/**
 * Retrieves the descriptor of the child element for the given [index].
 * For the property of type `T` on the position `i`, `getElementDescriptor(i)` yields the same result
 * as for `T.serializer().descriptor`, if the serializer for this property is not explicitly overridden
 * with `@Serializable(with = ...`)`, [Polymorphic] or [Contextual].
 * This method can be used to completely introspect the type that the current descriptor describes.
 *
 * Example:
 * ```
 * @Serializable
 * @OnClassSerialAnnotation
 * class Nested(...)
 *
 * @Serializable
 * class Outer(val nested: Nested)
 *
 * val outerDescriptor = Outer.serializer().descriptor
 *
 * outerDescriptor.getElementDescriptor(0).serialName // Returns "Nested"
 * outerDescriptor.getElementDescriptor(0).annotations // Returns [@OnClassSerialAnnotation]
 * ```
 *
 * @throws IndexOutOfBoundsException for illegal [index] values.
 * @throws IllegalStateException if the current descriptor does not support children elements (e.g. is a primitive).
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)getElementDescriptorIndex:(int32_t)index __attribute__((swift_name("getElementDescriptor(index:)")));

/**
 * Returns an index in the children list of the given element by its name or [CompositeDecoder.UNKNOWN_NAME]
 * if there is no such element.
 * The resulting index, if it is not [CompositeDecoder.UNKNOWN_NAME], is guaranteed to be usable with [getElementName].
 *
 * Example:
 *
 * ```
 * @Serializable
 * class User(val name: String, val alias: String?)
 *
 * val userDescriptor = User.serializer().descriptor
 *
 * userDescriptor.getElementIndex("name") // Returns 0
 * userDescriptor.getElementIndex("alias") // Returns 1
 * userDescriptor.getElementIndex("lastName") // Returns CompositeDecoder.UNKNOWN_NAME = -3
 * ```
 */
- (int32_t)getElementIndexName:(NSString *)name __attribute__((swift_name("getElementIndex(name:)")));

/**
 * Returns a positional name of the child at the given [index].
 * Positional name represents a corresponding property name in the class, associated with
 * the current descriptor.
 *
 * Do not confuse with [serialName], which returns class name:
 *
 * ```
 * package my.app
 *
 * @Serializable
 * class User(val name: String)
 *
 * val userDescriptor = User.serializer().descriptor
 *
 * userDescriptor.serialName // Returns "my.app.User"
 * userDescriptor.getElementName(0) // Returns "name"
 * ```
 *
 * @throws IndexOutOfBoundsException for an illegal [index] values.
 * @throws IllegalStateException if the current descriptor does not support children elements (e.g. is a primitive)
 */
- (NSString *)getElementNameIndex:(int32_t)index __attribute__((swift_name("getElementName(index:)")));

/**
 * Whether the element at the given [index] is optional (can be absent in serialized form).
 * For generated descriptors, all elements that have a corresponding default parameter value are
 * marked as optional. Custom serializers can treat optional values in a serialization-specific manner
 * without a default parameters constraint.
 *
 * Example of optionality:
 * ```
 * @Serializable
 * class Holder(
 *     val a: Int, // isElementOptional(0) == false
 *     val b: Int?, // isElementOptional(1) == false
 *     val c: Int? = null, // isElementOptional(2) == true
 *     val d: List<Int>, // isElementOptional(3) == false
 *     val e: List<Int> = listOf(1), // isElementOptional(4) == true
 * )
 * ```
 * Returns `false` for valid indices of collections, maps, and enums.
 *
 * @throws IndexOutOfBoundsException for an illegal [index] values.
 * @throws IllegalStateException if the current descriptor does not support children elements (e.g. is a primitive).
 */
- (BOOL)isElementOptionalIndex:(int32_t)index __attribute__((swift_name("isElementOptional(index:)")));

/**
 * Returns serial annotations of the associated class.
 * Serial annotations can be used to specify additional metadata that may be used during serialization.
 * Only annotations marked with [SerialInfo] are added to the resulting list.
 *
 * Do not confuse with [getElementAnnotations]:
 * ```
 * @Serializable
 * @OnClassSerialAnnotation
 * class Nested(...)
 *
 * @Serializable
 * class Outer(@OnPropertySerialAnnotation val nested: Nested)
 *
 * val outerDescriptor = Outer.serializer().descriptor
 *
 * outerDescriptor.getElementAnnotations(0) // Returns [@OnPropertySerialAnnotation]
 * outerDescriptor.getElementDescriptor(0).annotations // Returns [@OnClassSerialAnnotation]
 * ```
 */
@property (readonly) NSArray<id<DynamicsMultiplatformKotlinAnnotation>> *annotations __attribute__((swift_name("annotations")));

/**
 * The number of elements this descriptor describes, besides from the class itself.
 * [elementsCount] describes the number of **semantic** elements, not the number
 * of actual fields/properties in the serialized form, even though they frequently match.
 *
 * For example, for the following class
 * `class Complex(val real: Long, val imaginary: Long)` the corresponding descriptor
 * and the serialized form both have two elements, while for `List<Int>`
 * the corresponding descriptor has a single element (`IntDescriptor`, the type of list element),
 * but from zero up to `Int.MAX_VALUE` values in the serialized form:
 *
 * ```
 * @Serializable
 * class Complex(val real: Long, val imaginary: Long)
 *
 * Complex.serializer().descriptor.elementsCount // Returns 2
 *
 * @Serializable
 * class OuterList(val list: List<Int>)
 *
 * OuterList.serializer().descriptor.getElementDescriptor(0).elementsCount // Returns 1
 * ```
 */
@property (readonly) int32_t elementsCount __attribute__((swift_name("elementsCount")));

/**
 * Returns `true` if this descriptor describes a serializable value class which underlying value
 * is serialized directly.
 *
 * This property is true for serializable `@JvmInline value` classes:
 * ```
 * @Serializable
 * class User(val name: Name)
 *
 * @Serializable
 * @JvmInline
 * value class Name(val value: String)
 *
 * User.serializer().descriptor.isInline // false
 * User.serializer().descriptor.getElementDescriptor(0).isInline // true
 * Name.serializer().descriptor.isInline // true
 * ```
 */
@property (readonly) BOOL isInline __attribute__((swift_name("isInline")));

/**
 * Whether the descriptor describes a nullable type.
 * Returns `true` if associated serializer can serialize/deserialize nullable elements of the described type.
 *
 * Example:
 *
 * ```
 * @Serializable
 * class User(val name: String, val alias: String?)
 *
 * val userDescriptor = User.serializer().descriptor
 *
 * userDescriptor.isNullable // Returns false
 * userDescriptor.getElementDescriptor(0).isNullable // Returns false
 * userDescriptor.getElementDescriptor(1).isNullable // Returns true
 * ```
 */
@property (readonly) BOOL isNullable __attribute__((swift_name("isNullable")));

/**
 * The kind of the serialized form that determines **the shape** of the serialized data.
 * Formats use serial kind to add and parse serializer-agnostic metadata to the result.
 *
 * For example, JSON format wraps [classes][StructureKind.CLASS] and [StructureKind.MAP] into
 * brackets, while ProtoBuf just serialize these types in separate ways.
 *
 * Kind should be consistent with the implementation, for example, if it is a [primitive][PrimitiveKind],
 * then its element count should be zero and vice versa.
 *
 * Example of introspecting kinds:
 *
 * ```
 * @Serializable
 * class User(val name: String)
 *
 * val userDescriptor = User.serializer().descriptor
 *
 * userDescriptor.kind // Returns StructureKind.CLASS
 * userDescriptor.getElementDescriptor(0).kind // Returns PrimitiveKind.STRING
 * ```
 */
@property (readonly) DynamicsMultiplatformKotlinx_serialization_coreSerialKind *kind __attribute__((swift_name("kind")));

/**
 * Serial name of the descriptor that identifies a pair of the associated serializer and target class.
 *
 * For generated and default serializers, the serial name is equal to the corresponding class's fully qualified name
 * or, if overridden, [SerialName].
 * Custom serializers should provide a unique serial name that identifies both the serializable class and
 * the serializer itself, ignoring type arguments if they are present, for example: `my.package.LongAsTrimmedString`.
 *
 * Do not confuse with [getElementName], which returns property name:
 *
 * ```
 * package my.app
 *
 * @Serializable
 * class User(val name: String)
 *
 * val userDescriptor = User.serializer().descriptor
 *
 * userDescriptor.serialName // Returns "my.app.User"
 * userDescriptor.getElementName(0) // Returns "name"
 * ```
 */
@property (readonly) NSString *serialName __attribute__((swift_name("serialName")));
@end


/**
 * Decoder is a core deserialization primitive that encapsulates the knowledge of the underlying
 * format and an underlying storage, exposing only structural methods to the deserializer, making it completely
 * format-agnostic. Deserialization process takes a decoder and asks him for a sequence of primitive elements,
 * defined by a deserializer serial form, while decoder knows how to retrieve these primitive elements from an actual format
 * representations.
 *
 * Decoder provides high-level API that operates with basic primitive types, collections
 * and nested structures. Internally, the decoder represents input storage, and operates with its state
 * and lower level format-specific details.
 *
 * To be more specific, serialization asks a decoder for a sequence of "give me an int, give me
 * a double, give me a list of strings and give me another object that is a nested int", while decoding
 * transforms this sequence into a format-specific commands such as "parse the part of the string until the next quotation mark
 * as an int to retrieve an int, parse everything within the next curly braces to retrieve elements of a nested object etc."
 *
 * The symmetric interface for the serialization process is [Encoder].
 *
 * ### Deserialization. Primitives
 *
 * If a class is represented as a single [primitive][PrimitiveKind] value in its serialized form,
 * then one of the `decode*` methods (e.g. [decodeInt]) can be used directly.
 *
 * ### Deserialization. Structured types
 *
 * If a class is represented as a structure or has multiple values in its serialized form,
 * `decode*` methods are not that helpful, because format may not require a strict order of data
 * (e.g. JSON or XML), do not allow working with collection types or establish structure boundaries.
 * All these capabilities are delegated to the [CompositeDecoder] interface with a more specific API surface.
 * To denote a structure start, [beginStructure] should be used.
 * ```
 * // Denote the structure start,
 * val composite = decoder.beginStructure(descriptor)
 * // Decode all elements within the structure using 'composite'
 * ...
 * // Denote the structure end
 * composite.endStructure(descriptor)
 * ```
 *
 * E.g. if the decoder belongs to JSON format, then [beginStructure] will parse an opening bracket
 * (`{` or `[`, depending on the descriptor kind), returning the [CompositeDecoder] that is aware of colon separator,
 * that should be read after each key-value pair, whilst [CompositeDecoder.endStructure] will parse a closing bracket.
 *
 * ### Exception guarantees
 *
 * For the regular exceptions, such as invalid input, missing control symbols or attributes, and unknown symbols,
 * [SerializationException] can be thrown by any decoder methods. It is recommended to declare a format-specific
 * subclass of [SerializationException] and throw it.
 *
 * ### Exception safety
 *
 * In general, catching [SerializationException] from any of `decode*` methods is not allowed and produces unspecified behavior.
 * After thrown exception, the current decoder is left in an arbitrary state, no longer suitable for further decoding.
 *
 * ### Format encapsulation
 *
 * For example, for the following deserializer:
 * ```
 * class StringHolder(val stringValue: String)
 *
 * object StringPairDeserializer : DeserializationStrategy<StringHolder> {
 *    override val descriptor = ...
 *
 *    override fun deserializer(decoder: Decoder): StringHolder {
 *        // Denotes start of the structure, StringHolder is not a "plain" data type
 *        val composite = decoder.beginStructure(descriptor)
 *        if (composite.decodeElementIndex(descriptor) != 0)
 *            throw MissingFieldException("Field 'stringValue' is missing")
 *        // Decode the nested string value
 *        val value = composite.decodeStringElement(descriptor, index = 0)
 *        // Denotes end of the structure
 *        composite.endStructure(descriptor)
 *    }
 * }
 * ```
 *
 * This deserializer does not know anything about the underlying data and will work with any properly-implemented decoder.
 * JSON, for example, parses an opening bracket `{` during the `beginStructure` call, checks that the next key
 * after this bracket is `stringValue` (using the descriptor), returns the value after the colon as string value
 * and parses closing bracket `}` during the `endStructure`.
 * XML would do roughly the same, but with different separators and parsing structures, while ProtoBuf
 * machinery could be completely different.
 * In any case, all these parsing details are encapsulated by a decoder.
 *
 * ### Decoder implementation
 *
 * While being strictly typed, an underlying format can transform actual types in the way it wants.
 * For example, a format can support only string types and encode/decode all primitives in a string form:
 * ```
 * StringFormatDecoder : Decoder {
 *
 *     ...
 *     override fun decodeDouble(): Double = decodeString().toDouble()
 *     override fun decodeInt(): Int = decodeString().toInt()
 *     ...
 * }
 * ```
 *
 * ### Not stable for inheritance
 *
 * `Decoder` interface is not stable for inheritance in 3rd-party libraries, as new methods
 * might be added to this interface or contracts of the existing methods can be changed.
 */
__attribute__((swift_name("Kotlinx_serialization_coreDecoder")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreDecoder
@required

/**
 * Decodes the beginning of the nested structure in a serialized form
 * and returns [CompositeDecoder] responsible for decoding this very structure.
 *
 * Typically, classes, collections and maps are represented as a nested structure in a serialized form.
 * E.g. the following JSON
 * ```
 * {
 *     "a": 2,
 *     "b": { "nested": "c" }
 *     "c": [1, 2, 3],
 *     "d": null
 * }
 * ```
 * has three nested structures: the very beginning of the data, "b" value and "c" value.
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder>)beginStructureDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("beginStructure(descriptor:)")));

/**
 * Decodes a boolean value.
 * Corresponding kind is [PrimitiveKind.BOOLEAN].
 */
- (BOOL)decodeBoolean __attribute__((swift_name("decodeBoolean()")));

/**
 * Decodes a single byte value.
 * Corresponding kind is [PrimitiveKind.BYTE].
 */
- (int8_t)decodeByte __attribute__((swift_name("decodeByte()")));

/**
 * Decodes a 16-bit unicode character value.
 * Corresponding kind is [PrimitiveKind.CHAR].
 */
- (unichar)decodeChar __attribute__((swift_name("decodeChar()")));

/**
 * Decodes a 64-bit IEEE 754 floating point value.
 * Corresponding kind is [PrimitiveKind.DOUBLE].
 */
- (double)decodeDouble __attribute__((swift_name("decodeDouble()")));

/**
 * Decodes a enum value and returns its index in [enumDescriptor] elements collection.
 * Corresponding kind is [SerialKind.ENUM].
 *
 * E.g. for the enum `enum class Letters { A, B, C, D }` and
 * underlying input "C", [decodeEnum] method should return `2` as a result.
 *
 * This method does not imply any restrictions on the input format,
 * the format is free to store the enum by its name, index, ordinal or any other enum representation.
 */
- (int32_t)decodeEnumEnumDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)enumDescriptor __attribute__((swift_name("decodeEnum(enumDescriptor:)")));

/**
 * Decodes a 32-bit IEEE 754 floating point value.
 * Corresponding kind is [PrimitiveKind.FLOAT].
 */
- (float)decodeFloat __attribute__((swift_name("decodeFloat()")));

/**
 * Returns [Decoder] for decoding an underlying type of a value class in an inline manner.
 * [descriptor] describes a target value class.
 *
 * Namely, for the `@Serializable @JvmInline value class MyInt(val my: Int)`, the following sequence is used:
 * ```
 * thisDecoder.decodeInline(MyInt.serializer().descriptor).decodeInt()
 * ```
 *
 * Current decoder may return any other instance of [Decoder] class, depending on the provided [descriptor].
 * For example, when this function is called on `Json` decoder with
 * `UInt.serializer().descriptor`, the returned decoder is able to decode unsigned integers.
 *
 * Note that this function returns [Decoder] instead of the [CompositeDecoder]
 * because value classes always have the single property.
 *
 * Calling [Decoder.beginStructure] on returned instance leads to an unspecified behavior and, in general, is prohibited.
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decodeInlineDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeInline(descriptor:)")));

/**
 * Decodes a 32-bit integer value.
 * Corresponding kind is [PrimitiveKind.INT].
 */
- (int32_t)decodeInt __attribute__((swift_name("decodeInt()")));

/**
 * Decodes a 64-bit integer value.
 * Corresponding kind is [PrimitiveKind.LONG].
 */
- (int64_t)decodeLong __attribute__((swift_name("decodeLong()")));

/**
 * Returns `true` if the current value in decoder is not null, false otherwise.
 * This method is usually used to decode potentially nullable data:
 * ```
 * // Could be String? deserialize() method
 * public fun deserialize(decoder: Decoder): String? {
 *     if (decoder.decodeNotNullMark()) {
 *         return decoder.decodeString()
 *     } else {
 *         return decoder.decodeNull()
 *     }
 * }
 * ```
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeNotNullMark __attribute__((swift_name("decodeNotNullMark()")));

/**
 * Decodes the `null` value and returns it.
 *
 * It is expected that `decodeNotNullMark` was called
 * prior to `decodeNull` invocation and the case when it returned `true` was handled.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (DynamicsMultiplatformKotlinNothing * _Nullable)decodeNull __attribute__((swift_name("decodeNull()")));

/**
 * Decodes the nullable value of type [T] by delegating the decoding process to the given [deserializer].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableValueDeserializer:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeNullableSerializableValue(deserializer:)")));

/**
 * Decodes the value of type [T] by delegating the decoding process to the given [deserializer].
 * For example, `decodeInt` call is equivalent to delegating integer decoding to [Int.serializer][Int.Companion.serializer]:
 * `decodeSerializableValue(Int.serializer())`
 */
- (id _Nullable)decodeSerializableValueDeserializer:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy>)deserializer __attribute__((swift_name("decodeSerializableValue(deserializer:)")));

/**
 * Decodes a 16-bit short value.
 * Corresponding kind is [PrimitiveKind.SHORT].
 */
- (int16_t)decodeShort __attribute__((swift_name("decodeShort()")));

/**
 * Decodes a string value.
 * Corresponding kind is [PrimitiveKind.STRING].
 */
- (NSString *)decodeString __attribute__((swift_name("decodeString()")));

/**
 * Context of the current serialization process, including contextual and polymorphic serialization and,
 * potentially, a format-specific configuration.
 */
@property (readonly) DynamicsMultiplatformKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * [CompositeDecoder] is a part of decoding process that is bound to a particular structured part of
 * the serialized form, described by the serial descriptor passed to [Decoder.beginStructure].
 *
 * Typically, for unordered data, [CompositeDecoder] is used by a serializer withing a [decodeElementIndex]-based
 * loop that decodes all the required data one-by-one in any order and then terminates by calling [endStructure].
 * Please refer to [decodeElementIndex] for example of such loop.
 *
 * All `decode*` methods have `index` and `serialDescriptor` parameters with a strict semantics and constraints:
 *   * `descriptor` argument is always the same as one used in [Decoder.beginStructure].
 *   * `index` of the element being decoded. For [sequential][decodeSequentially] decoding, it is always a monotonic
 *      sequence from `0` to `descriptor.elementsCount` and for indexing-loop it is always an index that [decodeElementIndex]
 *      has returned from the last call.
 *
 * The symmetric interface for the serialization process is [CompositeEncoder].
 *
 * ### Not stable for inheritance
 *
 * `CompositeDecoder` interface is not stable for inheritance in 3rd party libraries, as new methods
 * might be added to this interface or contracts of the existing methods can be changed.
 */
__attribute__((swift_name("Kotlinx_serialization_coreCompositeDecoder")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreCompositeDecoder
@required

/**
 * Decodes a boolean value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.BOOLEAN] kind.
 */
- (BOOL)decodeBooleanElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeBooleanElement(descriptor:index:)")));

/**
 * Decodes a single byte value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.BYTE] kind.
 */
- (int8_t)decodeByteElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeByteElement(descriptor:index:)")));

/**
 * Decodes a 16-bit unicode character value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.CHAR] kind.
 */
- (unichar)decodeCharElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeCharElement(descriptor:index:)")));

/**
 * Method to decode collection size that may be called before the collection decoding.
 * Collection type includes [Collection], [Map] and [Array] (including primitive arrays).
 * Method can return `-1` if the size is not known in advance, though for [sequential decoding][decodeSequentially]
 * knowing precise size is a mandatory requirement.
 */
- (int32_t)decodeCollectionSizeDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeCollectionSize(descriptor:)")));

/**
 * Decodes a 64-bit IEEE 754 floating point value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.DOUBLE] kind.
 */
- (double)decodeDoubleElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeDoubleElement(descriptor:index:)")));

/**
 *  Decodes the index of the next element to be decoded.
 *  Index represents a position of the current element in the serial descriptor element that can be found
 *  with [SerialDescriptor.getElementIndex].
 *
 *  If this method returns non-negative index, the caller should call one of the `decode*Element` methods
 *  with a resulting index.
 *  Apart from positive values, this method can return [DECODE_DONE] to indicate that no more elements
 *  are left or [UNKNOWN_NAME] to indicate that symbol with an unknown name was encountered.
 *
 * Example of usage:
 * ```
 * class MyPair(i: Int, d: Double)
 *
 * object MyPairSerializer : KSerializer<MyPair> {
 *     // ... other methods omitted
 *
 *    fun deserialize(decoder: Decoder): MyPair {
 *        val composite = decoder.beginStructure(descriptor)
 *        var i: Int? = null
 *        var d: Double? = null
 *        while (true) {
 *            when (val index = composite.decodeElementIndex(descriptor)) {
 *                0 -> i = composite.decodeIntElement(descriptor, 0)
 *                1 -> d = composite.decodeDoubleElement(descriptor, 1)
 *                DECODE_DONE -> break // Input is over
 *                else -> error("Unexpected index: $index)
 *            }
 *        }
 *        composite.endStructure(descriptor)
 *        require(i != null && d != null)
 *        return MyPair(i, d)
 *    }
 * }
 * ```
 * This example is a rough equivalent of what serialization plugin generates for serializable pair class.
 *
 * The need in such a loop comes from unstructured nature of most serialization formats.
 * For example, JSON for the following input `{"d": 2.0, "i": 1}`, will first read `d` key with index `1`
 * and only after `i` with the index `0`.
 *
 * A potential implementation of this method for JSON format can be the following:
 * ```
 * fun decodeElementIndex(descriptor: SerialDescriptor): Int {
 *     // Ignore arrays
 *     val nextKey: String? = myStringJsonParser.nextKey()
 *     if (nextKey == null) return DECODE_DONE
 *     return descriptor.getElementIndex(nextKey) // getElementIndex can return UNKNOWN_NAME
 * }
 * ```
 *
 * If [decodeSequentially] returns `true`, the caller might skip calling this method.
 */
- (int32_t)decodeElementIndexDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("decodeElementIndex(descriptor:)")));

/**
 * Decodes a 32-bit IEEE 754 floating point value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.FLOAT] kind.
 */
- (float)decodeFloatElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeFloatElement(descriptor:index:)")));

/**
 * Returns [Decoder] for decoding an underlying type of a value class in an inline manner.
 * Serializable value class is described by the [child descriptor][SerialDescriptor.getElementDescriptor]
 * of given [descriptor] at [index].
 *
 * Namely, for the `@Serializable @JvmInline value class MyInt(val my: Int)`,
 * and `@Serializable class MyData(val myInt: MyInt)` the following sequence is used:
 * ```
 * thisDecoder.decodeInlineElement(MyData.serializer().descriptor, 0).decodeInt()
 * ```
 *
 * This method provides an opportunity for the optimization to avoid boxing of a carried value
 * and its invocation should be equivalent to the following:
 * ```
 * thisDecoder.decodeSerializableElement(MyData.serializer.descriptor, 0, MyInt.serializer())
 * ```
 *
 * Current decoder may return any other instance of [Decoder] class, depending on the provided descriptor.
 * For example, when this function is called on `Json` decoder with descriptor that has
 * `UInt.serializer().descriptor` at the given [index], the returned decoder is able
 * to decode unsigned integers.
 *
 * Note that this function returns [Decoder] instead of the [CompositeDecoder]
 * because value classes always have the single property.
 * Calling [Decoder.beginStructure] on returned instance leads to an unspecified behavior and, in general, is prohibited.
 *
 * @see Decoder.decodeInline
 * @see SerialDescriptor.getElementDescriptor
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreDecoder>)decodeInlineElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeInlineElement(descriptor:index:)")));

/**
 * Decodes a 32-bit integer value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.INT] kind.
 */
- (int32_t)decodeIntElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeIntElement(descriptor:index:)")));

/**
 * Decodes a 64-bit integer value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.LONG] kind.
 */
- (int64_t)decodeLongElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeLongElement(descriptor:index:)")));

/**
 * Decodes nullable value of the type [T] with the given [deserializer].
 *
 * If value at given [index] was already decoded with previous [decodeSerializableElement] call with the same index,
 * [previousValue] would contain a previously decoded value.
 * This parameter can be used to aggregate multiple values of the given property to the only one.
 * Implementation can safely ignore it and return a new value, efficiently using 'the last one wins' strategy,
 * or apply format-specific aggregating strategies, e.g. appending scattered Protobuf lists to a single one.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id _Nullable)decodeNullableSerializableElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeNullableSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * Checks whether the current decoder supports strictly ordered decoding of the data
 * without calling to [decodeElementIndex].
 * If the method returns `true`, the caller might skip [decodeElementIndex] calls
 * and start invoking `decode*Element` directly, incrementing the index of the element one by one.
 * This method can be called by serializers (either generated or user-defined) as a performance optimization,
 * but there is no guarantee that the method will be ever called. Practically, it means that implementations
 * that may benefit from sequential decoding should also support a regular [decodeElementIndex]-based decoding as well.
 *
 * Example of usage:
 * ```
 * class MyPair(i: Int, d: Double)
 *
 * object MyPairSerializer : KSerializer<MyPair> {
 *     // ... other methods omitted
 *
 *    fun deserialize(decoder: Decoder): MyPair {
 *        val composite = decoder.beginStructure(descriptor)
 *        if (composite.decodeSequentially()) {
 *            val i = composite.decodeIntElement(descriptor, index = 0) // Mind the sequential indexing
 *            val d = composite.decodeIntElement(descriptor, index = 1)
 *            composite.endStructure(descriptor)
 *            return MyPair(i, d)
 *        } else {
 *            // Fallback to `decodeElementIndex` loop, refer to its documentation for details
 *        }
 *    }
 * }
 * ```
 * This example is a rough equivalent of what serialization plugin generates for serializable pair class.
 *
 * Sequential decoding is a performance optimization for formats with strictly ordered schema,
 * usually binary ones. Regular formats such as JSON or ProtoBuf cannot use this optimization,
 * because e.g. in the latter example, the same data can be represented both as
 * `{"i": 1, "d": 1.0}` and `{"d": 1.0, "i": 1}` (thus, unordered).
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)decodeSequentially __attribute__((swift_name("decodeSequentially()")));

/**
 * Decodes value of the type [T] with the given [deserializer].
 *
 * Implementations of [CompositeDecoder] may use their format-specific deserializers
 * for particular data types, e.g. handle [ByteArray] specifically if format is binary.
 *
 * If value at given [index] was already decoded with previous [decodeSerializableElement] call with the same index,
 * [previousValue] would contain a previously decoded value.
 * This parameter can be used to aggregate multiple values of the given property to the only one.
 * Implementation can safely ignore it and return a new value, effectively using 'the last one wins' strategy,
 * or apply format-specific aggregating strategies, e.g. appending scattered Protobuf lists to a single one.
 */
- (id _Nullable)decodeSerializableElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index deserializer:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy>)deserializer previousValue:(id _Nullable)previousValue __attribute__((swift_name("decodeSerializableElement(descriptor:index:deserializer:previousValue:)")));

/**
 * Decodes a 16-bit short value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.SHORT] kind.
 */
- (int16_t)decodeShortElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeShortElement(descriptor:index:)")));

/**
 * Decodes a string value from the underlying input.
 * The resulting value is associated with the [descriptor] element at the given [index].
 * The element at the given index should have [PrimitiveKind.STRING] kind.
 */
- (NSString *)decodeStringElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("decodeStringElement(descriptor:index:)")));

/**
 * Denotes the end of the structure associated with current decoder.
 * For example, composite decoder of JSON format will expect (and parse)
 * a closing bracket in the underlying input.
 */
- (void)endStructureDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * Context of the current decoding process, including contextual and polymorphic serialization and,
 * potentially, a format-specific configuration.
 */
@property (readonly) DynamicsMultiplatformKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end

__attribute__((swift_name("KotlinKDeclarationContainer")))
@protocol DynamicsMultiplatformKotlinKDeclarationContainer
@required
@end

__attribute__((swift_name("KotlinKAnnotatedElement")))
@protocol DynamicsMultiplatformKotlinKAnnotatedElement
@required
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((swift_name("KotlinKClassifier")))
@protocol DynamicsMultiplatformKotlinKClassifier
@required
@end

__attribute__((swift_name("KotlinKClass")))
@protocol DynamicsMultiplatformKotlinKClass <DynamicsMultiplatformKotlinKDeclarationContainer, DynamicsMultiplatformKotlinKAnnotatedElement, DynamicsMultiplatformKotlinKClassifier>
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
- (BOOL)isInstanceValue:(id _Nullable)value __attribute__((swift_name("isInstance(value:)")));
@property (readonly) NSString * _Nullable qualifiedName __attribute__((swift_name("qualifiedName")));
@property (readonly) NSString * _Nullable simpleName __attribute__((swift_name("simpleName")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_utilsNanoSeconds")))
@interface DynamicsMultiplatformDynamics_utilsNanoSeconds : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinComparable>
- (instancetype)initWithNanoSeconds:(int64_t)nanoSeconds __attribute__((swift_name("init(nanoSeconds:)"))) __attribute__((objc_designated_initializer));
- (int32_t)compareToOther:(DynamicsMultiplatformDynamics_utilsNanoSeconds *)other __attribute__((swift_name("compareTo(other:)")));
- (DynamicsMultiplatformDynamics_utilsNanoSeconds *)doCopyNanoSeconds:(int64_t)nanoSeconds __attribute__((swift_name("doCopy(nanoSeconds:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t duration __attribute__((swift_name("duration")));
@property (readonly) int64_t nanoSeconds __attribute__((swift_name("nanoSeconds")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinRandom")))
@interface DynamicsMultiplatformKotlinRandom : DynamicsMultiplatformBase
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinRandomDefault *companion __attribute__((swift_name("companion")));
- (int32_t)nextBitsBitCount:(int32_t)bitCount __attribute__((swift_name("nextBits(bitCount:)")));
- (BOOL)nextBoolean __attribute__((swift_name("nextBoolean()")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (DynamicsMultiplatformKotlinByteArray *)nextBytesArray:(DynamicsMultiplatformKotlinByteArray *)array __attribute__((swift_name("nextBytes(array:)")));
- (DynamicsMultiplatformKotlinByteArray *)nextBytesSize:(int32_t)size __attribute__((swift_name("nextBytes(size:)")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (DynamicsMultiplatformKotlinByteArray *)nextBytesArray:(DynamicsMultiplatformKotlinByteArray *)array fromIndex:(int32_t)fromIndex toIndex:(int32_t)toIndex __attribute__((swift_name("nextBytes(array:fromIndex:toIndex:)")));
- (double)nextDouble __attribute__((swift_name("nextDouble()")));
- (double)nextDoubleUntil:(double)until __attribute__((swift_name("nextDouble(until:)")));
- (double)nextDoubleFrom:(double)from until:(double)until __attribute__((swift_name("nextDouble(from:until:)")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
- (int32_t)nextIntUntil:(int32_t)until __attribute__((swift_name("nextInt(until:)")));
- (int32_t)nextIntFrom:(int32_t)from until:(int32_t)until __attribute__((swift_name("nextInt(from:until:)")));
- (int64_t)nextLong __attribute__((swift_name("nextLong()")));
- (int64_t)nextLongUntil:(int64_t)until __attribute__((swift_name("nextLong(until:)")));
- (int64_t)nextLongFrom:(int64_t)from until:(int64_t)until __attribute__((swift_name("nextLong(from:until:)")));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreCoroutineScope")))
@protocol DynamicsMultiplatformKotlinx_coroutines_coreCoroutineScope
@required
@property (readonly) id<DynamicsMultiplatformKotlinCoroutineContext> coroutineContext __attribute__((swift_name("coroutineContext")));
@end

__attribute__((swift_name("CoreLocationState")))
@interface DynamicsMultiplatformCoreLocationState : DynamicsMultiplatformBase
@property (class, readonly, getter=companion) DynamicsMultiplatformCoreLocationStateCompanion *companion __attribute__((swift_name("companion")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
__attribute__((swift_name("KotlinClock")))
@protocol DynamicsMultiplatformKotlinClock
@required
- (DynamicsMultiplatformKotlinInstant *)now __attribute__((swift_name("now()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinTimeSource")))
@protocol DynamicsMultiplatformKotlinTimeSource
@required
- (id<DynamicsMultiplatformKotlinTimeMark>)markNow __attribute__((swift_name("markNow()")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinTimeSourceWithComparableMarks")))
@protocol DynamicsMultiplatformKotlinTimeSourceWithComparableMarks <DynamicsMultiplatformKotlinTimeSource>
@required
@end

__attribute__((swift_name("KotlinReadOnlyProperty")))
@protocol DynamicsMultiplatformKotlinReadOnlyProperty
@required
- (id _Nullable)getValueThisRef:(id _Nullable)thisRef property:(id<DynamicsMultiplatformKotlinKProperty>)property __attribute__((swift_name("getValue(thisRef:property:)")));
@end

__attribute__((swift_name("KotlinReadWriteProperty")))
@protocol DynamicsMultiplatformKotlinReadWriteProperty <DynamicsMultiplatformKotlinReadOnlyProperty>
@required
- (void)setValueThisRef:(id _Nullable)thisRef property:(id<DynamicsMultiplatformKotlinKProperty>)property value:(id _Nullable)value __attribute__((swift_name("setValue(thisRef:property:value:)")));
@end

__attribute__((swift_name("KotlinLongProgression")))
@interface DynamicsMultiplatformKotlinLongProgression : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinIterable>
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinLongProgressionCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (DynamicsMultiplatformKotlinLongIterator *)iterator __attribute__((swift_name("iterator()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) int64_t first __attribute__((swift_name("first")));
@property (readonly) int64_t last __attribute__((swift_name("last")));
@property (readonly) int64_t step __attribute__((swift_name("step")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange")))
@interface DynamicsMultiplatformKotlinLongRange : DynamicsMultiplatformKotlinLongProgression <DynamicsMultiplatformKotlinClosedRange, DynamicsMultiplatformKotlinOpenEndRange>
- (instancetype)initWithStart:(int64_t)start endInclusive:(int64_t)endInclusive __attribute__((swift_name("init(start:endInclusive:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinLongRangeCompanion *companion __attribute__((swift_name("companion")));
- (BOOL)containsValue:(DynamicsMultiplatformLong *)value __attribute__((swift_name("contains(value:)")));
- (BOOL)containsValue_:(DynamicsMultiplatformLong *)value __attribute__((swift_name("contains(value_:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (BOOL)isEmpty __attribute__((swift_name("isEmpty()")));
- (NSString *)description __attribute__((swift_name("description()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
@property (readonly) DynamicsMultiplatformLong *endExclusive __attribute__((swift_name("endExclusive"))) __attribute__((deprecated("Can throw an exception when it's impossible to represent the value with Long type, for example, when the range includes MAX_VALUE. It's recommended to use 'endInclusive' property that doesn't throw.")));
@property (readonly) DynamicsMultiplatformLong *endInclusive __attribute__((swift_name("endInclusive")));
@property (readonly) DynamicsMultiplatformLong *start __attribute__((swift_name("start")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinNothing")))
@interface DynamicsMultiplatformKotlinNothing : DynamicsMultiplatformBase
@end

__attribute__((swift_name("KotlinByteIterator")))
@interface DynamicsMultiplatformKotlinByteIterator : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DynamicsMultiplatformByte *)next __attribute__((swift_name("next()")));
- (int8_t)nextByte __attribute__((swift_name("nextByte()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinUuid.Companion")))
@interface DynamicsMultiplatformKotlinUuidCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinUuidCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformKotlinUuid *)fromByteArrayByteArray:(DynamicsMultiplatformKotlinByteArray *)byteArray __attribute__((swift_name("fromByteArray(byteArray:)")));
- (DynamicsMultiplatformKotlinUuid *)fromLongsMostSignificantBits:(int64_t)mostSignificantBits leastSignificantBits:(int64_t)leastSignificantBits __attribute__((swift_name("fromLongs(mostSignificantBits:leastSignificantBits:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.1")
 *   kotlin.ExperimentalUnsignedTypes
*/
- (DynamicsMultiplatformKotlinUuid *)fromUByteArrayUbyteArray:(id)ubyteArray __attribute__((swift_name("fromUByteArray(ubyteArray:)")));
- (DynamicsMultiplatformKotlinUuid *)fromULongsMostSignificantBits:(uint64_t)mostSignificantBits leastSignificantBits:(uint64_t)leastSignificantBits __attribute__((swift_name("fromULongs(mostSignificantBits:leastSignificantBits:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid *)generateV4 __attribute__((swift_name("generateV4()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid *)generateV7 __attribute__((swift_name("generateV7()")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid *)generateV7NonMonotonicAtTimestamp:(DynamicsMultiplatformKotlinInstant *)timestamp __attribute__((swift_name("generateV7NonMonotonicAt(timestamp:)")));
- (DynamicsMultiplatformKotlinUuid *)parseUuidString:(NSString *)uuidString __attribute__((swift_name("parse(uuidString:)")));
- (DynamicsMultiplatformKotlinUuid *)parseHexHexString:(NSString *)hexString __attribute__((swift_name("parseHex(hexString:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.1")
*/
- (DynamicsMultiplatformKotlinUuid *)parseHexDashHexDashString:(NSString *)hexDashString __attribute__((swift_name("parseHexDash(hexDashString:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid * _Nullable)parseHexDashOrNullHexDashString:(NSString *)hexDashString __attribute__((swift_name("parseHexDashOrNull(hexDashString:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid * _Nullable)parseHexOrNullHexString:(NSString *)hexString __attribute__((swift_name("parseHexOrNull(hexString:)")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="2.3")
*/
- (DynamicsMultiplatformKotlinUuid * _Nullable)parseOrNullUuidString:(NSString *)uuidString __attribute__((swift_name("parseOrNull(uuidString:)")));
- (DynamicsMultiplatformKotlinUuid *)random __attribute__((swift_name("random()")));

/**
 * @note annotations
 *   kotlin.DeprecatedSinceKotlin(warningSince="2.1")
*/
@property (readonly) id<DynamicsMultiplatformKotlinComparator> LEXICAL_ORDER __attribute__((swift_name("LEXICAL_ORDER"))) __attribute__((deprecated("Use naturalOrder<Uuid>() instead")));
@property (readonly) DynamicsMultiplatformKotlinUuid *NIL __attribute__((swift_name("NIL")));
@property (readonly) int32_t SIZE_BITS __attribute__((swift_name("SIZE_BITS")));
@property (readonly) int32_t SIZE_BYTES __attribute__((swift_name("SIZE_BYTES")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntProgression.Companion")))
@interface DynamicsMultiplatformKotlinIntProgressionCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinIntProgressionCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformKotlinIntProgression *)fromClosedRangeRangeStart:(int32_t)rangeStart rangeEnd:(int32_t)rangeEnd step:(int32_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((swift_name("KotlinIntIterator")))
@interface DynamicsMultiplatformKotlinIntIterator : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DynamicsMultiplatformInt *)next __attribute__((swift_name("next()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinIntRange.Companion")))
@interface DynamicsMultiplatformKotlinIntRangeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinIntRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformKotlinIntRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_utilsSamplingRateMark.Companion")))
@interface DynamicsMultiplatformDynamics_utilsSamplingRateMarkCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamics_utilsSamplingRateMarkCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSArray<DynamicsMultiplatformDynamics_utilsSamplingRateMark *> *NONE __attribute__((swift_name("NONE")));
@end

__attribute__((swift_name("KotlinIllegalStateException")))
@interface DynamicsMultiplatformKotlinIllegalStateException : DynamicsMultiplatformKotlinRuntimeException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.4")
*/
__attribute__((swift_name("KotlinCancellationException")))
@interface DynamicsMultiplatformKotlinCancellationException : DynamicsMultiplatformKotlinIllegalStateException
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (instancetype)initWithMessage:(NSString * _Nullable)message __attribute__((swift_name("init(message:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithCause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(cause:)"))) __attribute__((objc_designated_initializer));
- (instancetype)initWithMessage:(NSString * _Nullable)message cause:(DynamicsMultiplatformKotlinThrowable * _Nullable)cause __attribute__((swift_name("init(message:cause:)"))) __attribute__((objc_designated_initializer));
@end

__attribute__((swift_name("Kotlinx_coroutines_coreFlowCollector")))
@protocol DynamicsMultiplatformKotlinx_coroutines_coreFlowCollector
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)emitValue:(id _Nullable)value completionHandler:(void (^)(NSError * _Nullable))completionHandler __attribute__((swift_name("emit(value:completionHandler:)")));
@end


/**
 * Represents a successful resource with the [result] of type [T].
 *
 * @param result the object of type [T].
 * @param [warning] an optional [Exception].
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("ResourceResourceSuccess")))
@interface DynamicsMultiplatformResourceResourceSuccess<T> : DynamicsMultiplatformResourceResource<T>
- (instancetype)initWithResult:(T _Nullable)result warning:(DynamicsMultiplatformKotlinException * _Nullable)warning __attribute__((swift_name("init(result:warning:)"))) __attribute__((objc_designated_initializer));
- (DynamicsMultiplatformResourceResourceSuccess<T> *)doCopyResult:(T _Nullable)result warning:(DynamicsMultiplatformKotlinException * _Nullable)warning __attribute__((swift_name("doCopy(result:warning:)")));

/**
 * Represents a successful resource with the [result] of type [T].
 *
 * @param result the object of type [T].
 * @param [warning] an optional [Exception].
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * Represents a successful resource with the [result] of type [T].
 *
 * @param result the object of type [T].
 * @param [warning] an optional [Exception].
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * Represents a successful resource with the [result] of type [T].
 *
 * @param result the object of type [T].
 * @param [warning] an optional [Exception].
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) T _Nullable result __attribute__((swift_name("result")));
@property (readonly) DynamicsMultiplatformKotlinException * _Nullable warning __attribute__((swift_name("warning")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_dbDatabase.Companion")))
@interface DynamicsMultiplatformDynamics_dbDatabaseCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamics_dbDatabaseCompanion *shared __attribute__((swift_name("shared")));

/**
 * Defines the side that is used for the first peripheral if there is none persisted yet.
 */
@property (readonly) DynamicsMultiplatformSide *INITIAL_SIDE __attribute__((swift_name("INITIAL_SIDE")));

/**
 * Defines the maximum number of peripherals.
 */
@property (readonly) int32_t MAX_PERIPHERALS __attribute__((swift_name("MAX_PERIPHERALS")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_dbGloveModeGenericNullable")))
@interface DynamicsMultiplatformDynamics_dbGloveModeGenericNullable<T> : DynamicsMultiplatformBase
- (T _Nullable)getBySideSide:(DynamicsMultiplatformSide *)side __attribute__((swift_name("getBySide(side:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_dbBodyProfileDao")))
@protocol DynamicsMultiplatformDynamics_dbBodyProfileDao
@required

/**
 * @return the currently set [BodyProfile].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBodyProfileWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformBodyProfile *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBodyProfile(completionHandler:)")));

/**
 * Inserts a [BodyProfile] for a [com.riseworld.dynamics.models.domain.session.TrainingSession].
 *
 * Throws an error if a [BodyProfile] is already set.
 *
 * @note This method converts instances of Exception to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (BOOL)insertBodyProfileForTrainingSessionTrainingSessionId:(id)trainingSessionId bodyProfile:(DynamicsMultiplatformBodyProfile *)bodyProfile error:(NSError * _Nullable * _Nullable)error __attribute__((swift_name("insertBodyProfileForTrainingSession(trainingSessionId:bodyProfile:)")));

/**
 * Inserts or updates the current [bodyProfile].
 *
 * Note that the [BodyProfile.id] doesn't matter as this is changed by the internal impl to
 * only persist one [BodyProfile].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)insertOrUpdateBodyProfile:(DynamicsMultiplatformBodyProfile *)bodyProfile completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("insertOrUpdate(bodyProfile:completionHandler:)")));

/**
 * Observes the one and only [BodyProfile] that can be persisted via [insertOrUpdate].
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeBodyProfile __attribute__((swift_name("observeBodyProfile()")));

/**
 * Observes the set [BodyProfile] for a specific training session with [trainingSessionId].
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)observeBodyProfileForTrainingSessionTrainingSessionId:(id)trainingSessionId __attribute__((swift_name("observeBodyProfileForTrainingSession(trainingSessionId:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_bleGloveOptions")))
@interface DynamicsMultiplatformDynamics_bleGloveOptions : DynamicsMultiplatformBase
- (instancetype)initWithIsDummyImpactDataEnabled:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))isDummyImpactDataEnabled isBatteryMockEnabled:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))isBatteryMockEnabled advertisingPrefix:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))advertisingPrefix acceptAllPunches:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))acceptAllPunches firmwareUpdateBaseUrl:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))firmwareUpdateBaseUrl useDebugFirmwareUpdateImage:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))useDebugFirmwareUpdateImage backgroundDisconnectTimeout:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))backgroundDisconnectTimeout allowUnsetSerialNumberForPeripherals:(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^)(void))allowUnsetSerialNumberForPeripherals __attribute__((swift_name("init(isDummyImpactDataEnabled:isBatteryMockEnabled:advertisingPrefix:acceptAllPunches:firmwareUpdateBaseUrl:useDebugFirmwareUpdateImage:backgroundDisconnectTimeout:allowUnsetSerialNumberForPeripherals:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^acceptAllPunches)(void) __attribute__((swift_name("acceptAllPunches")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^advertisingPrefix)(void) __attribute__((swift_name("advertisingPrefix")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^allowUnsetSerialNumberForPeripherals)(void) __attribute__((swift_name("allowUnsetSerialNumberForPeripherals")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^backgroundDisconnectTimeout)(void) __attribute__((swift_name("backgroundDisconnectTimeout")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^firmwareUpdateBaseUrl)(void) __attribute__((swift_name("firmwareUpdateBaseUrl")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^isBatteryMockEnabled)(void) __attribute__((swift_name("isBatteryMockEnabled")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^isDummyImpactDataEnabled)(void) __attribute__((swift_name("isDummyImpactDataEnabled")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> (^useDebugFirmwareUpdateImage)(void) __attribute__((swift_name("useDebugFirmwareUpdateImage")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_bleGloveManager.Companion")))
@interface DynamicsMultiplatformDynamics_bleGloveManagerCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamics_bleGloveManagerCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) NSString *TAG __attribute__((swift_name("TAG")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleGenericPeripheral")))
@protocol DynamicsMultiplatformDynamics_bleGenericPeripheral
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBatteryWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBattery(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeviceInfoWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeviceInfo *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeviceInfo(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeviceNameWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeviceName(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPowerStateWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPowerState *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPowerState(completionHandler:)")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> batteryLevel __attribute__((swift_name("batteryLevel")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> deviceInfo __attribute__((swift_name("deviceInfo")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> deviceName __attribute__((swift_name("deviceName")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> lifecycleState __attribute__((swift_name("lifecycleState")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> powerState __attribute__((swift_name("powerState")));
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> state __attribute__((swift_name("state")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleGlovePeripheral")))
@protocol DynamicsMultiplatformDynamics_bleGlovePeripheral <DynamicsMultiplatformDynamics_bleGenericPeripheral>
@required

/**
 * Sends out a [OperationalState.CALIBRATE_SENSORS] command and awaits its completion.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)calibrateSensorsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("calibrateSensors(completionHandler:)")));

/**
 * Sends out a [OperationalState.ERASE_FLASH] command.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)eraseFlashWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("eraseFlash(completionHandler:)")));

/**
 * Sends out a [OperationalState.FACTORY_RESET] command and awaits the re-connect until
 * [LifeCycleState] transitions back to [LifeCycleState.Ready].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)factoryResetWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("factoryReset(completionHandler:)")));

/**
 * While subscribed to this state - rapid baro readouts are performed by calling
 * [OperationalState.FORCE_BAROMETER_READOUT] every [delay].
 */
- (id<DynamicsMultiplatformKotlinx_coroutines_coreFlow>)forceBaroReadoutDelay:(int64_t)delay __attribute__((swift_name("forceBaroReadout(delay:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getImpactConfigsForceRefresh:(BOOL)forceRefresh completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllImpactConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getImpactConfigs(forceRefresh:completionHandler:)")));

/**
 * IMPORTANT NOTE: Accessing these services will by-pass the entire [GlovePeripheral]
 * state machine.
 *
 * @return [GlovePeripheralServices].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getServicesWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDynamics_bleGlovePeripheralServices *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getServices(completionHandler:)")));

/**
 * Sends out a [OperationalState.ENTER_DEEP_SLEEP] command, the glove will then disconnect.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)putToDeepSleepWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("putToDeepSleep(completionHandler:)")));

/**
 * Starts a self test.
 *
 * @return [SelfTestOutput].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)runSelfTestWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformSelfTestOutput *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("runSelfTest(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setImpactConfigsOption:(DynamicsMultiplatformImpactConfigOption *)option configs:(DynamicsMultiplatformAllImpactConfigs *)configs completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllImpactConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setImpactConfigs(option:configs:completionHandler:)")));

/**
 * Sends out a [OperationalState.REBOOT] command and awaits the re-connect until [LifeCycleState] transitions
 * back to [LifeCycleState.Ready].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)softRebootWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("softReboot(completionHandler:)")));

/**
 * @return true if the throughput has been started by this action, otherwise false.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)toggleThroughputTestWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformBoolean *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("toggleThroughputTest(completionHandler:)")));

/**
 * @return a state flow with the most recent raw acceleration [Vector3d].
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> accelerationData __attribute__((swift_name("accelerationData")));

/** The latest [PeripheralData] (combined data) received from the peripheral. */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> combinedData __attribute__((swift_name("combinedData")));

/**
 * @return a flow that emits continuous sensor data
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> continuousSensorData __attribute__((swift_name("continuousSensorData")));

/**
 * @return a flow with the last known extended device info.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> extendedDeviceInfo __attribute__((swift_name("extendedDeviceInfo")));

/**
 * @return a flow with the most recent [ImpactDataPacket].
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> impact __attribute__((swift_name("impact")));

/**
 * @return a flow with the last known impact configs - this will be updated once the peripheral
 * transitions to a state where impacts are being processed.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> impactConfigs __attribute__((swift_name("impactConfigs")));

/**
 * The [Uuid] of the current [GlovePeripheral] instance. This is just for internal purposes,
 * to track if the object has been re-created.
 */
@property (readonly) DynamicsMultiplatformKotlinUuid *instanceId __attribute__((swift_name("instanceId")));

/**
 * @return a flow with the last known value.
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow> minimumAbsoluteAccelerationForValidImpact __attribute__((swift_name("minimumAbsoluteAccelerationForValidImpact")));

/**
 * @return a flow with [ThroughputTest].
 */
@property (readonly) id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> throughputTest __attribute__((swift_name("throughputTest")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreSharedFlow")))
@protocol DynamicsMultiplatformKotlinx_coroutines_coreSharedFlow <DynamicsMultiplatformKotlinx_coroutines_coreFlow>
@required
@property (readonly) NSArray<id> *replayCache __attribute__((swift_name("replayCache")));
@end


/**
 * @note annotations
 *   kotlin.SubclassOptInRequired(markerClass=[NormalClass(value=kotlinx/coroutines/ExperimentalForInheritanceCoroutinesApi)])
*/
__attribute__((swift_name("Kotlinx_coroutines_coreStateFlow")))
@protocol DynamicsMultiplatformKotlinx_coroutines_coreStateFlow <DynamicsMultiplatformKotlinx_coroutines_coreSharedFlow>
@required
@property (readonly) id _Nullable value_ __attribute__((swift_name("value_")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreManufacturerData")))
@interface DynamicsMultiplatformCoreManufacturerData : DynamicsMultiplatformBase
- (instancetype)initWithCode:(int32_t)code data:(DynamicsMultiplatformKotlinByteArray *)data __attribute__((swift_name("init(code:data:)"))) __attribute__((objc_designated_initializer));

/**
 * Two-octet [Company Identifier Code][https://www.bluetooth.com/specifications/assigned-numbers/company-identifiers/]
 */
@property (readonly) int32_t code __attribute__((swift_name("code")));

/**
 * the Manufacturer Data (not including the leading two identifier octets)
 */
@property (readonly) DynamicsMultiplatformKotlinByteArray *data __attribute__((swift_name("data")));
@end


/**
 * [CompositeEncoder] is a part of encoding process that is bound to a particular structured part of
 * the serialized form, described by the serial descriptor passed to [Encoder.beginStructure].
 *
 * All `encode*` methods have `index` and `serialDescriptor` parameters with a strict semantics and constraints:
 *   * `descriptor` is always the same as one used in [Encoder.beginStructure]. While this parameter may seem redundant,
 *      it is required for efficient serialization process to avoid excessive field spilling.
 *      If you are writing your own format, you can safely ignore this parameter and use one used in `beginStructure`
 *      for simplicity.
 *   * `index` of the element being encoded. This element at this index in the descriptor should be associated with
 *      the one being written.
 *
 * The symmetric interface for the deserialization process is [CompositeDecoder].
 *
 * ### Not stable for inheritance
 *
 * `CompositeEncoder` interface is not stable for inheritance in 3rd party libraries, as new methods
 * might be added to this interface or contracts of the existing methods can be changed.
 */
__attribute__((swift_name("Kotlinx_serialization_coreCompositeEncoder")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreCompositeEncoder
@required

/**
 * Encodes a boolean [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.BOOLEAN] kind.
 */
- (void)encodeBooleanElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(BOOL)value __attribute__((swift_name("encodeBooleanElement(descriptor:index:value:)")));

/**
 * Encodes a single byte [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.BYTE] kind.
 */
- (void)encodeByteElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int8_t)value __attribute__((swift_name("encodeByteElement(descriptor:index:value:)")));

/**
 * Encodes a 16-bit unicode character [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.CHAR] kind.
 */
- (void)encodeCharElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(unichar)value __attribute__((swift_name("encodeCharElement(descriptor:index:value:)")));

/**
 * Encodes a 64-bit IEEE 754 floating point [value] associated with an element
 * at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.DOUBLE] kind.
 */
- (void)encodeDoubleElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(double)value __attribute__((swift_name("encodeDoubleElement(descriptor:index:value:)")));

/**
 * Encodes a 32-bit IEEE 754 floating point [value] associated with an element
 * at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.FLOAT] kind.
 */
- (void)encodeFloatElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(float)value __attribute__((swift_name("encodeFloatElement(descriptor:index:value:)")));

/**
 * Returns [Encoder] for decoding an underlying type of a value class in an inline manner.
 * Serializable value class is described by the [child descriptor][SerialDescriptor.getElementDescriptor]
 * of given [descriptor] at [index].
 *
 * Namely, for the `@Serializable @JvmInline value class MyInt(val my: Int)`,
 * and `@Serializable class MyData(val myInt: MyInt)` the following sequence is used:
 * ```
 * thisEncoder.encodeInlineElement(MyData.serializer.descriptor, 0).encodeInt(my)
 * ```
 *
 * This method provides an opportunity for the optimization to avoid boxing of a carried value
 * and its invocation should be equivalent to the following:
 * ```
 * thisEncoder.encodeSerializableElement(MyData.serializer.descriptor, 0, MyInt.serializer(), myInt)
 * ```
 *
 * Current encoder may return any other instance of [Encoder] class, depending on provided descriptor.
 * For example, when this function is called on Json encoder with descriptor that has
 * `UInt.serializer().descriptor` at the given [index], the returned encoder is able
 * to encode unsigned integers.
 *
 * Note that this function returns [Encoder] instead of the [CompositeEncoder]
 * because value classes always have the single property.
 * Calling [Encoder.beginStructure] on returned instance leads to an unspecified behavior and, in general, is prohibited.
 *
 * @see Encoder.encodeInline
 * @see SerialDescriptor.getElementDescriptor
 */
- (id<DynamicsMultiplatformKotlinx_serialization_coreEncoder>)encodeInlineElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("encodeInlineElement(descriptor:index:)")));

/**
 * Encodes a 32-bit integer [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.INT] kind.
 */
- (void)encodeIntElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int32_t)value __attribute__((swift_name("encodeIntElement(descriptor:index:value:)")));

/**
 * Encodes a 64-bit integer [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.LONG] kind.
 */
- (void)encodeLongElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int64_t)value __attribute__((swift_name("encodeLongElement(descriptor:index:value:)")));

/**
 * Delegates nullable [value] encoding of the type [T] to the given [serializer].
 * [value] is associated with an element at the given [index] in [serial descriptor][descriptor].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)encodeNullableSerializableElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeNullableSerializableElement(descriptor:index:serializer:value:)")));

/**
 * Delegates [value] encoding of the type [T] to the given [serializer].
 * [value] is associated with an element at the given [index] in [serial descriptor][descriptor].
 */
- (void)encodeSerializableElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index serializer:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy>)serializer value:(id _Nullable)value __attribute__((swift_name("encodeSerializableElement(descriptor:index:serializer:value:)")));

/**
 * Encodes a 16-bit short [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.SHORT] kind.
 */
- (void)encodeShortElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(int16_t)value __attribute__((swift_name("encodeShortElement(descriptor:index:value:)")));

/**
 * Encodes a string [value] associated with an element at the given [index] in [serial descriptor][descriptor].
 * The element at the given [index] should have [PrimitiveKind.STRING] kind.
 */
- (void)encodeStringElementDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index value:(NSString *)value __attribute__((swift_name("encodeStringElement(descriptor:index:value:)")));

/**
 * Denotes the end of the structure associated with current encoder.
 * For example, composite encoder of JSON format will write
 * a closing bracket in the underlying input and reduce the number of nesting for pretty printing.
 */
- (void)endStructureDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor __attribute__((swift_name("endStructure(descriptor:)")));

/**
 * Whether the format should encode values that are equal to the default values.
 * This method is used by plugin-generated serializers for properties with default values:
 * ```
 * @Serializable
 * class WithDefault(val int: Int = 42)
 * // serialize method
 * if (value.int != 42 || output.shouldEncodeElementDefault(serialDesc, 0)) {
 *    encoder.encodeIntElement(serialDesc, 0, value.int);
 * }
 * ```
 *
 * This method is never invoked for properties annotated with [EncodeDefault].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (BOOL)shouldEncodeElementDefaultDescriptor:(id<DynamicsMultiplatformKotlinx_serialization_coreSerialDescriptor>)descriptor index:(int32_t)index __attribute__((swift_name("shouldEncodeElementDefault(descriptor:index:)")));

/**
 * Context of the current serialization process, including contextual and polymorphic serialization and,
 * potentially, a format-specific configuration.
 */
@property (readonly) DynamicsMultiplatformKotlinx_serialization_coreSerializersModule *serializersModule __attribute__((swift_name("serializersModule")));
@end


/**
 * [SerializersModule] is a collection of serializers used by [ContextualSerializer] and [PolymorphicSerializer]
 * to override or provide serializers at the runtime, whereas at the compile-time they provided by the serialization plugin.
 * It can be considered as a map where serializers can be found using their statically known KClasses.
 *
 * To enable runtime serializers resolution, one of the special annotations must be used on target types
 * ([Polymorphic] or [Contextual]), and a serial module with serializers should be used during construction of [SerialFormat].
 *
 * Serializers module can be built with `SerializersModule {}` builder function.
 * Empty module can be obtained with `EmptySerializersModule()` factory function.
 *
 * @see Contextual
 * @see Polymorphic
 */
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModule")))
@interface DynamicsMultiplatformKotlinx_serialization_coreSerializersModule : DynamicsMultiplatformBase

/**
 * Copies contents of this module to the given [collector].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (void)dumpToCollector:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializersModuleCollector>)collector __attribute__((swift_name("dumpTo(collector:)")));

/**
 * Returns a contextual serializer associated with a given [kClass].
 * If given class has generic parameters and module has provider for [kClass],
 * [typeArgumentsSerializers] are used to create serializer.
 * This method is used in context-sensitive operations on a property marked with [Contextual] by a [ContextualSerializer].
 *
 * @see SerializersModuleBuilder.contextual
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer> _Nullable)getContextualKClass:(id<DynamicsMultiplatformKotlinKClass>)kClass typeArgumentsSerializers:(NSArray<id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>> *)typeArgumentsSerializers __attribute__((swift_name("getContextual(kClass:typeArgumentsSerializers:)")));

/**
 * Returns a polymorphic serializer registered for a class of the given [value] in the scope of [baseClass].
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy> _Nullable)getPolymorphicBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass value:(id)value __attribute__((swift_name("getPolymorphic(baseClass:value:)")));

/**
 * Returns a polymorphic deserializer registered for a [serializedClassName] in the scope of [baseClass]
 * or default value constructed from [serializedClassName] if a default serializer provider was registered.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
- (id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable)getPolymorphicBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass serializedClassName:(NSString * _Nullable)serializedClassName __attribute__((swift_name("getPolymorphic(baseClass:serializedClassName:)")));
@end

__attribute__((swift_name("KotlinAnnotation")))
@protocol DynamicsMultiplatformKotlinAnnotation
@required
@end


/**
 * Serial kind is an intrinsic property of [SerialDescriptor] that indicates how
 * the corresponding type is structurally represented by its serializer.
 *
 * Kind is used by serialization formats to determine how exactly the given type
 * should be serialized. For example, JSON format detects the kind of the value and,
 * depending on that, may write it as a plain value for primitive kinds, open a
 * curly brace '{' for class-like structures and square bracket '[' for list- and array- like structures.
 *
 * Kinds are used both during serialization, to serialize a value properly and statically, and
 * to introspect the type structure or build serialization schema.
 *
 * Kind should match the structure of the serialized form, not the structure of the corresponding Kotlin class.
 * Meaning that if serializable class `class IntPair(val left: Int, val right: Int)` is represented by the serializer
 * as a single `Long` value, its descriptor should have [PrimitiveKind.LONG] without nested elements even though the class itself
 * represents a structure with two primitive fields.
 */
__attribute__((swift_name("Kotlinx_serialization_coreSerialKind")))
@interface DynamicsMultiplatformKotlinx_serialization_coreSerialKind : DynamicsMultiplatformBase
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinRandom.Default")))
@interface DynamicsMultiplatformKotlinRandomDefault : DynamicsMultiplatformKotlinRandom
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
+ (instancetype)new __attribute__((unavailable));
+ (instancetype)default_ __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinRandomDefault *shared __attribute__((swift_name("shared")));
- (int32_t)nextBitsBitCount:(int32_t)bitCount __attribute__((swift_name("nextBits(bitCount:)")));
- (BOOL)nextBoolean __attribute__((swift_name("nextBoolean()")));

/**
 * @note annotations
 *   kotlin.IgnorableReturnValue
*/
- (DynamicsMultiplatformKotlinByteArray *)nextBytesArray:(DynamicsMultiplatformKotlinByteArray *)array __attribute__((swift_name("nextBytes(array:)")));
- (DynamicsMultiplatformKotlinByteArray *)nextBytesSize:(int32_t)size __attribute__((swift_name("nextBytes(size:)")));
- (DynamicsMultiplatformKotlinByteArray *)nextBytesArray:(DynamicsMultiplatformKotlinByteArray *)array fromIndex:(int32_t)fromIndex toIndex:(int32_t)toIndex __attribute__((swift_name("nextBytes(array:fromIndex:toIndex:)")));
- (double)nextDouble __attribute__((swift_name("nextDouble()")));
- (double)nextDoubleUntil:(double)until __attribute__((swift_name("nextDouble(until:)")));
- (double)nextDoubleFrom:(double)from until:(double)until __attribute__((swift_name("nextDouble(from:until:)")));
- (float)nextFloat __attribute__((swift_name("nextFloat()")));
- (int32_t)nextInt __attribute__((swift_name("nextInt()")));
- (int32_t)nextIntUntil:(int32_t)until __attribute__((swift_name("nextInt(until:)")));
- (int32_t)nextIntFrom:(int32_t)from until:(int32_t)until __attribute__((swift_name("nextInt(from:until:)")));
- (int64_t)nextLong __attribute__((swift_name("nextLong()")));
- (int64_t)nextLongUntil:(int64_t)until __attribute__((swift_name("nextLong(until:)")));
- (int64_t)nextLongFrom:(int64_t)from until:(int64_t)until __attribute__((swift_name("nextLong(from:until:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.3")
*/
__attribute__((swift_name("KotlinCoroutineContext")))
@protocol DynamicsMultiplatformKotlinCoroutineContext
@required
- (id _Nullable)foldInitial:(id _Nullable)initial operation:(id _Nullable (^)(id _Nullable, id<DynamicsMultiplatformKotlinCoroutineContextElement>))operation __attribute__((swift_name("fold(initial:operation:)")));
- (id<DynamicsMultiplatformKotlinCoroutineContextElement> _Nullable)getKey:(id<DynamicsMultiplatformKotlinCoroutineContextKey>)key __attribute__((swift_name("get(key:)")));
- (id<DynamicsMultiplatformKotlinCoroutineContext>)minusKeyKey:(id<DynamicsMultiplatformKotlinCoroutineContextKey>)key __attribute__((swift_name("minusKey(key:)")));
- (id<DynamicsMultiplatformKotlinCoroutineContext>)plusContext:(id<DynamicsMultiplatformKotlinCoroutineContext>)context __attribute__((swift_name("plus(context:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("CoreLocationState.Companion")))
@interface DynamicsMultiplatformCoreLocationStateCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformCoreLocationStateCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformCoreLocationState *)getLocationStateIsEnabled:(BOOL)isEnabled __attribute__((swift_name("getLocationState(isEnabled:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.9")
*/
__attribute__((swift_name("KotlinTimeMark")))
@protocol DynamicsMultiplatformKotlinTimeMark
@required
- (int64_t)elapsedNow __attribute__((swift_name("elapsedNow()")));
- (BOOL)hasNotPassedNow __attribute__((swift_name("hasNotPassedNow()")));
- (BOOL)hasPassedNow __attribute__((swift_name("hasPassedNow()")));
- (id<DynamicsMultiplatformKotlinTimeMark>)minusDuration:(int64_t)duration __attribute__((swift_name("minus(duration:)")));
- (id<DynamicsMultiplatformKotlinTimeMark>)plusDuration:(int64_t)duration __attribute__((swift_name("plus(duration:)")));
@end

__attribute__((swift_name("KotlinKCallable")))
@protocol DynamicsMultiplatformKotlinKCallable <DynamicsMultiplatformKotlinKAnnotatedElement>
@required
@property (readonly) NSString *name __attribute__((swift_name("name")));
@property (readonly) id<DynamicsMultiplatformKotlinKType> returnType __attribute__((swift_name("returnType")));
@end

__attribute__((swift_name("KotlinKProperty")))
@protocol DynamicsMultiplatformKotlinKProperty <DynamicsMultiplatformKotlinKCallable>
@required
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongProgression.Companion")))
@interface DynamicsMultiplatformKotlinLongProgressionCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinLongProgressionCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformKotlinLongProgression *)fromClosedRangeRangeStart:(int64_t)rangeStart rangeEnd:(int64_t)rangeEnd step:(int64_t)step __attribute__((swift_name("fromClosedRange(rangeStart:rangeEnd:step:)")));
@end

__attribute__((swift_name("KotlinLongIterator")))
@interface DynamicsMultiplatformKotlinLongIterator : DynamicsMultiplatformBase <DynamicsMultiplatformKotlinIterator>
- (instancetype)init __attribute__((swift_name("init()"))) __attribute__((objc_designated_initializer));
+ (instancetype)new __attribute__((availability(swift, unavailable, message="use object initializers instead")));
- (DynamicsMultiplatformLong *)next __attribute__((swift_name("next()")));
- (int64_t)nextLong __attribute__((swift_name("nextLong()")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinLongRange.Companion")))
@interface DynamicsMultiplatformKotlinLongRangeCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinLongRangeCompanion *shared __attribute__((swift_name("shared")));
@property (readonly) DynamicsMultiplatformKotlinLongRange *EMPTY __attribute__((swift_name("EMPTY")));
@end

__attribute__((swift_name("KotlinComparator")))
@protocol DynamicsMultiplatformKotlinComparator
@required
- (int32_t)compareA:(id _Nullable)a b:(id _Nullable)b __attribute__((swift_name("compare(a:b:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_bleGlovePeripheralServices")))
@interface DynamicsMultiplatformDynamics_bleGlovePeripheralServices : DynamicsMultiplatformBase
- (instancetype)initWithDeviceInformationService:(id<DynamicsMultiplatformBle_multiplexDeviceInformationService>)deviceInformationService genericAccessService:(id<DynamicsMultiplatformBle_multiplexGenericAccessService>)genericAccessService batteryService:(id<DynamicsMultiplatformBle_multiplexBatteryService>)batteryService operationConnectionService:(id<DynamicsMultiplatformDynamics_bleOperationConnectionService>)operationConnectionService customDeviceNameService:(id<DynamicsMultiplatformDynamics_bleCustomDeviceNameService>)customDeviceNameService impactConfigurationService:(id<DynamicsMultiplatformDynamics_bleImpactConfigurationService>)impactConfigurationService advertisingConfigService:(id<DynamicsMultiplatformDynamics_bleAdvertisingConfigService>)advertisingConfigService testAndErrorCodeService:(id<DynamicsMultiplatformDynamics_bleTestAndErrorService>)testAndErrorCodeService wakeUpConfigurationService:(id<DynamicsMultiplatformDynamics_bleWakeUpConfigurationService>)wakeUpConfigurationService dataPipeService:(id<DynamicsMultiplatformDynamics_bleDataPipeService>)dataPipeService bondingConfigurationService:(id<DynamicsMultiplatformDynamics_bleBondingConfigurationService>)bondingConfigurationService __attribute__((swift_name("init(deviceInformationService:genericAccessService:batteryService:operationConnectionService:customDeviceNameService:impactConfigurationService:advertisingConfigService:testAndErrorCodeService:wakeUpConfigurationService:dataPipeService:bondingConfigurationService:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformDynamics_bleGlovePeripheralServicesCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformDynamics_bleGlovePeripheralServices *)doCopyDeviceInformationService:(id<DynamicsMultiplatformBle_multiplexDeviceInformationService>)deviceInformationService genericAccessService:(id<DynamicsMultiplatformBle_multiplexGenericAccessService>)genericAccessService batteryService:(id<DynamicsMultiplatformBle_multiplexBatteryService>)batteryService operationConnectionService:(id<DynamicsMultiplatformDynamics_bleOperationConnectionService>)operationConnectionService customDeviceNameService:(id<DynamicsMultiplatformDynamics_bleCustomDeviceNameService>)customDeviceNameService impactConfigurationService:(id<DynamicsMultiplatformDynamics_bleImpactConfigurationService>)impactConfigurationService advertisingConfigService:(id<DynamicsMultiplatformDynamics_bleAdvertisingConfigService>)advertisingConfigService testAndErrorCodeService:(id<DynamicsMultiplatformDynamics_bleTestAndErrorService>)testAndErrorCodeService wakeUpConfigurationService:(id<DynamicsMultiplatformDynamics_bleWakeUpConfigurationService>)wakeUpConfigurationService dataPipeService:(id<DynamicsMultiplatformDynamics_bleDataPipeService>)dataPipeService bondingConfigurationService:(id<DynamicsMultiplatformDynamics_bleBondingConfigurationService>)bondingConfigurationService __attribute__((swift_name("doCopy(deviceInformationService:genericAccessService:batteryService:operationConnectionService:customDeviceNameService:impactConfigurationService:advertisingConfigService:testAndErrorCodeService:wakeUpConfigurationService:dataPipeService:bondingConfigurationService:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSUInteger)hash __attribute__((swift_name("hash()")));

/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleAdvertisingConfigService> advertisingConfigService __attribute__((swift_name("advertisingConfigService")));
@property (readonly) id<DynamicsMultiplatformBle_multiplexBatteryService> batteryService __attribute__((swift_name("batteryService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleBondingConfigurationService> bondingConfigurationService __attribute__((swift_name("bondingConfigurationService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleCustomDeviceNameService> customDeviceNameService __attribute__((swift_name("customDeviceNameService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleDataPipeService> dataPipeService __attribute__((swift_name("dataPipeService")));
@property (readonly) id<DynamicsMultiplatformBle_multiplexDeviceInformationService> deviceInformationService __attribute__((swift_name("deviceInformationService")));
@property (readonly) id<DynamicsMultiplatformBle_multiplexGenericAccessService> genericAccessService __attribute__((swift_name("genericAccessService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleImpactConfigurationService> impactConfigurationService __attribute__((swift_name("impactConfigurationService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleOperationConnectionService> operationConnectionService __attribute__((swift_name("operationConnectionService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleTestAndErrorService> testAndErrorCodeService __attribute__((swift_name("testAndErrorCodeService")));
@property (readonly) id<DynamicsMultiplatformDynamics_bleWakeUpConfigurationService> wakeUpConfigurationService __attribute__((swift_name("wakeUpConfigurationService")));
@end


/**
 * [SerializersModuleCollector] can introspect and accumulate content of any [SerializersModule] via [SerializersModule.dumpTo],
 * using a visitor-like pattern: [contextual] and [polymorphic] functions are invoked for each registered serializer.
 *
 * ### Not stable for inheritance
 *
 * `SerializersModuleCollector` interface is not stable for inheritance in 3rd party libraries, as new methods
 * might be added to this interface or contracts of the existing methods can be changed.
 *
 * @note annotations
 *   kotlinx.serialization.ExperimentalSerializationApi
*/
__attribute__((swift_name("Kotlinx_serialization_coreSerializersModuleCollector")))
@protocol DynamicsMultiplatformKotlinx_serialization_coreSerializersModuleCollector
@required

/**
 * Accept a provider, associated with generic [kClass] for contextual serialization.
 */
- (void)contextualKClass:(id<DynamicsMultiplatformKotlinKClass>)kClass provider:(id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer> (^)(NSArray<id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>> *))provider __attribute__((swift_name("contextual(kClass:provider:)")));

/**
 * Accept a serializer, associated with [kClass] for contextual serialization.
 */
- (void)contextualKClass:(id<DynamicsMultiplatformKotlinKClass>)kClass serializer:(id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)serializer __attribute__((swift_name("contextual(kClass:serializer:)")));

/**
 * Accept a serializer, associated with [actualClass] for polymorphic serialization.
 */
- (void)polymorphicBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass actualClass:(id<DynamicsMultiplatformKotlinKClass>)actualClass actualSerializer:(id<DynamicsMultiplatformKotlinx_serialization_coreKSerializer>)actualSerializer __attribute__((swift_name("polymorphic(baseClass:actualClass:actualSerializer:)")));

/**
 * Accept a default deserializer provider, associated with the [baseClass] for polymorphic deserialization.
 *
 * This function affect only deserialization process. To avoid confusion, it was deprecated and replaced with [polymorphicDefaultDeserializer].
 * To affect serialization process, use [SerializersModuleCollector.polymorphicDefaultSerializer].
 *
 * [defaultDeserializerProvider] is invoked when no polymorphic serializers associated with the `className`
 * in the scope of [baseClass] were found. `className` could be `null` for formats that support nullable class discriminators
 * (currently only `Json` with `useArrayPolymorphism` set to `false`).
 *
 * [defaultDeserializerProvider] can be stateful and lookup a serializer for the missing type dynamically.
 *
 * @see SerializersModuleCollector.polymorphicDefaultDeserializer
 * @see SerializersModuleCollector.polymorphicDefaultSerializer
 */
- (void)polymorphicDefaultBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass defaultDeserializerProvider:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefault(baseClass:defaultDeserializerProvider:)"))) __attribute__((deprecated("Deprecated in favor of function with more precise name: polymorphicDefaultDeserializer")));

/**
 * Accept a default deserializer provider, associated with the [baseClass] for polymorphic deserialization.
 * [defaultDeserializerProvider] is invoked when no polymorphic serializers associated with the `className`
 * in the scope of [baseClass] were found. `className` could be `null` for formats that support nullable class discriminators
 * (currently only `Json` with `useArrayPolymorphism` set to `false`).
 *
 * Default deserializers provider affects only deserialization process. Serializers are accepted in the
 * [SerializersModuleCollector.polymorphicDefaultSerializer] method.
 *
 * [defaultDeserializerProvider] can be stateful and lookup a serializer for the missing type dynamically.
 */
- (void)polymorphicDefaultDeserializerBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass defaultDeserializerProvider:(id<DynamicsMultiplatformKotlinx_serialization_coreDeserializationStrategy> _Nullable (^)(NSString * _Nullable))defaultDeserializerProvider __attribute__((swift_name("polymorphicDefaultDeserializer(baseClass:defaultDeserializerProvider:)")));

/**
 * Accept a default serializer provider, associated with the [baseClass] for polymorphic serialization.
 * [defaultSerializerProvider] is invoked when no polymorphic serializers for `value` in the scope of [baseClass] were found.
 *
 * Default serializers provider affects only serialization process. Deserializers are accepted in the
 * [SerializersModuleCollector.polymorphicDefaultDeserializer] method.
 *
 * [defaultSerializerProvider] can be stateful and lookup a serializer for the missing type dynamically.
 */
- (void)polymorphicDefaultSerializerBaseClass:(id<DynamicsMultiplatformKotlinKClass>)baseClass defaultSerializerProvider:(id<DynamicsMultiplatformKotlinx_serialization_coreSerializationStrategy> _Nullable (^)(id))defaultSerializerProvider __attribute__((swift_name("polymorphicDefaultSerializer(baseClass:defaultSerializerProvider:)")));
@end

__attribute__((swift_name("KotlinCoroutineContextElement")))
@protocol DynamicsMultiplatformKotlinCoroutineContextElement <DynamicsMultiplatformKotlinCoroutineContext>
@required
@property (readonly) id<DynamicsMultiplatformKotlinCoroutineContextKey> key __attribute__((swift_name("key")));
@end

__attribute__((swift_name("KotlinCoroutineContextKey")))
@protocol DynamicsMultiplatformKotlinCoroutineContextKey
@required
@end

__attribute__((swift_name("KotlinKType")))
@protocol DynamicsMultiplatformKotlinKType
@required

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) NSArray<DynamicsMultiplatformKotlinKTypeProjection *> *arguments __attribute__((swift_name("arguments")));

/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
@property (readonly) id<DynamicsMultiplatformKotlinKClassifier> _Nullable classifier __attribute__((swift_name("classifier")));
@property (readonly) BOOL isMarkedNullable __attribute__((swift_name("isMarkedNullable")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Ble_multiplexDeviceInformationService")))
@protocol DynamicsMultiplatformBle_multiplexDeviceInformationService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeviceInfoWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeviceInfo *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeviceInfo(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getFirmwareRevisionWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getFirmwareRevision(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getHardwareRevisionWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getHardwareRevision(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getManufacturerNameWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getManufacturerName(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getModelNumberWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getModelNumber(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSerialNumberWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSerialNumber(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Ble_multiplexGenericAccessService")))
@protocol DynamicsMultiplatformBle_multiplexGenericAccessService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeviceNameWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeviceName(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Ble_multiplexBatteryService")))
@protocol DynamicsMultiplatformBle_multiplexBatteryService
@required

/**
 * Read the battery level of the device.
 *
 * @return the [BatteryLevel]
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBatteryLevelWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBatteryLevel(completionHandler:)")));

/**
 * Read the power state from the battery status level characteristic.
 *
 * The [PowerState] is the mandatory field of the battery status level characteristic.
 *
 * @return [PowerState] as [Flow].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPowerStateWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformPowerState *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPowerState(completionHandler:)")));

/**
 * Observe the battery level of the device.
 *
 * @return [BatteryLevel] as [Flow].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeBatteryLevelWithCompletionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observeBatteryLevel(completionHandler:)")));

/**
 * Observe the power state from the battery status level characteristic.
 *
 * The [PowerState] is the mandatory field of the battery status level characteristic.
 *
 * @return [PowerState] as [Flow].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observePowerStateWithCompletionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observePowerState(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleOperationConnectionService")))
@protocol DynamicsMultiplatformDynamics_bleOperationConnectionService
@required

/**
 * Calibrates the time on the peripheral if necessary.
 *
 * The peripheral holds two timestamps:
 * - an absolute base time, in uint64 in second precision.
 * - a relative time stamp in precision of 1 Tick ≜ 100 ms
 *
 * The absolute timestamp is only updated if really necessary:
 * - if the peripheral's base time is ahead of the device's time.
 * - if the peripheral's base time is older than [absoluteTimeTolerance].
 *
 * The relative timestamp is updated more eagerly, as the MCU has a max error of 1.728 seconds
 * per day:
 * - if the absolute time stamp is set, then the relative timestamp is also always set.
 * - if the absolute + relative has diff of more than [relativeTimeTolerance], then the relative
 * is set.
 *
 * @param absoluteTimeTolerance the time tolerance at which the absoluteTime is
 * not being adjusted.
 * @param relativeTimeTolerance the time tolerance at which the relativeTime is
 * not being adjusted.
 *
 * @return [Instant] the current time of the peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)calibrateTimeAbsoluteTimeTolerance:(int64_t)absoluteTimeTolerance relativeTimeTolerance:(int64_t)relativeTimeTolerance completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinInstant *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("calibrateTime(absoluteTimeTolerance:relativeTimeTolerance:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAbsoluteReferenceTimestampWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinInstant *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAbsoluteReferenceTimestamp(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAllOperationalConfigsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllOperationalConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAllOperationalConfigs(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCurrentRelativeTimeCounterWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCurrentRelativeTimeCounter(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeactivateOfflineMeasurementModeTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeactivateOfflineMeasurementModeTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getOperationalStateWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformOperationalState *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getOperationalState(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getStatusAttachableWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformBoolean *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getStatusAttachable(completionHandler:)")));

/**
 * @return [GloveTime] the current time of the peripheral.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getTimeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformGloveTime *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getTime(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeOperationalStateWithCompletionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observeOperationalState(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeStatusAttachableWithCompletionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observeStatusAttachable(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setAbsoluteReferenceTimestampInstant:(DynamicsMultiplatformKotlinInstant *)instant completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinInstant *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setAbsoluteReferenceTimestamp(instant:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCurrentRelativeTimeCounterDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCurrentRelativeTimeCounter(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeactivateOfflineMeasurementModeTimeoutDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeactivateOfflineMeasurementModeTimeout(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setOperationalConfigsOption:(DynamicsMultiplatformOperationConfigOption *)option configs:(DynamicsMultiplatformAllOperationalConfigs *)configs completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllOperationalConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setOperationalConfigs(option:configs:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setOperationalStateState:(DynamicsMultiplatformOperationalState *)state completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformOperationalState *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setOperationalState(state:completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleCustomDeviceNameService")))
@protocol DynamicsMultiplatformDynamics_bleCustomDeviceNameService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeviceFullNameWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSString *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeviceFullName(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleImpactConfigurationService")))
@protocol DynamicsMultiplatformDynamics_bleImpactConfigurationService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBackToMeasurementIdleTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBackToMeasurementIdleTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapAnchorIndexWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapAnchorIndex(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapCombinationWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformCapCombination *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapCombination(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapDetectionDirectionWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapDetectionDirection(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapOptionsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformCapOptions *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapOptions(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapShapeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSArray<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapShape(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapShapeOffsetWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapShapeOffset(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCapSizeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCapSize(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCountOfPostImpactSamplesWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCountOfPostImpactSamples(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCountOfPreTriggerSamplesWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCountOfPreTriggerSamples(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getImpactConfigsForceRefresh:(BOOL)forceRefresh firmwareVersion:(NSString *)firmwareVersion completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllImpactConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getImpactConfigs(forceRefresh:firmwareVersion:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMagnetoMeterCalibrationOffsetValuesWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMagnetoMeterCalibrationOffsetValues(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMagnetoMeterCalibrationScaleValuesWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMagnetoMeterCalibrationScaleValues(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMaximumWaitingTimeForAbsValidationWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMaximumWaitingTimeForAbsValidation(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getMinimumAbsAccForValidImpactWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getMinimumAbsAccForValidImpact(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getWakeupTriggerDebounceTimeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getWakeupTriggerDebounceTime(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getWakeupTriggerThresholdWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getWakeupTriggerThreshold(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBackToMeasurementIdleTimeoutDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBackToMeasurementIdleTimeout(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapAnchorIndexIndex:(int32_t)index completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapAnchorIndex(index:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapCombinationOption:(DynamicsMultiplatformCapCombination *)option completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformCapCombination *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapCombination(option:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapDetectionDirectionVector3d:(DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *)vector3d completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<DynamicsMultiplatformBoolean *> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapDetectionDirection(vector3d:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapOptionsOptions:(DynamicsMultiplatformCapOptions *)options completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformCapOptions *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapOptions(options:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapShapeShape:(NSArray<id> *)shape completionHandler:(void (^)(DynamicsMultiplatformResourceResource<NSArray<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapShape(shape:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCapShapeOffsetOffset:(int32_t)offset completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCapShapeOffset(offset:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCountOfPostImpactSamplesCount:(int32_t)count completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCountOfPostImpactSamples(count:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setCountOfPreTriggerSamplesCount:(int32_t)count completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setCountOfPreTriggerSamples(count:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setImpactConfigsOption:(DynamicsMultiplatformImpactConfigOption *)option configs:(DynamicsMultiplatformAllImpactConfigs *)configs completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllImpactConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setImpactConfigs(option:configs:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setMagnetoMeterCalibrationOffsetValuesVector3d:(DynamicsMultiplatformVector3d<id> *)vector3d completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setMagnetoMeterCalibrationOffsetValues(vector3d:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setMagnetoMeterCalibrationScaleValuesVector3d:(DynamicsMultiplatformVector3d<id> *)vector3d completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformVector3d<id> *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setMagnetoMeterCalibrationScaleValues(vector3d:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setMaximumWaitingTimeForAbsValidationDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setMaximumWaitingTimeForAbsValidation(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setMinimumAbsAccForValidImpactGravity:(double)gravity completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setMinimumAbsAccForValidImpact(gravity:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setWakeupTriggerDebounceTimeDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setWakeupTriggerDebounceTime(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setWakeupTriggerThresholdGravity:(double)gravity completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setWakeupTriggerThreshold(gravity:completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleAdvertisingConfigService")))
@protocol DynamicsMultiplatformDynamics_bleAdvertisingConfigService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAdvertisingIntervalWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAdvertisingInterval(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAdvertisingTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAdvertisingTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAllAdvertisingConfigsForceRefresh:(BOOL)forceRefresh completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllAdvertisingConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAllAdvertisingConfigs(forceRefresh:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeepSleepAdvertisingIntervalWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeepSleepAdvertisingInterval(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeepSleepAdvertisingTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeepSleepAdvertisingTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setAdvertisingIntervalDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setAdvertisingInterval(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setAdvertisingTimeoutDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setAdvertisingTimeout(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setAllAdvertisingConfigsOption:(DynamicsMultiplatformAdvertisingConfigOption *)option configs:(DynamicsMultiplatformAllAdvertisingConfigs *)configs completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllAdvertisingConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setAllAdvertisingConfigs(option:configs:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeepSleepAdvertisingIntervalDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeepSleepAdvertisingInterval(duration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeepSleepAdvertisingTimeoutDuration:(int64_t)duration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeepSleepAdvertisingTimeout(duration:completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleTestAndErrorService")))
@protocol DynamicsMultiplatformDynamics_bleTestAndErrorService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getErrorCodeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getErrorCode(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getSelfTestOutputWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformSelfTestOutput *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getSelfTestOutput(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleWakeUpConfigurationService")))
@protocol DynamicsMultiplatformDynamics_bleWakeUpConfigurationService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getAllDeepSleepWakeUpConfigsForceRefresh:(BOOL)forceRefresh completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllDeepSleepWakeUpConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getAllDeepSleepWakeUpConfigs(forceRefresh:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeepSleepWakeDoubleTapAccConfigWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeepSleepWakeDoubleTapAccConfig(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeepSleepWakeUpAccConfigWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpAccConfig *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeepSleepWakeUpAccConfig(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDeepSleepWakeUpConfigurationWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpConfiguration *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDeepSleepWakeUpConfiguration(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setAllDeepSleepWakeUpConfigsOption:(DynamicsMultiplatformDeepSleepWakeUpConfigOption *)option config:(DynamicsMultiplatformAllDeepSleepWakeUpConfigs *)config completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformAllDeepSleepWakeUpConfigs *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setAllDeepSleepWakeUpConfigs(option:config:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeepSleepWakeDoubleTapAccConfigConfig:(DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc *)config completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpDoubleTapAcc *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeepSleepWakeDoubleTapAccConfig(config:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeepSleepWakeUpAccConfigConfig:(DynamicsMultiplatformDeepSleepWakeUpAccConfig *)config completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpAccConfig *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeepSleepWakeUpAccConfig(config:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDeepSleepWakeUpConfigurationConfig:(DynamicsMultiplatformDeepSleepWakeUpConfiguration *)config completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformDeepSleepWakeUpConfiguration *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDeepSleepWakeUpConfiguration(config:completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleDataPipeService")))
@protocol DynamicsMultiplatformDynamics_bleDataPipeService
@required

/**
 * Subscribes to the data pipe characteristic.
 *
 * [OperationalState] is required in order to adapt the decoding.
 *
 * @param operationalState a state to react and lookup the current operational state.
 * @return a flow of [DataPipePacket].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeDataPipeOperationalState:(id<DynamicsMultiplatformKotlinx_coroutines_coreStateFlow>)operationalState completionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observeDataPipe(operationalState:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeDataPipeRawWithCompletionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observeDataPipeRaw(completionHandler:)")));
@end


/**
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Dynamics_bleBondingConfigurationService")))
@protocol DynamicsMultiplatformDynamics_bleBondingConfigurationService
@required

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBondingModeInitialMaxAccelerationWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBondingModeInitialMaxAcceleration(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBondingModeTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBondingModeTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBondingModeTriggerStartTimeoutWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBondingModeTriggerStartTimeout(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBondingModeTriggerTimeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBondingModeTriggerTime(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getBondingSettingsWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformBondingSettings *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getBondingSettings(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getDisconnectTimeoutWithoutBondingWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getDisconnectTimeoutWithoutBonding(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPressureIncreaseTimeWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPressureIncreaseTime(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getPressureThresholdWithCompletionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getPressureThreshold(completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBondingModeInitialMaxAccelerationAcceleration:(double)acceleration completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBondingModeInitialMaxAcceleration(acceleration:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBondingModeTimeoutTimeout:(int64_t)timeout completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBondingModeTimeout(timeout:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBondingModeTriggerStartTimeoutTimeout:(int64_t)timeout completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBondingModeTriggerStartTimeout(timeout:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBondingModeTriggerTimeTimeout:(int64_t)timeout completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBondingModeTriggerTime(timeout:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setBondingSettingsSettings:(DynamicsMultiplatformBondingSettings *)settings completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformBondingSettings *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setBondingSettings(settings:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setDisconnectTimeoutWithoutBondingDisconnectTime:(int64_t)disconnectTime completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setDisconnectTimeoutWithoutBonding(disconnectTime:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setPressureIncreaseTimeTimeout:(int64_t)timeout completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setPressureIncreaseTime(timeout:completionHandler:)")));

/**
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)setPressureThresholdThreshold:(int32_t)threshold completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("setPressureThreshold(threshold:completionHandler:)")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Dynamics_bleGlovePeripheralServices.Companion")))
@interface DynamicsMultiplatformDynamics_bleGlovePeripheralServicesCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformDynamics_bleGlovePeripheralServicesCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformDynamics_bleGlovePeripheralServices *)doInitServicesBleScope:(DynamicsMultiplatformBle_multiplexBleScope *)bleScope coroutineScope:(id<DynamicsMultiplatformKotlinx_coroutines_coreCoroutineScope>)coroutineScope deviceInfo:(DynamicsMultiplatformDeviceInfo *)deviceInfo name:(NSString *)name isMock:(BOOL)isMock __attribute__((swift_name("doInitServices(bleScope:coroutineScope:deviceInfo:name:isMock:)")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection")))
@interface DynamicsMultiplatformKotlinKTypeProjection : DynamicsMultiplatformBase
- (instancetype)initWithVariance:(DynamicsMultiplatformKotlinKVariance * _Nullable)variance type:(id<DynamicsMultiplatformKotlinKType> _Nullable)type __attribute__((swift_name("init(variance:type:)"))) __attribute__((objc_designated_initializer));
@property (class, readonly, getter=companion) DynamicsMultiplatformKotlinKTypeProjectionCompanion *companion __attribute__((swift_name("companion")));
- (DynamicsMultiplatformKotlinKTypeProjection *)doCopyVariance:(DynamicsMultiplatformKotlinKVariance * _Nullable)variance type:(id<DynamicsMultiplatformKotlinKType> _Nullable)type __attribute__((swift_name("doCopy(variance:type:)")));
- (BOOL)isEqual:(id _Nullable)other __attribute__((swift_name("isEqual(_:)")));
- (NSUInteger)hash __attribute__((swift_name("hash()")));
- (NSString *)description __attribute__((swift_name("description()")));
@property (readonly) id<DynamicsMultiplatformKotlinKType> _Nullable type __attribute__((swift_name("type")));
@property (readonly) DynamicsMultiplatformKotlinKVariance * _Nullable variance __attribute__((swift_name("variance")));
@end


/**
 * Defines the interfaces to the ble operations for a specific address.
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("Ble_multiplexBleScope")))
@interface DynamicsMultiplatformBle_multiplexBleScope : DynamicsMultiplatformBase
- (instancetype)initWithAddress:(id)address operations:(id<DynamicsMultiplatformBle_multiplexBleOperationsProvider>)operations __attribute__((swift_name("init(address:operations:)"))) __attribute__((objc_designated_initializer));
@property (readonly) id address __attribute__((swift_name("address")));
@property (readonly) id<DynamicsMultiplatformBle_multiplexBleOperationsProvider> operations __attribute__((swift_name("operations")));
@end


/**
 * @note annotations
 *   kotlin.SinceKotlin(version="1.1")
*/
__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKVariance")))
@interface DynamicsMultiplatformKotlinKVariance : DynamicsMultiplatformKotlinEnum<DynamicsMultiplatformKotlinKVariance *>
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
- (instancetype)initWithName:(NSString *)name ordinal:(int32_t)ordinal __attribute__((swift_name("init(name:ordinal:)"))) __attribute__((objc_designated_initializer)) __attribute__((unavailable));
@property (class, readonly) DynamicsMultiplatformKotlinKVariance *invariant __attribute__((swift_name("invariant")));
@property (class, readonly) DynamicsMultiplatformKotlinKVariance *in __attribute__((swift_name("in")));
@property (class, readonly) DynamicsMultiplatformKotlinKVariance *out __attribute__((swift_name("out")));
+ (DynamicsMultiplatformKotlinArray<DynamicsMultiplatformKotlinKVariance *> *)values __attribute__((swift_name("values()")));
@property (class, readonly) NSArray<DynamicsMultiplatformKotlinKVariance *> *entries __attribute__((swift_name("entries")));
@end

__attribute__((objc_subclassing_restricted))
__attribute__((swift_name("KotlinKTypeProjection.Companion")))
@interface DynamicsMultiplatformKotlinKTypeProjectionCompanion : DynamicsMultiplatformBase
+ (instancetype)alloc __attribute__((unavailable));
+ (instancetype)allocWithZone:(struct _NSZone *)zone __attribute__((unavailable));
+ (instancetype)companion __attribute__((swift_name("init()")));
@property (class, readonly, getter=shared) DynamicsMultiplatformKotlinKTypeProjectionCompanion *shared __attribute__((swift_name("shared")));
- (DynamicsMultiplatformKotlinKTypeProjection *)contravariantType:(id<DynamicsMultiplatformKotlinKType>)type __attribute__((swift_name("contravariant(type:)")));
- (DynamicsMultiplatformKotlinKTypeProjection *)covariantType:(id<DynamicsMultiplatformKotlinKType>)type __attribute__((swift_name("covariant(type:)")));
- (DynamicsMultiplatformKotlinKTypeProjection *)invariantType:(id<DynamicsMultiplatformKotlinKType>)type __attribute__((swift_name("invariant(type:)")));
@property (readonly) DynamicsMultiplatformKotlinKTypeProjection *STAR __attribute__((swift_name("STAR")));
@end


/**
 * Provides BLE GATT operations for peripherals, for further information about the behavior of these operations, see
 * [com.juul.kable.Peripheral].
 *
 * @author Research Industrial Systems Engineering (RISE) Forschungs-, Entwicklungs- und Großprojektberatung GmbH
 */
__attribute__((swift_name("Ble_multiplexBleOperationsProvider")))
@protocol DynamicsMultiplatformBle_multiplexBleOperationsProvider
@required

/**
 * Pre-Condition: [Peripheral] with [address] needs to be added via [BlePeripheralManager.addPeripheral] first.
 *
 * Connects to the peripheral.
 *
 * If not successful, then an error is returned as [BleException] with [BleException.error]:
 * - [BleError.BondRemoval.RemoveBondByUserRequired] if running on an iOS platform that returns an error code for
 * which a user interaction needs to be done.
 * - [BleError.Operation.ConnectFailed] for any other connection related error.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)connectAddress:(id)address completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("connect(address:completionHandler:)")));

/**
 * Disconnects a previously connected peripheral.
 *
 * If not successful, then an error is returned as [BleException] with [BleException.error]:
 * - [BleError.Operation.DisconnectFailed]
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)disconnectAddress:(id)address completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("disconnect(address:completionHandler:)")));

/**
 * @return the [CommonDevice] instance for [address].
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)getCommonDeviceAddress:(id)address completionHandler:(void (^)(DynamicsMultiplatformResourceResource<id<DynamicsMultiplatformCommonDevice>> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("getCommonDevice(address:completionHandler:)")));

/**
 * Observes a characteristic for a peripheral, this function may throw a CancellationException in
 * cases where the Peripheral is not ready yet to observe or if the connection disconnects. It does not provide
 * proper error handling, so for better practice always restart observing characteristics if the peripheral connects.
 *
 * @throws [CancellationException] if the tasks to start the observation will fail, [CancellationException.cause]
 * will contain the underlying error.
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)observeAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid completionHandler:(void (^)(id<DynamicsMultiplatformKotlinx_coroutines_coreFlow> _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("observe(address:bleUuid:completionHandler:)")));

/**
 * Reads from a characteristic and may also return errors if the peripheral is not yet ready to perform this action
 * or if the action fails.
 *
 * If not successful, then an error is returned as [BleException] with [BleException.error]:
 * - [BleError.Operation.ReadFailed]
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)readAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinByteArray *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("read(address:bleUuid:completionHandler:)")));

/**
 * Reads the rssi
 *
 * If not successful, then an error is returned as [BleException] with [BleException.error]:
 * - [BleError.GenericError]
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)rssiAddress:(id)address completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformInt *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("rssi(address:completionHandler:)")));

/**
 * Reads from a characteristic and may also return errors if the peripheral is not yet ready to perform this action
 * or if the action fails.
 * If not successful, then an error is returned as [BleException] with [BleException.error]:
 * - [BleError.Operation.WriteFailed]
 *
 * @note This method converts instances of CancellationException to errors.
 * Other uncaught Kotlin exceptions are fatal.
*/
- (void)writeAddress:(id)address bleUuid:(DynamicsMultiplatformBle_multiplex_uuidBleUuid *)bleUuid byteArray:(DynamicsMultiplatformKotlinByteArray *)byteArray isWithResponse:(BOOL)isWithResponse completionHandler:(void (^)(DynamicsMultiplatformResourceResource<DynamicsMultiplatformKotlinUnit *> * _Nullable, NSError * _Nullable))completionHandler __attribute__((swift_name("write(address:bleUuid:byteArray:isWithResponse:completionHandler:)")));
@end

#pragma pop_macro("_Nullable_result")
#pragma clang diagnostic pop
NS_ASSUME_NONNULL_END
