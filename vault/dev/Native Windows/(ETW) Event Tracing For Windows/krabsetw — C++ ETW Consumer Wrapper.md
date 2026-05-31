# krabsetw - C++ ETW Consumer Wrapper

krabsetw is valuable because it removes most of the brittle plumbing from native ETW consumers: session creation, provider enablement, callback dispatch, schema lookup, and typed property parsing. Raw ETW is powerful but hostile; a serious consumer has to manage `StartTrace`, `EnableTraceEx2`, `OpenTrace`, `ProcessTrace`, TDH property formatting, buffer sizing, and version-specific event layouts. krabsetw compresses that into provider objects and callbacks without hiding the ETW model.

The tradeoff is that it still depends on the quality of provider metadata. Manifest-backed providers decode cleanly; TraceLogging and private providers may require manual field handling or keyword research. It is best treated as a native equivalent to TraceEvent: high-level enough for tools, low-level enough to understand why capture sessions fail or fields disappear.

## Consumer Shape

The native examples reduce to this pattern: create a `user_trace`, add a provider by GUID, set keyword masks, attach a callback, enable the provider, and call `start()` on a worker thread if the rest of the program must keep running.

```cpp
#include <krabs.hpp>

void WatchProvider() {
    krabs::user_trace trace(L"native-windows-watch");
    krabs::provider<> provider(krabs::guid(L"{A0C1853B-5C40-4B15-8766-3CF1C58F985A}"));

    provider.any(0xf0010000000003ff);
    provider.add_on_event_callback([](const EVENT_RECORD& record,
                                      const krabs::trace_context& ctx) {
        krabs::schema schema(record, ctx.schema_locator);
        krabs::parser parser(schema);

        std::wcout << schema.provider_name()
                   << L" id=" << schema.event_id()
                   << L" opcode=" << schema.opcode_name()
                   << L" pid=" << record.EventHeader.ProcessId
                   << std::endl;
    });

    trace.enable(provider);
    trace.start(); // blocking
}
```

Kernel-provider examples follow the same callback model but use `krabs::kernel_trace` and provider helpers or PERFINFO group masks. That is the route from ProcMon-style process/file/registry observation to a small custom diagnostic tool.

## Source Code Reading

The abstraction body is in `krabs/krabs/etw.hpp` and `krabs/krabs/ut.hpp`. The headline `trace.start()` expands into:

```text
trace_manager<T>::start
  -> open()
      -> register_trace()
          -> StartTrace(...)
          -> if session exists: stop_trace(), retry, or open existing if not privileged
      -> enable_providers()
          -> EnableTraceEx2(... EVENT_CONTROL_CODE_ENABLE_PROVIDER ...)
      -> open_trace()
          -> OpenTrace(EVENT_TRACE_LOGFILE with EventRecordCallback)
  -> process_trace()
      -> enable_rundown(...)
      -> ProcessTrace(...)
```

krabsetw owns four failure-prone ETW layers: session registration, provider enablement, real-time/file trace opening, and callback dispatch. When a callback does not fire, debug those layers in order instead of staring at the lambda.

`ut.hpp` contains the subtle piece: several `provider<>` objects with the same GUID are unioned before `EnableTraceEx2`. Level, any-keyword, all-keyword, trace flags, rundown state, and event-ID filters are merged into one provider enablement. This lets logical callbacks share a provider but can widen capture if a sibling asks for broader keywords.

```cpp
// pseudocode from krabs/krabs/ut.hpp
for each provider object:
  settings[guid].level |= provider.level
  settings[guid].any   |= provider.any
  settings[guid].all   |= provider.all
  settings[guid].trace_flags |= provider.trace_flags
  collect EVENT_FILTER_TYPE_EVENT_ID ids

EnableTraceEx2(session, guid, ENABLE_PROVIDER,
               level, any, all, 0, &parameters);
```

`ut::forward_events` explains wrapper-level "missing" events. Manifest and TraceLogging records route by `EventHeader.ProviderId`. MOF/WPP records may carry a message GUID, so krabsetw asks TDH for schema metadata to find the provider GUID. If WPP/MOF schema lookup fails and no default callback is set, records can disappear at dispatch time even though `ProcessTrace` delivered them.

Verifiable assertions to drive:

```text
claim: provider objects with the same GUID are union-enabled
probe: enable two logical providers with different event-id filters; compare callback counts and session query stats

claim: rundown must happen immediately before ProcessTrace
probe: enable provider rundown and move capture-state later/earlier in a local fork; count rundown events

claim: WPP/MOF routing depends on TDH schema lookup
probe: attach a default callback and count records that do not reach specific providers
```

Source files read:
- `krabs/krabs/etw.hpp`
- `krabs/krabs/ut.hpp`
- `krabs/krabs/provider.hpp`
- `examples/NativeExamples/user_trace_001.cpp`
- `examples/NativeExamples/kernel_and_user_trace_001.cpp`

## Experiment Harness

Goal: test whether wrapper-level decoding agrees with raw ETW delivery.

```cpp
std::atomic<uint64_t> seen = 0, decoded = 0;

provider.add_on_event_callback([&](const EVENT_RECORD& record,
                                  const krabs::trace_context& ctx) {
    ++seen;
    krabs::schema schema(record, ctx.schema_locator);
    if (schema.event_id() == 1) ++decoded;
});
```

Procedure:
1. Run the same producer used by `EventWrite`.
2. Consume it once with the raw `evntcons.h` callback and once with krabsetw.
3. Compare per-second counts: raw `seen`, krabsetw `seen`, and successfully decoded schema count.
4. Change keyword masks from broad to narrow and verify that both consumers lose the same filtered events.

Failure interpretation:
- Raw count rises but krabsetw callback does not: wrapper session/provider setup is wrong.
- krabsetw callback fires but schema fields are unnamed or missing: metadata problem, not delivery failure.
- Counts diverge under high volume: callback work or buffering differs; reduce parsing in the hot path and re-run.

## Connections
- Sealighter builds the same style of user-mode endpoint sensor around krabsetw.
- ETWStudio helps choose provider names, GUIDs, keywords, and event fields before writing krabsetw callbacks.
- `evntcons.h` and TDH explain the raw records krabsetw wraps.
- `Yosifovich System Programming Samples` gives adjacent producer/consumer and TraceLogging examples when the goal is to learn the ETW model, not just consume it.
- `ProcMonXv2` shows the UI and correlation layer required after the callback works.

## Discussion Claim Verification

Claim: "krabsetw hides ETW complexity."

Why it matters for new diagnostic code: hiding the boilerplate is useful only if the failure planes stay visible. A serious consumer still needs to debug session ownership, provider enablement, TDH metadata, callback cost, and event loss.

How to verify:
1. Implement the same consumer twice: raw `evntcons.h` and krabsetw.
2. Enable the same provider GUID, level, and keywords.
3. Print only `ProviderId`, `EventId`, `PID`, `TID`, `UserDataLength`, and an incrementing count in both.
4. Add field parsing only after raw delivery counts match.

Minimal code/pseudocode:

```cpp
std::atomic<uint64_t> raw_seen = 0;
std::atomic<uint64_t> krabs_seen = 0;

// raw callback
OnEvent(EVENT_RECORD* r) {
    ++raw_seen;
    print(r->EventHeader.ProviderId, r->EventHeader.EventDescriptor.Id,
          r->EventHeader.ProcessId, r->UserDataLength);
}

// krabsetw callback
provider.add_on_event_callback([&](const EVENT_RECORD& r, const krabs::trace_context&) {
    ++krabs_seen;
    print(r.EventHeader.ProviderId, r.EventHeader.EventDescriptor.Id,
          r.EventHeader.ProcessId, r.UserDataLength);
});
```

Interpretation: if raw and krabsetw counts diverge, debug wrapper setup, merged provider options, and dispatch filtering. If counts match but fields differ, the problem is schema/TDH interpretation. The GitHub link supports wrapper mechanics; it does not nullify the need to understand raw ETW.

## References
- <https://github.com/microsoft/krabsetw>
