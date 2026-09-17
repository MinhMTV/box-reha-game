# Research event contract v1

Producer: Assets/Scripts/Research/ResearchSessionLog.cs.
Output: Application.persistentDataPath/research/<sessionId>.jsonl.
UTF-8 JSON object per line; append-only during a session, flushed after each record. No display name or demographics are written.

This is the implemented contract, not evidence that a Unity session was executed or physical sensors were verified.

## Common fields

schemaVersion = 1; kind; sessionId; eventId; studyId; utc (ISO 8601 UTC);
monotonicSeconds (Unity realtimeSinceStartupAsDouble); gameplaySeconds (Time.time minus session start, pauses excluded).

JsonUtility writes the full record class for every kind. **Only the fields defined for that kind are meaningful.** Null, empty, zero and false in unrelated fields are defaults, not measurements or negative observations. For action raw quantities, interpret validity, provenance, quantity and unit together.

## Record kinds

| kind | Relevant additional fields | Meaning |
|---|---|---|
| session_start | mode, buildVersion, buildRevision, unityVersion, configJson, gameConfigJson, inputStatus, acquisitionJson (optional) | LevelDefinition and GameConfig JSON are embedded strings. buildRevision is contents of optional Resources/ResearchBuildInfo.txt, or unrecorded. Acquisition is SDK configuration/status metadata, not sensor measurements. |
| acquisition_state | acquisitionJson | Optional Android SDK state change during an open game recording. Unchanged heartbeat snapshots are suppressed. No body values, gender or device display names are included. |
| action | actionType, side, lane, inputSource, deviceType, deviceId, connectionId, provenance, sourceEventId, sourceTimestamp, sourceClock, receivedTimestamp, power, normalizationValid, rawValue, quantity, unit, isValid, validityReason, detector, sensorEvidenceJson | An input action routed to a playing round. Native source event identity and original SensorReading evidence are retained separately from Unity action identity. |
| target_spawn | targetId, targetType, lane, spawnGameplaySeconds, hitWindowSeconds, targetSpeed, hitZoneZ, expectedHitGameplaySeconds, maxHealth, remainingHealth, heavyTimeoutSeconds | Full hit window is symmetric around expected hit time. Max/remaining health represent gameplay counters, not sensor quantities. |
| heavy_impact | target fields, matchedEventId, healthDamage | Accepted heavy impact. healthDamage is distinct from score. |
| target_resolved | target fields, matchedEventId, outcome, hitQuality, timingOffsetSeconds, resolutionSeconds | Exactly one terminal outcome per tracked target. outcome is hit, miss, heavy_timeout or aborted. matchedEventId and timing quality are meaningful for hits only. |
| score | targetId, matchedEventId, baseScore, multiplier, combo, awardedScore, totalScore, outcome | Every actual increment. outcome is hit, heavy_partial or chain_complete. baseScore is the post-power gameplay base, before combo multiplier. |
| pause / resume | common fields | Pause state transitions. No physiological adaptation implied. |
| session_end | stopReason, statsJson | End summary after unfinished targets are marked aborted. time_limit, player_stop and application_quit are current reasons. |

Config caveat: GameConfig includes some historical fields unused by current evaluator. Actual timing policy is in GameplayRules: perfect <= min(.1, halfWindow), good <= min(.25, halfWindow), otherwise early/late within halfWindow. Per-level full hit window is recorded on each target. Scoring policy: 100/50/25 for Perfect/Good/Early-Late, heavy base 100 + break bonus 350, partial heavy impact 10, completed rapid chain 500. First completed target combo multiplier 1.0, then +0.1 per completion, cap 3.0. Only sensor events with normalizationValid=true use power multiplier bounded to [.75,1.25]; current uncalibrated sensor pipeline sets false.

An optional build manifest is not generated from an assumed commit. A study build must embed its actual source/artifact revision, config and qualification evidence before enrollment.

## Session summary

GameSessionStats serializes fields using PascalCase. Derived properties are not emitted by JsonUtility.

- SessionId, StudyId, StartedUtc, Mode, StopReason, LogPath, DurationSeconds.
- SpawnedTargets, TotalTargets (resolved hits + misses), AbortedTargets, HeavyTimeouts.
- PerfectHits, GoodHits, EarlyHits, LateHits, Misses, Score, MaxCombo, FinalCombo.
- ArmTargets/ArmHits/ArmMisses and LegTargets/LegHits/LegMisses.
- LeftTargets/RightTargets/CenterTargets and corresponding Hits; heavy targets use Center.
- Actions, LeftActions, RightActions, PunchActions, KickActions, KeyboardActions, SensorActions, OtherActions.
- AverageReactionTime is a retained legacy field name; its actual meaning is mean **active target-resolution duration from spawn to successful completion**. It is not human reaction time or sensor latency. Empty-hit sessions have a stored zero sentinel.

## Reconciliation rules

- Count distinct target_spawn IDs; every completed session must have one target_resolved for every spawned ID.
- SpawnedTargets = TotalTargets + AbortedTargets.
- TotalTargets = PerfectHits + GoodHits + EarlyHits + LateHits + Misses.
- A heavy partial impact is not a completed target. It can award score even if that target later times out or the round stops.
- Sum all score.awardedScore = final stats Score. Each totalScore must be previous total plus awardedScore.
- Timing accuracy = (PerfectHits + GoodHits) / TotalTargets.
- Completion = (PerfectHits + GoodHits + EarlyHits + LateHits) / TotalTargets.
- Both ratios are undefined when TotalTargets=0; UI uses zero convention, analyses should report missing/undefined.
- Heavy timeouts count as misses; aborted targets are excluded from both ratios and must be reported separately.
- Action counts include routed attempts even when no matching target exists. Never equate them to sensor true positives or use them as ground truth.
- action.EventId is the linkage to matchedEventId; sourceEventId belongs to native event identity and can repeat across different devices/connection epochs.
- Directly comparing native sourceTimestamp and Unity monotonicSeconds is invalid without an externally verified clock mapping.
- A file lacking session_end is incomplete. Do not impute a completed result from it.

## Limits

Calibration records are produced in a separate audit stream described below, not as game-session record kinds. HR sample and adaptation decision producers are not implemented. Android acquisition snapshots report observed status changes, but full BLE transition coverage, rejected reading diagnostics and continuous packet capture require additional instrumentation. Raw SDK identity is preserved for emitted actions only, not every continuous packet. Crash durability is best-effort local flush, not a transactional database. History retains 200 summaries, while JSONL files are not automatically deleted.

## Android acquisition metadata (added 2026-09-14)

`acquisitionJson` is an optional embedded JSON object with `platform`, `source`, `requestedFamily`, `effectiveFamily`, `sdkVersion`, `sdkSessionState`, `profileReference`, `profileStudyId`, `initialized`, `permissionsGranted`, `profileReady`, and `devices`. Each device has `deviceId`, `connectionId`, `family`, `side`, `firmwareVersion`, `online` and `isMock`. Unknown SDK fields remain unknown; an online snapshot does not establish continuous connection coverage or physical detection accuracy. Existing recordings without this optional field remain valid.

The SDK additionally stores body profiles and finished sessions in its own local database. The game JSONL deliberately omits weight, height and gender; `profileReference` links only to a separately protected SDK configuration record. Participant transitions require fresh SDK profile confirmation and a correlated start acknowledgement. Export, retention, backup and deletion of both stores must be qualified before participant use. No demographic force normalization is added to gameplay.

## Hardware feedback extension — 15 September 2026

Action records additionally include calibrationId when a matching personal game reference is used. Raw quantity/unit/source evidence remain unchanged; power is the dimensionless bounded relative value only when normalizationValid=true.

`below_strength_threshold`: target metadata, matchedEventId, calibrationId, power, strengthThreshold and normalizationValid. This records a timed matching action below the current game threshold, not a terminal resolution. The target may later resolve, miss or abort; do not add this record to TotalTargets.

`persistentDataPath/calibration/calibration-<random>.jsonl` is a separate per-attempt physical reference audit. Kinds: calibration_start, calibration_familiarization, calibration_sample, calibration_rejected, calibration_complete. Each contains active study/device/connection/family/side/quantity, source event ID/timestamp/raw value when applicable, UTC and reason. Rejection counts cover the measured-reference stage after validated ingress; they are not all BLE packet rejections or sensor accuracy. Mock/keyboard cannot advance it.

Saved reference JSON schema 2 adds calibrationId, referenceKind, raw sample arrays/event IDs/source timestamps, rejectedSamples, median interval/rate, app/build and SDK metadata. Strong protocol excludes three practice actions from its five-sample median; rapid protocol uses five controlled actions. qualification stays UNQUALIFIED. Recalibration writes a new record. Legacy schema-1 references remain readable; no physical unit is inferred.

## Pacing context — current source, 17 September 2026

`pacing_configuration` records configJson and pacingSeed. `pacing_schedule` records targetId, pacingPhase, pacingTier, patternId, patternIndex, scheduledIntervalSeconds and configuredTravelTimeSeconds. These describe scheduled game work, not observed human cadence or physical sensor performance. Preserve the latest source/config/build identity when comparing runs; older logs can lack these additive kinds.

Current status and remaining qualification: [GAME_STATUS.md](GAME_STATUS.md), [TODO.md](TODO.md). No research data or validation report was generated by this documentation update.
