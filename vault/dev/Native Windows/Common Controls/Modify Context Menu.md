To intercept and modify the default context menu of a subclassed control (e.g. Edit), hook `EVENT_SYSTEM_MENUPOPUPSTART` inside `WM_CONTEXTMENU` via `SetWinEventHook`. The hook fires before the menu is displayed, allowing `InsertMenu`, `EnableMenuItem`, or `DeleteMenu` calls on the live `HMENU`.

```c
#define WINVER 0x0501
#define MN_GETHMENU 0x01E1   /* undocumented: retrieves the HMENU from a menu window */
#define ID_TEST 222

void CALLBACK WinEventProc(HWINEVENTHOOK hWinEventHook, DWORD event, HWND hwnd,
                            LONG idObject, LONG idChild,
                            DWORD dwEventThread, DWORD dwmsEventTime)
{
    HMENU hMenu = (HMENU)SendMessage(hwnd, MN_GETHMENU, 0, 0);
    InsertMenu(hMenu, 0, MF_BYPOSITION | MF_CHECKED, ID_TEST, "Test");
    EnableMenuItem(hMenu, WM_PASTE, MF_GRAYED);
    DeleteMenu(hMenu, WM_CUT, 0);
}

LRESULT CALLBACK EditorProc(HWND hEditor, UINT message, WPARAM wParam, LPARAM lParam,
                             UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    switch (message) {
    case WM_CONTEXTMENU: {
        HWINEVENTHOOK hEventHook = SetWinEventHook(
            EVENT_SYSTEM_MENUPOPUPSTART, EVENT_SYSTEM_MENUPOPUPSTART, 0,
            WinEventProc, GetCurrentProcessId(), GetCurrentThreadId(), 0);
        DefSubclassProc(hEditor, WM_CONTEXTMENU, wParam, lParam);
        UnhookWinEvent(hEventHook);
        break;
    }
    default:
        return DefSubclassProc(hEditor, message, wParam, lParam);
    }
    return 0;
}

// Setup:
// HWND hEdit = CreateWindowW(L"Edit", ...);
// SetWindowSubclass(hEdit, EditorProc, 0, 0);
```

## References
- https://gist.github.com/michelesalvador/4a26852657521298f1f8c95cca77cb03
