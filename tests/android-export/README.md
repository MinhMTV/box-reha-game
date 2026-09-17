# Generated Android export host checks

Run `dotnet run --project tests/android-export/AndroidExportChecks.csproj` from the game repository.

This links the production pure file-transformation helper and checks synthetic Gradle exports in a temporary directory: Kotlin configuration, repository modes, SDK API requirements, idempotence, unsupported-version and missing-path failures. It does not execute Unity, Gradle, the Dynamics SDK or Bluetooth. The actual output is recorded separately under `artifacts/validation/android-export-host.txt`.

The real native collector build and Kotlin unit tests use the separate `tools/android` Gradle harness. Its normal dependency graph currently fails on the SDK's missing `resource:2.11.1`; explicit COMPATIBILITY now provides a successful application build route with resource 2.12.0 and the pinned adapter. It does not certify vendor semantics or physical operation. See [ANDROID_STATUS.md](../../ANDROID_STATUS.md); no tests were rerun for this documentation update.
