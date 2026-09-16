using UnityEngine;

/// <summary>Read-only view of the evaluator. No hit decisions, timers or scoring live here.</summary>
[RequireComponent(typeof(HitZoneEvaluator))]
public sealed class HitZoneVisualizer : MonoBehaviour
{
    public float PlaneZ => evaluator.HitZoneZ;
    public string PunchState { get; private set; } = "READY";
    public string KickState { get; private set; } = "READY";
    public float PunchHeight { get; private set; } = 2.1f;
    public float KickHeight { get; private set; } = .45f;
    HitZoneEvaluator evaluator;
    Transform root;
    readonly Renderer[][] bars = new Renderer[2][];
    readonly TextMesh[] labels = new TextMesh[2];
    readonly float[] flashUntil = new float[2];
    readonly string[] feedback = new string[2];
    readonly float[] intensity = { .15f, .15f };
    MaterialPropertyBlock block;
    Material material;
    void Awake()
    {
        block = new MaterialPropertyBlock();
        evaluator = GetComponent<HitZoneEvaluator>();
        var spawner = FindFirstObjectByType<TargetSpawner>();
        if (spawner != null && spawner.Configuration != null)
        {
            PunchHeight = spawner.Configuration.GetVerticalOffset(VerticalPosition.High);
            KickHeight = spawner.Configuration.GetVerticalOffset(VerticalPosition.Low);
        }
        root = new GameObject("HitGate").transform;
        root.SetParent(transform, false);
        material = new Material(Shader.Find("Unlit/Color"));
        for (int row = 0; row < 2; row++)
        {
            var group = new GameObject(row == 0 ? "PunchGate" : "KickGate").transform;
            group.SetParent(root, false);
            group.localPosition = new Vector3(0, row == 0 ? PunchHeight : KickHeight, 0);
            bars[row] = new Renderer[10];
            bars[row][0] = Bar(group, new Vector3(0,-.33f,0), new Vector3(6.4f,.022f,.018f));
            int index = 1;
            foreach (float x in new[] {-2.4f,0f,2.4f})
            {
                bars[row][index++] = Bar(group, new Vector3(x-.48f,0,0), new Vector3(.025f,.22f,.018f));
                bars[row][index++] = Bar(group, new Vector3(x+.48f,0,0), new Vector3(.025f,.22f,.018f));
                bars[row][index++] = Bar(group, new Vector3(x,-.29f,0), new Vector3(.12f,.075f,.018f));
            }
            var label = new GameObject("TimingState").AddComponent<TextMesh>();
            label.transform.SetParent(group,false); label.transform.localPosition = new Vector3(0,-.47f,-.02f);
            label.anchor = TextAnchor.MiddleCenter; label.alignment = TextAlignment.Center;
            label.fontSize = 48; label.characterSize = .035f;
            labels[row] = label;
        }
    }
    Renderer Bar(Transform parent, Vector3 p, Vector3 size)
    {
        var go = VisualPrimitive.Create(PrimitiveType.Cube); go.name = "GateMarker";
        go.transform.SetParent(parent,false); go.transform.localPosition=p; go.transform.localScale=size;
        var r = go.GetComponent<Renderer>(); r.sharedMaterial=material;
        r.shadowCastingMode=UnityEngine.Rendering.ShadowCastingMode.Off; r.receiveShadows=false; return r;
    }
    void OnEnable() { HitZoneEvaluator.OnTargetFeedback += Feedback; }
    void OnDisable() { HitZoneEvaluator.OnTargetFeedback -= Feedback; }
    void OnDestroy() { if (material != null) Destroy(material); if(root != null) Destroy(root.gameObject); }
    void Feedback(TargetObject target, HitQuality quality, bool weak)
    {
        int row=target.IsKick?1:0; flashUntil[row]=Time.time+.22f;
        feedback[row]=weak ? "TOO LIGHT — RETRY" : quality==HitQuality.Miss ? "MISS" : quality.ToString().ToUpperInvariant();
    }
    void LateUpdate()
    {
        // World coordinates follow a moved/scaled evaluator or a separate hitZoneCenter exactly.
        root.SetPositionAndRotation(new Vector3(0,0,evaluator.HitZoneZ),Quaternion.identity);
        root.localScale = new Vector3(1/transform.lossyScale.x,1/transform.lossyScale.y,1/transform.lossyScale.z);
        RenderRow(0); RenderRow(1);
    }
    void RenderRow(int row)
    {
        TargetObject nearest=null; float distance=float.MaxValue;
        var targets=evaluator.ActiveTargets;
        for(int i=0;i<targets.Count;i++)
        {
            var t=targets[i]; if(t==null || t.IsResolved || t.IsDeploying || t.IsKick!=(row==1)) continue;
            float d=Mathf.Abs(evaluator.TimingOffset(t)); if(d<distance) { nearest=t; distance=d; }
        }
        string state="READY"; float brightness=.15f;
        if(nearest!=null)
        {
            var quality=evaluator.PreviewTiming(nearest);
            brightness=Mathf.Lerp(.15f,.5f,1-Mathf.Clamp01(distance/1.3f));
            if(quality!=HitQuality.Miss)
            {
                state=quality==HitQuality.Perfect ? "NOW • PERFECT" : quality==HitQuality.Good ? "HIT • GOOD" : quality==HitQuality.Early?"EARLY":"LATE";
                brightness=quality==HitQuality.Perfect ? 1 : .72f;
            }
            else state="APPROACH";
            if(nearest.IsLockedInHitZone) state="HIT AGAIN";
        }
        if(Time.time<flashUntil[row]) { state=feedback[row]; brightness=state=="MISS" ? .15f : 1; }
        intensity[row]=brightness>intensity[row]?brightness:Mathf.MoveTowards(intensity[row],brightness,Time.deltaTime*(SettingsManager.ReducedMotion?4:10));
        Color color=row==0?GameVisualPalette.PunchColor:GameVisualPalette.KickColor;
        block.SetColor("_Color",color*intensity[row]);
        foreach(var bar in bars[row]) bar.SetPropertyBlock(block);
        bars[row][0].transform.localScale=new Vector3(6.4f,nearest!=null&&nearest.IsTough?.04f:.022f,.018f);
        labels[row].color=Color.Lerp(color,Color.white,.35f)*Mathf.Max(.3f,intensity[row]);
        string previous=row==0?PunchState:KickState;
        if(previous!=state || labels[row].text.Length==0) labels[row].text=(row==0?"PUNCH  ":"KICK  ")+state;
        if(row==0) PunchState=state; else KickState=state;
    }
}
