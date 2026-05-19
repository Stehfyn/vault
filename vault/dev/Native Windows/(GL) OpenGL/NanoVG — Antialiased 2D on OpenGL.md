# NanoVG — Antialiased 2D on OpenGL

NanoVG is an immediate-mode 2D vector drawing API backed by OpenGL. It is valuable for tooling UIs, overlays, and visualization panels where paths, strokes, gradients, text, and antialiasing are needed but a full retained UI framework is overkill.

The tradeoff is that NanoVG owns a chunk of GL state and rendering policy. In a serious renderer, isolate its pass, restore state deliberately, and account for sRGB/premultiplied-alpha behavior if compositing over D3D/DXGI or DWM surfaces.

## References
- <https://github.com/memononen/nanovg>

## Connections
- `Header-Only OpenGL Vector Graphics.md`
