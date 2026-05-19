# ImGui Borderless Win32 (Custom Frame + Viewports)

Stitches melak47-style borderless-window NC handling (cf. melak47/BorderlessWindow #72, grassator/win32-window-custom-titlebar #1) onto an ImGui multi-viewport host running on a transparent OpenGL context — so child viewports get true DWM drop-shadow, resize hit-test, and snap behavior instead of ImGui's faux client-area decorations (cf. tbindi723/IMGuiTool #7). The non-obvious part is the WS_THICKFRAME + WM_NCCALCSIZE-returns-0 trick: you keep the frame for sizing/shadow/snap, then zero out the non-client rect so the client owns every pixel.

Code contribution: inspect the repo for `WM_NCCALCSIZE`, `WM_NCHITTEST`, `WS_THICKFRAME`, transparent WGL setup, and ImGui multi-viewport HWND handling.

## References
- <https://github.com/Stehfyn/imgui-borderless-win32>
