> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](GAME_STATUS.md), [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](TODO.md). Reviewed 17 September 2026; no tests rerun.

> Update 2026-09-14: the explicit SDK COMPATIBILITY mode now passes full native compilation/tests and a real Unity 6000.6.0f1 APK build. Hardware remains untested. Current authority: root ANDROID_STATUS.md and SDK_COMPATIBILITY_REPORT.md. Older blocked-build statements below are historical.

# Android continuation: implementation and validation

The user selected **Windows development with the complete Unity game and Dynamics SDK running together on Android**. OnePlus 15 or Samsung Galaxy Tab S3 are possible target devices. This record is software-development evidence, not a successful APK, sensor qualification or study result. Current readiness remains **RED**.

## Source changes

The native Android collector now implements initialization, Android permission requests, BLE discovery, persistent pairing/removal with explicit sides, SDK body-profile configuration, session start/pause/resume/finish and computed-event forwarding against SDK 0.25.6's documented API. It owns one session and accepts one device or a left/right pair of one reported family. ALPHA maps to punches; the separate DELTA mode maps to experimental foot/kick input. The planned two ALPHA gloves plus one DELTA simultaneously are not supported by this collector until a matching SDK route is confirmed.

Unity now presents connection/profile/session steps, explicit development input, touch pause/finish and landscape/safe-area layout. Start/resume requires a matching request, participant, profile and family acknowledgement. Status freshness uses a three-second gate around the one-second native heartbeat; stale state pauses the game. Targets use only connected sides; DELTA excludes punch-only heavy/chains. These are source-level behaviors; rendering, JNI and physical use remain unverified.

The bridge preserves original SDK event identity, quantity and Unix source time. Android emission and callback age are measured in Android's monotonic clock, then Unity queue age is included separately. Absolute clock origins are not equated. Missing/invalid Android emission timing fails closed. SDK-generated measurements retain unknown units where the documentation gives no physical unit. Game magnitude remains neutral without measured calibration.

JSONL adds optional sanitized acquisition snapshots. The companion analyzer accepts legacy logs, checks reported participant/device/connection/family/side consistency and validates optional transport-age components. It does not turn configuration metadata into sensor samples or coverage measurements. The SDK's local body-profile/session database is a separate storage obligation; a profile ID alone is not an immutable profile version.

## Executed checks

| Check | Actual result | Boundary / artifact |
|---|---|---|
| Existing .NET sensor/input/gameplay/logger/history harness | 26 host groups passed | Production logic with narrow Unity stubs; `sensor-host-checks.txt` and exact linked hashes in `sensor-host-source-manifest.json`. |
| Android state/profile/family/ack/freshness/transport policies | 47 assertions passed | Synthetic reported states, no JNI/SDK/device execution; same host log. |
| C# syntax | 67 files × 5 symbol configurations; zero errors | Includes Android Editor and Android player branches; no Unity API type resolution. `csharp-syntax.json`. |
| Static scenes/assets | 635 checks passed | Serialized source/reference checks, not rendered scenes. `static-scene-checks.json`. |
| Kotlin production collector policy | 11 JUnit tests passed | Independent JVM project without SDK/Android; `android-policy-host.log` and copied JUnit XML. |
| Generated Gradle export transformation | 13 .NET host checks passed | Synthetic export files; no actual Unity export. `android-export-host.txt`. |
| Python study/gameplay analysis | 60 tests passed; production synthetic logger replay passed | Companion thesis `analysis/validation`; no empirical data. |
| Standard native Android library build | FAILED before compilation | Exact SDK graph cannot resolve resource 2.11.1; `android-collector-build.json` and log. Zero Android-module tests executed. |
| Separate diagnostic resource 2.12.0 build | FAILED in Kotlin compilation | API 36 metadata check passed, then documented model APIs were unavailable. Does not qualify a supported SDK graph. |
| Independent two-line SDK Kotlin consumer | Reproduced `Power.Alpha` compilation failure | Confirms a package API problem independently of collector source. `android-sdk-minimal-api-probe.log`. |
| Unity Editor/Android APK/JNI/BLE | NOT RUN / NOT VERIFIED | User is installing Unity 6.6. Project still records 2022.3.62f3; no migration or APK claim. |

All game artifacts above live in `artifacts/validation/`. The companion thesis was updated and rebuilt separately; its precise PDF hash/build/visual-review record is `E:\Programming Projekte\latex_diplom\validation\pdf-review.json`. The expose and authoritative SDK were not modified.

## Confirmed package blockers

1. SDK 0.25.6 requests `com.riseworld.launchpad.resource:resource:2.11.1`, absent from the supplied repository and queried public repositories. Only 2.12.0 is delivered. The production build does not override it.
2. Inspected Android model classes lack attributes needed for the documented Kotlin API. `Power` lacks both Kotlin metadata and inner-class attributes; inspected `BleGloveState`/`ScannerState` retain Kotlin metadata but lack inner-class attributes. A minimal independent consumer reproduces the nested-class failure. The exact AAR hashes, inspection and requested vendor correction are in `SDK_PACKAGE_BLOCKERS_2026-09-14.md`.

The diagnostic override lives outside production configuration. No SDK bytecode patch, JVM-for-Android substitution, reflection or mangled binary-name adapter was introduced. A corrected publication must be compiled against the full collector again; current blocked compilation does not establish that every remaining SDK call is correct.

## Review findings and fixes

| Finding | Fix and evidence |
|---|---|
| Late SDK `running` could acknowledge another start/participant | Request IDs, participant/profile/family correlation and monotonic status sequence; host assertions. |
| Collector status could remain `running` after callback silence or JNI failure | Status freshness gate and automatic gameplay pause; native heartbeat; host clock-boundary checks. |
| JNI callback queue wait was absent from event age | Same Android clock measured at emission and callback; source/transport/Unity queue ages remain distinct. Host timing assertions; real transport still unverified. |
| Rejected native participant change could not be retried | Reissue selection until the current study ID is acknowledged. |
| Observer registration could race immediate startup failure | Register lazy jobs before starting subscriptions; source cross-review. |
| Native dedup capacity could silently stop events | Explicit disarm/error; reset only for a new owned SDK session; Kotlin policy tests. |
| Build hash could be invalidated by Android PlayerSettings changes | Separate Android preparation before source stamping; later build verifies frozen source. |
| Native-to-C# callbacks are addressed by string during IL2CPP builds | `Assets/link.xml` explicitly retains the `DynamicsSdkBridge` endpoint. XML inspected; actual IL2CPP runtime remains a separate gate. |
| Existing API 35 configuration conflicts with SDK AAR metadata | Compile/target API 36 and generated-module compile API checks. Diagnostic AAR metadata stage passed. |

## Reproduction and next executable gate

Use `scripts/verify-android-collector.ps1` for the exact native graph; `tests/android-policy` and `tests/android-export` for their explicitly limited host checks. The standalone toolchain is Gradle 8.13 / AGP 8.13.2 / Kotlin 2.3.21 / Java 17 / Android API 36. Unity 6.6 uses its own bundled Gradle/AGP toolchain, which remains untested here; the export hook configures Kotlin and repositories without silently replacing those tools.

After obtaining a corrected SDK bundle and finishing Unity 6.6 Android installation, import the existing project, review the actual migration, and follow `SETUP_GUIDE.md` to run `scripts/verify-unity.ps1 -UnityPath ... -BuildCandidate`. Its default target is Android. A separate explicit `WindowsDevelopment` target remains for development checks. Record APK installation, actual OS/ABI, device/firmware IDs, permissions, background/reconnect, side mapping and independent physical-event labels before making runtime or scientific claims.
