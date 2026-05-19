# libvalinet - ExplorerPatcher Helpers

Header-only utility C shared across valinet projects, especially ExplorerPatcher. Its value is in the unglamorous mechanisms that make runtime shell patching maintainable: byte-pattern scanning for per-build offsets, small inline-hook helpers, resource/string utilities, registry-backed settings, and wrappers around common Win32 chores. It is not a general-purpose framework; it is support code for living inside Explorer's moving implementation.

Read it beside ExplorerPatcher, DWM/custom-frame notes, and shell-extension material. The through-line is practical version resilience: when Microsoft changes private shell code, a patcher survives by keeping signatures, hooks, feature flags, and rollback paths small and auditable.

Code contribution: the useful patterns are `GetProcAddress`/pattern-scan resolution, tiny hook wrappers, registry settings helpers, and rollback paths around private shell entry points.

## References
- <https://github.com/valinet/libvalinet> - reusable support library behind ExplorerPatcher-style shell patching.
