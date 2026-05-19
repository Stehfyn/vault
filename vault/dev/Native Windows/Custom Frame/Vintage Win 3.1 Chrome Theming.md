# Vintage Win 3.1 Chrome Theming

Vintage window-chrome theming utility — paints Windows 3.1 / OS/2-style title bars and frame controls on modern NT systems, in the spirit of WindowBlinds and the old uxtheme.dll patches. Written almost entirely in C (the repo is ~98% C, 1% C++) and targets XP through Windows 11 on x86/x64. The interesting part is the scope: not just a single themed window but a system-wide non-client repaint, which is why most projects in this corner of Win32 either replace uxtheme.dll or hijack `WM_NCPAINT` / `WM_NCACTIVATE` through a CBT or `WH_CALLWNDPROC` hook injected into every process. Despite the name, this has nothing to do with cascading shell submenus.

## References
- <https://github.com/Vortesys/Cascades>
