# secext.h - SSPI Extended Name Format

`secext.h` is the header behind `GetUserNameEx`, which returns the current security principal in formats such as SAM-compatible, user-principal-name, DNS domain, display name, or service-principal-oriented forms. Its value is identity normalization: the same logon session can be rendered differently depending on whether code needs an NT account name, directory identity, or display string.

The nuance is that name format is not authentication. These APIs report names from the security context; they do not prove group membership, token integrity, logon type, or credential freshness. For security tooling, pair name reporting with token inspection rather than treating a formatted string as authority.

## Connections
- System Informer and native process tools often display token/user identity alongside process state.
- Secure Attention Sequence belongs to the adjacent logon/trusted-path area, not to name formatting.

## References
- Windows SDK `secext.h`
