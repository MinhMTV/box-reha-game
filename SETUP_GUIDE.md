# Setup and qualification — 17 September 2026

Open the existing `E:/Programming Projekte/box-reha-game` with Unity **6000.6.1f1** (the originally targeted 6000.6.0f1 is superseded; see [ANDROID_STATUS.md](ANDROID_STATUS.md)) and matching Android Build Support/SDK/NDK/OpenJDK. Do not regenerate scenes or create a replacement project. Windows is the development host; the complete Unity game and SDK run on Android without a relay.

## Development
Open `Assets/Scenes/Boot.unity`. Runtime MainMenu replaces historical serialized concept UI. Development keys: Left/Right arrows = punches; A/D = kicks; ESC or touch PAUSE; Finish & Results ends a round. Profiles, references and history use actual local state. See [CURRENT_GAMEPLAY.md](CURRENT_GAMEPLAY.md).

## Build/check entry points
These are instructions for future execution; this documentation pass ran none of them.

```powershell
dotnet run --project tests/sensor/SensorHostChecks.csproj --configuration Release
dotnet run --project tests/syntax/SyntaxChecks.csproj -- .
python tests/check_scene_assets.py
.\scripts\verify-unity.ps1 -UnityPath "C:\Program Files\Unity\Hub\Editor\6000.6.1f1\Editor\Unity.exe" -SdkMode COMPATIBILITY -BuildCandidate
```

Use the actual installed Editor path. Host fixtures are synthetic and use narrow Unity stubs. The Unity wrapper prepares settings, records source identity and performs checks/build; it does not qualify BLE or human performance. Default SDK mode is VENDOR-UNCHANGED and still hits the missing resource 2.11.1 dependency; choose COMPATIBILITY explicitly for the existing successful path. It uses resource 2.12.0 plus the pinned Java/reflection adapter. [SDK_COMPATIBILITY_REPORT.md](SDK_COMPATIBILITY_REPORT.md).

Current output: `Builds/AndroidCandidate/DigitalDojo.apk`, ARM64/IL2CPP, min API 26, target/compile API 36. Exact latest identity and dated build evidence: [ANDROID_STATUS.md](ANDROID_STATUS.md). Historical source/signature reports must not be reused for a different APK hash.

## Physical setup
1. Confirm device ABI/OS, enable USB debugging and authorize the host; install the identified APK without unnecessarily removing existing profile data.
2. Initialize SDK, grant permissions, scan, inspect actual device names and assign actual Left/Right sides. Unknown family remains visible but blocks readiness. Use confirmed Remove/re-pair or pair-aware side swap for corrections.
3. Select/create a local participant and explicitly supply SDK-required body profile fields. SDK ranges: weight 20–250 kg, height 50–250 cm, gender MALE/FEMALE. These are SDK prerequisites, not force calibration; collect only under the agreed study procedure.
4. Choose ALPHA Punch or experimental DELTA Kick. One same-family device or Left/Right pair is allowed; only connected sides are used. DELTA includes Heavy Kick but excludes Punch rapid-chain behavior. Mixed/third/fourth devices remain blocked.
5. Start only after matching profile/family/session acknowledgement. Strong/Rapid collection requires fresh valid physical events; no button creates a baseline. Test references, profile switching, TOO LIGHT and persistence.
6. Check pause/resume, connection loss, background/reconnect, end-session recovery and prolonged use. Record actual device/firmware, source/config/APK identity and input provenance.

There is no qualified physical sensor result yet. Follow [TODO.md](TODO.md) for the full hardware sequence. Raw technique recording/classification and active HR are not current functions.

## Data and study boundary
`Application.persistentDataPath` contains profiles, calibration references/audits, session history and research JSONL. SDK body/session storage is separate. Game research logs exclude names/body values; configure controlled export/access/retention across all stores. See [PROFILE_DATA_MODEL.md](PROFILE_DATA_MODEL.md) and [RESEARCH_LOG_SCHEMA.md](RESEARCH_LOG_SCHEMA.md). A build pass is not study readiness.
