# Shell Execute

Per-link references for launching content.

## SHELLEXECUTEINFOA structure
Link: https://learn.microsoft.com/en-us/windows/win32/api/shellapi/ns-shellapi-shellexecuteinfoa
Brief: Launch with ShellExecuteEx and keep a process handle.
```cpp
SHELLEXECUTEINFOA sei = {};
sei.cbSize = sizeof(sei);
sei.fMask = SEE_MASK_NOCLOSEPROCESS;
sei.lpVerb = "open";
sei.lpFile = "notepad.exe";
ShellExecuteExA(&sei);
```

## Launch guidance
Link: https://learn.microsoft.com/en-us/windows/win32/shell/launch
Brief: Use ShellExecute for common verbs (open/runas).
```cpp
HINSTANCE res = ShellExecuteW(hwnd, L"runas", L"cmd.exe",
                              L"/c whoami", NULL, SW_SHOWNORMAL);
if ((INT_PTR)res <= 32) {
  // error
}
```

