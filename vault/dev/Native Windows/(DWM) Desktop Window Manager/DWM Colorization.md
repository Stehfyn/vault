# DWM Colorization

`DwmGetColorizationColor` returns the accent/colorization value that DWM uses for legacy glass tinting and some non-client metrics, not a complete theme description. The returned `DWORD` is ARGB, while `pfOpaqueBlend` tells you whether DWM is treating the color as an opaque blend rather than translucent glass. On Windows 10/11 this is mostly a compatibility surface: modern Mica/Acrylic/backdrop policy is driven by `DwmSetWindowAttribute` and undocumented accent policy paths, but the colorization value still matters for custom title bars that want to match system chrome instead of hard-coding an accent color.

The calculator script is useful because Windows stores user-facing color sliders in a different space than the final ARGB value. If a note only says "query the color", it misses the actual trap: matching DWM's title-bar tint means reproducing the blend math, not just reading an RGB tuple.

## Snippet
```c
DWORD color = 0;
BOOL opaque = FALSE;
if (SUCCEEDED(DwmGetColorizationColor(&color, &opaque)))
{
    // color is ARGB
}
```

## References
- https://raw.githubusercontent.com/ALTaleX531/dwm_colorization_calculator/main/main.py
- https://blog.csdn.net/liu__ke/article/details/8906289
- Related: `Title Bar Customization.md`, `DWM Internals Documentation.md`, `OpenGlass (Aero Blur Restoration).md`
