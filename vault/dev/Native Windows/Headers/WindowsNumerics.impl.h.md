# WindowsNumerics.impl.h

Inline implementation header for the `Windows::Foundation::Numerics` value types -- `float2`, `float3`, `float4`, `float3x2`, `float4x4`, `plane`, `quaternion` -- the lingua-franca math types shared across WinRT graphics surfaces (`Windows.UI.Composition`, `Windows.UI.Xaml.Media`, `Windows.Graphics.DirectX`, Microsoft.UI.* / WinUI 3). Roughly the same shape as XNA's `Vector3` / `Matrix4x4` -- column-major matrices, row-vector convention for `Transform()`, free functions for `dot`, `cross`, `length`, `normalize`, `lerp`. Bridges trivially to DirectXMath: the storage layout matches `XMFLOAT3` / `XMFLOAT4X4`, so you can `reinterpret_cast` and back. Included via `<winrt/Windows.Foundation.Numerics.h>` in cppwinrt code, or directly in C++/WRL projects. Cluster: `DirectXMath.h` (the SIMD-friendly internal compute side), `Windows.Foundation.Numerics` projection.

## References
- <https://learn.microsoft.com/en-us/uwp/api/windows.foundation.numerics>
- <https://learn.microsoft.com/en-us/windows/win32/dxmath/directxmath-portal>
