# Enumerating Threads in a Process

This example demonstrates the ToolHelp thread snapshot pattern: take a system-wide thread snapshot, iterate `THREADENTRY32`, and filter by owner process ID. The awkwardness is intentional: Win32 does not expose "enumerate threads for this process" as a single high-level call.

Use it as the baseline before reaching for heavier process libraries. It connects to `Threaded Message Queue`, `Win32 Process Snippet Utilities`, and debugger/profiler code where thread IDs, GUI queues, and process ownership must be correlated.

## References
- <https://learn.microsoft.com/en-us/windows/win32/toolhelp/traversing-the-thread-list>
