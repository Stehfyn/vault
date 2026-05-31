# Explorer++ (Tabbed Win32 Explorer)

Pure Win32 C++ Explorer alternative with tabs. Important reference codebase for: tabbed-document MDI in raw Win32 (`SysTabControl32` + manual child-window management), the right way to enumerate the shell namespace via `IShellFolder::EnumObjects` + `IShellFolder2::GetDetailsEx` for property columns, custom drop-targets via `IDropTarget`, and shell context-menu invocation via `IContextMenu::QueryContextMenu` + `InvokeCommand`. Built-in dark mode added in recent versions.

## Source Shape

Source pass: `Explorer++/Explorer++/ShellEnumeratorImpl.cpp` shows the canonical Shell namespace enumeration loop. The useful pattern is not "list files"; it is bind PIDL to `IShellFolder`, request an `IEnumIDList`, and preserve PIDL ownership while cancellation and hidden/super-hidden policy are layered above it.

```cpp
wil::com_ptr_nothrow<IShellFolder> folder;
SHBindToObject(nullptr, pidlDirectory, nullptr, IID_PPV_ARGS(&folder));

SHCONTF flags = SHCONTF_FOLDERS | SHCONTF_NONFOLDERS;
wil::com_ptr_nothrow<IEnumIDList> e;
folder->EnumObjects(ownerHwnd, flags, &e);

while (e && e->Next(1, wil::out_param(childPidl), &fetched) == S_OK) {
    items.emplace_back(childPidl.get());
}
```

Source pass: `Explorer++/Helper/ShellContextMenu.cpp` is the context-menu route. Explorer-style menus are not app-owned menus with shell-looking labels; they are `IContextMenu` objects queried, tracked, optionally extended, and invoked by command offset.

```cpp
wil::unique_hmenu menu(CreatePopupMenu());
wil::com_ptr_nothrow<IContextMenu> cm = MaybeGetShellContextMenu(hwnd);
cm->QueryContextMenu(menu.get(), 0, MIN_SHELL_MENU_ID, MAX_SHELL_MENU_ID, flags);

UINT cmd = TrackPopupMenu(menu.get(), TPM_RETURNCMD, x, y, 0, hwnd, nullptr);
CMINVOKECOMMANDINFO info{ sizeof(info) };
info.hwnd = hwnd;
info.lpVerb = MAKEINTRESOURCEA(cmd - MIN_SHELL_MENU_ID);
cm->InvokeCommand(&info);
```

## Source Code Reading

The highest-value source detail is that Explorer++ is not a wrapper around `IExplorerBrowser`; it builds its own browser surface out of common controls plus Shell COM. `Explorer++/Explorer++/ShellBrowser/ShellBrowserImpl.cpp` creates a `SysListView32`, subclasses it, wires navigation observers, and uses one-thread COM initialization callbacks for column, thumbnail, and infotip worker pools:

```cpp
m_columnThreadPool(1, bind(CoInitializeEx, nullptr, COINIT_APARTMENTTHREADED), CoUninitialize);
m_thumbnailThreadPool(1, bind(CoInitializeEx, nullptr, COINIT_APARTMENTTHREADED), CoUninitialize);
m_shellWindows = winrt::try_create_instance<IShellWindows>(CLSID_ShellWindows, CLSCTX_ALL);
```

That is an architectural point: the UI thread owns HWND/list-view state; worker STA threads own Shell property/thumbnail calls that may require COM apartment behavior.

Drag/drop is source-complete in `Explorer++/Helper/DragDropHelper.cpp`. `StartDragForShellItems` creates an `IShellItemArray` from absolute PIDLs, asks for `SFGAO_CANCOPY | SFGAO_CANMOVE | SFGAO_CANLINK`, binds the array to `BHID_DataObject`, optionally writes `CFSTR_PREFERREDDROPEFFECT`, and calls `SHDoDragDrop`. `CreateDataObjectForShellTransfer` wraps the shell data object in `DataObjectWrapper` because simply querying `IDataObjectAsyncCapability` on the shell object was not enough to make async transfer actually occur in practice.

```cpp
SHCreateShellItemArrayFromIDLists(count, pidls, &array);
array->BindToHandler(nullptr, BHID_DataObject, IID_PPV_ARGS(&data));
auto wrapped = winrt::make<DataObjectWrapper>(data.get());
wrapped->QueryInterface(IID_PPV_ARGS(&async))->SetAsyncMode(VARIANT_TRUE);
SHDoDragDrop(nullptr, wrapped.get(), nullptr, allowedEffects, &effect);
```

`ShellBrowser/BrowsingHandler.cpp` is the namespace identity path. Navigation stores PIDLs, binds the current folder with `SHBindToObject`, enumerates child PIDLs, combines parent/child PIDLs with `ILCombine`, and computes parsing/edit/display names separately. It also extracts properties through `IShellFolder2` / property-store helpers rather than assuming filesystem metadata.

Claim -> source/probe -> interpretation:

Claim: a full Explorer replacement should treat PIDLs as first-class identity, not merely convert them to paths.
Source/probe: inspect `BrowsingHandler.cpp` and `ShellHelper.cpp`; then run a probe over `shell:Downloads`, Control Panel, Recycle Bin, and a normal folder, logging `SHGDN_FORPARSING`, `SHGDN_INFOLDER`, and `SIGDN_FILESYSPATH` where available.
Interpretation: if a view collapses everything to paths, it stops being a Shell namespace browser and becomes a filesystem browser with Explorer-like decoration.

## Connections

- `Shell Items and Folders.md` is the object model Explorer++ repeatedly consumes.
- `Windows Explorer Integration.md` shows smaller one-off Explorer automation; this note is the larger app-shaped implementation.
- `../(COM) Component Object Model/COM in plain C.md` explains why `IShellFolder`, `IEnumIDList`, `IDataObject`, `IDropTarget`, and `IContextMenu` all compose despite coming from different shell subsystems.
- `../(WTL) Windows Template Library/WIL (Windows Implementation Library).md` is the helper style visible in the source through `wil::com_ptr_nothrow`, `wil::unique_hmenu`, and `RETURN_IF_FAILED`.

## Experiment Harness

Goal: test namespace enumeration separately from Explorer++ UI.

```cpp
wil::com_ptr<IShellFolder> desktop;
SHGetDesktopFolder(&desktop);

wil::com_ptr<IEnumIDList> e;
HRESULT hr = desktop->EnumObjects(hwnd,
    SHCONTF_FOLDERS | SHCONTF_NONFOLDERS | SHCONTF_INCLUDEHIDDEN, &e);

ULONG fetched = 0, count = 0;
wil::unique_cotaskmem_ptr<ITEMID_CHILD> child;
while (e && e->Next(1, wil::out_param(child), &fetched) == S_OK) ++count;
printf("EnumObjects=%08lx count=%lu\n", hr, count);
```

Measured signal: item count by `SHCONTF` flags, elapsed enumeration time, HRESULTs from `BindToObject` and `GetDetailsEx`.

Failure interpretation: slow/failed enumeration usually belongs to shell extensions, network/cloud providers, or flags, not the tab UI. Reference: <https://learn.microsoft.com/windows/win32/shell/folder-info>.

## References
- <https://github.com/derceg/explorerplusplus>
