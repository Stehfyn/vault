# Modify Context Menu

The gist demonstrates a narrow but useful hack: when a stock control shows its default context menu, install a same-thread `SetWinEventHook` for `EVENT_SYSTEM_MENUPOPUPSTART`, obtain the live `HMENU` from the menu window using the undocumented `MN_GETHMENU`, then insert, disable, or delete menu items before it is displayed. This targets menus you do not otherwise own, such as the default Edit control menu.

The fragility is the point. If you own the menu, build it yourself in `WM_CONTEXTMENU`. If you only subclass the control and need to surgically alter the system-provided menu, this technique works because it intercepts the popup at creation time. Keep the hook lifetime short and same-thread to avoid broad accessibility-event side effects.

## Source Shape

The route is event hook, menu-window callback, `MN_GETHMENU`, then ordinary menu mutation.

```cpp
constexpr UINT MN_GETHMENU = 0x01E1;

void CALLBACK OnMenuPopup(HWINEVENTHOOK, DWORD event, HWND menu_hwnd,
                          LONG, LONG, DWORD, DWORD) {
    if (event != EVENT_SYSTEM_MENUPOPUPSTART) {
        return;
    }

    HMENU menu = reinterpret_cast<HMENU>(
        SendMessageW(menu_hwnd, MN_GETHMENU, 0, 0));
    InsertMenuW(menu, 0, MF_BYPOSITION | MF_STRING, ID_EXTRA, L"Extra");
}

HWINEVENTHOOK hook = SetWinEventHook(EVENT_SYSTEM_MENUPOPUPSTART,
    EVENT_SYSTEM_MENUPOPUPSTART, nullptr, OnMenuPopup,
    GetCurrentProcessId(), GetCurrentThreadId(), WINEVENT_OUTOFCONTEXT);
```

Unhook as soon as the menu has been handled; broad WinEvent hooks are the wrong default for a one-popup edit.

## Source Code Reading

The gist is small enough that the ordering matters more than the API names. In `WM_CREATE`, it creates an `Edit` child and subclasses that child with `SetWindowSubclass(hEdit, EditorProc, 0, 0)`. The edit control still owns its default context menu; the subclass only intercepts the moment before the default handler displays it.

`EditorProc` handles `WM_CONTEXTMENU` like this:

```cpp
hHook = SetWinEventHook(EVENT_SYSTEM_MENUPOPUPSTART,
                        EVENT_SYSTEM_MENUPOPUPSTART,
                        0, WinEventProc,
                        GetCurrentProcessId(),
                        GetCurrentThreadId(), 0);
DefSubclassProc(hEditor, WM_CONTEXTMENU, wParam, lParam);
UnhookWinEvent(hHook);
```

That is the core trick: install a same-process, same-thread WinEvent hook only around the call to the edit control's default context-menu logic. The hook observes the transient menu window created by USER/comctl32.

`WinEventProc` receives the menu window HWND, sends the undocumented `MN_GETHMENU` message, and then uses normal menu APIs:

```cpp
HMENU menu = (HMENU)SendMessage(hwndMenu, MN_GETHMENU, 0, 0);
InsertMenu(menu, 0, MF_BYPOSITION | MF_CHECKED, ID_TEST, "Test");
EnableMenuItem(menu, WM_PASTE, MF_GRAYED);
DeleteMenu(menu, WM_CUT, 0);
```

Falsifiable claims:

- Spy++ should show an `EVENT_SYSTEM_MENUPOPUPSTART`-adjacent popup/menu window when the edit context menu opens.
- If `DefSubclassProc` is not called while the hook is installed, the default edit menu is never created and `WinEventProc` has nothing to mutate.
- If `UnhookWinEvent` is omitted, later menus on the same thread can be unintentionally modified.
- If `MN_GETHMENU` changes or stops working on a future build, `SendMessage` will not yield a usable `HMENU`; the fallback is to own `WM_CONTEXTMENU` and build the menu yourself.

## Verification Route

Claim: the gist works because the edit control's default context-menu path creates a real menu window during `DefSubclassProc(WM_CONTEXTMENU)`, and the scoped WinEvent hook sees that transient window soon enough to ask it for `HMENU`.

Why it matters for new code: this is a tactical compatibility patch, not a menu framework. If the menu is yours, build it. If the menu is USER/comctl32-owned, the only maintainable version of this trick is narrow, same-thread, and instrumented so future Windows changes fail visibly.

How to verify:

- In Spy++, watch for the popup menu window while right-clicking the edit control.
- Add logging before `SetWinEventHook`, inside `WinEventProc`, around `MN_GETHMENU`, and after `UnhookWinEvent`.
- Remove the call to `DefSubclassProc` and confirm the callback never receives the menu to mutate.
- Assert that the returned `HMENU` passes a cheap sanity check such as `GetMenuItemCount(menu) >= 0` before modifying it.

Minimal code/pseudocode:

```cpp
case WM_CONTEXTMENU:
    hook = SetWinEventHook(EVENT_SYSTEM_MENUPOPUPSTART,
                           EVENT_SYSTEM_MENUPOPUPSTART,
                           nullptr, OnMenu, pid, tid, WINEVENT_OUTOFCONTEXT);
    DefSubclassProc(hwndEdit, msg, wParam, lParam); // creates default menu
    UnhookWinEvent(hook);
    return 0;

OnMenu(hwndMenu):
    menu = (HMENU)SendMessageW(hwndMenu, MN_GETHMENU, 0, 0);
    if (menu && GetMenuItemCount(menu) >= 0) InsertMenuW(menu, ...);
```

Interpretation: if the event fires but `MN_GETHMENU` fails, the undocumented bridge broke and the correct fallback is `WM_CONTEXTMENU` ownership. If events continue after your edit menu closes, your hook lifetime is too broad.

## References
- <https://gist.github.com/michelesalvador/4a26852657521298f1f8c95cca77cb03> - default Edit context-menu modification using WinEvent and `MN_GETHMENU`.

## Connections
- `Custom Menubar.md` is a different undocumented menu-drawing path.
- `Window Messaging.md` covers why subclassing alone is not enough once USER owns the popup menu window.
- `../Custom Frame/Acrylic Popup Menus.md` is the visual-treatment route for the same transient `#32768` menu-window family.
- `../Hooks/SetWindowsHookEx.md` contrasts WinEvent observation with USER32 hook procedures.
