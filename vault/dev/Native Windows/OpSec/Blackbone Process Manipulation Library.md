# Blackbone Process Manipulation Library

Blackbone is a mature C++ process-manipulation library covering module enumeration, remote memory management, manual mapping, WOW64 edge cases, and optional kernel assist. It matters because many smaller offensive and game-cheat projects reimplement a worse subset of the same primitives.

For defensive work, it is a vocabulary builder: manual mapping leaves different artifacts than `LoadLibrary`, cross-architecture work exposes WOW64 assumptions, and kernel-assisted access changes the telemetry from user-mode handles to driver/device activity. Connect this to `Win32 Process Snippet Utilities` for the simple version and to the BYOVD/PPL entries for the kernel-backed version.

Process-manipulation API families to track when using the project as a reference:

```cpp
struct ProcessManipulationSurface {
    DWORD source_pid;
    DWORD target_pid;
    DWORD desired_access;
    bool enumerates_modules;
    bool allocates_remote_memory;
    bool changes_remote_protection;
    bool creates_or_queues_remote_execution;
    bool uses_kernel_assist;
};
```

This bridges `DLL Shellcode Injectors Catalog`, `VirtualAlloc Memory API Header`, and BYOVD notes: the same intent may surface as Win32 imports, direct NT calls, manual PE loader behavior, or driver traffic depending on which boundary the tool chooses.

## References
- <https://github.com/DarthTon/Blackbone>
