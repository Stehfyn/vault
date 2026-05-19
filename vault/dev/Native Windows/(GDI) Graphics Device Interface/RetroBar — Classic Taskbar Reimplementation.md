# RetroBar - Classic Taskbar Reimplementation

RetroBar recreates the Windows 95/98/2000/XP/Vista taskbar on modern Windows. It is notable less for GDI specifically than for faithfully reproducing classic shell visuals while handling taskbar responsibilities such as appbar registration, screen-edge reservation, quick launch, tray behavior, and shell integration. A fake taskbar that only paints a bar is easy; one that participates in work-area negotiation is not.

The appbar protocol is the key Native Windows connection: `SHAppBarMessage` with `ABM_NEW`, `ABM_QUERYPOS`, and `ABM_SETPOS` tells the shell and other apps that a desktop edge is occupied. The visual skin is only the surface of a larger shell contract.

## References
- <https://github.com/dremin/RetroBar> - classic taskbar replacement for modern Windows.

## Connections
- `Common Controls/Tray Framework.md` covers the notification-area side at smaller scale.
- Shell entries elsewhere in Native Windows cover appbar and Explorer integration in more depth.
