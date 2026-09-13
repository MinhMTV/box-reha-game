# Digital Dojo interface

The existing warm wood / matte dark dojo environment and target assets are retained. The current hub is built by DigitalDojoMenuController at runtime and replaces the old concept-only UI children in Awake.

The Android UI and full collector flow below describe the implemented source against the documented SDK API. Native compilation remains blocked by missing production `resource:2.11.1` and stripped Kotlin metadata/InnerClasses in the supplied Android AARs; even the separate diagnostic 2.12.0 substitution does not compile that API. No running APK or device UI is implied. See [SDK package blockers](SDK_PACKAGE_BLOCKERS_2026-09-14.md).

The hub includes Home, Level Mode, Endless Mode, Sensor Setup, Calibration, Statistics, Player Profile, Settings and Exit. Level Mode offers all three presets. Statistics load local session history for the active pseudonymous ID. Profile provides a display name and explicit New participant ID action. Settings apply SFX volume, reduced motion and an explicit physical/development input choice.

The Android sensor path has three touch-operated steps: connection/permissions/discovery and explicit side assignment; the separate required SDK body profile; and family/session readiness. Each step displays actual native status and errors. Body fields start empty and gender has no automatic selection. The session screen explains single-family limits, experimental Delta kick mapping, connected-side target selection and missing prerequisites. End SDK session provides recovery from an incomplete SDK start. A matching running acknowledgement is required before scene entry.

The top HUD uses live score, combo, time and timing accuracy. The bottom shows controls, actual input/native status and an always-visible PAUSE touch button. The active pause overlay shows Resume and Finish & Results plus the current native prerequisite/error state. Backgrounding or connection loss also opens that overlay; Resume remains gated. UI pointer presses are excluded from gameplay gestures. Results distinguish completion, timing, active target-resolution time, action side split and unfinished targets, and expose the native finish status.

The UI uses Unity UGUI and a 1600x900 reference with CanvasScaler Expand. A Canvas child follows Screen.safeArea, and Android uses landscape orientation. Layout, effective physical touch size, text/keyboard fit, contrast and target occlusion still require a real player review on OnePlus 15 and Galaxy Tab S3. No actual screenshots have been produced by this source change. Unity 6.6 migration is pending; the repository remains pinned to 2022.3.62f3 until actual import and checks.

## Scene generator

BoxReha > Build Digital Dojo Menu Scene now creates the room, canvas and runtime hub controller. It no longer generates fabricated profile, calibration, sensor-status or statistics values.

The current serialized MainMenu.unity still contains historical concept children. They are disabled/destroyed before runtime rendering, but an Editor screenshot without entering Play Mode may display that old concept. Such an image is not evidence of the implemented data-backed hub. Regenerate only in a controlled Unity session after compile and runtime checks.

BoxReha > Create All Scenes rewrites all scenes and generated assets. Do not run it merely to inspect the project or verify these changes.

## Implemented limits

Calibration is a clearly identified preparation screen; sensor data collection and baseline persistence are not yet implemented there. There is no active HR display or physiological adaptation UI. Effects are reused or reduced for readability; no claim of AAA quality or validated accessibility is made without rendered and user review.

See GAMEPLAY_UI_AUDIT.md for rationale and verification gates.
