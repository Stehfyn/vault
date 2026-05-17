# DDS Utilities

Archived NVIDIA DDS utilities (nvDXT, readDXT, detach/stitch). For programmatic loading, DirectXTex offers a clean API for DDS parsing.

```cpp
#include <DirectXTex.h>

DirectX::ScratchImage image;
HRESULT hr = DirectX::LoadFromDDSFile(L"texture.dds",
                                      DirectX::DDS_FLAGS_NONE,
                                      nullptr, image);
```

## References
- https://archive.org/details/NVIDIA_DDS_Utilities_8.31
