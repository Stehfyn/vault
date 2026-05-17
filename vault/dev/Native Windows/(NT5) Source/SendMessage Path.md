# SendMessage Path (sendmsg.c)

`sendmsg.c` implements the synchronous in-process dispatch path. When sender and receiver are on the same thread, the message is delivered directly without crossing into kernel mode. Cross-thread sends block the sender in `MsgWaitForMultipleObjects` until the receiver processes the message.

```cpp
// Get text length then retrieve the full string via SendMessage
LRESULT len = SendMessageW(hwnd, WM_GETTEXTLENGTH, 0, 0);
std::wstring text(len + 1, L'\0');
SendMessageW(hwnd, WM_GETTEXT, (WPARAM)text.size(), (LPARAM)text.data());
text.resize(len);
```

## References
- https://github.com/tongzx/nt5src/blob/daad8a087a4e75422ec96b7911f1df4669989611/Source/XPSP1/NT/windows/core/ntuser/kernel/sendmsg.c
