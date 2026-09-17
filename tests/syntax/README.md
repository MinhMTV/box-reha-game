# C# syntax gate

Run from the game root: `dotnet run --project tests/syntax/SyntaxChecks.csproj -- .`

Uses Roslyn from the installed .NET SDK to parse Assets C# sources under Windows Editor, Android Editor, Windows player, Android player and iOS symbols. Output: `artifacts/validation/csharp-syntax.json`. This does not resolve Unity API types, load scenes or verify hardware.

Current Editor is Unity 6000.6.0f1. Explicit SDK COMPATIBILITY has existing native/Unity Android build evidence; VENDOR-UNCHANGED retains the dependency blocker. See [ANDROID_STATUS.md](../../ANDROID_STATUS.md). Older 67-file/5-configuration counts describe the 14 September snapshot, not the present source inventory. No syntax check or other test was run for this documentation update. [TODO.md](../../TODO.md).
