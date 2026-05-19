# Immersive Context Menu (Explorer Look-Alike)

Reverse-engineered reimplementation of Explorer's "Immersive" context-menu look (the rounded, padded, dark-mode-aware popup menus File Explorer uses) by the same author as ysc3839/win32-darkmode (#25). The catch the README calls out: turning on `MNS_OWNERDRAW` for the whole menu reverts the chrome (separators, check marks, border) to the Windows 95 ownerdraw style — so the implementation has to repaint *everything*, not just the items, to keep it modern. Distinct from the uxtheme-ordinal `SetPreferredAppMode(135)` / `AllowDarkModeForWindow(133)` trick used in win32-darkmode — that one only restyles built-in controls; this one literally replaces the menu renderer. Tangentially cf. krlvm/AcrylicMenus (#69) for the acrylic-blur variant.

## References
- <https://github.com/ysc3839/ImmersiveContextMenu>
