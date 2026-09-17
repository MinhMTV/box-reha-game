# Gameplay pacing — 17 September 2026

GameplayPacingProfile is the sole pacing configuration. See SPAWNING_ARCHITECTURE.md for runtime flow, migration audit and ownership.

| Difficulty | Start intensity | Opening Punch | Normal | Long | Burst | Conditioning | Visible |
|---|---:|---|---|---|---|---|---:|
| Easy | .25 | 2–4 | 3–6 | 6–8 | 6–10 | 10–12 | 4 |
| Medium | .50 | 4–6 | 5–10 | 10–15 | 15–20 | 20–25 | 5 |
| Hard | .80 | 5–8 | 8–15 | 15–25 | 20–35 | 30–50 | 7 |

Hard opening travel .73s, normal interval .268s; later normal approaches .22s and burst .18s. There is no empty warmup timer. The initial queue is spawned immediately and mechanically deploys.
Physical per-side refractory stays .35s; alternating hands may run .18s apart. Kick cadence >=.55s. Mixed development motifs are Punch-dominant; physical mixed is blocked.
Kick-only Easy2–5, Medium3–8, Hard4–12, rare15, absolute20. Opening/recovery are smaller bounded sequences. Endless Kick never inherits uncapped Punch growth.
Recovery is active work: Easy2–3, Medium/Hard2–4 with configurable interval multiplier1.8. Transitions are timestamp gaps while rolling targets remain visible, not waits for VFX.

## Phase-dependent selection
Hard phase ends:5/18/35/48/60/65/78/88/100%.
Normal/Long/Burst/Conditioning weights:
Opening50/35/15/0; Build20/35/30/15; Burst5/10/50/35; Long0/60/25/15; Conditioning and HighIntensity0/15/35/50; Final0/0/30/70. Opening length is overridden by its difficulty range. Recovery uses its own active-work range.
Easy and Medium independent editable distributions and phase boundaries live in EasyCurve/MediumCurve. Sampling occurs at logical pattern boundaries; long work may cross a phase boundary.

Heavy has one timer, serviced at 12-Punch / 4-Kick-action segment boundaries or pattern starts. Ranges18–25/12–18/8–14s, minimum separation13/10/7s. Boundary delay is possible. Durability is seeded inclusive Min/Max. Heavy ends on logical resolution, never on debris completion.
Endless speed tier caps at6; logical Punch envelope grows from5+5*minutes through15+10*minutes, with platform integer bounds only. Lookahead caps at8. Opening and active recovery remain short.
Preview horizon simulates actual action timestamps, including Kick and same-side constraints. Capacity pressure never positions targets beyond the room.

These are game balance parameters, not physiological prescriptions. Personal measured calibration does not drive pace. The current APK receipt is `artifacts/validation/unity-android-candidate-build.json`; synthetic execution records are historical validation artifacts.
