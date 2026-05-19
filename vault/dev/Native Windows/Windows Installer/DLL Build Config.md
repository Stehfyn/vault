# DLL Build Config

For installer custom actions, shell extensions, and preload/shim DLLs, the build configuration is part of deployment correctness. `/LD` produces the DLL image, but CRT choice, target architecture, exports, manifests, delay-loads, and signing determine whether that DLL can actually load inside `msiexec.exe`, Explorer, a packaged app process, or an arbitrary AppInit target.

The x64 developer environment note matters because setup tooling frequently crosses architecture boundaries: a 32-bit custom action cannot load into 64-bit `msiexec`, and registry/file redirection changes what the action sees. Build both bitnesses intentionally instead of assuming "Any CPU" semantics exist for native DLLs.

## Connections
- `CRT Linkage (MD MT DLL)` covers the runtime boundary a deployed DLL brings with it.
- `win32-ldpreload` and `MSIX Package Support Framework` are examples where DLL load behavior is the whole mechanism.

## References
- <https://learn.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp?view=msvc-170>
- <https://learn.microsoft.com/en-us/cpp/build/how-to-enable-a-64-bit-visual-cpp-toolset-on-the-command-line?view=msvc-170>
