# DUIThink (DirectUI Framework)

DUIThink sits in the DirectUI/DuiLib lineage: one real HWND hosts a tree of logical, non-windowed controls described by XML and painted by the framework. The upside is obvious for skinned apps: no child-window z-order fights, cheap layout trees, and theme changes that are mostly resource swaps. This is why similar ideas appeared in shell UI and many Chinese Win32 skinning frameworks.

The cost is that USER32 no longer gives you much for free. Focus navigation, IME, accessibility, hit testing, capture, invalidation, and Per-Monitor DPI behavior become framework responsibilities. DUIThink is therefore best read as a full UI framework trade study, not as a normal common-control wrapper.

## References
- <https://github.com/miaomiaoyule/DUIThink> - XML-driven DirectUI-style Win32 framework.

## Connections
- `Custom Controls.md` is the HWND-based alternative.
- `Rendering.md` covers the lower-level paint mechanics that DirectUI frameworks centralize.
