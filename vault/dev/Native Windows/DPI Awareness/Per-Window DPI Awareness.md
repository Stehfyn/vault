# Per-Window DPI Awareness

Windows lets a thread temporarily switch DPI awareness with `SetThreadDpiAwarenessContext`, which is how a process can create different HWND subtrees under different scaling contracts. The key word is "temporarily": set the desired context before creating the window or dialog, then restore the previous context immediately so unrelated UI does not inherit it accidentally.

This is most useful for hosting legacy child windows, common dialogs, or plug-in UI inside a Per-Monitor V2 application. It is not a substitute for `WM_DPICHANGED`; each awareness context changes virtualization behavior, but your owner-drawn controls, cached bitmaps, and layout constants still have to be rebuilt when the window's effective DPI changes.

## Source Shape

Scope the thread context around HWND creation, then restore it immediately. The created window keeps the awareness context; the thread should not accidentally leak it into unrelated UI.

```cpp
DPI_AWARENESS_CONTEXT old =
    SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

HWND child = CreateWindowExW(0, L"LegacyHost", nullptr,
                             WS_CHILD | WS_VISIBLE,
                             0, 0, width, height,
                             parent, nullptr, instance, nullptr);

SetThreadDpiAwarenessContext(old);
```

For dialogs, set the scope before creation so template scaling, font selection, and child HWND creation all happen under the intended context.

```cpp
DPI_AWARENESS_CONTEXT old =
    SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
HWND dlg = CreateDialogParamW(instance, MAKEINTRESOURCEW(IDD_LEGACY),
                              owner, DlgProc, 0);
SetThreadDpiAwarenessContext(old);
```

## Discussion Claim To Verify

Claim: `SetThreadDpiAwarenessContext` is a scoped creation tool, not a global mode switch. The Microsoft sample's value is the save/restore shape around HWND creation.

Why it matters for new code: leaking a temporary DPI context changes unrelated windows created later on the same thread. Mixed-DPI hosting should make the context boundary visible in code review.

How to verify:

- Log `GetThreadDpiAwarenessContext()` before setting, during creation, and after restore.
- For the created child, compare `GetWindowDpiAwarenessContext(child)` or equivalent awareness inspection against the parent.
- Intentionally omit restore in a throwaway repro and create a second unrelated child; it should inherit the wrong context.

Minimal code/pseudocode:

```cpp
class ScopedDpiContext {
public:
    explicit ScopedDpiContext(DPI_AWARENESS_CONTEXT next)
        : old_(SetThreadDpiAwarenessContext(next)) {}
    ~ScopedDpiContext() { SetThreadDpiAwarenessContext(old_); }
private:
    DPI_AWARENESS_CONTEXT old_;
};

{
    ScopedDpiContext dpi(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
    hwndLegacy = CreateDialogParamW(instance, resource, owner, DlgProc, 0);
}
```

Interpretation: if the second child changes behavior when restore is omitted, the note's warning is verified. Wrap the pattern in an RAII guard or equivalent cleanup block before building real mixed-DPI hosts.

## References
- <https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/DPIAwarenessPerWindow/client/DpiAwarenessContext.cpp> - Microsoft source demonstrating scoped thread DPI context changes.

## Connections
- `Per-Monitor V2 DPI Reference.md` covers the process/window-level baseline.
- `Custom Controls.md` and `Rendering.md` in Common Controls are where mixed-DPI mistakes usually surface visually.
- `../Common Controls/Dialog Units.md` explains why dialog-template geometry must be converted after the dialog font is known.
- `../Custom Frame/Custom Titlebar (Minimal Recipe).md` is the non-client case where per-window DPI affects hit-test thickness and caption height.
