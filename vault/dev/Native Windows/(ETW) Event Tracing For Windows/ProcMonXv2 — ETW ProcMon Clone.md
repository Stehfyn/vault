# ProcMonXv2 - ETW ProcMon Clone

ProcMonXv2 is a useful counterexample to the assumption that Procmon-style visibility always requires a custom kernel driver. It builds a process/file/registry/network monitor on real-time ETW providers, then does the hard desktop-tooling work: filtering, correlation, formatting, and keeping a high-volume UI responsive.

Its limitation is also instructive. ETW can expose a large fraction of operational behavior, but it does not automatically provide every pre-operation decision point, stack, buffer, or object detail that a driver can collect. Read it as a practical map of what stock ETW can do well before reaching for kernel instrumentation.

## Diagnostic Route

Use ProcMonXv2 as the middle layer between raw ETW APIs and full WPA traces.

```text
question: "what did this process touch?"
route:
  quick text stream -> wtrace
  GUI filter/correlation -> ProcMonXv2
  programmable callback -> krabsetw / Sealighter
  whole-system timeline/stacks -> UIforETW / WPR / WPA
  post-capture reduction -> relogger.h
```

The high-impact connection is services: when a service fails to start, pair SCM events (`Service Control Manager` in the System log) with ProcMon-style file/registry/process ETW. That separates "SCM rejected the service contract" from "the worker started and then failed inside its dependencies."

## Source Code Reading

The important source file is `EventTracing/TraceManager.cpp`. `TraceManager::Start` is the implementation behind "start monitoring": it enables privileges, creates a kernel logger session, updates enabled categories, opens a real-time `EVENT_RECORD` stream, and moves `ProcessTrace` onto a dedicated high-priority thread.

```text
TraceManager::Start(callback)
  -> EnablePrivilege(SE_DEBUG_NAME)
  -> EnablePrivilege(SE_SYSTEM_PROFILE_NAME)
  -> allocate EVENT_TRACE_PROPERTIES
  -> StartTrace(KERNEL_LOGGER_NAME, ...)
       if ERROR_ALREADY_EXISTS: ControlTrace(... STOP), retry
  -> UpdateEventConfig()
  -> OpenTrace(EVENT_TRACE_LOGFILE with EventRecordCallback)
  -> CreateThread(Run)
  -> SetThreadPriority(THREAD_PRIORITY_HIGHEST)

TraceManager::Run()
  -> ProcessTrace(...)
```

That fills in the missing body of "ProcMon-like": ProcMonXv2 is a real-time kernel ETW controller and consumer. It is not walking directories, polling registry keys, or intercepting APIs. If `StartTrace` fails, no UI filter can recover because the event plane never came up.

Event decoding is split between `EventTracing/EventData.cpp` and `EventTracing/EventParser.cpp`. They call `TdhGetEventInformation`, `TdhGetPropertySize`, `TdhGetEventMapInformation`, and `TdhFormatProperty` against the incoming `EVENT_RECORD`. When fields are missing or numerically formatted, the likely fault is TDH/schema availability or event-version handling, not the table view.

`EventTracing/KernelEvents.cpp` is the code-backed answer to "what can this clone see?" It maps categories such as Process, Thread, Image, File, Registry, TCP, UDP, Disk I/O, Virtual Memory, ALPC, Object Manager, Heap, Job, Driver, and WorkerThread into GUIDs/opcodes/enable flags. If a category is absent there, the GUI cannot magically observe it.

Verifiable assertions to drive:

```text
claim: monitoring requires kernel ETW session ownership
probe: start while another kernel logger is active; observe StartTrace/ControlTrace behavior

claim: category coverage is bounded by KernelEvents.cpp
probe: enable one category at a time and compare emitted provider GUID/opcode pairs

claim: service failures split into SCM-contract vs dependency failures
probe: compare SCM System-log rows with process/file/registry ETW for the service PID
```

Source files read:
- `EventTracing/TraceManager.cpp`
- `EventTracing/EventData.cpp`
- `EventTracing/EventParser.cpp`
- `EventTracing/KernelEvents.cpp`
- `ProcMonX/View.cpp`

## Experiment Harness

Goal: separate service-contract failure from dependency failure.

Procedure:
1. Create a test service whose worker opens one known file and one known registry key.
2. Start ProcMonXv2 with filters for the service image name and service PID.
3. Start/stop the service three times with `sc.exe start` and `sc.exe stop`.
4. Export or screenshot the filtered process/file/registry events next to the SCM System-log events.

```powershell
sc.exe queryex MyService
sc.exe start MyService
Start-Sleep -Seconds 3
sc.exe queryex MyService
Get-WinEvent -LogName System -MaxEvents 30 |
  Where-Object ProviderName -eq 'Service Control Manager'
```

Measurable signals:
- SCM accepted start: service reaches `SERVICE_START_PENDING` or `SERVICE_RUNNING`.
- Worker ran: process-create event and file/registry events appear for the service PID.
- Dependency failure: access denied, path not found, DLL load, or registry miss appears after worker start.

Failure interpretation:
- SCM log shows start failure and no process events: service registration/path/account/control contract is wrong.
- Process events appear then service stops: worker initialization or dependency failure.
- ProcMonXv2 misses a class of behavior: stock ETW provider coverage is insufficient; use WPR stacks, a custom provider, or process-local tracing.

## Connections
- Compare with `wtrace` for CLI streaming and `UIforETW` for WPA-oriented capture.
- Compare with NpEtw for cases where stock providers do not cover the object class being studied.
- Compare with `wintrace` when you need call-site argument logging inside one process rather than provider-level operating-system telemetry.

## Discussion Claim Verification

Claim: "ProcMon-like visibility can be built from stock ETW."

Why it matters for new diagnostic code: this is the fork between a user-mode diagnostic tool and a driver. Before writing privileged code, prove whether kernel ETW categories already expose the process/file/registry/network surface you need.

How to verify:
1. Start a real-time kernel ETW session with only one category enabled.
2. Run a deterministic workload that performs one process launch, one file create, one registry read, and one loopback TCP connection.
3. Repeat with categories added one at a time.
4. Compare rows against Sysinternals Procmon or a WPR capture only as a coverage reference, not as proof of identical implementation.

Minimal code/pseudocode:

```text
for category in [Process, ImageLoad, FileIO, Registry, TcpIp]:
  TraceManager.Start(categories = [category])
  run_workload()
  count events by ProviderId + Opcode + PID
  TraceManager.Stop()

assert:
  process category sees create/exit
  registry category sees key operations
  file category may need name/rundown correlation
  missing rows mean provider coverage/configuration gap, not UI-filter failure
```

Interpretation: the ProcMonXv2 link supports "ProcMon-like UI over ETW providers." It does not support "equivalent to Sysinternals Procmon's driver-level pre/post-operation model." Treat mismatches as an experiment result: stock ETW may be enough for triage and insufficient for blocking decisions, stack-rich attribution, or object classes without providers.

## References
- <https://github.com/zodiacon/ProcMonXv2>
