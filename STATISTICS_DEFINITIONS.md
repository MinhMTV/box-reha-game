# Displayed metrics — 15 September 2026

All participant statistics filter exact active StudyId. History retains its existing 200-summary global cap; research JSONL is not trimmed by this cap. Overview numbers cover available summaries, not an unlimited lifetime archive. Missing session_end remains incomplete and is never converted into a completed summary.

| Displayed metric | Exact definition / source / denominator |
|---|---|
| Sessions | Number of retained completed summaries for active StudyId |
| Training minutes | Sum DurationSeconds / 60; scaled active gameplay time, excludes pause |
| Best score | Maximum recorded Score, including bounded bonuses/partial heavy score |
| Average score | Sum Score / number of retained profile sessions |
| Best combo | Maximum MaxCombo across those sessions |
| Score / Combo / Time HUD | Current awarded total / current combo / active session timer |
| Timing accuracy | (PerfectHits + GoodHits) / TotalTargets. Profile overview pools counts; HUD/results use the current session |
| Completion | (PerfectHits + GoodHits + EarlyHits + LateHits) / TotalTargets |
| Perfect, Good, Early, Late, Miss | Terminal target timing counts, not action counts. See GameplayRules for configured temporal bands |
| Punches / Kicks | PunchActions / KickActions, all emitted game input sources in retained summaries |
| Left / Right actions | LeftActions / RightActions, not sensor true positives |
| Upper/lower target hits | ArmHits/ArmTargets and LegHits/LegTargets in results; heavy is upper-body |
| Heavy timeouts | HeavyTimeouts; partial impacts do not count as completed targets |
| TOO LIGHT actions | BelowStrengthHits: valid matching/timed actions below game threshold. Not a terminal Miss; target can subsequently resolve or time out |
| Average target resolution time | Stored historical AverageReactionTime: mean active spawn-to-successful-resolution duration for successful targets. Misses/aborted targets are not in this mean. This is not pure reaction time |
| Unfinished targets | AbortedTargets; separate from TotalTargets and both ratio denominators |
| Keyboard / sensor / other inputs | KeyboardActions / SensorActions / OtherActions; input provenance retained |
| Mean relative signal by family and side | AlphaLeftRelativeSum/AlphaLeftSamples etc. Accepted calibrated physical actions only; four separate channels; no cross-family averaging. Ratios are clamped at 2.5; different calibration IDs may contribute |
| Gameplay action rate | Sum Actions / sum active DurationSeconds, including the profile's input modes; different from the rapid calibration protocol |
| Strong reference | Median of five accepted raw values after three familiarization actions; separate device, family, side, quantity, unit, SDK mode/version and StudyId |
| Fast sequence reference | Five controlled physical events; reciprocal median of four source-timestamp intervals. SDK acceptance and 120ms ingress cooldown constrain observed rate |
| Game performance by session | Recent date/Score/Timing accuracy/Completion summaries. No inferred health or fitness improvement |
| Reference dates/versions | CreatedUtc, reference kind/channel and short calibration ID of newest available records; raw quantity remains named |

Zero denominator uses the existing UI zero convention (or not available where implemented); analysis should use undefined/missing. Heavy completed count and mean impacts are not newly invented from insufficient historical aggregates.

Personal game thresholds: levels 1/2/3+ require 0.45/0.60/0.75 relative signal. Uncalibrated physical input remains neutral 1 with NormalizationValid=false; the preparation screen explains measured references and the log distinguishes neutral from calibrated actions. Heavy damage is rounded and bounded to 1–2 per accepted above-threshold action. Thresholds are gameplay balance only, not medical limits. No height/weight modifier is active.
