# Reflective DLL Loader (Extended)

ReflectiveLoaderEx matters because it addresses the parts of reflective loading that toy examples usually skip: TLS callbacks, C++ initialization expectations, x64 unwind metadata, and exception handling. Those details are not optional for many real DLLs; they are part of what the Windows loader normally sets up before code assumes the module is alive.

The defensive angle is the same: the closer a reflective loader gets to correctness, the more loader semantics it must reproduce, and each reproduced or omitted step creates artifacts. Exception function tables, TLS directories, import resolution, memory protections, and missing loader-list state are all clues that a module did not arrive through the ordinary path.

## Connections
- `In-Memory Module Loading` is the benign baseline for loader reimplementation.
- `ManualMap` and `MemJect` are simpler relatives that expose the same responsibilities.

## References
- <https://github.com/wwh1004/ReflectiveLoaderEx>
