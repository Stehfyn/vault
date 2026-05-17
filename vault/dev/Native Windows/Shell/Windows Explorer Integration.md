# Windows Explorer Integration

Per-link references for Explorer automation and dialogs.

## Developing with Windows Explorer
Link: https://learn.microsoft.com/en-us/windows/win32/shell/developing-with-windows-explorer
Brief: Enumerate Explorer windows with IShellWindows.
```cpp
IShellWindows* sw = NULL;
CoCreateInstance(CLSID_ShellWindows, NULL, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&sw));
long count = 0;
sw->get_Count(&count);
for (long i = 0; i < count; ++i) { /* inspect */ }
sw->Release();
```

## Common file dialog
Link: https://learn.microsoft.com/en-us/windows/win32/shell/common-file-dialog
Brief: Use IFileOpenDialog to select a file.
```cpp
IFileOpenDialog* dlg = NULL;
CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&dlg));
if (SUCCEEDED(dlg->Show(hwnd))) {
  IShellItem* item = NULL;
  dlg->GetResult(&item);
  item->Release();
}
dlg->Release();
```

## FileBookmark sample
Link: https://github.com/sgrottel/FileBookmark
Brief: Open a folder and select items in Explorer.
```cpp
PIDLIST_ABSOLUTE pidl = NULL;
SFGAOF attrs = 0;
SHParseDisplayName(L"C:\\Projects", NULL, &pidl, 0, &attrs);
SHOpenFolderAndSelectItems(pidl, 0, NULL, 0);
CoTaskMemFree(pidl);
```

