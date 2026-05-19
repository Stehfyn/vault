# namedpipeapi.h

Named-pipe primitives carved out of `winbase.h` by the API-set / minwin reshuffle: `CreateNamedPipeW`, `ConnectNamedPipe`, `DisconnectNamedPipe`, `PeekNamedPipe`, `TransactNamedPipe`, `WaitNamedPipeW`, `SetNamedPipeHandleState`, `GetNamedPipeHandleStateW`, plus the anonymous-pipe `CreatePipe`. The two operational truths: (1) named pipes can do real DACLs and SIDs, so `\\.\pipe\foo` with a deny ACE on `S-1-5-7` (`Anonymous Logon`) is the standard way to block null-session enumeration; (2) `PIPE_TYPE_MESSAGE` mode preserves message boundaries -- `WriteFile` writes one message, `ReadFile` reads one message (or returns `ERROR_MORE_DATA` if your buffer was short) -- while `PIPE_TYPE_BYTE` is a pure stream. Pair with `fileapi.h` (it's `ReadFile`/`WriteFile` after `CreateNamedPipe`), `winsvc.h` for service-context use, and `securitybaseapi.h` for SID-impersonation tricks (`ImpersonateNamedPipeClient`).

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/namedpipeapi/>
- <https://learn.microsoft.com/en-us/windows/win32/ipc/named-pipes>
