# WindowCustomizer - Cross-Process Window Mutator

WindowCustomizer is essentially Spy++ with mutation: inspect another process's top-level windows and change selected properties such as title text or styles through USER32-mediated calls. The interesting nuance is that some window-manager state is intentionally cross-process addressable through HWNDs; not every customization requires injection.

Use it beside `WinHier`, `WindowDetective`, and `Windows Explorer Integration`. It is valuable for debugging window ownership, styles, z-order, and operator labeling workflows, while also reminding you that HWNDs are capabilities of a sort and should not be treated as private object references.

## References
- <https://github.com/mikeage/WindowCustomizer>
