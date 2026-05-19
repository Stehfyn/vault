# Capture-Protected Window (Sprite Hack)

Marks a window as capture-protected by routing through `win32kfull!GreProtectSpriteContent`, the same internal routine that backs `SetWindowDisplayAffinity(WDA_EXCLUDEFROMCAPTURE)` (added in Windows 10 2004) but reached directly so it works regardless of the public API's gating. The result: PrintScreen, Win+Shift+S, `BitBlt(CAPTUREBLT)`, and DXGI desktop-duplication all see a black rectangle where your window is. The trick relies on DWM sprite-layer compositing — pre-DWM capture paths (GDI screen DC on Win7-style fallback) still see the content.

```cpp
// the public API equivalent — what NoScreen reaches via the kernel symbol:
#ifndef WDA_EXCLUDEFROMCAPTURE
#define WDA_EXCLUDEFROMCAPTURE 0x00000011 // Win10 2004+
#endif
SetWindowDisplayAffinity(hwnd, WDA_EXCLUDEFROMCAPTURE);
// Caveats worth knowing:
//  - DWM must be running; basic/safe-mode renders the window normally to capture
//  - WDA_MONITOR (0x1) gives a black frame in capture but still HW-overlays on screen
//  - Game Bar / OBS via DXGI Output Duplication both honor the sprite-protect bit
//  - Accessibility tools using UI Automation still see the tree
```

## References
- <https://github.com/KANKOSHEV/NoScreen>
- Related: `DwmGetDxSharedSurface Window Capture.md`, `DXGI Output Duplication Capture.md`, `DWM Internals Documentation.md`
