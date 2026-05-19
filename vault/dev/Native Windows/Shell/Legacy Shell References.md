# Legacy Shell References

This is the coalesced map for older shell extension and Control Panel surfaces. Keep links here only when they show a code-bearing COM/registry boundary that still explains old tools, shell extensions, or Explorer replacements.

## Namespace parsing and enumeration
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb762499(v=vs.85)

Contribution: `IShellFolder::ParseDisplayName` and `EnumObjects` are the pre-`IShellItem` core. The code pattern is PIDL ownership: the shell allocates with the COM task allocator, and callers free with `CoTaskMemFree`.

```cpp
wil::com_ptr<IShellFolder> desktop;
SHGetDesktopFolder(&desktop);

PIDLIST_RELATIVE pidl = nullptr;
ULONG eaten = 0, attrs = 0;
desktop->ParseDisplayName(hwnd, nullptr, L"C:\\Windows", &eaten, &pidl, &attrs);
CoTaskMemFree(pidl);
```

## Control Panel applet ABI
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms644697(v=vs.85)

Contribution: a `.cpl` is a DLL exporting `CPlApplet`; Control Panel drives it with `CPL_INIT`, `CPL_GETCOUNT`, `CPL_INQUIRE`/`CPL_NEWINQUIRE`, `CPL_DBLCLK`, `CPL_STOP`, and `CPL_EXIT`. That message protocol is the important code, not the icon resource.

```cpp
extern "C" LONG CALLBACK CPlApplet(HWND hwnd, UINT msg, LPARAM p1, LPARAM p2) {
    switch (msg) {
    case CPL_INIT: return TRUE;
    case CPL_GETCOUNT: return 1;
    case CPL_DBLCLK: DialogBoxW(g_hinst, MAKEINTRESOURCEW(IDD_MAIN), hwnd, DlgProc); return 0;
    case CPL_STOP:
    case CPL_EXIT: return 0;
    }
    return 0;
}
```

## Context menus and property sheets
Links:
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb762599(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/cc144195(v=vs.85)

Contribution: `IContextMenu` extends Explorer's verb list; `IShellPropSheetExt` contributes property pages. Both are in-process shell extensions, so COM apartment behavior, DLL lifetime, registry registration, and crash isolation matter more than the menu/page UI itself.

```cpp
HRESULT QueryContextMenu(HMENU menu, UINT index, UINT idFirst, UINT idLast, UINT flags) {
    InsertMenuW(menu, index, MF_BYPOSITION | MF_STRING, idFirst, L"Inspect");
    return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 1); // one verb consumed
}
```

## Taskbar thumbnails
Links:
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh127450(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh127447(v=vs.85)

Contribution: these document the Vista/Win7 taskbar extension layer: thumbnail buttons through `ITaskbarList3` and live-preview bitmaps through `DwmSetIconicThumbnail` / `DwmSetIconicLivePreviewBitmap`. They connect shell UI to DWM composition.

```cpp
THUMBBUTTON b = {};
b.dwMask = THB_TOOLTIP | THB_FLAGS;
b.iId = 1;
b.dwFlags = THBF_ENABLED;
StringCchCopyW(b.szTip, ARRAYSIZE(b.szTip), L"Capture");
taskbar->ThumbBarAddButtons(hwnd, 1, &b);
```

## Control Panel namespace registration and policy
Links:
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/cc144115(v=vs.85)
- https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/ne-shlobj_core-restrictions

Contribution: namespace registration is registry-backed shell discovery, while `SHRestricted` reflects policy gates. Together they explain why shell UI is not just code: registration and policy decide what Explorer surfaces.

Connections: `Cpl.h.md` covers the CPL ABI; `Shell Items and Folders.md` covers the newer item model; `Explorer++ (Tabbed Win32 Explorer).md` is the larger codebase where namespace enumeration, context menus, and view state are coalesced.
