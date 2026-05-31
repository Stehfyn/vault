# Mica Backport for Windows 10

Back-ports the Win11 Mica material onto Windows 10 by re-implementing what `DwmExtendFrameIntoClientArea` + `DWMWA_SYSTEMBACKDROP_TYPE` would do — except those flags don't exist pre-22H2, so it falls back to the undocumented `SetWindowCompositionAttribute(ACCENT_ENABLE_HOSTBACKDROP)` path plus its own desktop-wallpaper-aware blur tint to fake the wallpaper-tinted look (cf. wangwenx190/Win32Acrylic #50, ALTaleX531/Win32Acrylic #14, Maplespe/DWMBlurGlass #54 which goes the other direction and rewrites DWM itself).

## References
- <https://github.com/ahmed605/10Mica>

## Source Code Reading

`ahmed605/10Mica` is a XAML composition brush that reconstructs Mica on older Windows builds. The relevant files are `TenMica/TenMicaBrush.cpp`, `TenMica/TenMicaBrush.h`, and `TenMica/DwmThumbnail.h`.

`TenMicaBrush::Init` resolves private DWM thumbnail exports by ordinal:

- `DwmpQueryThumbnailType`
- `DwmpCreateSharedThumbnailVisual`
- `DwmpQueryWindowThumbnailSourceSize`
- public `DwmUnregisterThumbnail`

It also detects whether the compositor supports `TryCreateBlurredWallpaperBackdropBrush`. If it does and fallback is enabled, the brush can hand off to the system method instead of emulating Mica.

The update path is the center:

```text
UpdateBrush()
  find target window and source size
  create or refresh DWM thumbnail visual
  choose system Mica, composition visual branch, or legacy DComp branch
  build effect brush
  cross-fade old brush to new brush
```

`BuildMicaEffectBrush` uses a compositor `Visual` source, tint color, tint opacity, luminosity opacity, and window size. `BuildMicaEffectBrushLegacy` accepts an `IDCompositionVisual2*` created from the DWM thumbnail. `UpdateVisual(RECT)` and event handlers keep the source in sync across activation, color values, high contrast, composition capability changes, energy saver, display changes, and internal window-position changes.

Cleanup is explicit: `OnDisconnected` removes event subscriptions and unregisters the DWM thumbnail. The README recommendation to use only one brush instance is grounded in that shared capture/invalidation machinery.

### Claim -> Probe

Claim from the README: Windows 10 can mimic Mica. Probe it by forcing `FallbackToSystemMica = false`, logging whether `DwmpCreateSharedThumbnailVisual` succeeds, and taking before/after screenshots while changing wallpaper or moving the window. Interpretation: if the source visual does not update on display/window events, you have a stale wallpaper sample, not real Mica.

Claim: "newer systems should use system Mica when available." Probe `ApiInformation::IsMethodPresent(Compositor, "TryCreateBlurredWallpaperBackdropBrush")` and compare brush creation paths. Interpretation: if that method exists, the emulation branch should be a fallback, not the default.
