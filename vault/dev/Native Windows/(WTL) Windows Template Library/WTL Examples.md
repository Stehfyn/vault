# WTL Examples

WTL wraps Win32 window plumbing with ATL-style classes and message maps. Typical usage derives from `CWindowImpl`, overrides handlers, and uses `BEGIN_MSG_MAP`.

```cpp
#include <atlbase.h>
#include <atlwin.h>

class CMainWnd : public CWindowImpl<CMainWnd>
{
public:
    DECLARE_WND_CLASS(L"WTLMainWnd")

    BEGIN_MSG_MAP(CMainWnd)
        MESSAGE_HANDLER(WM_PAINT, OnPaint)
        MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
    END_MSG_MAP()

    LRESULT OnPaint(UINT, WPARAM, LPARAM, BOOL&)
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(&ps);
        TextOutW(hdc, 10, 10, L"WTL", 3);
        EndPaint(&ps);
        return 0;
    }

    LRESULT OnDestroy(UINT, WPARAM, LPARAM, BOOL&)
    {
        PostQuitMessage(0);
        return 0;
    }
};

int WINAPI wWinMain(HINSTANCE hInst, HINSTANCE, PWSTR, int nCmdShow)
{
    CMainWnd wnd;
    wnd.Create(nullptr, CWindow::rcDefault, L"WTL Sample");
    wnd.ShowWindow(nCmdShow);

    MSG msg = {};
    while (GetMessageW(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
```

## References
- https://github.com/wyrover/wtl-examples
