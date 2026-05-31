# Sealighter - JSON-Configured ETW Sensor

Sealighter is an endpoint-sensor pattern rather than just another ETW demo: provider selection, keyword masks, filters, and outputs are driven by configuration instead of being hard-coded into a collector. That makes it useful for defensive experiments where the question is "which user-mode ETW mix gives enough signal" before committing to a driver, Sysmon policy, or EDR integration.

The important constraint is provider access. Some high-value providers are restricted, noisy, version-sensitive, or require administrative/session privileges; a JSON config cannot bypass those boundaries. Sealighter is best read alongside ETWStudio for schema discovery and krabsetw for the consumer mechanics underneath it.

## Source Code Reading

Sealighter's value is visible only when you read `sealighter/sealighter_controller.cpp` and `sealighter/sealighter_handler.cpp`. The config file is compiled into krabsetw providers, native filters, callbacks, event parsing, optional buffering, and output routing.

```text
sealighter_main.cpp
  -> read config file
  -> run_sealighter(config_string)
       -> EventRegisterSealighter()
       -> parse_config(...)
            session_properties: session_name, BufferSize, MinimumBuffers, MaximumBuffers, FlushTimer
            user_traces -> add_user_traces(...)
            kernel_traces -> add_kernel_traces(...)
       -> start configured sessions
```

`add_kernel_traces` maps strings such as `process`, `thread`, `image_load`, `context_switch`, `debug_print`, `disk_io`, `registry`, `network_tcpip`, `file_io`, `virtual_alloc`, and `object_manager` into concrete krabsetw provider classes. `add_user_traces` resolves `provider_name` as GUID or provider name, sets `keywords_all`, `keywords_any`, `level`, and `trace_flags`, optionally ORs `EVENT_ENABLE_PROPERTY_STACK_TRACE`, and applies filters.

Filter composition is explicit:

```text
filters.any_of  -> sealighter_any_of(...)
filters.all_of  -> sealighter_all_of(...)
filters.none_of -> sealighter_none_of(...)
top-level filter -> AND of configured groups
callback -> handle_event_context(...)
```

`parse_event_to_json` constructs a JSON header from `krabs::schema`, then iterates `krabs::parser::properties()` and switches on TDH input type. Strings, integers, floats, GUIDs, FILETIME, SYSTEMTIME, SID, pointer, binary, and unknown types are each handled differently. If parsing fails, Sealighter falls back to hex bytes rather than dropping the property.

```cpp
schema s(record, trace_context.schema_locator);
json header = { event_id, event_name, task_name, pid, tid, provider_name, activity_id };

if (dump_raw_event)
  json["raw"] = hex(record.UserData, record.UserDataLength);
else
  for (property prop : parser.properties())
    json["properties"][prop.name()] = parse_by_tdh_intype(prop.type());
```

Verifiable assertions to drive:

```text
claim: config filters run before JSON output
probe: set `none_of` for one event id and prove it never reaches `handle_event_context`

claim: stack traces require enable property plus provider/session support
probe: toggle `report_stacktrace`; compare `ExtendedDataCount` and `stack_trace`

claim: raw dump distinguishes delivery failure from parse failure
probe: run once with `dump_raw_event=true`, once false; compare event counts
```

Source files read:
- `sealighter/sealighter_main.cpp`
- `sealighter/sealighter_controller.cpp`
- `sealighter/sealighter_handler.cpp`
- `sealighter/sealighter_predicates.h`
- `sealighter/sealighter_provider.man`

## Connections
- Built around the same consumer concerns as krabsetw.
- Compare with `wtrace` for ad-hoc investigation and ProcMonXv2 for a GUI monitor.
- Connects to `WinAPI-RedBlue` where offensive primitives are reframed as telemetry questions.

## Discussion Claim Verification

Claim: "A JSON ETW sensor can be reconfigured without changing code."

Why it matters for new diagnostic code: the claim is valuable only if configuration changes affect provider enablement before event delivery, not merely JSON formatting after the callback has already paid the cost.

How to verify:
1. Run one config with a broad provider keyword mask and no filters.
2. Run a second config with a narrow event-id filter or `none_of` clause.
3. Keep the workload unchanged.
4. Compare delivered event count, output row count, and raw-dump count.

Minimal code/pseudocode:

```json
{
  "session_properties": { "BufferSize": 1024, "MinimumBuffers": 64 },
  "user_traces": [{
    "provider_name": "{PROVIDER-GUID}",
    "keywords_any": "0xffffffffffffffff",
    "level": 5,
    "filters": { "none_of": [{ "EventId": 42 }] },
    "dump_raw_event": true
  }]
}
```

Interpretation: if raw dump count changes when only parse settings change, the supposed parse-only switch is actually altering delivery or filtering. If raw count is stable but JSON fields change, the event plane is healthy and the parser/schema path is the variable. The Sealighter link supports this config-to-krabsetw model; it does not prove that every named provider is available or unrestricted on every Windows build.

## References
- <https://github.com/pathtofile/Sealighter>
