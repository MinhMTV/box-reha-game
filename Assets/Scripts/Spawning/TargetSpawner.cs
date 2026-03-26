using UnityEngine;
using System.Collections;

public class TargetSpawner : MonoBehaviour
{
    [SerializeField] private GameObject targetPrefab;
    [SerializeField] private Transform spawnPointLeft;
    [SerializeField] private Transform spawnPointCenter;
    [SerializeField] private Transform spawnPointRight;
    [SerializeField] private float missZoneZ = 0f;

    private LevelDefinition currentLevel;
    private bool isSpawning;

    public void StartSpawning(LevelDefinition level)
    {
        currentLevel = level;
        isSpawning = true;
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

        GameObject targetObj = CreateTargetObject(spawnPoint.position);
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

    private GameObject CreateTargetObject(Vector3 position)
    {
        if (targetPrefab != null)
        {
            return Instantiate(targetPrefab, position, Quaternion.identity);
        }

        GameObject cube = GameObject.CreatePrimitive(PrimitiveType.Cube);
        cube.transform.position = position;
        cube.transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);
        cube.AddComponent<TargetObject>();
        cube.AddComponent<TargetMover>();
        Rigidbody rb = cube.GetComponent<Rigidbody>();
        if (rb != null)
        {
            rb.useGravity = false;
            rb.isKinematic = true;
        }
        return cube;
    }
}
