using UnityEngine;

public class TargetMover : MonoBehaviour
{
    public float Speed { get; set; }
    private float missZoneZ;

    public void Initialize(float speed, float missZonePosition)
    {
        Speed = speed;
        missZoneZ = missZonePosition;
    }

    void Update()
    {
        transform.Translate(Vector3.back * Speed * Time.deltaTime);
        if (transform.position.z < missZoneZ)
        {
            Destroy(gameObject);
        }
    }
}
