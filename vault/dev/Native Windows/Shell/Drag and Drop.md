# Drag and Drop

Win32 drag-and-drop for files uses `DragAcceptFiles` + `WM_DROPFILES`. For richer shell DnD (drag from your app to Explorer, support for virtual files) implement `IDropSource` / `IDropTarget`.

```cpp
// Accept dropped files
DragAcceptFiles(hwnd, TRUE);

case WM_DROPFILES: {
  HDROP drop = (HDROP)wParam;
  UINT count = DragQueryFileW(drop, 0xFFFFFFFF, nullptr, 0);
  for (UINT i = 0; i < count; ++i) {
    WCHAR file[MAX_PATH] = {};
    DragQueryFileW(drop, i, file, MAX_PATH);
    // process file...
  }
  DragFinish(drop);
  break;
}
```

## References
- https://learn.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms692761(v=vs.85)
