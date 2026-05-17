1. https://stackoverflow.com/questions/29038024/drawing-a-window-with-a-standard-frame-and-transparent-contents

Snippet (layered window + UpdateLayeredWindow):

```cpp
HWND hwnd = CreateWindowEx(WS_EX_LAYERED | WS_EX_APPWINDOW, L"Cls", L"Transparent",
                           WS_OVERLAPPED | WS_SYSMENU, x, y, w, h,
                           nullptr, nullptr, hInst, nullptr);

POINT ptSrc = { 0, 0 };
SIZE sizeWnd = { w, h };
POINT ptDst = { x, y };
BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };

UpdateLayeredWindow(hwnd, nullptr, &ptDst, &sizeWnd, hdcMem, &ptSrc, 0, &bf, ULW_ALPHA);
```
