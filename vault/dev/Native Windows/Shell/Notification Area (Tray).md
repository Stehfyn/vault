# Notification Area (Tray)

Per-link references with a brief note and focused snippet.

## Notification area overview
Link: https://learn.microsoft.com/en-us/windows/win32/shell/notification-area
Brief: Add a tray icon with NOTIFYICONDATA.
```cpp
NOTIFYICONDATAW nid = {};
nid.cbSize = sizeof(nid);
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
Shell_NotifyIconW(NIM_ADD, &nid);
```

## Query user notification state
Link: https://learn.microsoft.com/en-us/windows/win32/api/shellapi/ne-shellapi-query_user_notification_state
Brief: Defer notifications when in quiet/presentation modes.
```cpp
QUERY_USER_NOTIFICATION_STATE state = QUNS_ACCEPTS_NOTIFICATIONS;
SHQueryUserNotificationState(&state);
if (state != QUNS_ACCEPTS_NOTIFICATIONS) {
  // defer toast
}
```

## RegisterShellHookWindow
Link: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registershellhookwindow
Brief: Receive shell hook messages for window events.
```cpp
UINT msg = RegisterWindowMessageW(L"SHELLHOOK");
RegisterShellHookWindow(hwnd);
LRESULT OnShellHook(WPARAM w, LPARAM l) {
  if (w == HSHELL_WINDOWCREATED) { /* ... */ }
  return 0;
}
```

## Shell_NotifyIconW
Link: https://learn.microsoft.com/en-us/windows/win32/api/shellapi/nf-shellapi-shell_notifyiconw
Brief: Update tooltip text on an existing icon.
```cpp
NOTIFYICONDATAW nid = {};
nid.cbSize = sizeof(nid);
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_TIP;
StringCchCopyW(nid.szTip, ARRAYSIZE(nid.szTip), L"My App");
Shell_NotifyIconW(NIM_MODIFY, &nid);
```

## Taskbar extensions thumbbars
Link: https://learn.microsoft.com/en-us/windows/win32/shell/taskbar-extensions?redirectedfrom=MSDN#thumbbars
Brief: Add a button to the thumbnail toolbar.
```cpp
ITaskbarList3* tbl = NULL;
CoCreateInstance(CLSID_TaskbarList, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&tbl));
THUMBBUTTON btn = {};
btn.iId = 1; btn.dwMask = THB_TOOLTIP;
StringCchCopyW(btn.szTip, ARRAYSIZE(btn.szTip), L"Play");
tbl->ThumbBarAddButtons(hwnd, 1, &btn);
tbl->Release();
```

