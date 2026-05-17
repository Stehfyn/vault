# Shell Items and Folders

`IShellItem` (Vista+) replaces the raw `PIDL` API for most shell operations. `SHCreateItemFromParsingName` converts a path to an `IShellItem`. `IShellItem2` extends it with `GetProperty` for shell property system access.

```cpp
// Open a file picker and get the selected IShellItem
IFileOpenDialog* dlg = nullptr;
CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER,
    IID_PPV_ARGS(&dlg));
if (SUCCEEDED(dlg->Show(hwnd))) {
  IShellItem* item = nullptr;
  dlg->GetResult(&item);
  PWSTR path = nullptr;
  item->GetDisplayName(SIGDN_FILESYSPATH, &path);
  SetWindowTextW(hwnd, path);
  CoTaskMemFree(path);
  item->Release();
}
dlg->Release();
```

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh437216(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms703240(v=vs.85)
