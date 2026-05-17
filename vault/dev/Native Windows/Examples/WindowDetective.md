WindowDetective is a GUI tool for inspecting Win32 window hierarchies, properties, styles, and messages in real time — similar to Spy++ but open-source. Programmatically, the same information is obtained via `EnumWindows` + `GetWindowText`/`GetClassNameW` and `GetWindowLong` for style flags.

```cpp
#include <windows.h>
#include <stdio.h>

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    wchar_t title[256] = {};
    wchar_t cls[256]   = {};
    GetWindowTextW(hwnd, title, 256);
    GetClassNameW(hwnd,  cls,   256);

    DWORD pid = 0;
    GetWindowThreadProcessId(hwnd, &pid);

    LONG style   = GetWindowLong(hwnd, GWL_STYLE);
    LONG exStyle = GetWindowLong(hwnd, GWL_EXSTYLE);

    if (IsWindowVisible(hwnd) && title[0])
    {
        wprintf(L"HWND=%p  PID=%lu  Class=%-32s  Title=%s\n",
                hwnd, pid, cls, title);
        wprintf(L"  Style=0x%08X  ExStyle=0x%08X\n", style, exStyle);
    }
    return TRUE; // continue enumeration
}

int main()
{
    EnumWindows(EnumWindowsProc, 0);
    return 0;
}
```

## References
- https://github.com/WindowDetective/WindowDetective
