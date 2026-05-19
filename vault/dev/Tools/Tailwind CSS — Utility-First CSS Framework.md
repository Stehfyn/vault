<!-- generated-from-dump2 -->
# Tailwind CSS — Utility-First CSS Framework

Tailwind CSS - the utility-first CSS framework. Notable as a build artifact: the JIT engine scans your template files (HTML, JSX, TSX, Vue, etc.) for class-name strings, generates only the CSS rules you actually used, and tree-shakes everything else. The interesting architectural decision is that the framework is implemented as a PostCSS plugin + custom AST tooling rather than a runtime, so the cost is moved to build-time.

```bash
# Standalone CLI (no Node toolchain required):
$ tailwindcss -i ./src/input.css -o ./dist/output.css --watch
```
```html
<!-- input.css generates rules for classes seen in this file -->
<div class="flex items-center gap-4 p-6 rounded-2xl shadow-md
            hover:shadow-lg transition">
  <img src="..." class="size-12 rounded-full"/>
  <p class="text-sm font-medium text-slate-700">Hello, Tailwind.</p>
</div>
```

## References
- <https://github.com/tailwindlabs/tailwindcss>
