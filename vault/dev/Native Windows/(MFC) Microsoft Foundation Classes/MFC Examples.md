# MFC Examples

Minimal MFC app pattern: derive `CWinApp`, create a `CFrameWnd`, and run the message loop.

```cpp
#include <afxwin.h>

class CMyApp : public CWinApp
{
public:
    BOOL InitInstance() override
    {
        CFrameWnd* frame = new CFrameWnd();
        frame->Create(nullptr, L"MFC Sample");
        m_pMainWnd = frame;
        frame->ShowWindow(SW_SHOW);
        frame->UpdateWindow();
        return TRUE;
    }
};

CMyApp theApp;
```

## References
- https://github.com/jwhu1024/MFC
- https://files.cbps.xyz/archive/ipw/exe/source/
