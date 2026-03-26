using UnityEngine;
using System;

public class SessionTimer : MonoBehaviour
{
    public static event Action<float> OnTimeChanged;
    public static event Action OnTimeUp;
    public static event Action<int> OnTimeWarning;

    private float timeRemaining;
    private bool isRunning;
    private bool warned30;
    private bool warned10;

    public float TimeRemaining => timeRemaining;
    public bool IsRunning => isRunning;

    public void StartTimer(float duration)
    {
        timeRemaining = duration;
        isRunning = true;
        warned30 = false;
        warned10 = false;
        OnTimeChanged?.Invoke(timeRemaining);
    }

    public void StopTimer()
    {
        isRunning = false;
    }

    void Update()
    {
        if (!isRunning) return;

        timeRemaining -= Time.deltaTime;
        OnTimeChanged?.Invoke(timeRemaining);

        if (!warned30 && timeRemaining <= 30f)
        {
            warned30 = true;
            OnTimeWarning?.Invoke(30);
        }

        if (!warned10 && timeRemaining <= 10f)
        {
            warned10 = true;
            OnTimeWarning?.Invoke(10);
        }

        if (timeRemaining <= 0f)
        {
            timeRemaining = 0f;
            isRunning = false;
            OnTimeUp?.Invoke();
        }
    }
}
