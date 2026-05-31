# Registry Setup (RegInstallW)

`RegInstallW` is an ADVPACK helper that applies registry instructions embedded in INF-style `RegInstall` sections, with string-table substitution for paths or identifiers. It belongs to the Internet Explorer / setup-helper lineage, not to MSI's transactional installation model.

The relevant deployment detail is rollback: `RegInstallW` is just an imperative registry write helper. It does not give you MSI component key paths, repair semantics, reference counting, or automatic uninstall rollback unless the caller builds that discipline around it. It remains useful when maintaining old self-registering modules and INF-driven setup code.

## Substitution Shape

The older source describes a module resource named `REGINST`; the public header shape is a module, section name, and string-substitution table. That makes the call convenient for legacy setup, but opaque compared with MSI tables.

```c
STRENTRYW entries[] = {
    { L"MODULE_PATH", L"C:\\Program Files\\Vendor\\Component" },
};
STRTABLEW table = { ARRAYSIZE(entries), entries };
HRESULT hr = RegInstallW(hModule, L"RegisterComponent", &table);
```

## Connections
- `advpub.h` is the header surface for this function.
- `RegStr.h` and `INI File API` are adjacent compatibility-era configuration mechanisms.
- `Msi.h` is the transactional contrast; `MsiQuery.h` can audit declarative registry rows, while `RegInstallW` executes imperative INF/resource instructions.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/advpub/nf-advpub-reginstallw>
