Create a Win32 toolbar using `CreateWindowEx` with `TOOLBARCLASSNAME`, send `TB_BUTTONSTRUCTSIZE` to initialize it, populate `TBBUTTON` structs, and add them with `TB_ADDBUTTONS`. Image lists for normal/hot/disabled states are attached via `TB_SETIMAGELIST`.

```cpp
#include <windows.h>
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

HWND CreateSimpleToolbar(HWND hParent, HINSTANCE hInst)
{
    HWND hToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
        WS_CHILD | WS_VISIBLE | CCS_NODIVIDER | TBSTYLE_FLAT,
        0, 0, 0, 0, hParent, (HMENU)IDC_TOOLBAR, hInst, NULL);

    // Required before adding buttons
    SendMessage(hToolbar, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0);

    TBBUTTON buttons[] = {
        { 0, ID_FILE_NEW,  TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"New"  },
        { 1, ID_FILE_OPEN, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"Open" },
        { 0, 0,            TBSTATE_ENABLED, BTNS_SEP,    {0}, 0, 0                 },
        { 2, ID_FILE_SAVE, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"Save" },
    };
    SendMessage(hToolbar, TB_ADDBUTTONS, ARRAYSIZE(buttons), (LPARAM)buttons);

    HIMAGELIST hIml = ImageList_LoadImage(hInst, MAKEINTRESOURCE(IDB_TOOLBAR),
        16, 0, CLR_DEFAULT, IMAGE_BITMAP, LR_CREATEDIBSECTION);
    SendMessage(hToolbar, TB_SETIMAGELIST, 0, (LPARAM)hIml);

    SendMessage(hToolbar, TB_AUTOSIZE, 0, 0);
    return hToolbar;
}
```

## References
- https://github.com/microsoft/Windows-classic-samples/blob/main/Samples/Win7Samples/multimedia/directshow/common/toolbar.cpp
