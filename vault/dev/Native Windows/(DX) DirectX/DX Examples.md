# DX Examples

## Hello-Cube-Windows
https://github.com/mindaptiv/Hello-Cube-Windows
Brief: Minimal Win32 + D3D11 spinning cube setup with swap chain and device creation.
```cpp
DXGI_SWAP_CHAIN_DESC scd = {};
scd.BufferCount = 1;
scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
scd.OutputWindow = hwnd;
scd.SampleDesc.Count = 1;
scd.Windowed = TRUE;
D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
    nullptr, 0, D3D11_SDK_VERSION, &scd, &swap, &device, nullptr, &ctx);
```

## D3D11 + OpenGL interop gist
https://gist.github.com/mmozeiko/c99f9891ce723234854f0919bfd88eae
Brief: WGL_NV_DX_interop flow that shares a D3D texture with an OpenGL texture.
```c
HGLRC glrc = wglCreateContext(hdc);
wglMakeCurrent(hdc, glrc);
HANDLE hDevice = wglDXOpenDeviceNV(d3dDevice);
GLuint glTex = 0;
glGenTextures(1, &glTex);
HANDLE hObject = wglDXRegisterObjectNV(hDevice, d3dTexture, glTex,
    GL_TEXTURE_2D, WGL_ACCESS_WRITE_DISCARD_NV);
```

## DirectX 11 cube tutorial video
https://www.youtube.com/watch?v=E3wTajGZOsA
Brief: Core D3D11 pipeline setup, including constant buffers for transforms.
```cpp
D3D11_BUFFER_DESC cbd = {};
cbd.ByteWidth = sizeof(CBScene);
cbd.Usage = D3D11_USAGE_DEFAULT;
cbd.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
device->CreateBuffer(&cbd, nullptr, &cb);
ctx->VSSetConstantBuffers(0, 1, &cb);
```

## DirectX 11 render loop video
https://www.youtube.com/watch?v=OYq9rpwl9Dc
Brief: Basic frame loop that clears the back buffer and presents.
```cpp
float clear[4] = { 0.1f, 0.1f, 0.2f, 1.0f };
ctx->OMSetRenderTargets(1, &rtv, nullptr);
ctx->ClearRenderTargetView(rtv, clear);
ctx->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
ctx->DrawIndexed(indexCount, 0, 0);
swap->Present(1, 0);
```

https://github.com/Jaykul/Windows7APICodePack/blob/master/Samples/DirectX/UtilitiesLibrary/Controls/RenderHost.cpp#L41
RenderHost is a Win32 control that hosts a DirectX renderer. It handles WM_PAINT by calling into the renderer and ValidateRect to suppress default paint.
```cpp
LRESULT CALLBACK RenderWndProc(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
  RenderHost* host = (RenderHost*)GetWindowLongPtrW(hwnd, GWLP_USERDATA);
  switch (msg) {
    case WM_PAINT:
      if (host) host->RenderFrame();
      ValidateRect(hwnd, nullptr);
      return 0;
    case WM_SIZE:
      if (host) host->Resize(LOWORD(l), HIWORD(l));
      return 0;
  }
  return DefWindowProcW(hwnd, msg, w, l);
}
```

http://www.directxtutorial.com/lesson.aspx?lessonid=111-4-3
Classic D3D11 device and swap chain setup. The minimum setup: create device + swap chain with D3D11CreateDeviceAndSwapChain, get the back buffer as an ID3D11Texture2D, create an RTV, set it as the render target.
```cpp
DXGI_SWAP_CHAIN_DESC scd = {};
scd.BufferCount       = 2;
scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
scd.BufferUsage       = DXGI_USAGE_RENDER_TARGET_OUTPUT;
scd.OutputWindow      = hwnd;
scd.SampleDesc.Count  = 1;
scd.Windowed          = TRUE;
scd.SwapEffect        = DXGI_SWAP_EFFECT_FLIP_DISCARD;
ComPtr<ID3D11Device> dev;
ComPtr<ID3D11DeviceContext> ctx;
ComPtr<IDXGISwapChain> sc;
D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
    nullptr, 0, D3D11_SDK_VERSION, &scd, &sc, &dev, nullptr, &ctx);
```
