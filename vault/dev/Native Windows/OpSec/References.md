# References

This page is the defensive reading shelf for the OpSec folder. Keep links here when they are broad references rather than a single Windows primitive; move them into their own entry once the note can name the trust boundary, the relevant API family, and the observable artifacts.

## Process and Socket Boundary

The netcat process-redirection link contributes the observable shape behind bind-shell detection: socket handles or pipe handles become a child process's standard streams. Do not copy the implementation here; extract the artifact model.

```cpp
struct ChildIoObservation {
    DWORD parent_pid;
    DWORD child_pid;
    HANDLE stdin_handle;
    HANDLE stdout_handle;
    HANDLE stderr_handle;
    bool inherited_handles;
    const wchar_t* image_name;
};

bool LooksLikeRedirectedInteractiveShell(const STARTUPINFOW& si) {
    return (si.dwFlags & STARTF_USESTDHANDLES) &&
           si.hStdInput && si.hStdOutput &&
           si.hStdInput != GetStdHandle(STD_INPUT_HANDLE);
}
```

## Sensitive Win32 API Families

The offensive-cheatsheet and AbuseWin32 links are useful only if coalesced into API families: token manipulation, remote memory/thread creation, handle duplication, impersonation, registry persistence, and service creation. The defensive contribution is a coverage map, not a bag of tricks.

```cpp
enum class SensitiveFamily {
    Token,
    RemoteMemory,
    RemoteThread,
    HandleDuplication,
    Impersonation,
    Persistence,
    ServiceControl
};

SensitiveFamily ClassifyImport(std::string_view name) {
    if (name == "OpenProcessToken" || name == "AdjustTokenPrivileges") return SensitiveFamily::Token;
    if (name == "VirtualAllocEx" || name == "WriteProcessMemory") return SensitiveFamily::RemoteMemory;
    if (name == "CreateRemoteThread" || name == "NtCreateThreadEx") return SensitiveFamily::RemoteThread;
    if (name == "DuplicateHandle") return SensitiveFamily::HandleDuplication;
    if (name == "ImpersonateLoggedOnUser" || name == "RevertToSelf") return SensitiveFamily::Impersonation;
    return SensitiveFamily::Persistence;
}
```

## Input Capture Boundary

The keylogger links contribute two detection surfaces: global USER32 hooks and raw/hotkey-style input capture from a process that has no legitimate foreground UI role.

```cpp
struct InputCaptureSignal {
    DWORD pid;
    bool has_visible_top_level_window;
    bool imports_low_level_hook;
    bool imports_raw_input;
    bool writes_periodic_key_log;
};

bool SuspiciousInputCapture(const InputCaptureSignal& s) {
    return !s.has_visible_top_level_window &&
           (s.imports_low_level_hook || s.imports_raw_input) &&
           s.writes_periodic_key_log;
}
```

## PE and Reconstruction Boundary

The malware-analysis, sample-collection, and decompiler links belong with PE triage. Their code contribution is the shape of a triage record: imports, sections, timestamps, resources, and anti-analysis markers. Decompilation preserves control/data hints; it does not recover original source semantics.

```cpp
struct PeTriageRecord {
    std::vector<std::string> imported_dlls;
    std::vector<std::string> imported_functions;
    std::vector<std::string> suspicious_sections;
    bool has_tls_callbacks;
    bool has_overlay;
    bool packed_entropy_profile;
};
```

## Defensive Analysis Links
- <https://github.com/diegocr/netcat/blob/master/doexec.c> - Netcat's Windows process-redirection code is a compact reference for how socket handles, pipes, and child-process stdio get wired together. It is relevant to bind-shell detection without needing to duplicate the implementation.
- <https://github.com/matthieu-hackwitharts/Win32_Offensive_Cheatsheet> - Broad Win32 offensive API checklist covering tokens, handles, processes, and persistence. Use it to build defensive coverage maps against API families rather than to cargo-cult snippets.
- <https://github.com/un4ckn0wl3z/AbuseWin32> - Documentation of security-sensitive Win32 patterns such as handle duplication, impersonation, and process enumeration. Useful for seeing how legitimate primitives become abuse paths.
- <https://github.com/safesploit/C_keylogger> - Low-level keyboard-hook keylogger example. Keep for detection thinking around `WH_KEYBOARD_LL`, suspicious hook owners, and non-UI processes observing input.
- <https://github.com/boned101/portable-keylogger> - Portable keylogger reference showing why single-binary input capture often avoids installation footprints. Relevant to Raw Input and global-hook monitoring.
- <https://github.com/bats3c/shad0w> - C2 framework reference for studying beacon/tasking architecture, staging choices, and operator workflow at a high level.
- <https://github.com/jstrosch/learning-malware-analysis> - Malware-analysis training material covering PE structure, imports, anti-analysis behavior, and detection-rule thinking.
- <https://github.com/MinhasKamal/CuteVirusCollection> - Historical malware sample collection for isolated lab analysis. Its value is taxonomy and behavior comparison, not execution.
- <https://github.com/wyrover/ExeToC-Decompiler> - Decompiler reference for understanding what PE-to-C reconstruction preserves, distorts, and loses.
- <https://www.amazon.com/Writing-Secure-Second-Developer-Practices/dp/0735617228> - Secure development practices reference; dated in places, but still useful for threat-model vocabulary and defensive coding habits.

## Connections
- `Win32 Bind Shell Reference` covers the process/socket pattern from the netcat link.
- `Input` entries cover the keylogger-related hook and Raw Input surfaces.
- `Blackbone Process Manipulation Library` and `Win32 Process Snippet Utilities` cover the process/handle side of the cheat sheets.
