# Tray Framework

A tray app is a hidden or minimal HWND plus `Shell_NotifyIcon`. `NOTIFYICONDATA` registers the icon, tooltip, and callback message; the window proc handles mouse notifications and usually opens a popup menu after `SetForegroundWindow` so the menu dismisses correctly. Cleanup with `NIM_DELETE` is part of the contract, not an optional nicety.

`marek/trayframework` is useful because it distills that plumbing into the smallest reusable shape. For production code, add Explorer-restart recovery (`TaskbarCreated` registered message), versioned `NOTIFYICONDATA` behavior, DPI-appropriate icons, and explicit lifetime management for menus and icons.

## References
- <https://github.com/marek/trayframework> - minimal Win32 notification-area framework.

## Connections
- `Window Messaging.md` covers private callback messages and registered messages.
- Shell entries elsewhere in Native Windows cover richer notification-area and taskbar behavior.
