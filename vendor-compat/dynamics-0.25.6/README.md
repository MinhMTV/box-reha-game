# Dynamics 0.25.6 local compatibility workspace

This is an application-side compatibility layer, not an official SDK release. `C:\dynamics-sdk-main` remains authoritative and read-only. No AAR, JAR, Kotlin metadata or class bytecode is rewritten. Development uses Windows; physical acquisition runs in the Android player.

## Modes

`VENDOR-UNCHANGED` is the default. It preserves dependency resolution and reproduces the missing `com.riseworld.launchpad.resource:resource:2.11.1` error. It means unchanged **vendor inputs**, not that the application's collector predates its Java adapter. The separate original Kotlin minimal consumer preserves that original source-level failure too.

`COMPATIBILITY` explicitly resolves resource/resource-android 2.11.1 to the supplied 2.12.0. The application Java adapter handles nested types directly and eight public mangled method descriptors through reflection. Four critical Android AAR hashes are pinned by `verifyDynamicsAbiInputs`. Runtime status and the research build identity include the build mode. No mock provider substitutes for missing hardware.

## Reproduce

From the game repository in PowerShell:

```powershell
$gradle = 'C:\Users\manmi\.cache\codex-runtimes\android-qualification\gradle-8.13\bin\gradle.bat'
.\scripts\verify-android-collector.ps1 -GradlePath $gradle -SdkMode VENDOR-UNCHANGED
.\scripts\verify-android-collector.ps1 -GradlePath $gradle -SdkMode COMPATIBILITY
.\scripts\verify-unity.ps1 -BuildCandidate -SdkMode COMPATIBILITY
python vendor-compat/dynamics-0.25.6/inspect_resource_abi.py
```

The first command is expected to fail. After dependencies are cached, `-Offline` makes either native mode reproducible without repository retries. Reports are written directly to separate mode directories; a file lock rejects concurrent use of the shared native harness. Native reports are copied to separate `artifacts/validation/VENDOR-UNCHANGED` and `COMPATIBILITY` folders. Unity requires the exact installed Editor plus Android support. For an interactive Editor, set `DYNAMICS_SDK_MODE=COMPATIBILITY` in its launching environment; already running editors do not inherit later shell changes.

Minimal consumers (`probe/original` fails at `Power.Alpha`; `probe/java` compiles Java nested types and raw/computed flow entry points):

```powershell
$env:JAVA_HOME = 'C:\Program Files\Android\Android Studio\jbr'
$env:ANDROID_HOME = "$env:LOCALAPPDATA\Android\Sdk"
$env:DYNAMICS_MAVEN_PATH = 'C:\dynamics-sdk-main\mavenLocal'
& $gradle --no-daemon --console=plain -p vendor-compat/dynamics-0.25.6/probe -Pprobe=original compileDebugKotlin
& $gradle --no-daemon --console=plain -p vendor-compat/dynamics-0.25.6/probe -Pprobe=java assembleDebug
& $gradle --no-daemon --console=plain -p tests/android-policy test
```

## Source and evidence

- `Assets/Plugins/Android/DynamicsSdkUnityBridge.androidlib/src/main/java/com/boxreha/dynamics/Sdk0256Compat.java`: adapter and ABI descriptor checks.
- Plugin `build.gradle`: explicit mode, replacement rule, input hashes.
- Plugin `consumer-rules.pro`: retain exact reflection targets through stripping.
- `Assets/Editor/DynamicsGradleExportConfig.cs`: same replacement for all generated Unity Gradle modules, after plugin declarations.
- `evidence/original-sha256.json`: pre-change inventory of every authoritative SDK file; `original-integrity.json` records comparison after execution.
- `evidence/resource-linkage.json`: all 15 resource member references resolve against 2.12.0. This is static ABI evidence, not semantic equivalence to unavailable 2.11.1.
- `evidence/minimal-*`: independent compiler reproduction and successful Java consumer.
- `topology/TopologyPolicyTest.kt`: seven application-policy topology fixtures, not physical tests.

See root `SDK_COMPATIBILITY_REPORT.md` and `MULTI_SENSOR_REPORT.md`. Vendor permission to redistribute its binaries is not inferred; this workspace contains application code, scripts and inspection evidence only.
