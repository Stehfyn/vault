Tool to package a `.bat` batch script as a standalone `.exe` by embedding the script as a Win32 resource. The resulting executable extracts the batch file to a temporary path at runtime and launches it via `CreateProcess`. Useful for distributing scripts without exposing source or requiring a separate `.bat` file alongside the executable.

```cpp
#include <windows.h>

// 1. Locate the embedded BATCH resource
HRSRC   hRes    = FindResourceW(nullptr, MAKEINTRESOURCEW(IDR_SCRIPT), L"BATCH");
HGLOBAL hGlobal = LoadResource(nullptr, hRes);
void*   data    = LockResource(hGlobal);
DWORD   size    = SizeofResource(nullptr, hRes);

// 2. Write to a temp file with .bat extension
wchar_t tmp[MAX_PATH], dir[MAX_PATH];
GetTempPathW(MAX_PATH, dir);
GetTempFileNameW(dir, L"bat", 0, tmp);
wcscat_s(tmp, L".bat");

HANDLE hFile = CreateFileW(tmp, GENERIC_WRITE, 0, nullptr,
                           CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
DWORD written;
WriteFile(hFile, data, size, &written, nullptr);
CloseHandle(hFile);

// 3. Execute via cmd.exe
wchar_t cmd[MAX_PATH + 16];
swprintf_s(cmd, L"cmd.exe /c \"%s\"", tmp);
STARTUPINFOW si = { sizeof(si) };
PROCESS_INFORMATION pi;
CreateProcessW(nullptr, cmd, nullptr, nullptr, FALSE, 0,
               nullptr, nullptr, &si, &pi);
WaitForSingleObject(pi.hProcess, INFINITE);
CloseHandle(pi.hProcess);
CloseHandle(pi.hThread);
DeleteFileW(tmp);
```

## References

- <https://github.com/kyleleong/bat2exe>
