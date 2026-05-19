# Low-Latency Audio - ASIO Driver Samples

Microsoft's `low-latency-audio` samples are useful because ASIO lives outside the normal WASAPI shared-mode comfort zone: small buffers, strict callback timing, and driver/user-mode boundaries become visible immediately. The repo is a concrete reference for the plumbing around a low-latency audio path rather than another explanation of what latency is.

Read it beside `MMCSS Research`. ASIO, WASAPI exclusive mode, and pro-audio engines all end up caring about thread priority, timer behavior, CPU contention, and avoiding page faults in the hot path; MMCSS is the Windows mechanism that keeps real-time-ish audio work from being starved without giving arbitrary code true hard-real-time priority.

## References
- <https://github.com/microsoft/low-latency-audio>
