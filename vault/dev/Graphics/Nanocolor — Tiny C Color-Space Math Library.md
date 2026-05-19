<!-- generated-from-dump2 -->
# Nanocolor — Tiny C Color-Space Math Library

Tiny C library (think stb-style, header-light) for color-space math — not a full ICC color-management engine like LittleCMS, just the matrix-and-curve transforms you actually need to move pixels between sRGB / Rec.709 / Rec.2020 / DCI-P3 / ACES2065-1 / ACEScg / Linear, with correct gamma encoding and white-point chromatic adaptation. Aimed at game/film tooling where you want to apply a color transform in a shader or in tooling code without dragging OCIO/OpenImageIO in. Encodes the standard primaries + EOTFs (sRGB piecewise, Rec.709 OETF, PQ, HLG, ACES) as compile-time constants. Useful read for "how do these color-space conversions actually compose" — most tutorials get gamma backwards somewhere.

```c
#include "nanocolor.h"

// Build a transform: sRGB display values -> ACEScg linear, ready for engine.
NcColorSpace src = nc_srgb_2_0();      // sRGB primaries + sRGB EOTF
NcColorSpace dst = nc_ap1_linear();    // ACES AP1 primaries + linear EOTF

NcTransform t = nc_color_transform(src, dst);

float in[3] = {0.5f, 0.5f, 0.5f};
float out[3];
nc_apply(&t, in, out);                  // out is now ACEScg linear ~ (0.18, 0.18, 0.18)
```

## References
- <https://github.com/meshula/Nanocolor>
