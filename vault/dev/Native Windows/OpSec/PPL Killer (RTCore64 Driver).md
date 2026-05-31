# PPL Killer (RTCore64 Driver)

Red Cursor's PPLKiller is the modern canonical writeup/tooling shape for abusing a vulnerable signed driver such as RTCore64 to weaken Protected Process Light. It demonstrates the dependency chain clearly: get kernel read/write, locate the process object, alter protection metadata, then user-mode access controls no longer mean what they did.

Keep the entry defensive: this is a reminder that PPL is not a defense against an already-compromised kernel. Detection and prevention live in driver blocklists, code integrity policy, EDR kernel telemetry, and watching for suspicious access immediately after vulnerable-driver load.

Code contribution: map the chain to driver-load telemetry, device IOCTL access, process-object protection fields, and suspicious `PROCESS_VM_READ`/handle opens after PPL downgrade.

Structure-level reference for reversing writeups:

```cpp
struct ProtectedProcessObservation {
    DWORD target_pid;
    bool target_was_ppl;
    bool vulnerable_driver_loaded_first;
    bool kernel_write_primitive_present;
    bool user_mode_handle_opened_after_change;
};
```

Do not anchor detection on a single offset or driver family. The durable connection is `driver load -> kernel write capability -> protected-process metadata change -> later user-mode access`. That same shape explains Capcom-era PPL bypasses, RTCore64 variants, and newer BYOVD case studies.

## References
- <https://github.com/RedCursorSecurityConsulting/PPLKiller>
