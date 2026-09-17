# Local profiles — 15 September 2026

`IProfileRepository` / `FileProfileRepository` owns `profiles-v1.json` under Application.persistentDataPath. Version 1 uses a JSON database, flushed temporary writes, atomic File.Replace and a `.bak` predecessor. No SQLite native dependency was added to the working ARM64/IL2CPP pipeline. Android filesystem replacement still needs device verification. Unreadable/unknown schemas throw and preserve original data; no silent empty database replacement. Failed writes reload persisted state before rethrowing.

Each profile has stable StudyId, Name (UI only), CreatedUtc/UpdatedUtc, HeightCm, WeightKg, explicitly selected SdkGender, acknowledged SdkProfileReference, PreferredLevel, Archived and CalibrationReferences. PreferredLevel is reserved storage, not automatic adaptive training. Settings retain their existing device-wide preferences.

`PlayerProfileStore` is a compatibility facade; PlayerPrefs is read only for migration of `dojo_profile_v2`. Versioned migration imports the original ID once, never combines matching names, preserves the old preference and selects the existing profile. Histories and old reference files remain in place and retain StudyId. `CalibrationLibrary` loads references by StudyId even if an old profile has no reference filename index; schema-1 references receive a deterministic legacy ID at read time. No research record is rewritten.

Create/select/edit/archive are available under Player profile > Saved profiles. Four profiles per page; selection restores the original ID. Archive hides a non-active profile but retains its data, session logs and references. Select another profile before archiving the active one. There is intentionally no irreversible delete button.

Profile selection closes the prior SDK session and immediately invalidates C# profile readiness. Native commands are serialized; native participant selection also refuses an active old session. Fresh body-profile and request-ID running acknowledgements must match the new StudyId. BLE bindings are device-level and retained; the previous participant's body-profile acknowledgement is never reused.

Profile database contains local body information required by the SDK. Research JSONL excludes display names, height, weight, SDK gender and human-readable device names. Body dimensions never estimate Newton or gameplay strength. Local storage is not encrypted; study retention/access decisions remain separate.

Tests: host file create/reload/migrate/rename/archive, duplicate display names, corrupt preservation; existing history profile isolation; calibration reference separation. These are synthetic file/policy tests, not Android upgrade proof.

## Current calibration boundary — 17 September 2026
Strong uses three familiarization actions plus five samples (median raw quantity). Rapid uses five events (reciprocal median of four intervals), stored separately as referenceKind speed. Reference schema 2 retains event/timestamp/provenance/SDK metadata; schema 1 remains readable. CalibrationLibrary applies only matching strength references, capped at 2.5; Rapid does not drive pacing. Both protocols remain scientifically UNQUALIFIED.
Technique Calibration (Straight/Hook/Uppercut and possible Kick techniques) and its UI/persistence are not implemented. Permanent deletion and corrupt-profile recovery UI are also absent. Work and dependencies: [TODO.md](TODO.md).
