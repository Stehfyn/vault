# Title Bar Customization

These links are useful because they show three distinct title-bar customization levels. WinCenterTitle injects into DWM and hooks the text drawing/layout path, so it changes caption rendering globally without modifying each app. CaptionButtonFixer targets the caption-button sizing regression around maximized/fullscreen windows. Kenny Kerr's DWM material is the clean public-API side: extend the frame, handle hit testing, and let DWM keep ownership of the dangerous parts.

## App-Owned Custom Chrome

Kenny Kerr's material contributes the supported app-local path: adjust non-client calculation, extend the frame, and answer hit tests so resizing/caption drag still works.

```cpp
MARGINS margins = { 0, 0, 1, 0 };
DwmExtendFrameIntoClientArea(hwnd, &margins);

case WM_NCCALCSIZE:
    if (wParam) return 0;
    break;
case WM_NCHITTEST:
    // Return HTCAPTION, HTLEFT, HTRIGHT, etc. for custom chrome zones.
    break;
```

## Global Caption Mutation

WinCenterTitle and CaptionButtonFixer contribute the warning boundary: changing every app's caption behavior is DWM injection/hooking territory, not ordinary window customization. Keep those links near DWM internals and hook notes, not in app UI guidance.

```cpp
struct CaptionCustomizationBoundary {
    bool app_local_nonclient_handling;
    bool uses_public_dwm_attributes;
    bool injects_into_dwm_process;
};
```

## References

- <https://raw.githubusercontent.com/valinet/WinCenterTitle/master/README.md>
- <https://raw.githubusercontent.com/7kt4/CaptionButtonFixer/master/README.md>
- <https://gist.githubusercontent.com/kennykerr/62923cdacaba28fedc4f3dab6e0c12ec/raw/>
- Related: `No Title Bar Window.md`, `Snap Layout API.md`, `DWM Blur Glass (Aero Restoration).md`
