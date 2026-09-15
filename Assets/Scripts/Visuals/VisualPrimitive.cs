using UnityEngine;
using System.Collections.Generic;

/// <summary>Visual geometry only. Never invokes CreatePrimitive's implicit physics components.</summary>
public static class VisualPrimitive
{
    private static readonly Dictionary<PrimitiveType, Mesh> meshes = new Dictionary<PrimitiveType, Mesh>();
    public static GameObject Create(PrimitiveType type)
    {
        if (!meshes.TryGetValue(type, out Mesh mesh) || mesh == null) meshes[type] = mesh = Build(type);
        var go = new GameObject(type.ToString(), typeof(MeshFilter), typeof(MeshRenderer));
        go.GetComponent<MeshFilter>().sharedMesh = mesh;
        return go;
    }
    private static Mesh Build(PrimitiveType type)
    {
        var vertices = new List<Vector3>(); var triangles = new List<int>();
        if(type == PrimitiveType.Cube)
        {
            Vector3[] corners = {new Vector3(-.5f,-.5f,-.5f),new Vector3(.5f,-.5f,-.5f),new Vector3(.5f,.5f,-.5f),new Vector3(-.5f,.5f,-.5f),new Vector3(-.5f,-.5f,.5f),new Vector3(.5f,-.5f,.5f),new Vector3(.5f,.5f,.5f),new Vector3(-.5f,.5f,.5f)};
            int[] faces = {0,3,2,1, 5,6,7,4, 4,7,3,0, 1,2,6,5, 3,7,6,2, 4,0,1,5};
            for(int f=0;f<6;f++){int k=vertices.Count; for(int n=0;n<4;n++)vertices.Add(corners[faces[f*4+n]]); triangles.AddRange(new[]{k,k+1,k+2,k,k+2,k+3});}
        }
        else
        {
            bool sphere = type == PrimitiveType.Sphere;
            int rings = sphere ? 12 : 1, segments = 24;
            for(int r=0;r<=rings;r++)
            {
                float angle = Mathf.PI*r/rings;
                float y = sphere ? .5f*Mathf.Cos(angle) : 1f-2f*r;
                float radius = sphere ? .5f*Mathf.Sin(angle) : .5f;
                for(int n=0;n<=segments;n++){float a=2*Mathf.PI*n/segments;vertices.Add(new Vector3(radius*Mathf.Cos(a),y,radius*Mathf.Sin(a)));}
            }
            for(int r=0;r<rings;r++)for(int n=0;n<segments;n++){int k=r*(segments+1)+n,j=k+segments+1;triangles.AddRange(new[]{k,k+1,j,k+1,j+1,j});}
            if(!sphere)for(int cap=0;cap<2;cap++){int center=vertices.Count;vertices.Add(new Vector3(0,cap==0?1:-1,0));for(int n=0;n<segments;n++){int k=cap*(segments+1)+n;triangles.AddRange(cap==0?new[]{center,k+1,k}:new[]{center,k,k+1});}}
        }
        Mesh mesh=new Mesh {name="Dojo visual " + type};mesh.SetVertices(vertices);mesh.SetTriangles(triangles,0);mesh.RecalculateNormals();mesh.RecalculateBounds();return mesh;
    }
}
