# Legacy Shell References

Per-link snippets for legacy shell, Control Panel, and taskbar topics.

## Shell namespace entry points
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb762499(v=vs.85)
Brief: Use the desktop IShellFolder to parse a display name.
```cpp
IShellFolder* desktop = NULL;
SHGetDesktopFolder(&desktop);
LPITEMIDLIST pidl = NULL;
ULONG eaten = 0;
desktop->ParseDisplayName(hwnd, NULL, L"::{CLSID}", &eaten, &pidl, NULL);
desktop->Release();
```

## Control Panel CPL entry point
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms644697(v=vs.85)
Brief: Implement a minimal CPlApplet handler.
```cpp
LONG CALLBACK CPlApplet(HWND hwndCpl, UINT msg, LPARAM l1, LPARAM l2) {
  if (msg == CPL_INIT) return TRUE;
  if (msg == CPL_GETCOUNT) return 1;
  if (msg == CPL_DBLCLK) { /* launch UI */ }
  return 0;
}
```

## Thumbnail toolbar buttons
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh127450(v=vs.85)
Brief: Add a single thumbnail toolbar button.
```cpp
ITaskbarList3* tbl = NULL;
CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&tbl));
THUMBBUTTON buttons[1] = {};
buttons[0].iId = 1; buttons[0].dwMask = THB_FLAGS;
buttons[0].dwFlags = THBF_ENABLED;
tbl->ThumbBarAddButtons(hwnd, 1, buttons);
tbl->Release();
```

## Control Panel namespace registration
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/cc144115(v=vs.85)
Brief: Create the Control Panel NameSpace key.
```cpp
HKEY key = NULL;
RegCreateKeyExW(HKEY_LOCAL_MACHINE,
  L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ControlPanel\\NameSpace\\{GUID}",
  0, NULL, 0, KEY_WRITE, NULL, &key, NULL);
RegCloseKey(key);
```

## Shell namespace extension skeleton
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ee663597(v=vs.85)
Brief: Basic EnumObjects implementation.
```cpp
HRESULT MyFolder::EnumObjects(HWND hwnd, SHCONTF flags, IEnumIDList** ppenum) {
  *ppenum = NULL;
  if (!(flags & SHCONTF_NONFOLDERS)) return S_FALSE;
  return CreateEnumIDList(flags, ppenum);
}
```

## Property sheet handler
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/cc144195(v=vs.85)
Brief: Add a property sheet page from IShellPropSheetExt.
```cpp
STDMETHODIMP MyPropSheet::AddPages(LPFNADDPROPSHEETPAGE add, LPARAM lParam) {
  HPROPSHEETPAGE page = CreatePropertySheetPage(&psp);
  if (page) { add(page, lParam); }
  return S_OK;
}
```

## IContextMenu basic entry
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/bb762599(v=vs.85)
Brief: Insert a single custom command.
```cpp
HRESULT MyMenu::QueryContextMenu(HMENU menu, UINT index, UINT idFirst, UINT idLast, UINT flags) {
  if (!(flags & CMF_DEFAULTONLY)) {
    InsertMenuW(menu, index, MF_BYPOSITION, idFirst, L"My Action");
    return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 1);
  }
  return MAKE_HRESULT(SEVERITY_SUCCESS, 0, 0);
}
```

## Iconic thumbnail API
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/hh127447(v=vs.85)
Brief: Provide thumbnail and live preview bitmaps.
```cpp
HBITMAP bmp = CreateCompatibleBitmap(hdc, 256, 256);
if (bmp) {
  DwmSetIconicThumbnail(hwnd, bmp, 0);
  DwmSetIconicLivePreviewBitmap(hwnd, bmp, NULL, 0);
  DeleteObject(bmp);
}
```

## Legacy shell enum index
Link: https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ff521656(v=vs.85)
Brief: Resolve file association data with AssocQueryString.
```cpp
WCHAR buf[260];
DWORD cch = ARRAYSIZE(buf);
HRESULT hr = AssocQueryStringW(0, ASSOCSTR_EXECUTABLE, L".txt", NULL, buf, &cch);
if (SUCCEEDED(hr)) {
  // buf has executable path
}
```

## SHRestricted flags
Link: https://learn.microsoft.com/en-us/windows/win32/api/shlobj_core/ne-shlobj_core-restrictions
Brief: Gate UI features on restriction policy.
```cpp
DWORD val = SHRestricted(REST_NORUN);
if (val) {
  // disable Run command
} else {
  // allow Run command
}
```

