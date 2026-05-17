# WND Internal Structure

`GetWindowLongPtr(hWnd, -1)` returns a pointer to the internal `WF` struct — a nested part of USER32's undocumented `WND` structure — exposing window state flags, styles, and fnid beyond what `GetWindowLong` reveals.

## Snippet

```cpp
// Undocumented: index -1 returns a pointer to the WF struct inside WND.
// Do NOT write through this pointer — read-only diagnostic use only.

struct WF {
    DWORD state;    // WF_STATE bitfield  (WNDS_* flags)
    DWORD state2;   // WF_STATE2 bitfield (WNDS2_* flags)
    DWORD ExStyles; // Extended styles with extra undocumented bits
    DWORD Styles;   // Window styles with extra undocumented bits
    HMODULE hModule;
    USHORT reserved;
    USHORT fnid;    // Control class identifier (e.g. FNID_BUTTON = 0x02A1)
};

WF* pWf = reinterpret_cast<WF*>(::GetWindowLongPtr(hWnd, -1));
if (pWf) {
    bool isDialog      = (pWf->state  & 0x00010000) != 0; // WNDS_DIALOGWINDOW
    bool isFullscreen  = (pWf->state2 & 0x00000040) != 0; // WNDS2_FULLSCREEN
    bool isDestroyed   = (pWf->state  & 0x80000000) != 0; // WNDS_DESTROYED
}
```

### WF_STATE selected flags (state)
| Flag | Value | Meaning |
|------|-------|---------|
| `WNDS_HASMENU` | `0x00000001` | Window has a menu |
| `WNDS_HASCAPTION` | `0x00000008` | Has a title bar |
| `WNDS_DIALOGWINDOW` | `0x00010000` | Is a dialog window |
| `WNDS_SERVERSIDEWINDOWPROC` | `0x00040000` | WndProc is in win32k.sys |
| `WNDS_DESTROYED` | `0x80000000` | Window is being destroyed |

### WF_STATE2 selected flags (state2)
| Flag | Value | Meaning |
|------|-------|---------|
| `WNDS2_HASCLIENTEDGE` | `0x00000010` | Has `WS_EX_CLIENTEDGE` |
| `WNDS2_FULLSCREEN` | `0x00000040` | Fullscreen mode |
| `WNDS2_INDESTROY` | `0x00000080` | Inside `DestroyWindow` |
| `WNDS2_SHELLHOOKREGISTERED` | `0x40000000` | Registered shell hook |

## References
- https://reverseengineering.stackexchange.com/a/21135
- https://www.geoffchappell.com/studies/windows/win32/user32/structs/wnd/index.htm
- https://doxygen.reactos.org/dd/d79/include_2ntuser_8h_source.html#l00572
- https://github.com/tinysec/public/blob/master/win32k/fnID.md
