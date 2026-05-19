# ReactOS - Open-Source NT Reimplementation

ReactOS is a full open-source attempt at NT-family compatibility: kernel objects, executive services, win32k, USER32, GDI, shell pieces, setup, drivers, and public API surfaces. For this vault, its main use is not "clone Windows" but "read a plausible implementation when the Windows documentation stops at the ABI."

Its greatest value is triangulation. If MSDN states a contract, NT5 shows the historical proprietary implementation, and ReactOS shows an independent implementation with tests and bug history, the behavior is usually better understood than from any one source alone. License and divergence still matter; treat it as comparative evidence, not as a drop-in authority.

## Connections
- Compare with `phnt` for native structure definitions and `Win32k Kernel Structures` for USER object layout.
- Compare with Wine when the question is user-mode API compatibility rather than NT internals.

## References
- <https://github.com/reactos/reactos>
