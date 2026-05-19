# windows-defender-remover - Defender Service Strip

This project is a destructive Defender-removal script set, not a normal configuration helper. Its editorial value is showing which moving parts such tools try to tamper with: Defender services, protected files, policy keys, Tamper Protection behavior, and Windows Update self-repair.

For defensive and admin review, the important point is resilience. Modern Defender is intentionally hard to remove cleanly, and attempts to strip it leave strong artifacts in service-control logs, registry policy state, file ACL changes, and failed self-healing events. Connect this to `NanaRun` because many such tools seek TrustedInstaller/SYSTEM context, and to OpSec BYOVD notes where endpoint protection is attacked below normal admin boundaries.

## References
- <https://github.com/ionuttbara/windows-defender-remover>
