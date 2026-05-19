# afk-clicker — Unfocused Window Auto-Clicker

Auto-clicker that sends mouse/keyboard input into a *specific* unfocused window — that "unfocused" part is the technically interesting bit. `SendInput` always goes to the foreground; you have to use `PostMessage(WM_KEYDOWN/WM_LBUTTONDOWN)` directly against the target HWND (which works for some apps that read messages from their queue) or, for games that use raw input / DirectInput, you need to interpose at a lower level via a DLL injection. This project demonstrates the simpler `PostMessage` route.

## References
- <https://github.com/eHonnef/afk-clicker>
