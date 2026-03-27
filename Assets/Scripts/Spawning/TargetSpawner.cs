using UnityEngine;
using System.Collections;

/// <summary>
/// Phase 3: Supports vertical position offset on spawned targets.
/// Phase 4: Uses ActionVisualFeedback for lane flashes.
/// v3: Tough target and rapid fire chain spawning support.
/// </summary>
public class TargetSpawner : MonoBehaviour
{
    [SerializeField] private GameObject targetPrefab;
    [SerializeField] private Transform spawnPointLeft;
    [SerializeField] private Transform spawnPointCenter;
    [SerializeField] private Transform spawnPointRight;
    [SerializeField] private float missZoneZ = 0f;
    [SerializeField] private GameConfig gameConfig;

    // v3: Reference to evaluator for rapid fire chains
    [SerializeField] private HitZoneEvaluator hitZoneEvaluator;

    private LevelDefinition currentLevel;
    private bool isSpawning;
    private float speedMultiplier = 1f;
    private float intervalMultiplier = 1f;

    public void StartSpawning(LevelDefinition level)
    {
        currentLevel = level;
        isSpawning = true;
        speedMultiplier = 1f;
        intervalMultiplier = 1f;
        SpawnPatternGenerator.Reset();
        StartCoroutine(SpawnRoutine());
    }

    public void StopSpawning()
    {
        isSpawning = false;
        StopAllCoroutines();
    }

    /// <summary>
    /// Set difficulty modifiers from GameRoundController.
    /// </summary>
    public void SetDifficultyModifiers(float speedMult, float intervalMult)
    {
        speedMultiplier = speedMult;
        intervalMultiplier = intervalMult;
    }

    private IEnumerator SpawnRoutine()
    {
        while (isSpawning)
        {
            float interval = currentLevel.SpawnInterval * intervalMultiplier;
            yield return new WaitForSeconds(interval);
            if (!isSpawning) yield break;

            // v3: Check for rapid fire chain
            if (Random.value < currentLevel.RapidFireChance)
            {
                yield return StartCoroutine(SpawnRapidFireChain());
                continue;
            }

            SpawnPatternData pattern = SpawnPatternGenerator.GetNextPattern(currentLevel);
            pattern.Speed = currentLevel.TargetSpeed * speedMultiplier;

            // v3: Check for tough target
            if (Random.value < currentLevel.ToughTargetChance)
            {
                SpawnToughTarget(pattern);
            }
            else
            {
                SpawnTarget(pattern);
            }
        }
    }

    /// <summary>
    /// v3: Spawn a tough target with multi-hit requirement.
    /// </summary>
    private void SpawnToughTarget(SpawnPatternData pattern)
    {
        Transform spawnPoint = GetSpawnPoint(pattern.Lane);
        if (spawnPoint == null) return;

        Vector3 spawnPos = spawnPoint.position;
        if (gameConfig != null)
        {
            spawnPos.y += gameConfig.GetVerticalOffset(pattern.VerticalPos);
        }

        // Tough targets are 20% slower
        float toughSpeed = pattern.Speed * 0.8f;

        GameObject targetObj = CreateTargetObject(spawnPos, TargetType.ToughPunch);
        if (targetObj == null) return;

        TargetObject target = targetObj.GetComponent<TargetObject>();
        TargetMover mover = targetObj.GetComponent<TargetMover>();

        if (target != null)
        {
            target.Lane = pattern.Lane;
            target.Type = TargetType.ToughPunch;
            target.MoveSpeed = toughSpeed;
            target.HitWindow = currentLevel.HitWindowSeconds;
            target.MinPower = currentLevel.MinPower;
            target.VertPosition = pattern.VerticalPos;
            target.MaxHits = Random.Range(currentLevel.MinToughHits, currentLevel.MaxToughHits + 1);
        }

        if (mover != null)
        {
            mover.Initialize(toughSpeed, missZoneZ);
        }
    }

    /// <summary>
    /// v3: Spawn a rapid fire chain of targets in the same lane.
    /// </summary>
    private IEnumerator SpawnRapidFireChain()
    {
        // Pick a random lane
        LaneType[] lanes = currentLevel.AllowedLanes;
        LaneType chainLane = lanes[Random.Range(0, lanes.Length)];
        int chainLength = Random.Range(currentLevel.MinChainLength, currentLevel.MaxChainLength + 1);

        // Notify evaluator of chain start
        if (hitZoneEvaluator != null)
        {
            hitZoneEvaluator.StartRapidFireChain(chainLane, chainLength);
        }

        float chainSpeed = currentLevel.TargetSpeed * speedMultiplier;

        for (int i = 0; i < chainLength; i++)
        {
            if (!isSpawning) yield break;

            Transform spawnPoint = GetSpawnPoint(chainLane);
            if (spawnPoint == null) yield break;

            Vector3 spawnPos = spawnPoint.position;
            if (gameConfig != null)
            {
                spawnPos.y += gameConfig.GetVerticalOffset(VerticalPosition.Mid);
            }

            GameObject targetObj = CreateTargetObject(spawnPos, TargetType.Punch);
            if (targetObj == null) yield break;

            TargetObject target = targetObj.GetComponent<TargetObject>();
            TargetMover mover = targetObj.GetComponent<TargetMover>();

            if (target != null)
            {
                target.Lane = chainLane;
                target.Type = TargetType.Punch;
                target.MoveSpeed = chainSpeed;
                target.HitWindow = currentLevel.HitWindowSeconds;
                target.MinPower = currentLevel.MinPower;
                target.VertPosition = VerticalPosition.Mid;
            }

            if (mover != null)
            {
                mover.Initialize(chainSpeed, missZoneZ);
            }

            // Short delay between chain targets
            float chainSpacing = Random.Range(0.3f, 0.5f);
            yield return new WaitForSeconds(chainSpacing);
        }
    }

    private void SpawnTarget(SpawnPatternData pattern)
    {
        Transform spawnPoint = GetSpawnPoint(pattern.Lane);
        if (spawnPoint == null) return;

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
            case TargetType.ToughPunch:
                // v3: Slightly larger dark red cube
                target = GameObject.CreatePrimitive(PrimitiveType.Cube);
                target.transform.localScale = new Vector3(1.8f, 1.8f, 1.8f);
                target.transform.rotation = Quaternion.Euler(0f, 45f, 0f);
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
