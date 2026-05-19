# ETWStudio - WPF Provider Manifest Explorer

ETWStudio is a provider-discovery and schema-reading tool, not a trace viewer. Its value is the TDH path: enumerate registered providers, inspect GUIDs, tasks, opcodes, keywords, maps, and field layouts, then decide what a consumer should enable before writing code. That is the missing step between "I know there is a provider" and "I can decode its payload without guessing."

It is strongest for manifest-backed providers where TDH can recover names and property types. TraceLogging and provider-specific conventions still require judgment, but ETWStudio makes the ambiguity visible. Use it before building krabsetw consumers, Sealighter configs, or xperf/WPR profiles so keyword masks and event IDs are not copied blindly.

## Connections
- Complements `evntcons.h`, which exposes the raw event record structures but not the friendly schema.
- Complements `UIforETW` and `wtrace`: those capture or stream events, while ETWStudio explains what the provider can emit.

## References
- <https://github.com/zodiacon/ETWStudio>
