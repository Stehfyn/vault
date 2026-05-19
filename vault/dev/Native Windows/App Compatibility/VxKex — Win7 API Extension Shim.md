# VxKex - Win7 API Extension Shim

VxKex is a per-process compatibility layer for running applications that import APIs newer than Windows 7. Its strength is containment: instead of replacing system DLLs globally, it uses shim registration/loader indirection so selected executables see compatibility implementations for missing functions.

This is the clean middle ground between `YY-Thunks` and `OneCoreAPI`. Static thunks require rebuilding the application, OneCoreAPI changes the OS surface globally, and VxKex tries to make the loader lie only for marked processes. The hard part is not adding one export; it is matching enough behavior that modern Electron, UCRT, or .NET-era applications get past startup and keep working.

## References
- <https://github.com/i486/VxKex>
