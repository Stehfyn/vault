# IME via Hook with Direct2D

`FullIME` is useful because it demonstrates the awkward boundary between Windows text input and custom-rendered UI. Traditional IME composition wants a focused HWND, caret rectangle, and message-driven edit control semantics; Direct2D/DirectWrite applications often own their text layout and need to display preedit/candidate state themselves.

The hook is a compatibility tactic, not the core idea. The real lesson is how to connect `WM_IME_*`/composition notifications, TSF-era expectations, and DirectWrite text rendering without falling back to an EDIT control. Pair this with `Mouse Input`, `InteractionContext.h`, and any custom-frame entry where non-client hit testing competes with input focus.

## Source Shape

The custom renderer has to pull composition text from the IME context, then draw it at the app's caret location rather than letting an EDIT control own the UI.

```cpp
case WM_IME_COMPOSITION:
    if (lParam & GCS_COMPSTR) {
        HIMC imc = ImmGetContext(hwnd);
        LONG bytes = ImmGetCompositionStringW(imc, GCS_COMPSTR, nullptr, 0);
        std::wstring text(bytes / sizeof(wchar_t), L'\0');
        ImmGetCompositionStringW(imc, GCS_COMPSTR, text.data(), bytes);
        ImmReleaseContext(hwnd, imc);
        UpdateDirectWritePreedit(text);
    }
    break;

case WM_IME_ENDCOMPOSITION:
    ClearDirectWritePreedit();
    break;
```

## Source Code Reading

`fanlusky/FullIME` is not a small `WM_IME_COMPOSITION` sample. It is a global low-level keyboard hook feeding a custom Direct2D/DirectWrite candidate window.

`main.cpp` installs the hook and creates the candidate UI:

```cpp
HHOOK kbd = SetWindowsHookEx(WH_KEYBOARD_LL, &KBDHook, 0, 0);
RegisterClassEx(&winClass);              // class name "Direct2D"
gHwnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_TOPMOST |
                       WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE,
                       L"Direct2D", L"FullIME", WS_POPUP, ...);
CreateDWResource(gHwnd);
```

Those extended styles are the UI contract: the candidate window is topmost, layered, tool-window-hidden from the taskbar, and non-activating, so it can appear near text input without stealing focus.

`src/hook/ime_hook.cpp` defines `KBDHook`. It casts `lParam` to `KBDLLHOOKSTRUCT`, maps `vkCode` to a character with `MapVirtualKey`, reads modifier state using `GetAsyncKeyState`, and branches on control keys:

- `Ctrl+Space` toggles `IMEState` and returns `1` to consume the event.
- `Esc`, `Backspace`, and `Enter` manipulate the composition buffer when `charVec` is non-empty.
- alphabetic keys append to `charVec`, query SQLite-backed candidate lists, redraw the UI, and return `1`.
- keys outside the custom IME state fall through to `CallNextHookEx`.

`src/hook/key_handle_func_lib.cpp` owns the composition state transitions: `toggleIMEState`, `handleEsc`, `handleAlphaByChars`, `handleBackSpaceByChars`, and candidate query/update paths. This is the missing decomposition behind a vague `HandleIMEKey()` helper: mutate composition buffer, query candidates, update selected page, draw or hide the candidate UI, then decide whether the original key should continue down the hook chain.

`src/ui/cand_ui.cpp` owns the rendering path. `CreateDWResource` calls `DwmExtendFrameIntoClientArea`, creates a multi-threaded D2D factory, creates an `ID2D1HwndRenderTarget` with premultiplied alpha, creates a DWrite factory and text format, and stores the resources globally. `printOneDVector` formats the pinyin buffer plus numbered candidates and posts `WM_FANY_REDRAW`; `FanyDrawText` clears to transparent, creates an `IDWriteTextLayout`, fills a rounded rectangle, and calls `DrawTextLayout`.

The reader takeaway: the hook is only the input tap. The actual IME-like behavior is buffer state plus candidate lookup plus a non-activating layered HWND plus D2D/DWrite rendering plus explicit event consumption.

## References
- <https://github.com/fanlusky/FullIME>

## Connections
- `../Common Controls/Custom Controls.md` is the checklist for everything you inherit when you stop using EDIT.
- `InteractionContext.h - Pointer Gesture Interpreter.md` is the adjacent custom-surface input layer.
- `../Hooks/SetWindowsHookEx.md` explains the compatibility hook tactic; the durable design issue is still IME state ownership.
