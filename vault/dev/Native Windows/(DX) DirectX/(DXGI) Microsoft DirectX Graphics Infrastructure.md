# DXGI (Microsoft DirectX Graphics Infrastructure)

DXGI is the ownership layer between graphics APIs and the Windows display stack: factories enumerate adapters and outputs, swap chains own presentation, and shared resources cross API/process boundaries. D3D11 and D3D12 differ radically above it, but both eventually need DXGI for adapter selection, flip-model swap chains, fullscreen/Alt+Enter policy, tearing flags, output duplication, HDR metadata, and frame statistics.

The two mistakes this note should prevent are adapter drift and accidental window-policy drift. If a D2D/D3D/DComp pipeline mixes devices from different adapters, sharing fails or silently copies. If you let DXGI handle Alt+Enter or window changes while also running custom fullscreen code, you get conflicting style changes and resize behavior. `IDXGIFactory6::EnumAdapterByGpuPreference`, `MakeWindowAssociation`, and flip-model swap-chain creation are therefore not boilerplate; they decide where the frame actually goes.

The Godot OpenGL/DXGI branch is relevant because it shows DXGI as a presentation solution even when rendering is not D3D: render GL into a shared texture, then present through a DXGI swap chain. That connects directly to `OpenGL on DXGI Swapchain.md` and the WGL interop notes.

## Adapter Identity

The API catalog, `EnumAdapterByGpuPreference` answer, and sandbox examples all contribute to the same rule: choose the adapter once, then make D3D, D2D, DComp, and capture code live on that adapter unless a copy is intentional.

```cpp
wil::com_ptr<IDXGIFactory6> factory;
CreateDXGIFactory2(0, IID_PPV_ARGS(&factory));

wil::com_ptr<IDXGIAdapter1> adapter;
for (UINT i = 0; factory->EnumAdapterByGpuPreference(
         i, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter)) != DXGI_ERROR_NOT_FOUND; ++i) {
    DXGI_ADAPTER_DESC1 desc = {};
    adapter->GetDesc1(&desc);
    if (!(desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)) {
        break;
    }
    adapter.reset();
}
```

## Window Policy and Swap Chains

The programming guide and best-practices link contribute the flip-model/window-policy boundary. Disable DXGI's Alt+Enter behavior when the application owns fullscreen transitions, and create a swap chain that matches the compositor-era presentation model.

```cpp
factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);

DXGI_SWAP_CHAIN_DESC1 desc = {};
desc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
desc.BufferCount = 2;
desc.SampleDesc.Count = 1;
desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
desc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;

wil::com_ptr<IDXGISwapChain1> swap_chain;
factory->CreateSwapChainForHwnd(d3d_device.get(), hwnd, &desc, nullptr, nullptr, &swap_chain);
```

## C COM and GL Presentation

The C `__uuidof` link contributes the pure-C COM shape; the Godot branch contributes the larger insight that DXGI can be the presentation layer even when the renderer is OpenGL, provided shared texture/device ownership is explicit.

```c
#include <initguid.h>
#include <dxgi1_6.h>

IDXGIFactory6* factory = NULL;
HRESULT hr = CreateDXGIFactory2(0, &IID_IDXGIFactory6, (void**)&factory);
```

## Shared-Resource Boundary

The same DXGI identity rule shows up in DWM capture, WGL interop, D2D/DComp rendering, and cross-process texture sharing: the handle opens cleanly only when the device/adapter/format assumptions line up.

```cpp
D3D11_TEXTURE2D_DESC td = {};
td.Width = width;
td.Height = height;
td.MipLevels = 1;
td.ArraySize = 1;
td.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
td.SampleDesc.Count = 1;
td.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
td.MiscFlags = D3D11_RESOURCE_MISC_SHARED;

wil::com_ptr<ID3D11Texture2D> shared_texture;
d3d_device->CreateTexture2D(&td, nullptr, &shared_texture);

wil::com_ptr<IDXGIResource> dxgi_resource;
shared_texture->QueryInterface(IID_PPV_ARGS(&dxgi_resource));

HANDLE shared_handle = nullptr;
dxgi_resource->GetSharedHandle(&shared_handle);

wil::com_ptr<ID3D11Resource> opened;
other_device->OpenSharedResource(shared_handle, IID_PPV_ARGS(&opened));
```

Use this route with `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md` when the handle comes from DWM, and with `../(GL) OpenGL/WGL_NV_DX_interop Demo.md` when GL needs to lock a D3D resource.

## Discussion Claim To Verify

The Stack Overflow `EnumAdapterByGpuPreference` answer is actionable only if the chosen adapter remains the same adapter used by the swap chain, DComp target, output duplication object, GL interop texture, and DWM shared-surface opener. The pure-C `__uuidof` question adds a smaller but useful claim: DXGI is ordinary COM; if a C build supplies the right IID, the object model is the same.

```cpp
struct DxgiIdentityProbe {
    LUID factory_adapter_luid;
    LUID d3d_device_luid;
    LUID containing_output_adapter_luid;
    LUID duplication_adapter_luid;
    HRESULT shared_open_hr;
};

// C-compatible IID route: no C++ __uuidof required.
HRESULT hr = CreateDXGIFactory2(0, &IID_IDXGIFactory6, (void**)&factory);
```

Verification route: log every LUID boundary. Create the D3D device from the selected adapter, create a swap chain for an HWND, call `GetContainingOutput`, create an output duplication object for that output, and attempt one shared-resource open. Then move the window to another monitor and change Win+P topology. If the LUID chain changes or shared opens start failing, the original "pick the high-performance adapter" answer was incomplete for this workload. It selected a GPU, but it did not prove output ownership.

Expected interpretation: `EnumAdapterByGpuPreference` is a preference input, not a presentation guarantee. In hybrid systems, remote sessions, software adapters, and virtual displays, the correct adapter may be the one attached to the output or shared handle rather than the fastest one.

## Experiment Harness

Goal: make adapter drift and presentation-policy drift visible before building capture, DComp, or GL interop on top.

Procedure:
1. Enumerate adapters/outputs; log LUID, vendor/device id, software flag, output name, and current mode.
2. Create one device on the chosen adapter and one intentionally wrong-adapter device if multiple adapters exist.
3. Test swap-chain creation, shared-resource open, output duplication, and `GetContainingOutput` with explicit logs.

```cpp
log(adapter_desc.AdapterLuid, adapter_desc.VendorId, output_desc.DeviceName);
hr = other_device->OpenSharedResource(shared_handle, IID_PPV_ARGS(&opened));
log("open shared on other adapter", hr);
```

Metric: adapter LUID consistency across D3D/D2D/DComp/capture, shared-resource open success, containing output identity, and behavior after monitor move or Win+P topology change.

Failure interpretation: shared-resource failure with valid handles is usually adapter or format mismatch. `GetContainingOutput` changing after a window move is expected. Alt+Enter or resize surprises usually mean DXGI window association policy and app fullscreen policy both tried to own the window.

## References
- <https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/dx-graphics-dxgi> - DXGI factories, adapters, outputs, and swap chains.
- <https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi> - programming guide for swap-chain setup.
- <https://learn.microsoft.com/en-us/windows/win32/api/_direct3ddxgi/> - API reference.
- <https://stackoverflow.com/questions/57223294/how-to-call-dxgi-from-c-without-uuidof> - pure-C COM/IID pattern.
- <https://github.com/toivjon/dxgi-sandbox> - adapter enumeration and swap-chain experiments.
- <https://stackoverflow.com/a/59732413> - `IDXGIFactory6::EnumAdapterByGpuPreference` usage.
- <https://learn.microsoft.com/en-us/windows/win32/direct3darticles/dxgi-best-practices#full-screen-issues> - fullscreen and Alt+Enter pitfalls.
- <https://github.com/godotengine/godot/compare/master...alvinhochun:godot:opengl-with-dxgi-present> - GL rendering presented through DXGI.

## Connections
- `DXGI Output Duplication Capture.md`
- `DXGI Disable VBlank Virtualization.md`
- `DXGI SwapChain2 SetSourceSize.md`
- `OpenGL on DXGI Swapchain.md`
- `../(DWM) Desktop Window Manager/DwmGetDxSharedSurface Window Capture.md`
- `../(DX) DirectX/Windows Composition Engine.md`
- `../Display Control/Examples.md`
