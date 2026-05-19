# evntprov.h - ETW Provider Header

`evntprov.h` is the provider-side ETW surface: registration, enable callbacks, descriptors, and event emission. It is the header behind classic manifest providers and direct calls such as `EventRegister`, `EventWrite`, `EventWriteTransfer`, and `EventUnregister`.

The important nuance is lifecycle. Registration creates per-process state in `ntdll`; sessions enable providers by GUID and keyword/level; the provider can cheaply test enablement before building expensive payloads. That lifecycle is why registration inventory, schema exploration, and live capture are separate jobs rather than one generic "ETW" action.

## Connections
- `EventWrite` is the key emission call exposed here.
- ETWListicle inspects the runtime registration state produced by these APIs.
- `evntcons.h` describes what consumers receive after the event is written.

## References
- Windows SDK `evntprov.h`
