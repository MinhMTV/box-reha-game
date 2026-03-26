using UnityEngine;

public class TargetObject : MonoBehaviour
{
    public LaneType Lane { get; set; }
    public TargetType Type { get; set; }
    public float MoveSpeed { get; set; }
    public float HitWindow { get; set; }
    public float MinPower { get; set; }
    public bool HasSpawnedInHitZone { get; set; }

    private Renderer cachedRenderer;

    public float SpawnTime { get; private set; }

    void Start()
    {
        SpawnTime = Time.time;
        cachedRenderer = GetComponent<Renderer>();
        ApplyColor();
    }

    private void ApplyColor()
    {
        if (cachedRenderer == null) cachedRenderer = GetComponent<Renderer>();
        if (cachedRenderer == null) return;
        switch (Type)
        {
            case TargetType.Punch:
                cachedRenderer.material.color = Color.red;
                break;
            case TargetType.Block:
                cachedRenderer.material.color = Color.blue;
                break;
            case TargetType.Dodge:
                cachedRenderer.material.color = Color.green;
                break;
        }
    }

    public float GetTimeInZone()
    {
        return Time.time - SpawnTime;
    }
}
