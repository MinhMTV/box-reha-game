# BoxReha Game - Setup Guide

## Unity Version
Use Unity 2022.3 LTS or later.

## Step 1: Create Project
1. Open Unity Hub
2. Click "New Project"
3. Select "3D" template
4. Name: "BoxRehaGame"
5. Location: Choose your preferred directory
6. Click "Create Project"

## Step 2: Import Scripts
1. Copy the entire `Assets/Scripts` folder into your Unity project's Assets folder
2. Wait for Unity to compile the scripts

## Step 3: Create Scenes

### Scene 1: Boot
1. File → New Scene → Basic (Built-in)
2. Save as `Assets/Scenes/Boot.unity`
3. Create empty GameObject: "GameManager"
   - Add Component: `GameManager`
4. Create empty GameObject: "Bootstrapper"
   - Add Component: `Bootstrapper`
5. Set Bootstrapper settings:
   - Auto Load Main Menu: ✓
   - Delay: 0.5

### Scene 2: MainMenu
1. File → New Scene → Basic (Built-in)
2. Save as `Assets/Scenes/MainMenu.unity`
3. Create Canvas: Right-click Hierarchy → UI → Canvas
4. Create Panel inside Canvas:
   - Add Component: `MainMenuController`
5. Create Button "Start Game" inside Panel:
   - On Click → MainMenuController → OnStartGameButton
6. Create Button "Quit" inside Panel:
   - On Click → MainMenuController → OnQuitButton
7. Create Text "BoxReha" (title) inside Panel

### Scene 3: Game
1. File → New Scene → Basic (Built-in)
2. Save as `Assets/Scenes/Game.unity`
3. Create empty GameObject: "GameRoundController"
   - Add Component: `GameRoundController`
4. Create empty GameObject: "TargetSpawner"
   - Add Component: `TargetSpawner`
5. Create empty GameObject: "SessionTimer"
   - Add Component: `SessionTimer`
6. Create empty GameObject: "ScoreSystem"
   - Add Component: `ScoreSystem`
7. Create empty GameObject: "ComboSystem"
   - Add Component: `ComboSystem`
8. Create empty GameObject: "HitZoneEvaluator"
   - Add Component: `HitZoneEvaluator`
   - Add BoxCollider (Is Trigger: ✓)
   - Size: (10, 5, 2)
   - Position: (0, 2.5, 5)
9. Create empty GameObject: "InputManager"
   - Add Component: `MouseTouchInputProvider`
10. Create empty GameObject: "PlayerRoot"
    - Position: (0, 0, 5)
11. Create empty GameObject: "SpawnRoot"
    - Position: (0, 0, 30)
12. Create empty GameObject: "SpawnPoint_Left"
    - Parent: SpawnRoot
    - Position: (-3, 1, 30)
13. Create empty GameObject: "SpawnPoint_Center"
    - Parent: SpawnRoot
    - Position: (0, 1, 30)
14. Create empty GameObject: "SpawnPoint_Right"
    - Parent: SpawnRoot
    - Position: (3, 1, 30)
15. Create Canvas for HUD
16. Create Text "ScoreText" inside Canvas
    - Position: Top-left area
    - Font Size: 24
17. Create Text "ComboText" inside Canvas
    - Position: Top-center area
    - Font Size: 28
18. Create Text "TimerText" inside Canvas
    - Position: Top-right area
    - Font Size: 32
19. Add `HUDController` to Canvas
    - Drag ScoreText → Score Text field
    - Drag ComboText → Combo Text field
    - Drag TimerText → Timer Text field

**GameRoundController Inspector Setup:**
- Target Spawner: Drag TargetSpawner GameObject
- Session Timer: Drag SessionTimer GameObject
- Score System: Drag ScoreSystem GameObject
- Combo System: Drag ComboSystem GameObject
- Hit Zone Evaluator: Drag HitZoneEvaluator GameObject
- Input Provider: Drag InputManager GameObject
- HUD Controller: Drag HUD Canvas

**TargetSpawner Inspector Setup:**
- Spawn Point Left: Drag SpawnPoint_Left
- Spawn Point Center: Drag SpawnPoint_Center
- Spawn Point Right: Drag SpawnPoint_Right
- Miss Zone Z: 0

**Camera Setup:**
- Position: (0, 5, -10)
- Rotation: (20, 0, 0)
- Field of View: 60

### Scene 4: Results
1. File → New Scene → Basic (Built-in)
2. Save as `Assets/Scenes/Results.unity`
3. Create Canvas
4. Add `ResultsController` to Canvas
5. Create Text elements:
   - ScoreText
   - AccuracyText
   - PerfectText
   - GoodText
   - EarlyText
   - LateText
   - MissText
   - MaxComboText
6. Create Button "Restart"
   - On Click → ResultsController → OnRestartButton
7. Create Button "Main Menu"
   - On Click → ResultsController → OnMainMenuButton

**ResultsController Inspector Setup:**
- Drag all Text elements to corresponding fields

## Step 4: Build Settings
1. File → Build Settings
2. Add scenes in order:
   - Boot (index 0)
   - MainMenu (index 1)
   - Game (index 2)
   - Results (index 3)
3. Ensure "Boot" is at index 0

## Step 5: Play
1. Open Boot scene
2. Press Play
3. Game should:
   - Boot → Load MainMenu
   - Click Start → Load Game
   - Click/tap screen to punch targets
   - Timer counts down
   - When time up → Load Results
   - Shows stats
   - Can Restart or return to Main Menu

## Troubleshooting

### Scripts not compiling
- Ensure all scripts are in `Assets/Scripts/` folder
- Check for missing semicolons or braces
- Unity Console will show compilation errors

### Game doesn't start
- Check Boot scene is first in Build Settings
- Ensure GameManager and Bootstrapper are in Boot scene
- Check Console for errors

### Targets not spawning
- Ensure TargetSpawner has spawn points assigned
- Check SessionTimer is running
- Verify GameRoundController references

### Input not working
- Ensure InputManager has MouseTouchInputProvider
- Check GameRoundController links to InputManager
- Verify MouseTouchInputProvider is enabled

### HUD not updating
- Check HUDController has all Text references
- Ensure events are subscribed (OnEnable/OnDisable)
- Verify ScoreSystem and ComboSystem are active

## Inspector Reference Values

### GameManager
- Boot Scene Name: "Boot"
- Main Menu Scene Name: "MainMenu"
- Game Scene Name: "Game"
- Results Scene Name: "Results"

### Bootstrapper
- Auto Load Main Menu: ✓
- Delay: 0.5

### HitZoneEvaluator
- BoxCollider Is Trigger: ✓
- BoxCollider Size: (10, 5, 2)
- BoxCollider Center: (0, 2.5, 0)

### Camera
- Position: (0, 5, -10)
- Rotation: (20, 0, 0)
- FOV: 60

### Spawn Points
- Left: (-3, 1, 30)
- Center: (0, 1, 30)
- Right: (3, 1, 30)

### Player Root
- Position: (0, 0, 5)

## Notes
- Phase 1: Only Punch targets
- Mouse/Touch input only
- 60-second rounds
- Score and combo tracking
- Results screen with full stats
