# relogger.h - ETW Trace Relogger Header

`relogger.h` exposes the COM relogger interfaces for reading ETL input and writing a transformed ETL output. This is the post-capture side of ETW: filter events, rewrite metadata, merge traces, or reduce a capture before loading it into WPA or a custom analysis pipeline.

Relogging is not the same as live consumption. A live consumer must keep up with buffers and session delivery; a relogger can spend more time normalizing or pruning a trace after the fact. That makes it useful for performance investigations where raw WPR captures are too large or noisy to share.

## Connections
- UIforETW produces WPA-loadable ETL traces that may later be relogged.
- `evntcons.h` describes the event records the relogger reads.

## References
- Windows SDK `relogger.h`
