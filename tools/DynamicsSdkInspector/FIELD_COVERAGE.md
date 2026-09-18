# SDK 0.25.6 field coverage — schema 2

- RAW: relativeTimeCounter packed Duration plus converted seconds/nanoseconds, bleCounter, samplingRate name/IMU/barometer frequencies; complete ordered accData, gyroData, magnetoData, baroData arrays. Units: m/s², degrees/second, µT, Pa. Empty channels stay empty.
- Envelope: UTC, elapsedRealtimeNanos, global event sequence, per-subscription flowEmissionSequence, packetIndexInEmission, PeripheralId/address/SDK name/family/side/role. RAW_STATE marks subscription restart.
- Computed: actual Punch UUID, peripheral ID, side, timestamp, validity, all Speed quantities, concrete Power fields. ALPHA impact and peakForceBasedOnBaro; DELTA powerIndex. One event per newly observed UUID.
- Device: saved identity/name/address/side/bond, mock flag, firmware/hardware/model/manufacturer; runtime family/online/connecting/bond/error/battery/charging/barometer and operational state.
- Session, scan, raw-state, operation results, root exceptions, phone barometer and manual annotations are recorded while recording.

Explicit serializers replace recursive reflection on packet/Resource paths. Coverage is of exposed measurements, not private SDK state or all firmware configuration. UI shows latest samples and throttled previews; JSONL preserves full observed packets. Channel order is retained without invented per-sample timestamps. Counter discontinuities are not proof of packet loss. SDK body-profile demographics are not exported. Interrupted partial recordings remain exportable.
