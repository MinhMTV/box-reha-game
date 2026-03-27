using UnityEngine;
using System.Collections;

/// <summary>
/// Target behavior and properties. Phase 2: Enhanced visuals per type.
/// Phase 3: Supports VerticalPosition for Y offset.
/// v3: ToughTarget support - multi-hit targets.
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

    // v3: Tough target multi-hit support
    public int MaxHits { get; set; } = 1;
    public int CurrentHits { get; set; } = 0;
    public bool IsTough => MaxHits > 1;

    private Renderer cachedRenderer;
    private Color originalColor;
    private MaterialPropertyBlock propBlock;
    private bool glowEnabled;
    private TextMesh labelMesh;

    // v3: Health bar reference
    private ToughTargetHealthBar healthBar;

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
    /// </summary>
    private void UpdateGlowEffect()
    {
        if (cachedRenderer == null) return;

        float distanceToHitZone = transform.position.z - HitZoneZ;

        if (distanceToHitZone < GlowActivateDistance && distanceToHitZone > 0f)
        {
            glowEnabled = true;

            float proximity = 1f - (distanceToHitZone / GlowActivateDistance);
            float pulse = 0.3f + 0.7f * Mathf.Abs(Mathf.Sin(Time.time * GlowSpeed));
            float intensity = pulse * (0.3f + proximity * 0.7f);

            Color emissionColor = originalColor * intensity;

            cachedRenderer.GetPropertyBlock(propBlock);
            propBlock.SetColor("_EmissionColor", emissionColor);
            cachedRenderer.SetPropertyBlock(propBlock);
        }
        else if (glowEnabled)
        {
            glowEnabled = false;
            cachedRenderer.GetPropertyBlock(propBlock);
            propBlock.SetColor("_EmissionColor", Color.black);
            cachedRenderer.SetPropertyBlock(propBlock);
        }
    }

    /// <summary>
    /// Apply distinct visuals per target type.
    /// v3: ToughPunch = dark red, 1.2x scale, health bar.
    /// </summary>
    private void ApplyVisuals()
    {
        if (cachedRenderer == null) cachedRenderer = GetComponent<Renderer>();
        if (cachedRenderer == null) return;

        string labelText = "PUNCH";
        Color accentColor = Color.red;

        switch (Type)
        {
            case TargetType.Punch:
                accentColor = new Color(1f, 0.22f, 0.22f, 1f);
                labelText = "PUNCH";
                ApplyTargetMaterial(accentColor, 1.9f);
                transform.rotation = Quaternion.Euler(0f, 45f, 0f);
                break;
            case TargetType.Block:
                accentColor = new Color(0.2f, 0.75f, 1f, 1f);
                labelText = "BLOCK";
                ApplyTargetMaterial(accentColor, 1.7f);
                transform.localScale = new Vector3(1.8f, 1.8f, 0.3f);
                break;
            case TargetType.Dodge:
                accentColor = new Color(0.35f, 1f, 0.55f, 1f);
                labelText = "DODGE";
                ApplyTargetMaterial(accentColor, 1.6f);
                transform.localScale = new Vector3(2.5f, 0.8f, 0.8f);
                break;
            case TargetType.ToughPunch:
                // Dark red, slightly larger
                accentColor = new Color(1f, 0.55f, 0.1f, 1f);
                labelText = "POWER";
                ApplyTargetMaterial(new Color(0.75f, 0.08f, 0.08f, 1f), 2.2f);
                transform.localScale = new Vector3(1.8f, 1.8f, 1.8f);
                transform.rotation = Quaternion.Euler(0f, 45f, 0f);
                // Create health bar
                CreateHealthBar();
                break;
        }

        originalColor = cachedRenderer.material.color;
        EnsureLabel(labelText, accentColor);
    }

    /// <summary>
    /// v3: Create 3D health bar above tough target.
    /// </summary>
    private void CreateHealthBar()
    {
        healthBar = ToughTargetHealthBar.Create(transform, MaxHits);
    }

    /// <summary>
    /// v3: Called when a tough target is hit. Returns true if destroyed.
    /// </summary>
    public bool TakeHit()
    {
        CurrentHits++;
        int hitsLeft = MaxHits - CurrentHits;

        // Update health bar
        if (healthBar != null)
        {
            healthBar.UpdateFill((float)hitsLeft / MaxHits);
        }

        // Visual crack effect: change color progressively
        // Dark red -> orange -> yellow as it weakens
        float t = (float)CurrentHits / MaxHits;
        Color damageColor = Color.Lerp(new Color(0.6f, 0.05f, 0.05f), new Color(1f, 0.8f, 0f), t);
        if (cachedRenderer != null)
        {
            cachedRenderer.material.color = damageColor;
            originalColor = damageColor;
        }

        // Scale wiggle on each hit
        StartCoroutine(WiggleOnHit());

        if (hitsLeft <= 0)
        {
            // Destroyed
            if (healthBar != null)
            {
                healthBar.FadeOut();
            }
            return true;
        }

        return false;
    }

    /// <brief>
    /// Brief scale wiggle/shake when hit.
    /// </brief>
    private IEnumerator WiggleOnHit()
    {
        Vector3 originalScale = transform.localScale;
        float duration = 0.15f;
        float elapsed = 0f;
        float wiggleAmount = 0.15f;

        while (elapsed < duration)
        {
            elapsed += Time.deltaTime;
            float factor = 1f + Mathf.Sin(elapsed * 40f) * wiggleAmount * (1f - elapsed / duration);
            transform.localScale = originalScale * factor;
            yield return null;
        }

        transform.localScale = originalScale;
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

    private void ApplyTargetMaterial(Color baseColor, float emissionIntensity)
    {
        Material material = cachedRenderer.material;
        material.color = baseColor;
        material.SetFloat("_Metallic", 0.15f);
        material.SetFloat("_Glossiness", 0.72f);
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", baseColor * emissionIntensity);
    }

    private void EnsureLabel(string actionLabel, Color accentColor)
    {
        if (labelMesh == null)
        {
            Transform existing = transform.Find("TargetLabel");
            if (existing != null)
            {
                labelMesh = existing.GetComponent<TextMesh>();
            }
        }

        if (labelMesh == null)
        {
            GameObject labelObject = new GameObject("TargetLabel");
            labelObject.transform.SetParent(transform, false);
            labelMesh = labelObject.AddComponent<TextMesh>();
            labelMesh.alignment = TextAlignment.Center;
            labelMesh.anchor = TextAnchor.MiddleCenter;
            labelMesh.characterSize = 0.11f;
            labelMesh.fontSize = 56;
        }

        string verticalLabel = VertPosition.ToString().ToUpperInvariant();
        labelMesh.text = actionLabel + "\n" + verticalLabel;
        labelMesh.color = Color.Lerp(Color.white, accentColor, 0.2f);
        labelMesh.transform.localPosition = new Vector3(0f, 0f, -0.42f);
        labelMesh.transform.localRotation = Quaternion.identity;
        labelMesh.transform.localScale = Vector3.one;
    }

    public float GetTimeInZone()
    {
        return Time.time - SpawnTime;
    }
}
