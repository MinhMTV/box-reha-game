# Digital Dojo Design Pass

This project now contains a generated Digital Dojo UI pass based on the provided references.

## How To Build The Menu Scene

Open the project in Unity 2022.3 and run:

`BoxReha > Build Digital Dojo Menu Scene`

This rebuilds `Assets/Scenes/MainMenu.unity` with:

- Dark dojo background with wood floor, warm wall lights, red/blue lane accents
- Large left-side main menu card
- Home, Calibration, Statistics, Player Profile, and Settings panels
- Buttons wired to the existing `GameManager`
- Existing generated punch, kick, and heavy target prefabs used as the scene preview

You can also run:

`BoxReha > Create All Scenes`

This now uses the Digital Dojo menu generator instead of the older placeholder menu.

## Runtime Game Dressing

The playable `Game` scene receives a Digital Dojo environment at runtime through:

`Assets/Scripts/Visuals/DigitalDojoRuntimeDressing.cs`

It creates:

- Warm dark dojo room shell
- Wood floor and wall slats
- Red hit line
- Red, blue, and center lane lights
- Camera and light polish for the front-view rhythm game

This does not change the sensor/input/gameplay architecture.

## Current Limitation

The design is recreated with Unity primitives, UGUI, materials, emission, and generated prefabs. It is not pixel-perfect image reproduction, but it follows the same composition and visual language so the game remains editable and dependency-free.
