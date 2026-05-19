# Window Manager Internals (winmgr.c)

`winmgr.c` is the NT5 source-side map for z-order, ownership, visibility, activation-adjacent state, and `SetWindowPos` routing. It explains why changing a style bit is often inert until a frame recalculation is requested, and why move/size operations are policy-heavy rather than simple rectangle assignment.

The practical reading is that top-level window state is a graph problem: owners, parents, desktops, topmost bands, clipping, activation, and redraw invalidation all interact. That is why window bugs often look inconsistent when reproduced with child windows, owned popups, tool windows, or different monitor/work-area geometry.

## Connections
- `Caption Rendering`, `MinMax Size Computation`, and `System Command Processing` are specialized pieces of the same window-manager path.
- WinSpy++ is a user-mode tool for observing the resulting handles, styles, messages, and hierarchy.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/rtl/winmgr.c#L19
- https://shreklane.github.io/winkrnldocs/d3/d7/rtl_2winmgr_8c-source.html#l00856
