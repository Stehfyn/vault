# getconkbl — Console Keyboard Layout Probe

Pre-Win10 trick for discovering the active keyboard layout (HKL) of a console process. The non-obvious gotcha: a console app doesn't own its own input — `conhost.exe` does — so `GetKeyboardLayout(GetCurrentThreadId())` lies. The technique walks back to the conhost that owns the console, then either injects/IPCs in or queries via `GetWindowThreadProcessId` on the console window plus `GetGUIThreadInfo` to figure out which thread is processing input, and finally calls `GetKeyboardLayout` against *that* thread. Strictly Windows 7-era; on Win10+ conhost can be ConPTY-hosted and this falls apart.

## Source Shape

The useful pattern is "ask the GUI thread that owns the console window," not "ask my current thread."

```cpp
HWND console = GetConsoleWindow();
DWORD process_id = 0;
DWORD thread_id = GetWindowThreadProcessId(console, &process_id);

GUITHREADINFO gui = { sizeof(gui) };
GetGUIThreadInfo(thread_id, &gui);

HKL layout = GetKeyboardLayout(thread_id);
```

## Source Code Reading

The linked repository does not actually use the simplified `GetConsoleWindow` route above as its main implementation. Its Windows 7-era code walks conhost ownership because the console window belongs to a hosting process.

`getlayout/getlayout.cpp` is the CLI probe. It parses a console app PID, calls `GetConhostInit`, optionally enables debug privilege, calls `FindConhost(&conhost_count)`, picks the matching host with `GetRelevantPID(conhost, conhost_count, console_pid)`, enumerates host threads with `GetThreads(conhost_pid)`, and prints `GetKeyboardLayout(threadId)` for each thread.

`getconkbl/getconkbl.cpp` turns the same logic into a DLL API:

```cpp
Initialize(debug):
    GetConhostInit()
    optional EnableSeDebug()
    Init = TRUE

GetConsoleAppKbLayout(console_pid):
    conhost = FindConhost(&count)
    conhost_pid = GetRelevantPID(conhost, count, console_pid)
    threads = GetThreads(conhost_pid)
    return GetKeyboardLayout(threads[1])
```

The buried detail is the `threads[1]` assumption. The source comments say the second enumerated conhost thread appears to be the relevant one for `GetKeyboardLayout`, even if it is not the numerically second-lowest TID. That is a brittle empirical rule, not a documented API guarantee. The actionable experiment is to print all thread IDs/layouts, change the console input language, and observe which thread's `HKL` changes.

The implementation also shows why this belongs near HWND/thread inspection notes: the result is an `HKL` attached to a GUI/input thread, not a process-wide console setting. Treat any helper named `GetConsoleKeyboardLayout(pid)` as suspect until it explains how it chooses the conhost and thread.

## Verification Route

Claim: the source's `threads[1]` selection is an empirical Windows 7-era observation, not a documented console keyboard-layout contract.

Why it matters for new code: code that chooses one conhost thread by enumeration order will fail silently when conhost internals, ConPTY hosting, Terminal, or input-language behavior changes. A new helper should report the evidence it used to choose the thread.

How to verify:

- Enumerate every thread in the selected conhost process and print `threadId -> HKL`.
- Change the active input language while the console has focus and repeat the scan.
- Compare against `GetWindowThreadProcessId(GetConsoleWindow(), &pid)` and `GetGUIThreadInfo` where available.

Minimal code/pseudocode:

```text
for tid in EnumerateThreads(conhost_pid):
    HKL hkl = GetKeyboardLayout(tid)
    printf("%lu %p%s\n", tid, hkl, tid == console_window_tid ? " window" : "")

// Choose the thread whose HKL changes with focused console input, not threads[1].
```

Interpretation: if several threads report different or stale layouts, the old shortcut is nullified for that machine. If exactly one thread changes with focused console input, record the selection rule that found it; do not preserve the ordinal assumption.

## References
- <https://github.com/Elfy/getconkbl>

## Connections
- `Mouse Input.md` has the same thread/window ownership premise for cursor and client coordinates.
- `../Message Queue/System-Defined Messages.md` explains why input belongs to a GUI thread's queue.
- `../Hooks/WinSpy++ - Open-Source Spy++ Clone.md` is the adjacent inspection route for HWND/thread/process relationships.
