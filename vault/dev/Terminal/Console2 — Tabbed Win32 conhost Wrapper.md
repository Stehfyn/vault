<!-- generated-from-dump2 -->
# Console2 — Tabbed Win32 conhost Wrapper

GitHub mirror of **Console2**, the long-running Windows-only console-window wrapper originally on SourceForge (Marko Bozikovic et al.). It hosts `cmd.exe` / PowerShell inside a tabbed Win32 host that adds features the real conhost.exe lacked for years: multiple tabs, alpha-blended/transparent window, configurable fonts including TTF in the console, true UNICODE on pre-Win10, drag-resize without console-buffer reflow, and copy-on-select. Implementation is C++/WTL + a `ConsoleHook` DLL that injects into the hosted shell to capture the screen buffer over a shared-memory protocol — predates ConPTY by a decade. Mostly historical now (Windows Terminal does this properly) but a useful read for how people screen-scraped conhost before Microsoft shipped a real API.

```text
# Architecture sketch:
#   Console2.exe (host window, tabs, transparency)
#       |
#       v  spawns
#   cmd.exe / powershell.exe (the hosted shell)
#       |
#       v  ConsoleHook.dll injected (CreateRemoteThread + LoadLibrary)
#   ConsoleHook hooks ReadConsoleOutput / WriteConsoleOutput, mirrors the
#   screen buffer into a named shared-memory section that Console2 paints.
```

## References
- <https://github.com/bozho/console>
