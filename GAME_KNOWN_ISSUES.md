# Known issues — 15 September 2026

- No ADB device is available. New APK installation, permission recovery, BLE removal/re-pair/swap, reconnect, actual punch/kick delivery and measured references require hardware. User-observed launch/discovery/ALPHA pairing concerns the earlier APK.
- Mixed ALPHA + DELTA / third sensor is blocked: SDK pairing/session ownership does not establish supported independent concurrent acquisition. Raw API Java compilation is not proof of concurrent hardware operation. See MULTI_SENSOR_REPORT.md.
- Unknown SDK family remains visible but blocks preparation until identified; no family guess from SG advertising names. Firmware attachable detection and single ALPHA start require device verification.
- COMPATIBILITY explicitly substitutes missing Resource 2.11.1 with 2.12.0 and uses the documented local adapter. Vendor binaries are unchanged; an official corrected package is preferable. VENDOR-UNCHANGED remains blocked.
- Unity SearchDatabase raises an editor startup ArgumentOutOfRangeException on this machine. It did not prevent the recorded Play Mode completion. This is not claimed fixed; inspect the final editor/build logs separately.
- Corrupt profile files are preserved and refused; automatic repair/recovery UI is not implemented. Profile archiving is supported, permanent deletion is not. History retains the existing global 200-summary limit.
- Uncalibrated actions use neutral gameplay strength, explicitly invalid for normalization. References and thresholds are unqualified game parameters, not clinical measurements. Body measurements do not modify force or heart-rate adaptation.
- Measured speed references are stored and displayed separately; adaptive speed/difficulty based on them remains unqualified. No fabricated calibration is bundled.
- Visual validation is synthetic Editor rendering at four landscape sizes, not on-device frame pacing, thermals or display qualification.

- Final Android build succeeded with 17 C# warnings: 15 deprecated object lookup calls and two unused serialized HitZoneEvaluator fields. These warnings remain; zero build errors.
