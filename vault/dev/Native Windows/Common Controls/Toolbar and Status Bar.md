# Toolbar and Status Bar

Toolbars (`TOOLBARCLASSNAME`) and status bars (`STATUSCLASSNAME`) are standard comctl32 controls. The status bar auto-sizes its height to font metrics; pass `SB_SETPARTS` an array of right-edge x-coordinates (last = -1 for stretching).

```cpp
// Status bar with two panes
HWND hStatus = CreateWindowW(STATUSCLASSNAME, L"",
    WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP,
    0, 0, 0, 0, hwnd, (HMENU)IDC_STATUS, hInst, nullptr);
int parts[2] = { 200, -1 };
SendMessageW(hStatus, SB_SETPARTS, 2, (LPARAM)parts);
SendMessageW(hStatus, SB_SETTEXTW, 0, (LPARAM)L"Ready");
SendMessageW(hStatus, SB_SETTEXTW, 1, (LPARAM)L"0 items");

// Reposition status bar on WM_SIZE
case WM_SIZE:
  SendMessageW(hStatus, WM_SIZE, 0, 0);
  break;
```

## References
- https://learn.microsoft.com/en-us/previous-versions/ms810439(v=msdn.10)?redirectedfrom=MSDN
