<!-- generated-from-dump2 -->
# CLIPasso — Semantic Bezier Sketching

Yael Vinker et al's "CLIPasso: Semantically-Aware Object Sketching" (SIGGRAPH 2022) - given a photo, produce a minimal abstract Bezier-curve sketch (a few dozen strokes) that still matches the image semantically. The clever trick: parametrize the sketch as a small set of Bezier curves, render it differentiably to an image, push the image through CLIP, and minimize the CLIP-embedding distance to the original photo. Number of curves is a controllable abstraction knob (8 strokes = Picasso-style, 64 = realistic outline).

```text
# Conceptual training-time loop per image (paraphrased from the paper):
#   1. Initialize K Bezier curves at salient image points (CLIP saliency).
#   2. For T iterations:
#       a) Render strokes -> sketch image via diffvg.
#       b) z_photo = CLIP(image),  z_sketch = CLIP(sketch).
#       c) Loss  = 1 - cos(z_photo, z_sketch) + lambda * geometric_loss
#       d) Backprop into the curve control points; Adam step.
#   3. Output the final stroke set as SVG.
```

## References
- <https://github.com/yael-vinker/CLIPasso>
