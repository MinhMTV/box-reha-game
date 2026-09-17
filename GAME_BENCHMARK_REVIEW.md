> Historical snapshot — current behavior and build identity are documented in [GAME_STATUS.md](GAME_STATUS.md), [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md) and [ANDROID_STATUS.md](ANDROID_STATUS.md). Older numbers, completion claims, paths and blockers below apply only to their recorded source/artifact. Remaining work: [TODO.md](TODO.md). Reviewed 17 September 2026; no tests rerun.

# Game benchmark and art-direction review

Role J / UI review, 2026-09-13. Documentary comparison, not a hands-on comparative user study. Product pages identify published features; the adaptations below are this project's design judgments. No assets, music, character designs or proprietary scoring rules were copied. Current Digital Dojo source was inspected; its new runtime presentation still needs fresh Unity captures.

| Reference and evidence | Principle to examine | Adopt / adapt / reject in this prototype | Verification still needed |
|---|---|---|---|
| [Beat Saber official site](https://www.beatsaber.com/) and its FAQ | Immediate understanding of the action requested by an approaching target; close feedback/action timing | Adapt: stable approach direction, separate upper punch and lower kick silhouettes, physical side, text and colour cues. Reject VR saber geometry, complex direction recognition and music-library production requirements. This is a readability hypothesis, not a claim of Beat Saber-equivalent experience. | Can a new player identify action and side without reading a manual? Can they see the next target during a hit effect? |
| [Fitness Boxing 3 official description](https://www.nintendo.com/us/store/products/fitness-boxing-3-your-personal-trainer-switch/) | Guided boxing interaction and user choice of training/session characteristics | Adapt: clear mode/level selection, short instruction cues and explicit session end. Reject animated personal trainers and any inference that controller detection validates force measurement. | First-session setup, instruction comprehension, stop/results flow and meaningful difficulty differences. |
| [Ring Fit Adventure official FAQ](https://www.nintendo.com/sg/switch/al3p/faq/index.html) | Adjustable exercise load and approachable setup | Adapt: selectable predefined levels and manual stop; plan measured comfortable-action calibration separately. Reject automatic clinical intensity prescriptions and copying its exercise repertoire/character system. | Participant-selected pace, assistance needs and actual per-side calibration if included later. |
| [Wii Fit Channel overview](https://en-americas-support.nintendo.com/app/answers/detail/a_id/2532/kw/wii) | Accessible progress history | Adapt: real recent session history, stable participant IDs and explicit metric denominators. Reject weight/BMI collection without an RQ justification; do not repurpose game scores as health measures. | Save/reload, profile separation, corrupted-history preservation and participants' interpretation of results. |
| [ExerCube adaptation study](https://www.frontiersin.org/journals/psychology/articles/10.3389/fpsyg.2021.572877/full) | Distinguishing physical workload from cognitive/game challenge in adaptation | Adapt at design level: separate HR quality channel, bounded decisions, explicit dropout behaviour. Current game remains time-progressed and HR-inactive. The published comparison concerns different maximum-HR inputs, not a blanket adaptive/non-adaptive comparison or this game. | Real HR source/coverage, clock alignment and controller qualification before any physiological result. |

## Digital Dojo decisions

Retain the existing room, warm matte materials and restrained red accents. Use a quiet dark navigation panel, visible active identity, high-contrast primary action, and compact session results. Preserve target visibility over decoration. Ordinary targets occupy left/right; centre is reserved for the larger repeated-punch disc. Distinguish hits through brief labels and impact feedback. Reduced motion limits target animation; it must be verified on the actual display.

The runtime menu replaces historical serialized concept children. The scene editor can still show that old concept content; an Editor scene screenshot is therefore not evidence of the new runtime UI. Calibration has an honest unavailable state. No fake connected status, sample baselines, invented training history or physiological widget belongs in study screenshots.

## Review rubric for the runnable candidate

Record build/source digest, resolution, aspect ratio, input source and observed result for each item. Proposed checks: 1280×720 and 1920×1080 with actual study hardware, plus 4:3/ultrawide layout inspection if relevant. Do not mark passed from static source alone.

1. Main menu: primary start action and participant identity visible; each navigation action leads to its labelled page.
2. Onboarding: left/right punch and kick instructions map to the actual shared action pipeline.
3. Gameplay: target silhouettes, lower kick orientation and hit line readable during dense sequences.
4. HUD: score/combo/time/accuracy remain outside the target approach; heavy health visible only while active.
5. Feedback: one terminal outcome, brief timing text, no persistent overlay obscuring the next action.
6. Stop: ESC pause, resume and finish/results work at any point, including heavy timeout and connection loss.
7. Results: denominator, incomplete targets and input condition clear; no force unit inferred from gameplay power.
8. Accessibility: reduced-motion setting persists and changes the advertised effects; text/shape cues remain usable without relying on red/blue distinction.

Disposition: source-level design changes implemented; hands-on benchmark comparison and fresh visual acceptance remain **NOT RUN**.
