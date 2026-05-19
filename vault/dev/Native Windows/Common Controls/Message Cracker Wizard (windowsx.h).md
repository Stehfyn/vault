# Message Cracker Wizard (windowsx.h)

`windowsx.h` message crackers are the old Petzold-era answer to unreadable `WPARAM`/`LPARAM` unpacking. `HANDLE_MSG(hwnd, WM_COMMAND, OnCommand)` dispatches to typed handlers such as `OnCommand(HWND, int id, HWND ctl, UINT code)`, so the call site documents the message contract and avoids repeated `LOWORD`/`HIWORD` mistakes. The wizard generates those handler stubs.

This is not magic and not a framework; it is a disciplined switch statement. It is still useful in C or C-style Win32 code where introducing WTL/MFC is too heavy but raw message decoding is producing bugs. The main limitation is that it helps with dispatch shape, not lifetime, ownership, or async message ordering.

## References
- <https://github.com/hernandp/MessageCrackerWizard> - generator for `windowsx.h` HANDLE_MSG handlers.

## Connections
- `Window Messaging.md` covers the queue and delivery model under those messages.
