# Immersive Color Set Reader

Wraps the undocumented `uxtheme!GetImmersiveColorFromColorSetEx` (ordinal 95) + `GetImmersiveColorTypeFromName` (96) + `GetImmersiveUserColorSetPreference` (98) so you can read the Windows accent colors that the official `UISettings::GetColorValue` API only exposes a subset of. Lets you match your app's theming to Explorer's title-bar tint exactly, including the variants by `(highContrast, dark)`. Same approach as the win32-darkmode shim, different ordinal table.

## References
- <https://github.com/MahdiSafsafi/ImmersiveColors>
