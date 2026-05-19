# DirectX 12

The useful D3D12 material here is not "how to create a device"; it is how real projects structure explicit GPU ownership. `LearnDirectX-samples` walks through the canonical sequence: factory/adapter, device, command queue, command allocator/list, descriptor heaps, fences, then resources. `D3d12info` is the capability-query counterpart: before choosing bindless resources, mesh shaders, shader model targets, resource heap behavior, or raytracing, ask `CheckFeatureSupport` and branch on the actual adapter.

The sample/framework links show different levels of abstraction. `XUSG` wraps barriers, descriptors, and resource lifetimes into a thinner API for experiments; Intel's TAA sample shows the temporal-rendering requirements that D3D12 makes explicit: jittered projection, history buffers, motion vectors, and stable frame indexing. Connect this note to `DXGI` whenever presentation behavior matters, because swap chains, tearing, HDR metadata, and frame pacing are DXGI contracts even in D3D12 apps.

## Device, Queue, and Fence

The LearnDirectX samples contribute the canonical ownership chain. D3D12 does not hide queue submission or completion; every resource lifetime decision eventually depends on a fence value.

```cpp
wil::com_ptr<ID3D12Device> device;
D3D12CreateDevice(adapter.get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&device));

D3D12_COMMAND_QUEUE_DESC queue_desc = {};
queue_desc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

wil::com_ptr<ID3D12CommandQueue> queue;
device->CreateCommandQueue(&queue_desc, IID_PPV_ARGS(&queue));

wil::com_ptr<ID3D12Fence> fence;
device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
UINT64 next_fence_value = 1;
```

## Capability Gating

`D3d12info` contributes the habit that separates robust D3D12 code from sample code: query the adapter before committing to shader model, raytracing, mesh shaders, resource binding tier, or enhanced barriers.

```cpp
D3D12_FEATURE_DATA_D3D12_OPTIONS7 options7 = {};
if (SUCCEEDED(device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS7,
                                          &options7, sizeof(options7))) &&
    options7.MeshShaderTier != D3D12_MESH_SHADER_TIER_NOT_SUPPORTED) {
    // Enable mesh-shader path for this adapter.
}
```

## Descriptors, Barriers, and History

`XUSG` contributes abstraction pressure around descriptors/barriers; the TAA sample contributes the frame-history contract. A temporal effect is not just a shader: it owns jitter, motion vectors, previous-frame resources, and barrier order.

```cpp
D3D12_RESOURCE_BARRIER barrier = {};
barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
barrier.Transition.pResource = history_texture.Get();
barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE;
barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;
barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
command_list->ResourceBarrier(1, &barrier);
```

## References
- <https://github.com/PAMinerva/LearnDirectX-samples> - stepwise D3D12 pipeline and descriptor heap samples.
- <https://github.com/sawickiap/D3d12info> - exhaustive `CheckFeatureSupport` capability dump.
- <https://github.com/StarsX/XUSG> - compact D3D12/Vulkan-style helper layer.
- <https://github.com/GameTechDev/TAA> - temporal AA sample with projection jitter and history resolve.
- <https://github.com/rocksdanister/weather> - real Win32/DX12 app structure rather than a synthetic triangle.

## Connections
- `(DXGI) Microsoft DirectX Graphics Infrastructure.md`
- `D3D12 Multi-Engine Queues.md`
- `D3D12 Memory Allocator (AMD).md`
- `Bindless Deferred Texturing (D3D12).md`
