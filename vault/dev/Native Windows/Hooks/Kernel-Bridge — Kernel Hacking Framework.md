# Kernel-Bridge - Kernel Hacking Framework

Kernel-Bridge is a framework and driver/user communication environment for Windows kernel experimentation. In the hook taxonomy, it matters because many kernel hook projects need the same scaffolding before they ever touch an interception point: driver loading, device interfaces, IOCTL contracts, memory access helpers, symbol/offset handling, and safe teardown.

The useful editorial distinction is framework versus technique. Kernel-Bridge is not one hook; it is infrastructure that can support kernel research patterns, some legitimate and some fragile. Notes that cite it should say which boundary is being crossed: kernel callbacks, memory inspection, object manipulation, or user/kernel RPC.

## Connections
- HookLib is the adjacent interception library from the same ecosystem.
- KernelBhop and SinMapper show riskier driver-use patterns worth analyzing defensively.

Code contribution: the reusable pieces are device creation, `IRP_MJ_DEVICE_CONTROL`, IOCTL dispatch, user/kernel RPC structs, memory helpers, symbol/offset handling, and teardown paths.

## References
- <https://github.com/HoShiMin/Kernel-Bridge>
