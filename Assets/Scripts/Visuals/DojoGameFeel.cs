using System;
using UnityEngine;

public enum DojoAudioCue { TargetDeploy, TargetTravel, PunchImpact, KickImpact, TooLight, Perfect, HeavyDamage, HeavyBreak, ComboTier, SessionStart, SessionEnd }

/// <summary>One scene-owned controller, six inexpensive trim meshes, no new realtime lights.</summary>
public sealed class DojoGameFeel : MonoBehaviour
{
    public static event Action<DojoAudioCue> OnAudioCue;
    public static void Cue(DojoAudioCue cue,bool kick=false) { OnAudioCue?.Invoke(cue); AudioManager.Instance?.PlayCue(cue,kick); }
    HitZoneEvaluator evaluator;
    Renderer[] trim=new Renderer[6];
    Material material;
    MaterialPropertyBlock block;
    Transform trimRoot, cameraTransform;
    Vector3 previousOffset;
    float pulse, impulse, tier, currentEnergy;
    int kickStreak;
    Color accent=GameVisualPalette.PunchColor;
    bool ended;
    public float Energy => currentEnergy;
    void Start()
    {
        block=new MaterialPropertyBlock();
        evaluator=GetComponent<HitZoneEvaluator>();
        cameraTransform=Camera.main!=null?Camera.main.transform:null;
        trimRoot=new GameObject("DojoReactiveTrim").transform;trimRoot.SetParent(transform,false);
        material=new Material(Shader.Find("Unlit/Color"));
        for(int i=0;i<trim.Length;i++)
        {
            var go=VisualPrimitive.Create(PrimitiveType.Cube);go.name="ReactiveWallInset";
            go.transform.SetParent(trimRoot,false);
            go.transform.position=new Vector3(i%2==0?-6.65f:6.65f,1.3f,8+(i/2)*8);
            go.transform.localScale=new Vector3(.018f,1.1f,.04f);
            trim[i]=go.GetComponent<Renderer>();trim[i].sharedMaterial=material;
            trim[i].shadowCastingMode=UnityEngine.Rendering.ShadowCastingMode.Off;
        }
        Cue(DojoAudioCue.SessionStart);
    }
    void OnEnable()
    { HitZoneEvaluator.OnTargetFeedback+=Feedback;ComboSystem.OnComboChanged+=Combo;GameRoundController.OnRoundEnd+=End; }
    void OnDisable()
    {
        HitZoneEvaluator.OnTargetFeedback-=Feedback;ComboSystem.OnComboChanged-=Combo;GameRoundController.OnRoundEnd-=End;
        if(cameraTransform!=null)cameraTransform.localPosition-=previousOffset;previousOffset=Vector3.zero;
    }
    void OnDestroy() { if(material!=null)Destroy(material); if(trimRoot!=null)Destroy(trimRoot.gameObject); }
    void Combo(int count) { tier=count>=30?4:count>=20?3:count>=10?2:count>=5?1:0; }
    void End(GameSessionStats stats) { ended=true;tier=0;Cue(DojoAudioCue.SessionEnd); }
    void Feedback(TargetObject target,HitQuality quality,bool weak)
    {
        if(quality==HitQuality.Miss) { kickStreak=0;return; }
        accent=target.IsKick?GameVisualPalette.KickColor:GameVisualPalette.PunchColor;
        if(weak) { Cue(DojoAudioCue.TooLight);return; }
        if(target.IsResolved)kickStreak=target.IsKick?kickStreak+1:0;
        pulse=Mathf.Max(pulse,quality==HitQuality.Perfect?1:.4f);
        impulse=Mathf.Max(impulse,quality==HitQuality.Perfect?.012f:.006f);
        if(quality==HitQuality.Perfect)Cue(DojoAudioCue.Perfect);
    }
    void LateUpdate()
    {
        bool heavy=false;
        if(evaluator!=null)
        {
            var targets=evaluator.ActiveTargets;
            for(int i=0;i<targets.Count;i++)
            {
                var target=targets[i];
                if(target!=null&&!target.IsResolved&&target.IsTough){heavy=true;break;}
            }
        }
        float goal=ended?0:tier*.08f+(heavy?.16f:0)+Mathf.Min(3,kickStreak)*.025f;
        currentEnergy=Mathf.MoveTowards(currentEnergy,goal,Time.deltaTime*.3f);
        pulse=Mathf.MoveTowards(pulse,0,Time.deltaTime*3);impulse=Mathf.MoveTowards(impulse,0,Time.deltaTime*.1f);
        Color warm=new Color(1,.55f,.22f);
        block.SetColor("_Color",Color.Lerp(warm,accent,.15f+currentEnergy*.25f)*(.25f+currentEnergy+(SettingsManager.ReducedMotion?0:pulse*.08f)));
        foreach(var r in trim)if(r!=null)r.SetPropertyBlock(block);
        if(cameraTransform!=null)
        {
            cameraTransform.localPosition-=previousOffset;
            previousOffset=SettingsManager.ReducedMotion?Vector3.zero:Vector3.up*impulse;
            cameraTransform.localPosition+=previousOffset;
        }
    }
}
