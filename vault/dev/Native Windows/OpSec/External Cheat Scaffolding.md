# External Cheat Scaffolding

External cheat scaffolds are useful to defenders because they show the lowest-friction path: enumerate processes/modules, obtain a target handle, read state, write state if permitted, and synthesize input. They avoid injection, which means fewer in-process artifacts but stronger dependence on handle rights and predictable target memory layouts.

Detection thinking should start with process access patterns, repeated reads against game processes, foreground/input anomalies, and unsigned tools that combine ToolHelp snapshots with VM access. Pair this with `Mouse Input`, `Win32 Process Snippet Utilities`, and kernel-driver entries that appear when user-mode rights are blocked.

Benign-looking baseline APIs that become distinctive in combination:

```cpp
HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE, 0);
HANDLE proc = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION | PROCESS_VM_READ,
                          FALSE, target_pid);
BOOL read = ReadProcessMemory(proc, address, buffer, size, &bytes_read);
UINT sent = SendInput(input_count, inputs, sizeof(INPUT));
```

None of those calls is inherently malicious. The connection worth preserving is cadence and target context: polling another interactive process, reading stable in-process state, and synthesizing input from a tool that is not the foreground application.

## References
- <https://github.com/nbqofficial/norsefire>
