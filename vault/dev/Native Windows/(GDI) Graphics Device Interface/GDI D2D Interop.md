# GDI D2D Interop

The Direct2D `ID2D1DCRenderTarget` is the intended bridge when a Direct2D scene must render into a GDI `HDC`, such as during `WM_PAINT` from a classic HWND. Create the DC render target with a compatible pixel format, call `BindDC` for the paint rectangle, then `BeginDraw` / `EndDraw`. This is not the same as hosting stock GDI controls inside a Direct2D render target; it simply lets Direct2D draw to a DC-backed surface.

Use this for incremental modernization: keep the HWND/message/control model, but draw selected content with D2D/DirectWrite. For full-frame GPU composition, prefer an HWND render target, swap chain, or DirectComposition path rather than repeatedly binding a GDI DC.

## References
- <https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample> - Microsoft GDI/D2D interop sample.
- <https://raw.githubusercontent.com/microsoft/Windows-classic-samples/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample/GdiInteropSample.cpp> - source showing `CreateDCRenderTarget` and `BindDC`.

## Connections
- `Common Controls/Rendering.md` covers the same interop boundary from the control side.
