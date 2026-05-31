# Line Edit Control

LineNumEdit demonstrates the pragmatic way to add line numbers to a standard multiline Edit control: keep the Edit for text input and scrolling, add a sibling/static gutter, and synchronize painting with `Edit_GetFirstVisibleLine` and `Edit_LineIndex`. That avoids reimplementing text editing while still producing editor-like chrome.

The hard parts are alignment and invalidation. The gutter must track scroll position, font changes, selection highlighting, and DPI-derived line height. Double buffering is useful because repainting the gutter separately from the Edit can otherwise produce visible tear during scroll.

## Source Code Reading

`LineNumEdit.cpp` and `LineNumEdit.hpp` show two distinct techniques: subclass an existing child and superclass the `EDIT` class.

`LineNumBase::WindowProc` in the header retrieves the object pointer from window storage and dispatches to `WindowProcDx`. `LineNumBase::Attach` replaces `GWLP_WNDPROC` with `LineNumBase::WindowProc`; `Detach` restores the saved old procedure. This is old-style subclassing with `SetWindowLongPtr`, so cleanup depends on restoring the original `WNDPROC`.

`LineNumEdit::SuperclassWindow` goes further. It calls `GetClassInfoEx(NULL, TEXT("EDIT"), &wcx)`, saves `wcx.lpfnWndProc`, changes `wcx.lpszClassName` to the custom class name, changes `wcx.lpfnWndProc` to `SuperclassWndProc`, and registers a new class. `SuperclassWndProc` allocates `LineNumEdit` on `WM_NCCREATE`, stores it in `GWLP_USERDATA`, and deletes it on `WM_NCDESTROY`.

The gutter is not painted inside the edit control. `LineNumEdit::Prepare` adjusts the edit formatting rectangle with `Edit_SetRectNoPaint`, then creates or moves a child `STATIC` gutter:

```cpp
cxColumn = GetColumnWidth();
Edit_SetRectNoPaint(edit, &rcEditShiftedRight);
CreateWindow(TEXT("STATIC"), NULL, WS_CHILD | WS_VISIBLE | SS_NOTIFY,
             0, 0, cxColumn, cyColumn, edit, NULL, module, NULL);
```

`LineNumStatic::WindowProcDx` handles `WM_PAINT` by calling `OnDrawClient`, forwards mouse messages into the edit by mapping gutter coordinates to edit coordinates, returns `TRUE` from `WM_ERASEBKGND`, and deletes per-line properties on `WM_DESTROY`.

`OnDrawClient` is the meat:

- Create a compatible memory DC and bitmap for double buffering.
- Ask the parent for the correct edit/static background brush with `WM_CTLCOLOREDIT` or `WM_CTLCOLORSTATIC`.
- Use `Edit_GetFirstVisibleLine`, `Edit_LineIndex`, `Edit_LineFromChar`, and `Edit_GetText` to map physical visible lines back to logical line labels.
- Use per-line `SetProp`/`GetProp` markers to color marked lines.
- Draw right-aligned labels with `DrawTextW`, then `BitBlt` the buffer into the gutter.

The observable outcome: scrolling, typing, paste, undo, font changes, margin changes, and resize all have explicit branches in `LineNumEdit::WindowProcDx` that call either `m_hwndStatic.Redraw()` or `Prepare()`. A line-number helper that does not name these invalidation triggers is incomplete.

## Verification Route

Claim: the source's old-style subclassing/superclassing is correct only if the original window procedure and object lifetime are restored at the right boundary. The gutter drawing is the visible feature; the storage and teardown path is the part that keeps the process stable.

Why it matters for new code: an editor companion control is likely to survive font changes, text replacement, subclass removal, and parent destruction. If it leaves a stale `GWLP_WNDPROC` or `GWLP_USERDATA` pointer, the next message turns a drawing enhancement into a use-after-free.

How to verify:

- Break on `SetWindowLongPtrW` and confirm the subclass path stores exactly one object pointer and one previous procedure.
- Trace `WM_NCCREATE`, `WM_NCDESTROY`, `WM_SETFONT`, `EM_SETMARGINS`, `WM_VSCROLL`, and `WM_MOUSEWHEEL`; each should either rebuild layout or redraw the gutter.
- Destroy the parent while the edit has focus and while it is scrolling; the old procedure should not be called through a freed object after `WM_NCDESTROY`.

Minimal code/pseudocode:

```cpp
Attach(hwnd):
    oldproc = (WNDPROC)SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)ThunkProc)
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this)

ThunkProc(hwnd, msg, w, l):
    self = (LineEdit*)GetWindowLongPtr(hwnd, GWLP_USERDATA)
    if msg == WM_NCDESTROY:
        oldproc = self->oldproc
        SetWindowLongPtr(hwnd, GWLP_WNDPROC, (LONG_PTR)oldproc)
        SetWindowLongPtr(hwnd, GWLP_USERDATA, 0)
        result = CallWindowProc(oldproc, hwnd, msg, w, l)
        delete self
        return result
    return CallWindowProc(self->oldproc, hwnd, msg, w, l)
```

Interpretation: if `WM_NCDESTROY` can arrive and the next message still dispatches through your thunk with freed state, the subclass contract is broken. If resize/font/scroll messages do not trigger `Prepare` or redraw, line numbers will eventually desynchronize even though the initial paint looked correct.

## References
- <https://github.com/katahiromz/LineNumEdit> - Edit-control companion gutter for line numbers and highlighting.

## Connections
- `Rendering.md` covers flicker and buffering.
- `Custom Controls.md` explains why this is composition around a stock control rather than a full editor control.
