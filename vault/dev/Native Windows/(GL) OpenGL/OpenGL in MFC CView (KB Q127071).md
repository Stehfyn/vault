# OpenGL in MFC CView (KB Q127071)

This mirror of Microsoft's old KB Q127071 sample is still useful because the Windows OpenGL bootstrap has barely changed: choose a pixel format once for the window DC, set it, create a WGL context, and make it current on the drawing thread. The fixed-function rendering and palette messages are historical; the DC/context lifetime rules are not.

For modern MFC integration, use the sample only for the `CView`/WGL ownership pattern, then create a dummy context to load `wglCreateContextAttribsARB` and switch to a core profile. The MFC-specific trap is the same as D2D-in-MFC: framework paint/lifetime rules decide when the graphics API is allowed to touch the window.

## References
- <https://github.com/pmachapman/MfcOgl>

## Connections
- `WGL Context Attribute Helper (wglarb).md`
- `../(DX) DirectX/Direct2D and DirectWrite in MFC.md`
