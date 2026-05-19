# TotalSystem - Unified Windows System Explorer

Pavel Yosifovich's TotalSystem is a native Windows inspection tool that collapses several Sysinternals/System Informer-style views into one process: processes, threads, handles, modules, memory, object-manager namespaces, kernel objects, and GPU/system detail. The code is useful because it demonstrates the normal Windows tooling split: documented UI and setup APIs for presentation, paired with native/NT queries such as `NtQuerySystemInformation` when the public Win32 layer does not expose enough state.

Place this next to NTAPI, ETW, and Process Hacker/System Informer notes. It is not merely "a system explorer"; it is a worked example of how much Windows diagnostic software depends on buffer-retry enumeration patterns, privilege-sensitive object names, unstable information classes, and graceful degradation when a query fails on a different build.

## References
- <https://github.com/zodiacon/TotalSystem> - source for a broad native Windows system-inspection application.
