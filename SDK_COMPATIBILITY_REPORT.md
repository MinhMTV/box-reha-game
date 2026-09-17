> Current scope reviewed 17 September 2026: same-family single/pair is implemented application policy, not qualified physical acquisition. Mixed ALPHA+DELTA and clean 2+2 are blocked/not implemented. Current artifact: [ANDROID_STATUS.md](ANDROID_STATUS.md); remaining work: [TODO.md](TODO.md). Dated build/probe results below retain their original evidence scope.

# Dynamics SDK 0.25.6 — compatibility engineering report

Date: 2026-09-14. Highest demonstrated stage: **LEVEL 5, real Unity Android APK**. No authorized ADB device was present. This dated build report is superseded on hardware evidence: the user subsequently installed/launched the APK, discovered ALPHA SG devices and observed paired/connected UI. Real punch/calibration/DELTA/mixed behavior remains unverified.

## Original package and independent reproduction

The authoritative package is `C:\dynamics-sdk-main`; all its files were inventoried before work. The exact unchanged native dependency build fails because `resource:2.11.1` is absent. Only 2.12.0 is supplied. Original log/report: `vendor-compat/dynamics-0.25.6/evidence/vendor-unchanged-build.*`.

After the separate dependency-only replacement, a minimal Kotlin consumer importing `Power` and evaluating `value is Power.Alpha` fails with unresolved `Alpha`. This was independently reproduced during this run with Kotlin 2.3.21 / AGP 8.13.2 / Gradle 8.13. The public Android nested classes physically exist, but critical `InnerClasses`, generic signatures and Kotlin metadata were stripped. `javap` evidence is retained. JVM artifacts were inspected historically for comparison and are **not** substituted into Android production.

## Escalation and decision

1. **Dependency compatibility:** explicit application Gradle rule redirects only resource/resource-android 2.11.1 to 2.12.0. It resolves the graph. A read-only constant-pool audit finds 15 distinct Resource fields/methods referenced by supplied Android AARs; all descriptors resolve. The unavailable 2.11.1 binary cannot be behaviorally compared.
2. **Java adapter:** successful minimal Java consumer uses `Power$Alpha` directly. Java also accesses ALPHA/DELTA fields, nested session/scanner/connection states, body validation ranges, body constructors and Free session settings. It avoids manufacturing metadata.
3. **Narrow reflection:** Java cannot express identifiers containing `-`. `Sdk0256Compat` checks exact public owners, parameter and return types for peripheral/punch/profile UUIDs, boxed PeripheralId, packed Kotlin durations and Kotlin's own duration-to-seconds conversion. There is no private field probing, accessibility override, guessed class search or hand-written packed-duration conversion. Failure disables acquisition; linkage failures are also handled explicitly.
4. **Bytecode repair:** unnecessary and not performed. No annotation reconstruction, Android/JVM artifact swap, class removal or obfuscation reversal was used.

The local adapter is pinned to exact SHA-256 values of models, composite models, BLE models and resource Android AARs. The source Gradle task rejects changed inputs. ProGuard consumer rules retain reflective classes/methods. Tests instantiate the actual supplied SDK model classes; those synthetic fixtures never enter the game or research data.

## Changed integration files

- Native plugin `build.gradle`, `consumer-rules.pro`, `src/main/AndroidManifest.xml`.
- Native `Sdk0256Compat.java`, `DynamicsCollector.kt`, and `Sdk0256CompatTest.java`.
- Unity `DynamicsGradleExportConfig.cs`, `DynamicsAndroidGradleIntegration.cs`.
- Validation scripts `verify-android-collector.ps1`, `verify-unity.ps1`; host export tests and isolated minimal consumers.
- SDK mode propagates to native status and `ResearchBuildInfo` in the player.

The original AARs and rich Maven metadata remain untouched. The overlay is an explicit resolution rule and application source, not a renamed 2.12.0 binary pretending to be 2.11.1.

## Build evidence

- Full native Android library + **16 JVM tests passed** (11 collector-policy tests, 5 actual-vendor ABI tests).
- Minimal Java consumer compiles nested power and raw/computed repository flow access. Original Kotlin minimal consumer still fails, as expected.
- Unity **6000.6.0f1**, actual Android toolchain **Gradle 9.1.0 / AGP 9.0.0 / OpenJDK 17**, ARM64 IL2CPP, min API 26, target/compile API 36.
- Unity's APK build succeeded. This is historical build evidence. Current APK identity is in ANDROID_STATUS.md; apk-artifact/signature/manifest files refer only to their recorded hashes and must not be assumed to identify the latest APK.
- No JNI stub is packaged in the APK: the standalone harness uses a compile-only stub, while Unity exports its real player classes.
- An initial Unity compatibility attempt exposed a Gradle ordering mistake in our export rule. It was fixed by placing `allprojects` after `plugins`; failure evidence is retained separately. No toolchain version was silently replaced.

## Permissions and lifecycle

API 31+ requests Bluetooth SCAN/CONNECT; API 26–30 requests location for BLE. Permission denial, permanent denial/settings recovery, Bluetooth settings, disconnect, foreground/background, timeout, duplicate snapshots and explicit session acknowledgement retain fail-closed handling. Legacy telephony/external-storage permissions were found to be **implicitly added by manifest merging** because vendor library manifests omit targetSdk; the app manifest removes these unused permissions. The app uses private storage and no telephony API.

Actual permission dialogs, BLE discovery, JNI callbacks, Android background/resume and device reconnect still need device testing. Build success cannot prove these.

## Calibration and research integrity

The existing preparation wizard now links to a measured-reference page. It starts an acknowledged SDK reference session independently of gameplay. Collection requires a ready physical device and an explicit side; five valid, fresh computed events of the same device, epoch, family, side, quantity and provenance create a median reference. Mock, mismatched, stale, duplicate and nonfinite events are rejected. Identity history is checked before collection. Leaving the page, pausing or losing readiness interrupts collection.

Saved JSON contains study/device/connection/family/side/quantity/unit/provenance, SDK mode/version, sample count, event IDs, source timestamps, values and median. Status remains `UNQUALIFIED`. No baseline is pre-populated, no measured reference was generated on this machine, and subsequent hardware-feedback work enabled gameplay normalization from matching Strong references (cap 2.5; see PROFILE_DATA_MODEL.md). The original collection-stage result was not physical qualification. ALPHA impact, DELTA power index and physical force are not equated. Heart rate remains inactive.

## Unity execution reliability

The wrapper checks fresh reports and owns each launched process. It records exit codes, timeouts and any forced termination separately. A completed but lingering owned Editor receives 30 seconds to exit, then only that Process object may be terminated; no broad Unity kill is used. A 40-minute deadline bounds missing completion. JSON date handling now supports PowerShell's automatic DateTime conversion without locale-dependent parsing. Environment-variable dumps are redacted from shareable logs.

The prior `UnityEditor.Search.SearchDatabase` exception was not reproduced in the current fresh prepare/check/build runs. Current process evidence records clean exits. No global cache deletion or unrelated Editor termination was needed; a definitive root cause for the earlier engine exception is not claimed.

## Remaining risks and vendor request

Resource 2.12.0 is ABI-compatible with the observed call sites, but full runtime semantic compatibility remains unproven. Android startup/linking and physical BLE behavior require real devices. The default build mode intentionally remains VENDOR-UNCHANGED so compatibility use is explicit.

Request from vendor: republish Android artifacts with consumer-facing Kotlin metadata/InnerClasses/signatures retained; provide the declared Resource 2.11.1 or confirm 2.12.0; document simultaneous ALPHA/DELTA ownership and supported device count; provide a supported mixed acquisition example and unit/calibration guarantees. See `MULTI_SENSOR_REPORT.md` for the exact topology findings.

The 15 September feedback pass retains both build modes and pinned vendor inputs. All 4,085 vendor files were rehashed unchanged (artifacts/validation/hardware-vendor-integrity.json). Added remove/swap operations compile against real SDK APIs; on-device behavior awaits retest.

## SDK edit authorization and source availability (15 September follow-up)

The user now authorizes SDK changes. A local Git repository preserves the unmodified distribution at 20554e6; 48aa7be adds an exact source inventory and implementation contract. No core Kotlin/Gradle project was present in either supplied SDK copy. Multi-device acquisition has therefore not been implemented or enabled. Earlier read-only constraints describe the previous pass and no longer restrict authorized future SDK work. Existing binary hash gates remain correct because no library binary changed.


### 2026-09-18 sensor ABI correction

Static caller-versus-vendor bytecode inspection identified missing unmangled `deleteGloveById(PeripheralId, Continuation)` / swap and raw descriptors emitted from the stripped Kotlin metadata. Both Unity and Inspector now use identical public-ABI adapters: `deleteGloveById-gP7SR54(Uuid, Continuation)`, `swapGloveSideForId-gP7SR54(Uuid, Continuation)`, `observeSensorData-16HgSWs(Uuid)`. Suspend continuations and SDK errors propagate; no vendor binary was patched. Public pair returns PeripheralId, subsequently confirmed against savedPeripherals. Build evidence is separate from pending physical pairing/removal/side-swap validation.
