HexCtrl is a fully-featured hex viewer/editor written in pure Win32 API, supporting data up to 16 EB via virtual data mode, bookmarks, search/replace, data interpreter, undo/redo, custom colors, and Per-Monitor V2 DPI awareness. Integrate via sources or DLL; create with `CreateHexCtrl()` then feed data with `SetData()`.

```cpp
#include "HexCtrl/HexCtrl.h"
using namespace HEXCTRL;

// Declare the smart-pointer wrapper
IHexCtrlPtr myHex { CreateHexCtrl() };

// Classic window creation
HEXCREATE hc;
hc.hWndParent = hwndParent;
hc.rect       = { 0, 0, 800, 600 };
myHex->Create(hc);

// Set data from a buffer (memory mode)
std::vector<std::byte> data(4096);
// ... fill data ...
HEXDATA hd;
hd.spnData  = { data.data(), data.size() };
hd.fMutable = true;   // allow editing
myHex->SetData(hd);

// Dialog usage: place a Custom Control with class "HexCtrl_MainWnd",
// then in OnInitDialog:
//   m_myHex->CreateDialogCtrl(IDC_HEX_CTRL, m_hWnd);
```

## References
- https://github.com/jovibor/HexCtrl
