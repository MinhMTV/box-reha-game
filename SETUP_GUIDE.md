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
6. Create Text "BoxReha" (title) inside Panel
7. **Level Selection (Phase 4):**
   Create 3 buttons for level selection:
   - Button "Level 1 - Easy": On Click → MainMenuController → OnStartLevel1
   - Button "Level 2 - Medium": On Click → MainMenuController → OnStartLevel2
   - Button "Level 3 - Hard": On Click → MainMenuController → OnStartLevel3
8. Create Button "Quit" inside Panel:
   - On Click → MainMenuController → OnQuitButton

**Alternative: Use LevelSelectController**
- Add `LevelSelectController` to a separate Panel
- Drag the 3 level buttons to Level1/2/3 Button fields
- Each button auto-wires via Start()

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
   - (Optional) Add `GameConfig` ScriptableObject reference
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
15. **Lane Visual Feedback (Phase 4):**
    Create 3 plane/cube objects as lane floor indicators:
    - "Lane_Left": Position (-3, 0, 5), Scale (2, 0.1, 8), dark gray material
    - "Lane_Center": Position (0, 0, 5), Scale (2, 0.1, 8), gray material
    - "Lane_Right": Position (3, 0, 5), Scale (2, 0.1, 8), dark gray material
    Create empty GameObject: "ActionVisualFeedback"
    - Add Component: `ActionVisualFeedback`
    - Drag Lane renderers to Left/Center/Right fields
16. **Debug UI (Phase 4):**
    Create a separate Canvas or child: "DebugCanvas"
    - Add Text "DebugText" (top-left, font size 16)
    - Add Component: `DebugUI` to DebugCanvas
    - Drag DebugText to Debug Text field
17. Create Canvas for HUD
18. Create Text "ScoreText" inside Canvas
    - Position: Top-left area
    - Font Size: 24
19. Create Text "ComboText" inside Canvas
    - Position: Top-center area
    - Font Size: 28
20. Create Text "TimerText" inside Canvas
    - Position: Top-right area
    - Font Size: 32
21. Create Text "AccuracyText" inside Canvas
    - Position: Below ScoreText
    - Font Size: 20
22. Add `HUDController` to Canvas
    - Drag ScoreText → Score Text field
    - Drag ComboText → Combo Text field
    - Drag TimerText → Timer Text field
    - Drag AccuracyText → Accuracy Text field

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
- Game Config: (Optional) Drag GameConfig asset

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
   - **ReactionTimeText** (Phase 4: Shows average reaction time)
6. Create Button "Restart"
   - On Click → ResultsController → OnRestartButton
7. Create Button "Main Menu"
   - On Click → ResultsController → OnMainMenuButton

**ResultsController Inspector Setup:**
- Drag all Text elements to corresponding fields
- Drag ReactionTimeText → Reaction Time Text field

## Step 4: GameConfig (Optional)
1. In Project window: Right-click → Create → BoxReha → GameConfig
2. Configure values:
   - **Timing**: PerfectWindow 0.1s, GoodWindow 0.25s, EarlyLateWindow 0.5s
   - **Scoring**: Perfect 100, Good 50, Early/Late 25, Block 75, Dodge 75
   - **Input**: BlockHoldDuration 0.5s, SwipeMinDistance 200px, SwipeMaxDuration 0.3s
   - **Visual**: Punch red, Block blue, Dodge green
3. Drag GameConfig asset to MouseTouchInputProvider and TargetSpawner

## Step 5: Build Settings
1. File → Build Settings
2. Add scenes in order:
   - Boot (index 0)
   - MainMenu (index 1)
   - Game (index 2)
   - Results (index 3)
3. Ensure "Boot" is at index 0

## Step 6: Play
1. Open Boot scene
2. Press Play
3. Game should:
   - Boot → Load MainMenu with level selection
   - Select level → Load Game with appropriate targets
   - Click to Punch (red), Hold to Block (blue), Swipe to Dodge (green)
   - Timer counts down with accuracy display
   - When time up → Load Results with reaction time
   - Can Restart or return to Main Menu

## Input Actions Reference

| Action | Input | Visual |
|--------|-------|--------|
| Punch | Quick click/release | Red cube (rotated 45°) |
| Block | Hold >0.5s without moving | Blue flat cube |
| Dodge | Fast swipe >200px in <0.3s | Green stretched cube |

## Debug Features
- Press **D** to toggle debug overlay (FPS, state, targets)
- Accuracy shown in real-time during gameplay
- Reaction time tracked per hit

## Troubleshooting

### Scripts not compiling
- Ensure all scripts are in `Assets/Scripts/` folder
- Check Unity Console for compilation errors
- Verify no duplicate class names

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

### Debug overlay not showing
- Press D key during gameplay
- Ensure DebugUI component is in scene
- Check DebugText reference is assigned

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
