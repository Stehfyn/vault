# Dark Mode (Uxtheme Ordinals)

The canonical reverse-engineered reference for the undocumented uxtheme.dll dark-mode surface added in Windows 10 1809 (build 17763). Everything in the dark-mode cluster downstream (ozone10/win32-darkmodelib #16, TBOpen/CWin32DarkMode #18, Pixelsuft/win32-darkmode-test #76, ysc3839/ImmersiveContextMenu #83) traces back to the ordinals catalogued here. The key insight: Microsoft never exported these by name, only by ordinal, and the ordinals shifted between 1809 and 1903 — so you must GetProcAddress by ordinal *and* branch on build number. Also documents the per-window opt-in (DwmSetWindowAttribute with the undocumented value 19 on 1809, then 20 from 1903 onward — Microsoft eventually published it as DWMWA_USE_IMMERSIVE_DARK_MODE = 20 in the SDK).

Code contribution: the link contributes ordinal-loaded `uxtheme.dll` functions, `GetProcAddress`, `DwmSetWindowAttribute`, and per-build guards rather than a stable public API contract.

## References
- <https://github.com/ysc3839/win32-darkmode>

## Connections
- `Dark Mode Minimal Test.md` is the smallest harness for validating the ordinal map on a real build.
- `Dark Mode Library (Maintained).md` packages the same surface behind a maintained library boundary.
- `../Common Controls/Dark Mode (C Port).md` is the C-only route for codebases that cannot take a C++ shim.
- `../Common Controls/Visual Styles.md` covers the documented UxTheme side; this note covers the undocumented dark-mode extension around it.
