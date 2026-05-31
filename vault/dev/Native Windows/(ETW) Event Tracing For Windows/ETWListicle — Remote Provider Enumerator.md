# ETWListicle - Remote Provider Enumerator

ETWListicle is useful because it looks at ETW from inside a process instead of from the controller side. It walks the target process's `ntdll` ETW registration state, so it can answer a question that `logman`, TDH enumeration, and normal consumers cannot: which providers has this process actually registered with `EventRegister`? That matters when validating sensor assumptions, investigating patched `EtwEventWrite` paths, or comparing what a process should expose against what is present at runtime.

The interesting boundary is that provider presence is not the same as provider activity. A process may register a GUID and never emit, emit only when enabled, or emit through a wrapper such as TraceLogging. Treat this as a registration inventory tool, not a substitute for a live consumer such as krabsetw, Sealighter, ProcMonXv2, or wtrace.

## Source Code Reading

`ETWListicle/main.c` parses one process name, resolves a PID with `FindPid`, tries to enable debug privilege, and calls `ParseRegistrationTable(pid)`. The body is in `ETWListicle/lister.h`.

```text
GetEtwpRegistrationTableVA()
  -> GetModuleHandleA("ntdll.dll")
  -> parse DOS/NT/section headers
  -> find `.data`
  -> scan pointer-sized slots for an RTL_RB_TREE-looking value
  -> accept candidate when root looks heap-backed and Callback looks code-backed

ParseRegistrationTable(pid)
  -> OpenProcess(...)
  -> ReadProcessMemory(remote EtwpRegistrationTable)
  -> SymInitialize(...)
  -> FetchUserEntries(root)
```

`DumpNodeInfo` prints `ProviderId`, resolves a display name through the `ITraceDataProvider` COM class, maps callback and callback-context addresses to module names with `GetMappedFileNameA`, resolves symbols with `SymFromAddr`, prints a synthesized registration handle, and prints callback thread/reply-handle values.

The code-level boundary is precise: this reads registration metadata from the target process. It does not enable the provider, decode payloads, or prove that `EventWrite` is happening.

Verifiable assertions to drive:

```text
claim: a process has registered a provider GUID
probe: call `EventRegister` in a tiny sleeping process, then run ETWListicle and confirm that GUID

claim: registration is not emission
probe: run ETWListicle before and after `EventWrite`; registration output should not change

claim: provider identity can be cross-checked externally
probe: enable the listed GUID with krabsetw/raw ETW and count actual records
```

Source files read:
- `ETWListicle/main.c`
- `ETWListicle/lister.h`
- `ETWListicle/utils.h`

## Connections
- Pair with `evntprov.h` and `EventWrite` for the producer-side state that ETWListicle is inspecting.
- Pair with `krabsetw` or `ETWStudio` when the next step is decoding provider metadata and event fields.

## Discussion Claim Verification

Claim: "A registered provider means the process is emitting telemetry."

Why it matters for new diagnostic code: provider registration is inventory, not occurrence evidence. Diagnostic tools should use it to choose what to enable, then prove flow with a consumer.

How to verify:
1. Start a sleeping process that calls `EventRegister` but never calls `EventWrite`.
2. Enumerate the process registration table.
3. Start a consumer for that GUID; confirm zero callbacks.
4. Trigger one `EventWrite`; confirm registration output stays the same while callback count changes.

Minimal code/pseudocode:

```text
producer:
  EventRegister(Guid, ...)
  wait_for_key("write")
  EventWrite(RegHandle, EventId=1, ...)

verification:
  before_write_registration = ETWListicle(pid)
  before_write_callbacks = raw_consumer_count(Guid)
  after_write_registration = ETWListicle(pid)
  after_write_callbacks = raw_consumer_count(Guid)
```

Interpretation: the ETWListicle link supports runtime registration discovery. It does not support claims about event volume, field schema, or successful delivery. Use it as an arterial connection into `EventWrite`, `krabsetw`, and provider-enablement tests, not as a final telemetry verdict.

## References
- <https://github.com/whokilleddb/ETWListicle>
