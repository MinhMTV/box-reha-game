# C# syntax gate

Run from the game root: `dotnet run --project tests/syntax/SyntaxChecks.csproj -- .`

Uses Roslyn from the installed .NET SDK, without a network package dependency. Parses every Assets C# source with C# 9 under Windows Editor, Android Editor, Windows player, Android player and iOS symbols. The Android Editor configuration includes the Gradle export callback. Output: `artifacts/validation/csharp-syntax.json`.

Latest local pass on 2026-09-14 parsed **67 C# files × 5 configurations with zero syntax errors**. Root final validation
may refresh the artifact after documentation freeze. The separate sensor host harness passes 47 Android policy assertions;
neither number is a Unity compilation or native collector execution result.

This catches syntax errors in conditional platform branches. It **does not resolve Unity API types, compile the Unity project, load scenes or verify hardware**. Execute the separate Editor checks and actual player/scene qualification when Unity 2022.3.62f3 is available.

Unity 6.6 migration remains pending until an actual project import. Native SDK compilation is independently blocked:
missing production resource 2.11.1, followed by stripped Kotlin metadata/InnerClasses in Android AARs even with the
separate diagnostic resource 2.12.0 substitution. See [SDK package blockers](../../SDK_PACKAGE_BLOCKERS_2026-09-14.md).
The collector is implemented in source against the documented SDK API; a syntax pass cannot resolve those package failures.
