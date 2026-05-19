# Ghost Window Prevention

`DisableProcessWindowsGhosting` turns off the USER32 fallback that paints a "ghost" window when a GUI thread stops pumping messages. It is a blunt diagnostic switch: useful for tools that would rather expose a hung UI honestly than let Windows synthesize a fake responsive frame.

Do not confuse it with fixing responsiveness. The real cure is keeping the UI thread out of blocking work, which connects this entry to `Threaded Message Queue`, service-control handlers, and long-running shell extensions. Use the API when ghosting itself corrupts a repro or debugger session.

## References
- <https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-disableprocesswindowsghosting>
