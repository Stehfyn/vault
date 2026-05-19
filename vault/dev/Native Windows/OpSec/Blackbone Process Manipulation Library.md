# Blackbone Process Manipulation Library

Blackbone is a mature C++ process-manipulation library covering module enumeration, remote memory management, manual mapping, WOW64 edge cases, and optional kernel assist. It matters because many smaller offensive and game-cheat projects reimplement a worse subset of the same primitives.

For defensive work, it is a vocabulary builder: manual mapping leaves different artifacts than `LoadLibrary`, cross-architecture work exposes WOW64 assumptions, and kernel-assisted access changes the telemetry from user-mode handles to driver/device activity. Connect this to `Win32 Process Snippet Utilities` for the simple version and to the BYOVD/PPL entries for the kernel-backed version.

## References
- <https://github.com/DarthTon/Blackbone>
