# Hit gate — 17 September 2026

HitZoneVisualizer is the sole runtime gate. It follows HitZoneEvaluator.HitZonePosition in all three world axes. Default hit plane is Z=2. Upper red/lower blue rows use configured action heights relative to that origin.
Before input, state is conveyed by marker brightness/thickness: Dormant, Approaching, Ready, PerfectWindow. No PUNCH/KICK, EARLY or LATE pre-action labels are shown.
Only evaluated outcomes display short feedback: PERFECT/GOOD/EARLY/LATE, MISS or TOO LIGHT — RETRY. Weak input leaves the target active; the real hit window still applies.
Evaluator timing remains authoritative: Perfect within100ms, Good within250ms, accepted remaining half-window Early/Late. Heavy locks and remains actionable; deployment is not actionable. Visualizer does not score.
Legacy EnsureHitGuide/CreateGuide/material ownership code is removed. Regression includes changed XYZ, empty pre-action labels, real outcomes, retries, Heavy fallback and repeated-resolution rejection.
Current evidence: artifacts/validation/hit-gate-playmode.txt and DesignReferences/CurrentBuild/Gameplay-Consolidation/. Hardware BLE/display latency remains unverified.
