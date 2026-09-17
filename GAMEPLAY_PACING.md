# Gameplay pacing — 17 September 2026

Source of truth: `Assets/Scripts/Spawning/GameplayPacingProfile.cs` at main `3f99b17`. It also defines GameplayPatternPlanner, ComboPlan and PacingActionTimeline.

| Difficulty | Start intensity | Opening Punch | Normal | Long | Burst | Conditioning | Lookahead |
|---|---:|---|---|---|---|---|---:|
| Easy | .25 | 2–4 | 3–6 | 6–8 | 6–10 | 10–12 | 4 |
| Medium | .50 | 4–6 | 10–15 | 15–25 | 15–25 | 20–30 | 5 |
| Hard | .80 | 5–8 | 15–25 | 20–35 | 25–35 | 25–50 | 7 |

| Difficulty | Configured travel range | Normal interval range | Burst interval range | Transition range |
|---|---|---|---|---|
| Easy | 1.00–1.40 s | .40–.55 s | .30–.40 s | .70–1.20 s |
| Medium | .55–.75 s | .22–.30 s | .20–.25 s | .25–.40 s |
| Hard | .45–.60 s | .20–.25 s | .18–.22 s | .20–.30 s |

Ranges are configuration envelopes, not measured delivered cadence. Sample interpolates directly from start intensity: first Medium travel .65 s / normal .26 s; first Hard .48 s / normal .21 s. No half-intensity opening blend. Preload .08 s plus normal deployment .20 s precedes travel; first arrival also includes this delay. Conditioning uses the tier burst minimum. Capacity, lane spacing and physical same-side constraints may delay actual arrivals.

## Variation and family cadence
ComboPlan selects deterministic seeded eight-action side motifs, mirrored by starting side. Hard sometimes selects extended-run motifs (including four/five repeated sides within a motif); segment joins must be considered when measuring actual maximum runs. One available device projects every action to its side.
Mixed development uses fixed ten-action P/K motifs, seven with two kicks and one with one kick. It is approximately Punch-dominant 80/20, not an exact per-combo quota. Profile MixedPunchWeight/MixedKickWeight fields are currently not read by TypeAt; changing them alone does not change motifs. Punch→Kick minimum .35 s; Kick→Punch .30 s; consecutive Kicks at least .55 s with configured .55–.90 s cadence.
Kick-only defaults: Easy 2–5, Medium 3–8, Hard 4–12; rare Hard non-normal selection can allow 15; absolute cap 20. Opening/recovery overrides remain short. Physical mixed is rejected by the planner and Android policy.
Global minimum is .18 s. Physical same-side minimum is max(.35 s, GameConfig.SensorActionCooldown); different devices have independent timestamps. These are scheduling rules, not demonstrated BLE throughput.

## Phases, recovery and Endless
Each difficulty owns its phase distribution; sampled at pattern boundaries. Hard boundaries are 5/18/35/48/60/65/78/88/100%: Opening, Build, Burst, Long, Conditioning, Recovery, HighIntensity, HeavyOpportunity, FinalBurst. Long sequences can cross phase boundaries.
Active recovery uses 2–3 Easy or 2–4 Medium/Hard actions, interval ×1.8 with .4 s floor. A miss-triggered recovery request also exists; no empty recovery/VFX wait is intended.
Endless cycles every 60 s; speed tiers advance every 25 s and cap at 6. Outside opening/recovery, Punch-containing sequence envelope grows from `5+5*minutes` to `15+10*minutes` (integer bounds). Kick-only never inherits this growth. Lookahead is capped at 8.

## Heavy and ordering
Heavy due ranges: Easy 18–25 s, Medium 12–18 s, Hard 8–14 s; Endless approaches 7–10 s over 300 s. Minimum separations 13/10/7/6 s. Due encounters wait for a work boundary (12 Punch-plan / 4 Kick-plan actions) and sufficient remaining time; these are not guaranteed exact arrival periods. Durability is seeded within level MinToughHits..MaxToughHits. Heavy work waits for logical resolution, not debris.
Target speed derives from spawn distance / sampled travel duration. Lookahead capacity and minimum same-lane visual spacing (1.1 world units) delay spawn timestamps rather than accelerate targets or push spawn positions beyond the room. See [SPAWNING_ARCHITECTURE.md](SPAWNING_ARCHITECTURE.md).

Latest compile/build passed; no latest-speed Play Mode or hardware cadence validation is claimed. Older fitness reports are historical. Parameters are game balance, not physiological prescriptions or HR/calibration-driven adaptation.
