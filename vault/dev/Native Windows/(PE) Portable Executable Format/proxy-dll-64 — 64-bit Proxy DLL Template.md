# proxy-dll-64 - 64-bit Proxy DLL Template

proxy-dll-64 is a template for wrapper DLLs that stand in front of a real DLL while forwarding exports to the original implementation. In legitimate software this pattern appears in compatibility shims, instrumentation, modding ecosystems, and transitional wrappers; in analysis it is a clean way to study export forwarding, search order, and loader identity.

The important PE detail is that forwarding has to match the original export surface closely: names, ordinals, calling conventions, and architecture all matter. A sloppy proxy breaks consumers before any interesting behavior occurs. This entry is about the loader/export contract, not about stealth.

## Source Code Reading

The `Erik-JS/proxy-dll-64` repository is direct: each proxy DLL has a `main.cpp` with an array of original function addresses, plus shared plugin loading/logging helpers.

Files read:
- `d3d11/main.cpp`
- `d3d12/main.cpp`
- `dinput8/main.cpp`
- `winmm/main.cpp`
- `sharedcode/PluginLoader.cpp`
- `sharedcode/Logging.cpp`

The proxy composition is:

```text
DllMain(DLL_PROCESS_ATTACH)
  -> build path to real DLL, usually under system directory
  -> LoadLibrary(real DLL)
  -> GetProcAddress for each export this proxy forwards
  -> start log
  -> load optional plugin files

export stubs
  -> jump/call through stored address array
```

The `d3d11` and `winmm` variants show why this is tedious: a proxy must enumerate a large export surface, not just the one function the author currently cares about. `sharedcode/Logging.cpp` writes logs under the user's Documents known folder via `SHGetKnownFolderPath`, which is a small but useful deployment detail: the proxy avoids assuming its load directory is writable.

Claim -> source/probe -> interpretation:
- Claim: "A proxy DLL is transparent if it forwards exports."
- Source/probe: compare `dumpbin /exports original.dll` and `dumpbin /exports proxy.dll`; run a caller that exercises name and ordinal imports.
- Interpretation: transparency requires export names, ordinals, calling conventions, bitness, loader search path, and side-effect timing to match. A proxy that forwards only common names may work for one app and fail for another.

## Discussion Claim Verification

Claim: "Forwarding the functions my app uses makes a proxy DLL correct."

Why it matters for new code: consumers bind by more than visible function names. They can import by ordinal, expect forwarded exports, rely on `DllMain` side effects, load resources, query version metadata, or depend on delay-load failure behavior. A partial proxy is a test fixture, not a transparent replacement.

How to verify:

```powershell
dumpbin /exports C:\Windows\System32\winmm.dll > original.exports.txt
dumpbin /exports .\winmm.dll > proxy.exports.txt
fc original.exports.txt proxy.exports.txt
dumpbin /dependents .\host.exe
gflags /i host.exe +sls
.\host.exe
```

Minimal code/pseudocode:

```text
for each export in original:
  preserve name
  preserve ordinal
  preserve calling convention and architecture
  resolve real address from the intended system DLL path
  fail loudly if resolution is missing
```

Interpretation: the repository verifies a practical proxy shape, not universal transparency. Unsupported claim nullified: "works for one target app" equals "correct proxy." Correctness is the export diff plus runtime exercise of name imports, ordinal imports, delay-load paths, and loader-search provenance.

## Connections
- `perfect-loader` and `Proxy-DLL-Loads` are loader-path manipulation notes with different goals.
- XPEViewer can inspect exports and forwarders to validate a proxy.

## References
- <https://github.com/Erik-JS/proxy-dll-64>
