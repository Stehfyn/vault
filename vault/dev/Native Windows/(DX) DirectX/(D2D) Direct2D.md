# Direct2D

## d2d-mica
https://github.com/wangwenx190/d2d-mica
Brief: Direct2D device-context setup for DComp-backed effects like Mica.
```cpp
ID2D1Factory1* factory = nullptr;
D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
ID2D1Device* d2dDevice = nullptr;
factory->CreateDevice(dxgiDevice, &d2dDevice);
ID2D1DeviceContext* dc = nullptr;
d2dDevice->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &dc);
dc->SetAntialiasMode(D2D1_ANTIALIAS_MODE_PER_PRIMITIVE);
```

## GdiInteropSample
https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample
Brief: GDI interop path using a DC render target.
```cpp
ID2D1Factory* factory = nullptr;
D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &factory);
ID2D1DCRenderTarget* dcTarget = nullptr;
D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties();
factory->CreateDCRenderTarget(&props, &dcTarget);
dcTarget->BindDC(hdc, &rect);
```

https://learn.microsoft.com/en-us/windows/win32/api/d2d1/nn-d2d1-id2d1hwndrendertarget?redirectedfrom=MSDN
ID2D1HwndRenderTarget is the simplest D2D entry point for Win32 windows. The render target owns its own device and back buffer; resizing requires calling Resize().
```cpp
ComPtr<ID2D1Factory> factory;
D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, factory.GetAddressOf());
D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties();
D2D1_HWND_RENDER_TARGET_PROPERTIES hwndProps =
    D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(640, 480));
ComPtr<ID2D1HwndRenderTarget> rt;
factory->CreateHwndRenderTarget(props, hwndProps, &rt);
// On WM_SIZE: rt->Resize(D2D1::SizeU(newW, newH));
```

https://learn.microsoft.com/en-us/windows/win32/direct2d/devices-and-device-contexts#how-to-create-a-direct2d-device-context-for-rendering
The D2D device context is the modern entry point. Create it from a D2D device (itself created from a DXGI device), then target it at a DXGI surface or bitmap.
```cpp
ComPtr<ID2D1Factory1> factory;
D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, IID_PPV_ARGS(&factory));
ComPtr<ID2D1Device> d2dDev;
factory->CreateDevice(dxgiDevice.Get(), &d2dDev);
ComPtr<ID2D1DeviceContext> dc;
d2dDev->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &dc);
dc->BeginDraw();
dc->Clear(D2D1::ColorF(D2D1::ColorF::CornflowerBlue));
dc->EndDraw();
```

https://learn.microsoft.com/en-us/windows/win32/direct2d/how-to-topics
D2D geometry sinks accept lines, Bezier curves, and arcs. Close the sink before drawing the geometry.
```cpp
ComPtr<ID2D1PathGeometry> geo;
factory->CreatePathGeometry(&geo);
ComPtr<ID2D1GeometrySink> sink;
geo->Open(&sink);
sink->BeginFigure({10.0f, 100.0f}, D2D1_FIGURE_BEGIN_FILLED);
sink->AddLine({100.0f, 10.0f});
sink->AddLine({190.0f, 100.0f});
sink->EndFigure(D2D1_FIGURE_END_CLOSED);
sink->Close();
rt->FillGeometry(geo.Get(), fillBrush.Get());
rt->DrawGeometry(geo.Get(), strokeBrush.Get(), 2.0f);
```

https://learn.microsoft.com/en-us/windows/win32/direct2d/profiling-directx-applications
Use ID3DUserDefinedAnnotation (D3D11) or PIX event markers (D3D12) to name GPU passes. These appear in GPU captures from PIX, RenderDoc, and NSight.
```cpp
ComPtr<ID3DUserDefinedAnnotation> anno;
context->QueryInterface(IID_PPV_ARGS(&anno));
anno->BeginEvent(L"Shadow Map Pass");
RenderShadowMap();
anno->EndEvent();
anno->BeginEvent(L"Main Pass");
RenderScene();
anno->EndEvent();
```

https://github.com/fdwr/TextLayoutSampler
DirectWrite TextLayout provides per-glyph metrics. Use IDWriteTextLayout::GetMetrics, GetLineMetrics, and HitTestPoint for caret placement. DrawTextLayout takes a custom renderer for fine-grained control.
```cpp
ComPtr<IDWriteFactory> dwf;
DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory),
    (IUnknown**)dwf.GetAddressOf());
ComPtr<IDWriteTextFormat> fmt;
dwf->CreateTextFormat(L"Segoe UI", nullptr, DWRITE_FONT_WEIGHT_NORMAL,
    DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 18.0f, L"en-us", &fmt);
ComPtr<IDWriteTextLayout> layout;
dwf->CreateTextLayout(L"Hello DWrite", 12, fmt.Get(), 400.0f, 200.0f, &layout);
DWRITE_TEXT_METRICS m = {};
layout->GetMetrics(&m);
```

https://github.com/yu2924/TestD2DTextRender
D2D DrawText is convenient but DrawTextLayout gives more control. Always call BeginDraw/EndDraw around all draw calls; check EndDraw's return for D2DERR_RECREATE_TARGET on device loss.
```cpp
rt->BeginDraw();
rt->Clear(D2D1::ColorF(D2D1::ColorF::White));
D2D1_RECT_F layoutRect = {10, 10, 390, 190};
rt->DrawTextW(L"Direct2D Text", 13, format.Get(), layoutRect, brush.Get());
HRESULT hr = rt->EndDraw();
if (hr == D2DERR_RECREATE_TARGET) RecreateResources();
```

https://github.com/xoofx/CustomFormattingDemo
IDWriteTextLayout::SetDrawingEffect associates an IUnknown with a text range. A custom IDWriteTextRenderer can query the effect per glyph run to apply colors, gradients, or images.
```cpp
DWRITE_TEXT_RANGE range = { 0, 5 };
ComPtr<IUnknown> redEffect = MakeColorEffect(RGB(255, 0, 0));
layout->SetDrawingEffect(redEffect.Get(), range);
rt->BeginDraw();
layout->Draw(nullptr, customRenderer.Get(), 10.0f, 10.0f);
rt->EndDraw();
```

https://devblogs.microsoft.com/math-in-office/richeditd2d-window-controls/
Windowless RichEdit (ITextServices2) draws via TxDraw into any HDC or D2D surface. Useful for embedding styled text without a HWND.
```cpp
ITextServices2* ts = nullptr;
CreateTextServices(nullptr, host, (IUnknown**)&ts);
RECT rc = { 0, 0, 400, 200 };
ts->TxDraw(DVASPECT_CONTENT, 0, nullptr, nullptr,
    hdc, nullptr,
    (RECTL*)&rc, (RECTL*)&rc,
    nullptr, nullptr, 0);
ts->Release();
```

https://learn.microsoft.com/en-us/windows/win32/direct2d/multi-threaded-direct2d-apps
Multi-threaded D2D requires D2D1_FACTORY_TYPE_MULTI_THREADED. QueryInterface for ID2D1Multithread and call Enter/Leave around access from secondary threads.
```cpp
ComPtr<ID2D1Factory1> factory;
D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, IID_PPV_ARGS(&factory));
ComPtr<ID2D1Multithread> mt;
factory->QueryInterface(IID_PPV_ARGS(&mt));
// Worker thread:
mt->Enter();
rt->BeginDraw();
rt->DrawLine({0,0}, {100,100}, brush.Get(), 1.0f);
rt->EndDraw();
mt->Leave();
```

https://medium.com/@python-javascript-php-html-css/using-c-and-direct2d-to-create-a-circular-transparent-window-with-mouse-click-passthrough-035aaa7e3209
D2D layered window for click-through circular UI: WS_EX_LAYERED | WS_EX_TRANSPARENT makes the window non-hit-testable. Draw with D2D clearing alpha to 0 outside the shape.
```cpp
// Per-pixel transparent layered window
SetWindowLongW(hwnd, GWL_EXSTYLE, WS_EX_LAYERED | WS_EX_TRANSPARENT);
rt->BeginDraw();
rt->Clear(D2D1::ColorF(0, 0.0f));  // fully transparent background
D2D1_ELLIPSE e = D2D1::Ellipse({100.0f, 100.0f}, 90.0f, 90.0f);
rt->FillEllipse(e, solidBrush.Get());
rt->EndDraw();
```

https://learn.microsoft.com/en-us/windows/win32/direct2d/supported-pixel-formats-and-alpha-modes
DXGI_FORMAT_B8G8R8A8_UNORM with D2D1_ALPHA_MODE_PREMULTIPLIED is the standard D2D pixel format. Use IGNORE for opaque targets (avoids alpha blend overhead).
```cpp
D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
    D2D1_RENDER_TARGET_TYPE_DEFAULT,
    D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED));
factory->CreateHwndRenderTarget(props, hwndProps, &rt);
```

https://www.simonmourier.com/Blog/Category/direct2D
Create a D2D bitmap from pixel data with CreateBitmap. Stride = width * bytesPerPixel, aligned to 4 bytes.
```cpp
UINT stride = w * 4;
ComPtr<ID2D1Bitmap> bmp;
rt->CreateBitmap(
    D2D1::SizeU(w, h),
    pixels, stride,
    D2D1::BitmapProperties(
        D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)),
    &bmp);
rt->DrawBitmap(bmp.Get(), D2D1::RectF(0, 0, (float)w, (float)h));
```
