# DWM Overlay WndProc Hook

A working DWM-overlay that fixes the usual ImGui-over-DWM breakage: instead of trampolining `IDXGISwapChain::Present` (which fights anti-cheat heuristics), it hooks the target's WndProc so ImGui input routing actually works inside the compositor surface. Compare with the much heavier compositor mods in this cluster — kawapure/DWM-Documentation (#11), notr1ch/DWMCapture (#12), Maplespe/DWMBlurGlass (#54), ALTaleX531/OpenGlass (#13), Maplespe/ExplorerBlurMica (#66), MapleSwan/dwm-overlay (#67) — this one is the minimum-viable overlay surface.

```cpp
// hook target's WndProc via SetWindowLongPtr; forward to ImGui first
WNDPROC oWndProc = nullptr;
LRESULT CALLBACK hkWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    if (ImGui_ImplWin32_WndProcHandler(h, m, w, l))
        return 1;
    return CallWindowProcW(oWndProc, h, m, w, l);
}
// install:
oWndProc = (WNDPROC)SetWindowLongPtrW(target, GWLP_WNDPROC, (LONG_PTR)hkWndProc);
```

## References
- <https://github.com/seiftnesse/DWM_Hook>
- Related: `DWM Process Overlay Injection.md`, `DwmGetDxSharedSurface Window Capture.md`

## Discussion Claim To Verify

The useful claim is not "hook WndProc"; it is that input routing and rendering are separate boundaries. A present-hook-only overlay can draw but fail to receive coherent ImGui input; a WndProc route can receive input but does not prove the compositor draw path is stable.

```cpp
LRESULT CALLBACK ProbeWndProc(HWND h, UINT m, WPARAM w, LPARAM l) {
    bool imgui_wants = ImGui_ImplWin32_WndProcHandler(h, m, w, l);
    log_message(qpc_now(), h, m, w, l, imgui_wants);
    return imgui_wants ? 1 : CallWindowProcW(original, h, m, w, l);
}
```

Verification route: synthesize mouse move, click, DPI-change, resize, and activation messages against the same target and compare the WndProc log with visible overlay state. Failure cases: wrong HWND, subclass overwritten by another component, reentrancy during destruction, or input captured by another top-level window. Keep this note at the message-boundary level; do not turn it into a DWM injection recipe.
