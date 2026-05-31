# NpEtw - Named-Pipe I/O ETW Provider

NpEtw fills a real visibility gap: Windows exposes excellent file, registry, process, image-load, and network ETW, but named-pipe content and pipe-level flow are not covered with the same fidelity. A minifilter-style component can observe named-pipe operations and publish them through a custom ETW provider, letting ordinary ETW consumers correlate pipe activity with process, RPC, service-control, and authentication events.

The research value is architectural more than procedural. It shows when user-mode ETW is insufficient and why a provider may need to be added near the object being observed. That distinction matters for defenders: missed telemetry is not always a bad query; sometimes the provider simply does not exist in stock Windows.

## Source Code Reading

Treat this repository as a provider-boundary study. The safe educational value is the observability architecture.

`NpEtw/NpEtw.cpp` registers a minifilter with `FLTFL_REGISTRATION_SUPPORT_NPFS_MSFS`, which is the source-level signal that the filter is scoped to named-pipe and mailslot file systems rather than ordinary disk files. Its `OperationCallbacks` table names the observed classes:

```text
IRP_MJ_CREATE              -> pre/post create pipe name capture
IRP_MJ_CREATE_NAMED_PIPE   -> pre/post create pipe name capture
IRP_MJ_READ                -> post-read safe callback
IRP_MJ_WRITE               -> post-write safe callback
IRP_MJ_DIRECTORY_CONTROL   -> generic pre/post
IRP_MJ_FILE_SYSTEM_CONTROL -> FSCtl-specific post path
```

The lifecycle is conventional and testable:

```text
DriverEntry
  -> WPP_INIT_TRACING
  -> EventRegisterNpEtw()
  -> FltRegisterFilter(...)
  -> FltStartFiltering(...)

NpEtwUnload
  -> FltUnregisterFilter(...)
  -> EventUnregisterNpEtw()
  -> WPP_CLEANUP(...)
```

`NpEtwInstanceSetup` attaches only when `VolumeFilesystemType == FLT_FSTYPE_NPFS`; otherwise it returns `STATUS_FLT_DO_NOT_ATTACH`. `NpEtwPreCreateNamedPipe` captures cheap metadata before completion by calling `FltGetFileNameInformation`, storing the result in `CompletionContext`, and synchronizing into the post callback.

`NpEtw/Trace.h` defines WPP control bits (`General`, `Create`, `ReadWrite`, `FSCtl`) and a custom `HEXDUMP` complex type for buffer+length logging. The defensible takeaway is provider-flag design: consumers can enable creation metadata separately from high-volume read/write data.

Verifiable assertions to drive:

```text
claim: the provider attaches only to NPFS
probe: debugger/log output from `NpEtwInstanceSetup`; confirm non-NPFS volumes return DO_NOT_ATTACH

claim: pre-create preserves names for failed creates
probe: attempt a known failing pipe open and verify the emitted create event still has a name/status

claim: stock ETW misses this visibility class
probe: compare stock process/file ETW against NpEtw Create-only events for one pipe workload
```

Source files read:
- `NpEtw/NpEtw.cpp`
- `NpEtw/NpEtw.h`
- `NpEtw/Trace.h`
- `NpEtw/NpEtwEvents.man`

## Connections
- Pair with `ProcMonXv2` and `wtrace` to compare stock kernel providers with custom provider coverage.
- Pair with `evntprov.h` and `EventWrite` for the custom-provider emission model.

## Discussion Claim Verification

Claim: "Stock ETW does not expose enough named-pipe detail, so a custom provider is justified."

Why it matters for new diagnostic code: this is the precise bar for adding a provider near the object being observed. If stock providers already answer the question, the custom component is unnecessary. If they do not, the new provider must make the missing field explicit.

How to verify:
1. Run a named-pipe client/server workload with a unique pipe name and fixed message sizes.
2. Capture stock kernel ETW through WPR/wtrace/ProcMonXv2-equivalent file/process providers.
3. Capture NpEtw create-only events, then read/write events if enabled.
4. Compare which planes expose pipe name, creator PID, status, byte count, and payload policy.

Minimal code/pseudocode:

```text
server:
  CreateNamedPipeW("\\\\.\\pipe\\NativeWindowsProbe")
  ConnectNamedPipe()
  ReadFile(buffer)

client:
  CreateFileW("\\\\.\\pipe\\NativeWindowsProbe")
  WriteFile("probe-message")

verification:
  stock_etw = capture(Process + FileIO + ALPC/RPC if relevant)
  npetw = capture(NpEtw Create only, then ReadWrite)
  compare fields by pid + pipe name + timestamp window
```

Interpretation: the NpEtw link supports the provider-boundary claim because the code attaches to NPFS/MSFS and emits its own ETW events. It should not be cited as proof that stock ETW is useless for all pipe investigations; stock providers may still show process, handle, file-name, service, RPC, or network context around the pipe workload.

## References
- <https://github.com/kobykahane/NpEtw>
