# NanaRun - TrustedInstaller Process Launcher

NanaRun is an open-source launcher for starting processes under elevated service identities such as SYSTEM or TrustedInstaller. Its value is as a token/session/service-control reference: the hard parts are not the UI, but starting or finding the service process, duplicating a suitable primary token, choosing the right logon/session behavior, and creating the child process without leaking handles.

Keep it near `Win32 Service Template` because it demonstrates the security context around services rather than the service loop itself. It also connects to OpSec pages on process access and PPL because token abuse and service identity are frequent pivots in both administrative tooling and intrusion investigations.

## Service-Identity Route

The reusable lesson is the call graph, not the specific UI: reach a service process, obtain an appropriate token, duplicate it as a primary token, choose the target session, then create a process with explicit environment and handle ownership.

```cpp
SC_HANDLE scm = OpenSCManagerW(nullptr, nullptr, SC_MANAGER_CONNECT);
SC_HANDLE ti = OpenServiceW(scm, L"TrustedInstaller",
    SERVICE_QUERY_STATUS | SERVICE_START);

SERVICE_STATUS_PROCESS ssp = {};
DWORD bytes = 0;
QueryServiceStatusEx(ti, SC_STATUS_PROCESS_INFO,
    reinterpret_cast<BYTE*>(&ssp), sizeof(ssp), &bytes);

HANDLE process = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, FALSE, ssp.dwProcessId);
HANDLE token = nullptr;
OpenProcessToken(process, TOKEN_DUPLICATE | TOKEN_ASSIGN_PRIMARY | TOKEN_QUERY, &token);

HANDLE primary = nullptr;
DuplicateTokenEx(token, TOKEN_ALL_ACCESS, nullptr, SecurityImpersonation,
    TokenPrimary, &primary);

STARTUPINFOW si = { sizeof(si) };
PROCESS_INFORMATION pi = {};
CreateProcessAsUserW(primary, nullptr, cmdline, nullptr, nullptr, FALSE,
    CREATE_UNICODE_ENVIRONMENT, env, nullptr, &si, &pi);
```

Trace the route with service-control logs, WMI service state, process/token inspection, and ETW process-start events. That combination catches the common blind spot: the spawned process is visible in process telemetry even when the interesting part was service identity selection.

## Discussion Claim To Verify

Claim commonly attached to TrustedInstaller launchers: "running as TrustedInstaller" means the process can edit anything Windows protects.

Why it matters: this overstates the boundary. Token user, groups, privileges, integrity level, session, object ACLs, service SID behavior, and protected-process rules are separate checks.

Verification route:

```powershell
sc.exe queryex TrustedInstaller
Get-CimInstance Win32_Process -Filter "Name='TrustedInstaller.exe'" |
  Select-Object ProcessId, ParentProcessId, SessionId, ExecutablePath

whoami /user /groups /priv
```

Token probe to run inside the child:

```cpp
HANDLE token = nullptr;
OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &token);

// Query TokenUser, TokenGroups, TokenPrivileges, TokenIntegrityLevel,
// TokenSessionId, and TokenElevationType with GetTokenInformation.
```

Interpretation:
- User SID is `NT SERVICE\TrustedInstaller` and privileges are enabled: the launcher achieved the service-identity goal.
- Session ID differs from the interactive desktop or UI cannot appear: process identity succeeded but desktop/session routing did not.
- Protected service/PPL targets still deny access: the source supports token/session launch behavior, not a blanket bypass of every Windows protection boundary.

## References
- <https://github.com/M2Team/NanaRun>
