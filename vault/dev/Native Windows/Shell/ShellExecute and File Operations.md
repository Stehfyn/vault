# ShellExecute and File Operations

`ShellExecuteW` opens files, URIs, or verbs on shell items via the default handler. `SHFileOperationW` performs multi-file copy/move/delete with shell UI. For modern code prefer `IFileOperation` which supports progress callbacks and undo.

```cpp
// Launch notepad via ShellExecute
HINSTANCE rc = ShellExecuteW(hwnd, L"open", L"notepad.exe",
    L"C:\\log.txt", nullptr, SW_SHOWNORMAL);
if ((INT_PTR)rc <= 32) { /* error */ }

// Shell-style delete with confirmation suppressed
SHFILEOPSTRUCTW op = {};
op.hwnd  = hwnd;
op.wFunc = FO_DELETE;
op.pFrom = L"C:\\Temp\\old.txt\0\0"; // double-null terminated
op.fFlags = FOF_NOCONFIRMATION | FOF_SILENT | FOF_ALLOWUNDO;
SHFileOperationW(&op);
```

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms681895(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms687066(v=vs.85)
