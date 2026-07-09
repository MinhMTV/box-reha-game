# Current Gameplay State

This Unity 2022.3 project is a 2.5D rhythm/combat serious game for boxing and kicking rehab training.

## Keyboard Controls

| Input | Action | Sensor Equivalent | Lane |
| --- | --- | --- | --- |
| Hold/release Left Arrow | Left punch, hold longer = stronger | RD ALPHA | Left |
| Hold/release Right Arrow | Right punch, hold longer = stronger | RD ALPHA | Right |
| Hold/release A | Left kick, hold longer = stronger | RD DELTA | Left |
| Hold/release D | Right kick, hold longer = stronger | RD DELTA | Right |
| F1 | Toggle debug UI | Debug only | - |

Keyboard input is implemented as a mock/debug input provider and emits the same `PlayerActionEvent` structure that sensor input uses.

## Gameplay

- Normal punch targets spawn only in the left or right upper lanes.
- Normal kick targets spawn only in the left or right lower lanes.
- The center lane is reserved for the Heavy Center Target.
- Heavy Center Targets can be damaged by repeated valid punches from either side.
- Heavy Targets no longer require strict left/right alternation.
- Heavy Targets stop in the hit zone and must be destroyed before the wave continues.
- Dodge/duck targets are currently disabled for non-VR play.
- The game can still run without RD ALPHA/RD DELTA hardware.

## Tuning

- Target speed is controlled by `TargetSpeed` in `Assets/Scripts/Spawning/LevelDefinition.cs`.
- Spawn timing is controlled by `SpawnInterval` in `Assets/Scripts/Spawning/LevelDefinition.cs`.
- Heavy Target life is controlled by `MinToughHits` and `MaxToughHits` in `Assets/Scripts/Spawning/LevelDefinition.cs`.
- If you later use serialized `LevelDefinition` assets, the same fields are editable in the Unity Inspector.

## Sensor Integration

- RD ALPHA maps to punch-style actions.
- RD DELTA maps to kick/foot-style actions.
- `BleSensorInputProvider`, `SensorReading`, and `DynamicsSdkBridge` remain the integration path for real hardware.
- The native SDK bridge still needs calibrated real device data for production tuning, but the gameplay loop is already separated from the concrete input source.
