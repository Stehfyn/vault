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

## Source Code Reading

`ALTaleX531/dwm_colorization_calculator/main.py` is useful because it reverse-maps the user-facing color controls to the legacy DWM colorization parameters. The key classes are `hsb`, `argb`, `colorization_color`, and `dwm_colorization_parameters`. `colorization_color.from_hsb` performs the HSB-to-RGB sector math and stores intensity in alpha; `to_dwm_colorization_parameters` converts intensity into `color_balance`, `afterglow_balance`, and `blur_balance`; `convert_colorization_parameters_to_argb` reverses the legacy parameter structure into the public ARGB returned by DWM.

The detail to copy into probes is the balance mapping, not the UI script:

```python
# Source-shaped from main.py.
balance = int(((alpha / 255.0) - 0.1) / 0.75 * 100.0 + 10.0)
if opaque:
    afterglow_balance = 10
    color_balance = balance - afterglow_balance
    blur_balance = 100 - balance
elif balance < 50:
    color_balance = 5
    blur_balance = 100 - balance
    afterglow_balance = 100 - color_balance - blur_balance
else:
    blur_balance = 50 - ((balance - 50) >> 1)
    color_balance = 100 - afterglow_balance - blur_balance
```

Falsifiable path: call `DwmGetColorizationColor`, convert the returned ARGB through the script's `get_hsb_color`/`to_dwm_colorization_parameters` logic, then compare predicted active/inactive title-bar tint against sampled pixels from a standard-caption test window. If the HSB/balance math predicts the legacy color but not the visible title bar on Windows 11, the failure is not arithmetic; it is that modern backdrop/non-client policy is using a different material path.

## References
- https://raw.githubusercontent.com/ALTaleX531/dwm_colorization_calculator/main/main.py
- https://blog.csdn.net/liu__ke/article/details/8906289
- Related: `Title Bar Customization.md`, `DWM Internals Documentation.md`, `OpenGlass (Aero Blur Restoration).md`
