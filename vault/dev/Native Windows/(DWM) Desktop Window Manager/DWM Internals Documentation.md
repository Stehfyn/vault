# DWM Internals Documentation

The most thorough community write-up of how the Desktop Window Manager actually works under the hood: the per-monitor composition tree, the role of `dwmcore.dll` vs `udwm.dll` vs `uDWM`'s renderer thread, how `DwmEnableBlurBehindWindow` (deprecated since 8) and the modern `DwmSetWindowAttribute(DWMWA_SYSTEMBACKDROP_TYPE)` route through the composition engine, and the undocumented `IDCompositionDevice`-private interfaces that things like Mica and Acrylic are built on. Worth reading because Microsoft's own docs stop at the public `dwmapi.h` surface, which has been frozen for years while the actual capabilities of DWM have shipped almost entirely behind undocumented attributes and private COM interfaces — the gap is what every modern Windows theming project (Mica enabler, Acrylic-everywhere, OpenGlass) lives in. Also documents the DWM thumbnail relationship (`DwmRegisterThumbnail`), which is the only sanctioned way to read another window's composited contents on modern Windows since the old `BitBlt(GetDC(NULL))` path was broken by DWM's offscreen rendering. (cf. notr1ch/DWMCapture for the practical "capture from DWM surfaces" application, and kawapure's repo cross-references many of the same primitives the ALTaleX531 projects depend on.)

```cpp
// The modern backdrop API (Windows 11 22H2+). All the magic happens in DWM;
// the app just declares intent. Requires DwmExtendFrameIntoClientArea with
// nonzero margins on the same window to actually see the backdrop bleed in.
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")

// DWMWA_SYSTEMBACKDROP_TYPE = 38 (DWMWINDOWATTRIBUTE)
// Values: 1=Auto 2=None 3=Mica 4=Acrylic 5=Tabbed
enum DWM_SYSTEMBACKDROP_TYPE { DWMSBT_AUTO=1, DWMSBT_NONE=2,
    DWMSBT_MAINWINDOW=3, DWMSBT_TRANSIENTWINDOW=4, DWMSBT_TABBEDWINDOW=5 };

void EnableMica(HWND hwnd, bool dark) {
    MARGINS m{ -1, -1, -1, -1 };               // extend frame into entire client
    DwmExtendFrameIntoClientArea(hwnd, &m);

    BOOL useDark = dark ? TRUE : FALSE;
    DwmSetWindowAttribute(hwnd, /*DWMWA_USE_IMMERSIVE_DARK_MODE*/ 20,
                          &useDark, sizeof(useDark));

    int backdrop = DWMSBT_MAINWINDOW;          // Mica
    DwmSetWindowAttribute(hwnd, /*DWMWA_SYSTEMBACKDROP_TYPE*/ 38,
                          &backdrop, sizeof(backdrop));
    // On <22H2, fall back to the undocumented SetWindowCompositionAttribute
    // with WCA_ACCENT_POLICY=ACCENT_ENABLE_HOSTBACKDROP — that's the path
    // ysc3839/win32-darkmode and the ALTaleX531 projects use.
}
```

## References
- <https://github.com/kawapure/DWM-Documentation>
- Related: `DwmGetDxSharedSurface Window Capture.md`, `DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`, `OpenGlass (Aero Blur Restoration).md`
