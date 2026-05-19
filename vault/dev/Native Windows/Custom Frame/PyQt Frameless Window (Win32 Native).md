# PyQt Frameless Window (Win32 Native)

Cross-platform frameless window for PyQt5/PyQt6/PySide2/PySide6 with native Win32 chrome semantics — drag, snap, Aero shake, maximize-against-taskbar — all preserved. The Windows port wins by handling `WM_NCCALCSIZE` (return 0 with `wParam==TRUE` to eat the entire non-client area) and `WM_NCHITTEST` (synthesize `HTCAPTION`/`HTLEFT`/etc. from cursor position), then leaning on `DwmExtendFrameIntoClientArea` so the OS still draws the drop shadow and the window still participates in Snap layouts. Same playbook as melak47/BorderlessWindow (#72), grassator/win32-window-custom-titlebar (#1) and Stehfyn/imgui-borderless-win32 (#60), but bridged through Qt's `nativeEvent` so PyQt apps don't have to drop to ctypes themselves.

```python
from PyQt5.QtWidgets import QWidget
from ctypes.wintypes import MSG

class FramelessWindow(QWidget):
    def nativeEvent(self, eventType, message):
        msg = MSG.from_address(int(message))
        if msg.message == 0x0083:          # WM_NCCALCSIZE
            return True, 0                 # zero non-client area
        if msg.message == 0x0084:          # WM_NCHITTEST
            return True, self._hit_test(msg.lParam)
        return super().nativeEvent(eventType, message)
```

## References
- <https://github.com/zhiyiYo/PyQt-Frameless-Window>
