# XblIdpAuthManager.h - Xbox Live Auth Interface

`XblIdpAuthManager` is part of the Xbox Live identity-provider plumbing used by Xbox service SDK flows. The useful detail is that Xbox authentication is not just a REST token fetch: the desktop client path crosses COM/WinRT activation, Web Account Manager-style broker behavior, title identity, and service-scoped tokens.

Keep this near `xbox-live-api` and `HaloMCC-DiscordRPC`. Those entries show why auth is the hard part of presence tooling: service calls are ordinary async requests once the user handle and XSTS/XBL token chain exist.

## References
- `XblIdpAuthManager.h`
