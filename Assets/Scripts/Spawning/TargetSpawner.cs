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
    private float toughChanceBonus;
    private float rapidFireChanceBonus;

    public void StartSpawning(LevelDefinition level)
    {
        currentLevel = level;
        isSpawning = true;
        speedMultiplier = 1f;
        intervalMultiplier = 1f;
        toughChanceBonus = 0f;
        rapidFireChanceBonus = 0f;
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
    public void SetDifficultyModifiers(float speedMult, float intervalMult, float toughChanceExtra = 0f, float rapidFireChanceExtra = 0f)
    {
        speedMultiplier = speedMult;
        intervalMultiplier = intervalMult;
        toughChanceBonus = toughChanceExtra;
        rapidFireChanceBonus = rapidFireChanceExtra;
    }

    private IEnumerator SpawnRoutine()
    {
        while (isSpawning)
        {
            if (HasActiveToughTarget())
            {
                yield return new WaitForSeconds(0.1f);
                continue;
            }

            float interval = currentLevel.SpawnInterval * intervalMultiplier;
            yield return new WaitForSeconds(interval);
            if (!isSpawning) yield break;

            // v3: Check for rapid fire chain
            float rapidFireChance = Mathf.Clamp01(currentLevel.RapidFireChance + rapidFireChanceBonus);
            if (Random.value < rapidFireChance)
            {
                yield return StartCoroutine(SpawnRapidFireChain());
                continue;
            }

            SpawnPatternData pattern = SpawnPatternGenerator.GetNextPattern(currentLevel);
            pattern.Speed = currentLevel.TargetSpeed * speedMultiplier;
            ShowSpawnWarning(pattern.Lane, pattern.VerticalPos, pattern.Type);
            yield return new WaitForSeconds(0.16f);
            if (!isSpawning) yield break;

            // v3: Check for tough target
            float toughChance = Mathf.Clamp01(currentLevel.ToughTargetChance + toughChanceBonus);
            if (Random.value < toughChance)
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

            ShowSpawnWarning(chainLane, VerticalPosition.Mid, TargetType.Punch);
            yield return new WaitForSeconds(0.12f);
            if (!isSpawning) yield break;

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

    private bool HasActiveToughTarget()
    {
        TargetObject[] activeObjects = FindObjectsOfType<TargetObject>();
        for (int i = 0; i < activeObjects.Length; i++)
        {
            TargetObject target = activeObjects[i];
            if (target != null && target.IsTough && !target.IsBreaking)
            {
                return true;
            }
        }

        return false;
    }

    private GameObject CreateTargetObject(Vector3 position, TargetType type)
    {
        if (targetPrefab != null)
        {
            return Instantiate(targetPrefab, position, Quaternion.identity);
        }

        GameObject target = new GameObject(type + "Target");
        target.transform.position = position;

        BoxCollider collider = target.AddComponent<BoxCollider>();
        collider.center = Vector3.zero;

        switch (type)
        {
            case TargetType.Block:
                BuildBlockTarget(target.transform);
                collider.size = new Vector3(1.9f, 2.1f, 0.9f);
                break;
            case TargetType.Dodge:
                BuildDodgeTarget(target.transform);
                collider.size = new Vector3(2.8f, 1.0f, 1.0f);
                break;
            case TargetType.ToughPunch:
                BuildTargetDisc(target.transform, GameVisualPalette.GetTargetColor(TargetType.ToughPunch), true);
                collider.size = new Vector3(1.9f, 1.9f, 0.9f);
                break;
            default: // Punch
                BuildTargetDisc(target.transform, GameVisualPalette.GetTargetColor(TargetType.Punch), false);
                collider.size = new Vector3(1.7f, 1.7f, 0.8f);
                break;
        }

        target.AddComponent<TargetObject>();
        target.AddComponent<TargetMover>();
        Rigidbody rb = target.GetComponent<Rigidbody>();
        if (rb == null)
        {
            rb = target.AddComponent<Rigidbody>();
        }

        rb.useGravity = false;
        rb.isKinematic = true;
        return target;
    }

    private void ShowSpawnWarning(LaneType lane, VerticalPosition verticalPosition, TargetType type)
    {
        Transform spawnPoint = GetSpawnPoint(lane);
        if (spawnPoint == null)
        {
            return;
        }

        Vector3 effectPosition = new Vector3(spawnPoint.position.x, spawnPoint.position.y, 5f);
        if (gameConfig != null)
        {
            effectPosition.y = gameConfig.GetVerticalOffset(verticalPosition);
        }

        Color warningColor = GameVisualPalette.GetTargetColor(type);
        SpawnWarningEffect.Create(effectPosition, warningColor, GameVisualPalette.GetSpawnWarningDuration(type));
    }

    private void BuildTargetDisc(Transform parent, Color targetColor, bool heavyTarget)
    {
        float baseRadius = heavyTarget ? 0.95f : 0.82f;
        float depth = heavyTarget ? 0.26f : 0.22f;

        GameObject backPlate = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        backPlate.name = "BackPlate";
        backPlate.transform.SetParent(parent, false);
        backPlate.transform.localPosition = Vector3.zero;
        backPlate.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        backPlate.transform.localScale = new Vector3(baseRadius, depth, baseRadius);
        ApplyMaterial(backPlate, new Color(0.09f, 0.13f, 0.18f, 1f), 0.3f);

        GameObject outerRing = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        outerRing.name = "OuterRing";
        outerRing.transform.SetParent(parent, false);
        outerRing.transform.localPosition = new Vector3(0f, 0f, -0.03f);
        outerRing.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        outerRing.transform.localScale = new Vector3(baseRadius * 0.92f, depth * 0.65f, baseRadius * 0.92f);
        ApplyMaterial(outerRing, targetColor, heavyTarget ? 2.4f : 1.9f);

        GameObject midRing = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        midRing.name = "MidRing";
        midRing.transform.SetParent(parent, false);
        midRing.transform.localPosition = new Vector3(0f, 0f, -0.06f);
        midRing.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        midRing.transform.localScale = new Vector3(baseRadius * 0.62f, depth * 0.55f, baseRadius * 0.62f);
        ApplyMaterial(midRing, new Color(1f, 0.93f, 0.82f, 1f), 0.8f);

        GameObject bullseye = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        bullseye.name = "Bullseye";
        bullseye.transform.SetParent(parent, false);
        bullseye.transform.localPosition = new Vector3(0f, 0f, -0.09f);
        bullseye.transform.localRotation = Quaternion.Euler(90f, 0f, 0f);
        bullseye.transform.localScale = new Vector3(baseRadius * 0.28f, depth * 0.42f, baseRadius * 0.28f);
        ApplyMaterial(bullseye, heavyTarget ? new Color(1f, 0.72f, 0.12f, 1f) : new Color(1f, 0.96f, 0.35f, 1f), heavyTarget ? 2.8f : 2.2f);

        GameObject mount = GameObject.CreatePrimitive(PrimitiveType.Cube);
        mount.name = "Mount";
        mount.transform.SetParent(parent, false);
        mount.transform.localPosition = new Vector3(0f, 0f, 0.18f);
        mount.transform.localScale = new Vector3(baseRadius * 1.2f, baseRadius * 1.2f, 0.08f);
        ApplyMaterial(mount, new Color(0.12f, 0.18f, 0.25f, 1f), 0.25f);
    }

    private void BuildBlockTarget(Transform parent)
    {
        GameObject shield = GameObject.CreatePrimitive(PrimitiveType.Cube);
        shield.name = "Shield";
        shield.transform.SetParent(parent, false);
        shield.transform.localPosition = Vector3.zero;
        shield.transform.localScale = new Vector3(1.65f, 1.95f, 0.42f);
        ApplyMaterial(shield, GameVisualPalette.GetTargetColor(TargetType.Block), 1.7f);

        GameObject core = GameObject.CreatePrimitive(PrimitiveType.Cube);
        core.name = "ShieldCore";
        core.transform.SetParent(parent, false);
        core.transform.localPosition = new Vector3(0f, 0f, -0.08f);
        core.transform.localScale = new Vector3(1.0f, 1.2f, 0.20f);
        ApplyMaterial(core, new Color(0.05f, 0.14f, 0.22f, 1f), 0.4f);
    }

    private void BuildDodgeTarget(Transform parent)
    {
        GameObject bar = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        bar.name = "DodgeBar";
        bar.transform.SetParent(parent, false);
        bar.transform.localPosition = Vector3.zero;
        bar.transform.localRotation = Quaternion.Euler(0f, 0f, 90f);
        bar.transform.localScale = new Vector3(0.42f, 1.45f, 0.42f);
        ApplyMaterial(bar, GameVisualPalette.GetTargetColor(TargetType.Dodge), 1.5f);

        GameObject leftCap = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        leftCap.name = "DodgeCapLeft";
        leftCap.transform.SetParent(parent, false);
        leftCap.transform.localPosition = new Vector3(-1.4f, 0f, 0f);
        leftCap.transform.localScale = Vector3.one * 0.45f;
        ApplyMaterial(leftCap, GameVisualPalette.GetTargetHighlight(TargetType.Dodge), 1.0f);

        GameObject rightCap = GameObject.CreatePrimitive(PrimitiveType.Sphere);
        rightCap.name = "DodgeCapRight";
        rightCap.transform.SetParent(parent, false);
        rightCap.transform.localPosition = new Vector3(1.4f, 0f, 0f);
        rightCap.transform.localScale = Vector3.one * 0.45f;
        ApplyMaterial(rightCap, GameVisualPalette.GetTargetHighlight(TargetType.Dodge), 1.0f);
    }

    private void ApplyMaterial(GameObject visual, Color color, float emissionStrength)
    {
        Collider primitiveCollider = visual.GetComponent<Collider>();
        if (primitiveCollider != null)
        {
            Destroy(primitiveCollider);
        }

        Renderer renderer = visual.GetComponent<Renderer>();
        if (renderer == null)
        {
            return;
        }

        Material material = new Material(Shader.Find("Standard"));
        material.color = color;
        material.SetFloat("_Metallic", 0.12f);
        material.SetFloat("_Glossiness", 0.75f);
        material.EnableKeyword("_EMISSION");
        material.SetColor("_EmissionColor", color * emissionStrength);
        renderer.sharedMaterial = material;
    }
}
