# WIC Image Loading

Windows Imaging Component (WIC) decodes images from files or streams. `IWICBitmapDecoder` → `IWICBitmapFrameDecode` → `IWICFormatConverter` (to 32bpp BGRA) → `IWICBitmap` or `CreateDIBSection`. Works with PNG, JPEG, BMP, TIFF, GIF, and more without additional libraries.

```cpp
// Load a PNG and get a GDI HBITMAP via WIC
CoInitialize(nullptr);
ComPtr<IWICImagingFactory> wic;
CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER,
    IID_PPV_ARGS(&wic));

ComPtr<IWICBitmapDecoder> decoder;
wic->CreateDecoderFromFilename(L"photo.png", nullptr, GENERIC_READ,
    WICDecodeMetadataCacheOnLoad, &decoder);

ComPtr<IWICBitmapFrameDecode> frame;
decoder->GetFrame(0, &frame);

ComPtr<IWICFormatConverter> conv;
wic->CreateFormatConverter(&conv);
conv->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
    WICBitmapDitherTypeNone, nullptr, 0.0, WICBitmapPaletteTypeCustom);

UINT w, h;
conv->GetSize(&w, &h);
BITMAPINFO bmi = {};
bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
bmi.bmiHeader.biWidth = w;
bmi.bmiHeader.biHeight = -(LONG)h;
bmi.bmiHeader.biPlanes = 1;
bmi.bmiHeader.biBitCount = 32;
bmi.bmiHeader.biCompression = BI_RGB;
void* bits = nullptr;
HBITMAP hbm = CreateDIBSection(nullptr, &bmi, DIB_RGB_COLORS, &bits, nullptr, 0);
conv->CopyPixels(nullptr, w * 4, w * h * 4, (BYTE*)bits);
```

## References
- https://github.com/RadAd/RadImgViewer2
