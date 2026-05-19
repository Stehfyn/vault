# User-Mode Physical Memory Library

UMPMLib exposes a user-mode abstraction over physical-memory access after a vulnerable or helper driver supplies the necessary primitive. It matters because it turns x64 paging concepts into a reusable library surface: process directory bases, virtual-to-physical translation, and page reads become ordinary API calls to the client.

For defenders, the warning is that process-handle monitoring is insufficient when an actor can read physical pages or walk page tables externally. The practical control point shifts to driver load policy, vulnerable-driver blocklists, device access, and anomalous memory-scanning behavior.

Code contribution: use it to understand page-table walking, virtual-to-physical translation, driver-backed read primitives, and why `OpenProcess` telemetry can be bypassed.

## References
- <https://github.com/waryas/UMPMLib>
