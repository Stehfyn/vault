# evntcons.h - ETW Consumer Header

`evntcons.h` is the low-level consumer-side header for ETW records, trace-log headers, event descriptors, and callback-facing structures. It is where the raw shape of a consumed event lives: provider GUID, event header, timestamp, process/thread IDs, activity IDs, and the opaque user data that still has to be interpreted.

The header is rarely enough by itself. Real consumers usually combine it with `tdh.h` for manifest decoding, `evntrace.h` for session control, and a wrapper such as krabsetw or TraceEvent to avoid hand-parsing every property. Keep it in mind when debugging wrapper behavior: if a field is not in `EVENT_RECORD`, the wrapper cannot invent it.

## Connections
- Provider-side counterpart: `evntprov.h`.
- Practical consumers: `krabsetw`, `wtrace`, `ProcMonXv2`, and Sealighter.

## References
- Windows SDK `evntcons.h`
