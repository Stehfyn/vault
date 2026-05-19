# WinSpy++ - Open-Source Spy++ Clone

WinSpy++ is valuable because it shows what a serious window inspector actually has to do. Enumerating windows from the outside gives handles, titles, classes, rectangles, styles, and hierarchy, but it does not give message flow. To observe messages the tool uses USER32 hook machinery in the target thread, which is the same architectural reason Microsoft's Spy++ has always felt closer to a debugger than to a simple enumeration sample.

The finder-tool behavior is also instructive: hit-testing, child-window selection, visual highlighting, and cross-thread/process inspection all sit on ordinary USER32 APIs until message logging requires injected hook code. This makes WinSpy++ the clean, defensive counterexample to treating SetWindowsHookEx only as an injection trick.

## Connections
- `SetWindowsHookEx` explains the hook contract behind message logging.
- `WND Internal Structure` and `Win32k Kernel Structures` explain the deeper state that a supported inspector can only infer indirectly.
- `System-Defined Messages` and `Message Queue Implementation` explain what the logger is watching.

## References
- <https://github.com/strobejb/winspy>
