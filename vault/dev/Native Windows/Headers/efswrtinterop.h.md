# efswrtinterop.h

WinRT-to-Win32 interop surface for `Windows.Security.EnterpriseData.FileRevocationManager` and the protected-data clipboard / file APIs introduced for Windows Information Protection (WIP, formerly EDP / Enterprise Data Protection). WIP itself was officially deprecated in Windows 11 (replaced by Microsoft Purview MAM), but the header and interfaces still ship. The interop part exposes `IDataProtectionManagerInterop` and the underlying handles so unpackaged Win32 code can participate in WIP-tagged data flows (protect a file with a corp identity, query whether a buffer is corp-tagged, etc.) without going through full WinRT. Sits next to `efsadu.h` (classic EFS), `efsstruc.h`, `efswrt.h`.

## References
- <https://learn.microsoft.com/en-us/uwp/api/windows.security.enterprisedata>
