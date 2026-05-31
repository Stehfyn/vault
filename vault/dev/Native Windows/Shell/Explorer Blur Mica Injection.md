# Explorer Blur Mica Injection

Injects into explorer.exe and hot-patches its window-frame painting so File Explorer windows (and the shell's various host windows) get DWM blur or Win11 Mica on both Win10 and Win11 — i.e., it skips the public `DWMWA_SYSTEMBACKDROP_TYPE` path because explorer doesn't opt into it. Same author and same general playbook as Maplespe/DWMBlurGlass (#54), but DWMBlurGlass patches dwm.exe to restore the backdrop pipeline globally, whereas ExplorerBlurMica is a surgical explorer-only injection that leaves DWM alone.

## Source Code Reading

`Maplespe/ExplorerBlurMica` is useful less as a public API recipe and more as a map of where Explorer still paints through older HWND/DirectUI seams. The project file lists the actual intervention points: `HookDef.h`, `DirectUITweaker.h`, `WindowListener.h`, `TranslucentImpl.h`, `tapsite.h`, `visualtreewatcher.h`, and helper headers for DWM/accent, WinRT, DirectUI, and DLL load notification.

The source tree's headers expose four separate jobs that a vague "patch Explorer backdrop" phrase hides:

1. `dllmain.cpp` forwards process attach/detach to `MBox::OnDllMain`; real startup/shutdown is split into `MBox::Startup`, `StartupPart`, and `Shutdown` in `TranslucentImpl.h`.
2. `HookDef.h` declares detours for `DwmExtendFrameIntoClientArea`, `DwmSetWindowAttribute`, `CreateWindowExW` from `explorerframe`, `dui70`, and `shell32`, plus DirectUI paint and text functions.
3. `DirectUITweaker.h` supplies window listeners such as `CabinetWClassListener`, with callbacks for "update backdrop" and "apply backdrop" keyed to the Explorer cabinet window size.
4. `ThemeHelper.h` defines the private `WINDOWCOMPOSITIONATTRIBUTE`, `ACCENT_POLICY`, and `ACCENT_STATE` layout used to call `SetWindowCompositionAttribute`.

```cpp
// ExplorerBlurMica shape, reduced from headers.
My_CreateWindowExW_explorerframe(...); // detect/attach cabinet host HWND
CabinetWClassListener::WndProc(...);   // react to size/theme/non-client events
MyDwmSetWindowAttribute(...);          // suppress or rewrite Explorer's own attrs
SetWindowCompositionAttribute(hwnd, WCA_ACCENT_POLICY, &accent);
```

`ApplyBackdrop` in this project family therefore composes at least three decisions: identify which Explorer-created HWND is safe to restyle, decide whether to use legacy `ACCENT_ENABLE_*` or Win11 DWM backdrop attributes, then force repaint/reframe so DirectUI's existing solid backgrounds do not cover the material. The companion `DirectUI::Element::PaintBackground` dispatcher in `HookDef.h` is why this is not equivalent to calling `DwmSetWindowAttribute` on a random HWND after creation.

The repository currently publishes several header declarations for `.cpp` files that are not present in the shallow source tree I inspected (`DirectUITweaker.cpp`, `TranslucentImpl.cpp`, `WindowListener.cpp`, `ThemeHelper.cpp` are referenced by the `.vcxproj` but absent from `HEAD`). That limits exact control-flow reconstruction, but the declared hook surface is still concrete: the implementation must own detour installation, HWND listener lifetime, and the accent/DWM policy mutation above.

## References
- <https://github.com/Maplespe/ExplorerBlurMica>
