# Custom Chrome Sample (NCCALCSIZE)

Tiny Win32 sample that strips the standard non-client area and reconstructs window chrome (caption, system menu, min/max/close, resize borders) entirely in the client area using `WM_NCCALCSIZE` and `WM_NCHITTEST`. The non-obvious part: returning 0 from `WM_NCCALCSIZE` collapses the non-client frame to nothing, but to keep the DWM shadow / snap / animation behaviour you also need to extend the frame via `DwmExtendFrameIntoClientArea`. Useful baseline for any custom titlebar (VS Code, Slack, etc).

## References
- <https://github.com/oberth/custom-chrome>
