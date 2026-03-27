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
    private MaterialPropertyBlock propBlock;
    private bool glowEnabled;

    public float SpawnTime { get; private set; }

    // HitZone Z position for glow calculation
    private const float HitZoneZ = 5f;
    private const float GlowActivateDistance = 10f;
    private const float GlowSpeed = 4f;

    void Start()
    {
        SpawnTime = Time.time;
        cachedRenderer = GetComponent<Renderer>();
        propBlock = new MaterialPropertyBlock();
        ApplyVisuals();
    }

    void Update()
    {
        UpdateGlowEffect();
    }

    /// <summary>
    /// Pulsing glow effect as target approaches hit zone.
    /// Uses emission color intensity that increases as Z position decreases toward HitZone.
    /// </summary>
    private void UpdateGlowEffect()
    {
        if (cachedRenderer == null) return;

        float distanceToHitZone = transform.position.z - HitZoneZ;

        if (distanceToHitZone < GlowActivateDistance && distanceToHitZone > 0f)
        {
            glowEnabled = true;

            // Proximity factor: 0 at 10 units, 1 at hit zone
            float proximity = 1f - (distanceToHitZone / GlowActivateDistance);

            // Sine wave pulse
            float pulse = 0.3f + 0.7f * Mathf.Abs(Mathf.Sin(Time.time * GlowSpeed));

            // Emission intensity increases with proximity
            float intensity = pulse * (0.3f + proximity * 0.7f);

            Color emissionColor = originalColor * intensity;

            cachedRenderer.GetPropertyBlock(propBlock);
            propBlock.SetColor("_EmissionColor", emissionColor);
            cachedRenderer.SetPropertyBlock(propBlock);
        }
        else if (glowEnabled)
        {
            // Disable glow
            glowEnabled = false;
            cachedRenderer.GetPropertyBlock(propBlock);
            propBlock.SetColor("_EmissionColor", Color.black);
            cachedRenderer.SetPropertyBlock(propBlock);
        }
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
