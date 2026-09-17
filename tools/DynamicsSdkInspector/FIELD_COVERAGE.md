# SDK 0.25.6 field coverage

Inspected actual Android class signatures in sdk-api/public-api.txt; originals remain under C:/dynamics-sdk-main. Serialization enumerates all public readable getters/fields recursively rather than a selected gameplay field list.

- SensorDataPacket: relativeTimeCounter (packed Duration long), bleCounter, samplingRate, baroData, accData, gyroData, magnetoData; every list element is serialized.
- Punch: id, peripheralId, side, timestamp, areComputedValuesValid, speed, concrete power type.
- Speed: punchDuration/contactDuration (original packed Duration longs), peakAcceleration, peakVelocity, displacement.
- Power: concrete ALPHA impact/peakForceBasedOnBaro or DELTA powerIndex; additional readable fields are included automatically.
- PeripheralDto/Glove/NearbyGlove: every readable public property, nested device metadata/state/configuration where exposed. RSSI/firmware are never synthesized when absent.
- Session state/stats/pairs and phone barometer: every public readable property on each delivered value, preserving whole stats snapshots.

Original mangled getter names are mapped in _accessors. Class names/toString are retained. Unknown objects with no readable fields preserve class/representation. Cycles/depth limit/getter failures emit explicit serializationWarning/serializationError fields. Methods requiring arguments, private fields, native handles and hidden firmware/SDK state cannot be losslessly introspected; they are not claimed captured. No model-field truncation or list cap is applied. SDK getters returning a Flow do not themselves provide that Flow's emitted history; only explicitly subscribed streams above are observed.

Repeated computed snapshots are retained. Event counts are occurrences, not unique Punch counts; use original IDs to deduplicate offline. Per-device counters reset at recording start but live observation may continue after stop. Exported metadata includes start/end device metadata, latest raw packet/rates and observed counters. UTC and monotonic receipt timestamps remain separate from SDK source time.
