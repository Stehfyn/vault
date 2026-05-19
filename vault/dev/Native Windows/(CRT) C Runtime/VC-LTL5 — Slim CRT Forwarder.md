# VC-LTL5 — Slim CRT Forwarder to System DLL

VC-LTL is a compatibility and size tactic: keep MSVC source-level CRT expectations, but replace the normal static CRT libraries with import/forwarder libraries that resolve as much as possible to system CRT DLLs such as `msvcrt.dll` or `ucrtbase.dll`. That yields much smaller binaries than `/MT` while avoiding a separate redist for some targets. The cost is that you are now relying on the exact CRT surface present on the target OS, so feature selection and minimum-OS targeting become part of the link step rather than a packaging afterthought.

This is not the same as no-CRT programming. C++ initialization, security helpers, floating-point support, and allocator semantics still exist; VC-LTL just changes where implementation bodies come from. It pairs naturally with API thunk projects when a modern toolchain is used to produce binaries for old Windows versions.

## Connections
- `CRT Linkage (MD MT DLL)` gives the baseline model VC-LTL bends.
- `Binary Size Reduction` and `No-CRT Win32` are more aggressive approaches when CRT semantics are disposable.

## References
- <https://github.com/Chuyu-Team/VC-LTL5>
