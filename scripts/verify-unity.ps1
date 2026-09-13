param(
    [string]$UnityPath,
    [switch]$BuildCandidate
)
$ErrorActionPreference = 'Stop'
$projectRoot = Split-Path -Parent $PSScriptRoot
$validationDir = Join-Path $projectRoot 'artifacts\validation'
New-Item -ItemType Directory -Force -Path $validationDir | Out-Null
$editorVersionLine = Get-Content -LiteralPath (Join-Path $projectRoot 'ProjectSettings\ProjectVersion.txt') | Select-Object -First 1
$editorVersion = ($editorVersionLine -split ':', 2)[1].Trim()
if (-not $UnityPath) {
    $UnityPath = Join-Path $env:ProgramFiles "Unity\Hub\Editor\$editorVersion\Editor\Unity.exe"
}
if (-not (Test-Path -LiteralPath $UnityPath -PathType Leaf)) {
    $failure = @{ status = 'NOT RUN'; reason = 'Unity editor executable unavailable'; requiredVersion = $editorVersion; checkedPath = $UnityPath; generatedUtc = [DateTime]::UtcNow.ToString('O') }
    $failure | ConvertTo-Json | Set-Content -LiteralPath (Join-Path $validationDir 'unity-environment.json') -Encoding utf8
    throw 'Unity 2022.3.62f3 is required. Pass -UnityPath with the installed, licensed Editor executable.'
}
$UnityPath = (Resolve-Path -LiteralPath $UnityPath).Path
$projectRoot = (Resolve-Path -LiteralPath $projectRoot).Path
$environmentReport = Join-Path $validationDir 'unity-environment.json'
@{ status = 'INCOMPLETE'; reason = 'Verification started; success requires fresh validated reports'; requiredVersion = $editorVersion; checkedPath = $UnityPath; generatedUtc = [DateTime]::UtcNow.ToString('O') } |
    ConvertTo-Json | Set-Content -LiteralPath $environmentReport -Encoding utf8
function Read-FreshUnityReport([string]$ReportPath, [DateTime]$StartedUtc, [string[]]$RequiredFields) {
    if (-not (Test-Path -LiteralPath $ReportPath -PathType Leaf)) { throw "Unity did not produce $ReportPath" }
    $reportFile = Get-Item -LiteralPath $ReportPath
    if ($reportFile.LastWriteTimeUtc -lt $StartedUtc) { throw "Unity report is stale: $ReportPath" }
    $result = Get-Content -LiteralPath $ReportPath -Raw | ConvertFrom-Json
    foreach ($field in $RequiredFields) {
        if ($result.PSObject.Properties.Name -notcontains $field -or $null -eq $result.$field) { throw "Unity report is missing $field" }
    }
    if ($result.unityVersion -ne $editorVersion) { throw "Unexpected Unity version $($result.unityVersion); expected $editorVersion" }
    if ([DateTimeOffset]::Parse($result.utc).UtcDateTime -lt $StartedUtc) { throw "Unity report timestamp is stale: $ReportPath" }
    return $result
}
$gitRevision = (& git -C $projectRoot rev-parse HEAD).Trim()
if ($LASTEXITCODE -ne 0) { throw 'Unable to record source revision.' }
function Get-SourceSnapshot {
    $sourceFiles = foreach ($sourceRoot in @('Assets', 'Packages', 'ProjectSettings')) {
        Get-ChildItem -LiteralPath (Join-Path $projectRoot $sourceRoot) -Recurse -File |
            Where-Object { $_.Name -notlike 'ResearchBuildInfo.txt*' } |
            ForEach-Object { [PSCustomObject]@{ path = $_.FullName.Substring($projectRoot.Length + 1).Replace('\', '/'); sha256 = (Get-FileHash -LiteralPath $_.FullName -Algorithm SHA256).Hash.ToLowerInvariant() } }
    }
    $sourceFiles = @($sourceFiles | Sort-Object path)
    $payload = ($sourceFiles | ForEach-Object { $_.path + ':' + $_.sha256 }) -join "`n"
    $sha = [Security.Cryptography.SHA256]::Create()
    try { $digest = [BitConverter]::ToString($sha.ComputeHash([Text.Encoding]::UTF8.GetBytes($payload))).Replace('-', '').ToLowerInvariant() }
    finally { $sha.Dispose() }
    return [PSCustomObject]@{ files = $sourceFiles; digest = $digest }
}
$snapshot = Get-SourceSnapshot
$sourceFiles = $snapshot.files
$sourceDigest = $snapshot.digest
$dirty = @(& git -C $projectRoot status --porcelain -- Assets Packages ProjectSettings).Count -gt 0
$buildIdentity = "revision=$gitRevision; sourceSha256=$sourceDigest; dirty=$dirty"
$resourcePath = Join-Path $projectRoot 'Assets\Resources\ResearchBuildInfo.txt'
[IO.File]::WriteAllText($resourcePath, $buildIdentity + "`n", [Text.UTF8Encoding]::new($false))
$manifest = @{ generatedUtc = [DateTime]::UtcNow.ToString('O'); revision = $gitRevision; sourceSha256 = $sourceDigest; dirty = $dirty; files = $sourceFiles; unityPath = $UnityPath }
$manifest | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $validationDir 'unity-source-manifest.json') -Encoding utf8
$editorLog = Join-Path $validationDir 'unity-editor.log'
# Start-Process is hidden; quoted paths are necessary for this workspace's spaces.
$arguments = @('-batchmode', '-nographics', '-quit', '-projectPath', ('"' + $projectRoot + '"'), '-executeMethod', 'GameRegressionChecks.RunBatch', '-logFile', ('"' + $editorLog + '"'))
$checksStartedUtc = [DateTime]::UtcNow
$process = Start-Process -FilePath $UnityPath -ArgumentList $arguments -PassThru -Wait -WindowStyle Hidden
if ($process.ExitCode -ne 0) { throw "Unity qualification failed (exit $($process.ExitCode)). Inspect $editorLog" }
$checks = Read-FreshUnityReport (Join-Path $validationDir 'unity-editor-checks.json') $checksStartedUtc @('utc', 'unityVersion', 'passed', 'failed', 'checks')
if ($checks.failed -ne 0 -or $checks.passed -le 0 -or @($checks.checks).Count -ne ($checks.passed + $checks.failed)) { throw 'Unity regression report contains failures or an inconsistent check count.' }
if ((Get-SourceSnapshot).digest -ne $sourceDigest) { throw 'Project source changed during Editor import/checks. Inspect the diff, freeze the imported source and rerun verification.' }
if ($BuildCandidate) {
    $buildLog = Join-Path $validationDir 'unity-player-build.log'
    $arguments = @('-batchmode', '-nographics', '-quit', '-projectPath', ('"' + $projectRoot + '"'), '-executeMethod', 'GameRegressionChecks.BuildStudyCandidate', '-logFile', ('"' + $buildLog + '"'))
    $buildStartedUtc = [DateTime]::UtcNow
    $process = Start-Process -FilePath $UnityPath -ArgumentList $arguments -PassThru -Wait -WindowStyle Hidden
    if ($process.ExitCode -ne 0) { throw "Candidate build failed (exit $($process.ExitCode)). Inspect $buildLog" }
    $build = Read-FreshUnityReport (Join-Path $validationDir 'unity-candidate-build.json') $buildStartedUtc @('utc', 'unityVersion', 'result', 'errors', 'outputPath')
    if ($build.result -ne 'Succeeded' -or $build.errors -ne 0) { throw 'Unity candidate report did not record a successful build without errors.' }
    if (-not (Test-Path -LiteralPath $build.outputPath -PathType Leaf)) { throw 'Reported candidate executable is missing.' }
    if ((Get-SourceSnapshot).digest -ne $sourceDigest) { throw 'Project source changed during candidate build. Inspect the diff and rerun verification against a frozen source snapshot.' }
}
@{ status = 'EDITOR CHECKS PASSED'; candidateBuild = $(if ($BuildCandidate) { 'PASSED' } else { 'NOT RUN' }); requiredVersion = $editorVersion; checkedPath = $UnityPath; sourceSha256 = $sourceDigest; runtimeAndHardware = 'NOT VERIFIED BY THIS SCRIPT'; generatedUtc = [DateTime]::UtcNow.ToString('O') } |
    ConvertTo-Json | Set-Content -LiteralPath $environmentReport -Encoding utf8
Write-Output 'Editor checks completed. Player interaction, visual QA and physical hardware remain separate qualification gates.'
