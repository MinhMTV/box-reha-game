# Hardware feedback implementation — historical record, updated 17 September 2026

This document records the earlier hardware-feedback implementation. The current source is the main checkout and has since received pacing, visual, cleanup and Android build updates. Use ANDROID_STATUS.md and SENSOR_PAIRING_FLOW.md for the current implementation boundary.

## Evidence boundaries

The user's previous APK test established Android launch, ALPHA discovery (SG-2300003 / SG-2300002) and pairing UI. It did not establish punch delivery, references, DELTA, mixed acquisition or accuracy. No ADB device was available in this pass; new binary installation/runtime remains NOT RUN. Synthetic checks/captures are labelled and use an isolated QA profile.

## Issues and outcomes

| Issue | Status and implemented result | Evidence / remaining boundary |
|---|---|---|
| Remove paired sensor | Implemented; success waits for savedPeripherals and observeGloves absence after deleteGloveById | Native compile; host retirement/slot tests; actual SDK database/BLE acknowledgement still needs device |
| Reassign after remove | Implemented; old epochs retired, cache/processor slot released, scan/side assignment available again | 25 sequential removals and fresh opposite-side binding in host fixtures; hardware pending |
| Wrong glove side | Implemented using swapGloveSideForId; SDK swaps pair counterpart too; waits for changed DTO side | Actual SDK API/bytecode evidence; native compile, radio retest pending |
| Device names | Implemented advertising name on pairing and actual SDK name with persisted fallback | Named ALPHA UI capture; no hardcoded BoxReha pairing label |
| Setup completion states | Implemented gray/blue/green from actual prerequisites and pending operation/session locks | Synthetic UI captures at landscape sizes |
| Single ALPHA readiness | Policy supports Left/Right separately, named unknown-family errors and exact-device SDK family cache | All four single-family/side fixtures pass. Exact reported physical failure is only partially addressed until retest |
| DELTA standalone/mixed | Single/pair Delta policy implemented; mixed remains blocked | Policy tests and raw Java API probe pass; real DELTA and concurrent streams unverified |
| Profiles | Implemented versioned atomic JSON repository, create/select/edit/archive, stable IDs and one-time legacy migration | Host file reload/migration/name collision/history isolation tests |
| Strength and rapid calibration | Implemented separate records; three practice plus five strong events; five-event rapid interval reference | 26 calibration assertions plus new isolation/reference assertions; no measured physical baseline here |
| Personalized strength / TOO LIGHT | Implemented exact profile/device/side/quantity reference and ratio cap 2.5; weak action is separate nonterminal outcome | Host normalization checks; Play Mode weak-then-normal target test |
| Statistics | Implemented profile-scoped summaries, separate family/side relative means and references | STATISTICS_DEFINITIONS.md defines each displayed metric and denominators; existing 200-summary cap retained |
| Target cleanup | Implemented early resolution/removal and unscaled destruction fallback, miss/abort removal; heavy bar owned by target | Play Mode normal/kick/weak-then-strong/miss/heavy completion/timeout; no targets or health bars remain |
| Runtime collider errors | Runtime visual primitives use mesh-only factory; no implicit CapsuleCollider | Real Play Mode cylinder/cube/sphere collider checks; no vendor or physics package workaround |
| Strike plane / rails | Real shared plane moved Z=5 to Z=2; visible guide bars/rails removed | Play Mode assertions plus close-target screenshots |
| HUD / mobile layout | Production instructions hidden; debug opt-in; PAUSE moved bottom-center away from KICK | Reviewed 4:3 close targets/calibration and wide sensor page; Android performance/touch still pending |

Mixed experimental route: raw/computed APIs are reachable, but pair capacity, ongoing-session guard and singleton ownership prevent claiming an independent third-device route. No untested raw detector or fake power index was enabled. See MULTI_SENSOR_REPORT.md and vendor-compat/dynamics-0.25.6/evidence/hardware-feedback-sdk.txt.

## Executed checks

- `dotnet run --project tests/sensor`: existing 26 checks (16 sensor, 3 additional, 5 gameplay, 1 logger, 1 history), plus 47 Android policy, 26 calibration and 108 hardware-feedback assertions; PASS.
- `dotnet run --project tests/syntax`: 75 C# files across five symbol configurations, zero errors.
- `dotnet run --project tests/android-export`: 18 checks PASS.
- `python tests/check_scene_assets.py`: 635 PASS, zero failures.
- `scripts/verify-android-collector.ps1 -SdkMode COMPATIBILITY -Offline` with Gradle 8.13: collector compilation and 16 JVM tests PASS (00:36 UTC); real SDK API reachability, not BLE runtime.
- Raw API Java probe `compileDebugJavaWithJavac --offline`: BUILD SUCCESSFUL, tasks up to date; no physical concurrency claim.
- `scripts/verify-hardware-feedback-playmode.ps1`: owned Unity 6000.6.0f1 exited 0 without forced termination at 00:44 UTC; 30 assertions PASS and 75 PNGs generated. This is an actual Play Mode harness, not a Unity Test Runner NUnit suite.
- Editor regression checks: 9 PASS, zero failures. Editor SearchDatabase startup exception is recorded separately and is not claimed fixed.
- Vendor integrity: 4,085 authoritative SDK files unchanged; build-critical AAR hash enforcement retained.

## Binary and next device test

New COMPATIBILITY APK: version 1.1/code2, 34,189,756 bytes, SHA-256 `aa82afe63a2a0afc76b999f563c3214094217d63c941ceaec4efa207d4fcf472`. Build Succeeded with 0 errors and 17 warnings; signature, zipalign and five native ELF alignments pass. See ANDROID_STATUS.md and artifacts/validation/apk-artifact.json. Build details are in unity-android-candidate-build.json. The primary checkout has not been merged; use the APK from this worktree.

After USB authorization, install with `adb install -r` (do not uninstall data). Test removal left/right/both, counterpart preservation, opposite-side re-pair, pair swap, actual names and unresolved family, then each single ALPHA side and each single DELTA side independently. Verify actual events, permissions/reconnect/background, profile upgrade/switch, strong and rapid collection, saving/restarting and TOO LIGHT/retry. Only then qualify each same-family pair. Mixed mode remains blocked until an independent supported acquisition route and hardware evidence exist.

Remaining non-hardware limitations: corrupt-profile recovery UI and permanent deletion are not implemented; rapid-reference adaptive difficulty is not qualified; no clinical measurement or accuracy claim. Android resource substitution remains explicitly COMPATIBILITY.
