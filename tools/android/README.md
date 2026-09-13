# Native Android collector qualification

This standalone build compiles the actual `.androidlib` source against Dynamics SDK 0.25.6 and Android API 36, then executes local JVM policy tests. It does not launch Unity, produce the game APK, emulate Bluetooth or test a physical sensor. API 36 is required by the SDK's actual AAR metadata.

Pinned qualification toolchain: Java 17, Gradle 8.13, Android Gradle Plugin 8.13.2, Kotlin 2.3.21. Dependencies use the vendor-supplied `mavenLocal` directory plus Google and Maven Central. No vendor artifact versions are substituted. Build output stays under `tools/android/build`; the existing tracked plugin `.gradle` files are not used.

From the game root:

```powershell
.\scripts\verify-android-collector.ps1 -GradlePath 'C:\path\to\gradle-8.13\bin\gradle.bat'
```

Pass `-JavaHome`, `-AndroidSdkPath` and `-DynamicsMavenPath` for other installations. Without `-UnityClassesJar`, the harness builds a deliberately narrow compile-only `UnityPlayer` stub. Its method throws if executed, and the stub must never ship in the APK. A successful AAR build proves native source/API compatibility only; the Unity JNI boundary remains unverified until the real game runs.

Unity 6.6 uses a different bundled Gradle/AGP pair. The Editor export hook configures the SDK repository and Kotlin dependency on the generated project; it does not silently replace Unity's toolchain. The separate Unity 6.6 import/export/APK gate remains necessary even if this standalone build passes. Run `scripts/verify-unity.ps1 -UnityPath ... -BuildCandidate` after installing Android Build Support and reviewing the actual project migration.

Current supplied SDK package does **not** pass this build. See [SDK package blockers](../../SDK_PACKAGE_BLOCKERS_2026-09-14.md) for the missing resource 2.11.1 and the independently exposed Kotlin/inner-class metadata failures. The production source remains written against the documented SDK API.
