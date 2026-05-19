# CRT Startup Hooks

MSVC discovers pre-`main` work by walking linker-sorted subsections such as `.CRT$XIA..XIZ` for C initializers and `.CRT$XCA..XCZ` for C++ dynamic initializers. User code normally lands in `.CRT$XCU`; manually allocating a function pointer into `.CRT$XCT` or another alphabetically adjacent subsection changes ordering, which is why this technique is powerful and brittle at the same time. The hook runs only if the CRT startup path runs; `/ENTRY` plus `/NODEFAULTLIB` bypasses it entirely unless you implement the same table walk yourself.

Use this as a diagnostic or bootstrap escape hatch, not as hidden application architecture. At hook time, loader lock may still matter for DLLs, global object order across translation units is intentionally weak, and failure paths are ugly because the process has not reached user code yet. It also interacts badly with static CRT duplication: every statically linked DLL has its own initializer tables and teardown callbacks.

## Connections
- `No-CRT Win32` and `Win32 No-CRT C Template` are the cases where these tables disappear unless you recreate CRT startup.
- `CRT Linkage (MD MT DLL)` determines whether a module shares the process CRT DLL or owns a private static CRT instance.

## References
- <https://stackoverflow.com/questions/728939/how-to-execute-some-code-before-entering-the-main-routine-in-vc>
