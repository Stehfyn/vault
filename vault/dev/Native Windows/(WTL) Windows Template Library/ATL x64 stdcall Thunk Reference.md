# ATL x64 stdcall Thunk Reference

ATL window thunks are the machinery that lets a C++ object method behave like a C `WNDPROC`. On x86 that involved stack/calling-convention tricks; on x64 the ABI is simpler but ATL still emits a tiny per-instance stub that loads the object pointer into the first argument register and jumps to the real window procedure.

This is worth keeping because WTL's pleasant `CWindowImpl` message maps rest on this low-level fact. If you are debugging crashes before `WM_NCCREATE`, subclass lifetime bugs, or hand-rolled window wrappers, the thunk explains how an HWND message becomes a method call and why object lifetime must outlive the registered/subclassed procedure.

```asm
mov     rcx, <this>
mov     rax, <target>
jmp     rax
```

## References
- <https://github.com/adzm/atlmfc/blob/master/src/atl/atls/x64/stdcallthunk.s> - ATL/MFC x64 thunk assembly used to route callbacks into object instances.
