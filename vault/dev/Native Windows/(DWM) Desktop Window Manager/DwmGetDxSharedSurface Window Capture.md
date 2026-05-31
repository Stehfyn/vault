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

## Source Shape

The DWMCapture source is useful because it shows two adjacent reverse-engineered routes: resolve DWM's shared-surface function dynamically, then open the returned handle through the graphics device. The adapter `LUID` is not decorative; it decides whether `OpenSharedResource` succeeds without a cross-adapter mess.

```cpp
using DwmGetDxSharedSurfaceFn = BOOL (WINAPI *)(
    HWND, HANDLE *, LUID *, ULONG *, ULONG *, ULONGLONG *);

auto get_surface = reinterpret_cast<DwmGetDxSharedSurfaceFn>(
    GetProcAddress(GetModuleHandleW(L"user32.dll"), "DwmGetDxSharedSurface"));

HANDLE shared = nullptr;
LUID adapter_luid = {};
ULONG format = 0, present_flags = 0;
ULONGLONG update_id = 0;

if (get_surface(hwnd, &shared, &adapter_luid, &format, &present_flags, &update_id)) {
    wil::com_ptr<ID3D10Resource> resource;
    d3d->OpenSharedResource(shared, __uuidof(ID3D10Resource), resource.put_void());
}
```

## Capture Boundary

This route answers "what texture does DWM own for this HWND?" rather than "what pixels are visible on a monitor?" That makes it the conceptual sibling of DirectComposition and the opposite of output duplication.

```cpp
struct CaptureBoundary {
    HWND hwnd;              // window-level identity
    LUID adapter_luid;      // match the D3D/DXGI device to this
    HANDLE shared_surface;  // open as a D3D resource, then copy/sample
    ULONG dxgi_format_hint; // validate before creating SRV/copy targets
    ULONGLONG update_id;    // useful for frame-change filtering
};
```

Route from here to `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` before creating devices, to `../(DX) DirectX/DXGI Output Duplication Capture.md` when monitor-frame capture is acceptable, and to `Capture-Protected Window (Sprite Hack).md` when the question is why capture intentionally returns black.

## Experiment Harness

Goal: compare per-HWND DWM redirection capture against monitor capture without treating the undocumented surface as stable API.

Procedure:
1. Resolve the ordinal dynamically and log failure as "unsupported route," not as fatal.
2. For one visible, one occluded, and one minimized/hidden target window, record returned `LUID`, format, present flags, update id, and `OpenSharedResource` result.
3. Compare hashes against GDI capture and DXGI output duplication while moving another window over the target.

```cpp
hr = get_surface(hwnd, &shared, &luid, &fmt, &flags, &update_id);
log(hwnd, hr, luid, fmt, flags, update_id);
if (SUCCEEDED(hr)) log(device->OpenSharedResource(shared, iid, &resource));
```

Metric: success rate by window state, update-id changes per second, open-resource failure rate by adapter, and pixel mismatch against output-duplication/GDI routes.

Failure interpretation: ordinal/signature failure means the undocumented route changed or is absent. `OpenSharedResource` failure usually means adapter LUID mismatch or incompatible D3D version/format assumptions. Differences from output duplication are expected when the HWND is occluded, transformed, minimized, or protected.

## Source Code Reading

`notr1ch/DWMCapture` is valuable because it shows the entire per-HWND route in `DWMCaptureSource.cpp`, not just the undocumented function name. The relevant source units are `DWMCapture.cpp` for OBS source registration/configuration and `DWMCaptureSource.cpp` for the capture path.

The code has two shared-surface discovery paths. `GetWindowSharedSurfaceHandle` asks which monitor owns the HWND, calls `GetMonitorInfo`, opens the matching graphics adapter with `D3DKMTOpenAdapterFromGdiDisplayName`, copies the returned `AdapterLuid`, closes the adapter handle with `D3DKMTCloseAdapter`, then calls DWM's ordinal-100 shared-surface function with that LUID. The shorter path, `GetDWMSharedHandle`, resolves `DwmGetDxSharedSurface` from `USER32` and asks it for `HANDLE surface`, `LUID adapter`, `ULONG pFmtWindow`, `ULONG pPresentFlags`, and `ULONGLONG pWin32kUpdateId`.

The observable capture path is:

```cpp
// Source-shaped from DWMCaptureSource.cpp.
Init(data):
    DwmIsCompositionEnabled(&enabled); fail if disabled
    GetTargetSize()

BeginScene():
    className = data["windowClass"]
    optional cursor shader setup
    AttemptCapture()

AttemptCapture():
    hwnd = FindWindow(className, nullptr)
    shared = GetDWMSharedHandle(hwnd)
    sharedTexture = GS->CreateTextureFromSharedHandle(0, 0, shared)

GetTargetSize():
    shared = GetDWMSharedHandle(hwnd)
    d3d->OpenSharedResource(shared, ID3D10Resource, &resource)
    resource->QueryInterface(ID3D10Texture2D, &texture)
    texture->GetDesc(&desc)
```

Cursor capture is a separate CPU/GDI overlay, not part of the DWM surface. `GetCursorData` creates a 32-bpp DIB section, draws the current icon into it, copies the bits into an OBS texture, and `Render` draws the DWM shared texture first and then draws the cursor sprite. That matters for probes: a mismatch between captured pixels and the on-screen cursor may be a cursor-overlay problem, not a DWM-surface problem.

Minimal probe decomposition:

```cpp
surface = DwmGetDxSharedSurface(hwnd, &luid, &format, &flags, &update_id);
device = CreateD3DDeviceOnAdapter(luid);      // required, not optional
resource = device.OpenSharedResource(surface);
tex = resource.QueryInterface(ID3D11Texture2D);
desc = tex.GetDesc();
copy tex into a staging texture or shader-resource path;
log(hwnd, luid, format, flags, update_id, desc.Width, desc.Height);
```

The first failure branch to log is not pixels. It is identity: `FindWindow` target, returned `LUID`, D3D device adapter `LUID`, shared-handle open result, and `ID3D10/11Texture2D` query result. Only after those agree should a reader investigate stale frames, protected content, minimization, or transforms.

## References
- <https://github.com/notr1ch/DWMCapture>
- Related: `Get Windows 7 windows as DirectX textures.md`, `DWM Thumbnail - VirtualDesktop IDCompositionVisual.md`, `Capture-Protected Window (Sprite Hack).md`

## Connections
- `DWM Internals Documentation.md` is the conceptual map for why the shared surface exists and why public `dwmapi.h` does not document it.
- `../(DX) DirectX/(DXGI) Microsoft DirectX Graphics Infrastructure.md` matters because the returned adapter `LUID` must match the device that opens the shared resource.
- `../(GDI) Graphics Device Interface/How to Capture the Screen.md` and `../(DX) DirectX/DXGI Output Duplication Capture.md` are the documented capture alternatives to compare for occlusion, latency, and protected-content behavior.
