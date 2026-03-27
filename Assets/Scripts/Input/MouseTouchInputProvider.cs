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
    public string Status => IsEnabled ? "Mouse/Touch active" : "Mouse/Touch standby";

    [SerializeField] private GameConfig gameConfig;

    private Vector2 mouseDownPosition;
    private float mouseDownTime;
    private bool isMouseDown;

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
        ProcessMouseInput();
        ProcessTouchInput();
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

        PlayerActionEvent actionEvent = PlayerActionEvent.Create(
            actionType, lane, power, startPos, endPos, holdDuration, source, vertPos
        );
        OnActionDetected?.Invoke(actionEvent);
    }
}
