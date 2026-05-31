# Diagnostics Observability Routes

This note is the routing table for Native Windows diagnostics. Pick the plane before picking the tool.

```text
state now:
  WMI/CIM -> Get-CimInstance Win32_Service, Win32_Process, root/wmi monitor classes
  SCM     -> sc.exe queryex, QueryServiceStatusEx, service failure actions

events happening:
  ETW provider -> EventWrite/TraceLogging
  live ETW     -> krabsetw, Sealighter, wtrace, ProcMonXv2
  ETL capture  -> WPR/UIforETW/xperf -> WPA

inside one process:
  IAT/API hook -> wintrace
  debug print  -> OutputDebugStringW / DebugView

after capture:
  relogger.h -> reduce/filter/rewrite ETL
  TDH        -> decode manifest-backed EVENT_RECORD payloads
```

## Command Spine

```powershell
logman query providers
wpr -start GeneralProfile -filemode
wpr -stop native-windows.etl
wpa native-windows.etl

sc.exe queryex MyService
Get-CimInstance Win32_Service -Filter "Name='MyService'" |
  Select-Object Name, State, StartMode, ProcessId, PathName

Get-WinEvent -LogName System -FilterXPath "*[System[Provider[@Name='Service Control Manager']]]"
```

## Experiment Harness Matrix

Use the smallest harness that can falsify the hypothesis.

| Hypothesis | Harness | Measurable signal | Failure interpretation |
|---|---|---|---|
| Provider emits records | `EventWrite` producer plus raw `evntcons.h` consumer | callback count, provider GUID, event ID, PID | wrong GUID/keyword/level, provider idle, no enabled session |
| Consumer cannot keep up | `ControlTraceW(... QUERY)` during high-rate writes | `EventsLost`, `RealTimeBuffersLost`, `BuffersWritten` | buffer sizing, callback cost, disk/real-time bottleneck |
| Service state is real | `sc.exe queryex` plus `Get-CimInstance Win32_Service` | SCM state/PID vs WMI state/PID over time | WMI staleness/provider failure vs SCM contract failure |
| Process touched a resource | wtrace/ProcMonXv2 filtered to PID | file/registry/process/network event rows | provider coverage/filter/elevation issue |
| Exact API arguments matter | `wintrace` IAT hook | call count and argument tuples | ETW cannot answer; hook missed alternate call path |
| Performance changed | WPR baseline/workload ETL pair | WPA CPU, waits, I/O, stacks, trace statistics | wrong profile, missing symbols/stacks, lost events, wrong hypothesis |

The harness should leave behind one artifact: stdout transcript, ETL file, exported event rows, or a small CSV of state samples. If it leaves only prose, it is not a harness.

## Connection Routes

- `EventWrite` -> `evntprov.h` -> `evntcons.h` -> krabsetw/Sealighter/wtrace.
- `Win32 Service Template` -> SCM logs -> WMI `Win32_Service` -> ETW process/file/registry traces.
- `NanaRun` -> service identity/token context -> process creation telemetry -> ProcMonXv2/wtrace.
- `windows-defender-remover` -> WMI/SCM inventory -> Defender operational log -> file/registry ETW.
- `wintrace` -> exact in-process API arguments; ProcMonXv2/wtrace -> external behavior stream.
- `UIforETW` -> WPR/xperf capture; `relogger.h` -> ETL reduction; WPA -> timeline and stack analysis.

## Discussion Claim Verification Standard

Do not preserve a claim as prose when it can be converted into a diagnostic artifact.

```text
Claim:
  One falsifiable sentence, not a category label.

Why it matters for new diagnostic code:
  What tool, probe, or branch this changes.

How to verify:
  First-party tool or minimal probe: WPR/WPA/xperf/logman/TraceView,
  raw ETW consumer, WMI/SCM comparison, powercfg, vssadmin, MSDelta roundtrip.

Minimal code/pseudocode:
  The smallest loop/callback/query that proves the boundary.

Interpretation:
  What each result means, including the null result.
```

High-value nullifications:
- A provider-enumeration link proves registration, not event emission.
- A wrapper repository proves code shape, not first-party API semantics.
- A ProcMon-like ETW tool proves stock-provider coverage, not driver-equivalent pre-operation visibility.
- A WMI bridge source proves one namespace/provider path, not generic state authority.
- A VSS requester source proves the VSS lifecycle, not every PowerShell module command.
- A process-snippet link with no relevant Win32 source is provenance only; Microsoft process-access docs become the evidence.
