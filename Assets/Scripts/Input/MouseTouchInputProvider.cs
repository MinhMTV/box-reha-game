using UnityEngine;

/// <summary>Mouse/touch gestures and four keyboard actions share the abstract input pipeline.</summary>
public class MouseTouchInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event System.Action<PlayerActionEvent> OnActionDetected;
    public bool IsEnabled
    {
        get => isEnabled;
        set { if (isEnabled != value) isPointerDown = false; isEnabled = value; }
    }
    public InputSourceType SourceType => InputSourceType.Mouse;
    public bool IsReady => true;
    public string Status => IsEnabled ? "Arrows: punch | A/D: kick | mouse/touch active" : "Keyboard / mouse / touch standby";
    [SerializeField] private GameConfig gameConfig;
    private bool isEnabled;
    private int lastInputFrame = -1;
    private Vector2 downPosition;
    private float downTime;
    private bool isPointerDown;

    void Update() { UpdateInput(); }
    public void UpdateInput()
    {
        if (!isEnabled || lastInputFrame == Time.frameCount) return;
        lastInputFrame = Time.frameCount;
        EmitKeyboard(KeyCode.LeftArrow, ActionType.Punch, BodySide.Left);
        EmitKeyboard(KeyCode.RightArrow, ActionType.Punch, BodySide.Right);
        EmitKeyboard(KeyCode.A, ActionType.Kick, BodySide.Left);
        EmitKeyboard(KeyCode.D, ActionType.Kick, BodySide.Right);
        // Unity can synthesize mouse events from touch. Only process one pointer channel.
        if (Input.touchCount > 0) ProcessTouch();
        else ProcessMouse();
    }
    private void EmitKeyboard(KeyCode key, ActionType action, BodySide side)
    {
        if (Input.GetKeyDown(key)) OnActionDetected?.Invoke(KeyboardActionFactory.Create(action, side));
    }
    private void ProcessMouse()
    {
        if (Input.GetMouseButtonDown(0) && !OverInterface()) Begin(Input.mousePosition);
        if (Input.GetMouseButtonUp(0) && isPointerDown) End(Input.mousePosition, InputSourceType.Mouse);
    }
    private void ProcessTouch()
    {
        Touch touch = Input.GetTouch(0);
        if (touch.phase == TouchPhase.Began && !OverInterface(touch.fingerId)) Begin(touch.position);
        else if (touch.phase == TouchPhase.Ended && isPointerDown) End(touch.position, InputSourceType.Touch);
        else if (touch.phase == TouchPhase.Canceled) isPointerDown = false;
    }
    private static bool OverInterface(int pointerId = -1)
    {
        UnityEngine.EventSystems.EventSystem events = UnityEngine.EventSystems.EventSystem.current;
        return events != null && events.IsPointerOverGameObject(pointerId);
    }
    private void Begin(Vector2 position)
    {
        downPosition = position;
        downTime = Time.unscaledTime;
        isPointerDown = true;
    }
    private void End(Vector2 position, InputSourceType source)
    {
        isPointerDown = false;
        float duration = Time.unscaledTime - downTime;
        float distance = Vector2.Distance(downPosition, position);
        ActionType action = InputInterpreter.ClassifyAction();
        VerticalPosition vertical = InputInterpreter.GetVerticalPositionFromScreenY(position.y);
        if (vertical == VerticalPosition.Low && action == ActionType.Punch) action = ActionType.Kick;
        BodySide side = position.x < Screen.width * 0.5f ? BodySide.Left : BodySide.Right;
        LaneType lane = side == BodySide.Left ? LaneType.Left : LaneType.Right;
        OnActionDetected?.Invoke(PlayerActionEvent.Create(action, lane, 1f, downPosition, position,
            duration, source, vertical, 0f, SensorDeviceType.Unknown, side));
    }
}
