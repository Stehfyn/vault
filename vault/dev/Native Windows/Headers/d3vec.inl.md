# d3vec.inl

Inline implementation of the legacy `D3DXVECTOR2` / `D3DXVECTOR3` / `D3DXVECTOR4` arithmetic operators (and matrix helpers) from the D3DX9 / D3DX10 utility library, pulled in by `d3dx9math.h`. D3DX itself was deprecated alongside the June 2010 DirectX SDK; from the August 2012 Win8 SDK onward the supported replacement is DirectXMath (`DirectXMath.h` -- header-only, SIMD-friendly `XMVECTOR` / `XMMATRIX` API on top of SSE/SSE2/AVX/NEON), and from C++/WinRT the equivalent is `Windows::Foundation::Numerics::float3` etc. (`WindowsNumerics.impl.h`). You only still see `d3vec.inl` in legacy DX9/DX10 samples and in third-party engines that never finished the port. Practically: if you're writing new code, ignore this header and use DirectXMath; if you're maintaining a DX9-era codebase, `D3DXVec3Normalize` etc. still work but require the deprecated `d3dx9.lib` from the legacy SDK.

## References
- <https://learn.microsoft.com/en-us/windows/win32/direct3d9/d3dx>
- <https://learn.microsoft.com/en-us/windows/win32/dxmath/directxmath-portal>
