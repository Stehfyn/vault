# DwmGetDxSharedSurface Window Capture

OBS plugin that bypasses GDI/DXGI capture and pulls window pixels straight from the DWM-owned shared D3D texture for each HWND. The trick is calling the undocumented `DwmGetDxSharedSurface` (exported by ordinal from dwmapi.dll) to obtain a shared-handle and a `LUID` for the adapter, then `OpenSharedResource` on your own D3D device — you get the composited window content without the window being foreground, unoccluded, or even visible, and without the per-frame overhead of `BitBlt`/`PrintWindow` (cf. kawapure/DWM-Documentation for the reverse-engineered surface, seiftnesse/DWM_Hook for the hook side of the same API).

```cpp
// Undocumented dwmapi.dll ordinal 100 — signature pieced together from reversers
typedef HRESULT (WINAPI *PFN_DwmGetDxSharedSurface)(
    HWND hwnd, HANDLE *phSurface, LUID *pAdapterLuid,
    ULONG *pFmtWindow, ULONG *pPresentFlags, ULONGLONG *pWin32kUpdateId);

HMODULE dwm = LoadLibraryW(L"dwmapi.dll");
auto DwmGetDxSharedSurface = (PFN_DwmGetDxSharedSurface)GetProcAddress(dwm, MAKEINTRESOURCEA(100));

HANDLE shared = nullptr; LUID luid{}; ULONG fmt = 0, flags = 0; ULONGLONG updId = 0;
if (SUCCEEDED(DwmGetDxSharedSurface(hwnd, &shared, &luid, &fmt, &flags, &updId))) {
    ID3D11Resource* res = nullptr;
    // Caller's device must be created on the adapter matching `luid`
    device->OpenSharedResource(shared, __uuidof(ID3D11Resource), (void**)&res);
    // res is the live DWM redirection surface — wrap as SRV and sample
}
```

## References
- <https://github.com/notr1ch/DWMCapture>
- Related: `Get Windows 7 windows as DirectX textures.md`, `DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`, `Capture-Protected Window (Sprite Hack).md`
