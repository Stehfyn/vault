# MsiDefs.h — MSI Constants and Error Codes

`MsiDefs.h` is the constant vocabulary around Windows Installer: install states, run modes, message types, error codes, feature attributes, and database-open flags. It is the header you end up reading when a custom action receives an opaque `INSTALLSTATE`, `INSTALLMESSAGE`, or `ERROR_INSTALL_*` value and the logs are not enough.

The definitions matter because MSI code is table-driven. Constants are often not mere return codes; they decide UI/log message routing, feature selection, reboot behavior, and whether a query is against a product, component, patch, or feature.

## Connections
- `Msi.h` uses these constants in the public API.
- `MsiQuery.h` uses the database flags and record/view concepts behind MSI tooling.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/msidefs/>
