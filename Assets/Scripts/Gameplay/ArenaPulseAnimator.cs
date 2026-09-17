using UnityEngine;

/// <summary>Animates emission without cloning materials. Source materials must enable emission.</summary>
public class ArenaPulseAnimator : MonoBehaviour
{
    [SerializeField] private Color pulseColor = Color.cyan;
    [SerializeField] private float baseEmission = .7f;
    [SerializeField] private float pulseEmission = 1.6f;
    [SerializeField] private float pulseSpeed = 2.4f;
    Renderer[] renderers;
    MaterialPropertyBlock block;
    void Awake(){renderers=GetComponentsInChildren<Renderer>(true);block=new MaterialPropertyBlock();}
    void Update()
    {
        float pulse=SettingsManager.ReducedMotion?.5f:.5f+.5f*Mathf.Sin(Time.time*pulseSpeed);
        Color emission=pulseColor*Mathf.Lerp(baseEmission,pulseEmission,pulse);
        foreach(var renderer in renderers)
        {
            if(renderer==null)continue;
            renderer.GetPropertyBlock(block);block.SetColor("_EmissionColor",emission);renderer.SetPropertyBlock(block);
        }
    }
    public void Configure(Color color,float baseStrength,float pulseStrength,float speed)
    {pulseColor=color;baseEmission=baseStrength;pulseEmission=pulseStrength;pulseSpeed=speed;}
}
