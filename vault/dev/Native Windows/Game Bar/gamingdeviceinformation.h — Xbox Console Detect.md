# gamingdeviceinformation.h - Xbox Console Detection

`GetGamingDeviceModelInformation` is a small Gaming Runtime probe for distinguishing desktop Windows from Xbox-family hardware at runtime. It matters for codebases that share binaries across PC and console but need different behavior for storage, input assumptions, entitlement flow, or performance defaults.

The header is thin, but it belongs next to `gamingtcui.h` and `xbox-live-api`: device model, Xbox UI affordances, and service identity are usually queried together during startup. Treat it as feature selection, not as a licensing or security boundary.

## References
- `gamingdeviceinformation.h`
