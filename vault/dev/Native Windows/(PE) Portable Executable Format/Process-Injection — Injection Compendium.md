# Process-Injection - Injection Compendium

This compendium is useful as an index of x86/x64 injection variants rather than as a source of any single primitive. The common substrate is small: obtain authority over a target process or thread, place or reference executable content, and arrange for execution in the target context. The differences are where authority comes from and which Windows subsystem delivers execution.

That taxonomy helps organize defensive notes. Loader-based methods create module artifacts, memory-only methods create suspicious VAD/protection patterns, thread-based methods create scheduling and start-address artifacts, and hook/message methods require GUI-thread participation. The compendium belongs at the map level, with concrete details delegated to PE, NTAPI, and Hooks entries.

## Connections
- `process-inject` is a smaller five-method suite in the same space.
- `WinAPI-RedBlue` connects these primitives to telemetry and defensive controls.

## References
- <https://github.com/Gality369/Process-Injection>
