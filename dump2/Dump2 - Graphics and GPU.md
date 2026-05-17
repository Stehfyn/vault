# Dump2 - Graphics and GPU

Starred repositories related to graphics APIs, GPU upscaling SDKs, DirectX wrappers, and rendering frameworks.

---

## diharaw/dw-sample-framework
https://github.com/diharaw/dw-sample-framework

A minimal C++ framework (281 stars) for writing graphics technique demos with OpenGL and Vulkan. Abstracts window creation, input, and a basic render loop. Each sample creates a subclass of `dw::Application`, overrides `init()`, `render()`, and `shutdown()`. Good reference for clean OpenGL/Vulkan interop startup code.

```cpp
// dw sample framework subclass pattern
class MyApp : public dw::Application {
protected:
    bool init(int argc, const char* argv[]) override {
        // Create shader programs, buffers, etc.
        m_shader = dw::Shader::create_from_file("vertex.glsl", "fragment.glsl");
        m_vao = dw::VertexArray::create();
        return true;
    }
    void render(double delta) override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_shader->use();
        m_vao->bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
};
DW_DECLARE_MAIN(MyApp)
```

---

## mmozeiko/build-mesa
https://github.com/mmozeiko/build-mesa

Automatic Mesa3D builds for Windows (130 stars). Mesa provides a software OpenGL ICD (`opengl32.dll`) and also LLVM-based OpenGL via llvmpipe. Key use case: run OpenGL apps on machines without a GPU or on CI with no display adapter. Drop `opengl32.dll` into the app's directory and Mesa takes over as the ICD.

```cpp
// Using Mesa software renderer: just drop opengl32.dll next to your exe.
// To verify which ICD is loaded at runtime:
const char* renderer = (const char*)glGetString(GL_RENDERER);
const char* vendor   = (const char*)glGetString(GL_VENDOR);
// Mesa software: vendor = "VMware, Inc.", renderer = "llvmpipe ..."
// Or use MESA_GL_VERSION_OVERRIDE env var to request a specific version
// set MESA_GL_VERSION_OVERRIDE=4.5
```

---

## elishacloud/dxwrapper
https://github.com/elishacloud/dxwrapper

Fixes DirectX compatibility issues for old games on Windows 10/11 by providing proxy DLLs for ddraw.dll, d3d8.dll, d3d9.dll (and others). Also works as a generic ASI loader — drop a DLL named `dinput.dll` or `dsound.dll` and it injects into the game process. The wrapper intercepts `IDirectDraw::CreateSurface` and can redirect surface creation to a D3D9 path with proper scaling.

```cpp
// Proxy DLL pattern: intercept COM factory creation
// ddraw.dll proxy intercepts DirectDrawCreate
extern "C" HRESULT WINAPI DirectDrawCreate(GUID* lpGUID, LPDIRECTDRAW* lplpDD, IUnknown* pUnkOuter) {
    // Load original
    static auto real_func = (decltype(&DirectDrawCreate))
        GetProcAddress(LoadLibraryW(L"C:\\Windows\\System32\\ddraw.dll"), "DirectDrawCreate");
    HRESULT hr = real_func(lpGUID, lplpDD, pUnkOuter);
    if (SUCCEEDED(hr))
        *lplpDD = new DDraw7Wrapper(*lplpDD); // wrap with compatibility shim
    return hr;
}
```

---

## NVIDIA/DLSS
https://github.com/NVIDIA/DLSS

NVIDIA's DLSS SDK (1335 stars). Provides DLSS 2.x (temporal upscaling), DLSS 3 (frame generation), and DLSS Ray Reconstruction. Integration: call `NVSDK_NGX_D3D12_Init`, create a `DLSS` feature with `NVSDK_NGX_D3D12_CreateFeature`, then call `NVSDK_NGX_D3D12_EvaluateFeature` per frame with motion vectors, depth, and color buffers. Requires shipping the NGX runtime DLLs.

```cpp
// DLSS integration skeleton (D3D12)
NVSDK_NGX_D3D12_Init(APP_ID, L".", device);

// Create feature once at startup or on resolution change
NVSDK_NGX_PerfQuality_Value quality = NVSDK_NGX_PerfQuality_Value_Balanced;
NVSDK_NGX_Parameter* params = nullptr;
NVSDK_NGX_D3D12_GetCapabilityParameters(&params);
params->Set(NVSDK_NGX_Parameter_Width,  renderWidth);
params->Set(NVSDK_NGX_Parameter_Height, renderHeight);
params->Set(NVSDK_NGX_Parameter_OutWidth,  displayWidth);
params->Set(NVSDK_NGX_Parameter_OutHeight, displayHeight);
NVSDK_NGX_Handle* dlssHandle = nullptr;
NVSDK_NGX_D3D12_CreateFeature(cmdList, NVSDK_NGX_Feature_SuperSampling, params, &dlssHandle);

// Per frame:
NVSDK_NGX_D3D12_DLSS_Eval_Params evalParams = {};
evalParams.Feature.pInColor        = colorBuffer;
evalParams.Feature.pInOutput       = upscaledBuffer;
evalParams.pInDepth                = depthBuffer;
evalParams.pInMotionVectors        = motionVectors;
evalParams.InJitterOffsetX         = jitterX;
evalParams.InJitterOffsetY         = jitterY;
NVSDK_NGX_D3D12_EvaluateFeature(cmdList, dlssHandle, params, &evalParams);
```

---

## intel/xess
https://github.com/intel/xess

Intel XeSS SDK (957 stars) — ML-based upscaling that runs on any DX12 GPU (DP4a instructions), not just Intel. Integration is similar to DLSS: init, create context, evaluate per-frame. XeSS uses a pre-trained network and runs on the GPU as a compute shader dispatch. The SDK ships with multiple quality levels (Ultra Performance -> Ultra Quality).

```cpp
// XeSS integration (D3D12)
xess_d3d12_init_params_t init_params = {};
init_params.outputResolution.x = displayWidth;
init_params.outputResolution.y = displayHeight;
init_params.qualitySetting = XESS_QUALITY_SETTING_BALANCED;
init_params.initFlags = XESS_INIT_FLAG_INVERTED_DEPTH;
xessD3D12Init(xess_context, device, &init_params);

// Per frame
xess_d3d12_execute_params_t exec_params = {};
exec_params.pColorTexture    = colorSRV;
exec_params.pVelocityTexture = motionSRV;
exec_params.pDepthTexture    = depthSRV;
exec_params.pOutputTexture   = outputUAV;
exec_params.jitterOffsetX    = jitterX;
exec_params.jitterOffsetY    = jitterY;
xessD3D12Execute(xess_context, cmdList, &exec_params);
```

---

## GPUOpen-LibrariesAndSDKs/FidelityFX-SDK
https://github.com/GPUOpen-LibrariesAndSDKs/FidelityFX-SDK

AMD's FidelityFX SDK (1673 stars) — collection of post-processing effects: FSR 3 (upscaling + frame gen), CACAO (ambient occlusion), SPD (single-pass downsampler), Denoiser, Lens, and more. Each effect is provided as a standalone C++ class with a unified `Dispatch()` interface. The SDK abstracts DX12/Vulkan via `ffx_interface_*` backends.

```cpp
// FSR 3 upscaling setup
FfxFsr3ContextDescription contextDesc = {};
contextDesc.maxRenderSize   = {renderWidth, renderHeight};
contextDesc.displaySize     = {displayWidth, displayHeight};
contextDesc.flags           = FFX_FSR3_ENABLE_HIGH_DYNAMIC_RANGE;
FfxFsr3Context fsr3Context;
ffxFsr3ContextCreate(&fsr3Context, &contextDesc);

// Per frame dispatch
FfxFsr3DispatchUpscaleDescription dispatch = {};
dispatch.color         = colorResource;
dispatch.depth         = depthResource;
dispatch.motionVectors = motionResource;
dispatch.output        = outputResource;
dispatch.jitterOffset  = {jitterX, jitterY};
dispatch.frameTimeDelta = deltaMs;
ffxFsr3ContextDispatchUpscale(&fsr3Context, &dispatch);
```

---

## vulkano-rs/vulkano
https://github.com/vulkano-rs/vulkano

Safe Rust wrapper around Vulkan (4k+ stars). Provides type-safe render passes, pipeline descriptors, and command buffers with borrow-checker enforcement of resource lifetimes. A good reference for understanding Vulkan resource ownership semantics, even if you're not using Rust -- the API design decisions mirror the underlying Vulkan spec closely.

```rust
// vulkano: create a basic render pass with a single attachment
let render_pass = vulkano::single_pass_renderpass!(
    device.clone(),
    attachments: {
        color: {
            format: Format::R8G8B8A8_SRGB,
            samples: 1,
            load_op: Clear,
            store_op: Store,
        }
    },
    pass: {
        color: [color],
        depth_stencil: {}
    }
)?;
```
