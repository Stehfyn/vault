# Shell File Icons

SHGetFileInfoW retrieves the icon and display name for a file path or extension. SHGFI_ICON returns an HICON that must be destroyed with DestroyIcon. SHGFI_SYSICONINDEX returns an index into the system image list (faster for lists).

```cpp
// Get large icon and display name for a path
SHFILEINFOW sfi = {};
HIMAGELIST hImgList = (HIMAGELIST)SHGetFileInfoW(
    L"C:\\Windows\\explorer.exe", 0, &sfi, sizeof(sfi),
    SHGFI_ICON | SHGFI_LARGEICON | SHGFI_DISPLAYNAME);

// Show the icon in a static control
SendMessageW(hwndIcon, STM_SETICON, (WPARAM)sfi.hIcon, 0);
SetWindowTextW(hwndLabel, sfi.szDisplayName);

// Don't forget to clean up
DestroyIcon(sfi.hIcon);

// For a ListView with the system image list:
SHFILEINFOW sfi2 = {};
HIMAGELIST sysIml = (HIMAGELIST)SHGetFileInfoW(
    L"", 0, &sfi2, sizeof(sfi2),
    SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
ListView_SetImageList(hList, sysIml, LVSIL_SMALL);
```

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb776884(v=vs.85)
- https://github.com/rpavlik/HashCheck/blob/439eebbc28839a5fed81f859cb060a927ed56bde/HashVerify.c#L687

## Experiment Harness

Goal: compare icon identity by extension, file path, and system image-list index.

```cpp
for (PCWSTR p : { L"C:\\Windows\\explorer.exe", L".txt", L"C:\\does-not-exist.zzz" }) {
    SHFILEINFOW sfi{};
    DWORD_PTR r = SHGetFileInfoW(p, FILE_ATTRIBUTE_NORMAL, &sfi, sizeof(sfi),
        SHGFI_USEFILEATTRIBUTES | SHGFI_SYSICONINDEX | SHGFI_TYPENAME | SHGFI_SMALLICON);
    wprintf(L"%ls ret=%p idx=%d type=%ls\n", p, (void*)r, sfi.iIcon, sfi.szTypeName);
}
```

Measured signal: return value, system image index, type name, whether `SHGFI_USEFILEATTRIBUTES` changes behavior.

Failure interpretation: per-file icon extraction is expensive and handle-owning; list controls should prefer system image-list indexes where possible. Reference: <https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shgetfileinfow>.
