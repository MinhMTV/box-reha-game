using UnityEngine;

public class TargetMover : MonoBehaviour
{
    public float Speed { get; set; }
    private float missZoneZ;
    private TargetObject targetObject;
    private HitZoneEvaluator evaluator;

    public void Initialize(float speed, float missZonePosition, HitZoneEvaluator hitEvaluator = null)
    {
        Speed = speed;
        missZoneZ = missZonePosition;
        targetObject = GetComponent<TargetObject>();
        evaluator = hitEvaluator != null ? hitEvaluator : targetObject?.Evaluator;
    }

    void Update()
    {
        if (targetObject != null && (targetObject.IsDeploying || targetObject.IsResolved || targetObject.IsLockedInHitZone))
        {
            return;
        }

        if(targetObject!=null&&evaluator!=null)
        {
            // A shared clock avoids frame-order drift and reaches the plane at the authoritative timestamp.
            var position=transform.position;
            position.z=evaluator.HitZoneZ+Speed*(targetObject.ExpectedHitTime-Time.time);
            transform.position=position;
        }
        else transform.Translate(Vector3.back * Speed * Time.deltaTime, Space.World);
        // A fixed Z cutoff would truncate the Late window at higher travel speeds.
        // Registered gameplay targets are expired/locked by the evaluator's temporal rule only.
        if (targetObject != null && evaluator != null) return;
        if (transform.position.z < missZoneZ)
        {
            if (targetObject != null && !targetObject.IsResolved && evaluator != null)
                evaluator.Miss(targetObject, "miss");
            else Destroy(gameObject);
        }
    }
}
