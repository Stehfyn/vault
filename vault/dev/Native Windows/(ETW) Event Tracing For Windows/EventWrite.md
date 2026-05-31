# EventWrite

`EventWrite` is the classic manifest-based ETW provider emission call: a provider registers a GUID, fills an `EVENT_DESCRIPTOR`, supplies one or more `EVENT_DATA_DESCRIPTOR` buffers, and lets ETW copy the payload into enabled sessions. The subtle point is that `EventWrite` is not self-describing by itself; consumers need the matching manifest, TDH metadata, or out-of-band knowledge to turn the descriptor and binary payload into useful fields.

For research, this entry anchors the producer side of ETW. `EventRegister` creates the per-process registration state ETWListicle inspects; `EnableTraceEx2` toggles whether a provider is hot; `OpenTrace`/`ProcessTrace` and TDH decode what was written. Misreading those layers leads to a common mistake: seeing a provider GUID and assuming meaningful telemetry is being emitted.

## Provider Skeleton

Minimal classic-provider shape: register once, check enablement only if the payload is expensive, write pointer/length pairs, then unregister during process teardown.

```cpp
#include <evntprov.h>

// {01234567-89AB-CDEF-0123-456789ABCDEF}
static const GUID ProviderGuid =
    { 0x01234567, 0x89ab, 0xcdef, { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef } };

static REGHANDLE g_provider = 0;

void EtwInit() {
    EventRegister(&ProviderGuid, nullptr, nullptr, &g_provider);
}

void EtwWriteServiceState(ULONG pid, const wchar_t* state) {
    EVENT_DESCRIPTOR desc = {};
    desc.Id = 1;
    desc.Version = 0;
    desc.Level = TRACE_LEVEL_INFORMATION;
    desc.Opcode = EVENT_TRACE_TYPE_INFO;

    EVENT_DATA_DESCRIPTOR data[2];
    EventDataDescCreate(&data[0], &pid, sizeof(pid));
    EventDataDescCreate(&data[1], state, ((ULONG)wcslen(state) + 1) * sizeof(wchar_t));

    EventWrite(g_provider, &desc, ARRAYSIZE(data), data);
}

void EtwShutdown() {
    EventUnregister(g_provider);
}
```

Connect this directly to service diagnostics: a service can report SCM state through `SetServiceStatus`, expose sampled state through WMI/PerfLib, and emit occurrence records through `EventWrite`. Those are not interchangeable channels.

## Source Code Reading

This note is first-party API/header driven rather than repository driven. The source-shaped contract lives in the Windows SDK headers and generated manifest provider headers: `EventRegister` creates a provider registration handle, `EventDataDescCreate` converts pointer/length pairs into `EVENT_DATA_DESCRIPTOR`s, and `EventWrite` copies the payload under an `EVENT_DESCRIPTOR`.

The body of a generated manifest provider macro is usually:

```text
EventWriteProvider_EventName(...)
  -> fill EVENT_DATA_DESCRIPTOR array
  -> point each descriptor at one argument buffer
  -> call EventWrite(RegHandle, &Descriptor, count, data)
```

Sealighter's generated `sealighter_provider.h` shows this concretely: `EventRegisterSealighter()` wraps `EventRegister`, `EventWriteSEALIGHTER_REPORT_EVENT(...)` expands into a template helper, and that helper ends by calling `EventWrite(RegHandle, Descriptor, ..., EventData)`.

The subtle contract is ownership and metadata:

```text
provider owns: provider GUID, REGHANDLE lifetime, descriptor ID/version/level/keyword
caller owns: argument buffers until EventWrite returns
ETW owns: copied event payload after EventWrite succeeds
consumer needs: manifest/TraceLogging/TDH knowledge to name fields
```

Verifiable assertions to drive:

```text
claim: registration is separable from event flow
probe: confirm provider appears in ETWListicle before any `EventWrite` records arrive

claim: successful EventWrite does not imply an enabled consumer saw it
probe: call `EventWrite` with no session and then with a krabsetw/raw consumer; compare callback counts

claim: payload delivery and field decoding are different
probe: consume raw `UserDataLength` first, then add manifest/TDH decoding and compare named fields
```

Source files read:
- Windows SDK `evntprov.h`
- `Sealighter/sealighter/sealighter_provider.h`
- Microsoft `EventWrite` documentation

## Experiment Harness

Goal: prove a provider emits only when a session enables the provider, and measure write failure modes without building a full manifest project.

```cpp
// Instrument the tiny provider skeleton, then vary event size and enabled state.
ULONG status = EventWrite(g_provider, &desc, ARRAYSIZE(data), data);
printf("EventWrite status=%lu pid=%lu bytes=%lu\n", status, GetCurrentProcessId(), payload_bytes);
```

Procedure:
1. Run the producer with no ETW session enabled. Expected signal: `EventWrite` returns `ERROR_SUCCESS`, but no external consumer sees records.
2. Start a real-time consumer for `ProviderGuid`. Expected signal: callback count increases and `EVENT_RECORD.EventHeader.ProcessId` matches the producer PID.
3. Increase payload toward the session buffer size. Expected signal: `ERROR_MORE_DATA` or missed records if the event cannot fit or the consumer/session cannot keep up.
4. Add level/keyword variants. Expected signal: event counts change only when the session enables matching level/keyword masks.

Failure interpretation:
- `ERROR_INVALID_HANDLE`: `EventRegister` failed or `EventUnregister` already ran.
- `ERROR_SUCCESS` with no records: no enabled matching session, wrong provider GUID, wrong keyword/level, or consumer attached after the write.
- Consumer sees binary payload but no fields: provider metadata/manifest/TDH path is missing; the event emission path still worked.

## Connections
- `evntprov.h` declares the provider APIs around `EventWrite`.
- `evntcons.h`, krabsetw, and TraceEvent sit on the consumer side and decode the resulting `EVENT_RECORD`s.
- `ETWListicle` can confirm this provider was registered inside the emitting process, but only a live consumer proves events are flowing.
- `Win32 Service Template` is the natural host pattern for long-lived providers: service lifecycle through SCM, diagnostics through ETW.

## Discussion Claim Verification

Claim: "`EventWrite` succeeded, so telemetry was recorded."

Why it matters for new diagnostic code: provider return status and consumer observation are different facts. A producer can successfully write into zero enabled sessions, and a consumer can receive binary payloads that it cannot decode into named fields.

How to verify:
1. Call `EventRegister`, then sleep without writing. Confirm ETWListicle-style registration if available.
2. Call `EventWrite` with no consumer. Log return status.
3. Start a raw real-time consumer. Call `EventWrite` again.
4. Add TDH/manifest decoding only after raw `EVENT_RECORD` count increments.

Minimal code/pseudocode:

```cpp
ULONG s = EventWrite(g_provider, &desc, data_count, data);
printf("write status=%lu enabled=%d\n",
       s, EventEnabled(g_provider, &desc));

// consumer side
OnEvent(r):
  print(r->EventHeader.ProviderId,
        r->EventHeader.EventDescriptor.Id,
        r->UserDataLength);
```

Interpretation: the Microsoft `EventWrite` and `EventEnabled` links support producer-side semantics. They do not prove a trace file contains the event. Evidence for recorded telemetry is a consumer callback, ETL export, or WPA row with matching provider, event ID, timestamp, and PID.

## References
- https://learn.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventwrite
- <https://learn.microsoft.com/en-us/windows/win32/api/evntprov/nf-evntprov-eventenabled>
