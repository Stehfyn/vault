# D3D12 Multi-Engine Queues

D3D12 exposes graphics, compute, and copy queues as separate engines, but concurrency is only real when the hardware and workload allow overlap. The Microsoft guide matters because it shows the fence choreography: a copy queue uploads data, signals a fence, the graphics queue waits before consuming it, and resource states/barriers still have to describe ownership transitions correctly.

The trap is assuming extra queues automatically improve performance. They can just add synchronization latency if the copy is tiny, the async compute work contends for the same units, or the frame graph cannot get far enough ahead. Use this with `D3D12 Memory Allocator (AMD).md` for upload/readback heap lifetime and with `(DXGI) Microsoft DirectX Graphics Infrastructure.md` when queue depth affects present latency.

## References
- <https://learn.microsoft.com/en-us/windows/win32/direct3d12/multi-engine>
