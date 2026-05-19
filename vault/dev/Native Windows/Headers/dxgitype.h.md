# dxgitype.h

Shared DXGI value types used by Direct3D 10/11/12, Direct2D, WIC interop, Media Foundation surfaces, and the swap-chain APIs. The important one is `DXGI_FORMAT`: it is not just "pixel format" but the cross-API contract for channel order, numeric interpretation, compression block layout, typeless reinterpretation, depth/stencil packing, and sRGB conversion. `DXGI_RATIONAL` is the legacy refresh-rate fraction used by display-mode enumeration; modern flip-model swap chains usually leave refresh selection to DWM, but exclusive/fullscreen and mode-listing code still has to preserve the numerator/denominator instead of rounding to an integer.

Connections: pair with `dcommon.h` for the Direct2D/DWrite-friendly aliases, `(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` for swap-chain ownership, and the WIC/GDI notes when translating between `GUID_WICPixelFormat*`, `BITMAPINFO`, and `DXGI_FORMAT`.

## References
- dxgitype.h
