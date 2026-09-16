using UnityEngine;

/// <summary>
/// Particle hit effect that spawns on target hit.
/// Color matches target type. Self-destructs after 1 second.
/// </summary>
public class HitParticleEffect : MonoBehaviour
{
    static Material sharedParticleMaterial;
    static readonly System.Collections.Generic.List<HitParticleEffect> active=new System.Collections.Generic.List<HitParticleEffect>();
    void OnDestroy()
    {
        active.Remove(this);
        if(active.Count==0&&sharedParticleMaterial!=null){Destroy(sharedParticleMaterial);sharedParticleMaterial=null;}
    }
    public static void Spawn(Vector3 position, Color color, int particleCount = 15)
    {
        while(active.Count>=4){var old=active[0];active.RemoveAt(0);if(old!=null){old.gameObject.SetActive(false);Destroy(old.gameObject);}}
        GameObject obj = new GameObject("HitParticleEffect");
        obj.transform.position = position;

        ParticleSystem ps = obj.AddComponent<ParticleSystem>();
        HitParticleEffect effect = obj.AddComponent<HitParticleEffect>();
        active.Add(effect);
        effect.Initialize(ps, color, particleCount);
    }

    public static Color GetColorForTargetType(TargetType type)
    {
        return GameVisualPalette.GetTargetColor(type);
    }

    public static int GetParticleCountForTargetType(TargetType type)
    {
        return GameVisualPalette.GetParticleCount(type);
    }

    private void Initialize(ParticleSystem ps, Color color, int particleCount)
    {
        var main = ps.main;
        bool intenseBurst = particleCount >= 28;
        particleCount=SettingsManager.ReducedMotion?3:Mathf.Clamp(particleCount,4,24);
        main.startLifetime = SettingsManager.ReducedMotion?.2f:intenseBurst ? .5f : .35f;
        main.startSpeed = SettingsManager.ReducedMotion?.25f:intenseBurst ? 2.5f : 1.8f;
        main.startSize = intenseBurst ? 0.06f : 0.04f;
        main.startColor = color;
        main.maxParticles = particleCount;
        main.simulationSpace = ParticleSystemSimulationSpace.World;
        main.loop = false;
        main.playOnAwake = false;
        main.gravityModifier = 0.35f;

        var emission = ps.emission;
        emission.enabled = true;
        emission.rateOverTime = 0f;
        emission.SetBursts(new ParticleSystem.Burst[] {
            new ParticleSystem.Burst(0f, (short)particleCount)
        });

        var shape = ps.shape;
        shape.shapeType = intenseBurst ? ParticleSystemShapeType.Hemisphere : ParticleSystemShapeType.Sphere;
        shape.radius = intenseBurst ? 0.34f : 0.26f;

        var velocityOverLifetime = ps.velocityOverLifetime;
        velocityOverLifetime.enabled = true;
        velocityOverLifetime.orbitalY = intenseBurst ? 1.2f : 0.7f;

        var colorOverLifetime = ps.colorOverLifetime;
        colorOverLifetime.enabled = true;
        Gradient gradient = new Gradient();
        Color highlight = Color.Lerp(color, Color.white, 0.45f);
        gradient.SetKeys(
            new[] {
                new GradientColorKey(color, 0f),
                new GradientColorKey(highlight, 0.35f),
                new GradientColorKey(Color.Lerp(color, Color.black, 0.15f), 1f)
            },
            new[] {
                new GradientAlphaKey(1f, 0f),
                new GradientAlphaKey(0.85f, 0.4f),
                new GradientAlphaKey(0f, 1f)
            });
        colorOverLifetime.color = gradient;

        var sizeOverLifetime = ps.sizeOverLifetime;
        sizeOverLifetime.enabled = true;
        AnimationCurve curve = new AnimationCurve();
        curve.AddKey(0f, intenseBurst ? 0.55f : 0.4f);
        curve.AddKey(0.25f, intenseBurst ? 1.2f : 1f);
        curve.AddKey(1f, 0.1f);
        sizeOverLifetime.size = new ParticleSystem.MinMaxCurve(1f, curve);

        var renderer = ps.GetComponent<ParticleSystemRenderer>();
        if(sharedParticleMaterial==null)sharedParticleMaterial=new Material(Shader.Find("Particles/Standard Unlit"));
        renderer.sharedMaterial=sharedParticleMaterial;
        renderer.renderMode = ParticleSystemRenderMode.Billboard;

        ps.Play();
        Destroy(gameObject, .8f);
    }
}
