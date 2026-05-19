# AFSM Start Menu Replacement

"Another Freaking Start Menu" — a Win11 start-menu replacement using a classic Win32 popup window (cf. Open-Shell, StartIsBack). Hooks the Win key via low-level keyboard hook, draws its own menu in `WS_POPUP` with `SetWindowPos(HWND_TOPMOST)`, and shells out to `ShellExecute` for app launches. Read this for the keyboard-hook + popup-show pattern, not for production-quality shell integration.

## References
- <https://github.com/Nazgul07/AFSM>
