# AlphaVSS - .NET Binding for Volume Shadow Copy

AlphaVSS wraps the COM-heavy Volume Shadow Copy Service API behind a stable .NET surface. It matters because VSS is both powerful and version-fussy: requester, writer metadata, snapshot sets, provider behavior, and OS-specific interface differences are tedious to handle directly.

Keep it near the PowerShell VSS module. AlphaVSS is the library path for application code; the module is the admin scripting path. Both clarify why backup tools need coordinated snapshots rather than naive file copies when databases or locked files are involved.

Code contribution: inspect requester/writer coordination, `IVssBackupComponents`, snapshot-set creation, COM interop wrappers, and provider-specific error handling around VSS APIs.

## References
- <https://github.com/alphaleonis/AlphaVSS>
