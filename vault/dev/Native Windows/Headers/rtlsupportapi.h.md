# rtlsupportapi.h

The runtime-support / unwind subset of NTDLL's Rtl prefix: `RtlCaptureContext`, `RtlUnwindEx`, `RtlLookupFunctionEntry`, `RtlVirtualUnwind`, `RtlAddFunctionTable` / `RtlInstallFunctionTableCallback`, and the doubly-linked-list / hash-table helpers (`RtlInitializeSListHead`, `InitializeListHead`, `RtlRbInsertNodeEx`). Indispensable for x64 / ARM64 SEH on Windows because frame-based exception handling was scrapped in favour of table-driven unwind: each function exports a `RUNTIME_FUNCTION` describing how to restore its caller's `RSP` / non-volatile regs, and `RtlLookupFunctionEntry` is how a debugger or stack-walker finds that record from an `RIP`. JITs (`coreclr`, V8, LuaJIT) call `RtlAddFunctionTable` to register synthesized unwind info so exceptions can propagate through dynamic code.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winnt/>
- <https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64>
