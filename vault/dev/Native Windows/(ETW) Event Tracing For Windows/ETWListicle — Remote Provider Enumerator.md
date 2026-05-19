# ETWListicle - Remote Provider Enumerator

ETWListicle is useful because it looks at ETW from inside a process instead of from the controller side. It walks the target process's `ntdll` ETW registration state, so it can answer a question that `logman`, TDH enumeration, and normal consumers cannot: which providers has this process actually registered with `EventRegister`? That matters when validating sensor assumptions, investigating patched `EtwEventWrite` paths, or comparing what a process should expose against what is present at runtime.

The interesting boundary is that provider presence is not the same as provider activity. A process may register a GUID and never emit, emit only when enabled, or emit through a wrapper such as TraceLogging. Treat this as a registration inventory tool, not a substitute for a live consumer such as krabsetw, Sealighter, ProcMonXv2, or wtrace.

## Connections
- Pair with `evntprov.h` and `EventWrite` for the producer-side state that ETWListicle is inspecting.
- Pair with `krabsetw` or `ETWStudio` when the next step is decoding provider metadata and event fields.

## References
- <https://github.com/whokilleddb/ETWListicle>
