# Mouse Input

Classic Win32 mouse input is HWND-relative message delivery, not a device stream. `WM_MOUSEMOVE`, button messages, capture, hit testing, and coordinate conversion are all tied to the thread's message queue and the target window; `GetCursorPos` gives screen coordinates, while `ScreenToClient` maps them into the client area that rendering code actually uses.

The distinction matters when mixing old and new input paths. Raw Input can report hardware packets while unfocused, `SendInput` targets the foreground queue, `PostMessage` can fake messages only for controls that trust their queue, and `InteractionContext` consumes pointer frames to synthesize gestures. This page is the baseline for those comparisons.

## References
- <https://web.archive.org/web/20070123100817/http://msdn.microsoft.com/library/en-us/winui/winui/windowsuserinterface/userinput/mouseinput/aboutmouseinput.asp>
