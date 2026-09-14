using System.Collections.Generic;
using UnityEngine;

/// <summary>Authored target feedback, without changing hit rules or allocating materials.</summary>
public sealed class DigitalDojoTargetVisual : MonoBehaviour
{
    Renderer[] accents;
    Renderer[] segments;
    MaterialPropertyBlock block;
    float born, pulse;
    Color color;
    void Awake()
    {
        var lights = new List<Renderer>();
        var damage = new List<Renderer>();
        foreach (Renderer renderer in GetComponentsInChildren<Renderer>())
        {
            if (renderer.name.StartsWith("DamageSegment_")) damage.Add(renderer);
            if (renderer.sharedMaterial != null && renderer.sharedMaterial.name.Contains("Emissive")) lights.Add(renderer);
        }
        accents = lights.ToArray(); segments = damage.ToArray(); block = new MaterialPropertyBlock();
        born = Time.time;
        color = name.Contains("Kick") ? GameVisualPalette.KickColor : GameVisualPalette.PunchColor;
    }
    void Update()
    {
        pulse = Mathf.MoveTowards(pulse, 0, Time.deltaTime * 5);
        float appearance = SettingsManager.ReducedMotion ? 1 : Mathf.Lerp(0.94f, 1, Mathf.Clamp01((Time.time - born) / 0.18f));
        transform.localScale = Vector3.one * appearance;
        foreach (var renderer in accents)
        {
            if (renderer.name.StartsWith("DamageSegment_")) continue;
            renderer.GetPropertyBlock(block);
            block.SetColor("_EmissionColor", color * (0.4f + pulse));
            renderer.SetPropertyBlock(block);
        }
    }
    public void Hit(float progress = -1)
    {
        pulse = SettingsManager.ReducedMotion ? 0.3f : 1.2f;
        // A follow-up flash must preserve segments consumed by TakeHit.
        if (progress < 0) return;
        for (int i=0; i<segments.Length; i++)
        {
            bool spent = (i + 1f) / segments.Length <= progress;
            segments[i].GetPropertyBlock(block);
            block.SetColor("_Color", spent ? new Color(0.12f,0.08f,0.07f) : color);
            block.SetColor("_EmissionColor", spent ? Color.black : color * 0.6f);
            segments[i].SetPropertyBlock(block);
        }
    }
}
