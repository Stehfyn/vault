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
