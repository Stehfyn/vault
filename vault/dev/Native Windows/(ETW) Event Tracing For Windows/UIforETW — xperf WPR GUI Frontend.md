# UIforETW - xperf/WPR GUI Frontend

UIforETW is valuable because it treats ETW as a performance-capture discipline, not as a programming exercise. It wraps WPR/xperf profiles for CPU sampling, context switches, GPU/DWM, file I/O, and symbol configuration, producing ETL files intended for Windows Performance Analyzer rather than for custom callbacks.

The repository matters for its profiles and capture defaults. Buffer sizes, stack walking, symbol paths, and provider mixes are where many ETW investigations fail. UIforETW documents a battle-tested configuration style for game, browser, and desktop latency analysis.

## Capture Commands

Use these command shapes when translating a GUI capture into a reproducible terminal workflow.

```powershell
# Fast inventory: names/GUIDs before building a krabsetw or Sealighter config.
logman query providers
logman query providers "Microsoft-Windows-Kernel-Process"

# WPR scenario capture for WPA.
wpr -start GeneralProfile -filemode
wpr -stop native-windows.etl

# xperf-style kernel capture with stacks. Tune flags and stackwalk categories per investigation.
xperf -on PROC_THREAD+LOADER+CSWITCH+PROFILE -stackwalk Profile+CSwitch -buffersize 1024 -MaxFile 1024 -FileMode Circular
xperf -d native-windows.etl

# Open the captured trace.
wpa native-windows.etl
```

Route selection is the key diagnostic decision: use WPR/UIforETW for whole-system latency and stacks, wtrace/ProcMonXv2 for live process behavior, krabsetw/Sealighter when you need programmable event filtering, and `relogger.h` when an ETL needs to be reduced after capture.

## Source Code Reading

UIforETW is partly capture UI and partly a bundle of trace-analysis habits. The linked repository has useful code and scripts that make its claims verifiable.

`EventEmitter/EventEmitter.cpp` is a local event-generation helper. It creates a named semaphore to stop the helper, starts monitor threads for power status, CPU frequency, and working set sampling, then waits until the stop signal is released. That gives traces extra user-mode markers and sampled state beside normal ETW providers.

`include/ETWProviders/etwprof.h` is the small instrumentation API: `ETWBegin`, `ETWEnd`, `ETWWorkerBegin`, `ETWWorkerEnd`, and RAII-style scoped helpers emit Generic Events markers into the trace. The practical code shape is:

```text
ETWBegin("phase")
  -> emit start marker
work
ETWEnd("phase", start_time)
  -> emit end/duration marker
```

The scripts under `bin/` show the post-capture path. `xperf_to_collapsedstacks.py` invokes `wpaexporter` with `ExportCPUUsageSampled.wpaProfile`, parses exported sampled CPU rows, converts stack separators to folded-stack format, and accumulates sample counts. `VirtualFreeStacks.py` expects an xperf dumper export and aggregates decommit/free stacks. `XperfProcessParentage.py` uses a WPA profile to export process-parentage data and reconstruct parent chains.

This matters because it turns "open in WPA and look" into reproducible artifacts:

```text
ETL
  -> wpaexporter + .wpaProfile
  -> CSV/text table
  -> script aggregation
  -> collapsed stacks / parentage / memory-free stack summaries
```

Verifiable assertions to drive:

```text
claim: user markers make trace phase boundaries visible
probe: wrap one workload phase with `ETWBegin`/`ETWEnd`, capture ETL, and confirm Generic Events rows

claim: stack usefulness depends on capture profile and symbols
probe: export sampled CPU with and without symbols; compare collapsed stack quality

claim: WPA views can be made reproducible
probe: run `wpaexporter` with a checked-in `.wpaProfile` and diff CSV row counts between baseline/workload
```

Source files read:
- `UIforETW/EventEmitter/EventEmitter.cpp`
- `UIforETW/include/ETWProviders/etwprof.h`
- `UIforETW/bin/xperf_to_collapsedstacks.py`
- `UIforETW/bin/VirtualFreeStacks.py`
- `UIforETW/bin/XperfProcessParentage.py`
- `UIforETW/bin/*.wpaProfile`

## Experiment Harness

Goal: convert a performance suspicion into an ETL artifact with a repeatable before/after measurement.

```powershell
# Baseline trace.
wpr -start GeneralProfile -filemode
Start-Sleep -Seconds 15
wpr -stop baseline.etl

# Perturbed trace: run the workload while recording.
wpr -start GeneralProfile -filemode
.\workload.exe
wpr -stop workload.etl

wpa workload.etl
```

Measure in WPA:
- CPU Usage (Sampled): hot function/module and sampled CPU percent.
- CPU Usage (Precise): wait reason, ready thread, context-switch chains.
- Generic Events: provider/event counts for the custom provider.
- Disk Usage/File I/O: request size, path, latency, issuing process.
- System Configuration/Trace Statistics: lost event and buffer warnings.

Failure interpretation:
- Trace opens but has no useful stacks: stackwalk/profile settings or symbols are missing.
- Workload is invisible: wrong time window, wrong process filter, or the behavior is not represented by enabled providers.
- Lost events are present: reduce provider set, increase buffers, switch to file mode, or shorten the repro.
- Baseline and workload look identical: the hypothesis is wrong or the chosen profile does not observe the subsystem under test.

## Connections
- Complement to `relogger.h`: UIforETW captures ETL; relogging can reduce or transform it later.
- Complement to `ProcMonXv2` and `wtrace`, which emphasize live operational views instead of WPA analysis.
- Pair with `Windows-Dev-Performance` when a trace suggests a platform-level bottleneck rather than an application bug.

## Discussion Claim Verification

Claim: "A UIforETW/WPR trace makes a performance discussion reproducible."

Why it matters for new diagnostic code: the value is not the GUI. The value is a captured ETL plus a profile/export path that lets a reader rerun the same analysis after changing code.

How to verify:
1. Capture a baseline ETL with a fixed WPR/xperf profile.
2. Capture a workload ETL with the same profile.
3. Export both through `wpaexporter` using the same `.wpaProfile`.
4. Compare row counts, top stacks, lost-event counters, and timestamp windows.

Minimal code/pseudocode:

```powershell
wpr -start GeneralProfile -filemode
.\workload.exe --scenario contention
wpr -stop workload.etl

wpaexporter -i workload.etl -profile ExportCPUUsageSampled.wpaProfile -outputfolder exported
Import-Csv exported\*.csv |
  Group-Object Process,Stack |
  Sort-Object Count -Descending |
  Select-Object -First 20
```

Interpretation: the UIforETW repository supports reproducible capture and export habits. The Microsoft WPR/WPA links support the first-party tooling contract. Neither link proves a performance hypothesis by itself; the proof is a stable before/after ETL pair with low loss counters and the same analysis profile.

## References
- <https://github.com/google/UIforETW>
- <https://learn.microsoft.com/en-us/windows-hardware/test/wpt/windows-performance-recorder>
- <https://learn.microsoft.com/en-us/windows-hardware/test/wpt/windows-performance-analyzer>
- <https://learn.microsoft.com/en-us/troubleshoot/windows-server/support-tools/support-tools-xperf-wpa-wpr>
