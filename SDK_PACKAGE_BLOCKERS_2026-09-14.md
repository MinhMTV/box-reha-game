> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](GAME_STATUS.md), [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](TODO.md). Reviewed 17 September 2026; no tests rerun.

# Dynamics SDK Android package blockers — 2026-09-14

The Android collector is implemented in source against the supplied SDK's documented Kotlin API. **Native compilation is blocked; no working collector AAR, Unity APK, Bluetooth connection or hardware measurement has been established.** Two independent packaging problems were reproduced with the authoritative `C:\dynamics-sdk-main` bundle, SDK **0.25.6**. The bundle and production dependency versions remain unchanged.

## 1. Required resource 2.11.1 is absent

The normal build fails resolving `com.riseworld.launchpad.resource:resource:2.11.1`. The rich Gradle module for `dynamics-multiplatform:0.25.6` declares this requirement; the Android graph also requires it through `dynamics-multiplatform-android`, `dynamics-api-android`, `dynamics-db-android`, other SDK modules and `ble-multiplex-models-android:0.24.0`.

Authoritative metadata: `C:\dynamics-sdk-main\mavenLocal\com\riseworld\dynamics\multiplatform\dynamics-multiplatform\0.25.6\dynamics-multiplatform-0.25.6.module`, including the resource requirement around line 44. Gradle searched the supplied Maven repository, Google Maven and Maven Central; none supplied 2.11.1. The bundle contains 2.12.0, which does not satisfy an absent exact publication merely by existing alongside it.

Evidence: [standard build log](artifacts/validation/android-collector-build.log) and [machine-readable failed build report](artifacts/validation/android-collector-build.json). Reproduce from the game root with the installed Java 17 / Android API 36 toolchain:

```powershell
& .\scripts\verify-android-collector.ps1 -GradlePath 'C:\Users\manmi\.cache\codex-runtimes\android-qualification\gradle-8.13\bin\gradle.bat'
```

The harness uses Gradle 8.13, AGP 8.13.2, Kotlin 2.3.21 and a narrow compile-only UnityPlayer stub. That stub is not Unity runtime evidence. The missing dependency prevents this standard build from reaching collector compilation or its Android-module tests.

**Required vendor fix:** deliver the complete, internally consistent 0.25.6 Maven publication graph, including the required 2.11.1 publications, or publish an explicitly supported corrected SDK release and its matching graph. A version override is not an accepted production fix without vendor compatibility confirmation and qualification.

## 2. Android publications do not preserve the documented Kotlin API

A separately labelled diagnostic build temporarily selected the delivered resource 2.12.0 only to expose subsequent failures. This was an external diagnostic override, not a production or bundle modification. After resolving that graph, Kotlin compilation failed on documented API constructs such as `Power.Alpha`, `BleGloveState.Online`, `TrainingSessionSettings.Free`, SDK value-class IDs and duration properties. See [diagnostic compiler log](artifacts/validation/android-collector-DIAGNOSTIC-resource-2.12.log).

Read-only inspection of `classes.jar` inside the delivered Android AARs found:

| Android publication / inspected class | `kotlin.Metadata` | `InnerClasses` |
| --- | --- | --- |
| `dynamics-models-android:0.25.6` / `com.riseworld.dynamics.models.domain.punch.Power` | absent | absent |
| `dynamics-models-composite-android:0.25.6` / `com.riseworld.dynamics.composite.ble.BleGloveState` | present | absent |
| `ble-multiplex-models-android:0.24.0` / `com.riseworld.launchpad.ble.multiplex.models.domain.ScannerState` | present | absent |

The nested `$Alpha`, `$Online` and corresponding nested class files exist, but the inspected outer classes lack the nesting attributes needed to present the documented source API. The inspected classes have `r8-map-id-...` source attributes. These observations support a publication/minification defect; they do not establish the vendor's exact build configuration. Metadata is **not** uniformly absent from all inspected classes.

For comparison, `Power` in the supplied `dynamics-models-jvm:0.25.6` JAR retains both `kotlin.Metadata` and `InnerClasses`, and identifies `Punch.kt` as its source file. Its SHA-256 is `8F9DA5DC807299D04F1F39A2B8E5F3895E840DA7FAD1D8E5B2B76BDB58FE5A8E`; the same inspection report records the full path and nested ALPHA/DELTA entries. This comparison does not authorize substituting JVM artifacts for Android publications.

The Android `BodyProfile` bytecode additionally exposes an erased constructor with UUID/double parameters and `DefaultConstructorMarker`, plus a mangled `getId-vSVUwiQ()` method. Without the original Kotlin metadata this does not reconstruct the documented value-class-facing API for Kotlin callers. No reflection, mangled-name calls, replacement SDK classes or binary patching is used in the collector.

The [inspection evidence](artifacts/validation/android-sdk-metadata-inspection.txt) records these exact input files and SHA-256 hashes:

| AAR, relative to `C:\dynamics-sdk-main\mavenLocal` | SHA-256 |
| --- | --- |
| `com\riseworld\dynamics\multiplatform\dynamics-models-android\0.25.6\dynamics-models-android-0.25.6.aar` | `05F95B816ED3490B836588A5719D1B2DC8E45FB7C93301B9357CB967FB936DA0` |
| `com\riseworld\dynamics\multiplatform\dynamics-models-composite-android\0.25.6\dynamics-models-composite-android-0.25.6.aar` | `3207BC50915057022353CEAAEFE81093590B38DFD178C2348847506F1FF9F3E4` |
| `com\riseworld\launchpad\ble\ble-multiplex-models-android\0.24.0\ble-multiplex-models-android-0.24.0.aar` | `94B6789918B0A4B7E239E7112B5465C06D67989C0BB698075BED0A3519C60198` |

### Minimal independent reproduction

This two-line consumer, compiled with Kotlin 2.3.21 / Java 17 and the **Android** models AAR's extracted `classes.jar`, fails with `Unresolved reference 'Alpha'`. It does not include the collector, Unity, Android framework calls or a substituted resource dependency. The actual run is recorded in [minimal API probe log](artifacts/validation/android-sdk-minimal-api-probe.log).

```kotlin
import com.riseworld.dynamics.models.domain.punch.Power
fun isAlpha(value: Power): Boolean = value is Power.Alpha
```

To reproduce, extract a copy of `classes.jar` from the first AAR into a temporary directory as `models.jar`; leave the original AAR untouched. In a new independent Gradle project use:

```groovy
plugins { id 'org.jetbrains.kotlin.jvm' version '2.3.21' }
repositories { mavenCentral() }
kotlin { jvmToolchain(17) }
dependencies { implementation files('models.jar') }
```

Put the Kotlin snippet in `src/main/kotlin/DocumentedApi.kt`, provide a `settings.gradle` containing `rootProject.name = 'sdk-documented-api-probe'`, and execute Gradle 8.13 `compileKotlin` with Java 17. For bytecode inspection run:

```powershell
& 'C:\Program Files\Android\Android Studio\jbr\bin\javap.exe' -v -p -classpath .\models.jar com.riseworld.dynamics.models.domain.punch.Power
```

**Required vendor fix:** republish Android libraries preserving their public Kotlin API, relevant Kotlin metadata, generic signatures and nesting/enclosing attributes, or supply unminified Android artifacts. Validate the corrected Android publication with a fresh Kotlin consumer using the documented nested classes, value-class constructors/IDs, flows and duration properties. Consumer ProGuard rules cannot restore attributes already removed before publication. Once a corrected package exists, rerun the full collector compiler: the present blocker does not prove the remaining collector source error-free.

## Resolved configuration finding and remaining qualification

The SDK's AAR metadata requires **compileSdk 36 or newer**. The plugin and generated Unity `unityLibrary`/`launcher` integration now request at least 36, and the diagnostic build passed the AAR-metadata stage with API 36. This fixes that configuration error; it does not fix either package blocker above.

The Unity export hook preserves Unity's AGP/Gradle choice and configures external Kotlin 2.3.21. Its AGP-version guard and AGP 9 opt-outs express supported configuration intent, not a successfully built Unity player. An installed and functioning intended Unity 6.6 Android toolchain must still be exercised after the SDK package is corrected.

Independent checks actually completed on this source snapshot:

| Check | Result | Evidence boundary |
| --- | --- | --- |
| Production `CollectorPolicy.kt` through isolated Kotlin/JVM JUnit project | **11 tests passed**, no skipped/failures/errors | Synthetic UUID capacity, timestamp freshness/clock changes, pause/resume, same-family/device-side rules; no SDK or Android dependency. [Run log](artifacts/validation/android-policy-host.log), [test project](tests/android-policy/README.md). |
| Production Gradle-export transformation helper through .NET host | **13 checks passed** | Synthetic generated Gradle files; no Unity or actual exported-player build. [Run log](artifacts/validation/android-export-host.txt), [test project](tests/android-export/README.md). |
| Standard native Android module | **FAILED / BLOCKED**, zero module tests executed | Exact graph missing resource 2.11.1. |
| Diagnostic alternate dependency graph | **FAILED / BLOCKED** | Reached Kotlin compilation and exposed Android API metadata defects; alternate graph is not production qualification. |
| Unity APK, JNI delivery, permissions, BLE pairing/session and hardware measurements | **NOT VERIFIED** | Requires corrected SDK package, completed Unity toolchain and physical devices. |

The collector's source permits one or two uniquely sided devices from one SDK-reported family. A mixed ALPHA/DELTA or three-device session remains unsupported by this integration until its SDK lifecycle is established and validated. This is a software integration boundary, not a statement that the hardware is inherently incapable of it.
