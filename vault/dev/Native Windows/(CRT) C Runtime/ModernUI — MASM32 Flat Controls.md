# ModernUI — MASM32 Flat Controls Framework

ModernUI is a MASM32 framework for flat, owner-drawn Win32 controls: buttons, checkboxes, caption bars, progress indicators, smart panels, tooltip/tray helpers, and related RadASM design-time metadata. The interesting part is not that it looks "modern"; it is that it keeps the entire GUI stack in hand-written assembly, avoiding both the CRT and most common-control theming assumptions.

That makes it a useful companion to no-CRT and assembly entries. It shows the other half of tiny-native Windows work: once you skip framework layers, every control class, message handler, font, DPI adjustment, invalidation region, and GDI object lifetime is yours. It is closer to DirectUI-style skinning than to normal `comctl32` composition, but with MASM rather than C++.

## Connections
- `win32asm` covers the low-level calling and import mechanics this framework builds on.
- `Cpl.h`, `commdlg.h`, and `dcomp.h` show adjacent Win32 UI surfaces with very different levels of abstraction.

## References
- <https://github.com/mrfearless/ModernUI>
