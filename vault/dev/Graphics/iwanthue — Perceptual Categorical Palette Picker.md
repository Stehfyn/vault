<!-- generated-from-dump2 -->
# iwanthue — Perceptual Categorical Palette Picker

Web tool + JS library from Sciences Po médialab for picking categorical color palettes that are actually distinguishable on a chart with many series. The technique: sample candidate colors in **CIE Lab** (perceptual color space, where Euclidean distance correlates with perceived difference), filter by a quality criterion (color-blindness friendly, "pleasant," etc.), then run **k-means** to find the most-spread-out cluster of size N. The result is far better than `hcl_palette(n=20)` or, much worse, naïve hue-spacing in HSL — the standard failure of which is putting two greens and two greys in the same palette without realizing it. Used by Gephi, Sigma.js, and many academic data viz workflows.

```javascript
import iwanthue from 'iwanthue';

// 8 categorical colors optimized for perceptual distinguishability
const palette = iwanthue(8);          // -> array of hex strings, e.g. "#e26a5b"

// Constrained: avoid pastels, target color-blind safe
const safePalette = iwanthue(8, {
  colorSpace: 'colorblind',           // also: 'fancy-light', 'fancy-dark', 'pastel', ...
  quality: 50,                        // higher = more k-means iterations
  attempts: 3,
});
```

## References
- <https://github.com/medialab/iwanthue>
