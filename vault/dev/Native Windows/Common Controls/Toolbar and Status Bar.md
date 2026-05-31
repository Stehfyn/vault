# Toolbar and Status Bar

Toolbars and status bars are comctl32 controls, not decorative strips. A toolbar needs `TB_BUTTONSTRUCTSIZE` before `TB_ADDBUTTONS`, an image list sized for the current DPI, and command IDs that flow back through `WM_COMMAND`. A status bar uses `SB_SETPARTS` with right-edge coordinates; `-1` makes the final pane stretch, and forwarding `WM_SIZE` lets the control recompute its own height and position.

The old MSDN toolbar/status-bar material is still useful because these controls have not fundamentally changed. Modern polish comes from the surrounding contracts: comctl32 v6 activation, visual styles, DPI-scaled image lists, and owner/custom draw only where the stock rendering cannot match the application.

## Source Shape

Toolbar setup has an ordering requirement: create the control, send `TB_BUTTONSTRUCTSIZE`, attach image state, then add buttons.

```cpp
HWND toolbar = CreateWindowExW(0, TOOLBARCLASSNAMEW, nullptr,
    WS_CHILD | WS_VISIBLE | TBSTYLE_FLAT | TBSTYLE_TOOLTIPS,
    0, 0, 0, 0, parent, nullptr, instance, nullptr);

SendMessageW(toolbar, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0);
SendMessageW(toolbar, TB_SETIMAGELIST, 0, reinterpret_cast<LPARAM>(images));
SendMessageW(toolbar, TB_ADDBUTTONS, ARRAYSIZE(buttons),
             reinterpret_cast<LPARAM>(buttons));
```

Status bars size themselves from `WM_SIZE`, but parts are right-edge coordinates.

```cpp
int parts[] = { ScaleForDpi(160, dpi), ScaleForDpi(320, dpi), -1 };
SendMessageW(status, SB_SETPARTS, ARRAYSIZE(parts),
             reinterpret_cast<LPARAM>(parts));
SendMessageW(status, WM_SIZE, 0, 0);
```

## References
- <https://learn.microsoft.com/en-us/previous-versions/ms810439(v=msdn.10)?redirectedfrom=MSDN> - classic toolbar/status-bar programming reference.

## Connections
- `Custom Toolbar Header.md` covers custom drawing around toolbar/header surfaces.
- `Visual Styles.md` covers the comctl32 v6 and theming setup.
- `../DPI Awareness/Per-Monitor V2 DPI Reference.md` is required for DPI-scaled image lists and part widths.
- `Window Messaging.md` explains the `WM_COMMAND` route from toolbar button IDs back to the parent.
