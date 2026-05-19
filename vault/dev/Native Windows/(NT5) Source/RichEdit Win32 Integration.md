# RichEdit Win32 Integration

The NT5 RichEdit `w32win32.cpp` file is useful because RichEdit is not a plain edit control with more features. It owns complex Win32 integration points: window creation, style translation, notification dispatch, IME, text services, scrolling, selection rendering, and compatibility with old `RICHEDIT_CLASS` callers. That makes it a good specimen for how heavyweight controls sit on top of the message system without becoming ordinary top-level windows.

Modern code usually loads `Msftedit.dll` and creates `MSFTEDIT_CLASS`, but the integration problems are the same: the host talks through messages, notifications, styles, and subclassing while the control maintains a much richer internal document model. The source is most useful for understanding where control behavior is window-manager contract and where it is RichEdit-specific policy.

## Connections
- `Winuser Header` defines the public messages and styles used by controls.
- `NT User Message Definitions` explains why controls reserve `WM_USER` ranges for their own protocol.

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/richedit/re41/w32win32.cpp#L5212
