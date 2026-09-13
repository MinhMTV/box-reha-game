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

    public InputSourceType SourceType => activeProvider != null ? activeProvider.SourceType : lastRequestedSource;
    public bool IsReady => activeProvider != null && activeProvider.IsReady;
    public string Status => activeProvider != null ? activeProvider.Status : "Selected " + lastRequestedSource + " input unavailable (missing provider)";

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
        ApplyProviderState();
    }

    public void UpdateInput()
    {
        if (AllowsInput()) activeProvider?.UpdateInput();
    }

    public string GetStatusLine()
    {
        string readiness = IsReady ? "ready" : "waiting";
        return $"{SourceType}: {readiness} | {Status}";
    }

    private void RefreshProvider(bool forceRebind)
    {
        InputSourceType requestedSource = SessionInputSelection.Override ?? (gameConfig != null ? gameConfig.ActiveInputSourceType : InputSourceType.Mouse);
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
        if (requestedSource == InputSourceType.Sensor)
        {
            return bleSensorInputProvider;
        }

        if (requestedSource == InputSourceType.Mouse || requestedSource == InputSourceType.Touch || requestedSource == InputSourceType.Keyboard)
        {
            return mouseTouchInputProvider;
        }

        return null;
    }

    private void ApplyProviderState()
    {
        bool mouseIsActive = ReferenceEquals(activeProvider, mouseTouchInputProvider as IPlayerActionInputProvider);
        bool sensorIsActive = ReferenceEquals(activeProvider, bleSensorInputProvider as IPlayerActionInputProvider);

        SetProviderEnabled(mouseTouchInputProvider, mouseIsActive && AllowsInput());
        SetProviderEnabled(bleSensorInputProvider, sensorIsActive && AllowsInput());
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
        if (AllowsInput() && actionEvent.IsValid) OnActionDetected?.Invoke(actionEvent);
    }

    private bool AllowsInput()
    {
        if (!isEnabled) return false;
        GameManager manager = GameManager.Instance;
        return manager == null || manager.CurrentState == GameState.Playing;
    }
}
