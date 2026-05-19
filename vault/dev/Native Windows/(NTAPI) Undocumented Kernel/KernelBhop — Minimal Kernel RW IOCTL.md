# KernelBhop - Minimal Kernel R/W IOCTL

KernelBhop is representative of a small kernel-driver plus user-mode-client pattern: the driver exposes an IOCTL interface that lets the client ask the kernel component to inspect or copy memory associated with another process. The interesting part for research is the boundary, not the game-cheat context: user-mode handle restrictions and API hooks can be bypassed when a trusted kernel component performs the access.

Defensively, this family of projects is a clean model for what to monitor and constrain: unsigned or test-signed driver loading, vulnerable signed-driver abuse, device-object exposure, permissive IOCTL ACLs, and memory-copy routines that accept caller-controlled process IDs and addresses. The source is useful as a small specimen of the anti-pattern.

## Connections
- `SinMapper` and other signed-driver mapping notes cover the loading side of the same risk.
- System Informer and phnt are safer references for legitimate native inspection tooling.

## References
- <https://github.com/Zer0Mem0ry/KernelBhop>
