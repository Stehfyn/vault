# errhandlingapi.h

The error-handling cluster from `kernel32`: per-thread `GetLastError` / `SetLastError`, structured exception raising (`RaiseException`, `RaiseFailFastException`), process-wide unhandled-exception filtering (`SetUnhandledExceptionFilter`, `UnhandledExceptionFilter`), the OS-level error-reporting dialog gate (`SetErrorMode`), and (Vista+) the vectored exception handler chain that runs *before* SEH (`AddVectoredExceptionHandler`, `AddVectoredContinueHandler`, `RemoveVectoredExceptionHandler`). Two operational facts everyone should know: (1) `SetUnhandledExceptionFilter` is hijacked by the CRT's `__CxxFrameHandler` and by debuggers -- if WER or a JIT debugger is attached, your filter never runs; the supported alternative for "always run my crash handler" is a vectored exception handler with `EXCEPTION_CONTINUE_SEARCH` and `WerRegisterRuntimeExceptionModule`. (2) `RaiseFailFastException` (Win7+) is the right call for "I'm crashing on purpose, take the dump now" -- it skips all handlers and triggers WER immediately.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/errhandlingapi/>
- <https://learn.microsoft.com/en-us/windows/win32/debug/about-vectored-exception-handling>
