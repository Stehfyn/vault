# win10toast - Python Tray Balloon Toasts

`win10toast` is a pywin32 wrapper around the shell notification-area balloon mechanism, not a full WinRT toast library. Internally it creates a small window and calls `Shell_NotifyIcon` with `NIF_INFO`; Windows 10/11 may render that through notification UI, but the app is not submitting a WinRT toast XML payload and does not get the same activation model.

That distinction is the entire reason to keep the note. Use it for quick Python status popups in scripts and admin tools. Do not use it as evidence that unpackaged apps can ignore AUMIDs, notification activation COM servers, or the Windows App SDK app-notification path when they need production-grade toasts.

## References
- <https://github.com/jithurjacob/Windows-10-Toast-Notifications> - small pywin32 tray-balloon wrapper commonly confused with modern WinRT toast APIs.
