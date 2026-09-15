# Android pairing and correction — 15 September 2026

User evidence from the previous APK: Android install/launch, discovery of ALPHA devices SG-2300003 / SG-2300002, and pairing/connected UI. Wrong side, failed removal and ambiguous family errors were reported. This is real user evidence; real punch delivery/calibration/DELTA/mixed use remain unverified.

1. Initialize SDK, grant Bluetooth permissions, turn on a glove and scan. To identify indistinguishable gloves, switch on one physical glove at a time and note the advertised SG name. Do not infer side from background motion.
2. Select a discovered device and Assign LEFT or RIGHT. Pairing passes the advertised name, no longer the hardcoded BoxReha label.
3. The status lists every reported device, including unresolved/offline entries: real current SDK deviceName (fallback persisted name), side, family, connection state and short pseudonymous ID. It no longer filters Unknown devices out of the UI.
4. Remove LEFT/RIGHT calls SDK `deleteGloveById` for a current saved peripheral. Success requires both savedPeripherals and observeGloves to confirm absence (5-second bounded waits). SDK documentation states persistent deletion and underlying BLE deinitialization. C# caches and per-device processors forget the removed binding. Retired epochs cannot revive it. Current saved binding count controls pairing capacity.
5. Scan again; the device can be assigned a different side. Native removal behavior and slot release must still be rechecked on hardware.
6. Change / swap sides invokes `swapGloveSideForId` for the first listed peripheral. The SDK automatically changes its counterpart within a pair. A single sensor moves to the opposite side; two sensors swap. Wait for the selected DTO's updated side, retire old connection epochs and re-evaluate readiness. The UI states this combined behavior; no two independent non-atomic side writes are used.
7. During a session, Remove/swap/pair buttons are disabled; end the SDK session first. Native commands independently enforce this guard. During pair/remove/swap, buttons remain unavailable until the operation finishes.

Gray = unavailable; blue = actionable; green = a reported completed prerequisite. These colors derive from native state, not click history. Initialize remains green after successful initialization. Profile readiness belongs to the current participant. Errors identify the affected device/side and distinguish unresolved family from a mismatched selected family. Unknown type is never assigned from an SG name or the selected mode.

One Alpha Left, Alpha Right, Alpha pair, Delta Left, Delta Right or Delta pair is valid application policy. Family caching uses only a previous SDK report for that exact peripheral in this collector lifetime; it is cleared on removal. No second phantom glove is required. A genuinely unresolved SDK type remains blocked, so the exact physical single-ALPHA start failure cannot be declared hardware-fixed until retested.

Cases A/B/C: remove left, remove right while preserving left, remove both, re-add opposite side. Case D: end active session first. Host tests prove retirement/capacity/old-epoch rejection and readiness; native compilation proves actual SDK method reachability. They do not execute the Android SDK database or radio.

No Test Device event-identification UI is claimed. Manual one-at-a-time discovery is the available identification procedure. Human-readable names are runtime UI data only; research uses pseudonymous device identity.
