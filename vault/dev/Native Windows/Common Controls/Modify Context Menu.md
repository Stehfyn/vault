# Modify Context Menu

The gist demonstrates a narrow but useful hack: when a stock control shows its default context menu, install a same-thread `SetWinEventHook` for `EVENT_SYSTEM_MENUPOPUPSTART`, obtain the live `HMENU` from the menu window using the undocumented `MN_GETHMENU`, then insert, disable, or delete menu items before it is displayed. This targets menus you do not otherwise own, such as the default Edit control menu.

The fragility is the point. If you own the menu, build it yourself in `WM_CONTEXTMENU`. If you only subclass the control and need to surgically alter the system-provided menu, this technique works because it intercepts the popup at creation time. Keep the hook lifetime short and same-thread to avoid broad accessibility-event side effects.

## References
- <https://gist.github.com/michelesalvador/4a26852657521298f1f8c95cca77cb03> - default Edit context-menu modification using WinEvent and `MN_GETHMENU`.

## Connections
- `Custom Menubar.md` is a different undocumented menu-drawing path.
- `Window Messaging.md` covers why subclassing alone is not enough once USER owns the popup menu window.
