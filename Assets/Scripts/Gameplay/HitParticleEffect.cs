using UnityEngine;

/// <summary>
/// Particle hit effect that spawns on target hit.
/// Color matches target type. Self-destructs after 1 second.
/// </summary>
public class HitParticleEffect : MonoBehaviour
{
    public static void Spawn(Vector3 position, Color color, int particleCount = 15)
    {
        GameObject obj = new GameObject("HitParticleEffect");
        obj.transform.position = position;

        ParticleSystem ps = obj.AddComponent<ParticleSystem>();
        HitParticleEffect effect = obj.AddComponent<HitParticleEffect>();
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
        main.startLifetime = intenseBurst ? 0.9f : 0.65f;
        main.startSpeed = intenseBurst ? 5.8f : 4.5f;
        main.startSize = intenseBurst ? 0.22f : 0.18f;
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
        renderer.material = new Material(Shader.Find("Particles/Standard Unlit"));
        renderer.material.color = color;
        renderer.renderMode = ParticleSystemRenderMode.Billboard;

        ps.Play();
        Destroy(gameObject, 1.2f);
    }
}
