# Custom Menubar

Classic menus are awkward to theme because the top menubar is not a normal common control. The `adzm/win32-custom-menubar-aero-theme` technique handles undocumented `WM_UAHDRAWMENU` and `WM_UAHDRAWMENUITEM` messages that `DefWindowProc` uses while drawing the themed menu bar. Intercepting them lets an app paint dark or custom menubar backgrounds without replacing the whole menu system.

This is useful but brittle. The structures are reverse-engineered, the messages are not a stable public contract, and popup menus still have their own theming path. For a controlled desktop tool the trade can be acceptable; for a library, prefer documented owner-draw menus or a full custom frame/menu implementation where the compatibility boundary is explicit.

## References
- <https://github.com/adzm/win32-custom-menubar-aero-theme> - reverse-engineered UAH menubar draw-message handling.

## Connections
- `Darkmode.md` explains why menu bars lag behind the rest of Windows dark mode.
- `Modify Context Menu.md` is the popup-menu counterpart, using a different interception technique.
