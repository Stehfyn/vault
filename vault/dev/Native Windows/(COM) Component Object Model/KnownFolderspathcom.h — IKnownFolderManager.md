# KnownFolderspathcom.h - IKnownFolderManager

## Experiment Harness

Goal: distinguish known-folder identity from current filesystem location.

```cpp
wil::com_ptr<IKnownFolderManager> mgr;
CoCreateInstance(CLSID_KnownFolderManager, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&mgr));

KNOWNFOLDERID *ids = nullptr;
UINT count = 0;
RETURN_IF_FAILED(mgr->GetFolderIds(&ids, &count));
printf("known-folder-count=%u\n", count);

for (UINT i = 0; i < min(count, 10u); ++i) {
    wil::com_ptr<IKnownFolder> folder;
    if (SUCCEEDED(mgr->GetFolder(ids[i], &folder))) {
        wil::unique_cotaskmem_string path;
        HRESULT hr = folder->GetPath(0, &path);
        wprintf(L"%08lx %ls\n", hr, path ? path.get() : L"<virtual/unavailable>");
    }
}
CoTaskMemFree(ids);
```

Measured signal: count of registered folders, per-folder `HRESULT`, path or no-path result, and whether x86/x64 builds report different Program Files IDs.

Failure interpretation: no path is not automatically failure; some folders are virtual, redirected, unavailable, or policy-bound. Reference: <https://learn.microsoft.com/en-us/windows/win32/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids>.

`KnownFolderspathcom.h` is the COM side of the known-folder system. `KnownFolders.h` gives the `FOLDERID_*` GUIDs; `IKnownFolderManager` and `IKnownFolder` give code a way to enumerate, resolve, redirect, and inspect the shell's registered known folders without hard-coding paths or old CSIDL constants.

This is the bridge between registry-backed shell state and COM-based shell APIs. Use it when a note needs to explain why `SHGetKnownFolderPath` is only the convenient endpoint: the manager exposes category, definition, canonical name, path, redirection support, and folder identity in a way that matters for installers, profile migration, sandboxing, and shell replacement tools.

## References
- `KnownFolderspathcom.h` - Windows SDK header declaring `IKnownFolderManager` and related known-folder COM interfaces.
