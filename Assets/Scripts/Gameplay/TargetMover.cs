using UnityEngine;

public class TargetMover : MonoBehaviour
{
    public float Speed { get; set; }
    private float missZoneZ;
    private TargetObject targetObject;

    public void Initialize(float speed, float missZonePosition)
    {
        Speed = speed;
        missZoneZ = missZonePosition;
        targetObject = GetComponent<TargetObject>();
    }

    void Update()
    {
        if (targetObject != null && targetObject.IsTough && targetObject.HasSpawnedInHitZone && !targetObject.IsBreaking)
        {
            return;
        }

        transform.Translate(Vector3.back * Speed * Time.deltaTime, Space.World);
        if (transform.position.z < missZoneZ)
        {
            Destroy(gameObject);
        }
    }
}
