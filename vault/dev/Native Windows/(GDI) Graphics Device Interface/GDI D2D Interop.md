1. https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample
2. https://raw.githubusercontent.com/microsoft/Windows-classic-samples/main/Samples/Win7Samples/multimedia/Direct2D/GdiInteropSample/GdiInteropSample.cpp

Minimal pattern (CreateDCRenderTarget + BindDC):

```cpp
D2D1_RENDER_TARGET_PROPERTIES props = D2D1::RenderTargetProperties(
    D2D1_RENDER_TARGET_TYPE_DEFAULT,
    D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_IGNORE));
factory->CreateDCRenderTarget(&props, &dcrt);

// in WM_PAINT:
dcrt->BindDC(ps.hdc, &rc);
dcrt->BeginDraw();
// D2D drawing
dcrt->EndDraw();
```
