LineNumEdit pairs a custom static control (for line numbers) alongside a standard multiline Edit control. The static subclass intercepts `WM_PAINT` and synchronizes with `Edit_GetFirstVisibleLine` / `Edit_LineIndex` to draw line numbers, using double-buffering to eliminate flicker.

```cpp
#include "LineNumEdit.hpp"

// 1. Create a standard multiline edit control
HWND hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), NULL,
    WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | WS_VSCROLL,
    50, 0, 400, 300, hwndParent, (HMENU)IDC_EDIT, hInst, NULL);

// 2. Wrap it — Prepare() inserts a sibling LineNumStatic and sets the edit's left margin
LineNumEdit lineNumEdit(hEdit);
lineNumEdit.Prepare();

// Optionally highlight a specific line number with a background color
lineNumEdit.SetHighlight(3, RGB(255, 220, 220));

// Internal paint loop (inside LineNumStatic::OnDrawClient):
//   INT iPhysicalLine = Edit_GetFirstVisibleLine(hwndEdit);
//   INT ich           = Edit_LineIndex(hwndEdit, iPhysicalLine);
//   // for each visible line: format number, DrawTextW right-aligned into the static
```

## References
- https://github.com/katahiromz/LineNumEdit
