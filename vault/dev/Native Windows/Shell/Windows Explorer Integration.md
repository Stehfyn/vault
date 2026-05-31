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

## Source Code Reading

`sgrottel/FileBookmark` is a small but useful Explorer-integration sample because it shows the surrounding app code, not just the Shell API call. The source files that matter are `FileBookmark/Main.cpp`, `Bookmark.cpp`, `DialogWindowPlacer.cpp`, `Registation.cpp`, and `CallElevated.cpp`.

`Main.cpp` routes modes from `CmdLineOptions`: register file type, open a bookmark, set a bookmark on a selected file, or show a `TaskDialogIndirect` action picker. The file dialogs are old common-dialog APIs (`OPENFILENAMEW`, `GetOpenFileNameW`, `GetSaveFileNameW`) rather than `IFileDialog`, but `DialogWindowPlacer` watches for dialog windows and positions them consistently. The actual launch path is deliberately plain: `OpenBookmarkedFile` calls `ShellExecuteW(nullptr, L"open", file.c_str(), ...)`.

`Bookmark.cpp` owns the `.bookmark` file format: create a sidecar file named `<target>.bookmark`, write/read the target path, compute next/previous files in the directory, then pass the chosen target back to the UI. This is not a shell extension; it is an ordinary EXE plus file association.

`Registation.cpp` writes the association by creating `HKCR\.bookmark`, `HKCR\FileBookmark.bookmark`, `DefaultIcon`, and `shell\open\command` style keys. `CallElevated.cpp` uses `ShellExecuteW(..., L"runas", ...)` when registration needs elevation.

Claim -> source/probe -> interpretation:

Claim: many Explorer integrations do not require an in-proc shell extension.
Source/probe: register a private extension under `HKCU\Software\Classes` instead of `HKCR`, point `shell\open\command` at a test EXE, and log the command line passed by Explorer.
Interpretation: if association plus `ShellExecute` solves the workflow, an in-proc `IContextMenu`/preview/namespace extension is unnecessary risk.

Claim: a file-dialog sample can still be Shell-relevant even when it uses `OPENFILENAMEW`.
Source/probe: compare `GetOpenFileNameW` output with `IFileOpenDialog::GetResult(IShellItem)` for a normal file, a library, and a cloud placeholder.
Interpretation: `OPENFILENAMEW` is path-buffer integration. `IFileDialog` is Shell item integration. Use the latter when object identity matters.

Connections: `Shell Items and Folders.md` is the object model; `Shell Shortcuts.md` persists shell targets; `Explorer++ (Tabbed Win32 Explorer).md` is the larger codebase showing namespace enumeration, context menus, and drag/drop together.

## Experiment Harness

Goal: prove whether Explorer state is reachable through Shell COM or only through HWND scraping.

```cpp
wil::com_ptr<IShellWindows> sw;
CoCreateInstance(CLSID_ShellWindows, nullptr, CLSCTX_ALL, IID_PPV_ARGS(&sw));
long count = 0;
sw->get_Count(&count);
wprintf(L"shell-windows=%ld\n", count);
```

Procedure: open File Explorer, Control Panel, and Edge/IE-mode if present; enumerate `LocationURL`, `HWND`, and `FullName`.

Measured signal: object count, URL scheme, HWND validity via `IsWindow`, process image behind each HWND.

Failure interpretation: top-level HWND enumeration sees windows; `IShellWindows` sees shell automation objects. If counts diverge, choose the plane that matches the tool's goal. Reference: <https://learn.microsoft.com/en-us/windows/win32/shell/developing-with-windows-explorer>.
