using UnityEngine;
using System.Collections;
using System;

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
    public string TargetId { get; private set; } = Guid.NewGuid().ToString("N");
    public string ChainId { get; set; }
    public int SequenceIndex { get; set; }
    public int SequenceLength { get; set; } = 1;
    public bool IsResolved { get; private set; }
    public float LockedTime { get; private set; }
    public float HeavyTimeoutSeconds { get; set; } = 12f;
    // Phase 3: Vertical position
    public VerticalPosition VertPosition { get; set; }

    // v3: Tough target multi-hit support
    public int MaxHits { get; set; } = 1;
    public int CurrentHits { get; set; } = 0;
    public bool IsTough => MaxHits > 1;
    public bool IsKick => Type == TargetType.Kick || Type == TargetType.ToughKick;
    public bool IsDeploying => mount != null && mount.enabled && !mount.Ready;
    private TargetMountMotion mount;
    public bool IsBreaking { get; private set; }
    public bool IsLockedInHitZone { get; private set; }

    private Renderer cachedRenderer;
    private Renderer[] cachedRenderers;
    private Color originalColor;
    private MaterialPropertyBlock propBlock;
    private bool glowEnabled;
    private Coroutine wiggle;
    private Vector3 restingScale;
    private DigitalDojoTargetVisual authoredVisual;

    // v3: Health bar reference
    private ToughTargetHealthBar healthBar;

    public float SpawnTime { get; private set; }
    public float ExpectedHitTime { get; private set; }
    private bool trackedSpawn;

    // HitZone Z position for glow calculation
    private const float HitZoneZ = HitZoneEvaluator.PlayerHitPlaneZ;
    private const float GlowActivateDistance = 10f;
    private const float GlowSpeed = 4f;

    void Awake()
    {
        authoredVisual = GetComponentInChildren<DigitalDojoTargetVisual>();
        EnsureVisualReferences();
    }

    void Start()
    {
        EnsureTrackedSpawn();
        EnsureVisualReferences();
        ApplyVisuals();
        restingScale = transform.localScale;
    }

    public HitZoneEvaluator Evaluator { get; private set; }
    public void BindEvaluator(HitZoneEvaluator evaluator) { Evaluator=evaluator; }

    public void EnsureTrackedSpawn()
    {
        if (trackedSpawn) return;
        trackedSpawn = true;
        mount = GetComponent<TargetMountMotion>();
        SpawnTime = Time.time;
        var evaluator = Evaluator;
        float zoneZ = evaluator != null ? evaluator.HitZoneZ : HitZoneZ;
        if(mount!=null && IsTough && mount.Duration<.5f) mount.Duration=.65f;
        ExpectedHitTime = SpawnTime + (mount != null && mount.enabled ? mount.Duration : 0f) + Mathf.Max(0f, transform.position.z - zoneZ) / Mathf.Max(0.01f, MoveSpeed);
        if (evaluator != null) evaluator.RegisterTarget(this);
        if (GameManager.Instance?.SessionStats != null) GameManager.Instance.SessionStats.SpawnedTargets++;
        ResearchSessionLog.TargetSpawn(this);
    }

    private void EnsureVisualReferences()
    {
        cachedRenderer = GetComponentInChildren<Renderer>();
        cachedRenderers = GetComponentsInChildren<Renderer>(true);

        if (propBlock == null)
        {
            propBlock = new MaterialPropertyBlock();
        }
    }

    private float destroyAt;
    void Update()
    {
        if(IsResolved && Time.unscaledTime >= destroyAt) { Destroy(gameObject); return; }
        UpdateGlowEffect();
    }

    /// <summary>
    /// Pulsing glow effect as target approaches hit zone.
    /// </summary>
    private void UpdateGlowEffect()
    {
        if (authoredVisual != null) return;
        if (SettingsManager.ReducedMotion) return;
        if (propBlock == null || cachedRenderer == null)
        {
            EnsureVisualReferences();
        }

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
        if (cachedRenderer == null) cachedRenderer = GetComponentInChildren<Renderer>();
        if (cachedRenderer == null) return;

        if (authoredVisual != null)
        {
            originalColor = GameVisualPalette.GetTargetColor(Type);
            transform.rotation = Quaternion.identity;
            if (IsTough) { transform.localScale = Vector3.one * (IsKick ? 1.15f : 1.8f); CreateHealthBar(); }
            return;
        }

        Color accentColor = Color.red;

        switch (Type)
        {
            case TargetType.Punch:
                accentColor = new Color(1f, 0.22f, 0.22f, 1f);
                ApplyTargetMaterial(accentColor, 1.9f);
                transform.rotation = Quaternion.identity;
                break;
            case TargetType.Kick:
                accentColor = GameVisualPalette.KickColor;
                ApplyTargetMaterial(accentColor, 1.9f);
                transform.rotation = Quaternion.identity;
                break;
            case TargetType.ToughKick:
                accentColor = GameVisualPalette.KickColor;
                ApplyTargetMaterial(accentColor, 2.2f);
                transform.localScale = Vector3.one * 1.15f;
                transform.rotation = Quaternion.identity;
                CreateHealthBar();
                break;
            case TargetType.ToughPunch:
                // Dark red, slightly larger
                accentColor = new Color(1f, 0.55f, 0.1f, 1f);
                ApplyTargetMaterial(new Color(0.75f, 0.08f, 0.08f, 1f), 2.2f);
                transform.localScale = new Vector3(1.8f, 1.8f, 1.8f);
                transform.rotation = Quaternion.identity;
                // Create health bar
                CreateHealthBar();
                break;
        }

        originalColor = accentColor;
    }

    /// <summary>
    /// v3: Create 3D health bar above tough target.
    /// </summary>
    private void CreateHealthBar()
    {
        healthBar = ToughTargetHealthBar.Create(transform);
    }

    /// <summary>
    /// v3: Called when a tough target is hit. Returns true if destroyed.
    /// </summary>

    public void LockInHitZone(float hitZoneZ)
    {
        if (!IsTough || IsBreaking)
        {
            return;
        }

        if (!IsLockedInHitZone) LockedTime = Time.time;
        IsLockedInHitZone = true;
        Vector3 position = transform.position;
        position.z = hitZoneZ;
        transform.position = position;
    }


    public bool TakeHit(float normalizedPower)
    {
        if (IsBreaking || IsResolved)
        {
            return false;
        }

        if (float.IsNaN(normalizedPower) || float.IsInfinity(normalizedPower) || normalizedPower < 0f) return false;
        int damage = GameplayRules.HeavyDamage(normalizedPower);
        CurrentHits = Mathf.Min(MaxHits, CurrentHits + damage);
        int hitsLeft = MaxHits - CurrentHits;

        try
        {
        // Update health bar
        if (healthBar != null)
        {
            healthBar.UpdateFill((float)hitsLeft / MaxHits);
        }

        // Visual crack effect: change color progressively
        // Dark red -> orange -> yellow as it weakens
        float t = (float)CurrentHits / MaxHits;
        if (authoredVisual != null) authoredVisual.Hit(t);
        Color damageColor = Color.Lerp(new Color(0.6f, 0.05f, 0.05f), new Color(1f, 0.8f, 0f), t);
        if (cachedRenderer != null && authoredVisual == null)
        {
            SetSurfaceColor(cachedRenderer,damageColor);
            originalColor = damageColor;
        }

        // Scale wiggle on each hit
        if (!SettingsManager.ReducedMotion && authoredVisual == null)
        {
            if (wiggle != null) StopCoroutine(wiggle);
            transform.localScale = restingScale;
            wiggle = StartCoroutine(WiggleOnHit());
        }

        if (hitsLeft <= 0)
        {
            // Destroyed
            if (healthBar != null)
            {
                healthBar.FadeOut();
            }

        }
        }
        catch(Exception error) { Debug.LogException(error); }
        // Presentation errors do not change the already accepted damage or terminal result.
        return hitsLeft <= 0;
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
        if (authoredVisual != null) { authoredVisual.Hit(); return; }
        if (cachedRenderer == null || IsBreaking) return;
        SetSurfaceColor(cachedRenderer,flashColor);
        Invoke(nameof(RestoreColor), duration);
    }

    private void RestoreColor()
    {
        if (cachedRenderer != null)
            SetSurfaceColor(cachedRenderer,originalColor);
    }

    private void ApplyTargetMaterial(Color baseColor, float emissionIntensity)
    {
        if (cachedRenderer == null)
        {
            cachedRenderer = GetComponentInChildren<Renderer>();
        }

        if (cachedRenderer == null)
        {
            return;
        }

        cachedRenderer.GetPropertyBlock(propBlock);
        propBlock.SetColor("_Color",baseColor);
        propBlock.SetFloat("_Metallic",.15f);
        propBlock.SetFloat("_Glossiness",.72f);
        propBlock.SetColor("_EmissionColor",baseColor*emissionIntensity);
        cachedRenderer.SetPropertyBlock(propBlock);
    }


    private void SetSurfaceColor(Renderer renderer,Color color)
    {
        renderer.GetPropertyBlock(propBlock);propBlock.SetColor("_Color",color);renderer.SetPropertyBlock(propBlock);
    }

    public bool Resolve()
    {
        if (IsResolved) return false;
        IsResolved = true;
        destroyAt = Time.unscaledTime + .35f;
        return true;
    }

    public void PlayDestroyAnimation(Action onComplete = null, bool breakApart = true)
    {
        if (IsBreaking)
        {
            return;
        }

        IsBreaking = true;
        if (wiggle != null) StopCoroutine(wiggle);
        TargetMover mover = GetComponent<TargetMover>();
        if (mover != null)
        {
            mover.enabled = false;
        }

        Collider[] colliders = GetComponentsInChildren<Collider>();
        for (int i = 0; i < colliders.Length; i++)
        {
            colliders[i].enabled = false;
        }

        if (SettingsManager.ReducedMotion)
        {
            Destroy(gameObject);
            onComplete?.Invoke();
            return;
        }

        // Optional fracture presentation cannot prevent the scheduled target cleanup.
        try { if (authoredVisual != null && breakApart) authoredVisual.BeginBreak(); }
        catch(Exception error) { Debug.LogException(error); }
        StartCoroutine(DestroyAnimationCoroutine(onComplete,breakApart));
    }

    private IEnumerator DestroyAnimationCoroutine(Action onComplete,bool breakApart)
    {
        Vector3 startScale = transform.localScale;
        float duration = 0.24f;
        float elapsed = 0f;

        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Mathf.Clamp01(elapsed / duration);
            float scale = Mathf.Lerp(1f, breakApart ? 0.88f : .96f, t);
            transform.localScale = startScale * scale;
            if(breakApart) transform.Rotate(Vector3.forward, 18f * Time.deltaTime, Space.Self);
            else if(mount!=null) mount.RetractProgress=t;

            if (cachedRenderers != null && authoredVisual == null)
            {
                for (int i = 0; i < cachedRenderers.Length; i++)
                {
                    Renderer renderer = cachedRenderers[i];
                    if (renderer == null) continue;
                    SetSurfaceColor(renderer,new Color(originalColor.r,originalColor.g,originalColor.b,1f-t));
                }
            }

            yield return null;
        }

        Destroy(gameObject);
        onComplete?.Invoke();
    }
}
