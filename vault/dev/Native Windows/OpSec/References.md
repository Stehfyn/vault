# References

Defensive Windows opsec and secure-coding references. The snippet below enables DEP as a baseline mitigation in-process.

```cpp
#include <windows.h>

PROCESS_MITIGATION_DEP_POLICY dep = {};
dep.Enable = 1;
dep.Permanent = 1;
SetProcessMitigationPolicy(ProcessDEPPolicy, &dep, sizeof(dep));
```

## References
- https://github.com/diegocr/netcat/blob/master/doexec.c — Netcat variant implementation showing a Windows shell session wired through pipes and Winsock.
- https://github.com/safesploit/C_keylogger — C-based Windows keylogger project (reference only; no code excerpts).
- https://www.amazon.com/Writing-Secure-Second-Developer-Practices/dp/0735617228 

https://github.com/matthieu-hackwitharts/Win32_Offensive_Cheatsheet
Offensive Win32 reference covering token manipulation, privilege escalation patterns, and OPSEC considerations. Useful as a study guide for understanding Windows security mechanisms from the attacker's perspective.
```cpp
// Token privilege manipulation pattern
HANDLE token = nullptr;
OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token);
TOKEN_PRIVILEGES tp = {};
tp.PrivilegeCount = 1;
LookupPrivilegeValueA(nullptr, "SeDebugPrivilege", &tp.Privileges[0].Luid);
tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
AdjustTokenPrivileges(token, FALSE, &tp, 0, nullptr, nullptr);
CloseHandle(token);
```

https://github.com/un4ckn0wl3z/AbuseWin32
Win32 security-relevant API abuse documentation covering handle duplication, token impersonation, and process enumeration patterns useful for understanding detection opportunities.
```cpp
// Duplicate a handle into a target process
HANDLE hTarget = OpenProcess(PROCESS_DUP_HANDLE, FALSE, targetPid);
HANDLE hDup = nullptr;
DuplicateHandle(hTarget, sourceHandle, GetCurrentProcess(),
    &hDup, PROCESS_ALL_ACCESS, FALSE, 0);
// hDup is now a local handle with PROCESS_ALL_ACCESS to the target
CloseHandle(hTarget);
CloseHandle(hDup);
```

https://github.com/safesploit/C_keylogger
Low-level keyboard hook keylogger for defensive analysis. Uses WH_KEYBOARD_LL with GetAsyncKeyState / GetKeyNameTextW for readable key names. Detection: scan for SetWindowsHookEx(WH_KEYBOARD_LL) in unknown processes.
```cpp
// Low-level keyboard hook for monitoring (defensive research)
HHOOK g_hook = nullptr;
LRESULT CALLBACK LLKeyProc(int code, WPARAM wParam, LPARAM lParam) {
  if (code == HC_ACTION && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)) {
    KBDLLHOOKSTRUCT* kb = (KBDLLHOOKSTRUCT*)lParam;
    wchar_t name[32] = {};
    LONG scanCode = (kb->scanCode << 16) | (kb->flags & LLKHF_EXTENDED ? (1<<24) : 0);
    GetKeyNameTextW(scanCode, name, ARRAYSIZE(name));
    OutputDebugStringW(name);
  }
  return CallNextHookEx(g_hook, code, wParam, lParam);
}
g_hook = SetWindowsHookExW(WH_KEYBOARD_LL, LLKeyProc, nullptr, 0);
```

https://github.com/boned101/portable-keylogger
Study in how portable keyloggers minimize their footprint — no install, single binary, may use raw input or global hooks. Detection vector: RegisterRawInputDevices with RIDEV_INPUTSINK from non-UI processes.
```cpp
// Raw input approach for stealthy keyboard monitoring (study only)
RAWINPUTDEVICE rid = {};
rid.usUsagePage = 0x01;   // Generic Desktop Controls
rid.usUsage     = 0x06;   // Keyboard
rid.dwFlags     = RIDEV_INPUTSINK;  // receive input even when not focused
rid.hwndTarget  = hwnd;
RegisterRawInputDevices(&rid, 1, sizeof(rid));
// WM_INPUT messages arrive in hwnd's message loop
```

https://github.com/bats3c/shad0w
shad0w is a C2 framework for red-team operations. Study the implant architecture for understanding command channels, staging, and in-memory execution patterns used in modern offensive tooling.
```cpp
// Reflective DLL loading pattern (used by many C2 implants)
typedef PVOID (WINAPI *ReflectiveDllMain_t)(PVOID, DWORD, PVOID);
// After mapping the DLL image in memory:
// 1. Fix up relocations
// 2. Resolve imports
// 3. Call the entry point as a function pointer
// No LoadLibrary involved — evades module enumeration
```

https://github.com/jstrosch/learning-malware-analysis
Malware analysis learning materials: PE header parsing, IAT hooking detection, anti-analysis tricks, and behavioral signatures. Excellent for defenders learning to write YARA rules and detection logic.
```cpp
// FNV-1a hash for API name resolution (common in malware)
static uint32_t Fnv1a(const char* s) {
  uint32_t h = 2166136261u;
  for (; *s; ++s) h = (h ^ (uint8_t)*s) * 16777619u;
  return h;
}
// Malware resolves exports by hash to avoid string artifacts
// Detection: scan for GetProcAddress with computed values, or
//            PEB traversal without string literals
```

https://github.com/MinhasKamal/CuteVirusCollection
Virus sample collection for malware analysis training in controlled lab environments. Do not execute outside an isolated VM. Useful for understanding historical propagation mechanisms.
```cpp
// Defensive: detect file-infecting executable by checking for modified timestamps
WIN32_FILE_ATTRIBUTE_DATA fa = {};
GetFileAttributesExW(L"C:\\target.exe", GetFileExInfoStandard, &fa);
FILETIME created  = fa.ftCreationTime;
FILETIME modified = fa.ftLastWriteTime;
// Infection: ftLastWriteTime newer than expected without legitimate update
```

https://github.com/wyrover/ExeToC-Decompiler
Decompiler that converts x86 executables to C-like pseudocode. Reference for understanding decompiler output artifacts and how code patterns survive compilation.
```cpp
// Reading PE headers directly — what decompilers start from
IMAGE_DOS_HEADER* dos = (IMAGE_DOS_HEADER*)module;
IMAGE_NT_HEADERS* nt  = (IMAGE_NT_HEADERS*)((BYTE*)module + dos->e_lfanew);
IMAGE_SECTION_HEADER* sec = IMAGE_FIRST_SECTION(nt);
for (WORD i = 0; i < nt->FileHeader.NumberOfSections; ++i, ++sec) {
  printf("Section: %.8s  VA: %08X  Size: %08X\n",
      sec->Name, sec->VirtualAddress, sec->SizeOfRawData);
}
```
— “Writing Secure Code, Second Edition,” a secure development practices reference.
