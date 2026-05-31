# Transparent Window GDI

Per-pixel transparent top-level windows use `WS_EX_LAYERED` with `UpdateLayeredWindow`. The source DC must contain a 32-bpp bitmap with premultiplied alpha, and `BLENDFUNCTION` normally uses `AC_SRC_OVER` plus `AC_SRC_ALPHA`. This bypasses ordinary `WM_PAINT` presentation: you update the layered surface explicitly.

Layered windows are useful for overlays, splash windows, shaped UI, and lenses, but they are not a general replacement for child-control composition. Hit testing, capture, screen capture visibility, DWM interaction, and performance all differ from a normal overlapped window. For simple whole-window translucency, `SetLayeredWindowAttributes` is easier but less expressive.

## UpdateLayeredWindow Shape

The source surface is a memory DC containing a 32-bpp premultiplied-alpha DIB. `UpdateLayeredWindow` atomically hands that bitmap to USER/DWM as the top-level window image; it is not a normal `WM_PAINT` repaint.

```cpp
SetWindowLongPtr(hwnd, GWL_EXSTYLE,
    GetWindowLongPtr(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);

POINT dst = { x, y };
SIZE size = { width, height };
POINT src = { 0, 0 };
BLENDFUNCTION blend = {};
blend.BlendOp = AC_SRC_OVER;
blend.SourceConstantAlpha = 255;
blend.AlphaFormat = AC_SRC_ALPHA;

UpdateLayeredWindow(hwnd, screen_dc, &dst, &size,
    mem_dc_with_premultiplied_dib, &src, 0, &blend, ULW_ALPHA);
```

If the pixels come from WIC, convert to `GUID_WICPixelFormat32bppPBGRA` before copying into the DIB. If the pixels come from GDI drawing, route through `Alpha Blending a Bitmap.md` and verify premultiplication before blaming DWM.

## References
- <https://stackoverflow.com/questions/29038024/drawing-a-window-with-a-standard-frame-and-transparent-contents> - discusses standard frame plus transparent/layered contents.

## Connections
- `Alpha Blending a Bitmap.md` covers premultiplied alpha.
- `Common Controls/Borderless Window.md` covers the custom-frame half of transparent UI.
- `WIC Image Loading.md` is the clean decode path for premultiplied BGRA pixels.
- `../(DX) DirectX/Windows Composition Engine.md` is the GPU/DComp alternative for transparent top-level composition.
- `../(DWM) Desktop Window Manager/Capture-Protected Window (Sprite Hack).md` is the opposite concern: not transparency, but whether capture should see the surface.
