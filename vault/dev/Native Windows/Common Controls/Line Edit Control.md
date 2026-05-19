# Line Edit Control

LineNumEdit demonstrates the pragmatic way to add line numbers to a standard multiline Edit control: keep the Edit for text input and scrolling, add a sibling/static gutter, and synchronize painting with `Edit_GetFirstVisibleLine` and `Edit_LineIndex`. That avoids reimplementing text editing while still producing editor-like chrome.

The hard parts are alignment and invalidation. The gutter must track scroll position, font changes, selection highlighting, and DPI-derived line height. Double buffering is useful because repainting the gutter separately from the Edit can otherwise produce visible tear during scroll.

## References
- <https://github.com/katahiromz/LineNumEdit> - Edit-control companion gutter for line numbers and highlighting.

## Connections
- `Rendering.md` covers flicker and buffering.
- `Custom Controls.md` explains why this is composition around a stock control rather than a full editor control.
