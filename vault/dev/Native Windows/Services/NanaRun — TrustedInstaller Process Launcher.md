# NanaRun - TrustedInstaller Process Launcher

NanaRun is an open-source launcher for starting processes under elevated service identities such as SYSTEM or TrustedInstaller. Its value is as a token/session/service-control reference: the hard parts are not the UI, but starting or finding the service process, duplicating a suitable primary token, choosing the right logon/session behavior, and creating the child process without leaking handles.

Keep it near `Win32 Service Template` because it demonstrates the security context around services rather than the service loop itself. It also connects to OpSec pages on process access and PPL because token abuse and service identity are frequent pivots in both administrative tooling and intrusion investigations.

## References
- <https://github.com/M2Team/NanaRun>
