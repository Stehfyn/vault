# Notification Area (Tray)

Tray icons are shell-owned state keyed by `(HWND, uID)` or a GUID, not child controls. A robust tray app needs a hidden/message-only window, icon recreation after Explorer restarts, DPI-aware icon resources, and policy-aware notification behavior. The references below are kept because each exposes a different part of that contract.

## Add and update an icon
Link: https://learn.microsoft.com/en-us/windows/win32/shell/notification-area

Contribution: the overview gives the required `NOTIFYICONDATA` state machine. `NIM_ADD` registers the icon, `NIM_SETVERSION` opts into modern callback behavior, and `NIM_MODIFY` updates tooltip/icon text without replacing the identity.

```cpp
constexpr UINT WM_TRAY = WM_APP + 1;

NOTIFYICONDATAW nid = { sizeof(nid) };
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
nid.uCallbackMessage = WM_TRAY;
nid.hIcon = LoadIconW(hInst, MAKEINTRESOURCEW(IDI_APP));
StringCchCopyW(nid.szTip, ARRAYSIZE(nid.szTip), L"Native utility");
Shell_NotifyIconW(NIM_ADD, &nid);

nid.uVersion = NOTIFYICON_VERSION_4;
Shell_NotifyIconW(NIM_SETVERSION, &nid);
```

## Notification policy
Link: https://learn.microsoft.com/en-us/windows/win32/api/shellapi/ne-shellapi-query_user_notification_state

Contribution: `SHQueryUserNotificationState` is the cheap policy gate before showing noisy UI. It tells you whether the user is in quiet time, presentation mode, fullscreen, or otherwise suppressing notifications.

```cpp
QUERY_USER_NOTIFICATION_STATE state = QUNS_ACCEPTS_NOTIFICATIONS;
if (SUCCEEDED(SHQueryUserNotificationState(&state)) &&
    state != QUNS_ACCEPTS_NOTIFICATIONS) {
    QueueToastForLater();
}
```

## Shell hook window messages
Link: https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-registershellhookwindow

Contribution: `RegisterShellHookWindow` lets a normal HWND receive shell lifecycle messages such as top-level window creation/destruction. It is useful for tray/status tools, but it is not a global hook and does not replace UI Automation or ETW for deep observation.

```cpp
UINT shell_msg = RegisterWindowMessageW(L"SHELLHOOK");
RegisterShellHookWindow(hwnd);

// In WndProc:
if (msg == shell_msg && wParam == HSHELL_WINDOWCREATED) {
    HWND created = (HWND)lParam;
}
```

## Thumbnail toolbar buttons
Link: https://learn.microsoft.com/en-us/windows/win32/shell/taskbar-extensions?redirectedfrom=MSDN#thumbbars

Contribution: `ITaskbarList3::ThumbBarAddButtons` is taskbar integration, not tray integration, but tray apps often also own a main window. Keep it here because it is the neighboring shell-notification surface.

```cpp
wil::com_ptr<ITaskbarList3> taskbar;
CoCreateInstance(CLSID_TaskbarList, nullptr, CLSCTX_INPROC_SERVER,
                 IID_PPV_ARGS(&taskbar));

THUMBBUTTON button = {};
button.dwMask = THB_TOOLTIP | THB_ICON;
button.iId = 100;
button.hIcon = LoadIconW(hInst, MAKEINTRESOURCEW(IDI_PAUSE));
StringCchCopyW(button.szTip, ARRAYSIZE(button.szTip), L"Pause");
taskbar->ThumbBarAddButtons(hwnd, 1, &button);
```

Connections: `Tray App Scratch Reference.md` is the small app-shaped example; `Shell Execute.md` handles launching from menu commands; `Shell App Manager (IShellApp).md` and Game Bar notes cover newer app/presence surfaces.
