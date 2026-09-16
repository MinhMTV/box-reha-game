# High-intensity fitness pacing — 16 September 2026

Game balance only; no physiological prescription or sensor qualification. GameplayPacingProfile on TargetSpawner is the configuration authority; HitZoneEvaluator remains the scoring/timing authority. Existing calibration and sensor ingress code are unchanged.

| Tier | Normal | Long | Burst | Conditioning | Travel | Normal action interval | Burst interval | Transition between patterns | Active cap |
|---|---|---|---|---|---|---|---|---|---|
| Easy | 3–6 | 6–8 | 6–10 | 10–12 | 1–1.4 s | .40–.55 s | .30–.40 s | .7–1.2 s | 4 |
| Medium | 5–10 | 10–15 | 15–20 | 20–25 | .75–1.1 s | .28–.38 s | .22–.30 s | .5–.9 s | 5 |
| Hard | 8–15 | 15–25 | 20–35 | 30–50 | .55–.85 s | .22–.30 s | .18–.22 s | .3–.7 s | 7 |

Weighted selection uses 20% conditioning, the burst phase or remaining weight below 45% for bursts, up to 65% for long sequences, otherwise normal sequences. Warmup/recovery use one or two slower actions. Seeded generator variants are alternating, mirrored by starting side, alternating with safe doubles, and power finish. Generator identity does not repeat immediately. Hard can select 40–50 naturally; an Editor fixture also forces an exact alternating 50 for end-to-end verification.

**Rolling lookahead:** logical length is an integer plus constant-size generator state, not a growing array. Only live target slots are counted: four/five/seven, or eight at advanced Endless speed. The scheduler emits the next target as a logical slot becomes free. It never reserves capacity for the full sequence. Later actions remain in the lazy sequence; misses do not cancel that sequence.

Travel values describe first-action movement. Targets within a preview share speed and occupy increasing depth; later actions travel longer by their offset. Preload .08 seconds and normal deploy .20 seconds precede movement. Heavy deploy is .50 seconds. All initial preview targets are instantiated immediately; there is no blank warmup timer. No independent surprise 180-ms reaction target is introduced.

Fastest configured alternating punch interval is .18 seconds. AbsoluteMinimumActionSpacingSeconds and MinimumPhysicalActionSpacingSeconds are inspectable, with an implementation safety floor of .18. PacingActionTimeline retains independent LastLeft and LastRight across patterns. Physical same-side minimum remains the existing GameConfig SensorActionCooldown (.35 seconds); alternating hands are not globally slowed to .35. Kicks always have at least .55 seconds, normally .55–.90. ALPHA remains punch-only, DELTA kick-only, one-sided projection remains playable and physical mixed-family input stays blocked.

**Micro-recovery:** no intentional empty-screen sleep. Easy/Medium/Hard recovery budgets are at most 1.5/1.2/1 seconds, represented by slower one/two-action work. Transition values are scheduled between action times while the next target can already deploy. Heavy is followed by low-intensity work rather than a multi-second wait. Three misses in five seconds request one low-intensity pattern after current queued work; an eight-second MissRecoveryCooldownSeconds and reset window prevent repeated miss-triggered recovery loops.

Phases scale to session duration: Warmup 0–4%, Rhythm 4–12%, Build 12–30%, Burst 30–43%, Recovery 43–47%, Build 47–68%, Burst 68–80%, Heavy 80–90%, final Burst 90–100%. The scheduler samples at pattern boundaries. Long work may cross phase boundaries. Near round end it truncates logical sequences against the round deadline rather than pausing early.

**Endless:** SpeedTier is capped at six, advancing every 25 active seconds. ComboLengthTier is elapsed active seconds / 60 and has no game-design cap. Non-recovery length envelope is floor(5 + 5 × tier) through floor(15 + 10 × tier); weighted seeded selection chooses within it. Conditioning probability grows from .20 by .025 per length tier to .65. Action speed and visible counts stay bounded. Length uses platform integer representation (not mathematically infinite storage), and generation uses constant memory. No calibration reference is consumed; UsePersonalRapidReferenceForPacing remains reserved/false.

**Stall diagnosis:** the previous scheduler re-entered WaitForSeconds(recovery) on every iteration while the sampled time phase remained Recovery. It also waited until final expected arrival plus half a hit window before starting another pattern, then added deployment/travel and optional burst recovery. Full-pattern capacity reservation was additionally incompatible with sequences longer than the cap and would deadlock a naive length increase. These paths are removed: rolling live slots replace whole-pattern reservations, recovery produces actions, and the next timeline is planned while the previous tail remains visible. This is the code-level cause of scheduled gaps; the exact historical on-device pause was not captured in a trace.

Diagnostics include phase, remaining time, pattern, pending count, lookahead, active targets, zero reserved capacity, next spawn/pattern times, recovery deadline, heavy/miss state and wait reason. ActiveWorkTime and LowIntensityTime measure time with visible targets, EmptyIdleTime time with none; these are gameplay visibility metrics, not measured human exertion. The 34–26 seconds remaining window logs twice per second. Unexpected idle over .7/1/1.3 seconds (Hard/Medium/Easy) emits PACING_IDLE_DIAGNOSTIC and releases stale spawn waits. Unsupported input does not fabricate targets.

Scheduling never waits for debris, particles, retraction, break animation or health-bar fade. Existing bounded effects remain independently owned and cleaned up. Physical frame/GC/thermal performance still requires device profiling.

Execution evidence belongs in FITNESS_PACING_VALIDATION.md and artifacts/validation/pacing-playmode.txt. Do not infer a runtime pass from fixture existence.
