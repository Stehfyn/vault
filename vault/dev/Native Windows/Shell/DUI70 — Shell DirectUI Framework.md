# DUI70 — Shell DirectUI Framework

Reverse-engineering notes and a partial reimplementation of `DUI70.dll`, the undocumented "DirectUI" framework Microsoft uses internally for Explorer's address bar, the modern File Open dialog, the Start menu's search results, and large chunks of the shell. DUI70 is interesting historically because it is essentially Microsoft's *internal* answer to the same problem that WPF/XAML solved publicly: declarative UI in a markup language (`.duix`/`.uix`), retained-mode element tree, layout/styling system, all running on top of GDI+ and DirectComposition. The shell team never shipped a public SDK for it, so the only way to learn it is by reading binaries — what this repo collects. Practical use: hooking DUI70 lets you restyle Explorer, modify the search results popup, or inject custom elements into shell surfaces without rewriting them. The catch is that DUI70's ABI is unstable across Windows versions (the vtables for `DirectUI::Element` shift between 10.0.19041 and 10.0.22621), so any hook needs version-keyed offsets. (cf. ALTaleX531/OpenGlass and Maplespe/DWMBlurGlass for similar shell-internals RE work.)

## References
- <https://github.com/seven-mile/dui70>

## Connections
- `Explorer Patcher (Win11 Shell Restore).md` and `../libvalinet - ExplorerPatcher Helpers.md` show the same unsupported-shell territory from the runtime patching side.
- `../Common Controls/DUIThink (DirectUI Framework).md` is the public/reimplementation-adjacent DirectUI study note; read it before assuming DUI70 behaves like normal HWND controls.
- `Visual Style (msstyles) Editor.md` and `../Custom Frame/Immersive Context Menu (Explorer Look-Alike).md` are adjacent when the goal is shell appearance rather than shell behavior.

## Experiment Harness

Goal: observe DirectUI presence without depending on unstable private vtables.

Procedure:
1. Enumerate loaded modules in Explorer and confirm `dui70.dll` version/path.
2. Use UI Automation or Spy++-style HWND inspection to map the outer shell HWNDs.
3. Compare visible element changes after theme/DPI/search interactions.
4. Keep private symbol/vtable assumptions in a separate, version-keyed report.

Measured signal: module version, shell surface under test, UIA tree deltas, Windows build.

Failure interpretation: if UIA/HWND observation is enough, avoid private DUI hooks; if not, the hook must be build-gated like ExplorerPatcher signatures.
