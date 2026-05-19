# Transparent Window GDI

Per-pixel transparent top-level windows use `WS_EX_LAYERED` with `UpdateLayeredWindow`. The source DC must contain a 32-bpp bitmap with premultiplied alpha, and `BLENDFUNCTION` normally uses `AC_SRC_OVER` plus `AC_SRC_ALPHA`. This bypasses ordinary `WM_PAINT` presentation: you update the layered surface explicitly.

Layered windows are useful for overlays, splash windows, shaped UI, and lenses, but they are not a general replacement for child-control composition. Hit testing, capture, screen capture visibility, DWM interaction, and performance all differ from a normal overlapped window. For simple whole-window translucency, `SetLayeredWindowAttributes` is easier but less expressive.

## References
- <https://stackoverflow.com/questions/29038024/drawing-a-window-with-a-standard-frame-and-transparent-contents> - discusses standard frame plus transparent/layered contents.

## Connections
- `Alpha Blending a Bitmap.md` covers premultiplied alpha.
- `Common Controls/Borderless Window.md` covers the custom-frame half of transparent UI.
