# getconkbl — Console Keyboard Layout Probe

Pre-Win10 trick for discovering the active keyboard layout (HKL) of a console process. The non-obvious gotcha: a console app doesn't own its own input — `conhost.exe` does — so `GetKeyboardLayout(GetCurrentThreadId())` lies. The technique walks back to the conhost that owns the console, then either injects/IPCs in or queries via `GetWindowThreadProcessId` on the console window plus `GetGUIThreadInfo` to figure out which thread is processing input, and finally calls `GetKeyboardLayout` against *that* thread. Strictly Windows 7-era; on Win10+ conhost can be ConPTY-hosted and this falls apart.

## References
- <https://github.com/Elfy/getconkbl>
