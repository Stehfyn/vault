<!-- generated-from-dump2 -->
# Front-End Performance Checklist

Curated checklist of front-end performance optimizations, grouped from "must do" -> "should do" -> "nice to have": HTML/CSS hygiene, JS bundling/loading, image formats, font loading, third-party scripts, network/HTTP, build pipeline, monitoring. Each item links to a measurement or article justifying it. Pairs well with WebPageTest and Lighthouse - use it as the "what to fix" reference after the tools have told you "something's slow."

```text
# Top-level structure (paraphrased):
1. HTML            - minify, defer non-essential <script>, preload, preconnect
2. CSS             - critical CSS inline, defer rest, avoid @import chains
3. Fonts           - subset, woff2, font-display: swap, self-host
4. Images          - srcset + sizes, WebP/AVIF, lazy-load below the fold
5. JavaScript      - tree-shake, code-split per route, defer/async
6. Server / CDN    - HTTP/2 or 3, Brotli, cache headers, edge cache
7. Build & monitor - bundlesize budgets, Lighthouse CI, RUM via web-vitals
```

## References
- <https://github.com/thedaviddias/Front-End-Performance-Checklist>
