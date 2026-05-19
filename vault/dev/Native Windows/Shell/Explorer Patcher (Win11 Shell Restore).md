# Explorer Patcher (Win11 Shell Restore)

The reference reverse-engineering project for Windows 11's shell. It restores Win10-style behaviour (full taskbar, classic context menu, never-combine, Show Desktop button, Start menu layout, system tray icons, drag-drop onto taskbar) by injecting `ep_dwm.dll`/`ep_setup.exe` into `explorer.exe` and patching DWM/SHELL32/EXPLORERFRAME at runtime with hardcoded byte signatures per Windows build. Worth studying as a working example of how to do binary-version-resilient runtime patching of a shipping Microsoft binary: a giant per-build `signatures.h` of pattern → offset mappings, scanned at load and applied with `WriteProcessMemory`.

## References
- <https://github.com/valinet/ExplorerPatcher>
