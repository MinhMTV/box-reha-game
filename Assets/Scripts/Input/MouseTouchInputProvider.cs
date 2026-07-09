using UnityEngine;

/// <summary>
/// Enhanced input provider with Punch, Block, and Dodge detection.
/// - Quick click/release = Punch
/// - Hold without movement (>0.5s) = Block
/// - Fast horizontal swipe (>200px in <0.3s) = Dodge
/// 
/// Phase 3: Maps vertical screen position to VerticalPosition.
/// </summary>
public class MouseTouchInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event System.Action<PlayerActionEvent> OnActionDetected;
    public bool IsEnabled { get; set; }
    public InputSourceType SourceType => InputSourceType.Mouse;
    public bool IsReady => true;
    public string Status => IsEnabled ? "Mouse/Touch active + keyboard hold sim (arrows punch, A/D kick)" : "Mouse/Touch standby";

    [SerializeField] private GameConfig gameConfig;

    private Vector2 mouseDownPosition;
    private float mouseDownTime;
    private bool isMouseDown;
    private float leftPunchDownTime = -1f;
    private float rightPunchDownTime = -1f;
    private float leftKickDownTime = -1f;
    private float rightKickDownTime = -1f;

    private const float KeyboardTapPower = 0.9f;
    private const float KeyboardMinPower = 0.75f;
    private const float KeyboardMaxPower = 1.65f;
    private const float KeyboardChargedReleaseThreshold = 0.18f;
    private const float KeyboardFullPowerHoldSeconds = 0.75f;

    // Fallback values if no GameConfig assigned
    private float BlockHoldDuration => gameConfig != null ? gameConfig.BlockHoldDuration : 0.5f;
    private float SwipeMinDistance => gameConfig != null ? gameConfig.SwipeMinDistance : 200f;
    private float SwipeMaxDuration => gameConfig != null ? gameConfig.SwipeMaxDuration : 0.3f;
    private float BlockMaxMovement => gameConfig != null ? gameConfig.BlockMaxMovement : 10f;

    void Update()
    {
        if (!IsEnabled) return;
        UpdateInput();
    }

    public void UpdateInput()
    {
        ProcessKeyboardInput();
        ProcessMouseInput();
        ProcessTouchInput();
    }

    private void ProcessKeyboardInput()
    {
        TrackKeyboardHold(KeyCode.LeftArrow, ActionType.Punch, BodySide.Left, LaneType.Left, VerticalPosition.High, ref leftPunchDownTime);
        TrackKeyboardHold(KeyCode.RightArrow, ActionType.Punch, BodySide.Right, LaneType.Right, VerticalPosition.High, ref rightPunchDownTime);
        TrackKeyboardHold(KeyCode.A, ActionType.Kick, BodySide.Left, LaneType.Left, VerticalPosition.Low, ref leftKickDownTime);
        TrackKeyboardHold(KeyCode.D, ActionType.Kick, BodySide.Right, LaneType.Right, VerticalPosition.Low, ref rightKickDownTime);
    }

    private void TrackKeyboardHold(KeyCode key, ActionType actionType, BodySide bodySide, LaneType lane, VerticalPosition verticalPosition, ref float downTime)
    {
        if (Input.GetKeyDown(key))
        {
            downTime = Time.time;
            EmitKeyboardAction(actionType, bodySide, lane, verticalPosition, KeyboardTapPower, 0f);
        }

        if (!Input.GetKeyUp(key))
        {
            return;
        }

        float holdDuration = downTime >= 0f ? Time.time - downTime : 0f;
        downTime = -1f;
        if (holdDuration < KeyboardChargedReleaseThreshold)
        {
            return;
        }

        EmitKeyboardAction(actionType, bodySide, lane, verticalPosition, GetKeyboardPower(holdDuration), holdDuration);
    }

    private float GetKeyboardPower(float holdDuration)
    {
        float t = Mathf.Clamp01(holdDuration / KeyboardFullPowerHoldSeconds);
        return Mathf.Lerp(KeyboardMinPower, KeyboardMaxPower, t);
    }

    private void EmitKeyboardAction(ActionType actionType, BodySide bodySide, LaneType lane, VerticalPosition verticalPosition, float power, float holdDuration)
    {
        PlayerActionEvent actionEvent = PlayerActionEvent.Create(
            actionType,
            lane,
            power,
            Vector2.zero,
            Vector2.zero,
            holdDuration,
            InputSourceType.Keyboard,
            verticalPosition,
            0f,
            actionType == ActionType.Kick ? SensorDeviceType.Delta : SensorDeviceType.Alpha,
            bodySide);
        OnActionDetected?.Invoke(actionEvent);
    }

    private void ProcessMouseInput()
    {
        if (Input.GetMouseButtonDown(0))
        {
            mouseDownPosition = Input.mousePosition;
            mouseDownTime = Time.time;
            isMouseDown = true;
        }

        if (Input.GetMouseButtonUp(0) && isMouseDown)
        {
            isMouseDown = false;
            Vector2 mouseUpPosition = Input.mousePosition;
            float holdDuration = Time.time - mouseDownTime;
            float swipeDistance = Vector2.Distance(mouseDownPosition, mouseUpPosition);

            EmitAction(mouseDownPosition, mouseUpPosition, holdDuration, swipeDistance, InputSourceType.Mouse);
        }
    }

    private void ProcessTouchInput()
    {
        if (Input.touchCount <= 0) return;
        Touch touch = Input.GetTouch(0);
        switch (touch.phase)
        {
            case TouchPhase.Began:
                mouseDownPosition = touch.position;
                mouseDownTime = Time.time;
                isMouseDown = true;
                break;
            case TouchPhase.Ended:
                if (!isMouseDown) break;
                isMouseDown = false;
                float holdDuration = Time.time - mouseDownTime;
                float swipeDistance = Vector2.Distance(mouseDownPosition, touch.position);
                EmitAction(mouseDownPosition, touch.position, holdDuration, swipeDistance, InputSourceType.Touch);
                break;
        }
    }

    private void EmitAction(Vector2 startPos, Vector2 endPos, float holdDuration, float swipeDistance, InputSourceType source)
    {
        float power = Mathf.Clamp01(holdDuration / 0.3f);
        LaneType lane = InputInterpreter.GetLaneFromScreenX(endPos.x);

        // Classify the action type
        ActionType actionType = InputInterpreter.ClassifyAction(
            holdDuration, swipeDistance, holdDuration,
            BlockHoldDuration, SwipeMinDistance, SwipeMaxDuration, BlockMaxMovement
        );

        // Phase 3: Vertical position from screen Y
        VerticalPosition vertPos = InputInterpreter.GetVerticalPositionFromScreenY(endPos.y);
        if (vertPos == VerticalPosition.Low && actionType == ActionType.Punch)
        {
            actionType = ActionType.Kick;
        }

        BodySide bodySide = endPos.x < Screen.width * 0.5f ? BodySide.Left : BodySide.Right;

        PlayerActionEvent actionEvent = PlayerActionEvent.Create(
            actionType, lane, power, startPos, endPos, holdDuration, source, vertPos, 0f,
            SensorDeviceType.Unknown, bodySide
        );
        OnActionDetected?.Invoke(actionEvent);
    }
}
