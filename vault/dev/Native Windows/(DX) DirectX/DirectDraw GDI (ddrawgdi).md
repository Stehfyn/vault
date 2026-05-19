# DirectDraw GDI (ddrawgdi)

`ddrawgdi.h` documents the old DirectDraw/GDI driver interface for surface and DC handling: creating DirectDraw objects, creating surface objects, acquiring/releasing DCs, and coordinating GDI access to DirectDraw-managed surfaces. It is not the API you use for a modern app; it is a map of how legacy display drivers and DirectDraw-era GDI interop fit together.

Read it when debugging compatibility shims or old code that treats DirectDraw surfaces and GDI DCs as interchangeable. For user-mode game fixes, `dxwrapper` is the practical layer above this.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/ddrawgdi/>

## Connections
- `DirectDraw and D3D9 Proxy DLL (dxwrapper).md`
