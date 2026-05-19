# Custom Controls in Common File Dialogs

On Vista and later, `IFileDialogCustomize` is the supported way to add small pieces of UI to the common open/save dialogs. It can add check buttons, combo boxes, edit boxes, push buttons, radio lists, visual groups, and separators while leaving layout and visual integration to the shell. The application assigns control IDs, shows the dialog, then queries state through the same interface.

This is not the old hook-template model from `GetOpenFileName`; it is COM customization layered onto the modern shell dialog. That distinction matters because the Vista+ dialog can change layout across Windows versions without breaking your control placement. Use it for options tightly coupled to file selection, not for building a general settings panel inside the file picker.

## References
- <https://devblogs.microsoft.com/oldnewthing/20211227-00/?p=106054> - Raymond Chen's concise example of `IFileDialogCustomize` control insertion.

## Connections
- `Custom Controls.md` covers HWND controls; file dialog customization is a shell COM surface instead.
