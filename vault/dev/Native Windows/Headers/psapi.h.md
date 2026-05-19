# psapi.h

Process Status API -- the original Win32 way to enumerate processes (`EnumProcesses`), their loaded modules (`EnumProcessModulesEx`, `GetModuleBaseNameW`, `GetModuleFileNameExW`), and memory accounting (`GetProcessMemoryInfo`, `GetPerformanceInfo`, `QueryWorkingSet`). Originally a separate `psapi.dll`; Vista's `kernel32` redirected most entry points to the `K32*` aliases living in `kernel32` itself, so on modern Windows you link `psapi.lib` (an import-by-name shim) and don't actually take a `psapi.dll` dependency unless you opt in with `PSAPI_VERSION=1`. The Tool Help library (`tlhelp32.h` -- `CreateToolhelp32Snapshot`) does largely the same job with a different programming model and was the Win9x alternative; on modern Windows both work but PSAPI is generally preferred for cross-process enumeration.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/psapi/>
