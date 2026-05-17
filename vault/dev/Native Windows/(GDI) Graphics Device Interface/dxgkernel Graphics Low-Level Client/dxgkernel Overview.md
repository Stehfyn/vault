# dxgkernel Overview

Source: https://learn.microsoft.com/en-us/windows/win32/devnotes/-dxgkernel-low-level-client-support

These low-level entry points expose kernel-mode DirectDraw/Direct3D operations to user-mode clients (typically via Gdi32.dll or D3D8THK.DLL) and return handles instead of driver pointers.

```cpp
// minimal example (pseudo)
D3DKMT_OPENADAPTERFROMHDC open = {};
open.hDc = hdc;
NTSTATUS status = D3DKMTOpenAdapterFromHdc(&open);
if (status == 0) {
    // use open.hAdapter / open.hDevice
}
```
