# phnt - Process Hacker Native API Headers

phnt is the practical header set for user-mode native Windows work. It fills the gap between the public SDK's deliberately thin `winternl.h` and the real structures used by tools such as System Informer: process/thread information classes, system-information records, object-manager types, PEB/TEB layouts, loader structures, handle tables, and many `Nt*` declarations.

The reason it matters is maintenance. Native structures drift across Windows releases, and one-off typedefs copied from old articles are a common source of subtle bugs. phnt is not an official ABI guarantee, but it is one of the best maintained public maps of the territory.

## Connections
- System Informer is the main consumer and validation source for phnt.
- `NtCreateUserProcess`, `RTL_USER_PROCESS_PARAMETERS`, and process dump notes all become less fragile when based on phnt declarations.

## References
- <https://github.com/winsiderss/phnt>
