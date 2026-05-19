# Binary Size Reduction

Small Windows binaries are mostly a linker discipline problem. `/Os`, `/GL`, `/Gy`, `/Gw`, `/OPT:REF`, and `/OPT:ICF` remove dead functions, isolate data, fold identical COMDATs, and let LTCG see across translation units; they do not fix accidental CRT pull-in from exceptions, iostreams, locale, static constructors, stack cookies, checked iterators, or security-cookie initialization. The first useful pass is to inspect imports and map files: if a "tiny" tool imports `ucrtbase.dll`, `vcruntime*.dll`, or large C++ runtime surfaces, the source likely used a convenience feature that forced startup and teardown machinery into the binary.

The `fmt` size-reduction discussion matters because it shows the real trap: formatting libraries often instantiate templates and locale paths that dwarf the application's own logic. For no-CRT Win32 tools, the alternative is not "write everything in assembly"; it is to keep the API boundary explicit, use compiler intrinsics for memory primitives where possible, avoid C++ runtime features that imply global initialization, and link only the Win32 import libraries you actually call.

## Connections
- `No-CRT Win32`, `Win32 No-CRT C Template`, and `CRT Linkage (MD MT DLL)` are the practical knobs behind most size wins.
- `VC-LTL5` is a different tradeoff: keep CRT semantics but forward much of the implementation to system DLLs.

## References
- <https://www.reddit.com/r/cpp/comments/1f561x3/honey_i_shrunk_fmt_bringing_binary_size_to_14k/>
- <https://downloads.ctfassets.net/9pcn2syx7zns/1WZnLuQfJlIcjRR8GeJRM2/857dc5743f68461a7e0e39a5faabfd87/c-run-time-reference.pdf>
