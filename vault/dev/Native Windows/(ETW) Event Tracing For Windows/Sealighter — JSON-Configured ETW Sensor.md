# Sealighter - JSON-Configured ETW Sensor

Sealighter is an endpoint-sensor pattern rather than just another ETW demo: provider selection, keyword masks, filters, and outputs are driven by configuration instead of being hard-coded into a collector. That makes it useful for defensive experiments where the question is "which user-mode ETW mix gives enough signal" before committing to a driver, Sysmon policy, or EDR integration.

The important constraint is provider access. Some high-value providers are restricted, noisy, version-sensitive, or require administrative/session privileges; a JSON config cannot bypass those boundaries. Sealighter is best read alongside ETWStudio for schema discovery and krabsetw for the consumer mechanics underneath it.

## Connections
- Built around the same consumer concerns as krabsetw.
- Compare with `wtrace` for ad-hoc investigation and ProcMonXv2 for a GUI monitor.
- Connects to `WinAPI-RedBlue` where offensive primitives are reframed as telemetry questions.

## References
- <https://github.com/pathtofile/Sealighter>
