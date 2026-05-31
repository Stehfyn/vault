# Tray Framework

A tray app is a hidden or minimal HWND plus `Shell_NotifyIcon`. `NOTIFYICONDATA` registers the icon, tooltip, and callback message; the window proc handles mouse notifications and usually opens a popup menu after `SetForegroundWindow` so the menu dismisses correctly. Cleanup with `NIM_DELETE` is part of the contract, not an optional nicety.

`marek/trayframework` is useful because it distills that plumbing into the smallest reusable shape. For production code, add Explorer-restart recovery (`TaskbarCreated` registered message), versioned `NOTIFYICONDATA` behavior, DPI-appropriate icons, and explicit lifetime management for menus and icons.

## Source Shape

The tray icon is a message route through a hidden owner HWND. Register the icon, handle the callback message, and remove it on shutdown.

```cpp
constexpr UINT WM_TRAYICON = WM_APP + 10;

NOTIFYICONDATAW nid = { sizeof(nid) };
nid.hWnd = hwnd;
nid.uID = 1;
nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
nid.uCallbackMessage = WM_TRAYICON;
nid.hIcon = LoadIconW(instance, MAKEINTRESOURCEW(IDI_APP));
StringCchCopyW(nid.szTip, ARRAYSIZE(nid.szTip), L"App");
Shell_NotifyIconW(NIM_ADD, &nid);

// On shutdown:
Shell_NotifyIconW(NIM_DELETE, &nid);
```

Explorer restart recovery is just a registered message plus re-add.

```cpp
UINT taskbar_created = RegisterWindowMessageW(L"TaskbarCreated");
if (msg == taskbar_created) {
    Shell_NotifyIconW(NIM_ADD, &nid);
}
```

## Source Code Reading

`trayframework.c` is valuable because it does not hide the tray icon behind a framework object. The relevant globals are `HWND hWnd`, `HINSTANCE hInst`, `NOTIFYICONDATA structNID`, and `BOOL Enabled`; the sample is a stateful hidden-window program.

`WinMain` does the lifetime setup in this order:

```cpp
CreateMutex(...)                         // single-instance gate
InitCommonControlsEx(&iccex)             // only if the app uses common controls
RegisterClassEx(&wc)                     // wc.lpfnWndProc = WndProc
CreateWindowEx(..., "Tray Application")  // hidden owner HWND

structNID.cbSize = sizeof(NOTIFYICONDATA);
structNID.hWnd = hWnd;
structNID.uID = IDI_TRAYICON;
structNID.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
structNID.uCallbackMessage = WM_USER_SHELLICON;
Shell_NotifyIcon(NIM_ADD, &structNID);
```

The `WndProc` contains the contracts readers usually miss:

- `if (Message == WM_TASKBAR_CREATE)` re-adds the icon after Explorer/taskbar recreation. The macro expands to `RegisterWindowMessage("TaskbarCreated")`, so it is not a fixed numeric message.
- `WM_USER_SHELLICON` receives mouse notifications in `lParam`, not in `Message`. The sample switches on `LOWORD(lParam)` and reacts to `WM_RBUTTONDOWN`.
- The popup menu path is `GetCursorPos` -> `LoadMenu` -> `GetSubMenu` -> `CheckMenuItem` -> `SetForegroundWindow` -> `TrackPopupMenu` -> `SendMessage(hwnd, WM_NULL, 0, 0)` -> `DestroyMenu`.
- `WM_DESTROY` calls `Shell_NotifyIcon(NIM_DELETE, &structNID)` before `PostQuitMessage`. Without this, the notification area can retain a dead icon until shell cleanup catches up.

The important observable outcome is that the tray icon is just a Shell-owned UI surface calling back into your HWND. If callback handling blocks, your tray menu feels broken; if cleanup is skipped, the shell shows stale state; if `TaskbarCreated` is ignored, Explorer restart silently removes your app's only UI.

## References
- <https://github.com/marek/trayframework> - minimal Win32 notification-area framework.

## Connections
- `Window Messaging.md` covers private callback messages and registered messages.
- Shell entries elsewhere in Native Windows cover richer notification-area and taskbar behavior.
- `../Message Queue/System-Defined Messages.md` explains the `WM_APP`/registered-message split used by tray callbacks.
- `Modify Context Menu.md` and `../Custom Frame/Acrylic Popup Menus.md` are adjacent popup-menu customization routes once a tray icon opens a menu.
