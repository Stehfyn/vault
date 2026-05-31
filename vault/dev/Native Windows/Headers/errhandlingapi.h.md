# errhandlingapi.h

The error-handling cluster from `kernel32`: per-thread `GetLastError` / `SetLastError`, structured exception raising (`RaiseException`, `RaiseFailFastException`), process-wide unhandled-exception filtering (`SetUnhandledExceptionFilter`, `UnhandledExceptionFilter`), the OS-level error-reporting dialog gate (`SetErrorMode`), and (Vista+) the vectored exception handler chain that runs *before* SEH (`AddVectoredExceptionHandler`, `AddVectoredContinueHandler`, `RemoveVectoredExceptionHandler`). Two operational facts everyone should know: (1) `SetUnhandledExceptionFilter` is hijacked by the CRT's `__CxxFrameHandler` and by debuggers -- if WER or a JIT debugger is attached, your filter never runs; the supported alternative for "always run my crash handler" is a vectored exception handler with `EXCEPTION_CONTINUE_SEARCH` and `WerRegisterRuntimeExceptionModule`. (2) `RaiseFailFastException` (Win7+) is the right call for "I'm crashing on purpose, take the dump now" -- it skips all handlers and triggers WER immediately.

## Source Code Reading

The code-level distinction is handler order and intent.

```c
LONG CALLBACK Veh(PEXCEPTION_POINTERS ep) {
    // log minimal crash context
    return EXCEPTION_CONTINUE_SEARCH;
}

PVOID cookie = AddVectoredExceptionHandler(1, Veh);
RaiseException(0xE0000001, 0, 0, NULL);
RemoveVectoredExceptionHandler(cookie);
```

Probe matrix:
- `RaiseException` -> vectored handler -> SEH/unhandled filters/debugger policy.
- access violation -> vectored handler -> frame handlers -> unhandled filter/WER.
- `RaiseFailFastException` -> fail-fast path; normal handlers are not a recovery path.

Claim -> source/probe -> interpretation:
- Claim: "`SetUnhandledExceptionFilter` gives me a reliable crash hook."
- Probe: register VEH and unhandled filter; run under debugger, without debugger, and with CRT/C++ exceptions.
- Interpretation: VEH is the earlier observation point. Unhandled filters are process policy hooks and can be bypassed by debugger/WER/CRT behavior.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/>
- <https://learn.microsoft.com/en-us/windows/win32/debug/about-vectored-exception-handling>
