# TotalSystem - Unified Windows System Explorer

Pavel Yosifovich's TotalSystem is a native Windows inspection tool that collapses several Sysinternals/System Informer-style views into one process: processes, threads, handles, modules, memory, object-manager namespaces, kernel objects, and GPU/system detail. The code is useful because it demonstrates the normal Windows tooling split: documented UI and setup APIs for presentation, paired with native/NT queries such as `NtQuerySystemInformation` when the public Win32 layer does not expose enough state.

Place this next to NTAPI, ETW, and Process Hacker/System Informer notes. It is not merely "a system explorer"; it is a worked example of how much Windows diagnostic software depends on buffer-retry enumeration patterns, privilege-sensitive object names, unstable information classes, and graceful degradation when a query fails on a different build.

## Verification Route

Claim to verify: a unified system explorer can reconstruct process/thread/handle/module state mostly from query APIs.

Why it matters: the harder claim is freshness and privilege, not enumeration. `NtQuerySystemInformation` snapshots race process exit, handles can disappear between rows, and object names often require extra access rights or timeouts.

Probe shape:

```cpp
ULONG bytes = 1 << 20;
std::vector<BYTE> buffer(bytes);
NTSTATUS st = NtQuerySystemInformation(SystemProcessInformation,
                                       buffer.data(), bytes, &bytes);
while (st == STATUS_INFO_LENGTH_MISMATCH) {
    buffer.resize(bytes + (1 << 20));
    st = NtQuerySystemInformation(SystemProcessInformation,
                                  buffer.data(), (ULONG)buffer.size(), &bytes);
}
```

Verification route:

```powershell
tasklist /v > tasklist.txt
handle.exe -a > handles.txt
```

Interpretation:
- Counts differ slightly between tools: snapshot race, privilege, and filtering are expected.
- Query fails only without elevation/debug privilege: the source supports graceful degradation, not omniscient inspection.
- Handle names hang or are missing: object-name resolution is a second query path with its own blocking and access behavior.

## References
- <https://github.com/zodiacon/TotalSystem> - source for a broad native Windows system-inspection application.
