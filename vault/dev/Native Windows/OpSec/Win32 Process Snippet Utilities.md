# Win32 Process Snippet Utilities

`pwned` is a small grab bag of process-enumeration and process-manipulation snippets. Its editorial value is as the plain Win32 baseline: ToolHelp snapshots, process handles, module walks, and simple utility code before heavier frameworks such as Blackbone appear.

For defensive readers, these snippets identify the API calls commodity tools reach for first. That makes them useful for lab telemetry and for distinguishing ordinary inventory utilities from tools that escalate into remote memory, injection, or token manipulation.

Plain Win32 baseline:

```cpp
CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
Process32FirstW(snapshot, &process_entry);
OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid);
EnumProcessModules(process, modules, sizeof(modules), &needed);
```

This entry is the control group for heavier notes. If a tool stops at enumeration, it belongs with inventory and diagnostics; if it adds remote allocation, remote writes, handle duplication, or driver-backed access, follow the route to `Blackbone Process Manipulation Library`, `DLL Shellcode Injectors Catalog`, or the BYOVD cluster.

## Source Code Reading

The linked `nurettin/pwned` repository currently does not appear to contain focused Win32 process-enumeration source despite the note's name. A source-code pass should not invent details from an unrelated tree. Keep the link, but do not cite it as evidence for ToolHelp/process-handle utilities until the target is corrected.

The actionable baseline is the first-party API contract:

```text
CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)
  -> Process32FirstW / Process32NextW
  -> collect PID, parent PID, image name

OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, pid)
  -> QueryFullProcessImageNameW
  -> CloseHandle

OpenProcess(PROCESS_VM_READ, FALSE, pid)
  -> expected to fail for protected/higher-integrity/system targets
```

Test it as an access-rights matrix, not as a memory-manipulation demo:

```cpp
struct ProbeMask { DWORD mask; const wchar_t* name; };
ProbeMask probes[] = {
  { PROCESS_QUERY_LIMITED_INFORMATION, L"query_limited" },
  { PROCESS_QUERY_INFORMATION,         L"query" },
  { PROCESS_VM_READ,                   L"vm_read" },
  { SYNCHRONIZE,                       L"synchronize" }
};
```

Verifiable assertions to drive:

```text
claim: minimal query rights succeed more often than broad rights
probe: run the matrix across same-user, elevated, service, PPL, and system processes

claim: access denied is useful boundary data
probe: log PID, image, integrity, requested mask, success, and `GetLastError`

claim: this note is a control group
probe: ensure the harness never calls remote allocation, remote write, or thread creation APIs
```

Source status:
- `nurettin/pwned` cloned and inspected.
- No relevant `OpenProcess`, `CreateToolhelp32Snapshot`, `Process32First`, `EnumProcesses`, or `QueryFullProcessImageName` usage found in that tree.

## Experiment Harness

Goal: measure process-handle access boundaries without touching remote memory.

Procedure:

```cpp
DWORD masks[] = {
    PROCESS_QUERY_LIMITED_INFORMATION,
    PROCESS_QUERY_INFORMATION,
    PROCESS_VM_READ,
    PROCESS_VM_OPERATION | PROCESS_VM_WRITE,
    PROCESS_ALL_ACCESS
};

for (DWORD mask : masks) {
    HANDLE h = OpenProcess(mask, FALSE, pid);
    printf("pid=%lu mask=0x%08lx ok=%d gle=%lu\n",
           pid, mask, h != nullptr, h ? ERROR_SUCCESS : GetLastError());
    if (h) CloseHandle(h);
}
```

Signals to record: target image name, integrity level if available, requested mask, success/failure, `GetLastError`, and whether the target is a protected/system process. Expected baseline: ordinary same-user processes should usually allow `PROCESS_QUERY_LIMITED_INFORMATION`; system, CSRSS, protected, or higher-integrity targets commonly fail stronger masks with `ERROR_ACCESS_DENIED`. Treat `PROCESS_ALL_ACCESS` failures as useful data, not a reason to broaden privilege; Microsoft explicitly recommends requesting the minimum required rights.

## Discussion Claim Verification

Claim: "The linked snippet repository is evidence for Win32 process-enumeration utilities."

Why it matters for new diagnostic code: a weak link poisons the note. The useful diagnostic experiment here is first-party process-access behavior, not an unrelated repository citation.

How to verify:
1. Keep the `nurettin/pwned` link for provenance, but do not cite it for ToolHelp or `OpenProcess` until relevant source is present.
2. Build a local access-rights matrix around Microsoft-documented process access rights.
3. Run it from standard and elevated shells against same-user, service, system, and protected-process targets.
4. Record only handle-open outcomes and metadata; do not add remote memory or thread operations.

Minimal code/pseudocode:

```cpp
for pid in enumerate_processes():
  for mask in [PROCESS_QUERY_LIMITED_INFORMATION,
               PROCESS_QUERY_INFORMATION,
               PROCESS_VM_READ,
               PROCESS_ALL_ACCESS]:
    HANDLE h = OpenProcess(mask, FALSE, pid);
    log(pid, mask, h != nullptr, h ? 0 : GetLastError());
    if (h) CloseHandle(h);
```

Interpretation: nullified contribution: `https://github.com/nurettin/pwned` was inspected and does not currently support the note's claimed process-enumeration content. Supported contribution: Microsoft `OpenProcess` and process-access-rights documentation define the falsifiable access matrix. Keep this entry defensive and diagnostic.

## References
- <https://github.com/nurettin/pwned>
- <https://learn.microsoft.com/en-us/windows/win32/api/processthreadsapi/nf-processthreadsapi-openprocess>
- <https://learn.microsoft.com/en-us/windows/win32/procthread/process-security-and-access-rights>
