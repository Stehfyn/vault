<!-- generated-from-dump2 -->
# obamify — Gradient-Domain Image Style Transfer Joke

Joke pixel-shader project from the Spu7Nix YouTube channel: takes any input image and stylizes it toward a portrait of Barack Obama using a clever combination of GLSL displacement and color-mapping. Useful only as a meme; included because the technique behind it (gradient-domain image-to-image style transfer without an actual neural net) is a fun trick.

```text
# Conceptual approach (see project for details):
#   1. Convert input + reference (Obama) to grayscale gradients.
#   2. For each pixel, find the local region in the reference whose gradient
#      direction best matches the input's gradient.
#   3. Copy the reference's color into the output at that pixel.
#   4. Smooth via Poisson reconstruction so the result looks coherent.
```

## References
- <https://github.com/Spu7Nix/obamify>
