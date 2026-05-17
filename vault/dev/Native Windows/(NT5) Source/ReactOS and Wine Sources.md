# ReactOS and Wine Sources

ReactOS and Wine provide open-source reimplementations of the Windows API. ReactOS power configuration CPL (`dll/cpl/powercfg`) uses standard Win32 dialog patterns. Wine's `comctl32/animate.c` implements `SysAnimate32`. Both are invaluable for understanding expected behavior without access to the proprietary source.

```cpp
// Animate control (SysAnimate32) — plays AVI clips in child windows
HWND hAnim = CreateWindowW(ANIMATE_CLASS, nullptr,
    WS_CHILD | WS_VISIBLE, 10, 10, 200, 50, hwnd, nullptr, hInst, nullptr);
Animate_Open(hAnim, MAKEINTRESOURCEW(IDR_AVI1));
Animate_Play(hAnim, 0, -1, -1);   // loop from frame 0 to end, infinite times
Animate_Stop(hAnim);
```

## References
- https://github.com/SpinlockLabs/reactos/blob/e1e79f248b354f0a0f257b8001932704e3eee7a5/dll/cpl/powercfg/advanced.c
- https://github.com/lunixbochs/wine/blob/f316bfd0c7ab8fdae7abc0919ba236f245c099dc/dlls/comctl32/animate.c
