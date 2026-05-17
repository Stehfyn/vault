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
