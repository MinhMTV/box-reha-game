using UnityEngine;

public class TargetMover : MonoBehaviour
{
    public float Speed { get; set; }
    private float missZoneZ;
    private TargetObject targetObject;
    private HitZoneEvaluator evaluator;

    public void Initialize(float speed, float missZonePosition)
    {
        Speed = speed;
        missZoneZ = missZonePosition;
        targetObject = GetComponent<TargetObject>();
        evaluator = FindFirstObjectByType<HitZoneEvaluator>();
    }

    void Update()
    {
        if (targetObject != null && (targetObject.IsDeploying || targetObject.IsResolved || targetObject.IsLockedInHitZone))
        {
            return;
        }

        transform.Translate(Vector3.back * Speed * Time.deltaTime, Space.World);
        // A fixed Z cutoff would truncate the Late window at higher travel speeds.
        // Registered gameplay targets are expired/locked by the evaluator's temporal rule only.
        if (targetObject != null && evaluator != null) return;
        if (transform.position.z < missZoneZ)
        {
            HitZoneEvaluator evaluator = FindObjectOfType<HitZoneEvaluator>();
            if (targetObject != null && !targetObject.IsResolved && evaluator != null)
                evaluator.Miss(targetObject, "miss");
            else Destroy(gameObject);
        }
    }
}
