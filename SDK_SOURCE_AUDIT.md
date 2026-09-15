# SDK source audit — 15 September 2026

Scope: complete recursive local inventory excluding .git. 105 JAR/AAR archives opened, 99 Gradle module metadata files parsed. Exact modules, checksums, archive source members and relevant compiled class names: C:/dynamics-sdk-main/SDK_SOURCE_AUDIT.json.

Editable implementation found: 0 loose Kotlin/Java source files. Gradle/source-project paths: 0. The six BLE multiplex UUID Sources-JARs each contain five real helper Kotlin sources (BleAddress/BleUuid/version/source-set helpers), not the acquisition core. Dokka HTML is documentation, .module files are publication metadata, and .class/AAR/iOS frameworks are compiled binaries. API and model signatures can be inspected but are not a buildable Kotlin core source tree.

Database.class resides in dynamics-db-android 0.25.6; GloveManager.class in dynamics-ble-android; GloveRepository and raw/session repository implementation classes in the multiplatform archive. Names/descriptors are retained where supplied; obfuscated implementation classes also exist. No TrainingSession/Repository source project was found hidden in an AAR or JAR. No vendor bytecode was changed.

The original SDK files remain Git-identical to baseline 20554e6; only audit/development documents were added. The second SDK copy was independently checked previously and has no core source project either.
