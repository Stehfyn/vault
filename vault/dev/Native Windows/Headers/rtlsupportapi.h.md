# rtlsupportapi.h

The runtime-support / unwind subset of NTDLL's Rtl prefix: `RtlCaptureContext`, `RtlUnwindEx`, `RtlLookupFunctionEntry`, `RtlVirtualUnwind`, `RtlAddFunctionTable` / `RtlInstallFunctionTableCallback`, and the doubly-linked-list / hash-table helpers (`RtlInitializeSListHead`, `InitializeListHead`, `RtlRbInsertNodeEx`). Indispensable for x64 / ARM64 SEH on Windows because frame-based exception handling was scrapped in favour of table-driven unwind: each function exports a `RUNTIME_FUNCTION` describing how to restore its caller's `RSP` / non-volatile regs, and `RtlLookupFunctionEntry` is how a debugger or stack-walker finds that record from an `RIP`. JITs (`coreclr`, V8, LuaJIT) call `RtlAddFunctionTable` to register synthesized unwind info so exceptions can propagate through dynamic code.

## Source Code Reading

For dynamic code and PE loaders, the useful call chain is:

```c
CONTEXT ctx;
RtlCaptureContext(&ctx);

DWORD64 imageBase = 0;
PRUNTIME_FUNCTION rf =
    RtlLookupFunctionEntry(ctx.Rip, &imageBase, NULL);
```

Manual mappers and JITs need the inverse path: when executable code does not come from a normal image section with registered `.pdata`, call `RtlAddFunctionTable` with valid `RUNTIME_FUNCTION` records. Without that, stack walking and exception propagation through dynamic code are guesswork or failure.

Claim -> source/probe -> interpretation:
- Claim: "Copied executable bytes are enough for x64 code to run correctly."
- Probe: raise an exception through copied/JIT code with and without `RtlAddFunctionTable`.
- Interpretation: execution may work until the first unwind. Correct x64 runtime behavior requires unwind metadata, not just executable memory.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winnt/>
- <https://learn.microsoft.com/en-us/cpp/build/exception-handling-x64>
