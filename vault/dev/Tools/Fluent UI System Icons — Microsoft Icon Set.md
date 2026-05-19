<!-- generated-from-dump2 -->
# Fluent UI System Icons — Microsoft Icon Set

Microsoft's open-source icon set (MIT) — the actual icons used across Windows 11, Office, Teams, and Microsoft 365. ~3000 glyphs, every glyph in two styles (**regular** = outline, **filled** = solid), every glyph in five pixel-target sizes (16/20/24/28/32/48 px) drawn separately rather than scaled — important because at 16 px you simplify away detail that's necessary at 48 px. Distributed in (a) raw SVGs, (b) per-platform font packs (`FluentSystemIcons-Regular.ttf` / `-Filled.ttf` with PUA codepoint mapping), and (c) per-framework wrappers — React (`@fluentui/react-icons`), Android (Compose + XML), iOS, WPF. The pixel-targeted-not-scaled approach is the unusual part vs Material/Heroicons.

```html
<!-- Three ways to use the same icon -->

<!-- 1. Raw SVG -->
<img src="ic_fluent_alert_24_regular.svg" width="24" height="24">

<!-- 2. Web font (PUA codepoint) -->
<link rel="stylesheet" href="FluentSystemIcons-Regular.css">
<i class="ms-Icon ms-Icon--alert"></i>

<!-- 3. React component (auto-tree-shakes) -->
<script type="module">
  import { Alert24Regular } from '@fluentui/react-icons';
  // <Alert24Regular />  in JSX
</script>
```

## References
- <https://github.com/microsoft/fluentui-system-icons>
