# win10toast - Python Tray Balloon Toasts

`win10toast` is a pywin32 wrapper around the shell notification-area balloon mechanism, not a full WinRT toast library. Internally it creates a small window and calls `Shell_NotifyIcon` with `NIF_INFO`; Windows 10/11 may render that through notification UI, but the app is not submitting a WinRT toast XML payload and does not get the same activation model.

That distinction is the entire reason to keep the note. Use it for quick Python status popups in scripts and admin tools. Do not use it as evidence that unpackaged apps can ignore AUMIDs, notification activation COM servers, or the Windows App SDK app-notification path when they need production-grade toasts.

## Source Code Reading

The repository's entire native shape is in `win10toast/__init__.py`. `ToastNotifier._show_toast` registers a hidden window class named `PythonTaskbar`, creates a basic overlapped window, loads an `.ico`, adds a notification-area icon, then modifies that icon with `NIF_INFO`. `on_destroy` deletes the tray icon and posts quit.

```python
wc.lpfnWndProc = { WM_DESTROY: self.on_destroy }
hwnd = CreateWindow(classAtom, "Taskbar", WS_OVERLAPPED | WS_SYSMENU, ...)
Shell_NotifyIcon(NIM_ADD, (hwnd, 0, NIF_ICON | NIF_MESSAGE | NIF_TIP, ...))
Shell_NotifyIcon(NIM_MODIFY, (hwnd, 0, NIF_INFO, ..., msg, 200, title))
```

There is no `RoInitialize`, no `RoGetActivationFactory`, no `IXmlDocument`, no AUMID property store, and no activation callback. The "toast" is a shell balloon surfaced through notification-area compatibility behavior. That is exactly why it is useful for small scripts and exactly why it should not be cited as a modern toast implementation.

The threaded mode is also intentionally shallow: `show_toast(..., threaded=True)` starts a Python `threading.Thread` and refuses to start a second notification while the first thread is alive. It is not an OLE/COM message pump, and the lifetime is timer-based (`sleep(duration)` then `DestroyWindow`), not event-driven toast dismissal.

## References
- <https://github.com/jithurjacob/Windows-10-Toast-Notifications> - small pywin32 tray-balloon wrapper commonly confused with modern WinRT toast APIs.
