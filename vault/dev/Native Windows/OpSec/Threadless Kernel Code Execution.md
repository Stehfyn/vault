# Threadless Kernel Code Execution

This research pattern avoids creating an obvious new system thread by arranging for code to run from existing kernel callback paths. The key idea is telemetry displacement: defenders that only watch thread creation miss execution that rides callbacks, notifications, or existing dispatch flows.

The defensive angle is to monitor callback registration, driver load provenance, unexpected callback density, and code regions referenced by callback pointers. Pair this with kernel exploitation resources and the stealth memory-manipulation entries; all are about where kernel activity hides when the obvious primitive is watched.

Code contribution: reason about callback registration APIs, function-pointer provenance, executable memory regions, and absence of fresh `PsCreateSystemThread` activity.

## References
- <https://github.com/zer0condition/ZeroThreadKernel>
