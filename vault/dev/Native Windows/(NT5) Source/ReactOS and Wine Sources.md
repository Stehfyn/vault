# ReactOS and Wine Sources

ReactOS and Wine are best used as executable commentary on Windows contracts. ReactOS aims at NT-compatible internals and therefore mirrors many kernel, win32k, USER32, and shell assumptions; Wine implements Win32 behavior on non-Windows hosts and is often excellent at documenting user-mode API edge cases through tests and compatibility fixes.

The linked examples are small but representative: ReactOS power configuration code shows conventional CPL/dialog plumbing, while Wine's animate control implementation documents the message/style behavior of `SysAnimate32`. Neither source tree proves what current Windows does, but both are clean comparison material when MSDN is vague and the NT5 source is too old or legally awkward.

## Connections
- Pair with `nt5src` for proprietary historical behavior.
- Pair with `Winuser Header`, `RichEdit Win32 Integration`, and common-control notes when reconstructing UI contracts.

## References
- https://github.com/SpinlockLabs/reactos/blob/e1e79f248b354f0a0f257b8001932704e3eee7a5/dll/cpl/powercfg/advanced.c
- https://github.com/lunixbochs/wine/blob/f316bfd0c7ab8fdae7abc0919ba236f245c099dc/dlls/comctl32/animate.c
