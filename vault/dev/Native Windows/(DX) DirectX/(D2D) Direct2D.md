# Direct2D

Direct2D has two practical entry points on Win32. `ID2D1HwndRenderTarget` is the simple path for a single HWND: easy resize handling, direct `BeginDraw`/`EndDraw`, and `D2DERR_RECREATE_TARGET` recovery. `ID2D1DeviceContext` is the modern path: create it from a DXGI device, target it at a DXGI surface/bitmap, and share the same adapter/swap-chain world as D3D11, DirectComposition, and Media Foundation. The distinction matters because DComp/Mica/layered-window work usually needs the DXGI-backed device-context path, while old MFC controls are often cleaner with an HWND render target.

The linked samples cover the real failure modes: GDI interop via `ID2D1DCRenderTarget`, DirectWrite layout/hit-testing, custom text rendering through `IDWriteTextRenderer`, RichEdit hosted into a D2D surface, multithreaded factory locking, premultiplied BGRA alpha, and bitmap upload stride rules. Treat these as a map of boundaries, not tutorials: once you cross into DComp or D3D, pixel format, alpha mode, device loss, and adapter identity become the load-bearing details.

## HWND Render Target

The `ID2D1HwndRenderTarget` link contributes the classic window-control shape: bind D2D to one HWND, resize on `WM_SIZE`, and recreate resources if `EndDraw` reports target loss.

```cpp
D2D1_RENDER_TARGET_PROPERTIES props =
    D2D1::RenderTargetProperties(D2D1_RENDER_TARGET_TYPE_DEFAULT);
D2D1_HWND_RENDER_TARGET_PROPERTIES hwnd_props =
    D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(width, height));

wil::com_ptr<ID2D1HwndRenderTarget> target;
factory->CreateHwndRenderTarget(props, hwnd_props, &target);

target->BeginDraw();
target->Clear(D2D1::ColorF(D2D1::ColorF::White));
HRESULT hr = target->EndDraw();
if (hr == D2DERR_RECREATE_TARGET) {
    target.reset();
}
```

## DXGI-Backed Device Context

The D2D device-context and Mica/DComp examples contribute the modern composition shape: create D2D from the same DXGI device family as the swap chain or composition surface, then target a BGRA premultiplied bitmap.

```cpp
wil::com_ptr<IDXGIDevice> dxgi_device;
d3d_device.query_to(&dxgi_device);

wil::com_ptr<ID2D1Device> d2d_device;
d2d_factory->CreateDevice(dxgi_device.get(), &d2d_device);

wil::com_ptr<ID2D1DeviceContext> dc;
d2d_device->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &dc);

D2D1_BITMAP_PROPERTIES1 bitmap_props = D2D1::BitmapProperties1(
    D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
    D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
```

## GDI, Text, and Alpha Boundaries

The GDI interop sample contributes the HDC boundary, the DirectWrite samples contribute layout/drawing callbacks, and the pixel-format reference explains why straight-alpha images produce dark fringes in D2D targets expecting premultiplied BGRA.

```cpp
D2D1_RECT_U dirty = D2D1::RectU(0, 0, width, height);
wil::com_ptr<ID2D1DCRenderTarget> dc_target;
factory->CreateDCRenderTarget(&props, &dc_target);
dc_target->BindDC(hdc, &dirty);

text_layout->Draw(client_context, text_renderer, origin_x, origin_y);
```

## References
- <https://github.com/wangwenx190/d2d-mica> - D2D/DComp device-context setup for Mica-like effects.
- <https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample> - DC render target bridge for mixed GDI/D2D code.
- <https://learn.microsoft.com/en-us/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget> - HWND render target lifecycle.
- <https://learn.microsoft.com/en-us/windows/win32/direct2d/devices-and-device-contexts#how-to-create-a-direct2d-device-context-for-rendering> - DXGI-backed D2D device context.
- <https://github.com/fdwr/TextLayoutSampler> - DirectWrite metrics compared against other Windows text stacks.
- <https://github.com/xoofx/CustomFormattingDemo> - `IDWriteTextLayout::SetDrawingEffect` plus custom renderers.
- <https://devblogs.microsoft.com/math-in-office/richeditd2d-window-controls/> - Windowless RichEdit rendered through D2D/HDC hosting.
- <https://learn.microsoft.com/en-us/windows/win32/direct2d/supported-pixel-formats-and-alpha-modes> - BGRA/premultiplied-alpha rules.

## Connections
- `Direct2D and DirectWrite in C.md`
- `Direct2D and DirectWrite in MFC.md`
- `Windows Composition Engine.md`
- `Text Stack Side-by-Side Sampler.md`
