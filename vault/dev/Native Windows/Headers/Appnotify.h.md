# Appnotify.h

Public app-state notification surface for packaged/UWP-style process lifetime: `RegisterAppStateChangeNotification` tells code when the app is suspending, resuming, entering background, leaving background, or hitting low-memory pressure. Classic Win32 apps are used to `WM_POWERBROADCAST`, session messages, and process lifetime being under their own control; packaged apps add brokered suspend/resume semantics where background work must be checkpointed quickly and handles may outlive visible UI. This header is the lightweight C ABI side of that model.

Connections: `statehelpers.h.md` wraps the same cluster; `(WinRT) Windows Runtime/Sandboxing Win32 Apps via MSIX.md` and Windows Installer/MSIX notes explain why app identity changes lifetime, storage, and notification behavior.

## References
- Appnotify.h
