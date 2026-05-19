<!-- generated-from-dump2 -->
# MathMap — JIT-Compiled Image-Processing DSL

Mark Probst's MathMap - an image-processing DSL and GIMP plugin from the early 2000s, still maintained sporadically. You write a per-pixel expression in a tiny C-like language (`m=xy/r; rgba(noise([m,r]), ...)`) and MathMap JITs it to native code (originally via a custom IR + libjit, later via LLVM) so the per-pixel kernel runs in tight loops. Predates `fragment.glsl` as a casual artist tool by years; many demoscene/glitch-art effects of the era started in MathMap.

```text
filter spiral (image in, float radius: 0-500 (100))
    p = xy;
    r = sqrt(p[0]*p[0] + p[1]*p[1]);
    a = atan2(p[1], p[0]) + r/radius;
    in(r*[cos(a), sin(a)])
end
# Renders a spiral warp of the input image; the function body is JIT-compiled
# once per filter invocation, then run on every pixel.
```

## References
- <https://github.com/schani/mathmap>
