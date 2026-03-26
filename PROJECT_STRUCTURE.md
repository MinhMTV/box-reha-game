# BoxReha Game - Unity Boxing/Rhythm Rehabilitation Game

A 2.5D boxing/rehab rhythm game inspired by Beat Saber, designed for physical rehabilitation and exercise.

## Overview

This project implements a Unity-based rhythm game where players react to incoming targets with boxing-style movements (punch, block, dodge). The game is designed with clean architecture to support future BLE/IMU sensor integration.

## Architecture

### Core Systems
- **GameManager**: Singleton managing game state, scene transitions, and level selection
- **Bootstrapper**: Initializes core systems on boot
- **SceneLoader**: Static utility for scene management
- **GameRoundController**: Orchestrates gameplay rounds

### Input System
- **IPlayerActionInputProvider**: Abstraction for input sources
- **MouseTouchInputProvider**: Mouse/touch input with Punch/Block/Dodge detection
- **InputInterpreter**: Static helper for input classification and vertical position mapping

### Gameplay
- **TargetObject**: Target behavior with distinct visuals per type
- **TargetMover**: Moves targets along Z-axis
- **HitZoneEvaluator**: Hit detection, quality assessment, and visual feedback events
- **ScoreSystem**: Score calculation with combo multipliers
- **ComboSystem**: Combo tracking
- **ActionVisualFeedback**: Lane flash effects on hit/miss
- **SessionTimer**: Round timer management

### Spawning
- **TargetSpawner**: Spawns targets at spawn points with vertical position support
- **SpawnPatternGenerator**: Generates spawn patterns with vertical positions
- **LevelDefinition**: ScriptableObject for level configuration

### UI
- **HUDController**: In-game HUD with score, combo, timer, accuracy, and debug overlay
- **MainMenuController**: Main menu with level selection
- **LevelSelectController**: Dedicated level selection UI
- **ResultsController**: Results screen with reaction time display
- **TextPopup**: Floating text popups for hit/miss feedback
- **DebugUI**: Debug overlay (toggle with D key)

### Data
- **Enums**: Core enumerations (ActionType, LaneType, VerticalPosition, etc.)
- **PlayerActionEvent**: Action event structure with vertical position
- **TargetSpawnData**: Spawn data structure with vertical position
- **GameSessionStats**: Session statistics with reaction time tracking

### Config
- **GameConfig**: Global game configuration with scoring, timing, and input settings

### Sensors (Phase 3 - Stub)
- **ISensorDataProvider**: Interface for raw sensor data
- **BleSensorInputProvider**: Stub BLE input provider for future integration
- **SensorDataBuffer**: Circular buffer for sensor readings

## Scene Flow

```
Boot → MainMenu → Game → Results
  ↑           │         │
  │      Level Select    │
  └──────────────────────┘
```

## Input Mapping

### Punch (Red targets)
- Quick click/release (hold < 0.5s, minimal movement)

### Block (Blue targets)
- Hold mouse button without movement (> 0.5s, < 10px movement)

### Dodge (Green targets)
- Fast horizontal swipe (> 200px in < 0.3s)

### Vertical Position (Phase 3)
- Screen top third → High
- Screen middle third → Mid
- Screen bottom third → Low

## Target Types
- **Punch** (Red): Red cube with slight rotation (45°)
- **Block** (Blue): Blue flat cube (shield-like, 1.8×1.8×0.3)
- **Dodge** (Green): Green stretched cube (2.5×0.8×0.8)

## Hit Quality
- **Perfect**: ±0.1s from hit zone center (100pts)
- **Good**: ±0.25s from hit zone center (50pts)
- **Early**: -0.5s to -0.25s (25pts)
- **Late**: +0.25s to +0.5s (25pts)
- **Miss**: Outside timing windows (0pts)

## Scoring
- Base scores per hit quality
- Block/Dodge targets get minimum 75pts
- Combo multiplier: 1 + (combo × 0.1), max 3×
- Final score = base × multiplier

## Level Design

### Level 1
- Duration: 60 seconds
- Spawn Interval: 2.5 seconds
- Speed: 4 units/s
- Only Punch targets
- All lanes, Mid vertical position

### Level 2
- Duration: 60 seconds
- Spawn Interval: 2 seconds
- Speed: 5 units/s
- Punch + Block targets
- All lanes, Mid vertical position

### Level 3
- Duration: 60 seconds
- Spawn Interval: 1.5 seconds
- Speed: 6 units/s
- Punch + Block + Dodge targets
- All lanes, Low/Mid/High vertical positions

## Visual Feedback
- Hit: Brief green/yellow flash on lane + "PERFECT"/"GOOD" text popup
- Miss: Brief red flash on lane + "MISS" text popup
- Debug overlay: Press D to toggle FPS, state, target count

## Debug UI
Press **D** to toggle the debug overlay showing:
- Current FPS
- Game state
- Selected level
- Active target count

## Scene Setup

See `Scenes/` folder for scene setup instructions.

## Requirements

- Unity 2022.3 LTS or later
- No external dependencies
- Legacy UI (UnityEngine.UI)

## Project Structure

```
Assets/
  Scenes/           # Unity scenes (see setup guide)
  Scripts/
    Core/           # Game management
    Gameplay/       # Gameplay mechanics
    Input/          # Input handling
    Spawning/       # Target spawning
    UI/             # User interface
    Data/           # Data structures
    Config/         # Configuration
    Sensors/        # Sensor interfaces (Phase 3)
```

## Future Roadmap

- **Phase 5**: Visual effects, particle systems, audio feedback
- **Phase 6**: BLE/IMU sensor integration (interface ready)
- **Phase 7**: Leaderboards and achievements
