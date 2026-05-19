# WSL2 DirectX Userland (libdxg)

`libdxg` is the user-space side of DirectX-on-WSL. Linux processes talk to `/dev/dxg`, which is backed by the WSL dxgkrnl bridge and forwards WDDM-style operations to the Windows host GPU stack. The API mirrors D3DKMT concepts such as adapter LUIDs, allocations, submissions, synchronization, and locks.

This is not a graphics convenience wrapper; it is plumbing for CUDA-on-WSL, DirectML, and GPU virtualization. The useful connection for this vault is conceptual: WDDM allocation/submission surfaces show up both in native Windows D3D12 and in WSL through a Linux ioctl facade.

## References
- <https://github.com/microsoft/libdxg>

## Connections
- `D3D12 Memory Allocator (AMD).md`
- `(DX12) DirectX12.md`
