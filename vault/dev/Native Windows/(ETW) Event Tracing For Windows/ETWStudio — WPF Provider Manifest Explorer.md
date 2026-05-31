# ETWStudio - WPF Provider Manifest Explorer

ETWStudio is a provider-discovery and schema-reading tool, not a trace viewer. Its value is the TDH path: enumerate registered providers, inspect GUIDs, tasks, opcodes, keywords, maps, and field layouts, then decide what a consumer should enable before writing code. That is the missing step between "I know there is a provider" and "I can decode its payload without guessing."

It is strongest for manifest-backed providers where TDH can recover names and property types. TraceLogging and provider-specific conventions still require judgment, but ETWStudio makes the ambiguity visible. Use it before building krabsetw consumers, Sealighter configs, or xperf/WPR profiles so keyword masks and event IDs are not copied blindly.

## Connections
- Complements `evntcons.h`, which exposes the raw event record structures but not the friendly schema.
- Complements `UIforETW` and `wtrace`: those capture or stream events, while ETWStudio explains what the provider can emit.

## Discussion Claim Verification

Claim: "ETWStudio tells me what this provider emits."

Why it matters for new diagnostic code: schema discovery should drive keyword masks, event IDs, and parser expectations before a consumer is written. Guessing masks from blog posts creates silent blind spots.

How to verify:
1. Use ETWStudio or TDH enumeration to record provider GUID, keyword names, tasks, opcodes, and field layouts.
2. Enable one keyword/event family at a time with krabsetw or `logman`.
3. Run a workload expected to trigger that event.
4. Compare schema-declared fields against raw `EVENT_RECORD.UserDataLength` and parsed TDH output.

Minimal code/pseudocode:

```text
provider_schema = ETWStudio(provider)
for event in provider_schema.events:
  enable(provider.Guid, event.Keyword, event.Level)
  run_workload()
  print(EventId, Opcode, UserDataLength, ParsedPropertyNames)
```

Interpretation: the ETWStudio link supports schema exploration. It does not prove that every schema event is emitted by a given workload, available on every OS build, or enabled for the current privilege/session. Treat it as provider intelligence, then verify with a consumer.

## References
- <https://github.com/zodiacon/ETWStudio>
