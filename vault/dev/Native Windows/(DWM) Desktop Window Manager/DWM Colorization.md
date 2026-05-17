# DWM Colorization

Query the current DWM colorization value with `DwmGetColorizationColor`; calculators explain how sliders map to ARGB values.

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
