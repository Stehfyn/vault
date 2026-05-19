# Math3DHelper.h

Sample / SDK-internal convenience header layered on top of DirectXMath. Not part of the public SDK install -- you'll find it inside Microsoft sample repositories (e.g. the older Win2D / DirectX TK / WinRT Composition samples) where the same handful of vector ops (`XMFLOAT3` add/subtract, cross/dot helpers that return scalars, simple matrix constructors) gets pasted into project after project. Treat it as a project-local utility; the modern path is to use DirectXMath / DirectXMath::SimpleMath directly, or `Windows::Foundation::Numerics` if you're already in a WinRT codebase. Nothing here is unique enough to warrant a runtime dependency.

## References
- <https://learn.microsoft.com/en-us/windows/win32/dxmath/directxmath-portal>
- <https://github.com/microsoft/DirectXTK/wiki/SimpleMath>
