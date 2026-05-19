# IME via Hook with Direct2D

`FullIME` is useful because it demonstrates the awkward boundary between Windows text input and custom-rendered UI. Traditional IME composition wants a focused HWND, caret rectangle, and message-driven edit control semantics; Direct2D/DirectWrite applications often own their text layout and need to display preedit/candidate state themselves.

The hook is a compatibility tactic, not the core idea. The real lesson is how to connect `WM_IME_*`/composition notifications, TSF-era expectations, and DirectWrite text rendering without falling back to an EDIT control. Pair this with `Mouse Input`, `InteractionContext.h`, and any custom-frame entry where non-client hit testing competes with input focus.

## References
- <https://github.com/fanlusky/FullIME>
