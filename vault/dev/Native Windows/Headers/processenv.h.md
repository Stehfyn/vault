# processenv.h

Process environment-strings, command line, current directory, and console-handle accessors carved out of the old monolithic `winbase.h` for the API-set / minwin refactor. `GetCommandLineW`, `GetEnvironmentStringsW` / `FreeEnvironmentStringsW`, `GetEnvironmentVariableW` / `SetEnvironmentVariableW`, `ExpandEnvironmentStringsW`, `GetCurrentDirectoryW` / `SetCurrentDirectoryW`, `GetStdHandle` / `SetStdHandle`. Two well-known traps: (1) the environment block returned by `GetEnvironmentStringsW` is a `\0`-separated list terminated by `\0\0` -- like the `OPENFILENAME` filter -- and you must call the matching `FreeEnvironmentStringsW`; (2) setting an environment variable in the current process never propagates to children that have already been started, and `SetEnvironmentVariable` does not touch HKCU/HKLM, so registry-based env edits need an explicit `SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, ..., L"Environment")` to take effect in already-running Explorer-spawned processes.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/processenv/>
