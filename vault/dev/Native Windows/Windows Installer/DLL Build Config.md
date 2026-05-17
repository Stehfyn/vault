## References
- https://learn.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp?view=msvc-170
- https://learn.microsoft.com/en-us/cpp/build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line?view=msvc-170

Build DLLs with /LD (or /DLL) and use the x64 toolset via vcvarsall to access 64-bit hosted tools and larger memory limits.

```bat
call "%VSINSTALLDIR%VC\Auxiliary\Build\vcvarsall.bat" x64
cl /LD /MD MyDll.cpp /Fe:MyDll.dll
```
