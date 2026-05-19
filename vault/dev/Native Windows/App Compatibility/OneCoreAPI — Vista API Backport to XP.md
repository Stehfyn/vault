# OneCoreAPI - Vista API Backport to XP

OneCoreAPI is the aggressive end of Windows compatibility backporting: it adds large chunks of Vista-and-later API surface to XP/Server 2003 by replacing or extending system DLL behavior. That is more powerful than a per-process shim, and correspondingly more fragile because every process now sees the altered surface.

The editorial value is the export-compatibility problem. Modern applications fail on old Windows before main executes because imports such as condition variables, SRW locks, newer locale/string APIs, and shell helpers are missing. Compare OneCoreAPI with VxKex-style per-process forwarding and YY-Thunks static fallbacks to decide where the compatibility boundary lives.

Code contribution: study export forwarding/stubbing for APIs such as `InitializeConditionVariable`, `AcquireSRWLockExclusive`, newer NLS functions, and shell/kernel32 imports missing on XP.

## References
- <https://github.com/shorthorn-project/One-Core-API-Source>
