# Kernel DLL Injector (alexvogt91)

This project represents the kernel-assisted DLL-injection pattern: a driver watches process/module creation state and arranges for user-mode code to be loaded into selected processes. The notable boundary is that kernel visibility can see image-load milestones and process creation earlier than most user-mode instrumentation, but the payload still has to satisfy ordinary user-mode loader constraints once it lands.

For defensive analysis, the important artifacts are driver loading, process/image notify callbacks, cross-boundary communication, and anomalous DLL presence in newly created processes. Keep the note at that level; the project is useful as a specimen of the technique family, not as an implementation guide.

## Connections
- `windows-process-monitor` covers process-create notification from the NTAPI/kernel side.
- PE loader notes explain what must be true for any injected DLL to initialize correctly.

## References
- <https://github.com/alexvogt91/Kernel-dll-injector>
