# Game status — 15 September 2026

Source changes are saved in the separate checkout on `codex/android-hardware-feedback`. See HARDWARE_FEEDBACK_REPORT.md for current build and evidence.

Implemented: acknowledged persistent sensor removal, SDK side swap, real device names, visible unknown-family devices with preparation blocked, one-family single/pair readiness, profile repository and selector, legacy migration, separate measured strength/rapid references, bounded per-profile strength normalization, nonterminal TOO LIGHT, target and health-bar cleanup, mesh-only visual primitives, closer hit plane and reduced HUD clutter.

Validation: 108 hardware-feedback host assertions, 47 Android policy assertions, 26 calibration assertions and existing host groups pass. C# syntax: 75 files across five configurations, zero errors. Static scene checks: 635 pass. Android export checks: 18 pass. Native collector: 16 JVM tests pass in COMPATIBILITY mode. Unity Play Mode synthetic checks pass, including all four action channels, weak-then-strong, heavy completion/timeout and no target/health-bar orphans. These checks are not measured physical sensor evidence.

The user reported successful launch/discovery/ALPHA pairing on the previous APK. Actual physical actions, corrected removal/swap, references and DELTA are still unqualified. ADB currently lists no device. Mixed-family acquisition remains blocked. Current APK result is recorded in ANDROID_STATUS.md.
