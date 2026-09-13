# Pure Android collector policy tests on the JVM

This independent Gradle project links production `CollectorPolicy.kt` and its JUnit tests. It checks event identity saturation, pause/resume freshness, clock jumps and supported device-family configurations using synthetic values. It deliberately has no Dynamics SDK or Android dependency.

With Java 17 and Gradle 8.13, run `gradle --no-daemon -p tests/android-policy test`. These are JVM logic tests, not collector integration, Unity player, Bluetooth or physical measurement verification. The full Android collector build remains the separate `tools/android` harness and its exact SDK dependency graph.
