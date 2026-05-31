# RegStr.h — Shell Registry Path Constants

`RegStr.h` is a graveyard of named registry path/value constants used by shell, setup, device, network, and legacy Control Panel code: `REGSTR_PATH_*`, `REGSTR_VAL_*`, and related strings. Its value is not abstraction; it is archaeology. When old code refers to a symbolic constant instead of a literal `HKLM\...\CurrentVersion` path, this header tells you which registry contract it believed existed.

The header predates newer configuration surfaces such as Known Folders, SetupAPI device properties, and the property system. Prefer those when writing new code, but keep `RegStr.h` close when maintaining installers, CPLs, or INF-era setup helpers that still use path constants as part of their ABI.

## Maintenance Shape

Treat the constants as named ABI, not as authority that the path is still the best write target. Old setup code often combines these constants with raw registry APIs or INF substitution, which is why the same route appears in ADVPACK and SetupAPI notes.

```c
RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"Software\\Microsoft\\Windows\\CurrentVersion",
              0, KEY_QUERY_VALUE, &key);
```

## Connections
- `KnownFolders.h` replaces hardcoded shell folder paths with GUID identity.
- `SetupAPI.h`, `infstr.h`, and `Registry Setup (RegInstallW)` sit in the same older setup/configuration ecosystem.
- `INI File API` is the compatibility bridge when apparent INI reads are redirected into registry-backed storage.
- `MSI Search Conditions` shows how installer detection still mixes registry, INI, component, directory, and file locators.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/regstr/>
