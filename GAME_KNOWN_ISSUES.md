# Known issues and qualification gates

Updated 2026-09-13. This is a source-hardened development candidate, not a study-ready build.
Priority P0 blocks study enrollment or defensible runtime claims; P1 must be resolved or explicitly excluded from study scope.

| Priority | Issue / current boundary | Next concrete verification | Status / evidence |
|---|---|---|---|
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
| P1 | Continuous sensor packets, rejected readings and connection transitions are not fully exported by game logger | Add channel-specific diagnostic events if the technical evaluation requires those rates/latencies | Emitted action evidence and starting input status available; full packet audit absent |
| P2 | Historical concept UI remains serialized in MainMenu.unity | Regenerate menu in a controlled Unity session after compile; capture runtime screens only | Runtime Awake replaces all old UI before rendering; Editor-only screenshot may show old concept |
| P2 | Prior participant selection UI is unavailable | Add explicit stored-profile selection if repeated participant switching is needed | New ID flow preserves old histories; name edits preserve active ID |
| P2 | Local history has a 200-summary cap and is not encrypted | Define study retention/export workflow and restricted storage location | JSONL files retained separately; corrupted summaries are preserved instead of overwritten |
| P2 | Abrupt termination may leave a session without session_end | Test interruption and treat incomplete logs as incomplete in analysis | Logger flushes each record; no crash-durability guarantee |
| P2 | Accessibility, contrast and screen-size behavior lack user/visual review | Inspect 1280x720, 1920x1080, 16:10; test keyboard focus and reduced motion | UGUI Expand layout and motion/SFX controls implemented, NOT visually verified |

## Available verification entrypoints

| Check | Command / entrypoint | Result artifact / boundary |
|---|---|---|
| C# conditional syntax | dotnet run --project tests/syntax/SyntaxChecks.csproj -- . | artifacts/validation/csharp-syntax.json; not Unity API compile |
| Sensor/input/gameplay policy and logger/history host fixtures | dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release | artifacts/validation/sensor-host-checks.txt when captured; minimal Unity stubs, synthetic data |
| Serialized scene references | python tests/check_scene_assets.py | artifacts/validation/static-scene-checks.json; 635 assertions passed on initial run, external script GUIDs separately unverified |
| Unity Editor rules + scene validation | -batchmode -quit -executeMethod GameRegressionChecks.RunBatch | artifacts/validation/unity-editor-checks.json; NOT RUN here |
| Windows x64 development candidate | -batchmode -quit -executeMethod GameRegressionChecks.BuildStudyCandidate | Builds/StudyCandidate/DigitalDojo.exe and artifacts/validation/unity-candidate-build.json; NOT RUN here |
| Manual player qualification | Launch verified candidate and complete matrix above | Actual console logs, session JSONL, screenshots and signed test record; NOT RUN here |

BuildStudyCandidate builds enabled scenes with Development options. It fails on a non-success result or any build errors and writes a BuildReport summary. It does not launch the player, verify sensors, certify a clinical product or mark the project study-ready.

See GAME_STATUS.md for consolidated status, GAMEPLAY_UI_AUDIT.md for engineering findings and RESEARCH_LOG_SCHEMA.md for event/metric definitions.
