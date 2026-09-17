# Digital Dojo TODO

Updated 17 September 2026 against main `3f99b17`. Central remaining-work checklist. DONE means present in source, not physically qualified. Existing evidence: [GAME_STATUS.md](GAME_STATUS.md), [ANDROID_STATUS.md](ANDROID_STATUS.md). No tests/builds were run for this documentation update.

NEXT: 1. ALPHA hardware → 2. DELTA hardware → 3. gameplay manual tuning → 4. raw IMU recorder → 5. Straight/Hook/Uppercut research → 6. Technique Calibration → 7. Kick classification → 8. optional defense → 9. training modes → 10. user evaluation/results. Agree the study scope before treating future classification as a prerequisite for evaluation.

## Gameplay / Pacing

- [x] DONE — Modern profile/planner/plan/timeline/spawner architecture.
- [x] DONE — Long Punch combinations and seeded side variation.
- [x] DONE — Endless length scaling with bounded speed/visible count.
- [x] DONE — Kick-only cap of 20; smaller difficulty defaults.
- [x] DONE — Punch-dominant mixed development combos.
- [x] DONE — Scheduled Heavy Punch/Kick targets and active recovery.
- [x] DONE — Rolling lookahead and lane predecessor/visual-spacing guards.
- [x] DONE — Hit Gate, removed target labels and nonterminal TOO LIGHT.
- [ ] PARTIAL — No-overtake implementation is saved/buildable; latest runtime behavior is not revalidated.
- [ ] TODO — Run latest-source ordering/cadence checks across rapid repeats, phase/speed changes, capacity pressure, pause and Heavy boundaries.
- [ ] TODO — Manually tune current fast Medium/Hard timing and gate readability; compare planned with delivered cadence.

## Real Hardware Validation

Alternating-hand intervals below .35 s must not be mistaken for same-device throughput; current physical same-side scheduling remains at least .35 s. Use independently labelled physical actions and record misses/duplicates.

- [ ] HARDWARE TEST — ALPHA Left Punch.
- [ ] HARDWARE TEST — ALPHA Right Punch.
- [ ] HARDWARE TEST — Rapid alternating L/R at approximately 350 ms.
- [ ] HARDWARE TEST — Rapid alternating L/R at approximately 250 ms.
- [ ] HARDWARE TEST — Rapid alternating L/R at approximately 200 ms.
- [ ] HARDWARE TEST — Rapid alternating L/R at approximately 180 ms.
- [ ] HARDWARE TEST — 10-hit Punch combo.
- [ ] HARDWARE TEST — 20-hit Punch combo.
- [ ] HARDWARE TEST — 30–50-hit Punch flurry.
- [ ] HARDWARE TEST — Heavy Punch repeated same-side/alternating hits.
- [ ] HARDWARE TEST — DELTA Left Kick.
- [ ] HARDWARE TEST — DELTA Right Kick.
- [ ] HARDWARE TEST — Repeated Kick events and cadence.
- [ ] HARDWARE TEST — Heavy Kick.
- [ ] HARDWARE TEST — DELTA reconnect/stability.
- [ ] HARDWARE TEST — BLE end-to-end latency, duplicate/missing events and freshness rejection.
- [ ] HARDWARE TEST — Confirmed remove/re-pair, pair-aware side swap, real names and unknown-family handling.
- [ ] HARDWARE TEST — Permission denial/recovery, disconnect, background/resume and process restart.
- [ ] HARDWARE TEST — Strong/Rapid capture, profile switch, persistence and weak-hit retry.

## Punch Technique Recognition

Not implemented. Depends on a qualified raw ALPHA recording route and labelled data; SDK computed Punch events are not technique labels.

- [ ] TODO — Raw ALPHA IMU recording mode.
- [ ] TODO — Collect labelled Straight samples.
- [ ] TODO — Collect labelled Hook samples.
- [ ] TODO — Collect labelled Uppercut samples.
- [ ] TODO — Record Left/Right separately.
- [ ] TODO — Visualize acceleration/gyro signals.
- [ ] TODO — Determine useful features.
- [ ] TODO — Build baseline classifier and compare simple rules versus ML.
- [ ] TODO — Evaluate Straight/Hook/Uppercut classification on held-out participants/sessions.
- [ ] TODO — Add player stance: Orthodox/Southpaw.
- [ ] TODO — Derive Jab/Cross from Straight + side + stance.
- [ ] TODO — Confidence/unknown classification.
- [ ] TODO — Technique Calibration per player, including Straight/Hook/Uppercut.
- [ ] TODO — Persist technique calibration.
- [ ] TODO — Recalibrate/Test Calibration UI.

## Kick Technique Recognition

Not implemented; feasibility depends on real DELTA data and placement, not the current experimental Kick mapping.

- [ ] TODO — Raw DELTA recording mode.
- [ ] TODO — Collect Front Kick samples.
- [ ] TODO — Collect Side Kick samples.
- [ ] TODO — Collect Roundhouse Kick samples.
- [ ] TODO — Record Left/Right separately.
- [ ] TODO — Evaluate whether placement reliably separates techniques.
- [ ] TODO — Build and evaluate Kick classifier.
- [ ] TODO — Confidence/unknown handling.
- [ ] TODO — Profile-scoped Kick technique calibration and persistence.

## Defensive Mechanics

Depends on raw recording and gesture feasibility. None is currently an active gameplay mechanic.

- [ ] TODO — Investigate IMU-based bilateral Block gesture.
- [ ] TODO — Evaluate final glove orientation reliability.
- [ ] TODO — Left Parry.
- [ ] TODO — Right Parry.
- [ ] OPTIONAL — Guard calibration.
- [ ] OPTIONAL — Camera-based Slip/Duck/Weave; later scope, no current pose tracking.

## Multi-Sensor / SDK

- [x] DONE — SDK distribution audited.
- [x] DONE — Supplied SDK identified as compiled distribution, not full core source.
- [x] DONE — Same-family single/pair application policy and explicit compatibility build path.
- [ ] BLOCKED — Physical ALPHA + DELTA mixed production acquisition: one-pair/session ownership and no verified independent route.
- [ ] BLOCKED — Clean simultaneous 2 ALPHA + 2 DELTA acquisition through current high-level SDK.
- [ ] TODO — Investigate lower-level acquisition only if mixed sensors become thesis-critical.
- [ ] TODO — Obtain vendor clarification/source or supported mixed-device example and compatibility/quantity guarantees.
- [ ] TODO — Verify independent raw streams if a supported binding/firmware route becomes available.

Application identity/queue architecture does not establish SDK acquisition capability. API compilation does not establish live raw streams. [MULTI_SENSOR_REPORT.md](MULTI_SENSOR_REPORT.md).

## Training Modes

Existing pacing phases or Strong/Rapid references are not separate training modes.

- [x] DONE — Endless base mode and timed difficulty levels.
- [ ] TODO — Technique mode; depends on qualified classifier.
- [ ] TODO — Speed mode.
- [ ] TODO — Power mode; retain quantity-specific, dimensionless interpretation.
- [ ] TODO — Conditioning mode.
- [ ] TODO — Future Combat Flow mode combining techniques/defense; depends on classifiers, mechanics and supported acquisition.

## Profiles / Calibration

- [x] DONE — Profile create/select/edit/archive, persistent versioned repository and legacy migration.
- [x] DONE — Separate Strong and Rapid references, profile/device/side/quantity provenance and schema-1 compatibility.
- [x] DONE — Matching Strong normalization capped at 2.5; neutral uncalibrated input.
- [ ] TODO — Permanent profile deletion with explicit scope across history, calibration, research and SDK stores; current UI only archives.
- [ ] TODO — Corrupt profile recovery UI; originals are preserved/refused, not automatically repaired.
- [ ] TODO — Technique Calibration persistence (depends on Punch classifier/protocol).
- [ ] TODO — Kick Technique Calibration persistence (depends on DELTA feasibility).

## Android / Performance

- [x] DONE — Existing Unity 6000.6.0f1 Android 1.5/code 6 compatibility candidate built with zero errors.
- [ ] HARDWARE TEST — Install latest exact APK on an authorized compatible Android device.
- [ ] HARDWARE TEST — Sustained long-combo performance.
- [ ] HARDWARE TEST — FPS, GC and thermal behavior.
- [ ] HARDWARE TEST — Phone/tablet readability, safe area and touch controls.
- [ ] HARDWARE TEST — BLE plus gameplay over prolonged sessions.
- [ ] TODO — Review 20 existing build warnings; prioritize only demonstrated issues.
- [ ] TODO — Investigate historical Unity SearchDatabase exception if reproduced.

## Research / Thesis

Depends on agreed scope and technical/device qualification. Synthetic fixtures are not participant data.

- [ ] TODO — Finalize study protocol, consent/data handling and minimum feature set.
- [ ] TODO — Conduct and analyze real expert interviews.
- [ ] TODO — Complete promised literature searches/full-text and measurement-semantic checks.
- [ ] TODO — Synchronize companion thesis implementation claims with current compatibility build/profile/pacing state.
- [ ] TODO — Freeze qualified build, device/firmware, calibration protocol and analysis choices.
- [ ] TODO — Real participant/user evaluation.
- [ ] TODO — Collect SUS/usability data.
- [ ] TODO — Collect research gameplay logs and reconcile target/action/score totals.
- [ ] TODO — Analyze real results.
- [ ] TODO — Thesis Results.
- [ ] TODO — Thesis Discussion and conclusions/abstracts.
- [ ] TODO — Document observed limitations.
- [ ] TODO — Final genuine build screenshots/figures.
- [ ] TODO — Final appendix/materials and submission PDF review.
- [ ] OPTIONAL — HR transport/controller only if selected study scope requires it; currently inactive.
