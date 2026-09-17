# Dynamics SDK Inspector

**APK built:** [DynamicsSdkInspector-debug.apk](DynamicsSdkInspector-debug.apk). Open this folder in Android Studio. [Build result](BUILD_RESULT.md).

Standalone Kotlin/Compose Android diagnostic app; no Unity code/assets or vendor binaries modified. Package `com.digitaldojo.sdkinspector`, min API 26, target 36. SDK Maven distribution: `C:/dynamics-sdk-main/mavenLocal` (override DYNAMICS_MAVEN_PATH or -PdynamicsMavenPath).

## Build

Java 17, Android SDK platform 36 and Gradle 9.1.0. Open this directory in Android Studio. Set local.properties sdk.dir for your machine. Run `gradlew.bat :app:assembleDebug` (or installed Gradle 9.1.0). APK: `app/build/outputs/apk/debug/app-debug.apk`.

SDK COMPATIBILITY is explicit in app/build.gradle: resource 2.11.1 → 2.12.0, copied Sdk0256Compat Java adapter and original four SHA-256 input gates. SDK AAR/JAR files are not patched. This is a separate app/database from Digital Dojo.

## Connect and inspect

Grant Nearby Devices permissions on Android 12+, location for BLE on API 26–30; allow notifications for visible recording status. Enable Bluetooth (and location services on older Android where needed). Initialize, Scan, inspect complete discovered metadata and Add LEFT/RIGHT. Side is never assigned by discovery order. With Raw sensor stream enabled, every saved peripheral receives its own raw Flow; observed SDK state controls connected labels. Family remains UNKNOWN until reported by the SDK.

Remove calls deleteGloveById and waits for saved/observed absence. Swap calls swapGloveSideForId and waits for a saved side change; its paired counterpart may also change. No application two-device cap is added; SDK rejections are logged. This does not establish mixed or 2+2 support.

The public GloveRepository inspected exposes no independent connect/disconnect API. SDK observation owns connection acquisition; Refresh/reconnect resubscribes. The Devices screen explains the restriction; physical power-off, Android Bluetooth settings or persistent Remove are available. No private manager/singleton bypass or new raw GATT connection is used.

Raw recording is primary. Optional computed sessions require explicitly entered SDK body fields and one selected family. SDK body values stay in its local database and are not added to recording metadata. Raw/computed coexistence is unverified: Raw sensor stream switch permits isolated experiments. Starting a computed session can be rejected by SDK pairing/session constraints.

## Record and export

START creates a unique directory, metadata.json and continuously streamed events.jsonl. STOP drains the writer before marking complete. Foreground connectedDevice service, notification Stop action and partial wake lock run only during active recording. SDK background disconnect timeout is set to 86400 seconds; actual lock/background continuity still requires hardware validation. Android can kill processes; an interrupted session retains complete=false, not a false clean stop.

Sessions lists retained recordings; EXPORT uses Android CreateDocument/Storage Access Framework to save a ZIP containing metadata.json and events.jsonl (plus recording-error.txt on writer failure). Share the saved ZIP through your file provider. DELETE requires confirmation; no automatic deletion. Current recording cannot be exported/deleted. Incomplete recordings remain exportable.

The writer uses a bounded 256-entry channel with suspending backpressure, not a dropping UI queue or unbounded recording list. UI retains 1000 recent previews (at most 8192 characters each) and refreshes about 10 Hz. Truncation is explicitly labelled and applies only to UI history, never JSONL. All raw packets delivered to our collectors are submitted individually; upstream SDK/OS/BLE buffering and loss are not under app control. UI counters are observed occurrences, not verified physical actions. Computed snapshots may repeat Punch IDs: all occurrences and the complete snapshot are retained for later deduplication by original ID.

## JSONL schema 1 and field coverage

Every line contains sequence, eventType, utcTimestamp, elapsedRealtimeNanos, device (peripheralId/family/side/role), sdkTimestamp or null, and payload. App-wide events have null peripheral ID/UNKNOWN role. Original SDK values are never replaced by friendly labels.

Public no-argument get*/is* accessors and public instance fields are serialized recursively, including nested packet arrays, sampling rates, firmware metadata, Punch Speed/Power and concrete class. `_accessors` preserves exact mangled JVM getter names; `_representation` preserves original toString. Packed Kotlin Duration longs are retained without inventing units. Raw sdkTimestamp is the original packed relativeTimeCounter, not UTC. Complete accData/gyroData/magnetoData/baroData arrays are kept, not only last samples.

Cycles, depth over 32, opaque classes and getter exceptions are explicitly represented; no inaccessible private field is read. No promise of recovering SDK-internal state or fields not exposed to public getters. `sdk-api/public-api.txt` records inspected signatures. See FIELD_COVERAGE.md.

ALPHA impact/peakForceBasedOnBaro and DELTA powerIndex retain their names. **DELTA powerIndex is NOT interpreted as physical force.** No force units, clock alignment, technique recognition or packet-loss accuracy are inferred.

Implemented observers: per-device raw packets, saved peripherals, discovered/scanner state, observed gloves/device metadata, glove pairs, active session state/stats and every observed computed Punch, plus smartphone barometer when SDK supplies it. Commands/results/errors and app/permission/Bluetooth transitions are recorded during an active recording. No firmware erase/calibration/test command is automatically invoked to discover additional streams.

No physical sensor validation or screenshots were performed. Background/throughput, SDK firmware stream interaction and every multi-device combination require real hardware.

Android foreground-service reference: https://developer.android.com/develop/background-work/services/fgs/declare


## Sensor setup fix � 18 September 2026

The previous Kotlin caller emitted `deleteGloveById(PeripheralId, Continuation)` although the shipped binary only has `deleteGloveById-gP7SR54(Uuid, Continuation)`. Swap and per-device raw observation have the same value-class ABI mismatch. Both apps now use identical Sdk0256Compat.java / SdkDeviceOperations.kt adapters for those exact public descriptors, preserving the suspend continuation. Vendor binaries remain unchanged. Pair uses the existing public `PairingRepository.pair`, then confirms the returned PeripheralId in savedPeripherals; removal awaits both saved and observed-device absence; swap awaits persisted side change. No pair reconstruction is needed for public repository deletion.

Discovery is subscription-driven: nearbyGloves collects SDK nearby peripherals when subscribed (verified repository constructor/l4/k4 bytecode). It exposes address/name/RSSI, not a PeripheralId or sensor family; PeripheralId is returned by pairing. Do not infer family from SG names or invent an ID before pairing. Inspector now gates Scan by SDK initialization, BLE feature, permissions, Bluetooth and legacy location services. Android settings changes are reflected by the 10 Hz state publisher. Scanner failures remain visible; stop and scan again after correcting prerequisites.

Devices, Live, Log and Sessions use dark Material 3 cards. Raw stream defaults OFF and never disconnects a glove. Live renders last observed vector samples while JSONL retains every full packet and snapshot. Fresh Punch cues exclude the first historical snapshot and repeated IDs in unchanged snapshots. SDK sampling-rate enum getters are retained, including actual IMU/barometer Hz. UI status and recording counters are published at 10 Hz; the recorder is not sampled.

Unity setup now uses an explicit stable discovery selection and actual SDK session-presence / mutation flags instead of treating every non-idle error label as an active session. Real active sessions still require End SDK session. Single-family and maximum-one-pair Unity gameplay guards remain; Inspector has no app two-device cap. Physical scan, pair, remove, swap and simultaneous sensor operation still require device validation.
