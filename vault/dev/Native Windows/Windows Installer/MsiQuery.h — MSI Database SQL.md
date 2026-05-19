# MsiQuery.h — MSI Database SQL Queries

`MsiQuery.h` exposes the SQL-like database API over MSI files: open a database, prepare a view, execute it, fetch records, and read or update fields. It is indispensable for validation tools, transforms, patch/build systems, and forensic inspection because an MSI is a structured database, not just a wrapper around files.

The SQL dialect is deliberately limited and table-schema driven. You cannot reason about installation behavior from a single property value; you have to inspect table relationships, component key paths, conditions, sequences, and transforms applied at install time.

## Connections
- `Msi.h` runs the installer engine; `MsiQuery.h` inspects or mutates the database feeding it.
- `MSI Search Conditions` is a concrete table family worth auditing with this API.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/msiquery/>
