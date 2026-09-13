using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;

// Parse every project C# file under the relevant conditional compilation symbols.
// This does not compile against UnityEngine or execute scenes.
class Program
{
    static int Main(string[] args)
    {
        string root = args.Length > 0 ? Path.GetFullPath(args[0]) : Directory.GetCurrentDirectory();
        string[] files = Directory.GetFiles(Path.Combine(root, "Assets"), "*.cs", SearchOption.AllDirectories);
        string[][] symbolSets = { new[] { "UNITY_EDITOR", "UNITY_STANDALONE_WIN" }, new[] { "UNITY_EDITOR", "UNITY_ANDROID" },
            new[] { "UNITY_ANDROID" }, new[] { "UNITY_IOS" }, new[] { "UNITY_STANDALONE_WIN" } };
        var errors = new List<string>();
        foreach (string[] symbols in symbolSets)
        foreach (string file in files)
        {
            var options = new CSharpParseOptions(LanguageVersion.CSharp9, preprocessorSymbols: symbols);
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(file), options, file);
            foreach (Diagnostic diagnostic in tree.GetDiagnostics().Where(d => d.Severity == DiagnosticSeverity.Error))
                errors.Add(string.Join(",", symbols) + ": " + diagnostic);
        }
        string output = Path.Combine(root, "artifacts", "validation", "csharp-syntax.json");
        Directory.CreateDirectory(Path.GetDirectoryName(output));
        var report = new { generatedUtc = DateTime.UtcNow.ToString("O"), language = "C# 9",
            status = errors.Count == 0 ? "PASS" : "FAIL", fileCount = files.Length,
            configurationCount = symbolSets.Length, errors,
            boundary = "Syntax parsing only. NOT Unity API compilation, player build, runtime or hardware qualification." };
        File.WriteAllText(output, JsonSerializer.Serialize(report, new JsonSerializerOptions { WriteIndented = true }) + "\n");
        Console.WriteLine($"C# syntax: {files.Length} files x {symbolSets.Length} configurations, {errors.Count} errors.");
        foreach (string error in errors) Console.WriteLine(error);
        return errors.Count == 0 ? 0 : 1;
    }
}
