# nt5src - Leaked NT5 Source Archive

The `nt5src` mirror is a behavioral reference for Windows XP/Server 2003 internals: `win32k`, USER32/GDI, shell components, task manager, shlwapi, NTOS subsystems, and compatibility code. Its value is not as code to reuse; it is evidence for old-but-still-relevant contracts that the public SDK describes only from the outside.

Use it carefully. NT5 is not modern Windows: DWM, UAC, AppContainer, CFG, Control Flow Guard metadata, ETW provider coverage, loader policy, win32k lockdown, and many security boundaries changed later. The archive is strongest for enduring architecture - message queues, window management, shell utilities, process enumeration patterns - and weakest as a statement about current hardening.

## Connections
- ReactOS and Wine provide open-source comparison points where copying proprietary source is inappropriate.
- The NT5 notes in this folder pull specific files out of the archive so the reference is actionable rather than a generic source dump.

## References
- <https://github.com/tongzx/nt5src>
