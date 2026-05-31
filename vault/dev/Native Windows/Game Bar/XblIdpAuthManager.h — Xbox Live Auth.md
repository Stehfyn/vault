# XblIdpAuthManager.h - Xbox Live Auth Interface

`XblIdpAuthManager` is part of the Xbox Live identity-provider plumbing used by Xbox service SDK flows. The useful detail is that Xbox authentication is not just a REST token fetch: the desktop client path crosses COM/WinRT activation, Web Account Manager-style broker behavior, title identity, and service-scoped tokens.

Keep this near `xbox-live-api` and `HaloMCC-DiscordRPC`. Those entries show why auth is the hard part of presence tooling: service calls are ordinary async requests once the user handle and XSTS/XBL token chain exist.

## References
- `XblIdpAuthManager.h`

## Experiment Harness

Goal: separate broker/account failure from service-call failure.

Probe shape:

```cpp
printf("package=%ld\n", GetCurrentPackageFullName(&len, nullptr));
// Acquire user/account handle, request token, print HRESULT and token audience only.
```

Measured signal: package identity, user handle acquisition HRESULT, token request HRESULT, token audience/scope metadata without logging secrets.

Failure interpretation: no package/title identity or no signed-in broker account fails before HTTP service calls matter.
