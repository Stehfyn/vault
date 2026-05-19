# Edit Clipboard Contents — Per-Format Clipboard Editor

Utility that exposes the full Windows clipboard - every format, simultaneously - and lets you view, edit, or delete individual items. Useful because the Windows clipboard is actually a list of typed payloads (text, HTML, BITMAP, CF_DIB, file drop list, proprietary app formats like "Excel Range") not a single string; most tools only show one. The unusual capability is per-format deletion, which the OS clipboard API technically supports via `OpenClipboard` + `EmptyClipboard` + reapply, but no shipping tool exposes.

## References
- <https://github.com/ThioJoe/Edit-Clipboard-Contents>
