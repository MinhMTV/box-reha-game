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
        // Registered gameplay targets (targetObject and evaluator both set) are expired/locked by
        // the evaluator's temporal rule only and already returned above; this fallback only ever
        // runs for an unregistered mover (no evaluator, or no TargetObject at all), so it just
        // cleans itself up rather than reporting a gameplay miss.
        if (targetObject != null && evaluator != null) return;
        if (transform.position.z < missZoneZ) Destroy(gameObject);
    }
}
