# Anti-Debug Check Catalog

This catalog is best treated as a taxonomy of observable anti-analysis signals, not as durable protection. It groups the standard checks: debug-port/process queries, PEB flags, heap-debug metadata, hardware breakpoint registers, hidden-thread tricks, timing skew, and debugger-window/process fingerprints.

The defensive value is mapping each check to where it can be observed or neutralized. API-level checks are easy to shim, direct PEB reads survive naive hooks, hardware-register checks require thread-context visibility, and timing checks create noisy false positives under virtualization. Connect this to `Anti-Tamper Anti-Debug Library`, `Windows Kernel Exploitation Resources`, and ETW/debugger notes when building lab detections.

Use a family map rather than memorizing function names:

```cpp
enum class AntiDebugSurface {
    ProcessDebugState,   // IsDebuggerPresent, CheckRemoteDebuggerPresent, NtQueryInformationProcess
    PebOrHeapMetadata,   // BeingDebugged, NtGlobalFlag, heap flags
    ThreadContext,       // debug registers, hidden-thread behavior
    TimingSkew,          // QueryPerformanceCounter, tick-count deltas
    EnvironmentProbe     // windows, processes, devices, VM/debugger artifacts
};
```

For reversing, log both the check and its consumer. A weak signal becomes important only when it feeds a branch that changes unpacking, decryption, feature flags, or process exit behavior.

## Discussion Claim To Verify

Claim common in anti-debug catalogs: the presence of an anti-debug check means the program is protected or malicious.

Why it matters: many checks are copied boilerplate, dead code, telemetry gates, or compatibility probes. The important fact is whether the result controls behavior.

Verification route:

```text
static pass:
  find imports/direct syscalls/PEB reads/debug-register reads
  identify the compare/test instruction consuming the result
  follow the branch to exit, decrypt, unpack, sleep, feature-disable, or no-op

dynamic pass:
  run once normally, once under debugger, once with check patched/stubbed
  diff file, registry, network, process, and module-load behavior
```

WinDbg probe shape:

```text
bp kernel32!IsDebuggerPresent
bp ntdll!NtQueryInformationProcess
ba r1 @$peb+2
g
```

Interpretation:
- Check executes and gates decryption/unpacking or process exit: high-value anti-analysis behavior.
- Check executes but its result is unused or only logged: the catalog entry is real but operationally weak.
- Static import exists but no runtime call occurs in the tested path: the source supports capability, not behavior.

## References
- <https://github.com/BaumFX/cpp-anti-debug>
