# Systray Shell Extension

The XP system tray is implemented as a shell extension (`systray.c`) loaded by `explorer.exe`. The power panel (`power.c`) queries `GetSystemPowerStatus` on a timer and posts status changes to the tray icon. Modern code uses `Shell_NotifyIconW` with `NOTIFYICONDATAW`.

```cpp
// Add a tray icon with callback message and tooltip
NOTIFYICONDATAW nid = { sizeof(nid) };
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
nid.uCallbackMessage = WM_APP + 10;
nid.hIcon = LoadIconW(nullptr, IDI_APPLICATION);
wcscpy_s(nid.szTip, L"My Tray App");
Shell_NotifyIconW(NIM_ADD, &nid);

// Check if notifications should be suppressed (presentation mode etc.)
QUERY_USER_NOTIFICATION_STATE state = QUNS_NOT_PRESENT;
if (SUCCEEDED(SHQueryUserNotificationState(&state)) &&
    state == QUNS_ACCEPTS_NOTIFICATIONS) {
  Shell_NotifyIconW(NIM_MODIFY, &nid);
}
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/shell/ext/systray/exestub/systray.c#L51
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/shell/ext/systray/dll/power.c
