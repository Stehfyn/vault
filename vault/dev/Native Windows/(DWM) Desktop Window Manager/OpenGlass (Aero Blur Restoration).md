# OpenGlass (Aero Blur Restoration)

Resurrects Aero Glass blur-behind on Windows 10/11 by injecting into `dwm.exe` and intercepting the post-Win8 compositor's effect pipeline (uDWM.dll / dwmcore.dll), replacing the flat Mica/Acrylic backdrops with a real Gaussian blur + tint pass. Notable because it does not rely on the old `DwmEnableBlurBehindWindow` path (which Microsoft gutted after 8.1) — it patches the compositor itself, so it works on UWP, WPF, and legacy Win32 windows uniformly (cf. Maplespe/DWMBlurGlass for a sibling project, ALTaleX531/Win32Acrylic for the in-process WinRT route that doesn't need injection).

```cpp
// Conceptual: hook the symbol that builds the per-window effect graph in dwmcore.dll
// Real project resolves the function via PDB symbol lookup against the MS symbol server.
using CRenderingComposition_Build_t = HRESULT(__fastcall*)(void* self, void* visual);
CRenderingComposition_Build_t orig = nullptr;

HRESULT __fastcall HookedBuild(void* self, void* visual) {
    HRESULT hr = orig(self, visual);
    // Walk the visual tree, find the backdrop brush node, swap its
    // CBackdropEffectGroup for a Gaussian-blur + tint chain.
    InjectBlurEffect(visual, /*radius*/ 30.0f, /*tint*/ 0x80FFFFFF);
    return hr;
}

// MinHook-style detour installed from a DLL loaded into dwm.exe via
// SetWindowsHookEx(WH_GETMESSAGE, ...) or a debug-privilege CreateRemoteThread.
```

## References
- <https://github.com/ALTaleX531/OpenGlass>
- Related: `DWM Blur Glass (Aero Restoration).md`, `DWM Internals Documentation.md`, `DWM Colorization.md`
