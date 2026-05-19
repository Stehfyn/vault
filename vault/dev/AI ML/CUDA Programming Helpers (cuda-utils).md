<!-- generated-from-dump2 -->
# CUDA Programming Helpers (cuda-utils)

Small grab-bag of CUDA-programming helpers — error-checked launch macros, pinned-memory RAII wrappers, simple cuBLAS/cuSolver shims, and a few common kernels (memset_typed, transpose, reduce). Useful as a scratchpad starter when you don't want to set up a full framework but you also don't want to retype `cudaGetLastError()` / `cudaDeviceSynchronize()` boilerplate for the nth time.

```cpp
#include "cuda_utils.h"

// Error-checked launch: aborts with file/line + cudaGetErrorString on failure.
CUDA_CHECK(cudaMalloc(&d_x, n * sizeof(float)));
my_kernel<<<grid, block>>>(d_x, n);
CUDA_CHECK_LAST();           // cudaGetLastError + cudaDeviceSynchronize
```

## References
- <https://github.com/abdimoallim/cuda-utils>
