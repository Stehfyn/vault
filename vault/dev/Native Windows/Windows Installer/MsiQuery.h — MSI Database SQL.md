# MsiQuery.h — MSI Database SQL Queries

`MsiQuery.h` exposes the SQL-like database API over MSI files: open a database, prepare a view, execute it, fetch records, and read or update fields. It is indispensable for validation tools, transforms, patch/build systems, and forensic inspection because an MSI is a structured database, not just a wrapper around files.

The SQL dialect is deliberately limited and table-schema driven. You cannot reason about installation behavior from a single property value; you have to inspect table relationships, component key paths, conditions, sequences, and transforms applied at install time.

## View Call Shape

The core boundary is database handle -> SQL view handle -> record cursor. Close raw `MSIHANDLE`s or use `PMSIHANDLE` in C++ code that can rely on the MSI RAII typedef.

```c
MSIHANDLE view = 0;
UINT rc = MsiDatabaseOpenViewW(db,
    L"SELECT `Property`, `Value` FROM `Property`",
    &view);
if (rc == ERROR_SUCCESS && MsiViewExecute(view, 0) == ERROR_SUCCESS) {
    MSIHANDLE rec = 0;
    while (MsiViewFetch(view, &rec) == ERROR_SUCCESS) {
        MsiCloseHandle(rec);
    }
}
MsiCloseHandle(view);
```

## Source Code Reading

The code shape from Windows classic MSI samples and the SDK reference is consistent: MSI database access is handle choreography, not object magic.

Entry points to compose:
- `MsiOpenDatabaseW` / `MsiOpenDatabaseA`
- `MsiDatabaseOpenViewW`
- `MsiViewExecute`
- `MsiViewFetch`
- `MsiRecordGetStringW`, `MsiRecordGetInteger`
- `MsiCloseHandle`

Robust reader pseudocode:

```text
open database readonly
open parameterized or literal SQL view
execute view
while fetch returns ERROR_SUCCESS:
  for each selected column:
    call MsiRecordGetString with small buffer
    if ERROR_MORE_DATA, resize and retry
  close record
close view
close database
```

Claim -> source/probe -> interpretation:
- Claim: "An MSI property exists because the authoring project sets it."
- Source/probe: query the built MSI `Property` table and, when the value is generated, the search tables that feed it.
- Interpretation: authoring intent is not the package. The MSI database is the artifact the engine consumes.

## Experiment Harness

Turn MSI review into repeatable assertions. Query the package for tables that should exist and fail the harness when a required property/search row is missing.

```powershell
.\msi_query.exe probe.msi "SELECT `Property`,`Signature_` FROM `AppSearch`"
.\msi_query.exe probe.msi "SELECT `Action`,`Condition`,`Sequence` FROM `InstallExecuteSequence`"
```

Signal: nonzero row count, expected public property names, expected sequence placement. Failure interpretation: a passing install can still hide a bad MSI database; table-level assertions catch drift before `msiexec` runs.

## Connections
- `Msi.h` runs the installer engine; `MsiQuery.h` inspects or mutates the database feeding it.
- `MSI Search Conditions` is a concrete table family worth auditing with this API.
- `INI File API` and `RegStr.h` explain two legacy data sources that can appear in locator/search tables.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/msiquery/>
- <https://learn.microsoft.com/en-us/windows/win32/api/msiquery/nf-msiquery-msidatabaseopenvieww>
