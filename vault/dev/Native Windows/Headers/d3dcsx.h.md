# d3dcsx.h

Deprecated Direct3D 11 Compute Shader Extensions helper header from the old DirectX SDK era. It wrapped stock compute kernels for FFTs, parallel prefix scans, and segmented scans so samples could demonstrate GPGPU workloads before most engines had their own compute utility layer. Its value today is historical: it shows Microsoft's pre-D3D12 model for "library compute" on top of D3D11 resources and UAVs, but it is not a modern dependency. New code should use DirectCompute directly, vendor SDK kernels, DirectML, or a D3D12/Vulkan compute path where resource barriers and descriptor ownership are explicit.

Connections: compare with `(DX) DirectX/D3D12 Multi-Engine Queues.md` and `(DX) DirectX/Bindless Deferred Texturing (D3D12).md`; those entries show why the D3D11 helper-library model aged poorly once async compute and explicit resource-state tracking became normal.

## References
- d3dcsx.h
