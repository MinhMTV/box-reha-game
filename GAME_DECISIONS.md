# Current engineering decisions — 15 September 2026

Historical decisions retained in docs/history/pre-hardware-feedback/GAME_DECISIONS.md.

- Preserve Unity 6000.6.0f1, four scenes, art, Android ARM64/IL2CPP and explicit compatibility overlay. No vendor files modified.
- Use actual SDK deleteGloveById and swapGloveSideForId, with persistent-state acknowledgement; do not simulate removal only in the UI.
- Display all paired states including Unknown and use actual device names. Only SDK-reported family can establish identity. Keep mixed-family protection.
- Use a versioned atomic local file repository instead of adding an unqualified SQLite Android dependency. Retain legacy preferences and logs during idempotent migration. Archive rather than destructive deletion.
- Strong reference = median of five comfortable strong actions after familiarization; rapid reference = separately named inter-action interval statistic. Both are physical event-gated and versioned per channel/profile/device. No physiological maximum or force unit is inferred.
- Relative gameplay signal compares identical source quantity/provenance only, with a 2.5 cap. Thresholds 0.45/0.60/0.75 are centralized game balance. Uncalibrated input is explicitly neutral, and body size has no damage modifier.
- TOO LIGHT is a nonterminal matching action, not a Miss. Terminal cleanup is independent of optional presentation. Mesh-only visuals need no colliders.
- Move the actual scoring plane from Z=5 to Z=2, including expected time and heavy lock. Remove visible rails and default control clutter; retain logical lanes and touch pause.
- Keep SDK-dependent raw DELTA experimentation out of gameplay until independent device binding/firmware acquisition is supported. No fake powerIndex or invented raw-kick threshold is deployed.
- Preserve evidence boundaries: user-observed old APK discovery/pairing is real; current synthetic tests, Editor captures, native compilation, APK build and physical measurements are distinct.
