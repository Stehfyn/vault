# Win32 Dialog Framework

This sample wraps the dialog-box programming model: resource-backed templates, dialog procedures, control IDs, `WM_INITDIALOG`, command routing, and modal/modeless lifetime. It is the smallest native UI framework many Win32 tools actually need.

Keep it connected to custom-frame and common-control examples. Dialogs are efficient for utilities, settings, and service/admin tools, but they impose message-routing and DPI/layout constraints that become visible as soon as controls are owner-drawn or dynamically resized.

## References
- Local snippet source retained in previous revision of this note.
