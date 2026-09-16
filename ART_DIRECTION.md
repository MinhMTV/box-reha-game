# Digital Dojo art direction

Current imported reference kit uses the baked 4096px room atlas (Android ASTC 6x6), target normal maps and authored panel fragments. The older texture-free counts below describe the initial kit, not the current reference import. New game-feel accents are thin transverse red/blue hit gates, small mount indicators and six reactive wall insets. Debris and short particles stay bounded; reduced motion retains clear timing. The concept-art fidelity limitations and historical validator gates are classified in ROOM_VALIDATION_REVIEW.md.

Modern training room: dark wood, charcoal concrete, matte padding, restrained dark metal, off-white text, warm indirect-looking accents. Red signals punch; blue signals kick. Heavy uses a large segmented octagonal silhouette and concentric rings. Normal targets are vertical. No floor pads, NPCs, cyberpunk clutter or excessive neon.

## Source and integration

`ArtSource/Blender/DigitalDojo/generate_dojo.py` creates original meter-scale geometry, `DigitalDojoKit.blend`, nine FBX exports and an asset inventory. Targets use center pivots; room modules use floor-center pivots. Blender front is -Y and FBX converts to Unity Y-up. The exported orientation is verified through Unity captures, not inferred from Blender alone.

`Assets/Art/DigitalDojo/Materials` is the shared Built-in Standard material library. `DigitalDojoAssetIntegration` creates reusable prefabs, assigns the three visual references on the existing TargetSpawner and assembles the room resource. Gameplay scripts, colliders and hit resolution stay on the existing runtime target root. Damage segments remain separate; feedback uses MaterialPropertyBlock.

## UI rules

Off-white text on charcoal; one red primary action; visible selected, pressed and disabled states. Display 42, title 34, section 25, body 22, caption 18, metric 32, button 22 logical pixels. Touch controls at least 64 logical pixels high. Use negative space and the room; avoid enclosing every item in a card. Layout must be reviewed at 16:9, wide phone and 4:3 tablet ratios. Do not mistake logical pixels for measured Android dp.

## Rendering budget

Punch 4,588 triangles; kick 1,504; heavy 6,224. Shared materials, no textures required, no real-time point-light arrays, no post-processing dependency. Static modules can batch; target meshes retain separation for feedback. These are geometry/configuration budgets, not device FPS measurements.

## Evidence

`DesignReferences/CurrentBuild/Before` and subsequent pass directories contain actual Unity Play Mode camera renders. `ArtSource/Blender/DigitalDojo/asset-review.png` is a Blender asset sheet, not a game screenshot. Synthetic QA data is labelled and isolated from participant profiles/history/logs. Future approved 2D concepts belong in `DesignReferences/FutureConcepts`.
