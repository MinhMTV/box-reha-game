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
and as `-executeMethod SensorRegressionChecks.RunAll` once a Unity 2022.3.62f3 editor is installed.
Passing here is not evidence that that Unity command has run.

**NOT VERIFIED WITH PHYSICAL HARDWARE.**

The host runner also links production GameplayRules, GameSessionStats, PlayerProfile,
LevelDefinition and ResearchSessionLog. It runs 25 check groups: 16 shared sensor groups,
3 host input/buffer/routing groups, 5 gameplay rule/statistics groups and 1 logger group.
The logger check writes an explicitly synthetic JSONL recording to
`artifacts/validation/synthetic/production-logger.synthetic.jsonl`. TargetObject and Unity
environment values in that check are typed fixtures, not an emulated game scene. All records
carry `studyId: SYNTHETIC_NOT_EMPIRICAL_DATA`; the player-name exclusion is checked.

Observed output is saved in `artifacts/validation/sensor-host-checks.txt`. The separate thesis
analysis pipeline has replayed the production-emitted synthetic file to
`artifacts/validation/synthetic/production-logger.replay.json`. These artifacts prove host
schema/logic interoperability and do not establish gameplay performance or sensor accuracy.
