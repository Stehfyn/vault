# Dialog Units and MapDialogRect

Dialog units (DLUs) are font-relative units: 1 DLU horizontal = 1/4 of the average character width; 1 DLU vertical = 1/8 of the average character height. `MapDialogRect` converts a RECT in DLUs to pixels using the dialog's current font. This is how classic Win32 dialogs achieve DPI-like scaling before DPI awareness existed.

```cpp
// Convert a DLU-sized rect to pixels based on the dialog font
RECT rc = { 0, 0, 100, 14 };   // 100x14 DLUs — typical button
MapDialogRect(hDlg, &rc);
int pxW = rc.right  - rc.left;
int pxH = rc.bottom - rc.top;
MoveWindow(hButton, 10, 10, pxW, pxH, TRUE);

// The dialog template header stores cx/cy in DLUs too
// DLGTEMPLATE.cx / cy are both in dialog units
```

## References
- https://github.com/andlabs/windlgunits/blob/master/main.c
