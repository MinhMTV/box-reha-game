# Current run state — 15 September 2026

All previous development branches were fast-forward consolidated into local main in E:/Programming Projekte/box-reha-game through 027773f. Five fully incorporated local branches were deleted. Remote branches were not changed or pushed. The old worktree remains detached to preserve its local build/cache files.

The verified version 1.1/code2 APK is now also at Builds/AndroidCandidate/DigitalDojo.apk in the main checkout, SHA-256 aa82afe63a2a0afc76b999f563c3214094217d63c941ceaec4efa207d4fcf472. Merge receipt: artifacts/validation/main-checkout-delivery.json. Host tests after merge: 207 pass; this was an integration/copy, not a new binary build. The four pre-existing tracked Gradle cache changes are preserved outside the commits.

User now authorizes SDK modifications. C:/dynamics-sdk-main is a local Git repository: 20554e6 captures the original distribution, 48aa7be records the multi-device requirements and actual source inventory. The requested Alpha pair plus Delta foot sensors is not implemented: both supplied SDK copies lack the core Kotlin/Gradle sources, and the sources JARs contain only UUID helpers. A source path was requested. See C:/dynamics-sdk-main/LOCAL_DEVELOPMENT.md. Existing two-device/mixed-family guards remain active; no binary bypass was presented as functional support.
