using System;
using System.IO;

// Host file-transformation checks against synthetic Gradle exports. No Unity or Android execution.
int passed = 0;
void Check(bool value, string name) { if (!value) throw new Exception(name); passed++; Console.WriteLine("PASS " + name); }
void Reject(Action action, string name) { try { action(); } catch (InvalidOperationException) { Check(true, name); return; } throw new Exception(name); }
string root = Path.Combine(Path.GetTempPath(), "boxreha-synthetic-gradle-" + Guid.NewGuid().ToString("N"));
string library = Path.Combine(root, "unityLibrary");
string repo = Path.Combine(root, "supplied sdk");
Directory.CreateDirectory(library);
Directory.CreateDirectory(Path.Combine(root, "launcher"));
File.WriteAllText(Path.Combine(library, "build.gradle"), "android {\n    compileSdk 34\n}\n");
File.WriteAllText(Path.Combine(root, "launcher", "build.gradle"), "android {\n    compileSdkVersion 35\n}\n");
string artifact = Path.Combine(repo, "com", "riseworld", "dynamics", "multiplatform", "dynamics-multiplatform", "0.25.6", "dynamics-multiplatform-0.25.6.module");
Directory.CreateDirectory(Path.GetDirectoryName(artifact));
File.WriteAllText(artifact, "SYNTHETIC PATH FIXTURE, NOT SDK DATA");
File.WriteAllText(Path.Combine(root, "build.gradle"), "plugins { id 'com.android.library' version '9.0.0' apply false }\n");
File.WriteAllText(Path.Combine(root, "settings.gradle"), "dependencyResolutionManagement { repositoriesMode.set(RepositoriesMode.FAIL_ON_PROJECT_REPOS); repositories { google(); mavenCentral() } }\n");
File.WriteAllText(Path.Combine(root, "gradle.properties"), "existing=value\nandroid.builtInKotlin=true\nandroid.newDsl=true\n");
DynamicsGradleExportConfig.Configure(library, repo);
string build = File.ReadAllText(Path.Combine(root, "build.gradle"));
string settings = File.ReadAllText(Path.Combine(root, "settings.gradle"));
string properties = File.ReadAllText(Path.Combine(root, "gradle.properties"));
Check(build.Contains("kotlin-gradle-plugin:2.3.21") && build.Contains("version '9.0.0'"), "Kotlin added while Unity AGP preserved");
Check(settings.Contains("supplied%20sdk") && settings.Contains("FAIL_ON_PROJECT_REPOS"), "Repository path encoded and existing repository mode preserved");
Check(properties.Contains("android.builtInKotlin=false") && properties.Contains("android.newDsl=false") && properties.Contains("existing=value"), "AGP9 opt-out preserves other properties");
Check(File.ReadAllText(Path.Combine(library, "build.gradle")).Contains("compileSdk 36") && File.ReadAllText(Path.Combine(root, "launcher", "build.gradle")).Contains("compileSdkVersion 36"), "Both Unity modules compile against SDK-required API 36");
Check(DynamicsGradleExportConfig.RequireCompileSdk36("android {\n compileSdk = 37\n}").Contains("compileSdk = 37"), "Higher compile SDK is preserved");
Reject(() => DynamicsGradleExportConfig.RequireCompileSdk36("android { compileSdk project.sdkApi }"), "Unresolved compile SDK expression fails explicitly");
DynamicsGradleExportConfig.Configure(library, repo);
Check(build == File.ReadAllText(Path.Combine(root, "build.gradle")) && settings == File.ReadAllText(Path.Combine(root, "settings.gradle")) && properties == File.ReadAllText(Path.Combine(root, "gradle.properties")), "Repeated export transformation is idempotent");
File.WriteAllText(Path.Combine(root, "build.gradle"), "buildscript { dependencies { classpath 'com.android.tools.build:gradle:7.4.2' } }");
Reject(() => DynamicsGradleExportConfig.Configure(library, repo), "Old Unity AGP fails clearly rather than being silently replaced");
Check(!File.ReadAllText(Path.Combine(root, "build.gradle")).Contains("2.3.21"), "Unsupported AGP export remains unchanged");
File.WriteAllText(Path.Combine(root, "build.gradle"), "buildscript { repositories { google() } dependencies { classpath 'com.android.tools.build:gradle:8.13.2' } }\nallprojects { repositories { google(); mavenCentral() } }\n");
File.WriteAllText(Path.Combine(root, "settings.gradle"), "rootProject.name='synthetic'\n");
DynamicsGradleExportConfig.Configure(library, repo);
Check(File.ReadAllText(Path.Combine(root, "build.gradle")).Contains("BOXREHA SDK REPOSITORY"), "Legacy project repositories include supplied SDK without dropping existing repositories");
Reject(() => DynamicsGradleExportConfig.Configure(library, Path.Combine(root, "missing")), "Missing SDK metadata fails before configuration");
Reject(() => DynamicsGradleExportConfig.Configure(root, repo), "Non-export target is refused");
Check(DynamicsGradleExportConfig.ReadAgpVersion("plugins { id(\"com.android.application\") version \"9.0.0\" apply false }") == new Version(9, 0, 0), "Plugin DSL form identifies actual AGP");
Console.WriteLine($"{passed} host Gradle-export checks passed; SYNTHETIC FILE FIXTURES ONLY, NOT UNITY/ANDROID BUILD.");
