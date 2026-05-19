<!-- generated-from-dump2 -->
# Visual C++ Team Sample Archive

Sample-code archive maintained alongside the Visual C++ team — historical MFC / ATL / Win32 / DirectShow samples plus newer C++/WinRT and modules examples. Where MSDN / learn.microsoft.com pages link to a "complete sample on GitHub", this is often the repo. Quality varies wildly by sample: the C++/WinRT and DirectX 12 demos are recent and well-maintained; the MFC samples are direct extractions from `vcredist` install bundles and have not been seriously updated since 2010-ish. Useful as a search target ("does anyone have a working `IFileDialog` sample" → likely yes, in here) rather than as a curriculum.

```text
# Tree shape (approximate; check the README for the current index):
VC2008Samples/  - legacy MFC/ATL/CRT samples
VC2010Samples/  - C++0x preview, parallel-patterns library
VC2013Samples/  - WinRT 8.x, Direct2D updates
VC2017Samples/  - C++/WinRT, /std:c++latest demos
VC2022Samples/  - Modules, C++20 ranges, std::format
```

```cpp
// Each sample is a self-contained Visual Studio solution — open the .sln
// at its root. Most use msbuild / vcpkg; a few link to legacy DDK headers.
```

## References
- <https://github.com/microsoft/VCSamples>
