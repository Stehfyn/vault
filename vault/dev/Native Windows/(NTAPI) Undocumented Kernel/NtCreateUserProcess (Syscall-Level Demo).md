# NtCreateUserProcess (Syscall-Level Demo)

This demo is useful because it makes `CreateProcessW`'s hidden work visible. Native process creation requires correctly formed `RTL_USER_PROCESS_PARAMETERS`, `PS_CREATE_INFO`, and `PS_ATTRIBUTE_LIST` state, plus NT-style paths and careful handle cleanup. The public Win32 wrapper normally builds that machinery, coordinates compatibility behavior, and reports errors in Win32 terms.

The security-research angle is that bypassing the wrapper does not bypass process creation as a kernel event. It changes which user-mode hooks and convenience layers are skipped, but the object manager, image section creation, thread creation, callbacks, and ETW/process telemetry still exist. Treat syscall-level demos as process-creation anatomy, not as magic invisibility.

## Connections
- `RTL_USER_PROCESS_PARAMETERS` is one of the central structures passed into the call.
- `windows-process-monitor` shows kernel notification paths that observe process creation below Win32 wrappers.

## References
- <https://github.com/BlackOfWorld/NtCreateUserProcess>
