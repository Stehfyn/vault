# ManualMap - Textbook Manual-Map Injector

Manual mapping is a reimplementation of enough of the Windows PE loader to make a DLL image run without calling the normal `LoadLibrary` path. The useful anatomy is loader responsibility: section mapping, relocations, import resolution, TLS callbacks, exception/unwind data, page protections, and entry-point ordering. The common failure mode is assuming that copying sections and calling `DllMain` is equivalent to being loaded by Windows.

For defensive research, manual mapping is best studied by its missing or altered artifacts: incomplete `PEB->Ldr` participation, unusual private executable mappings, mismatched section permissions, absent image-load notifications, or header/entry-point tampering. Those observations connect it directly to ETW, process dump, and memory forensics notes.

## Connections
- `In-Memory Module Loading` is the benign loader-reimplementation baseline.
- `Reflective DLL Loader (Extended)` explains why TLS and unwind metadata are not optional for real-world DLLs.

## References
- <https://github.com/Zer0Mem0ry/ManualMap>
