using UnityEngine;

public enum ActionType { None, Punch, Kick, Block, Dodge }
public enum LaneType { Left, Center, Right }
public enum InputSourceType { Mouse, Touch, Keyboard, Sensor }
public enum TargetType { Punch, Kick, Block, Dodge, ToughPunch }
public enum HitQuality { Perfect, Good, Early, Late, Miss }
public enum GameState { Menu, Playing, Paused, Results }
public enum SexCategory { Unspecified, Female, Male, NonBinary }
public enum SensorDeviceType { Unknown, Alpha, Delta }
public enum BodySide { Unknown, Left, Right }

// Phase 3: Vertical position for targets (High punch, Mid, Low)
public enum VerticalPosition { Low, Mid, High }
