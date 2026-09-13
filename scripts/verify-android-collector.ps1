param(
    [Parameter(Mandatory = $true)][string]$GradlePath,
    [string]$JavaHome = 'C:\Program Files\Android\Android Studio\jbr',
    [string]$AndroidSdkPath = "$env:LOCALAPPDATA\Android\Sdk",
    [string]$DynamicsMavenPath = 'C:\dynamics-sdk-main\mavenLocal',
    [string]$UnityClassesJar
)
$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
$harness = Join-Path $projectRoot 'tools\android'
$output = Join-Path $projectRoot 'artifacts\validation'
New-Item -ItemType Directory -Force -Path $output | Out-Null
$reportPath = Join-Path $output 'android-collector-build.json'
$started = [DateTime]::UtcNow
$summary = [ordered]@{ status = 'INCOMPLETE'; generatedUtc = $started.ToString('O'); scope = 'Native Android library compilation and local JVM policy tests; no Unity APK, JNI runtime or Bluetooth hardware verification'; gradle = '8.13'; agp = '8.13.2'; kotlin = '2.3.21'; dynamics = '0.25.6'; unityBoundary = ''; tests = 0; sourceFiles = @() }
$oldJava = $env:JAVA_HOME
$oldAndroid = $env:ANDROID_HOME
$oldDynamics = $env:DYNAMICS_MAVEN_PATH
try {
    foreach ($required in @($GradlePath, (Join-Path $JavaHome 'bin\javac.exe'), (Join-Path $AndroidSdkPath 'platforms\android-36\android.jar'), (Join-Path $DynamicsMavenPath 'com\riseworld\dynamics\multiplatform\dynamics-multiplatform\0.25.6\dynamics-multiplatform-0.25.6.module'))) {
        if (-not (Test-Path -LiteralPath $required -PathType Leaf)) { throw "Missing build dependency: $required" }
    }
    $env:JAVA_HOME = $JavaHome
    $env:ANDROID_HOME = $AndroidSdkPath
    $env:DYNAMICS_MAVEN_PATH = $DynamicsMavenPath
    $gradleVersion = (& $GradlePath --version 2>&1) -join "`n"
    if ($LASTEXITCODE -ne 0 -or $gradleVersion -notmatch '(?m)^Gradle 8\.13\s*$') { throw 'This standalone harness is pinned to Gradle 8.13.' }
    $gradleVersion | Set-Content -LiteralPath (Join-Path $output 'android-toolchain.txt') -Encoding utf8
    if (-not $UnityClassesJar) {
        $stubDirectory = Join-Path $harness '.unity-stub'
        New-Item -ItemType Directory -Force -Path $stubDirectory | Out-Null
        & (Join-Path $JavaHome 'bin\javac.exe') -source 17 -target 17 -classpath (Join-Path $AndroidSdkPath 'platforms\android-36\android.jar') -d $stubDirectory (Join-Path $harness 'stubs\com\unity3d\player\UnityPlayer.java')
        if ($LASTEXITCODE -ne 0) { throw 'Compile-only Unity boundary failed.' }
        $UnityClassesJar = Join-Path $stubDirectory 'unity-compile-only.jar'
        & (Join-Path $JavaHome 'bin\jar.exe') --create --file $UnityClassesJar -C $stubDirectory com
        if ($LASTEXITCODE -ne 0) { throw 'Compile-only Unity boundary jar failed.' }
        $summary.unityBoundary = 'Narrow compile-only UnityPlayer stub, excluded from the AAR; not Unity integration evidence'
    } else { $summary.unityBoundary = 'Caller-supplied compile-only Unity classes jar' }
    $UnityClassesJar = (Resolve-Path -LiteralPath $UnityClassesJar).Path
    $plugin = Join-Path $projectRoot 'Assets\Plugins\Android\DynamicsSdkUnityBridge.androidlib'
    $summary.sourceFiles = @(Get-ChildItem -LiteralPath $plugin -Recurse -File |
        Where-Object { $_.FullName -notmatch '[\\/](\.gradle|\.kotlin|build)[\\/]' } |
        Sort-Object FullName | ForEach-Object { @{ path = $_.FullName.Substring($projectRoot.Length + 1); sha256 = (Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant() } })
    & $GradlePath --no-daemon --console=plain -p $harness "-PunityClassesJar=$UnityClassesJar" :bridge:assembleDebug :bridge:testDebugUnitTest 2>&1 | Tee-Object -FilePath (Join-Path $output 'android-collector-build.log')
    if ($LASTEXITCODE -ne 0) { throw 'Native Gradle build failed; inspect android-collector-build.log.' }
    foreach ($source in $summary.sourceFiles) {
        if ((Get-FileHash -LiteralPath (Join-Path $projectRoot $source.path) -Algorithm SHA256).Hash.ToLowerInvariant() -ne $source.sha256) { throw 'Native source changed during build; rerun against the frozen source.' }
    }
    $aar = Join-Path $harness 'build\bridge\outputs\aar\bridge-debug.aar'
    if (-not (Test-Path -LiteralPath $aar)) { throw 'Gradle did not produce the expected AAR.' }
    $testReports = @(Get-ChildItem -LiteralPath (Join-Path $harness 'build\bridge\test-results\testDebugUnitTest') -Filter 'TEST-*.xml' -File)
    if ($testReports.Count -eq 0) { throw 'Missing native policy test report.' }
    foreach ($file in $testReports) {
        [xml]$result = Get-Content -LiteralPath $file.FullName -Raw
        if ([int]$result.testsuite.failures -gt 0 -or [int]$result.testsuite.errors -gt 0 -or [int]$result.testsuite.skipped -gt 0) { throw 'Native policy tests failed or were skipped.' }
        $summary.tests += [int]$result.testsuite.tests
    }
    if ($summary.tests -lt 1) { throw 'No native policy tests executed.' }
    & $GradlePath --no-daemon --console=plain -p $harness "-PunityClassesJar=$UnityClassesJar" :bridge:dependencies --configuration debugRuntimeClasspath 2>&1 | Tee-Object -FilePath (Join-Path $output 'android-runtime-dependencies.txt')
    if ($LASTEXITCODE -ne 0 -or (Select-String -LiteralPath (Join-Path $output 'android-runtime-dependencies.txt') -Pattern '\bFAILED\b' -Quiet)) { throw 'Dependency report contains unresolved dependencies.' }
    $summary.status = 'PASSED'
    $summary.aar = $aar
    $summary.aarSha256 = (Get-FileHash -LiteralPath $aar -Algorithm SHA256).Hash.ToLowerInvariant()
} catch {
    $summary.status = 'FAILED'
    $summary.reason = $_.Exception.Message
    throw
} finally {
    $summary.generatedUtc = [DateTime]::UtcNow.ToString('O')
    $summary | ConvertTo-Json -Depth 6 | Set-Content -LiteralPath $reportPath -Encoding utf8
    $env:JAVA_HOME = $oldJava
    $env:ANDROID_HOME = $oldAndroid
    $env:DYNAMICS_MAVEN_PATH = $oldDynamics
}
