# Translucent Win32 Flyouts

Hooks the per-process drawing path of the legacy Win32 flyout/menu/tooltip stack (`DrawThemeBackground`, `BeginBufferedPaint`, the menu owner-draw plumbing) and substitutes a DWM-blurred backdrop, so Win32 context menus and combo dropdowns visually match Win11's WinUI flyouts. Same author as ALTaleX531/OpenGlass (#13) and ALTaleX531/Win32Acrylic (#14); this is the "third leg" — OpenGlass restores Aero, Win32Acrylic adds the acrylic backdrop, TranslucentFlyouts brings the menus along.

## Source Shape

Read this as an interception stack, not a single backdrop flag: discover transient flyout windows, patch or subclass the drawing path, then let DWM/DirectComposition supply the blurred material.

```cpp
// Conceptual shape: real projects split this across hook/subclass helpers.
HookApi("uxtheme.dll", "DrawThemeBackground", DrawThemeBackgroundHook);
HookApi("uxtheme.dll", "BeginBufferedPaint", BeginBufferedPaintHook);

if (IsLegacyFlyoutWindow(hwnd)) {
    ApplyBackdrop(hwnd);
    InvalidateRect(hwnd, nullptr, TRUE);
}
```

The value of the link is in the coverage map: menus, combo dropdowns, tooltips, and other USER32 flyouts do not all pass through one documented customization API.

## Source Code Reading

`ALTaleX531/TranslucentFlyouts` makes the hidden `ApplyBackdrop(hwnd)` step concrete. The main composition path is:

1. A handler class classifies the transient window and reads registry-backed policy.
2. `Api::QueryBackdropEffectContext(part, darkMode, context)` fills `effectType`, `enableDropShadow`, and ARGB tint.
3. `Api::ApplyEffect(hwnd, darkMode, backdrop, border)` applies backdrop first, then border/corners.
4. `EffectHelper::SetWindowBackdrop(hwnd, dropShadow, tintColor, effectType)` maps the abstract effect into DWM and `SetWindowCompositionAttribute`.

The key files are `TFMain/MenuHandler.cpp`, `TFMain/ToolTipHandler.cpp`, `TFMain/ApiEx.cpp`, and `TFMain/EffectHelper.hpp`.

```cpp
// ApiEx.cpp shape, reduced.
ApplyBackdropEffect(hwnd, darkMode, context);
ApplyBorderEffect(hwnd, darkMode, border);
```

`ApplyBackdropEffect` is not a one-liner: it first sets immersive dark mode, then calls `SetWindowBackdrop`, then forces owned-window transition/reposition so the non-client visual state refreshes. `DropEffect` is the reverse path: disable the accent policy, reset Win11 corner/border DWM attributes, and invalidate the window.

```cpp
// EffectHelper.hpp shape, reduced.
EnableWindowDarkMode(hwnd, darkMode);
SetWindowBackdrop(hwnd, shadow, tintArgb, effectType);
DwmTransitionOwnedWindow(hwnd, DWMTRANSITION_OWNEDWINDOW_REPOSITION);
```

`SetWindowBackdrop` is the actual material switch. `None`, `Solid`, `Transparent`, `Blur`, `AcrylicBlur`, and `ModernAcrylicBlur` are expressed through `WCA_ACCENT_POLICY` and an `ACCENT_POLICY`. The Win11 background-layer modes instead set `DWMSBT_TRANSIENTWINDOW`, `DWMSBT_MAINWINDOW`, or `DWMSBT_TABBEDWINDOW`, optionally toggle the undocumented build-22000-era Mica attribute `1029`, then make the window transparent with `DwmEnableBlurBehindWindow` so the system backdrop can show through.

```cpp
switch (effectType) {
case Solid:  accent.AccentState = ACCENT_ENABLE_GRADIENT; break;
case Blur:   accent.AccentState = ACCENT_ENABLE_BLURBEHIND; break;
case AcrylicBlur:
case ModernAcrylicBlur:
    accent.AccentState = ACCENT_ENABLE_ACRYLICBLURBEHIND;
    break;
case Acrylic: backdrop = DWMSBT_TRANSIENTWINDOW; transparent = TRUE; break;
case Mica:    backdrop = DWMSBT_MAINWINDOW;      transparent = TRUE; break;
case MicaAlt: backdrop = DWMSBT_TABBEDWINDOW;    transparent = TRUE; break;
}
```

That means an independent experiment should not test "does `ApplyBackdrop` work?" It should log four separate facts: OS build, selected effect type, whether `SetWindowCompositionAttribute` exists, and which DWM attribute path was used. The smallest useful probe is a throwaway popup HWND with the same style bits as a menu/tooltip, then apply each effect type and record `DwmGetWindowAttribute(DWMWA_EXTENDED_FRAME_BOUNDS)` plus screenshot pixels at the center and border.

The drawing hook is separate. `TFMain/UxThemeHooks.cpp` hooks or call-site-patches `DrawThemeBackground` / `DrawThemeText` in the menu path, classifies `Menu` theme parts, and delegates real rendering to `MenuRendering`. `Prepare()` resolves `uxtheme.dll` private `CThemeMenuPopup::*` offsets through symbols and caches them by `UxThemeVersion`. This is why a source-derived test harness should have two phases: material application on a normal HWND, then menu rendering interception on a real `#32768` popup.

### What `ApplyBackdrop(hwnd)` Actually Contains

The decomposed call chain from the current source is:

```cpp
// MenuHandler.cpp / DropDownHandler.cpp / ToolTipHandler.cpp
QueryBackdropEffectContext(L"Menu", useDarkMode, ctx.backdropEffect);
QueryBorderContext(L"Menu", useDarkMode, ctx.border);
ApplyEffect(hwnd, useDarkMode, ctx.backdropEffect, ctx.border);
```

`ApplyEffect` in `TFMain/ApiEx.cpp` calls `ApplyBackdropEffect` and then `ApplyBorderEffect`. `ApplyBackdropEffect` sets the dark frame with `EnableWindowDarkMode`, converts the configured ARGB tint into the ABGR/COLORREF shape expected by the accent path, calls `SetWindowBackdrop`, and then calls `DwmTransitionOwnedWindow(hwnd, DWMTRANSITION_OWNEDWINDOW_REPOSITION)`. `ApplyBorderEffect` applies `DWMWA_WINDOW_CORNER_PREFERENCE` and `DWMWA_BORDER_COLOR` on Windows 11+ and also transitions the owned window.

`SetWindowBackdrop` in `TFMain/EffectHelper.hpp` is the material switch. It builds:

```cpp
ACCENT_POLICY accent = { ACCENT_DISABLED,
    dropShadow ? ACCENT_ENABLE_BORDER : ACCENT_NONE,
    tintColor,
    0 };
WINDOWCOMPOSITIONATTRIBUTEDATA data = {
    WCA_ACCENT_POLICY, &accent, sizeof(accent)
};
```

Then the effect enum selects the mechanism:

- `Solid`, `Transparent`, `Blur`, `AcrylicBlur`, and `ModernAcrylicBlur` use the private `SetWindowCompositionAttribute(WCA_ACCENT_POLICY)` route. `ModernAcrylicBlur` also sets `ACCENT_ENABLE_MODERN_ACRYLIC_RECIPE`.
- `Acrylic`, `Mica`, and `MicaAlt` set `DWMSBT_TRANSIENTWINDOW`, `DWMSBT_MAINWINDOW`, or `DWMSBT_TABBEDWINDOW`, enable non-client rendering, and call `DwmEnableBlurBehindWindow` with an empty region to make the HWND transparent to the compositor.
- build `22000 < build < 22621` uses the interim private Mica attribute `1029`; build `>= 22621` uses `DWMWA_SYSTEMBACKDROP_TYPE`.
- after a system-backdrop branch, `TriggerWindowNCRendering` sends `WM_NCACTIVATE` through `DefWindowProcW` and calls `SetWindowPos(... SWP_DRAWFRAME | SWP_NOACTIVATE)`.

The detach path is also part of the helper. `DropEffect(part, hwnd)` calls `SetWindowBackdrop(... None)`, resets Win11 corner and border attributes to defaults or menu defaults, then calls `InvalidateRect(hwnd, nullptr, TRUE)`. If a note only says "invalidate after applying backdrop," it is missing the more important observation: invalidation is also used after dropping the effect so stale non-client and client pixels disappear.

### Discussion Claim -> Probe

Claim: "legacy flyouts do not share one customization API." Source confirmation: `MenuHandler`, `DropDownHandler`, and `ToolTipHandler` all reach `ApplyEffect`, but their discovery and repaint paths differ. Probe it by logging attach/detach messages, HWND class, root HWND, and whether `ApplyEffect` or `DropEffect` ran. Interpretation: material policy is shared; HWND discovery is not.

Claim: "Win11 system backdrops are not equivalent to accent acrylic." Source confirmation: `EffectHelper::SetWindowBackdrop` has separate SWCA branches and DWM backdrop branches. Probe it with a small popup HWND and ETW/debug logs around `SetWindowCompositionAttribute`, `DwmSetWindowAttribute(1029)`, `DwmSetWindowAttribute(DWMWA_SYSTEMBACKDROP_TYPE)`, `DwmEnableBlurBehindWindow`, and `WM_NCACTIVATE`. Interpretation: if only SWCA fires, you are testing accent blur; if DWM backdrop and non-client refresh fire, you are testing the Win11 backdrop path.

Claim: "menu rendering and backdrop rendering are independent." Source confirmation: `UxThemeHooks.cpp` handles theme drawing hooks, while `ApiEx.cpp`/`EffectHelper.hpp` handle material. Probe it by applying `SetWindowBackdrop` to a normal owned popup without enabling UxTheme hooks, then enabling hooks on a real `#32768` menu. Interpretation: a blurred menu background without correct item rendering is expected; the renderer layer must still paint text, separators, icons, hot states, and check marks.

## References
- <https://github.com/ALTaleX531/TranslucentFlyouts>

## Connections
- `Acrylic Popup Menus.md` is the narrower HMENU popup route using `WH_CBT`.
- `Acrylic with DirectComposition.md` covers the backdrop/composition side once the target HWND is known.
- `../Hooks/MinHook - Minimal Hooking Library.md` is the function-interception primitive behind theme/drawing hooks.
- `../Common Controls/Visual Styles.md` explains the UxTheme drawing APIs being intercepted.
