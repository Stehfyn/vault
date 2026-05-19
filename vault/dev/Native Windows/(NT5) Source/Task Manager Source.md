# Task Manager Source

The XP SP1 Task Manager source is a compact example of native process enumeration wrapped in a conventional Win32 UI. Its process list comes from `NtQuerySystemInformation(SystemProcessInformation)`, then the app layers sorting, refresh cadence, dialog state, and display policy on top. That makes it more useful than a bare syscall sample: it shows how native data becomes a user-facing tool.

The implementation is also a historical boundary marker. Modern Task Manager has different UI architecture and richer telemetry, but the NT system-information pattern still appears in tools such as System Informer and many process monitors. The entry belongs near NTAPI notes because Task Manager is a shell app that reaches below Toolhelp and PSAPI when it needs kernel process state.

## Connections
- `System Informer` is the modern open-source descendant of this style of tool.
- `phnt` supplies the native declarations usually needed to reproduce the enumeration cleanly.

## References
- https://github.com/tongzx/nt5src/tree/master/Source/XPSP1/NT/shell/applets/taskmgr
