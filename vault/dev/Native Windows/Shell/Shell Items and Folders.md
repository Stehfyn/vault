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

## Source Shape

The actionable split is `IShellItem` for modern identity and PIDLs for APIs that still need the old namespace token. Use `SIGDN_FILESYSPATH` only when you truly require a filesystem path; many shell objects are virtual, library-backed, cloud-backed, or extension-backed.

```cpp
wil::com_ptr<IShellItem> item;
SHCreateItemFromParsingName(path, nullptr, IID_PPV_ARGS(&item));

wil::unique_cotaskmem_string parsingName;
item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &parsingName);

wil::com_ptr<IShellItem2> item2;
if (SUCCEEDED(item.query_to(&item2))) {
    PROPVARIANT v{};
    item2->GetProperty(PKEY_ItemNameDisplay, &v);
    PropVariantClear(&v);
}
```

## Source Code Reading

Explorer++ is the useful corrective to overly tidy `IShellItem` examples. Its `Explorer++/Helper/ShellHelper.cpp` keeps both worlds alive:

- `GetDisplayName(PCIDLIST_ABSOLUTE, flags, output)` binds to the parent `IShellFolder`, then calls `IShellFolder::GetDisplayNameOf` on the child PIDL.
- `UpdatePidl` creates `IShellItem2` from an existing PIDL with `SHCreateItemFromIDList`, then obtains a fresh PIDL with `SHGetIDListFromObject`.
- `MaybeGetLinkTarget` starts from `IShellItem`, queries link-related interfaces, and returns a target PIDL instead of assuming the target is a path.
- `ArePidlsEquivalent` compares through the desktop folder instead of byte-comparing PIDL memory.

```cpp
SHBindToParent(pidl, IID_PPV_ARGS(&parent), &child);
parent->GetDisplayNameOf(child, SHGDN_FORPARSING, &strret);
StrRetToBuf(&strret, child, buffer, count);
```

`Explorer++/ShellBrowser/BrowsingHandler.cpp` then uses that helper layer during enumeration: bind the current absolute PIDL to `IShellFolder`, combine parent/child PIDLs with `ILCombine`, compute parsing name, display name, editing name, attributes, and property details independently.

Claim -> source/probe -> interpretation:

Claim: PIDL equivalence is a Shell question, not a `memcmp`.
Source/probe: compare two PIDLs for the same known folder obtained through different APIs: `SHGetKnownFolderIDList`, `SHParseDisplayName`, and `SHGetIDListFromObject(IShellItem2)`. Use `IShellFolder::CompareIDs` through the desktop folder.
Interpretation: byte identity is not semantic identity. Namespace extensions may allocate different PIDL representations for the same logical object.

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh437216(v=vs.85)
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms703240(v=vs.85)

## Connections
- `Known Folders.md` supplies the stable folder IDs that often become the starting point for `IShellItem` creation.
- `Windows Explorer Integration.md` and `Drag and Drop.md` are the next layer once items need verbs, context menus, data objects, or Explorer-facing behavior.
- `../(COM) Component Object Model/COM in plain C.md` is the ABI fallback when shell interfaces need to be consumed without C++ helper wrappers.
- `Explorer++ (Tabbed Win32 Explorer).md` is where `IShellItem` convenience gives way to raw `IShellFolder`/PIDL enumeration for a full namespace browser.

## Experiment Harness

Goal: test whether an object can be represented as a filesystem path or only as shell identity.

```cpp
for (PCWSTR name : { L"C:\\Windows", L"shell:Downloads", L"::{20D04FE0-3AEA-1069-A2D8-08002B30309D}" }) {
    wil::com_ptr<IShellItem> item;
    HRESULT hr = SHCreateItemFromParsingName(name, nullptr, IID_PPV_ARGS(&item));
    wil::unique_cotaskmem_string fs, parse;
    if (item) {
        item->GetDisplayName(SIGDN_FILESYSPATH, &fs);
        item->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, &parse);
    }
    wprintf(L"%ls hr=%08lx fs=%ls parse=%ls\n", name, hr,
            fs ? fs.get() : L"<none>", parse ? parse.get() : L"<none>");
}
```

Measured signal: `SIGDN_FILESYSPATH` success/failure versus `SIGDN_DESKTOPABSOLUTEPARSING` success/failure.

Failure interpretation: code that requires `SIGDN_FILESYSPATH` is filesystem-only even if it claims to support the Shell namespace. References: <https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nn-shobjidl_core-ishellitem> and <https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-shcreateitemfromparsingname>.
