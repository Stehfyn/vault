# Secure Attention Sequence - Ctrl+Alt+Del

The Secure Attention Sequence is the trusted-path mechanism that lets Windows reserve Ctrl+Alt+Del for Winlogon rather than ordinary desktop applications. Its security value is not the key combination itself; it is the guarantee that credential UI after SAS is owned by the trusted logon path, not by a spoofable foreground window.

This belongs in NTAPI/kernel notes because it crosses desktop isolation, Winlogon, credential providers, session state, and privilege boundaries. Programmatic SAS generation is deliberately constrained and depends on system component context, policy, and privilege; for research, the interesting question is how Windows keeps ordinary GUI message handling from impersonating the secure desktop.

## Connections
- `secext.h` covers identity-name reporting after logon, a different layer of the authentication story.
- Message queue and hook notes illustrate why ordinary USER32 input paths are not trusted enough for credential entry.

## References
- Secure Attention Sequence / Winlogon trusted-path documentation
