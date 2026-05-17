Collection of small utility programs written in C using the Windows API. Each tool demonstrates a focused Win32 technique such as process management, window enumeration, file operations, or registry access. The project serves as a practical reference for common low-level Win32 patterns with minimal dependencies.

**Utilities in the repo:**
- Small, self-contained C programs built against the Win32 API
- Tools for system inspection, process/window manipulation, and file operations
- Compilable with MSVC or MinGW, no external dependencies

```c
// Enumerate all top-level windows and print their titles
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
    char title[256];
    if (GetWindowTextA(hwnd, title, sizeof(title)) > 0 && IsWindowVisible(hwnd))
        printf("%p: %s\n", (void*)hwnd, title);
    return TRUE;
}

int main(void) {
    EnumWindows(EnumWindowsProc, 0);
    return 0;
}
```

## References

- <https://github.com/myfreeer/win32-tools>
