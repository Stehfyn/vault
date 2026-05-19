# SinMapper - Signed Driver Hijack Mapper

SinMapper belongs in the driver-abuse corner of the hook map. Its premise is to use a signed driver image or signed-driver trust path as cover for loading or hosting code with kernel privileges. The exact implementation is less important here than the defensive lesson: kernel trust decisions based only on signing can be undermined when vulnerable, overly permissive, or hijacked drivers are present.

Analyze it through artifacts and controls: driver load events, certificate reputation, vulnerable-driver blocklists, section/object anomalies, device interfaces, callbacks, and unexpected kernel memory modifications. It connects to hooks because a kernel foothold can intercept or manipulate paths that user-mode hook libraries cannot safely reach.

## Connections
- Kernel-Bridge and HookLib are research frameworks; SinMapper is a risk pattern around driver loading/trust.
- KernelBhop is a smaller example of kernel capability exposed to user mode.

Code contribution: keep analysis at artifact level around service/driver load events, `NtLoadDriver`, device objects, section mapping, callback tables, and vulnerable-driver blocklist coverage.

## References
- <https://github.com/armvirus/SinMapper>
