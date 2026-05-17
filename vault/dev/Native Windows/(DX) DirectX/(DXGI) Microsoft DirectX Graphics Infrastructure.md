# DXGI (Microsoft DirectX Graphics Infrastructure)

## DXGI overview
https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/dx-graphics-dxgi
Brief: Core DXGI concepts like factories, adapters, and outputs.
```cpp
IDXGIFactory1* factory = nullptr;
CreateDXGIFactory1(IID_PPV_ARGS(&factory));
IDXGIAdapter1* adapter = nullptr;
if (factory->EnumAdapters1(0, &adapter) == S_OK) {
    DXGI_ADAPTER_DESC1 desc = {};
    adapter->GetDesc1(&desc);
    adapter->Release();
}
factory->Release();
```

## DXGI programming guide
https://learn.microsoft.com/en-us/windows/win32/direct3ddxgi/d3d10-graphics-programming-guide-dxgi
Brief: Swap chain creation path used by D3D10/D3D11 applications.
```cpp
DXGI_SWAP_CHAIN_DESC1 scd = {};
scd.Width = width;
scd.Height = height;
scd.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
scd.BufferCount = 2;
factory->CreateSwapChainForHwnd(commandQueue, hwnd, &scd, nullptr, nullptr, &swap);
```

## Calling DXGI from C without __uuidof
https://stackoverflow.com/questions/57223294/how-to-call-dxgi-from-c-without-uuidof
Brief: Use IID_* constants with initguid in pure C.
```c
#define COBJMACROS
#include <initguid.h>
#include <dxgi.h>
IDXGIFactory1* factory = NULL;
HRESULT hr = CreateDXGIFactory1(&IID_IDXGIFactory1, (void**)&factory);
if (SUCCEEDED(hr)) factory->lpVtbl->Release(factory);
```

## DXGI API reference
https://learn.microsoft.com/en-us/windows/win32/api/_direct3ddxgi/
Brief: Use modern swap chain interfaces for frame indexing.
```cpp
IDXGISwapChain3* swap3 = nullptr;
swap->QueryInterface(IID_PPV_ARGS(&swap3));
UINT index = swap3->GetCurrentBackBufferIndex();
swap3->Release();
```

https://github.com/toivjon/dxgi-sandbox
DXGI sandbox for adapter enumeration and swap chain creation patterns. IDXGIFactory6::EnumAdapterByGpuPreference lets you select the high-performance (discrete) GPU explicitly.
```cpp
ComPtr<IDXGIFactory6> factory;
CreateDXGIFactory1(IID_PPV_ARGS(&factory));
ComPtr<IDXGIAdapter1> adapter;
// Prefer discrete GPU
factory->EnumAdapterByGpuPreference(0,
    DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter));
DXGI_ADAPTER_DESC1 desc = {};
adapter->GetDesc1(&desc);
```

https://stackoverflow.com/a/59732413
DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE selects the dedicated GPU; MINIMUM_POWER selects the integrated one. Available via IDXGIFactory6 (DXGI 1.6, Windows 10 1803+).
```cpp
ComPtr<IDXGIFactory6> factory6;
CreateDXGIFactory1(IID_PPV_ARGS(&factory6));
ComPtr<IDXGIAdapter1> gpu;
factory6->EnumAdapterByGpuPreference(0,
    DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&gpu));
D3D12CreateDevice(gpu.Get(), D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));
```

https://learn.microsoft.com/fr-fr/windows/win32/direct3darticles/dxgi-best-practices#full-screen-issues
Disable DXGI's built-in Alt+Enter handler with MakeWindowAssociation — it can conflict with custom fullscreen logic. Always call it after swap chain creation.
```cpp
factory->MakeWindowAssociation(hwnd, DXGI_MWA_NO_ALT_ENTER);
// Manual fullscreen toggle
bool isFullscreen = false;
if (toggleKey) {
  isFullscreen = !isFullscreen;
  swapChain->SetFullscreenState(isFullscreen, nullptr);
  // Resize buffers after state change
  swapChain->ResizeBuffers(0, 0, 0, DXGI_FORMAT_UNKNOWN, 0);
}
```

https://learn.microsoft.com/fr-fr/windows/win32/api/dxgi/nf-dxgi-idxgifactory-makewindowassociation
DXGI_MWA_NO_ALT_ENTER suppresses the automatic fullscreen switch on Alt+Enter. Pair with DXGI_MWA_NO_WINDOW_CHANGES to prevent DXGI from modifying the window style.
```cpp
UINT flags = DXGI_MWA_NO_ALT_ENTER | DXGI_MWA_NO_WINDOW_CHANGES;
factory->MakeWindowAssociation(hwnd, flags);
```

https://github.com/godotengine/godot/compare/master...alvinhochun:godot:opengl-with-dxgi-present
Godot branch experimenting with DXGI swap chain for OpenGL presentation. The key trick: create a D3D11 device and swap chain for presentation, render into a shared texture from OpenGL, then blit to the back buffer.
```cpp
DXGI_SWAP_CHAIN_DESC1 desc = {};
desc.Format      = DXGI_FORMAT_B8G8R8A8_UNORM;
desc.BufferCount = 2;
desc.Width       = width;
desc.Height      = height;
desc.SwapEffect  = DXGI_SWAP_EFFECT_FLIP_DISCARD;
desc.SampleDesc.Count = 1;
ComPtr<IDXGISwapChain1> swapChain;
factory->CreateSwapChainForHwnd(queue.Get(), hwnd, &desc, nullptr, nullptr, &swapChain);
swapChain->Present(1, 0);
```
