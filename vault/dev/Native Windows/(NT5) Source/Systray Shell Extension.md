# Systray Shell Extension

The NT5 systray source is a reminder that notification-area behavior is shell policy layered on top of ordinary windows, messages, timers, and callbacks. The linked executable stub and power component show Explorer loading tray functionality and polling/reporting power state through shell-owned UI, not through some special kernel notification panel.

For modern code, the durable contract is still `Shell_NotifyIcon` plus a callback message, but the surrounding policy changed: notification suppression, quiet hours/focus assist, per-user shell state, DPI, and overflow UI all live above the raw icon API. The source is most useful for understanding why tray icons behave like cooperative clients of Explorer rather than independent always-on UI.

## Connections
- `Shlwapi Utilities` covers adjacent shell helper code.
- `System-Defined Messages` and `NT User Message Definitions` explain the callback-message protocol used by tray clients.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/shell/ext/systray/exestub/systray.c#L51
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/shell/ext/systray/dll/power.c
