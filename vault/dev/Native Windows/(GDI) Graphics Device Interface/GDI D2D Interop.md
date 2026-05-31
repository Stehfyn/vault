# GDI D2D Interop

The Direct2D `ID2D1DCRenderTarget` is the intended bridge when a Direct2D scene must render into a GDI `HDC`, such as during `WM_PAINT` from a classic HWND. Create the DC render target with a compatible pixel format, call `BindDC` for the paint rectangle, then `BeginDraw` / `EndDraw`. This is not the same as hosting stock GDI controls inside a Direct2D render target; it simply lets Direct2D draw to a DC-backed surface.

Use this for incremental modernization: keep the HWND/message/control model, but draw selected content with D2D/DirectWrite. For full-frame GPU composition, prefer an HWND render target, swap chain, or DirectComposition path rather than repeatedly binding a GDI DC.

## Source Code Reading

The Microsoft `GdiInteropSample.cpp` is intentionally small, which makes it good probe material. `DemoApp::CreateDeviceIndependentResources` creates the D2D factory. `DemoApp::CreateDeviceResources` creates an `ID2D1DCRenderTarget`, not an HWND render target. `DemoApp::OnRender` receives the `PAINTSTRUCT`, calls `GetClientRect`, binds the current paint HDC with `ID2D1DCRenderTarget::BindDC`, runs `BeginDraw`/draw commands/`EndDraw`, and returns the HRESULT to the normal `WM_PAINT` handler.

```cpp
// Source-shaped from GdiInteropSample.cpp.
CreateDCRenderTarget(&props, &dc_target);

case WM_PAINT:
    BeginPaint(hwnd, &ps);
    rect = client rect;
    dc_target->BindDC(ps.hdc, &rect);
    dc_target->BeginDraw();
    dc_target->SetTransform(Identity());
    // D2D draws into the GDI paint DC here.
    hr = dc_target->EndDraw();
    EndPaint(hwnd, &ps);
```

The lifetime rule is the lesson: the HDC belongs to GDI/USER for one paint; the D2D DC render target is reusable; `BindDC` is the per-paint bridge. A good experiment alternates pure GDI fill/text with D2D fill/text inside the same `WM_PAINT` and logs `BindDC`, `BeginDraw`, and `EndDraw` costs. If `EndDraw` returns target loss, recreate the D2D render target, not the HWND.

## References
- <https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample> - Microsoft GDI/D2D interop sample.
- <https://raw.githubusercontent.com/microsoft/Windows-classic-samples/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample/GdiInteropSample.cpp> - source showing `CreateDCRenderTarget` and `BindDC`.

## Connections
- `Common Controls/Rendering.md` covers the same interop boundary from the control side.
