using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

/// <summary>Pure file transformation of a generated Unity Gradle export; host-testable without Unity.</summary>
public static class DynamicsGradleExportConfig
{
    private const string KotlinVersion = "2.3.21";
    private const string Start = "// BEGIN BOXREHA DYNAMICS GENERATED CONFIG";
    private const string End = "// END BOXREHA DYNAMICS GENERATED CONFIG";
    private static readonly UTF8Encoding Utf8 = new UTF8Encoding(false);

    public static void Configure(string unityLibraryDirectory, string mavenRepository)
    {
        string library = Path.GetFullPath(unityLibraryDirectory);
        if (!string.Equals(Path.GetFileName(library.TrimEnd(Path.DirectorySeparatorChar, Path.AltDirectorySeparatorChar)), "unityLibrary", StringComparison.Ordinal))
            throw new InvalidOperationException("Dynamics integration expects Unity's generated unityLibrary directory.");
        string root = Directory.GetParent(library).FullName;
        string buildFile = Path.Combine(root, "build.gradle");
        string settingsFile = Path.Combine(root, "settings.gradle");
        if (!File.Exists(buildFile) || !File.Exists(settingsFile))
            throw new InvalidOperationException("Generated Gradle root build.gradle/settings.gradle are missing.");
        string repo = Path.GetFullPath(mavenRepository);
        string module = Path.Combine(repo, "com", "riseworld", "dynamics", "multiplatform", "dynamics-multiplatform", "0.25.6", "dynamics-multiplatform-0.25.6.module");
        if (!File.Exists(module)) throw new InvalidOperationException("DYNAMICS_MAVEN_PATH must point to the supplied SDK mavenLocal directory containing SDK 0.25.6 rich Gradle metadata.");

        string build = RemoveOwnedBlock(File.ReadAllText(buildFile));
        string settings = RemoveOwnedBlock(File.ReadAllText(settingsFile)).TrimEnd();
        Version agp = ReadAgpVersion(build);
        if (agp < new Version(8, 2, 2) || agp > new Version(9, 0, 99))
            throw new InvalidOperationException("SDK Kotlin 2.3.21 requires a compatible Android build toolchain. Generated AGP " + agp + " is outside this configuration guard's range 8.2.2–9.0.x. Use the intended Unity 6.6 Android toolchain; this guard is not build qualification and never replaces Unity's AGP or Gradle.");
        if (build.Contains("org.jetbrains.kotlin") && !build.Contains(KotlinVersion))
            throw new InvalidOperationException("Existing Kotlin plugin configuration conflicts with SDK Kotlin " + KotlinVersion + ". Resolve it explicitly before building.");

        string repositoryUri = new Uri(repo + Path.DirectorySeparatorChar).AbsoluteUri.Replace("'", "\\'");
        string repositoryLine = "maven { url = uri('" + repositoryUri + "'); content { includeGroupByRegex 'com\\\\.riseworld.*'; includeGroupByRegex 'com\\\\.launchpad.*' } }";
        string kotlin = Start + "\nbuildscript {\n    repositories { google(); mavenCentral() }\n    dependencies { classpath 'org.jetbrains.kotlin:kotlin-gradle-plugin:" + KotlinVersion + "' }\n}\n" + End + "\n";
        build = kotlin + build;
        // Settings repositories cover modern Unity exports. Existing project repositories are extended
        // below for exports using PREFER_PROJECT, so no repository-mode override is needed.
        settings += "\n" + Start + "\ndependencyResolutionManagement {\n    repositories { " + repositoryLine + " }\n}\n" + End + "\n";
        bool forbidProjectRepos = settings.Contains("FAIL_ON_PROJECT_REPOS") || settings.Contains("PREFER_SETTINGS");
        if (!forbidProjectRepos)
        {
            build = ExtendRepositories(build, repositoryLine);
        }
        foreach (string relative in new[] { "unityLibrary", "launcher" })
        {
            string moduleFile = Path.Combine(root, relative, "build.gradle");
            if (!File.Exists(moduleFile)) throw new InvalidOperationException("Generated " + relative + "/build.gradle is missing.");
            string moduleBuild = RequireCompileSdk36(File.ReadAllText(moduleFile));
            if (!forbidProjectRepos) moduleBuild = ExtendRepositories(moduleBuild, repositoryLine);
            File.WriteAllText(moduleFile, moduleBuild, Utf8);
        }
        File.WriteAllText(buildFile, build, Utf8);
        File.WriteAllText(settingsFile, settings, Utf8);

        string propertiesFile = Path.Combine(root, "gradle.properties");
        string properties = File.Exists(propertiesFile) ? File.ReadAllText(propertiesFile) : "";
        // Official AGP 9 migration opt-out while the external Kotlin 2.3.21 plugin is used.
        if (agp.Major == 9)
        {
            properties = SetProperty(properties, "android.builtInKotlin", "false");
            properties = SetProperty(properties, "android.newDsl", "false");
        }
        File.WriteAllText(propertiesFile, properties, Utf8);
    }

    public static Version ReadAgpVersion(string gradle)
    {
        Match match = Regex.Match(gradle, @"com\.android\.tools\.build:gradle:(\d+\.\d+\.\d+)");
        if (!match.Success) match = Regex.Match(gradle, "id\\s*(?:\\(\\s*)?['\"]com\\.android\\.(?:application|library)['\"]\\s*\\)?\\s*version\\s*(?:\\(\\s*)?['\"](\\d+\\.\\d+\\.\\d+)['\"]");
        if (!match.Success) throw new InvalidOperationException("Cannot identify generated Android Gradle plugin version; refusing an unverified build mutation.");
        return Version.Parse(match.Groups[1].Value);
    }
    public static string RequireCompileSdk36(string contents)
    {
        const string pattern = "(?m)^(?<prefix>[ \\t]*compileSdk(?:Version)?[ \\t]*(?:=[ \\t]*)?)(?<quote>['\"]?)(?<api>\\d+)\\k<quote>";
        if (!Regex.IsMatch(contents, pattern))
            throw new InvalidOperationException("Cannot identify the generated numeric compileSdk. Dynamics SDK 0.25.6 requires API 36 or later; select Android API 36 in Unity and regenerate.");
        return Regex.Replace(contents, pattern, m => m.Groups["prefix"].Value + m.Groups["quote"].Value + Math.Max(36, int.Parse(m.Groups["api"].Value)) + m.Groups["quote"].Value);
    }
    private static string ExtendRepositories(string contents, string line)
    {
        const string marker = "// BOXREHA SDK REPOSITORY";
        contents = Regex.Replace(contents, @"(?m)^\s*// BOXREHA SDK REPOSITORY\r?\n[^\r\n]*\r?\n", "");
        return Regex.Replace(contents, @"\brepositories\s*\{", m => m.Value + "\n" + marker + "\n" + line + "\n");
    }
    private static string RemoveOwnedBlock(string text) => Regex.Replace(text, Regex.Escape(Start) + ".*?" + Regex.Escape(End) + @"\r?\n?", "", RegexOptions.Singleline);
    private static string SetProperty(string text, string key, string value)
    {
        text = Regex.Replace(text, @"(?m)^\s*" + Regex.Escape(key) + @"\s*=.*\r?\n?", "");
        return text.TrimEnd() + "\n" + key + "=" + value + "\n";
    }
}
