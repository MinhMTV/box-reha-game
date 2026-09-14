param(
    [string]$UnityPath,
    [switch]$BuildCandidate,
    [ValidateSet('VENDOR-UNCHANGED', 'COMPATIBILITY')][string]$SdkMode = 'VENDOR-UNCHANGED',
    [ValidateSet('Android', 'WindowsDevelopment')][string]$Target = 'Android'
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
    throw "Unity Editor $editorVersion is not available. Pass -UnityPath after installation and any intended Unity 6.6 migration/import. Android also requires Android Build Support, SDK/NDK and OpenJDK."
}
$UnityPath = (Resolve-Path -LiteralPath $UnityPath).Path
$projectRoot = (Resolve-Path -LiteralPath $projectRoot).Path
$environmentReport = Join-Path $validationDir 'unity-environment.json'
@{ status = 'INCOMPLETE'; reason = 'Verification started; success requires fresh validated reports'; requiredVersion = $editorVersion; checkedPath = $UnityPath; generatedUtc = [DateTime]::UtcNow.ToString('O') } |
    ConvertTo-Json | Set-Content -LiteralPath $environmentReport -Encoding utf8
# Each owned Editor has a bounded lifetime; force termination is recorded independently of task success.
$env:DYNAMICS_SDK_MODE = $SdkMode
$ownedRuns = [Collections.Generic.List[object]]::new()
function Get-JsonUtc($Value) {
    if ($Value -is [DateTimeOffset]) { return $Value.UtcDateTime }
    if ($Value -is [DateTime]) { return $Value.ToUniversalTime() }
    return [DateTimeOffset]::Parse([string]$Value, [Globalization.CultureInfo]::InvariantCulture, [Globalization.DateTimeStyles]::RoundtripKind).UtcDateTime
}
function Wait-OwnedEditor($OwnedProcess, [string]$LogPath, [string]$ReportPath, [DateTime]$Started, [string]$Marker) {
    $completedAt = $null
    $forced = $false
    $timedOut = $false
    while (-not $OwnedProcess.HasExited) {
        $freshEvidence = $false
        if ($ReportPath -and (Test-Path -LiteralPath $ReportPath)) {
            try {
                $item = Get-Item -LiteralPath $ReportPath
                $data = Get-Content -LiteralPath $ReportPath -Raw | ConvertFrom-Json
                $freshEvidence = $item.LastWriteTimeUtc -ge $Started -and (Get-JsonUtc $data.utc) -ge $Started
            } catch { $freshEvidence = $false }
        } elseif ($Marker -and (Test-Path -LiteralPath $LogPath)) {
            $freshEvidence = (Get-Item -LiteralPath $LogPath).LastWriteTimeUtc -ge $Started -and (Select-String -LiteralPath $LogPath -SimpleMatch $Marker -Quiet)
        }
        if ($freshEvidence -and -not $completedAt) { $completedAt = [DateTime]::UtcNow }
        $timedOut = ([DateTime]::UtcNow - $Started).TotalMinutes -gt 40
        if ($timedOut -or ($completedAt -and ([DateTime]::UtcNow - $completedAt).TotalSeconds -ge 30)) {
            # Keep the Process object/start time from Start-Process; never enumerate and kill unrelated Editors.
            if (-not $OwnedProcess.HasExited) { $OwnedProcess.Kill(); $OwnedProcess.WaitForExit(); $forced = $true }
            break
        }
        Start-Sleep -Milliseconds 500
        $OwnedProcess.Refresh()
    }
    $OwnedProcess.WaitForExit()
    $ownedRuns.Add(@{ pid = $OwnedProcess.Id; startedUtc = $Started.ToString('O'); forcedTermination = $forced; timedOut = $timedOut;
        freshCompletionEvidence = [bool]$completedAt; exitCode = $OwnedProcess.ExitCode; sdkMode = $SdkMode; log = $LogPath })
    $ownedRuns | ConvertTo-Json -Depth 4 | Set-Content -LiteralPath (Join-Path $validationDir 'unity-owned-processes.json') -Encoding utf8
    if (Test-Path -LiteralPath $LogPath) {
        $logContents = Get-Content -LiteralPath $LogPath -Raw
        if ($logContents -match '(?m)^Environment Variables\s*:') {
            $rawDirectory = Join-Path $projectRoot '.agent-tooling/validation-raw'
            New-Item -ItemType Directory -Force $rawDirectory | Out-Null
            Copy-Item -LiteralPath $LogPath -Destination (Join-Path $rawDirectory ($OwnedProcess.Id.ToString() + '-' + [IO.Path]::GetFileName($LogPath)))
            $safeLog = [regex]::Replace($logContents, '(?ms)^Environment Variables\s*:.*?(?=^stderr\[|\z)', 'Environment Variables: [OMITTED FROM SHAREABLE EVIDENCE]' + "`n")
            [IO.File]::WriteAllText($LogPath, $safeLog, [Text.UTF8Encoding]::new($false))
        }
    }
    if ($timedOut) { throw 'Owned Unity process timed out without completing within 40 minutes.' }
    if (-not $forced -and $OwnedProcess.ExitCode -ne 0) { throw "Unity exited with code $($OwnedProcess.ExitCode). See $LogPath" }
    if ($forced -and -not $completedAt) { throw 'Forced Unity termination without fresh completion evidence.' }
}
# Android preparation deliberately precedes the source stamp: it persists the
# candidate PlayerSettings. Subsequent checks/build must leave that source frozen.
$unityBuildTarget = if ($Target -eq 'Android') { 'Android' } else { 'Win64' }
if ($BuildCandidate -and $Target -eq 'Android') {
    $prepareLog = Join-Path $validationDir 'unity-android-prepare.log'
    $prepareArguments = @('-batchmode', '-nographics', '-quit', '-projectPath', ('"' + $projectRoot + '"'), '-buildTarget', 'Android', '-executeMethod', 'GameRegressionChecks.PrepareAndroidCandidate', '-logFile', ('"' + $prepareLog + '"'))
    $prepareStarted = [DateTime]::UtcNow
    $prepareProcess = Start-Process -FilePath $UnityPath -ArgumentList $prepareArguments -PassThru -WindowStyle Hidden
    Wait-OwnedEditor $prepareProcess $prepareLog $null $prepareStarted "BOXREHA_ANDROID_PREPARATION_COMPLETED"
    $importedVersion = ((Get-Content -LiteralPath (Join-Path $projectRoot 'ProjectSettings\ProjectVersion.txt') | Select-Object -First 1) -split ':', 2)[1].Trim()
    if ($importedVersion -ne $editorVersion) { throw 'Editor import changed ProjectVersion. Review and freeze the migration, then rerun verification.' }
}
function Read-FreshUnityReport([string]$ReportPath, [DateTime]$StartedUtc, [string[]]$RequiredFields) {
    if (-not (Test-Path -LiteralPath $ReportPath -PathType Leaf)) { throw "Unity did not produce $ReportPath" }
    $reportFile = Get-Item -LiteralPath $ReportPath
    if ($reportFile.LastWriteTimeUtc -lt $StartedUtc) { throw "Unity report is stale: $ReportPath" }
    $result = Get-Content -LiteralPath $ReportPath -Raw | ConvertFrom-Json
    foreach ($field in $RequiredFields) {
        if ($result.PSObject.Properties.Name -notcontains $field -or $null -eq $result.$field) { throw "Unity report is missing $field" }
    }
    if ($result.unityVersion -ne $editorVersion) { throw "Unexpected Unity version $($result.unityVersion); expected $editorVersion" }
    if ((Get-JsonUtc $result.utc) -lt $StartedUtc) { throw "Unity report timestamp is stale: $ReportPath" }
    return $result
}
$gitRevision = (& git -C $projectRoot rev-parse HEAD).Trim()
if ($LASTEXITCODE -ne 0) { throw 'Unable to record source revision.' }
function Get-SourceSnapshot {
    $sourceFiles = foreach ($sourceRoot in @('Assets', 'Packages', 'ProjectSettings')) {
        Get-ChildItem -LiteralPath (Join-Path $projectRoot $sourceRoot) -Recurse -File |
            Where-Object { $_.Name -notlike 'ResearchBuildInfo.txt*' -and $_.Name -notlike 'PerformanceTestRunInfo.json*' -and $_.Name -notlike 'PerformanceTestRunSettings.json*' -and $_.FullName -notmatch '[\\/](\.gradle|\.kotlin|build)[\\/]' } |
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
$buildIdentity = "revision=$gitRevision; sourceSha256=$sourceDigest; dirty=$dirty; sdkMode=$SdkMode"
$resourcePath = Join-Path $projectRoot 'Assets\Resources\ResearchBuildInfo.txt'
New-Item -ItemType Directory -Force -Path (Split-Path -Parent $resourcePath) | Out-Null
[IO.File]::WriteAllText($resourcePath, $buildIdentity + "`n", [Text.UTF8Encoding]::new($false))
$manifest = @{ generatedUtc = [DateTime]::UtcNow.ToString('O'); revision = $gitRevision; sourceSha256 = $sourceDigest; dirty = $dirty; files = $sourceFiles; unityPath = $UnityPath }
$manifest | ConvertTo-Json -Depth 5 | Set-Content -LiteralPath (Join-Path $validationDir 'unity-source-manifest.json') -Encoding utf8
$editorLog = Join-Path $validationDir 'unity-editor.log'
# Start-Process is hidden; quoted paths are necessary for this workspace's spaces.
$arguments = @('-batchmode', '-nographics', '-quit', '-projectPath', ('"' + $projectRoot + '"'), '-buildTarget', $unityBuildTarget, '-executeMethod', 'GameRegressionChecks.RunBatch', '-logFile', ('"' + $editorLog + '"'))
$checksStartedUtc = [DateTime]::UtcNow
$process = Start-Process -FilePath $UnityPath -ArgumentList $arguments -PassThru -WindowStyle Hidden
# Wait for this Editor, not every descendant: Unity can start long-lived workers/services.
Wait-OwnedEditor $process $editorLog (Join-Path $validationDir "unity-editor-checks.json") $checksStartedUtc $null
$checks = Read-FreshUnityReport (Join-Path $validationDir 'unity-editor-checks.json') $checksStartedUtc @('utc', 'unityVersion', 'passed', 'failed', 'checks')
if ($checks.failed -ne 0 -or $checks.passed -le 0 -or @($checks.checks).Count -ne ($checks.passed + $checks.failed)) { throw 'Unity regression report contains failures or an inconsistent check count.' }
if ((Get-SourceSnapshot).digest -ne $sourceDigest) { throw 'Project source changed during Editor import/checks. Inspect the diff, freeze the imported source and rerun verification.' }
if ($BuildCandidate) {
    $buildLog = Join-Path $validationDir 'unity-player-build.log'
    $buildMethod = if ($Target -eq 'Android') { 'GameRegressionChecks.BuildAndroidCandidate' } else { 'GameRegressionChecks.BuildStudyCandidate' }
    $reportName = if ($Target -eq 'Android') { 'unity-android-candidate-build.json' } else { 'unity-candidate-build.json' }
    $arguments = @('-batchmode', '-nographics', '-quit', '-projectPath', ('"' + $projectRoot + '"'), '-buildTarget', $unityBuildTarget, '-executeMethod', $buildMethod, '-logFile', ('"' + $buildLog + '"'))
    $buildStartedUtc = [DateTime]::UtcNow
    $process = Start-Process -FilePath $UnityPath -ArgumentList $arguments -PassThru -WindowStyle Hidden
    Wait-OwnedEditor $process $buildLog (Join-Path $validationDir $reportName) $buildStartedUtc $null
    $build = Read-FreshUnityReport (Join-Path $validationDir $reportName) $buildStartedUtc @('utc', 'unityVersion', 'result', 'errors', 'outputPath')
    if ($build.result -ne 'Succeeded' -or $build.errors -ne 0) { throw 'Unity candidate report did not record a successful build without errors.' }
    if (-not (Test-Path -LiteralPath $build.outputPath -PathType Leaf)) { throw 'Reported candidate artifact is missing.' }
    if ($Target -eq 'Android' -and [IO.Path]::GetExtension($build.outputPath) -ne '.apk') { throw 'Android candidate must produce an APK.' }
    if ((Get-Item -LiteralPath $build.outputPath).LastWriteTimeUtc -lt $buildStartedUtc) { throw 'Candidate artifact is stale.' }
    if ((Get-SourceSnapshot).digest -ne $sourceDigest) { throw 'Project source changed during candidate build. Inspect the diff and rerun verification against a frozen source snapshot.' }
}
@{ status = 'EDITOR CHECKS PASSED'; target = $Target; candidateBuild = $(if ($BuildCandidate) { 'PASSED' } else { 'NOT RUN' }); requiredVersion = $editorVersion; checkedPath = $UnityPath; sourceSha256 = $sourceDigest; runtimeAndHardware = 'NOT VERIFIED BY THIS SCRIPT'; generatedUtc = [DateTime]::UtcNow.ToString('O') } |
    ConvertTo-Json | Set-Content -LiteralPath $environmentReport -Encoding utf8
Write-Output 'Editor checks completed. Player interaction, visual QA and physical hardware remain separate qualification gates.'
