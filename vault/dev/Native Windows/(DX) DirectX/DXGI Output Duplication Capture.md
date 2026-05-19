# DXGI Output Duplication Capture

ScreenEx is a concrete use of DXGI Output Duplication: acquire frames from an `IDXGIOutputDuplication`, inspect dirty/move rects, and copy the desktop image out of the GPU path. This is monitor capture, not HWND capture. It sees the post-composition output for an output, so it is the right primitive for screenshot/recording tools and the wrong primitive when you need a hidden or occluded window's independent surface.

That distinction connects it directly to DWM capture notes. `DwmGetDxSharedSurface Window Capture.md` targets per-window DWM redirection surfaces; Output Duplication targets the final output image. Capture-protected windows can also affect what duplication returns.

## References
- <https://github.com/MurkyYT/ScreenEx>

## Connections
- `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md`
- `Screen Capture to H.264.md`
- `../(DWM) Desktop Window Manager/Capture-Protected Window (Sprite Hack).md`
