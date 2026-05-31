# Immersive Context Menu (Explorer Look-Alike)

Reverse-engineered reimplementation of Explorer's "Immersive" context-menu look (the rounded, padded, dark-mode-aware popup menus File Explorer uses) by the same author as ysc3839/win32-darkmode (#25). The catch the README calls out: turning on `MNS_OWNERDRAW` for the whole menu reverts the chrome (separators, check marks, border) to the Windows 95 ownerdraw style — so the implementation has to repaint *everything*, not just the items, to keep it modern. Distinct from the uxtheme-ordinal `SetPreferredAppMode(135)` / `AllowDarkModeForWindow(133)` trick used in win32-darkmode — that one only restyles built-in controls; this one literally replaces the menu renderer. Tangentially cf. krlvm/AcrylicMenus (#69) for the acrylic-blur variant.

## References
- <https://github.com/ysc3839/ImmersiveContextMenu>

## Source Code Reading

`ysc3839/ImmersiveContextMenu` is a renderer replacement, not a backdrop trick. The key files are `ImmersiveContextMenu.cpp`, `ImmersiveContextMenu.hpp`, and `UxThemeHelper.hpp`.

The sample window forwards `WM_DRAWITEM` and `WM_MEASUREITEM` to `ImmersiveContextMenu::ContextMenuWndProc`. On `WM_CREATE`, it walks the app menu and calls:

```cpp
ApplyOwnerDrawToMenu(submenu, hwnd, nullptr,
    ICMO_USEPPI | ICMO_FORCEMOUSESTYLING, &cmrdArray);
```

`ApplyOwnerDrawToMenu` checks compatibility, iterates menu items with `GetMenuItemInfoW`, builds a `ContextMenuRenderingData` record containing text, item bitmaps, padding mode, scale type, DPI, dark-theme flag, and system-padding flag, then sets `MFT_OWNERDRAW` through `SetMenuItemInfoW`. If it cannot use `dwItemData` directly, it stores render data as an HWND property.

Rendering is split:

- `_OnMeasureItem` computes item dimensions from theme metrics, menu font, separator rules, DPI/PPI scaling, and padding mode.
- `_OnDrawItem` opens `DarkMode_ImmersiveStart::Menu`, `LightMode_ImmersiveStart::Menu`, or `ImmersiveStart::Menu`, calls `DrawThemeBackground`, then draws text via `DrawThemeTextEx` with font-weight tweaks from `UxThemeHelper.hpp`.
- `OverrideBackgroundColor` calls `SetMenuInfo(MIM_BACKGROUND)` so the popup background follows the immersive theme.

Cleanup is symmetrical. `RemoveOwnerDrawFromMenu` walks the tree, removes stored render data, unsets `MFT_OWNERDRAW`, restores background brush state, and clears HWND properties.

### Claim -> Probe

Claim from the README: once `MNS_OWNERDRAW` / owner draw is used, built-in menu chrome falls back unless you repaint everything. Probe by owner-drawing only text for one menu, then compare separators, checks, hot state, and border against the full renderer. Interpretation: owner-draw is an all-or-nothing contract for visual fidelity.
