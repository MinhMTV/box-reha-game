# Sensor host regression checks

All fixtures are **SYNTHETIC / NOT EMPIRICAL DATA**.

Run from repository root:

```powershell
dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release
```

The harness links the actual sensor/input/event C# source and executes
`Assets/Editor/SensorRegressionChecks.cs`. It injects timestamps and explicit SDK mock provenance.
It compiles with deliberately small Unity API stubs, not Unity assemblies. Thus this is evidence
for deterministic host logic only. It does not verify Unity serialization, scene wiring, mobile
builds, native SDK initialization, Bluetooth, physical detection accuracy, or latency.

The same check entrypoint is available as **BoxReha → Run Sensor Regression Checks** in Unity
and as `-executeMethod SensorRegressionChecks.RunAll` with the matching Unity 6000.6.0f1 editor.
Passing here is not evidence that that Unity command has run.

**NOT VERIFIED WITH PHYSICAL HARDWARE.**

The host runner also links production GameplayRules, GameSessionStats, PlayerProfile,
LevelDefinition, ResearchSessionLog and SessionHistoryStore. It runs 26 check groups: 16 shared sensor groups,
3 host input/buffer/routing groups, 5 gameplay rule/statistics groups, 1 logger group and 1 history preservation group.
It also links AndroidSessionPolicy and executes **47 Android policy assertions**: initialized/permission/profile gates,
single/pair family and side restrictions, mock rejection, connected lanes, request/participant/family acknowledgements,
heartbeat freshness, and combined native plus JNI transport age. AndroidNativeClock is linked in its non-device branch;
these tests do not execute the actual SystemClock JNI call or AndroidDynamicsController lifecycle.
The logger check writes an explicitly synthetic JSONL recording to
`artifacts/validation/synthetic/production-logger.synthetic.jsonl`. TargetObject and Unity
environment values in that check are typed fixtures, not an emulated game scene. All records
carry `studyId: SYNTHETIC_NOT_EMPIRICAL_DATA`; the player-name exclusion is checked.
The current fixture contains eight records, including one deliberately unready/offline/mock acquisition_state emitted
through the production logger. Embedded metadata serialization is checked without claiming a physical session.

Observed output is saved in `artifacts/validation/sensor-host-checks.txt`. The separate thesis
analysis pipeline has replayed the production-emitted synthetic file to
`artifacts/validation/synthetic/production-logger.replay.json`. These artifacts prove host
schema/logic interoperability and do not establish gameplay performance or sensor accuracy.

The group counts and fixture observations above are historical harness evidence; current source includes additional pacing/profile/calibration checks. No test was run in the 17 September documentation update. Use dated artifacts only for their source hashes. Native/Unity COMPATIBILITY builds now succeed; VENDOR-UNCHANGED remains package-blocked. See [current status](../../GAME_STATUS.md), [Android identity](../../ANDROID_STATUS.md) and [TODO](../../TODO.md).
