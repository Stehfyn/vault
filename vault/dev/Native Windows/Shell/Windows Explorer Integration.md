# Windows Explorer Integration

Explorer integration sits at the Shell COM boundary: `IShellWindows` for existing Explorer windows, `IFileDialog` for brokered file/folder picking, `IShellItem`/PIDLs for namespace objects, and helper functions such as `SHOpenFolderAndSelectItems` for driving Explorer UI. Coalesce anything here with the deeper shell notes instead of leaving one-off "open a dialog" snippets.

## Enumerate Explorer windows
Link: https://learn.microsoft.com/en-us/windows/win32/shell/developing-with-windows-explorer

Contribution: the useful pattern is `IShellWindows` -> `IWebBrowserApp` -> `LocationURL`/`HWND`, which is still the simplest way to find live Explorer windows without walking random top-level HWNDs.

```cpp
wil::com_ptr<IShellWindows> windows;
CoCreateInstance(CLSID_ShellWindows, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&windows));

long count = 0;
windows->get_Count(&count);
for (long i = 0; i < count; ++i) {
    VARIANT v; VariantInit(&v);
    v.vt = VT_I4; v.lVal = i;

    wil::com_ptr<IDispatch> disp;
    if (SUCCEEDED(windows->Item(v, &disp)) && disp) {
        wil::com_ptr<IWebBrowserApp> app;
        if (SUCCEEDED(disp.query_to(&app))) {
            SHANDLE_PTR hwnd = 0;
            app->get_HWND(&hwnd);
        }
    }
}
```

## File/folder picking
Link: https://learn.microsoft.com/en-us/windows/win32/shell/common-file-dialog

Contribution: `IFileOpenDialog` supersedes `GetOpenFileNameW` because it returns `IShellItem`, not just a path buffer. That matters for libraries, known folders, cloud placeholders, and namespace extensions where the path is not the real object identity.

```cpp
wil::com_ptr<IFileOpenDialog> dlg;
CoCreateInstance(CLSID_FileOpenDialog, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&dlg));
dlg->SetOptions(FOS_PICKFOLDERS | FOS_FORCEFILESYSTEM);

if (SUCCEEDED(dlg->Show(hwnd))) {
    wil::com_ptr<IShellItem> item;
    dlg->GetResult(&item);
    wil::unique_cotaskmem_string path;
    item->GetDisplayName(SIGDN_FILESYSPATH, &path);
}
```

## Select a file in Explorer
Link: https://github.com/sgrottel/FileBookmark

Contribution: `FileBookmark` is useful because it drives Explorer to a concrete selection instead of merely launching a folder. The underlying primitive is `SHOpenFolderAndSelectItems`: build a folder PIDL and child PIDLs, then let Explorer handle view activation.

```cpp
PIDLIST_ABSOLUTE folder = nullptr;
SHParseDisplayName(LR"(C:\Temp)", nullptr, &folder, 0, nullptr);

PIDLIST_RELATIVE child = nullptr;
SHParseDisplayName(LR"(C:\Temp\log.txt)", nullptr, &child, 0, nullptr);

PCUITEMID_CHILD items[] = { ILFindLastID(child) };
SHOpenFolderAndSelectItems(folder, ARRAYSIZE(items), items, 0);

CoTaskMemFree(child);
CoTaskMemFree(folder);
```

Connections: `Shell Items and Folders.md` is the object model; `Shell Shortcuts.md` persists shell targets; `Explorer++ (Tabbed Win32 Explorer).md` is the larger codebase showing namespace enumeration, context menus, and drag/drop together.
