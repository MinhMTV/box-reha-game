# Visual status — 2026-09-14

Actual Unity 6000.6.0f1 Play Mode produced the current-build screenshots. The final set contains 46 PNGs: ten screens at 1920x1080, 1280x720, 2400x1080 and 1024x768, plus six additional preparation steps at 1280x720.

- [Final gameplay](DesignReferences/CurrentBuild/Final/Gameplay-Targets-HUD-1280x720.png)
- [Final menu](DesignReferences/CurrentBuild/Final/Home-1280x720.png)
- [Final pause](DesignReferences/CurrentBuild/Final/Pause-1280x720.png)
- [Preparation summary](DesignReferences/CurrentBuild/Final/Calibration-Step-7-1280x720.png)
- [Blender kit review](ArtSource/Blender/DigitalDojo/asset-review.png)

`DesignReferences/CurrentBuild/Before` records the actual prior magenta target/material state. `After-01` through `After-05` are ignored local diagnostic iterations in the validation worktree. The `Final` set supersedes them.

## Review and corrections

Corrected incompatible shader selection in the Built-in project, FBX target front orientation/unit-root integration, floor extent, camera framing, marker occlusion, labels and the hidden pause overlay. The pause defect also explained persistent darkening of gameplay. Navigation now highlights the active page. The room uses shared materials and static batching; target accents use MaterialPropertyBlock. Existing action/target gameplay remains authoritative.

Reviewed home, gameplay, pause, preparation, profile, settings, sensor setup, statistics, levels and results. Final captures expose actual unavailable sensor states and synthetic QA results; they contain no fabricated measurements. The synthetic QA profile/history/research directory is isolated from ordinary participant data.

## Evidence boundaries

The capture harness invokes real menu entrypoints and gameplay handlers in Play Mode, then renders the real camera/UI into RenderTextures. Overlay canvases are temporarily adapted to camera rendering. These are not Android-device screenshots and do not prove cutout handling, touch accuracy or mobile frame rate. Text appears softer in these offscreen captures; on-device legibility remains a qualification item.

`Assets/Editor/DigitalDojoCapture.cs` is opt-in (`-executeMethod DigitalDojoCapture.Run`, `DOJO_CAPTURE_PASS=<folder>`). It checks gameplay and pause visibility, writes `artifacts/validation/dd-runtime-checks.txt`, and logs `DIGITAL_DOJO_CAPTURE_COMPLETE`. Unity Editor Search emits an ArgumentOutOfRangeException during startup; completed checks do not justify a zero-Console-error claim. Several graphics-enabled batch processes remained alive during shutdown after completion and were terminated only after their results were written.

Art direction and sources: [ART_DIRECTION](ART_DIRECTION.md), [benchmark review](docs/projects/digital-dojo/BENCHMARK_REVIEW.md). No concept image is passed off as an in-game screenshot.
