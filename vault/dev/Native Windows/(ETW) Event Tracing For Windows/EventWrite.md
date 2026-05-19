# EventWrite

`EventWrite` is the classic manifest-based ETW provider emission call: a provider registers a GUID, fills an `EVENT_DESCRIPTOR`, supplies one or more `EVENT_DATA_DESCRIPTOR` buffers, and lets ETW copy the payload into enabled sessions. The subtle point is that `EventWrite` is not self-describing by itself; consumers need the matching manifest, TDH metadata, or out-of-band knowledge to turn the descriptor and binary payload into useful fields.

For research, this entry anchors the producer side of ETW. `EventRegister` creates the per-process registration state ETWListicle inspects; `EnableTraceEx2` toggles whether a provider is hot; `OpenTrace`/`ProcessTrace` and TDH decode what was written. Misreading those layers leads to a common mistake: seeing a provider GUID and assuming meaningful telemetry is being emitted.

## Connections
- `evntprov.h` declares the provider APIs around `EventWrite`.
- `evntcons.h`, krabsetw, and TraceEvent sit on the consumer side and decode the resulting `EVENT_RECORD`s.

## References
- https://learn.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventwrite
