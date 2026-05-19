# wtrace - CLI strace for Windows

wtrace is the lightweight, terminal-oriented face of ETW: start a process or attach a filter, subscribe to selected providers, and stream file, registry, network, process, RPC, or task-parallel events as text. It matters because many investigations do not need a full WPA trace or Procmon UI; they need a quick answer to "what did this process touch?"

The tool also demonstrates an important Windows difference from Unix `strace`: it is not primarily syscall interception. It reconstructs behavior from ETW providers, which means coverage depends on provider semantics, dropped buffers, privileges, and event decoding. That makes it excellent for observation and less exact as a syscall transcript.

## Connections
- Compare with NtTrace for native-call tracing through debug/instrumentation rather than ETW.
- Compare with ProcMonXv2 for a GUI, high-volume view of similar provider families.

## References
- <https://github.com/lowleveldesign/wtrace>
