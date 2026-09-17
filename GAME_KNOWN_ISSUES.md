# Known issues — 17 September 2026

- Fitness pacing checks use synthetic input. Global alternating spacing can reach .18 s, with the existing .35 s per-device refractory preserved and kick intervals at least .55 s. Bluetooth/event/display latency and achievable cadence must still be measured on hardware.
- Exact concept-art parity is not achieved: room proportions are stretched to the gameplay volume; plants and panel fracture remain simplified. See ROOM_VALIDATION_REVIEW.md. Historical all-false plugin gates were not relabelled as passed.
- Pacing does not consume measured rapid references; the dead experimental flag has been removed. Device performance, thermals and sustained high-speed readability remain open until hardware testing.

- Latest-build physical device qualification is unavailable in the recorded evidence. New APK installation, permission recovery, BLE removal/re-pair/swap, reconnect, actual punch/kick delivery and measured references require hardware. User-observed launch/discovery/ALPHA pairing concerns the earlier APK.
- Mixed ALPHA + DELTA / third sensor is blocked: SDK pairing/session ownership does not establish supported independent concurrent acquisition. Raw API Java compilation is not proof of concurrent hardware operation. See MULTI_SENSOR_REPORT.md.
- Unknown SDK family remains visible but blocks preparation until identified; no family guess from SG advertising names. Firmware attachable detection and single ALPHA start require device verification.
- COMPATIBILITY explicitly substitutes missing Resource 2.11.1 with 2.12.0 and uses the documented local adapter. Vendor binaries are unchanged; an official corrected package is preferable. VENDOR-UNCHANGED remains blocked.
- A historical Unity SearchDatabase startup ArgumentOutOfRangeException was observed on this machine; recurrence in the latest build is not established. It did not prevent the recorded Play Mode completion. This is not claimed fixed; inspect the final editor/build logs separately.
- Corrupt profile files are preserved and refused; automatic repair/recovery UI is not implemented. Profile archiving is supported, permanent deletion is not. History retains the existing global 200-summary limit.
- Uncalibrated actions use neutral gameplay strength, explicitly invalid for normalization. References and thresholds are unqualified game parameters, not clinical measurements. Body measurements do not modify force or heart-rate adaptation.
- Measured speed references are stored and displayed separately; adaptive speed/difficulty based on them remains unqualified. No fabricated calibration is bundled.
- Visual validation is synthetic Editor rendering at four landscape sizes, not on-device frame pacing, thermals or display qualification.

- Older 1.3 build warning counts are historical. The current Unity/Android build has zero errors and 20 warnings, recorded in `artifacts/validation/unity-android-candidate-build.json`. Target and healthbar objects still instantiate; mount/effect caches are bounded. Device GC/frame/thermal profiling remains open.

Latest fast pacing/no-overtake implementation has compile/build evidence only; runtime arrival ordering and delivered cadence still require verification. Central remaining-work checklist: [TODO.md](TODO.md). Technique recognition/calibration, Block/Parry and camera tracking are not implemented.
