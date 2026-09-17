using UnityEngine;
using System.Collections;

/// <summary>
/// v3: Simple 3D health bar displayed above tough targets.
/// Uses 3 cubes: background, fill, border.
/// Updates fill scale based on remaining hits ratio.
/// </summary>
public class ToughTargetHealthBar : MonoBehaviour
{
    static Material sharedMaterial;
    static int owners;
    void Awake(){block=new MaterialPropertyBlock();owners++;if(sharedMaterial==null)sharedMaterial=new Material(Shader.Find("Unlit/Color"));}
    void OnDestroy(){if(--owners==0&&sharedMaterial!=null){Destroy(sharedMaterial);sharedMaterial=null;}}
    private Transform targetTransform;
    private Transform cameraTransform;
    private MaterialPropertyBlock block;
    private GameObject backgroundObj;
    private GameObject fillObj;
    private GameObject borderObj;

    private Color fullColor = new Color(1f, 0.2f, 0.2f); // Red
    private Color lowColor = new Color(1f, 0.8f, 0f);    // Yellow when almost broken

    private Vector3 offset = new Vector3(0f, 1.8f, 0f);
    private bool fadingOut = false;

    /// <summary>
    /// Create a health bar attached to the given target transform.
    /// </summary>
    public static ToughTargetHealthBar Create(Transform target)
    {
        GameObject barObj = new GameObject("ToughTargetHealthBar");
        ToughTargetHealthBar bar = barObj.AddComponent<ToughTargetHealthBar>();
        bar.targetTransform = target;
        bool kick=target.GetComponent<TargetObject>()?.IsKick == true;
        bar.offset=new Vector3(0,kick?1f:1.95f,0);
        if(kick)bar.fullColor=GameVisualPalette.KickColor;
        barObj.transform.SetParent(target, true);
        bar.Initialize();
        return bar;
    }

    private void Initialize()
    {
        cameraTransform=Camera.main!=null?Camera.main.transform:null;
        float barWidth = 1.2f;
        float barHeight = 0.12f;
        float barDepth = 0.05f;

        // Background (dark gray)
        backgroundObj = VisualPrimitive.Create(PrimitiveType.Cube);
        backgroundObj.transform.SetParent(transform);
        backgroundObj.transform.localPosition = Vector3.zero;
        backgroundObj.transform.localScale = new Vector3(barWidth + 0.05f, barHeight + 0.05f, barDepth);
        SetColor(backgroundObj, new Color(0.15f, 0.15f, 0.15f, 1f));
        Destroy(backgroundObj.GetComponent<Collider>());

        // Fill (colored bar)
        fillObj = VisualPrimitive.Create(PrimitiveType.Cube);
        fillObj.transform.SetParent(transform);
        fillObj.transform.localPosition = Vector3.zero;
        fillObj.transform.localScale = new Vector3(barWidth, barHeight, barDepth + 0.01f);
        SetColor(fillObj, fullColor);
        Destroy(fillObj.GetComponent<Collider>());

        // Border (white outline effect via slightly larger cube behind background)
        borderObj = VisualPrimitive.Create(PrimitiveType.Cube);
        borderObj.transform.SetParent(transform);
        borderObj.transform.localPosition = Vector3.zero;
        borderObj.transform.localScale = new Vector3(barWidth + 0.1f, barHeight + 0.1f, barDepth - 0.01f);
        SetColor(borderObj, new Color(0.4f, 0.4f, 0.4f, 1f));
        Destroy(borderObj.GetComponent<Collider>());

        // Re-order children so border is behind, then background, then fill on top
        borderObj.transform.localPosition = new Vector3(0f, 0f, -0.001f);
        backgroundObj.transform.localPosition = new Vector3(0f, 0f, 0f);
        fillObj.transform.localPosition = new Vector3(0f, 0f, 0.001f);
    }

    void LateUpdate()
    {
        if (fadingOut) return;

        if (targetTransform == null)
        {
            Destroy(gameObject);
            return;
        }

        // Position above target
        transform.position = targetTransform.position + offset;

        // Face camera
        if (cameraTransform != null)
        {
            transform.rotation = Quaternion.LookRotation(transform.position - cameraTransform.position);
        }
    }

    /// <summary>
    /// Update the fill bar based on remaining hit ratio (0 to 1).
    /// </summary>
    public void UpdateFill(float ratio)
    {
        if (fillObj == null) return;

        ratio = Mathf.Clamp01(ratio);

        // Scale the fill bar based on ratio (shrink from right side)
        Vector3 baseScale = new Vector3(1.2f, 0.12f, 0.06f);
        fillObj.transform.localScale = new Vector3(baseScale.x * ratio, baseScale.y, baseScale.z);

        // Shift fill left as it shrinks so it depletes from right
        float maxOffset = baseScale.x * 0.5f;
        float fillOffset = maxOffset * (1f - ratio);
        fillObj.transform.localPosition = new Vector3(-fillOffset, 0f, 0.001f);

        // Lerp color from full (red) to low (yellow)
        Color currentColor = Color.Lerp(fullColor, lowColor, 1f - ratio);
        SetColor(fillObj, currentColor);
    }

    /// <summary>
    /// Fade out and destroy the health bar.
    /// </summary>
    public void FadeOut()
    {
        fadingOut = true;
        StartCoroutine(FadeOutRoutine());
    }

    private IEnumerator FadeOutRoutine()
    {
        float duration = 0.20f;
        float elapsed = 0f;

        // Store original scales
        Vector3 bgScale = backgroundObj != null ? backgroundObj.transform.localScale : Vector3.one;
        Vector3 fillScale = fillObj != null ? fillObj.transform.localScale : Vector3.one;
        Vector3 borderScale = borderObj != null ? borderObj.transform.localScale : Vector3.one;

        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = elapsed / duration;

            // Shrink and fade
            if (backgroundObj != null)
            {
                backgroundObj.transform.localScale = Vector3.Lerp(bgScale, Vector3.zero, t);
            }
            if (fillObj != null)
            {
                fillObj.transform.localScale = Vector3.Lerp(fillScale, Vector3.zero, t);
            }
            if (borderObj != null)
            {
                borderObj.transform.localScale = Vector3.Lerp(borderScale, Vector3.zero, t);
            }

            yield return null;
        }

        Destroy(gameObject);
    }

    private void SetColor(GameObject obj, Color color)
    {
        Renderer rend = obj.GetComponent<Renderer>();
        if (rend != null)
        {
            rend.sharedMaterial=sharedMaterial;
            rend.GetPropertyBlock(block);block.SetColor("_Color",color);rend.SetPropertyBlock(block);
        }
    }
}
