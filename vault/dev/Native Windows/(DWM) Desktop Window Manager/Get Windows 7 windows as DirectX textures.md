Uses the DWM thumbnail API (`DwmRegisterThumbnail`) to capture any window's content and composite it into a destination window. The `dwmaxx2` library extends this by hooking DWM's DX10 draw calls to expose a shared texture handle (`HANDLE`) for any HWND, enabling true DirectX 10 texture access to other windows' contents.

```c
// Simple DWM thumbnail compositing
HTHUMBNAIL thumb = NULL;
DwmRegisterThumbnail(hwndDest, hwndSrc, &thumb);

DWM_THUMBNAIL_PROPERTIES props = {};
props.dwFlags = DWM_TNP_RECTDESTINATION | DWM_TNP_VISIBLE | DWM_TNP_OPACITY;
props.rcDestination = { 0, 0, 200, 150 };
props.opacity = 255;
props.fVisible = TRUE;
DwmUpdateThumbnailProperties(thumb, &props);

// on cleanup:
DwmUnregisterThumbnail(thumb);

// dwmaxx2: get shared DX10 texture handle for any HWND
DwmaxxLoad();
HANDLE hShared = DwmaxxGetWindowSharedHandle(hwndTarget);
// open as ID3D10Resource via OpenSharedResource
```

## References
- https://github.com/steeve/dwmaxx2
