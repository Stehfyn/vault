# Known Folders

`SHGetKnownFolderPath` replaces the old `SHGetFolderPath`/`CSIDL_*` API. Returns a heap-allocated path that must be freed with `CoTaskMemFree`. GUID constants like `FOLDERID_Desktop`, `FOLDERID_AppData`, etc. are defined in `<KnownFolders.h>`.

```cpp
// Get the user's AppData\Roaming path
PWSTR path = nullptr;
if (SUCCEEDED(SHGetKnownFolderPath(FOLDERID_RoamingAppData, 0, nullptr, &path))) {
  std::wstring appData(path);
  CoTaskMemFree(path);
  std::wstring myApp = appData + L"\\MyApp";
  CreateDirectoryW(myApp.c_str(), nullptr);
}
```

## References
- https://learn.microsoft.com/en-us/previous-versions//bb776819(v=vs.85)?redirectedfrom=MSDN
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb776884(v=vs.85)

## Connections
- `Shell Items and Folders.md` is the COM object layer above these filesystem and virtual-folder IDs.
- `../Headers/KnownFolders.h - FOLDERID GUIDs.md` is the declaration catalogue; this note is the usage recipe.
- `Shell Shortcuts.md` and `Shell Execute.md` are common consumers after resolving a known folder path into an installed-app, startup, desktop, or per-user data location.

## Experiment Harness

Goal: prove a known folder is a stable ID whose path can vary by user, bitness, policy, and redirection.

```cpp
for (auto id : { FOLDERID_Profile, FOLDERID_RoamingAppData,
                 FOLDERID_ProgramFiles, FOLDERID_ProgramFilesX86 }) {
    PWSTR path = nullptr;
    HRESULT hr = SHGetKnownFolderPath(id, KF_FLAG_DEFAULT, nullptr, &path);
    wprintf(L"%08lx %ls\n", hr, path ? path : L"<none>");
    CoTaskMemFree(path);
}
```

Procedure: run the same binary as x86 and x64, then compare Program Files outputs; run as a second user and compare profile/AppData paths.

Measured signal: GUID input, HRESULT, returned path, process bitness, user SID.

Failure interpretation: hardcoded paths break first; `KNOWNFOLDERID` survives redirection better. Reference: <https://learn.microsoft.com/en-us/windows/win32/shell/knownfolderid>.
