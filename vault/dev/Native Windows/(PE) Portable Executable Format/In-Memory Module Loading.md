# In-Memory Module Loading

MemoryModule is the classic benign reference for loading a PE-format DLL from a memory buffer instead of from a file path. It has to reproduce the loader's core jobs: map sections with the right permissions, apply base relocations, resolve imports, handle TLS, expose exports, and call initialization in the expected order.

The reason it belongs here is contrast. Windows' real loader updates `PEB->Ldr`, sends DLL notifications, applies policy, participates in ETW/image-load telemetry, and integrates with exception/unwind metadata. In-memory loaders often miss some of that behavior, which is why they are useful for studying loader contracts and why they leave different forensic artifacts.

## Connections
- `ManualMap`, `MemJect`, and Reflective DLL Loader notes are security-adjacent variations of the same loader responsibilities.
- `perfect-loader` and `Proxy-DLL-Loads` show different relationships to the official loader path.

## References
- https://raw.githubusercontent.com/fancycode/MemoryModule/master/example/DllLoader/DllLoader.cpp
- https://github.com/fancycode/MemoryModule
