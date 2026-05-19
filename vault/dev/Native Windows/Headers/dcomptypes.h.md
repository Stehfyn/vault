# dcomptypes.h

DirectComposition's small shared enum/type header: bitmap interpolation, border modes, composite modes, backface visibility, and other values that must be visible without pulling in every `IDComposition*` interface declaration. These constants decide how the compositor samples and blends visual content; they are subtle because the final output also depends on the DXGI swap-chain format, premultiplied-alpha convention, DWM color pipeline, and whether the source is a surface, swap chain, or effect graph.

Connections: use with `dcomp.h`; compare the alpha/interpolation language with `(GDI) Graphics Device Interface/Alpha Blending a Bitmap.md` and `(DX) DirectX/DirectComposition DX12.md`, where the same visual artifact can come from a different layer.

## References
- dcomptypes.h
