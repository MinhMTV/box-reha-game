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
        switch (type)
        {
            case TargetType.Punch: return Color.red;
            case TargetType.Block: return Color.blue;
            case TargetType.Dodge: return Color.green;
            case TargetType.ToughPunch: return new Color(0.8f, 0.1f, 0.1f); // Dark red
            default: return Color.white;
        }
    }

    private void Initialize(ParticleSystem ps, Color color, int particleCount)
    {
        var main = ps.main;
        main.startLifetime = 0.5f;
        main.startSpeed = 3f;
        main.startSize = 0.15f;
        main.startColor = color;
        main.maxParticles = particleCount;
        main.simulationSpace = ParticleSystemSimulationSpace.World;
        main.loop = false;
        main.playOnAwake = false;
        main.gravityModifier = 1f;

        var emission = ps.emission;
        emission.enabled = true;
        emission.rateOverTime = 0f;
        emission.SetBursts(new ParticleSystem.Burst[] {
            new ParticleSystem.Burst(0f, (short)particleCount)
        });

        var shape = ps.shape;
        shape.shapeType = ParticleSystemShapeType.Sphere;
        shape.radius = 0.2f;

        var renderer = ps.GetComponent<ParticleSystemRenderer>();
        renderer.material = new Material(Shader.Find("Particles/Standard Unlit"));
        renderer.material.color = color;

        ps.Play();
        Destroy(gameObject, 1f);
    }
}
