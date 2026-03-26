using UnityEngine;
using System.Collections;

/// <summary>
/// Phase 3: Supports vertical position offset on spawned targets.
/// Phase 4: Uses ActionVisualFeedback for lane flashes.
/// </summary>
public class TargetSpawner : MonoBehaviour
{
    [SerializeField] private GameObject targetPrefab;
    [SerializeField] private Transform spawnPointLeft;
    [SerializeField] private Transform spawnPointCenter;
    [SerializeField] private Transform spawnPointRight;
    [SerializeField] private float missZoneZ = 0f;
    [SerializeField] private GameConfig gameConfig;

    private LevelDefinition currentLevel;
    private bool isSpawning;

    public void StartSpawning(LevelDefinition level)
    {
        currentLevel = level;
        isSpawning = true;
        SpawnPatternGenerator.Reset();
        StartCoroutine(SpawnRoutine());
    }

    public void StopSpawning()
    {
        isSpawning = false;
        StopAllCoroutines();
    }

    private IEnumerator SpawnRoutine()
    {
        while (isSpawning)
        {
            yield return new WaitForSeconds(currentLevel.SpawnInterval);
            if (!isSpawning) yield break;

            SpawnPatternData pattern = SpawnPatternGenerator.GetNextPattern(currentLevel);
            SpawnTarget(pattern);
        }
    }

    private void SpawnTarget(SpawnPatternData pattern)
    {
        Transform spawnPoint = GetSpawnPoint(pattern.Lane);
        if (spawnPoint == null) return;

        // Phase 3: Apply vertical offset
        Vector3 spawnPos = spawnPoint.position;
        if (gameConfig != null)
        {
            spawnPos.y += gameConfig.GetVerticalOffset(pattern.VerticalPos);
        }

        GameObject targetObj = CreateTargetObject(spawnPos, pattern.Type);
        if (targetObj == null) return;

        TargetObject target = targetObj.GetComponent<TargetObject>();
        TargetMover mover = targetObj.GetComponent<TargetMover>();

        if (target != null)
        {
            target.Lane = pattern.Lane;
            target.Type = pattern.Type;
            target.MoveSpeed = pattern.Speed;
            target.HitWindow = currentLevel.HitWindowSeconds;
            target.MinPower = currentLevel.MinPower;
            target.VertPosition = pattern.VerticalPos;
        }

        if (mover != null)
        {
            mover.Initialize(pattern.Speed, missZoneZ);
        }
    }

    private Transform GetSpawnPoint(LaneType lane)
    {
        switch (lane)
        {
            case LaneType.Left: return spawnPointLeft;
            case LaneType.Center: return spawnPointCenter;
            case LaneType.Right: return spawnPointRight;
            default: return spawnPointCenter;
        }
    }

    private GameObject CreateTargetObject(Vector3 position, TargetType type)
    {
        if (targetPrefab != null)
        {
            return Instantiate(targetPrefab, position, Quaternion.identity);
        }

        // Phase 4: Distinct shapes per target type
        GameObject target;
        switch (type)
        {
            case TargetType.Block:
                target = GameObject.CreatePrimitive(PrimitiveType.Cube);
                target.transform.localScale = new Vector3(1.8f, 1.8f, 0.3f);
                break;
            case TargetType.Dodge:
                target = GameObject.CreatePrimitive(PrimitiveType.Cube);
                target.transform.localScale = new Vector3(2.5f, 0.8f, 0.8f);
                break;
            default: // Punch
                target = GameObject.CreatePrimitive(PrimitiveType.Cube);
                target.transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);
                target.transform.rotation = Quaternion.Euler(0f, 45f, 0f);
                break;
        }

        target.transform.position = position;
        target.AddComponent<TargetObject>();
        target.AddComponent<TargetMover>();
        Rigidbody rb = target.GetComponent<Rigidbody>();
        if (rb != null)
        {
            rb.useGravity = false;
            rb.isKinematic = true;
        }
        return target;
    }
}
