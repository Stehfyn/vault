# windows-defender-remover - Defender Service Strip

This project is a destructive Defender-removal script set, not a normal configuration helper. Its editorial value is showing which moving parts such tools try to tamper with: Defender services, protected files, policy keys, Tamper Protection behavior, and Windows Update self-repair.

For defensive and admin review, the important point is resilience. Modern Defender is intentionally hard to remove cleanly, and attempts to strip it leave strong artifacts in service-control logs, registry policy state, file ACL changes, and failed self-healing events. Connect this to `NanaRun` because many such tools seek TrustedInstaller/SYSTEM context, and to OpSec BYOVD notes where endpoint protection is attacked below normal admin boundaries.

## Inspection Commands

Treat this note as an artifact map. Inventory first, then correlate with service-control and Defender event logs.

```powershell
Get-CimInstance Win32_Service |
  Where-Object { $_.Name -match 'WinDefend|WdNisSvc|Sense|SecurityHealthService' } |
  Select-Object Name, State, StartMode, ProcessId, PathName

sc.exe queryex WinDefend
sc.exe qc WinDefend

Get-ItemProperty 'HKLM:\SOFTWARE\Policies\Microsoft\Windows Defender' -ErrorAction SilentlyContinue

Get-WinEvent -LogName System |
  Where-Object { $_.ProviderName -eq 'Service Control Manager' -and $_.Message -match 'WinDefend|WdNisSvc|Sense' } |
  Select-Object TimeCreated, Id, Message

Get-WinEvent -ListLog 'Microsoft-Windows-Windows Defender/Operational'
Get-WinEvent -LogName 'Microsoft-Windows-Windows Defender/Operational' -MaxEvents 50
```

Connection route: WMI/SCM tells whether services exist and how they are configured; Event Log shows control and repair attempts; ETW process/file/registry tools such as ProcMonXv2 or wtrace show what the remover touched while running.

## Discussion Claim To Verify

Claim implied by destructive "remover" scripts: deleting or disabling Defender services produces a durable Defender-free machine.

Why it matters: for defenders and administrators, the real signal is not whether a script claims success. The useful facts are which service, policy, file, driver, task, or self-repair artifact changed, and whether Windows reversed or resisted it.

Verification route:

```powershell
Get-MpComputerStatus | Select-Object AMServiceEnabled,AntivirusEnabled,RealTimeProtectionEnabled,IsTamperProtected

Get-CimInstance Win32_Service |
  Where-Object Name -match 'WinDefend|WdNisSvc|Sense|SecurityHealthService' |
  Select-Object Name, State, StartMode, ProcessId, PathName

wevtutil qe System /q:"*[System[Provider[@Name='Service Control Manager']]]" /f:text /c:50
wevtutil qe "Microsoft-Windows-Windows Defender/Operational" /f:text /c:50
```

Safe metadata probe:

```cpp
SC_HANDLE scm = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_CONNECT | SC_MANAGER_ENUMERATE_SERVICE);
// EnumServicesStatusExW and record only service name, state, start type, PID.
// Do not stop, delete, reconfigure, or change ACLs in this probe.
```

Interpretation:
- Service state changes but Defender event logs show tamper/self-repair: the source supports "attempted modification," not durable removal.
- Policy keys exist but runtime status remains enabled: registry state alone is not the enforcement state.
- Missing services plus file/ACL drift and SCM events: treat as destructive tampering evidence, not a supported configuration path.

## References
- <https://github.com/ionuttbara/windows-defender-remover>
