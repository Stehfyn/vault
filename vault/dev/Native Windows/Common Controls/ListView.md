# ListView

`WC_LISTVIEW` is the workhorse report/table control in comctl32. In `LVS_REPORT` mode, columns are `LVCOLUMN`, rows are `LVITEM`, and subitems are addressed by column index. The control becomes substantially more usable with extended styles such as `LVS_EX_FULLROWSELECT`, `LVS_EX_DOUBLEBUFFER`, and `LVS_EX_GRIDLINES`, but large datasets should use owner-data/virtual mode instead of inserting every row as stored control state.

The linked `VolumeWalker` helper matters because real ListView code quickly turns into repetitive column, sort, selection, and text-buffer plumbing. The Microsoft common-control styles page is the guardrail: many behaviors are style-bit contracts, not messages you can patch in later without recreating or carefully updating the control.

## References
- <https://github.com/yamashita-software-works/VolumeWalker/blob/26793168cd95fb7e7dcba1b22773df90680a30fd/libmisc/listviewutil.h#L26> - helper layer over common ListView operations.
- <https://learn.microsoft.com/en-us/windows/win32/controls/common-control-styles> - style reference for common controls.

## Connections
- `Visual Styles.md` covers `Explorer` theming and comctl32 v6 expectations.
- `Rendering.md` covers custom draw when ListView visuals need to diverge.
