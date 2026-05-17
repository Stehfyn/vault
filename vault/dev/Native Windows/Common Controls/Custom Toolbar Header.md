A custom Win32 toolbar is created with `CreateWindowEx(0, TOOLBARCLASSNAME, ...)` and populated via `TBBUTTON` structs sent with `TB_ADDBUTTONS`. For owner-draw header columns, handle `NM_CUSTOMDRAW` in the parent's `WM_NOTIFY` to override painting per column item.

```cpp
#include <windows.h>
#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

HWND CreateCustomToolbar(HWND hwndParent, HINSTANCE hInst) {
    HWND hToolbar = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
        WS_CHILD | WS_VISIBLE | TBSTYLE_FLAT | CCS_TOP | TBSTYLE_TOOLTIPS,
        0, 0, 0, 0, hwndParent, (HMENU)IDC_TOOLBAR, hInst, NULL);

    SendMessage(hToolbar, TB_BUTTONSTRUCTSIZE, sizeof(TBBUTTON), 0);

    HIMAGELIST hImgList = ImageList_Create(16, 16, ILC_COLOR32 | ILC_MASK, 3, 0);
    SendMessage(hToolbar, TB_SETIMAGELIST, 0, (LPARAM)hImgList);

    TBBUTTON tbb[] = {
        { 0, ID_FILE_NEW,  TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"New"  },
        { 1, ID_FILE_OPEN, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"Open" },
        { 0, 0,            TBSTATE_ENABLED, BTNS_SEP,    {0}, 0, 0                 },
        { 2, ID_FILE_SAVE, TBSTATE_ENABLED, BTNS_BUTTON, {0}, 0, (INT_PTR)L"Save" },
    };
    SendMessage(hToolbar, TB_ADDBUTTONS, _countof(tbb), (LPARAM)tbb);
    SendMessage(hToolbar, TB_AUTOSIZE, 0, 0);
    return hToolbar;
}

// Custom-draw header in WM_NOTIFY handler:
// case WM_NOTIFY: {
//     LPNMHDR pnmh = (LPNMHDR)lParam;
//     if (pnmh->code == NM_CUSTOMDRAW) {
//         LPNMCUSTOMDRAW pcd = (LPNMCUSTOMDRAW)lParam;
//         if (pcd->dwDrawStage == CDDS_ITEMPREPAINT) {
//             FillRect(pcd->hdc, &pcd->rc, hbrHeaderBg);
//             SetTextColor(pcd->hdc, RGB(255, 255, 255));
//             return CDRF_SKIPDEFAULT;
//         }
//     }
// }
```

## References
- https://github.com/Alexandre-Carpentier/Win32CustomToolbarHeader
