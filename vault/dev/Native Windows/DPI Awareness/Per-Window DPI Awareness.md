# Per-Window DPI Awareness

Windows lets a thread temporarily switch DPI awareness with `SetThreadDpiAwarenessContext`, which is how a process can create different HWND subtrees under different scaling contracts. The key word is "temporarily": set the desired context before creating the window or dialog, then restore the previous context immediately so unrelated UI does not inherit it accidentally.

This is most useful for hosting legacy child windows, common dialogs, or plug-in UI inside a Per-Monitor V2 application. It is not a substitute for `WM_DPICHANGED`; each awareness context changes virtualization behavior, but your owner-drawn controls, cached bitmaps, and layout constants still have to be rebuilt when the window's effective DPI changes.

## References
- <https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/DPIAwarenessPerWindow/client/DpiAwarenessContext.cpp> - Microsoft source demonstrating scoped thread DPI context changes.

## Connections
- `Per-Monitor V2 DPI Reference.md` covers the process/window-level baseline.
- `Custom Controls.md` and `Rendering.md` in Common Controls are where mixed-DPI mistakes usually surface visually.
