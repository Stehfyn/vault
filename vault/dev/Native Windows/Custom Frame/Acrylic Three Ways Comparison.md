# Acrylic Three Ways Comparison

Archived (Sep 2022) side-by-side comparison of *three* ways to put acrylic behind a Win32 window — UWP XAML Island hosting a `Microsoft.UI.Xaml.Controls.AcrylicBrush`, raw `IDCompositionDevice`/`IDCompositionVisual` trees, and the undocumented `SetWindowCompositionAttribute(WCA_ACCENT_POLICY)` path. The pedagogical value is in seeing them in one tree: the DComp variant is the only one that actually composes correctly on Win11 with rounded corners, the SWCA variant is the smallest and the one Microsoft would prefer you never used, the XAML Island variant is the most "supported" but drags in the entire WinRT toolchain. Sibling to ALTaleX531/Win32Acrylic (#14) and the cluster at ahmed605/10Mica (#61), Maplespe/DWMBlurGlass (#54), selastingeorge/Win32-Acrylic-Effect (#68), krlvm/AcrylicMenus (#69).

## References
- <https://github.com/wangwenx190/Win32Acrylic>
