# RichEdit Win32 Integration

The XP RichEdit source (`w32win32.cpp` in re41) shows how the control creates its HWND, handles style flags, and interfaces with IME. Modern RichEdit uses `Msftedit.dll` (v4.1+). Creating with `MSFTEDIT_CLASS` gives Unicode support and better IME handling than the older `RICHEDIT_CLASS`.

```cpp
// Create a RichEdit v4.1 control
LoadLibraryW(L"Msftedit.dll");
HWND hEdit = CreateWindowExW(0, MSFTEDIT_CLASS, L"",
    WS_CHILD | WS_VISIBLE | ES_MULTILINE | WS_VSCROLL,
    10, 10, 300, 200, hwnd, nullptr, hInst, nullptr);
SendMessageW(hEdit, EM_SETLIMITTEXT, 0, 0);        // unlimited text
SendMessageW(hEdit, EM_SETEVENTMASK, 0, ENM_CHANGE);
SetFocus(hEdit);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/richedit/re41/w32win32.cpp#L5212
