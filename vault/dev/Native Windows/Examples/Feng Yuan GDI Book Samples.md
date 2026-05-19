# Feng Yuan GDI Book Samples

Source for Feng Yuan's "Windows Graphics Programming: Win32 GDI and DirectDraw" (2000, Prentice Hall) — one of the few books that documents how the GDI/DDI bridge actually worked under the hood on NT4/2000. The samples are uniquely valuable because they exercise the raw HDC/DDI surfaces (battle-axe GDI internals: DDB vs DIB, palette engine, brush realization, path tracker), the DCI/DirectDraw paths that almost no modern codebase touches, and the printer DDI which has barely changed since.

```text
# Notable directories (paraphrased — see book chapter mapping)
Chapter04_GDI_Coords/      # mapping modes, world transform internals
Chapter06_GDI_DC/          # printer DC vs display DC, DC handle internals
Chapter08_Pixels_Bitmaps/  # DIB header layouts, BitBlt, StretchDIBits
Chapter10_BitmapAlgo/      # palette-realization tricks
Chapter11_Drawing/         # path tracker, region engine
Chapter15_DDRAW/           # DirectDraw blits, overlays (legacy)
```

## References
- <https://github.com/tpn/windows-graphics-programming-src>
