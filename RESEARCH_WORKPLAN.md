# Research and development workplan

**14 September continuation:** The user selected Android as the complete game/SDK runtime, with Windows as development/build host. OnePlus 15 or Galaxy Tab S3 are target candidates; Unity 6.6 installation/import is pending. Android collector, Unity control/UI and build integration are now implemented in source. The actual standard native build is blocked by missing vendor resource 2.11.1; compileSdk 36 is required by the SDK AARs. Current details/evidence are in `GAME_STATUS.md` and `ANDROID_VALIDATION_2026-09-14.md`. The sections below retain the dated 13 September baseline and disposition.

Baseline inspected 2026-09-13. This record is an audit and implementation plan, not evidence of study readiness.

## Sources and working paths

1. Approved expose: `E:\Programming Projekte\expose_latex_diplom\expose_v3.tex`, HEAD `f224d41`. Its substantive content matches the original v3 commit `c1aacbd`; only the date changed. No local or fetched `Codex/expose` ref exists. Do not silently substitute an older expose.
2. Thesis: `E:\Programming Projekte\latex_diplom`, baseline `aecac7d`, existing branch `codex/expose-v3-thesis-2026-09-13`.
3. Game: `E:\Programming Projekte\box-reha-game`, baseline `8b736f6`, working branch `codex/research-hardening-2026-09-13`.
4. Authoritative SDK: `C:\dynamics-sdk-main`, documentation version 0.25.6. The game also contains an SDK copy; the explicitly named external SDK takes precedence.

All three repositories were clean before this cycle. Expose and SDK are read-only. Existing historical reviews and March game screenshots are not current build evidence.

## Scientific scope

Four RQs concern requirements, heterogeneous Alpha/Delta mappings, optional HR adaptation, and exploratory post-use usability/perceptions. Three phases: literature/expert interviews, constructive prototyping, technical qualification then user evaluation. Non-clinical adult physical activity; no rehabilitation efficacy, sustained adherence or clinical resilience claim. No completed interview or study corpus has been supplied. Keyboard play cannot answer the real-device component of RQ2.

## Prioritized gap analysis

| ID | Priority | Gap and baseline evidence | Action / acceptance evidence | Owner |
|---|---|---|---|---|
| G01 | P0 | Shared sensor buffer/cooldown; unread samples retrigger (`BleSensorInputProvider`) | Consumable per-device events; stale/duplicate/invalid/reconnect/concurrency tests | Sensor |
| G02 | P0 | Sensor/keyboard provenance and Alpha/Delta quantities mixed | Preserve metric names, known/unknown units, validity, identity and clock metadata; never infer force from demographics | Sensor + Gameplay |
| G03 | P0 | Native Java/iOS only forward payloads; no complete collector | Exact SDK lifecycle/contract; verify mixed-family support and physical traces before sensor study claims | Sensor; hardware external |
| G04 | P0 | Fake connection/calibration/profile/statistics in scene/UI generators and HUD | Actual local data binding and honest empty states; remove fabricated measurement displays | Gameplay/UI |
| G05 | P0 | Pause panel disables its own input controller; stop can lose session | Always available pause/stop; finalize logs/results with unresolved targets | Gameplay/QA |
| G06 | P0 | No research export; clocks mixed in target timing | Versioned JSONL with linked actions/targets/scores/session/config; reproducible analysis | Gameplay + Coordinator |
| G07 | P0 | No current Unity build/runtime/hardware evidence | Discover editor, compile, execute regression and scene flow checks, archive actual output | QA |
| T01 | P0 | No empirical corpus or approved final study protocol | Prepare instruments/codebook/analysis; retain empirical TODOs and consolidate decisions | Methodology; user/supervisor external |
| T02 | P1 | Static thesis becomes stale as game changes | Update actual implementation claims; distinguish specification, host test, Unity test, hardware test | Thesis + technical reviewer |
| T03 | P1 | Interview appendix too brief for reproducible fieldwork | Full common core, role probes, information/consent checklist, transcript/coding/traceability records | Coordinator |
| T04 | P1 | Only architecture figure; TODOs fragmented; stale absolute paths | Accurate process/flow figures and comprehensive current status; source validation | Thesis |
| T05 | P1 | Lower-body literature limited; systematic screening unfinished | Targeted primary-source extraction and explicit search/access limits | Literature reviewer |
| G08 | P1 | Timing windows in seconds disagree with trigger volume; heavy can hold indefinitely | Time-based eligibility, bounded heavy timeout, same-side repeated hits, pause clock tests | Gameplay |
| G09 | P1 | Decorative settings/calibration mistaken for implemented functionality | Functional justified settings; exclude measurement calibration until validated samples exist | UI |
| G10 | P2 | Readability and onboarding need fresh visual review | Consistent Digital Dojo hub, action/side cues, concise HUD, actual screenshots only | UI + Benchmark |
| T06 | P1 | Historical professor review includes unsupported outcome numbers | Explicit supersession/withdrawal warning; no reuse as evidence | Thesis / red team |

## Review roles and sequence

Actual parallel agents: Thesis Auditor; Sensor Integration Engineer; Gameplay/UI/QA Engineer. Coordinator performs literature, practical qualitative instruments, analysis verification and cross-project integration. These roles cover A Research Coordinator, B Thesis Auditor, C Literature, D Mayring, E Gameplay, F Sensor, G UI/Art, H QA, I Scientific Red Team, J Game Benchmark. Role coverage does not imply ten independent people or completed human expert reviews.

First pass: read-only inventory completed before substantive edits. Next: P0/P1 implementation, available builds/tests, independent cross-review, fix concrete findings, refresh thesis/code consistency and status. Record each review's problem, severity, evidence, suggested fix and resolution. Visual and hardware checks remain open unless actually run.

## External dependencies

- Real Alpha/Delta devices, firmware and host platform to qualify collection and combined-family lifecycle.
- Manufacturer clarification of computed quantity units/ranges and clock behaviour where absent from SDK docs.
- Supervisor/institution decisions about recruitment, ethics/consent, study language and optional HR/calibration scope.
- Actual consented interviews, independently labelled sensor sequences and user-study records.

See `OPEN_DECISIONS.md`, `GAME_STATUS.md`, and the thesis `THESIS_STATUS.md` for current dispositions. Internal code, documentation and analysis work should continue independently of these decisions.

## End-of-cycle disposition

The source fixes for G01/G02/G04/G05/G06/G08/G09 and manuscript/instrument/diagram work T02/T03/T04/T06 are implemented and independently reviewed. Their available host, syntax, static asset and document checks pass, as recorded in `VALIDATION_REPORT_2026-09-13.md`; source implementation does not close runtime gates. G03/G07 remain open because complete native acquisition and actual Unity/device qualification are absent. T01 remains prepared but empirical. T05 now includes a verified additional kick-sensor paper and bounded synthesis, while the promised database search and continuous lower-body evidence review remain unfinished. G10 has source-level UI changes and a documentary benchmark, but rendered visual review and real screenshots remain open.

Final red-team corrections included participant-ID isolation, safe history preservation, input fail-closed behavior, timing-denominator consistency, strict replay of retained sensor evidence and rejection of mock physiological channels labelled empirical. New regression checks cover these findings. All empirical TODOs remain visible. This cycle ends with a coherent reviewed candidate and explicit continuation tasks; it does not assert all internal development or research is finished.
