using System;

public interface IPlayerActionInputProvider
{
    event Action<PlayerActionEvent> OnActionDetected;
    void UpdateInput();
    bool IsEnabled { get; set; }
    InputSourceType SourceType { get; }
    bool IsReady { get; }
    string Status { get; }
}
