# Mouse Input

Mouse input arrives as window messages; use GetCursorPos and ScreenToClient to convert screen coordinates to client coordinates.

## Snippet
```cpp
case WM_LBUTTONDOWN:
{
    POINT pt{};
    GetCursorPos(&pt);
    ScreenToClient(hwnd, &pt);
    // pt now contains client coordinates
    return 0;
}
```

## References
- https://web.archive.org/web/20070123100817/http://msdn.microsoft.com/library/en-us/winui/winui/windowsuserinterface/userinput/mouseinput/aboutmouseinput.asp
