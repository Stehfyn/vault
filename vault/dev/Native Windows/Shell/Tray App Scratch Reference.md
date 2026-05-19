# Tray App Scratch Reference

`whosalive` is a small tray/status widget that is useful less for its product idea than for its shell shape: hidden/message-only window, `Shell_NotifyIcon`, icon lifetime, tooltip/menu behavior, and redraw/update loops. Tray apps are deceptively easy until Explorer restarts, DPI changes, or the notification icon needs to be recreated.

Connect this to `Notification Area (Tray)`, `Shell Execute`, and `Master Volume Control`. Many desktop utilities live entirely in this pattern: background state, a notification icon, and a small native surface instead of a normal main window.

## References
- <https://github.com/fadan/whosalive>
