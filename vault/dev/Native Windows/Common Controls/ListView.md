# ListView

`WC_LISTVIEW` is the workhorse report/table control in comctl32. In `LVS_REPORT` mode, columns are `LVCOLUMN`, rows are `LVITEM`, and subitems are addressed by column index. The control becomes substantially more usable with extended styles such as `LVS_EX_FULLROWSELECT`, `LVS_EX_DOUBLEBUFFER`, and `LVS_EX_GRIDLINES`, but large datasets should use owner-data/virtual mode instead of inserting every row as stored control state.

The linked `VolumeWalker` helper matters because real ListView code quickly turns into repetitive column, sort, selection, and text-buffer plumbing. The Microsoft common-control styles page is the guardrail: many behaviors are style-bit contracts, not messages you can patch in later without recreating or carefully updating the control.

## Source Shape

The creation sequence is style first, columns second, rows or virtual callbacks third.

```cpp
HWND list = CreateWindowExW(WS_EX_CLIENTEDGE, WC_LISTVIEWW, nullptr,
    WS_CHILD | WS_VISIBLE | LVS_REPORT | LVS_SHOWSELALWAYS,
    0, 0, width, height, parent, (HMENU)IDC_LIST, instance, nullptr);

ListView_SetExtendedListViewStyle(list,
    LVS_EX_FULLROWSELECT | LVS_EX_DOUBLEBUFFER | LVS_EX_GRIDLINES);

LVCOLUMNW col = { LVCF_TEXT | LVCF_WIDTH | LVCF_SUBITEM };
col.pszText = L"Name";
col.cx = ScaleForDpi(220, GetDpiForWindow(list));
ListView_InsertColumn(list, 0, &col);
```

For large datasets, use `LVS_OWNERDATA` and answer `LVN_GETDISPINFO` instead of filling the control with duplicated strings.

```cpp
case WM_NOTIFY:
    if (auto *di = AsListViewDispInfo(lParam)) {
        di->item.pszText = ModelText(di->item.iItem, di->item.iSubItem);
        return TRUE;
    }
    break;
```

## Source Code Reading

The linked `VolumeWalker` source is more useful than a bare `ListView_InsertItem` snippet because it shows how report controls scale when the data model is not trivial. Read `fsvolumelist/page_volumelist.h`, `fsvolumelist/page_vdsdisks.h`, and `libmisc/listviewutil.h`.

The pattern is:

```cpp
CreateWindowEx(..., WC_LISTVIEW, ..., LVS_REPORT | LVS_SHOWSELALWAYS, ...)
ListView_SetExtendedListViewStyle(hwndList, LVS_EX_FULLROWSELECT | ...)
insert columns with LVCOLUMN
insert rows with LVITEM.pszText = LPSTR_TEXTCALLBACK
handle WM_NOTIFY from the parent
```

`page_volumelist.h` routes `WM_NOTIFY` to ListView-specific handlers for `LVN_GETDISPINFO`, `LVN_ITEMCHANGED`, `LVN_DELETEITEM`, `LVN_ITEMACTIVATE`, and `LVN_COLUMNCLICK`. That is the real table-control contract: the parent owns interpretation, and the control reports user action through `NMHDR.code`.

For callback rows, the source deliberately stores sentinels:

```cpp
lvi.pszText = LPSTR_TEXTCALLBACK;
lvi.iImage = I_IMAGECALLBACK;
ListView_SetItemText(hwndList, item, subitem, LPSTR_TEXTCALLBACK);
```

The observable behavior is that the ListView asks for display text later, during paint, sort, or refresh. Your backing model must remain alive and indexable after insertion. A helper like `AddRow(modelRow)` is too vague unless it states whether it copies text into comctl32 or installs callback rows.

Sorting is a separate callback contract. The `CompareProc` functions compare `LPARAM` model identifiers, not visible strings. Column clicks update sort state, then `ListView_SortItems` or an equivalent wrapper reorders view items. If item `lParam` does not point to stable model identity, sort and delete notifications will eventually lie.

## References
- <https://github.com/yamashita-software-works/VolumeWalker/blob/26793168cd95fb7e7dcba1b22773df90680a30fd/libmisc/listviewutil.h#L26> - helper layer over common ListView operations.
- <https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles> - style reference for common controls.

## Connections
- `Visual Styles.md` covers `Explorer` theming and comctl32 v6 expectations.
- `Rendering.md` covers custom draw when ListView visuals need to diverge.
- `Dialog Units.md` and `../DPI Awareness/Per-Monitor V2 DPI Reference.md` cover column widths and row metrics that should not be hard-coded pixels.
- `Custom Controls.md` is the escalation route when ListView virtual mode still cannot model the interaction.
