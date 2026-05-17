A Win32 splitter control is implemented by tracking mouse capture on a divider region. On `WM_LBUTTONDOWN` within the splitter hit zone, capture the mouse; on `WM_MOUSEMOVE` with the button held, reposition child windows; on `WM_LBUTTONUP`, release capture.

```cpp
#include <windows.h>

static int  g_splitterX = 200;
static BOOL g_dragging  = FALSE;

void ResizeChildren(HWND hwnd) {
    RECT rc; GetClientRect(hwnd, &rc);
    MoveWindow(GetDlgItem(hwnd, IDC_LEFT),
               0, 0, g_splitterX - 2, rc.bottom, TRUE);
    MoveWindow(GetDlgItem(hwnd, IDC_RIGHT),
               g_splitterX + 2, 0, rc.right - g_splitterX - 2, rc.bottom, TRUE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_LBUTTONDOWN: {
        int x = GET_X_LPARAM(lp);
        if (abs(x - g_splitterX) <= 4) {
            g_dragging = TRUE;
            SetCapture(hwnd);
            SetCursor(LoadCursor(NULL, IDC_SIZEWE));
        }
        return 0;
    }
    case WM_MOUSEMOVE: {
        int x = GET_X_LPARAM(lp);
        if (g_dragging) {
            g_splitterX = x;
            ResizeChildren(hwnd);
        } else if (abs(x - g_splitterX) <= 4) {
            SetCursor(LoadCursor(NULL, IDC_SIZEWE));
        }
        return 0;
    }
    case WM_LBUTTONUP:
        if (g_dragging) { g_dragging = FALSE; ReleaseCapture(); }
        return 0;
    case WM_SIZE:
        ResizeChildren(hwnd);
        return 0;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}
```

## References
- https://github.com/kurtjm/splitter-layout-win32
