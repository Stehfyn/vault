<!-- generated-from-dump2 -->
# pywin32doc — Browsable pywin32 Reference

Community-mirrored, web-browsable port of the pywin32 help (.chm) into per-module HTML/Markdown, because mhammond/pywin32 (#71) ships its docs as a Windows-only compiled HTML help file that nobody can grep on Linux/macOS or link to from a bug report. Useful precisely because the upstream API surface is enormous (every `win32api`/`win32gui`/`win32com` symbol has a CHM page nobody reads); having it indexed by Google turns "what's the signature of `win32gui.SendMessageTimeout`?" into a search instead of a CHM hunt.

```python
# The docs in this repo describe signatures like:
#   win32gui.SendMessageTimeout(hWnd, Msg, wParam, lParam, fuFlags, uTimeout)
import win32gui, win32con
result = win32gui.SendMessageTimeout(
    win32con.HWND_BROADCAST, win32con.WM_SETTINGCHANGE,
    0, "Environment", win32con.SMTO_ABORTIFHUNG, 1000)
```

## References
- <https://github.com/wuxc/pywin32doc>
