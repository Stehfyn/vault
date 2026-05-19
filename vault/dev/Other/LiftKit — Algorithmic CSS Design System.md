<!-- generated-from-dump2 -->
# LiftKit — Algorithmic CSS Design System

A CSS+TypeScript design system that ships scaling, spacing, and color as algorithmic formulas rather than fixed tokens — the pitch is "a UI framework that makes you a better designer without even realizing it." Currently bound to Next.js but the formula layer is framework-agnostic. The repo's own README admits it was "developed by a designer without consulting professional developers" and is mid-rewrite to wrap Base UI primitives, so the value here is the formulas (golden-ratio type scale, optical-symmetry spacing) more than the component implementations.

```css
/* Spacing/typography use ratio-based scale variables rather than fixed pixels,
   so a single root unit cascades into a coherent rhythm. (Real names are
   defined in src/styles/*.css; this is the pattern, not the literal API.) */
:root {
  --lk-scale-ratio: 1.618; /* phi */
  --lk-size-md: 1rem;
  --lk-size-lg: calc(var(--lk-size-md) * var(--lk-scale-ratio));
  --lk-size-xl: calc(var(--lk-size-lg) * var(--lk-scale-ratio));
}
```

## References
- <https://github.com/Chainlift/liftkit>
