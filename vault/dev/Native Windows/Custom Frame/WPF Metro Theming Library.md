# WPF Metro Theming Library

WPF (not Win32 — this one is the odd-one-out in this dump) theming library that mimics the VS2012+ "Modern" look: flat chrome, accent-colored title bar, dark/light swap at runtime via merged ResourceDictionaries. Notable for being one of the few WPF theme libs that hooks `SystemParameters` and the Windows accent-color broadcast (`WM_DWMCOLORIZATIONCOLORCHANGED`) so the app tracks the user's personalization changes live, instead of requiring a restart.

## References
- <https://github.com/Grabacr07/MetroRadiance>
