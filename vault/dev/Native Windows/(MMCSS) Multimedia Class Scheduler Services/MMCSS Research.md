# MMCSS Research

MMCSS is the compromise Windows uses for media workloads that need low jitter but cannot be allowed to monopolize the machine like a hard real-time scheduler. Threads call `AvSetMmThreadCharacteristicsW` with task names such as `Audio`, `Pro Audio`, or `Games`; policy then comes from `HKLM\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Multimedia\SystemProfile\Tasks\<TaskName>`.

The useful research detail in the linked thread is not a magic registry tweak; it is the interaction among `Scheduling Category`, `BackgroundPriority`, clock-rate behavior, and the hidden-looking `Latency Sensitive` value under load. Treat the values as workload policy: changes should be measured with ETW/audio glitch counters, not copied as universal "latency optimization."

## Connections
- `Low-Latency Audio - ASIO Driver Samples` for a workload that actually needs MMCSS.
- `Power State APIs` because media apps often coordinate scheduler hints with sleep/display inhibition.
- `Windows-11-Latency-Optimization Scripts` as the cautionary opposite: broad tweaks without a workload model are hard to trust.

## References
- <https://www.overclock.net/threads/research-on-multimedia-class-scheduler-service-mmcss.1774590/>
