using UnityEngine;

public class MouseTouchInputProvider : MonoBehaviour, IPlayerActionInputProvider
{
    public event System.Action<PlayerActionEvent> OnActionDetected;
    public bool IsEnabled { get; set; }

    private Vector2 mouseDownPosition;
    private float mouseDownTime;
    private bool isMouseDown;

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
            float power = Mathf.Clamp01(holdDuration / 0.3f);

            LaneType lane = GetLaneFromScreenX(mouseUpPosition.x);
            PlayerActionEvent actionEvent = PlayerActionEvent.Create(
                ActionType.Punch, lane, power, mouseDownPosition, mouseUpPosition, holdDuration, InputSourceType.Mouse
            );
            OnActionDetected?.Invoke(actionEvent);
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
                float power = Mathf.Clamp01(holdDuration / 0.3f);
                LaneType lane = GetLaneFromScreenX(touch.position.x);
                PlayerActionEvent actionEvent = PlayerActionEvent.Create(
                    ActionType.Punch, lane, power, mouseDownPosition, touch.position, holdDuration, InputSourceType.Touch
                );
                OnActionDetected?.Invoke(actionEvent);
                break;
        }
    }

    private LaneType GetLaneFromScreenX(float screenX)
    {
        float screenWidth = Screen.width;
        float third = screenWidth / 3f;
        if (screenX < third) return LaneType.Left;
        if (screenX < third * 2) return LaneType.Center;
        return LaneType.Right;
    }
}
