# Windows-DLL-Injector - C++ Techniques

This repository is a small C++ collection of DLL-injection approaches across x86 and x64 processes. Its value is not that the methods are rare; it is that they provide a comparative view of the assumptions each method makes about architecture, target process state, loader behavior, and thread execution.

Keep the analysis at the artifact layer. Classic loader-based injection leaves different evidence than manual mapping or hook-assisted loading: module lists, image-load telemetry, remote allocation patterns, thread starts, and GUI hook requirements. That comparison is what makes the reference useful here.

## Connections
- `process-inject` and `Process-Injection` provide broader taxonomies.
- Hooks entries cover the SetWindowsHookEx branch of DLL loading.

## References
- <https://github.com/KooroshRZ/Windows-DLL-Injector>
