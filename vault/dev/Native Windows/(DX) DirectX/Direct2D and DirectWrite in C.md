# Direct2D and DirectWrite in C

Martins Mozeiko's headers translate Direct2D and DirectWrite COM interfaces into plain C vtables. That matters because Microsoft's official headers expose these APIs as C++ pure-virtual interfaces; if you are writing C, you either need explicit `lpVtbl` calls or a header set that defines helpers such as `ID2D1Factory_CreateHwndRenderTarget`.

The note is most useful for strict-C Win32 projects, plugin ABIs, or small tools that want D2D/DWrite without converting the codebase to C++. It pairs naturally with `C Drawing Shim - D2D or GDI+.md`: one exposes the exact API, the other hides it behind a portable drawing layer.

## References
- <https://github.com/mmozeiko/c_d2d_dwrite>
