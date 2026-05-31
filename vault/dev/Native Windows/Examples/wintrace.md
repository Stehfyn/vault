A Win32 function call tracer that intercepts API calls using Import Address Table (IAT) patching. The approach replaces function pointers in the PE import table at runtime so that every call to a target API (e.g. `CreateWindowExW`) passes through a trampoline that logs arguments before forwarding to the real function.

```cpp
#include <windows.h>
#include <imagehlp.h>
#pragma comment(lib, "imagehlp.lib")

// Saved real function pointer
static HWND (WINAPI *Real_CreateWindowExW)(DWORD, LPCWSTR, LPCWSTR, DWORD,
    int, int, int, int, HWND, HMENU, HINSTANCE, LPVOID) = CreateWindowExW;

// Hook: log then forward
HWND WINAPI Hook_CreateWindowExW(DWORD exStyle, LPCWSTR cls, LPCWSTR name,
    DWORD style, int x, int y, int w, int h,
    HWND parent, HMENU menu, HINSTANCE inst, LPVOID param)
{
    wchar_t buf[256];
    swprintf_s(buf, L"[wintrace] CreateWindowExW: %s", name ? name : L"<null>");
    OutputDebugStringW(buf);
    return Real_CreateWindowExW(exStyle, cls, name, style, x, y, w, h, parent, menu, inst, param);
}

// Patch the IAT of hMod to redirect targetDll!funcName -> hookFn
void PatchIAT(HMODULE hMod, const char* targetDll, const char* funcName, void* hookFn)
{
    ULONG size;
    auto* imp = (IMAGE_IMPORT_DESCRIPTOR*)ImageDirectoryEntryToData(
        hMod, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &size);

    for (; imp->Name; ++imp)
    {
        if (_stricmp((char*)((BYTE*)hMod + imp->Name), targetDll) != 0) continue;
        auto* thunk = (IMAGE_THUNK_DATA*)((BYTE*)hMod + imp->FirstThunk);
        auto* orig  = (IMAGE_THUNK_DATA*)((BYTE*)hMod + imp->OriginalFirstThunk);
        for (; orig->u1.AddressOfData; ++thunk, ++orig)
        {
            auto* info = (IMAGE_IMPORT_BY_NAME*)((BYTE*)hMod + orig->u1.AddressOfData);
            if (strcmp((char*)info->Name, funcName) != 0) continue;
            DWORD old;
            VirtualProtect(thunk, sizeof(void*), PAGE_READWRITE, &old);
            thunk->u1.Function = (ULONG_PTR)hookFn;
            VirtualProtect(thunk, sizeof(void*), old, &old);
            return;
        }
    }
}

// Install:
// PatchIAT(GetModuleHandle(NULL), "user32.dll", "CreateWindowExW", Hook_CreateWindowExW);
```

## ETW Comparison Route

IAT tracing and ETW answer different questions. Use IAT patching when the exact imported function call and argument shape matter inside one process. Use ETW when the behavior should be observed outside the process and correlated with services, files, registry, network, or process lifetime.

```text
single-process argument trace:
  wintrace -> imported API -> trampoline -> OutputDebugString/log

system-observable behavior:
  EventWrite/TraceLogging provider -> krabsetw/wtrace/ProcMonXv2 -> ETL or live records

service failure investigation:
  SCM System log -> WMI Win32_Service state -> wtrace/ProcMonXv2 -> targeted IAT hook only if needed
```

The practical bridge is `OutputDebugStringW`: quick hooks can emit debug strings during development, but durable tools should graduate either to an ETW provider (`EventWrite`) or to an external ETW consumer.

## Experiment Harness

Goal: prove when process-local tracing is more precise than ETW and when it is the wrong tool.

Procedure:
1. Patch one imported API with low risk, such as `CreateFileW` or `CreateWindowExW`.
2. Emit one compact line per call through `OutputDebugStringW` or a ring buffer.
3. Run the same workload under wtrace/ProcMonXv2.
4. Compare call-site argument count against ETW-observed behavior count.

```cpp
// Keep hook output small; heavy logging changes the behavior being measured.
OutputDebugStringW(L"[wintrace] CreateFileW path=<captured> access=<hex>\n");
```

Measurable signals:
- Hook count per API.
- Distinct argument tuples.
- ETW file/window/process events for the same PID/time window.
- Added latency per call if the hook writes synchronously.

Failure interpretation:
- Hook sees calls but ETW does not: the API call did not produce an OS-visible event, provider coverage is absent, or ETW filtering missed it.
- ETW sees behavior but hook does not: the target used a different API path, delay-loaded module, direct syscall, another process, or an unpatched import.
- The program changes behavior under tracing: hook reentrancy, loader-lock timing, page-protection mistakes, or logging overhead.

## References
- https://github.com/matthewgeorgy/wintracea
- <https://www.microsoft.com/en-us/research/project/detours/>
