<!-- generated-from-dump2 -->
# PowerToys — Modern Windows Utility Suite

Modern revival of the Win95-era PowerToys; the most important real-world C#/WinUI 3 codebase on GitHub. Notable modules (each is its own subproject, useful read in isolation): **FancyZones** (real implementation of window-grid snapping via a low-level mouse hook plus `SetWindowPos`), **PowerToys Run** (Spotlight-like launcher; plugin architecture), **PowerRename** (regex bulk rename driven by `IShellExtInit`+`IContextMenu` so it shows in Explorer's right-click), **Color Picker** (full-screen overlay with cursor-tracked color sampling via `GetDC(0)`), **Image Resizer** (shell extension demonstrating modern PRT — `IExplorerCommand`), **PowerToys Awake** (suppresses sleep via `SetThreadExecutionState`), **Keyboard Manager** (low-level keyboard hook + remap engine), **Mouse without Borders** (KM/M sharing across LAN). The repo is a working reference for nearly every Win32-from-modern-C# pattern.

```csharp
// Flavour: FancyZones-style window placement. PowerToys exposes wrappers,
// but underneath every snap is a SetWindowPos with a precomputed rect.
[DllImport("user32.dll")] static extern bool SetWindowPos(
    IntPtr hWnd, IntPtr hWndInsertAfter, int X, int Y, int cx, int cy, uint uFlags);

// Snap the foreground window into a zone (px coords).
var hwnd = GetForegroundWindow();
SetWindowPos(hwnd, IntPtr.Zero,
             zone.Left, zone.Top, zone.Width, zone.Height,
             0x0040 /*SWP_SHOWWINDOW*/ | 0x0004 /*SWP_NOZORDER*/);
```

## References
- <https://github.com/microsoft/PowerToys>
