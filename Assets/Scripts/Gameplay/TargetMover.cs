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
        if (targetObject != null && (targetObject.IsResolved || targetObject.IsLockedInHitZone))
        {
            return;
        }

        transform.Translate(Vector3.back * Speed * Time.deltaTime, Space.World);
        if (transform.position.z < missZoneZ)
        {
            HitZoneEvaluator evaluator = FindObjectOfType<HitZoneEvaluator>();
            if (targetObject != null && !targetObject.IsResolved && evaluator != null)
                evaluator.Miss(targetObject, "miss");
            else Destroy(gameObject);
        }
    }
}
