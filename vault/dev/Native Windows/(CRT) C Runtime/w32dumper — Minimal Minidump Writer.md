# w32dumper — Minimal Minidump Writer

Aegisub's `w32dumper` is a useful model for crash capture because it is deliberately boring: resolve `dbghelp.dll`, call `MiniDumpWriteDump`, and avoid turning the exception filter into a second crash site. The operational detail is the point. Code running under `SetUnhandledExceptionFilter` should not allocate through the CRT, throw C++ exceptions, initialize COM, or use logging code that might take locks already held by the crashing thread.

The better architecture is still an out-of-process dumper. In-process minidumps work for ordinary access violations, but stack overflow, heap corruption, loader-lock failures, or overwritten process state can break the handler before it writes anything. `SetThreadStackGuarantee`, conservative dump flags, and returning either `EXCEPTION_EXECUTE_HANDLER` or `EXCEPTION_CONTINUE_SEARCH` are the knobs that decide whether your handler replaces or supplements Windows Error Reporting.

## Connections
- `DbgHelp.h` provides `MiniDumpWriteDump`; the entry is here because minimal dumpers often avoid the CRT as carefully as tiny launchers do.
- `errhandlingapi.h` covers the SEH and unhandled-filter surface around the dumper.

## References
- <https://github.com/Aegisub/w32dumper>
