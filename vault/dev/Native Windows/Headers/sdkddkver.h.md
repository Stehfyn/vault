# sdkddkver.h

The header that decides which APIs your TU sees. Defines `_WIN32_WINNT_*` (NT version constants -- `_WIN32_WINNT_WINXP=0x0501`, `_WIN32_WINNT_VISTA=0x0600`, `_WIN32_WINNT_WIN7=0x0601`, `_WIN32_WINNT_WIN8=0x0602`, `_WIN32_WINNT_WINBLUE=0x0603`, `_WIN32_WINNT_WIN10=0x0A00`) and `NTDDI_*` (a finer-grained 32-bit "major.minor.servicepack.subversion" code: `NTDDI_WIN10_RS5`, `NTDDI_WIN10_19H1`, `NTDDI_WIN10_VB`, `NTDDI_WIN10_NI`, `NTDDI_WIN11_*`, ...). The SDK headers gate API declarations with `#if (NTDDI_VERSION >= NTDDI_WIN10_RS5)` -- set the target version too low and a perfectly-shipping API simply doesn't exist as far as the compiler is concerned. Set it too high and you get binaries that fail to load on the older OS. The convention: define `WINVER`, `_WIN32_WINNT`, and `NTDDI_VERSION` before *any* SDK include, ideally in the project / preprocessor settings rather than per-file.

## Target Gate Pattern

This is a compile-time declaration gate, not a deployment guarantee. If a binary must run on older Windows while using newer APIs opportunistically, keep the header target honest and resolve the optional call through `GetProcAddress` or an API-set-aware import strategy instead of forcing a hard import.

```c
#define WINVER        _WIN32_WINNT_WIN7
#define _WIN32_WINNT  _WIN32_WINNT_WIN7
#define NTDDI_VERSION NTDDI_WIN7
#include <windows.h>

// For a post-Win7 API, prefer delay-load/GetProcAddress when older OS support matters.
```

## Experiment Harness

Prove the declaration gate before arguing about deployment. Compile the same translation unit twice: once with the oldest supported target, once with the newest target you intend to name.

```c
#include <windows.h>
int main(void) {
    return CompareObjectHandles(GetCurrentProcess(), GetCurrentProcess()) ? 0 : 1;
}
```

```powershell
cl /nologo /D_WIN32_WINNT=0x0601 gate.c
cl /nologo /D_WIN32_WINNT=0x0A00 gate.c
dumpbin /imports gate.exe | findstr /i "CompareObjectHandles"
```

Signal: the low-target build should fail at compile time if the declaration is gated; the high-target build should compile and show a hard import. Failure interpretation: if the low-target build succeeds, the API is not gated by that macro in the installed SDK; if the high-target binary must run on older Windows, replace the hard import with `GetProcAddress` and measure the missing-export path explicitly.

## Discussion Claim Verification

Claim: "Setting `_WIN32_WINNT` makes the program target that Windows version."

Why it matters for new code: the macro controls header declarations. It does not guarantee the binary avoids newer imports, nor does it make an older OS implement a newer API. This distinction is the root of many VxKex/OneCoreAPI/MSIX compatibility conversations.

How to verify:

```powershell
cl /nologo /D_WIN32_WINNT=0x0601 gate.c /link /MAP:win7.map
cl /nologo /D_WIN32_WINNT=0x0A00 gate.c /link /MAP:win10.map
dumpbin /imports gate.exe
dumpbin /dependents gate.exe
```

Minimal code/pseudocode:

```c
typedef BOOL (WINAPI *CompareObjectHandlesFn)(HANDLE, HANDLE);
CompareObjectHandlesFn p = (CompareObjectHandlesFn)
    GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "CompareObjectHandles");
if (p) {
    BOOL same = p(GetCurrentProcess(), GetCurrentProcess());
}
```

Interpretation: the Microsoft header docs verify the compile-time gate. Unsupported claim nullified: "I set `_WIN32_WINNT_WIN7`, so the EXE is Windows 7 compatible." Compatibility is proven by imports, delay-load behavior, dynamic probes, and execution on the oldest target.

## Connections

- `winnt.h` is where many of the gated declarations, calling conventions, access masks, and PE structures eventually land.
- `VxKex`, `OneCoreAPI`, and `MSIX Package Support Framework` are deployment-time answers to the same mismatch this header exposes at compile time: the source can see an API, but the target process may not be able to import or execute it.
- `mindumpapiset.h` and PE import-table notes are the binary-side view of the same problem: declarations become imports, imports become loader obligations.

## References
- <https://learn.microsoft.com/en-us/windows/win32/winprog/using-the-windows-headers>
- <https://learn.microsoft.com/en-us/cpp/porting/modifying-winver-and-win32-winnt>
