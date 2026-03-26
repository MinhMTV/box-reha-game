using UnityEngine;

/// <summary>
/// Target behavior and properties. Phase 2: Enhanced visuals per type.
/// Phase 3: Supports VerticalPosition for Y offset.
/// </summary>
public class TargetObject : MonoBehaviour
{
    public LaneType Lane { get; set; }
    public TargetType Type { get; set; }
    public float MoveSpeed { get; set; }
    public float HitWindow { get; set; }
    public float MinPower { get; set; }
    public bool HasSpawnedInHitZone { get; set; }
    // Phase 3: Vertical position
    public VerticalPosition VertPosition { get; set; }

    private Renderer cachedRenderer;
    private Color originalColor;

    public float SpawnTime { get; private set; }

    void Start()
    {
        SpawnTime = Time.time;
        cachedRenderer = GetComponent<Renderer>();
        ApplyVisuals();
    }

    /// <summary>
    /// Apply distinct visuals per target type.
    /// Phase 4: Punch = red cube with rotation, Block = blue flat cube, Dodge = green stretched cube.
    /// </summary>
    private void ApplyVisuals()
    {
        if (cachedRenderer == null) cachedRenderer = GetComponent<Renderer>();
        if (cachedRenderer == null) return;

        switch (Type)
        {
            case TargetType.Punch:
                cachedRenderer.material.color = Color.red;
                // Slight rotation for punch targets
                transform.rotation = Quaternion.Euler(0f, 45f, 0f);
                break;
            case TargetType.Block:
                cachedRenderer.material.color = Color.blue;
                // Flat shield-like shape
                transform.localScale = new Vector3(1.8f, 1.8f, 0.3f);
                break;
            case TargetType.Dodge:
                cachedRenderer.material.color = Color.green;
                // Stretched sideways
                transform.localScale = new Vector3(2.5f, 0.8f, 0.8f);
                break;
        }

        originalColor = cachedRenderer.material.color;
    }

    /// <summary>
    /// Brief flash on hit or miss.
    /// </summary>
    public void Flash(Color flashColor, float duration = 0.15f)
    {
        if (cachedRenderer == null) return;
        cachedRenderer.material.color = flashColor;
        Invoke(nameof(RestoreColor), duration);
    }

    private void RestoreColor()
    {
        if (cachedRenderer != null)
            cachedRenderer.material.color = originalColor;
    }

    public float GetTimeInZone()
    {
        return Time.time - SpawnTime;
    }
}
