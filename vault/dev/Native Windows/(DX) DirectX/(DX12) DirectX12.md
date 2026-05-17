# DirectX 12

## rocksdanister/weather
https://github.com/rocksdanister/weather
Brief: Real-world DX12 app showcasing command lists and per-frame allocators.
```cpp
ID3D12CommandAllocator* allocator = nullptr;
device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&allocator));
ID3D12GraphicsCommandList* list = nullptr;
device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, allocator, nullptr, IID_PPV_ARGS(&list));
list->Close();
allocator->Reset();
```

## LearnDirectX-samples
https://github.com/PAMinerva/LearnDirectX-samples
Brief: Step-by-step samples that build the DX12 pipeline and descriptor heaps.
```cpp
D3D12_DESCRIPTOR_HEAP_DESC rtvDesc = {};
rtvDesc.NumDescriptors = frameCount;
rtvDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
rtvDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
ID3D12DescriptorHeap* rtvHeap = nullptr;
device->CreateDescriptorHeap(&rtvDesc, IID_PPV_ARGS(&rtvHeap));
UINT rtvSize = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
```

https://github.com/sawickiap/D3d12info
D3d12info queries every D3D12 feature tier and option via CheckFeatureSupport. Reference it to understand the capability matrix before choosing a rendering path.
```cpp
D3D12_FEATURE_DATA_D3D12_OPTIONS opts = {};
device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &opts, sizeof(opts));
// Resource heap tier 2 allows mixing buffer/texture/RT in one heap
if (opts.ResourceHeapTier == D3D12_RESOURCE_HEAP_TIER_2) { /* ... */ }

D3D12_FEATURE_DATA_SHADER_MODEL sm = { D3D_SHADER_MODEL_6_6 };
device->CheckFeatureSupport(D3D12_FEATURE_SHADER_MODEL, &sm, sizeof(sm));
```

https://github.com/StarsX/XUSG
XUSG wraps D3D12 boilerplate (device/queue/command list creation, resource barriers, descriptor heaps) behind a clean API. Useful reference for understanding the minimal D3D12 setup path.
```cpp
// Minimal D3D12 setup pattern (XUSG style)
ComPtr<ID3D12Device> device;
D3D12CreateDevice(nullptr, D3D_FEATURE_LEVEL_11_0, IID_PPV_ARGS(&device));

D3D12_COMMAND_QUEUE_DESC qd = {};
qd.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
ComPtr<ID3D12CommandQueue> queue;
device->CreateCommandQueue(&qd, IID_PPV_ARGS(&queue));

ComPtr<ID3D12CommandAllocator> alloc;
device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&alloc));
ComPtr<ID3D12GraphicsCommandList> cmdList;
device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, alloc.Get(), nullptr, IID_PPV_ARGS(&cmdList));
```

https://github.com/GameTechDev/TAA
Temporal anti-aliasing requires per-frame projection jitter plus a history buffer blend. The jitter offset is taken from a Halton sequence (bases 2 and 3) and injected into the projection matrix translation row.
```cpp
// Jitter the projection matrix for TAA
uint32_t frameIdx = GetFrameIndex();
float jitterX = Halton(frameIdx & 7, 2) - 0.5f;
float jitterY = Halton(frameIdx & 7, 3) - 0.5f;
// Offset in NDC space: divide by viewport dims
XMMATRIX proj = GetBaseProjection();
proj.r[2] = XMVectorSetX(proj.r[2], XMVectorGetX(proj.r[2]) + jitterX * 2.0f / viewW);
proj.r[2] = XMVectorSetY(proj.r[2], XMVectorGetY(proj.r[2]) + jitterY * 2.0f / viewH);
// Blend: out = lerp(history, current, 0.1)
```
