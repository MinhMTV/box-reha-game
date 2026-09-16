using UnityEngine;

/// <summary>Owned mechanical carriage: preload, telescope deployment, travel and impact recoil.</summary>
public sealed class TargetMountMotion : MonoBehaviour
{
    public const float IdleSeconds = .08f;
    public float Duration { get; set; } = .30f;
    public float TelegraphSeconds { get; set; } = IdleSeconds;
    public float RetractProgress { get; set; }
    public bool Ready => started && Time.time - born >= Duration;
    public string Phase => target != null && target.IsResolved ? "Retract" :
        Time.time - impactAt < .22f ? "Impact" : Ready ? "Travel" :
        Time.time - born < TelegraphSeconds ? "Idle" : Time.time-born > Duration-.06f ? "Align" : "Deploy";
    bool started;
    TargetObject target;
    Transform visual, mount, plate;
    readonly Transform[] arms = new Transform[3];
    float born, impactAt = float.NegativeInfinity, impactStrength;
    Vector3 restPosition;
    Quaternion restRotation;
    Renderer indicator;
    MaterialPropertyBlock indicatorBlock;

    void Start()
    {
        if (started) return;
        started = true; born = Time.time;
        target = GetComponent<TargetObject>();
        if(target.IsTough && Duration < .5f) Duration=.65f;
        DojoGameFeel.Cue(DojoAudioCue.TargetDeploy);
        var authored = GetComponentInChildren<DigitalDojoTargetVisual>();
        if (authored != null)
        {
            visual = authored.transform; restPosition = visual.localPosition;
            restRotation = visual.localRotation;
        }
        mount = new GameObject("TargetOwnedMount").transform;
        mount.SetParent(transform, false);
        for (int i = 0; i < arms.Length; i++) arms[i] = CreatePart("MountArm");
        plate = CreatePart("MountPlate");
        if(plate!=null && authored!=null)
        {
            foreach(var renderer in authored.GetComponentsInChildren<Renderer>())
            {
                if(renderer.sharedMaterial==null || !renderer.sharedMaterial.name.Contains("Emissive"))continue;
                var led=VisualPrimitive.Create(PrimitiveType.Cube);led.name="MountStatusLight";led.transform.SetParent(plate,false);
                led.transform.localPosition=new Vector3(0,.28f,-.07f);led.transform.localScale=new Vector3(.34f,.035f,.018f);
                indicator=led.GetComponent<Renderer>();indicator.sharedMaterial=renderer.sharedMaterial;indicatorBlock=new MaterialPropertyBlock();break;
            }
        }
        PositionParts();
    }

    Transform CreatePart(string name)
    {
        var prefab = Resources.Load<GameObject>("DigitalDojo/" + name);
        if (prefab == null) { Debug.LogError("Missing authored mount prefab: " + name); return null; }
        var part = Instantiate(prefab, mount).transform; part.name = name; return part;
    }

    public void Impact(bool belowThreshold = false)
    {
        impactAt = Time.time;
        impactStrength = belowThreshold ? .015f : .05f;
    }

    void LateUpdate() { PositionParts(); }
    void PositionParts()
    {
        if (target == null || mount == null) return;
        float age = Time.time - born;
        float progress = Mathf.Clamp01((age - TelegraphSeconds) / Mathf.Max(.01f,Duration - TelegraphSeconds));
        float extension = progress * progress * (3f - 2f * progress);
        bool reduced = SettingsManager.ReducedMotion;
        if (reduced) extension = 1;
        else extension *= 1-Mathf.Clamp01(RetractProgress);
        if(indicator!=null)
        {
            Color color=target.IsKick?GameVisualPalette.KickColor:GameVisualPalette.PunchColor;
            float strength=target.IsResolved?.1f:Ready?.35f:Mathf.Lerp(.2f,1,progress);
            indicatorBlock.SetColor("_Color",color);indicatorBlock.SetColor("_EmissionColor",color*strength);
            indicator.SetPropertyBlock(indicatorBlock);
        }
        bool center = target.Lane == LaneType.Center;
        float side = target.Lane == LaneType.Left ? -1 : 1;
        Vector3 anchor = transform.position;
        if (center) anchor.y = -.54f; else anchor.x = side * 6.75f;
        float hitAge = Time.time - impactAt;
        float recoil = !reduced && hitAge >= 0 && hitAge < .22f
            ? Mathf.Sin(hitAge / .22f * Mathf.PI) * impactStrength : 0;
        if (visual != null)
        {
            Vector3 restWorld = transform.TransformPoint(restPosition);
            // The target starts at the support, rather than materialising halfway into the lane.
            Vector3 docked = center ? new Vector3(restWorld.x, anchor.y + .65f, restWorld.z)
                : new Vector3(anchor.x - side * .40f, restWorld.y, restWorld.z);
            visual.position = Vector3.Lerp(docked, restWorld, extension) + Vector3.forward * recoil;
            visual.localRotation = restRotation * Quaternion.Euler(recoil*30, center ? 0 : side * 72f * (1-extension), recoil*15);
            if (target.IsResolved && !reduced)
                visual.localPosition += Vector3.forward * .15f;
        }
        Vector3 endpoint = (visual != null ? visual.position : transform.position) + Vector3.forward * .35f;
        Vector3 scale = transform.lossyScale;
        mount.localScale = new Vector3(1/Mathf.Max(.01f,scale.x), 1/Mathf.Max(.01f,scale.y), 1/Mathf.Max(.01f,scale.z));
        mount.rotation = Quaternion.identity;
        if (plate != null)
        {
            plate.position = anchor;
            plate.rotation = center ? Quaternion.Euler(90,0,0) : Quaternion.Euler(0,90,0);
            plate.localScale = Vector3.one * .6f;
        }
        // Overlapping sleeves remain nested through the entire travel, with no implicit colliders.
        for (int i = 0; i < arms.Length; i++)
        {
            if (arms[i] == null) continue;
            Vector3 start = Vector3.Lerp(anchor,endpoint,i * .29f);
            Vector3 end = Vector3.Lerp(anchor,endpoint,Mathf.Min(1,(i+1)*.36f));
            arms[i].position = (start+end)*.5f;
            arms[i].rotation = Quaternion.FromToRotation(Vector3.up,endpoint-anchor);
            float width = .22f-i*.05f;
            arms[i].localScale = new Vector3(width, Mathf.Max(.03f,Vector3.Distance(start,end)), width);
        }
    }
}
