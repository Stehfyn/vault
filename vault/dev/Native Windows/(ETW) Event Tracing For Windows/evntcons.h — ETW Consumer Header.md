# evntcons.h - ETW Consumer Header

`evntcons.h` is the low-level consumer-side header for ETW records, trace-log headers, event descriptors, and callback-facing structures. It is where the raw shape of a consumed event lives: provider GUID, event header, timestamp, process/thread IDs, activity IDs, and the opaque user data that still has to be interpreted.

The header is rarely enough by itself. Real consumers usually combine it with `tdh.h` for manifest decoding, `evntrace.h` for session control, and a wrapper such as krabsetw or TraceEvent to avoid hand-parsing every property. Keep it in mind when debugging wrapper behavior: if a field is not in `EVENT_RECORD`, the wrapper cannot invent it.

## Real-Time Session Shape

The raw consumer path is controller plus consumer: create a real-time session, enable providers, open the session for callbacks, process records, then stop the session cleanly.

```cpp
#include <evntrace.h>
#include <evntcons.h>
#include <tdh.h>

static void WINAPI OnEvent(PEVENT_RECORD record) {
    const auto& h = record->EventHeader;
    // h.ProviderId, h.EventDescriptor.Id, h.ProcessId, h.ThreadId, h.TimeStamp
    // record->UserData / record->UserDataLength still need TDH or provider knowledge.
}

ULONG StartRealtimeConsumer(const GUID& provider) {
    alignas(8) BYTE buffer[sizeof(EVENT_TRACE_PROPERTIES) + 2 * 1024] = {};
    auto props = reinterpret_cast<EVENT_TRACE_PROPERTIES*>(buffer);
    props->Wnode.BufferSize = sizeof(buffer);
    props->Wnode.Flags = WNODE_FLAG_TRACED_GUID;
    props->LogFileMode = EVENT_TRACE_REAL_TIME_MODE;
    props->LoggerNameOffset = sizeof(EVENT_TRACE_PROPERTIES);

    TRACEHANDLE session = 0;
    ULONG status = StartTraceW(&session, L"MyNativeRealtimeSession", props);
    if (status != ERROR_SUCCESS && status != ERROR_ALREADY_EXISTS) return status;

    status = EnableTraceEx2(session, &provider, EVENT_CONTROL_CODE_ENABLE_PROVIDER,
                            TRACE_LEVEL_VERBOSE, 0, 0, 0, nullptr);
    if (status != ERROR_SUCCESS) return status;

    EVENT_TRACE_LOGFILEW log = {};
    log.LoggerName = const_cast<LPWSTR>(L"MyNativeRealtimeSession");
    log.ProcessTraceMode = PROCESS_TRACE_MODE_EVENT_RECORD | PROCESS_TRACE_MODE_REAL_TIME;
    log.EventRecordCallback = OnEvent;

    TRACEHANDLE trace = OpenTraceW(&log);
    status = ProcessTrace(&trace, 1, nullptr, nullptr);
    CloseTrace(trace);
    ControlTraceW(session, L"MyNativeRealtimeSession", props, EVENT_TRACE_CONTROL_STOP);
    return status;
}
```

Use this skeleton to understand what krabsetw, Sealighter, wtrace, and ProcMonXv2 are saving you from. If a tool drops events or fails to decode a field, map the failure back to one of these layers: session configuration, provider enablement, buffering, callback dispatch, or TDH/schema parsing.

## Source Code Reading

The linked tools all collapse back to the structures declared by `evntcons.h` and session-control APIs in `evntrace.h`. The fields that matter to every consumer are in `EVENT_RECORD`:

```text
EVENT_RECORD
  EventHeader.ProviderId
  EventHeader.EventDescriptor.{Id,Version,Level,Opcode,Task,Keyword}
  EventHeader.ProcessId / ThreadId / TimeStamp
  UserData / UserDataLength
  ExtendedData / ExtendedDataCount
  UserContext
```

ProcMonXv2's `EventTracing/TraceManager.cpp` sets `EVENT_TRACE_LOGFILE.EventRecordCallback` and passes `this` through `Context`; the callback recovers the instance through `record->UserContext`. krabsetw does the same idea through `EVENT_TRACE_LOGFILE.Context = &trace_` and a callback thunk in `krabs/krabs/etw.hpp`. Sealighter receives the same `EVENT_RECORD` and only later promotes it to JSON through `krabs::schema` and `krabs::parser`.

This is the buried abstraction boundary: wrappers can decorate `EVENT_RECORD`, but they cannot invent fields missing from it. If you need call arguments not represented by provider metadata, switch to a process-local hook/debugger probe. If you need stacks, enable the relevant extended-data path and prove `ExtendedDataCount` changed.

Verifiable assertions to drive:

```text
claim: wrappers receive the same kernel/user event record shape
probe: print ProviderId/EventId/PID/TID/UserDataLength in raw consumer, krabsetw, and Sealighter

claim: stack traces are extended data, not normal properties
probe: toggle EVENT_ENABLE_PROPERTY_STACK_TRACE and inspect `ExtendedDataCount`

claim: dropped records are session-level evidence
probe: query `EVENT_TRACE_PROPERTIES.EventsLost` while callbacks are intentionally slowed
```

Source files read:
- Windows SDK `evntcons.h`
- `ProcMonXv2/EventTracing/TraceManager.cpp`
- `krabsetw/krabs/krabs/etw.hpp`
- `Sealighter/sealighter/sealighter_handler.cpp`

## Experiment Harness

Goal: prove the consumer path independently from the provider path: session starts, provider enablement matches, records arrive, and loss counters stay explainable.

```cpp
static std::atomic<uint64_t> g_seen = 0;

static void WINAPI OnEvent(PEVENT_RECORD r) {
    ++g_seen;
    printf("provider=%08x id=%hu pid=%lu tid=%lu bytes=%hu\n",
        r->EventHeader.ProviderId.Data1,
        r->EventHeader.EventDescriptor.Id,
        r->EventHeader.ProcessId,
        r->EventHeader.ThreadId,
        r->UserDataLength);
}
```

Procedure:
1. Start the real-time session with a deliberately unique session name.
2. Enable one known provider GUID first, then your custom `EventWrite` provider.
3. Print `g_seen` once per second while the producer runs.
4. Query the session during the run with `ControlTraceW(..., EVENT_TRACE_CONTROL_QUERY)` and print `EventsLost`, `RealTimeBuffersLost`, `LogBuffersLost`, `BuffersWritten`, and `FreeBuffers`.

```cpp
// Same EVENT_TRACE_PROPERTIES buffer layout used for StartTraceW.
ControlTraceW(session, L"MyNativeRealtimeSession", props, EVENT_TRACE_CONTROL_QUERY);
printf("seen=%llu lost=%lu rt_lost=%lu log_lost=%lu free=%lu written=%lu\n",
    g_seen.load(), props->EventsLost, props->RealTimeBuffersLost,
    props->LogBuffersLost, props->FreeBuffers, props->BuffersWritten);
```

Failure interpretation:
- `StartTraceW` returns `ERROR_ALREADY_EXISTS`: stale session; stop it or choose a new name.
- `EnableTraceEx2` succeeds but `g_seen == 0`: provider is idle, level/keyword mismatch, or provider GUID is not the registered runtime GUID.
- `EventsLost` rises while `g_seen` rises: session buffers are too small, callbacks are too slow, or disk/real-time delivery cannot keep up.
- `RealTimeBuffersLost` rises but file trace is clean: live consumer is the bottleneck; switch to file capture or reduce callback work.

## Connections
- Provider-side counterpart: `evntprov.h`.
- Practical consumers: `krabsetw`, `wtrace`, `ProcMonXv2`, and Sealighter.
- `relogger.h` belongs after capture when the artifact is an ETL file rather than a live callback stream.
- `UIforETW` uses the same ETW substrate but optimizes for WPA analysis rather than per-event application logic.

## Discussion Claim Verification

Claim: "The wrapper dropped the field."

Why it matters for new diagnostic code: field absence can happen at three separate layers: the provider never emitted it, the session delivered only opaque bytes, or the wrapper failed to decode metadata. Blaming the wrapper first wastes time.

How to verify:
1. Print raw `EVENT_RECORD` identity and `UserDataLength`.
2. If raw bytes exist, call TDH manually for event information and property sizes.
3. Compare with krabsetw/Sealighter parsed output.
4. Query `EVENT_TRACE_PROPERTIES` while running to expose loss counters.

Minimal code/pseudocode:

```cpp
OnEvent(EVENT_RECORD* r) {
  printf("id=%hu ver=%hhu pid=%lu bytes=%hu ext=%hu\n",
         r->EventHeader.EventDescriptor.Id,
         r->EventHeader.EventDescriptor.Version,
         r->EventHeader.ProcessId,
         r->UserDataLength,
         r->ExtendedDataCount);

  // next step: TdhGetEventInformation(r, 0, nullptr, buffer, &size)
}
```

Interpretation: `UserDataLength > 0` with missing names is a metadata/TDH problem. `UserDataLength == 0` may be a provider design choice. Rising `EventsLost` is a session/callback throughput problem. The callback/OpenTrace/properties docs support the consumer contract; they do not guarantee semantic field names.

## References
- Windows SDK `evntcons.h`
- <https://learn.microsoft.com/en-us/windows/win32/api/evntrace/nc-evntrace-pevent_record_callback>
- <https://learn.microsoft.com/en-us/windows/win32/api/evntrace/nf-evntrace-opentracea>
- <https://learn.microsoft.com/en-us/windows/win32/api/evntrace/ns-evntrace-event_trace_properties>
