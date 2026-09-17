param([string]$Pass = 'Hardware-Feedback')
$ErrorActionPreference='Stop'
$project=Split-Path -Parent $PSScriptRoot
$env:DOJO_CAPTURE_PASS=$Pass
$env:DYNAMICS_SDK_MODE='COMPATIBILITY'
$editor='C:\Program Files\Unity\Hub\Editor\6000.6.0f1\Editor\Unity.exe'
$log=Join-Path $project 'artifacts\validation\hardware-playmode-final.log'
$started=[DateTime]::UtcNow
$owned=Start-Process -FilePath $editor -ArgumentList @('-batchmode','-projectPath',('"'+$project+'"'),'-buildTarget','Android','-executeMethod','DigitalDojoCapture.Run','-logFile',('"'+$log+'"')) -WindowStyle Hidden -PassThru
$forced=$false
while(-not $owned.HasExited -and ([DateTime]::UtcNow-$started).TotalMinutes -lt 12){Start-Sleep -Seconds 3;$owned.Refresh()}
if(-not $owned.HasExited){$owned.Kill();$forced=$true}
$success=(-not $forced) -and $owned.ExitCode -eq 0 -and (Select-String -LiteralPath $log -SimpleMatch 'DIGITAL_DOJO_CAPTURE_COMPLETE' -Quiet)
@{startedUtc=$started.ToString('O');finishedUtc=[DateTime]::UtcNow.ToString('O');processId=$owned.Id;exitCode=$owned.ExitCode;forced=$forced;passed=$success;log=$log} | ConvertTo-Json | Set-Content (Join-Path $project 'artifacts\validation\hardware-playmode-process.json')
if(-not $success){throw 'Play Mode capture/checks did not complete successfully; inspect hardware-playmode-final.log'}
Write-Output 'Play Mode checks and captures passed; physical hardware remains a separate test.'
