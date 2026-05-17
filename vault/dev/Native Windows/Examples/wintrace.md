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

## References
- https://github.com/matthewgeorgy/wintracea
