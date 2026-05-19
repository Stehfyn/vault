# Snap Layout API

There is no public Win32 API that says "show Snap Layouts for this window now" or "snap this HWND into layout slot X." Snap Layouts are shell/DWM policy layered on top of ordinary top-level window semantics. Your job as an app is to remain eligible: expose a real caption/maximize hit target via `WM_NCHITTEST`, keep sane `WS_OVERLAPPEDWINDOW`/maximize styles where possible, and do not replace the whole frame with a popup unless you are prepared to reimplement the non-client contract.

The StackOverflow answer matters because it prevents a common dead end: automation can fake Win+Z, but that is not an API contract and will break under focus, language, shell, or accessibility differences. This note belongs beside `No Title Bar Window.md` because custom chrome is the usual reason Snap Layouts disappear.

## References
- https://stackoverflow.com/questions/77523400/is-there-an-api-to-programmatically-invoke-snap-layout
- Related: `No Title Bar Window.md`, `Title Bar Customization.md`
