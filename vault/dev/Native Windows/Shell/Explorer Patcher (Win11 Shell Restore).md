# Explorer Patcher (Win11 Shell Restore)

The reference reverse-engineering project for Windows 11's shell. It restores Win10-style behaviour (full taskbar, classic context menu, never-combine, Show Desktop button, Start menu layout, system tray icons, drag-drop onto taskbar) by injecting `ep_dwm.dll`/`ep_setup.exe` into `explorer.exe` and patching DWM/SHELL32/EXPLORERFRAME at runtime with hardcoded byte signatures per Windows build. Worth studying as a working example of how to do binary-version-resilient runtime patching of a shipping Microsoft binary: a giant per-build `signatures.h` of pattern → offset mappings, scanned at load and applied with `WriteProcessMemory`.

## References
- <https://github.com/valinet/ExplorerPatcher>

## Connections
- `../libvalinet - ExplorerPatcher Helpers.md` extracts reusable helper code from the same ecosystem.
- `DUI70 — Shell DirectUI Framework.md` and `../(DWM) Desktop Window Manager/DWM Internals Documentation.md` explain the shell/DWM internals this project patches around.
- `Classic Explorer Search Box Restore.md`, `Open-Shell Classic Start Menu.md`, and `Visual Style (msstyles) Editor.md` are lower-risk neighboring references when the objective is UX restoration instead of binary patching.

## Experiment Harness

Goal: turn private-shell patching from folklore into a build-gated compatibility check.

Procedure:
1. Read `explorer.exe`, `shell32.dll`, and `explorerframe.dll` versions.
2. Dry-run every signature against copied module bytes.
3. Require exactly one match per required signature.
4. Emit a JSON report: build, module path, signature name, match count, RVA.

Measured signal: unique match count and expected module version per feature.

Failure interpretation: a feature should be disabled when signatures are absent or ambiguous; user-visible toggles must not imply the patch is viable on that Windows build.
