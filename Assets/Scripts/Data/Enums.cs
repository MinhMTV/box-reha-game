using UnityEngine;

public enum ActionType { None, Punch, Block, Dodge }
public enum LaneType { Left, Center, Right }
public enum InputSourceType { Mouse, Touch, Keyboard, Sensor }
public enum TargetType { Punch, Block, Dodge }
public enum HitQuality { Perfect, Good, Early, Late, Miss }
public enum GameState { Menu, Playing, Paused, Results }

// Phase 3: Vertical position for targets (High punch, Mid, Low)
public enum VerticalPosition { Low, Mid, High }
