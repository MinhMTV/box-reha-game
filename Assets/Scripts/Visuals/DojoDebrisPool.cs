using UnityEngine;

/// <summary>Bounded scene-owned mesh pool. Analytic floor-only bounce, no PhysX and no runtime fracture.</summary>
public sealed class DojoDebrisPool : MonoBehaviour
{
    public const int Capacity=48;
    public const float Lifetime=1.15f;
    static DojoDebrisPool instance;
    readonly Transform[] pieces=new Transform[Capacity];
    readonly MeshFilter[] meshes=new MeshFilter[Capacity];
    readonly MeshRenderer[] renderers=new MeshRenderer[Capacity];
    readonly Vector3[] velocity=new Vector3[Capacity];
    readonly Vector3[] scale=new Vector3[Capacity];
    readonly float[] age=new float[Capacity];
    int cursor;
    public int ActiveCount { get {int n=0;foreach(var t in pieces)if(t!=null&&t.gameObject.activeSelf)n++;return n;} }
    public static void Emit(Transform[] templates,bool heavy)
    {
        if(SettingsManager.ReducedMotion)return;
        if(instance==null)instance=new GameObject("DojoDebrisPool").AddComponent<DojoDebrisPool>();
        int count=Mathf.Min(templates.Length,heavy?10:6);
        for(int i=0;i<count;i++) instance.Launch(templates[i],i,heavy);
    }
    void Launch(Transform source,int index,bool heavy)
    {
        var sourceMesh=source.GetComponent<MeshFilter>();var sourceRenderer=source.GetComponent<Renderer>();
        if(sourceMesh==null||sourceRenderer==null)return;
        int slot=cursor++%Capacity;
        if(pieces[slot]==null)
        {
            var go=new GameObject("PooledFracture");go.transform.SetParent(transform,false);
            pieces[slot]=go.transform;meshes[slot]=go.AddComponent<MeshFilter>();renderers[slot]=go.AddComponent<MeshRenderer>();
            renderers[slot].shadowCastingMode=UnityEngine.Rendering.ShadowCastingMode.Off;
        }
        meshes[slot].sharedMesh=sourceMesh.sharedMesh;renderers[slot].sharedMaterials=sourceRenderer.sharedMaterials;
        pieces[slot].SetPositionAndRotation(source.position,source.rotation);scale[slot]=source.lossyScale;
        pieces[slot].localScale=scale[slot];pieces[slot].gameObject.SetActive(true);age[slot]=0;
        float a=index*2.399963f;
        velocity[slot]=new Vector3(Mathf.Cos(a)*1.2f,1+Mathf.Abs(Mathf.Sin(a))*1.2f,-.8f)*(heavy?1.2f:1);
    }
    void Update()
    { Advance(Time.deltaTime); }
    void Advance(float delta)
    {
        for(int i=0;i<Capacity;i++)
        {
            var t=pieces[i];if(t==null||!t.gameObject.activeSelf)continue;
            age[i]+=delta;
            if(age[i]>=Lifetime||SettingsManager.ReducedMotion){t.gameObject.SetActive(false);continue;}
            velocity[i]+=Vector3.down*(7*delta);var p=t.position+velocity[i]*delta;
            if(p.y<-.5f){p.y=-.5f;velocity[i]=new Vector3(velocity[i].x*.6f,Mathf.Abs(velocity[i].y)*.2f,velocity[i].z*.6f);}
            t.position=p;t.Rotate(new Vector3(27,41,i%2==0?85:-85)*delta,Space.Self);
            t.localScale=scale[i]*Mathf.Clamp01((Lifetime-age[i])/.25f);
        }
    }
    void OnDestroy(){if(instance==this)instance=null;}
}
