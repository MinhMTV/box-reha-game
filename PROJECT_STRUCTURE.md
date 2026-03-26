# BoxReha Game - Unity Boxing/Rhythm Rehabilitation Game

A 2.5D boxing/rehab rhythm game inspired by Beat Saber, designed for physical rehabilitation and exercise.

## Overview

This project implements a Unity-based rhythm game where players react to incoming targets with boxing-style movements (punch, block, dodge). The game is designed with clean architecture to support future BLE/IMU sensor integration.

## Architecture

### Core Systems
- **GameManager**: Singleton managing game state and scene transitions
- **Bootstrapper**: Initializes core systems on boot
- **SceneLoader**: Static utility for scene management
- **GameRoundController**: Orchestrates gameplay rounds

### Input System
- **IPlayerActionInputProvider**: Abstraction for input sources
- **MouseTouchInputProvider**: Mouse/touch input implementation
- **InputInterpreter**: Static helper for input classification

### Gameplay
- **TargetObject**: Target behavior and properties
- **TargetMover**: Moves targets along Z-axis
- **HitZoneEvaluator**: Hit detection and quality assessment
- **ScoreSystem**: Score calculation with combo multipliers
- **ComboSystem**: Combo tracking
- **SessionTimer**: Round timer management

### Spawning
- **TargetSpawner**: Spawns targets at spawn points
- **SpawnPatternGenerator**: Generates spawn patterns
- **LevelDefinition**: ScriptableObject for level configuration

### UI
- **HUDController**: In-game HUD display
- **MainMenuController**: Main menu interactions
- **ResultsController**: Results screen display

### Data
- **Enums**: Core enumerations
- **PlayerActionEvent**: Action event structure
- **TargetSpawnData**: Spawn data structure
- **GameSessionStats**: Session statistics

### Config
- **GameConfig**: Global game configuration

## Scene Flow

```
Boot → MainMenu → Game → Results
  ↑                    │
  └────────────────────┘
```

## Input Mapping

### Phase 1 (Current)
- **Mouse/Touch Down**: Start tracking
- **Mouse/Touch Up**: Trigger Punch action
- **Screen Position**: Left/Center/Right third = Lane
- **Hold Duration**: Power (0.3s = max power)

### Future Phases
- **Swipe**: Dodge action
- **Hold**: Block action
- **BLE/IMU**: Sensor-based input

## Target Types
- **Punch** (Red): Quick punch targets
- **Block** (Blue): Block targets (Phase 2)
- **Dodge** (Green): Dodge targets (Phase 2)

## Hit Quality
- **Perfect**: ±0.1s from hit zone center (100pts)
- **Good**: ±0.25s from hit zone center (50pts)
- **Early**: -0.5s to -0.25s (25pts)
- **Late**: +0.25s to +0.5s (25pts)
- **Miss**: Outside timing windows (0pts)

## Scoring
- Base scores per hit quality
- Combo multiplier: 1 + (combo × 0.1), max 3×
- Final score = base × multiplier

## Level Design

### Level 1 (Phase 1)
- Duration: 60 seconds
- Spawn Interval: 2.5 seconds
- Speed: 4 units/s
- Only Punch targets
- All lanes

### Level 2 (Future)
- Duration: 60 seconds
- Spawn Interval: 2 seconds
- Speed: 5 units/s
- Punch + Block targets
- All lanes

### Level 3 (Future)
- Duration: 60 seconds
- Spawn Interval: 1.5 seconds
- Speed: 6 units/s
- Punch + Block + Dodge targets
- All lanes

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
```

## Getting Started

1. Open project in Unity 2022.3 LTS
2. Create required scenes (see SETUP_GUIDE.md)
3. Add scene hierarchy (see SETUP_GUIDE.md)
4. Play the Boot scene

## Future Roadmap

- **Phase 2**: Block and Dodge actions
- **Phase 3**: BLE/IMU sensor integration
- **Phase 4**: Multiple levels and difficulty
- **Phase 5**: Visual effects and audio feedback
- **Phase 6**: Leaderboards and achievements
