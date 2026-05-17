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
