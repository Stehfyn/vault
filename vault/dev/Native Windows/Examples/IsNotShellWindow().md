# IsNotShellWindow()

This note is about filtering ordinary application windows from shell-owned or infrastructure windows during HWND enumeration. The practical problem appears in task switchers, window pickers, screenshot tools, tilers, and automation utilities: not every visible top-level HWND is a user document or app window.

Good filters combine ownership, styles, cloaking, tool-window flags, shell window handles, visibility, and sometimes process identity. Connect this to `WinHier`, `WindowDetective`, `WindowCustomizer`, and `Windows Explorer Integration`; all of them need a defensible model of what counts as an app window.

## References
- Local snippet source retained in previous revision of this note.
