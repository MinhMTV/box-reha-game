using System;

public interface IPlayerActionInputProvider
{
    event Action<PlayerActionEvent> OnActionDetected;
    void UpdateInput();
    bool IsEnabled { get; set; }
}
