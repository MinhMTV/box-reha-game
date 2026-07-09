using UnityEngine;

public class ArenaPulseAnimator : MonoBehaviour
{
    [SerializeField] private Color pulseColor = Color.cyan;
    [SerializeField] private float baseEmission = 0.7f;
    [SerializeField] private float pulseEmission = 1.6f;
    [SerializeField] private float pulseSpeed = 2.4f;

    private Renderer[] renderers;
    private Material[] runtimeMaterials;

    void Awake()
    {
        renderers = GetComponentsInChildren<Renderer>(true);
        runtimeMaterials = new Material[renderers.Length];

        for (int i = 0; i < renderers.Length; i++)
        {
            Renderer current = renderers[i];
            if (current == null || current.sharedMaterial == null)
            {
                continue;
            }

            runtimeMaterials[i] = new Material(current.sharedMaterial);
            current.sharedMaterial = runtimeMaterials[i];
            runtimeMaterials[i].EnableKeyword("_EMISSION");
        }
    }

    void Update()
    {
        if (runtimeMaterials == null)
        {
            return;
        }

        float pulse = 0.5f + 0.5f * Mathf.Sin(Time.time * pulseSpeed);
        Color emission = pulseColor * Mathf.Lerp(baseEmission, pulseEmission, pulse);

        for (int i = 0; i < runtimeMaterials.Length; i++)
        {
            Material material = runtimeMaterials[i];
            if (material != null)
            {
                material.SetColor("_EmissionColor", emission);
            }
        }
    }

    public void Configure(Color color, float baseStrength, float pulseStrength, float speed)
    {
        pulseColor = color;
        baseEmission = baseStrength;
        pulseEmission = pulseStrength;
        pulseSpeed = speed;
    }
}
