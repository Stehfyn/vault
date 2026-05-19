<!-- generated-from-dump2 -->
# Windows Terminal and OpenConsole

The combined repo for **Windows Terminal** (the modern WinUI 3 tabbed terminal) and **OpenConsole** (the legacy `conhost.exe` that hosts a console session — open-sourced after decades of being closed). The high-value engineering pieces to read: **ConPTY** (`ConhostV2/ConPTY/`), the pseudo-terminal layer Microsoft added in 2018 that finally let a third-party terminal speak VT directly to `cmd.exe`/PowerShell without screen-scraping conhost; the **AtlasEngine** renderer (DirectWrite + D3D11, the "fast text" rewrite after Casey Muratori's `termbench` made the original DxEngine look ridiculous); the **Cascadia Code** ligature handling pipeline; and **DECRQM/DSR** style query handling for terminal capability detection. Buildable in Visual Studio with the right SDKs — non-trivial setup but the bar to drop into the codebase is reasonable.

```text
# Repo layout highlights (relative to /src):
#   cascadia/             - WinUI 3 frontend (Windows Terminal itself)
#   host/                 - conhost (the classic Win32 console host, now open)
#   renderer/atlas/       - AtlasEngine: DirectWrite + D3D11 text renderer
#   terminal/             - parser, VT state machine, buffer model
#   ConPTY/               - the pseudo-console subsystem
#   inc/til/              - terminal-internal-libraries (small helpers, color)
#
# Notable build artifact: ConPTY exposes
#   HRESULT CreatePseudoConsole(COORD size, HANDLE in, HANDLE out,
#                               DWORD flags, HPCON* pcon);
# which third-party terminals (Windows Terminal itself, but also Tabby,
# Alacritty-win, ConEmu, fluent-terminal) all use to host the user's shell.
```

## References
- <https://github.com/microsoft/terminal>
