"""Static serialized-asset checks. Does not load Unity or execute scene lifecycle code."""
from __future__ import annotations
import json
import re
import sys
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
checks: list[dict] = []


def check(name: str, ok: bool, details: str = "") -> None:
    checks.append({"name": name, "passed": bool(ok), "details": details})


def main() -> int:
    scripts = {}
    for meta in (ROOT / "Assets").rglob("*.cs.meta"):
        match = re.search(r"^guid: (\w+)$", meta.read_text(encoding="utf-8-sig"), re.M)
        if match:
            scripts[match.group(1)] = Path(str(meta)[:-5])
    external_script_guids = set()
    build = (ROOT / "ProjectSettings/EditorBuildSettings.asset").read_text(encoding="utf-8-sig")
    paths = re.findall(r"- enabled: 1\s+path: (.+)", build)
    check("four expected scenes enabled", set(paths) == {
        "Assets/Scenes/Boot.unity", "Assets/Scenes/MainMenu.unity", "Assets/Scenes/Game.unity", "Assets/Scenes/Results.unity"})
    for relative in paths:
        path = ROOT / relative
        check(f"scene file {path.name}", path.is_file())
        if not path.is_file():
            continue
        text = path.read_text(encoding="utf-8-sig")
        documents = {int(m.group(2)): (int(m.group(1)), m.group(3)) for m in re.finditer(
            r"^--- !u!(\d+) &(-?\d+)[^\n]*\n(.*?)(?=^--- !u!|\Z)", text, re.M | re.S)}
        by_script = {}
        for ident, (kind, body) in documents.items():
            if kind != 114:
                continue
            match = re.search(r"m_Script: \{fileID: (\d+), guid: (\w+),", body)
            check(f"{path.name} MonoBehaviour {ident} has script", match is not None and int(match.group(1)) != 0)
            if not match:
                continue
            guid = match.group(2)
            if guid in scripts:
                script = scripts[guid]
                check(f"{path.name} source {script.name}", script.is_file())
                by_script.setdefault(script.stem, []).append((ident, body))
            else:
                external_script_guids.add(guid)
        if path.stem == "Game":
            rounds = by_script.get("GameRoundController", [])
            check("one round controller", len(rounds) == 1)
            if rounds:
                for field in ("targetSpawner", "sessionTimer", "scoreSystem", "comboSystem", "hitZoneEvaluator", "inputProvider", "hudController"):
                    match = re.search(rf"^  {field}: \{{fileID: (\d+)\}}", rounds[0][1], re.M)
                    check(f"round reference {field}", match is not None and int(match.group(1)) in documents)
            pauses = by_script.get("PauseMenuController", [])
            check("one pause controller", len(pauses) == 1)
            if pauses:
                body = pauses[0][1]
                for field in ("resumeButton", "quitButton", "pausePanel"):
                    match = re.search(rf"^  {field}: \{{fileID: (\d+)\}}", body, re.M)
                    check(f"pause reference {field}", match is not None and int(match.group(1)) in documents)
                owner = re.search(r"m_GameObject: \{fileID: (\d+)\}", body)
                obj = documents.get(int(owner.group(1)), (0, "")) if owner else (0, "")
                check("pause owner serialized active", "m_IsActive: 1" in obj[1])
        expected = {"MainMenu": "DigitalDojoMenuController", "Results": "ResultsController"}.get(path.stem)
        if expected:
            check(f"{path.name} has {expected}", len(by_script.get(expected, [])) == 1)
    report = {
        "scope": "STATIC UNITY YAML REFERENCES ONLY; NOT UNITY COMPILATION OR RUNTIME VERIFICATION",
        "utc": datetime.now(timezone.utc).isoformat(),
        "passed": sum(c["passed"] for c in checks),
        "failed": sum(not c["passed"] for c in checks),
        "checks": checks,
        "external_script_guids_unverified": sorted(external_script_guids),
        "limitations": ["External/package script GUIDs require Unity import to resolve.",
                        "Serialized MainMenu concept children are not runtime screenshots.",
                        "Awake/Start, buttons, pause and scene transitions are not executed."]}
    output = ROOT / "artifacts/validation/static-scene-checks.json"
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2), encoding="utf-8")
    print(f"Static scene checks: {report['passed']} passed, {report['failed']} failed. {output}")
    for item in checks:
        if not item["passed"]:
            print("FAIL", item["name"], item["details"])
    return int(report["failed"] != 0)


if __name__ == "__main__":
    sys.exit(main())
