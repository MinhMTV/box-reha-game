# C# syntax gate

Run from the game root: `dotnet run --project tests/syntax/SyntaxChecks.csproj -- .`

Uses Roslyn from the installed .NET SDK, without a network package dependency. Parses every Assets C# source with C# 9 under Windows Editor, Windows player, Android and iOS symbols. Output: `artifacts/validation/csharp-syntax.json`.

This catches syntax errors in conditional platform branches. It **does not resolve Unity API types, compile the Unity project, load scenes or verify hardware**. Execute the separate Editor checks and actual player/scene qualification when Unity 2022.3.62f3 is available.
