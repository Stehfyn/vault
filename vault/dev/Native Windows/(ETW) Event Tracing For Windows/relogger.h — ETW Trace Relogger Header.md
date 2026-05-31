# relogger.h - ETW Trace Relogger Header

`relogger.h` exposes the COM relogger interfaces for reading ETL input and writing a transformed ETL output. This is the post-capture side of ETW: filter events, rewrite metadata, merge traces, or reduce a capture before loading it into WPA or a custom analysis pipeline.

Relogging is not the same as live consumption. A live consumer must keep up with buffers and session delivery; a relogger can spend more time normalizing or pruning a trace after the fact. That makes it useful for performance investigations where raw WPR captures are too large or noisy to share.

## Connections
- UIforETW produces WPA-loadable ETL traces that may later be relogged.
- `evntcons.h` describes the event records the relogger reads.

## Discussion Claim Verification

Claim: "Relogging can fix a bad capture."

Why it matters for new diagnostic code: relogging is post-capture transformation. It can reduce, merge, or rewrite ETL artifacts; it cannot recover events that were never recorded or fields the provider never emitted.

How to verify:
1. Capture a known workload to ETL with WPR/xperf.
2. Query trace statistics and event counts before relogging.
3. Relog to keep only one provider/PID/time range.
4. Open both ETLs in WPA or export both with `wpaexporter`.
5. Compare event counts, provider list, and lost-event counters.

Minimal code/pseudocode:

```text
input.etl
  -> relogger callback reads EVENT_RECORD
  -> if ProviderId == target && ProcessId == pid:
       inject/write event to output.etl
  -> output.etl

verify:
  count(input, target_provider, pid) == count(output, target_provider, pid)
  lost events in input remain lost in output
```

Interpretation: the SDK `relogger.h` header supports post-capture ETL processing. It does not support live observation claims, throughput claims, or any promise that a noisy trace can be made semantically complete after the fact.

## References
- Windows SDK `relogger.h`
