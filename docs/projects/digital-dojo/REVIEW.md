# DD-M1 review — 2026-09-14

## Verified outcomes

- Actual Unity 6000.6.0f1 migration and C# compilation, Built-in/uGUI retained. Android modules installed and candidate settings prepared by Editor API.
- Original Blender kit: nine models, source .blend, reproducible script, FBX, inventory and Blender-rendered asset review. Prefabs/materials/room integrated through Editor API.
- Real Play Mode screenshot review across four resolutions; final set in DesignReferences/CurrentBuild/Final. Screens are not Android-device screenshots. QA profile, history and logs are isolated and synthetic.
- Gameplay regression includes all four side/action combinations, wrong-side/action rejection, five same-hand heavy hits, score/combo, provenance and pause/resume. Host policy checks remain a separate evidence level.

## Findings and corrections

1. P1: URP shader selection in a Built-in scene produced magenta target visuals. Shared Standard materials and runtime-compatible shader choice corrected this.
2. P1: FBX front/unit conversion was lost under gameplay transforms. Identity wrapper roots preserve import transforms; target fronts rotate toward the player.
3. P1: Camera/floor framing and full-width action bars reduced target readability. Extended room, closer camera and short scoring-plane brackets correct this.
4. P1: Missing CanvasGroup used C# null-coalescing with Unity's missing-component sentinel, so hidden pause graphics remained visible and darkened gameplay. Explicit Unity null comparison plus disabled content fixes this; capture asserts playing/paused alpha.
5. P2: Navigation highlighted Level mode on every page. Active page now owns the highlight.
6. P2: Heavy segment feedback and guide material ownership were corrected and verified before handoff; results are recorded in reviews/DD-006.md.

## Boundaries

The native vendor SDK dependency fails before full Kotlin integration can qualify. Permission/settings changes are source-implemented, not physical-device tested. ALPHA+DELTA mixed sessions, measured calibration, HR, touch/cutouts and mobile profiling remain separate gates. Existing thesis/expose scope and SDK repository are unchanged.

Unity Editor Search logs an engine/package startup exception. Some owned batch Editors hang during shutdown after writing completed reports. These were not reported as clean process exits. The scripted verification wrapper and direct BuildPipeline attempt are described in ANDROID_STATUS.md.
