# Dynamics SDK Inspector

Standalone Kotlin/Material 3 Android app, SDK 0.25.6 COMPATIBILITY, API 26–36. Vendor binaries unchanged.

## Build

Java 17: gradlew.bat :app:assembleDebug
Authoritative APK: app/build/outputs/apk/debug/app-debug.apk. Older copied APKs are not automatically refreshed.

## Sensor lifecycle — ALPHA and DELTA

Scan subscribes to nearbyGloves; Stop cancels the subscription. Actual scannerState drives the indicator. Grant Bluetooth permissions; API 26–30 also requires location services/permission.

Pair uses the real advertising name and explicit LEFT/RIGHT. The Java adapter extracts the returned PeripheralId without reflecting Resource internals. Saved and runtime flows confirm success. Occupied sides are rejected. One same-family sensor or LEFT/RIGHT pair is supported. Discovery has no authoritative family; a connected mixed-family addition is removed after SDK identification.

savedPeripherals means persisted; observeGloves supplies online/connecting/bond/error state. Missing runtime devices become SAVED/OFFLINE. Unknown families remain visible. REMOVE uses deleteGloveById and its documented BLE deinitialization semantics, then waits for absence in both flows. Confirmed FORGET ALL calls deleteAllGloves. Inconsistent removal reports SDK_STATE_INCONSISTENCY. SWAP calls swapGloveSideForId and waits for actual saved/runtime side changes, including a paired counterpart. Active training sessions block mutations. No fake disconnect-but-keep-saved button exists.

Roles: ALPHA LEFT_HAND/RIGHT_HAND, DELTA LEFT_FOOT/RIGHT_FOOT. SDK identity, family, side and name remain in exports. Mixed ALPHA/DELTA and simultaneous 2+2 acquisition are not qualified.

## Acquisition

Modes: IDLE, RAW, COMPUTED. RAW and COMPUTED are mutually exclusive pending hardware evidence.

RAW uses exactly one observeSensorData(peripheralId) collector per saved ID for either family. Inspected bytecode loads the saved DTO and subscribes to continuous packet observation. Each emission is List<SensorDataPacket>; every packet and all channel samples are recorded. The alternative all-device collector is not also subscribed.

States: OFF, STARTING, SUBSCRIBED — NO PACKETS, STREAMING, ERROR. Live shows operational state, rate, packet age, counters, sampling frequency and latest samples. Subscription does not establish physical delivery. UI previews are throttled to 8 Hz/device, recording is not sampled.

COMPUTED checks for an existing session, creates the required SDK body profile, initializes, readies ALPHA or DELTA, resumes and awaits Resumed. Finish awaits null activeTrainingSessionTime. Existing sessions may be explicitly finished/discarded; never automatically deleted. Punch snapshots are deduplicated by actual UUID. The SDK uses Punch with family-specific Power: ALPHA impact/peakForceBasedOnBaro, DELTA powerIndex. DELTA powerIndex is not force/Newtons.

## Recording

Record runs the foreground connectedDevice service with notification and wake lock. Buffered IO consumes a bounded 256-entry suspending queue, without intentional drops. Queue depth and RECORDING_BACKLOG are visible. Upstream BLE/SDK losses cannot be excluded.

Writes go to events.jsonl.partial, flushed periodically. Clean Stop drains/closes and finalizes events.jsonl. Partial files survive interruption and remain ZIP-exportable. Background disconnect timeout defaults to one second, extends only while recording, and restores on Stop/failure.

Manual MARK STRAIGHT / HOOK / UPPERCUT / KICK / CUSTOM append ANNOTATION with UTC, monotonic time and selected device identity. These labels do not classify movements.

Schema 2 retains full arrays, source counters, sampling frequencies, flowEmissionSequence and packetIndexInEmission. Kotlin Duration packed value and converted nanoseconds are separate. Sample order is preserved without fabricated per-sample timestamps. Counter discontinuities do not assert packet loss.

Metadata includes app/SDK/Android versions, device model, session times, sensors and acquisition mode. Body-profile demographics are excluded from research exports. See FIELD_COVERAGE.md.

## ABI

Shipped 0.25.6 value-class methods use deleteGloveById-gP7SR54(Uuid, Continuation), swapGloveSideForId-gP7SR54(Uuid, Continuation), and observeSensorData-16HgSWs(Uuid). Pair/deleteAllGloves keep unmangled names. Some Java generic/nested metadata is stripped. Both apps use the same checked Java adapter and unchanged vendor artifacts.

Build success does not prove physical pairing, raw throughput, background continuity or DELTA hardware behavior; those remain user hardware checks.
