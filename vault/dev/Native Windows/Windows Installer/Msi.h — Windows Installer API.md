# Msi.h — Windows Installer API Header

`Msi.h` is the top-level Windows Installer API for products, features, components, installation sessions, and advertised shortcuts. It exposes entry points such as `MsiInstallProduct`, `MsiConfigureProductEx`, `MsiGetProductInfo`, and install-handle APIs used by custom actions.

The important distinction is that MSI is a database-driven transaction engine, not a script runner. Calling the API starts or queries an action graph whose behavior is determined by tables, properties, component rules, per-user/per-machine context, elevation, and source resiliency.

## Connections
- `MsiQuery.h` is for reading/editing MSI database tables directly.
- `MSI Search Conditions` explains one common way properties are populated before install actions run.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/msi/>
