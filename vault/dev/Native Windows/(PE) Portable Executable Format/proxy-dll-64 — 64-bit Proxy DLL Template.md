# proxy-dll-64 - 64-bit Proxy DLL Template

proxy-dll-64 is a template for wrapper DLLs that stand in front of a real DLL while forwarding exports to the original implementation. In legitimate software this pattern appears in compatibility shims, instrumentation, modding ecosystems, and transitional wrappers; in analysis it is a clean way to study export forwarding, search order, and loader identity.

The important PE detail is that forwarding has to match the original export surface closely: names, ordinals, calling conventions, and architecture all matter. A sloppy proxy breaks consumers before any interesting behavior occurs. This entry is about the loader/export contract, not about stealth.

## Connections
- `perfect-loader` and `Proxy-DLL-Loads` are loader-path manipulation notes with different goals.
- XPEViewer can inspect exports and forwarders to validate a proxy.

## References
- <https://github.com/Erik-JS/proxy-dll-64>
