# Known issues and qualification gates

Updated 2026-09-14. This is an Android-first source implementation, not a study-ready build. The full Unity game and Dynamics SDK are intended to run together on Android; Windows is the development host. The repository remains at Unity 2022.3.62f3; installation of Unity 6.6 does not establish a completed migration.
Priority P0 blocks study enrollment or defensible runtime claims; P1 must be resolved or explicitly excluded from study scope.

The full collector is implemented in source against the documented SDK API, but **native compilation is blocked** by two confirmed SDK package failures. Both the standard dependency failure and the failed diagnostic compilation are documented in [SDK package blockers](SDK_PACKAGE_BLOCKERS_2026-09-14.md). No production native build or Android APK has passed.

| Priority | Issue / current boundary | Next concrete verification | Status / evidence |
|---|---|---|---|
| P0 | Unity 6.6 migration is pending | Import in the actual installed Editor, review changes, update the recorded version, then re-run exact-version compile/build checks | NOT RUN; do not relabel a 2022 source snapshot as a verified 6.6 project |
| P0 | Unity Android Gradle/export/JNI integration has no complete APK result | PrepareAndroidCandidate before source stamp; verify native dependencies and build ARM64 IL2CPP APK | Native compile evidence is separate; full Unity APK NOT RUN |
| P0 | Production SDK dependency graph references resource 2.11.1 absent from the supplied local Maven bundle | Obtain a compatible vendor dependency bundle or explicitly validated dependency decision | Original production native build BLOCKED; a separate diagnostic 2.12.0 substitution is not production qualification |
| P0 | Supplied Android AARs stripped Kotlin metadata/InnerClasses needed for the documented API | Obtain a vendor Android SDK package exposing its documented Kotlin API intact | Diagnostic resource 2.12.0 compilation also BLOCKED; see SDK_PACKAGE_BLOCKERS_2026-09-14.md |
| P0 | Physical target devices are not qualified | OnePlus 15 and Galaxy Tab S3: install, permission denial/grant, scan, explicit side, profile rejection/acceptance, native start, pause/resume/finish, background and reconnect | Intended devices only; no physical result claimed |
| P0 | Alpha and Delta require separate qualification | Test one sensor and same-family pair; confirm connected-side target policy; reject mixed family/three devices; validate Delta kick interpretation against physical ground truth | Source-gated single-family modes; Delta mapping experimental |
| P0 | Participant/session isolation needs device proof | Delay old running/profile statuses, change study ID, reject profile, resume after disconnect; verify request-ID/profile/family/sequence gates and SDK ownership | Pure policy fixtures pass; actual callback/lifecycle behavior NOT RUN |
| P0 | Android transport timing correction needs runtime proof | Stall Unity callback delivery, verify SystemClock transport age, reject missing/future/old packets and status, then resume explicitly | Host policy checks include combined native+transport age; JNI and clock queries NOT RUN on device |
| P0 | Unity Editor/player has not been compiled or run on this host | Run scripts/verify-unity.ps1 with Unity 2022.3.62f3; inspect import/compiler output | NOT RUN: compatible licensed Editor unavailable |
| P0 | New runtime hub, result layout and scene lifecycle have not been rendered | Boot -> hub -> every panel -> three levels/endless -> pause/resume/finish -> results -> restart/menu; inspect console | NOT RUN: source and static YAML checks only |
| P0 | Physical sensor and native collector behavior has not been qualified | Verify collector initialization, schema, real device/side/quantity, reconnect and action latency | NOT VERIFIED WITH PHYSICAL HARDWARE |
| P0 | Real participant, expert and sensor ground-truth data are absent | Obtain approved study/consent plan and real data before evaluating effects or accuracy | External empirical gate; synthetic fixtures are separate |
| P1 | Calibration screen is preparatory; capture and persistence are unimplemented | Implement quantity/device/side/provenance-specific comfortable-action baseline collection, qualify with hardware | Explicitly unavailable in runtime UI |
| P1 | Full gameplay mechanics are tested as policy on host, not running Unity objects | Exercise actual four-key input, repeated same-side heavy, timeout, wrong side/action, timing extremes and chain success/failure | Host logic checks exist; runtime gate NOT RUN |
| P1 | Stop/pause/result logging needs actual scene round-trip evidence | Reconcile every spawned target, terminal outcome and score increment including paused stop and partial heavy | Production logger exercised with labelled synthetic host fixture; Unity lifecycle NOT RUN |
| P1 | Native ALPHA and DELTA are not interchangeable quantities | Check raw evidence and native packet schema on both types; exclude unqualified channels from study | Separate quantity semantics retained; no physical accuracy claim |
| P1 | No active HR adaptation in gameplay | Keep excluded unless an independently validated HR provider and bounded controller are integrated | No HR samples or adaptive decisions are fabricated |
| P1 | Research build identifier can be unrecorded in ad hoc runs | Use verification script to stamp exact source manifest before candidate build | Optional Resources/ResearchBuildInfo consumed by logger; missing stamp is explicit |
| P1 | Continuous sensor packets and rejected readings are not fully exported by game logger | Add channel-specific diagnostic events if the technical evaluation requires those rates/latencies | Emitted action evidence and sanitized acquisition_state snapshots retain SDK/profile/family/device/connection/firmware state; full packet/rejection audit absent |
| P2 | Historical concept UI remains serialized in MainMenu.unity | Regenerate menu in a controlled Unity session after compile; capture runtime screens only | Runtime Awake replaces all old UI before rendering; Editor-only screenshot may show old concept |
| P2 | Prior participant selection UI is unavailable | Add explicit stored-profile selection if repeated participant switching is needed | New ID flow preserves old histories; name edits preserve active ID |
| P2 | Local history has a 200-summary cap and is not encrypted | Define study retention/export workflow and restricted storage location | JSONL files retained separately; corrupted summaries are preserved instead of overwritten |
| P2 | Abrupt termination may leave a session without session_end | Test interruption and treat incomplete logs as incomplete in analysis | Logger flushes each record; no crash-durability guarantee |
| P1 | Mobile touch target size, soft keyboard and safe-area layout are not visually qualified | Inspect actual OnePlus 15 and Galaxy Tab S3 landscape; navigate all setup pages, edit fields and use pause/finish without keyboard | UGUI Expand, safe-area roots, touch controls and motion/SFX settings implemented; NOT rendered/verified |
| P1 | SDK body profile is required and has restricted MALE/FEMALE categories | Verify local SDK storage, explain categories, document missing/declined input and do not infer participant attributes | Empty UI inputs, explicit category and readiness invalidation; no game force model or body values in JSONL |

## Available verification entrypoints

| Check | Command / entrypoint | Result artifact / boundary |
|---|---|---|
| C# conditional syntax | dotnet run --project tests/syntax/SyntaxChecks.csproj -- . | artifacts/validation/csharp-syntax.json; not Unity API compile |
| Sensor/input/gameplay policy and logger/history host fixtures | dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release | artifacts/validation/sensor-host-checks.txt when captured; minimal Unity stubs, synthetic data |
| Serialized scene references | python tests/check_scene_assets.py | artifacts/validation/static-scene-checks.json; 635 assertions passed on initial run, external script GUIDs separately unverified |
| Unity Editor rules + scene validation | -batchmode -quit -executeMethod GameRegressionChecks.RunBatch | artifacts/validation/unity-editor-checks.json; NOT RUN here |
| Windows x64 development candidate | -batchmode -quit -executeMethod GameRegressionChecks.BuildStudyCandidate | Builds/StudyCandidate/DigitalDojo.exe and artifacts/validation/unity-candidate-build.json; NOT RUN here |
| Android candidate settings | -batchmode -quit -executeMethod GameRegressionChecks.PrepareAndroidCandidate | Save settings before stamping source revision/hash; exact Editor/Android module required |
| Android ARM64 IL2CPP candidate | -batchmode -quit -executeMethod GameRegressionChecks.BuildAndroidCandidate | Builds/AndroidCandidate/DigitalDojo.apk and artifacts/validation/unity-android-candidate-build.json; NOT RUN here |
| Manual player qualification | Launch verified candidate and complete matrix above | Actual console logs, session JSONL, screenshots and signed test record; NOT RUN here |

BuildStudyCandidate builds enabled scenes with Development options. It fails on a non-success result or any build errors and writes a BuildReport summary. It does not launch the player, verify sensors, certify a clinical product or mark the project study-ready.

See GAME_STATUS.md for consolidated status, GAMEPLAY_UI_AUDIT.md for engineering findings and RESEARCH_LOG_SCHEMA.md for event/metric definitions.
