# DD-M1 — Integrated Android Digital Dojo

Scope and completion gates: [SPEC](SPEC.md). Branch: codex/agent-root-digital-dojo-2026-09-14. Tracking uses implementation, compile, runtime, visual and hardware evidence separately.

- [x] [DD-001](issues/DD-001.md): Unity 6.6 audit, compile and baseline captures (P0).
- [x] [DD-002](issues/DD-002.md): Reproducible Blender target and modular room kit (P1).
- [x] [DD-003](issues/DD-003.md): Target integration, materials, arena, camera and feedback (P1).
- [x] [DD-004](issues/DD-004.md): Mobile menu, calibration preparation and secondary screens (P1).
- [ ] [DD-005](issues/DD-005.md): Native Android build, permissions and lifecycle qualification (P0/P1).
- [x] [DD-006](issues/DD-006.md): Integrated runtime, visual and regression review (P1).

Sequence: establish compile baseline first; investigate native blockers before dependent APK verification; complete independent art/UI work while external issues are documented. Every issue has a bounded acceptance contract. No hardware or calibration validity is inferred from successful mocks.

DD-005 has an actual failed Unity Android build and an independently failed native build: missing vendor resource 2.11.1. It remains externally blocked; no APK/hardware success. DD-006 source fixes and evidence review completed; delivery is subject to the explicitly external DD-005 gates. See REVIEW.md for observed corrections.

## Current integration milestone

DD-005 native compilation and Android APK sub-gates now pass in explicit COMPATIBILITY mode (LEVEL 5). The checkbox remains open for physical permissions/JNI/BLE/lifecycle qualification. The original vendor publication is still defective; it no longer prevents building this explicitly labelled local candidate. Measured-reference collection/storage is implemented but remains UNQUALIFIED, and HR stays inactive.
