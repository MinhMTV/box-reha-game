using System.Collections.Generic;
using UnityEngine;

/// <summary>Authored target feedback, without changing hit rules or allocating materials.</summary>
public sealed class DigitalDojoTargetVisual : MonoBehaviour
{
    Renderer[] accents;
    Transform[] fragments;
    Vector3[] fragmentRest;
    Quaternion[] fragmentRotations;
    float breakAt = -1;
    Vector3 initialScale;
    Renderer[] segments;
    MaterialPropertyBlock block;
    float born, pulse;
    Color color;
    TargetObject target;
    public int DamageStage { get; private set; }
    void Awake()
    {
        initialScale = transform.localScale;
        var pieces = new List<Transform>();
        var lights = new List<Renderer>();
        var damage = new List<Renderer>();
        foreach (Renderer renderer in GetComponentsInChildren<Renderer>())
        {
            if (renderer.name.StartsWith("FracturePiece_")) pieces.Add(renderer.transform);
            if (renderer.name.StartsWith("DamageSegment_")) damage.Add(renderer);
            if (renderer.sharedMaterial != null && renderer.sharedMaterial.name.Contains("Emissive")) lights.Add(renderer);
        }
        fragments = pieces.ToArray(); fragmentRest = new Vector3[fragments.Length]; fragmentRotations=new Quaternion[fragments.Length];
        for(int i=0;i<fragments.Length;i++) { fragmentRest[i]=fragments[i].localPosition; fragmentRotations[i]=fragments[i].localRotation; }
        accents = lights.ToArray(); segments = damage.ToArray(); block = new MaterialPropertyBlock();
        born = Time.time;
        color = name.Contains("Kick") ? GameVisualPalette.KickColor : GameVisualPalette.PunchColor;
    }
    void Update()
    {
        if(target==null)target=GetComponentInParent<TargetObject>();
        pulse = Mathf.MoveTowards(pulse, 0, Time.deltaTime * 5);
        float appearance = SettingsManager.ReducedMotion ? 1 : Mathf.Lerp(0.94f, 1, Mathf.Clamp01((Time.time - born) / 0.18f));
        transform.localScale = initialScale * appearance;
        if(breakAt >= 0 && !SettingsManager.ReducedMotion)
        {
            float t = Mathf.Clamp01((Time.unscaledTime-breakAt)/.24f);
            for(int i=0;i<fragments.Length;i++)
            {
                // Authored pieces use deterministic motion, never runtime rigidbodies or colliders.
                float angle=i*2.399963f;
                Vector3 direction=new Vector3(Mathf.Cos(angle),Mathf.Sin(angle),-.45f);
                fragments[i].localPosition=fragmentRest[i]+direction*t*.45f;
                fragments[i].localRotation=fragmentRotations[i]*Quaternion.Euler(25*t,35*t,(i%2==0?1:-1)*40*t);
            }
        }
        foreach (var renderer in accents)
        {
            if (renderer.name.StartsWith("DamageSegment_")) continue;
            renderer.GetPropertyBlock(block);
            float anticipation=target!=null && target.IsDeploying ? .25f : 0;
            block.SetColor("_EmissionColor", color * (0.4f + pulse + anticipation));
            renderer.SetPropertyBlock(block);
        }
    }
    public void BeginBreak()
    {
        if(breakAt >= 0) return;
        breakAt=Time.unscaledTime;
        if(target==null)target=GetComponentInParent<TargetObject>();
        DojoDebrisPool.Emit(fragments,target!=null&&target.IsTough);
        if(!SettingsManager.ReducedMotion)
            foreach(var fragment in fragments) { var renderer=fragment.GetComponent<Renderer>();if(renderer!=null)renderer.enabled=false; }
        Hit();
    }
    public void Hit(float progress = -1)
    {
        pulse = SettingsManager.ReducedMotion ? 0.3f : 1.2f;
        // A follow-up flash must preserve segments consumed by TakeHit.
        if (progress < 0) return;
        float remaining=1-Mathf.Clamp01(progress);
        DamageStage=remaining<=0?3:remaining<=.4f?2:remaining<=.7f?1:0;
        if(!SettingsManager.ReducedMotion && DamageStage<3)
            for(int i=0;i<fragments.Length;i++)
            {
                float angle=i*2.399963f;
                fragments[i].localPosition=fragmentRest[i]+new Vector3(Mathf.Cos(angle),Mathf.Sin(angle),0)*(.007f*DamageStage);
            }
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
