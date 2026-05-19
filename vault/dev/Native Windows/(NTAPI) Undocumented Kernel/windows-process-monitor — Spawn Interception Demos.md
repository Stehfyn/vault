# windows-process-monitor - Spawn Interception Demos

This project is useful because it compares process-start observation at different layers: user-mode notification mechanisms, GUI/hook-adjacent approaches, and kernel process-create callbacks. The educational point is that "monitor process creation" is not one capability. Each layer sees different timing, metadata, authority, and opportunity to block.

Defensively, the kernel callback path is the meaningful boundary because it observes creation below `CreateProcessW` and native syscall wrapper choices. User-mode methods are still valuable for logging or policy prototypes, but they are later, easier to bypass, and more sensitive to desktop/session context.

## Connections
- `NtCreateUserProcess` explains the native creation path that user-mode wrappers eventually reach.
- ETW process providers, ProcMonXv2, and wtrace provide observation without blocking authority.

## References
- <https://github.com/apriorit/windows-process-monitor>
