# ListView Control

The list-view control (`WC_LISTVIEW`) displays rows and columns of items. Use `LVS_REPORT` for details view. Key macros: `ListView_InsertColumn`, `ListView_InsertItem`, `ListView_SetItemText`, `ListView_GetSelectedCount`. Sub-items use column index in `LVITEM.iSubItem`.

```cpp
INITCOMMONCONTROLSEX icc = { sizeof(icc), ICC_LISTVIEW_CLASSES };
InitCommonControlsEx(&icc);

HWND hList = CreateWindowW(WC_LISTVIEW, L"",
    WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SHOWSELALWAYS,
    0, 0, 400, 200, hwnd, (HMENU)IDC_LIST, hInst, nullptr);
ListView_SetExtendedListViewStyle(hList,
    LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

// Add columns
LVCOLUMNW col = { LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM };
col.iSubItem = 0; col.cx = 200; col.pszText = (LPWSTR)L"Name";
ListView_InsertColumn(hList, 0, &col);
col.iSubItem = 1; col.cx = 100; col.pszText = (LPWSTR)L"Size";
ListView_InsertColumn(hList, 1, &col);

// Insert an item
LVITEMW item = { LVIF_TEXT, 0, 0, 0, 0, (LPWSTR)L"file.txt" };
int row = ListView_InsertItem(hList, &item);
ListView_SetItemText(hList, row, 1, (LPWSTR)L"1024");
```

## References
- https://github.com/yamashita-software-works/VolumeWalker/blob/26793168cd95fb7e7dcba1b22773df90680a30fd/libmisc/listviewutil.h#L26
- https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles
