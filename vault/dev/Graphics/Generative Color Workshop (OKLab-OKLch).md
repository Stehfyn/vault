<!-- generated-from-dump2 -->
# Generative Color Workshop (OKLab/OKLch)

Matt DesLauriers' (canvas-sketch, glsl-noise) workshop materials on **perceptually-uniform color spaces** for generative art. The core lesson: HSL/HSV are convenient lies — they're cylindrical projections of RGB, not of human perception, so the same numeric "+10 lightness" change looks very different in the orange band vs. the blue band, and "evenly spaced hues" produce visually clumpy palettes. The fix is OKLab/OKLch (Björn Ottosson, 2020), CIE Lab, or LCh: interpolate, sample, and pick palette anchors in those spaces, then convert to sRGB only for output. Repo contains runnable JS demos for palette generation, palette interpolation, and accessibility (contrast in APCA / WCAG2). Worth working through if your generative output looks muddy regardless of which seed you pick.

```javascript
// Conceptual: generate a palette in OKLch (perceptually uniform), then convert.
import { oklch, formatHex, interpolate } from 'culori';

// 5 equally-spaced hues at the same lightness + chroma.
const stops = Array.from({length: 5}, (_, i) =>
  oklch({mode: 'oklch', l: 0.75, c: 0.18, h: (i * 360) / 5}));

const hexes = stops.map(formatHex);
// Smooth gradient between two anchors, perceptually linear:
const grad = interpolate(['oklch', stops[0], stops[2]], 'oklch');
for (let t = 0; t <= 1; t += 0.1) console.log(formatHex(grad(t)));
```

## References
- <https://github.com/mattdesl/workshop-generative-color>
