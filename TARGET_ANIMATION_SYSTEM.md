# Target animation — 15 September 2026

Runtime Unity motion uses the existing imported Blender meshes. Blender's review timeline remains an authoring reference, not an imported animation controller.

- Idle/preload: 80 ms in the fitness profile; shared target LEDs and a plate-mounted indicator anticipate deployment. The .20/.50 s deployment follows preload, for total movement delays .28/.58 s.
- Deploy / Align: production normal .20 s (bounded .20–.40), heavy .50 s (.50–.80), plus preload. Three owned nested sleeves extend from the wall/floor support. Last 60 ms is the alignment phase.
- Travel: TargetMover begins only after deployment. Reduced motion removes the swing/displacement but preserves this timing gate.
- Impact: accepted visual recoil 5 cm; weak recoil 1.5 cm; small angular response and emissive flash. Target positions used for scoring are not displaced by visual recoil.
- Resolve: logical removal and cleanup deadline precede optional presentation. Good/Early/Late normal targets retract; Perfect normal and completed heavy targets break. No global timeScale hit-stop.
- Heavy damage: stages at remaining health 70%, 40%, zero; existing LED damage segments darken persistently and authored panel seams open slightly. Same-hand Punch and same-foot Kick remain valid. Heavy Kick uses the lower blue silhouette and deeper impact/break audio.
- Break: original authored pieces feed a scene-owned 48-slot mesh pool. Normal uses up to six fragments; current heavy meshes supply six to eight (cap ten). No runtime fracture, Rigidbody or collider. Deterministic ballistic displacement with floor-only bounce, final shrink and 1.15 active-second lifetime. Source panels are hidden to avoid duplicate fragment drawing.
- Cleanup: target/mount/health bar are destroyed; inactive debris slots are reusable until scene unload. Abort and scene teardown retain ownership.

One `DojoGameFeel` controller adjusts six narrow wall insets through property blocks, reacting to combo 5/10/20/30, heavy focus, perfect pulse and kick streak. No extra realtime lights. Camera impulse is bounded at 1.2 cm and disabled in reduced motion. The room's baked lighting remains intact.

Audio hooks: TargetDeploy, optional TargetTravel (silent), PunchImpact, KickImpact, TooLight, Perfect, HeavyDamage, HeavyBreak, ComboTier, SessionStart/End. Clips are procedural. No third-party copyrighted audio was added.

Mobile discipline: at most four particle emitters × 24 particles, shared particle material with explicit lifetime; at most three short hit popups and one restrained combo popup. No per-frame material instantiation in the new gate/room/debris controllers. This configuration does not establish device FPS, thermal or GPU performance.

Current documentation review: 17 September 2026, main `3f99b17`. Existing test/capture statements retain their dated scope; no tests were run for this update. Latest pacing/order runtime remains unverified. Overall state: [GAME_STATUS.md](GAME_STATUS.md); remaining work: [TODO.md](TODO.md).
