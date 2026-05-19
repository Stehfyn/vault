<!-- generated-from-dump2 -->
# sioyek — PDF Reader for Technical Papers

PDF reader purpose-built for technical reading: textbooks and research papers. Standout features other readers don't ship: smart click-through on intra-document references (clicking a "(Eq. 3.7)" reference jumps to the equation and shows it in a popup, so you keep your place), a portal/picture-in-picture that pins a referenced figure or equation in a small floating window while you scroll, a built-in command palette (vim-style), and a persistent index of every PDF you've opened with cross-document linking. Written in C++ atop Qt + MuPDF. Keyboard-driven by default; the cognitive model is closer to Emacs/Vim than Acrobat.

```text
# Representative config (prefs.config) — these are the actual knobs:
"toggle_dark_mode"            "F10"
"open_link"                   "f"
"smart_jump_under_cursor"     "j"     # follow citation/eq reference
"portal"                      "p"     # pin a region as a floating window
"show_options"                "<C-,>"
```

## References
- <https://github.com/ahrm/sioyek>
