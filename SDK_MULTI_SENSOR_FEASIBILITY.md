# Multi-sensor feasibility — 15 September 2026

Decision: Case C for this deliverable. No mixed acquisition is enabled. This is a constraint of the supplied distribution and verified public ownership path, not a claim that all Bluetooth radios are limited to two devices.

## Evidence versus hypotheses

**Source:** complete inventory finds no loose .kt/.java or Gradle source project; the six Sources-JARs only contain UUID helpers. See SDK_SOURCE_AUDIT.md and the SDK JSON inventory (105 archives / 99 module metadata files).

**Verified binary/API:** Database's pair insertion reports `Glove Pair is already occupied on both sides!`; computed-session initialization rejects multiple glove pairs and an already-running session. Session models select one family (Alpha/Delta), while physical side is scoped to a glove pair. Public DI uses singleton database/manager/session owners. GloveRepository deletion/swap delegates to that database. See vendor-compat/dynamics-0.25.6/evidence/hardware-feedback-sdk.txt and the earlier MULTI_SENSOR_REPORT.md evidence matrix.

**Public raw APIs:** raw repository/all-device flows and computed APIs are accessible to the Java probe. A raw Flow observes already-bound peripherals; it does not add independent ownership for a third peripheral or establish simultaneous firmware streaming modes. No verified second pairing context or independent Delta binding route was found. Therefore compiling a Flow subscription is insufficient to implement AlphaComputed + DeltaRaw for three/four devices.

**Hypothesis only:** a future vendor-supported independent raw acquisition context could feed DELTA raw readings while ALPHA computed sessions run. Raw acceleration would need a separately named, validated kick detector and thresholds; it must not be relabelled SDK powerIndex. No detector is fabricated here and no compiled binary is patched.

## Implemented application extension boundary

ISensorReadingSink exposes connection/epoch binding, reading submission and forgetting. BleSensorInputProvider implements it and retains the existing validated per-device queue owner. UnifiedGameplayActionMapper now owns the shared SensorReading-to-PlayerActionEvent mapping, with original family/side/device/connection/source timestamp/provenance/detector/quantity/unit and SensorEvidence. Existing CreateSensorAction remains a compatibility facade.

The processor already indexes physical device IDs rather than two side-only slots. Future acquisition adapters can submit via the sink; gameplay need not know which adapter acquired a reading. This is an implemented extension boundary, not an implemented raw provider or orchestrator. Readiness continues to reject mixed/unresolved native families; no dormant UI toggle suggests unavailable support.

Single-family improvement: Delta-only levels/endless now retain Heavy targets and choose ToughKick, while Alpha-only chooses ToughPunch. Delta still disables punch rapid chains. One-sided Delta can complete a center Heavy Kick repeatedly with that same foot. Existing SDK computed Delta-to-kick mapping remains experimental and physically unqualified.

## Remaining evidence required

Buildable SDK source or a documented independent binding/session API, followed by simultaneous live acquisition tests with unique IDs, firmware modes, timestamps, reconnect/background behavior and measurement validation. The local SDK Git preserves original binaries; edits to documentation do not remove their restrictions.
