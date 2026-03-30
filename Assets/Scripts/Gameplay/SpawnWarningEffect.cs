using UnityEngine;

public class SpawnWarningEffect : MonoBehaviour
{
    public static void Create(Vector3 position, Color color, float duration = 0.25f)
    {
        GameObject root = new GameObject("SpawnWarningEffect");
        root.transform.position = position;

        SpawnWarningEffect effect = root.AddComponent<SpawnWarningEffect>();
        effect.Initialize(color, duration);
    }

    private float duration;
    private float elapsed;
    private Renderer ringRenderer;
    private Renderer glowRenderer;
    private Material ringMaterial;
    private Material glowMaterial;

    private void Initialize(Color color, float effectDuration)
    {
        duration = Mathf.Max(0.05f, effectDuration);

        GameObject ring = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        ring.name = "Ring";
        ring.transform.SetParent(transform, false);
        ring.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        ring.transform.localScale = new Vector3(0.65f, 0.04f, 0.65f);
        ringRenderer = ring.GetComponent<Renderer>();
        ringMaterial = BuildMaterial(color, 2.4f);
        ringRenderer.sharedMaterial = ringMaterial;
        Destroy(ring.GetComponent<Collider>());

        GameObject glow = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        glow.name = "Glow";
        glow.transform.SetParent(transform, false);
        glow.transform.localScale = Vector3.one * 0.25f;
        glowRenderer = glow.GetComponent<Renderer>();
        glowMaterial = BuildMaterial(new Color(color.r, color.g, color.b, 0.7f), 1.8f);
        glowRenderer.sharedMaterial = glowMaterial;
        Destroy(glow.GetComponent<Collider>());
    }

    private void Update()
    {
        elapsed += Time.deltaTime;
        float t = Mathf.Clamp01(elapsed / duration);
        float pulse = 1f + t * 1.25f;

        if (ringRenderer != null)
        {
            ringRenderer.transform.localScale = new Vector3(0.65f * pulse, 0.04f, 0.65f * pulse);
        }

        if (glowRenderer != null)
        {
            glowRenderer.transform.localScale = Vector3.one * Mathf.Lerp(0.25f, 0.85f, t);
        }

        UpdateAlpha(ringMaterial, 1f - t);
        UpdateAlpha(glowMaterial, 0.55f * (1f - t));

        if (elapsed >= duration)
        {
            Destroy(gameObject);
        }
    }

    private static Material BuildMaterial(Color color, float emission)
    {
        Material material = new Material(Shader.Find("Standard"));
        material.color = color;
        material.SetFloat("_Mode", 3f);
        material.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        material.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        material.SetInt("_ZWrite", 0);
        material.DisableKeyword("_ALPHATEST_ON");
        material.EnableKeyword("_ALPHABLEND_ON");
        material.DisableKeyword("_ALPHAPREMULTIPLY_ON");
        material.renderQueue = 3000;
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", color * emission);
        return material;
    }

    private static void UpdateAlpha(Material material, float alpha)
    {
        if (material == null)
        {
            return;
        }

        Color color = material.color;
        color.a = alpha;
        material.color = color;
    }
}
