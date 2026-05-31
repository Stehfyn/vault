# wtrace - CLI strace for Windows

wtrace is the lightweight, terminal-oriented face of ETW: start a process or attach a filter, subscribe to selected providers, and stream file, registry, network, process, RPC, or task-parallel events as text. It matters because many investigations do not need a full WPA trace or Procmon UI; they need a quick answer to "what did this process touch?"

The tool also demonstrates an important Windows difference from Unix `strace`: it is not primarily syscall interception. It reconstructs behavior from ETW providers, which means coverage depends on provider semantics, dropped buffers, privileges, and event decoding. That makes it excellent for observation and less exact as a syscall transcript.

## Command Shape

Use the tool category this way even when the exact flags change: scope the target, choose provider families, keep output greppable, then escalate to ETL/WPA only if timing or stacks matter.

```powershell
# Provider reconnaissance before choosing a live trace.
logman query providers | findstr /i "kernel process file registry tcpip rpc"

# Service/process triage route.
sc.exe queryex MyService
Get-CimInstance Win32_Service -Filter "Name='MyService'" | Select Name,State,ProcessId,PathName

# Then stream process/file/registry/network behavior with wtrace-style ETW filters.
# Keep the command line in the note next to the investigation so provider coverage is reproducible.
```

If the question is "which Win32 API call from this module had these exact arguments?", route to `wintrace`/IAT instrumentation. If the question is "what operating-system-visible behavior occurred?", route to ETW.

## Source Code Reading

The wtrace repository is not a syscall hooker. Its concrete spine is `wtrace.cmd/Tracing/EtwTraceSession.fs`, which builds a `Microsoft.Diagnostics.Tracing.Session.TraceEventSession`, enables kernel provider flags, subscribes event-family handlers, runs a short rundown session, and then calls `session.Source.Process()`.

```text
Program.fs
  -> handler selection: process, file, registry, tcp, udp, rpc, image
  -> TraceControl.fs
  -> EtwTraceSession.start
       handlers.Initialize(...)
       session.EnableKernelProvider(kernelFlags, kernelStackFlags)
       provider EnableProvider(...) for custom user providers
       handler.Subscribe(TraceEventSources(...), ...)
       runRundownSession(...)
       session.Source.Process()
```

`wtrace.cmd/Events/FileIO.fs` is the detail a reader actually needs. It does not merely print `FileIO` callbacks. It maintains pending file I/O keyed by event IDs, learns paths from `FileIOName`/rundown records, emits create/read/write/delete/rename/query events, and completes operations when `FileIOOperationEnd` arrives.

```text
on FileIORead/FileIOWrite:
  remember id -> event plus offset/size fields

on FileIOOperationEnd:
  lookup previous event by id
  merge completion status/timing
  publish TraceEventWithFields
```

That makes dropped or filtered completion events a testable failure mode. If the trace contains operation starts but no completions, the tool may be losing the result field rather than lying about file activity.

`wtrace.cmd/Events/Registry.fs` has the same stateful character. It watches KCB create/delete/rundown events so live registry operations can be normalized from NT registry paths into `HKLM`, `HKCU`, `HKCR`, and `HKU`. If registry names are poor, validate the rundown path before blaming display formatting.

Verifiable assertions to drive:

```text
claim: wtrace reconstructs behavior from ETW, not syscall trapping
probe: run the same workload under wtrace and an IAT hook; compare event rows vs API call tuples

claim: file rows can require operation-end correlation
probe: count FileIORead/FileIOWrite starts and FileIOOperationEnd callbacks for one PID

claim: registry names depend on rundown/KCB state
probe: run with and without registry rundown; compare normalized root names
```

Source files read:
- `wtrace.cmd/Tracing/EtwTraceSession.fs`
- `wtrace.cmd/Events/FileIO.fs`
- `wtrace.cmd/Events/Registry.fs`
- `wtrace.cmd/Processing/TraceEventProcessor.fs`

## Experiment Harness

Goal: turn a vague "what did it touch?" question into a short, greppable behavior transcript.

```powershell
$before = Get-Date
.\target.exe
$pid = (Get-Process target -ErrorAction SilentlyContinue).Id

# Then run the wtrace-style command for process/file/registry/network providers
# with a PID or process-name filter, and save stdout beside the repro.
```

Measure:
- Process events: create/exit PID, parent PID, command line if available.
- File events: path, operation, status, latency if surfaced by the tool.
- Registry events: key path, operation, status.
- Network events: destination, protocol, connection lifetime.

Failure interpretation:
- No output: provider family not enabled, PID filter wrong, process already exited, or elevation/session mismatch.
- Output misses exact arguments: this is ETW observation, not API-call interception; switch to `wintrace` for call-site arguments.
- High-volume noise hides signal: add PID/name/path filters or graduate to ProcMonXv2/WPA where grouping is easier.

## Connections
- Compare with NtTrace for native-call tracing through debug/instrumentation rather than ETW.
- Compare with ProcMonXv2 for a GUI, high-volume view of similar provider families.
- Pair with `windows-defender-remover` and `Win32 Service Template` notes for service-start and service-tamper investigations.

## Discussion Claim Verification

Claim: "`wtrace` is Windows `strace`."

Why it matters for new diagnostic code: if the reader copies the Unix mental model, they will build the wrong validator. `strace`-style code asks "which call entered the kernel?" `wtrace`-style code asks "which ETW provider emitted an observation that survived buffering, filtering, and decoding?"

How to verify:
1. Build a tiny workload that calls `CreateFileW`, `ReadFile`, `RegOpenKeyExW`, and `RegQueryValueExW` on known paths.
2. Run it under `wtrace`.
3. Run the same workload under an API-boundary probe such as `wintrace` or a local debug/IAT experiment.
4. Diff event rows against call tuples: ETW rows should group by provider/opcode/status, not by every user-mode helper call.

Minimal pseudocode:

```text
workload:
  CreateFileW("C:\\Temp\\wtrace-proof.txt")
  WriteFile(...)
  RegOpenKeyExW(HKCU, "Software\\NativeWindowsProbe")
  RegQueryValueExW(...)

verification:
  live_etw_rows = run_wtrace(pid_filter)
  api_rows = run_process_local_call_probe(pid)
  compare:
    file path appears in both
    exact helper-call count appears only in api_rows
    completion/status appears only if provider emitted and operation-end correlation succeeded
```

Interpretation: the GitHub link supports the ETW-reconstruction claim because the code is built around `TraceEventSession`, provider enablement, and event-family handlers. It does not support a stronger claim that every syscall or Win32 API argument is captured. If a future article says "wtrace sees every file API call," nullify it unless the note also names the provider event that carries that argument.

## References
- <https://github.com/lowleveldesign/wtrace>
