# Game status — 17 September 2026

Current consolidation work is saved in the main checkout based on e1e6341, uncommitted. See SPAWNING_ARCHITECTURE.md for the final flow and `artifacts/validation/unity-android-candidate-build.json` for the current build receipt. The current candidate is Unity 6000.6.0f1, Android ARM64/IL2CPP, SDK COMPATIBILITY.

Implemented: acknowledged persistent sensor removal, SDK side swap, real device names, visible unknown-family devices with preparation blocked, one-family single/pair readiness, profile repository and selector, legacy migration, separate measured strength/rapid references, bounded per-profile strength normalization, nonterminal TOO LIGHT, target and health-bar cleanup, mesh-only visual primitives, closer hit plane and reduced HUD clutter.

Validation: the latest Unity compile and Android candidate build completed with zero errors. The previously executed synthetic Play Mode and host checks remain passing; they are not measured physical sensor evidence.

The user reported successful launch/discovery/ALPHA pairing on the previous APK. Actual physical actions, corrected removal/swap, references and DELTA are still unqualified. ADB currently lists no device. Mixed-family acquisition remains blocked. Current APK result is recorded in ANDROID_STATUS.md.
