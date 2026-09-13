# Digital Dojo interface

The existing warm wood / matte dark dojo environment and target assets are retained. The current hub is built by DigitalDojoMenuController at runtime and replaces the old concept-only UI children in Awake.

The hub includes Home, Level Mode, Endless Mode, Calibration, Statistics, Player Profile, Settings and Exit. Level Mode now offers all three presets. Statistics are loaded from local session history for the active pseudonymous ID. Profile provides a display name and explicit New participant ID action. Settings apply actual SFX volume and reduced motion.

The top HUD uses live score, combo, time and timing accuracy. The bottom shows controls and actual input provider status. Invented limb percentages, calibration values and demographic force estimates were removed. Results distinguish completion, timing, active target-resolution time, action side split and unfinished targets.

The UI uses Unity UGUI and a 1600x900 reference with CanvasScaler Expand. Layout, contrast and target occlusion still require inspection in a running Unity build. No actual screenshots have been produced by this source-only change.

## Scene generator

BoxReha > Build Digital Dojo Menu Scene now creates the room, canvas and runtime hub controller. It no longer generates fabricated profile, calibration, sensor-status or statistics values.

The current serialized MainMenu.unity still contains historical concept children. They are disabled/destroyed before runtime rendering, but an Editor screenshot without entering Play Mode may display that old concept. Such an image is not evidence of the implemented data-backed hub. Regenerate only in a controlled Unity session after compile and runtime checks.

BoxReha > Create All Scenes rewrites all scenes and generated assets. Do not run it merely to inspect the project or verify these changes.

## Implemented limits

Calibration is a clearly identified preparation screen; sensor data collection and baseline persistence are not yet implemented there. There is no active HR display or physiological adaptation UI. Effects are reused or reduced for readability; no claim of AAA quality or validated accessibility is made without rendered and user review.

See GAMEPLAY_UI_AUDIT.md for rationale and verification gates.
