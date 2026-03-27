using UnityEngine;

/// <summary>
/// Routes gameplay input to the currently selected provider.
/// Useful for switching between test input and a sensor glove without changing gameplay code.
/// </summary>
public class InputProviderRouter : MonoBehaviour, IPlayerActionInputProvider
{
    public event System.Action<PlayerActionEvent> OnActionDetected;

    [SerializeField] private GameConfig gameConfig;
    [SerializeField] private MouseTouchInputProvider mouseTouchInputProvider;
    [SerializeField] private BleSensorInputProvider bleSensorInputProvider;

    private IPlayerActionInputProvider activeProvider;
    private InputSourceType lastRequestedSource;
    private bool isEnabled;

    public bool IsEnabled
    {
        get => isEnabled;
        set
        {
            isEnabled = value;
            ApplyProviderState();
        }
    }

    public InputSourceType SourceType => activeProvider != null ? activeProvider.SourceType : InputSourceType.Mouse;
    public bool IsReady => activeProvider != null && activeProvider.IsReady;
    public string Status => activeProvider != null ? activeProvider.Status : "No input provider";

    void Awake()
    {
        if (mouseTouchInputProvider == null)
        {
            mouseTouchInputProvider = GetComponent<MouseTouchInputProvider>();
        }

        if (bleSensorInputProvider == null)
        {
            bleSensorInputProvider = GetComponent<BleSensorInputProvider>();
        }
    }

    void OnEnable()
    {
        RefreshProvider(forceRebind: true);
    }

    void OnDisable()
    {
        Unsubscribe(activeProvider);
        SetProviderEnabled(mouseTouchInputProvider, false);
        SetProviderEnabled(bleSensorInputProvider, false);
    }

    void Update()
    {
        RefreshProvider(forceRebind: false);
    }

    public void UpdateInput()
    {
        activeProvider?.UpdateInput();
    }

    public string GetStatusLine()
    {
        string readiness = IsReady ? "ready" : "waiting";
        return $"{SourceType}: {readiness} | {Status}";
    }

    private void RefreshProvider(bool forceRebind)
    {
        InputSourceType requestedSource = gameConfig != null ? gameConfig.ActiveInputSourceType : InputSourceType.Mouse;
        if (!forceRebind && requestedSource == lastRequestedSource && activeProvider != null)
        {
            return;
        }

        lastRequestedSource = requestedSource;
        IPlayerActionInputProvider newProvider = SelectProvider(requestedSource);
        if (!forceRebind && ReferenceEquals(newProvider, activeProvider))
        {
            ApplyProviderState();
            return;
        }

        Unsubscribe(activeProvider);
        activeProvider = newProvider;
        Subscribe(activeProvider);
        ApplyProviderState();
    }

    private IPlayerActionInputProvider SelectProvider(InputSourceType requestedSource)
    {
        if (requestedSource == InputSourceType.Sensor && bleSensorInputProvider != null)
        {
            return bleSensorInputProvider;
        }

        if (mouseTouchInputProvider != null)
        {
            return mouseTouchInputProvider;
        }

        return bleSensorInputProvider;
    }

    private void ApplyProviderState()
    {
        bool mouseIsActive = ReferenceEquals(activeProvider, mouseTouchInputProvider as IPlayerActionInputProvider);
        bool sensorIsActive = ReferenceEquals(activeProvider, bleSensorInputProvider as IPlayerActionInputProvider);

        SetProviderEnabled(mouseTouchInputProvider, mouseIsActive && isEnabled);
        SetProviderEnabled(bleSensorInputProvider, sensorIsActive && isEnabled);
    }

    private void SetProviderEnabled(IPlayerActionInputProvider provider, bool enabled)
    {
        if (provider == null)
        {
            return;
        }

        provider.IsEnabled = enabled;
    }

    private void Subscribe(IPlayerActionInputProvider provider)
    {
        if (provider == null)
        {
            return;
        }

        provider.OnActionDetected += ForwardAction;
    }

    private void Unsubscribe(IPlayerActionInputProvider provider)
    {
        if (provider == null)
        {
            return;
        }

        provider.OnActionDetected -= ForwardAction;
    }

    private void ForwardAction(PlayerActionEvent actionEvent)
    {
        OnActionDetected?.Invoke(actionEvent);
    }
}
