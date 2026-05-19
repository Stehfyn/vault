# dcommon.h

Common scalar geometry and enum types shared by Direct2D, DirectWrite, DirectComposition-facing helpers, and some DXGI-adjacent APIs. It deliberately avoids device/resource ownership and just standardizes small value shapes: points, rectangles, matrices, color structs, measuring modes, alpha modes, interpolation modes. This is why a D2D render target, a DWrite text layout, and a composition visual can exchange rectangles without dragging the full Direct2D or DirectWrite header stack into every translation unit.

Connections: `dxgitype.h` carries the pixel-format side of the same "common DirectX vocabulary"; `dcomp.h` and `(DX) DirectX/(D2D) Direct2D.md` are where those value types become live rendering state.

## References
- dcommon.h
